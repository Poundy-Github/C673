/**************************************************************************
COPYRIGHT (C) $Date: 2019/12/10 13:11:29CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/ALCASA/LCRSIA_SEN/LCRSIA/i/project.pj $
$Log: LCRSIA.c  $
Revision 1.1.1.9 2019/12/10 13:11:29CET Mariut, Felix (uidp0906) 
automatically created
File          : LCRSIA
Generated on  : Tue 10.12.2019 at 13:47:11 (UTC+01:00)
MD5           : [702040967   200051780  4211271924     3882526 0](LCRSIA)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.1012177 (R2016b) Update 7
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "LCRSIA.h"
#include "LCRSIA_private.h"
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
#define LCRSIA_START_SEC_DATA_8
#include "LCRSIA_MemMap.h"
static uint8 DW_lcrsia_UnitDelay2_DSTATE_p;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_j;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_m;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_jw;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_b;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_k;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_p2;
static uint8 DW_lcrsia_UnitDelay1_DSTATE_d;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_kq;
static uint8 DW_lcrsia_UnitDelay1_DSTATE_b;
static uint8 DW_lcrsia_Unit_Delay_DSTATE_l;
static uint8 DW_lcrsia_Unit_Delay_DSTATE_b;
static uint8 DW_lcrsia_UnitDelay1_DSTATE_j;
static uint8 DW_lcrsia_UnitDelay1_DSTATE_jo;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_c[2];
static uint8 DW_lcrsia_UnitDelay3_DSTATE;
static uint8 DW_lcrsia_UnitDelay1_DSTATE_o;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_h;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_o;
static uint8 DW_lcrsia_UnitDelay2_DSTATE_a;
#define LCRSIA_STOP_SEC_DATA_8
#include "LCRSIA_MemMap.h"
#define LCRSIA_START_SEC_DATA_32
#include "LCRSIA_MemMap.h"
static float32 DW_lcrsia_UnitDelay2_DSTATE;
static float32 DW_lcrsia_UnitDelay2_DSTATE_d;
static float32 DW_lcrsia_UnitDelay1_DSTATE;
static float32 DW_lcrsia_UnitDelay1_DSTATE_n;
static float32 DW_lcrsia_Unit_Delay_DSTATE[8];
#define LCRSIA_STOP_SEC_DATA_32
#include "LCRSIA_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:LCRSIA/LCRSIA/INI'/LCRSIA_SenReset'
 * Block description for: 'sda:LCRSIA/LCRSIA/INI'/LCRSIA_SenReset'
 *   X.2.1
 */
#define RUNNABLE_ID RUNNABLE_ID_LCRSIA_SenReset
#include "Pse_LCRSIA.h"
/* Short description:  */
void LCRSIA_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant'/Constant' */
    SET_S_LCRSIA_LnBndValidALCA_nu(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant1'/Constant' */
    SET_S_LCRSIA_LnBndLeValidALCA_bool(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant10'/Constant' */
    SET_S_LCRSIA_TlcRiALCA_sec(0.0F);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant11'/Constant' */
    SET_S_LCRSIA_VelLatLeALCA_mps(0.0F);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant12'/Constant' */
    SET_S_LCRSIA_VelLatRiALCA_mps(0.0F);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant13'/Constant' */
    SET_S_LCRSIA_SideCondALCALe_btf(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant14'/Constant' */
    SET_S_LCRSIA_SideCondALCARi_btf(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant15'/Constant' */
    SET_S_LCRSIA_SpecificALCA_btf(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant16'/Constant' */
    SET_S_LCRSIA_LaneWidth_met(0.0F);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant17'/Constant' */
    SET_S_LCRSIA_TgtCntrLnEnable_bool(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant18'/Constant' */
    SET_S_LCRSIA_CurveTypeLe_enum(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant19'/Constant' */
    SET_S_LCRSIA_CurveTypeRi_enum(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant2'/Constant' */
    SET_S_LCRSIA_LnBndRiValidALCA_bool(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant3'/Constant' */
    SET_D_LCRSIA_LnBndLeTrgValidALCA_bool(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant4'/Constant' */
    SET_D_LCRSIA_LnBndRiTrgValidALCA_bool(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant5'/Constant' */
    SET_D_LCRSIA_LnBndLeCancelValidALCA_bool(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant6'/Constant' */
    SET_D_LCRSIA_LnBndRiCancelValidALCA_bool(0U);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant7'/Constant' */
    SET_S_LCRSIA_DlcLeALCA_met(0.0F);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant8'/Constant' */
    SET_S_LCRSIA_DlcRiALCA_met(0.0F);
    /* Constant: 'sda:LCRSIA/LCRSIA/INI/LCRSIA_SenReset/Constant9'/Constant' */
    SET_S_LCRSIA_TlcLeALCA_sec(0.0F);
}
#include "Pse_LCRSIA.h"
/*
 * Output and update for function-call system: 'sda:LCRSIA/LCRSIA'/LCRSIA_SenProcess'
 * Block description for: 'sda:LCRSIA/LCRSIA'/LCRSIA_SenProcess'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_LCRSIA_SenProcess
#include "Pse_LCRSIA.h"
/* Short description:  */
void LCRSIA_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    uint8 rtb_LogicalOperator_p[8];
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate1[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_sfun_setbit_i;
    uint8 rtb_sfun_setbit_m;
    uint8 rtb_EQ;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_GT_h4;
    uint8 rtb_LT_oz;
    uint8 rtb_Selector;
    float32 rtb_Switch;
    uint8 rtb_LT_bg;
    uint8 rtb_DataTypeConversion_d0;
    uint8 rtb_LogicalOperator;
    float32 rtb_Div;
    float32 rtb_Switch_ngc;
    uint8 rtb_EQ_g;
    float32 rtb_Switch_m2n;
    uint8 rtb_GT_m;
    uint8 rtb_LT_n;
    uint8 rtb_LT_c;
    uint8 rtb_DataTypeConversion_iy;
    uint8 rtb_LogicalOperator_b;
    float32 rtb_Switch_bp[2];
    uint8 rtb_LT_oc;
    float32 rtb_Switch_a;
    uint8 rtb_GT_bq;
    uint8 rtb_LT_dp;
    uint8 rtb_EQ_a;
    uint8 rtb_EQ_m2;
    uint8 rtb_VectorConcatenate_e[8];
    float32 rtb_Abs;
    float32 rtb_Sum_ln;
    sint8 rtb_DataTypeConversion_nu[2];
    sint8 rtb_DataTypeConversion_gc[2];
    sint8 rtb_Switch_j[2];
    uint8 rtb_Switch3_j;
    uint8 rtb_LT_p;
    uint8 rtb_LT_l;
    uint8 rtb_GT_c;
    float32 rtb_Abs_lt;
    sint32 i;
    uint8 tmp;
    uint8 rtb_LogicalOperator_1;
    float32 rtb_Switch_i1;
    float32 rtb_DataTypeConversion_8;
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/LT/Functionality'/LT'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch1/Functionality'/Switch'
         *  UnaryMinus: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Neg/Functionality'/Unary Minus'
         */
    if (GET_S_ABPLBP_LeLnClthCrv_1pm() > GET_P_LCRSIA_CurveDetectThreshold_1pm()) {
        /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch19'/copy1' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/from_data_definition2'/state_source'
                 */
        SET_S_LCRSIA_CurveTypeLe_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_INNER));
    } else if (GET_S_ABPLBP_LeLnClthCrv_1pm() < (-GET_P_LCRSIA_CurveDetectThreshold_1pm())) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/from_data_definition3'/state_source'
                 *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch19'/copy1'
                 */
        SET_S_LCRSIA_CurveTypeLe_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_OUTER));
    } else {
        /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch19'/copy1' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/from_data_definition4'/state_source'
                 *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch1/Functionality'/Switch'
                 */
        SET_S_LCRSIA_CurveTypeLe_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_NONE));
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/LT1/Functionality'/LT'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch3/Functionality'/Switch'
         *  UnaryMinus: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Neg3/Functionality'/Unary Minus'
         */
    if (GET_S_ABPLBP_RiLnClthCrv_1pm() < (-GET_P_LCRSIA_CurveDetectThreshold_1pm())) {
        /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch18'/copy1' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/from_data_definition6'/state_source'
                 */
        SET_S_LCRSIA_CurveTypeRi_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_INNER));
    } else if (GET_S_ABPLBP_RiLnClthCrv_1pm() > GET_P_LCRSIA_CurveDetectThreshold_1pm()) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/from_data_definition5'/state_source'
                 *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch18'/copy1'
                 */
        SET_S_LCRSIA_CurveTypeRi_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_OUTER));
    } else {
        /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch18'/copy1' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/from_data_definition1'/state_source'
                 *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch3/Functionality'/Switch'
                 */
        SET_S_LCRSIA_CurveTypeRi_enum(((uint8)E_LCF_CurveType_E_LCF_CURVE_NONE));
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/CurveType/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Constant5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND2/Functionality'/AND'
         */
    rtb_EQ = (uint8)((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_LCRSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Application Parameter6'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Constant6'/Constant'
         *  DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND4/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQuSIF_btf'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Relational Operator5/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND1/Functionality'/AND'
         */
    if (((sint32)GET_P_LCRSIA_SafetyIfaceALCAOn_bool()) != 0) {
        rtb_EQ = (uint8)(((((sint32)GET_S_ABPLBP_LeLnInvalidQuSIF_btf()) & ((sint32)GET_P_LCRSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32)rtb_EQ) != 0));
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_LCRSMI_DangerousSide_nu'
         */
    rtb_sfun_setbit_i = (uint8)(((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE)));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Application Parameter1'/Constant'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/AND4/Functionality'/AND'
         */
    rtb_DataTypeConversion = (uint8)((((sint32) GET_P_LCRSIA_SafetyIfaceALCAOn_bool()) != 0) && (((sint32)rtb_sfun_setbit_i) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch = GET_S_ABPLBP_LeLnClthHeadingSIF_rad();
    } else {
        rtb_Switch = GET_S_ABPLBP_LeLnClthHeading_rad();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Add/Functionality'/Sum'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Add1/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_p) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_HeadAngThresALCAMin_rad() - GET_P_LCRSIA_HeadAngThresALCAHyst_rad();
        rtb_Abs = GET_P_LCRSIA_HeadAngThresALCAHyst_rad() + GET_P_LCRSIA_HeadAngThresALCAMax_rad();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_HeadAngThresALCAMin_rad();
        rtb_Abs = GET_P_LCRSIA_HeadAngThresALCAMax_rad();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger/Neg/Functionality'/Unary Minus'
         */
    rtb_GT_h4 = (uint8)(((-rtb_Switch) > rtb_DataTypeConversion_8) && ((-rtb_Switch) < rtb_Abs));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND/Functionality'/AND'
         */
    rtb_EQ = (uint8)((((sint32)rtb_EQ) != 0) && (((sint32)rtb_GT_h4) != 0));
    /* S-Function Block sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_LCRSIA_VXCrvThresALCAMax_1pm (), &x_dps);
    }
    /* Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Abs_lt = rtb_ip_lookup_fxpt_sfun_7;
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_j) != 0) {
        /* S-Function Block sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D (GETA_Y_LCRSIA_VXCrvThresALCAHyst_1pm(), &x_dps);
        }
        rtb_Abs_lt += rtb_ip_lookup_fxpt_sfun_7_e;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_DataTypeConversion_8 = GET_S_ABPLBP_LeLnClthCrvSIF_1pm();
    } else {
        rtb_DataTypeConversion_8 = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_oz = (uint8)(f32_abs_f32(rtb_DataTypeConversion_8) < rtb_Abs_lt);
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND3/Functionality'/AND'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/NOT/Functionality'/NOT'
         */
    rtb_Selector = (uint8)(!((((sint32)GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32)GET_P_LCRSIA_ConstrSite_bool()) != 0)));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND5/Functionality'/AND'
         */
    rtb_EQ = (uint8)(((((sint32)rtb_EQ) != 0) && (((sint32)rtb_LT_oz) != 0)) && (((sint32)rtb_Selector) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_m) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_HeadAngThresALCAHyst_rad() + GET_P_LCRSIA_HeadAngThresALCAMax_rad();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_HeadAngThresALCAMax_rad();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel/Abs/Functionality'/Abs'
         */
    rtb_LT_bg = (uint8)(f32_abs_f32(rtb_Switch) < rtb_DataTypeConversion_8);
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND6/Functionality'/AND'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND7/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Relational Operator1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/AND13/Functionality'/AND'
         */
    rtb_DataTypeConversion_d0 = (uint8)((((((sint32)rtb_LT_bg) != 0) && ((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_LCRSIA_LaneCancelBitmask_btm())) == 0)) && (((sint32)rtb_LT_oz) != 0)) && (((sint32)rtb_Selector) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Switch9/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_i) != 0) {
        rtb_Selector = rtb_EQ;
    } else {
        rtb_Selector = rtb_DataTypeConversion_d0;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Switch9/Functionality'/Switch' */
    /* Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft'/Unit Delay2'
         */
    rtb_LogicalOperator = (uint8)((DW_lcrsia_UnitDelay2_DSTATE <= 0.0F) && (((sint32)rtb_Selector) != 0));
    /* Product: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/P_VEH_Width_met'/Constant'
         */
    rtb_Div = GET_P_VEH_Width_met() / 2.0F;
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant8'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Add/Functionality'/Sum'
         */
    if (((sint32)rtb_LogicalOperator) != 0) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch9/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_DataTypeConversion_8 = GET_S_ABPLBP_LeLnClthPosY0SIF_met();
        } else {
            rtb_DataTypeConversion_8 = GET_S_ABPLBP_LeLnClthPosY0_met();
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch9/Functionality'/Switch' */
        rtb_Switch_ngc = rtb_DataTypeConversion_8 - rtb_Div;
    } else {
        rtb_Switch_ngc = 10.0F;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant6'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/P_VEH_Width_met2'/Constant'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/AND3/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Neg/Functionality'/Unary Minus'
         */
    rtb_sfun_setbit = (uint8)(((((sint32)rtb_LogicalOperator) != 0) && (rtb_Switch_ngc > 0.0F)) && (rtb_Switch < (-GET_P_LCRSIA_TlcHeadAngThres_rad ())));
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Constant5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND2/Functionality'/AND'
         */
    rtb_EQ_g = (uint8)((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_LCRSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Application Parameter6'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Constant6'/Constant'
         *  DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND4/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQuSIF_btf'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Relational Operator5/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND1/Functionality'/AND'
         */
    if (((sint32)GET_P_LCRSIA_SafetyIfaceALCAOn_bool()) != 0) {
        rtb_EQ_g = (uint8)(((((sint32)GET_S_ABPLBP_RiLnInvalidQuSIF_btf()) & ((sint32)GET_P_LCRSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_g) != 0));
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_m2n = GET_S_ABPLBP_RiLnClthHeadingSIF_rad();
    } else {
        rtb_Switch_m2n = GET_S_ABPLBP_RiLnClthHeading_rad();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Add/Functionality'/Sum'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Add1/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_jw) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_HeadAngThresALCAMin_rad() - GET_P_LCRSIA_HeadAngThresALCAHyst_rad();
        rtb_Abs = GET_P_LCRSIA_HeadAngThresALCAHyst_rad() + GET_P_LCRSIA_HeadAngThresALCAMax_rad();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_HeadAngThresALCAMin_rad();
        rtb_Abs = GET_P_LCRSIA_HeadAngThresALCAMax_rad();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_m = (uint8)((rtb_Switch_m2n > rtb_DataTypeConversion_8) && (rtb_Switch_m2n < rtb_Abs));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND/Functionality'/AND'
         */
    rtb_EQ_g = (uint8)((((sint32)rtb_EQ_g) != 0) && (((sint32)rtb_GT_m) != 0));
    /* S-Function Block sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_LCRSIA_VXCrvThresALCAMax_1pm(), &x_dps);
    }
    /* Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Abs_lt = rtb_ip_lookup_fxpt_sfun_7_l;
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_b) != 0) {
        /* S-Function Block sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Y_LCRSIA_VXCrvThresALCAHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_LCRSIA_VXCrvThresALCAHyst_1pm(), &x_dps);
        }
        rtb_Abs_lt += rtb_ip_lookup_fxpt_sfun_7_b;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_DataTypeConversion_8 = GET_S_ABPLBP_RiLnClthCrvSIF_1pm();
    } else {
        rtb_DataTypeConversion_8 = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_n = (uint8)(f32_abs_f32(rtb_DataTypeConversion_8) < rtb_Abs_lt);
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND3/Functionality'/AND'
         */
    rtb_sfun_setbit_m = (uint8)((((sint32)GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32)GET_P_LCRSIA_ConstrSite_bool()) != 0));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/NOT/Functionality'/NOT'
         */
    rtb_sfun_setbit_m = (uint8)(!(((sint32)rtb_sfun_setbit_m) != 0));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND5/Functionality'/AND'
         */
    rtb_EQ_g = (uint8)(((((sint32)rtb_EQ_g) != 0) && (((sint32)rtb_LT_n) != 0)) && (((sint32)rtb_sfun_setbit_m) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_k) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_HeadAngThresALCAHyst_rad() + GET_P_LCRSIA_HeadAngThresALCAMax_rad();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_HeadAngThresALCAMax_rad();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel/Abs/Functionality'/Abs'
         */
    rtb_LT_c = (uint8)(f32_abs_f32(rtb_Switch_m2n) < rtb_DataTypeConversion_8);
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND6/Functionality'/AND'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND7/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Relational Operator1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/AND13/Functionality'/AND'
         */
    rtb_DataTypeConversion_iy = (uint8)((((((sint32)rtb_LT_c) != 0) && ((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_LCRSIA_LaneCancelBitmask_btm())) == 0)) && (((sint32)rtb_LT_n) != 0)) && (((sint32)rtb_sfun_setbit_m) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Switch9/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_i) != 0) {
        rtb_sfun_setbit_m = rtb_EQ_g;
    } else {
        rtb_sfun_setbit_m = rtb_DataTypeConversion_iy;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Switch9/Functionality'/Switch' */
    /* Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight'/Unit Delay2'
         */
    rtb_LogicalOperator_b = (uint8)((DW_lcrsia_UnitDelay2_DSTATE_d <= 0.0F) && (((sint32)rtb_sfun_setbit_m) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant9'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Product/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator) != 0) {
        rtb_Switch *= GET_S_LCFRCV_VehVelX_mps();
    } else {
        rtb_Switch = 0.0F;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant10'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Product2/Functionality'/Mul'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Add1/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch6/Functionality'/Switch'
         */
    if (((sint32)rtb_LogicalOperator_b) != 0) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_DataTypeConversion_8 = GET_S_ABPLBP_RiLnClthPosY0SIF_met();
        } else {
            rtb_DataTypeConversion_8 = GET_S_ABPLBP_RiLnClthPosY0_met();
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch1/Functionality'/Switch' */
        rtb_Div += rtb_DataTypeConversion_8;
        rtb_Switch_a = GET_S_LCFRCV_VehVelX_mps() * rtb_Switch_m2n;
    } else {
        rtb_Div = -10.0F;
        rtb_Switch_a = 0.0F;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant1'/Constant'
         */
    if (((sint32)rtb_sfun_setbit) != 0) {
        /* Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Abs/Functionality'/Abs' */
        rtb_Abs_lt = f32_abs_f32(rtb_Switch);
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide1/In3'/Constant'
                 *  Product: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Div'
                 */
        if (rtb_Abs_lt != 0.0F) {
            rtb_Abs_lt = rtb_Switch_ngc / rtb_Abs_lt;
        } else {
            rtb_Abs_lt = 10.0F;
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide1/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Abs_lt = 10.0F;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch9'/copy1' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant1'/Constant'
         *  MinMax: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Min/Functionality'/Min'
         */
    SET_S_LCRSIA_TlcLeALCA_sec(f32_min_f32_f32(rtb_Abs_lt, 10.0F));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch3/Functionality'/Switch' incorporates:
                                                                      *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant2'/Constant'
                                                                      *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant7'/Constant'
                                                                      *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/P_VEH_Width_met1'/Constant'
                                                                      *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/AND4/Functionality'/AND'
                                                                      *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/GT1/Functionality'/GT'
                                                                      *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/LT1/Functionality'/LT'
                                                                      */
    if (((((sint32)rtb_LogicalOperator_b) != 0) && (rtb_Div < 0.0F)) && (rtb_Switch_m2n > GET_P_LCRSIA_TlcHeadAngThres_rad())) {
        /* Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Abs2/Functionality'/Abs' */
        rtb_Switch_m2n = f32_abs_f32(rtb_Switch_a);
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide2/In3'/Constant'
                 *  Product: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Div'
                 *  UnaryMinus: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Neg1/Functionality'/Unary Minus'
                 */
        if (rtb_Switch_m2n != 0.0F) {
            rtb_Abs_lt = (-rtb_Div) / rtb_Switch_m2n;
        } else {
            rtb_Abs_lt = 10.0F;
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Divide2/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Abs_lt = 10.0F;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch10'/copy1' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Constant2'/Constant'
         *  MinMax: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/DlcTlcCalculation/Min1/Functionality'/Min'
         */
    SET_S_LCRSIA_TlcRiALCA_sec(f32_min_f32_f32(rtb_Abs_lt, 10.0F));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch6/Functionality'/Switch' incorporates:
                                                                      *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Application Parameter2'/Constant'
                                                                      *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
                                                                      *  Inport: '<Root>/S_ABPLBP_UncoupledLaneWidth_met'
                                                                      */
    if (((sint32)GET_P_LCRSIA_UncoupledLWEnable_bool()) != 0) {
        rtb_Switch_bp[1] = GET_S_ABPLBP_UncoupledLaneWidth_met();
    } else {
        rtb_Switch_bp[1] = GET_S_ABPLBP_CoupledLaneWidth_met();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneBoundaryInterface/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Selector) != 0) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft'/Unit Delay2'
                 */
        if (DW_lcrsia_UnitDelay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_lcrsia_UnitDelay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft'/Unit Delay2' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/Application Parameter4'/Constant'
                 */
        DW_lcrsia_UnitDelay2_DSTATE = GET_P_LCRSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_sfun_setbit_m) != 0) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight'/Unit Delay2'
                 */
        if (DW_lcrsia_UnitDelay2_DSTATE_d > 0.0F) {
            /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_lcrsia_UnitDelay2_DSTATE_d -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight'/Unit Delay2' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/Application Parameter4'/Constant'
                 */
        DW_lcrsia_UnitDelay2_DSTATE_d = GET_P_LCRSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[2] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector Concatenate1In4' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[3] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector Concatenate1In5' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[4] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector Concatenate1In6' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[5] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector Concatenate1In7' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[6] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector Concatenate1In8' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant2'/Constant'
         */
    rtb_VectorConcatenate1[7] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant3'/Constant'
         */
    rtb_VectorConcatenate[2] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant3'/Constant'
         */
    rtb_VectorConcatenate[3] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector ConcatenateIn5' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant3'/Constant'
         */
    rtb_VectorConcatenate[4] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant3'/Constant'
         */
    rtb_VectorConcatenate[5] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant3'/Constant'
         */
    rtb_VectorConcatenate[6] = 0U;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/Constant3'/Constant'
         */
    rtb_VectorConcatenate[7] = 0U;
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_p2) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelLatThresALCAMin_mps() - GET_P_LCRSIA_VelLatThresALCAHyst_mps();
        rtb_Abs = GET_P_LCRSIA_VelLatThresALCAHyst_mps() + GET_P_LCRSIA_VelLatThresALCAMax_mps();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelLatThresALCAMin_mps();
        rtb_Abs = GET_P_LCRSIA_VelLatThresALCAMax_mps();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion = (uint8)(((-rtb_Switch) > rtb_DataTypeConversion_8) && ((-rtb_Switch) < rtb_Abs));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/P_LDPSA_VelXMin_mps5'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft'/Unit Delay1'
         */
    if (((sint32)DW_lcrsia_UnitDelay1_DSTATE_d) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelLatThresALCAHyst_mps() + GET_P_LCRSIA_VelLatThresALCAMax_mps();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelLatThresALCAMax_mps();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Abs/Functionality'/Abs'
         *  UnaryMinus: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_LT_oc = (uint8)(f32_abs_f32(-rtb_Switch) < rtb_DataTypeConversion_8);
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Switch/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_i) != 0) {
        rtb_sfun_setbit_m = rtb_DataTypeConversion;
    } else {
        rtb_sfun_setbit_m = rtb_LT_oc;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate[1] = (uint8)(!(((sint32)rtb_sfun_setbit_m) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/P_LDPSA_VelXMin_mps5'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/P_LDPSA_VelXMin_mps6'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/P_LDPSA_VelXMin_mps7'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Add/Functionality'/Sum'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_kq) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelLatThresALCAMin_mps() - GET_P_LCRSIA_VelLatThresALCAHyst_mps();
        rtb_Abs = GET_P_LCRSIA_VelLatThresALCAHyst_mps() + GET_P_LCRSIA_VelLatThresALCAMax_mps();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelLatThresALCAMin_mps();
        rtb_Abs = GET_P_LCRSIA_VelLatThresALCAMax_mps();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_bq = (uint8)((rtb_Switch_a > rtb_DataTypeConversion_8) && (rtb_Switch_a < rtb_Abs));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight'/Unit Delay1'
         */
    if (((sint32)DW_lcrsia_UnitDelay1_DSTATE_b) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelLatThresALCAHyst_mps() + GET_P_LCRSIA_VelLatThresALCAMax_mps();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelLatThresALCAMax_mps();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Abs/Functionality'/Abs'
         */
    rtb_LT_dp = (uint8)(f32_abs_f32(rtb_Switch_a) < rtb_DataTypeConversion_8);
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Switch/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_i) != 0) {
        rtb_sfun_setbit_i = rtb_GT_bq;
    } else {
        rtb_sfun_setbit_i = rtb_LT_dp;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate1[1] = (uint8)(!(((sint32)rtb_sfun_setbit_i) != 0));
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/from_data_definition'/state_source'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalState_enum'
         */
    rtb_EQ_a = (uint8)(((sint32)GET_S_LCFRCV_TurnSignalState_enum()) == ((sint32) ((uint8)E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_LEFT)));
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalState_enum'
         */
    rtb_EQ_m2 = (uint8)(((sint32)GET_S_LCFRCV_TurnSignalState_enum()) == ((sint32)((uint8) E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_RIGHT)));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Application Parameter6'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Constant5'/Constant'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe'/Unit_Delay'
         */
    if (((sint32)GET_P_LCRSIA_TurnSignReset_bool()) != 0) {
        /* S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1'/fcg' incorporates:
                 *  SubSystem: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality'/Comparison'
                 */
        rtb_sfun_setbit_m = (uint8)((!(((sint32)DW_lcrsia_Unit_Delay_DSTATE_l) != 0)) && (((sint32)rtb_EQ_m2) != 0));
        /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1'/fcg' */
    } else {
        rtb_sfun_setbit_m = 0U;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Constant2'/Constant'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_sfun_setbit_m) != 0) {
        rtb_Switch_m2n = 0.0F;
    } else if (((sint32)rtb_EQ_a) != 0) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Application Parameter5'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Add2/Functionality'/Sum'
                 */
        rtb_Switch_m2n = GET_P_LCRSIA_TurnSignHoldingTime_sec() + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe'/Unit Delay1'
                 */
        rtb_Switch_m2n = DW_lcrsia_UnitDelay1_DSTATE;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Constant3'/Constant'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Relational Operator8/Functionality'/GT'
         */
    rtb_VectorConcatenate[0] = (uint8)((((sint32)rtb_EQ_a) != 0) || (rtb_Switch_m2n > 1.0E-5F));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Constant4'/Constant'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi'/Unit_Delay'
         */
    if (((sint32)GET_P_LCRSIA_TurnSignReset_bool()) != 0) {
        /* S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1'/fcg' incorporates:
                 *  SubSystem: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality'/Comparison'
                 */
        rtb_sfun_setbit_m = (uint8)((!(((sint32)DW_lcrsia_Unit_Delay_DSTATE_b) != 0)) && (((sint32)rtb_EQ_a) != 0));
        /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1'/fcg' */
    } else {
        rtb_sfun_setbit_m = 0U;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Switch8/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Constant2'/Constant'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_sfun_setbit_m) != 0) {
        rtb_Abs_lt = 0.0F;
    } else if (((sint32)rtb_EQ_m2) != 0) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/Application Parameter1'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Add2/Functionality'/Sum'
                 */
        rtb_Abs_lt = GET_P_LCRSIA_TurnSignHoldingTime_sec() + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Switch/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi '/Unit Delay1'
                 */
        rtb_Abs_lt = DW_lcrsia_UnitDelay1_DSTATE_n;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Constant3'/Constant'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Relational Operator8/Functionality'/GT'
         */
    rtb_VectorConcatenate1[0] = (uint8)((((sint32)rtb_EQ_m2) != 0) || (rtb_Abs_lt > 1.0E-5F));
    /* S-Function (sfun_setbit): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_m = temp;
    }
    /* S-Function (sfun_setbit): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/set_bit1/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit = temp;
    }
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/ALCASwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/ALCASwitch/Application Parameter2'/Constant'
         */
    if (((sint32)GET_P_LCRSMI_ALCASwitchEnable_bool()) != 0) {
        /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/ALCASwitch/NOT/Functionality'/Data Type Conversion' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_ALCASwitch_bool'
                 *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/ALCASwitch/NOT/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_e[7] = (uint8)(!(((sint32) GET_S_LCFRCV_ALCASwitch_bool()) != 0));
    } else {
        /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/ALCASwitch/NOT/Functionality'/Data Type Conversion' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/ALCASwitch/Application Parameter1'/Constant'
                 *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/ALCASwitch/NOT/Functionality'/NOT'
                 */
        rtb_VectorConcatenate_e[7] = (uint8)(!(((sint32) GET_P_LCRSMI_ALCASwitch_bool()) != 0));
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/ALCASwitch/Switch/Functionality'/Switch' */
    /* Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehAclY_mps2'
         */
    rtb_Abs = f32_abs_f32(GET_S_LCFRCV_VehAclY_mps2());
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/C_LCF_AclYHyst_mps2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/C_LCF_AclYMax_mps2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity'/Unit Delay1'
         */
    if (rtb_Abs > (GET_P_LCRSIA_AclYMax_mps2() + GET_P_LCRSIA_AclYHyst_mps2())) {
        rtb_Selector = 1U;
    } else if (rtb_Abs < GET_P_LCRSIA_AclYMax_mps2()) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_Selector = 0U;
    } else {
        rtb_Selector = DW_lcrsia_UnitDelay1_DSTATE_j;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity'/Unit Delay1' incorporates:
         *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    DW_lcrsia_UnitDelay1_DSTATE_j = rtb_Selector;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LatAclValidity/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate_e[5] = rtb_Selector;
    /* Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         */
    rtb_Abs = f32_abs_f32(GET_S_LCFRCV_VehCrv_1pm());
    /* S-Function Block sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/Y_LCRSIA_VXVehCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D (GETA_Y_LCRSIA_VXVehCrvThresMax_1pm(), &x_dps);
    }
    /* Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/Y_LCRSIA_VXVehCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/Y_LCRSIA_VXVehCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_ln = rtb_ip_lookup_fxpt_sfun_7_i;
    /* S-Function Block sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/Y_LCRSIA_VXVehCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_LCRSIA_VXVehCrvThresHyst_1pm(), &x_dps);
    }
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Relational Operator1'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/Y_LCRSIA_VXVehCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/Add3/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature'/Unit Delay1'
         */
    if (rtb_Abs > (rtb_Sum_ln + rtb_ip_lookup_fxpt_sfun_7_c)) {
        rtb_Selector = 1U;
    } else if (rtb_Abs < rtb_Sum_ln) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_Selector = 0U;
    } else {
        rtb_Selector = DW_lcrsia_UnitDelay1_DSTATE_jo;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch3' */
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature'/Unit Delay1' incorporates:
         *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    DW_lcrsia_UnitDelay1_DSTATE_jo = rtb_Selector;
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/EgoVehCurvature/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate_e[6] = rtb_Selector;
    /* Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Add/Functionality'/Sum' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXMin_mps'/Constant'
         */
    rtb_Abs = GET_P_LCRSIA_LaneWidthALCAMin_met() - GET_P_LCRSIA_LaneWidthALCAHyst_met();
    /* Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Add1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXMax_mps'/Constant'
         */
    rtb_Sum_ln = GET_P_LCRSIA_LaneWidthALCAHyst_met() + GET_P_LCRSIA_LaneWidthALCAMax_met();
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         */
    rtb_Switch_bp[0] = GET_S_ABPLBP_LaneWidth_met();
    /* Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator4/Functionality'/AND' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXHyst_mps3'/Constant'
         */
    tmp = (uint8)(((sint32)GET_P_LCRSIA_LaneWidthWideLn_bool()) != 0);
    /* Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator2/Functionality'/AND' */
    rtb_LogicalOperator_1 = (uint8)((((sint32)rtb_LogicalOperator) != 0) && (((sint32)rtb_LogicalOperator_b) != 0));
    for (i = 0; i < 2; i++) {
        /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Relational Operator1/Functionality'/LT' */
        rtb_Switch_i1 = rtb_Switch_bp[i];
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXMax_mps'/Constant'
                 *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/Unit Delay2'
                 */
        if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_c[i]) != 0) {
            rtb_DataTypeConversion_8 = rtb_Sum_ln;
        } else {
            rtb_DataTypeConversion_8 = GET_P_LCRSIA_LaneWidthALCAMax_met();
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch1/Functionality'/Switch' */
        /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Relational Operator1/Functionality'/LT' */
        rtb_Selector = (uint8)(rtb_Switch_bp[i] < rtb_DataTypeConversion_8);
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXMin_mps'/Constant'
                 *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/Unit Delay2'
                 */
        if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_c[i]) != 0) {
            rtb_DataTypeConversion_8 = rtb_Abs;
        } else {
            rtb_DataTypeConversion_8 = GET_P_LCRSIA_LaneWidthALCAMin_met();
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch3/Functionality'/Switch' */
        /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator1/Functionality'/AND'
                 *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Relational Operator/Functionality'/GT'
                 *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Relational Operator1/Functionality'/LT'
                 */
        rtb_Switch3_j = (uint8)((rtb_Switch_bp[i] > rtb_DataTypeConversion_8) && (((sint32)rtb_Selector) != 0));
        /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator3/Functionality'/NOT'
                 */
        rtb_Selector = (uint8)(!(((sint32)rtb_Selector) != 0));
        /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator4/Functionality'/AND'
                 */
        rtb_Selector = (uint8)(((sint32)tmp) && (((sint32)rtb_Selector) != 0));
        /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator5/Functionality'/NOT'
                 */
        rtb_Selector = (uint8)(!(((sint32)rtb_Selector) != 0));
        /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator2/Functionality'/AND'
                 */
        rtb_Selector = (uint8)(((sint32)rtb_LogicalOperator_1) && (((sint32) rtb_Selector) != 0));
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Constant2'/Constant'
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXHyst_mps2'/Constant'
                 *  DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator/Functionality'/Data Type Conversion'
                 *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator/Functionality'/NOT'
                 *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch4/Functionality'/Switch'
                 */
        if (((sint32)rtb_Selector) != 0) {
            rtb_Switch_j[i] = (sint8)(!(((sint32)rtb_Switch3_j) != 0));
        } else {
            rtb_Switch_j[i] = 0;
            rtb_Switch_i1 = GET_P_LCRSIA_LaneWidthWideLnDef_met();
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch2/Functionality'/Switch' */
        /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Relational Operator1/Functionality'/LT' */
        rtb_DataTypeConversion_nu[i] = (sint8)rtb_Selector;
        /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Logical Operator1/Functionality'/Data Type Conversion' */
        rtb_DataTypeConversion_gc[i] = (sint8)rtb_Switch3_j;
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch4/Functionality'/Switch' */
        rtb_Switch_bp[i] = rtb_Switch_i1;
    }
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch17'/copy1' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Constant1'/Constant'
         *  Selector: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/Selector'
         */
    SET_S_LCRSIA_TgtCntrLnEnable_bool((uint8)rtb_DataTypeConversion_nu[0]);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch16'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Constant3'/Constant'
                                                                          *  Selector: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/Selector1'
                                                                          */
    SET_S_LCRSIA_LaneWidth_met(rtb_Switch_bp[0]);
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch5/Functionality'/Switch' incorporates:
                                                    *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Constant4'/Constant'
                                                    *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Constant5'/Constant'
                                                    *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/P_LDPSA_VelXHyst_mps4'/Constant'
                                                    *  DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/OR/Functionality'/Data Type Conversion'
                                                    *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/OR/Functionality'/OR'
                                                    *  Selector: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/Selector2'
                                                    *  Selector: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/Selector3'
                                                    */
    if (((sint32)GET_P_LCRSIA_LaneWidthSIFOn_bool()) != 0) {
        rtb_VectorConcatenate_e[3] = (uint8)((((sint32)rtb_Switch_j[1]) != 0) || (((sint32)rtb_Switch_j[0]) != 0));
    } else {
        rtb_VectorConcatenate_e[3] = (uint8)rtb_Switch_j[0];
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/C_LCF_AclXHyst_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/C_LCF_AclXMin_mps2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/Add4/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity'/Unit Delay3'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > GET_P_LCRSIA_AclXMin_mps2()) {
        rtb_Selector = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < (GET_P_LCRSIA_AclXMin_mps2() - GET_P_LCRSIA_AclXHyst_mps2())) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Selector = 0U;
    } else {
        rtb_Selector = DW_lcrsia_UnitDelay3_DSTATE;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS2/Functionality'/Switch3' */
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/C_LCF_AclXHyst_mps2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/C_LCF_AclXMax_mps2'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity'/Unit Delay1'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > (GET_P_LCRSIA_AclXMax_mps2() + GET_P_LCRSIA_AclXHyst_mps2())) {
        rtb_Switch3_j = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < GET_P_LCRSIA_AclXMax_mps2()) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_Switch3_j = 0U;
    } else {
        rtb_Switch3_j = DW_lcrsia_UnitDelay1_DSTATE_o;
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/NOT2/Functionality'/NOT'
         */
    rtb_sfun_setbit_i = (uint8)(!(((sint32)rtb_Switch3_j) != 0));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/Logical Operator2/Functionality'/AND'
         */
    rtb_sfun_setbit_i = (uint8)((((sint32)rtb_sfun_setbit_i) != 0) && (((sint32) rtb_Selector) != 0));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[4] = (uint8)(!(((sint32)rtb_sfun_setbit_i) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/P_LDPSA_VelXMax_mps'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_h) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_StrWhlAngleALCAHyst_deg() + GET_P_LCRSIA_StrWhlAngleALCAMax_deg();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_StrWhlAngleALCAMax_deg();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngle_deg'
         */
    rtb_LT_p = (uint8)(f32_abs_f32(GET_S_LCFRCV_SteerWAngle_deg()) < rtb_DataTypeConversion_8);
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[1] = (uint8)(!(((sint32)rtb_LT_p) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/P_LDPSA_VelXMax_mps'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_o) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_StrWhlAngSpeedALCAHyst_degps() + GET_P_LCRSIA_StrWhlAngSpeedALCAMax_degps();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_StrWhlAngSpeedALCAMax_degps();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngleRate_degps'
         */
    rtb_LT_l = (uint8)(f32_abs_f32(GET_S_LCFRCV_SteerWAngleRate_degps()) < rtb_DataTypeConversion_8);
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[2] = (uint8)(!(((sint32)rtb_LT_l) != 0));
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/P_LDPSA_VelXMax_mps'/Constant'
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/P_LDPSA_VelXMin_mps'/Constant'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Add/Functionality'/Sum'
         *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Add1/Functionality'/Sum'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp'/Unit Delay2'
         */
    if (((sint32)DW_lcrsia_UnitDelay2_DSTATE_a) != 0) {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelDispALCAMin_kph() - GET_P_LCRSIA_VelDispALCAHyst_kph();
        rtb_Abs = GET_P_LCRSIA_VelDispALCAHyst_kph() + GET_P_LCRSIA_VelDispALCAMax_kph();
    } else {
        rtb_DataTypeConversion_8 = GET_P_LCRSIA_VelDispALCAMin_kph();
        rtb_Abs = GET_P_LCRSIA_VelDispALCAMax_kph();
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_c = (uint8)((GET_S_LCFRCV_VDy_VehVelocity_kph() > rtb_DataTypeConversion_8) && (GET_S_LCFRCV_VDy_VehVelocity_kph() < rtb_Abs));
    /* DataTypeConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp/Logical Operator/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[0] = (uint8)(!(((sint32)rtb_GT_c) != 0));
    /* Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA'/Unit_Delay'
         */
    for (i = 0; i < 8; i++) {
        rtb_LogicalOperator_p[i] = (uint8)((((sint32)rtb_VectorConcatenate_e[i]) != 0) || (DW_lcrsia_Unit_Delay_DSTATE[i] > 0.0F));
    }
    /* End of Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Logical Operator' */
    /* S-Function (sfun_setbit): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_LogicalOperator_p[0];
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
        rtb_sfun_setbit_i = temp;
    }
    /* Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Add1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Switch_m2n -= GET_S_LCFRCV_SysCycleTimeSen_sec();
    /* Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Add1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Abs_lt -= GET_S_LCFRCV_SysCycleTimeSen_sec();
    /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch9/Functionality'/Switch' incorporates:
         *  Logic: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/AND/Functionality'/AND'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch10/Functionality'/Switch'
         *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch11/Functionality'/Switch'
         */
    if ((((sint32)rtb_LogicalOperator) != 0) && (((sint32)rtb_LogicalOperator_b) != 0)) {
        /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch'/copy1' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/from_data_definition5'/state_source'
                 */
        SET_S_LCRSIA_LnBndValidALCA_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE));
    } else if (((sint32)rtb_LogicalOperator) != 0) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch10/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/from_data_definition2'/state_source'
                 *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch'/copy1'
                 */
        SET_S_LCRSIA_LnBndValidALCA_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY));
    } else if (((sint32)rtb_LogicalOperator_b) != 0) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch11/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/from_data_definition3'/state_source'
                 *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch'/copy1'
                 *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch10/Functionality'/Switch'
                 */
        SET_S_LCRSIA_LnBndValidALCA_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY));
    } else {
        /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch'/copy1' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/from_data_definition4'/state_source'
                 *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch11/Functionality'/Switch'
                 */
        SET_S_LCRSIA_LnBndValidALCA_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID));
    }
    /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LnBndValidALCA/Switch9/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch1'/copy1' */
    SET_S_LCRSIA_LnBndLeValidALCA_bool(rtb_LogicalOperator);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch11'/copy1' */
    SET_S_LCRSIA_VelLatLeALCA_mps(rtb_Switch);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch12'/copy1' */
    SET_S_LCRSIA_VelLatRiALCA_mps(rtb_Switch_a);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch13'/copy1' */
    SET_S_LCRSIA_SideCondALCALe_btf(rtb_sfun_setbit_m);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch14'/copy1' */
    SET_S_LCRSIA_SideCondALCARi_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch15'/copy1' */
    SET_S_LCRSIA_SpecificALCA_btf(rtb_sfun_setbit_i);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch2'/copy1' */
    SET_S_LCRSIA_LnBndRiValidALCA_bool(rtb_LogicalOperator_b);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch3'/copy1' */
    SET_D_LCRSIA_LnBndLeTrgValidALCA_bool(rtb_EQ);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch4'/copy1' */
    SET_D_LCRSIA_LnBndRiTrgValidALCA_bool(rtb_EQ_g);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch5'/copy1' */
    SET_D_LCRSIA_LnBndLeCancelValidALCA_bool(rtb_DataTypeConversion_d0);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch6'/copy1' */
    SET_D_LCRSIA_LnBndRiCancelValidALCA_bool(rtb_DataTypeConversion_iy);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch7'/copy1' */
    SET_S_LCRSIA_DlcLeALCA_met(rtb_Switch_ngc);
    /* SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/branch8'/copy1' */
    SET_S_LCRSIA_DlcRiALCA_met(rtb_Div);
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingTrigger'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_p = rtb_GT_h4;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/CurvatureLeft'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_j = rtb_LT_oz;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingLeft/HeadingCancel'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_m = rtb_LT_bg;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingTrigger'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_jw = rtb_GT_m;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/CurvatureLeft'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_b = rtb_LT_n;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/LaneMarkingValidationALCA/LaneMarkingRight/HeadingCancel'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_k = rtb_LT_c;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_p2 = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatLeft'/Unit Delay1' */
    DW_lcrsia_UnitDelay1_DSTATE_d = rtb_LT_oc;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_kq = rtb_GT_bq;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SideConditionsALCA/VelLatRight'/Unit Delay1' */
    DW_lcrsia_UnitDelay1_DSTATE_b = rtb_LT_dp;
    /* S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrsia_Unit_Delay_DSTATE_l = rtb_EQ_m2;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingLe/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe'/Unit Delay1' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Constant1'/Constant'
         *  MinMax: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerLe/Max/Functionality'/Max'
         */
    DW_lcrsia_UnitDelay1_DSTATE = f32_max_f32_f32(rtb_Switch_m2n, 0.0F);
    /* S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrsia_Unit_Delay_DSTATE_b = rtb_EQ_a;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/EdgeRisingRi/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi '/Unit Delay1' incorporates:
         *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Constant1'/Constant'
         *  MinMax: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/TurnSignal/FollowUpTimerRi /Max/Functionality'/Max'
         */
    DW_lcrsia_UnitDelay1_DSTATE_n = f32_max_f32_f32(rtb_Abs_lt, 0.0F);
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/Unit Delay2' */
    for (i = 0; i < 2; i++) {
        DW_lcrsia_UnitDelay2_DSTATE_c[i] = (uint8)rtb_DataTypeConversion_gc[i];
    }
    /* End of Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LaneWidth'/Unit Delay2' */
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity'/Unit Delay3' */
    DW_lcrsia_UnitDelay3_DSTATE = rtb_Selector;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/LongAclValidity'/Unit Delay1' */
    DW_lcrsia_UnitDelay1_DSTATE_o = rtb_Switch3_j;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngle'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_h = rtb_LT_p;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/SteeringWheelAngleSpeed'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_o = rtb_LT_l;
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA'/Unit_Delay' */
    for (i = 0; i < 8; i++) {
        /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/Constant'/Constant'
                 *  Constant: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Relational Operator'
                 *  Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Switch2'
                 *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA'/Unit_Delay'
                 */
        if (((sint32)rtb_VectorConcatenate_e[i]) != 0) {
            DW_lcrsia_Unit_Delay_DSTATE[i] = GET_P_LCRSIA_SpecificDebTime_sec((i));
        } else {
            if (DW_lcrsia_Unit_Delay_DSTATE[i] > 0.0F) {
                /* Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                                 *  UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA'/Unit_Delay'
                                 */
                DW_lcrsia_Unit_Delay_DSTATE[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
        }
        /* End of Switch: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/TURNOFFDELAYTIME/Functionality'/Switch1' */
    }
    /* End of Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA'/Unit_Delay' */
    /* Update for UnitDelay: 'sda:LCRSIA/LCRSIA/LCRSIA_SenProcess/OPM/LCRSIA_ALCA/SpecificConditionsALCA/VelVehDisp'/Unit Delay2' */
    DW_lcrsia_UnitDelay2_DSTATE_a = rtb_GT_c;
}
#include "Pse_LCRSIA.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
