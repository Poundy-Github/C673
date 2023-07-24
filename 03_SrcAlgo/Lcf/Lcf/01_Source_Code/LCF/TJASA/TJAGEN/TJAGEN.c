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
 * File          : TJAGEN
 * Generated on  : Mon 15.04.2019 at 09:22:39 (UTC+01:00)
 * MD5           : [3309847104    84932818  1389918634  3336430357 0](TJAGEN)
 *
 * Purpose       : <Purpose>
 * Specification : <Specification>
 *
 * Environment information:
 * Processor     : 32 Bit generic
 * Platform      : EMS3
 * SDA version   : 10.0
 * Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70
 * Add-ons       : -
 *
 * Version management information:
 * Filename      : $Workfile: $
 * Revision      : $Revision: 1.7 $
 * Author        : $Author: Werum, Gregor (uidq2175) $
 * Date          : $Date: 2019/08/29 10:04:22CEST $
 * Changes       :
 * $Log: TJAGEN.c  $
 * Revision 1.7 2019/08/29 10:04:22CEST Werum, Gregor (uidq2175) 
 * Module test update according to findings (FCT_CMP_TJASA_1577, FCT_CMP_TJASA_2145)
 * Revision 1.35 2019/04/15 09:35:55CEST Werum, Gregor (uidq2175) 
 * TJAGEN: Add minimum vehicle radius check, add absolute block to vehicle curvature signal
 * Revision 1.5 2019/04/15 09:24:59CEST Werum, Gregor (uidq2175) 
 * automatically created
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TJAGEN.h"
#include "TJAGEN_private.h"
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
#define TJAGEN_START_SEC_DATA_8
#include "TJAGEN_MemMap.h"
static uint8 DW_tjagen_Unit_Delay1_DSTATE;
static uint8 DW_tjagen_Unit_Delay2_DSTATE;
static uint8 DW_tjagen_UnitDelay1_DSTATE;
static uint8 DW_tjagen_UnitDelay3_DSTATE;
static uint8 DW_tjagen_UnitDelay2_DSTATE;
#define TJAGEN_STOP_SEC_DATA_8
#include "TJAGEN_MemMap.h"
#define TJAGEN_START_SEC_DATA_32
#include "TJAGEN_MemMap.h"
static float32 DW_tjagen_Unit_Delay_DSTATE;
static float32 DW_tjagen_Unit_Delay_DSTATE_a;
#define TJAGEN_STOP_SEC_DATA_32
#include "TJAGEN_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TJAGEN/TJAGEN/INI'/TJAGEN_SenReset'
 * Block description for: 'sda:TJAGEN/TJAGEN/INI'/TJAGEN_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TJAGEN_SenReset
#include "Pse_TJAGEN.h"
/* Short description: Not synchronized with ARAMIS */
void TJAGEN_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant'/Constant' */
    SET_S_TJAGEN_LKAOnlySwitch_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant1'/Constant' */
    SET_S_TJAGEN_FunctionSwitch_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant10'/Constant' */
    SET_S_TJAGEN_Cancel_nu(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant11'/Constant' */
    SET_S_TJAGEN_Abort_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant12'/Constant' */
    SET_S_TJAGEN_Degradation_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant2'/Constant' */
    SET_S_TJAGEN_CodeFunction_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant3'/Constant' */
    SET_S_TJAGEN_Error_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant4'/Constant' */
    SET_S_TJAGEN_Clearance_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant5'/Constant' */
    SET_D_TJAGEN_StrongReadyInvalid_btf(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant6'/Constant' */
    SET_S_TJAGEN_StrongReady_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant7'/Constant' */
    SET_D_TJAGEN_WeakReadyInvalid_btf(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant8'/Constant' */
    SET_S_TJAGEN_WeakReady_bool(0U);
    /* Constant: 'sda:TJAGEN/TJAGEN/INI/TJAGEN_SenReset/Constant9'/Constant' */
    SET_D_TJAGEN_CancelStatus_btf(0U);
}
#include "Pse_TJAGEN.h"
/*
 * Output and update for function-call system: 'sda:TJAGEN/TJAGEN'/TJAGEN_SenProcess'
 * Block description for: 'sda:TJAGEN/TJAGEN'/TJAGEN_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TJAGEN_SenProcess
#include "Pse_TJAGEN.h"
/* Short description: Not synchronized with ARAMIS */
void TJAGEN_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate_g[8];
    uint8 rtb_VectorConcatenate_c[8];
    uint8 rtb_EQ_h;
    uint8 rtb_NE;
    uint8 rtb_EQ_p;
    uint8 rtb_EQ_k;
    uint8 rtb_DataTypeConversion_ow;
    uint8 rtb_DataTypeConversion_m;
    uint8 rtb_EQ_c;
    uint8 rtb_Switch_l;
    uint8 rtb_GT;
    uint8 rtb_EQ_i;
    uint8 rtb_EQ_e;
    uint8 rtb_Switch3;
    uint8 rtb_DataTypeConversion_p;
    uint8 rtb_Switch3_f;
    float32 rtb_Abs;
    uint8 rtb_Switch3_e;
    uint8 rtb_DataTypeConversion_d;
    uint8 rtb_DataTypeConversion_dl;
    float32 rtb_Abs_o;
    float32 rtb_Switch2_k;
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/CheckTrajPlanStatusQualifier/NEQ3/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/CheckTrajPlanStatusQualifier/Constant1'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/CheckTrajPlanStatusQualifier/constant_value2'/Constant'
         *  Inport: '<Root>/S_TPLFBT_QuStatusTrajPlan_nu'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/CheckTrajPlanStatusQualifier/AND1/Functionality'/AND'
         */
    rtb_EQ_h = (uint8)((((sint32)GET_S_TPLFBT_QuStatusTrajPlan_nu()) & ((sint32) GET_P_TJAGEN_QuTrajPlanCancel_btm())) != 0);
    /* Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/Constant'/Constant' */
    rtb_VectorConcatenate[7] = 0U;
    /* Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/Constant1'/Constant' */
    rtb_VectorConcatenate[6] = 0U;
    /* Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/Constant5'/Constant' */
    rtb_VectorConcatenate[5] = 0U;
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/Constant3'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/constant_value1'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/AND3/Functionality'/AND'
         */
    rtb_NE = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_TJAGEN_VehStInvalidC_btm())) != 0);
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/MappingUint8'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_NE;
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/NEQ2/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/Constant4'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/constant_value3'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/AND5/Functionality'/AND'
         */
    rtb_EQ_p = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_TJAGEN_DrvStInvalidC_btm())) != 0);
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/MappingUint8'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_EQ_p;
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/Constant2'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/constant_value2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/AND3/Functionality'/AND'
         */
    rtb_EQ_k = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_TJAGEN_PrjSpecQuC_btm())) != 0);
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/MappingUint8'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_EQ_k;
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/MappingUint8'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_EQ_h;
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/NEQ4/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/Constant2'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/constant_value5'/Constant'
         *  Inport: '<Root>/S_TCTCLM_QuServTrajCtr_nu'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_ow = (uint8)((((sint32)GET_S_TCTCLM_QuServTrajCtr_nu()) & ((sint32)GET_P_TJAGEN_QuTrajCtrCancel_btm())) != 0);
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/MappingUint8'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_ow;
    /* S-Function (sfun_setbit): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/MappingUint8/set_bit1/Functionality'/sfun_setbit' */
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
        rtb_DataTypeConversion_m = temp;
    }
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/MappingUint8/set_bit1/Functionality'/DTC_out' */
    SET_D_TJAGEN_CancelStatus_btf(rtb_DataTypeConversion_m);
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/OR/Functionality'/Data Type Conversion' incorporates:
                                                               *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CancelConditions/OR/Functionality'/OR'
                                                               */
    rtb_DataTypeConversion_m = (uint8)(((((((sint32)rtb_NE) != 0) || (((sint32) rtb_EQ_p) != 0)) || (((sint32)rtb_EQ_k) != 0)) || (((sint32)rtb_EQ_h) != 0)) || (((sint32)rtb_DataTypeConversion_ow) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/C_LKA_Available_bool1'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/Constant1'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/Constant2'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/constant_value2'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/constant_value5'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/from_data_definition'/state_source'
         *  Inport: '<Root>/S_LCFRCV_SysStOnLatDMC_bool'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Inport: '<Root>/S_TCTCLM_QuServTrajCtr_nu'
         *  Inport: '<Root>/S_TPLFBT_QuStatusTrajPlan_nu'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/AND/Functionality'/AND'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/Relational Operator2/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/Clearance/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_ow = (uint8)((((((sint32) GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))) && ((((sint32) GET_S_LCFRCV_SysStOnLatDMC_bool()) != 0) || (((sint32) GET_P_TJAGEN_SetSysStOnLatDMC_bool()) != 0))) && ((((sint32) GET_S_TPLFBT_QuStatusTrajPlan_nu()) & ((sint32) GET_P_TJAGEN_QuTrajPlanClearance_btm())) == 0)) && ((((sint32) GET_S_TCTCLM_QuServTrajCtr_nu()) & ((sint32) GET_P_TJAGEN_QuTrajCtrClearance_btm())) == 0));
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/constant_value1'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/AND2/Functionality'/AND'
         */
    rtb_EQ_k = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_TJAGEN_PrjSpecQuWR_btm())) == 0);
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/Constant8'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/constant_value4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/AND1/Functionality'/AND'
         */
    rtb_EQ_p = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_TJAGEN_PrjSpecQuSR_btm())) == 0);
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/Constant3'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/constant_value3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CustomSpecificQualifiersCheck/AND4/Functionality'/AND'
         */
    rtb_NE = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_TJAGEN_PrjSpecQuA_btm())) != 0);
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         */
    rtb_EQ_c = (uint8)(((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)) == ((sint32) GET_S_TJASTM_SysStateTJA_nu()));
    /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/C_LKA_Available_bool1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/AND3/Functionality'/AND'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog'/Unit_Delay'
         *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog'/Unit_Delay1'
         */
    if ((((sint32)rtb_EQ_c) != 0) && (!(((sint32)DW_tjagen_Unit_Delay1_DSTATE) != 0))) {
        rtb_Switch2_k = GET_P_TJAGEN_RampoutTimeMax_sec();
    } else if (DW_tjagen_Unit_Delay_DSTATE > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog'/Unit_Delay'
                 */
        rtb_Switch2_k = DW_tjagen_Unit_Delay_DSTATE - GET_S_LCFRCV_SysCycleTimeSen_sec ();
    } else {
        /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_k = 0.0F;
    }
    /* End of Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/NOT2/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog'/Unit_Delay2'
         */
    if (!(((sint32)rtb_EQ_c) != 0)) {
        rtb_Switch_l = 0U;
    } else if (!(rtb_Switch2_k > 0.0F)) {
        /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_l = 1U;
    } else {
        rtb_Switch_l = DW_tjagen_Unit_Delay2_DSTATE;
    }
    /* End of Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog/RSFLIPFLOP/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/DriverStateCheck/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/DriverStateCheck/Constant8'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/DriverStateCheck/constant_value4'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/DriverStateCheck/AND1/Functionality'/AND'
         */
    rtb_EQ_h = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_TJAGEN_DrvStInvalidSR_btm())) == 0);
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/VehicleStateCheck/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/VehicleStateCheck/Constant2'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/VehicleStateCheck/constant_value5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/VehicleStateCheck/AND4/Functionality'/AND'
         */
    rtb_GT = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_TJAGEN_VehStInvalidSR_btm())) == 0);
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckStatesOfVehicleSafetyFunctions/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckStatesOfVehicleSafetyFunctions/Constant6'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckStatesOfVehicleSafetyFunctions/constant_value2'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckStatesOfVehicleSafetyFunctions/AND2/Functionality'/AND'
         */
    rtb_EQ_i = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_TJAGEN_ActiveStCtrlSR_btm())) == 0);
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckStatesOfVehicleSafetyFunctions/EQ4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckStatesOfVehicleSafetyFunctions/Constant5'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckStatesOfVehicleSafetyFunctions/constant_value1'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckStatesOfVehicleSafetyFunctions/AND1/Functionality'/AND'
         */
    rtb_EQ_e = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_TJAGEN_SysStErrorSR_btm())) == 0);
    /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/C_LCF_AclXHyst_mps3'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/C_LCF_AclXMax_mps1'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity'/Unit Delay1'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > (GET_P_TJAGEN_AclXMax_mps2() + GET_P_TJAGEN_AccelXHyst_mps2())) {
        rtb_Switch3 = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < GET_P_TJAGEN_AclXMax_mps2()) {
        /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_Switch3 = 0U;
    } else {
        rtb_Switch3 = DW_tjagen_UnitDelay1_DSTATE;
    }
    /* End of Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/C_LCF_AclXHyst_mps2'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/C_LCF_AclXMin_mps3'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/Add4/Functionality'/Sum'
         *  Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity'/Unit Delay3'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > GET_P_TJAGEN_AclXMin_mps2()) {
        rtb_Switch3_f = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < (GET_P_TJAGEN_AclXMin_mps2() - GET_P_TJAGEN_AccelXHyst_mps2())) {
        /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3_f = 0U;
    } else {
        rtb_Switch3_f = DW_tjagen_UnitDelay3_DSTATE;
    }
    /* End of Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS2/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_p = (uint8)((!(((sint32)rtb_Switch3) != 0)) && (((sint32)rtb_Switch3_f) != 0));
    /* Abs: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehAclY_mps2'
         */
    rtb_Abs = f32_abs_f32(GET_S_LCFRCV_VehAclY_mps2());
    /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/C_LCF_AclXHyst_mps1'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/C_LCF_AclYMax_mps3'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/Add1/Functionality'/Sum'
         *  Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity'/Unit Delay2'
         */
    if (rtb_Abs > (GET_P_TJAGEN_AclYMax_mps2() + GET_P_TJAGEN_AccelYHyst_mps2())) {
        rtb_Switch3_e = 1U;
    } else if (rtb_Abs < GET_P_TJAGEN_AclYMax_mps2()) {
        /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_e = 0U;
    } else {
        rtb_Switch3_e = DW_tjagen_UnitDelay2_DSTATE;
    }
    /* End of Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/HYSTERESIS1/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_d = (uint8)(!(((sint32)rtb_Switch3_e) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT4/Functionality'/NOT'
         */
    rtb_DataTypeConversion_dl = (uint8)(!(((sint32)rtb_NE) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/AND3/Functionality'/AND'
         */
    SET_S_TJAGEN_StrongReady_bool((uint8)((((((((((sint32)rtb_EQ_h) != 0) && (((sint32)rtb_GT) != 0)) && (((sint32)rtb_EQ_i) != 0)) && (((sint32)rtb_EQ_e) != 0)) && (((sint32)rtb_DataTypeConversion_p) != 0)) && (((sint32) rtb_DataTypeConversion_d) != 0)) && (((sint32)rtb_EQ_p) != 0)) && (((sint32) rtb_DataTypeConversion_dl) != 0)));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT7/Functionality'/Data Type Conversion' incorporates:
                                            *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT7/Functionality'/NOT'
                                            */
    rtb_VectorConcatenate_g[0] = (uint8)(!(((sint32)rtb_EQ_h) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_g[1] = (uint8)(!(((sint32)rtb_GT) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_g[2] = (uint8)(!(((sint32)rtb_EQ_i) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_g[3] = (uint8)(!(((sint32)rtb_EQ_e) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_g[4] = (uint8)(!(((sint32)rtb_DataTypeConversion_p) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_g[5] = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_g[6] = (uint8)(!(((sint32)rtb_EQ_p) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT11/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT11/Functionality'/NOT'
         */
    rtb_VectorConcatenate_g[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_dl) != 0));
    /* S-Function (sfun_setbit): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/MappingUint8/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_g[0];
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
        rtb_DataTypeConversion_dl = temp;
    }
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/MappingUint8/set_bit1/Functionality'/DTC_out' */
    SET_D_TJAGEN_StrongReadyInvalid_btf(rtb_DataTypeConversion_dl);
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT/Functionality'/Data Type Conversion' incorporates:
                                                                      *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT/Functionality'/NOT'
                                                                      */
    rtb_DataTypeConversion_dl = (uint8)(!(((sint32)rtb_GT) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT10/Functionality'/NOT'
         */
    rtb_DataTypeConversion_d = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/NOT9/Functionality'/NOT'
         */
    rtb_DataTypeConversion_p = (uint8)(!(((sint32)rtb_DataTypeConversion_p) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_dl = (uint8)(((((sint32)rtb_DataTypeConversion_dl) != 0) || (((sint32)rtb_DataTypeConversion_p) != 0)) || (((sint32) rtb_DataTypeConversion_d) != 0));
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngle_deg'
         */
    rtb_DataTypeConversion_d = (uint8)(GET_S_LCFRCV_SteerWAngle_deg() > GET_P_TJAGEN_SteerWAngleMaxWR_deg());
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/OR2/Functionality'/OR'
         */
    rtb_DataTypeConversion_dl = (uint8)(((((sint32)rtb_DataTypeConversion_dl) != 0) || (((sint32)rtb_DataTypeConversion_m) != 0)) || (((sint32) rtb_DataTypeConversion_d) != 0));
    /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  MinMax: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/Max/Functionality'/Max'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_dl) != 0) {
        rtb_Abs = f32_max_f32_f32(GET_S_LCFRCV_SysCycleTimeSen_sec(), GET_P_TJAGEN_BlockTimeTJA_sec());
    } else if (DW_tjagen_Unit_Delay_DSTATE_a > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck'/Unit_Delay'
                 */
        rtb_Abs = DW_tjagen_Unit_Delay_DSTATE_a - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Abs = 0.0F;
    }
    /* End of Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_dl = (uint8)(!(rtb_Abs > 0.0F));
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Constant3'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/constant_value4'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion_p = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32)GET_P_TJAGEN_VehStInvalidWR_btm())) == 0);
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Constant4'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/constant_value1'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/AND5/Functionality'/AND'
         */
    rtb_EQ_e = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_TJAGEN_DrvStInvalidWR_btm())) == 0);
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Constant7'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/constant_value3'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/AND1/Functionality'/AND'
         */
    rtb_EQ_i = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_TJAGEN_SysStNotAvailableWR_btm())) == 0);
    /* Abs: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_VehCrv_1pm());
    /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Div/Functionality/DivDefault'/Switch' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/constant_value5'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Div/In3'/Constant'
         *  Product: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Div/Functionality/DivDefault'/Div'
         */
    if (rtb_Abs_o != 0.0F) {
        rtb_Abs_o = 1.0F / rtb_Abs_o;
    } else {
        rtb_Abs_o = 0.0F;
    }
    /* End of Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Div/Functionality/DivDefault'/Switch' */
    /* S-Function Block sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Y_TJAGEN_VehRadiusMinWR_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TJAGEN_VehVelX_kph */
        FDPS_PTR_F32(GETA_X_TJAGEN_VehVelX_kph(), GET_S_LCFRCV_VDy_VehVelocity_kph(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TJAGEN_VehRadiusMinWR_met(), &dps_result_ln);
    }
    /* RelationalOperator: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/GT/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/Y_TJAGEN_VehRadiusMinWR_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_GT = (uint8)(rtb_Abs_o > rtb_ip_lookup_fxpt_sfun_7);
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/AND4/Functionality'/AND'
         */
    SET_S_TJAGEN_WeakReady_bool((uint8)((((((((sint32)rtb_DataTypeConversion_dl) != 0) && (((sint32)rtb_DataTypeConversion_p) != 0)) && (((sint32)rtb_EQ_e) != 0)) && (((sint32)rtb_EQ_i) != 0)) && (((sint32)rtb_EQ_k) != 0)) && (((sint32)rtb_GT) != 0)));
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/MappingUint8'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_c[5] = rtb_DataTypeConversion_d;
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_c[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_dl) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_c[1] = (uint8)(!(((sint32)rtb_DataTypeConversion_p) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_c[2] = (uint8)(!(((sint32)rtb_EQ_e) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_c[3] = (uint8)(!(((sint32)rtb_EQ_i) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_c[4] = (uint8)(!(((sint32)rtb_EQ_k) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_c[6] = (uint8)(!(((sint32)rtb_GT) != 0));
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/constant_value2'/Signal Conversion' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/constant_value2'/Constant'
         */
    rtb_VectorConcatenate_c[7] = 0U;
    /* S-Function (sfun_setbit): 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/MappingUint8/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_c[0];
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
        rtb_DataTypeConversion_dl = temp;
    }
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/MappingUint8/set_bit1/Functionality'/DTC_out' */
    SET_D_TJAGEN_WeakReadyInvalid_btf(rtb_DataTypeConversion_dl);
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/branch'/copy1' incorporates:
                                                                    *  DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/AND2/Functionality'/Data Type Conversion'
                                                                    *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/AND2/Functionality'/AND'
                                                                    *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/NOT/Functionality'/NOT'
                                                                    *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/OR/Functionality'/OR'
                                                                    */
    SET_S_TJAGEN_Degradation_bool((uint8)((((sint32)rtb_EQ_c) != 0) && ((((sint32)rtb_Switch_l) != 0) || (!(((sint32)rtb_DataTypeConversion_ow) != 0)))));
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/branch1'/copy1' */
    SET_S_TJAGEN_Clearance_bool(rtb_DataTypeConversion_ow);
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/branch2'/copy1' */
    SET_S_TJAGEN_Abort_bool(rtb_NE);
    /* SignalConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/branch3'/copy1' */
    SET_S_TJAGEN_Cancel_nu(rtb_DataTypeConversion_m);
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/AND4/Functionality'/Data Type Conversion' incorporates:
                                                        *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/C_LKA_Available_bool1'/Constant'
                                                        *  Inport: '<Root>/S_LCFRCV_LKASwitch_nu'
                                                        *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/AND4/Functionality'/AND'
                                                        */
    rtb_DataTypeConversion_dl = (uint8)((((sint32)GET_P_LKA_Available_bool()) != 0) && (((sint32)GET_S_LCFRCV_LKASwitch_nu()) != 0));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/C_LKA_Available_bool3'/Constant'
         *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/C_LKA_Available_bool4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_TJASwitch_nu'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/AND1/Functionality'/AND'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/AND3/Functionality'/AND'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_d = (uint8)(((((sint32)GET_S_LCFRCV_TJASwitch_nu()) != 0) && (((sint32)GET_P_TJA_Available_bool()) != 0)) || ((((sint32) GET_P_TJA_Available_bool()) != 0) && (((sint32) GET_P_TJA_ManFunctionSwitch_bool()) != 0)));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/AND/Functionality'/AND'
         *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/NOT1/Functionality'/NOT'
         */
    SET_S_TJAGEN_LKAOnlySwitch_bool((uint8)((((sint32)rtb_DataTypeConversion_dl) != 0) && (!(((sint32)rtb_DataTypeConversion_d) != 0))));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/OR/Functionality'/Data Type Conversion' incorporates:
                                                                 *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/OR/Functionality'/OR'
                                                                 */
    SET_S_TJAGEN_FunctionSwitch_bool((uint8)((((sint32)rtb_DataTypeConversion_dl) != 0) || (((sint32)rtb_DataTypeConversion_d) != 0)));
    /* DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/OR2/Functionality'/Data Type Conversion' incorporates:
                                                              *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/C_LKA_Available_bool2'/Constant'
                                                              *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/C_LKA_Available_bool5'/Constant'
                                                              *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/CodedFunctionAndFunctionSwitch/OR2/Functionality'/OR'
                                                              */
    SET_S_TJAGEN_CodeFunction_bool((uint8)((((sint32)GET_P_LKA_Available_bool()) != 0) || (((sint32)GET_P_TJA_Available_bool()) != 0)));
    /* Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/Switch/Functionality'/Switch' incorporates:
                                                                *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/C_LKA_Available_bool1'/Constant'
                                                                *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/C_LKA_Available_bool2'/Constant'
                                                                *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/C_LKA_Available_bool4'/Constant'
                                                                *  Constant: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/C_LKA_Available_bool5'/Constant'
                                                                *  DataTypeConversion: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/OR/Functionality'/Data Type Conversion'
                                                                *  Inport: '<Root>/S_LCFRCV_ErrorStateLKA_bool'
                                                                *  Inport: '<Root>/S_LCFRCV_ErrorStateTJA_bool'
                                                                *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/AND/Functionality'/AND'
                                                                *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/AND1/Functionality'/AND'
                                                                *  Logic: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/OR/Functionality'/OR'
                                                                */
    if (((sint32)GET_P_TJAGEN_CheckTJAErrorState_bool()) != 0) {
        SET_S_TJAGEN_Error_bool((uint8)(((((sint32)GET_S_LCFRCV_ErrorStateTJA_bool ()) != 0) && (((sint32)GET_P_TJA_Available_bool()) != 0)) || ((((sint32) GET_S_LCFRCV_ErrorStateLKA_bool()) != 0) && (((sint32) GET_P_LKA_Available_bool()) != 0))));
    } else {
        SET_S_TJAGEN_Error_bool(0U);
    }
    /* End of Switch: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/ErrorState/Switch/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog'/Unit_Delay1' */
    DW_tjagen_Unit_Delay1_DSTATE = rtb_EQ_c;
    /* Update for UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog'/Unit_Delay' */
    DW_tjagen_Unit_Delay_DSTATE = rtb_Switch2_k;
    /* Update for UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/DegradationCheck/RampoutWatchDog'/Unit_Delay2' */
    DW_tjagen_Unit_Delay2_DSTATE = rtb_Switch_l;
    /* Update for UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity'/Unit Delay1' */
    DW_tjagen_UnitDelay1_DSTATE = rtb_Switch3;
    /* Update for UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity'/Unit Delay3' */
    DW_tjagen_UnitDelay3_DSTATE = rtb_Switch3_f;
    /* Update for UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/StrongReadyConditions/CheckLongAndLatAclValidity'/Unit Delay2' */
    DW_tjagen_UnitDelay2_DSTATE = rtb_Switch3_e;
    /* Update for UnitDelay: 'sda:TJAGEN/TJAGEN/TJAGEN_SenProcess/M_TJAGEN/WeakReadyConditions/BlockingTimeConditionCheck'/Unit_Delay' */
    DW_tjagen_Unit_Delay_DSTATE_a = rtb_Abs;
}
#include "Pse_TJAGEN.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
