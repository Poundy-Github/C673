/**************************************************************************
COPYRIGHT (C) $Date: 2020/12/09 13:39:34CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/ABPR/ABPREP_SEN/ABPREP/i/project.pj $
$Log: ABPREP.c  $
Revision 1.4.1.5 2020/12/09 13:39:34CET Marele, Ana-Maria (uib19519) (uib19519) 
automatically created
File          : ABPREP
Generated on  : Mon 07.12.2020 at 19:28:16 (UTC+01:00)
MD5           : [1129826674  3720888766  3502451185   682596439 0](ABPREP)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.1012177 (R2016b) Update 7
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "ABPREP.h"
#include "ABPREP_private.h"
#include "roadEdgeKalmanFilter.h"
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
#define ABPREP_START_SEC_DATA_8
#include "ABPREP_MemMap.h"
static uint8 BI_abprep__T_ABPREP_ReBnd_Type_enum;
/* 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Merge/Functionality'/Merge' */
static uint8 BI_abprep__T_ABPREP_ReBnd_Type_enum_b;
/* 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Merge1/Functionality'/Merge' */
static uint8 DW_abprep_Unit_Delay_DSTATE_cvn[2];
static uint8 DW_abprep_Unit_Delay4_DSTATE_e[2];
static uint8 DW_abprep_Unit_Delay_DSTATE_e;
static uint8 DW_abprep_Unit_Delay4_DSTATE_l;
static uint8 DW_abprep_Unit_Delay_DSTATE_al;
static uint8 DW_abprep_Unit_Delay_DSTATE_hs[2];
static uint8 DW_abprep_Unit_Delay1_DSTATE_os[2];
static uint8 DW_abprep_Unit_Delay2_DSTATE_bb[2];
static uint8 DW_abprep_Unit_Delay3_DSTATE_m[2];
static uint8 DW_abprep_Unit_Delay4_DSTATE_o[2];
static uint8 DW_abprep_Unit_Delay_DSTATE_mn;
static uint8 DW_abprep_Unit_Delay_1_DSTATE_k;
static uint8 DW_abprep_Unit_Delay4_DSTATE_b;
static uint8 DW_abprep_Unit_Delay_DSTATE_k1;
static uint8 DW_abprep_Unit_Delay_2_DSTATE_m;
static uint8 DW_abprep_Unit_Delay4_DSTATE_g;
static uint8 DW_abprep_Unit_Delay_DSTATE_p;
static uint8 DW_abprep_Unit_Delay_1_DSTATE_d;
static uint8 DW_abprep_Unit_Delay4_DSTATE_f;
static uint8 DW_abprep_Unit_Delay_DSTATE_kt;
static uint8 DW_abprep_Unit_Delay_2_DSTATE_g;
static uint8 DW_abprep_Unit_Delay5_DSTATE_e;
static uint8 DW_abprep_Unit_Delay3_DSTATE_o;
static uint8 DW_abprep_Unit_Delay4_DSTATE_bs;
static uint8 DW_abprep_Unit_Delay5_DSTATE_eq;
static uint8 DW_abprep_Unit_Delay2_DSTATE_e;
static uint8 DW_abprep_Unit_Delay3_DSTATE_b;
static uint8 DW_abprep_Unit_Delay4_DSTATE_d;
static uint8 DW_abprep_Unit_Delay5_DSTATE_l;
static uint8 DW_abprep_Unit_Delay2_DSTATE_ch;
static uint8 DW_abprep_Unit_Delay5_DSTATE_m;
static uint8 DW_abprep_Unit_Delay3_DSTATE_jb;
static uint8 DW_abprep_Unit_Delay4_DSTATE_j;
static uint8 DW_abprep_Unit_Delay5_DSTATE_k;
static uint8 DW_abprep_Unit_Delay2_DSTATE_i;
static uint8 DW_abprep_Unit_Delay3_DSTATE_a;
static uint8 DW_abprep_Unit_Delay4_DSTATE_i;
static uint8 DW_abprep_Unit_Delay5_DSTATE_h;
static uint8 DW_abprep_Unit_Delay2_DSTATE_j;
#define ABPREP_STOP_SEC_DATA_8
#include "ABPREP_MemMap.h"
#define ABPREP_START_SEC_DATA_32
#include "ABPREP_MemMap.h"
static float32 DW_abprep_Unit_Delay_DSTATE[2];
static float32 DW_abprep_Unit_Delay_DSTATE_m[2];
static float32 DW_abprep_Unit_Delay_DSTATE_n[2];
static float32 DW_abprep_Unit_Delay1_DSTATE[2];
static float32 DW_abprep_Unit_Delay3_DSTATE[2];
static float32 DW_abprep_Unit_Delay2_DSTATE[2];
static float32 DW_abprep_Unit_Delay4_DSTATE;
static float32 DW_abprep_Unit_Delay_DSTATE_c;
static float32 DW_abprep_Unit_Delay6_DSTATE;
static float32 DW_abprep_Unit_Delay2_DSTATE_o;
static float32 DW_abprep_Unit_Delay5_DSTATE;
static float32 DW_abprep_Unit_Delay1_DSTATE_g;
static float32 DW_abprep_Unit_Delay1_DSTATE_l;
static float32 DW_abprep_Unit_Delay6_DSTATE_e;
static float32 DW_abprep_Unit_Delay1_DSTATE_n;
static float32 DW_abprep_Unit_Delay9_DSTATE;
static float32 DW_abprep_Unit_Delay5_DSTATE_p;
static float32 DW_abprep_Unit_Delay8_DSTATE;
static float32 DW_abprep_Unit_Delay4_DSTATE_k;
static float32 DW_abprep_Unit_Delay7_DSTATE;
static float32 DW_abprep_Unit_Delay3_DSTATE_j;
static float32 DW_abprep_Unit_Delay2_DSTATE_n;
static float32 DW_abprep_Unit_Delay7_DSTATE_m;
static float32 DW_abprep_Unit_Delay1_DSTATE_p;
static float32 DW_abprep_Unit_Delay_DSTATE_k;
static float32 DW_abprep_Unit_Delay_DSTATE_f;
static float32 DW_abprep_Unit_Delay1_DSTATE_m;
static float32 DW_abprep_Unit_Delay1_DSTATE_o;
static float32 DW_abprep_Unit_Delay2_DSTATE_c;
static float32 DW_abprep_Unit_Delay2_DSTATE_ce;
static float32 DW_abprep_Unit_Delay1_DSTATE_f;
static float32 DW_abprep_Unit_Delay_DSTATE_l;
static float32 DW_abprep_Unit_Delay_DSTATE_cv;
static float32 DW_abprep_Unit_Delay1_DSTATE_j;
static float32 DW_abprep_Unit_Delay1_DSTATE_lx;
static float32 DW_abprep_Unit_Delay2_DSTATE_l;
static float32 DW_abprep_Unit_Delay2_DSTATE_b;
static float32 DW_abprep_Unit_Delay1_DSTATE_fa;
static float32 DW_abprep_Unit_Delay3_DSTATE_i;
static float32 DW_abprep_Unit_Delay2_DSTATE_p;
static float32 DW_abprep_Unit_Delay1_DSTATE_h;
static float32 DW_abprep_Unit_Delay_DSTATE_h;
static float32 DW_abprep_Unit_Delay_2_DSTATE;
static float32 DW_abprep_Unit_Delay_DSTATE_hx;
static float32 DW_abprep_Unit_Delay1_DSTATE_d;
static float32 DW_abprep_Unit_Delay_2_DSTATE_j;
static float32 DW_abprep_Unit_Delay_DSTATE_g;
static float32 DW_abprep_Unit_Delay1_DSTATE_op;
static float32 DW_abprep_Unit_Delay3_DSTATE_h;
static float32 DW_abprep_Unit_Delay2_DSTATE_ol;
static float32 DW_abprep_Unit_Delay1_DSTATE_fr;
static float32 DW_abprep_Unit_Delay_DSTATE_n5;
static float32 DW_abprep_Unit_Delay_DSTATE_nv;
static float32 DW_abprep_Unit_Delay1_DSTATE_hm;
static float32 DW_abprep_Unit_Delay_DSTATE_o;
static float32 DW_abprep_Unit_Delay_1_DSTATE;
static float32 DW_abprep_Unit_Delay1_DSTATE_d5;
static float32 DW_abprep_Unit_Delay_DSTATE_hb;
static float32 DW_abprep_Unit_Delay1_DSTATE_pf;
static float32 DW_abprep_Unit_Delay_DSTATE_a;
static float32 DW_abprep_Unit_Delay_1_DSTATE_e;
static float32 DW_abprep_Unit_Delay1_DSTATE_h4;
#define ABPREP_STOP_SEC_DATA_32
#include "ABPREP_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:ABPREP/ABPREP'/ABPREP_SenReset'
 * Block description for: 'sda:ABPREP/ABPREP'/ABPREP_SenReset'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_ABPREP_SenReset
#include "Pse_ABPREP.h"
/* Short description: Not synchronized with ARAMIS */
void ABPREP_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant1'/Constant' */
    SET_S_ABPREP_RiReClthCrvChng_1pm2(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant10'/Constant' */
    SET_S_ABPREP_LeReLength_met(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant11'/Constant' */
    SET_S_ABPREP_LeReClthPosX0_met(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant12'/Constant' */
    SET_S_ABPREP_LeReInvalidQu_btf(U16_MAX);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant13'/Constant' */
    SET_S_ABPREP_RiReInvalidQu_btf(U16_MAX);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant14'/Constant' */
    SET_S_ABPREP_LeRePosY0_met(10.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant15'/Constant' */
    SET_S_ABPREP_LeReClthPosY0SIF_met(10.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant16'/Constant' */
    SET_S_ABPREP_LeReClthHeadingSIF_rad(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant17'/Constant' */
    SET_S_ABPREP_LeReClthCrvSIF_1pm(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant18'/Constant' */
    SET_S_ABPREP_RiReClthPosY0SIF_met(-10.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant19'/Constant' */
    SET_S_ABPREP_RiReClthHeadingSIF_rad(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant2'/Constant' */
    SET_S_ABPREP_RiReClthCrv_1pm(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant20'/Constant' */
    SET_S_ABPREP_RiReClthCrvSIF_1pm(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant21'/Constant' */
    SET_S_ABPREP_LeReInvalidQuSIF_btf(U8_MAX);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant22'/Constant' */
    SET_S_ABPREP_RiReInvalidQuSIF_btf(U8_MAX);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant23'/Constant' */
    SET_S_ABPREP_LaneStabilization_btf(U8_MAX);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant24'/Constant' */
    SET_S_ABPREP_LnBndGradLimActive_btf(U8_MAX);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant25'/Constant' */
    SET_S_ABPREP_LeReLatVel_mps(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant26'/Constant' */
    SET_S_ABPREP_RiReLatVel_mps(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant27'/Constant' */
    SET_S_ABPREP_LeReQuality_perc(0U);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant28'/Constant' */
    SET_S_ABPREP_RiReQuality_perc(0U);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant29'/Constant' */
    SET_S_ABPREP_LeReKFStatus_enum(0U);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant3'/Constant' */
    SET_S_ABPREP_RiReHeading_rad(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant30'/Constant' */
    SET_S_ABPREP_LeReKFQuality_perc(0U);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant31'/Constant' */
    SET_S_ABPREP_RiReKFStatus_enum(0U);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant32'/Constant' */
    SET_S_ABPREP_RiReKFQuality_perc(0U);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant4'/Constant' */
    SET_S_ABPREP_RiRePosY0_met(-10.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant5'/Constant' */
    SET_S_ABPREP_RiReLength_met(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant6'/Constant' */
    SET_S_ABPREP_RiReClthPosX0_met(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant7'/Constant' */
    SET_S_ABPREP_LeReClthCrvChng_1pm2(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant8'/Constant' */
    SET_S_ABPREP_LeReClthCrv_1pm(0.0F);
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenReset/Constant9'/Constant' */
    SET_S_ABPREP_LeReHeading_rad(0.0F);
}
#include "Pse_ABPREP.h"
/*
 * Output and update for function-call system: 'sda:ABPREP/ABPREP'/ABPREP_SenProcess'
 * Block description for: 'sda:ABPREP/ABPREP'/ABPREP_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_ABPREP_SenProcess
#include "Pse_ABPREP.h"
/* Short description: Not synchronized with ARAMIS */
void ABPREP_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    roadEdgeKFInType rtb_LCFRoadEdgeKalmanFilterIn;
    roadEdgeKFOutType rtb_sfun_roadEdgeKalmanFilter_Right;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_Div;
    float32 rtb_Unit_Delay_f;
    float32 rtb_SFunction;
    float32 rtb_Div_o;
    float32 rtb_Unit_Delay1_n;
    float32 rtb_SFunction_e;
    float32 rtb_Mul_nl[2];
    float32 rtb_Div_a;
    float32 rtb_Unit_Delay_d;
    float32 rtb_SFunction_c;
    float32 rtb_Div_j;
    float32 rtb_Unit_Delay1_oo;
    float32 rtb_SFunction_o;
    uint16 rtb_sfun_setbit;
    uint16 rtb_sfun_setbit_e;
    uint16 rtb_sfun_setbit_p;
    uint8 rtb_SFunction_d;
    uint8 rtb_SFunction_h;
    uint8 rtb_VectorConcatenate_i[8];
    uint8 rtb_DataTypeConversion_nj;
    uint8 rtb_VectorConcatenate_p[8];
    uint8 rtb_DataTypeConversion_ks;
    uint8 rtb_sfun_setbit_e4;
    uint8 rtb_sfun_setbit_m;
    uint8 rtb_sfun_setbit_g;
    uint8 rtb_sfun_setbit_c;
    uint8 rtb_VectorConcatenate_m[15];
    uint8 rtb_VectorConcatenate_h[15];
    uint8 rtb_VectorConcatenate5[10];
    uint8 rtb_VectorConcatenate_o[15];
    uint8 rtb_VectorConcatenate_n[15];
    uint8 rtb_VectorConcatenate_mz[4];
    uint8 rtb_VectorConcatenate2_h[8];
    uint8 rtb_SFunction_k;
    uint8 rtb_SFunction_ec;
    uint8 rtb_sfun_setbit_cp;
    uint8 rtb_sfun_setbit_pz;
    uint8 rtb_DataTypeConversion_cj;
    float32 rtb_Switch_gne[2];
    float32 rtb_Sum_aq;
    uint8 rtb_Switch_fy[2];
    sint8 rtb_DataTypeConversion[2];
    float32 rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my;
    sint8 rtb_VectorConcatenate_f[2];
    float32 rtb_VectorConcatenate1[2];
    float32 rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
    float32 rtb_Switch6_dg[2];
    float32 rtb_VectorConcatenate2[2];
    float32 rtb_Mul_i4[2];
    float32 rtb_VectorConcatenate3[2];
    float32 rtb_VectorConcatenate4[2];
    uint8 rtb_VectorConcatenate7[2];
    uint8 rtb_Switch2_d[2];
    uint8 rtb_DataTypeConversion_md;
    uint8 rtb_DataTypeConversion_e;
    uint8 rtb_Switch_g;
    uint8 rtb_RelationalOperator1_ev;
    uint8 rtb_RelationalOperator1_kge;
    uint8 rtb_RelationalOperator1_mn;
    uint8 rtb_RelationalOperator1_ic;
    uint8 rtb_Switch_mr;
    float32 rtb_VectorConcatenate_l[2];
    uint8 rtb_DataTypeConversion_cp;
    uint8 rtb_DataTypeConversion_fa;
    float32 rtb__T_ABPREP_ReBnd_PosY0_met_h1;
    float32 rtb_Mul_a;
    float32 rtb_Abs_p[2];
    float32 rtb__T_ABPREP_ReBnd_Heading_rad;
    float32 rtb_Mul_fd;
    uint8 rtb_Switch3_d[2];
    float32 rtb_Abs_cb[2];
    float32 rtb__T_ABPREP_ReBnd_Crv_1pm;
    uint8 rtb_Switch3_jm[2];
    float32 rtb_Abs_i[2];
    uint8 rtb_Switch3_l[2];
    float32 rtb_VectorConcatenate4_j[2];
    uint8 rtb_Switch3_m4[2];
    uint8 rtb_DataTypeConversion_ea;
    uint8 rtb_DataTypeConversion_fp1;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_DataTypeConversion_l;
    uint8 rtb_DataTypeConversion_ok;
    uint8 rtb_DataTypeConversion_m;
    uint8 rtb_Switch_gj;
    uint8 rtb_RelationalOperator1_fl;
    uint8 rtb_RelationalOperator1_p3;
    uint8 rtb_RelationalOperator1_nw;
    uint8 rtb_RelationalOperator1_lmp;
    uint8 rtb_Switch_g2;
    uint8 rtb_DataTypeConversion_n;
    uint8 rtb_DataTypeConversion_ak;
    uint8 rtb_DataTypeConversion_p;
    uint8 rtb_DataTypeConversion_f;
    uint8 rtb_DataTypeConversion_ei;
    uint8 rtb_DataTypeConversion_et;
    uint8 rtb_DataTypeConversion_d;
    uint8 rtb_DataTypeConversion_nrt;
    uint8 rtb_DataTypeConversion_mv;
    uint8 rtb_DataTypeConversion_gg;
    uint8 rtb_DataTypeConversion_a;
    uint8 rtb_DataTypeConversion_pp;
    uint8 rtb_DataTypeConversion_bc;
    float32 rtb_Mul_as;
    float32 rtb_Mul_ns;
    uint8 rtb_RelationalOperator_ag;
    uint8 rtb_RelationalOperator1_ht;
    float32 rtb_Mul_k1;
    float32 rtb_Mul_nt;
    float32 rtb_Mul_k;
    float32 rtb_Mul_bl;
    float32 rtb_Mul_ls;
    float32 rtb__T_ABPREP_ReBnd_PosY0_met_ni;
    float32 rtb_VectorConcatenate1_m[2];
    float32 rtb__T_ABPREP_ReBnd_PosY0_met_l;
    float32 rtb_Switch_nr;
    uint8 rtb_Min;
    uint8 rtb_Min_p;
    float32 rtb_Max_en;
    float32 rtb_Switch2_el;
    float32 rtb_Switch2_e;
    float32 rtb_Switch2_k;
    uint8 rtb_Switch3_ok;
    float32 rtb_Switch2_f;
    float32 rtb_Switch2_pp;
    float32 rtb_Switch2_aj;
    float32 rtb_Switch2_lz;
    float32 rtb_Switch2_dr;
    float32 rtb_Switch2_gi;
    float32 rtb_Switch2_py;
    float32 rtb_Switch2_o;
    float32 rtb_Switch2_a;
    float32 rtb_Switch2_bl;
    float32 rtb_Switch2_de;
    float32 rtb_Switch2_lv;
    float32 rtb_Switch2_n;
    float32 rtb_Switch2_bn;
    float32 rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j;
    float32 rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i;
    float32 rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l;
    float32 rtb__T_ABPREP_ReBnd_Crv_1pm_bv;
    float32 rtb__T_ABPREP_ReBnd_Crv_1pm_ck;
    float32 rtb__T_ABPREP_ReBnd_Heading_rad_i3;
    float32 rtb__T_ABPREP_ReBnd_Heading_rad_c;
    float32 rtb__T_ABPREP_ReBnd_Heading_rad_i;
    float32 rtb_Switch1_i;
    float32 rtb_Switch_gcr;
    float32 rtb__T_ABPREP_ReBnd_PosY0_met_j2;
    float32 rtb_Switch1_o;
    float32 rtb_Switch_f2;
    float32 rtb__T_ABPREP_ReBnd_PosY0_met_m;
    uint8 rtb__T_ABPREP_ReBnd_PosX0_met_kt;
    float32 rtb_Switch1;
    float32 rtb_VectorConcatenate1_f[2];
    float32 rtb__T_ABPREP_ReBnd_PosY0_met_ly;
    float32 rtb__T_ABPREP_ReBnd_Length_met_c;
    float32 rtb__T_ABPREP_ReBnd_Length_met_pf;
    uint8 T_ABPREP_ReBnd_ExProb_perc;
    uint8 T_ABPREP_ReBnd_Available_bool;
    float32 T_ABPREP_ReBnd_PosY0_met;
    float32 T_ABPREP_ReBnd_PosY0_met_i;
    float32 T_ABPREP_ReBnd_Heading_rad;
    float32 T_ABPREP_ReBnd_Heading_rad_e;
    float32 T_ABPREP_ReBnd_Crv_1pm;
    float32 T_ABPREP_ReBnd_Crv_1pm_i;
    float32 T_ABPREP_ReBnd_CrvChng_1pm2;
    float32 T_ABPREP_ReBnd_CrvChng_1pm2_g;
    uint8 T_ABPREP_ReBnd_ExProb_perc_f;
    sint32 i;
    float32 rtb_VectorConcatenate2_n_idx_1;
    /* S-Function Block sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/Y_ABPREP_ThReClthMinValLen_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_ABPLBP_ThLnClthMinValLen_mps */
        FDPS_PTR_F32(GETA_X_ABPLBP_ThLnClthMinValLen_mps(), GET_S_LCFRCV_VehVelX_mps (), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_ABPREP_ThReClthMinValLen_met (), &x_dps);
    }
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/Y_ABPREP_ThReClthMinValLen_met/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/Y_ABPREP_ThReClthMinValLen_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb__T_ABPREP_ReBnd_PosY0_met_j2 = rtb_ip_lookup_fxpt_sfun_7;
    /* S-Function Block sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/Y_ABPREP_ThReMinValLenHyst_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_ABPLBP_ThLnClthMinValLen_mps */
        FDPS_PTR_F32(GETA_X_ABPLBP_ThLnClthMinValLen_mps(), GET_S_LCFRCV_VehVelX_mps (), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_ABPREP_ThReMinValLenHyst_met(), &x_dps);
    }
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/Y_ABPREP_ThReMinValLenHyst_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_aq = rtb__T_ABPREP_ReBnd_PosY0_met_j2 - rtb_ip_lookup_fxpt_sfun_7_l;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Constant6'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndLeftIndex_nu'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/GE/Functionality'/GE'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/LE/Functionality'/LE'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32) GET_S_LCFRCV_AnyBndLeftIndex_nu(2)) <= 9) && (((sint32) GET_S_LCFRCV_AnyBndLeftIndex_nu(2)) >= 0));
    /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Min/Functionality'/Min' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Constant4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndLeftIndex_nu'
         *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Max/Functionality'/Max'
         */
    rtb_Min = u8_s8(s8_min_s8_s8(s8_max_s8_s8(GET_S_LCFRCV_AnyBndLeftIndex_nu(2), 0), 9));
    /* If: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/If' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant4'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant7'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        /* Outputs for IfAction SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/MapLeftRoadEdgeData' incorporates:
                 *  ActionPort: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Action Port'
                 *
                 * Block description for 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/MapLeftRoadEdgeData':
                 *  X.2.1.1.1.1.4
                 */
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Selector1' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndYawAngle_rad'
                 */
        T_ABPREP_ReBnd_Heading_rad = GET_S_LCFRCV_AnyBndYawAngle_rad((rtb_Min));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Selector2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndCurvature_1pm'
                 */
        T_ABPREP_ReBnd_Crv_1pm = GET_S_LCFRCV_AnyBndCurvature_1pm((rtb_Min));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Selector3' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndCrvRate_1pm2'
                 */
        T_ABPREP_ReBnd_CrvChng_1pm2 = GET_S_LCFRCV_AnyBndCrvRate_1pm2((rtb_Min));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Selector4' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndValidLength_met'
                 */
        rtb__T_ABPREP_ReBnd_Length_met_c = GET_S_LCFRCV_AnyBndValidLength_met ((rtb_Min));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Selector5' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndQuality_nu'
                 */
        T_ABPREP_ReBnd_ExProb_perc = GET_S_LCFRCV_AnyBndQuality_nu((rtb_Min));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Selector7' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndDistance_met'
                 */
        T_ABPREP_ReBnd_PosY0_met = GET_S_LCFRCV_AnyBndDistance_met((rtb_Min));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Selector8' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndAvailable_bool'
                 */
        T_ABPREP_ReBnd_Available_bool = GET_S_LCFRCV_AnyBndAvailable_bool((rtb_Min));
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData/Constant1'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData/from_data_definition'/state_source'
                 *  Inport: '<Root>/S_LCFRCV_AnyBndMarkerType_nu'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData/EQ/Functionality'/EQ'
                 *  Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData'/Selector6'
                 */
        if (((sint32)GET_S_LCFRCV_AnyBndMarkerType_nu((rtb_Min))) == ((sint32) ((uint8)E_ABPR_AbdLnMarkersType2_ABD_MT_UNKNOWN))) {
            BI_abprep__T_ABPREP_ReBnd_Type_enum = 10U;
        } else {
            BI_abprep__T_ABPREP_ReBnd_Type_enum = GET_S_LCFRCV_AnyBndMarkerType_nu((rtb_Min));
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapLeftRoadEdgeData/Switch/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/MapLeftRoadEdgeData' */
    } else {
        /* Outputs for IfAction SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/ProvideDefaultLeftRoadEdgeData' incorporates:
                 *  ActionPort: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData'/Action Port'
                 *
                 * Block description for 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/ProvideDefaultLeftRoadEdgeData':
                 *  X.2.1.1.1.1.2
                 */
        T_ABPREP_ReBnd_PosY0_met = 7.5F;
        T_ABPREP_ReBnd_Heading_rad = 0.0F;
        T_ABPREP_ReBnd_Crv_1pm = 0.0F;
        T_ABPREP_ReBnd_CrvChng_1pm2 = 0.0F;
        rtb__T_ABPREP_ReBnd_Length_met_c = 0.0F;
        T_ABPREP_ReBnd_ExProb_perc = 0U;
        T_ABPREP_ReBnd_Available_bool = 0U;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/from_data_definition'/Signal Conversion3' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant1'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant2'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant3'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant4'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant5'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/Constant7'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultLeftRoadEdgeData/from_data_definition'/state_source'
                 */
        BI_abprep__T_ABPREP_ReBnd_Type_enum = ((uint8) E_ABPR_AbdLnMarkersType2_ABD_MT_NO_LINE);
        /* End of Outputs for SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/ProvideDefaultLeftRoadEdgeData' */
    }
    /* End of If: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/If' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch'
         */
    rtb_Switch_gne[0] = rtb__T_ABPREP_ReBnd_Length_met_c;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Constant5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Constant8'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndRightIndex_nu'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/GE1/Functionality'/GE'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/LE1/Functionality'/LE'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32) GET_S_LCFRCV_AnyBndRightIndex_nu(2)) <= 9) && (((sint32) GET_S_LCFRCV_AnyBndRightIndex_nu(2)) >= 0));
    /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Min1/Functionality'/Min' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Constant7'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndRightIndex_nu'
         *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/Max1/Functionality'/Max'
         */
    rtb_Min_p = u8_s8(s8_min_s8_s8(s8_max_s8_s8(GET_S_LCFRCV_AnyBndRightIndex_nu(2), 0), 9));
    /* If: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/If1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant4'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant7'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        /* Outputs for IfAction SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/MapRightRoadEdgeData' incorporates:
                 *  ActionPort: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Action Port'
                 *
                 * Block description for 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/MapRightRoadEdgeData':
                 *  X.2.1.1.1.1.1
                 */
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Selector1' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndYawAngle_rad'
                 */
        T_ABPREP_ReBnd_Heading_rad_e = GET_S_LCFRCV_AnyBndYawAngle_rad((rtb_Min_p));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Selector2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndCurvature_1pm'
                 */
        T_ABPREP_ReBnd_Crv_1pm_i = GET_S_LCFRCV_AnyBndCurvature_1pm((rtb_Min_p));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Selector3' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndCrvRate_1pm2'
                 */
        T_ABPREP_ReBnd_CrvChng_1pm2_g = GET_S_LCFRCV_AnyBndCrvRate_1pm2((rtb_Min_p));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Selector4' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndValidLength_met'
                 */
        rtb__T_ABPREP_ReBnd_Length_met_pf = GET_S_LCFRCV_AnyBndValidLength_met ((rtb_Min_p));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Selector5' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndQuality_nu'
                 */
        T_ABPREP_ReBnd_ExProb_perc_f = GET_S_LCFRCV_AnyBndQuality_nu((rtb_Min_p));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Selector7' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndDistance_met'
                 */
        T_ABPREP_ReBnd_PosY0_met_i = GET_S_LCFRCV_AnyBndDistance_met((rtb_Min_p));
        /* Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Selector8' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AnyBndAvailable_bool'
                 */
        rtb_Min = GET_S_LCFRCV_AnyBndAvailable_bool((rtb_Min_p));
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData/Constant1'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData/from_data_definition'/state_source'
                 *  Inport: '<Root>/S_LCFRCV_AnyBndMarkerType_nu'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData/EQ/Functionality'/EQ'
                 *  Selector: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData'/Selector6'
                 */
        if (((sint32)GET_S_LCFRCV_AnyBndMarkerType_nu((rtb_Min_p))) == ((sint32) ((uint8)E_ABPR_AbdLnMarkersType2_ABD_MT_UNKNOWN))) {
            BI_abprep__T_ABPREP_ReBnd_Type_enum_b = 10U;
        } else {
            BI_abprep__T_ABPREP_ReBnd_Type_enum_b = GET_S_LCFRCV_AnyBndMarkerType_nu ((rtb_Min_p));
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/MapRightRoadEdgeData/Switch/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/MapRightRoadEdgeData' */
    } else {
        /* Outputs for IfAction SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/ProvideDefaultRightRoadEdgeData' incorporates:
                 *  ActionPort: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData'/Action Port'
                 *
                 * Block description for 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/ProvideDefaultRightRoadEdgeData':
                 *  X.2.1.1.1.1.3
                 */
        T_ABPREP_ReBnd_PosY0_met_i = -7.5F;
        T_ABPREP_ReBnd_Heading_rad_e = 0.0F;
        T_ABPREP_ReBnd_Crv_1pm_i = 0.0F;
        T_ABPREP_ReBnd_CrvChng_1pm2_g = 0.0F;
        rtb__T_ABPREP_ReBnd_Length_met_pf = 0.0F;
        T_ABPREP_ReBnd_ExProb_perc_f = 0U;
        rtb_Min = 0U;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/from_data_definition'/Signal Conversion3' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant1'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant2'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant3'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant4'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant5'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/Constant7'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges/ProvideDefaultRightRoadEdgeData/from_data_definition'/state_source'
                 */
        BI_abprep__T_ABPREP_ReBnd_Type_enum_b = ((uint8) E_ABPR_AbdLnMarkersType2_ABD_MT_NO_LINE);
        /* End of Outputs for SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/ProvideDefaultRightRoadEdgeData' */
    }
    /* End of If: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/RoadEdgeInputDataMapping/ReorganizeRoadEdges'/If1' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength'/ConcatBufferAtVector ConcatenateIn2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch'
         */
    rtb_Switch_gne[1] = rtb__T_ABPREP_ReBnd_Length_met_pf;
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/RSFLIPFLOP/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/RSFLIPFLOP/Functionality'/Constant'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/GT/Functionality'/GT'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/GT1/Functionality'/GT'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/RSFLIPFLOP/Functionality'/Switch1'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength'/Unit_Delay'
                 */
        if (rtb_Sum_aq > rtb_Switch_gne[i]) {
            rtb_Min_p = 0U;
        } else if (rtb_Switch_gne[i] > rtb__T_ABPREP_ReBnd_PosY0_met_j2) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/RSFLIPFLOP/Functionality'/Constant1'
                         */
            rtb_Min_p = 1U;
        } else {
            rtb_Min_p = DW_abprep_Unit_Delay_DSTATE_cvn[i];
        }
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/NOT/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/NOT/Functionality'/NOT'
                 */
        rtb_DataTypeConversion[i] = (sint8)(!(((sint32)rtb_Min_p) != 0));
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength/RSFLIPFLOP/Functionality'/Switch' */
        rtb_Switch_fy[i] = rtb_Min_p;
    }
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_o[0] = (uint8)rtb_DataTypeConversion[0];
    /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/Constant4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Sum_aq = f32_max_f32_f32(GET_S_LCFRCV_SysCycleTimeSen_sec(), 1.0E-5F);
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/P_ABPREP_LaneKFErrCoeff1_met'/Constant'
         */
    rtb__T_ABPREP_ReBnd_PosY0_met_j2 = GET_P_ABPREP_ReQualGradLimLU_nu() * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/P_ABPREP_LaneKFErrCoeff1_met'/Constant'
         */
    rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my = GET_P_ABPREP_ReQualPenGradLimLU_nu() * rtb_Sum_aq;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_f[0] = (sint8)T_ABPREP_ReBnd_Available_bool;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_f[1] = (sint8)rtb_Min;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1[0] = T_ABPREP_ReBnd_PosY0_met;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate1[1] = T_ABPREP_ReBnd_PosY0_met_i;
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met1'/Constant'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_lr = GET_P_ABPREP_ReQualDistanceMaxTh_met() - GET_P_ABPREP_ReQualDistanceMinTh_met();
    /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/Max/Functionality'/Max' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/Abs/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/Application Parameter1'/Constant'
         */
    rtb_Max_en = f32_max_f32_f32(f32_abs_f32(rtb__T_ABPREP_ReBnd_Crv_1pm_lr), 1.0E-15F);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/Application Parameter2'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/Neg/Functionality'/Unary Minus'
         */
    if (rtb__T_ABPREP_ReBnd_Crv_1pm_lr < 0.0F) {
        rtb_Max_en = -rtb_Max_en;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/Switch/Functionality'/Switch' */
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Constant1'/Constant'
         */
    rtb_Max_en = 1.0F / rtb_Max_en;
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Sum5/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Constant4'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Mul4/Functionality'/Mul'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_lr = 1.0F - (rtb_Max_en * GET_P_ABPREP_ReQualDistanceMaxTh_met());
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Sum4/Functionality'/Sum' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Abs3/Functionality'/Abs'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Mul3/Functionality'/Mul'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay'
         */
    for (i = 0; i < 2; i++) {
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP'/Functionality'
                 */
        rtb_Switch_gne[i] = (f32_abs_f32(rtb_VectorConcatenate1[i] - DW_abprep_Unit_Delay_DSTATE_n[i]) * rtb_Max_en) + rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP'/fcg' */
    }
    /* End of Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Sum4/Functionality'/Sum' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector Concatenate2In1' */
    rtb_VectorConcatenate2[0] = T_ABPREP_ReBnd_Heading_rad;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector Concatenate2In2' */
    rtb_VectorConcatenate2[1] = T_ABPREP_ReBnd_Heading_rad_e;
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met4'/Constant'
         */
    rtb_Max_en = GET_P_ABPREP_ReQualHeadingMaxTh_rad() - GET_P_ABPREP_ReQualHeadingMinTh_rad();
    /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/Max/Functionality'/Max' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/Abs/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/Application Parameter1'/Constant'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_lr = f32_max_f32_f32(f32_abs_f32(rtb_Max_en), 1.0E-15F);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/Application Parameter2'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/Neg/Functionality'/Unary Minus'
         */
    if (rtb_Max_en < 0.0F) {
        rtb_Max_en = -rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
    } else {
        rtb_Max_en = rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/Switch/Functionality'/Switch' */
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Constant1'/Constant'
         */
    rtb_Max_en = 1.0F / rtb_Max_en;
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Sum5/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Constant4'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Mul4/Functionality'/Mul'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_lr = 1.0F - (rtb_Max_en * GET_P_ABPREP_ReQualHeadingMaxTh_rad());
    for (i = 0; i < 2; i++) {
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP1'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP1'/Functionality'
                 */
        /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Sum4/Functionality'/Sum' incorporates:
                 *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Abs1/Functionality'/Abs'
                 *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Mul3/Functionality'/Mul'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay1'
                 */
        rtb_Switch2_o = (f32_abs_f32(rtb_VectorConcatenate2[i] - DW_abprep_Unit_Delay1_DSTATE[i]) * rtb_Max_en) + rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP1'/fcg' */
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Limit/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Limit'/MX'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Limit/Functionality'/Relational Operator'
                 */
        if (1.0F >= rtb_Switch2_o) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Limit/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Limit'/MN'
                         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Limit/Functionality'/Relational Operator1'
                         */
            if (!(0.0F <= rtb_Switch2_o)) {
                rtb_Switch2_o = 0.0F;
            }
            /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Limit/Functionality'/Switch1' */
        } else {
            rtb_Switch2_o = 1.0F;
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem3/Limit/Functionality'/Switch' */
        /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Mul4/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met5'/Constant'
                 */
        rtb_Mul_i4[i] = rtb_Switch2_o * GET_P_ABPREP_ReQualHeadingWeight_nu();
    }
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector Concatenate3In1' */
    rtb_VectorConcatenate3[0] = T_ABPREP_ReBnd_Crv_1pm;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector Concatenate3In2' */
    rtb_VectorConcatenate3[1] = T_ABPREP_ReBnd_Crv_1pm_i;
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met6'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met7'/Constant'
         */
    rtb_Max_en = GET_P_ABPREP_ReQualCrvMaxTh_1pm() - GET_P_ABPREP_ReQualCrvMinTh_1pm();
    /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/Max/Functionality'/Max' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/Abs/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/Application Parameter1'/Constant'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_lr = f32_max_f32_f32(f32_abs_f32(rtb_Max_en), 1.0E-15F);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/Application Parameter2'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/Neg/Functionality'/Unary Minus'
         */
    if (rtb_Max_en < 0.0F) {
        rtb_Max_en = -rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
    } else {
        rtb_Max_en = rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/Switch/Functionality'/Switch' */
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Constant1'/Constant'
         */
    rtb_Max_en = 1.0F / rtb_Max_en;
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Sum5/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met6'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Constant4'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Mul4/Functionality'/Mul'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_lr = 1.0F - (rtb_Max_en * GET_P_ABPREP_ReQualCrvMaxTh_1pm());
    for (i = 0; i < 2; i++) {
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP3'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP3'/Functionality'
                 */
        /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Sum4/Functionality'/Sum' incorporates:
                 *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Abs2/Functionality'/Abs'
                 *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Mul3/Functionality'/Mul'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP3/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay3'
                 */
        rtb_Switch2_o = (f32_abs_f32(rtb_VectorConcatenate3[i] - DW_abprep_Unit_Delay3_DSTATE[i]) * rtb_Max_en) + rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP3'/fcg' */
        /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Sum1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met10'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met2'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Limit'/MX'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Limit'/MX'
                 *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Mul1/Functionality'/Mul'
                 *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Mul3/Functionality'/Mul'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Limit/Functionality'/Relational Operator'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Limit/Functionality'/Relational Operator'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Sum/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Limit/Functionality'/Switch'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Limit/Functionality'/Switch'
                 */
        if (1.0F >= rtb_Switch_gne[i]) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Limit/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Limit'/MN'
                         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Limit/Functionality'/Relational Operator1'
                         */
            if (0.0F <= rtb_Switch_gne[i]) {
                rtb_VectorConcatenate2_n_idx_1 = rtb_Switch_gne[i];
            } else {
                rtb_VectorConcatenate2_n_idx_1 = 0.0F;
            }
            /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem4/Limit/Functionality'/Switch1' */
        } else {
            rtb_VectorConcatenate2_n_idx_1 = 1.0F;
        }
        if (1.0F >= rtb_Switch2_o) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Limit/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Limit'/MN'
                         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Limit/Functionality'/Relational Operator1'
                         */
            if (!(0.0F <= rtb_Switch2_o)) {
                rtb_Switch2_o = 0.0F;
            }
            /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem2/Limit/Functionality'/Switch1' */
        } else {
            rtb_Switch2_o = 1.0F;
        }
        rtb_Switch_gne[i] = ((rtb_VectorConcatenate2_n_idx_1 * GET_P_ABPREP_ReQualDistanceWeight_nu()) + rtb_Mul_i4[i]) + (rtb_Switch2_o * GET_P_ABPREP_ReQualCrvWeight_nu());
        /* End of Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Sum1/Functionality'/Sum' */
    }
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector Concatenate4In1' */
    rtb_VectorConcatenate4[0] = T_ABPREP_ReBnd_CrvChng_1pm2;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/ConcatBufferAtVector Concatenate4In2' */
    rtb_VectorConcatenate4[1] = T_ABPREP_ReBnd_CrvChng_1pm2_g;
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met8'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met9'/Constant'
         */
    rtb_Max_en = GET_P_ABPREP_ReQualCrvRateMaxTh_1pm2() - GET_P_ABPREP_ReQualCrvRateMinTh_1pm2();
    /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/Max/Functionality'/Max' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/Abs/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/Application Parameter1'/Constant'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_lr = f32_max_f32_f32(f32_abs_f32(rtb_Max_en), 1.0E-15F);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/Application Parameter2'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/Neg/Functionality'/Unary Minus'
         */
    if (rtb_Max_en < 0.0F) {
        rtb_Max_en = -rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
    } else {
        rtb_Max_en = rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/Switch/Functionality'/Switch' */
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Constant1'/Constant'
         */
    rtb_Max_en = 1.0F / rtb_Max_en;
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Sum5/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met8'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Constant4'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Mul4/Functionality'/Mul'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_lr = 1.0F - (rtb_Max_en * GET_P_ABPREP_ReQualCrvRateMaxTh_1pm2());
    for (i = 0; i < 2; i++) {
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP2'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP2'/Functionality'
                 */
        /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Sum4/Functionality'/Sum' incorporates:
                 *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Abs4/Functionality'/Abs'
                 *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Mul3/Functionality'/Mul'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP2/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay2'
                 */
        rtb_Switch2_o = (f32_abs_f32(rtb_VectorConcatenate4[i] - DW_abprep_Unit_Delay2_DSTATE[i]) * rtb_Max_en) + rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP2'/fcg' */
        /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/P_ABPREP_LaneKFErrCoeff1_met12'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Limit'/MX'
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/NOT/Functionality'/NOT'
                 *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Mul2/Functionality'/Mul'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI/Functionality'/Relational Operator'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Limit/Functionality'/Relational Operator'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Sum2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Limit/Functionality'/Switch'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay4'
                 */
        if (1.0F >= rtb_Switch2_o) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Limit/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Limit'/MN'
                         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Limit/Functionality'/Relational Operator1'
                         */
            if (!(0.0F <= rtb_Switch2_o)) {
                rtb_Switch2_o = 0.0F;
            }
            /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Limit/Functionality'/Switch1' */
        } else {
            rtb_Switch2_o = 1.0F;
        }
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/Functionality'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm = ((rtb_Switch2_o * GET_P_ABPREP_ReQualCrvRateWeight_nu()) + rtb_Switch_gne[i]) * ((float32) (!(((sint32)rtb_VectorConcatenate_f[i]) != ((sint32) DW_abprep_Unit_Delay4_DSTATE_e[i]))));
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/fcg' */
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/constant_value3'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/constant_value4'/Constant'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GT/Functionality'/GT'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination'/Unit_Delay'
                 */
        if (rtb__T_ABPREP_ReBnd_Crv_1pm > 0.0F) {
            rtb__T_ABPREP_ReBnd_Crv_1pm += DW_abprep_Unit_Delay_DSTATE_m[i];
        } else {
            rtb__T_ABPREP_ReBnd_Crv_1pm = 0.0F;
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/Switch/Functionality'/Switch' */
        /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/Min1/Functionality'/Min' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/P_ABPREP_LaneKFErrCoeff1_met3'/Constant'
                 */
        rtb_Switch2_o = f32_min_f32_f32(rtb__T_ABPREP_ReBnd_Crv_1pm, GET_P_ABPREP_ReQualPenHoldFactor_nu());
        /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Subsystem1/Sum4/Functionality'/Sum' */
        rtb_Switch6_dg[i] = rtb_Switch2_o;
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/Functionality'
                 */
        /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/Mul/Functionality'/Mul' incorporates:
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI/Functionality'/Relational Operator'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Add/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination'/Unit_Delay'
                 */
        rtb_Switch_gne[i] = rtb_Switch2_o - DW_abprep_Unit_Delay_DSTATE_m[i];
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/fcg' */
    }
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/P_ABPREP_LaneKFErrCoeff1_met1'/Constant'
         */
    rtb_Max_en = GET_P_ABPREP_ReQualPenGradLimLD_nu() * rtb_Sum_aq;
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator1'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination'/Unit_Delay'
                 */
        rtb_Switch2_o = rtb_Switch6_dg[i];
        if (rtb_Switch_gne[i] < rtb_Max_en) {
            rtb_Switch2_o = rtb_Max_en + DW_abprep_Unit_Delay_DSTATE_m[i];
        }
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination'/Unit_Delay'
                 */
        if (rtb_Switch_gne[i] > rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my) {
            rtb_Switch2_o = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my + DW_abprep_Unit_Delay_DSTATE_m[i];
        }
        rtb_Mul_i4[i] = rtb_Switch2_o;
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' */
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/P_ABPREP_LaneKFErrCoeff1_met2'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/constant_value6'/Constant'
                 *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/Min/Functionality'/Min'
                 *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/Mul/Functionality'/Mul'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator1'
                 */
        rtb_Switch6_dg[i] = f32_min_f32_f32(100.0F, rtb_Switch2_o * GET_P_ABPREP_ReQualPenFactor_nu());
    }
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/DivByZeroProtectionDefault/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/P_ABPREP_LaneKFErrCoeff1_met'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/DivByZeroProtectionDefault/Application Parameter2'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/DivByZeroProtectionDefault/Div/Functionality/Div'/Div'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/DivByZeroProtectionDefault/GT/Functionality'/GT'
         */
    if (GET_P_ABPREP_ReQualValidLength_met() > 1.0E-15F) {
        /* MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/DivByZeroProtectionDefault/Max/Functionality'/Max' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/DivByZeroProtectionDefault/Application Parameter1'/Constant'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my = f32_max_f32_f32(1.0E-15F, GET_P_ABPREP_ReQualValidLength_met());
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality'/ConcatBufferAtVector Concatenate1In2' */
        rtb_VectorConcatenate1_f[1] = rtb__T_ABPREP_ReBnd_Length_met_pf;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality'/ConcatBufferAtVector Concatenate1In1' */
        rtb_VectorConcatenate1_f[0] = rtb__T_ABPREP_ReBnd_Length_met_c;
        for (i = 0; i < 2; i++) {
            rtb_Switch_gne[i] = rtb_VectorConcatenate1_f[i] / rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my;
        }
    } else {
        for (i = 0; i < 2; i++) {
            rtb_Switch_gne[i] = 0.0F;
        }
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/DivByZeroProtectionDefault/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality'/ConcatBufferAtVector Concatenate7In1' */
    rtb_VectorConcatenate7[0] = T_ABPREP_ReBnd_Available_bool;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality'/ConcatBufferAtVector Concatenate7In2' */
    rtb_VectorConcatenate7[1] = rtb_Min;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_Switch2_d[0] = T_ABPREP_ReBnd_ExProb_perc;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_Switch2_d[1] = T_ABPREP_ReBnd_ExProb_perc_f;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/P_ABPREP_LaneKFErrCoeff1_met1'/Constant'
         */
    rtb_Max_en = GET_P_ABPREP_ReQualGradLimLD_nu() * rtb_Sum_aq;
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/Constant'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/Constant2'/Constant'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/GT/Functionality'/GT'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm = rtb_Switch_gne[i];
        if (rtb_Switch_gne[i] > 1.0F) {
            rtb__T_ABPREP_ReBnd_Crv_1pm = 1.0F;
        }
        /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/Mul/Functionality'/Mul' */
        rtb__T_ABPREP_ReBnd_Crv_1pm *= 100.0F;
        /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/Constant1'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/Constant2'/Constant'
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/AND/Functionality'/AND'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/GT/Functionality'/GT'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/GT1/Functionality'/GT'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/Sum/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/Switch/Functionality'/Switch'
                 */
        if (rtb_Switch6_dg[i] > rtb__T_ABPREP_ReBnd_Crv_1pm) {
            rtb_Switch2_o = 0.0F;
        } else {
            rtb_Switch2_o = rtb__T_ABPREP_ReBnd_Crv_1pm - rtb_Switch6_dg[i];
        }
        rtb_Switch2_o *= (float32)((((sint32)rtb_VectorConcatenate7[i]) != 0) && (((sint32)rtb_Switch2_d[i]) > 0));
        /* End of Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/Mul/Functionality'/Mul' */
        /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation'/Unit_Delay'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm = rtb_Switch2_o - DW_abprep_Unit_Delay_DSTATE[i];
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation'/Unit_Delay'
                 */
        if (rtb__T_ABPREP_ReBnd_Crv_1pm < rtb_Max_en) {
            rtb_Switch2_o = rtb_Max_en + DW_abprep_Unit_Delay_DSTATE[i];
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation'/Unit_Delay'
                 */
        if (rtb__T_ABPREP_ReBnd_Crv_1pm > rtb__T_ABPREP_ReBnd_PosY0_met_j2) {
            rtb__T_ABPREP_ReBnd_Crv_1pm = rtb__T_ABPREP_ReBnd_PosY0_met_j2 + DW_abprep_Unit_Delay_DSTATE[i];
        } else {
            rtb__T_ABPREP_ReBnd_Crv_1pm = rtb_Switch2_o;
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/Switch/Functionality'/Switch' incorporates:
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/LookaheadDistanceQuality/GT/Functionality'/GT'
                 */
        rtb_Switch_gne[i] = rtb__T_ABPREP_ReBnd_Crv_1pm;
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/DTC1'/Data Type Conversion' */
        rtb_VectorConcatenate7[i] = u8_f32(rtb__T_ABPREP_ReBnd_Crv_1pm);
    }
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Relational Operator1'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality'/Unit_Delay'
         */
    if (((sint32)rtb_VectorConcatenate7[0]) > ((sint32) GET_P_ABPREP_MinRoadEdgeQualRSP_perc())) {
        rtb_Min_p = 1U;
    } else if (((sint32)rtb_VectorConcatenate7[0]) < ((sint32) GET_P_ABPREP_MinRoadEdgeQualLSP_perc())) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Min_p = 0U;
    } else {
        rtb_Min_p = DW_abprep_Unit_Delay_DSTATE_e;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Switch3' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/P_ABPREP_LaneKFErrCoeff1_met5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/constant_value1'/Constant'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeQuality_nu()) != 0) {
        rtb_DataTypeConversion_cj = rtb_Min_p;
    } else {
        rtb_DataTypeConversion_cj = 1U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/Constant5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality/GT/Functionality'/GT'
         */
    rtb_DataTypeConversion_md = (uint8)((((sint32)T_ABPREP_ReBnd_ExProb_perc) > ((sint32)GET_P_ABPREP_MinRoadEdgeABDQual_perc())) && (((sint32) rtb_DataTypeConversion_cj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_md) != 0) && (((sint32)T_ABPREP_ReBnd_Available_bool) != 0));
    /* BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterIn' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFStdDevCrvRt_1pm2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFStdDevCrv_1pm'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFStdDevLatDist_met'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFStdDevYawRt_radps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFStdDevYaw_rad'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/constant_value1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/constant_value2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/Max/Functionality'/Max'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_LCFRoadEdgeKalmanFilterIn.sf_PosY0_met = T_ABPREP_ReBnd_PosY0_met;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_HeadingAngle_rad = -T_ABPREP_ReBnd_Heading_rad;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_Crv_1pm = T_ABPREP_ReBnd_Crv_1pm;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_CrvChng_1pm2 = T_ABPREP_ReBnd_CrvChng_1pm2;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_Length_met = 0.0F;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_PosY0StdDev_met = GET_P_ABPREP_LaneKFStdDevLatDist_met();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_HeadingAngleStdDev_rad = GET_P_ABPREP_LaneKFStdDevYaw_rad();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_CrvStdDev_1pm = GET_P_ABPREP_LaneKFStdDevCrv_1pm();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_CrvChngStdDev_1pm2 = GET_P_ABPREP_LaneKFStdDevCrvRt_1pm2();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_VehYawRateStdDev_radps = GET_P_ABPREP_LaneKFStdDevYawRt_radps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_VehVelX_mps = f32_max_f32_f32 (GET_S_LCFRCV_VehVelX_mps(), GET_P_ABPREP_MinVelForKalmanFilt_mps());
    rtb_LCFRoadEdgeKalmanFilterIn.sf_VehYawRate_radps = GET_S_LCFRCV_VehYawRate_rps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_DeltaT_sec = rtb_Sum_aq;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneDataValid_bool = rtb_DataTypeConversion_cj;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_DegradedUpdate_bool = 0U;
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met5'/Constant'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeQuality_nu()) != 0) {
        /* BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterIn' */
        rtb_LCFRoadEdgeKalmanFilterIn.sf_OverallMeasurementQuality_perc = rtb_VectorConcatenate7[0];
    } else {
        /* BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterIn' incorporates:
                 *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Mul/Functionality'/Mul'
                 */
        rtb_LCFRoadEdgeKalmanFilterIn.sf_OverallMeasurementQuality_perc = u8_u32 (((uint32)((sint32)rtb_DataTypeConversion_md)) * 100U);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch/Functionality'/Switch' */
    /* BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterIn' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFDecQualDeg_1ps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFDecQualPred_1ps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFDegradeWeight_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFDynCrvFactor_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFDynCrvRtFactor_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFDynDistYFact_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFDynYawFactor_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFErrCoeff1_met'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFErrCoeff2_mps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFIncQual_1ps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFInitRFactor_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFKGainFac_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFMnInitQual_perc'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/P_ABPREP_LaneKFMnUpdateQual_perc'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft/constant_value'/Constant'
         */
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneChange_bool = 0U;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFErrCoeff1_met = GET_P_ABPREP_LaneKFErrCoeff1_met();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFErrCoeff2_mps = GET_P_ABPREP_LaneKFErrCoeff2_mps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFInitRFactor_nu = GET_P_ABPREP_LaneKFInitRFactor_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDegradeWeight_nu = GET_P_ABPREP_LaneKFDegradeWeight_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFMnUpdateQual_perc = GET_P_ABPREP_LaneKFMnUpdateQual_perc();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFMnInitQual_perc = GET_P_ABPREP_LaneKFMnInitQual_perc();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFIncQual_1ps = GET_P_ABPREP_LaneKFIncQual_1ps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDecQualDeg_1ps = GET_P_ABPREP_LaneKFDecQualDeg_1ps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDecQualPred_1ps = GET_P_ABPREP_LaneKFDecQualPred_1ps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFKGainFac_nu = GET_P_ABPREP_LaneKFKGainFac_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDynYawFactor_nu = GET_P_ABPREP_LaneKFDynYawFactor_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDynDistYFact_nu = GET_P_ABPREP_LaneKFDynDistYFact_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDynCrvFact_nu = GET_P_ABPREP_LaneKFDynCrvFactor_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDynCrvRateFact_nu = GET_P_ABPREP_LaneKFDynCrvRtFactor_nu();
    /* S-Function (sfun_roadEdgeKalmanFilter_Left): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/sfun_roadEdgeKalmanFilter_Left' */
    roadEdgeKalmanFilter_Left((roadEdgeKFInType*)&rtb_LCFRoadEdgeKalmanFilterIn, &rtb_sfun_roadEdgeKalmanFilter_Right);
    /* BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterOut' */
    rtb_Switch2_o = rtb_sfun_roadEdgeKalmanFilter_Right.sf_HeadingAngle_rad;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch40'/copy1' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterOut'
         */
    SET_S_ABPREP_LeReKFStatus_enum (rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch41'/copy1' incorporates:
                                                               *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterOut'
                                                               */
    SET_S_ABPREP_LeReKFQuality_perc (rtb_sfun_roadEdgeKalmanFilter_Right.sf_QualityMeasure_perc);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/Switch/Functionality'/Switch' incorporates:
                                                                      *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterOut'
                                                                      *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/P_ABPREP_LaneKFErrCoeff1_met8'/Constant'
                                                                      *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/from_data_definition1'/state_source'
                                                                      *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/from_data_definition2'/state_source'
                                                                      *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/from_data_definition3'/state_source'
                                                                      *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/from_data_definition4'/state_source'
                                                                      *  DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/OR/Functionality'/Data Type Conversion'
                                                                      *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/OR/Functionality'/OR'
                                                                      *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EQ/Functionality'/EQ'
                                                                      *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EQ1/Functionality'/EQ'
                                                                      *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EQ2/Functionality'/EQ'
                                                                      *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EQ3/Functionality'/EQ'
                                                                      *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch'
                                                                      */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb_Switch_g = (uint8)((((((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_INITIALIZATION))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_FULL_UPDATE)))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_DEGR_UPDATE)))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_PREDICTION))));
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my = rtb_sfun_roadEdgeKalmanFilter_Right.sf_PosY0_met;
    } else {
        rtb_Switch_g = T_ABPREP_ReBnd_Available_bool;
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my = T_ABPREP_ReBnd_PosY0_met;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/NOT1/Functionality'/NOT'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/OR1/Functionality'/OR'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/NOT/Functionality'/NOT'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression'/Unit_Delay4'
         */
    rtb_DataTypeConversion_e = (uint8)(!(((!(((sint32) DW_abprep_Unit_Delay4_DSTATE_l) != 0)) && (((sint32)rtb_Switch_g) != 0)) || (!(((sint32)rtb_Switch_g) != 0))));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Abs/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Application Parameter10'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Relational Operator/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay4'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_e) != 0) && (f32_abs_f32(rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my - DW_abprep_Unit_Delay4_DSTATE) > GET_P_ABPREP_DistYLimitStepDtct_met()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/Application Parameter9'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb__T_ABPREP_ReBnd_Crv_1pm_lr = GET_P_ABPREP_DurValidDistYStep_sec();
    } else if (DW_abprep_Unit_Delay_DSTATE_c > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_lr = DW_abprep_Unit_Delay_DSTATE_c - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_lr = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Constant'
         */
    rtb_RelationalOperator1_ev = (uint8)(rtb__T_ABPREP_ReBnd_Crv_1pm_lr > 0.0F);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_o[1] = rtb_RelationalOperator1_ev;
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met3'/Constant'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb__T_ABPREP_ReBnd_Crv_1pm = rtb_sfun_roadEdgeKalmanFilter_Right.sf_Crv_1pm;
    } else {
        rtb__T_ABPREP_ReBnd_Crv_1pm = T_ABPREP_ReBnd_Crv_1pm;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP2'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Abs2/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Application Parameter1'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Relational Operator2/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP2/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay6'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_e) != 0) && (f32_abs_f32(rtb__T_ABPREP_ReBnd_Crv_1pm - DW_abprep_Unit_Delay6_DSTATE) > GET_P_ABPREP_CrvLimStepDtct_1pm()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP2'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/Application Parameter8'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay2'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Switch2_el = GET_P_ABPREP_DurValidCrvStep_sec();
    } else if (DW_abprep_Unit_Delay2_DSTATE_o > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay2'
                 */
        rtb_Switch2_el = DW_abprep_Unit_Delay2_DSTATE_o - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Constant2'
                 */
        rtb_Switch2_el = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Constant'
         */
    rtb_RelationalOperator1_kge = (uint8)(rtb_Switch2_el > 0.0F);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_o[2] = rtb_RelationalOperator1_kge;
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met3'/Constant'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Neg/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb__T_ABPREP_ReBnd_Heading_rad = -rtb_sfun_roadEdgeKalmanFilter_Right.sf_HeadingAngle_rad;
    } else {
        rtb__T_ABPREP_ReBnd_Heading_rad = T_ABPREP_ReBnd_Heading_rad;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP1'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Abs1/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Application Parameter4'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Relational Operator1/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP1/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay5'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_e) != 0) && (f32_abs_f32(rtb__T_ABPREP_ReBnd_Heading_rad - DW_abprep_Unit_Delay5_DSTATE) > GET_P_ABPREP_HeadLimStepDtct_rad()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP1'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/Application Parameter7'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Switch2_e = GET_P_ABPREP_DurValidHeadingStep_sec();
    } else if (DW_abprep_Unit_Delay1_DSTATE_g > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay1'
                 */
        rtb_Switch2_e = DW_abprep_Unit_Delay1_DSTATE_g - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 */
        rtb_Switch2_e = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_mn = (uint8)(rtb_Switch2_e > 0.0F);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_o[3] = rtb_RelationalOperator1_mn;
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met3'/Constant'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        T_ABPREP_ReBnd_CrvChng_1pm2 = rtb_sfun_roadEdgeKalmanFilter_Right.sf_CrvChng_1pm2;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP6'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP6'/Functionality'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Abs6/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/Application Parameter4'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Application Parameter6'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND6/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Relational Operator2'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Relational Operator6/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP6/Functionality/Sum/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay6'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay1'
         */
    if ((((sint32)rtb_DataTypeConversion_e) != 0) && (f32_abs_f32 (T_ABPREP_ReBnd_CrvChng_1pm2 - DW_abprep_Unit_Delay1_DSTATE_l) > GET_P_ABPREP_CrvRateLimStepDtct_1pm2())) {
        rtb_Switch2_k = GET_P_ABPREP_DurValidCrvRateStep_sec();
    } else if (DW_abprep_Unit_Delay6_DSTATE_e > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay6'
                 */
        rtb_Switch2_k = DW_abprep_Unit_Delay6_DSTATE_e - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Constant2'
                 */
        rtb_Switch2_k = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP6'/fcg' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE6/Functionality'/Constant'
         */
    rtb_RelationalOperator1_ic = (uint8)(rtb_Switch2_k > 0.0F);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_o[4] = rtb_RelationalOperator1_ic;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_o[5] = (uint8)(!(((sint32)rtb_DataTypeConversion_md) != 0));
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckLeftRoadEdgeType/get_bit/Functionality'/S-Function' */
    rtb_SFunction_d = flag_get_u16_u8(GET_P_ABPREP_ValidReTypeBitmask_nu(), BI_abprep__T_ABPREP_ReBnd_Type_enum);
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_o[6] = (uint8)(!(((sint32)rtb_SFunction_d) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_o[7] = (uint8)(!(((sint32) T_ABPREP_ReBnd_Available_bool) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/AND/Functionality'/Data Type Conversion' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterLeft'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/from_data_definition1'/state_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/from_data_definition2'/state_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/from_data_definition3'/state_source'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/AND/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/GE/Functionality'/GE'
         */
    rtb_DataTypeConversion_e = (uint8)((((((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_FULL_UPDATE))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_DEGR_UPDATE)))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_PREDICTION)))) && (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_QualityMeasure_perc) >= ((sint32) GET_P_ABPREP_KalmanMinQuality_perc())));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met8'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/constant_value4'/Constant'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb_Switch_mr = rtb_DataTypeConversion_e;
    } else {
        rtb_Switch_mr = 1U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch5/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_o[8] = (uint8)(!(((sint32)rtb_Switch_mr) != 0));
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_l[0] = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my;
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Relational Operator1'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality'/Unit_Delay'
         */
    if (((sint32)rtb_VectorConcatenate7[1]) > ((sint32) GET_P_ABPREP_MinRoadEdgeQualRSP_perc())) {
        rtb_Switch3_ok = 1U;
    } else if (((sint32)rtb_VectorConcatenate7[1]) < ((sint32) GET_P_ABPREP_MinRoadEdgeQualLSP_perc())) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3_ok = 0U;
    } else {
        rtb_Switch3_ok = DW_abprep_Unit_Delay_DSTATE_al;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/HYSTERESIS/Functionality'/Switch3' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/P_ABPREP_LaneKFErrCoeff1_met5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/constant_value1'/Constant'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeQuality_nu()) != 0) {
        rtb_DataTypeConversion_cj = rtb_Switch3_ok;
    } else {
        rtb_DataTypeConversion_cj = 1U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/Constant5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality/GT/Functionality'/GT'
         */
    rtb_DataTypeConversion_cp = (uint8)((((sint32)T_ABPREP_ReBnd_ExProb_perc_f) > ((sint32)GET_P_ABPREP_MinRoadEdgeABDQual_perc())) && (((sint32) rtb_DataTypeConversion_cj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_cp) != 0) && (((sint32)rtb_Min) != 0));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met1'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Mul1/Functionality'/Mul'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeQuality_nu()) != 0) {
        rtb_DataTypeConversion_fa = rtb_VectorConcatenate7[1];
    } else {
        rtb_DataTypeConversion_fa = u8_u32(((uint32)((sint32) rtb_DataTypeConversion_cp)) * 100U);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch1/Functionality'/Switch' */
    /* BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterIn' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFDecQualDeg_1ps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFDecQualPred_1ps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFDegradeWeight_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFDynCrvFactor_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFDynCrvRtFactor_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFDynDistYFact_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFDynYawFactor_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFErrCoeff1_met'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFErrCoeff2_mps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFIncQual_1ps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFInitRFactor_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFKGainFac_nu'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFMnInitQual_perc'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFMnUpdateQual_perc'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFStdDevCrvRt_1pm2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFStdDevCrv_1pm'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFStdDevLatDist_met'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFStdDevYawRt_radps'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/P_ABPREP_LaneKFStdDevYaw_rad'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/constant_value'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/constant_value1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/constant_value2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/Max/Functionality'/Max'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/Neg/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight/Neg2/Functionality'/Unary Minus'
         */
    rtb_LCFRoadEdgeKalmanFilterIn.sf_PosY0_met = -T_ABPREP_ReBnd_PosY0_met_i;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_HeadingAngle_rad = -T_ABPREP_ReBnd_Heading_rad_e;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_Crv_1pm = T_ABPREP_ReBnd_Crv_1pm_i;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_CrvChng_1pm2 = T_ABPREP_ReBnd_CrvChng_1pm2_g;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_Length_met = 0.0F;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_PosY0StdDev_met = GET_P_ABPREP_LaneKFStdDevLatDist_met();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_HeadingAngleStdDev_rad = GET_P_ABPREP_LaneKFStdDevYaw_rad();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_CrvStdDev_1pm = GET_P_ABPREP_LaneKFStdDevCrv_1pm();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_CrvChngStdDev_1pm2 = GET_P_ABPREP_LaneKFStdDevCrvRt_1pm2();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_VehYawRateStdDev_radps = GET_P_ABPREP_LaneKFStdDevYawRt_radps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_VehVelX_mps = f32_max_f32_f32 (GET_S_LCFRCV_VehVelX_mps(), GET_P_ABPREP_MinVelForKalmanFilt_mps());
    rtb_LCFRoadEdgeKalmanFilterIn.sf_VehYawRate_radps = GET_S_LCFRCV_VehYawRate_rps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_DeltaT_sec = rtb_Sum_aq;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneDataValid_bool = rtb_DataTypeConversion_cj;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_DegradedUpdate_bool = 0U;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_OverallMeasurementQuality_perc = rtb_DataTypeConversion_fa;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneChange_bool = 0U;
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFErrCoeff1_met = GET_P_ABPREP_LaneKFErrCoeff1_met();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFErrCoeff2_mps = GET_P_ABPREP_LaneKFErrCoeff2_mps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFInitRFactor_nu = GET_P_ABPREP_LaneKFInitRFactor_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDegradeWeight_nu = GET_P_ABPREP_LaneKFDegradeWeight_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFMnUpdateQual_perc = GET_P_ABPREP_LaneKFMnUpdateQual_perc();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFMnInitQual_perc = GET_P_ABPREP_LaneKFMnInitQual_perc();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFIncQual_1ps = GET_P_ABPREP_LaneKFIncQual_1ps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDecQualDeg_1ps = GET_P_ABPREP_LaneKFDecQualDeg_1ps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDecQualPred_1ps = GET_P_ABPREP_LaneKFDecQualPred_1ps();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFKGainFac_nu = GET_P_ABPREP_LaneKFKGainFac_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDynYawFactor_nu = GET_P_ABPREP_LaneKFDynYawFactor_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDynDistYFact_nu = GET_P_ABPREP_LaneKFDynDistYFact_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDynCrvFact_nu = GET_P_ABPREP_LaneKFDynCrvFactor_nu();
    rtb_LCFRoadEdgeKalmanFilterIn.sf_LaneKFDynCrvRateFact_nu = GET_P_ABPREP_LaneKFDynCrvRtFactor_nu();
    /* S-Function (sfun_roadEdgeKalmanFilter_Right): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/sfun_roadEdgeKalmanFilter_Right' */
    roadEdgeKalmanFilter_Right((roadEdgeKFInType*)&rtb_LCFRoadEdgeKalmanFilterIn, &rtb_sfun_roadEdgeKalmanFilter_Right);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met6'/Constant'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Neg2/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb__T_ABPREP_ReBnd_PosY0_met_h1 = -rtb_sfun_roadEdgeKalmanFilter_Right.sf_PosY0_met;
    } else {
        rtb__T_ABPREP_ReBnd_PosY0_met_h1 = T_ABPREP_ReBnd_PosY0_met_i;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch' */
    /* Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Abs/Functionality'/Abs' */
    rtb_VectorConcatenate_l[1] = f32_abs_f32(rtb__T_ABPREP_ReBnd_PosY0_met_h1);
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant4'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant6'/Constant'
         */
    rtb_Mul_a = GET_P_ABPREP_MaxRangeHyst_nu() * GET_P_ABPREP_MaxDistYRange_met();
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Switch3' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant4'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Constant1'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Relational Operator'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Relational Operator1'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Switch2'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay'
                 */
        if (rtb_VectorConcatenate_l[i] > GET_P_ABPREP_MaxDistYRange_met()) {
            rtb_DataTypeConversion_cj = 1U;
        } else if (rtb_VectorConcatenate_l[i] < rtb_Mul_a) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Constant'
                         */
            rtb_DataTypeConversion_cj = 0U;
        } else {
            rtb_DataTypeConversion_cj = DW_abprep_Unit_Delay_DSTATE_hs[i];
        }
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Signal Conversion1' */
        rtb_VectorConcatenate5[i] = rtb_DataTypeConversion_cj;
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS/Functionality'/Switch3' */
        rtb_Switch2_d[i] = rtb_DataTypeConversion_cj;
    }
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector Concatenate1In1' */
    rtb_Abs_p[0] = rtb__T_ABPREP_ReBnd_Heading_rad;
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met6'/Constant'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Neg1/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb_Mul_a = -rtb_sfun_roadEdgeKalmanFilter_Right.sf_HeadingAngle_rad;
    } else {
        rtb_Mul_a = T_ABPREP_ReBnd_Heading_rad_e;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector Concatenate1In2' */
    rtb_Abs_p[1] = rtb_Mul_a;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant7'/Constant'
         */
    rtb_Mul_fd = GET_P_ABPREP_MaxRangeHyst_nu() * GET_P_ABPREP_MaxHeadingRange_rad ();
    for (i = 0; i < 2; i++) {
        /* Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Abs3/Functionality'/Abs' */
        rtb_Max_en = f32_abs_f32(rtb_Abs_p[i]);
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Switch3' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant1'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Constant1'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Relational Operator'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Relational Operator1'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Switch2'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay1'
                 */
        if (rtb_Max_en > GET_P_ABPREP_MaxHeadingRange_rad()) {
            rtb_DataTypeConversion_cj = 1U;
        } else if (rtb_Max_en < rtb_Mul_fd) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Constant'
                         */
            rtb_DataTypeConversion_cj = 0U;
        } else {
            rtb_DataTypeConversion_cj = DW_abprep_Unit_Delay1_DSTATE_os[i];
        }
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Signal Conversion1' */
        rtb_VectorConcatenate5[i + 2] = rtb_DataTypeConversion_cj;
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS1/Functionality'/Switch3' */
        rtb_Switch3_d[i] = rtb_DataTypeConversion_cj;
    }
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector Concatenate2In1' */
    rtb_Abs_cb[0] = rtb__T_ABPREP_ReBnd_Crv_1pm;
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met6'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb_Mul_fd = rtb_sfun_roadEdgeKalmanFilter_Right.sf_Crv_1pm;
        T_ABPREP_ReBnd_CrvChng_1pm2_g = rtb_sfun_roadEdgeKalmanFilter_Right.sf_CrvChng_1pm2;
    } else {
        rtb_Mul_fd = T_ABPREP_ReBnd_Crv_1pm_i;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector Concatenate2In2' */
    rtb_Abs_cb[1] = rtb_Mul_fd;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Mul2/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant8'/Constant'
         */
    rtb_Max_en = GET_P_ABPREP_MaxRangeHyst_nu() * GET_P_ABPREP_MaxCurvatureRange_1pm();
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector Concatenate3In1' */
    rtb_Abs_i[0] = T_ABPREP_ReBnd_CrvChng_1pm2;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector Concatenate3In2' */
    rtb_Abs_i[1] = T_ABPREP_ReBnd_CrvChng_1pm2_g;
    for (i = 0; i < 2; i++) {
        /* Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Abs2/Functionality'/Abs' */
        rtb_Switch2_f = f32_abs_f32(rtb_Abs_cb[i]);
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Switch3' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant2'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Constant1'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Relational Operator'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Relational Operator1'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Switch2'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay2'
                 */
        if (rtb_Switch2_f > GET_P_ABPREP_MaxCurvatureRange_1pm()) {
            rtb_DataTypeConversion_cj = 1U;
        } else if (rtb_Switch2_f < rtb_Max_en) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Constant'
                         */
            rtb_DataTypeConversion_cj = 0U;
        } else {
            rtb_DataTypeConversion_cj = DW_abprep_Unit_Delay2_DSTATE_bb[i];
        }
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Signal Conversion1' */
        rtb_VectorConcatenate5[i + 4] = rtb_DataTypeConversion_cj;
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS2/Functionality'/Switch3' */
        rtb_Switch3_jm[i] = rtb_DataTypeConversion_cj;
        /* Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Abs1/Functionality'/Abs' */
        rtb_Abs_i[i] = f32_abs_f32(rtb_Abs_i[i]);
    }
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Mul3/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant9'/Constant'
         */
    rtb_Max_en = GET_P_ABPREP_MaxRangeHyst_nu() * GET_P_ABPREP_MaxCrvRateRange_1pm2();
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Switch3' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant3'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Constant1'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Relational Operator'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Relational Operator1'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Switch2'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay3'
                 */
        if (rtb_Abs_i[i] > GET_P_ABPREP_MaxCrvRateRange_1pm2()) {
            rtb_DataTypeConversion_cj = 1U;
        } else if (rtb_Abs_i[i] < rtb_Max_en) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Constant'
                         */
            rtb_DataTypeConversion_cj = 0U;
        } else {
            rtb_DataTypeConversion_cj = DW_abprep_Unit_Delay3_DSTATE_m[i];
        }
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Signal Conversion1' */
        rtb_VectorConcatenate5[i + 6] = rtb_DataTypeConversion_cj;
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS3/Functionality'/Switch3' */
        rtb_Switch3_l[i] = rtb_DataTypeConversion_cj;
    }
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector Concatenate4In1' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch2/Functionality'/Switch'
         */
    rtb_VectorConcatenate4_j[0] = rtb__T_ABPREP_ReBnd_Length_met_c;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/ConcatBufferAtVector Concatenate4In2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch3/Functionality'/Switch'
         */
    rtb_VectorConcatenate4_j[1] = rtb__T_ABPREP_ReBnd_Length_met_pf;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Mul4/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant10'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant5'/Constant'
         */
    rtb_Max_en = GET_P_ABPREP_MaxRangeHyst_nu() * GET_P_ABPREP_MaxValidLengthRange_met();
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Switch3' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/Constant5'/Constant'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Constant1'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Relational Operator'
                 *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Relational Operator1'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Switch2'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay4'
                 */
        if (rtb_VectorConcatenate4_j[i] > GET_P_ABPREP_MaxValidLengthRange_met()) {
            rtb_DataTypeConversion_cj = 1U;
        } else if (rtb_VectorConcatenate4_j[i] < rtb_Max_en) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Constant'
                         */
            rtb_DataTypeConversion_cj = 0U;
        } else {
            rtb_DataTypeConversion_cj = DW_abprep_Unit_Delay4_DSTATE_o[i];
        }
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Signal Conversion1' */
        rtb_VectorConcatenate5[i + 8] = rtb_DataTypeConversion_cj;
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/HYSTERESIS4/Functionality'/Switch3' */
        rtb_Switch3_m4[i] = rtb_DataTypeConversion_cj;
    }
    /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[10] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate5[0];
                for (i1=0; i1 < 10; i1++) {
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
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit1/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit1/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_fa = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)0U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit1/Functionality'/DTC_out' */
    rtb_VectorConcatenate_o[9] = rtb_DataTypeConversion_fa;
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit6/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit6/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_fa = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)2U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit6/Functionality'/DTC_out' */
    rtb_VectorConcatenate_o[10] = rtb_DataTypeConversion_fa;
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit7/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit7/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_fa = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)4U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit7/Functionality'/DTC_out' */
    rtb_VectorConcatenate_o[11] = rtb_DataTypeConversion_fa;
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit8/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit8/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_fa = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)6U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit8/Functionality'/DTC_out' */
    rtb_VectorConcatenate_o[12] = rtb_DataTypeConversion_fa;
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit9/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit9/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_fa = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)8U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/get_bit9/Functionality'/DTC_out' */
    rtb_VectorConcatenate_o[13] = rtb_DataTypeConversion_fa;
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Application Parameter1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Application Parameter3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Constant1'/Constant'
         *  DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/NOT1/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_LCFRCV_CBWeatherCond_enum'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/NOT1/Functionality'/NOT'
         *  S-Function (sfix_bitop): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/AND1/Functionality'/AND'
         */
    if (((sint32)GET_P_ABPREP_UseCBWeatherCond_bool()) != 0) {
        rtb_DataTypeConversion_fa = (uint8)(!((((sint32) GET_S_LCFRCV_CBWeatherCond_enum()) & ((sint32) GET_P_ABPREP_ValidCBWeatherCond_btf())) != 0));
    } else {
        rtb_DataTypeConversion_fa = 1U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Application Parameter10'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Constant7'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/from_data_definition'/state_source'
         *  Inport: '<Root>/S_LCFRCV_LDCompState_enum'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Relational Operator/Functionality'/EQ'
         */
    if (((sint32)GET_P_ABPREP_UseLDAlgoCompState_bool()) != 0) {
        rtb_DataTypeConversion_cj = (uint8)(((sint32)GET_S_LCFRCV_LDCompState_enum ()) == ((sint32)((uint8)E_ABPR_AlgoCompStateV2_COMP_ST_RUNNING)));
    } else {
        rtb_DataTypeConversion_cj = 1U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLDAlgoCompStateAndCBWeatherCondition/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_fa = (uint8)((((sint32)rtb_DataTypeConversion_fa) != 0) && (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_o[14] = (uint8)(!(((sint32)rtb_DataTypeConversion_fa) != 0));
    /* S-Function (sfun_or): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/OR/Functionality'/sfun_or' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_VectorConcatenate_o[0];
        for (i1=1; i1<15; i1++) {
            temp = temp | rtb_VectorConcatenate_o[i1];
        }
        rtb_DataTypeConversion_cj = temp;
    }
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ea = (uint8)(!(((sint32)rtb_DataTypeConversion_cj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/NOT5/Functionality'/NOT'
         */
    rtb_DataTypeConversion_cj = (uint8)(!(((sint32)rtb_DataTypeConversion_ea) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/Constant2'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/Unit_Delay'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/Unit_Delay1'
         */
    if ((((sint32)DW_abprep_Unit_Delay_DSTATE_mn) != 0) && (!(((sint32) rtb_DataTypeConversion_ea) != 0))) {
        rtb_Switch2_f = GET_P_ABPREP_MaxLaneBridgingTime_sec();
    } else if (DW_abprep_Unit_Delay1_DSTATE_n > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/Unit_Delay1'
                 */
        rtb_Switch2_f = DW_abprep_Unit_Delay1_DSTATE_n - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_f = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP'/Unit_Delay'
         */
    rtb_DataTypeConversion_fp1 = (uint8)(((((sint32)rtb_DataTypeConversion_cj) != 0) && (rtb_Switch2_f > 0.0F)) && (((sint32)DW_abprep_Unit_Delay_1_DSTATE_k) != 0));
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my - GET_S_ABPLBP_LeLnClthPosY0_met();
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/constant_value1'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/LT2/Functionality'/LT'
         */
    rtb_DataTypeConversion_cj = (uint8)((rtb_Max_en > 0.0F) && (rtb_Max_en < GET_P_ABPREP_Lane2ReDistThresh_met()));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/OR2/Functionality'/OR'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_fp1) != 0) || (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_o = (uint8)((((sint32)rtb_DataTypeConversion_ea) != 0) || (((sint32)rtb_DataTypeConversion_fp1) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Abs3/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/constant_value'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/LT1/Functionality'/LT'
         */
    rtb_DataTypeConversion_l = (uint8)((((((sint32)rtb_DataTypeConversion_cj) != 0) && (((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) == 0)) && (f32_abs_f32 (GET_S_ABPLBP_LeLnClthCrv_1pm()) < GET_P_ABPREP_LaneMaxCrv_1pm())) && (((sint32)rtb_DataTypeConversion_o) != 0));
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my - GET_S_ABPLBP_RiLnClthPosY0_met();
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Constant4'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/LT4/Functionality'/LT'
         */
    rtb_DataTypeConversion_cj = (uint8)((GET_P_ABPREP_MinLatDistStabilize_met() < rtb_Max_en) && (rtb_Max_en < GET_P_ABPREP_MaxLatDistStabilize_met()));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_fp1) != 0) || (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Abs1/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Constant5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/constant_value2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/AND3/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/LT3/Functionality'/LT'
         */
    rtb_DataTypeConversion_ok = (uint8)(((((((sint32)rtb_DataTypeConversion_cj) != 0) && (((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) == 0)) && (f32_abs_f32 (GET_S_ABPLBP_RiLnClthCrv_1pm()) < GET_P_ABPREP_LaneMaxCrv_1pm())) && (((sint32)rtb_DataTypeConversion_o) != 0)) && (!(((sint32) rtb_DataTypeConversion_l) != 0)));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_m = (uint8)((((sint32)rtb_DataTypeConversion_l) != 0) || (((sint32)rtb_DataTypeConversion_ok) != 0));
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/LaneStabilizationBitfieldGeneration'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_mz[0] = rtb_DataTypeConversion_m;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_n[0] = (uint8)rtb_DataTypeConversion[1];
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/Switch/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/P_ABPREP_LaneKFErrCoeff1_met8'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/from_data_definition1'/state_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/from_data_definition2'/state_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/from_data_definition3'/state_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/from_data_definition4'/state_source'
         *  DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/OR/Functionality'/Data Type Conversion'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EQ3/Functionality'/EQ'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb_Switch_gj = (uint8)((((((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_INITIALIZATION))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_FULL_UPDATE)))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_DEGR_UPDATE)))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_PREDICTION))));
    } else {
        rtb_Switch_gj = rtb_Min;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/NOT1/Functionality'/NOT'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/OR1/Functionality'/OR'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/NOT1/Functionality'/NOT'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1'/Unit_Delay4'
         */
    rtb__T_ABPREP_ReBnd_PosX0_met_kt = (uint8)(!(((!(((sint32) DW_abprep_Unit_Delay4_DSTATE_b) != 0)) && (((sint32)rtb_Switch_gj) != 0)) || ( !(((sint32)rtb_Switch_gj) != 0))));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP5'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP5'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Abs3/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Application Parameter5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND5/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Relational Operator3/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP5/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay9'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32) rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) && (f32_abs_f32 (rtb__T_ABPREP_ReBnd_PosY0_met_h1 - DW_abprep_Unit_Delay9_DSTATE) > GET_P_ABPREP_DistYLimitStepDtct_met()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP5'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/Application Parameter1'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay5'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Switch2_pp = GET_P_ABPREP_DurValidDistYStep_sec();
    } else if (DW_abprep_Unit_Delay5_DSTATE_p > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay5'
                 */
        rtb_Switch2_pp = DW_abprep_Unit_Delay5_DSTATE_p - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Constant2'
                 */
        rtb_Switch2_pp = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE5/Functionality'/Constant'
         */
    rtb_RelationalOperator1_fl = (uint8)(rtb_Switch2_pp > 0.0F);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_n[1] = rtb_RelationalOperator1_fl;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP4'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP4'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Abs4/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Application Parameter2'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Relational Operator4/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP4/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay8'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32) rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) && (f32_abs_f32(rtb_Mul_a - DW_abprep_Unit_Delay8_DSTATE) > GET_P_ABPREP_HeadLimStepDtct_rad()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP4'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/Application Parameter2'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Switch2_aj = GET_P_ABPREP_DurValidHeadingStep_sec();
    } else if (DW_abprep_Unit_Delay4_DSTATE_k > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay4'
                 */
        rtb_Switch2_aj = DW_abprep_Unit_Delay4_DSTATE_k - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Constant2'
                 */
        rtb_Switch2_aj = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE4/Functionality'/Constant'
         */
    rtb_RelationalOperator1_p3 = (uint8)(rtb_Switch2_aj > 0.0F);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_n[2] = rtb_RelationalOperator1_p3;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP3'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP3'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Abs5/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Application Parameter3'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND3/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Relational Operator5/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP3/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay7'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32) rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) && (f32_abs_f32(rtb_Mul_fd - DW_abprep_Unit_Delay7_DSTATE) > GET_P_ABPREP_CrvLimStepDtct_1pm()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP3'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/Application Parameter3'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay3'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Switch2_lz = GET_P_ABPREP_DurValidCrvStep_sec();
    } else if (DW_abprep_Unit_Delay3_DSTATE_j > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay3'
                 */
        rtb_Switch2_lz = DW_abprep_Unit_Delay3_DSTATE_j - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Constant2'
                 */
        rtb_Switch2_lz = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE3/Functionality'/Constant'
         */
    rtb_RelationalOperator1_nw = (uint8)(rtb_Switch2_lz > 0.0F);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_n[3] = rtb_RelationalOperator1_nw;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP7'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP7'/Functionality'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Abs7/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/Application Parameter5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Application Parameter7'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/AND7/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Relational Operator2'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/Relational Operator7/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP7/Functionality/Sum/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay7'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay2'
         */
    if ((((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) && (f32_abs_f32 (T_ABPREP_ReBnd_CrvChng_1pm2_g - DW_abprep_Unit_Delay2_DSTATE_n) > GET_P_ABPREP_CrvRateLimStepDtct_1pm2())) {
        rtb_Switch2_dr = GET_P_ABPREP_DurValidCrvRateStep_sec();
    } else if (DW_abprep_Unit_Delay7_DSTATE_m > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay7'
                 */
        rtb_Switch2_dr = DW_abprep_Unit_Delay7_DSTATE_m - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Constant2'
                 */
        rtb_Switch2_dr = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP7'/fcg' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE7/Functionality'/Constant'
         */
    rtb_RelationalOperator1_lmp = (uint8)(rtb_Switch2_dr > 0.0F);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_n[4] = rtb_RelationalOperator1_lmp;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[5] = (uint8)(!(((sint32)rtb_DataTypeConversion_cp) != 0));
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckLeftRoadEdgeType/get_bit/Functionality'/S-Function' */
    rtb_SFunction_h = flag_get_u16_u8(GET_P_ABPREP_ValidReTypeBitmask_nu(), BI_abprep__T_ABPREP_ReBnd_Type_enum_b);
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[6] = (uint8)(!(((sint32)rtb_SFunction_h) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[7] = (uint8)(!(((sint32)rtb_Min) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/AND1/Functionality'/Data Type Conversion' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met4'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/from_data_definition4'/state_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/from_data_definition5'/state_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/from_data_definition6'/state_source'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/AND1/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/GE1/Functionality'/GE'
         */
    rtb__T_ABPREP_ReBnd_PosX0_met_kt = (uint8)((((((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_FULL_UPDATE))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_DEGR_UPDATE)))) || (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf) == ((sint32)((uint8) E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_PREDICTION)))) && (((sint32) rtb_sfun_roadEdgeKalmanFilter_Right.sf_QualityMeasure_perc) >= ((sint32) GET_P_ABPREP_KalmanMinQuality_perc())));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/P_ABPREP_LaneKFErrCoeff1_met7'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/constant_value3'/Constant'
         */
    if (((sint32)GET_P_ABPREP_UseRoadEdgeKalman_nu()) != 0) {
        rtb_Switch_g2 = rtb__T_ABPREP_ReBnd_PosX0_met_kt;
    } else {
        rtb_Switch_g2 = 1U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[8] = (uint8)(!(((sint32)rtb_Switch_g2) != 0));
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit5/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit5/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_cj = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)1U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit5/Functionality'/DTC_out' */
    rtb_VectorConcatenate_n[9] = rtb_DataTypeConversion_cj;
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit6/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit6/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_cj = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)3U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit6/Functionality'/DTC_out' */
    rtb_VectorConcatenate_n[10] = rtb_DataTypeConversion_cj;
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit7/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit7/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_cj = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)5U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit7/Functionality'/DTC_out' */
    rtb_VectorConcatenate_n[11] = rtb_DataTypeConversion_cj;
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit8/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit8/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_cj = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)7U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit8/Functionality'/DTC_out' */
    rtb_VectorConcatenate_n[12] = rtb_DataTypeConversion_cj;
    /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit9/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit9/Functionality'/Const_bit_sel_param'
         */
    rtb_DataTypeConversion_cj = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)9U));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/get_bit9/Functionality'/DTC_out' */
    rtb_VectorConcatenate_n[13] = rtb_DataTypeConversion_cj;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[14] = (uint8)(!(((sint32)rtb_DataTypeConversion_fa) != 0));
    /* S-Function (sfun_or): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/OR/Functionality'/sfun_or' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_VectorConcatenate_n[0];
        for (i1=1; i1<15; i1++) {
            temp = temp | rtb_VectorConcatenate_n[i1];
        }
        rtb_DataTypeConversion_cj = temp;
    }
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_n = (uint8)(!(((sint32)rtb_DataTypeConversion_cj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/NOT5/Functionality'/NOT'
         */
    rtb_DataTypeConversion_cj = (uint8)(!(((sint32)rtb_DataTypeConversion_n) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/Constant2'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/Unit_Delay'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/Unit_Delay1'
         */
    if ((((sint32)DW_abprep_Unit_Delay_DSTATE_k1) != 0) && (!(((sint32) rtb_DataTypeConversion_n) != 0))) {
        rtb_Switch2_gi = GET_P_ABPREP_MaxLaneBridgingTime_sec();
    } else if (DW_abprep_Unit_Delay1_DSTATE_p > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/Unit_Delay1'
                 */
        rtb_Switch2_gi = DW_abprep_Unit_Delay1_DSTATE_p - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_gi = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP'/Unit_Delay'
         */
    rtb_DataTypeConversion_ak = (uint8)(((((sint32)rtb_DataTypeConversion_cj) != 0) && (rtb_Switch2_gi > 0.0F)) && (((sint32)DW_abprep_Unit_Delay_2_DSTATE_m) != 0));
    /* Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Sum1/Functionality'/Sum'
         */
    rtb_Max_en = f32_abs_f32(rtb__T_ABPREP_ReBnd_PosY0_met_h1 - GET_S_ABPLBP_LeLnClthPosY0_met());
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Constant4'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/LT4/Functionality'/LT'
         */
    rtb_DataTypeConversion_cj = (uint8)((GET_P_ABPREP_MinLatDistStabilize_met() < rtb_Max_en) && (rtb_Max_en < GET_P_ABPREP_MaxLatDistStabilize_met()));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_ak) != 0) || (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/OR2/Functionality'/OR'
         */
    rtb_DataTypeConversion_p = (uint8)((((sint32)rtb_DataTypeConversion_n) != 0) || (((sint32)rtb_DataTypeConversion_ak) != 0));
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         */
    rtb_Max_en = GET_S_ABPLBP_RiLnClthPosY0_met() - rtb__T_ABPREP_ReBnd_PosY0_met_h1;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/constant_value1'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/LT2/Functionality'/LT'
         */
    rtb_sfun_setbit_pz = (uint8)((rtb_Max_en > 0.0F) && (rtb_Max_en < GET_P_ABPREP_Lane2ReDistThresh_met()));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/OR2/Functionality'/OR'
         */
    rtb_sfun_setbit_pz = (uint8)((((sint32)rtb_DataTypeConversion_ak) != 0) || (((sint32)rtb_sfun_setbit_pz) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Abs2/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/constant_value'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/LT1/Functionality'/LT'
         */
    rtb_DataTypeConversion_f = (uint8)((((((sint32)rtb_sfun_setbit_pz) != 0) && (((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) == 0)) && (f32_abs_f32 (GET_S_ABPLBP_RiLnClthCrv_1pm()) < GET_P_ABPREP_LaneMaxCrv_1pm())) && (((sint32)rtb_DataTypeConversion_p) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/NOT/Functionality'/NOT'
         */
    rtb_sfun_setbit_pz = (uint8)(!(((sint32)rtb_DataTypeConversion_f) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Abs3/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Constant5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/constant_value2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/AND3/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/LT3/Functionality'/LT'
         */
    rtb_DataTypeConversion_ei = (uint8)(((((((sint32)rtb_DataTypeConversion_cj) != 0) && (((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) == 0)) && (f32_abs_f32 (GET_S_ABPLBP_LeLnClthCrv_1pm()) < GET_P_ABPREP_LaneMaxCrv_1pm())) && (((sint32)rtb_DataTypeConversion_p) != 0)) && (((sint32)rtb_sfun_setbit_pz) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_et = (uint8)((((sint32)rtb_DataTypeConversion_ei) != 0) || (((sint32)rtb_DataTypeConversion_f) != 0));
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/LaneStabilizationBitfieldGeneration'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_mz[1] = rtb_DataTypeConversion_et;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/NOT1/Functionality'/NOT'
         */
    rtb_sfun_setbit_pz = (uint8)(!(((sint32)T_ABPREP_ReBnd_Available_bool) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/OR1/Functionality'/OR'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression'/Unit_Delay4'
         */
    rtb_sfun_setbit_pz = (uint8)(((!(((sint32)DW_abprep_Unit_Delay4_DSTATE_g) != 0)) && (((sint32)T_ABPREP_ReBnd_Available_bool) != 0)) || (((sint32) rtb_sfun_setbit_pz) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/NOT3/Functionality'/NOT'
         */
    rtb_DataTypeConversion_cj = (uint8)(!(((sint32)rtb_sfun_setbit_pz) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Abs/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Application Parameter3'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Relational Operator/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay'
         */
    rtb_DataTypeConversion_cj = (uint8)((((sint32)rtb_DataTypeConversion_cj) != 0) && (f32_abs_f32(T_ABPREP_ReBnd_PosY0_met - DW_abprep_Unit_Delay_DSTATE_k) > GET_P_ABPREP_DistYLimitStepDtct_met()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/Application Parameter1'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Switch2_py = GET_P_ABPREP_SIFJumpDebounceT_sec();
    } else if (DW_abprep_Unit_Delay_DSTATE_f > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay'
                 */
        rtb_Switch2_py = DW_abprep_Unit_Delay_DSTATE_f - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_py = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Constant'
         */
    rtb_VectorConcatenate_i[0] = (uint8)(rtb_Switch2_py > 0.0F);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SIFHeadingSelection/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SIFHeadingSelection/Constant1'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SIFHeadingSelection/AND/Functionality'/AND'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Neg3/Functionality'/Unary Minus'
         */
    if ((((sint32)rtb_DataTypeConversion_e) != 0) && (((sint32) GET_P_ABPREP_SIFUseKalmanHead_bool()) != 0)) {
        T_ABPREP_ReBnd_Heading_rad = -rtb_Switch2_o;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SIFHeadingSelection/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/NOT2/Functionality'/NOT'
         */
    rtb_sfun_setbit_pz = (uint8)(!(((sint32)rtb_sfun_setbit_pz) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/Functionality'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Abs1/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/Application Parameter2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Application Parameter5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator11/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Relational Operator1/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1/Functionality/Sum/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay1'
         */
    if ((f32_abs_f32(T_ABPREP_ReBnd_Heading_rad - DW_abprep_Unit_Delay1_DSTATE_m) > GET_P_ABPREP_HeadLimStepDtct_rad()) && (((sint32)rtb_sfun_setbit_pz) != 0)) {
        rtb_Switch2_o = GET_P_ABPREP_SIFJumpDebounceT_sec();
    } else if (DW_abprep_Unit_Delay1_DSTATE_o > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay1'
                 */
        rtb_Switch2_o = DW_abprep_Unit_Delay1_DSTATE_o - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 */
        rtb_Switch2_o = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/fcg' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_VectorConcatenate_i[1] = (uint8)(rtb_Switch2_o > 0.0F);
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator12/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Abs2/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Application Parameter2'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator12/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/Relational Operator2/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay2'
         */
    rtb_sfun_setbit_pz = (uint8)((((sint32)rtb_sfun_setbit_pz) != 0) && (f32_abs_f32(T_ABPREP_ReBnd_Crv_1pm - DW_abprep_Unit_Delay2_DSTATE_c) > GET_P_ABPREP_CrvLimStepDtct_1pm()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/Application Parameter3'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay2'
         */
    if (((sint32)rtb_sfun_setbit_pz) != 0) {
        rtb_Switch2_a = GET_P_ABPREP_SIFJumpDebounceT_sec();
    } else if (DW_abprep_Unit_Delay2_DSTATE_ce > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay2'
                 */
        rtb_Switch2_a = DW_abprep_Unit_Delay2_DSTATE_ce - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Constant2'
                 */
        rtb_Switch2_a = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Constant'
         */
    rtb_VectorConcatenate_i[2] = (uint8)(rtb_Switch2_a > 0.0F);
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/CheckRoadBoundQuality/Constant5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/CheckRoadBoundQuality/GT/Functionality'/GT'
         */
    rtb_VectorConcatenate_i[3] = (uint8)(!(((sint32)T_ABPREP_ReBnd_ExProb_perc) > ((sint32)GET_P_ABPREP_MinRoadEdgeABDQual_perc())));
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/Constant4'/Constant' */
    rtb_VectorConcatenate_i[4] = 0U;
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/Constant3'/Constant' */
    rtb_VectorConcatenate_i[5] = 0U;
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/Constant2'/Constant' */
    rtb_VectorConcatenate_i[6] = 0U;
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/Constant1'/Constant' */
    rtb_VectorConcatenate_i[7] = 0U;
    /* S-Function (sfun_or): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/OR/Functionality'/sfun_or' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_VectorConcatenate_i[0];
        for (i1=1; i1<8; i1++) {
            temp = temp | rtb_VectorConcatenate_i[i1];
        }
        rtb_sfun_setbit_pz = temp;
    }
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/NOT1/Functionality'/NOT'
         */
    T_ABPREP_ReBnd_ExProb_perc = (uint8)(!(((sint32)rtb_sfun_setbit_pz) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/NOT5/Functionality'/NOT'
         */
    rtb_sfun_setbit_pz = (uint8)(!(((sint32)T_ABPREP_ReBnd_ExProb_perc) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/Constant5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData'/Unit_Delay'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData'/Unit_Delay1'
         */
    if ((((sint32)DW_abprep_Unit_Delay_DSTATE_p) != 0) && (!(((sint32) T_ABPREP_ReBnd_ExProb_perc) != 0))) {
        rtb_Switch2_bl = GET_P_ABPREP_MaxLaneBridgingTime_sec();
    } else if (DW_abprep_Unit_Delay1_DSTATE_f > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData'/Unit_Delay1'
                 */
        rtb_Switch2_bl = DW_abprep_Unit_Delay1_DSTATE_f - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_bl = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface'/Unit_Delay'
         */
    rtb_DataTypeConversion_nj = (uint8)(((((sint32)rtb_sfun_setbit_pz) != 0) && (rtb_Switch2_bl > 0.0F)) && (((sint32)DW_abprep_Unit_Delay_1_DSTATE_d) != 0));
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
         */
    rtb_Max_en = T_ABPREP_ReBnd_PosY0_met - GET_S_ABPLBP_LeLnClthPosY0SIF_met();
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/constant_value1'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/LT2/Functionality'/LT'
         */
    rtb_sfun_setbit_pz = (uint8)((rtb_Max_en > 0.0F) && (rtb_Max_en < GET_P_ABPREP_Lane2ReDistThresh_met()));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/OR2/Functionality'/OR'
         */
    rtb_sfun_setbit_pz = (uint8)((((sint32)rtb_DataTypeConversion_nj) != 0) || (((sint32)rtb_sfun_setbit_pz) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_e = (uint8)((((sint32)T_ABPREP_ReBnd_ExProb_perc) != 0) || (((sint32)rtb_DataTypeConversion_nj) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Abs3/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Constant6'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/constant_value'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQuSIF_btf'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/LT1/Functionality'/LT'
         */
    rtb_DataTypeConversion_d = (uint8)(((((((sint32)rtb_sfun_setbit_pz) != 0) && (((sint32)GET_S_ABPLBP_LeLnInvalidQuSIF_btf()) == 0)) && (f32_abs_f32 (GET_S_ABPLBP_LeLnClthCrvSIF_1pm()) < GET_P_ABPREP_LaneMaxCrv_1pm())) && (((sint32)rtb_DataTypeConversion_e) != 0)) && (((sint32) GET_P_ABPREP_StabilizeWithLanes_bool()) != 0));
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
         */
    rtb_Max_en = T_ABPREP_ReBnd_PosY0_met - GET_S_ABPLBP_RiLnClthPosY0SIF_met();
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Constant4'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/LT4/Functionality'/LT'
         */
    rtb_sfun_setbit_pz = (uint8)((GET_P_ABPREP_MinLatDistStabilize_met() < rtb_Max_en) && (rtb_Max_en < GET_P_ABPREP_MaxLatDistStabilize_met()));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/OR1/Functionality'/OR'
         */
    rtb_sfun_setbit_pz = (uint8)((((sint32)rtb_DataTypeConversion_nj) != 0) || (((sint32)rtb_sfun_setbit_pz) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_cj = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Abs1/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Constant5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Constant7'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/constant_value2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQuSIF_btf'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/AND3/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/LT3/Functionality'/LT'
         */
    rtb_DataTypeConversion_nrt = (uint8)((((((((sint32)rtb_sfun_setbit_pz) != 0) && (((sint32)GET_S_ABPLBP_RiLnInvalidQuSIF_btf()) == 0)) && (f32_abs_f32 (GET_S_ABPLBP_RiLnClthCrvSIF_1pm()) < GET_P_ABPREP_LaneMaxCrv_1pm())) && (((sint32)rtb_DataTypeConversion_e) != 0)) && (((sint32) rtb_DataTypeConversion_cj) != 0)) && (((sint32) GET_P_ABPREP_StabilizeWithLanes_bool()) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_mv = (uint8)((((sint32)rtb_DataTypeConversion_d) != 0) || (((sint32)rtb_DataTypeConversion_nrt) != 0));
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/LaneStabilizationBitfieldGeneration'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_mz[2] = rtb_DataTypeConversion_mv;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/NOT1/Functionality'/NOT'
         */
    rtb_sfun_setbit_pz = (uint8)(!(((sint32)rtb_Min) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/OR1/Functionality'/OR'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression'/Unit_Delay4'
         */
    rtb_sfun_setbit_pz = (uint8)(((!(((sint32)DW_abprep_Unit_Delay4_DSTATE_f) != 0)) && (((sint32)rtb_Min) != 0)) || (((sint32)rtb_sfun_setbit_pz) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/Functionality'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Abs/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/Application Parameter4'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Application Parameter3'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/NOT3/Functionality'/NOT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Relational Operator/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP/Functionality/Sum/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay'
         */
    if ((!(((sint32)rtb_sfun_setbit_pz) != 0)) && (f32_abs_f32 (T_ABPREP_ReBnd_PosY0_met_i - DW_abprep_Unit_Delay_DSTATE_l) > GET_P_ABPREP_DistYLimitStepDtct_met())) {
        rtb_Switch2_de = GET_P_ABPREP_SIFJumpDebounceT_sec();
    } else if (DW_abprep_Unit_Delay_DSTATE_cv > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay'
                 */
        rtb_Switch2_de = DW_abprep_Unit_Delay_DSTATE_cv - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_de = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/fcg' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE/Functionality'/Constant'
         */
    rtb_VectorConcatenate_p[0] = (uint8)(rtb_Switch2_de > 0.0F);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SIFHeadingSelection/Switch1/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterOut'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SIFHeadingSelection/Constant2'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SIFHeadingSelection/AND1/Functionality'/AND'
         *  UnaryMinus: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/Neg4/Functionality'/Unary Minus'
         */
    if ((((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) && (((sint32) GET_P_ABPREP_SIFUseKalmanHead_bool()) != 0)) {
        T_ABPREP_ReBnd_Heading_rad_e = -rtb_sfun_roadEdgeKalmanFilter_Right.sf_HeadingAngle_rad;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SIFHeadingSelection/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/NOT2/Functionality'/NOT'
         */
    rtb_sfun_setbit_pz = (uint8)(!(((sint32)rtb_sfun_setbit_pz) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/Functionality'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Abs1/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/Application Parameter1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Application Parameter5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator11/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Relational Operator1/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1/Functionality/Sum/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay1'
         */
    if ((f32_abs_f32(T_ABPREP_ReBnd_Heading_rad_e - DW_abprep_Unit_Delay1_DSTATE_j) > GET_P_ABPREP_HeadLimStepDtct_rad()) && (((sint32)rtb_sfun_setbit_pz) != 0)) {
        rtb_Switch2_lv = GET_P_ABPREP_SIFJumpDebounceT_sec();
    } else if (DW_abprep_Unit_Delay1_DSTATE_lx > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay1'
                 */
        rtb_Switch2_lv = DW_abprep_Unit_Delay1_DSTATE_lx - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 */
        rtb_Switch2_lv = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/fcg' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_VectorConcatenate_p[1] = (uint8)(rtb_Switch2_lv > 0.0F);
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/Functionality'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator12/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Abs2/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Application Parameter2'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Logical Operator12/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/Relational Operator2/Functionality'/GT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay2'
         */
    rtb_sfun_setbit_pz = (uint8)((((sint32)rtb_sfun_setbit_pz) != 0) && (f32_abs_f32(T_ABPREP_ReBnd_Crv_1pm_i - DW_abprep_Unit_Delay2_DSTATE_l) > GET_P_ABPREP_CrvLimStepDtct_1pm()));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/Application Parameter2'/Constant'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay2'
         */
    if (((sint32)rtb_sfun_setbit_pz) != 0) {
        rtb_Switch2_n = GET_P_ABPREP_SIFJumpDebounceT_sec();
    } else if (DW_abprep_Unit_Delay2_DSTATE_b > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay2'
                 */
        rtb_Switch2_n = DW_abprep_Unit_Delay2_DSTATE_b - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Constant2'
                 */
        rtb_Switch2_n = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections/TIMERRETRIGGER_RE2/Functionality'/Constant'
         */
    rtb_VectorConcatenate_p[2] = (uint8)(rtb_Switch2_n > 0.0F);
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/CheckRoadBoundQuality/Constant5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/CheckRoadBoundQuality/GT/Functionality'/GT'
         */
    rtb_VectorConcatenate_p[3] = (uint8)(!(((sint32) T_ABPREP_ReBnd_ExProb_perc_f) > ((sint32) GET_P_ABPREP_MinRoadEdgeABDQual_perc())));
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/Constant4'/Constant' */
    rtb_VectorConcatenate_p[4] = 0U;
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/Constant3'/Constant' */
    rtb_VectorConcatenate_p[5] = 0U;
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/Constant2'/Constant' */
    rtb_VectorConcatenate_p[6] = 0U;
    /* Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/Constant1'/Constant' */
    rtb_VectorConcatenate_p[7] = 0U;
    /* S-Function (sfun_or): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/OR/Functionality'/sfun_or' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_VectorConcatenate_p[0];
        for (i1=1; i1<8; i1++) {
            temp = temp | rtb_VectorConcatenate_p[i1];
        }
        rtb_sfun_setbit_pz = temp;
    }
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/NOT1/Functionality'/NOT'
         */
    T_ABPREP_ReBnd_ExProb_perc_f = (uint8)(!(((sint32)rtb_sfun_setbit_pz) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/NOT5/Functionality'/NOT'
         */
    rtb_sfun_setbit_pz = (uint8)(!(((sint32)T_ABPREP_ReBnd_ExProb_perc_f) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/Constant5'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData'/Unit_Delay'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData'/Unit_Delay1'
         */
    if ((((sint32)DW_abprep_Unit_Delay_DSTATE_kt) != 0) && (!(((sint32) T_ABPREP_ReBnd_ExProb_perc_f) != 0))) {
        rtb_Switch2_bn = GET_P_ABPREP_MaxLaneBridgingTime_sec();
    } else if (DW_abprep_Unit_Delay1_DSTATE_fa > rtb_Sum_aq) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData'/Unit_Delay1'
                 */
        rtb_Switch2_bn = DW_abprep_Unit_Delay1_DSTATE_fa - rtb_Sum_aq;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_bn = 0.0F;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface'/Unit_Delay'
         */
    rtb_DataTypeConversion_ks = (uint8)(((((sint32)rtb_sfun_setbit_pz) != 0) && (rtb_Switch2_bn > 0.0F)) && (((sint32)DW_abprep_Unit_Delay_2_DSTATE_g) != 0));
    /* Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Sum1/Functionality'/Sum'
         */
    rtb_Max_en = f32_abs_f32(T_ABPREP_ReBnd_PosY0_met_i - GET_S_ABPLBP_LeLnClthPosY0SIF_met());
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Constant4'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/LT4/Functionality'/LT'
         */
    rtb_sfun_setbit_pz = (uint8)((GET_P_ABPREP_MinLatDistStabilize_met() < rtb_Max_en) && (rtb_Max_en < GET_P_ABPREP_MaxLatDistStabilize_met()));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/OR1/Functionality'/OR'
         */
    rtb_sfun_setbit_pz = (uint8)((((sint32)rtb_DataTypeConversion_ks) != 0) || (((sint32)rtb_sfun_setbit_pz) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/OR1/Functionality'/OR'
         */
    rtb__T_ABPREP_ReBnd_PosX0_met_kt = (uint8)((((sint32) T_ABPREP_ReBnd_ExProb_perc_f) != 0) || (((sint32)rtb_DataTypeConversion_ks) != 0));
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
         */
    rtb_Max_en = GET_S_ABPLBP_RiLnClthPosY0SIF_met() - T_ABPREP_ReBnd_PosY0_met_i;
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Abs2/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Constant1'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Constant2'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Constant6'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/constant_value'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/constant_value1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQuSIF_btf'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/AND/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/AND2/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/LT2/Functionality'/LT'
         */
    rtb_DataTypeConversion_gg = (uint8)((((((((sint32)rtb_DataTypeConversion_ks) != 0) || ((rtb_Max_en > 0.0F) && (rtb_Max_en < GET_P_ABPREP_Lane2ReDistThresh_met()))) && (((sint32) GET_S_ABPLBP_RiLnInvalidQuSIF_btf()) == 0)) && (f32_abs_f32 (GET_S_ABPLBP_RiLnClthCrvSIF_1pm()) < GET_P_ABPREP_LaneMaxCrv_1pm())) && (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0)) && (((sint32) GET_P_ABPREP_StabilizeWithLanes_bool()) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Abs3/Functionality'/Abs'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Constant5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Constant7'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/constant_value2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQuSIF_btf'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/AND3/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/LT3/Functionality'/LT'
         */
    rtb_DataTypeConversion_a = (uint8)((((((((sint32)rtb_sfun_setbit_pz) != 0) && (((sint32)GET_S_ABPLBP_LeLnInvalidQuSIF_btf()) == 0)) && (f32_abs_f32 (GET_S_ABPLBP_LeLnClthCrvSIF_1pm()) < GET_P_ABPREP_LaneMaxCrv_1pm())) && (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0)) && (!(((sint32) rtb_DataTypeConversion_gg) != 0))) && (((sint32) GET_P_ABPREP_StabilizeWithLanes_bool()) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_pp = (uint8)((((sint32)rtb_DataTypeConversion_a) != 0) || (((sint32)rtb_DataTypeConversion_gg) != 0));
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/LaneStabilizationBitfieldGeneration'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_mz[3] = rtb_DataTypeConversion_pp;
    /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/LaneStabilizationBitfieldGeneration/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[4] = { 0U, 1U, 2U, 3U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_mz[0];
                for (i1=0; i1 < 4; i1++) {
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
        rtb_sfun_setbit_pz = temp;
    }
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_bc = (uint8)((((sint32)rtb_DataTypeConversion_o) != 0) && (((sint32)rtb_DataTypeConversion_p) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/NOT1/Functionality'/NOT'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/OR/Functionality'/OR'
         */
    rtb__T_ABPREP_ReBnd_PosX0_met_kt = (uint8)(!((((sint32) rtb_DataTypeConversion_o) != 0) || (((sint32)rtb_DataTypeConversion_p) != 0)));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Constant2'/Constant'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_e = (uint8)(!(((sint32) GET_P_ABPREP_StabilizeWithLanes_bool()) != 0));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_e) != 0) {
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j = T_ABPREP_ReBnd_CrvChng_1pm2;
    } else if (((sint32)rtb_DataTypeConversion_l) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
    } else if (((sint32)rtb_DataTypeConversion_ok) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j = T_ABPREP_ReBnd_CrvChng_1pm2;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Constant1'/Constant'
         */
    if (((sint32)GET_P_ABPREP_StabilizeWithLanes_bool()) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_f) != 0) {
            rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
        } else if (((sint32)rtb_DataTypeConversion_ei) != 0) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                         */
            rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
        } else {
            rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i = T_ABPREP_ReBnd_CrvChng_1pm2_g;
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' */
    } else {
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i = T_ABPREP_ReBnd_CrvChng_1pm2_g;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/LeftRoadEdgeZeroClothoid/Constant3'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_bc) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch' */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim'/Unit_Delay3'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l - DW_abprep_Unit_Delay3_DSTATE_i;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/Constant5'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/Mul3/Functionality'/Mul'
         */
    rtb_Mul_as = (-GET_P_ABPREP_MaxCrvChngGrad_1psm2()) * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/Constant5'/Constant'
         */
    rtb_Mul_ns = GET_P_ABPREP_MaxCrvChngGrad_1psm2() * rtb_Sum_aq;
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_ag = (uint8)(rtb_Max_en > rtb_Mul_ns);
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_ht = (uint8)(rtb_Max_en < rtb_Mul_as);
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_cj = (uint8)(!(((sint32)rtb_DataTypeConversion_o) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/OR/Functionality'/OR'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter'/Unit_Delay5'
         */
    rtb_DataTypeConversion_cj = (uint8)(((!(((sint32) DW_abprep_Unit_Delay5_DSTATE_e) != 0)) && (((sint32)rtb_DataTypeConversion_o) != 0)) || (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Mul_as = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l;
    } else if (((sint32)rtb_RelationalOperator_ag) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim'/Unit_Delay3'
                 */
        rtb_Mul_as = rtb_Mul_ns + DW_abprep_Unit_Delay3_DSTATE_i;
    } else if (((sint32)rtb_RelationalOperator1_ht) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim'/Unit_Delay3'
                 */
        rtb_Mul_as += DW_abprep_Unit_Delay3_DSTATE_i;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5'
                 */
        rtb_Mul_as = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator_ag) != 0) {
        rtb_RelationalOperator1_ht = 0U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate2_h[3] = (uint8)((((sint32)rtb_RelationalOperator1_ht) != 0) || (((sint32)rtb_RelationalOperator_ag) != 0));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_e) != 0) {
        rtb__T_ABPREP_ReBnd_Crv_1pm_bv = rtb__T_ABPREP_ReBnd_Crv_1pm;
    } else if (((sint32)rtb_DataTypeConversion_l) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_bv = GET_S_ABPLBP_LeLnClthCrv_1pm();
    } else if (((sint32)rtb_DataTypeConversion_ok) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_bv = GET_S_ABPLBP_RiLnClthCrv_1pm();
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_bv = rtb__T_ABPREP_ReBnd_Crv_1pm;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Constant1'/Constant'
         */
    if (((sint32)GET_P_ABPREP_StabilizeWithLanes_bool()) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_f) != 0) {
            rtb_Mul_ns = GET_S_ABPLBP_RiLnClthCrv_1pm();
        } else if (((sint32)rtb_DataTypeConversion_ei) != 0) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         */
            rtb_Mul_ns = GET_S_ABPLBP_LeLnClthCrv_1pm();
        } else {
            rtb_Mul_ns = rtb_Mul_fd;
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' */
    } else {
        rtb_Mul_ns = rtb_Mul_fd;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/LeftRoadEdgeZeroClothoid/Constant2'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        rtb__T_ABPREP_ReBnd_Crv_1pm_ck = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_bc) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch' */
        rtb__T_ABPREP_ReBnd_Crv_1pm_ck = rtb__T_ABPREP_ReBnd_Crv_1pm_bv;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_ck = rtb__T_ABPREP_ReBnd_Crv_1pm_bv;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_ck = rtb_Mul_ns;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim'/Unit_Delay2'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_Crv_1pm_ck - DW_abprep_Unit_Delay2_DSTATE_p;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/Constant3'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/Mul2/Functionality'/Mul'
         */
    rtb_Mul_k1 = (-GET_P_ABPREP_MaxCrvGrad_1pms()) * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/Constant3'/Constant'
         */
    rtb_Mul_nt = GET_P_ABPREP_MaxCrvGrad_1pms() * rtb_Sum_aq;
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_ag = (uint8)(rtb_Max_en > rtb_Mul_nt);
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_ht = (uint8)(rtb_Max_en < rtb_Mul_k1);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Mul_k1 = rtb__T_ABPREP_ReBnd_Crv_1pm_ck;
    } else if (((sint32)rtb_RelationalOperator_ag) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim'/Unit_Delay2'
                 */
        rtb_Mul_k1 = rtb_Mul_nt + DW_abprep_Unit_Delay2_DSTATE_p;
    } else if (((sint32)rtb_RelationalOperator1_ht) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim'/Unit_Delay2'
                 */
        rtb_Mul_k1 += DW_abprep_Unit_Delay2_DSTATE_p;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5'
                 */
        rtb_Mul_k1 = rtb__T_ABPREP_ReBnd_Crv_1pm_ck;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator_ag) != 0) {
        rtb_RelationalOperator1_ht = 0U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate2_h[2] = (uint8)((((sint32)rtb_RelationalOperator1_ht) != 0) || (((sint32)rtb_RelationalOperator_ag) != 0));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_e) != 0) {
        rtb__T_ABPREP_ReBnd_Heading_rad_i3 = rtb__T_ABPREP_ReBnd_Heading_rad;
    } else if (((sint32)rtb_DataTypeConversion_l) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_i3 = GET_S_ABPLBP_LeLnClthHeading_rad();
    } else if (((sint32)rtb_DataTypeConversion_ok) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_i3 = GET_S_ABPLBP_RiLnClthHeading_rad();
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_i3 = rtb__T_ABPREP_ReBnd_Heading_rad;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Constant1'/Constant'
         */
    if (((sint32)GET_P_ABPREP_StabilizeWithLanes_bool()) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_f) != 0) {
            rtb__T_ABPREP_ReBnd_Heading_rad_c = GET_S_ABPLBP_RiLnClthHeading_rad();
        } else if (((sint32)rtb_DataTypeConversion_ei) != 0) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                         */
            rtb__T_ABPREP_ReBnd_Heading_rad_c = GET_S_ABPLBP_LeLnClthHeading_rad();
        } else {
            rtb__T_ABPREP_ReBnd_Heading_rad_c = rtb_Mul_a;
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' */
    } else {
        rtb__T_ABPREP_ReBnd_Heading_rad_c = rtb_Mul_a;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/LeftRoadEdgeZeroClothoid/Constant1'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        rtb__T_ABPREP_ReBnd_Heading_rad_i = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_bc) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch' */
        rtb__T_ABPREP_ReBnd_Heading_rad_i = rtb__T_ABPREP_ReBnd_Heading_rad_i3;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_i = rtb__T_ABPREP_ReBnd_Heading_rad_i3;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_i = rtb__T_ABPREP_ReBnd_Heading_rad_c;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim'/Unit_Delay1'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_Heading_rad_i - DW_abprep_Unit_Delay1_DSTATE_h;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/Constant1'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/Mul1/Functionality'/Mul'
         */
    rtb_Mul_nt = (-GET_P_ABPREP_MaxHeadingGrad_radps()) * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/Constant1'/Constant'
         */
    rtb_Mul_k = GET_P_ABPREP_MaxHeadingGrad_radps() * rtb_Sum_aq;
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_ag = (uint8)(rtb_Max_en > rtb_Mul_k);
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_ht = (uint8)(rtb_Max_en < rtb_Mul_nt);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Mul_nt = rtb__T_ABPREP_ReBnd_Heading_rad_i;
    } else if (((sint32)rtb_RelationalOperator_ag) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim'/Unit_Delay1'
                 */
        rtb_Mul_nt = rtb_Mul_k + DW_abprep_Unit_Delay1_DSTATE_h;
    } else if (((sint32)rtb_RelationalOperator1_ht) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim'/Unit_Delay1'
                 */
        rtb_Mul_nt += DW_abprep_Unit_Delay1_DSTATE_h;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
                 */
        rtb_Mul_nt = rtb__T_ABPREP_ReBnd_Heading_rad_i;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator_ag) != 0) {
        rtb_RelationalOperator1_ht = 0U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate2_h[1] = (uint8)((((sint32)rtb_RelationalOperator1_ht) != 0) || (((sint32)rtb_RelationalOperator_ag) != 0));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_l) != 0) {
        rtb_Mul_k = GET_S_ABPLBP_LeLnClthPosY0_met();
    } else if (((sint32)rtb_DataTypeConversion_ok) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                 */
        rtb_Mul_k = GET_S_ABPLBP_RiLnClthPosY0_met();
    } else {
        rtb_Mul_k = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND1/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay5'
         */
    rtb_sfun_setbit_cp = (uint8)((((!(((sint32)DW_abprep_Unit_Delay5_DSTATE_eq) != 0)) && (((sint32)rtb_DataTypeConversion_l) != 0)) && ((((sint32) DW_abprep_Unit_Delay2_DSTATE_e) != 0) && (!(((sint32)rtb_DataTypeConversion_ok) != 0)))) && (((sint32)rtb_DataTypeConversion_fp1) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/OR/Functionality'/OR'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay3'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay4'
         */
    rtb_sfun_setbit_cp = (uint8)(((((((sint32)DW_abprep_Unit_Delay3_DSTATE_o) != 0) && (!(((sint32)rtb_DataTypeConversion_l) != 0))) && ((!(((sint32) DW_abprep_Unit_Delay4_DSTATE_bs) != 0)) && (((sint32)rtb_DataTypeConversion_ok) != 0))) && (((sint32)rtb_DataTypeConversion_fp1) != 0)) || (((sint32) rtb_sfun_setbit_cp) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/Abs1/Functionality'/Abs'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/NOT/Functionality'/NOT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/Sum1/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary'/Unit_Delay'
         */
    if (((sint32)rtb_sfun_setbit_cp) != 0) {
        rtb_Switch1_i = f32_abs_f32(rtb_Mul_k - DW_abprep_Unit_Delay_2_DSTATE);
    } else if (!(((sint32)rtb_DataTypeConversion_fp1) != 0)) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1' incorporates:
                 *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/Abs/Functionality'/Abs'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay'
                 */
        rtb_Switch1_i = f32_abs_f32(DW_abprep_Unit_Delay_DSTATE_hx);
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1' incorporates:
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay1'
                 */
        rtb_Switch1_i = DW_abprep_Unit_Delay1_DSTATE_d;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/Switch/Functionality'/Switch' incorporates:
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_fp1) != 0) {
        rtb_Switch_gcr = rtb_Mul_k + rtb_Switch1_i;
    } else {
        rtb_Switch_gcr = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_e) != 0) {
        rtb__T_ABPREP_ReBnd_PosY0_met_j2 = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my;
    } else {
        rtb__T_ABPREP_ReBnd_PosY0_met_j2 = rtb_Switch_gcr;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_f) != 0) {
        rtb__T_ABPREP_ReBnd_PosY0_met_ni = GET_S_ABPLBP_RiLnClthPosY0_met();
    } else if (((sint32)rtb_DataTypeConversion_ei) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                 */
        rtb__T_ABPREP_ReBnd_PosY0_met_ni = GET_S_ABPLBP_LeLnClthPosY0_met();
    } else {
        rtb__T_ABPREP_ReBnd_PosY0_met_ni = rtb__T_ABPREP_ReBnd_PosY0_met_h1;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay3'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay4'
         */
    rtb_sfun_setbit_cp = (uint8)((((((sint32)DW_abprep_Unit_Delay3_DSTATE_b) != 0) && (!(((sint32)rtb_DataTypeConversion_ei) != 0))) && ((!(((sint32) DW_abprep_Unit_Delay4_DSTATE_d) != 0)) && (((sint32)rtb_DataTypeConversion_f) != 0))) && (((sint32)rtb_DataTypeConversion_ak) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND1/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/OR/Functionality'/OR'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay5'
         */
    rtb_sfun_setbit_cp = (uint8)((((sint32)rtb_sfun_setbit_cp) != 0) || ((((!(((sint32)DW_abprep_Unit_Delay5_DSTATE_l) != 0)) && (((sint32) rtb_DataTypeConversion_ei) != 0)) && ((((sint32) DW_abprep_Unit_Delay2_DSTATE_ch) != 0) && (!(((sint32)rtb_DataTypeConversion_f) != 0)))) && (((sint32)rtb_DataTypeConversion_ak) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/Abs1/Functionality'/Abs'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/NOT/Functionality'/NOT'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/Sum1/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary'/Unit_Delay'
         */
    if (((sint32)rtb_sfun_setbit_cp) != 0) {
        rtb_Switch1_o = f32_abs_f32(rtb__T_ABPREP_ReBnd_PosY0_met_ni - DW_abprep_Unit_Delay_2_DSTATE_j);
    } else if (!(((sint32)rtb_DataTypeConversion_ak) != 0)) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1' incorporates:
                 *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/Abs/Functionality'/Abs'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay'
                 */
        rtb_Switch1_o = f32_abs_f32(DW_abprep_Unit_Delay_DSTATE_g);
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1' incorporates:
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay1'
                 */
        rtb_Switch1_o = DW_abprep_Unit_Delay1_DSTATE_op;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/Switch/Functionality'/Switch' incorporates:
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_ak) != 0) {
        rtb_Switch_f2 = rtb__T_ABPREP_ReBnd_PosY0_met_ni - rtb_Switch1_o;
    } else {
        rtb_Switch_f2 = rtb__T_ABPREP_ReBnd_PosY0_met_h1;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Constant1'/Constant'
         */
    if (((sint32)GET_P_ABPREP_StabilizeWithLanes_bool()) != 0) {
        rtb__T_ABPREP_ReBnd_PosY0_met_m = rtb_Switch_f2;
    } else {
        rtb__T_ABPREP_ReBnd_PosY0_met_m = rtb__T_ABPREP_ReBnd_PosY0_met_h1;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/LeftRoadEdgeZeroClothoid/Constant'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        rtb__T_ABPREP_ReBnd_PosY0_met_ly = 7.5F;
    } else if (((sint32)rtb_DataTypeConversion_bc) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch' */
        rtb__T_ABPREP_ReBnd_PosY0_met_ly = rtb__T_ABPREP_ReBnd_PosY0_met_j2;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_PosY0_met_ly = rtb__T_ABPREP_ReBnd_PosY0_met_j2;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/OnlyRightRoadEdgeValid/Constant1'/Constant'
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/OnlyRightRoadEdgeValid/Sum/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                 */
        rtb__T_ABPREP_ReBnd_PosY0_met_ly = GET_P_ABPREP_DefaultRoadWidth_met() + rtb__T_ABPREP_ReBnd_PosY0_met_m;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim'/Unit_Delay'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_PosY0_met_ly - DW_abprep_Unit_Delay_DSTATE_h;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/Constant8'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/Mul/Functionality'/Mul'
         */
    rtb_Mul_bl = (-GET_P_ABPREP_MaxDistYGrad_mps()) * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/Constant8'/Constant'
         */
    rtb_Mul_ls = GET_P_ABPREP_MaxDistYGrad_mps() * rtb_Sum_aq;
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_ag = (uint8)(rtb_Max_en > rtb_Mul_ls);
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_ht = (uint8)(rtb_Max_en < rtb_Mul_bl);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_Mul_bl = rtb__T_ABPREP_ReBnd_PosY0_met_ly;
    } else if (((sint32)rtb_RelationalOperator_ag) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim'/Unit_Delay'
                 */
        rtb_Mul_bl = rtb_Mul_ls + DW_abprep_Unit_Delay_DSTATE_h;
    } else if (((sint32)rtb_RelationalOperator1_ht) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim'/Unit_Delay'
                 */
        rtb_Mul_bl += DW_abprep_Unit_Delay_DSTATE_h;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 */
        rtb_Mul_bl = rtb__T_ABPREP_ReBnd_PosY0_met_ly;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator_ag) != 0) {
        rtb_sfun_setbit_cp = 0U;
    } else {
        rtb_sfun_setbit_cp = rtb_RelationalOperator1_ht;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate2_h[0] = (uint8)((((sint32)rtb_sfun_setbit_cp) != 0) || (((sint32)rtb_RelationalOperator_ag) != 0));
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/NOT/Functionality'/NOT'
         */
    rtb_sfun_setbit_cp = (uint8)(!(((sint32)rtb_DataTypeConversion_p) != 0));
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/OR/Functionality'/OR'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter'/Unit_Delay5'
         */
    rtb_sfun_setbit_cp = (uint8)(((!(((sint32)DW_abprep_Unit_Delay5_DSTATE_m) != 0)) && (((sint32)rtb_DataTypeConversion_p) != 0)) || (((sint32) rtb_sfun_setbit_cp) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/RightRoadEdgeZeroClothoid/Constant3'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i = 0.0F;
    } else {
        if ((((sint32)rtb_DataTypeConversion_bc) == 0) && (((sint32) rtb_DataTypeConversion_o) != 0)) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                         */
            rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j;
        }
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim'/Unit_Delay3'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i - DW_abprep_Unit_Delay3_DSTATE_h;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/Constant5'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/Mul3/Functionality'/Mul'
         */
    rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j = (-GET_P_ABPREP_MaxCrvChngGrad_1psm2()) * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/Constant5'/Constant'
         */
    rtb_Mul_ls = GET_P_ABPREP_MaxCrvChngGrad_1psm2() * rtb_Sum_aq;
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Relational Operator' */
    rtb_DataTypeConversion_cj = (uint8)(rtb_Max_en > rtb_Mul_ls);
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator_ag = (uint8)(rtb_Max_en < rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_sfun_setbit_cp) != 0) {
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i;
    } else if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim'/Unit_Delay3'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j = rtb_Mul_ls + DW_abprep_Unit_Delay3_DSTATE_h;
    } else if (((sint32)rtb_RelationalOperator_ag) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim'/Unit_Delay3'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j += DW_abprep_Unit_Delay3_DSTATE_h;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5'
                 */
        rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_RelationalOperator_ag = 0U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate2_h[7] = (uint8)((((sint32)rtb_RelationalOperator_ag) != 0) || (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/RightRoadEdgeZeroClothoid/Constant2'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        rtb_Mul_ns = 0.0F;
    } else {
        if ((((sint32)rtb_DataTypeConversion_bc) == 0) && (((sint32) rtb_DataTypeConversion_o) != 0)) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                         */
            rtb_Mul_ns = rtb__T_ABPREP_ReBnd_Crv_1pm_bv;
        }
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim'/Unit_Delay2'
         */
    rtb_Max_en = rtb_Mul_ns - DW_abprep_Unit_Delay2_DSTATE_ol;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/Constant3'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/Mul2/Functionality'/Mul'
         */
    rtb__T_ABPREP_ReBnd_Crv_1pm_bv = (-GET_P_ABPREP_MaxCrvGrad_1pms()) * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/Constant3'/Constant'
         */
    rtb_Mul_ls = GET_P_ABPREP_MaxCrvGrad_1pms() * rtb_Sum_aq;
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Relational Operator' */
    rtb_DataTypeConversion_cj = (uint8)(rtb_Max_en > rtb_Mul_ls);
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator_ag = (uint8)(rtb_Max_en < rtb__T_ABPREP_ReBnd_Crv_1pm_bv);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_sfun_setbit_cp) != 0) {
        rtb__T_ABPREP_ReBnd_Crv_1pm_bv = rtb_Mul_ns;
    } else if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim'/Unit_Delay2'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_bv = rtb_Mul_ls + DW_abprep_Unit_Delay2_DSTATE_ol;
    } else if (((sint32)rtb_RelationalOperator_ag) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim'/Unit_Delay2'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_bv += DW_abprep_Unit_Delay2_DSTATE_ol;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5'
                 */
        rtb__T_ABPREP_ReBnd_Crv_1pm_bv = rtb_Mul_ns;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_RelationalOperator_ag = 0U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate2_h[6] = (uint8)((((sint32)rtb_RelationalOperator_ag) != 0) || (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/RightRoadEdgeZeroClothoid/Constant1'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        rtb__T_ABPREP_ReBnd_Heading_rad_c = 0.0F;
    } else {
        if ((((sint32)rtb_DataTypeConversion_bc) == 0) && (((sint32) rtb_DataTypeConversion_o) != 0)) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                         */
            rtb__T_ABPREP_ReBnd_Heading_rad_c = rtb__T_ABPREP_ReBnd_Heading_rad_i3;
        }
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim'/Unit_Delay1'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_Heading_rad_c - DW_abprep_Unit_Delay1_DSTATE_fr;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/Constant1'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/Mul1/Functionality'/Mul'
         */
    rtb__T_ABPREP_ReBnd_Heading_rad_i3 = (-GET_P_ABPREP_MaxHeadingGrad_radps()) * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/Constant1'/Constant'
         */
    rtb_Mul_ls = GET_P_ABPREP_MaxHeadingGrad_radps() * rtb_Sum_aq;
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator' */
    rtb_DataTypeConversion_cj = (uint8)(rtb_Max_en > rtb_Mul_ls);
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator_ag = (uint8)(rtb_Max_en < rtb__T_ABPREP_ReBnd_Heading_rad_i3);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_sfun_setbit_cp) != 0) {
        rtb__T_ABPREP_ReBnd_Heading_rad_i3 = rtb__T_ABPREP_ReBnd_Heading_rad_c;
    } else if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim'/Unit_Delay1'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_i3 = rtb_Mul_ls + DW_abprep_Unit_Delay1_DSTATE_fr;
    } else if (((sint32)rtb_RelationalOperator_ag) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim'/Unit_Delay1'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_i3 += DW_abprep_Unit_Delay1_DSTATE_fr;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_i3 = rtb__T_ABPREP_ReBnd_Heading_rad_c;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_RelationalOperator_ag = 0U;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate2_h[5] = (uint8)((((sint32)rtb_RelationalOperator_ag) != 0) || (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/RightRoadEdgeZeroClothoid/Constant'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        rtb__T_ABPREP_ReBnd_PosY0_met_m = -7.5F;
    } else {
        if ((((sint32)rtb_DataTypeConversion_bc) == 0) && (((sint32) rtb_DataTypeConversion_o) != 0)) {
            /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/OnlyLeftRoadEdgeValid/Constant1'/Constant'
                         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/OnlyLeftRoadEdgeValid/Sum/Functionality'/Sum'
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                         */
            rtb__T_ABPREP_ReBnd_PosY0_met_m = rtb__T_ABPREP_ReBnd_PosY0_met_j2 - GET_P_ABPREP_DefaultRoadWidth_met();
        }
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim'/Unit_Delay'
         */
    rtb_Max_en = rtb__T_ABPREP_ReBnd_PosY0_met_m - DW_abprep_Unit_Delay_DSTATE_n5;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/Constant8'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/Mul/Functionality'/Mul'
         */
    rtb__T_ABPREP_ReBnd_PosY0_met_j2 = (-GET_P_ABPREP_MaxDistYGrad_mps()) * rtb_Sum_aq;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/Constant8'/Constant'
         */
    rtb_Mul_ls = GET_P_ABPREP_MaxDistYGrad_mps() * rtb_Sum_aq;
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator' */
    rtb_DataTypeConversion_cj = (uint8)(rtb_Max_en > rtb_Mul_ls);
    /* RelationalOperator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator_ag = (uint8)(rtb_Max_en < rtb__T_ABPREP_ReBnd_PosY0_met_j2);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_sfun_setbit_cp) != 0) {
        rtb_Max_en = rtb__T_ABPREP_ReBnd_PosY0_met_m;
    } else if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim'/Unit_Delay'
                 */
        rtb_Max_en = rtb_Mul_ls + DW_abprep_Unit_Delay_DSTATE_n5;
    } else if (((sint32)rtb_RelationalOperator_ag) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim'/Unit_Delay'
                 */
        rtb_Max_en = rtb__T_ABPREP_ReBnd_PosY0_met_j2 + DW_abprep_Unit_Delay_DSTATE_n5;
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 */
        rtb_Max_en = rtb__T_ABPREP_ReBnd_PosY0_met_m;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_DataTypeConversion_cj) != 0) {
        rtb_sfun_setbit_cp = 0U;
    } else {
        rtb_sfun_setbit_cp = rtb_RelationalOperator_ag;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate2_h[4] = (uint8)((((sint32)rtb_sfun_setbit_cp) != 0) || (((sint32)rtb_DataTypeConversion_cj) != 0));
    /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_cp = temp;
    }
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/Switch1/Functionality'/Switch' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch/Functionality'/Switch'
         */
    if ((((sint32)rtb_DataTypeConversion_e) == 0) && (((sint32) rtb_DataTypeConversion_fp1) != 0)) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_l) != 0) {
            rtb__T_ABPREP_ReBnd_Length_met_c = GET_S_ABPLBP_LeLnClthLength_met();
        } else {
            if (((sint32)rtb_DataTypeConversion_ok) != 0) {
                /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                                 */
                rtb__T_ABPREP_ReBnd_Length_met_c = GET_S_ABPLBP_RiLnClthLength_met();
            }
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Constant1'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/Switch1/Functionality'/Switch'
         */
    if ((((sint32)GET_P_ABPREP_StabilizeWithLanes_bool()) != 0) && (((sint32) rtb_DataTypeConversion_ak) != 0)) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_f) != 0) {
            rtb__T_ABPREP_ReBnd_Length_met_pf = GET_S_ABPLBP_RiLnClthLength_met();
        } else {
            if (((sint32)rtb_DataTypeConversion_ei) != 0) {
                /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                                 */
                rtb__T_ABPREP_ReBnd_Length_met_pf = GET_S_ABPLBP_LeLnClthLength_met();
            }
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/LeftRoadEdgeZeroClothoid/Constant4'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch'
         */
    if (((sint32)rtb__T_ABPREP_ReBnd_PosX0_met_kt) != 0) {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch27'/copy1' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/ZeroRoadEdgeClothoids/RightRoadEdgeZeroClothoid/Constant4'/Constant'
                 */
        SET_S_ABPREP_RiReLength_met(0.0F);
        rtb__T_ABPREP_ReBnd_Length_met_c = 0.0F;
    } else {
        if (((sint32)rtb_DataTypeConversion_bc) != 0) {
            /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch27'/copy1' incorporates:
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                         */
            SET_S_ABPREP_RiReLength_met(rtb__T_ABPREP_ReBnd_Length_met_pf);
        } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
            /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch27'/copy1' incorporates:
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                         */
            SET_S_ABPREP_RiReLength_met(rtb__T_ABPREP_ReBnd_Length_met_c);
        } else {
            /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch27'/copy1' incorporates:
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
                         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                         */
            SET_S_ABPREP_RiReLength_met(rtb__T_ABPREP_ReBnd_Length_met_pf);
        }
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch'
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch1/Functionality'/Switch'
                 */
        if ((((sint32)rtb_DataTypeConversion_bc) == 0) && (((sint32) rtb_DataTypeConversion_o) == 0)) {
            rtb__T_ABPREP_ReBnd_Length_met_c = rtb__T_ABPREP_ReBnd_Length_met_pf;
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Constant'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch'
         */
    if (((sint32)GET_P_ABPREP_UseGradientLimiter_bool()) != 0) {
        rtb__T_ABPREP_ReBnd_Heading_rad_i = rtb_Mul_nt;
        rtb__T_ABPREP_ReBnd_Length_met_pf = rtb__T_ABPREP_ReBnd_Heading_rad_i3;
    } else {
        rtb__T_ABPREP_ReBnd_Length_met_pf = rtb__T_ABPREP_ReBnd_Heading_rad_c;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit5/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit6/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit7/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit8/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit9/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/from_data_definition'/phys_max_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/from_data_definition1'/phys_max_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/Constant'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit2/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit6/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit7/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit8/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit9/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/Constant2'/Constant'
         *  S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/set_bit1/Functionality'/sfun_setbit'
         *  S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/set_bit/Functionality'/sfun_setbit'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_fa) != 0) {
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit9/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit9/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_ec = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)8U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit9/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit9/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_h[12] = rtb_SFunction_ec;
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit8/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit8/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_ec = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)6U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit8/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit8/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_h[11] = rtb_SFunction_ec;
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit7/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit7/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_ec = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)4U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit7/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit7/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_h[10] = rtb_SFunction_ec;
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit6/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit6/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_ec = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)2U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit6/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit6/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_h[9] = rtb_SFunction_ec;
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit2/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit2/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_ec = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)0U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit2/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/get_bit2/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_h[8] = rtb_SFunction_ec;
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/NOT3/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/NOT3/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_h[14] = (uint8)(!(((sint32)rtb_Switch_mr) != 0));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/NOT2/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/NOT2/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_h[2] = (uint8)(!(((sint32)rtb_SFunction_d) != 0));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/NOT1/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/NOT1/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_h[1] = (uint8)(!(((sint32)rtb_DataTypeConversion_md) != 0));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/NOT/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/NOT/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_h[0] = (uint8)(!(((sint32) T_ABPREP_ReBnd_Available_bool) != 0));
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn8' */
        rtb_VectorConcatenate_h[7] = rtb_RelationalOperator1_ic;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn7' */
        rtb_VectorConcatenate_h[6] = rtb_RelationalOperator1_kge;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn6' */
        rtb_VectorConcatenate_h[5] = rtb_RelationalOperator1_mn;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn5' */
        rtb_VectorConcatenate_h[4] = rtb_RelationalOperator1_ev;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn4' */
        rtb_VectorConcatenate_h[3] = (uint8)rtb_DataTypeConversion[0];
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn14' */
        rtb_VectorConcatenate_h[13] = rtb_DataTypeConversion_fp1;
        /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/set_bit/Functionality'/sfun_setbit' */
        {
            /* mask selection vector from setbit block */
            uint16 temp = ((uint16)0U);
            {
                uint16 set_mask = 0;
                uint16 reset_mask = 0;
                const uint8 selection_vec[15] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U };
                {
                    sint32 i1;
                    const uint8 *u1 = &rtb_VectorConcatenate_h[0];
                    for (i1=0; i1 < 15; i1++) {
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
            rtb_sfun_setbit_p = temp;
        }
        SET_S_ABPREP_LeReInvalidQu_btf(rtb_sfun_setbit_p);
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit9/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit9/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_k = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)9U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit9/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit9/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/Constant'/Constant'
                 *  S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/LeftRoadEdgeQualifier/set_bit/Functionality'/sfun_setbit'
                 */
        rtb_VectorConcatenate_m[12] = rtb_SFunction_k;
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit8/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit8/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_k = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)7U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit8/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit8/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_m[11] = rtb_SFunction_k;
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit7/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit7/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_k = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)5U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit7/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit7/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_m[10] = rtb_SFunction_k;
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit6/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit6/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_k = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)3U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit6/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit6/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_m[9] = rtb_SFunction_k;
        /* S-Function (sfun_getbit_77): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit5/Functionality'/S-Function' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit5/Functionality'/Const_bit_sel_param'
                 */
        rtb_SFunction_k = flag_get_u16_u8(rtb_sfun_setbit, ((uint8)1U));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit5/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/get_bit5/Functionality'/Const_bit_sel_param'
                 */
        rtb_VectorConcatenate_m[8] = rtb_SFunction_k;
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/NOT3/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/NOT3/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_m[14] = (uint8)(!(((sint32)rtb_Switch_g2) != 0));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/NOT2/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/NOT2/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_m[2] = (uint8)(!(((sint32)rtb_SFunction_h) != 0));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/NOT1/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/NOT1/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_m[1] = (uint8)(!(((sint32)rtb_DataTypeConversion_cp) != 0));
        /* DataTypeConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/NOT/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/NOT/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_m[0] = (uint8)(!(((sint32)rtb_Min) != 0));
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn8' */
        rtb_VectorConcatenate_m[7] = rtb_RelationalOperator1_lmp;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn7' */
        rtb_VectorConcatenate_m[6] = rtb_RelationalOperator1_nw;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn6' */
        rtb_VectorConcatenate_m[5] = rtb_RelationalOperator1_p3;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn5' */
        rtb_VectorConcatenate_m[4] = rtb_RelationalOperator1_fl;
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn4' */
        rtb_VectorConcatenate_m[3] = (uint8)rtb_DataTypeConversion[1];
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier'/ConcatBufferAtVector ConcatenateIn14' */
        rtb_VectorConcatenate_m[13] = rtb_DataTypeConversion_ak;
        /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeBitfields/RightRoadEdgeQualifier/set_bit1/Functionality'/sfun_setbit' */
        {
            /* mask selection vector from setbit block */
            uint16 temp = ((uint16)0U);
            {
                uint16 set_mask = 0;
                uint16 reset_mask = 0;
                const uint8 selection_vec[15] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U };
                {
                    sint32 i1;
                    const uint8 *u1 = &rtb_VectorConcatenate_m[0];
                    for (i1=0; i1 < 15; i1++) {
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
            rtb_sfun_setbit_e = temp;
        }
        SET_S_ABPREP_RiReInvalidQu_btf(rtb_sfun_setbit_e);
    } else {
        SET_S_ABPREP_LeReInvalidQu_btf(U16_MAX);
        SET_S_ABPREP_RiReInvalidQu_btf(U16_MAX);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/Switch/Functionality'/Switch' */
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Mul/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb__T_ABPREP_ReBnd_Heading_rad_c = GET_S_LCFRCV_VehVelX_mps() * rtb__T_ABPREP_ReBnd_Heading_rad_i;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Constant12'/Constant'
         *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Max/Functionality'/Max'
         */
    rtb_Div = rtb_Sum_aq / f32_max_f32_f32(GET_P_ABPREP_LatVelPT1TimeConst_sec(), rtb_Sum_aq);
    /* UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity'/Unit_Delay' */
    rtb_Unit_Delay_f = DW_abprep_Unit_Delay_DSTATE_nv;
    /* S-Function (sfun_mmv): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE'/E'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE'/R'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE'/IV'
         */
    rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay_f, rtb__T_ABPREP_ReBnd_Heading_rad_c, rtb_Div);
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Mul1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_Mul_ls = GET_S_LCFRCV_VehVelX_mps() * rtb__T_ABPREP_ReBnd_Length_met_pf;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE1/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Constant1'/Constant'
         *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Max1/Functionality'/Max'
         */
    rtb_Div_o = rtb_Sum_aq / f32_max_f32_f32(GET_P_ABPREP_LatVelPT1TimeConst_sec(), rtb_Sum_aq);
    /* UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity'/Unit_Delay1' */
    rtb_Unit_Delay1_n = DW_abprep_Unit_Delay1_DSTATE_hm;
    /* S-Function (sfun_mmv): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE1/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE1'/E'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE1'/R'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/LOWPASST_RE1'/IV'
         */
    rtb_SFunction_e = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_n, rtb_Mul_ls, rtb_Div_o);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Constant2'/Constant'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Switch4/Functionality'/Switch'
         */
    if (((sint32)GET_P_ABPREP_UseLatVelPT1Filter_bool()) != 0) {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/branch39'/copy1' */
        SET_S_ABPREP_RiReLatVel_mps(rtb_SFunction_e);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/branch38'/copy1' */
        SET_S_ABPREP_LeReLatVel_mps(rtb_SFunction);
    } else {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/branch39'/copy1' */
        SET_S_ABPREP_RiReLatVel_mps(rtb_Mul_ls);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/branch38'/copy1' */
        SET_S_ABPREP_LeReLatVel_mps(rtb__T_ABPREP_ReBnd_Heading_rad_c);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_d) != 0) {
        rtb__T_ABPREP_ReBnd_Heading_rad_c = GET_S_ABPLBP_LeLnClthPosY0SIF_met();
    } else if (((sint32)rtb_DataTypeConversion_nrt) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
                 */
        rtb__T_ABPREP_ReBnd_Heading_rad_c = GET_S_ABPLBP_RiLnClthPosY0SIF_met();
    } else {
        rtb__T_ABPREP_ReBnd_Heading_rad_c = T_ABPREP_ReBnd_PosY0_met;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/Abs1/Functionality'/Abs'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND1/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/NOT/Functionality'/NOT'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/OR/Functionality'/OR'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/Sum1/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary'/Unit_Delay'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay3'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay4'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay5'
         */
    if (((((((sint32)DW_abprep_Unit_Delay3_DSTATE_jb) != 0) && (!(((sint32) rtb_DataTypeConversion_d) != 0))) && ((!(((sint32) DW_abprep_Unit_Delay4_DSTATE_j) != 0)) && (((sint32) rtb_DataTypeConversion_nrt) != 0))) && (((sint32) rtb_DataTypeConversion_nj) != 0)) || ((((!(((sint32) DW_abprep_Unit_Delay5_DSTATE_k) != 0)) && (((sint32) rtb_DataTypeConversion_d) != 0)) && ((((sint32) DW_abprep_Unit_Delay2_DSTATE_i) != 0) && (!(((sint32) rtb_DataTypeConversion_nrt) != 0)))) && (((sint32) rtb_DataTypeConversion_nj) != 0))) {
        rtb_Mul_ls = f32_abs_f32(rtb__T_ABPREP_ReBnd_Heading_rad_c - DW_abprep_Unit_Delay_1_DSTATE);
    } else if (!(((sint32)rtb_DataTypeConversion_nj) != 0)) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1' incorporates:
                 *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/Abs/Functionality'/Abs'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay'
                 */
        rtb_Mul_ls = f32_abs_f32(DW_abprep_Unit_Delay_DSTATE_o);
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1' incorporates:
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay1'
                 */
        rtb_Mul_ls = DW_abprep_Unit_Delay1_DSTATE_d5;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1_m[0] = T_ABPREP_ReBnd_Heading_rad;
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate1_m[1] = T_ABPREP_ReBnd_Heading_rad_e;
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Mul/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    for (i = 0; i < 2; i++) {
        rtb_Mul_nl[i] = rtb_VectorConcatenate1_m[i] * GET_S_LCFRCV_VehVelX_mps();
    }
    /* End of Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Mul/Functionality'/Mul' */
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Constant12'/Constant'
         *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Max/Functionality'/Max'
         */
    rtb_Div_a = rtb_Sum_aq / f32_max_f32_f32(GET_P_ABPREP_SIFPT1TimeConst_sec(), rtb_Sum_aq);
    /* UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation'/Unit_Delay' */
    rtb_Unit_Delay_d = DW_abprep_Unit_Delay_DSTATE_hb;
    /* S-Function (sfun_mmv): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE'/E'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE'/R'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE'/IV'
         */
    rtb_SFunction_c = f32_mmv_f32_f32_f32( rtb_Unit_Delay_d, rtb_Mul_nl[0], rtb_Div_a);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Constant3'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Constant4'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Mul1/Functionality'/Mul'
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation'/ConcatBufferAtVector ConcatenateIn1'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Sum/Functionality'/Sum'
         */
    if (((sint32)GET_P_ABPREP_SIFUseLatencyComp_bool()) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Constant6'/Constant'
                 */
        if (((sint32)GET_P_ABPREP_SIFUseLatVelPT1Flt_bool()) != 0) {
            rtb_VectorConcatenate2_n_idx_1 = rtb_SFunction_c;
        } else {
            rtb_VectorConcatenate2_n_idx_1 = rtb_Mul_nl[0];
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Switch4/Functionality'/Switch' */
        rtb__T_ABPREP_ReBnd_PosY0_met_j2 = (GET_P_ABPREP_SIFLatencyTime_sec() * rtb_VectorConcatenate2_n_idx_1) + T_ABPREP_ReBnd_PosY0_met;
    } else {
        rtb__T_ABPREP_ReBnd_PosY0_met_j2 = T_ABPREP_ReBnd_PosY0_met;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Switch2/Functionality'/Switch' */
    /* Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE1/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Constant2'/Constant'
         *  MinMax: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Max1/Functionality'/Max'
         */
    rtb_Div_j = rtb_Sum_aq / f32_max_f32_f32(GET_P_ABPREP_SIFPT1TimeConst_sec(), rtb_Sum_aq);
    /* UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation'/Unit_Delay1' */
    rtb_Unit_Delay1_oo = DW_abprep_Unit_Delay1_DSTATE_pf;
    /* S-Function (sfun_mmv): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE1/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE1'/E'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE1'/R'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/LOWPASST_RE1'/IV'
         */
    rtb_SFunction_o = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_oo, rtb_Mul_nl[1], rtb_Div_j);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Constant5'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Constant7'/Constant'
         *  Product: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Mul2/Functionality'/Mul'
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation'/ConcatBufferAtVector ConcatenateIn2'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Sum1/Functionality'/Sum'
         */
    if (((sint32)GET_P_ABPREP_SIFUseLatencyComp_bool()) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Constant8'/Constant'
                 */
        if (((sint32)GET_P_ABPREP_SIFUseLatVelPT1Flt_bool()) != 0) {
            rtb_VectorConcatenate2_n_idx_1 = rtb_SFunction_o;
        } else {
            rtb_VectorConcatenate2_n_idx_1 = rtb_Mul_nl[1];
        }
        /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Switch3/Functionality'/Switch' */
        rtb_VectorConcatenate2_n_idx_1 = (GET_P_ABPREP_SIFLatencyTime_sec() * rtb_VectorConcatenate2_n_idx_1) + T_ABPREP_ReBnd_PosY0_met_i;
    } else {
        rtb_VectorConcatenate2_n_idx_1 = T_ABPREP_ReBnd_PosY0_met_i;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/Switch/Functionality'/Switch' incorporates:
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_nj) != 0) {
        rtb_Sum_aq = rtb__T_ABPREP_ReBnd_Heading_rad_c + rtb_Mul_ls;
    } else {
        rtb_Sum_aq = rtb__T_ABPREP_ReBnd_PosY0_met_j2;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_gg) != 0) {
        rtb__T_ABPREP_ReBnd_PosY0_met_l = GET_S_ABPLBP_RiLnClthPosY0SIF_met();
    } else if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
                 */
        rtb__T_ABPREP_ReBnd_PosY0_met_l = GET_S_ABPLBP_LeLnClthPosY0SIF_met();
    } else {
        rtb__T_ABPREP_ReBnd_PosY0_met_l = T_ABPREP_ReBnd_PosY0_met_i;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch' incorporates:
         *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/Abs1/Functionality'/Abs'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/AND1/Functionality'/AND'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/Logical Operator1'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/NOT/Functionality'/NOT'
         *  Logic: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/OR/Functionality'/OR'
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/Sum1/Functionality'/Sum'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary'/Unit_Delay'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay2'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay3'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay4'
         *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay5'
         */
    if (((((((sint32)DW_abprep_Unit_Delay3_DSTATE_a) != 0) && (!(((sint32) rtb_DataTypeConversion_a) != 0))) && ((!(((sint32) DW_abprep_Unit_Delay4_DSTATE_i) != 0)) && (((sint32) rtb_DataTypeConversion_gg) != 0))) && (((sint32) rtb_DataTypeConversion_ks) != 0)) || ((((!(((sint32) DW_abprep_Unit_Delay5_DSTATE_h) != 0)) && (((sint32) rtb_DataTypeConversion_a) != 0)) && ((((sint32) DW_abprep_Unit_Delay2_DSTATE_j) != 0) && (!(((sint32) rtb_DataTypeConversion_gg) != 0)))) && (((sint32) rtb_DataTypeConversion_ks) != 0))) {
        rtb_Switch1 = f32_abs_f32(rtb__T_ABPREP_ReBnd_PosY0_met_l - DW_abprep_Unit_Delay_1_DSTATE_e);
    } else if (!(((sint32)rtb_DataTypeConversion_ks) != 0)) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1' incorporates:
                 *  Abs: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/Abs/Functionality'/Abs'
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay'
                 */
        rtb_Switch1 = f32_abs_f32(DW_abprep_Unit_Delay_DSTATE_a);
    } else {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch1' incorporates:
                 *  UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay1'
                 */
        rtb_Switch1 = DW_abprep_Unit_Delay1_DSTATE_h4;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/SAMPLEANDHOLD_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/Switch/Functionality'/Switch' incorporates:
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_ks) != 0) {
        rtb_Switch_nr = rtb__T_ABPREP_ReBnd_PosY0_met_l - rtb_Switch1;
    } else {
        rtb_Switch_nr = rtb_VectorConcatenate2_n_idx_1;
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_d) != 0) {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch11'/copy1' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeadingSIF_rad'
                 */
        SET_S_ABPREP_LeReClthHeadingSIF_rad(GET_S_ABPLBP_LeLnClthHeadingSIF_rad());
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch12'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
                                                                              */
        SET_S_ABPREP_LeReClthCrvSIF_1pm(GET_S_ABPLBP_LeLnClthCrvSIF_1pm());
    } else if (((sint32)rtb_DataTypeConversion_nrt) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeadingSIF_rad'
                 *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch11'/copy1'
                 */
        SET_S_ABPREP_LeReClthHeadingSIF_rad(GET_S_ABPLBP_RiLnClthHeadingSIF_rad());
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                                                                              *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
                                                                              *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch12'/copy1'
                                                                              */
        SET_S_ABPREP_LeReClthCrvSIF_1pm(GET_S_ABPLBP_RiLnClthCrvSIF_1pm());
    } else {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch11'/copy1' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        SET_S_ABPREP_LeReClthHeadingSIF_rad(T_ABPREP_ReBnd_Heading_rad);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch12'/copy1' incorporates:
                                                                              *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch1/Functionality'/Switch'
                                                                              */
        SET_S_ABPREP_LeReClthCrvSIF_1pm(T_ABPREP_ReBnd_Crv_1pm);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckLeftRoadBoundaryValidation/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' incorporates:
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_gg) != 0) {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch14'/copy1' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeadingSIF_rad'
                 */
        SET_S_ABPREP_RiReClthHeadingSIF_rad(GET_S_ABPLBP_RiLnClthHeadingSIF_rad());
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch15'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
                                                                              */
        SET_S_ABPREP_RiReClthCrvSIF_1pm(GET_S_ABPLBP_RiLnClthCrvSIF_1pm());
    } else if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeadingSIF_rad'
                 *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch14'/copy1'
                 */
        SET_S_ABPREP_RiReClthHeadingSIF_rad(GET_S_ABPLBP_LeLnClthHeadingSIF_rad());
        /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch' incorporates:
                                                                              *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
                                                                              *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch15'/copy1'
                                                                              */
        SET_S_ABPREP_RiReClthCrvSIF_1pm(GET_S_ABPLBP_LeLnClthCrvSIF_1pm());
    } else {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch14'/copy1' incorporates:
                 *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
                 */
        SET_S_ABPREP_RiReClthHeadingSIF_rad(T_ABPREP_ReBnd_Heading_rad_e);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch15'/copy1' incorporates:
                                                                              *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch1/Functionality'/Switch'
                                                                              */
        SET_S_ABPREP_RiReClthCrvSIF_1pm(T_ABPREP_ReBnd_Crv_1pm_i);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/CheckRightRoadBoundaryValidation/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/Constant'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/Constant'/Constant'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/from_data_definition'/phys_max_source'
         *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/from_data_definition1'/phys_max_source'
         *  S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/set_bit/Functionality'/sfun_setbit'
         *  S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/set_bit1/Functionality'/sfun_setbit'
         *  S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/set_bit/Functionality'/sfun_setbit'
         *  S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/set_bit1/Functionality'/sfun_setbit'
         *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_fa) != 0) {
        /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/set_bit/Functionality'/sfun_setbit' */
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
            rtb_sfun_setbit_g = temp;
        }
        /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/set_bit1/Functionality'/sfun_setbit' */
        {
            /* mask selection vector from setbit block */
            uint8 temp = rtb_sfun_setbit_g;
            if (!rtb_DataTypeConversion_nj) {
                /* reset */
                temp = temp & (~u8_bit_u8( (uint8) 4U));
            } else {
                /* set */
                temp = temp | u8_bit_u8( (uint8) 4U);
            }
            rtb_sfun_setbit_c = temp;
        }
        SET_S_ABPREP_LeReInvalidQuSIF_btf(rtb_sfun_setbit_c);
        /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/set_bit/Functionality'/sfun_setbit' */
        {
            /* mask selection vector from setbit block */
            uint8 temp = ((uint8)0U);
            {
                uint8 set_mask = 0;
                uint8 reset_mask = 0;
                const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
                {
                    sint32 i1;
                    const uint8 *u1 = &rtb_VectorConcatenate_p[0];
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
            rtb_sfun_setbit_e4 = temp;
        }
        /* S-Function (sfun_setbit): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/set_bit1/Functionality'/sfun_setbit' */
        {
            /* mask selection vector from setbit block */
            uint8 temp = rtb_sfun_setbit_e4;
            if (!rtb_DataTypeConversion_ks) {
                /* reset */
                temp = temp & (~u8_bit_u8( (uint8) 4U));
            } else {
                /* set */
                temp = temp | u8_bit_u8( (uint8) 4U);
            }
            rtb_sfun_setbit_m = temp;
        }
        SET_S_ABPREP_RiReInvalidQuSIF_btf(rtb_sfun_setbit_m);
    } else {
        SET_S_ABPREP_LeReInvalidQuSIF_btf(U8_MAX);
        SET_S_ABPREP_RiReInvalidQuSIF_btf(U8_MAX);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch10'/copy1' */
    SET_S_ABPREP_LeReClthPosY0SIF_met(rtb_Sum_aq);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch13'/copy1' */
    SET_S_ABPREP_RiReClthPosY0SIF_met(rtb_Switch_nr);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch16'/copy1' incorporates:
                                                        *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch'
                                                        */
    SET_S_ABPREP_LeReClthPosX0_met(0.0F);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch' incorporates:
                                            *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Constant'/Constant'
                                            *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch'
                                            */
    if (((sint32)GET_P_ABPREP_UseGradientLimiter_bool()) != 0) {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch17'/copy1' */
        SET_S_ABPREP_LeRePosY0_met(rtb_Mul_bl);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch19'/copy1' */
        SET_S_ABPREP_LeReClthCrv_1pm(rtb_Mul_k1);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch20'/copy1' */
        SET_S_ABPREP_LeReClthCrvChng_1pm2(rtb_Mul_as);
    } else {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch17'/copy1' */
        SET_S_ABPREP_LeRePosY0_met(rtb__T_ABPREP_ReBnd_PosY0_met_ly);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch19'/copy1' */
        SET_S_ABPREP_LeReClthCrv_1pm(rtb__T_ABPREP_ReBnd_Crv_1pm_ck);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch20'/copy1' */
        SET_S_ABPREP_LeReClthCrvChng_1pm2(rtb__T_ABPREP_ReBnd_CrvChng_1pm2_l);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch18'/copy1' */
    SET_S_ABPREP_LeReHeading_rad(rtb__T_ABPREP_ReBnd_Heading_rad_i);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch21'/copy1' */
    SET_S_ABPREP_LeReLength_met(rtb__T_ABPREP_ReBnd_Length_met_c);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch22'/copy1' incorporates:
                                                                     *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch'
                                                                     */
    SET_S_ABPREP_RiReClthPosX0_met(0.0F);
    /* Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch' incorporates:
                                            *  Constant: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Constant'/Constant'
                                            *  Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch'
                                            */
    if (((sint32)GET_P_ABPREP_UseGradientLimiter_bool()) != 0) {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch23'/copy1' */
        SET_S_ABPREP_RiRePosY0_met(rtb_Max_en);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch25'/copy1' */
        SET_S_ABPREP_RiReClthCrv_1pm(rtb__T_ABPREP_ReBnd_Crv_1pm_bv);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch26'/copy1' */
        SET_S_ABPREP_RiReClthCrvChng_1pm2(rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j);
    } else {
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch23'/copy1' */
        SET_S_ABPREP_RiRePosY0_met(rtb__T_ABPREP_ReBnd_PosY0_met_m);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch25'/copy1' */
        SET_S_ABPREP_RiReClthCrv_1pm(rtb_Mul_ns);
        /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch26'/copy1' */
        SET_S_ABPREP_RiReClthCrvChng_1pm2(rtb__T_ABPREP_ReBnd_CrvChng_1pm2_i);
    }
    /* End of Switch: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/Switch2/Functionality'/Switch' */
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch24'/copy1' */
    SET_S_ABPREP_RiReHeading_rad(rtb__T_ABPREP_ReBnd_Length_met_pf);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch28'/copy1' */
    SET_S_ABPREP_LnBndGradLimActive_btf(rtb_sfun_setbit_cp);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch37'/copy1' */
    SET_S_ABPREP_LaneStabilization_btf(rtb_sfun_setbit_pz);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch38'/copy1' */
    SET_S_ABPREP_LeReQuality_perc(rtb_VectorConcatenate7[0]);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch39'/copy1' */
    SET_S_ABPREP_RiReQuality_perc(rtb_VectorConcatenate7[1]);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch42'/copy1' incorporates:
                                                                *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterOut'
                                                                */
    SET_S_ABPREP_RiReKFStatus_enum (rtb_sfun_roadEdgeKalmanFilter_Right.sf_KFStatus_btf);
    /* SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/branch43'/copy1' incorporates:
                                                               *  BusCreator: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/RoadEdgeKalmanFilter/RoadEdgeKalmanFilterRight'/LCFRoadEdgeKalmanFilterOut'
                                                               */
    SET_S_ABPREP_RiReKFQuality_perc (rtb_sfun_roadEdgeKalmanFilter_Right.sf_QualityMeasure_perc);
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckRoadEdgeBasicProperties/CheckRoadBoundQuality'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_e = rtb_Min_p;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE_l = rtb_Switch_g;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_c = rtb__T_ABPREP_ReBnd_Crv_1pm_lr;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP2'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay6' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP2/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay6_DSTATE = rtb__T_ABPREP_ReBnd_Crv_1pm;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP2'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay2' */
    DW_abprep_Unit_Delay2_DSTATE_o = rtb_Switch2_el;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP1'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP1/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay5_DSTATE = rtb__T_ABPREP_ReBnd_Heading_rad;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP1'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_g = rtb_Switch2_e;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP6'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP6'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP6/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay1_DSTATE_l = T_ABPREP_ReBnd_CrvChng_1pm2;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP6'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay6' */
    DW_abprep_Unit_Delay6_DSTATE_e = rtb_Switch2_k;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/CheckLeftRoadEdgeBasicProperties1/CheckRoadBoundQuality'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_al = rtb_Switch3_ok;
    for (i = 0; i < 2; i++) {
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/ValidateLength'/Unit_Delay' */
        DW_abprep_Unit_Delay_DSTATE_cvn[i] = rtb_Switch_fy[i];
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation'/Unit_Delay' */
        DW_abprep_Unit_Delay_DSTATE[i] = rtb_Switch_gne[i];
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepPenaltyDetermination'/Unit_Delay' */
        DW_abprep_Unit_Delay_DSTATE_m[i] = rtb_Mul_i4[i];
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/Functionality'
                 */
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay4' incorporates:
                 *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI/Functionality'/Signal Conversion'
                 */
        DW_abprep_Unit_Delay4_DSTATE_e[i] = (uint8)rtb_VectorConcatenate_f[i];
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/EDGEBI'/fcg' */
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP'/Functionality'
                 */
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay' incorporates:
                 *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP/Functionality'/Signal Conversion'
                 */
        DW_abprep_Unit_Delay_DSTATE_n[i] = rtb_VectorConcatenate1[i];
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP'/fcg' */
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP1'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP1'/Functionality'
                 */
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay1' incorporates:
                 *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP1/Functionality'/Signal Conversion'
                 */
        DW_abprep_Unit_Delay1_DSTATE[i] = rtb_VectorConcatenate2[i];
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP1'/fcg' */
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP3'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP3'/Functionality'
                 */
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay3' incorporates:
                 *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP3/Functionality'/Signal Conversion'
                 */
        DW_abprep_Unit_Delay3_DSTATE[i] = rtb_VectorConcatenate3[i];
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP3'/fcg' */
        /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP2'/fcg' incorporates:
                 *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP2'/Functionality'
                 */
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection'/Unit_Delay2' incorporates:
                 *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP2/Functionality'/Signal Conversion'
                 */
        DW_abprep_Unit_Delay2_DSTATE[i] = rtb_VectorConcatenate4[i];
        /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/CheckBasicRoadEdgeProperites/DetermineMeasurementQualityRoadEdge/RoadEdgeQualityCalculation/CalculateRoadEdgeQuality/PenaltyForStepDetections/RoadEdgeStepDetection/DELTAONESTEP2'/fcg' */
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay' */
        DW_abprep_Unit_Delay_DSTATE_hs[i] = rtb_Switch2_d[i];
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay1' */
        DW_abprep_Unit_Delay1_DSTATE_os[i] = rtb_Switch3_d[i];
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay2' */
        DW_abprep_Unit_Delay2_DSTATE_bb[i] = rtb_Switch3_jm[i];
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay3' */
        DW_abprep_Unit_Delay3_DSTATE_m[i] = rtb_Switch3_l[i];
        /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/RangeChecks'/Unit_Delay4' */
        DW_abprep_Unit_Delay4_DSTATE_o[i] = rtb_Switch3_m4[i];
    }
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay_DSTATE_mn = rtb_DataTypeConversion_ea;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckLeftRoadEdgeValidity'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_n = rtb_Switch2_f;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP'/Unit_Delay' */
    DW_abprep_Unit_Delay_1_DSTATE_k = rtb_DataTypeConversion_m;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE_b = rtb_Switch_gj;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/CheckRoadStepDtctSuppression1/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP5'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP5'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay9' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP5/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay9_DSTATE = rtb__T_ABPREP_ReBnd_PosY0_met_h1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP5'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay5' */
    DW_abprep_Unit_Delay5_DSTATE_p = rtb_Switch2_pp;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP4'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP4'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay8' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP4/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay8_DSTATE = rtb_Mul_a;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP4'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay4' */
    DW_abprep_Unit_Delay4_DSTATE_k = rtb_Switch2_aj;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP3'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP3'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay7' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP3/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay7_DSTATE = rtb_Mul_fd;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP3'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay3' */
    DW_abprep_Unit_Delay3_DSTATE_j = rtb_Switch2_lz;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP7'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP7'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP7/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay2_DSTATE_n = T_ABPREP_ReBnd_CrvChng_1pm2_g;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/RoadEdgeStepDetection/DELTAONESTEP7'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/StepDetection/DebounceStepDetections'/Unit_Delay7' */
    DW_abprep_Unit_Delay7_DSTATE_m = rtb_Switch2_dr;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay_DSTATE_k1 = rtb_DataTypeConversion_n;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/VALidation/ValidateRoadEdges/DetermineRoadEdgeValidState/CheckRightRoadEdgeValidity'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_p = rtb_Switch2_gi;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP'/Unit_Delay' */
    DW_abprep_Unit_Delay_2_DSTATE_m = rtb_DataTypeConversion_et;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE_g = T_ABPREP_ReBnd_Available_bool;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay_DSTATE_k = T_ABPREP_ReBnd_PosY0_met;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_f = rtb_Switch2_py;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay1_DSTATE_m = T_ABPREP_ReBnd_Heading_rad;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_o = rtb_Switch2_o;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay2_DSTATE_c = T_ABPREP_ReBnd_Crv_1pm;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay2' */
    DW_abprep_Unit_Delay2_DSTATE_ce = rtb_Switch2_a;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay_DSTATE_p = T_ABPREP_ReBnd_ExProb_perc;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckLeftSafetyRoadEdgeData'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_f = rtb_Switch2_bl;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface'/Unit_Delay' */
    DW_abprep_Unit_Delay_1_DSTATE_d = rtb_DataTypeConversion_mv;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE_f = rtb_Min;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/CheckRoadStepDtctSuppression/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay_DSTATE_l = T_ABPREP_ReBnd_PosY0_met_i;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_cv = rtb_Switch2_de;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay1_DSTATE_j = T_ABPREP_ReBnd_Heading_rad_e;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP1'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_lx = rtb_Switch2_lv;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2/Functionality'/Signal Conversion'
         */
    DW_abprep_Unit_Delay2_DSTATE_l = T_ABPREP_ReBnd_Crv_1pm_i;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/RoadStepDetection/DELTAONESTEP2'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/StepDetection/DebounceStepDetections'/Unit_Delay2' */
    DW_abprep_Unit_Delay2_DSTATE_b = rtb_Switch2_n;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay_DSTATE_kt = T_ABPREP_ReBnd_ExProb_perc_f;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/SafetyInterfaceValidation/CheckRightSafetyRoadEdgeData'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_fa = rtb_Switch2_bn;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface'/Unit_Delay' */
    DW_abprep_Unit_Delay_2_DSTATE_g = rtb_DataTypeConversion_pp;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay5_DSTATE_e = rtb_DataTypeConversion_o;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvChngGradLim'/Unit_Delay3' */
    DW_abprep_Unit_Delay3_DSTATE_i = rtb_Mul_as;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeCrvGradLim'/Unit_Delay2' */
    DW_abprep_Unit_Delay2_DSTATE_p = rtb_Mul_k1;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgeHeadingGradLim'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_h = rtb_Mul_nt;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/LeftRoadBndGrdLimiter/LeftRoadEdgePosYGradLim'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_h = rtb_Mul_bl;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary'/Unit_Delay' */
    DW_abprep_Unit_Delay_2_DSTATE = rtb_Switch_gcr;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay3_DSTATE_o = rtb_DataTypeConversion_l;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE_bs = rtb_DataTypeConversion_ok;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay5_DSTATE_eq = rtb_DataTypeConversion_l;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay2_DSTATE_e = rtb_DataTypeConversion_ok;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay' incorporates:
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/Sum/Functionality'/Sum'
         */
    DW_abprep_Unit_Delay_DSTATE_hx = rtb_Mul_k - rtb__T_ABPREP_ReBnd_CrvChng_1pm2_my;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_d = rtb_Switch1_i;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary'/Unit_Delay' */
    DW_abprep_Unit_Delay_2_DSTATE_j = rtb_Switch_f2;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay3_DSTATE_b = rtb_DataTypeConversion_ei;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE_d = rtb_DataTypeConversion_f;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay5_DSTATE_l = rtb_DataTypeConversion_ei;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay2_DSTATE_ch = rtb_DataTypeConversion_f;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay' incorporates:
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/Sum/Functionality'/Sum'
         */
    DW_abprep_Unit_Delay_DSTATE_g = rtb__T_ABPREP_ReBnd_PosY0_met_ni - rtb__T_ABPREP_ReBnd_PosY0_met_h1;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/PlausibilityCheckWithLaneData/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_op = rtb_Switch1_o;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay5_DSTATE_m = rtb_DataTypeConversion_p;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvChngGradLim'/Unit_Delay3' */
    DW_abprep_Unit_Delay3_DSTATE_h = rtb__T_ABPREP_ReBnd_CrvChng_1pm2_j;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeCrvGradLim'/Unit_Delay2' */
    DW_abprep_Unit_Delay2_DSTATE_ol = rtb__T_ABPREP_ReBnd_Crv_1pm_bv;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgeHeadingGradLim'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_fr = rtb__T_ABPREP_ReBnd_Heading_rad_i3;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/OUTputGeneration/GenerateRoadEdgeOutputs/GradientLimiterAndRoadOutputGeneration/GradientLimiter/RightRoadBndGrdLimiter/RightRoadEdgePosYGradLim'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_n5 = rtb_Max_en;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_nv = rtb_SFunction;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/ProvideLateralVelocity'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_hm = rtb_SFunction_e;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay3_DSTATE_jb = rtb_DataTypeConversion_d;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE_j = rtb_DataTypeConversion_nrt;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay5_DSTATE_k = rtb_DataTypeConversion_d;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay2_DSTATE_i = rtb_DataTypeConversion_nrt;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay' incorporates:
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging/Sum/Functionality'/Sum'
         */
    DW_abprep_Unit_Delay_DSTATE_o = rtb__T_ABPREP_ReBnd_Heading_rad_c - rtb__T_ABPREP_ReBnd_PosY0_met_j2;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary'/Unit_Delay' */
    DW_abprep_Unit_Delay_1_DSTATE = rtb_Sum_aq;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildLeftRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_d5 = rtb_Mul_ls;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation'/Unit_Delay' */
    DW_abprep_Unit_Delay_DSTATE_hb = rtb_SFunction_c;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LateralDistanceLatencyCompensation'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_pf = rtb_SFunction_o;
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay3_DSTATE_a = rtb_DataTypeConversion_a;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay4_DSTATE_i = rtb_DataTypeConversion_gg;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay5_DSTATE_h = rtb_DataTypeConversion_a;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_abprep_Unit_Delay2_DSTATE_j = rtb_DataTypeConversion_gg;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/EDGEFALLING1'/fcg' */
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay' incorporates:
         *  Sum: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging/Sum/Functionality'/Sum'
         */
    DW_abprep_Unit_Delay_DSTATE_a = rtb__T_ABPREP_ReBnd_PosY0_met_l - rtb_VectorConcatenate2_n_idx_1;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary'/Unit_Delay' */
    DW_abprep_Unit_Delay_1_DSTATE_e = rtb_Switch_nr;
    /* Update for UnitDelay: 'sda:ABPREP/ABPREP/ABPREP_SenProcess/ABPREP/RoadEdgeSafetyInterface/LaneStabilizationSIF/BuildRightRoadEdgeBoundary/DetermineLateralDistanceForBridging'/Unit_Delay1' */
    DW_abprep_Unit_Delay1_DSTATE_h4 = rtb_Switch1;
}
#include "Pse_ABPREP.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
