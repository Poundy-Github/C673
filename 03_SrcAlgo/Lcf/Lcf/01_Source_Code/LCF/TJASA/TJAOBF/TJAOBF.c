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
 * File          : TJAOBF
 * Generated on  : Thu 11.07.2019 at 12:17:00 (UTC+01:00)
 * MD5           : [29362645  1943745594  2652316388  3428518622 0](TJAOBF)
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
 * Author        : $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
 * Date          : $Date: 2020/04/09 14:23:59CEST $
 * Changes       :
 * $Log: TJAOBF.c  $
 * Revision 1.6 2020/04/09 14:23:59CEST Craciun, Mihaela (uidl9730) (uidl9730) 
 * integrate new updates
 * Revision 1.5 2019/07/17 12:12:48CEST Nastasa, Elena (uidt4846) 
 * Update LCF files for Sprint 05.10.04
 * Revision 1.5 2019/07/11 16:00:48CEST Werum, Gregor (uidq2175) 
 * Merge updates from INT2 branch to Family Trunk
 * Revision 1.52 2019/07/11 12:35:16CEST Werum, Gregor (uidq2175) 
 * - Add target clothoid bitfield check as WR condition
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TJAOBF.h"
#include "TJAOBF_private.h"
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
#define TJAOBF_START_SEC_DATA_8
#include "TJAOBF_MemMap.h"
static uint8 DW_tjaobf_Unit_Delay2_DSTATE_cf;
static uint8 DW_tjaobf_Unit_Delay2_DSTATE_e;
static uint8 DW_tjaobf_Unit_Delay1_DSTATE_a[2];
static uint8 DW_tjaobf_Unit_Delay3_DSTATE_l[2];
static uint8 DW_tjaobf_Unit_Delay1_DSTATE_d[2];
static uint8 DW_tjaobf_Unit_Delay1_DSTATE_n;
static uint8 DW_tjaobf_Unit_Delay_DSTATE_l;
static uint8 DW_tjaobf_Unit_Delay_DSTATE_n;
static uint8 DW_tjaobf_Unit_Delay_DSTATE_lt;
static uint8 DW_tjaobf_Unit_Delay_DSTATE_o;
static uint8 DW_tjaobf_Unit_Delay1_DSTATE_h;
static uint8 DW_tjaobf_Unit_Delay1_DSTATE_nu;
static uint8 DW_tjaobf_Unit_Delay2_DSTATE_m;
#define TJAOBF_STOP_SEC_DATA_8
#include "TJAOBF_MemMap.h"
#define TJAOBF_START_SEC_DATA_32
#include "TJAOBF_MemMap.h"
static float32 DW_tjaobf_Unit_Delay1_DSTATE;
static float32 DW_tjaobf_Unit_Delay2_DSTATE;
static float32 DW_tjaobf_Unit_Delay2_DSTATE_b;
static float32 DW_tjaobf_Unit_Delay3_DSTATE[2];
static float32 DW_tjaobf_Unit_Delay_DSTATE;
static float32 DW_tjaobf_Unit_Delay_DSTATE_e;
static float32 DW_tjaobf_Unit_Delay2_DSTATE_c;
static float32 DW_tjaobf_Unit_Delay1_DSTATE_e;
static float32 DW_tjaobf_Unit_Delay2_DSTATE_bv;
#define TJAOBF_STOP_SEC_DATA_32
#include "TJAOBF_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TJAOBF/TJAOBF/INI'/TJAOBF_SenReset'
 * Block description for: 'sda:TJAOBF/TJAOBF/INI'/TJAOBF_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TJAOBF_SenReset
#include "Pse_TJAOBF.h"
/* Short description: Not synchronized with ARAMIS */
void TJAOBF_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant'/Constant' */
    SET_D_TJAOBF_ObjFollowInvalid_btf(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant1'/Constant' */
    SET_S_TJAOBF_StrongReady_bool(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant10'/Constant' */
    SET_S_TJAOBF_ObjectCrv_1pm(0.0F);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant2'/Constant' */
    SET_S_TJAOBF_WeakReady_bool(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant3'/Constant' */
    SET_S_TJAOBF_Cancel_bool(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant4'/Constant' */
    SET_D_TJAOBF_ObjInLaneInvalid_btf(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant5'/Constant' */
    SET_S_TJAOBF_TgtObjDataValid_bool(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant6'/Constant' */
    SET_S_TJAOBF_AccObjValid_bool(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant7'/Constant' */
    SET_S_TJAOBF_ObjInLaneValid_bool(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant8'/Constant' */
    SET_D_TJAOBF_TgtObjDataInvalid_btf(0U);
    /* Constant: 'sda:TJAOBF/TJAOBF/INI/TJAOBF_SenReset/Constant9'/Constant' */
    SET_S_TJAOBF_CombObjectCrv_1pm(0.0F);
}
#include "Pse_TJAOBF.h"
/*
 * Output and update for function-call system: 'sda:TJAOBF/TJAOBF'/TJAOBF_SenProcess'
 * Block description for: 'sda:TJAOBF/TJAOBF'/TJAOBF_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TJAOBF_SenProcess
#include "Pse_TJAOBF.h"
/* Short description: Not synchronized with ARAMIS */
void TJAOBF_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    uint16 rtb_sfun_setbit;
    uint16 rtb_sfun_setbit_j;
    uint8 rtb_VectorConcatenate[16];
    uint8 rtb_VectorConcatenate_l[16];
    uint8 rtb_VectorConcatenate_e[8];
    uint8 rtb_sfun_setbit_d;
    uint8 rtb_LT_a;
    uint8 rtb_LT_f;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_LT_d;
    uint8 rtb_LogicalOperator;
    uint8 rtb_LogicalOperator_o;
    uint8 rtb_DataTypeConversion_h;
    uint8 rtb_NE_m;
    uint8 rtb_Switch2_j[2];
    uint8 rtb_Switch3[2];
    uint8 rtb_LT_b;
    float32 rtb_Switch4_a[2];
    uint8 rtb_DataTypeConversion_po;
    uint8 rtb_Switch3_i2[2];
    uint8 rtb_EQ_pi;
    uint8 rtb_DataTypeConversion_pb;
    uint8 rtb_EQ_p;
    uint8 rtb_LogicalOperator_j;
    uint8 rtb_Switch3_ne;
    uint8 rtb_DataTypeConversion_ow;
    uint8 rtb_Switch3_l;
    uint8 rtb_DataTypeConversion_ab;
    uint8 rtb_Switch3_m;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_GT_i;
    uint8 rtb_DataTypeConversion_a2;
    uint8 rtb_DataTypeConversion_oc;
    uint8 rtb_Switch3_oz;
    uint8 rtb_DataTypeConversion_im;
    uint8 rtb_Switch3_p;
    uint8 rtb_DataTypeConversion_m;
    uint8 rtb_DataTypeConversion_hu;
    uint8 rtb_DataTypeConversion_jb;
    uint8 rtb_EQ_h;
    uint8 rtb_DataTypeConversion_ia;
    uint8 rtb_DataTypeConversion_lt;
    float32 rtb_Abs_a;
    float32 rtb_Min_k;
    float32 rtb_Mul_a1;
    float32 rtb_Sum_iz;
    float32 rtb_Mul_me;
    float32 rtb_Mul_lc;
    uint8 LogicalOperator;
    sint32 i;
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/Constant2'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/constant_value2'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjInvBitfield_btf'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/AND2/Functionality'/AND'
         */
    rtb_LT_a = (uint8)((((sint32)GET_S_ODPFOP_AccObjInvBitfield_btf()) & ((sint32)GET_P_TJAOBF_AccObjLanesInvalid_btm())) == 0);
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/Constant4'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/constant_value1'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjInvBitfield_btf'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/AND1/Functionality'/AND'
         */
    rtb_LT_f = (uint8)((((sint32)GET_S_ODPFOP_AccObjInvBitfield_btf()) & ((sint32)GET_P_TJAOBF_AccObjectInvalid_btm())) == 0);
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/constant_value3'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjInvBitfield_btf'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/EQ1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion = (uint8)(!((((sint32) GET_S_ODPFOP_AccObjInvBitfield_btf()) & ((sint32) GET_P_TJAOBF_AccObjChange_btm())) == 0));
    /* S-Function (fcncallgen): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag'/Unit_Delay2'
         */
    LogicalOperator = (uint8)((!(((sint32)DW_tjaobf_Unit_Delay2_DSTATE_cf) != 0)) && (((sint32)rtb_DataTypeConversion) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING'/fcg' */
    /* Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag'/Unit_Delay1'
         */
    rtb_LT_d = (uint8)((((sint32)LogicalOperator) != 0) || (DW_tjaobf_Unit_Delay1_DSTATE > 0.0F));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag'/Unit_Delay1'
         */
    if (((sint32)LogicalOperator) != 0) {
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag'/Unit_Delay1' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/Constant1'/Constant'
                 */
        DW_tjaobf_Unit_Delay1_DSTATE = GET_P_TJAOBF_CutinObValidFreezTm_sec();
    } else {
        if (DW_tjaobf_Unit_Delay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag'/Unit_Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Switch2'
                         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag'/Unit_Delay1'
                         */
            DW_tjaobf_Unit_Delay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration'/Unit_Delay2'
         */
    rtb_LogicalOperator = (uint8)((DW_tjaobf_Unit_Delay2_DSTATE <= 0.0F) && (((sint32)rtb_LT_f) != 0));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_f) != 0) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration'/Unit_Delay2'
                 */
        if (DW_tjaobf_Unit_Delay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjaobf_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/Constant3'/Constant'
                 */
        DW_tjaobf_Unit_Delay2_DSTATE = GET_P_TJAOBF_MinDurAccObjValid_sec();
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1'/Unit_Delay2'
         */
    rtb_LogicalOperator_o = (uint8)((DW_tjaobf_Unit_Delay2_DSTATE_b <= 0.0F) && (((sint32)rtb_LT_a) != 0));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_a) != 0) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1'/Unit_Delay2'
                 */
        if (DW_tjaobf_Unit_Delay2_DSTATE_b > 0.0F) {
            /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjaobf_Unit_Delay2_DSTATE_b -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/Constant3'/Constant'
                 */
        DW_tjaobf_Unit_Delay2_DSTATE_b = GET_P_TJAOBF_MinDurAccObjValid_sec();
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/MinimumValidityDuration1/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Switch/Functionality'/Switch' */
    if (((sint32)rtb_LogicalOperator) != 0) {
        /* Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Mul1/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                 */
        rtb_Mul_lc = GET_S_ODPFOP_AccObjPosX_met() * GET_S_ODPFOP_AccObjPosX_met();
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Div/Functionality/DivDefault'/Switch' */
        if (rtb_Mul_lc != 0.0F) {
            /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch11'/copy1' incorporates:
                         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Constant'/Constant'
                         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
                         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Div/Functionality/DivDefault'/Div'
                         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Mul/Functionality'/Mul'
                         */
            SET_S_TJAOBF_ObjectCrv_1pm((2.0F * GET_S_ODPFOP_AccObjPosY_met()) / rtb_Mul_lc);
        } else {
            /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch11'/copy1' incorporates:
                         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Div/In3'/Constant'
                         */
            SET_S_TJAOBF_ObjectCrv_1pm(0.0F);
        }
        /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Div/Functionality/DivDefault'/Switch' */
    } else {
        /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch11'/copy1' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Constant1'/Constant'
                 */
        SET_S_TJAOBF_ObjectCrv_1pm(0.0F);
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TJALKA_LnBndValid_nu'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/EQ3/Functionality'/EQ'
         */
    if ((((sint32)GET_S_TJALKA_LnBndValid_nu()) == ((sint32)((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE))) && (((sint32) rtb_LogicalOperator) != 0)) {
        /* Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Mul1/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                 */
        rtb_Mul_lc = GET_S_ODPFOP_AccObjPosX_met() * GET_S_ODPFOP_AccObjPosX_met();
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Div/Functionality/DivDefault'/Switch' */
        if (rtb_Mul_lc != 0.0F) {
            /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch10'/copy1' incorporates:
                         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Constant'/Constant'
                         *  Inport: '<Root>/S_ABPLBP_CntrLnClthHeading_rad'
                         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
                         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
                         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Div/Functionality/DivDefault'/Div'
                         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Mul/Functionality'/Mul'
                         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Mul2/Functionality'/Mul'
                         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Sum1/Functionality'/Sum'
                         *  Trigonometry: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Trigonom/Functionality'/Trigonometric Function'
                         */
            SET_S_TJAOBF_CombObjectCrv_1pm((((GET_S_ODPFOP_AccObjPosY_met() - GET_S_ABPLBP_CntrLnClthPosY0_met()) - (f32_tan_f32 (GET_S_ABPLBP_CntrLnClthHeading_rad()) * GET_S_ODPFOP_AccObjPosX_met())) * 2.0F) / rtb_Mul_lc);
        } else {
            /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch10'/copy1' incorporates:
                         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Div/In3'/Constant'
                         */
            SET_S_TJAOBF_CombObjectCrv_1pm(0.0F);
        }
        /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Div/Functionality/DivDefault'/Switch' */
    } else {
        /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch10'/copy1' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Constant1'/Constant'
                 */
        SET_S_TJAOBF_CombObjectCrv_1pm(0.0F);
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CalculateObjectCurvatures/GetAccObjCrv1/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/MappingUint16'/ConcatBufferAtVector ConcatenateIn10' */
    rtb_VectorConcatenate[9] = rtb_LT_d;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/MappingUint16'/ConcatBufferAtVector ConcatenateIn12' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Constant'
         *  SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Signal Conversion'
         */
    rtb_VectorConcatenate[11] = 0U;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/MappingUint16'/ConcatBufferAtVector ConcatenateIn13' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Constant'
         *  SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Signal Conversion'
         */
    rtb_VectorConcatenate[12] = 0U;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/MappingUint16'/ConcatBufferAtVector ConcatenateIn14' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Constant'
         *  SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Signal Conversion'
         */
    rtb_VectorConcatenate[13] = 0U;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/MappingUint16'/ConcatBufferAtVector ConcatenateIn15' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Constant'
         *  SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Signal Conversion'
         */
    rtb_VectorConcatenate[14] = 0U;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/MappingUint16'/ConcatBufferAtVector ConcatenateIn16' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Constant'
         *  SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value1'/Signal Conversion'
         */
    rtb_VectorConcatenate[15] = 0U;
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         */
    rtb_LT_f = (uint8)(GET_S_LCFRCV_VDy_VehVelocity_kph() > GET_P_TJAOBF_ObjLnCheckMinVelX_kph());
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/SRFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_TJALKA_CombinedLaneSR_bool'
         *  Inport: '<Root>/S_TJALKA_CombinedLaneWR_bool'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/AND2/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/NOT/Functionality'/NOT'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid'/Unit_Delay2'
         */
    if ((((sint32)GET_S_TJALKA_CombinedLaneSR_bool()) != 0) && (((sint32) GET_S_TJALKA_CombinedLaneWR_bool()) != 0)) {
        LogicalOperator = 1U;
    } else if (!(((sint32)GET_S_TJALKA_CombinedLaneSR_bool()) != 0)) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/SRFLIPFLOP/Functionality'/Constant1'
                 */
        LogicalOperator = 0U;
    } else {
        LogicalOperator = DW_tjaobf_Unit_Delay2_DSTATE_e;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/SRFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TJALKA_LnBndValid_nu'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/AND3/Functionality'/AND'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/EQ3/Functionality'/EQ'
         */
    rtb_DataTypeConversion_h = (uint8)((((sint32)GET_S_TJALKA_LnBndValid_nu()) == ((sint32)((uint8)E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE))) && (((sint32)LogicalOperator) != 0));
    /* Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/Constant2'/Constant'
         */
    i = ((sint32)GET_P_TJACMB_LnQualMinWR_perc()) - ((sint32) GET_P_TJACMB_LnQualMinHystWR_perc());
    if (i < 0) {
        i = 0;
    }
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Constant1'
         *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
         *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/Sum3/Functionality'/Sum'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck'/Unit_Delay1'
         */
    if (((sint32)GET_S_ABPLBP_LeLnQuality_perc()) > ((sint32) GET_P_TJACMB_LnQualMinWR_perc())) {
        rtb_Switch3[0] = 1U;
    } else if (((sint32)GET_S_ABPLBP_LeLnQuality_perc()) < ((sint32)((uint8)i))) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3[0] = 0U;
    } else {
        rtb_Switch3[0] = DW_tjaobf_Unit_Delay1_DSTATE_a[0];
    }
    if (((sint32)GET_S_ABPLBP_RiLnQuality_perc()) > ((sint32) GET_P_TJACMB_LnQualMinWR_perc())) {
        rtb_Switch3[1] = 1U;
    } else if (((sint32)GET_S_ABPLBP_RiLnQuality_perc()) < ((sint32)((uint8)i))) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3[1] = 0U;
    } else {
        rtb_Switch3[1] = DW_tjaobf_Unit_Delay1_DSTATE_a[1];
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/HYSTERESIS/Functionality'/Switch3' */
    /* Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck'/Unit_Delay3'
         */
    for (i = 0; i < 2; i++) {
        rtb_Switch2_j[i] = (uint8)((DW_tjaobf_Unit_Delay3_DSTATE[i] <= 0.0F) && (((sint32)rtb_Switch3[i]) != 0));
    }
    /* End of Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Logical Operator' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/Constant'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/Constant2'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Inport: '<Root>/S_TJALKA_LnBndValid_nu'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/AND/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/AND1/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/AND/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/LT3/Functionality'/LT'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/EQ1/Functionality'/EQ'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/Sum1/Functionality'/Sum'
         */
    rtb_LT_a = (uint8)((((((sint32)rtb_LT_f) != 0) && (((sint32) rtb_LogicalOperator_o) != 0)) && (((GET_S_ODPFOP_AccObjPosX_met() - GET_S_ABPLBP_LeLnClthLength_met()) < GET_P_TJAOBF_MaxDiffLnLen2ObjPosX_met()) && (GET_S_ABPLBP_LeLnClthLength_met() > 0.0F))) && (((((sint32) GET_S_TJALKA_LnBndValid_nu()) == ((sint32)((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY))) || (((sint32) rtb_DataTypeConversion_h) != 0)) && (((sint32)rtb_Switch2_j[0]) != 0)));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/Constant2'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Inport: '<Root>/S_TJALKA_LnBndValid_nu'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/AND1/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/AND2/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/AND1/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/GT4/Functionality'/GT'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/LT2/Functionality'/LT'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/EQ2/Functionality'/EQ'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/CheckObjectPosXValidity/Sum/Functionality'/Sum'
         */
    rtb_LT_f = (uint8)((((((sint32)rtb_LT_f) != 0) && (((sint32) rtb_LogicalOperator_o) != 0)) && (((GET_S_ODPFOP_AccObjPosX_met() - GET_S_ABPLBP_RiLnClthLength_met()) < GET_P_TJAOBF_MaxDiffLnLen2ObjPosX_met()) && (GET_S_ABPLBP_RiLnClthLength_met() > 0.0F))) && ((((sint32)rtb_Switch2_j [1]) != 0) && ((((sint32)GET_S_TJALKA_LnBndValid_nu()) == ((sint32)((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY))) || (((sint32) rtb_DataTypeConversion_h) != 0))));
    /* Outputs for Atomic SubSystem: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX'/TrajectoryEquationOfCorridor'
         *
         * Block description for 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX'/TrajectoryEquationOfCorridor':
         *  X.2.1.1.1.1.2.1.1.1
         */
    /* Trigonometry: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Trigonom/Functionality'/Trigonometric Function' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/AvoidUndefinedTangent/Constant'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/AvoidUndefinedTangent/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         *  MinMax: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/AvoidUndefinedTangent/Max/Functionality'/Max'
         *  MinMax: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/AvoidUndefinedTangent/Min/Functionality'/Min'
         */
    rtb_Mul_lc = f32_tan_f32(f32_min_f32_f32(f32_max_f32_f32 (GET_S_ABPLBP_LeLnClthHeading_rad(), -0.785398185F), 0.785398185F));
    /* Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Add3/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         */
    rtb_Abs_a = GET_S_ODPFOP_AccObjPosX_met() - GET_S_ABPLBP_LeLnClthPosX0_met();
    /* Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product5/Functionality'/Mul' */
    rtb_Min_k = rtb_Abs_a * rtb_Abs_a;
    /* Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain_const'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product1/Functionality'/Mul'
         */
    rtb_Sum_iz = ((GET_S_ABPLBP_LeLnClthCrv_1pm() * rtb_Min_k) * 0.5F) + (rtb_Mul_lc * rtb_Abs_a);
    /* Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain1_const'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product6/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product7/Functionality'/Mul'
         */
    rtb_Mul_a1 = ((rtb_Min_k * rtb_Abs_a) * GET_S_ABPLBP_LeLnClthCrvChng_1pm2()) * 0.166666672F;
    /* MinMax: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Min/Functionality'/Min' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain3_const'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant4'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  MinMax: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Max/Functionality'/Max'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain3/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product3/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product4/Functionality'/Mul'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Sum1/Functionality'/Sum'
         */
    rtb_Min_k = f32_min_f32_f32(f32_max_f32_f32 ((((GET_S_ABPLBP_LeLnClthCrvChng_1pm2() * rtb_Min_k) * 0.5F) + rtb_Mul_lc) + (GET_S_ABPLBP_LeLnClthCrv_1pm() * rtb_Abs_a), -1.0F), 1.0F);
    /* Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/CalculateTargetObjectDist2LeftBoundary/Mul/Functionality'/Mul' incorporates:
         *  Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Abs/Functionality'/Abs'
         *  Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Abs1/Functionality'/Abs'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant2'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Mul3/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Mul4/Functionality'/Mul'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/CalculateTargetObjectDist2LeftBoundary/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Add1/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Sum3/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Sum3/Functionality'/Sum'
         *  Trigonometry: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/CalculateTargetObjectDist2LeftBoundary/Trigonom/Functionality'/Trigonometric Function'
         */
    rtb_Mul_lc = f32_cos_f32((0.785398185F * rtb_Min_k) - (((f32_abs_f32(rtb_Min_k) - 1.0F) * rtb_Min_k) * ((f32_abs_f32(rtb_Min_k) * 0.0663F) + 0.2447F))) * (((rtb_Sum_iz + rtb_Mul_a1) + GET_S_ABPLBP_LeLnClthPosY0_met()) - GET_S_ODPFOP_AccObjPosY_met());
    /* End of Outputs for SubSystem: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2LeftBoundary/EvaluateLeftLaneClothoidAtPosX'/TrajectoryEquationOfCorridor' */
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/Constant'/Constant'
         */
    rtb_DataTypeConversion_h = (uint8)(rtb_Mul_lc > 0.0F);
    /* Outputs for Atomic SubSystem: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX'/TrajectoryEquationOfCorridor'
         *
         * Block description for 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX'/TrajectoryEquationOfCorridor':
         *  X.2.1.1.1.1.2.2.1.1
         */
    /* Trigonometry: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Trigonom/Functionality'/Trigonometric Function' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/AvoidUndefinedTangent/Constant'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/AvoidUndefinedTangent/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         *  MinMax: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/AvoidUndefinedTangent/Max/Functionality'/Max'
         *  MinMax: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/AvoidUndefinedTangent/Min/Functionality'/Min'
         */
    rtb_Abs_a = f32_tan_f32(f32_min_f32_f32(f32_max_f32_f32 (GET_S_ABPLBP_RiLnClthHeading_rad(), -0.785398185F), 0.785398185F));
    /* Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Add3/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         */
    rtb_Min_k = GET_S_ODPFOP_AccObjPosX_met() - GET_S_ABPLBP_RiLnClthPosX0_met();
    /* Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product5/Functionality'/Mul' */
    rtb_Sum_iz = rtb_Min_k * rtb_Min_k;
    /* Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain_const'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product1/Functionality'/Mul'
         */
    rtb_Mul_a1 = ((GET_S_ABPLBP_RiLnClthCrv_1pm() * rtb_Sum_iz) * 0.5F) + (rtb_Abs_a * rtb_Min_k);
    /* Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain1_const'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product6/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product7/Functionality'/Mul'
         */
    rtb_Mul_me = ((rtb_Sum_iz * rtb_Min_k) * GET_S_ABPLBP_RiLnClthCrvChng_1pm2()) * 0.166666672F;
    /* MinMax: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Min/Functionality'/Min' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain3_const'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant4'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  MinMax: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Max/Functionality'/Max'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Gain3/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product3/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Product4/Functionality'/Mul'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Sum1/Functionality'/Sum'
         */
    rtb_Sum_iz = f32_min_f32_f32(f32_max_f32_f32 ((((GET_S_ABPLBP_RiLnClthCrvChng_1pm2() * rtb_Sum_iz) * 0.5F) + rtb_Abs_a) + (GET_S_ABPLBP_RiLnClthCrv_1pm() * rtb_Min_k), -1.0F), 1.0F);
    /* Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/CalculateTargetObjectDist2RightBoundary/Mul2/Functionality'/Mul' incorporates:
         *  Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Abs/Functionality'/Abs'
         *  Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Abs1/Functionality'/Abs'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant2'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Constant3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Mul3/Functionality'/Mul'
         *  Product: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Mul4/Functionality'/Mul'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/CalculateTargetObjectDist2RightBoundary/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Add1/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/ApproxAtan/Sum3/Functionality'/Sum'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX/TrajectoryEquationOfCorridor/Sum3/Functionality'/Sum'
         *  Trigonometry: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/CalculateTargetObjectDist2RightBoundary/Trigonom1/Functionality'/Trigonometric Function'
         */
    rtb_Abs_a = f32_cos_f32((0.785398185F * rtb_Sum_iz) - (((f32_abs_f32 (rtb_Sum_iz) - 1.0F) * rtb_Sum_iz) * ((f32_abs_f32(rtb_Sum_iz) * 0.0663F) + 0.2447F))) * (((rtb_Mul_a1 + rtb_Mul_me) + GET_S_ABPLBP_RiLnClthPosY0_met()) - GET_S_ODPFOP_AccObjPosY_met());
    /* End of Outputs for SubSystem: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CheckDist2RightBoundary/EvaluateRightLaneClothoidAtPosX'/TrajectoryEquationOfCorridor' */
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/Constant'/Constant'
         */
    rtb_LT_b = (uint8)(rtb_Abs_a < 0.0F);
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Constant4'/Constant'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/AND1/Functionality'/AND'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Switch3/Functionality'/Switch'
         */
    if ((((sint32)rtb_LT_a) != 0) && (((sint32)rtb_LT_f) != 0)) {
        rtb_NE_m = 0U;
    } else if (((sint32)rtb_LT_a) != 0) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Constant2'/Constant'
                 */
        rtb_NE_m = 1U;
    } else if (((sint32)rtb_LT_f) != 0) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Constant3'/Constant'
                 *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Switch2/Functionality'/Switch'
                 */
        rtb_NE_m = 2U;
    } else {
        rtb_NE_m = 3U;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/SwitchCreator/Switch1/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/Constant1'/Constant'
         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/NOT1/Functionality'/Data Type Conversion'
         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/NOT2/Functionality'/Data Type Conversion'
         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/NOT3/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/NOT2/Functionality'/NOT'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck/NOT3/Functionality'/NOT'
         */
    switch (rtb_NE_m) {
    case 0:
        rtb_DataTypeConversion_h = (uint8)(!((((sint32)rtb_DataTypeConversion_h) != 0) && (((sint32)rtb_LT_b) != 0)));
        break;
    case 1:
        rtb_DataTypeConversion_h = (uint8)(!(((sint32)rtb_DataTypeConversion_h) != 0));
        break;
    case 2:
        rtb_DataTypeConversion_h = (uint8)(!(((sint32)rtb_LT_b) != 0));
        break;
    default:
        rtb_DataTypeConversion_h = 0U;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/TargetObjectInEgoLaneCheck'/Multiport_Switch' */
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/MappingUint16'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_h;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value2'/Signal Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/constant_value2'/Constant'
         */
    rtb_VectorConcatenate[0] = 0U;
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate[1] = (uint8)(!(((sint32)rtb_LogicalOperator_o) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate[2] = (uint8)(!(((sint32)rtb_LT_a) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate[3] = (uint8)(!(((sint32)rtb_LT_f) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND2/Functionality'/AND'
         */
    rtb_NE_m = (uint8)((((sint32)rtb_LT_a) != 0) && (((sint32)rtb_LT_f) != 0));
    /* Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Abs/Functionality'/Abs' */
    rtb_Switch4_a[0] = f32_abs_f32(rtb_Mul_lc);
    rtb_Switch4_a[1] = f32_abs_f32(rtb_Abs_a);
    /* Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Constant3'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Constant4'/Constant'
         */
    rtb_Min_k = GET_P_TJAOBF_TgtVehDist2LnBndMin_met() + GET_P_TJAOBF_TgtVehDist2LnBndHst_met();
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Constant3'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck'/Unit_Delay3'
         */
    for (i = 0; i < 2; i++) {
        if (rtb_Switch4_a[i] > rtb_Min_k) {
            rtb_Switch2_j[i] = 1U;
        } else if (rtb_Switch4_a[i] < GET_P_TJAOBF_TgtVehDist2LnBndMin_met()) {
            /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Constant'
                         */
            rtb_Switch2_j[i] = 0U;
        } else {
            rtb_Switch2_j[i] = DW_tjaobf_Unit_Delay3_DSTATE_l[i];
        }
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS3/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/NOT3/Functionality'/NOT'
         */
    rtb_LT_b = (uint8)(!(((sint32)rtb_Switch2_j[0]) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND3/Functionality'/AND'
         */
    rtb_VectorConcatenate[5] = (uint8)((((sint32)rtb_NE_m) != 0) && (((sint32) rtb_LT_b) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/NOT1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_po = (uint8)(!(((sint32)rtb_Switch2_j[1]) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND4/Functionality'/AND'
         */
    rtb_VectorConcatenate[6] = (uint8)((((sint32)rtb_NE_m) != 0) && (((sint32) rtb_DataTypeConversion_po) != 0));
    /* Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Abs1/Functionality'/Abs' */
    rtb_Switch4_a[0] = f32_abs_f32(rtb_Mul_lc);
    rtb_Switch4_a[1] = f32_abs_f32(rtb_Abs_a);
    /* Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Constant5'/Constant'
         */
    rtb_Abs_a = GET_P_TJAOBF_DefaultLaneWidth_met() - GET_P_TJAOBF_TgtVehDist2LnBndMin_met();
    /* Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/Constant2'/Constant'
         */
    rtb_Mul_lc = rtb_Abs_a - GET_P_TJAOBF_TgtVehDist2LnBndHst_met();
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck'/Unit_Delay1'
         */
    for (i = 0; i < 2; i++) {
        if (rtb_Switch4_a[i] > rtb_Abs_a) {
            rtb_Switch3_i2[i] = 1U;
        } else if (rtb_Switch4_a[i] < rtb_Mul_lc) {
            /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS1/Functionality'/Constant'
                         */
            rtb_Switch3_i2[i] = 0U;
        } else {
            rtb_Switch3_i2[i] = DW_tjaobf_Unit_Delay1_DSTATE_d[i];
        }
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck/HYSTERESIS1/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND5/Functionality'/AND'
         */
    rtb_VectorConcatenate[7] = (uint8)((((sint32)rtb_LT_a) != 0) && (((sint32) rtb_Switch3_i2[0]) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND6/Functionality'/AND'
         */
    rtb_VectorConcatenate[8] = (uint8)((((sint32)rtb_LT_f) != 0) && (((sint32) rtb_Switch3_i2[1]) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR1/Functionality'/OR'
         */
    rtb_NE_m = (uint8)((((sint32)rtb_LT_a) != 0) || (((sint32)rtb_LT_f) != 0));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/QualifierFreezeDuringAccObjChange/Switch2/Functionality'/Switch' incorporates:
         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/NOT1/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/AND1/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/AND1/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR/Functionality'/OR'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch/Functionality'/Switch'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch2/Functionality'/Switch'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/QualifierFreezeDuringAccObjChange'/Unit_Delay1'
         */
    if (((sint32)rtb_LT_d) != 0) {
        rtb_LT_b = DW_tjaobf_Unit_Delay1_DSTATE_n;
    } else {
        if ((((sint32)rtb_LT_a) != 0) && (((sint32)rtb_LT_f) != 0)) {
            /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch/Functionality'/Switch' incorporates:
                         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR2/Functionality'/Data Type Conversion'
                         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR2/Functionality'/OR'
                         */
            rtb_LT_f = (uint8)((((sint32)rtb_LT_b) != 0) || (((sint32) rtb_DataTypeConversion_po) != 0));
        } else if (((sint32)rtb_LT_f) != 0) {
            /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch1/Functionality'/Switch' incorporates:
                         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR3/Functionality'/Data Type Conversion'
                         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR3/Functionality'/OR'
                         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch/Functionality'/Switch'
                         */
            rtb_LT_f = (uint8)((((sint32)rtb_DataTypeConversion_po) != 0) || (((sint32)rtb_Switch3_i2[1]) != 0));
        } else {
            if (((sint32)rtb_LT_a) != 0) {
                /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch2/Functionality'/Switch' incorporates:
                                 *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR4/Functionality'/Data Type Conversion'
                                 *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/OR4/Functionality'/OR'
                                 *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch/Functionality'/Switch'
                                 *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/CaseAnalysis/Switch1/Functionality'/Switch'
                                 */
                rtb_LT_f = (uint8)((((sint32)rtb_Switch3_i2[0]) != 0) || (((sint32) rtb_LT_b) != 0));
            }
        }
        rtb_LT_b = (uint8)(!((((sint32)rtb_NE_m) != 0) && ((((sint32) rtb_DataTypeConversion_h) != 0) || (((sint32)rtb_LT_f) != 0))));
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/QualifierFreezeDuringAccObjChange/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/Validity_Debug/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/Validity_Debug/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate[10] = (uint8)(!(((sint32)rtb_LT_b) != 0));
    /* S-Function (sfun_setbit): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/CreateDebugSignal/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
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
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/QualifierFreezeDuringAccObjChange/Switch1/Functionality'/Switch' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/NOT/Functionality'/NOT'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/QualifierFreezeDuringAccObjChange'/Unit_Delay'
         */
    if (((sint32)rtb_LT_d) != 0) {
        rtb_LogicalOperator = DW_tjaobf_Unit_Delay_DSTATE_l;
    } else {
        if (((sint32)rtb_NE_m) != 0) {
            rtb_LogicalOperator = rtb_LogicalOperator_o;
        }
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/QualifierFreezeDuringAccObjChange/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/Constant2'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/constant_value2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/AND3/Functionality'/AND'
         */
    rtb_NE_m = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_TJAOBF_PrjSpecQuC_btm())) != 0);
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/from_data_definition2'/state_source'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AND1/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/OR/Functionality'/OR'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/EQ2/Functionality'/EQ'
         */
    rtb_LogicalOperator_o = (uint8)((((sint32)rtb_NE_m) != 0) && ((((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)))));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/Constant2'/Constant'
         *  Inport: '<Root>/S_TJAGEN_LKAOnlySwitch_bool'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AND2/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT3/Functionality'/NOT'
         */
    rtb_DataTypeConversion_h = (uint8)((((sint32)GET_P_TJAOBF_OF_Enabled_bool()) != 0) && (!(((sint32)GET_S_TJAGEN_LKAOnlySwitch_bool()) != 0)));
    /* Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjPosY0_met'
         */
    rtb_Abs_a = f32_abs_f32(GET_S_ODPFOH_TgtObjPosY0_met());
    /* S-Function Block sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/Y_TJAOBF_TgtClthPosYMaxWR_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TJAOBF_VehVelX_kph */
        FDPS_PTR_F32(GETA_X_TJAOBF_VehVelX_kph(), GET_S_LCFRCV_VDy_VehVelocity_kph(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TJAOBF_TgtClthPosYMaxWR_met(), &dps_result_ln);
    }
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/LT/Functionality'/LT' */
    rtb_LT_d = (uint8)(rtb_Abs_a < rtb_ip_lookup_fxpt_sfun_7);
    /* Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjHeadAng_rad'
         */
    rtb_Min_k = f32_abs_f32(GET_S_ODPFOH_TgtObjHeadAng_rad());
    /* S-Function Block sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/Y_TJAOBF_TgtClthHeadMaxWR_rad/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TJAOBF_VehVelX_kph */
        FDPS_PTR_F32(GETA_X_TJAOBF_VehVelX_kph(), GET_S_LCFRCV_VDy_VehVelocity_kph(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D (GETA_Y_TJAOBF_TgtClthHeadMaxWR_rad(), &dps_result_ln);
    }
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/LT/Functionality'/LT' */
    rtb_LT_f = (uint8)(rtb_Min_k < rtb_ip_lookup_fxpt_sfun_7_k);
    /* Abs: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjCrv_1pm'
         */
    rtb_Sum_iz = f32_abs_f32(GET_S_ODPFOH_TgtObjCrv_1pm());
    /* S-Function Block sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/Y_TJAOBF_TgtClthCrvMaxWR_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TJAOBF_VehVelX_kph */
        FDPS_PTR_F32(GETA_X_TJAOBF_VehVelX_kph(), GET_S_LCFRCV_VDy_VehVelocity_kph(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D(GETA_Y_TJAOBF_TgtClthCrvMaxWR_1pm (), &dps_result_ln);
    }
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/LT/Functionality'/LT' */
    rtb_LT_a = (uint8)(rtb_Sum_iz < rtb_ip_lookup_fxpt_sfun_7_p);
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/constant_value1'/Constant'
         *  Inport: '<Root>/S_ODPFOH_TgtObjClothoidInv_btf'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/EQ1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_po = (uint8)(((((((sint32) GET_S_ODPFOH_TgtObjClothoidInv_btf()) & ((sint32) GET_P_TJAOBF_TgtClthWRInvalid_btm())) == 0) && (((sint32)rtb_LT_d) != 0)) && (((sint32)rtb_LT_f) != 0)) && (((sint32)rtb_LT_a) != 0));
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/constant_value1'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/AND2/Functionality'/AND'
         */
    rtb_EQ_pi = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_TJAOBF_PrjSpecQuWR_btm())) == 0);
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck'/Unit_Delay'
         */
    if (((sint32)rtb_LogicalOperator_o) != 0) {
        rtb_Mul_lc = GET_P_TJALKA_BlockTimeTJA_sec();
    } else if (DW_tjaobf_Unit_Delay_DSTATE > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck'/Unit_Delay'
                 */
        rtb_Mul_lc = DW_tjaobf_Unit_Delay_DSTATE - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Mul_lc = 0.0F;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_pb = (uint8)(!(rtb_Mul_lc > 0.0F));
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/Constant8'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/constant_value4'/Constant'
         *  Inport: '<Root>/S_ODPFOH_TgtObjClothoidInv_btf'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/AND1/Functionality'/AND'
         */
    rtb_EQ_p = (uint8)((((sint32)GET_S_ODPFOH_TgtObjClothoidInv_btf()) & ((sint32)GET_P_TJAOBF_TgtClthInvalid_btm())) == 0);
    /* Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck'/Unit_Delay'
         */
    rtb_LogicalOperator_j = (uint8)((DW_tjaobf_Unit_Delay_DSTATE_e <= 0.0F) && (((sint32)rtb_EQ_p) != 0));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/Constant5'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/Sum/Functionality'/Sum'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck'/Unit_Delay'
         */
    if (rtb_Abs_a > (rtb_ip_lookup_fxpt_sfun_7 + GET_P_TJAOBF_TgtClthPosYMaxHyst_met())) {
        rtb_Switch3_ne = 1U;
    } else if (rtb_Abs_a < rtb_ip_lookup_fxpt_sfun_7) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3_ne = 0U;
    } else {
        rtb_Switch3_ne = DW_tjaobf_Unit_Delay_DSTATE_n;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/HYSTERESIS/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ow = (uint8)(!(((sint32)rtb_Switch3_ne) != 0));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/Sum/Functionality'/Sum'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck'/Unit_Delay'
         */
    if (rtb_Min_k > (rtb_ip_lookup_fxpt_sfun_7_k + GET_P_TJAOBF_TgtClthHeadMaxHyst_rad())) {
        rtb_Switch3_l = 1U;
    } else if (rtb_Min_k < rtb_ip_lookup_fxpt_sfun_7_k) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3_l = 0U;
    } else {
        rtb_Switch3_l = DW_tjaobf_Unit_Delay_DSTATE_lt;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/HYSTERESIS/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ab = (uint8)(!(((sint32)rtb_Switch3_l) != 0));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/Sum/Functionality'/Sum'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck'/Unit_Delay'
         */
    if (rtb_Sum_iz > (rtb_ip_lookup_fxpt_sfun_7_p + GET_P_TJAOBF_TgtClthCrvMaxHyst_1pm())) {
        rtb_Switch3_m = 1U;
    } else if (rtb_Sum_iz < rtb_ip_lookup_fxpt_sfun_7_p) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3_m = 0U;
    } else {
        rtb_Switch3_m = DW_tjaobf_Unit_Delay_DSTATE_o;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/HYSTERESIS/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_o = (uint8)(!(((sint32)rtb_Switch3_m) != 0));
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/Subsystem/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/Subsystem/Constant4'/Constant'
         *  Inport: '<Root>/S_ODPFOH_TgtObjLength_met'
         */
    rtb_GT_i = (uint8)(GET_S_ODPFOH_TgtObjLength_met() > GET_P_TJAOBF_TgtClthLengthMin_met());
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_a2 = (uint8)(((((((sint32)rtb_LogicalOperator_j) != 0) && (((sint32)rtb_DataTypeConversion_ow) != 0)) && (((sint32) rtb_DataTypeConversion_ab) != 0)) && (((sint32)rtb_DataTypeConversion_o) != 0)) && (((sint32)rtb_GT_i) != 0));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/Constant2'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/Constant8'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/constant_value4'/Constant'
         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/AND/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalLeverHold_bool'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/NOT1/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/NEQ/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/AND1/Functionality'/AND'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck'/Unit_Delay1'
         */
    if (((sint32)GET_P_TJASLC_SALC_Enabled_bool()) != 0) {
        rtb_DataTypeConversion_oc = (uint8)((((sint32)DW_tjaobf_Unit_Delay1_DSTATE_h) != 0) && (!(((sint32)GET_S_LCFRCV_TurnSignalLeverHold_bool()) != 0)));
    } else {
        rtb_DataTypeConversion_oc = (uint8)((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_TJAOBF_DrvStInvalidSR_btm())) != 0);
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_oc = (uint8)(!(((sint32)rtb_DataTypeConversion_oc) != 0));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/Constant4'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS1/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/Sum1/Functionality'/Sum'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing'/Unit_Delay1'
         */
    if (GET_S_LCFRCV_VDy_VehVelocity_kph() > (GET_P_TJAOBF_VelXMax_kph() + GET_P_TJALKA_VelXHyst_kph())) {
        rtb_Switch3_oz = 1U;
    } else if (GET_S_LCFRCV_VDy_VehVelocity_kph() < GET_P_TJAOBF_VelXMax_kph()) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_oz = 0U;
    } else {
        rtb_Switch3_oz = DW_tjaobf_Unit_Delay1_DSTATE_nu;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS1/Functionality'/Switch3' */
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/Constant3'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/Constant5'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/Sum2/Functionality'/Sum'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing'/Unit_Delay2'
         */
    if (GET_S_LCFRCV_VDy_VehVelocity_kph() > GET_P_TJAOBF_VelXMin_kph()) {
        rtb_Switch3_p = 1U;
    } else if (GET_S_LCFRCV_VDy_VehVelocity_kph() < (GET_P_TJAOBF_VelXMin_kph() - GET_P_TJALKA_VelXHyst_kph())) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3_p = 0U;
    } else {
        rtb_Switch3_p = DW_tjaobf_Unit_Delay2_DSTATE_m;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/HYSTERESIS2/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/AND/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing/NOT1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_im = (uint8)((!(((sint32)rtb_Switch3_oz) != 0)) && (((sint32)rtb_Switch3_p) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/from_data_definition1'/state_source'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_m = (uint8)((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/Constant3'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Constant1'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Inport: '<Root>/S_TJALKA_Cancel_bool'
         *  Inport: '<Root>/S_TJALKA_StrongReady_bool'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/AND2/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/AND3/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Logical Operator'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Relational Operator2'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity'/Unit_Delay1'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity'/Unit_Delay2'
         */
    if ((((DW_tjaobf_Unit_Delay2_DSTATE_c <= 0.0F) && (((sint32) rtb_DataTypeConversion_m) != 0)) && (!((((sint32) GET_S_TJALKA_StrongReady_bool()) != 0) && (!(((sint32) GET_S_TJALKA_Cancel_bool()) != 0))))) && (DW_tjaobf_Unit_Delay1_DSTATE_e <= 0.0F)) {
        rtb_Abs_a = GET_P_TJAOBF_MaxDurObjBrdg_sec();
    } else if (DW_tjaobf_Unit_Delay1_DSTATE_e > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality/Sum/Functionality'/Sum'
                 */
        rtb_Abs_a = DW_tjaobf_Unit_Delay1_DSTATE_e - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Constant2'
                 */
        rtb_Abs_a = 0.0F;
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/Constant1'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Constant'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TIMER_RE/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_hu = (uint8)((rtb_Abs_a > 0.0F) && (((sint32) GET_P_TJAOBF_ObjBrdgEnabled_bool()) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/ConstructionSite/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/ConstructionSite/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/ConstructionSite/AND/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/ConstructionSite/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_jb = (uint8)(!((((sint32) GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32) GET_P_TJAOBF_ConstSiteCheckOn_bool()) != 0)));
    /* RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/Constant8'/Constant'
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/constant_value4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CustomSpecificQualifiersCheck/AND1/Functionality'/AND'
         */
    rtb_EQ_h = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_TJAOBF_PrjSpecQuSR_btm())) == 0);
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/Constant4'/Constant'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_ia = (uint8)((((sint32)rtb_LogicalOperator) != 0) || (!(((sint32)GET_P_TJAOBF_CheckAccObjValidty_bool()) != 0)));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/Constant1'/Constant'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_lt = (uint8)((((sint32)rtb_LT_b) != 0) || (!(((sint32) GET_P_TJAOBF_LaneCheckEnabled_bool()) != 0)));
    /* Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck'/Unit_Delay2'
         */
    rtb_sfun_setbit_d = (uint8)((DW_tjaobf_Unit_Delay2_DSTATE_bv <= 0.0F) && (((sint32)rtb_DataTypeConversion_lt) != 0));
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch1'/copy1' incorporates:
         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AND4/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AND4/Functionality'/AND'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/Logical Operator4/Functionality'/OR'
         */
    SET_S_TJAOBF_StrongReady_bool((uint8)((((((((((sint32) rtb_DataTypeConversion_a2) != 0) && (((sint32)rtb_DataTypeConversion_oc) != 0)) && ((((sint32)rtb_DataTypeConversion_im) != 0) || (((sint32) rtb_DataTypeConversion_hu) != 0))) && (((sint32)rtb_DataTypeConversion_h) != 0)) && (((sint32)rtb_DataTypeConversion_jb) != 0)) && (((sint32)rtb_EQ_h) != 0)) && (((sint32)rtb_DataTypeConversion_ia) != 0)) && (((sint32) rtb_sfun_setbit_d) != 0)));
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_lt) != 0) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck'/Unit_Delay2'
                 */
        if (DW_tjaobf_Unit_Delay2_DSTATE_bv > 0.0F) {
            /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjaobf_Unit_Delay2_DSTATE_bv -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/Constant3'/Constant'
                 */
        DW_tjaobf_Unit_Delay2_DSTATE_bv = GET_P_TJAOBF_MinDurObjLnValidWR_sec();
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AccObjValidityCheck/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_m) != 0) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity'/Unit_Delay2'
                 */
        if (DW_tjaobf_Unit_Delay2_DSTATE_c > 0.0F) {
            /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjaobf_Unit_Delay2_DSTATE_c -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/Constant4'/Constant'
                 */
        DW_tjaobf_Unit_Delay2_DSTATE_c = GET_P_TJAOBF_MinDurLCforOB_sec();
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MappingUint16'/ConcatBufferAtVector ConcatenateIn13' */
    rtb_VectorConcatenate_l[12] = rtb_NE_m;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MappingUint16'/ConcatBufferAtVector ConcatenateIn14' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/Constant'/Constant'
         */
    rtb_VectorConcatenate_l[13] = 0U;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MappingUint16'/ConcatBufferAtVector ConcatenateIn15' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/Constant'/Constant'
         */
    rtb_VectorConcatenate_l[14] = 0U;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MappingUint16'/ConcatBufferAtVector ConcatenateIn16' incorporates:
         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/Constant'/Constant'
         */
    rtb_VectorConcatenate_l[15] = 0U;
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MappingUint16'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_l[3] = rtb_DataTypeConversion_hu;
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT11/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT11/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_ia) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[1] = (uint8)(!(((sint32)rtb_DataTypeConversion_a2) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[2] = (uint8)(!(((sint32)rtb_DataTypeConversion_im) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT10/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[4] = (uint8)(!(((sint32)rtb_DataTypeConversion_oc) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[5] = (uint8)(!(((sint32)rtb_DataTypeConversion_h) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[6] = (uint8)(!(((sint32)rtb_DataTypeConversion_jb) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT14/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT14/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[7] = (uint8)(!(((sint32)rtb_EQ_h) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[8] = (uint8)(!(((sint32)rtb_DataTypeConversion_po) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[9] = (uint8)(!(((sint32)rtb_EQ_pi) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[10] = (uint8)(!(((sint32)rtb_DataTypeConversion_pb) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/NOT9/Functionality'/NOT'
         */
    rtb_VectorConcatenate_l[11] = (uint8)(!(((sint32)rtb_sfun_setbit_d) != 0));
    /* S-Function (sfun_setbit): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_l[0];
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
        rtb_sfun_setbit_j = temp;
    }
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[0] = (uint8)(!(((sint32)rtb_LogicalOperator_j) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[1] = (uint8)(!(((sint32)rtb_DataTypeConversion_ow) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[2] = (uint8)(!(((sint32)rtb_DataTypeConversion_ab) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[3] = (uint8)(!(((sint32)rtb_DataTypeConversion_o) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[4] = (uint8)(!(((sint32)rtb_GT_i) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[5] = (uint8)(!(((sint32)rtb_LT_d) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[6] = (uint8)(!(((sint32)rtb_LT_f) != 0));
    /* DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[7] = (uint8)(!(((sint32)rtb_LT_a) != 0));
    /* S-Function (sfun_setbit): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/MappingUint2/set_bit1/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_d = temp;
    }
    /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ_p) != 0) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck'/Unit_Delay'
                 */
        if (DW_tjaobf_Unit_Delay_DSTATE_e > 0.0F) {
            /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck'/Unit_Delay' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjaobf_Unit_Delay_DSTATE_e -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck'/Unit_Delay' incorporates:
                 *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/Constant5'/Constant'
                 */
        DW_tjaobf_Unit_Delay_DSTATE_e = GET_P_TJAOBF_TgtClthMinValidTime_sec();
    }
    /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjBitfieldCheck/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch2'/copy1' incorporates:
         *  DataTypeConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AND3/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/AND3/Functionality'/AND'
         */
    SET_S_TJAOBF_WeakReady_bool((uint8)(((((sint32)rtb_DataTypeConversion_po) != 0) && (((sint32)rtb_EQ_pi) != 0)) && (((sint32)rtb_DataTypeConversion_pb) != 0)));
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch3'/copy1' */
    SET_D_TJAOBF_ObjFollowInvalid_btf(rtb_sfun_setbit_j);
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch4'/copy1' */
    SET_S_TJAOBF_Cancel_bool(rtb_LogicalOperator_o);
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch5'/copy1' */
    SET_D_TJAOBF_ObjInLaneInvalid_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch6'/copy1' */
    SET_S_TJAOBF_TgtObjDataValid_bool(rtb_DataTypeConversion_a2);
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch7'/copy1' */
    SET_S_TJAOBF_ObjInLaneValid_bool(rtb_LT_b);
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch8'/copy1' */
    SET_S_TJAOBF_AccObjValid_bool(rtb_LogicalOperator);
    /* SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/branch9'/copy1' */
    SET_D_TJAOBF_TgtObjDataInvalid_btf(rtb_sfun_setbit_d);
    /* S-Function (fcncallgen): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING'/fcg' incorporates:
                                                             *  SubSystem: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING'/Functionality'
                                                             */
    /* S-Function (fcncallgen): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjaobf_Unit_Delay2_DSTATE_cf = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/AccObjectValidityCheck/HoldObjChangeFlag/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid'/Unit_Delay2' */
    DW_tjaobf_Unit_Delay2_DSTATE_e = LogicalOperator;
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Switch2' */
        if (((sint32)rtb_Switch3[i]) != 0) {
            /* Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Switch4' incorporates:
                         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Constant'
                         *  RelationalOperator: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Relational Operator'
                         *  UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck'/Unit_Delay3'
                         */
            if (DW_tjaobf_Unit_Delay3_DSTATE[i] > 0.0F) {
                /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck'/Unit_Delay3' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality/Add/Functionality'/Sum'
                                 */
                DW_tjaobf_Unit_Delay3_DSTATE[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
            /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Switch4' */
        } else {
            /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck'/Unit_Delay3' incorporates:
                         *  Constant: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/Constant7'/Constant'
                         */
            DW_tjaobf_Unit_Delay3_DSTATE[i] = GET_P_TJACMB_LnQualMinOnTmWR_sec();
        }
        /* End of Switch: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck/TURNONDELAYTIME1/Functionality'/Switch2' */
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/LaneCheckPreConditions/LaneAttributesValid/LaneQualityCheck'/Unit_Delay1' */
        DW_tjaobf_Unit_Delay1_DSTATE_a[i] = rtb_Switch3[i];
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck'/Unit_Delay3' */
        DW_tjaobf_Unit_Delay3_DSTATE_l[i] = rtb_Switch2_j[i];
        /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/ObjectInEgoLaneEvaluation/Distance2BoundaryCheck/MinimumDistanceToLaneBoundaryCheck'/Unit_Delay1' */
        DW_tjaobf_Unit_Delay1_DSTATE_d[i] = rtb_Switch3_i2[i];
    }
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/QualifierFreezeDuringAccObjChange'/Unit_Delay1' */
    DW_tjaobf_Unit_Delay1_DSTATE_n = rtb_LT_b;
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/CombinedObjectLaneCheck/GenerateValidityQualifier/QualifierFreezeDuringAccObjChange'/Unit_Delay' */
    DW_tjaobf_Unit_Delay_DSTATE_l = rtb_LogicalOperator;
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/BlockingTimeConditionCheck'/Unit_Delay' */
    DW_tjaobf_Unit_Delay_DSTATE = rtb_Mul_lc;
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjPosYCheck'/Unit_Delay' */
    DW_tjaobf_Unit_Delay_DSTATE_n = rtb_Switch3_ne;
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjHeadingCheck'/Unit_Delay' */
    DW_tjaobf_Unit_Delay_DSTATE_lt = rtb_Switch3_l;
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/TargetClothoidValidityCheck/TargetObjCurvatureCheck'/Unit_Delay' */
    DW_tjaobf_Unit_Delay_DSTATE_o = rtb_Switch3_m;
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/TurnSignalCheck'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_TurnSignalLeverHold_bool'
         */
    DW_tjaobf_Unit_Delay1_DSTATE_h = GET_S_LCFRCV_TurnSignalLeverHold_bool();
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing'/Unit_Delay1' */
    DW_tjaobf_Unit_Delay1_DSTATE_nu = rtb_Switch3_oz;
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/MaxVehVelXCheck_ObjectFollowing'/Unit_Delay2' */
    DW_tjaobf_Unit_Delay2_DSTATE_m = rtb_Switch3_p;
    /* Update for UnitDelay: 'sda:TJAOBF/TJAOBF/TJAOBF_SenProcess/M_TJAOBF/ObjectFollowingConditions/CheckForObjectBridgingValidity'/Unit_Delay1' */
    DW_tjaobf_Unit_Delay1_DSTATE_e = rtb_Abs_a;
}
#include "Pse_TJAOBF.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
