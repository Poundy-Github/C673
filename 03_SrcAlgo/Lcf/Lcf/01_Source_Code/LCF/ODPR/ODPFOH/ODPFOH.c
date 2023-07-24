/**************************************************************************
COPYRIGHT (C) $Date: 2020/04/09 14:20:45CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/ODPR/ODPFOH/project.pj $
$Log: ODPFOH.c  $
Revision 1.9 2020/04/09 14:20:45CEST Craciun, Mihaela (uidl9730) (uidl9730) 
integrate new updates
Revision 1.8 2019/07/17 12:10:33CEST Nastasa, Elena (uidt4846) 
Update LCF files for Sprint 05.10.04
Revision 1.6.1.2 2019/07/11 11:23:00CEST Fen, Alexander (TFPE05) 
automatically created
File          : ODPFOH
Generated on  : Wed 10.07.2019 at 17:52:19 (UTC+01:00)
MD5           : [3935846397  1527178513  1530317826  1484663609 0](ODPFOH)
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
#include "ODPFOH.h"
#include "objTraceKalmanFilter.h"
#include "sda_sil_dummy.h"
#include "ODPFOH_private.h"
#include "polyfitTgtObjectClothoid.h"
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
#define ODPFOH_START_SEC_DATA_8
#include "ODPFOH_MemMap.h"
static uint8 BI_odpfoh_LogicalOperator_m;
/* 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality/Comparison'/Logical Operator' */
static uint8 BI_odpfoh_LogicalOperator_k;
/* 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality/Comparison'/Logical Operator' */
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_f;
static uint8 DW_odpfoh_Unit_Delay_DSTATE_bc;
static uint8 DW_odpfoh_Unit_Delay_DSTATE_d;
static uint8 DW_odpfoh_Unit_Delay_DSTATE_c;
static uint8 DW_odpfoh_Unit_Delay4_DSTATE_g = 1U;
static uint8 DW_odpfoh_Unit_Delay4_DSTATE_b;
static uint8 DW_odpfoh_Unit_Delay4_DSTATE_e;
static uint8 DW_odpfoh_Unit_Delay3_DSTATE_d;
static uint8 DW_odpfoh_Unit_Delay_DSTATE_e;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_d;
static uint8 DW_odpfoh_Unit_Delay4_DSTATE_gn = 1U;
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_ow = 1U;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_e0 = 1U;
static uint8 DW_odpfoh_Unit_Delay_DSTATE_jh = 1U;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_ej = 1U;
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_jw;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_cw;
static uint8 DW_odpfoh_Unit_Delay5_DSTATE_m;
static uint8 DW_odpfoh_Unit_Delay_DSTATE_k;
static uint8 DW_odpfoh_Unit_Delay3_DSTATE_n = 1U;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_f;
static uint8 DW_odpfoh_Unit_Delay_DSTATE_i = 1U;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_ci;
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_a;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_k;
static uint8 DW_odpfoh_Unit_Delay3_DSTATE_es;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_p;
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_jl;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_d5;
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_ay;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_if;
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_ob;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_kx;
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_ap;
static uint8 DW_odpfoh_Unit_Delay_DSTATE_gw = 1U;
static uint8 DW_odpfoh_Unit_Delay1_DSTATE_b3;
static uint8 DW_odpfoh_Unit_Delay2_DSTATE_m;
static uint8 DW_odpfoh_Unit_Delay5_DSTATE_l = 1U;
#define ODPFOH_STOP_SEC_DATA_8
#include "ODPFOH_MemMap.h"
#define ODPFOH_START_SEC_DATA_16
#include "ODPFOH_MemMap.h"
static uint16 DW_odpfoh_Unit_Delay1_DSTATE_l2;
#define ODPFOH_STOP_SEC_DATA_16
#include "ODPFOH_MemMap.h"
#define ODPFOH_START_SEC_DATA_32
#include "ODPFOH_MemMap.h"
static float32 DW_odpfoh_Unit_Delay_DSTATE = 96.0F;
static float32 DW_odpfoh_Unit_Delay_DSTATE_b;
static float32 DW_odpfoh_Unit_Delay_DSTATE_h;
static float32 DW_odpfoh_Unit_Delay_DSTATE_g;
static float32 DW_odpfoh_Unit_Delay_DSTATE_j;
static float32 DW_odpfoh_Unit_Delay2_DSTATE;
static float32 DW_odpfoh_Unit_Delay3_DSTATE;
static float32 DW_odpfoh_Unit_Delay1_DSTATE;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_e;
static float32 DW_odpfoh_Unit_Delay4_DSTATE;
static float32 DW_odpfoh_Unit_Delay5_DSTATE;
static float32 DW_odpfoh_Unit_Delay6_DSTATE;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_b;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_b;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_j;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_c;
static float32 DW_odpfoh_Unit_Delay5_DSTATE_i;
static float32 DW_odpfoh_Unit_Delay3_DSTATE_p = 1.0F;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_j;
static float32 DW_odpfoh_Unit_Delay3_DSTATE_j;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_a;
static float32 DW_odpfoh_Unit_Delay_DSTATE_f = 1.0F;
static float32 DW_odpfoh_Unit_Delay_DSTATE_a;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_bl;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_e;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_l;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_jc;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_h;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_o;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_ek;
static float32 DW_odpfoh_Unit_Delay_DSTATE_n;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_ho;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_o;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_k;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_n;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_i;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_jh;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_cm;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_ko;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_i;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_ki;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_h;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_g;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_kk;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_k3;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_g3;
static float32 DW_odpfoh_Unit_Delay3_DSTATE_e;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_kq;
static float32 DW_odpfoh_Unit_Delay1_DSTATE_is;
static float32 DW_odpfoh_Unit_Delay2_DSTATE_c;
#define ODPFOH_STOP_SEC_DATA_32
#include "ODPFOH_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:ODPFOH/ODPFOH/INI'/ODPFOH_SenReset'
 * Block description for: 'sda:ODPFOH/ODPFOH/INI'/ODPFOH_SenReset'
 *   .1
 */
#define RUNNABLE_ID RUNNABLE_ID_ODPFOH_SenReset
#include "Pse_ODPFOH.h"
/* Short description:  */
void ODPFOH_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant1'/Constant' */
    SET_S_ODPFOH_TgtObjPosX0_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant10'/Constant' */
    SET_S_ODPFOH_AccObjTraceCrv_1pm(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant11'/Constant' */
    SET_D_ODPFOH_MinHistStartPosX_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant12'/Constant' */
    SET_D_ODPFOH_MinHistLength_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant13'/Constant' */
    SET_D_ODPFOH_MaxGapEgoToHist_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant14'/Constant' */
    SET_D_ODPFOH_LastStoredPntX_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant15'/Constant' */
    SET_D_ODPFOH_LastStoredPntAge_sec(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant16'/Constant' */
    SET_D_ODPFOH_NumValidSamples_nu(0U);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant17'/Constant' */
    SET_D_ODPFOH_MeanDevToTraj_1st_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant18'/Constant' */
    SET_D_ODPFOH_MeanDevToTraj_3rd_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant19'/Constant' */
    SET_D_ODPFOH_LastStoredPntY_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant2'/Constant' */
    SET_S_ODPFOH_TgtObjPosY0_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant20'/Constant' */
    SET_S_ODPFOH_ObjTraceStraight_perc(0U);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant21'/Constant' */
    SET_D_ODPFOH_AddNewSample_bool(0U);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant22'/Constant' */
    SET_D_ODPFOH_FirstStoredPntAge_sec(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant23'/Constant' */
    SET_D_ODPFOH_FirstStoredPntX_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant24'/Constant' */
    SET_D_ODPFOH_MeanStoredPntAge_sec(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant3'/Constant' */
    SET_S_ODPFOH_TgtObjHeadAng_rad(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant4'/Constant' */
    SET_S_ODPFOH_TgtObjCrv_1pm(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant5'/Constant' */
    SET_S_ODPFOH_TgtObjCrvChng_1pm2(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant6'/Constant' */
    SET_S_ODPFOH_TgtObjLength_met(0.0F);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant7'/Constant' */
    SET_S_ODPFOH_TgtObjClothoidInv_btf(0U);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant8'/Constant' */
    SET_S_ODPFOH_ObjTraceQual_perc(0U);
    /* Constant: 'sda:ODPFOH/ODPFOH/INI/ODPFOH_SenReset/Constant9'/Constant' */
    SET_S_ODPFOH_ObjTraceCrvQual_perc(0U);
}
#include "Pse_ODPFOH.h"
/* System initialize for function-call system: 'sda:ODPFOH/ODPFOH'/ODPFOH_SenProcess' */
/*
 * Output and update for function-call system: 'sda:ODPFOH/ODPFOH'/ODPFOH_SenProcess'
 * Block description for: 'sda:ODPFOH/ODPFOH'/ODPFOH_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_ODPFOH_SenProcess
#include "Pse_ODPFOH.h"
/* Short description:  */
void ODPFOH_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    TgtObjectTraceKF_Input rtb_ODPFOH_PF_KF_StructIn;
    TgtObjectPF_Input rtb_ODPFOH_PF_StructIn;
    TgtObjectPF_Output rtb_sfun_polyfitTgtObjectClothoid;
    TgtObjectTraceKF_Output rtb_sfun_objTraceKalmanFilter;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_Mul_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_Div;
    float32 rtb_Unit_Delay1_d;
    float32 rtb_SFunction;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_Div_n;
    float32 rtb_Unit_Delay1_o;
    float32 rtb_SFunction_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_Div_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_Div_m;
    float32 rtb_Unit_Delay3_l;
    float32 rtb_SFunction_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_Div_m4;
    float32 rtb_Unit_Delay1_a;
    float32 rtb_SFunction_ks;
    float32 rtb_Mul_b;
    float32 rtb_Div_er;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_Mul_ix;
    float32 rtb_ip_lookup_fxpt_sfun_7_e1;
    float32 rtb_Div_i;
    float32 rtb_Unit_Delay1_cv;
    float32 rtb_SFunction_ku;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_Div_eb;
    float32 rtb_Unit_Delay_f;
    float32 rtb_SFunction_j;
    float32 rtb_Mul_m2;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_gc;
    float32 rtb_Div_f;
    float32 rtb_Unit_Delay1_f;
    float32 rtb_SFunction_a;
    float32 rtb_Mul_jo;
    float32 rtb_ip_lookup_fxpt_sfun_7_dx;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_Div_fh;
    float32 rtb_Unit_Delay1_e;
    float32 rtb_SFunction_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_et;
    float32 rtb_Switch_iy;
    uint16 rtb_sfun_setbit;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_Sum_mk;
    uint8 rtb_VectorConcatenate[16];
    uint8 rtb_conversion_sfunction2;
    uint8 rtb_EQ_h;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_d4;
    uint8 rtb_NE;
    uint8 rtb_DataTypeConversion_l0;
    uint8 rtb_LogicalOperator;
    float32 rtb_Mul;
    float32 rtb_Sum;
    uint8 rtb_DataTypeConversion_jd;
    uint8 rtb_DataTypeConversion_ds;
    uint8 rtb_LogicalOperator_i;
    uint8 rtb_EQ;
    uint8 rtb_DataTypeConversion_d;
    uint8 rtb_DataTypeConversion_oa;
    uint8 rtb_DataTypeConversion_j;
    uint8 rtb_DataTypeConversion_o1;
    float32 rtb_Max;
    float32 rtb_Sum_ow;
    float32 rtb_Max_ml;
    float32 rtb_Min_a;
    float32 rtb_Switch_dh;
    uint8 rtb_LogicalOperator_ky;
    uint8 rtb_SignalConversion;
    float32 rtb_Max_jt;
    uint8 rtb_DataTypeConversion_or;
    uint8 rtb_DataTypeConversion_h;
    uint8 rtb_DataTypeConversion_bc;
    float32 rtb_Switch_id;
    float32 rtb_Sum_nd;
    uint8 rtb_DataTypeConversion_fs;
    float32 rtb_Sum_li;
    uint8 rtb_RelationalOperator_hc;
    uint8 rtb_RelationalOperator1_m;
    float32 rtb_Sum_o4;
    uint8 rtb_RelationalOperator_ce;
    uint8 rtb_RelationalOperator1_b;
    float32 rtb_Sum_bv5;
    uint8 rtb_RelationalOperator1_n;
    float32 rtb_Mul_pc;
    float32 rtb_Mul_kl;
    float32 rtb_Mul_ei;
    float32 rtb_Mul_mh;
    float32 rtb_Mul_jst;
    float32 rtb_Mul_j2;
    uint16 rtb_AND_pg;
    uint8 rtb_Switch3_e;
    uint8 rtb_Switch_ez;
    float32 rtb_Unit_Delay2;
    float32 rtb_Unit_Delay4;
    float32 rtb_Unit_Delay5;
    float32 rtb_Multiport_Switch;
    float32 rtb_Switch_l4;
    float32 rtb_Sum_o5;
    float32 rtb_Sum_hd;
    uint8 rtb_Switch_ji;
    float32 rtb_Sum_dn;
    float32 rtb_Switch_fd;
    float32 rtb_Switch_pv;
    float32 rtb_Sum_nk;
    float32 rtb_Switch_nr;
    float32 rtb_Switch_e;
    float32 rtb_Switch_dy;
    float32 rtb_Switch_kpw;
    uint8 rtb_Switch_jw;
    float32 rtb_Mul_dg;
    float32 rtb_Sum_atk;
    float32 rtb_Switch_a3;
    float32 rtb_Switch_bx;
    float32 rtb_Max_gw;
    uint8 rtb_DataTypeConversion_ja;
    uint8 rtb_DataTypeConversion_l;
    uint8 rtb_DataTypeConversion_m;
    float32 rtb_Mul_db;
    uint8 rtb_DataTypeConversion_ld;
    uint8 rtb_DataTypeConversion_gg;
    uint8 rtb_Sum_d;
    float32 rtb_Switch_os;
    uint8 LogicalOperator_ab;
    sint32 tmp;
    uint8 rtb_RelationalOperator_h;
    uint8 rtb_RelationalOperator_e;
    uint8 rtb_DataTypeConversion_ly;
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/Constant'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/Constant1'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjInvBitfield_btf'
         *  S-Function (sfix_bitop): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/AND/Functionality'/AND'
         */
    rtb_Switch_ez = (uint8)((((sint32)GET_S_ODPFOP_AccObjInvBitfield_btf()) & ((sint32)GET_P_ODPFOH_AccObjChange_btm())) != 0);
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/LT/Functionality'/LT'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl'/Unit_Delay'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck'/Unit_Delay'
         */
    rtb_DataTypeConversion = (uint8)(((((sint32)rtb_Switch_ez) != 0) && (GET_S_ODPFOP_AccObjPosX_met() < DW_odpfoh_Unit_Delay_DSTATE_b)) && (((sint32) DW_odpfoh_Unit_Delay_DSTATE_bc) != 0));
    /* S-Function (sfix_bitop): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/AND3/Functionality'/AND' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/Constant2'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjInvBitfield_btf'
         */
    rtb_AND_pg = (uint16)(((sint32)GET_P_ODPFOH_AccObjDtct_btm()) & ((sint32) GET_S_ODPFOP_AccObjInvBitfield_btf()));
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/GT/Functionality'/GT'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl'/Unit_Delay'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck'/Unit_Delay'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck'/Unit_Delay1'
         */
    rtb_DataTypeConversion_d4 = (uint8)((((!((((sint32) DW_odpfoh_Unit_Delay1_DSTATE_l2) != 0) && (!(((sint32)rtb_AND_pg) != 0)))) && (GET_S_ODPFOP_AccObjPosX_met() > DW_odpfoh_Unit_Delay_DSTATE_b)) && (((sint32) rtb_Switch_ez) != 0)) && (((sint32)DW_odpfoh_Unit_Delay_DSTATE_bc) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING'/fcg' */
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/Constant'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/Constant1'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjInvBitfield_btf'
         *  S-Function (sfix_bitop): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/AND1/Functionality'/AND'
         */
    rtb_NE = (uint8)((((sint32)GET_S_ODPFOP_AccObjInvBitfield_btf()) & ((sint32) GET_P_ODPFOH_AccObjFreeze_btm())) != 0);
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/AND3/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl'/Unit_Delay'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill'/Unit_Delay'
         */
    rtb_DataTypeConversion_l0 = (uint8)(((((sint32)DW_odpfoh_Unit_Delay_DSTATE_d) != 0) && (!(((sint32)rtb_NE) != 0))) && (((sint32) DW_odpfoh_Unit_Delay_DSTATE_bc) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING'/fcg' */
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/Application Parameter1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjInvBitfield_btf'
         *  S-Function (sfix_bitop): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/AND/Functionality'/AND'
         */
    rtb_EQ_h = (uint8)((((sint32)GET_S_ODPFOP_AccObjInvBitfield_btf()) & ((sint32)GET_P_ODPFOH_AccObjValidLSM_btm())) == 0);
    /* Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode'/Unit_Delay'
         */
    rtb_LogicalOperator = (uint8)((DW_odpfoh_Unit_Delay_DSTATE_h <= 0.0F) && (((sint32)rtb_EQ_h) != 0));
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_Mul = GET_S_LCFRCV_VehVelX_mps() * 3.6F;
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/ip_lookup1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_ODPFOH_MaxObjDistLSM_met(), &dps_result_ln);
    }
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Application Parameter8'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/ip_lookup1/Functionality/odtc'/Product'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/HYSTERESIS2/Functionality'/Relational Operator1'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/ip_lookup1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Sum4/Functionality'/Sum'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid'/Unit_Delay4'
         */
    if (GET_S_ODPFOP_AccObjPosX_met() > rtb_ip_lookup_fxpt_sfun_7) {
        rtb_Switch3_e = 1U;
    } else if (GET_S_ODPFOP_AccObjPosX_met() < (rtb_ip_lookup_fxpt_sfun_7 - GET_P_ODPFOH_MaxObjDistHystLSM_met())) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3_e = 0U;
    } else {
        rtb_Switch3_e = DW_odpfoh_Unit_Delay4_DSTATE_b;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/HYSTERESIS2/Functionality'/Switch3' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Application Parameter6'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Application Parameter7'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/logical_value1'/Constant'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/LT/Functionality'/LT'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Sum2/Functionality'/Sum'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Switch2/Functionality'/Switch'
         */
    if (rtb_Mul < GET_P_ODPFOH_LowSpeedMaxVel_kph()) {
        rtb_Switch_ez = 0U;
    } else if (rtb_Mul > (GET_P_ODPFOH_LowSpeedMaxVel_kph() + GET_P_ODPFOH_LowSpeedHystVel_kph())) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/logical_value2'/Constant'
                 */
        rtb_Switch_ez = 1U;
    } else {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Switch2/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/NOT3/Functionality'/NOT'
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/OR/Functionality'/OR'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay4'
                 */
        rtb_Switch_ez = (uint8)((!(((sint32)DW_odpfoh_Unit_Delay4_DSTATE_g) != 0)) || (((sint32)rtb_Switch3_e) != 0));
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid/Switch1/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/Application Parameter2'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/NOT/Functionality'/NOT'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising'/Unit_Delay'
         */
    rtb_DataTypeConversion_jd = (uint8)((((!(((sint32) DW_odpfoh_Unit_Delay_DSTATE_c) != 0)) && (((sint32)rtb_LogicalOperator) != 0)) && (!(((sint32)rtb_Switch_ez) != 0))) && (((sint32) GET_P_ODPFOH_EnableTransAtStart_bool()) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_o = (uint8)((((((sint32)rtb_DataTypeConversion) != 0) || (((sint32)rtb_DataTypeConversion_d4) != 0)) || (((sint32) rtb_DataTypeConversion_l0) != 0)) || (((sint32)rtb_DataTypeConversion_jd) != 0));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ds = (uint8)(!(((sint32)rtb_DataTypeConversion_o) != 0));
    /* Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime'/Unit_Delay'
         */
    rtb_LogicalOperator_i = (uint8)((((sint32)rtb_DataTypeConversion_o) != 0) || (DW_odpfoh_Unit_Delay_DSTATE_g > 0.0F));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch3/Functionality'/Switch' incorporates:
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch1/Functionality'/Switch'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch5/Functionality'/Switch'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch6/Functionality'/Switch'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier'/Unit_Delay2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier'/Unit_Delay4'
         */
    if ((((sint32)rtb_LogicalOperator_i) != 0) && (((sint32) rtb_DataTypeConversion_ds) != 0)) {
        rtb_DataTypeConversion = DW_odpfoh_Unit_Delay2_DSTATE_f;
        rtb_DataTypeConversion_d4 = DW_odpfoh_Unit_Delay4_DSTATE_e;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/Application Parameter1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjInvBitfield_btf'
         *  S-Function (sfix_bitop): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/AND/Functionality'/AND'
         */
    rtb_EQ = (uint8)((((sint32)GET_S_ODPFOP_AccObjInvBitfield_btf()) & ((sint32) GET_P_ODPFOH_AccObjKfUpdate_btm())) == 0);
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/Application Parameter4'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_TJAOBF_ObjInLaneValid_bool'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/NOT/Functionality'/NOT'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/OR/Functionality'/OR'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate'/Unit_Delay'
         */
    rtb_DataTypeConversion_d = (uint8)(((((sint32) GET_S_TJAOBF_ObjInLaneValid_bool()) != 0) || (!(((sint32) GET_P_ODPFOH_AccObjCheckLane_bool()) != 0))) && ((DW_odpfoh_Unit_Delay_DSTATE_j <= 0.0F) && (((sint32)rtb_EQ) != 0)));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Application Parameter1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Application Parameter3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Constant'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Constant4'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Constant5'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/logical_value'/Constant'
         *  DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/AND1/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/AND1/Functionality'/AND'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Max/Functionality'/Max'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Max1/Functionality'/Max'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Max2/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Div/Functionality/Div'/Div'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/LT/Functionality'/LT'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay3'
         */
    if (((sint32)DW_odpfoh_Unit_Delay3_DSTATE_d) > 0) {
        /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Sum/Functionality'/Sum' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay2'
                 */
        rtb_Mul = GET_S_ODPFOP_AccObjPosX_met() - DW_odpfoh_Unit_Delay2_DSTATE;
        rtb_DataTypeConversion_o1 = (uint8)((rtb_Mul < f32_max_f32_f32 (GET_P_ODPFOH_MaxObjHistSampleD_met(), GET_S_LCFRCV_VehVelX_mps() * GET_P_ODPFOH_MaxObjHistSampleT_sec())) && (rtb_Mul > f32_max_f32_f32 (GET_P_ODPFOH_MinObjHistSampleD_met(), GET_S_ODPFOP_AccObjPosX_met() / ((float32)u8_max_u8_u8(1U, GET_P_ODPFOH_NumObjDistHistParts_nu())))));
    } else {
        rtb_DataTypeConversion_o1 = 1U;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/OR/Functionality'/OR'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay4'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions'/Unit_Delay'
         */
    rtb_DataTypeConversion_oa = (uint8)((((!(((sint32) DW_odpfoh_Unit_Delay_DSTATE_e) != 0)) && (((sint32)rtb_DataTypeConversion_d) != 0)) && (((sint32)DW_odpfoh_Unit_Delay4_DSTATE_g) != 0)) || (((sint32) DW_odpfoh_Unit_Delay1_DSTATE_d) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckNewEntryConditions/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_j = (uint8)(((((sint32)rtb_DataTypeConversion_o1) != 0) && (((sint32)rtb_DataTypeConversion_d) != 0)) && (!(((sint32) rtb_DataTypeConversion_oa) != 0)));
    /* MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Max = f32_max_f32_f32(GET_P_LCF_AlmostZero_nu(), GET_S_LCFRCV_SysCycleTimeSen_sec());
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay3' */
    rtb_Mul = DW_odpfoh_Unit_Delay3_DSTATE;
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay1' */
    rtb_Sum = DW_odpfoh_Unit_Delay1_DSTATE;
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay2' */
    rtb_Unit_Delay2 = DW_odpfoh_Unit_Delay2_DSTATE_e;
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay4' */
    rtb_Unit_Delay4 = DW_odpfoh_Unit_Delay4_DSTATE;
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay5' */
    rtb_Unit_Delay5 = DW_odpfoh_Unit_Delay5_DSTATE;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    if (((sint32)GET_P_ODPFOH_YawRateDelayCycles_nu()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Limit/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Application Parameter2'/Constant'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Constant1'/Constant'
                 *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Limit/Functionality'/Relational Operator'
                 */
        if (6 >= ((sint32)GET_P_ODPFOH_YawRateDelayCycles_nu())) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Limit/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Constant10'/Constant'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Limit/Functionality'/Relational Operator1'
                         */
            if (1 <= ((sint32)GET_P_ODPFOH_YawRateDelayCycles_nu())) {
                rtb_DataTypeConversion_o1 = GET_P_ODPFOH_YawRateDelayCycles_nu();
            } else {
                rtb_DataTypeConversion_o1 = 1U;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Limit/Functionality'/Switch1' */
        } else {
            rtb_DataTypeConversion_o1 = 6U;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay/Limit/Functionality'/Switch' */
        /* MultiPortSwitch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Multiport_Switch' incorporates:
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay1'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay2'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay3'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay4'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay5'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay6'
                 */
        switch (rtb_DataTypeConversion_o1) {
        case 1:
            rtb_Multiport_Switch = DW_odpfoh_Unit_Delay3_DSTATE;
            break;
        case 2:
            rtb_Multiport_Switch = DW_odpfoh_Unit_Delay1_DSTATE;
            break;
        case 3:
            rtb_Multiport_Switch = DW_odpfoh_Unit_Delay2_DSTATE_e;
            break;
        case 4:
            rtb_Multiport_Switch = DW_odpfoh_Unit_Delay4_DSTATE;
            break;
        case 5:
            rtb_Multiport_Switch = DW_odpfoh_Unit_Delay5_DSTATE;
            break;
        default:
            rtb_Multiport_Switch = DW_odpfoh_Unit_Delay6_DSTATE;
            break;
        }
        /* End of MultiPortSwitch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Multiport_Switch' */
    } else {
        rtb_Multiport_Switch = GET_S_LCFRCV_VehYawRate_rps();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Application Parameter3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch4/Functionality'/Switch'
         */
    if (((sint32)GET_P_ODPFOH_UsePosYcorr_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Application Parameter1'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
                 *  Inport: '<Root>/S_ODPFOP_AccObjRelVelY_mps'
                 *  Inport: '<Root>/S_ODPFOP_EstimatedObjPosY_met'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Mul3/Functionality'/Mul'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Mul4/Functionality'/Mul'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Mul5/Functionality'/Mul'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Mul7/Functionality'/Mul'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Mul8/Functionality'/Mul'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Sum3/Functionality'/Sum'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Sum5/Functionality'/Sum'
                 */
        if (((sint32)GET_P_ODPFOH_UseEstimPosY_bool()) != 0) {
            rtb_Switch_l4 = GET_S_ODPFOP_EstimatedObjPosY_met() - ((GET_S_LCFRCV_VehYawRate_rps() * rtb_Max) * GET_S_ODPFOP_AccObjPosX_met ());
        } else {
            rtb_Switch_l4 = ((GET_S_ODPFOP_AccObjRelVelY_mps() * rtb_Max) + GET_S_ODPFOP_AccObjPosY_met()) - ((rtb_Max * rtb_Multiport_Switch) * GET_S_ODPFOP_AccObjPosX_met());
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch5/Functionality'/Switch' */
    } else if (((sint32)GET_P_ODPFOH_UseEstimPosY_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch4/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_EstimatedObjPosY_met'
                 */
        rtb_Switch_l4 = GET_S_ODPFOP_EstimatedObjPosY_met();
    } else {
        rtb_Switch_l4 = GET_S_ODPFOP_AccObjPosY_met();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Application Parameter2'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_UsePosYReduction_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch2/Functionality'/Switch' incorporates:
                 *  Abs: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Abs/Functionality'/Abs'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Constant10'/Constant'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Mul1/Functionality'/Mul'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Mul2/Functionality'/Mul'
                 *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/LT/Functionality'/LT'
                 */
        if (f32_abs_f32(rtb_Switch_l4) < 1.0F) {
            /* Signum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Sign/Functionality'/Sign' */
            if (rtb_Switch_l4 < 0.0F) {
                rtb_Switch_dh = -1.0F;
            } else if (rtb_Switch_l4 > 0.0F) {
                rtb_Switch_dh = 1.0F;
            } else if (rtb_Switch_l4 == 0.0F) {
                rtb_Switch_dh = 0.0F;
            } else {
                rtb_Switch_dh = rtb_Switch_l4;
            }
            /* End of Signum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Sign/Functionality'/Sign' */
            rtb_Switch_iy = (rtb_Switch_l4 * rtb_Switch_l4) * rtb_Switch_dh;
        } else {
            rtb_Switch_iy = rtb_Switch_l4;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch2/Functionality'/Switch' */
    } else {
        rtb_Switch_iy = rtb_Switch_l4;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/PosY_Preprocessing/Switch3/Functionality'/Switch' */
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_Mul_c = GET_S_LCFRCV_VehVelX_mps() * 3.6F;
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Y_ODPFOH_PT1TimeConstPosY_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelXPT1_kph */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelXPT1_kph(), rtb_Mul_c, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_ODPFOH_PT1TimeConstPosY_sec(), &dps_result_ln);
    }
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/LOWPASST_RE1/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Y_ODPFOH_PT1TimeConstPosY_sec/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Y_ODPFOH_PT1TimeConstPosY_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div = rtb_Max / f32_max_f32_f32(rtb_ip_lookup_fxpt_sfun_7_j, rtb_Max);
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter'/Unit_Delay1' */
    rtb_Unit_Delay1_d = DW_odpfoh_Unit_Delay1_DSTATE_b;
    /* S-Function (sfun_mmv): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/LOWPASST_RE1/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_o != 0U) {
        rtb_SFunction = rtb_Switch_iy;
    } else {
        rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_d, rtb_Switch_iy, rtb_Div);
    }
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Constant2'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_PT1PosYEnable_bool()) != 0) {
        rtb_Switch_dh = rtb_SFunction;
    } else {
        rtb_Switch_dh = rtb_Switch_iy;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    if (((sint32)GET_P_ODPFOH_UseEstimPosY_bool()) != 0) {
        rtb_Multiport_Switch = GET_S_LCFRCV_VehYawRate_rps();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Switch5/Functionality'/Switch' */
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Constant10'/Constant'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate'/Unit_Delay2'
         */
    rtb_Sum_o5 = (rtb_Multiport_Switch + DW_odpfoh_Unit_Delay2_DSTATE_b) / 2.0F;
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Y_ODPFOH_PT1TimeConstYawRate_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D (GETA_Y_ODPFOH_PT1TimeConstYawRate_sec(), &dps_result_ln);
    }
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Y_ODPFOH_PT1TimeConstYawRate_sec/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Y_ODPFOH_PT1TimeConstYawRate_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div_n = rtb_Max / f32_max_f32_f32(rtb_ip_lookup_fxpt_sfun_7_e, rtb_Max);
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate'/Unit_Delay1' */
    rtb_Unit_Delay1_o = DW_odpfoh_Unit_Delay1_DSTATE_j;
    /* S-Function (sfun_mmv): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/LOWPASST_RE/Functionality'/S-Function' */
    rtb_SFunction_f = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_o, rtb_Sum_o5, rtb_Div_n);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Application Parameter1'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_PT1YawRateEnable_bool()) != 0) {
        rtb_Sum_o5 = rtb_SFunction_f;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/meanVelX/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/meanVelX'/Unit_Delay1'
         */
    rtb_Sum_ow = GET_S_LCFRCV_VehVelX_mps() + DW_odpfoh_Unit_Delay1_DSTATE_c;
    /* MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Min1/Functionality'/Min' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant15'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant16'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Mul8/Functionality'/Mul'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Mul9/Functionality'/Mul'
         */
    rtb_Switch_l4 = f32_min_f32_f32(-(GET_P_ODPFOH_FeatPtsMinPosXTime_sec() * GET_S_LCFRCV_VehVelX_mps()), GET_P_ODPFOH_FeatPtsMinPosX_met());
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Y_ODPFOH_MinTrajectoryLength_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D(GETA_Y_ODPFOH_MaxSampleAge_sec(), &dps_result_ln);
    }
    /* MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant6'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant7'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Mul/Functionality'/Mul'
         */
    rtb_Max_ml = f32_max_f32_f32(GET_S_LCFRCV_VehVelX_mps() * GET_P_ODPFOH_MinHistLengthTime_sec(), GET_P_ODPFOH_MinHistLength_met());
    /* MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Min/Functionality'/Min' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant4'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant9'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Mul2/Functionality'/Mul'
         */
    rtb_Min_a = f32_min_f32_f32(GET_P_ODPFOH_MaxHistStartX0_met(), GET_S_LCFRCV_VehVelX_mps() * GET_P_ODPFOH_PredTimeMaxPosX0_sec());
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant1'/Constant'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay5'
         */
    rtb_Div_d = DW_odpfoh_Unit_Delay5_DSTATE_i / 100.0F;
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_StraightEstim_perc */
        FDPS_PTR_F32(GETA_X_ODPFOH_StraightEstim_perc(), rtb_Div_d, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D (GETA_Y_ODPFOH_WeightLastPolyfit_nu(), &dps_result_ln);
    }
    /* BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration'/ODPFOH_PF_StructIn' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/logical_value'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant12'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant18'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant19'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant20'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant21'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant22'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant23'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant24'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant25'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant5'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Constant8'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/meanVelX/Constant11'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosXStdDev_met'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosYStdDev_met'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Div/Functionality/Div'/Div'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Y_ODPFOH_MinTrajectoryLength_met/Functionality/odtc'/Product'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/ip_lookup/Functionality/odtc'/Product'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/meanVelX/Div1/Functionality/Div'/Div'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/Y_ODPFOH_MinTrajectoryLength_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay5'
         */
    rtb_ODPFOH_PF_StructIn.bEnable_bool = 1U;
    rtb_ODPFOH_PF_StructIn.bAddNewSample_bool = rtb_DataTypeConversion_j;
    rtb_ODPFOH_PF_StructIn.bReset_bool = rtb_DataTypeConversion_oa;
    rtb_ODPFOH_PF_StructIn.fObjXPos_met = GET_S_ODPFOP_AccObjPosX_met();
    rtb_ODPFOH_PF_StructIn.fObjYPos_met = rtb_Switch_dh;
    rtb_ODPFOH_PF_StructIn.fObjXPosStdDev_met = GET_S_ODPFOP_AccObjPosXStdDev_met();
    rtb_ODPFOH_PF_StructIn.fObjYPosStdDev_met = GET_S_ODPFOP_AccObjPosYStdDev_met();
    rtb_ODPFOH_PF_StructIn.fTimeSinceLastCall_sec = rtb_Max;
    rtb_ODPFOH_PF_StructIn.fEgoCrv_1pm = GET_S_LCFRCV_VehCrv_1pm();
    rtb_ODPFOH_PF_StructIn.fEgoYawRate_rps = rtb_Sum_o5;
    rtb_ODPFOH_PF_StructIn.fEgoVelX_mps = rtb_Sum_ow / 2.0F;
    rtb_ODPFOH_PF_StructIn.pPredYawRtVar_r2ps2 = 0.001F;
    rtb_ODPFOH_PF_StructIn.pPredVelXVar_m2 = 0.001F;
    rtb_ODPFOH_PF_StructIn.pModelPosYVar_m2 = 0.001F;
    rtb_ODPFOH_PF_StructIn.pModelYawVar_rad2 = 0.001F;
    rtb_ODPFOH_PF_StructIn.pModelCrvVar_1pm2 = 0.001F;
    rtb_ODPFOH_PF_StructIn.pModelCrvChngVar_1pm4 = 0.001F;
    rtb_ODPFOH_PF_StructIn.pObjMeasPosXVar_m2 = 0.001F;
    rtb_ODPFOH_PF_StructIn.pObjMeasPosYVar_m2 = 0.001F;
    rtb_ODPFOH_PF_StructIn.pCrvDecay_nu = GET_P_ODPFOH_PF_CrvDecay_nu();
    rtb_ODPFOH_PF_StructIn.pCrvChngDecay_nu = GET_P_ODPFOH_PF_CrvChngDecay_nu();
    rtb_ODPFOH_PF_StructIn.fMinHistStartPosX_met = rtb_Switch_l4;
    rtb_ODPFOH_PF_StructIn.fMaxSampleAge_sec = rtb_ip_lookup_fxpt_sfun_7_b;
    rtb_ODPFOH_PF_StructIn.uMinNumValidSamples_nu = GET_P_ODPFOH_MinValidEntries_nu();
    rtb_ODPFOH_PF_StructIn.fMinHistLength_met = rtb_Max_ml;
    rtb_ODPFOH_PF_StructIn.fMaxGapEgoToHist_met = rtb_Min_a;
    rtb_ODPFOH_PF_StructIn.pWeightLastFit_nu = rtb_ip_lookup_fxpt_sfun_7_d;
    /* S-Function (sfun_polyfitTgtObjectClothoid): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration'/sfun_polyfitTgtObjectClothoid' */
    polyfitTgtObjectClothoid((TgtObjectPF_Input*)&rtb_ODPFOH_PF_StructIn, &rtb_sfun_polyfitTgtObjectClothoid);
    /* Abs: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Abs2/Functionality'/Abs' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         */
    rtb_Sum_o5 = f32_abs_f32 (rtb_sfun_polyfitTgtObjectClothoid.fMeanDevToTraj_1st_met);
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Application Parameter3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant19'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant7'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant8'/Constant'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Div2/Functionality/Div'/Div'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Mul1/Functionality'/Mul'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Mul4/Functionality'/Mul'
         */
    rtb_Sum_o5 = (((GET_P_ODPFOH_StrEstimMeanDevFac_nu() * 2.0F) * rtb_Sum_o5) / f32_max_f32_f32(GET_P_LCF_AlmostZero_nu(), GET_P_ODPFOH_StrEstimMeanDev_met())) - GET_P_ODPFOH_StrEstimMeanDevFac_nu();
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant11'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Mul2/Functionality'/Mul'
         */
    rtb_Sum_hd = (rtb_Sum_o5 * rtb_Sum_o5) + 1.0F;
    /* Sqrt: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/MathFunction/Functionality'/MathFunction' */
    rtb_Sum_hd = f32_sqrt_f32(rtb_Sum_hd);
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Mul3/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant15'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant17'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant5'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Div1/Functionality/Div'/Div'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Div3/Functionality/Div'/Div'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Sum1/Functionality'/Sum'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Sum4/Functionality'/Sum'
         */
    rtb_Switch_os = (1.0F - (((rtb_Sum_o5 / rtb_Sum_hd) + 1.0F) / 2.0F)) * 100.0F;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch3/Functionality'/Switch' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/NOT/Functionality'/NOT'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/OR/Functionality'/OR'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay'
         */
    if (((((sint32)rtb_DataTypeConversion) != 0) || (((sint32) rtb_DataTypeConversion_d4) != 0)) || (!(((sint32) rtb_DataTypeConversion_d) != 0))) {
        rtb_Sum_ow = DW_odpfoh_Unit_Delay_DSTATE;
    } else {
        rtb_Sum_ow = rtb_Switch_os;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/OR/Functionality'/Data Type Conversion' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/OR/Functionality'/OR'
         */
    rtb_Switch_jw = (uint8)((((sint32) rtb_sfun_polyfitTgtObjectClothoid.bTrajInvalid3rd_bool) != 0) || (((sint32) rtb_sfun_polyfitTgtObjectClothoid.bTrajInvalid1st_bool) != 0));
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay4'
         */
    LogicalOperator_ab = (uint8)((!(((sint32)DW_odpfoh_Unit_Delay4_DSTATE_gn) != 0)) && (((sint32)rtb_Switch_jw) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1'/fcg' */
    /* Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay3'
         */
    rtb_LogicalOperator_ky = (uint8)((((sint32)rtb_Switch_jw) != 0) || (DW_odpfoh_Unit_Delay3_DSTATE_p > 0.0F));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/SRFLIPFLOP/Functionality'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay2'
         */
    if (((sint32)LogicalOperator_ab) != 0) {
        rtb_DataTypeConversion_o1 = 1U;
    } else {
        /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING'/fcg' incorporates:
                 *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality'/Comparison'
                 */
        if ((((sint32)DW_odpfoh_Unit_Delay2_DSTATE_ow) != 0) && (!(((sint32) rtb_LogicalOperator_ky) != 0))) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/SRFLIPFLOP/Functionality'/Constant1'
                         */
            rtb_DataTypeConversion_o1 = 0U;
        } else {
            rtb_DataTypeConversion_o1 = DW_odpfoh_Unit_Delay1_DSTATE_e0;
        }
        /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING'/fcg' */
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/SRFLIPFLOP/Functionality'/Switch' */
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/SRFLIPFLOP/Functionality'/Signal Conversion' */
    rtb_SignalConversion = rtb_DataTypeConversion_o1;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/Application Parameter6'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/Application Parameter7'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/Constant16'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/Mul5/Functionality'/Mul'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/LT/Functionality'/LT'
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/SRFLIPFLOP/Functionality'/Signal Conversion'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/Sum7/Functionality'/Sum'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging'/Unit_Delay'
         */
    rtb_DataTypeConversion_o1 = (uint8)(((GET_S_LCFRCV_VehVelX_mps() * 3.6F) < (GET_P_ODPFOH_LowSpeedMaxVel_kph() + GET_P_ODPFOH_LowSpeedHystVel_kph())) && ((!(((sint32)DW_odpfoh_Unit_Delay_DSTATE_jh) != 0)) && (((sint32) rtb_DataTypeConversion_o1) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging/NOT/Functionality'/NOT'
         */
    rtb_Switch_ez = (uint8)((((sint32)rtb_Switch_ez) != 0) && (!(((sint32) rtb_DataTypeConversion_o1) != 0)));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant18'/Constant'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch6/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_ez) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Application Parameter6'/Constant'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Application Parameter7'/Constant'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant12'/Constant'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant16'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/AND/Functionality'/AND'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Mul5/Functionality'/Mul'
                 *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/GT5/Functionality'/GT'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Sum7/Functionality'/Sum'
                 */
        if (((GET_S_LCFRCV_VehVelX_mps() * 3.6F) > (GET_P_ODPFOH_LowSpeedMaxVel_kph() + GET_P_ODPFOH_LowSpeedHystVel_kph())) && (((sint32) rtb_SignalConversion) != 0)) {
            rtb_DataTypeConversion_gg = 0U;
        } else {
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Div4/Functionality/Div'/Div' incorporates:
                         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant13'/Constant'
                         */
            rtb_Max_gw = rtb_sfun_polyfitTgtObjectClothoid.fMeanSampleAge_sec / 3.0F;
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant1'/Constant'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/GT/Functionality'/GT'
                         */
            if (rtb_Max_gw > 1.0F) {
                rtb_Max_gw = 1.0F;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch1/Functionality'/Switch' */
            /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/DTC1'/Data Type Conversion' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant14'/Constant'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant3'/Constant'
                         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Mul3/Functionality'/Mul'
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Sum5/Functionality'/Sum'
                         */
            rtb_DataTypeConversion_ja = u8_f32((1.0F - rtb_Max_gw) * 20.0F);
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Div3/Functionality/Div'/Div' incorporates:
                         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant7'/Constant'
                         */
            rtb_Max_gw = rtb_sfun_polyfitTgtObjectClothoid.fMeanDevToTraj_3rd_met / 0.2F;
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant1'/Constant'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/GT1/Functionality'/GT'
                         */
            if (rtb_Max_gw > 1.0F) {
                rtb_Max_gw = 1.0F;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch2/Functionality'/Switch' */
            /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/DTC2'/Data Type Conversion' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant11'/Constant'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant8'/Constant'
                         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Mul2/Functionality'/Mul'
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Sum3/Functionality'/Sum'
                         */
            rtb_DataTypeConversion_l = u8_f32((1.0F - rtb_Max_gw) * 15.0F);
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Div/Functionality/Div'/Div' incorporates:
                         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant2'/Constant'
                         */
            rtb_Max_gw = ((float32) rtb_sfun_polyfitTgtObjectClothoid.uNumValidSamples_nu) / 20.0F;
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant1'/Constant'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/GT2/Functionality'/GT'
                         */
            if (rtb_Max_gw > 1.0F) {
                rtb_Max_gw = 1.0F;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch4/Functionality'/Switch' */
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Mul/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant9'/Constant'
                         */
            rtb_Max_gw *= 10.0F;
            /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/DTC3'/Data Type Conversion' */
            rtb_DataTypeConversion_m = u8_f32(rtb_Max_gw);
            /* MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Max/Functionality'/Max' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant4'/Constant'
                         */
            rtb_Max_gw = f32_max_f32_f32(1.0F, GET_S_LCFRCV_VehVelX_mps());
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Div2/Functionality/Div'/Div' incorporates:
                         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant5'/Constant'
                         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Div1/Functionality/Div'/Div'
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping/Sum/Functionality'/Sum'
                         */
            rtb_Mul_db = ((rtb_sfun_polyfitTgtObjectClothoid.fTrajLength_met - rtb_sfun_polyfitTgtObjectClothoid.fPosX0_met) / rtb_Max_gw) / 2.5F;
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant1'/Constant'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/GT3/Functionality'/GT'
                         */
            if (rtb_Mul_db > 1.0F) {
                rtb_Mul_db = 1.0F;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch3/Functionality'/Switch' */
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Mul1/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant6'/Constant'
                         */
            rtb_Mul_db *= 15.0F;
            /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/DTC4'/Data Type Conversion' */
            rtb_DataTypeConversion_ld = u8_f32(rtb_Mul_db);
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Div6/Functionality/Div'/Div' incorporates:
                         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant10'/Constant'
                         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Div5/Functionality/Div'/Div'
                         */
            rtb_Mul_db = (rtb_sfun_polyfitTgtObjectClothoid.fTrajLength_met / rtb_Max_gw) / 1.8F;
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant1'/Constant'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/GT4/Functionality'/GT'
                         */
            if (rtb_Mul_db > 1.0F) {
                rtb_Mul_db = 1.0F;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch6/Functionality'/Switch' */
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Mul4/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Constant15'/Constant'
                         */
            rtb_Mul_db *= 40.0F;
            /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/DTC5'/Data Type Conversion' */
            rtb_DataTypeConversion_gg = u8_f32(rtb_Mul_db);
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit6'/MX'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit6/Functionality'/Relational Operator'
                         */
            if (!(40 >= ((sint32)rtb_DataTypeConversion_gg))) {
                rtb_DataTypeConversion_gg = 40U;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit6/Functionality'/Switch' */
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit5/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit5'/MX'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit5/Functionality'/Relational Operator'
                         */
            if (!(15 >= ((sint32)rtb_DataTypeConversion_ld))) {
                rtb_DataTypeConversion_ld = 15U;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit5/Functionality'/Switch' */
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit4'/MX'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit4/Functionality'/Relational Operator'
                         */
            if (!(20 >= ((sint32)rtb_DataTypeConversion_ja))) {
                rtb_DataTypeConversion_ja = 20U;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit4/Functionality'/Switch' */
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit3'/MX'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit3/Functionality'/Relational Operator'
                         */
            if (!(15 >= ((sint32)rtb_DataTypeConversion_l))) {
                rtb_DataTypeConversion_l = 15U;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit3/Functionality'/Switch' */
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit2'/MX'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit2/Functionality'/Relational Operator'
                         */
            if (!(10 >= ((sint32)rtb_DataTypeConversion_m))) {
                rtb_DataTypeConversion_m = 10U;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit2/Functionality'/Switch' */
            /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Sum2/Functionality'/Sum' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Sum6/Functionality'/Sum'
                         */
            rtb_DataTypeConversion_ja = u8_u32(((uint32)u8_u32(((uint32)u8_u32 (((uint32)rtb_DataTypeConversion_ja) + ((uint32)((sint32) rtb_DataTypeConversion_l)))) + ((uint32)((sint32) rtb_DataTypeConversion_m)))) + ((uint32)((sint32)u8_u32(((uint32) rtb_DataTypeConversion_ld) + ((uint32)((sint32) rtb_DataTypeConversion_gg))))));
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit1'/MX'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit1/Functionality'/Relational Operator'
                         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit1/Functionality'/Switch1'
                         */
            if (100 >= ((sint32)rtb_DataTypeConversion_ja)) {
                rtb_DataTypeConversion_gg = rtb_DataTypeConversion_ja;
            } else {
                rtb_DataTypeConversion_gg = 100U;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Limit1/Functionality'/Switch' */
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/TraceQualCalc/Switch5/Functionality'/Switch' */
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch7/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant21'/Constant'
                 */
        if (((sint32)GET_P_ODPFOH_UseStrEstimLimit_bool()) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant14'/Constant'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant2'/Constant'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant3'/Constant'
                         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Max3/Functionality'/Max'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/LT/Functionality'/LT'
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/LT1/Functionality'/LT'
                         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch5/Functionality'/Switch'
                         */
            if (((sint32)rtb_DataTypeConversion_gg) < 25) {
                rtb_Switch_os = f32_max_f32_f32(96.0F, rtb_Sum_ow);
            } else if (((sint32)rtb_DataTypeConversion_gg) < 50) {
                /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch5/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant16'/Constant'
                                 *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Max2/Functionality'/Max'
                                 */
                rtb_Switch_os = f32_max_f32_f32(75.0F, rtb_Sum_ow);
            } else {
                /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch5/Functionality'/Switch' */
                rtb_Switch_os = rtb_Sum_ow;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch4/Functionality'/Switch' */
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch7/Functionality'/Switch' */
    } else {
        rtb_DataTypeConversion_gg = 75U;
        rtb_Switch_os = 75.0F;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceQuality/Switch1/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality'/Comparison'
         */
    /* Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality'/Logical Operator1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay1'
         */
    BI_odpfoh_LogicalOperator_m = (uint8)((((sint32)DW_odpfoh_Unit_Delay1_DSTATE_ej) != 0) && (!(((sint32)rtb_SignalConversion) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING'/fcg' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch2' */
    if (((sint32)BI_odpfoh_LogicalOperator_m) != 0) {
        rtb_Max_gw = rtb_Switch_os;
    } else {
        /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Mul1/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant13'/Constant'
                 */
        rtb_Mul_db = GET_P_ODPFOH_StrEstimPosGrad_1ps() * rtb_Max;
        /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Add/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay2'
                 */
        rtb_Max_gw = rtb_Switch_os - DW_odpfoh_Unit_Delay2_DSTATE_j;
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay2'
                 */
        if (rtb_Max_gw > rtb_Mul_db) {
            rtb_Max_gw = rtb_Mul_db + DW_odpfoh_Unit_Delay2_DSTATE_j;
        } else {
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Mul/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant4'/Constant'
                         */
            rtb_Mul_db = GET_P_ODPFOH_StrEstimNegGrad_1ps() * rtb_Max;
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality'/Relational Operator1'
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay2'
                         */
            if (rtb_Max_gw < rtb_Mul_db) {
                rtb_Max_gw = rtb_Mul_db + DW_odpfoh_Unit_Delay2_DSTATE_j;
            } else {
                rtb_Max_gw = rtb_Switch_os;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6' */
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5' */
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant10'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_UseStrEstimGradLim_bool()) != 0) {
        rtb_Sum_hd = rtb_Max_gw;
    } else {
        rtb_Sum_hd = rtb_Switch_os;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch/Functionality'/Switch' */
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant20'/Constant'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Max1/Functionality'/Max'
         */
    rtb_Div_m = rtb_Max / f32_max_f32_f32(GET_P_ODPFOH_StrEstimPT1_sec(), rtb_Max);
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay3' */
    rtb_Unit_Delay3_l = DW_odpfoh_Unit_Delay3_DSTATE_j;
    /* S-Function (sfun_mmv): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_odpfoh_LogicalOperator_m != 0U) {
        rtb_SFunction_k = rtb_Sum_hd;
    } else {
        rtb_SFunction_k = f32_mmv_f32_f32_f32( rtb_Unit_Delay3_l, rtb_Sum_hd, rtb_Div_m);
    }
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Constant9'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_UseStrEstimPT1_bool()) != 0) {
        rtb_Switch_os = rtb_SFunction_k;
    } else {
        rtb_Switch_os = rtb_Sum_hd;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/Switch1/Functionality'/Switch' */
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D(GETA_Y_ODPFOH_WeightCrvPolyfit_nu (), &dps_result_ln);
    }
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/ip_lookup/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/ip_lookup/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_hd = rtb_ip_lookup_fxpt_sfun_7_a;
    /* MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/Min/Functionality'/Min' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/Constant2'/Constant'
         */
    rtb_Sum_hd = f32_min_f32_f32(1.0F, rtb_Sum_hd);
    /* MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/Constant1'/Constant'
         */
    rtb_Sum_hd = f32_max_f32_f32(rtb_Sum_hd, 0.0F);
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/WeightPosY0/fading/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/WeightPosY0/fading/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/WeightPosY0/fading/Functionality/B_minus_A/Functionality'/Sum'
         */
    rtb_Sum_o5 = ((rtb_sfun_polyfitTgtObjectClothoid.fPosY0_3rd_met - rtb_sfun_polyfitTgtObjectClothoid.fPosY0_1st_met) * rtb_Sum_hd) + rtb_sfun_polyfitTgtObjectClothoid.fPosY0_1st_met;
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/Constant2'/Constant'
         */
    rtb_Mul_db = rtb_Switch_os / 100.0F;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimPosY0/Switch1/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimPosY0/Application Parameter2'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimPosY0/fading/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimPosY0/fading/Functionality/B_minus_A/Functionality'/Sum'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimPosY0/fading/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum'
         */
    if (((sint32)GET_P_ODPFOH_UseStraightEstim_bool()) != 0) {
        rtb_Sum_o5 += (rtb_sfun_polyfitTgtObjectClothoid.fPosY0_1st_met - rtb_Sum_o5) * rtb_Mul_db;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimPosY0/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/WeightHead/fading/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/WeightHead/fading/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/WeightHead/fading/Functionality/B_minus_A/Functionality'/Sum'
         */
    rtb_Switch_a3 = ((rtb_sfun_polyfitTgtObjectClothoid.fHeading_3rd_rad - rtb_sfun_polyfitTgtObjectClothoid.fHeading_1st_rad) * rtb_Sum_hd) + rtb_sfun_polyfitTgtObjectClothoid.fHeading_1st_rad;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimHead/Switch1/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimHead/Application Parameter2'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimHead/fading/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimHead/fading/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimHead/fading/Functionality/B_minus_A/Functionality'/Sum'
         */
    if (((sint32)GET_P_ODPFOH_UseStraightEstim_bool()) != 0) {
        rtb_Switch_a3 += (rtb_sfun_polyfitTgtObjectClothoid.fHeading_1st_rad - rtb_Switch_a3) * rtb_Mul_db;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimHead/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/WeightCrv/fading/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/PolyfitSelection/WeightCrv/fading/Functionality/F_times_B_minus_A/Functionality'/Mul'
         */
    rtb_Sum_hd *= rtb_sfun_polyfitTgtObjectClothoid.fCrv_1pm;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimCrv/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimCrv/Application Parameter2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimCrv/Constant1'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimCrv/fading/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimCrv/fading/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimCrv/fading/Functionality/B_minus_A/Functionality'/Sum'
         */
    if (((sint32)GET_P_ODPFOH_UseStraightEstim_bool()) != 0) {
        rtb_Sum_hd += (0.0F - rtb_Sum_hd) * rtb_Mul_db;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/StraightEstimationFading CrvLimiter/StraightEstimCrv/Switch1/Functionality'/Switch' */
    /* MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/meanVelX/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/meanVelX/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_Max_jt = f32_max_f32_f32(GET_S_LCFRCV_VehVelX_mps(), GET_P_ODPFOH_MinVelForKF_mps());
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/Y_ODPFOH_PT1TimeConstYawRate_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_ODPFOH_PT1TimeConstYawRate_sec(), &dps_result_ln);
    }
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/Y_ODPFOH_PT1TimeConstYawRate_sec/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/Y_ODPFOH_PT1TimeConstYawRate_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div_m4 = rtb_Max / f32_max_f32_f32(rtb_ip_lookup_fxpt_sfun_7_l, rtb_Max);
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate'/Unit_Delay1' */
    rtb_Unit_Delay1_a = DW_odpfoh_Unit_Delay1_DSTATE_a;
    /* S-Function (sfun_mmv): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/LOWPASST_RE/Functionality'/S-Function' */
    rtb_SFunction_ks = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_a, GET_S_LCFRCV_VehYawRate_rps(), rtb_Div_m4);
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ja = (uint8)(!(((sint32)rtb_SignalConversion) != 0));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant23'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/HYSTERESIS/Functionality'/Relational Operator'
         */
    if (((sint32)rtb_DataTypeConversion_gg) > ((sint32) GET_P_ODPFOH_ObjKFDegrUpdateQu_perc())) {
        rtb_DataTypeConversion_l = 1U;
    } else {
        /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant2'/Constant'
                 */
        tmp = ((sint32)GET_P_ODPFOH_ObjKFDegrUpdateQu_perc()) - 9;
        if (tmp < 0) {
            tmp = 0;
        }
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/HYSTERESIS/Functionality'/Constant'
                 *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/HYSTERESIS/Functionality'/Relational Operator1'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation'/Unit_Delay2'
                 */
        if (((sint32)rtb_DataTypeConversion_gg) < tmp) {
            rtb_DataTypeConversion_l = 0U;
        } else {
            rtb_DataTypeConversion_l = DW_odpfoh_Unit_Delay2_DSTATE_jw;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/HYSTERESIS/Functionality'/Switch2' */
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/HYSTERESIS/Functionality'/Switch3' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant9'/Constant'
         *  DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/AND/Functionality'/Data Type Conversion'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/NOT/Functionality'/NOT'
         */
    if (((sint32)GET_P_ODPFOH_ObjKFDegrUpdate_bool()) != 0) {
        rtb_Switch_ji = (uint8)((((sint32)rtb_DataTypeConversion_ja) != 0) && (!(((sint32)rtb_DataTypeConversion_l) != 0)));
    } else {
        rtb_Switch_ji = GET_P_ODPFOH_ObjKFDegrUpdate_bool();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant1'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation'/Unit_Delay1'
         */
    if ((!(((sint32)DW_odpfoh_Unit_Delay1_DSTATE_cw) != 0)) && (((sint32) rtb_DataTypeConversion_ja) != 0)) {
        rtb_Mul_db = 1.0F;
    } else {
        /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Mul1/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant4'/Constant'
                 */
        rtb_Mul_dg = GET_P_ODPFOH_ObjKFDegrUpdGrad_1ps() * rtb_Max;
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant32'/Constant'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant6'/Constant'
                 */
        if (((sint32)rtb_Switch_ji) != 0) {
            rtb_Mul_db = GET_P_ODPFOH_ObjKFDegrUpdWeight_nu();
        } else {
            rtb_Mul_db = 1.0F;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Switch3/Functionality'/Switch' */
        /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Add/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation'/Unit_Delay'
                 */
        rtb_Sum_atk = rtb_Mul_db - DW_odpfoh_Unit_Delay_DSTATE_f;
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation'/Unit_Delay'
                 */
        if (rtb_Sum_atk > rtb_Mul_dg) {
            rtb_Mul_db = rtb_Mul_dg + DW_odpfoh_Unit_Delay_DSTATE_f;
        } else {
            /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Mul/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant3'/Constant'
                         */
            rtb_Mul_dg = -100.0F * rtb_Max;
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator1'
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation'/Unit_Delay'
                         */
            if (rtb_Sum_atk < rtb_Mul_dg) {
                rtb_Mul_db = rtb_Mul_dg + DW_odpfoh_Unit_Delay_DSTATE_f;
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' */
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' */
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING'/fcg' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Constant5'/Constant'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/LT1/Functionality'/LT'
         */
    if (((sint32)rtb_Switch_ji) == 0) {
        rtb_Switch_ji = (uint8)(rtb_Mul_db < 0.9F);
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/Switch1/Functionality'/Switch' */
    /* BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructIn' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter4'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Constant10'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Constant11'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Constant19'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Constant4'/Constant'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Max/Functionality'/Max'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Max1/Functionality'/Max'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Max2/Functionality'/Max'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Max3/Functionality'/Max'
         */
    rtb_ODPFOH_PF_KF_StructIn.fPosY0_met = rtb_Sum_o5;
    rtb_ODPFOH_PF_KF_StructIn.fHeadingAngle_rad = rtb_Switch_a3;
    rtb_ODPFOH_PF_KF_StructIn.fCrv_1pm = rtb_Sum_hd;
    rtb_ODPFOH_PF_KF_StructIn.fLength_met = rtb_sfun_polyfitTgtObjectClothoid.fTrajLength_met;
    rtb_ODPFOH_PF_KF_StructIn.fPosY0StdDev_met = f32_max_f32_f32(0.005F, GET_P_ODPFOH_PosY0StdDev_met());
    rtb_ODPFOH_PF_KF_StructIn.fHeadingAngleStdDev_rad = f32_max_f32_f32(0.001F, GET_P_ODPFOH_HeadingAngStdDev_rad());
    rtb_ODPFOH_PF_KF_StructIn.fCrvStdDev_1pm = f32_max_f32_f32(0.0001F, GET_P_ODPFOH_CrvStdDev_1pm());
    rtb_ODPFOH_PF_KF_StructIn.fVehYawRateStdDev_radps = f32_max_f32_f32(0.001F, GET_P_ODPFOH_VehYawRateStdDev_radps());
    rtb_ODPFOH_PF_KF_StructIn.fVehVelX_mps = rtb_Max_jt;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/Application Parameter1'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_PT1YawRateEnable_bool()) != 0) {
        /* BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructIn' */
        rtb_ODPFOH_PF_KF_StructIn.fVehYawRate_radps = rtb_SFunction_ks;
    } else {
        /* BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructIn' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
                 */
        rtb_ODPFOH_PF_KF_StructIn.fVehYawRate_radps = GET_S_LCFRCV_VehYawRate_rps();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate/Switch/Functionality'/Switch' */
    /* BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructIn' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter10'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter11'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter12'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter13'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter14'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter15'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter16'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter17'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter18'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter5'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter6'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter7'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter8'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/Application Parameter9'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/logical_value3'/Constant'
         */
    rtb_ODPFOH_PF_KF_StructIn.fDeltaT_sec = rtb_Max;
    rtb_ODPFOH_PF_KF_StructIn.bEnableKF_bool = GET_P_ODPFOH_EnableObjTraceKF_bool();
    rtb_ODPFOH_PF_KF_StructIn.bObjDataValid_bool = rtb_DataTypeConversion_ja;
    rtb_ODPFOH_PF_KF_StructIn.bDegradedUpdate_bool = rtb_Switch_ji;
    rtb_ODPFOH_PF_KF_StructIn.uOverallMeasurementQuality_perc = rtb_DataTypeConversion_gg;
    rtb_ODPFOH_PF_KF_StructIn.bObjChange_bool = 0U;
    rtb_ODPFOH_PF_KF_StructIn.fObjKinMaxLatAccel_mps2 = GET_P_ODPFOH_ObjKinMaxLatAccel_mps2();
    rtb_ODPFOH_PF_KF_StructIn.fObjKinMaxLatJerk_mps3 = GET_P_ODPFOH_ObjKinMaxLatJerk_mps3();
    rtb_ODPFOH_PF_KF_StructIn.fObjKinRefVel_mps = GET_P_ODPFOH_ObjKinRefVel_mps();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFInitRFactor_nu = GET_P_ODPFOH_ObjKFInitRFactor_nu();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFDegradeWeight_nu = rtb_Mul_db;
    rtb_ODPFOH_PF_KF_StructIn.uObjKFMnUpdateQual_perc = GET_P_ODPFOH_ObjKFMinUpdateQual_perc();
    rtb_ODPFOH_PF_KF_StructIn.uObjKFMnInitQual_perc = GET_P_ODPFOH_ObjKFMinInitQual_perc();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFIncQual_1ps = GET_P_ODPFOH_ObjKFIncrQual_1ps();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFDecQualDeg_1ps = GET_P_ODPFOH_ObjKFDecQualDegr_1ps();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFDecQualPred_1ps = GET_P_ODPFOH_ObjKFDecQualPred_1ps();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFKGainFac_nu = GET_P_ODPFOH_ObjKFKGainFact_nu();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFDynYawFactor_nu = GET_P_ODPFOH_ObjKFDynYawFact_nu();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFDynDistYFact_nu = GET_P_ODPFOH_ObjKFDynDistYFact_nu();
    rtb_ODPFOH_PF_KF_StructIn.fObjKFDynCrvFact_nu = GET_P_ODPFOH_ObjKFDynCrvFact_nu();
    /* S-Function (sfun_objTraceKalmanFilter): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/sfun_objTraceKalmanFilter' */
    objTraceKalmanFilter((TgtObjectTraceKF_Input*)&rtb_ODPFOH_PF_KF_StructIn, &rtb_sfun_objTraceKalmanFilter);
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/NOT/Functionality'/NOT'
         */
    rtb_Switch_ji = (uint8)(!(((sint32)rtb_LogicalOperator) != 0));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/OR/Functionality'/Data Type Conversion' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Constant2'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/LT/Functionality'/LT'
         */
    rtb_DataTypeConversion_or = (uint8)((((sint32) rtb_sfun_objTraceKalmanFilter.uKFStatus_btf) < 1) || (((sint32) rtb_sfun_objTraceKalmanFilter.uKFStatus_btf) > 3));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Application Parameter19'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_EnableObjTraceKF_bool()) != 0) {
        rtb_DataTypeConversion_m = rtb_DataTypeConversion_or;
    } else {
        rtb_DataTypeConversion_m = rtb_SignalConversion;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Application Parameter1'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/AND/Functionality'/AND'
         */
    if ((((sint32)GET_P_ODPFOH_EnableObjTraceKF_bool()) != 0) && (((sint32) rtb_Switch_ez) != 0)) {
        /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Sum1/Functionality'/Sum' incorporates:
                 *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
                 */
        rtb_Sum_mk = u8_u32(((uint32) rtb_sfun_objTraceKalmanFilter.uQualityMeasure_perc) + ((uint32)((sint32)rtb_DataTypeConversion_gg)));
        /* DTC_F32 : sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/DTC_F1'/conversion_sfunction2 */
        rtb_conversion_sfunction2 = rtb_Sum_mk;
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch19'/copy1' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Constant10'/Constant'
                 *  DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/DTC'/Data Type Conversion'
                 *  DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/DTC_F1'/Data Type Conversion'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Div/Functionality/Div'/Div'
                 */
        SET_S_ODPFOH_ObjTraceQual_perc(u8_f32(((float32)rtb_conversion_sfunction2) / 2.0F));
    } else {
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch19'/copy1' */
        SET_S_ODPFOH_ObjTraceQual_perc(rtb_DataTypeConversion_gg);
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Switch2/Functionality'/Switch' incorporates:
         *  DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/NOT1/Functionality'/Data Type Conversion'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/NOT1/Functionality'/NOT'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Switch3/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_ez) != 0) {
        rtb_DataTypeConversion_gg = rtb_DataTypeConversion_m;
        rtb_VectorConcatenate[5] = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    } else {
        rtb_DataTypeConversion_gg = rtb_Switch_ji;
        rtb_VectorConcatenate[5] = rtb_Switch_ji;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/EvaluateOverallValidityAndQuality/Switch2/Functionality'/Switch' */
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16'/ConcatBufferAtVector ConcatenateIn10' */
    rtb_VectorConcatenate[9] = rtb_Switch_ez;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi/EDGEBI'/Functionality'
         */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/AND4/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi/EDGEBI/Functionality'/Relational Operator'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic'/Unit_Delay'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi'/Unit_Delay3'
         */
    rtb_DataTypeConversion_o1 = (uint8)(((((sint32)DW_odpfoh_Unit_Delay_DSTATE_k) != 0) && (((sint32)rtb_Switch_ez) != ((sint32)DW_odpfoh_Unit_Delay3_DSTATE_n))) || (((sint32)rtb_DataTypeConversion_o1) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi/EDGEBI'/fcg' */
    /* Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime'/Unit_Delay'
         */
    rtb_DataTypeConversion_ld = (uint8)((((sint32)rtb_DataTypeConversion_o1) != 0) || (DW_odpfoh_Unit_Delay_DSTATE_a > 0.0F));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/DefineModeTransitionQualifier/Switch9/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/DefineModeTransitionQualifier/Switch10/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/DefineModeTransitionQualifier/NOT/Functionality'/NOT'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/DefineModeTransitionQualifier'/Unit_Delay5'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o1) != 0)) {
            rtb_Sum_d = DW_odpfoh_Unit_Delay5_DSTATE_m;
        } else {
            rtb_Sum_d = 1U;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/DefineModeTransitionQualifier/Switch10/Functionality'/Switch' */
    } else {
        rtb_Sum_d = rtb_DataTypeConversion_o1;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/DefineModeTransitionQualifier/Switch9/Functionality'/Switch' */
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16'/ConcatBufferAtVector ConcatenateIn11' */
    rtb_VectorConcatenate[10] = rtb_Sum_d;
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16'/ConcatBufferAtVector ConcatenateIn12' */
    rtb_VectorConcatenate[11] = rtb_DataTypeConversion_or;
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16'/ConcatBufferAtVector ConcatenateIn14' */
    rtb_VectorConcatenate[13] = rtb_DataTypeConversion_oa;
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16'/ConcatBufferAtVector ConcatenateIn15' */
    rtb_VectorConcatenate[14] = rtb_DataTypeConversion_gg;
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_DataTypeConversion;
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_d4;
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_SignalConversion;
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate[1] = (uint8)(!(((sint32)rtb_LogicalOperator) != 0));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/DTC'/Data Type Conversion' */
    rtb_DataTypeConversion_oa = u8_f32(rtb_Switch_os);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Constant4'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Constant5'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/HYSTERESIS/Functionality'/Relational Operator1'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_oa) > ((sint32) GET_P_ODPFOH_SignLimStrEstRSP_perc())) {
        rtb_DataTypeConversion_oa = 1U;
    } else if (((sint32)rtb_DataTypeConversion_oa) < ((sint32) GET_P_ODPFOH_SignLimStrEstLSP_perc())) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_DataTypeConversion_oa = 0U;
    } else {
        rtb_DataTypeConversion_oa = DW_odpfoh_Unit_Delay1_DSTATE_f;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/HYSTERESIS/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/NOT1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_or = (uint8)(!(((sint32)rtb_DataTypeConversion_oa) != 0));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/NOT/Functionality'/NOT'
         */
    rtb_Switch_ji = (uint8)(!(((sint32)rtb_DataTypeConversion_m) != 0));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Constant1'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/GT/Functionality'/GT'
         */
    rtb_DataTypeConversion_h = (uint8)(((((sint32)rtb_DataTypeConversion_or) != 0) && (((sint32)rtb_Switch_ji) != 0)) && (rtb_Switch_dh > GET_P_ODPFOH_SignLimMinObjPosY_met()));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Constant1'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Neg3/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_bc = (uint8)(((((sint32)rtb_Switch_ji) != 0) && (((sint32)rtb_DataTypeConversion_or) != 0)) && (rtb_Switch_dh < (-GET_P_ODPFOH_SignLimMinObjPosY_met())));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate[2] = (uint8)((((sint32)rtb_DataTypeConversion_h) != 0) || (((sint32)rtb_DataTypeConversion_bc) != 0));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate[6] = (uint8)(!(((sint32) rtb_sfun_polyfitTgtObjectClothoid.bTrajUpdate_bool) != 0));
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate[8] = (uint8)(!(((sint32)rtb_Switch_ez) != 0));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Freeze_IV/Switch1/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Freeze_IV/Switch6/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Freeze_IV/NOT/Functionality'/NOT'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0'/Unit_Delay1'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Freeze_IV'/Unit_Delay2'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o1) != 0)) {
            rtb_Switch_dh = DW_odpfoh_Unit_Delay2_DSTATE_bl;
        } else {
            rtb_Switch_dh = DW_odpfoh_Unit_Delay1_DSTATE_e;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Freeze_IV/Switch6/Functionality'/Switch' */
    } else {
        rtb_Switch_dh = DW_odpfoh_Unit_Delay1_DSTATE_e;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Freeze_IV/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Constant6'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3'
         */
    if (((sint32)rtb_DataTypeConversion_o1) != 0) {
        rtb_Max_jt = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/STOPWATCH_RE/Functionality/Sum1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA'/Unit_Delay1'
                 */
        rtb_Max_jt = DW_odpfoh_Unit_Delay1_DSTATE_l + rtb_Max;
    } else {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA'/Unit_Delay1'
                 */
        rtb_Max_jt = DW_odpfoh_Unit_Delay1_DSTATE_l;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch2' */
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Application Parameter2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Application Parameter3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Constant3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Constant4'/Constant'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Div/Functionality/Div'/Div'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Mul/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Sum/Functionality'/Sum'
         *  Trigonometry: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA/Trigonom/Functionality'/Trigonometric Function'
         */
    rtb_Sum_o5 = (f32_cos_f32((rtb_Max_jt / f32_max_f32_f32 (GET_P_LCF_AlmostZero_nu(), GET_P_ODPFOH_AccObjChngDuration_sec())) * 3.14159274F) + 1.0F) / 2.0F;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Switch3/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Constant7'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_UseSignLimPosY0_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Switch1/Functionality'/Switch' incorporates:
                 *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Constant1'/Constant'
                 *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Max/Functionality'/Max'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Switch2/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_h) != 0) {
            rtb_Sum_bv5 = f32_max_f32_f32(0.0F, rtb_sfun_objTraceKalmanFilter.fPosY0_met);
        } else if (((sint32)rtb_DataTypeConversion_bc) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Switch2/Functionality'/Switch' incorporates:
                         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Constant1'/Constant'
                         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Min/Functionality'/Min'
                         */
            rtb_Sum_bv5 = f32_min_f32_f32(0.0F, rtb_sfun_objTraceKalmanFilter.fPosY0_met);
        } else {
            rtb_Sum_bv5 = rtb_sfun_objTraceKalmanFilter.fPosY0_met;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Switch1/Functionality'/Switch' */
    } else {
        rtb_Sum_bv5 = rtb_sfun_objTraceKalmanFilter.fPosY0_met;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitPosY0/Switch3/Functionality'/Switch' */
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Constant2'/Constant'
         */
    rtb_Mul_b = rtb_Sum_bv5 * GET_P_ODPFOH_ScalingFactorPosY0_nu();
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/Constant8'/Constant'
         */
    rtb_Div_er = rtb_Switch_os / 100.0F;
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_StraightEstim_perc */
        FDPS_PTR_F32(GETA_X_ODPFOH_StraightEstim_perc(), rtb_Div_er, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D(GETA_Y_ODPFOH_PT1StrEstPosY0_sec(), &dps_result_ln);
    }
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_Mul_ix = GET_S_LCFRCV_VehVelX_mps() * 3.6F;
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/Y_ODPFOH_PT1TimeConstPosY_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelXPT1_kph */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelXPT1_kph(), rtb_Mul_ix, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e1 = F32_PTR_IP1D (GETA_Y_ODPFOH_PT1TimeConstPosY0_sec(), &dps_result_ln);
    }
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/Y_ODPFOH_PT1TimeConstPosY_sec/Functionality/odtc'/Product'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/ip_lookup/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/Y_ODPFOH_PT1TimeConstPosY_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div_i = rtb_Max / f32_max_f32_f32(f32_max_f32_f32 (rtb_ip_lookup_fxpt_sfun_7_p, rtb_ip_lookup_fxpt_sfun_7_e1), rtb_Max);
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality'/Comparison'
         */
    /* Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality'/Logical Operator1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter'/Unit_Delay'
         */
    BI_odpfoh_LogicalOperator_k = (uint8)((((sint32)DW_odpfoh_Unit_Delay_DSTATE_i) != 0) && (!(((sint32)rtb_DataTypeConversion_m) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING'/fcg' */
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY'/Unit_Delay1' */
    rtb_Unit_Delay1_cv = DW_odpfoh_Unit_Delay1_DSTATE_jc;
    /* S-Function (sfun_mmv): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_odpfoh_LogicalOperator_k != 0U) {
        rtb_SFunction_ku = rtb_Mul_b;
    } else {
        if (GET_P_ODPFOH_PT1PosY0Enable_bool() != 0U) {
            rtb_SFunction_ku = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_cv, rtb_Mul_b, rtb_Div_i);
        } else {
            rtb_SFunction_ku = rtb_Unit_Delay1_cv;
        }
    }
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Freeze_IV/Switch1/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY'/Unit_Delay1'
         */
    if (((sint32)rtb_LogicalOperator_i) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Freeze_IV/Switch2/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Freeze_IV/NOT/Functionality'/NOT'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY'/Unit_Delay1'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Freeze_IV'/Unit_Delay2'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o) != 0)) {
            rtb_Sum_atk = DW_odpfoh_Unit_Delay2_DSTATE_h;
        } else {
            rtb_Sum_atk = DW_odpfoh_Unit_Delay1_DSTATE_o;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Freeze_IV/Switch2/Functionality'/Switch' */
    } else {
        rtb_Sum_atk = DW_odpfoh_Unit_Delay1_DSTATE_o;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Freeze_IV/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Constant6'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3'
         */
    if (((sint32)rtb_DataTypeConversion_o) != 0) {
        rtb_Mul_dg = 0.0F;
    } else if (((sint32)rtb_LogicalOperator_i) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality/Sum1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA'/Unit_Delay1'
                 */
        rtb_Mul_dg = DW_odpfoh_Unit_Delay1_DSTATE_ek + rtb_Max;
    } else {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA'/Unit_Delay1'
                 */
        rtb_Mul_dg = DW_odpfoh_Unit_Delay1_DSTATE_ek;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch2' */
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Application Parameter2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Application Parameter3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Constant3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Constant4'/Constant'
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Div/Functionality/Div'/Div'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Mul/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Sum/Functionality'/Sum'
         *  Trigonometry: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA/Trigonom/Functionality'/Trigonometric Function'
         */
    rtb_Switch_bx = (f32_cos_f32((rtb_Mul_dg / f32_max_f32_f32 (GET_P_LCF_AlmostZero_nu(), GET_P_ODPFOH_AccObjChngDuration_sec())) * 3.14159274F) + 1.0F) / 2.0F;
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Y_ODPFOH_PT1TimeConstPosY_sec1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelXPT1_kph */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelXPT1_kph(), rtb_Mul_c, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D(GETA_Y_ODPFOH_LSMPT1TimePosY_sec(), &dps_result_ln);
    }
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Max1/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Y_ODPFOH_PT1TimeConstPosY_sec1/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Y_ODPFOH_PT1TimeConstPosY_sec1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div_eb = rtb_Max / f32_max_f32_f32(rtb_ip_lookup_fxpt_sfun_7_g, rtb_Max);
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter'/Unit_Delay' */
    rtb_Unit_Delay_f = DW_odpfoh_Unit_Delay_DSTATE_n;
    /* S-Function (sfun_mmv): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_o != 0U) {
        rtb_SFunction_j = rtb_Switch_iy;
    } else {
        rtb_SFunction_j = f32_mmv_f32_f32_f32( rtb_Unit_Delay_f, rtb_Switch_iy, rtb_Div_eb);
    }
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Constant1'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_PT1PosYEnable_bool()) != 0) {
        rtb_Switch_id = rtb_SFunction_j;
    } else {
        rtb_Switch_id = rtb_Switch_iy;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/A_Filter/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/A_Filter/Constant'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         */
    rtb_Sum_dn = ((1.0F - rtb_Switch_bx) * rtb_Switch_id) + (rtb_Sum_atk * rtb_Switch_bx);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Switch/Functionality'/Switch' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/NOT/Functionality'/NOT'
         */
    if (!(((sint32)rtb_LogicalOperator_i) != 0)) {
        rtb_Switch_a3 = rtb_Switch_id;
    } else {
        rtb_Switch_a3 = rtb_Sum_dn;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Sum/Functionality'/Sum' */
    rtb_Sum_nd = rtb_Switch_id - rtb_Switch_a3;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Constant2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Constant3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Constant4'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/LT1/Functionality'/LT'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions'/Unit_Delay2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay2'
         */
    if ((((rtb_Sum_nd > 0.001F) && (DW_odpfoh_Unit_Delay2_DSTATE_ho < -0.001F)) || ((DW_odpfoh_Unit_Delay2_DSTATE_ho > 0.001F) && (rtb_Sum_nd < -0.001F))) && (((sint32)DW_odpfoh_Unit_Delay1_DSTATE_ci) != 0)) {
        rtb_Switch_ji = 0U;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_ji = 1U;
    } else {
        rtb_Switch_ji = DW_odpfoh_Unit_Delay2_DSTATE_a;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch4/Functionality'/Switch' incorporates:
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch2/Functionality'/Switch'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch7/Functionality'/Switch'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch8/Functionality'/Switch'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier'/Unit_Delay3'
         */
    if ((((sint32)rtb_LogicalOperator_i) != 0) && (((sint32) rtb_DataTypeConversion_ds) != 0)) {
        rtb_DataTypeConversion_l0 = DW_odpfoh_Unit_Delay1_DSTATE_k;
        rtb_DataTypeConversion_jd = DW_odpfoh_Unit_Delay3_DSTATE_es;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_fs = (uint8)((((((sint32)rtb_DataTypeConversion) != 0) || (((sint32)rtb_DataTypeConversion_d4) != 0)) || (((sint32) rtb_DataTypeConversion_l0) != 0)) || (((sint32)rtb_DataTypeConversion_jd) != 0));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_fs) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Switch1/Functionality'/Switch' */
        if (((sint32)rtb_Switch_ji) != 0) {
            rtb_Switch_fd = rtb_Sum_dn;
        } else {
            rtb_Switch_fd = rtb_Switch_id;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Switch1/Functionality'/Switch' */
    } else {
        rtb_Switch_fd = rtb_Switch_id;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/PosY0/Application Parameter2'/Constant'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/PosY0/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_ez) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/Constant2'/Constant'
                 */
        if (((sint32)GET_P_ODPFOH_PT1PosY0Enable_bool()) != 0) {
            rtb_Sum_dn = rtb_SFunction_ku;
        } else {
            rtb_Sum_dn = rtb_Mul_b;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY/Switch/Functionality'/Switch' */
    } else if (((sint32)GET_P_ODPFOH_UseCrvOnlyLSM_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/PosY0/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/PosY0/Constant1'/Constant'
                 */
        rtb_Sum_dn = 0.0F;
    } else {
        rtb_Sum_dn = rtb_Switch_fd;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/A_Filtering/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/A_Filtering/A_Filter/Constant'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        rtb_Switch_a3 = ((1.0F - rtb_Sum_o5) * rtb_Sum_dn) + (rtb_Switch_dh * rtb_Sum_o5);
    } else {
        rtb_Switch_a3 = rtb_Sum_dn;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/A_Filtering/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/Switch/Functionality'/Switch' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/NOT/Functionality'/NOT'
         */
    if (!(((sint32)rtb_DataTypeConversion_ld) != 0)) {
        rtb_Sum_hd = rtb_Sum_dn;
    } else {
        rtb_Sum_hd = rtb_Switch_a3;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/Sum/Functionality'/Sum' */
    rtb_Sum_li = rtb_Sum_dn - rtb_Sum_hd;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/Constant2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/Constant3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/Constant4'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset/LT1/Functionality'/LT'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions'/Unit_Delay2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset'/Unit_Delay2'
         */
    if ((((rtb_Sum_li > 0.001F) && (DW_odpfoh_Unit_Delay2_DSTATE_o < -0.001F)) || ((DW_odpfoh_Unit_Delay2_DSTATE_o > 0.001F) && (rtb_Sum_li < -0.001F))) && (((sint32)DW_odpfoh_Unit_Delay1_DSTATE_p) != 0)) {
        rtb_DataTypeConversion_ds = 0U;
    } else if (((sint32)rtb_DataTypeConversion_o1) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_ds = 1U;
    } else {
        rtb_DataTypeConversion_ds = DW_odpfoh_Unit_Delay2_DSTATE_jl;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_ds) != 0) {
        rtb_Switch_e = rtb_Switch_a3;
    } else {
        rtb_Switch_e = rtb_Sum_dn;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/Relational Operator' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant6'/Constant'
         */
    rtb_RelationalOperator_hc = (uint8)(GET_P_ODPFOH_MaxRangePosY0_met() >= rtb_Switch_e);
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant6'/Constant'
         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg3/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1_m = (uint8)((-GET_P_ODPFOH_MaxRangePosY0_met()) <= rtb_Switch_e);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Freeze_IV/Switch1/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Freeze_IV/Switch6/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Freeze_IV/NOT/Functionality'/NOT'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead'/Unit_Delay1'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Freeze_IV'/Unit_Delay2'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o1) != 0)) {
            rtb_Switch_pv = DW_odpfoh_Unit_Delay2_DSTATE_k;
        } else {
            rtb_Switch_pv = DW_odpfoh_Unit_Delay1_DSTATE_n;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Freeze_IV/Switch6/Functionality'/Switch' */
    } else {
        rtb_Switch_pv = DW_odpfoh_Unit_Delay1_DSTATE_n;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Freeze_IV/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Switch3/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Constant2'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_UseSignLimHead_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Switch1/Functionality'/Switch' incorporates:
                 *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Constant1'/Constant'
                 *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Max/Functionality'/Max'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Switch2/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_h) != 0) {
            rtb_Sum_bv5 = f32_max_f32_f32(0.0F, rtb_sfun_objTraceKalmanFilter.fHeadingAngle_rad);
        } else if (((sint32)rtb_DataTypeConversion_bc) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Switch2/Functionality'/Switch' incorporates:
                         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Constant1'/Constant'
                         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Min/Functionality'/Min'
                         */
            rtb_Sum_bv5 = f32_min_f32_f32(0.0F, rtb_sfun_objTraceKalmanFilter.fHeadingAngle_rad);
        } else {
            rtb_Sum_bv5 = rtb_sfun_objTraceKalmanFilter.fHeadingAngle_rad;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Switch1/Functionality'/Switch' */
    } else {
        rtb_Sum_bv5 = rtb_sfun_objTraceKalmanFilter.fHeadingAngle_rad;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitHead/Switch3/Functionality'/Switch' */
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Constant3'/Constant'
         */
    rtb_Mul_m2 = rtb_Sum_bv5 * GET_P_ODPFOH_ScalingFactorHead_nu();
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_StraightEstim_perc */
        FDPS_PTR_F32(GETA_X_ODPFOH_StraightEstim_perc(), rtb_Div_er, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D(GETA_Y_ODPFOH_PT1StrEstHead_sec(), &dps_result_ln);
    }
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/Y_ODPFOH_PT1TimeConstHead_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelXPT1_kph */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelXPT1_kph(), rtb_Mul_ix, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_gc = F32_PTR_IP1D (GETA_Y_ODPFOH_PT1TimeConstHead_sec(), &dps_result_ln);
    }
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/Y_ODPFOH_PT1TimeConstHead_sec/Functionality/odtc'/Sum' incorporates:
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/Y_ODPFOH_PT1TimeConstHead_sec/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/Y_ODPFOH_PT1TimeConstHead_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_hd = rtb_ip_lookup_fxpt_sfun_7_gc;
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/ip_lookup/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div_f = rtb_Max / f32_max_f32_f32(f32_max_f32_f32 (rtb_ip_lookup_fxpt_sfun_7_h, rtb_Sum_hd), rtb_Max);
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head'/Unit_Delay1' */
    rtb_Unit_Delay1_f = DW_odpfoh_Unit_Delay1_DSTATE_i;
    /* S-Function (sfun_mmv): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_odpfoh_LogicalOperator_k != 0U) {
        rtb_SFunction_a = rtb_Mul_m2;
    } else {
        if (GET_P_ODPFOH_PT1HeadEnable_bool() != 0U) {
            rtb_SFunction_a = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_f, rtb_Mul_m2, rtb_Div_f);
        } else {
            rtb_SFunction_a = rtb_Unit_Delay1_f;
        }
    }
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Freeze_IV/Switch1/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw'/Unit_Delay1'
         */
    if (((sint32)rtb_LogicalOperator_i) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Freeze_IV/Switch2/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Freeze_IV/NOT/Functionality'/NOT'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw'/Unit_Delay1'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Freeze_IV'/Unit_Delay2'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o) != 0)) {
            rtb_Sum_hd = DW_odpfoh_Unit_Delay2_DSTATE_jh;
        } else {
            rtb_Sum_hd = DW_odpfoh_Unit_Delay1_DSTATE_cm;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Freeze_IV/Switch2/Functionality'/Switch' */
    } else {
        rtb_Sum_hd = DW_odpfoh_Unit_Delay1_DSTATE_cm;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Freeze_IV/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/A_Filter/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/A_Filter/Constant'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjRelYawAng_rad'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         */
    rtb_Sum_nk = ((1.0F - rtb_Switch_bx) * GET_S_ODPFOP_AccObjRelYawAng_rad()) + (rtb_Sum_hd * rtb_Switch_bx);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjRelYawAng_rad'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/NOT/Functionality'/NOT'
         */
    if (!(((sint32)rtb_LogicalOperator_i) != 0)) {
        rtb_Switch_a3 = GET_S_ODPFOP_AccObjRelYawAng_rad();
    } else {
        rtb_Switch_a3 = rtb_Sum_nk;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjRelYawAng_rad'
         */
    rtb_Switch_a3 = GET_S_ODPFOP_AccObjRelYawAng_rad() - rtb_Switch_a3;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/Constant2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/Constant3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/Constant4'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset/LT1/Functionality'/LT'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions'/Unit_Delay2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay2'
         */
    if ((((rtb_Switch_a3 > 1.0E-5F) && (DW_odpfoh_Unit_Delay2_DSTATE_ko < -1.0E-5F)) || ((DW_odpfoh_Unit_Delay2_DSTATE_ko > 1.0E-5F) && (rtb_Switch_a3 < -1.0E-5F))) && (((sint32)DW_odpfoh_Unit_Delay1_DSTATE_d5) != 0)) {
        rtb_DataTypeConversion_or = 0U;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_or = 1U;
    } else {
        rtb_DataTypeConversion_or = DW_odpfoh_Unit_Delay2_DSTATE_ay;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/Heading/Application Parameter2'/Constant'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/Switch2/Functionality'/Switch'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/Heading/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_ez) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/Application Parameter2'/Constant'
                 */
        if (((sint32)GET_P_ODPFOH_PT1HeadEnable_bool()) != 0) {
            rtb_Sum_nk = rtb_SFunction_a;
        } else {
            rtb_Sum_nk = rtb_Mul_m2;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head/Switch/Functionality'/Switch' */
    } else if (((sint32)GET_P_ODPFOH_UseCrvOnlyLSM_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/Heading/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/Heading/Constant1'/Constant'
                 */
        rtb_Sum_nk = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_fs) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjRelYawAng_rad'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/Heading/Switch1/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_or) == 0) {
            rtb_Sum_nk = GET_S_ODPFOP_AccObjRelYawAng_rad();
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Switch1/Functionality'/Switch' */
    } else {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/Switch2/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjRelYawAng_rad'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/Heading/Switch1/Functionality'/Switch'
                 */
        rtb_Sum_nk = GET_S_ODPFOP_AccObjRelYawAng_rad();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/A_Filtering/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/A_Filtering/A_Filter/Constant'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        rtb_Switch_bx = ((1.0F - rtb_Sum_o5) * rtb_Sum_nk) + (rtb_Switch_pv * rtb_Sum_o5);
    } else {
        rtb_Switch_bx = rtb_Sum_nk;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/A_Filtering/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/Switch/Functionality'/Switch' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/NOT/Functionality'/NOT'
         */
    if (!(((sint32)rtb_DataTypeConversion_ld) != 0)) {
        rtb_Mul_kl = rtb_Sum_nk;
    } else {
        rtb_Mul_kl = rtb_Switch_bx;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/Sum/Functionality'/Sum' */
    rtb_Sum_o4 = rtb_Sum_nk - rtb_Mul_kl;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/Constant2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/Constant3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/Constant4'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset/LT1/Functionality'/LT'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions'/Unit_Delay2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset'/Unit_Delay2'
         */
    if ((((rtb_Sum_o4 > 1.0E-6F) && (DW_odpfoh_Unit_Delay2_DSTATE_i < -1.0E-6F)) || ((DW_odpfoh_Unit_Delay2_DSTATE_i > 1.0E-6F) && (rtb_Sum_o4 < -1.0E-6F))) && (((sint32)DW_odpfoh_Unit_Delay1_DSTATE_if) != 0)) {
        rtb_DataTypeConversion_fs = 0U;
    } else if (((sint32)rtb_DataTypeConversion_o1) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_fs = 1U;
    } else {
        rtb_DataTypeConversion_fs = DW_odpfoh_Unit_Delay2_DSTATE_ob;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_fs) != 0) {
        rtb_Switch_dy = rtb_Switch_bx;
    } else {
        rtb_Switch_dy = rtb_Sum_nk;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/Relational Operator' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant8'/Constant'
         */
    rtb_RelationalOperator_ce = (uint8)(GET_P_ODPFOH_MaxRangeHead_rad() >= rtb_Switch_dy);
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant8'/Constant'
         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg4/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1_b = (uint8)((-GET_P_ODPFOH_MaxRangeHead_rad()) <= rtb_Switch_dy);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Freeze_IV/Switch1/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Freeze_IV/Switch6/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Freeze_IV/NOT/Functionality'/NOT'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv'/Unit_Delay1'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Freeze_IV'/Unit_Delay2'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o1) != 0)) {
            rtb_Switch_nr = DW_odpfoh_Unit_Delay2_DSTATE_ki;
        } else {
            rtb_Switch_nr = DW_odpfoh_Unit_Delay1_DSTATE_h;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Freeze_IV/Switch6/Functionality'/Switch' */
    } else {
        rtb_Switch_nr = DW_odpfoh_Unit_Delay1_DSTATE_h;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Freeze_IV/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Switch3/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Constant3'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_UseSignLimCrv_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Switch1/Functionality'/Switch' incorporates:
                 *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Constant1'/Constant'
                 *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Max/Functionality'/Max'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Switch2/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_h) != 0) {
            rtb_Sum_bv5 = f32_max_f32_f32(0.0F, rtb_sfun_objTraceKalmanFilter.fCrv_1pm);
        } else if (((sint32)rtb_DataTypeConversion_bc) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Switch2/Functionality'/Switch' incorporates:
                         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter'/ODPFOH_PF_KF_StructOut'
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Constant1'/Constant'
                         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Min/Functionality'/Min'
                         */
            rtb_Sum_bv5 = f32_min_f32_f32(0.0F, rtb_sfun_objTraceKalmanFilter.fCrv_1pm);
        } else {
            rtb_Sum_bv5 = rtb_sfun_objTraceKalmanFilter.fCrv_1pm;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Switch1/Functionality'/Switch' */
    } else {
        rtb_Sum_bv5 = rtb_sfun_objTraceKalmanFilter.fCrv_1pm;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/LimitCrv/Switch3/Functionality'/Switch' */
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Mul2/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling/Constant6'/Constant'
         */
    rtb_Mul_jo = rtb_Sum_bv5 * GET_P_ODPFOH_ScalingFactorCrv_nu();
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_StraightEstim_perc */
        FDPS_PTR_F32(GETA_X_ODPFOH_StraightEstim_perc(), rtb_Div_er, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_dx = F32_PTR_IP1D(GETA_Y_ODPFOH_PT1StrEstCrv_sec(), &dps_result_ln);
    }
    /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/Y_ODPFOH_PT1TimeConstCrv_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOH_VehVelXPT1_kph */
        FDPS_PTR_F32(GETA_X_ODPFOH_VehVelXPT1_kph(), rtb_Mul_ix, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D(GETA_Y_ODPFOH_PT1TimeConstCrv_sec (), &dps_result_ln);
    }
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/Max/Functionality'/Max'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/Y_ODPFOH_PT1TimeConstCrv_sec/Functionality/odtc'/Product'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/ip_lookup/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/Y_ODPFOH_PT1TimeConstCrv_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/ip_lookup/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div_fh = rtb_Max / f32_max_f32_f32(f32_max_f32_f32 (rtb_ip_lookup_fxpt_sfun_7_dx, rtb_ip_lookup_fxpt_sfun_7_c), rtb_Max);
    /* UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv'/Unit_Delay1' */
    rtb_Unit_Delay1_e = DW_odpfoh_Unit_Delay1_DSTATE_g;
    /* S-Function (sfun_mmv): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_odpfoh_LogicalOperator_k != 0U) {
        rtb_SFunction_e = rtb_Mul_jo;
    } else {
        if (GET_P_ODPFOH_PT1CrvEnable_bool() != 0U) {
            rtb_SFunction_e = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_e, rtb_Mul_jo, rtb_Div_fh);
        } else {
            rtb_SFunction_e = rtb_Unit_Delay1_e;
        }
    }
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Application Parameter2'/Constant'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_ez) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/Application Parameter1'/Constant'
                 */
        if (((sint32)GET_P_ODPFOH_PT1CrvEnable_bool()) != 0) {
            rtb_Switch_fd = rtb_SFunction_e;
        } else {
            rtb_Switch_fd = rtb_Mul_jo;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv/Switch/Functionality'/Switch' */
    } else if (((sint32)GET_P_ODPFOH_UseCrvOnlyLSM_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Application Parameter1'/Constant'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Application Parameter3'/Constant'
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Constant2'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                 *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Max/Functionality'/Max'
                 *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Max2/Functionality'/Max'
                 *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Min2/Functionality'/Min'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Div/Functionality/Div'/Div'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Mul/Functionality'/Mul'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Sum2/Functionality'/Sum'
                 */
        rtb_Switch_fd = f32_min_f32_f32(f32_max_f32_f32((rtb_Switch_fd * 2.0F) / f32_max_f32_f32(GET_P_LCF_AlmostZero_nu(), GET_S_ODPFOP_AccObjPosX_met() * GET_S_ODPFOP_AccObjPosX_met()), GET_S_LCFRCV_VehCrv_1pm() - GET_P_ODPFOH_MaxDeltaEgoCrvLSM_1pm()), GET_S_LCFRCV_VehCrv_1pm() + GET_P_ODPFOH_MaxDeltaEgoCrvLSM_1pm());
    } else {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LSM_TgtTraj_Processing/CalculateDirectCrv/Constant1'/Constant'
                 */
        rtb_Switch_fd = 0.0F;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/A_Filtering/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/A_Filtering/A_Filter/Constant'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        rtb_Switch_bx = ((1.0F - rtb_Sum_o5) * rtb_Switch_fd) + (rtb_Switch_nr * rtb_Sum_o5);
    } else {
        rtb_Switch_bx = rtb_Switch_fd;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/A_Filtering/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/Switch/Functionality'/Switch' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/NOT/Functionality'/NOT'
         */
    if (!(((sint32)rtb_DataTypeConversion_ld) != 0)) {
        rtb_Mul_kl = rtb_Switch_fd;
    } else {
        rtb_Mul_kl = rtb_Switch_bx;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/Sum/Functionality'/Sum' */
    rtb_Sum_bv5 = rtb_Switch_fd - rtb_Mul_kl;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/Constant2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/Constant3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/Constant4'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset/LT1/Functionality'/LT'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions'/Unit_Delay2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset'/Unit_Delay2'
         */
    if ((((rtb_Sum_bv5 > 1.0E-7F) && (DW_odpfoh_Unit_Delay2_DSTATE_kk < -1.0E-7F)) || ((DW_odpfoh_Unit_Delay2_DSTATE_kk > 1.0E-7F) && (rtb_Sum_bv5 < -1.0E-7F))) && (((sint32)DW_odpfoh_Unit_Delay1_DSTATE_kx) != 0)) {
        rtb_DataTypeConversion_h = 0U;
    } else if (((sint32)rtb_DataTypeConversion_o1) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_h = 1U;
    } else {
        rtb_DataTypeConversion_h = DW_odpfoh_Unit_Delay2_DSTATE_ap;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch_kpw = rtb_Switch_bx;
    } else {
        rtb_Switch_kpw = rtb_Switch_fd;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/Relational Operator' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant11'/Constant'
         */
    rtb_DataTypeConversion_bc = (uint8)(GET_P_ODPFOH_MaxRangeCrv_1pm() >= rtb_Switch_kpw);
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant11'/Constant'
         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg5/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1_n = (uint8)((-GET_P_ODPFOH_MaxRangeCrv_1pm()) <= rtb_Switch_kpw);
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/OR2/Functionality'/OR'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/And'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/Not1'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/Not2'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/And'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/Not1'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/Not2'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/And'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/Not1'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/Not2'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/OR3/Functionality'/OR'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/OR4/Functionality'/OR'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/OR5/Functionality'/OR'
         */
    rtb_VectorConcatenate[12] = (uint8)(((((((sint32)rtb_RelationalOperator_hc) != 0) && (!(((sint32)rtb_RelationalOperator1_m) != 0))) || (!(((sint32) rtb_RelationalOperator_hc) != 0))) || (((((sint32)rtb_RelationalOperator_ce) != 0) && (!(((sint32)rtb_RelationalOperator1_b) != 0))) || (!(((sint32) rtb_RelationalOperator_ce) != 0)))) || (((((sint32)rtb_DataTypeConversion_bc) != 0) && (!(((sint32)rtb_RelationalOperator1_n) != 0))) || (!(((sint32) rtb_DataTypeConversion_bc) != 0))));
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant7'/Constant'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch4/Functionality'/Switch'
         */
    if (((sint32)GET_P_ODPFOH_UseOutputRangeLim_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant6'/Constant'
                 */
        if (((sint32)rtb_RelationalOperator_hc) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant6'/Constant'
                         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg3/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1_m) == 0) {
                rtb_Switch_e = -GET_P_ODPFOH_MaxRangePosY0_met();
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/Switch1' */
        } else {
            rtb_Switch_e = GET_P_ODPFOH_MaxRangePosY0_met();
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit/Functionality'/Switch' */
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant8'/Constant'
                 */
        if (((sint32)rtb_RelationalOperator_ce) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant8'/Constant'
                         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg4/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1_b) == 0) {
                rtb_Switch_dy = -GET_P_ODPFOH_MaxRangeHead_rad();
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/Switch1' */
        } else {
            rtb_Switch_dy = GET_P_ODPFOH_MaxRangeHead_rad();
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit1/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay2'
         */
    rtb_Switch_bx = rtb_Switch_e - DW_odpfoh_Unit_Delay2_DSTATE_k3;
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant1'/Constant'
         */
    rtb_Mul_pc = GET_P_ODPFOH_MaxGradPosY0_mps() * rtb_Max;
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_hc = (uint8)(rtb_Switch_bx > rtb_Mul_pc);
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant1'/Constant'
         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg/Functionality'/Unary Minus'
         */
    rtb_Mul_kl = (-GET_P_ODPFOH_MaxGradPosY0_mps()) * rtb_Max;
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_m = (uint8)(rtb_Switch_bx < rtb_Mul_kl);
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay1'
         */
    rtb_Switch_bx = rtb_Switch_dy - DW_odpfoh_Unit_Delay1_DSTATE_g3;
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant2'/Constant'
         */
    rtb_Mul_ei = GET_P_ODPFOH_MaxGradHeadAng_rps() * rtb_Max;
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_ce = (uint8)(rtb_Switch_bx > rtb_Mul_ei);
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant2'/Constant'
         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg1/Functionality'/Unary Minus'
         */
    rtb_Mul_mh = (-GET_P_ODPFOH_MaxGradHeadAng_rps()) * rtb_Max;
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_b = (uint8)(rtb_Switch_bx < rtb_Mul_mh);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant12'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_UseOutputRangeLim_bool()) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant11'/Constant'
                 */
        if (((sint32)rtb_DataTypeConversion_bc) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant11'/Constant'
                         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg5/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1_n) == 0) {
                rtb_Switch_kpw = -GET_P_ODPFOH_MaxRangeCrv_1pm();
            }
            /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/Switch1' */
        } else {
            rtb_Switch_kpw = GET_P_ODPFOH_MaxRangeCrv_1pm();
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Limit2/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay3'
         */
    rtb_Switch_bx = rtb_Switch_kpw - DW_odpfoh_Unit_Delay3_DSTATE_e;
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant4'/Constant'
         */
    rtb_Mul_jst = GET_P_ODPFOH_MaxGradCrv_1pms() * rtb_Max;
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Relational Operator' */
    rtb_DataTypeConversion_bc = (uint8)(rtb_Switch_bx > rtb_Mul_jst);
    /* Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant4'/Constant'
         *  UnaryMinus: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Neg2/Functionality'/Unary Minus'
         */
    rtb_Mul_j2 = (-GET_P_ODPFOH_MaxGradCrv_1pms()) * rtb_Max;
    /* RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_n = (uint8)(rtb_Switch_bx < rtb_Mul_j2);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator_hc) != 0) {
        rtb_RelationalOperator_h = 0U;
    } else {
        rtb_RelationalOperator_h = rtb_RelationalOperator1_m;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch7' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator_ce) != 0) {
        rtb_RelationalOperator_e = 0U;
    } else {
        rtb_RelationalOperator_e = rtb_RelationalOperator1_b;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch7' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_DataTypeConversion_bc) != 0) {
        rtb_DataTypeConversion_ly = 0U;
    } else {
        rtb_DataTypeConversion_ly = rtb_RelationalOperator1_n;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/OR1/Functionality'/OR'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/OR/Functionality'/OR'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/OR1/Functionality'/OR'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/OR2/Functionality'/OR'
         */
    rtb_VectorConcatenate[15] = (uint8)((((((sint32)rtb_RelationalOperator_h) != 0) || (((sint32)rtb_RelationalOperator_hc) != 0)) || ((((sint32) rtb_RelationalOperator_e) != 0) || (((sint32)rtb_RelationalOperator_ce) != 0))) || ((((sint32)rtb_DataTypeConversion_ly) != 0) || (((sint32) rtb_DataTypeConversion_bc) != 0)));
    /* S-Function (sfun_setbit): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/InvalidBitfield/Mapping_uint16/set_bit1/Functionality'/sfun_setbit' */
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
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch2'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay'
         */
    if ((((sint32)DW_odpfoh_Unit_Delay_DSTATE_gw) != 0) && (!(((sint32) rtb_DataTypeConversion_gg) != 0))) {
        rtb_Switch_bx = rtb_Switch_dy;
        rtb_Mul_pc = rtb_Switch_e;
        rtb_Mul_jst = rtb_Switch_kpw;
    } else {
        if (((sint32)rtb_RelationalOperator_ce) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay1'
                         */
            rtb_Switch_bx = rtb_Mul_ei + DW_odpfoh_Unit_Delay1_DSTATE_g3;
        } else if (((sint32)rtb_RelationalOperator1_b) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay1'
                         */
            rtb_Switch_bx = rtb_Mul_mh + DW_odpfoh_Unit_Delay1_DSTATE_g3;
        } else {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
                         */
            rtb_Switch_bx = rtb_Switch_dy;
        }
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay2'
                 */
        if (((sint32)rtb_RelationalOperator_hc) != 0) {
            rtb_Mul_pc += DW_odpfoh_Unit_Delay2_DSTATE_k3;
        } else if (((sint32)rtb_RelationalOperator1_m) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay2'
                         */
            rtb_Mul_pc = rtb_Mul_kl + DW_odpfoh_Unit_Delay2_DSTATE_k3;
        } else {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch6' */
            rtb_Mul_pc = rtb_Switch_e;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER2/Functionality/Subfunctionality'/Switch5' */
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay3'
                 */
        if (((sint32)rtb_DataTypeConversion_bc) != 0) {
            rtb_Mul_jst += DW_odpfoh_Unit_Delay3_DSTATE_e;
        } else if (((sint32)rtb_RelationalOperator1_n) != 0) {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay3'
                         */
            rtb_Mul_jst = rtb_Mul_j2 + DW_odpfoh_Unit_Delay3_DSTATE_e;
        } else {
            /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch6' */
            rtb_Mul_jst = rtb_Switch_kpw;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER3/Functionality/Subfunctionality'/Switch5' */
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING'/fcg' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant5'/Constant'
         */
    if (((sint32)GET_P_ODPFOH_UseOutputGradLim_bool()) != 0) {
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch10'/copy1' */
        SET_S_ODPFOH_TgtObjCrv_1pm(rtb_Mul_jst);
    } else {
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch10'/copy1' */
        SET_S_ODPFOH_TgtObjCrv_1pm(rtb_Switch_kpw);
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Switch4/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         */
    if (((sint32)rtb_Switch_ez) != 0) {
        rtb_Mul_j2 = rtb_sfun_polyfitTgtObjectClothoid.fTrajLength_met;
    } else {
        rtb_Mul_j2 = GET_S_ODPFOP_AccObjPosX_met();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Freeze_IV/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/A_Filtering/A_Filter/Constant'/Constant'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/A_Filtering/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_ld) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Freeze_IV/Switch6/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Freeze_IV/NOT/Functionality'/NOT'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength'/Unit_Delay1'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Freeze_IV'/Unit_Delay2'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o1) != 0)) {
            rtb_Switch_kpw = DW_odpfoh_Unit_Delay2_DSTATE_kq;
        } else {
            rtb_Switch_kpw = DW_odpfoh_Unit_Delay1_DSTATE_is;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Freeze_IV/Switch6/Functionality'/Switch' */
        rtb_Sum_o5 = ((1.0F - rtb_Sum_o5) * rtb_Mul_j2) + (rtb_Switch_kpw * rtb_Sum_o5);
    } else {
        rtb_Switch_kpw = DW_odpfoh_Unit_Delay1_DSTATE_is;
        rtb_Sum_o5 = rtb_Mul_j2;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Freeze_IV/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/Switch/Functionality'/Switch' incorporates:
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/NOT/Functionality'/NOT'
         */
    if (!(((sint32)rtb_DataTypeConversion_ld) != 0)) {
        rtb_Mul_kl = rtb_Mul_j2;
    } else {
        rtb_Mul_kl = rtb_Sum_o5;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/Sum/Functionality'/Sum' */
    rtb_Mul_kl = rtb_Mul_j2 - rtb_Mul_kl;
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/Constant1'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/Constant2'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/Constant3'/Constant'
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/Constant4'/Constant'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/AND1/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset/LT1/Functionality'/LT'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions'/Unit_Delay2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset'/Unit_Delay2'
         */
    if ((((rtb_Mul_kl > 0.001F) && (DW_odpfoh_Unit_Delay2_DSTATE_c < -0.001F)) || ((DW_odpfoh_Unit_Delay2_DSTATE_c > 0.001F) && (rtb_Mul_kl < -0.001F))) && (((sint32)DW_odpfoh_Unit_Delay1_DSTATE_b3) != 0)) {
        rtb_RelationalOperator_ce = 0U;
    } else if (((sint32)rtb_DataTypeConversion_o1) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_RelationalOperator_ce = 1U;
    } else {
        rtb_RelationalOperator_ce = DW_odpfoh_Unit_Delay2_DSTATE_m;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_RelationalOperator_ce) == 0) {
        rtb_Sum_o5 = rtb_Mul_j2;
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/MinObjPosX/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/MinObjPosX/Constant6'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/MinObjPosX/Y_ODPFOH_MinTrajectoryLength_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    if (((sint32)GET_P_ODPFOH_MinPosXVelXOn_bool()) != 0) {
        /* S-Function Block sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/MinObjPosX/Y_ODPFOH_MinTrajectoryLength_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_ODPFOH_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_ODPFOH_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_et = F32_PTR_IP1D (GETA_Y_ODPFOH_MinTrajectoryLength_met(), &dps_result_ln);
        }
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch8'/copy1' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  MinMax: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/MinObjPosX/Max/Functionality'/Max'
                 *  Product: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/MinObjPosX/Y_ODPFOH_MinTrajectoryLength_met/Functionality/odtc'/Product'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/MinObjPosX/Y_ODPFOH_MinTrajectoryLength_met/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        SET_S_ODPFOH_TgtObjLength_met(f32_max_f32_f32(rtb_ip_lookup_fxpt_sfun_7_et, rtb_Sum_o5));
    } else {
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch8'/copy1' */
        SET_S_ODPFOH_TgtObjLength_met(rtb_Sum_o5);
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/MinObjPosX/Switch/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay3'
         */
    if (((sint32)rtb_Switch_jw) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay3' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/Application Parameter2'/Constant'
                 */
        DW_odpfoh_Unit_Delay3_DSTATE_p = GET_P_ODPFOH_MinTrajValidTime_sec();
    } else {
        if (DW_odpfoh_Unit_Delay3_DSTATE_p > 0.0F) {
            /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay3' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Switch2'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay3'
                         */
            DW_odpfoh_Unit_Delay3_DSTATE_p -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime'/Unit_Delay' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/Application Parameter2'/Constant'
                 */
        DW_odpfoh_Unit_Delay_DSTATE_g = GET_P_ODPFOH_AccObjChngDuration_sec();
    } else {
        if (DW_odpfoh_Unit_Delay_DSTATE_g > 0.0F) {
            /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime'/Unit_Delay' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Switch2'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime'/Unit_Delay'
                         */
            DW_odpfoh_Unit_Delay_DSTATE_g -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/SetObjTransitionTime/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ_h) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode'/Unit_Delay'
                 */
        if (DW_odpfoh_Unit_Delay_DSTATE_h > 0.0F) {
            /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode'/Unit_Delay' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_odpfoh_Unit_Delay_DSTATE_h -= rtb_Max;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode'/Unit_Delay' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/Application Parameter2'/Constant'
                 */
        DW_odpfoh_Unit_Delay_DSTATE_h = GET_P_ODPFOH_MinObjValidityTime_sec();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForLowSpeedMode/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ) != 0) {
        /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate'/Unit_Delay'
                 */
        if (DW_odpfoh_Unit_Delay_DSTATE_j > 0.0F) {
            /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate'/Unit_Delay' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_odpfoh_Unit_Delay_DSTATE_j -= rtb_Max;
        }
        /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate'/Unit_Delay' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/Application Parameter2'/Constant'
                 */
        DW_odpfoh_Unit_Delay_DSTATE_j = GET_P_ODPFOH_MinObjValidityTime_sec();
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjValidityForObjectUpdate/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_o1) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime'/Unit_Delay' incorporates:
                 *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/Application Parameter2'/Constant'
                 */
        DW_odpfoh_Unit_Delay_DSTATE_a = GET_P_ODPFOH_AccObjChngDuration_sec();
    } else {
        if (DW_odpfoh_Unit_Delay_DSTATE_a > 0.0F) {
            /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime'/Unit_Delay' incorporates:
                         *  Sum: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Switch2'
                         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime'/Unit_Delay'
                         */
            DW_odpfoh_Unit_Delay_DSTATE_a -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch1'/copy1' */
    SET_D_ODPFOH_MinHistLength_met(rtb_Max_ml);
    /* Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch1/Functionality'/Switch' incorporates:
                                                  *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Constant3'/Constant'
                                                  *  Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch/Functionality'/Switch'
                                                  */
    if (((sint32)GET_P_ODPFOH_UseOutputGradLim_bool()) != 0) {
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch11'/copy1' */
        SET_S_ODPFOH_TgtObjHeadAng_rad(rtb_Switch_bx);
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch12'/copy1' */
        SET_S_ODPFOH_TgtObjPosY0_met(rtb_Mul_pc);
    } else {
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch11'/copy1' */
        SET_S_ODPFOH_TgtObjHeadAng_rad(rtb_Switch_dy);
        /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch12'/copy1' */
        SET_S_ODPFOH_TgtObjPosY0_met(rtb_Switch_e);
    }
    /* End of Switch: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch13'/copy1' incorporates:
         *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Constant2'/Constant'
         */
    SET_S_ODPFOH_TgtObjPosX0_met(0.0F);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch14'/copy1' incorporates:
                                            *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                            */
    SET_D_ODPFOH_LastStoredPntY_met (rtb_sfun_polyfitTgtObjectClothoid.fLastStoredPntY_met);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch15'/copy1' incorporates:
                                                                 *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                                                 */
    SET_D_ODPFOH_LastStoredPntAge_sec (rtb_sfun_polyfitTgtObjectClothoid.fLastStoredAge_sec);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch16'/copy1' incorporates:
                                                                *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                                                */
    SET_D_ODPFOH_NumValidSamples_nu (rtb_sfun_polyfitTgtObjectClothoid.uNumValidSamples_nu);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch17'/copy1' incorporates:
                                                                 *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                                                 */
    SET_D_ODPFOH_MeanDevToTraj_1st_met (rtb_sfun_polyfitTgtObjectClothoid.fMeanDevToTraj_1st_met);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch18'/copy1' incorporates:
                                                                    *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                                                    */
    SET_D_ODPFOH_MeanDevToTraj_3rd_met (rtb_sfun_polyfitTgtObjectClothoid.fMeanDevToTraj_3rd_met);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch2'/copy1' */
    SET_D_ODPFOH_MinHistStartPosX_met(rtb_Switch_l4);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch20'/copy1' incorporates:
                                                        *  DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/DTC'/Data Type Conversion'
                                                        */
    SET_S_ODPFOH_ObjTraceStraight_perc(u8_f32(rtb_Switch_os));
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch21'/copy1' incorporates:
                                                                 *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                                                 */
    SET_D_ODPFOH_FirstStoredPntAge_sec (rtb_sfun_polyfitTgtObjectClothoid.fFirstStoredAge_sec);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch22'/copy1' */
    SET_D_ODPFOH_AddNewSample_bool(rtb_DataTypeConversion_j);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch23'/copy1' incorporates:
                                                                *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                                                */
    SET_D_ODPFOH_FirstStoredPntX_met(rtb_sfun_polyfitTgtObjectClothoid.fPosX0_met);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch24'/copy1' incorporates:
                                                                          *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                                                          */
    SET_D_ODPFOH_MeanStoredPntAge_sec (rtb_sfun_polyfitTgtObjectClothoid.fMeanSampleAge_sec);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch5'/copy1' */
    SET_D_ODPFOH_MaxGapEgoToHist_met(rtb_Min_a);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch6'/copy1' incorporates:
                                                   *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
                                                   */
    SET_D_ODPFOH_LastStoredPntX_met (rtb_sfun_polyfitTgtObjectClothoid.fLastStoredPntX_met);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch7'/copy1' */
    SET_S_ODPFOH_TgtObjClothoidInv_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch9'/copy1' incorporates:
                                                           *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/Constant3'/Constant'
                                                           */
    SET_S_ODPFOH_TgtObjCrvChng_1pm2(0.0F);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch4'/copy1' incorporates:
                                             *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Constant7'/Constant'
                                             */
    SET_S_ODPFOH_ObjTraceCrvQual_perc(0U);
    /* SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/branch3'/copy1' incorporates:
                                             *  Constant: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Constant1'/Constant'
                                             */
    SET_S_ODPFOH_AccObjTraceCrv_1pm(0.0F);
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay' */
    DW_odpfoh_Unit_Delay_DSTATE = rtb_Sum_ow;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_f = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck'/Unit_Delay' incorporates:
         *  Update for Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         */
    DW_odpfoh_Unit_Delay_DSTATE_b = GET_S_ODPFOP_AccObjPosX_met();
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl'/Unit_Delay' */
    DW_odpfoh_Unit_Delay_DSTATE_bc = rtb_LogicalOperator;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay1_DSTATE_l2 = rtb_AND_pg;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjChangeCheck/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay_DSTATE_d = rtb_NE;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/AccObjFreezeStandstill/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay_DSTATE_c = rtb_LogicalOperator;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/EdgeRising/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay4' */
    DW_odpfoh_Unit_Delay4_DSTATE_g = rtb_DataTypeConversion_m;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjStatusCheck/LowSpeedMode_Invalid'/Unit_Delay4' */
    DW_odpfoh_Unit_Delay4_DSTATE_b = rtb_Switch3_e;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier'/Unit_Delay4' */
    DW_odpfoh_Unit_Delay4_DSTATE_e = rtb_DataTypeConversion_d4;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay2' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         */
    DW_odpfoh_Unit_Delay2_DSTATE = rtb_sfun_polyfitTgtObjectClothoid.fLastStoredPntX_met;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay3' incorporates:
         *  BusCreator: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/PolyfitOutputMapping'/ODPFOH_PF_StructOut'
         */
    DW_odpfoh_Unit_Delay3_DSTATE_d = rtb_sfun_polyfitTgtObjectClothoid.uNumValidSamples_nu;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay_DSTATE_e = rtb_DataTypeConversion_d;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/HistoryControl/CheckHistoryResetConditions/EDGERISING'/fcg' */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality'/Comparison'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay1' incorporates:
         *  DataTypeConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/OR1/Functionality'/Data Type Conversion'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality'/Logical Operator1'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/NOT/Functionality'/NOT'
         *  Logic: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/OR1/Functionality'/OR'
         *  UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay5'
         */
    DW_odpfoh_Unit_Delay1_DSTATE_d = (uint8)(((!(((sint32)rtb_DataTypeConversion_d) != 0)) && ((((sint32)DW_odpfoh_Unit_Delay5_DSTATE_l) != 0) && (!(((sint32) rtb_Switch_jw) != 0)))) || (((sint32)LogicalOperator_ab) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay3' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    DW_odpfoh_Unit_Delay3_DSTATE = GET_S_LCFRCV_VehYawRate_rps();
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE = rtb_Mul;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_e = rtb_Sum;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay4' */
    DW_odpfoh_Unit_Delay4_DSTATE = rtb_Unit_Delay2;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay5' */
    DW_odpfoh_Unit_Delay5_DSTATE = rtb_Unit_Delay4;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/YawRateObjSync/VariableDelay'/Unit_Delay6' */
    DW_odpfoh_Unit_Delay6_DSTATE = rtb_Unit_Delay5;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_b = rtb_SFunction;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_b = rtb_Multiport_Switch;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/filterMeanEgoYawRate'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_j = rtb_SFunction_f;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/meanVelX'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    DW_odpfoh_Unit_Delay1_DSTATE_c = GET_S_LCFRCV_VehVelX_mps();
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/UnitDelay'/Unit_Delay5' */
    DW_odpfoh_Unit_Delay5_DSTATE_i = rtb_Switch_os;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay4_DSTATE_gn = rtb_Switch_jw;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay2_DSTATE_ow = rtb_LogicalOperator_ky;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_e0 = rtb_SignalConversion;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/LSM_Bridging'/Unit_Delay' */
    DW_odpfoh_Unit_Delay_DSTATE_jh = rtb_SignalConversion;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay1_DSTATE_ej = rtb_SignalConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_j = rtb_Max_gw;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTracePostprocessing/TraceStraightEstimation'/Unit_Delay3' */
    DW_odpfoh_Unit_Delay3_DSTATE_j = rtb_SFunction_k;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/filterMeanEgoYawRate'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_a = rtb_SFunction_ks;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_jw = rtb_DataTypeConversion_l;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay1_DSTATE_cw = rtb_DataTypeConversion_ja;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/KalmanFilter/EvaluateObjTraceDegradation'/Unit_Delay' */
    DW_odpfoh_Unit_Delay_DSTATE_f = rtb_Mul_db;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/DefineModeTransitionQualifier'/Unit_Delay5' */
    DW_odpfoh_Unit_Delay5_DSTATE_m = rtb_Sum_d;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic'/Unit_Delay' */
    DW_odpfoh_Unit_Delay_DSTATE_k = rtb_LogicalOperator;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi/EDGEBI'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi/EDGEBI/Functionality'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay3_DSTATE_n = rtb_Switch_ez;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/EdgeBi/EDGEBI'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/SignLimiterAndScaling'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_f = rtb_DataTypeConversion_oa;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/Freeze_IV'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_bl = rtb_Switch_dh;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_e = rtb_Sum_dn;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/TransitionControlLogic/SetModeTransitionTime/CalculateTransitionFactorA'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_l = rtb_Max_jt;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay_DSTATE_i = rtb_DataTypeConversion_m;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_PosY'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_jc = rtb_SFunction_ku;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/Freeze_IV'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_h = rtb_Sum_atk;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_o = rtb_Switch_id;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/CalculateTransitionFactorA'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_ek = rtb_Mul_dg;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/PosY_Filter'/Unit_Delay' */
    DW_odpfoh_Unit_Delay_DSTATE_n = rtb_SFunction_j;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_ho = rtb_Sum_nd;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_ci = rtb_LogicalOperator_i;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterPosY/A_Filtering/EnableFilterConditions'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_a = rtb_Switch_ji;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_k = rtb_DataTypeConversion_l0;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionControl/DefineObjTransitionQualifier'/Unit_Delay3' */
    DW_odpfoh_Unit_Delay3_DSTATE_es = rtb_DataTypeConversion_jd;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_o = rtb_Sum_li;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions/Reset'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_p = rtb_DataTypeConversion_ld;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionPosY0/EnableFilterConditions'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_jl = rtb_DataTypeConversion_ds;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/Freeze_IV'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_k = rtb_Switch_pv;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_n = rtb_Sum_nk;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Head'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_i = rtb_SFunction_a;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/Freeze_IV'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_jh = rtb_Sum_hd;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_ODPFOP_AccObjRelYawAng_rad'
         */
    DW_odpfoh_Unit_Delay1_DSTATE_cm = GET_S_ODPFOP_AccObjRelYawAng_rad();
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_ko = rtb_Switch_a3;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_d5 = rtb_LogicalOperator_i;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtObjDataPreprocessing/AccObjDataPreProcessing/TransitionSwitch/TransitionFilterYaw/A_Filtering/EnableFilterConditions'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_ay = rtb_DataTypeConversion_or;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_i = rtb_Sum_o4;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions/Reset'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_if = rtb_DataTypeConversion_ld;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionHead/EnableFilterConditions'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_ob = rtb_DataTypeConversion_fs;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/Freeze_IV'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_ki = rtb_Switch_nr;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_h = rtb_Switch_fd;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/LowPassFilter/LowPassFilter_Crv'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_g = rtb_SFunction_e;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_kk = rtb_Sum_bv5;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions/Reset'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_kx = rtb_DataTypeConversion_ld;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionCrv/EnableFilterConditions'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_ap = rtb_DataTypeConversion_h;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_k3 = rtb_Mul_pc;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_g3 = rtb_Switch_bx;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay3' */
    DW_odpfoh_Unit_Delay3_DSTATE_e = rtb_Mul_jst;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay_DSTATE_gw = rtb_DataTypeConversion_gg;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/Limiter_FMEA/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/Freeze_IV'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_kq = rtb_Switch_kpw;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_is = rtb_Mul_j2;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_c = rtb_Mul_kl;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions/Reset'/Unit_Delay1' */
    DW_odpfoh_Unit_Delay1_DSTATE_b3 = rtb_DataTypeConversion_ld;
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TgtTrajTransition/CosineTransitionLength/EnableFilterConditions'/Unit_Delay2' */
    DW_odpfoh_Unit_Delay2_DSTATE_m = rtb_RelationalOperator_ce;
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfoh_Unit_Delay5_DSTATE_l = rtb_Switch_jw;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOH/ODPFOH/ODPFOH_SenProcess/ODPFOH/TargetObjTraceGeneration/TrajInvalidBridging/EDGEFALLING1'/fcg' */
}
#include "Pse_ODPFOH.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
