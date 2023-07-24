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
 * File          : MCTLFC
 * Generated on  : Thu 17.01.2019 at 15:36:02 (UTC+01:00)
 * MD5           : [1238070630  4234946184  2437353000  2768753694 0](MCTLFC)
 *
 * Purpose       : <Purpose>
 * Specification : <Specification>
 *
 * Environment information:
 * Processor     : 32 Bit generic
 * Platform      : EMS3
 * SDA version   : 10.0
 * Hot fixes     : SDA-RPT: 1 SDA-Core: 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,56,57,58,59
 * Add-ons       : -
 *
 * Version management information:
 * Filename      : $Workfile: $
 * Revision      : $Revision: 1.2.1.1 $
 * Author        : $Author: Diaz Bravo, Jose Luis (uidg8685) $
 * Date          : $Date: 2019/05/29 09:52:52CEST $
 * Changes       :
 * $Log: MCTLFC.c  $
 * Revision 1.2.1.1 2019/05/29 09:52:52CEST Diaz Bravo, Jose Luis (uidg8685) 
 * B2B
 * Revision 1.17 2019/01/17 15:44:17CET Diaz Bravo, Jose Luis (uidg8685) 
 * automatically created
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "MCTLFC.h"
#include "MCTLFC_private.h"
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
/* Named constants for Chart: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/MCT_StateMachine' */
#define IN_ALCA                        ((uint8)1U)
#define IN_AOLC                        ((uint8)2U)
#define IN_ESA                         ((uint8)3U)
#define IN_LDP                         ((uint8)4U)
#define IN_LDPOC                       ((uint8)5U)
#define IN_OFF                         ((uint8)6U)
#define IN_RDP                         ((uint8)7U)
#define IN_TJA                         ((uint8)8U)
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
#define MCTLFC_START_SEC_DATA_8
#include "MCTLFC_MemMap.h"
static uint8 BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l;
/* 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/MCT_StateMachine' */
static uint8 DW_mctlfc_Unit_Delay2_DSTATE[7];
static uint8 DW_mctlfc_Unit_Delay1_DSTATE[7] = {1U,1U,1U,1U,1U,1U,1U};
static uint8 DW_mctlfc_is_active_c5_MCTLFC_cg;
static uint8 DW_mctlfc_is_c5_MCTLFC_cg;
#define MCTLFC_STOP_SEC_DATA_8
#include "MCTLFC_MemMap.h"
#define MCTLFC_START_SEC_DATA_32
#include "MCTLFC_MemMap.h"
static float32 DW_mctlfc_Unit_Delay_DSTATE[7];
#define MCTLFC_STOP_SEC_DATA_32
#include "MCTLFC_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:MCTLFC/MCTLFC/INI'/MCTLFC_SenReset'
 * Block description for: 'sda:MCTLFC/MCTLFC/INI'/MCTLFC_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_MCTLFC_SenReset
#include "Pse_MCTLFC.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void MCTLFC_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:MCTLFC/MCTLFC/INI/MCTLFC_SenReset/Constant'/Constant' */
    SET_S_MCTLFC_ControllingFunction_nu(0U);
}
#include "Pse_MCTLFC.h"
/* System initialize for function-call system: 'sda:MCTLFC/MCTLFC'/MCTLFC_SenProcess' */
/*
 * Output and update for function-call system: 'sda:MCTLFC/MCTLFC'/MCTLFC_SenProcess'
 * Block description for: 'sda:MCTLFC/MCTLFC'/MCTLFC_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_MCTLFC_SenProcess
#include "Pse_MCTLFC.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void MCTLFC_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    uint8 rtb_EQ_d[7];
    uint8 rtb_EQ_p[7];
    uint8 rtb_sfun_or;
    uint8 rtb_Switch_a[7];
    uint8 rtb_DataTypeConversion;
    sint8 rtb_EQ_g[7];
    float32 rtb_Switch[7];
    sint32 i;
    uint8 rtb_Switch_gn;
    uint8 rtb_EQ_o;
    float32 rtb_Switch_l;
    /* Outputs for Atomic SubSystem: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM'/M_MCTLFC'
         *
         * Block description for 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM'/M_MCTLFC':
         *  X.2.1.1
         */
    /* SignalConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         */
    rtb_Switch_a[0] = GET_S_TJASTM_SysStateTJA_nu();
    /* SignalConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/ConcatBufferAtVector ConcatenateIn2' incorporates:
         *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
         */
    rtb_Switch_a[1] = GET_S_DPLSMI_SysStateLDP_nu();
    /* SignalConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Inport: '<Root>/S_DPOSTM_SysStateLDPOC_nu'
         */
    rtb_Switch_a[2] = GET_S_DPOSTM_SysStateLDPOC_nu();
    /* SignalConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
         */
    rtb_Switch_a[3] = GET_S_DPRSMI_SysStateRDP_nu();
    /* SignalConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/ConcatBufferAtVector ConcatenateIn5' incorporates:
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         */
    rtb_Switch_a[4] = GET_S_LCRSMI_SysStateALCA_nu();
    /* SignalConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Inport: '<Root>/S_LCSSTM_SysStateAOLC_nu'
         */
    rtb_Switch_a[5] = GET_S_LCSSTM_SysStateAOLC_nu();
    /* SignalConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Inport: '<Root>/S_ESASTM_SysStateESA_nu'
         */
    rtb_Switch_a[6] = GET_S_ESASTM_SysStateESA_nu();
    /* RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/from_data_definition17'/state_source'
         */
    for (i = 0; i < 7; i++) {
        rtb_EQ_d[i] = (uint8)(((sint32)rtb_Switch_a[i]) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)));
    }
    /* End of RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Relational Operator2/Functionality'/EQ' */
    /* S-Function (sfun_or): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Logical Operator1/Functionality'/sfun_or' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_EQ_d[0];
        for (i1=1; i1<7; i1++) {
            temp = temp || rtb_EQ_d[i1];
        }
        rtb_sfun_or = temp;
    }
    /* RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/from_data_definition3'/state_source'
         */
    for (i = 0; i < 7; i++) {
        rtb_EQ_p[i] = (uint8)(((sint32)rtb_Switch_a[i]) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    }
    /* End of RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Relational Operator3/Functionality'/EQ' */
    /* S-Function (sfun_or): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Logical Operator2/Functionality'/sfun_or' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_EQ_p[0];
        for (i1=1; i1<7; i1++) {
            temp = temp || rtb_EQ_p[i1];
        }
        rtb_DataTypeConversion = temp;
    }
    /* DataTypeConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Logical Operator3/Functionality'/OR'
         */
    rtb_DataTypeConversion = (uint8)((((sint32)rtb_sfun_or) != 0) || (((sint32) rtb_DataTypeConversion) != 0));
    for (i = 0; i < 7; i++) {
        /* Product: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Product2/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Constant2'/Constant'
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Constant6'/Constant'
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/from_data_definition'/state_source'
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/from_data_definition1'/state_source'
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/from_data_definition2'/state_source'
                 *  Logic: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/AND1/Functionality'/AND'
                 *  Logic: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/AND2/Functionality'/AND'
                 *  Logic: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Logical Operator/Functionality'/OR'
                 *  Logic: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/NOT1/Functionality'/NOT'
                 *  RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Relational Operator/Functionality'/EQ'
                 *  RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Relational Operator1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Relational Operator14/Functionality'/EQ'
                 */
        rtb_Switch_gn = (uint8)(((uint32)(((((sint32)rtb_Switch_a[i]) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)rtb_Switch_a[i]) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || ((((sint32) rtb_Switch_a[i]) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) && (!((((sint32) GET_P_MCTLFC_RampOutOverwrite_bool((i))) != 0) && (((sint32) rtb_DataTypeConversion) != 0)))))) * ((uint32)((sint32) GET_P_MCTLFC_PriorityVector_nu((i)))));
        /* RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EQ/Functionality'/EQ' incorporates:
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/Constant5'/Constant'
                 */
        rtb_EQ_o = (uint8)(((sint32)rtb_Switch_gn) == 0);
        /* S-Function (fcncallgen): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality'/Comparison'
                 */
        /* Switch: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/Constant1'/Constant'
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Logic: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality'/Logical Operator2'
                 *  Logic: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality/Comparison'/Logical Operator'
                 *  RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
                 *  Switch: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality'/Switch2'
                 *  UnitDelay: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer'/Unit_Delay'
                 *  UnitDelay: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer'/Unit_Delay1'
                 */
        if ((!(((sint32)DW_mctlfc_Unit_Delay1_DSTATE[i]) != 0)) && (((sint32)rtb_EQ_o) != 0)) {
            rtb_Switch_l = GET_P_MCTLFC_FollowUpDurationVec_sec((i));
        } else if (DW_mctlfc_Unit_Delay_DSTATE[i] > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
            /* Switch: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                         *  UnitDelay: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer'/Unit_Delay'
                         */
            rtb_Switch_l = DW_mctlfc_Unit_Delay_DSTATE[i] - GET_S_LCFRCV_SysCycleTimeSen_sec();
        } else {
            rtb_Switch_l = 0.0F;
        }
        /* End of Outputs for S-Function (fcncallgen): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING'/fcg' */
        /* Switch: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality'/Constant'
                 *  RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
                 *  UnitDelay: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer'/Unit_Delay2'
                 */
        if (rtb_Switch_l > 0.0F) {
            rtb_Switch_gn = DW_mctlfc_Unit_Delay2_DSTATE[i];
        }
        /* End of Switch: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/Switch/Functionality'/Switch' */
        /* RelationalOperator: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EQ/Functionality'/EQ' */
        rtb_EQ_g[i] = (sint8)rtb_EQ_o;
        /* Switch: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/TIMERRETRIGGER_RE/Functionality'/Switch' */
        rtb_Switch[i] = rtb_Switch_l;
        /* Product: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Product2/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/Constant6'/Constant'
                 */
        rtb_Switch_a[i] = rtb_Switch_gn;
    }
    /* MinMax: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MinMax/Functionality'/Max' */
    rtb_DataTypeConversion = rtb_Switch_a[0];
    for (i = 0; i < 6; i++) {
        rtb_DataTypeConversion = u8_max_u8_u8(rtb_DataTypeConversion, rtb_Switch_a[i + 1]);
    }
    /* Chart: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/MCT_StateMachine' incorporates:
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition1'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition10'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition11'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition12'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition14'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition15'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition2'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition3'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition4'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition5'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition6'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition7'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition8'/state_source'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/from_data_definition9'/state_source'
         *  MinMax: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MinMax/Functionality'/Max'
         *  Selector: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/Selector'
         *  Selector: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/Selector1'
         *  Selector: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/Selector2'
         *  Selector: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/Selector3'
         *  Selector: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/Selector4'
         *  Selector: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/Selector5'
         *  Selector: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/Selector6'
         *
         * Block description for 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/MCT_StateMachine':
         *  X.2.1.1.1
         */
    /* Gateway: MCTLFC_cg/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine */
    /* During: MCTLFC_cg/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine */
    if (((uint32)((sint32)DW_mctlfc_is_active_c5_MCTLFC_cg)) == 0U) {
        /* Entry: MCTLFC_cg/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine */
        DW_mctlfc_is_active_c5_MCTLFC_cg = 1U;
        /* Entry Internal: MCTLFC_cg/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine */
        /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':8' */
        DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
        /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
        BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
    } else {
        switch (DW_mctlfc_is_c5_MCTLFC_cg) {
        case IN_ALCA:
            /* During 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
            if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) < ((sint32) rtb_DataTypeConversion)) || (((sint32)rtb_DataTypeConversion) == 0)) {
                /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':48' */
                if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32)rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':79' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ESA;
                    /* Entry 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':43' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDPOC;
                    /* Entry 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':49' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_AOLC;
                    /* Entry 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':47' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ALCA;
                    /* Entry 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':45' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_RDP;
                    /* Entry 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':42' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDP;
                    /* Entry 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':40' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_TJA;
                    /* Entry 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu);
                } else {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':57' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
                    /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
                }
            }
            break;
        case IN_AOLC:
            /* During 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
            if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) < ((sint32) rtb_DataTypeConversion)) || (((sint32)rtb_DataTypeConversion) == 0)) {
                /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':50' */
                if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32)rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':79' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ESA;
                    /* Entry 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':43' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDPOC;
                    /* Entry 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':49' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_AOLC;
                    /* Entry 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':47' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ALCA;
                    /* Entry 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':45' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_RDP;
                    /* Entry 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':42' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDP;
                    /* Entry 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':40' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_TJA;
                    /* Entry 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu);
                } else {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':57' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
                    /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
                }
            }
            break;
        case IN_ESA:
            /* During 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
            if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) < ((sint32) rtb_DataTypeConversion)) || (((sint32)rtb_DataTypeConversion) == 0)) {
                /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':78' */
                if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32)rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':79' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ESA;
                    /* Entry 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':43' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDPOC;
                    /* Entry 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':49' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_AOLC;
                    /* Entry 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':47' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ALCA;
                    /* Entry 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':45' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_RDP;
                    /* Entry 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':42' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDP;
                    /* Entry 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':40' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_TJA;
                    /* Entry 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu);
                } else {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':57' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
                    /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
                }
            }
            break;
        case IN_LDP:
            /* During 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
            if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) < ((sint32) rtb_DataTypeConversion)) || (((sint32)rtb_DataTypeConversion) == 0)) {
                /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':41' */
                if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32)rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':79' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ESA;
                    /* Entry 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':43' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDPOC;
                    /* Entry 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':49' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_AOLC;
                    /* Entry 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':47' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ALCA;
                    /* Entry 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':45' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_RDP;
                    /* Entry 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':42' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDP;
                    /* Entry 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':40' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_TJA;
                    /* Entry 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu);
                } else {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':57' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
                    /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
                }
            }
            break;
        case IN_LDPOC:
            /* During 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
            if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) < ((sint32) rtb_DataTypeConversion)) || (((sint32)rtb_DataTypeConversion) == 0)) {
                /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':44' */
                if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32)rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':79' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ESA;
                    /* Entry 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':43' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDPOC;
                    /* Entry 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':49' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_AOLC;
                    /* Entry 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':47' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ALCA;
                    /* Entry 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':45' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_RDP;
                    /* Entry 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':42' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDP;
                    /* Entry 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':40' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_TJA;
                    /* Entry 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu);
                } else {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':57' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
                    /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
                }
            }
            break;
        case IN_OFF:
            /* During 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
            if (((sint32)rtb_DataTypeConversion) != 0) {
                /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':56' */
                if (((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':79' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ESA;
                    /* Entry 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu);
                } else if (((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':43' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDPOC;
                    /* Entry 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu);
                } else if (((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':49' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_AOLC;
                    /* Entry 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu);
                } else if (((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':47' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ALCA;
                    /* Entry 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu);
                } else if (((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':45' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_RDP;
                    /* Entry 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu);
                } else if (((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':42' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDP;
                    /* Entry 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu);
                } else if (((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':40' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_TJA;
                    /* Entry 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu);
                } else {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':57' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
                    /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
                }
            }
            break;
        case IN_RDP:
            /* During 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
            if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) < ((sint32) rtb_DataTypeConversion)) || (((sint32)rtb_DataTypeConversion) == 0)) {
                /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':46' */
                if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32)rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':79' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ESA;
                    /* Entry 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':43' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDPOC;
                    /* Entry 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':49' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_AOLC;
                    /* Entry 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':47' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ALCA;
                    /* Entry 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':45' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_RDP;
                    /* Entry 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':42' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDP;
                    /* Entry 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':40' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_TJA;
                    /* Entry 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu);
                } else {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':57' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
                    /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
                }
            }
            break;
        default:
            /* During 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
            if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) < ((sint32) rtb_DataTypeConversion)) || (((sint32)rtb_DataTypeConversion) == 0)) {
                /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':39' */
                if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32)rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':79' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ESA;
                    /* Entry 'ESA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':77' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':43' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDPOC;
                    /* Entry 'LDPOC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':5' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':49' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_AOLC;
                    /* Entry 'AOLC': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':3' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':47' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_ALCA;
                    /* Entry 'ALCA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':6' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':45' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_RDP;
                    /* Entry 'RDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':7' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':42' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_LDP;
                    /* Entry 'LDP': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':4' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu);
                } else if ((((sint32)rtb_Switch_a[((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) - 1]) == ((sint32) rtb_DataTypeConversion)) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':40' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_TJA;
                    /* Entry 'TJA': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':2' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu);
                } else {
                    /* Transition: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':57' */
                    DW_mctlfc_is_c5_MCTLFC_cg = IN_OFF;
                    /* Entry 'OFF': 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/MCT_StateMachine':1' */
                    BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = ((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu);
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC'/MCT_StateMachine' */
    /* Switch: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/Constant1'/Constant'
         *  Constant: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/Constant2'/Constant'
         */
    if (((sint32)GET_P_MCTLFC_ErrInjEnable_bool()) != 0) {
        SET_S_MCTLFC_ControllingFunction_nu(GET_P_MCTLFC_ControllingFunction_nu());
    } else {
        SET_S_MCTLFC_ControllingFunction_nu(BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l);
    }
    /* End of Switch: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/Switch/Functionality'/Switch' */
    for (i = 0; i < 7; i++) {
        /* Update for UnitDelay: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer'/Unit_Delay2' */
        DW_mctlfc_Unit_Delay2_DSTATE[i] = rtb_Switch_a[i];
        /* S-Function (fcncallgen): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality'/SignalConversion'
                 */
        /* Update for UnitDelay: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer'/Unit_Delay1' incorporates:
                 *  SignalConversion: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
                 */
        DW_mctlfc_Unit_Delay1_DSTATE[i] = (uint8)rtb_EQ_g[i];
        /* End of Outputs for S-Function (fcncallgen): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer/EDGERISING'/fcg' */
        /* Update for UnitDelay: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM/M_MCTLFC/RequestLCF/FollowUpTimer'/Unit_Delay' */
        DW_mctlfc_Unit_Delay_DSTATE[i] = rtb_Switch[i];
    }
    /* End of Outputs for SubSystem: 'sda:MCTLFC/MCTLFC/MCTLFC_SenProcess/OPM'/M_MCTLFC' */
}
#include "Pse_MCTLFC.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
