/**************************************************************************
COPYRIGHT (C) $Date: 2019/12/17 14:25:23CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/LDPSA/DPLSIA_SEN/DPLSIA/i/project.pj $
$Log: DPLSIA.c  $
Revision 1.3.1.3 2019/12/17 14:25:23CET Diaz Bravo, Jose Luis (uidg8685) 
New bridged lane marking logic.
File          : DPLSIA
Generated on  : Tue 17.12.2019 at 13:44:30 (UTC+01:00)
MD5           : [1528749473  1902142629  3868190980  3775299332 0](DPLSIA)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.441655 (R2016b)
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "DPLSIA.h"
#include "DPLSIA_private.h"
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
#define DPLSIA_START_SEC_DATA_8
#include "DPLSIA_MemMap.h"
static uint8 DW_dplsia_UnitDelay2_DSTATE_o;
static uint8 DW_dplsia_UnitDelay2_DSTATE_g;
static uint8 DW_dplsia_UnitDelay2_DSTATE_f;
static uint8 DW_dplsia_UnitDelay2_DSTATE_oc;
static uint8 DW_dplsia_UnitDelay2_DSTATE_b;
static uint8 DW_dplsia_UnitDelay2_DSTATE_k;
static uint8 DW_dplsia_Unit_Delay_DSTATE;
static uint8 DW_dplsia_Unit_Delay_DSTATE_p;
static uint8 DW_dplsia_UnitDelay2_DSTATE_mk;
static uint8 DW_dplsia_UnitDelay1_DSTATE_n;
static uint8 DW_dplsia_UnitDelay2_DSTATE_a;
static uint8 DW_dplsia_UnitDelay1_DSTATE_j;
static uint8 DW_dplsia_UnitDelay1_DSTATE_nx;
static uint8 DW_dplsia_UnitDelay1_DSTATE_d;
static uint8 DW_dplsia_UnitDelay2_DSTATE_p[2];
static uint8 DW_dplsia_UnitDelay3_DSTATE;
static uint8 DW_dplsia_UnitDelay1_DSTATE_p;
static uint8 DW_dplsia_UnitDelay2_DSTATE_d;
static uint8 DW_dplsia_UnitDelay2_DSTATE_h;
static uint8 DW_dplsia_UnitDelay2_DSTATE_ly;
static uint8 DW_dplsia_UnitDelay2_DSTATE_n;
static uint8 DW_dplsia_UnitDelay2_DSTATE_la;
static uint8 DW_dplsia_UnitDelay2_DSTATE_j;
static uint8 DW_dplsia_UnitDelay2_DSTATE_kx;
static uint8 DW_dplsia_UnitDelay2_DSTATE_id;
static uint8 DW_dplsia_UnitDelay2_DSTATE_e;
static uint8 DW_dplsia_UnitDelay2_DSTATE_le;
static uint8 DW_dplsia_UnitDelay1_DSTATE_l;
static uint8 DW_dplsia_UnitDelay2_DSTATE_ix;
static uint8 DW_dplsia_UnitDelay1_DSTATE_b;
static uint8 DW_dplsia_UnitDelay1_DSTATE_f;
static uint8 DW_dplsia_UnitDelay1_DSTATE_o;
static uint8 DW_dplsia_UnitDelay1_DSTATE_jp[2];
static uint8 DW_dplsia_UnitDelay3_DSTATE_e;
static uint8 DW_dplsia_UnitDelay1_DSTATE_b5;
static uint8 DW_dplsia_UnitDelay2_DSTATE_jc;
static uint8 DW_dplsia_UnitDelay2_DSTATE_c;
static uint8 DW_dplsia_UnitDelay2_DSTATE_c5;
#define DPLSIA_STOP_SEC_DATA_8
#include "DPLSIA_MemMap.h"
#define DPLSIA_START_SEC_DATA_32
#include "DPLSIA_MemMap.h"
static float32 DW_dplsia_UnitDelay2_DSTATE;
static float32 DW_dplsia_UnitDelay2_DSTATE_l;
static float32 DW_dplsia_UnitDelay1_DSTATE;
static float32 DW_dplsia_UnitDelay1_DSTATE_c;
static float32 DW_dplsia_Unit_Delay1_DSTATE[8];
static float32 DW_dplsia_UnitDelay2_DSTATE_i;
static float32 DW_dplsia_UnitDelay2_DSTATE_m;
#define DPLSIA_STOP_SEC_DATA_32
#include "DPLSIA_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPLSIA/DPLSIA/INI'/DPLSIA_SenReset'
 * Block description for: 'sda:DPLSIA/DPLSIA/INI'/DPLSIA_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLSIA_SenReset
#include "Pse_DPLSIA.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLSIA_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant1'/Constant' */
    SET_S_DPLSIA_SpecificLDP_btf(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant10'/Constant' */
    SET_S_DPLSIA_DlcRiLDP_met(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant11'/Constant' */
    SET_S_DPLSIA_TlcRiLDP_sec(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant12'/Constant' */
    SET_S_DPLSIA_SideCondLDPRi_btf(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant13'/Constant' */
    SET_S_DPLSIA_LnBndValidLDP_nu(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant14'/Constant' */
    SET_D_DPLSIA_LnBndRiTrgValidLDP_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant15'/Constant' */
    SET_D_DPLSIA_LnBndLeCancelValidLDP_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant16'/Constant' */
    SET_D_DPLSIA_LnBndRiCancelValidLDP_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant17'/Constant' */
    SET_D_DPLSIA_LnBndLeTrgValidLDP_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant18'/Constant' */
    SET_S_DPLSIA_LnBndValidLDW_nu(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant19'/Constant' */
    SET_S_DPLSIA_LnBndLeValidLDW_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant2'/Constant' */
    SET_S_DPLSIA_SpecificLDW_btf(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant20'/Constant' */
    SET_S_DPLSIA_LnBndRiValidLDW_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant21'/Constant' */
    SET_D_DPLSIA_LnBndLeTrgValidLDW_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant22'/Constant' */
    SET_D_DPLSIA_LnBndRiTrgValidLDW_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant23'/Constant' */
    SET_D_DPLSIA_LnBndLeCancelValidLDW_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant24'/Constant' */
    SET_D_DPLSIA_LnBndRiCancelValidLDW_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant25'/Constant' */
    SET_S_DPLSIA_VelLatLeLDP_mps(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant26'/Constant' */
    SET_S_DPLSIA_VelLatRiLDP_mps(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant27'/Constant' */
    SET_S_DPLSIA_DlcRiLDW_met(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant28'/Constant' */
    SET_S_DPLSIA_TlcRiLDW_sec(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant29'/Constant' */
    SET_S_DPLSIA_VelLatLeLDW_mps(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant3'/Constant' */
    SET_S_DPLSIA_LnBndLeValidLDP_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant30'/Constant' */
    SET_S_DPLSIA_VelLatRiLDW_mps(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant31'/Constant' */
    SET_S_DPLSIA_DlcLeLDW_met(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant32'/Constant' */
    SET_S_DPLSIA_TlcLeLDW_sec(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant33'/Constant' */
    SET_S_DPLSIA_LaneWidthLDP_met(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant34'/Constant' */
    SET_S_DPLSIA_LaneWidthLDW_met(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant35'/Constant' */
    SET_S_DPLSIA_TgtCntrLnEnable_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant36'/Constant' */
    SET_S_DPLSIA_CurveTypeLe_enum(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant37'/Constant' */
    SET_S_DPLSIA_CurveTypeRi_enum(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant4'/Constant' */
    SET_S_DPLSIA_LnBndRiValidLDP_bool(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant5'/Constant' */
    SET_S_DPLSIA_SideCondLDWLe_btf(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant6'/Constant' */
    SET_S_DPLSIA_SideCondLDWRi_btf(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant7'/Constant' */
    SET_S_DPLSIA_SideCondLDPLe_btf(0U);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant8'/Constant' */
    SET_S_DPLSIA_DlcLeLDP_met(0.0F);
    /* Constant: 'sda:DPLSIA/DPLSIA/INI/DPLSIA_SenReset/Constant9'/Constant' */
    SET_S_DPLSIA_TlcLeLDP_sec(0.0F);
}
#include "Pse_DPLSIA.h"
/*
 * Output and update for function-call system: 'sda:DPLSIA/DPLSIA'/DPLSIA_SenProcess'
 * Block description for: 'sda:DPLSIA/DPLSIA'/DPLSIA_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLSIA_SenProcess
#include "Pse_DPLSIA.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLSIA_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_o;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_oa;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_es;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    uint8 rtb_LogicalOperator_o[8];
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate1[8];
    uint8 rtb_VectorConcatenate_h[8];
    uint8 rtb_VectorConcatenate1_g[8];
    uint8 rtb_VectorConcatenate_e[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_EQ;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_GT_k;
    uint8 rtb_LT_ai;
    uint8 rtb_DataTypeConversion_ae;
    float32 rtb_Switch;
    uint8 rtb_LT_h1;
    uint8 rtb_Switch_hb;
    uint8 rtb_LogicalOperator;
    float32 rtb_Div;
    float32 rtb_Switch_in;
    uint8 rtb_DataTypeConversion_lb;
    uint8 rtb_EQ_dr;
    float32 rtb_Switch_f;
    uint8 rtb_GT_d;
    uint8 rtb_LT_cc;
    uint8 rtb_DataTypeConversion_bp;
    uint8 rtb_LT_lr;
    uint8 rtb_LogicalOperator_b;
    uint8 rtb_DataTypeConversion_k;
    float32 rtb_Switch_kk[2];
    uint8 rtb_DataTypeConversion_fu;
    uint8 rtb_LT_m2;
    float32 rtb_Switch_ao;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_LT_aw;
    uint8 rtb_VectorConcatenate_d[8];
    float32 rtb_Sum_mh;
    sint8 rtb_DataTypeConversion_fb[2];
    sint8 rtb_DataTypeConversion_g[2];
    sint8 rtb_Switch_mu[2];
    uint8 rtb_Switch3_mc;
    uint8 rtb_Switch3;
    uint8 rtb_LT_fr;
    uint8 rtb_LT_lt;
    uint8 rtb_GT_fm;
    uint8 rtb_EQ_ed;
    uint8 rtb_DataTypeConversion_py;
    uint8 rtb_LT_l;
    uint8 rtb_LogicalOperator_l;
    uint8 rtb_EQ_i1;
    uint8 rtb_GT_gk;
    uint8 rtb_LT_h;
    uint8 rtb_LT_eo;
    uint8 rtb_DataTypeConversion_b;
    uint8 rtb_LogicalOperator_n;
    float32 rtb_Switch_ny[2];
    uint8 rtb_GT_p;
    float32 rtb_Switch_ar;
    float32 rtb_Abs_g;
    sint32 i;
    uint8 tmp;
    uint8 rtb_Switch_pz;
    float32 rtb_Switch_i;
    float32 tmp_0;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/LT/Functionality'/LT'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Switch1/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Neg/Functionality'/Unary Minus'
         */
    if (GET_S_ABPLBP_LeLnClthCrv_1pm() > GET_P_DPLSIA_CurveDetectThreshold_1pm()) {
        SET_S_DPLSIA_CurveTypeLe_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_INNER));
    } else if (GET_S_ABPLBP_LeLnClthCrv_1pm() < (-GET_P_DPLSIA_CurveDetectThreshold_1pm())) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/from_data_definition3'/state_source'
                 */
        SET_S_DPLSIA_CurveTypeLe_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_OUTER));
    } else {
        SET_S_DPLSIA_CurveTypeLe_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_NONE));
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/LT1/Functionality'/LT'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Switch3/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Neg3/Functionality'/Unary Minus'
         */
    if (GET_S_ABPLBP_RiLnClthCrv_1pm() < (-GET_P_DPLSIA_CurveDetectThreshold_1pm())) {
        SET_S_DPLSIA_CurveTypeRi_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_INNER));
    } else if (GET_S_ABPLBP_RiLnClthCrv_1pm() > GET_P_DPLSIA_CurveDetectThreshold_1pm()) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/from_data_definition5'/state_source'
                 */
        SET_S_DPLSIA_CurveTypeRi_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_OUTER));
    } else {
        SET_S_DPLSIA_CurveTypeRi_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_NONE));
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/CurveType/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Constant5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND2/Functionality'/AND'
         */
    rtb_EQ = (uint8)((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Constant6'/Constant'
         *  DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND4/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQuSIF_btf'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Relational Operator5/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND1/Functionality'/AND'
         */
    if (((sint32)GET_P_DPLSIA_SafetyIfaceLDPOn_bool()) != 0) {
        rtb_EQ = (uint8)(((((sint32)GET_S_ABPLBP_LeLnInvalidQuSIF_btf()) & ((sint32)GET_P_DPLSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32)rtb_EQ) != 0));
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPLSMI_DangerousSide_nu'
         */
    rtb_EQ_i1 = (uint8)(((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE)));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Application Parameter1'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/AND4/Functionality'/AND'
         */
    rtb_DataTypeConversion = (uint8)((((sint32) GET_P_DPLSIA_SafetyIfaceLDPOn_bool()) != 0) && (((sint32)rtb_EQ_i1) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch = GET_S_ABPLBP_LeLnClthHeadingSIF_rad();
    } else {
        rtb_Switch = GET_S_ABPLBP_LeLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Add/Functionality'/Sum'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_o) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDPMin_rad() - GET_P_DPLSIA_HeadAngThresLDPHyst_rad();
        rtb_Switch_ar = GET_P_DPLSIA_HeadAngThresLDPHyst_rad() + GET_P_DPLSIA_HeadAngThresLDPMax_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDPMin_rad();
        rtb_Switch_ar = GET_P_DPLSIA_HeadAngThresLDPMax_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger/Neg/Functionality'/Unary Minus'
         */
    rtb_GT_k = (uint8)(((-rtb_Switch) > tmp_0) && ((-rtb_Switch) < rtb_Switch_ar));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND7/Functionality'/AND'
         */
    rtb_EQ = (uint8)((((sint32)rtb_EQ) != 0) && (((sint32)rtb_GT_k) != 0));
    /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_DPLSIA_VXCrvThresLDPMax_1pm(), &x_dps);
    }
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_g) != 0) {
        /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D (GETA_Y_DPLSIA_VXCrvThresLDPHyst_1pm(), &x_dps);
        }
        rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_h + rtb_ip_lookup_fxpt_sfun_7;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_ao = GET_S_ABPLBP_LeLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_ao = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_ai = (uint8)(f32_abs_f32(rtb_Switch_ao) < rtb_Abs_g);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ae = (uint8)(!((((sint32) GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32) GET_P_DPLSIA_ConstrSiteLDP_bool()) != 0)));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND5/Functionality'/AND'
         */
    rtb_EQ = (uint8)(((((sint32)rtb_EQ) != 0) && (((sint32)rtb_LT_ai) != 0)) && (((sint32)rtb_DataTypeConversion_ae) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_f) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDPHyst_rad() + GET_P_DPLSIA_HeadAngThresLDPMax_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDPMax_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel/Abs/Functionality'/Abs'
         */
    rtb_LT_h1 = (uint8)(f32_abs_f32(rtb_Switch) < tmp_0);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Constant1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND3/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND6/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Relational Operator1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND13/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/AND8/Functionality'/AND'
         */
    rtb_Switch_hb = (uint8)((((((sint32)rtb_LT_h1) != 0) && (((((sint32) GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_ai) != 0)) && (((sint32)rtb_DataTypeConversion_ae) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Switch9/Functionality'/Switch' */
    if (((sint32)rtb_EQ_i1) != 0) {
        rtb_DataTypeConversion_ae = rtb_EQ;
    } else {
        rtb_DataTypeConversion_ae = rtb_Switch_hb;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Switch9/Functionality'/Switch' */
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft'/Unit Delay2'
         */
    rtb_LogicalOperator = (uint8)((DW_dplsia_UnitDelay2_DSTATE <= 0.0F) && (((sint32)rtb_DataTypeConversion_ae) != 0));
    /* Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/P_VEH_Width_met'/Constant'
         */
    rtb_Div = GET_P_VEH_Width_met() / 2.0F;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant8'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Add/Functionality'/Sum'
         */
    if (((sint32)rtb_LogicalOperator) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch9/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_Switch_ao = GET_S_ABPLBP_LeLnClthPosY0SIF_met();
        } else {
            rtb_Switch_ao = GET_S_ABPLBP_LeLnClthPosY0_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch9/Functionality'/Switch' */
        rtb_Switch_in = rtb_Switch_ao - rtb_Div;
    } else {
        rtb_Switch_in = 10.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant6'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/P_VEH_Width_met2'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/AND3/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_lb = (uint8)(((((sint32)rtb_LogicalOperator) != 0) && (rtb_Switch_in > 0.0F)) && (rtb_Switch < (-GET_P_DPLSIA_TlcHeadAngThres_rad())));
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Constant3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND14/Functionality'/AND'
         */
    rtb_EQ_dr = (uint8)((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Constant8'/Constant'
         *  DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND1/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQuSIF_btf'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Relational Operator8/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND12/Functionality'/AND'
         */
    if (((sint32)GET_P_DPLSIA_SafetyIfaceLDPOn_bool()) != 0) {
        rtb_EQ_dr = (uint8)(((((sint32)GET_S_ABPLBP_RiLnInvalidQuSIF_btf()) & ((sint32)GET_P_DPLSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_dr) != 0));
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_f = GET_S_ABPLBP_RiLnClthHeadingSIF_rad();
    } else {
        rtb_Switch_f = GET_S_ABPLBP_RiLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Add/Functionality'/Sum'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_oc) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDPMin_rad() - GET_P_DPLSIA_HeadAngThresLDPHyst_rad();
        rtb_Switch_ar = GET_P_DPLSIA_HeadAngThresLDPHyst_rad() + GET_P_DPLSIA_HeadAngThresLDPMax_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDPMin_rad();
        rtb_Switch_ar = GET_P_DPLSIA_HeadAngThresLDPMax_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_d = (uint8)((rtb_Switch_f > tmp_0) && (rtb_Switch_f < rtb_Switch_ar));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND2/Functionality'/AND'
         */
    rtb_EQ_dr = (uint8)((((sint32)rtb_EQ_dr) != 0) && (((sint32)rtb_GT_d) != 0));
    /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_o = F32_PTR_IP1D (GETA_Y_DPLSIA_VXCrvThresLDPMax_1pm(), &x_dps);
    }
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_o;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_b) != 0) {
        /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_DPLSIA_VXCrvThresLDPHyst_1pm(), &x_dps);
        }
        rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_c + rtb_ip_lookup_fxpt_sfun_7_o;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_ao = GET_S_ABPLBP_RiLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_ao = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight/Abs/Functionality'/Abs'
         */
    rtb_LT_cc = (uint8)(f32_abs_f32(rtb_Switch_ao) < rtb_Abs_g);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_bp = (uint8)(!((((sint32) GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32) GET_P_DPLSIA_ConstrSiteLDP_bool()) != 0)));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND9/Functionality'/AND'
         */
    rtb_EQ_dr = (uint8)(((((sint32)rtb_EQ_dr) != 0) && (((sint32)rtb_LT_cc) != 0)) && (((sint32)rtb_DataTypeConversion_bp) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_k) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDPHyst_rad() + GET_P_DPLSIA_HeadAngThresLDPMax_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDPMax_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel/Abs/Functionality'/Abs'
         */
    rtb_LT_lr = (uint8)(f32_abs_f32(rtb_Switch_f) < tmp_0);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND10/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Constant1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND10/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND3/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Relational Operator2/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND11/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/AND8/Functionality'/AND'
         */
    rtb_EQ_ed = (uint8)((((((sint32)rtb_LT_lr) != 0) && (((((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_cc) != 0)) && (((sint32)rtb_DataTypeConversion_bp) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_EQ_i1) != 0) {
        rtb_DataTypeConversion_bp = rtb_EQ_dr;
    } else {
        rtb_DataTypeConversion_bp = rtb_EQ_ed;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Switch1/Functionality'/Switch' */
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight'/Unit Delay2'
         */
    rtb_LogicalOperator_b = (uint8)((DW_dplsia_UnitDelay2_DSTATE_l <= 0.0F) && (((sint32)rtb_DataTypeConversion_bp) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant9'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Product/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator) != 0) {
        rtb_Switch *= GET_S_LCFRCV_VehVelX_mps();
    } else {
        rtb_Switch = 0.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant10'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Product2/Functionality'/Mul'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch6/Functionality'/Switch'
         */
    if (((sint32)rtb_LogicalOperator_b) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_Switch_ao = GET_S_ABPLBP_RiLnClthPosY0SIF_met();
        } else {
            rtb_Switch_ao = GET_S_ABPLBP_RiLnClthPosY0_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch1/Functionality'/Switch' */
        rtb_Div += rtb_Switch_ao;
        rtb_Switch_ao = GET_S_LCFRCV_VehVelX_mps() * rtb_Switch_f;
    } else {
        rtb_Div = -10.0F;
        rtb_Switch_ao = 0.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant1'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_lb) != 0) {
        /* Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Abs/Functionality'/Abs' */
        rtb_Abs_g = f32_abs_f32(rtb_Switch);
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide1/In3'/Constant'
                 *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Div'
                 */
        if (rtb_Abs_g != 0.0F) {
            rtb_Switch_ar = rtb_Switch_in / rtb_Abs_g;
        } else {
            rtb_Switch_ar = 10.0F;
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_ar = 10.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch4'/copy1' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant1'/Constant'
         *  MinMax: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Min/Functionality'/Min'
         */
    SET_S_DPLSIA_TlcLeLDP_sec(f32_min_f32_f32(rtb_Switch_ar, 10.0F));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch3/Functionality'/Switch' incorporates:
                                                                        *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant2'/Constant'
                                                                        *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant7'/Constant'
                                                                        *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/P_VEH_Width_met1'/Constant'
                                                                        *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/AND4/Functionality'/AND'
                                                                        *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/GT1/Functionality'/GT'
                                                                        *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/LT1/Functionality'/LT'
                                                                        */
    if (((((sint32)rtb_LogicalOperator_b) != 0) && (rtb_Div < 0.0F)) && (rtb_Switch_f > GET_P_DPLSIA_TlcHeadAngThres_rad())) {
        /* Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Abs2/Functionality'/Abs' */
        rtb_Switch_f = f32_abs_f32(rtb_Switch_ao);
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide2/In3'/Constant'
                 *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Div'
                 *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Neg1/Functionality'/Unary Minus'
                 */
        if (rtb_Switch_f != 0.0F) {
            rtb_Abs_g = (-rtb_Div) / rtb_Switch_f;
        } else {
            rtb_Abs_g = 10.0F;
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Abs_g = 10.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch5'/copy1' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Constant2'/Constant'
         *  MinMax: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/DlcTlcCalculation/Min1/Functionality'/Min'
         */
    SET_S_DPLSIA_TlcRiLDP_sec(f32_min_f32_f32(rtb_Abs_g, 10.0F));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch6/Functionality'/Switch' incorporates:
                                                                    *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Application Parameter2'/Constant'
                                                                    *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
                                                                    *  Inport: '<Root>/S_ABPLBP_UncoupledLaneWidth_met'
                                                                    */
    if (((sint32)GET_P_DPLSIA_UncoupledLWEnable_bool()) != 0) {
        rtb_Switch_kk[1] = GET_S_ABPLBP_UncoupledLaneWidth_met();
    } else {
        rtb_Switch_kk[1] = GET_S_ABPLBP_CoupledLaneWidth_met();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneBoundaryInterface/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_ae) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft'/Unit Delay2'
                 */
        if (DW_dplsia_UnitDelay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsia_UnitDelay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/Application Parameter4'/Constant'
                 */
        DW_dplsia_UnitDelay2_DSTATE = GET_P_DPLSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/branch2'/copy1' */
    SET_D_DPLSIA_LnBndLeTrgValidLDP_bool(rtb_EQ);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_bp) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight'/Unit Delay2'
                 */
        if (DW_dplsia_UnitDelay2_DSTATE_l > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsia_UnitDelay2_DSTATE_l -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/Application Parameter3'/Constant'
                 */
        DW_dplsia_UnitDelay2_DSTATE_l = GET_P_DPLSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/branch1'/copy1' */
    SET_D_DPLSIA_LnBndRiTrgValidLDP_bool(rtb_EQ_dr);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch9/Functionality'/Switch' incorporates:
                                                       *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/from_data_definition1'/state_source'
                                                       *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/AND/Functionality'/AND'
                                                       *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch10/Functionality'/Switch'
                                                       *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch11/Functionality'/Switch'
                                                       */
    if ((((sint32)rtb_LogicalOperator) != 0) && (((sint32)rtb_LogicalOperator_b) != 0)) {
        SET_S_DPLSIA_LnBndValidLDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE));
    } else if (((sint32)rtb_LogicalOperator) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch10/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/from_data_definition2'/state_source'
                 */
        SET_S_DPLSIA_LnBndValidLDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY));
    } else if (((sint32)rtb_LogicalOperator_b) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch11/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch10/Functionality'/Switch'
                 */
        SET_S_DPLSIA_LnBndValidLDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY));
    } else {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch10/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch11/Functionality'/Switch'
                 */
        SET_S_DPLSIA_LnBndValidLDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID));
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LnBndValidLDP/Switch9/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalState_enum'
         */
    rtb_DataTypeConversion = (uint8)(((sint32)GET_S_LCFRCV_TurnSignalState_enum()) == ((sint32)((uint8)E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_RIGHT)));
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/from_data_definition'/state_source'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalState_enum'
         */
    rtb_DataTypeConversion_ae = (uint8)(((sint32) GET_S_LCFRCV_TurnSignalState_enum()) == ((sint32)((uint8) E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_LEFT)));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Constant4'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi'/Unit_Delay'
         */
    if (((sint32)GET_P_DPLSIA_TurnSignReset_bool()) != 0) {
        /* S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1'/fcg' incorporates:
                 *  SubSystem: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality'/Comparison'
                 */
        rtb_DataTypeConversion_bp = (uint8)((!(((sint32)DW_dplsia_Unit_Delay_DSTATE) != 0)) && (((sint32)rtb_DataTypeConversion_ae) != 0));
        /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1'/fcg' */
    } else {
        rtb_DataTypeConversion_bp = 0U;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Switch8/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Constant2'/Constant'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_bp) != 0) {
        rtb_Switch_f = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Application Parameter1'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Add2/Functionality'/Sum'
                 */
        rtb_Switch_f = GET_P_DPLSIA_TurnSignHoldingTime_sec() + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Switch/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi '/Unit Delay1'
                 */
        rtb_Switch_f = DW_dplsia_UnitDelay1_DSTATE;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Constant3'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Relational Operator8/Functionality'/GT'
         */
    rtb_DataTypeConversion_k = (uint8)((((sint32)rtb_DataTypeConversion) != 0) || (rtb_Switch_f > 1.0E-5F));
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1[0] = rtb_DataTypeConversion_k;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[2] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector Concatenate1In4' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[3] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector Concatenate1In5' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[4] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector Concatenate1In6' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[5] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector Concatenate1In7' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[6] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector Concatenate1In8' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[7] = 0U;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Constant5'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe'/Unit_Delay'
         */
    if (((sint32)GET_P_DPLSIA_TurnSignReset_bool()) != 0) {
        /* S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1'/fcg' incorporates:
                 *  SubSystem: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality'/Comparison'
                 */
        rtb_DataTypeConversion_bp = (uint8)((!(((sint32) DW_dplsia_Unit_Delay_DSTATE_p) != 0)) && (((sint32)rtb_DataTypeConversion) != 0));
        /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1'/fcg' */
    } else {
        rtb_DataTypeConversion_bp = 0U;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Constant2'/Constant'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_bp) != 0) {
        rtb_Abs_g = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_ae) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/Application Parameter5'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Add2/Functionality'/Sum'
                 */
        rtb_Abs_g = GET_P_DPLSIA_TurnSignHoldingTime_sec() + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe'/Unit Delay1'
                 */
        rtb_Abs_g = DW_dplsia_UnitDelay1_DSTATE_c;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Constant3'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Relational Operator8/Functionality'/GT'
         */
    rtb_DataTypeConversion_bp = (uint8)((((sint32)rtb_DataTypeConversion_ae) != 0) || (rtb_Abs_g > 1.0E-5F));
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_DataTypeConversion_bp;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant3'/Constant'
         */
    rtb_VectorConcatenate[2] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant3'/Constant'
         */
    rtb_VectorConcatenate[3] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector ConcatenateIn5' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant3'/Constant'
         */
    rtb_VectorConcatenate[4] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant3'/Constant'
         */
    rtb_VectorConcatenate[5] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant3'/Constant'
         */
    rtb_VectorConcatenate[6] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/Constant3'/Constant'
         */
    rtb_VectorConcatenate[7] = 0U;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_mk) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPMin_mps() - GET_P_DPLSIA_VelLatThresLDPHyst_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPMin_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Relational Operator/Functionality'/GT' incorporates:
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_lb = (uint8)((-rtb_Switch) > tmp_0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_mk) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPHyst_mps() + GET_P_DPLSIA_VelLatThresLDPMax_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPMax_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_fu = (uint8)((((sint32)rtb_DataTypeConversion_lb) != 0) && ((-rtb_Switch) < tmp_0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/P_LDPSA_VelXMin_mps5'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft'/Unit Delay1'
         */
    if (((sint32)DW_dplsia_UnitDelay1_DSTATE_n) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPHyst_mps() + GET_P_DPLSIA_VelLatThresLDPMax_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPMax_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Abs/Functionality'/Abs'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_LT_m2 = (uint8)(f32_abs_f32(-rtb_Switch) < tmp_0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Switch4/Functionality'/Switch' */
    if (((sint32)rtb_EQ_i1) != 0) {
        rtb_EQ_dr = rtb_DataTypeConversion_fu;
    } else {
        rtb_EQ_dr = rtb_LT_m2;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate[1] = (uint8)(!(((sint32)rtb_EQ_dr) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_a) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPMin_mps() - GET_P_DPLSIA_VelLatThresLDPHyst_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPMin_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Relational Operator/Functionality'/GT' */
    rtb_DataTypeConversion_lb = (uint8)(rtb_Switch_ao > tmp_0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_a) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPHyst_mps() + GET_P_DPLSIA_VelLatThresLDPMax_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPMax_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Relational Operator1/Functionality'/LT'
         */
    rtb_DataTypeConversion_o = (uint8)((((sint32)rtb_DataTypeConversion_lb) != 0) && (rtb_Switch_ao < tmp_0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/P_LDPSA_VelXMin_mps5'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight'/Unit Delay1'
         */
    if (((sint32)DW_dplsia_UnitDelay1_DSTATE_j) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPHyst_mps() + GET_P_DPLSIA_VelLatThresLDPMax_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDPMax_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Abs/Functionality'/Abs'
         */
    rtb_LT_aw = (uint8)(f32_abs_f32(rtb_Switch_ao) < tmp_0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Switch4/Functionality'/Switch' */
    if (((sint32)rtb_EQ_i1) != 0) {
        rtb_EQ_i1 = rtb_DataTypeConversion_o;
    } else {
        rtb_EQ_i1 = rtb_LT_aw;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate1[1] = (uint8)(!(((sint32)rtb_EQ_i1) != 0));
    /* S-Function (sfun_setbit): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/set_bit/Functionality'/sfun_setbit' */
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
        rtb_EQ_dr = temp;
    }
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/set_bit/Functionality'/DTC_out' */
    SET_S_DPLSIA_SideCondLDPLe_btf(rtb_EQ_dr);
    /* S-Function (sfun_setbit): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/set_bit1/Functionality'/sfun_setbit' */
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
        rtb_EQ_dr = temp;
    }
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/set_bit1/Functionality'/DTC_out' */
    SET_S_DPLSIA_SideCondLDPRi_btf(rtb_EQ_dr);
    /* Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/Abs/Functionality'/Abs' incorporates:
                                                 *  Inport: '<Root>/S_LCFRCV_VehAclY_mps2'
                                                 */
    rtb_Switch_ar = f32_abs_f32(GET_S_LCFRCV_VehAclY_mps2());
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/C_LCF_AclYHyst_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/C_LCF_AclYMax_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity'/Unit Delay1'
         */
    if (rtb_Switch_ar > (GET_P_DPLSIA_AclYMax_mps2() + GET_P_DPLSIA_AclYHyst_mps2())) {
        rtb_EQ_dr = 1U;
    } else if (rtb_Switch_ar < GET_P_DPLSIA_AclYMax_mps2()) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_EQ_dr = 0U;
    } else {
        rtb_EQ_dr = DW_dplsia_UnitDelay1_DSTATE_nx;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity'/Unit Delay1' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    DW_dplsia_UnitDelay1_DSTATE_nx = rtb_EQ_dr;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LatAclValidity/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate_d[5] = rtb_EQ_dr;
    /* Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         */
    rtb_Switch_ar = f32_abs_f32(GET_S_LCFRCV_VehCrv_1pm());
    /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D (GETA_Y_DPLSIA_VXVehCrvThresMax_1pm(), &x_dps);
    }
    /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_DPLSIA_VXVehCrvThresHyst_1pm(), &x_dps);
    }
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Relational Operator1'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature'/Unit Delay1'
         */
    if (rtb_Switch_ar > (rtb_ip_lookup_fxpt_sfun_7_a + rtb_ip_lookup_fxpt_sfun_7_j)) {
        rtb_EQ_dr = 1U;
    } else if (rtb_Switch_ar < rtb_ip_lookup_fxpt_sfun_7_a) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_EQ_dr = 0U;
    } else {
        rtb_EQ_dr = DW_dplsia_UnitDelay1_DSTATE_d;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch3' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature'/Unit Delay1' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    DW_dplsia_UnitDelay1_DSTATE_d = rtb_EQ_dr;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/EgoVehCurvature/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate_d[6] = rtb_EQ_dr;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LDPSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LDPSwitch/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LDPSwitch/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_LDPSwitch_bool'
         */
    if (((sint32)GET_P_DPLSMI_LDPSwitchEnable_bool()) != 0) {
        rtb_EQ_dr = GET_S_LCFRCV_LDPSwitch_bool();
    } else {
        rtb_EQ_dr = GET_P_DPLSMI_LDPSwitch_bool();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LDPSwitch/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LDPSwitch/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LDPSwitch/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_d[7] = (uint8)(!(((sint32)rtb_EQ_dr) != 0));
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Add/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXMin_mps'/Constant'
         */
    rtb_Switch_ar = GET_P_DPLSIA_LaneWidthLDPMin_met() - GET_P_DPLSIA_LaneWidthLDPHyst_met();
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Add1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXMax_mps'/Constant'
         */
    rtb_Sum_mh = GET_P_DPLSIA_LaneWidthLDPHyst_met() + GET_P_DPLSIA_LaneWidthLDPMax_met();
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         */
    rtb_Switch_kk[0] = GET_S_ABPLBP_LaneWidth_met();
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator3/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXHyst_mps3'/Constant'
         */
    tmp = (uint8)(((sint32)GET_P_DPLSIA_LaneWidthWideLn_bool()) != 0);
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator2/Functionality'/AND' */
    rtb_Switch_pz = (uint8)((((sint32)rtb_Switch_hb) != 0) && (((sint32) rtb_EQ_ed) != 0));
    for (i = 0; i < 2; i++) {
        /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Relational Operator1/Functionality'/LT' */
        rtb_Switch_i = rtb_Switch_kk[i];
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXMax_mps'/Constant'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/Unit Delay2'
                 */
        if (((sint32)DW_dplsia_UnitDelay2_DSTATE_p[i]) != 0) {
            tmp_0 = rtb_Sum_mh;
        } else {
            tmp_0 = GET_P_DPLSIA_LaneWidthLDPMax_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch1/Functionality'/Switch' */
        /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Relational Operator1/Functionality'/LT' */
        rtb_EQ = (uint8)(rtb_Switch_kk[i] < tmp_0);
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXMin_mps'/Constant'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/Unit Delay2'
                 */
        if (((sint32)DW_dplsia_UnitDelay2_DSTATE_p[i]) != 0) {
            tmp_0 = rtb_Switch_ar;
        } else {
            tmp_0 = GET_P_DPLSIA_LaneWidthLDPMin_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch3/Functionality'/Switch' */
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator1/Functionality'/AND'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Relational Operator/Functionality'/GT'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Relational Operator1/Functionality'/LT'
                 */
        rtb_EQ_i1 = (uint8)((rtb_Switch_kk[i] > tmp_0) && (((sint32)rtb_EQ) != 0));
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator4/Functionality'/NOT'
                 */
        rtb_EQ = (uint8)(!(((sint32)rtb_EQ) != 0));
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator3/Functionality'/AND'
                 */
        rtb_EQ = (uint8)(((sint32)tmp) && (((sint32)rtb_EQ) != 0));
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator5/Functionality'/NOT'
                 */
        rtb_EQ = (uint8)(!(((sint32)rtb_EQ) != 0));
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator2/Functionality'/AND'
                 */
        rtb_EQ = (uint8)(((sint32)rtb_Switch_pz) && (((sint32)rtb_EQ) != 0));
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Constant2'/Constant'
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXHyst_mps2'/Constant'
                 *  DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator/Functionality'/Data Type Conversion'
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator/Functionality'/NOT'
                 *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch4/Functionality'/Switch'
                 */
        if (((sint32)rtb_EQ) != 0) {
            rtb_Switch_mu[i] = (sint8)(!(((sint32)rtb_EQ_i1) != 0));
        } else {
            rtb_Switch_mu[i] = 0;
            rtb_Switch_i = GET_P_DPLSIA_LaneWidthWideLnDef_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch2/Functionality'/Switch' */
        /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Relational Operator1/Functionality'/LT' */
        rtb_DataTypeConversion_fb[i] = (sint8)rtb_EQ;
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Logical Operator1/Functionality'/Data Type Conversion' */
        rtb_DataTypeConversion_g[i] = (sint8)rtb_EQ_i1;
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch4/Functionality'/Switch' */
        rtb_Switch_kk[i] = rtb_Switch_i;
    }
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch11'/copy1' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Constant1'/Constant'
         *  Selector: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/Selector'
         */
    SET_S_DPLSIA_TgtCntrLnEnable_bool((uint8)rtb_DataTypeConversion_fb[0]);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch8'/copy1' incorporates:
                                                                          *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Constant3'/Constant'
                                                                          *  Selector: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/Selector1'
                                                                          */
    SET_S_DPLSIA_LaneWidthLDP_met(rtb_Switch_kk[0]);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch5/Functionality'/Switch' incorporates:
                                                       *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Constant4'/Constant'
                                                       *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Constant5'/Constant'
                                                       *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/P_LDPSA_VelXHyst_mps4'/Constant'
                                                       *  DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/OR/Functionality'/Data Type Conversion'
                                                       *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/OR/Functionality'/OR'
                                                       *  Selector: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/Selector2'
                                                       *  Selector: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/Selector3'
                                                       */
    if (((sint32)GET_P_DPLSIA_LaneWidthSIFOn_bool()) != 0) {
        rtb_VectorConcatenate_d[3] = (uint8)((((sint32)rtb_Switch_mu[1]) != 0) || (((sint32)rtb_Switch_mu[0]) != 0));
    } else {
        rtb_VectorConcatenate_d[3] = (uint8)rtb_Switch_mu[0];
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/C_LCF_AclXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/C_LCF_AclXMin_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/Add4/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity'/Unit Delay3'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > GET_P_DPLSIA_AclXMin_mps2()) {
        rtb_Switch3 = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < (GET_P_DPLSIA_AclXMin_mps2() - GET_P_DPLSIA_AclXHyst_mps2())) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3 = 0U;
    } else {
        rtb_Switch3 = DW_dplsia_UnitDelay3_DSTATE;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS2/Functionality'/Switch3' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/C_LCF_AclXHyst_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/C_LCF_AclXMax_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity'/Unit Delay1'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > (GET_P_DPLSIA_AclXMax_mps2() + GET_P_DPLSIA_AclXHyst_mps2())) {
        rtb_Switch3_mc = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < GET_P_DPLSIA_AclXMax_mps2()) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_Switch3_mc = 0U;
    } else {
        rtb_Switch3_mc = DW_dplsia_UnitDelay1_DSTATE_p;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_lb = (uint8)(!(((sint32)rtb_Switch3_mc) != 0));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/Logical Operator2/Functionality'/AND'
         */
    rtb_DataTypeConversion_lb = (uint8)((((sint32)rtb_DataTypeConversion_lb) != 0) && (((sint32)rtb_Switch3) != 0));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_d[4] = (uint8)(!(((sint32)rtb_DataTypeConversion_lb) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/P_LDPSA_VelXMax_mps'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_d) != 0) {
        tmp_0 = GET_P_DPLSIA_StrWhlAngleLDPHyst_deg() + GET_P_DPLSIA_StrWhlAngleLDPMax_deg();
    } else {
        tmp_0 = GET_P_DPLSIA_StrWhlAngleLDPMax_deg();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngle_deg'
         */
    rtb_LT_fr = (uint8)(f32_abs_f32(GET_S_LCFRCV_SteerWAngle_deg()) < tmp_0);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_d[1] = (uint8)(!(((sint32)rtb_LT_fr) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/P_LDPSA_VelXMax_mps'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_h) != 0) {
        tmp_0 = GET_P_DPLSIA_StrWhlAngSpLDPHys_degps() + GET_P_DPLSIA_StrWhlAngSpLDPMax_degps();
    } else {
        tmp_0 = GET_P_DPLSIA_StrWhlAngSpLDPMax_degps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngleRate_degps'
         */
    rtb_LT_lt = (uint8)(f32_abs_f32(GET_S_LCFRCV_SteerWAngleRate_degps()) < tmp_0);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_d[2] = (uint8)(!(((sint32)rtb_LT_lt) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/P_LDPSA_VelXMax_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/P_LDPSA_VelXMin_mps'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Add/Functionality'/Sum'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_ly) != 0) {
        tmp_0 = GET_P_DPLSIA_VelDispLDPMin_kph() - GET_P_DPLSIA_VelDispLDPHyst_kph();
        rtb_Switch_ar = GET_P_DPLSIA_VelDispLDPHyst_kph() + GET_P_DPLSIA_VelDispLDPMax_kph();
    } else {
        tmp_0 = GET_P_DPLSIA_VelDispLDPMin_kph();
        rtb_Switch_ar = GET_P_DPLSIA_VelDispLDPMax_kph();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_fm = (uint8)((GET_S_LCFRCV_VDy_VehVelocity_kph() > tmp_0) && (GET_S_LCFRCV_VDy_VehVelocity_kph() < rtb_Switch_ar));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_d[0] = (uint8)(!(((sint32)rtb_GT_fm) != 0));
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP'/Unit_Delay1'
         */
    for (i = 0; i < 8; i++) {
        rtb_LogicalOperator_o[i] = (uint8)((((sint32)rtb_VectorConcatenate_d[i]) != 0) || (DW_dplsia_Unit_Delay1_DSTATE[i] > 0.0F));
    }
    /* End of Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Logical Operator' */
    /* S-Function (sfun_setbit): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_LogicalOperator_o[0];
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
        rtb_DataTypeConversion_lb = temp;
    }
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch1'/copy1' */
    SET_S_DPLSIA_LnBndLeValidLDP_bool(rtb_LogicalOperator);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch10'/copy1' */
    SET_S_DPLSIA_VelLatRiLDP_mps(rtb_Switch_ao);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch12'/copy1' */
    SET_D_DPLSIA_LnBndRiCancelValidLDP_bool(rtb_EQ_ed);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch13'/copy1' */
    SET_D_DPLSIA_LnBndLeCancelValidLDP_bool(rtb_Switch_hb);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch2'/copy1' */
    SET_S_DPLSIA_DlcLeLDP_met(rtb_Switch_in);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch3'/copy1' */
    SET_S_DPLSIA_DlcRiLDP_met(rtb_Div);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch6'/copy1' */
    SET_S_DPLSIA_LnBndRiValidLDP_bool(rtb_LogicalOperator_b);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch7'/copy1' */
    SET_S_DPLSIA_SpecificLDP_btf(rtb_DataTypeConversion_lb);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/branch9'/copy1' */
    SET_S_DPLSIA_VelLatLeLDP_mps(rtb_Switch);
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Relational Operator7/Functionality'/EQ' incorporates:
                                                *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Application Parameter2'/Constant'
                                                *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Constant5'/Constant'
                                                *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
                                                *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND2/Functionality'/AND'
                                                */
    rtb_EQ_ed = (uint8)((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Application Parameter5'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Constant6'/Constant'
         *  DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND4/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQuSIF_btf'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Relational Operator5/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND1/Functionality'/AND'
         */
    if (((sint32)GET_P_DPLSIA_SafetyIfaceLDWOn_bool()) != 0) {
        rtb_EQ_ed = (uint8)(((((sint32)GET_S_ABPLBP_LeLnInvalidQuSIF_btf()) & ((sint32)GET_P_DPLSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_ed) != 0));
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPLSMW_DangerousSide_nu'
         */
    rtb_EQ_dr = (uint8)(((sint32)GET_S_DPLSMW_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE)));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Application Parameter1'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/AND4/Functionality'/AND'
         */
    rtb_DataTypeConversion_py = (uint8)((((sint32) GET_P_DPLSIA_SafetyIfaceLDWOn_bool()) != 0) && (((sint32)rtb_EQ_dr) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         */
    if (((sint32)rtb_DataTypeConversion_py) != 0) {
        rtb_Sum_mh = GET_S_ABPLBP_LeLnClthHeadingSIF_rad();
    } else {
        rtb_Sum_mh = GET_S_ABPLBP_LeLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_n) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWMin_rad() - GET_P_DPLSIA_HeadAngThresLDWHyst_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWMin_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Relational Operator/Functionality'/GT' incorporates:
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_lb = (uint8)((-rtb_Sum_mh) > tmp_0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_n) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWHyst_rad() + GET_P_DPLSIA_HeadAngThresLDWMax_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWMax_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger/Neg/Functionality'/Unary Minus'
         */
    rtb_LogicalOperator = (uint8)((((sint32)rtb_DataTypeConversion_lb) != 0) && ((-rtb_Sum_mh) < tmp_0));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND7/Functionality'/AND'
         */
    rtb_EQ_ed = (uint8)((((sint32)rtb_EQ_ed) != 0) && (((sint32) rtb_LogicalOperator) != 0));
    /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_oa = F32_PTR_IP1D (GETA_Y_DPLSIA_VXCrvThresLDWMax_1pm(), &x_dps);
    }
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_ar = rtb_ip_lookup_fxpt_sfun_7_oa;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_la) != 0) {
        /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_DPLSIA_VXCrvThresLDWHyst_1pm(), &x_dps);
        }
        rtb_Switch_ar = rtb_ip_lookup_fxpt_sfun_7_b + rtb_ip_lookup_fxpt_sfun_7_oa;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         */
    if (((sint32)rtb_DataTypeConversion_py) != 0) {
        rtb_Switch = GET_S_ABPLBP_LeLnClthCrvSIF_1pm();
    } else {
        rtb_Switch = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft/Abs/Functionality'/Abs'
         */
    rtb_LogicalOperator_b = (uint8)(f32_abs_f32(rtb_Switch) < rtb_Switch_ar);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_lb = (uint8)((((sint32) GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32) GET_P_DPLSIA_ConstrSiteLDW_bool()) != 0));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_lb = (uint8)(!(((sint32)rtb_DataTypeConversion_lb) != 0));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND5/Functionality'/AND'
         */
    rtb_EQ_ed = (uint8)(((((sint32)rtb_EQ_ed) != 0) && (((sint32) rtb_LogicalOperator_b) != 0)) && (((sint32)rtb_DataTypeConversion_lb) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_j) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWHyst_rad() + GET_P_DPLSIA_HeadAngThresLDWMax_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWMax_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel/Abs/Functionality'/Abs'
         */
    rtb_LT_l = (uint8)(f32_abs_f32(rtb_Sum_mh) < tmp_0);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Constant1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND3/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND6/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Relational Operator1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND13/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/AND8/Functionality'/AND'
         */
    rtb_DataTypeConversion_lb = (uint8)((((((sint32)rtb_LT_l) != 0) && (((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneBridgedBitmask_btm())) != 0))) && (((sint32) rtb_LogicalOperator_b) != 0)) && (((sint32)rtb_DataTypeConversion_lb) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Switch9/Functionality'/Switch' */
    if (((sint32)rtb_EQ_dr) != 0) {
        rtb_Switch_hb = rtb_EQ_ed;
    } else {
        rtb_Switch_hb = rtb_DataTypeConversion_lb;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Switch9/Functionality'/Switch' */
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft'/Unit Delay2'
         */
    rtb_LogicalOperator_l = (uint8)((DW_dplsia_UnitDelay2_DSTATE_i <= 0.0F) && (((sint32)rtb_Switch_hb) != 0));
    /* Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/P_VEH_Width_met'/Constant'
         */
    rtb_Div = GET_P_VEH_Width_met() / 2.0F;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant8'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Add/Functionality'/Sum'
         */
    if (((sint32)rtb_LogicalOperator_l) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch9/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                 */
        if (((sint32)rtb_DataTypeConversion_py) != 0) {
            rtb_Switch = GET_S_ABPLBP_LeLnClthPosY0SIF_met();
        } else {
            rtb_Switch = GET_S_ABPLBP_LeLnClthPosY0_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch9/Functionality'/Switch' */
        rtb_Switch_in = rtb_Switch - rtb_Div;
    } else {
        rtb_Switch_in = 10.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Constant3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND14/Functionality'/AND'
         */
    rtb_EQ_i1 = (uint8)((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Application Parameter5'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Constant8'/Constant'
         *  DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND1/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQuSIF_btf'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Relational Operator8/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND12/Functionality'/AND'
         */
    if (((sint32)GET_P_DPLSIA_SafetyIfaceLDWOn_bool()) != 0) {
        rtb_EQ_i1 = (uint8)(((((sint32)GET_S_ABPLBP_RiLnInvalidQuSIF_btf()) & ((sint32)GET_P_DPLSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_i1) != 0));
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         */
    if (((sint32)rtb_DataTypeConversion_py) != 0) {
        rtb_Switch_ao = GET_S_ABPLBP_RiLnClthHeadingSIF_rad();
    } else {
        rtb_Switch_ao = GET_S_ABPLBP_RiLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Add/Functionality'/Sum'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_kx) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWMin_rad() - GET_P_DPLSIA_HeadAngThresLDWHyst_rad();
        rtb_Switch_ar = GET_P_DPLSIA_HeadAngThresLDWHyst_rad() + GET_P_DPLSIA_HeadAngThresLDWMax_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWMin_rad();
        rtb_Switch_ar = GET_P_DPLSIA_HeadAngThresLDWMax_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_gk = (uint8)((rtb_Switch_ao > tmp_0) && (rtb_Switch_ao < rtb_Switch_ar));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND4/Functionality'/AND'
         */
    rtb_EQ_i1 = (uint8)((((sint32)rtb_EQ_i1) != 0) && (((sint32)rtb_GT_gk) != 0));
    /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D (GETA_Y_DPLSIA_VXCrvThresLDWMax_1pm(), &x_dps);
    }
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_ar = rtb_ip_lookup_fxpt_sfun_7_e;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_id) != 0) {
        /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Y_DPLSIA_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D (GETA_Y_DPLSIA_VXCrvThresLDWHyst_1pm(), &x_dps);
        }
        rtb_Switch_ar = rtb_ip_lookup_fxpt_sfun_7_n + rtb_ip_lookup_fxpt_sfun_7_e;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    if (((sint32)rtb_DataTypeConversion_py) != 0) {
        rtb_Switch = GET_S_ABPLBP_RiLnClthCrvSIF_1pm();
    } else {
        rtb_Switch = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight/Abs/Functionality'/Abs'
         */
    rtb_LT_h = (uint8)(f32_abs_f32(rtb_Switch) < rtb_Switch_ar);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/NOT2/Functionality'/NOT'
         */
    rtb_EQ = (uint8)(!((((sint32)GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32)GET_P_DPLSIA_ConstrSiteLDW_bool()) != 0)));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND9/Functionality'/AND'
         */
    rtb_EQ_i1 = (uint8)(((((sint32)rtb_EQ_i1) != 0) && (((sint32)rtb_LT_h) != 0)) && (((sint32)rtb_EQ) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_e) != 0) {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWHyst_rad() + GET_P_DPLSIA_HeadAngThresLDWMax_rad();
    } else {
        tmp_0 = GET_P_DPLSIA_HeadAngThresLDWMax_rad();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel/Abs/Functionality'/Abs'
         */
    rtb_LT_eo = (uint8)(f32_abs_f32(rtb_Switch_ao) < tmp_0);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND10/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Constant1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND10/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND2/Functionality'/AND'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Relational Operator2/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND11/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/AND8/Functionality'/AND'
         */
    rtb_DataTypeConversion_b = (uint8)((((((sint32)rtb_LT_eo) != 0) && (((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPLSIA_LaneBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_h) != 0)) && (((sint32)rtb_EQ) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_EQ_dr) != 0) {
        rtb_EQ = rtb_EQ_i1;
    } else {
        rtb_EQ = rtb_DataTypeConversion_b;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Switch1/Functionality'/Switch' */
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight'/Unit Delay2'
         */
    rtb_LogicalOperator_n = (uint8)((DW_dplsia_UnitDelay2_DSTATE_m <= 0.0F) && (((sint32)rtb_EQ) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Add1/Functionality'/Sum'
         */
    if (((sint32)rtb_LogicalOperator_n) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                 */
        if (((sint32)rtb_DataTypeConversion_py) != 0) {
            rtb_Switch = GET_S_ABPLBP_RiLnClthPosY0SIF_met();
        } else {
            rtb_Switch = GET_S_ABPLBP_RiLnClthPosY0_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch1/Functionality'/Switch' */
        rtb_Div += rtb_Switch;
    } else {
        rtb_Div = -10.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant7'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/P_VEH_Width_met1'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/LT1/Functionality'/LT'
         */
    rtb_sfun_setbit = (uint8)(((((sint32)rtb_LogicalOperator_n) != 0) && (rtb_Div < 0.0F)) && (rtb_Switch_ao > GET_P_DPLSIA_TlcHeadAngThres_rad()));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant9'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Product/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator_l) != 0) {
        rtb_Switch = GET_S_LCFRCV_VehVelX_mps() * rtb_Sum_mh;
    } else {
        rtb_Switch = 0.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant10'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Product2/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator_n) != 0) {
        rtb_Switch_ao *= GET_S_LCFRCV_VehVelX_mps();
    } else {
        rtb_Switch_ao = 0.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant6'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/P_VEH_Width_met2'/Constant'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/AND3/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Neg/Functionality'/Unary Minus'
         */
    if (((((sint32)rtb_LogicalOperator_l) != 0) && (rtb_Switch_in > 0.0F)) && (rtb_Sum_mh < (-GET_P_DPLSIA_TlcHeadAngThres_rad()))) {
        /* Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Abs/Functionality'/Abs' */
        rtb_Switch_ar = f32_abs_f32(rtb_Switch);
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide1/In3'/Constant'
                 *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Div'
                 */
        if (rtb_Switch_ar != 0.0F) {
            rtb_Switch_ar = rtb_Switch_in / rtb_Switch_ar;
        } else {
            rtb_Switch_ar = 10.0F;
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_ar = 10.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch4'/copy1' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant1'/Constant'
         *  MinMax: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Min/Functionality'/Min'
         */
    SET_S_DPLSIA_TlcLeLDW_sec(f32_min_f32_f32(rtb_Switch_ar, 10.0F));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch3/Functionality'/Switch' incorporates:
                                                                        *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant2'/Constant'
                                                                        */
    if (((sint32)rtb_sfun_setbit) != 0) {
        /* Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Abs2/Functionality'/Abs' */
        rtb_Switch_ar = f32_abs_f32(rtb_Switch_ao);
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide2/In3'/Constant'
                 *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Div'
                 *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Neg1/Functionality'/Unary Minus'
                 */
        if (rtb_Switch_ar != 0.0F) {
            rtb_Switch_ar = (-rtb_Div) / rtb_Switch_ar;
        } else {
            rtb_Switch_ar = 10.0F;
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_ar = 10.0F;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch5'/copy1' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Constant2'/Constant'
         *  MinMax: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/DlcTlcCalculation/Min1/Functionality'/Min'
         */
    SET_S_DPLSIA_TlcRiLDW_sec(f32_min_f32_f32(rtb_Switch_ar, 10.0F));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch6/Functionality'/Switch' incorporates:
                                                                        *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Application Parameter2'/Constant'
                                                                        *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
                                                                        *  Inport: '<Root>/S_ABPLBP_UncoupledLaneWidth_met'
                                                                        */
    if (((sint32)GET_P_DPLSIA_UncoupledLWEnable_bool()) != 0) {
        rtb_Switch_ny[1] = GET_S_ABPLBP_UncoupledLaneWidth_met();
    } else {
        rtb_Switch_ny[1] = GET_S_ABPLBP_CoupledLaneWidth_met();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneBoundaryInterface/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_hb) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft'/Unit Delay2'
                 */
        if (DW_dplsia_UnitDelay2_DSTATE_i > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsia_UnitDelay2_DSTATE_i -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/Application Parameter4'/Constant'
                 */
        DW_dplsia_UnitDelay2_DSTATE_i = GET_P_DPLSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/branch2'/copy1' */
    SET_D_DPLSIA_LnBndLeTrgValidLDW_bool(rtb_EQ_ed);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight'/Unit Delay2'
                 */
        if (DW_dplsia_UnitDelay2_DSTATE_m > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsia_UnitDelay2_DSTATE_m -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/Application Parameter3'/Constant'
                 */
        DW_dplsia_UnitDelay2_DSTATE_m = GET_P_DPLSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/branch1'/copy1' */
    SET_D_DPLSIA_LnBndRiTrgValidLDW_bool(rtb_EQ_i1);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/AND/Functionality'/Data Type Conversion' incorporates:
                                                       *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/AND/Functionality'/AND'
                                                       */
    rtb_sfun_setbit = (uint8)((((sint32)rtb_LogicalOperator_l) != 0) && (((sint32)rtb_LogicalOperator_n) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch9/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/from_data_definition1'/state_source'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch10/Functionality'/Switch'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch11/Functionality'/Switch'
         */
    if (((sint32)rtb_sfun_setbit) != 0) {
        SET_S_DPLSIA_LnBndValidLDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE));
    } else if (((sint32)rtb_LogicalOperator_l) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch10/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/from_data_definition2'/state_source'
                 */
        SET_S_DPLSIA_LnBndValidLDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY));
    } else if (((sint32)rtb_LogicalOperator_n) != 0) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch11/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch10/Functionality'/Switch'
                 */
        SET_S_DPLSIA_LnBndValidLDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY));
    } else {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch10/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch11/Functionality'/Switch'
                 */
        SET_S_DPLSIA_LnBndValidLDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID));
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LnBndValidLDW/Switch9/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1_g[0] = rtb_DataTypeConversion_k;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant2'/Constant'
         */
    rtb_VectorConcatenate1_g[2] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector Concatenate1In4' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant2'/Constant'
         */
    rtb_VectorConcatenate1_g[3] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector Concatenate1In5' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant2'/Constant'
         */
    rtb_VectorConcatenate1_g[4] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector Concatenate1In6' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant2'/Constant'
         */
    rtb_VectorConcatenate1_g[5] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector Concatenate1In7' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant2'/Constant'
         */
    rtb_VectorConcatenate1_g[6] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector Concatenate1In8' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant2'/Constant'
         */
    rtb_VectorConcatenate1_g[7] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_h[0] = rtb_DataTypeConversion_bp;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant3'/Constant'
         */
    rtb_VectorConcatenate_h[2] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant3'/Constant'
         */
    rtb_VectorConcatenate_h[3] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector ConcatenateIn5' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant3'/Constant'
         */
    rtb_VectorConcatenate_h[4] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant3'/Constant'
         */
    rtb_VectorConcatenate_h[5] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant3'/Constant'
         */
    rtb_VectorConcatenate_h[6] = 0U;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/Constant3'/Constant'
         */
    rtb_VectorConcatenate_h[7] = 0U;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_le) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDWMin_mps() - GET_P_DPLSIA_VelLatThresLDWHyst_mps();
        rtb_Switch_ar = GET_P_DPLSIA_VelLatThresLDWHyst_mps() + GET_P_DPLSIA_VelLatThresLDWMax_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDWMin_mps();
        rtb_Switch_ar = GET_P_DPLSIA_VelLatThresLDWMax_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_Switch_hb = (uint8)(((-rtb_Switch) > tmp_0) && ((-rtb_Switch) < rtb_Switch_ar));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/P_LDPSA_VelXMin_mps5'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/P_LDPSA_VelXMin_mps4'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft'/Unit Delay1'
         */
    if (((sint32)DW_dplsia_UnitDelay1_DSTATE_l) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDWHyst_mps() + GET_P_DPLSIA_VelLatThresLDWMax_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDWMax_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Abs/Functionality'/Abs'
         *  UnaryMinus: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_bp = (uint8)(f32_abs_f32(-rtb_Switch) < tmp_0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Switch2/Functionality'/Switch' */
    if (((sint32)rtb_EQ_dr) != 0) {
        rtb_sfun_setbit = rtb_Switch_hb;
    } else {
        rtb_sfun_setbit = rtb_DataTypeConversion_bp;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[1] = (uint8)(!(((sint32)rtb_sfun_setbit) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_ix) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDWMin_mps() - GET_P_DPLSIA_VelLatThresLDWHyst_mps();
        rtb_Switch_ar = GET_P_DPLSIA_VelLatThresLDWHyst_mps() + GET_P_DPLSIA_VelLatThresLDWMax_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDWMin_mps();
        rtb_Switch_ar = GET_P_DPLSIA_VelLatThresLDWMax_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Relational Operator1/Functionality'/LT'
         */
    rtb_EQ_ed = (uint8)((rtb_Switch_ao > tmp_0) && (rtb_Switch_ao < rtb_Switch_ar));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/P_LDPSA_VelXMin_mps5'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight'/Unit Delay1'
         */
    if (((sint32)DW_dplsia_UnitDelay1_DSTATE_b) != 0) {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDWHyst_mps() + GET_P_DPLSIA_VelLatThresLDWMax_mps();
    } else {
        tmp_0 = GET_P_DPLSIA_VelLatThresLDWMax_mps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Abs/Functionality'/Abs'
         */
    rtb_EQ_i1 = (uint8)(f32_abs_f32(rtb_Switch_ao) < tmp_0);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Switch2/Functionality'/Switch' */
    if (((sint32)rtb_EQ_dr) != 0) {
        rtb_EQ_dr = rtb_EQ_ed;
    } else {
        rtb_EQ_dr = rtb_EQ_i1;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate1_g[1] = (uint8)(!(((sint32)rtb_EQ_dr) != 0));
    /* S-Function (sfun_setbit): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit = temp;
    }
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/set_bit/Functionality'/DTC_out' */
    SET_S_DPLSIA_SideCondLDWLe_btf(rtb_sfun_setbit);
    /* S-Function (sfun_setbit): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate1_g[0];
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
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/set_bit1/Functionality'/DTC_out' */
    SET_S_DPLSIA_SideCondLDWRi_btf(rtb_sfun_setbit);
    /* Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/Abs/Functionality'/Abs' incorporates:
                                                       *  Inport: '<Root>/S_LCFRCV_VehAclY_mps2'
                                                       */
    rtb_Switch_ar = f32_abs_f32(GET_S_LCFRCV_VehAclY_mps2());
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/C_LCF_AclYHyst_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/C_LCF_AclYMax_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity'/Unit Delay1'
         */
    if (rtb_Switch_ar > (GET_P_DPLSIA_AclYLDWMax_mps2() + GET_P_DPLSIA_AclYLDWHyst_mps2())) {
        rtb_sfun_setbit = 1U;
    } else if (rtb_Switch_ar < GET_P_DPLSIA_AclYLDWMax_mps2()) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_sfun_setbit = 0U;
    } else {
        rtb_sfun_setbit = DW_dplsia_UnitDelay1_DSTATE_f;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity'/Unit Delay1' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    DW_dplsia_UnitDelay1_DSTATE_f = rtb_sfun_setbit;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LatAclValidity/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate_e[5] = rtb_sfun_setbit;
    /* Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         */
    rtb_Switch_ar = f32_abs_f32(GET_S_LCFRCV_VehCrv_1pm());
    /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_es = F32_PTR_IP1D (GETA_Y_DPLSIA_VXVehCrvThresLDWMax_1pm(), &x_dps);
    }
    /* S-Function Block sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_DPLSIA_VXVehCrvThresLDWHyst_1pm(), &x_dps);
    }
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Relational Operator1'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature'/Unit Delay1'
         */
    if (rtb_Switch_ar > (rtb_ip_lookup_fxpt_sfun_7_es + rtb_ip_lookup_fxpt_sfun_7_p)) {
        rtb_sfun_setbit = 1U;
    } else if (rtb_Switch_ar < rtb_ip_lookup_fxpt_sfun_7_es) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_sfun_setbit = 0U;
    } else {
        rtb_sfun_setbit = DW_dplsia_UnitDelay1_DSTATE_o;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch3' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature'/Unit Delay1' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    DW_dplsia_UnitDelay1_DSTATE_o = rtb_sfun_setbit;
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate_e[6] = rtb_sfun_setbit;
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LDWSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LDWSwitch/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LDWSwitch/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_LDWSwitch_bool'
         */
    if (((sint32)GET_P_DPLSMW_LDWSwitchEnable_bool()) != 0) {
        rtb_sfun_setbit = GET_S_LCFRCV_LDWSwitch_bool();
    } else {
        rtb_sfun_setbit = GET_P_DPLSMW_LDWSwitch_bool();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LDWSwitch/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LDWSwitch/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LDWSwitch/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[7] = (uint8)(!(((sint32)rtb_sfun_setbit) != 0));
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Add2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXMin_mps'/Constant'
         */
    rtb_Switch_ar = GET_P_DPLSIA_LaneWidthLDWMin_met() - GET_P_DPLSIA_LaneWidthLDWHyst_met();
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Add3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXMax_mps'/Constant'
         */
    rtb_Sum_mh = GET_P_DPLSIA_LaneWidthLDWHyst_met() + GET_P_DPLSIA_LaneWidthLDWMax_met();
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         */
    rtb_Switch_ny[0] = GET_S_ABPLBP_LaneWidth_met();
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator6/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXHyst_mps5'/Constant'
         */
    tmp = (uint8)(((sint32)GET_P_DPLSIA_LaneWidthWideLn_bool()) != 0);
    /* Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator5/Functionality'/AND' */
    rtb_Switch_pz = (uint8)((((sint32)rtb_DataTypeConversion_lb) != 0) && (((sint32)rtb_DataTypeConversion_b) != 0));
    for (i = 0; i < 2; i++) {
        /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Relational Operator3/Functionality'/LT' */
        rtb_Switch_i = rtb_Switch_ny[i];
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXMax_mps'/Constant'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth'/Unit Delay1'
                 */
        if (((sint32)DW_dplsia_UnitDelay1_DSTATE_jp[i]) != 0) {
            tmp_0 = rtb_Sum_mh;
        } else {
            tmp_0 = GET_P_DPLSIA_LaneWidthLDWMax_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch4/Functionality'/Switch' */
        /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Relational Operator3/Functionality'/LT' */
        rtb_EQ = (uint8)(rtb_Switch_ny[i] < tmp_0);
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXMin_mps'/Constant'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth'/Unit Delay1'
                 */
        if (((sint32)DW_dplsia_UnitDelay1_DSTATE_jp[i]) != 0) {
            tmp_0 = rtb_Switch_ar;
        } else {
            tmp_0 = GET_P_DPLSIA_LaneWidthLDWMin_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch6/Functionality'/Switch' */
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator4/Functionality'/AND'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Relational Operator2/Functionality'/GT'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Relational Operator3/Functionality'/LT'
                 */
        rtb_DataTypeConversion_k = (uint8)((rtb_Switch_ny[i] > tmp_0) && (((sint32) rtb_EQ) != 0));
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator7/Functionality'/NOT'
                 */
        rtb_EQ = (uint8)(!(((sint32)rtb_EQ) != 0));
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator6/Functionality'/AND'
                 */
        rtb_EQ = (uint8)(((sint32)tmp) && (((sint32)rtb_EQ) != 0));
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator8/Functionality'/NOT'
                 */
        rtb_EQ = (uint8)(!(((sint32)rtb_EQ) != 0));
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator5/Functionality'/AND'
                 */
        rtb_EQ = (uint8)(((sint32)rtb_Switch_pz) && (((sint32)rtb_EQ) != 0));
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Constant1'/Constant'
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXHyst_mps4'/Constant'
                 *  DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator3/Functionality'/Data Type Conversion'
                 *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator3/Functionality'/NOT'
                 *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch7/Functionality'/Switch'
                 */
        if (((sint32)rtb_EQ) != 0) {
            rtb_DataTypeConversion_fb[i] = (sint8)(!(((sint32)rtb_DataTypeConversion_k) != 0));
        } else {
            rtb_DataTypeConversion_fb[i] = 0;
            rtb_Switch_i = GET_P_DPLSIA_LaneWidthWideLnDef_met();
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch5/Functionality'/Switch' */
        /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Logical Operator4/Functionality'/Data Type Conversion' */
        rtb_Switch_mu[i] = (sint8)rtb_DataTypeConversion_k;
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch7/Functionality'/Switch' */
        rtb_Switch_ny[i] = rtb_Switch_i;
    }
    /* Selector: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth'/Selector1' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Constant3'/Constant'
         */
    SET_S_DPLSIA_LaneWidthLDW_met(rtb_Switch_ny[0]);
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch1/Functionality'/Switch' incorporates:
                                                       *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Constant4'/Constant'
                                                       *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Constant5'/Constant'
                                                       *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/P_LDPSA_VelXHyst_mps2'/Constant'
                                                       *  DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/OR/Functionality'/Data Type Conversion'
                                                       *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/OR/Functionality'/OR'
                                                       *  Selector: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth'/Selector2'
                                                       *  Selector: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth'/Selector3'
                                                       */
    if (((sint32)GET_P_DPLSIA_LaneWidthSIFOn_bool()) != 0) {
        rtb_VectorConcatenate_e[3] = (uint8)((((sint32)rtb_DataTypeConversion_fb[1]) != 0) || (((sint32)rtb_DataTypeConversion_fb[0]) != 0));
    } else {
        rtb_VectorConcatenate_e[3] = (uint8)rtb_DataTypeConversion_fb[0];
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/C_LCF_AclXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/C_LCF_AclXMin_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/Add4/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity'/Unit Delay3'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > GET_P_DPLSIA_AclXLDWMin_mps2()) {
        rtb_EQ_dr = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < (GET_P_DPLSIA_AclXLDWMin_mps2() - GET_P_DPLSIA_AclXLDWHyst_mps2())) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_EQ_dr = 0U;
    } else {
        rtb_EQ_dr = DW_dplsia_UnitDelay3_DSTATE_e;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS2/Functionality'/Switch3' */
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/C_LCF_AclXHyst_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/C_LCF_AclXMax_mps2'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity'/Unit Delay1'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > (GET_P_DPLSIA_AclXLDWMax_mps2() + GET_P_DPLSIA_AclXLDWHyst_mps2())) {
        rtb_DataTypeConversion_k = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < GET_P_DPLSIA_AclXLDWMax_mps2()) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_DataTypeConversion_k = 0U;
    } else {
        rtb_DataTypeConversion_k = DW_dplsia_UnitDelay1_DSTATE_b5;
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/NOT2/Functionality'/NOT'
         */
    rtb_sfun_setbit = (uint8)(!(((sint32)rtb_DataTypeConversion_k) != 0));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/Logical Operator2/Functionality'/AND'
         */
    rtb_sfun_setbit = (uint8)((((sint32)rtb_sfun_setbit) != 0) && (((sint32) rtb_EQ_dr) != 0));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[4] = (uint8)(!(((sint32)rtb_sfun_setbit) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/P_LDPSA_VelXMax_mps'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_jc) != 0) {
        tmp_0 = GET_P_DPLSIA_StrWhlAngleLDWHyst_deg() + GET_P_DPLSIA_StrWhlAngleLDWMax_deg();
    } else {
        tmp_0 = GET_P_DPLSIA_StrWhlAngleLDWMax_deg();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngle_deg'
         */
    rtb_EQ = (uint8)(f32_abs_f32(GET_S_LCFRCV_SteerWAngle_deg()) < tmp_0);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[1] = (uint8)(!(((sint32)rtb_EQ) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/P_LDPSA_VelXMax_mps'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_c) != 0) {
        tmp_0 = GET_P_DPLSIA_StrWhlAngSpLDWHys_degps() + GET_P_DPLSIA_StrWhlAngSpLDWMax_degps();
    } else {
        tmp_0 = GET_P_DPLSIA_StrWhlAngSpLDWMax_degps();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngleRate_degps'
         */
    rtb_DataTypeConversion_py = (uint8)(f32_abs_f32 (GET_S_LCFRCV_SteerWAngleRate_degps()) < tmp_0);
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[2] = (uint8)(!(((sint32)rtb_DataTypeConversion_py) != 0));
    /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/P_LDPSA_VelXMax_mps'/Constant'
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/P_LDPSA_VelXMin_mps'/Constant'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Add/Functionality'/Sum'
         *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp'/Unit Delay2'
         */
    if (((sint32)DW_dplsia_UnitDelay2_DSTATE_c5) != 0) {
        tmp_0 = GET_P_DPLSIA_VelDispLDWMin_kph() - GET_P_DPLSIA_VelDispLDWHyst_kph();
        rtb_Switch_ar = GET_P_DPLSIA_VelDispLDWHyst_kph() + GET_P_DPLSIA_VelDispLDWMax_kph();
    } else {
        tmp_0 = GET_P_DPLSIA_VelDispLDWMin_kph();
        rtb_Switch_ar = GET_P_DPLSIA_VelDispLDWMax_kph();
    }
    /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_p = (uint8)((GET_S_LCFRCV_VDy_VehVelocity_kph() > tmp_0) && (GET_S_LCFRCV_VDy_VehVelocity_kph() < rtb_Switch_ar));
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[0] = (uint8)(!(((sint32)rtb_GT_p) != 0));
    /* S-Function (sfun_setbit): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit = temp;
    }
    /* DataTypeConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/set_bit/Functionality'/DTC_out' */
    SET_S_DPLSIA_SpecificLDW_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch1'/copy1' */
    SET_D_DPLSIA_LnBndRiCancelValidLDW_bool(rtb_DataTypeConversion_b);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch10'/copy1' */
    SET_S_DPLSIA_VelLatRiLDW_mps(rtb_Switch_ao);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch2'/copy1' */
    SET_S_DPLSIA_DlcLeLDW_met(rtb_Switch_in);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch3'/copy1' */
    SET_S_DPLSIA_DlcRiLDW_met(rtb_Div);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch6'/copy1' */
    SET_D_DPLSIA_LnBndLeCancelValidLDW_bool(rtb_DataTypeConversion_lb);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch7'/copy1' */
    SET_S_DPLSIA_LnBndLeValidLDW_bool(rtb_LogicalOperator_l);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch8'/copy1' */
    SET_S_DPLSIA_LnBndRiValidLDW_bool(rtb_LogicalOperator_n);
    /* SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/branch9'/copy1' */
    SET_S_DPLSIA_VelLatLeLDW_mps(rtb_Switch);
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Add1/Functionality'/Sum' incorporates:
                                                *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                                */
    rtb_Abs_g -= GET_S_LCFRCV_SysCycleTimeSen_sec();
    /* Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Add1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Switch_f -= GET_S_LCFRCV_SysCycleTimeSen_sec();
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingTrigger'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_o = rtb_GT_k;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/CurvatureLeft'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_g = rtb_LT_ai;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingLeft/HeadingCancel'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_f = rtb_LT_h1;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingTrigger'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_oc = rtb_GT_d;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/CurvatureRight'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_b = rtb_LT_cc;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/LaneMarkingValidationLDP/LaneMarkingRight/HeadingCancel'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_k = rtb_LT_lr;
    /* S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsia_Unit_Delay_DSTATE = rtb_DataTypeConversion_ae;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingRi/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi '/Unit Delay1' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Constant1'/Constant'
         *  MinMax: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerRi /Max/Functionality'/Max'
         */
    DW_dplsia_UnitDelay1_DSTATE = f32_max_f32_f32(rtb_Switch_f, 0.0F);
    /* S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsia_Unit_Delay_DSTATE_p = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/EdgeRisingLe/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe'/Unit Delay1' incorporates:
         *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Constant1'/Constant'
         *  MinMax: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/TurnSignal/FollowUpTimerLe/Max/Functionality'/Max'
         */
    DW_dplsia_UnitDelay1_DSTATE_c = f32_max_f32_f32(rtb_Abs_g, 0.0F);
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_mk = rtb_DataTypeConversion_fu;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatLeft'/Unit Delay1' */
    DW_dplsia_UnitDelay1_DSTATE_n = rtb_LT_m2;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_a = rtb_DataTypeConversion_o;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SideConditionsLDP/VelLatRight'/Unit Delay1' */
    DW_dplsia_UnitDelay1_DSTATE_j = rtb_LT_aw;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/Unit Delay2' */
    for (i = 0; i < 2; i++) {
        DW_dplsia_UnitDelay2_DSTATE_p[i] = (uint8)rtb_DataTypeConversion_g[i];
    }
    /* End of Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LaneWidth'/Unit Delay2' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity'/Unit Delay3' */
    DW_dplsia_UnitDelay3_DSTATE = rtb_Switch3;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/LongAclValidity'/Unit Delay1' */
    DW_dplsia_UnitDelay1_DSTATE_p = rtb_Switch3_mc;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngle'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_d = rtb_LT_fr;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/SteeringWheelAngleSpeed'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_h = rtb_LT_lt;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP'/Unit_Delay1' */
    for (i = 0; i < 8; i++) {
        /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/P_LDPSA_VelXHyst_mps'/Constant'
                 *  Constant: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Relational Operator'
                 *  Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Switch2'
                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP'/Unit_Delay1'
                 */
        if (((sint32)rtb_VectorConcatenate_d[i]) != 0) {
            DW_dplsia_Unit_Delay1_DSTATE[i] = GET_P_DPLSIA_LDPSpecificDebTime_sec((i));
        } else {
            if (DW_dplsia_Unit_Delay1_DSTATE[i] > 0.0F) {
                /* Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                                 *  UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP'/Unit_Delay1'
                                 */
                DW_dplsia_Unit_Delay1_DSTATE[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
        }
        /* End of Switch: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/TURNOFFDELAYTIME/Functionality'/Switch1' */
    }
    /* End of Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP'/Unit_Delay1' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDP/SpecificConditionsLDP/VelVehDisp'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_ly = rtb_GT_fm;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingTrigger'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_n = rtb_LogicalOperator;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/CurvatureLeft'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_la = rtb_LogicalOperator_b;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingLeft/HeadingCancel'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_j = rtb_LT_l;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingTrigger'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_kx = rtb_GT_gk;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/CurvatureRight'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_id = rtb_LT_h;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/LaneMarkingValidationLDW/LaneMarkingRight/HeadingCancel'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_e = rtb_LT_eo;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_le = rtb_Switch_hb;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatLeft'/Unit Delay1' */
    DW_dplsia_UnitDelay1_DSTATE_l = rtb_DataTypeConversion_bp;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_ix = rtb_EQ_ed;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SideConditionsLDW/VelLatRight'/Unit Delay1' */
    DW_dplsia_UnitDelay1_DSTATE_b = rtb_EQ_i1;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth'/Unit Delay1' */
    for (i = 0; i < 2; i++) {
        DW_dplsia_UnitDelay1_DSTATE_jp[i] = (uint8)rtb_Switch_mu[i];
    }
    /* End of Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LaneWidth'/Unit Delay1' */
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity'/Unit Delay3' */
    DW_dplsia_UnitDelay3_DSTATE_e = rtb_EQ_dr;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/LongAclValidity'/Unit Delay1' */
    DW_dplsia_UnitDelay1_DSTATE_b5 = rtb_DataTypeConversion_k;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngle'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_jc = rtb_EQ;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/SteeringWheelAngleSpeed'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_c = rtb_DataTypeConversion_py;
    /* Update for UnitDelay: 'sda:DPLSIA/DPLSIA/DPLSIA_SenProcess/OPM/M_DPLSIA/DPLSIA_LDW/SpecificConditionsLDW/VelVehDisp'/Unit Delay2' */
    DW_dplsia_UnitDelay2_DSTATE_c5 = rtb_GT_p;
}
#include "Pse_DPLSIA.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
