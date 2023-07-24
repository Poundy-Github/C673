/****************************************************************************
 * COPYRIGHT (C) CONTINENTAL AUTOMOTIVE GMBH 2019
 * ALL RIGHTS RESERVED.
 *
 * The reproduction, transmission or use of this document or its
 * contents is not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights
 * created by patent grant or registration of a utility model or design,
 * are reserved.
 *-------------------------------------------------------------------------
 *
 * File          : TJALKA
 * Generated on  : Tue 30.07.2019 at 13:35:25 (UTC+01:00)
 * MD5           : [339097802   775933508  2351025875  2405998867 0](TJALKA)
 *
 * Purpose       : <Purpose>
 * Specification : <Specification>
 *
 * Environment information:
 * Processor     : 32 Bit generic
 * Platform      : EMS3
 * SDA version   : 10.0
 * Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,79,81,82
 * Add-ons       : -
 *
 * Version management information:
 * Filename      : $Workfile: $
 * Revision      : $Revision: 1.6 $
 * Author        : $Author: Werum, Gregor (uidq2175) $
 * Date          : $Date: 2019/08/29 10:04:44CEST $
 * Changes       :
 * $Log: TJALKA.c  $
 * Revision 1.6 2019/08/29 10:04:44CEST Werum, Gregor (uidq2175) 
 * Module test update according to findings (FCT_CMP_TJASA_1577, FCT_CMP_TJASA_2145)
 * Revision 1.41.1.9 2019/07/30 14:01:50CEST Werum, Gregor (uidq2175) 
 * Unit delay added to max curvature check for lane prediction activation
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TJALKA.h"
#include "TJALKA_private.h"
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
#define TJALKA_START_SEC_DATA_8
#include "TJALKA_MemMap.h"
static uint8 DW_tjalka_Unit_Delay_DSTATE_o;
static uint8 DW_tjalka_Unit_Delay_DSTATE_b;
static uint8 DW_tjalka_Unit_Delay5_DSTATE[2];
static uint8 DW_tjalka_Unit_Delay1_DSTATE_c;
static uint8 DW_tjalka_Unit_Delay3_DSTATE;
static uint8 DW_tjalka_Unit_Delay4_DSTATE_h;
static uint8 DW_tjalka_Unit_Delay_DSTATE_a;
static uint8 DW_tjalka_Unit_Delay5_DSTATE_b;
static uint8 DW_tjalka_Unit_Delay_DSTATE_bh;
static uint8 DW_tjalka_Unit_Delay2_DSTATE_i;
static uint8 DW_tjalka_Unit_Delay3_DSTATE_i[2];
static uint8 DW_tjalka_Unit_Delay_DSTATE_n;
static uint8 DW_tjalka_Unit_Delay1_DSTATE_e;
static uint8 DW_tjalka_Unit_Delay_DSTATE_j;
static uint8 DW_tjalka_Unit_Delay_DSTATE_bl[2];
static uint8 DW_tjalka_Unit_Delay1_DSTATE_j;
static uint8 DW_tjalka_Unit_Delay1_DSTATE_cp;
static uint8 DW_tjalka_Unit_Delay2_DSTATE_e;
static uint8 DW_tjalka_Unit_Delay2_DSTATE_d;
static uint8 DW_tjalka_Unit_Delay1_DSTATE_ju[2];
#define TJALKA_STOP_SEC_DATA_8
#include "TJALKA_MemMap.h"
#define TJALKA_START_SEC_DATA_32
#include "TJALKA_MemMap.h"
static float32 DW_tjalka_Unit_Delay_DSTATE;
static float32 DW_tjalka_Unit_Delay4_DSTATE[2];
static float32 DW_tjalka_Unit_Delay2_DSTATE[2];
static float32 DW_tjalka_Unit_Delay2_DSTATE_b;
static float32 DW_tjalka_Unit_Delay1_DSTATE;
static float32 DW_tjalka_Unit_Delay2_DSTATE_n;
static float32 DW_tjalka_Unit_Delay1_DSTATE_i;
static float32 DW_tjalka_Unit_Delay4_DSTATE_d;
static float32 DW_tjalka_Unit_Delay4_DSTATE_p;
static float32 DW_tjalka_Unit_Delay2_DSTATE_j[2];
#define TJALKA_STOP_SEC_DATA_32
#include "TJALKA_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TJALKA/TJALKA/INI'/TJALKA_SenReset'
 * Block description for: 'sda:TJALKA/TJALKA/INI'/TJALKA_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TJALKA_SenReset
#include "Pse_TJALKA.h"
/* Short description: Not synchronized with ARAMIS */
void TJALKA_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant'/Constant' */
    SET_D_TJALKA_LaneInvalid_btf(0U);
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant1'/Constant' */
    SET_D_TJALKA_LaneCenterInvalid_btf(0U);
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant2'/Constant' */
    SET_S_TJALKA_WeakReady_bool(0U);
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant3'/Constant' */
    SET_S_TJALKA_Cancel_bool(0U);
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant4'/Constant' */
    SET_S_TJALKA_LnBndValid_nu(0U);
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant5'/Constant' */
    SET_S_TJALKA_StrongReady_bool(0U);
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant6'/Constant' */
    SET_S_TJALKA_LanePredictValid_bool(0U);
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant7'/Constant' */
    SET_S_TJALKA_CombinedLaneSR_bool(0U);
    /* Constant: 'sda:TJALKA/TJALKA/INI/TJALKA_SenReset/Constant8'/Constant' */
    SET_S_TJALKA_CombinedLaneWR_bool(0U);
}
#include "Pse_TJALKA.h"
/*
 * Output and update for function-call system: 'sda:TJALKA/TJALKA'/TJALKA_SenProcess'
 * Block description for: 'sda:TJALKA/TJALKA'/TJALKA_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TJALKA_SenProcess
#include "Pse_TJALKA.h"
/* Short description: Not synchronized with ARAMIS */
void TJALKA_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    uint16 rtb_sfun_setbit;
    uint16 rtb_sfun_setbit_c;
    uint8 rtb_Switch3_g[2];
    uint8 rtb_Switch3_o2[2];
    uint8 rtb_VectorConcatenate[16];
    uint8 rtb_VectorConcatenate_h[16];
    uint8 rtb_GT_mh[2];
    uint8 rtb_NE_c;
    uint8 rtb_DataTypeConversion_d;
    uint8 rtb_DataTypeConversion_fw;
    uint8 rtb_DataTypeConversion_az;
    uint8 rtb_DataTypeConversion_jq;
    uint8 rtb_DataTypeConversion_au;
    uint8 rtb_DataTypeConversion_gg;
    sint8 rtb_GE[2];
    uint8 rtb_Switch2_g[2];
    uint8 rtb_DataTypeConversion_g4;
    sint8 rtb_GE_k[2];
    uint8 rtb_Switch_l[2];
    uint8 rtb_DataTypeConversion_me;
    uint8 rtb_DataTypeConversion_je;
    uint8 rtb_DataTypeConversion_kj;
    uint8 rtb_DataTypeConversion_f;
    uint8 rtb_DataTypeConversion_c;
    uint8 rtb_DataTypeConversion_crf;
    uint8 rtb_DataTypeConversion_ir;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_DataTypeConversion_n;
    uint8 rtb_LogicalOperator_p;
    uint8 rtb_DataTypeConversion_i;
    uint8 rtb_Switch_k;
    uint8 rtb_Switch3;
    uint8 rtb_Switch3_i;
    float32 rtb_Switch4_l[2];
    float32 rtb_Sum_fd;
    uint8 rtb_Switch3_f;
    uint8 rtb_DataTypeConversion_oo;
    uint8 rtb_Switch3_or;
    uint8 rtb_Switch3_j;
    uint8 rtb_DataTypeConversion_le;
    uint8 rtb_DataTypeConversion_e;
    uint8 rtb_DataTypeConversion_b1;
    sint8 rtb_LogicalOperator_nq[2];
    uint8 rtb_DataTypeConversion_b;
    float32 rtb_Switch2_eh;
    uint8 rtb_DataTypeConversion_jw;
    uint8 LogicalOperator;
    sint32 i;
    uint8 rtb_Switch_ht_idx_0;
    uint8 rtb_Switch_ht_idx_1;
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/Constant2'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/constant_value2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/AND3/Functionality'/AND'
         */
    rtb_NE_c = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_TJALKA_PrjSpecQuC_btm())) != 0);
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/SRFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_TJAOBS_CancelLC_bool'
         */
    if (((sint32)GET_S_TJAOBS_CancelLC_bool()) != 0) {
        rtb_DataTypeConversion_jw = 1U;
    } else {
        /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/GT/Functionality'/GT' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/P_TJAGEN_QuTrajPlanMinLnQual_perc'/Constant'
                 *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
                 *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
                 */
        rtb_GT_mh[0] = (uint8)(((sint32)GET_S_ABPLBP_LeLnQuality_perc()) > ((sint32)GET_P_TJAGEN_QuTrajPlanMinLnQual_perc()));
        rtb_GT_mh[1] = (uint8)(((sint32)GET_S_ABPLBP_RiLnQuality_perc()) > ((sint32)GET_P_TJAGEN_QuTrajPlanMinLnQual_perc()));
        /* S-Function (sfun_and): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/AND1/Functionality'/sfun_and' */
        {
            /*vectorized operation*/
            sint32 i1;
            uint8 temp = rtb_GT_mh[0];
            for (i1=1; i1 < 2; i1++) {
                temp = temp && rtb_GT_mh[i1];
            }
            rtb_DataTypeConversion_jw = temp;
        }
        /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/AND/Functionality'/Data Type Conversion' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/from_data_definition1'/state_source'
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/from_data_definition5'/state_source'
                 *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
                 *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/AND/Functionality'/AND'
                 *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/EQ/Functionality'/EQ'
                 *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/EQ1/Functionality'/EQ'
                 */
        rtb_DataTypeConversion_jw = (uint8)((((sint32)rtb_DataTypeConversion_jw) != 0) && ((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_PASSIVE)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()))));
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/SRFLIPFLOP/Functionality'/Constant1'
                 *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion_jw) != 0) {
            rtb_DataTypeConversion_jw = 0U;
        } else {
            rtb_DataTypeConversion_jw = DW_tjalka_Unit_Delay_DSTATE_o;
        }
        /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/SRFLIPFLOP/Functionality'/Switch1' */
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier/SRFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/from_data_definition2'/state_source'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/OR1/Functionality'/OR'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/OR2/Functionality'/OR'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_fw = (uint8)(((((sint32)rtb_NE_c) != 0) || (((sint32) rtb_DataTypeConversion_jw) != 0)) && ((((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC))) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))));
    /* Signum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         */
    if (GET_S_ABPLBP_CntrLnClthPosY0_met() < 0.0F) {
        rtb_Switch2_eh = -1.0F;
    } else if (GET_S_ABPLBP_CntrLnClthPosY0_met() > 0.0F) {
        rtb_Switch2_eh = 1.0F;
    } else if (GET_S_ABPLBP_CntrLnClthPosY0_met() == 0.0F) {
        rtb_Switch2_eh = 0.0F;
    } else {
        rtb_Switch2_eh = GET_S_ABPLBP_CntrLnClthPosY0_met();
    }
    /* End of Signum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/Sign/Functionality'/Sign' */
    /* Signum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/Sign1/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthHeading_rad'
         */
    if (GET_S_ABPLBP_CntrLnClthHeading_rad() < 0.0F) {
        rtb_Sum_fd = -1.0F;
    } else if (GET_S_ABPLBP_CntrLnClthHeading_rad() > 0.0F) {
        rtb_Sum_fd = 1.0F;
    } else if (GET_S_ABPLBP_CntrLnClthHeading_rad() == 0.0F) {
        rtb_Sum_fd = 0.0F;
    } else {
        rtb_Sum_fd = GET_S_ABPLBP_CntrLnClthHeading_rad();
    }
    /* End of Signum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/Sign1/Functionality'/Sign' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/Abs/Functionality'/Abs'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/Constant3'/Constant'
         *  DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/DTC'/Data Type Conversion'
         *  DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/DTC1'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthHeading_rad'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneInCaptureRangeCheck/NEQ/Functionality'/NE'
         */
    rtb_DataTypeConversion_d = (uint8)((((sint32)s8_f32(rtb_Switch2_eh)) != ((sint32)s8_f32(rtb_Sum_fd))) || (f32_abs_f32 (GET_S_ABPLBP_CntrLnClthHeading_rad()) < GET_P_TJALKA_MaxHeadAngActnTJA_rad()));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/Switch/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/Switch/P_LDPSA_VelXMax_mps3'/Constant'
         *  Inport: '<Root>/S_TJASLC_TakeOverValid_bool'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/Switch/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_az = (uint8)((((sint32) GET_P_TJALKA_TransLnChecksOff_bool()) != 0) && (((sint32) GET_S_TJASLC_TakeOverValid_bool()) != 0));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/Constant2'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/Constant8'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/constant_value4'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/from_data_definition5'/state_source'
         *  DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/AND/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalLeverHold_bool'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/NEQ/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/AND1/Functionality'/AND'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck'/Unit_Delay'
         */
    if (((sint32)GET_P_TJASLC_SALC_Enabled_bool()) != 0) {
        /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING'/fcg' incorporates:
                 *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING/Functionality'/Comparison'
                 */
        rtb_DataTypeConversion_jq = (uint8)((!((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)rtb_DataTypeConversion_az) != 0))) && ((((sint32)DW_tjalka_Unit_Delay_DSTATE_b) != 0) && (!(((sint32) GET_S_LCFRCV_TurnSignalLeverHold_bool()) != 0))));
        /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING'/fcg' */
    } else {
        rtb_DataTypeConversion_jq = (uint8)((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_TJALKA_DrvStInvalidSR_btm())) != 0);
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_jq = (uint8)(!(((sint32)rtb_DataTypeConversion_jq) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionsCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionsCheck/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionsCheck/AND2/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionsCheck/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionsCheck/NEQ/Functionality'/NE'
         */
    rtb_DataTypeConversion_au = (uint8)(!((((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0) && (((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)) != ((sint32) GET_S_TJASTM_LatCtrlMode_nu()))));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/OR/Functionality'/OR'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT17/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/OR/Functionality'/OR'
         *  MinMax: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/Max/Functionality'/Max'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck'/Unit_Delay'
         */
    if (((!(((sint32)rtb_DataTypeConversion_jq) != 0)) || (!(((sint32) rtb_DataTypeConversion_au) != 0))) || (((sint32) rtb_DataTypeConversion_fw) != 0)) {
        rtb_Switch2_eh = f32_max_f32_f32(GET_S_LCFRCV_SysCycleTimeSen_sec(), GET_P_TJALKA_BlockTimeTJA_sec());
    } else if (DW_tjalka_Unit_Delay_DSTATE > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck'/Unit_Delay'
                 */
        rtb_Switch2_eh = DW_tjalka_Unit_Delay_DSTATE - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_eh = 0.0F;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_gg = (uint8)(!(rtb_Switch2_eh > 0.0F));
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch2'/copy1' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/Constant1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/constant_value1'/Constant'
         *  DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/AND1/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/EQ1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/AND2/Functionality'/AND'
         */
    SET_S_TJALKA_WeakReady_bool((uint8)((((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_TJALKA_PrjSpecQuWR_btm())) == 0) && (((sint32) rtb_DataTypeConversion_d) != 0)) && (((sint32)rtb_DataTypeConversion_gg) != 0)));
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/GE2/Functionality'/GE' incorporates:
                                            *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/Constant1'/Constant'
                                            *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
                                            *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
                                            */
    rtb_GE[0] = (sint8)(((sint32)GET_S_ABPLBP_LeLnQuality_perc()) >= ((sint32) GET_P_TJALKA_LaneQualityMin_perc()));
    rtb_GE[1] = (sint8)(((sint32)GET_S_ABPLBP_RiLnQuality_perc()) >= ((sint32) GET_P_TJALKA_LaneQualityMin_perc()));
    /* Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/Constant1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/Constant2'/Constant'
         */
    rtb_DataTypeConversion_g4 = u8_u32(((uint32) GET_P_TJALKA_LaneQualityHyst_perc()) + ((uint32)((sint32) GET_P_TJALKA_LaneQualityMin_perc())));
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/GE1/Functionality'/GE' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         */
    rtb_GE_k[0] = (sint8)(((sint32)GET_S_ABPLBP_LeLnQuality_perc()) >= ((sint32) rtb_DataTypeConversion_g4));
    rtb_GE_k[1] = (sint8)(((sint32)GET_S_ABPLBP_RiLnQuality_perc()) >= ((sint32) rtb_DataTypeConversion_g4));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Constant1'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Constant1'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Logical Operator'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Relational Operator1'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay4'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay5'
         */
    for (i = 0; i < 2; i++) {
        if (!((((sint32)rtb_GE[i]) != 0) || (DW_tjalka_Unit_Delay4_DSTATE[i] > 0.0F))) {
            rtb_Switch_l[i] = 0U;
        } else if ((DW_tjalka_Unit_Delay2_DSTATE[i] <= 0.0F) && (((sint32)rtb_GE_k[i]) != 0)) {
            /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/RSFLIPFLOP/Functionality'/Constant1'
                         */
            rtb_Switch_l[i] = 1U;
        } else {
            rtb_Switch_l[i] = DW_tjalka_Unit_Delay5_DSTATE[i];
        }
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/RSFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_g4 = (uint8)((((sint32)rtb_Switch_l[0]) != 0) || (((sint32)rtb_DataTypeConversion_az) != 0));
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/Constant4'/Constant'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck'/Unit_Delay1'
         */
    LogicalOperator = (uint8)((!(((sint32)DW_tjalka_Unit_Delay1_DSTATE_c) != 0)) && (((sint32)GET_P_TJALKA_InjectLaneError_bool()) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING'/fcg' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/Constant3'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/constant_value1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/constant_value2'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/constant_value4'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  S-Function (sfix_bitop): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/AND2/Functionality'/AND'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck'/Unit_Delay2'
         */
    if ((((sint32)LogicalOperator) != 0) || (DW_tjalka_Unit_Delay2_DSTATE_b > 0.0F)) {
        rtb_Switch_ht_idx_0 = 0U;
        rtb_Switch_ht_idx_1 = 0U;
    } else {
        rtb_Switch_ht_idx_0 = (uint8)((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32)GET_P_TJALKA_LaneValid_btm())) == 0);
        rtb_Switch_ht_idx_1 = (uint8)((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32)GET_P_TJALKA_LaneValid_btm())) == 0);
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/Constant1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/constant_value3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Inport: '<Root>/S_ABPLBP_RiUncoupBrid_bool'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/NEQ/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion_je = (uint8)((((sint32)GET_S_ABPLBP_RiUncoupBrid_bool ()) != 0) || ((((sint32)GET_P_TJALKA_LaneVirtOrBridged_btm()) & ((sint32) GET_S_ABPLBP_LeLnInvalidQu_btf())) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/AND/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_kj = (uint8)(((((sint32)rtb_DataTypeConversion_g4) != 0) && (((sint32)rtb_Switch_ht_idx_0) != 0)) || (((sint32) rtb_DataTypeConversion_je) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_me = (uint8)((((sint32)rtb_Switch_l[1]) != 0) || (((sint32)rtb_DataTypeConversion_az) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/AND1/Functionality'/AND'
         */
    rtb_DataTypeConversion_f = (uint8)((((sint32)rtb_DataTypeConversion_me) != 0) && (((sint32)rtb_Switch_ht_idx_1) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/Constant1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/constant_value3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeUncoupBrid_bool'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/NEQ/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion_c = (uint8)((((sint32)GET_S_ABPLBP_LeUncoupBrid_bool()) != 0) || ((((sint32)GET_P_TJALKA_LaneVirtOrBridged_btm()) & ((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf())) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_crf = (uint8)((((sint32)rtb_DataTypeConversion_f) != 0) || (((sint32)rtb_DataTypeConversion_c) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/AND6/Functionality'/AND'
         */
    rtb_DataTypeConversion_f = (uint8)((((sint32)rtb_DataTypeConversion_kj) != 0) && (((sint32)rtb_DataTypeConversion_crf) != 0));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/from_data_definition5'/state_source'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_f) != 0) {
        rtb_DataTypeConversion_kj = ((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE);
    } else if (((sint32)rtb_DataTypeConversion_kj) != 0) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_kj = ((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY);
    } else if (((sint32)rtb_DataTypeConversion_crf) != 0) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/from_data_definition2'/state_source'
                 *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch1/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_kj = ((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY);
    } else {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/from_data_definition4'/state_source'
                 *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch2/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_kj = ((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID);
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneBoundaryQualifier/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EQ4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/from_data_definition4'/state_source'
         */
    rtb_DataTypeConversion_f = (uint8)(((sint32)((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE)) == ((sint32) rtb_DataTypeConversion_kj));
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    rtb_DataTypeConversion_crf = (uint8)(((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/from_data_definition3'/state_source'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/AND/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EQ3/Functionality'/EQ'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay3'
         */
    rtb_DataTypeConversion_o = (uint8)(((((sint32)rtb_DataTypeConversion_crf) != 0) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))) && (((sint32)((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE)) == ((sint32) DW_tjalka_Unit_Delay3_DSTATE)));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/Abs/Functionality'/Abs'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/Constant1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/Constant2'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/from_data_definition1'/state_source'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Constant1'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/AND1/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/AND3/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay1'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay2'
         */
    rtb_DataTypeConversion_n = (uint8)(((((((!(((sint32) rtb_DataTypeConversion_je) != 0)) && (!(((sint32)rtb_DataTypeConversion_c) != 0))) && (((sint32)GET_P_TJALKA_BothSideBrdgEnable_bool()) != 0)) && (f32_abs_f32(DW_tjalka_Unit_Delay1_DSTATE) < GET_P_TJALKA_LnPredictionCrvMax_1pm())) && (((sint32) rtb_DataTypeConversion_crf) != 0)) && ((DW_tjalka_Unit_Delay2_DSTATE_n <= 0.0F) && (((sint32)rtb_DataTypeConversion_o) != 0))) && (((sint32)((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID)) == ((sint32) rtb_DataTypeConversion_kj)));
    /* Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime'/Unit_Delay1'
         */
    rtb_LogicalOperator_p = (uint8)((((sint32)rtb_DataTypeConversion_n) != 0) || (DW_tjalka_Unit_Delay1_DSTATE_i > 0.0F));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAOBF_Cancel_bool'
         *  Inport: '<Root>/S_TJAOBF_StrongReady_bool'
         *  Inport: '<Root>/S_TJAOBF_WeakReady_bool'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/AND2/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/NOT3/Functionality'/NOT'
         */
    rtb_DataTypeConversion_i = (uint8)(((((sint32)GET_S_TJAOBF_StrongReady_bool()) != 0) && (((sint32)GET_S_TJAOBF_WeakReady_bool()) != 0)) && (!(((sint32) GET_S_TJAOBF_Cancel_bool()) != 0)));
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/RSFLIPFLOP/Functionality'/Constant'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/NOT2/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/OR1/Functionality'/OR'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality'/Logical Operator1'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality/Comparison'/Logical Operator'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay5'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime'/Unit_Delay4'
         */
    if (((((((sint32)DW_tjalka_Unit_Delay4_DSTATE_h) != 0) && (!(((sint32) rtb_LogicalOperator_p) != 0))) || (!(((sint32) rtb_DataTypeConversion_crf) != 0))) || (((sint32) rtb_DataTypeConversion_f) != 0)) || ((!(((sint32) DW_tjalka_Unit_Delay_DSTATE_a) != 0)) && (((sint32) rtb_DataTypeConversion_i) != 0))) {
        rtb_Switch_k = 0U;
    } else if (((sint32)rtb_DataTypeConversion_n) != 0) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_k = 1U;
    } else {
        rtb_Switch_k = DW_tjalka_Unit_Delay5_DSTATE_b;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/RSFLIPFLOP/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1'/fcg' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/OR3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/OR3/Functionality'/OR'
         */
    rtb_DataTypeConversion_ir = (uint8)((((sint32)rtb_DataTypeConversion_f) != 0) || (((sint32)rtb_Switch_k) != 0));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/Constant6'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/Constant7'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/Sum/Functionality'/Sum'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering'/Unit_Delay'
         */
    if (GET_S_LCFRCV_VDy_VehVelocity_kph() > (GET_P_TJALKA_VelXMax_kph() + GET_P_TJALKA_VelXHyst_kph())) {
        rtb_Switch3 = 1U;
    } else if (GET_S_LCFRCV_VDy_VehVelocity_kph() < GET_P_TJALKA_VelXMax_kph()) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3 = 0U;
    } else {
        rtb_Switch3 = DW_tjalka_Unit_Delay_DSTATE_bh;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS/Functionality'/Switch3' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/Constant1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/Constant8'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/Sum2/Functionality'/Sum'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering'/Unit_Delay2'
         */
    if (GET_S_LCFRCV_VDy_VehVelocity_kph() > GET_P_TJALKA_VelXMin_kph()) {
        rtb_Switch3_i = 1U;
    } else if (GET_S_LCFRCV_VDy_VehVelocity_kph() < (GET_P_TJALKA_VelXMin_kph() - GET_P_TJALKA_VelXHyst_kph())) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3_i = 0U;
    } else {
        rtb_Switch3_i = DW_tjalka_Unit_Delay2_DSTATE_i;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/HYSTERESIS2/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/AND/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_crf = (uint8)((!(((sint32)rtb_Switch3) != 0)) && (((sint32)rtb_Switch3_i) != 0));
    /* Abs: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         */
    rtb_Switch4_l[0] = f32_abs_f32(GET_S_ABPLBP_LeLnClthPosY0_met());
    rtb_Switch4_l[1] = f32_abs_f32(GET_S_ABPLBP_RiLnClthPosY0_met());
    /* Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/Constant3'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/Constant4'/Constant'
         */
    rtb_Sum_fd = GET_P_TJALKA_DistVeh2LnBndMin_met() + GET_P_TJALKA_DistVeh2LnBndHyst_met();
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/Constant3'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck'/Unit_Delay3'
         */
    for (i = 0; i < 2; i++) {
        if (rtb_Switch4_l[i] > rtb_Sum_fd) {
            rtb_Switch3_g[i] = 1U;
        } else if (rtb_Switch4_l[i] < GET_P_TJALKA_DistVeh2LnBndMin_met()) {
            /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Constant'
                         */
            rtb_Switch3_g[i] = 0U;
        } else {
            rtb_Switch3_g[i] = DW_tjalka_Unit_Delay3_DSTATE_i[i];
        }
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Switch3' */
    /* S-Function (sfun_and): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/AND1/Functionality'/sfun_and' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_Switch3_g[0];
        for (i1=1; i1 < 2; i1++) {
            temp = temp && rtb_Switch3_g[i1];
        }
        rtb_DataTypeConversion_f = temp;
    }
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/LT/Functionality'/LT'
         */
    rtb_DataTypeConversion_f = (uint8)(((((sint32)rtb_DataTypeConversion_f) != 0) && (GET_S_ABPLBP_LeLnClthPosY0_met() > 0.0F)) && (GET_S_ABPLBP_RiLnClthPosY0_met() < 0.0F));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_f = (uint8)(((((sint32)rtb_DataTypeConversion_f) != 0) || (((sint32)rtb_DataTypeConversion_az) != 0)) || (((sint32)rtb_Switch_k) != 0));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/P_LDPSA_VelXMax_mps2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         */
    if (((sint32)GET_P_TJALKA_MaxLnWdthUseCoup_bool()) != 0) {
        rtb_Sum_fd = GET_S_ABPLBP_CoupledLaneWidth_met();
    } else {
        rtb_Sum_fd = GET_S_ABPLBP_LaneWidth_met();
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/P_LDPSA_VelXHyst_mps4'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/P_LDPSA_VelXMax_mps3'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/Add2/Functionality'/Sum'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck'/Unit_Delay'
         */
    if (rtb_Sum_fd > (GET_P_TJALKA_LaneWidthMax_met() + GET_P_TJALKA_LaneWidthHyst_met())) {
        rtb_Switch3_f = 1U;
    } else if (rtb_Sum_fd < GET_P_TJALKA_LaneWidthMax_met()) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_f = 0U;
    } else {
        rtb_Switch3_f = DW_tjalka_Unit_Delay_DSTATE_n;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS1/Functionality'/Switch3' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/P_LDPSA_VelXMax_mps1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_ABPLBP_UncoupledLaneWidth_met'
         */
    if (((sint32)GET_P_TJALKA_MinLnWdthUseUncoup_bool()) != 0) {
        rtb_Sum_fd = GET_S_ABPLBP_UncoupledLaneWidth_met();
    } else {
        rtb_Sum_fd = GET_S_ABPLBP_LaneWidth_met();
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/P_LDPSA_VelXMin_mps3'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS2/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/Add3/Functionality'/Sum'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck'/Unit_Delay1'
         */
    if (rtb_Sum_fd > GET_P_TJALKA_LaneWidthMin_met()) {
        rtb_Switch3_or = 1U;
    } else if (rtb_Sum_fd < (GET_P_TJALKA_LaneWidthMin_met() - GET_P_TJALKA_LaneWidthHyst_met())) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3_or = 0U;
    } else {
        rtb_Switch3_or = DW_tjalka_Unit_Delay1_DSTATE_e;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/HYSTERESIS2/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_oo = (uint8)(((!(((sint32)rtb_Switch3_f) != 0)) && (((sint32)rtb_Switch3_or) != 0)) || (((sint32)rtb_Switch_k) != 0));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/Div/Functionality/DivDefault'/Switch' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/Constant'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/Div/In3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthCrv_1pm'
         *  Product: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/Div/Functionality/DivDefault'/Div'
         */
    if (GET_S_ABPLBP_CntrLnClthCrv_1pm() != 0.0F) {
        rtb_Sum_fd = 1.0F / GET_S_ABPLBP_CntrLnClthCrv_1pm();
    } else {
        rtb_Sum_fd = 10000.0F;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/Div/Functionality/DivDefault'/Switch' */
    /* Abs: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/Abs/Functionality'/Abs' */
    rtb_Sum_fd = f32_abs_f32(rtb_Sum_fd);
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/P_LDPSA_VelXHyst_mps4'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/P_LDPSA_VelXMax_mps3'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/HYSTERESIS1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/Add2/Functionality'/Sum'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck'/Unit_Delay'
         */
    if (rtb_Sum_fd > (GET_P_TJALKA_RadiusMin_met() + GET_P_TJALKA_RadiusHyst_met())) {
        rtb_Switch3_j = 1U;
    } else if (rtb_Sum_fd < GET_P_TJALKA_RadiusMin_met()) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_j = 0U;
    } else {
        rtb_Switch3_j = DW_tjalka_Unit_Delay_DSTATE_j;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/HYSTERESIS1/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)rtb_Switch3_j) != 0) || (((sint32)rtb_Switch_k) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/ConstructionSiteCheck/NOT12/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/ConstructionSiteCheck/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/ConstructionSiteCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/ConstructionSiteCheck/NOT12/Functionality'/NOT'
         */
    rtb_DataTypeConversion_e = (uint8)(!((((sint32) GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32) GET_P_TJALKA_ConstSiteCheckOn_bool()) != 0)));
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/Constant8'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/constant_value4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CustomSpecificQualifiersCheck/AND1/Functionality'/AND'
         */
    rtb_DataTypeConversion_b1 = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_TJALKA_PrjSpecQuSR_btm())) == 0);
    /* Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/Add2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/P_LDPSA_VelXHyst_mps4'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/P_LDPSA_VelXMax_mps3'/Constant'
         */
    rtb_Sum_fd = GET_P_TJALKA_ValidLengthMin_met() - GET_P_TJALKA_ValidLengthMinHyst_met();
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/P_LDPSA_VelXMax_mps3'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Constant1'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthLength_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck'/Unit_Delay'
         */
    if (GET_S_ABPLBP_CntrLnClthLength_met() > GET_P_TJALKA_ValidLengthMin_met()) {
        rtb_Switch3_o2[0] = 1U;
    } else if (GET_S_ABPLBP_CntrLnClthLength_met() < rtb_Sum_fd) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_o2[0] = 0U;
    } else {
        rtb_Switch3_o2[0] = DW_tjalka_Unit_Delay_DSTATE_bl[0];
    }
    if (GET_S_ABPLBP_RiLnClthLength_met() > GET_P_TJALKA_ValidLengthMin_met()) {
        rtb_Switch3_o2[1] = 1U;
    } else if (GET_S_ABPLBP_RiLnClthLength_met() < rtb_Sum_fd) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_o2[1] = 0U;
    } else {
        rtb_Switch3_o2[1] = DW_tjalka_Unit_Delay_DSTATE_bl[1];
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/HYSTERESIS1/Functionality'/Switch3' */
    /* S-Function (sfun_and): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/AND/Functionality'/sfun_and' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_Switch3_o2[0];
        for (i1=1; i1 < 2; i1++) {
            temp = temp && rtb_Switch3_o2[i1];
        }
        rtb_DataTypeConversion_b = temp;
    }
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_b = (uint8)((((sint32)rtb_DataTypeConversion_b) != 0) || (((sint32)rtb_Switch_k) != 0));
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch3'/copy1' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/Constant1'/Constant'
         *  DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/AND3/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/AND3/Functionality'/AND'
         */
    SET_S_TJALKA_StrongReady_bool((uint8)(((((((((((((sint32) rtb_DataTypeConversion_ir) != 0) && (((sint32)rtb_DataTypeConversion_crf) != 0)) && (((sint32)rtb_DataTypeConversion_f) != 0)) && (((sint32) rtb_DataTypeConversion_oo) != 0)) && (((sint32)rtb_DataTypeConversion_le) != 0)) && (((sint32)rtb_DataTypeConversion_jq) != 0)) && (((sint32) rtb_DataTypeConversion_e) != 0)) && (((sint32)GET_P_TJALKA_LC_Enabled_bool()) != 0)) && (((sint32)rtb_DataTypeConversion_b1) != 0)) && (((sint32) rtb_DataTypeConversion_au) != 0)) && (((sint32)rtb_DataTypeConversion_b) != 0)));
    /* Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/Constant'/Constant' */
    rtb_VectorConcatenate[9] = 0U;
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MappingUint16'/ConcatBufferAtVector ConcatenateIn15' */
    rtb_VectorConcatenate[14] = rtb_NE_c;
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MappingUint16'/ConcatBufferAtVector ConcatenateIn16' */
    rtb_VectorConcatenate[15] = rtb_DataTypeConversion_fw;
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_ir) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate[1] = (uint8)(!(((sint32)rtb_DataTypeConversion_crf) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate[2] = (uint8)(!(((sint32)rtb_DataTypeConversion_f) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate[3] = (uint8)(!(((sint32)rtb_DataTypeConversion_oo) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate[4] = (uint8)(!(((sint32)rtb_DataTypeConversion_le) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate[5] = (uint8)(!(((sint32)rtb_DataTypeConversion_jq) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate[6] = (uint8)(!(((sint32)rtb_DataTypeConversion_e) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/Constant1'/Constant'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT9/Functionality'/NOT'
         */
    rtb_VectorConcatenate[7] = (uint8)(!(((sint32)GET_P_TJALKA_LC_Enabled_bool()) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT13/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT13/Functionality'/NOT'
         */
    rtb_VectorConcatenate[8] = (uint8)(!(((sint32)rtb_DataTypeConversion_b1) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT16/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT16/Functionality'/NOT'
         */
    rtb_VectorConcatenate[10] = (uint8)(!(((sint32)rtb_DataTypeConversion_au) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT10/Functionality'/NOT'
         */
    rtb_VectorConcatenate[11] = (uint8)(!(((sint32)rtb_DataTypeConversion_b) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT11/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT11/Functionality'/NOT'
         */
    rtb_VectorConcatenate[12] = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/NOT8/Functionality'/NOT'
         */
    rtb_VectorConcatenate[13] = (uint8)(!(((sint32)rtb_DataTypeConversion_gg) != 0));
    /* S-Function (sfun_setbit): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
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
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay2'
                 */
        if (DW_tjalka_Unit_Delay2_DSTATE_n > 0.0F) {
            /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjalka_Unit_Delay2_DSTATE_n -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/Constant3'/Constant'
                 */
        DW_tjalka_Unit_Delay2_DSTATE_n = GET_P_TJALKA_LnPredMinValidTime_sec();
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/TURNONDELAYTIME/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         */
    rtb_DataTypeConversion_b = (uint8)(((sint32)GET_S_ABPLBP_LeLnQuality_perc()) < ((sint32)GET_P_TJACMB_LnQualMinCurve_perc()));
    /* Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck'/Unit_Delay4'
         */
    rtb_DataTypeConversion_b1 = (uint8)((DW_tjalka_Unit_Delay4_DSTATE_d <= 0.0F) && (((sint32)rtb_DataTypeConversion_b) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_e = (uint8)(!(((sint32)rtb_DataTypeConversion_je) != 0));
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         */
    rtb_DataTypeConversion_le = (uint8)(((sint32)GET_S_ABPLBP_RiLnQuality_perc()) < ((sint32)GET_P_TJACMB_LnQualMinCurve_perc()));
    /* Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck'/Unit_Delay4'
         */
    rtb_DataTypeConversion_oo = (uint8)((DW_tjalka_Unit_Delay4_DSTATE_p <= 0.0F) && (((sint32)rtb_DataTypeConversion_le) != 0));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_e) != 0) {
        rtb_DataTypeConversion_o = rtb_DataTypeConversion_b1;
    } else {
        rtb_DataTypeConversion_o = rtb_DataTypeConversion_oo;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch4/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_c) == 0) {
        rtb_DataTypeConversion_b1 = rtb_DataTypeConversion_oo;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_b1 = (uint8)((((sint32)rtb_DataTypeConversion_o) != 0) && (((sint32)rtb_DataTypeConversion_b1) != 0));
    /* Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck'/Unit_Delay1'
         */
    i = ((sint32)DW_tjalka_Unit_Delay1_DSTATE_j) - ((sint32) GET_S_ABPLBP_LeLnQuality_perc());
    if (i < 0) {
        i = 0;
    }
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Constant2'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Constant3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/LT1/Functionality'/LT'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Sum/Functionality'/Sum'
         */
    rtb_DataTypeConversion_oo = (uint8)((((sint32)GET_S_ABPLBP_LeLnQuality_perc()) < ((sint32)GET_P_TJACMB_LnQualMinExit_perc())) || (i > ((sint32) GET_P_TJACMB_LnQualGradMaxExit_perc())));
    /* Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck'/Unit_Delay1'
         */
    i = ((sint32)DW_tjalka_Unit_Delay1_DSTATE_cp) - ((sint32) GET_S_ABPLBP_RiLnQuality_perc());
    if (i < 0) {
        i = 0;
    }
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Constant2'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Constant3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/LT1/Functionality'/LT'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Sum/Functionality'/Sum'
         */
    rtb_DataTypeConversion_o = (uint8)((((sint32)GET_S_ABPLBP_RiLnQuality_perc()) < ((sint32)GET_P_TJACMB_LnQualMinExit_perc())) || (i > ((sint32) GET_P_TJACMB_LnQualGradMaxExit_perc())));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_e) != 0) {
        rtb_DataTypeConversion_ir = rtb_DataTypeConversion_oo;
    } else {
        rtb_DataTypeConversion_ir = rtb_DataTypeConversion_o;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch5/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_c) == 0) {
        rtb_DataTypeConversion_oo = rtb_DataTypeConversion_o;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch5/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_oo = (uint8)((((sint32)rtb_DataTypeConversion_ir) != 0) || (((sint32)rtb_DataTypeConversion_oo) != 0));
    /* Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck'/Unit_Delay2'
         */
    i = ((sint32)DW_tjalka_Unit_Delay2_DSTATE_e) - ((sint32) GET_S_ABPLBP_LeLnQuality_perc());
    if (i < 0) {
        i = 0;
    }
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Constant4'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Constant5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/LT2/Functionality'/LT'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Sum1/Functionality'/Sum'
         */
    rtb_DataTypeConversion_o = (uint8)((((sint32)GET_S_ABPLBP_LeLnQuality_perc()) < ((sint32)GET_P_TJACMB_LnQualMinExit_perc())) || (i > ((sint32) GET_P_TJACMB_LnQualGradMaxExit_perc())));
    /* Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck'/Unit_Delay2'
         */
    i = ((sint32)DW_tjalka_Unit_Delay2_DSTATE_d) - ((sint32) GET_S_ABPLBP_RiLnQuality_perc());
    if (i < 0) {
        i = 0;
    }
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Constant4'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Constant5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/LT2/Functionality'/LT'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Sum1/Functionality'/Sum'
         */
    rtb_DataTypeConversion_ir = (uint8)((((sint32)GET_S_ABPLBP_RiLnQuality_perc()) < ((sint32)GET_P_TJACMB_LnQualMinExit_perc())) || (i > ((sint32) GET_P_TJACMB_LnQualGradMaxExit_perc())));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch2/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_e) != 0) {
        rtb_DataTypeConversion_crf = rtb_DataTypeConversion_o;
    } else {
        rtb_DataTypeConversion_crf = rtb_DataTypeConversion_ir;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch6/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_c) == 0) {
        rtb_DataTypeConversion_o = rtb_DataTypeConversion_ir;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch6/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/AND1/Functionality'/AND'
         */
    rtb_DataTypeConversion_o = (uint8)((((sint32)rtb_DataTypeConversion_crf) != 0) && (((sint32)rtb_DataTypeConversion_o) != 0));
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/LT3/Functionality'/LT' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Constant6'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         */
    rtb_DataTypeConversion_ir = (uint8)(((sint32)GET_S_ABPLBP_LeLnQuality_perc()) < ((sint32)GET_P_TJACMB_LnQualMinContrast_perc()));
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/LT3/Functionality'/LT' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Constant6'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         */
    rtb_DataTypeConversion_crf = (uint8)(((sint32)GET_S_ABPLBP_RiLnQuality_perc()) < ((sint32)GET_P_TJACMB_LnQualMinContrast_perc()));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch3/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_e) != 0) {
        rtb_DataTypeConversion_e = rtb_DataTypeConversion_ir;
    } else {
        rtb_DataTypeConversion_e = rtb_DataTypeConversion_crf;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch7/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_c) == 0) {
        rtb_DataTypeConversion_ir = rtb_DataTypeConversion_crf;
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/Switch7/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_e = (uint8)((((sint32)rtb_DataTypeConversion_e) != 0) && (((sint32)rtb_DataTypeConversion_ir) != 0));
    /* Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/Constant1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/Constant2'/Constant'
         */
    i = ((sint32)GET_P_TJACMB_LnQualMinWR_perc()) - ((sint32) GET_P_TJACMB_LnQualMinHystWR_perc());
    if (i < 0) {
        i = 0;
    }
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/Constant1'/Constant'
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Constant1'
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/Sum3/Functionality'/Sum'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck'/Unit_Delay1'
         */
    if (((sint32)GET_S_ABPLBP_LeLnQuality_perc()) > ((sint32) GET_P_TJACMB_LnQualMinWR_perc())) {
        rtb_Switch2_g[0] = 1U;
    } else if (((sint32)GET_S_ABPLBP_LeLnQuality_perc()) < ((sint32)((uint8)i))) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch2_g[0] = 0U;
    } else {
        rtb_Switch2_g[0] = DW_tjalka_Unit_Delay1_DSTATE_ju[0];
    }
    if (((sint32)GET_S_ABPLBP_RiLnQuality_perc()) > ((sint32) GET_P_TJACMB_LnQualMinWR_perc())) {
        rtb_Switch2_g[1] = 1U;
    } else if (((sint32)GET_S_ABPLBP_RiLnQuality_perc()) < ((sint32)((uint8)i))) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch2_g[1] = 0U;
    } else {
        rtb_Switch2_g[1] = DW_tjalka_Unit_Delay1_DSTATE_ju[1];
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/HYSTERESIS/Functionality'/Switch3' */
    /* Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck'/Unit_Delay2'
         */
    for (i = 0; i < 2; i++) {
        rtb_LogicalOperator_nq[i] = (sint8)((DW_tjalka_Unit_Delay2_DSTATE_j[i] <= 0.0F) && (((sint32)rtb_Switch2_g[i]) != 0));
    }
    /* End of Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Logical Operator' */
    /* RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/from_data_definition5'/state_source'
         */
    rtb_DataTypeConversion_f = (uint8)(((sint32)rtb_DataTypeConversion_kj) == ((sint32)((uint8)E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE)));
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch8'/copy1' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/Constant3'/Constant'
         *  DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/AND2/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/AND2/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/OR/Functionality'/OR'
         */
    SET_S_TJALKA_CombinedLaneSR_bool((uint8)((!((((sint32) GET_P_TJACMB_LnQualShutOffQulOn_bool()) != 0) && ((((((sint32) rtb_DataTypeConversion_b1) != 0) || (((sint32)rtb_DataTypeConversion_oo) != 0)) || (((sint32)rtb_DataTypeConversion_o) != 0)) || (((sint32) rtb_DataTypeConversion_e) != 0)))) && (((sint32)rtb_DataTypeConversion_f) != 0)));
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_b) != 0) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck'/Unit_Delay4'
                 */
        if (DW_tjalka_Unit_Delay4_DSTATE_d > 0.0F) {
            /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck'/Unit_Delay4' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjalka_Unit_Delay4_DSTATE_d -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck'/Unit_Delay4' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/Constant7'/Constant'
                 */
        DW_tjalka_Unit_Delay4_DSTATE_d = GET_P_TJACMB_LnQualMinOnTmCurve_sec();
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_le) != 0) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck'/Unit_Delay4'
                 */
        if (DW_tjalka_Unit_Delay4_DSTATE_p > 0.0F) {
            /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck'/Unit_Delay4' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjalka_Unit_Delay4_DSTATE_p -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck'/Unit_Delay4' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/Constant7'/Constant'
                 */
        DW_tjalka_Unit_Delay4_DSTATE_p = GET_P_TJACMB_LnQualMinOnTmCurve_sec();
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck/TURNONDELAYTIME/Functionality'/Switch2' */
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/Constant3'/Constant'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/NOT1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_b = (uint8)(!(((sint32) GET_P_TJACMB_LnQualShutOffQulOn_bool()) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_le = (uint8)(!(((sint32)rtb_DataTypeConversion_f) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_f = (uint8)(!(((sint32)rtb_DataTypeConversion_b) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND4/Functionality'/AND'
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/NOT1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_f = (uint8)((((sint32)rtb_DataTypeConversion_f) != 0) && (!(((sint32)rtb_DataTypeConversion_le) != 0)));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND/Functionality'/AND'
         */
    rtb_VectorConcatenate_h[9] = (uint8)((((sint32)rtb_DataTypeConversion_e) != 0) && (((sint32)rtb_DataTypeConversion_f) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND1/Functionality'/AND'
         */
    rtb_VectorConcatenate_h[10] = (uint8)((((sint32)rtb_DataTypeConversion_o) != 0) && (((sint32)rtb_DataTypeConversion_f) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND2/Functionality'/AND'
         */
    rtb_VectorConcatenate_h[11] = (uint8)((((sint32)rtb_DataTypeConversion_oo) != 0) && (((sint32)rtb_DataTypeConversion_f) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/AND3/Functionality'/AND'
         */
    rtb_VectorConcatenate_h[12] = (uint8)((((sint32)rtb_DataTypeConversion_b1) != 0) && (((sint32)rtb_DataTypeConversion_f) != 0));
    /* Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/Constant'/Constant' */
    rtb_VectorConcatenate_h[15] = 0U;
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn14' */
    rtb_VectorConcatenate_h[13] = rtb_DataTypeConversion_b;
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn15' */
    rtb_VectorConcatenate_h[14] = rtb_DataTypeConversion_le;
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_h[4] = rtb_DataTypeConversion_je;
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_h[5] = rtb_DataTypeConversion_c;
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_h[6] = rtb_DataTypeConversion_az;
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_h[7] = (uint8)rtb_LogicalOperator_nq[0];
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn9' */
    rtb_VectorConcatenate_h[8] = (uint8)rtb_LogicalOperator_nq[1];
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[0] = (uint8)(!(((sint32)rtb_Switch_ht_idx_0) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[1] = (uint8)(!(((sint32)rtb_Switch_ht_idx_1) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[2] = (uint8)(!(((sint32)rtb_DataTypeConversion_g4) != 0));
    /* DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[3] = (uint8)(!(((sint32)rtb_DataTypeConversion_me) != 0));
    /* S-Function (sfun_setbit): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/Debug/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_h[0];
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
        rtb_sfun_setbit_c = temp;
    }
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch1'/copy1' */
    SET_S_TJALKA_Cancel_bool(rtb_DataTypeConversion_fw);
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch4'/copy1' */
    SET_D_TJALKA_LaneCenterInvalid_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch5'/copy1' */
    SET_S_TJALKA_LnBndValid_nu(rtb_DataTypeConversion_kj);
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch6'/copy1' */
    SET_D_TJALKA_LaneInvalid_btf(rtb_sfun_setbit_c);
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch7'/copy1' */
    SET_S_TJALKA_LanePredictValid_bool(rtb_Switch_k);
    /* SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/branch9'/copy1' incorporates:
                                                        *  DataTypeConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/AND1/Functionality'/Data Type Conversion'
                                                        *  Logic: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/AND1/Functionality'/AND'
                                                        */
    SET_S_TJALKA_CombinedLaneWR_bool((uint8)((((sint32)rtb_LogicalOperator_nq[0]) != 0) && (((sint32)rtb_LogicalOperator_nq[1]) != 0)));
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/CheckTrajPlanStatusQualifier'/Unit_Delay' */
    DW_tjalka_Unit_Delay_DSTATE_o = rtb_DataTypeConversion_jw;
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck'/Unit_Delay' incorporates:
         *  Inport: '<Root>/S_LCFRCV_TurnSignalLeverHold_bool'
         */
    DW_tjalka_Unit_Delay_DSTATE_b = GET_S_LCFRCV_TurnSignalLeverHold_bool();
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/TurnSignalCheck/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/BlockingTimeConditionCheck'/Unit_Delay' */
    DW_tjalka_Unit_Delay_DSTATE = rtb_Switch2_eh;
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck'/Unit_Delay1' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/Constant4'/Constant'
         *  SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjalka_Unit_Delay1_DSTATE_c = GET_P_TJALKA_InjectLaneError_bool();
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/EDGERISING'/fcg' */
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck'/Unit_Delay2'
         */
    if (((sint32)LogicalOperator) != 0) {
        /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/Constant2'/Constant'
                 */
        DW_tjalka_Unit_Delay2_DSTATE_b = GET_P_TJALKA_LaneInvalidTime_sec();
    } else {
        if (DW_tjalka_Unit_Delay2_DSTATE_b > 0.0F) {
            /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck'/Unit_Delay2'
                         *  Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck'/Unit_Delay2'
                         */
            DW_tjalka_Unit_Delay2_DSTATE_b -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualifierCheck/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_ABPLBP_CntrLnClthCrv_1pm'
         */
    DW_tjalka_Unit_Delay1_DSTATE = GET_S_ABPLBP_CntrLnClthCrv_1pm();
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay3' */
    DW_tjalka_Unit_Delay3_DSTATE = rtb_DataTypeConversion_kj;
    /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_n) != 0) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/Constant1'/Constant'
                 */
        if (((sint32)GET_P_TJALKA_RampoutPredictOn_bool()) != 0) {
            /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime'/Unit_Delay1' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/Constant5'/Constant'
                         */
            DW_tjalka_Unit_Delay1_DSTATE_i = GET_P_TJALKA_LnPredictionTimeMin_sec();
        } else {
            /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime'/Unit_Delay1' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/Constant3'/Constant'
                         */
            DW_tjalka_Unit_Delay1_DSTATE_i = GET_P_TJALKA_LnPredictionTimeMax_sec();
        }
        /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/Switch/Functionality'/Switch' */
    } else {
        if (DW_tjalka_Unit_Delay1_DSTATE_i > 0.0F) {
            /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime'/Unit_Delay1'
                         *  Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime'/Unit_Delay1'
                         */
            DW_tjalka_Unit_Delay1_DSTATE_i -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1'/fcg' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjalka_Unit_Delay4_DSTATE_h = rtb_LogicalOperator_p;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/PredictionTime/EDGEFALLING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjalka_Unit_Delay_DSTATE_a = rtb_DataTypeConversion_i;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/BothSidedBridging'/Unit_Delay5' */
    DW_tjalka_Unit_Delay5_DSTATE_b = rtb_Switch_k;
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering'/Unit_Delay' */
    DW_tjalka_Unit_Delay_DSTATE_bh = rtb_Switch3;
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/VehicleVelocityCheck_LaneCentering'/Unit_Delay2' */
    DW_tjalka_Unit_Delay2_DSTATE_i = rtb_Switch3_i;
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck'/Unit_Delay' */
    DW_tjalka_Unit_Delay_DSTATE_n = rtb_Switch3_f;
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/LaneWidthCheck'/Unit_Delay1' */
    DW_tjalka_Unit_Delay1_DSTATE_e = rtb_Switch3_or;
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinRadiusCheck'/Unit_Delay' */
    DW_tjalka_Unit_Delay_DSTATE_j = rtb_Switch3_j;
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         */
    DW_tjalka_Unit_Delay1_DSTATE_j = GET_S_ABPLBP_LeLnQuality_perc();
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         */
    DW_tjalka_Unit_Delay1_DSTATE_cp = GET_S_ABPLBP_RiLnQuality_perc();
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/LeftLaneCheck'/Unit_Delay2' incorporates:
         *  Update for Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         */
    DW_tjalka_Unit_Delay2_DSTATE_e = GET_S_ABPLBP_LeLnQuality_perc();
    /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneShutOffScenarios/RightLaneCheck'/Unit_Delay2' incorporates:
         *  Update for Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         */
    DW_tjalka_Unit_Delay2_DSTATE_d = GET_S_ABPLBP_RiLnQuality_perc();
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Relational Operator'
                 *  Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Switch2'
                 *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay4'
                 */
        if (((sint32)rtb_GE[i]) != 0) {
            /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay4' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/Constant8'/Constant'
                         */
            DW_tjalka_Unit_Delay4_DSTATE[i] = GET_P_TJALKA_LnQualTurnOffTime_sec();
        } else {
            if (DW_tjalka_Unit_Delay4_DSTATE[i] > 0.0F) {
                /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Switch2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality/Add/Functionality'/Sum'
                                 *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay4'
                                 *  Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay4'
                                 */
                DW_tjalka_Unit_Delay4_DSTATE[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
        }
        /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNOFFDELAYTIME1/Functionality'/Switch1' */
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Switch2' */
        if (((sint32)rtb_GE_k[i]) != 0) {
            /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Switch4' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Constant'
                         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Relational Operator'
                         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay2'
                         */
            if (DW_tjalka_Unit_Delay2_DSTATE[i] > 0.0F) {
                /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality/Add/Functionality'/Sum'
                                 */
                DW_tjalka_Unit_Delay2_DSTATE[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
            /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Switch4' */
        } else {
            /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay2' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/Constant7'/Constant'
                         */
            DW_tjalka_Unit_Delay2_DSTATE[i] = GET_P_TJALKA_LnQualTurnOnTime_sec();
        }
        /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Switch2' */
        /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/LaneQualityCheck'/Unit_Delay5' */
        DW_tjalka_Unit_Delay5_DSTATE[i] = rtb_Switch_l[i];
        /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinimumDistanceToLaneBoundaryCheck'/Unit_Delay3' */
        DW_tjalka_Unit_Delay3_DSTATE_i[i] = rtb_Switch3_g[i];
        /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneCenteringConditions/MinValidLengthCheck'/Unit_Delay' */
        DW_tjalka_Unit_Delay_DSTATE_bl[i] = rtb_Switch3_o2[i];
        /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Switch2' */
        if (((sint32)rtb_Switch2_g[i]) != 0) {
            /* Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Switch4' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Constant'
                         *  RelationalOperator: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Relational Operator'
                         *  UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck'/Unit_Delay2'
                         */
            if (DW_tjalka_Unit_Delay2_DSTATE_j[i] > 0.0F) {
                /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck'/Unit_Delay2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality/Add/Functionality'/Sum'
                                 */
                DW_tjalka_Unit_Delay2_DSTATE_j[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
            /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Switch4' */
        } else {
            /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck'/Unit_Delay2' incorporates:
                         *  Constant: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/Constant7'/Constant'
                         */
            DW_tjalka_Unit_Delay2_DSTATE_j[i] = GET_P_TJACMB_LnQualMinOnTmWR_sec();
        }
        /* End of Switch: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck/TURNONDELAYTIME1/Functionality'/Switch2' */
        /* Update for UnitDelay: 'sda:TJALKA/TJALKA/TJALKA_SenProcess/M_TJALKA/LaneValidation/CombinedLaneQualityCheck/LaneActivationConditionCheck'/Unit_Delay1' */
        DW_tjalka_Unit_Delay1_DSTATE_ju[i] = rtb_Switch2_g[i];
    }
}
#include "Pse_TJALKA.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
