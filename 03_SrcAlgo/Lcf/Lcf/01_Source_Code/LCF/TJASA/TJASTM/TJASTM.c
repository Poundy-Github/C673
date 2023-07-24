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
 * File          : TJASTM
 * Generated on  : Mon 08.07.2019 at 13:16:49 (UTC+01:00)
 * MD5           : [356862033   887822466  1821126801  1001640659 0](TJASTM)
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
 * Revision      : $Revision: 1.4 $
 * Author        : $Author: Werum, Gregor (uidq2175) $
 * Date          : $Date: 2019/08/29 10:04:20CEST $
 * Changes       :
 * $Log: TJASTM.c  $
 * Revision 1.4 2019/08/29 10:04:20CEST Werum, Gregor (uidq2175) 
 * Module test update according to findings (FCT_CMP_TJASA_1577, FCT_CMP_TJASA_2145)
 * Revision 1.20.1.4 2019/07/08 14:11:39CEST Werum, Gregor (uidq2175) 
 * - Update module test
 * - Update .req file
 * - Bugfix to reduce number of not required branches (NOT_PRESENT, ERROR states)
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TJASTM.h"
#include "TJASTM_private.h"
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
/* Named constants for Chart: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/LatCtrlMode' */
#define IN_Combined                    ((uint8)1U)
#define IN_Controlling                 ((uint8)1U)
#define IN_LaneCentering               ((uint8)2U)
#define IN_LaneChange                  ((uint8)3U)
#define IN_NO_ACTIVE_CHILD             ((uint8)0U)
#define IN_ObjectFollowing             ((uint8)3U)
#define IN_ObjectFollowing_g           ((uint8)4U)
#define IN_Passive                     ((uint8)2U)
#define IN_Request                     ((uint8)3U)
/* Named constants for Chart: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/StateMachineTJA' */
#define IN_CONTROLLING                 ((uint8)1U)
#define IN_DISABLED                    ((uint8)2U)
#define IN_ERROR                       ((uint8)1U)
#define IN_NOT_PRESENT                 ((uint8)2U)
#define IN_PASSIVE                     ((uint8)3U)
#define IN_PRESENT                     ((uint8)3U)
#define IN_RAMPOUT                     ((uint8)4U)
#define IN_REQUEST                     ((uint8)5U)
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
#define TJASTM_START_SEC_DATA_8
#include "TJASTM_MemMap.h"
static uint8 BI_tjastm_SysState_nu;
/* 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/StateMachineTJA' */
static uint8 BI_tjastm_LatCtrlMode_nu;
/* 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/LatCtrlMode' */
static uint8 DW_tjastm_is_active_c10_TJASTM_cg;
static uint8 DW_tjastm_is_c10_TJASTM_cg;
static uint8 DW_tjastm_is_PRESENT;
static uint8 DW_tjastm_is_active_c14_TJASTM_cg;
static uint8 DW_tjastm_is_c14_TJASTM_cg;
static uint8 DW_tjastm_is_Request;
static uint8 DW_tjastm_is_Controlling;
#define TJASTM_STOP_SEC_DATA_8
#include "TJASTM_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TJASTM/TJASTM/INI'/TJASTM_SenReset'
 * Block description for: 'sda:TJASTM/TJASTM/INI'/TJASTM_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TJASTM_SenReset
#include "Pse_TJASTM.h"
/* Short description: Not synchronized with ARAMIS */
void TJASTM_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TJASTM/TJASTM/INI/TJASTM_SenReset/Constant'/Constant' */
    SET_S_TJASTM_SysStateTJA_nu(0U);
    /* Constant: 'sda:TJASTM/TJASTM/INI/TJASTM_SenReset/Constant1'/Constant' */
    SET_S_TJASTM_LatCtrlMode_nu(0U);
    /* Constant: 'sda:TJASTM/TJASTM/INI/TJASTM_SenReset/Constant2'/Constant' */
    SET_D_TJASTM_TJAInvalid_btf(0U);
}
#include "Pse_TJASTM.h"
/*
 * Output and update for function-call system: 'sda:TJASTM/TJASTM'/TJASTM_SenProcess'
 * Block description for: 'sda:TJASTM/TJASTM'/TJASTM_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TJASTM_SenProcess
#include "Pse_TJASTM.h"
/* Short description: Not synchronized with ARAMIS */
void TJASTM_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    uint16 rtb_sfun_setbit;
    uint8 rtb_VectorConcatenate[16];
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_b;
    uint8 rtb_Unit_Delay;
    uint8 rtb_EQ_et;
    uint8 rtb_EQ_i;
    uint8 rtb_EQ_n;
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/OR/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJALKA_Cancel_bool'
         *  Inport: '<Root>/S_TJAOBS_CancelLC_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion = (uint8)((((sint32)GET_S_TJALKA_Cancel_bool()) != 0) || (((sint32)GET_S_TJAOBS_CancelLC_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAOBF_Cancel_bool'
         *  Inport: '<Root>/S_TJAOBS_CancelOF_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_b = (uint8)((((sint32)GET_S_TJAOBF_Cancel_bool()) != 0) || (((sint32)GET_S_TJAOBS_CancelOF_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/from_data_definition1'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/from_data_definition16'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/SLC_CancelConditions/from_data_definition18'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_TJACMB_Cancel_bool'
         *  Inport: '<Root>/S_TJACMB_StrongReady_bool'
         *  Inport: '<Root>/S_TJACMB_WeakReady_bool'
         *  Inport: '<Root>/S_TJAGEN_Cancel_nu'
         *  Inport: '<Root>/S_TJALKA_StrongReady_bool'
         *  Inport: '<Root>/S_TJALKA_WeakReady_bool'
         *  Inport: '<Root>/S_TJAOBF_StrongReady_bool'
         *  Inport: '<Root>/S_TJAOBF_WeakReady_bool'
         *  Inport: '<Root>/S_TJASLC_Cancel_bool'
         *  Inport: '<Root>/S_TJASLC_StrongReady_bool'
         *  Inport: '<Root>/S_TJASLC_WeakReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/AND/Functionality'/AND'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/NOT10/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/NOT11/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/NOT13/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/NOT14/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/NOT2/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/NOT3/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/OR1/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/OR5/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/OR7/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/OR8/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/AND1/Functionality'/AND'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/NOT15/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/NOT16/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/NOT2/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/NOT3/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/NOT6/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/OR4/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/OR6/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/OR8/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OR/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/SLC_CancelConditions/AND2/Functionality'/AND'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/SLC_CancelConditions/NOT15/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/SLC_CancelConditions/NOT16/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/SLC_CancelConditions/NOT5/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/SLC_CancelConditions/OR3/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/SLC_CancelConditions/OR6/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/AND/Functionality'/AND'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/AND/Functionality'/AND'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/NOT10/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/NOT11/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/NOT13/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/NOT14/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/NOT2/Functionality'/NOT'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/OR1/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/OR5/Functionality'/OR'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/OR7/Functionality'/OR'
         *  RelationalOperator: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/LC_CancelConditions/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/OF_CancelConditions/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/SLC_CancelConditions/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/CancelConditions/CMB_CancelConditions/EQ4/Functionality'/EQ'
         *  UnitDelay: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/Unit_Delay'
         */
    rtb_DataTypeConversion_b = (uint8)((((((((sint32)GET_S_TJAGEN_Cancel_nu()) != 0) || ((((((sint32)BI_tjastm_LatCtrlMode_nu) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF))) && ((!(((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0)) || (((sint32) rtb_DataTypeConversion_b) != 0))) && ((!(((sint32) GET_S_TJALKA_StrongReady_bool()) != 0)) || (!(((sint32) GET_S_TJALKA_WeakReady_bool()) != 0)))) && ((!(((sint32) GET_S_TJACMB_StrongReady_bool()) != 0)) || (!(((sint32) GET_S_TJACMB_WeakReady_bool()) != 0))))) || (((((sint32)BI_tjastm_LatCtrlMode_nu) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC))) && (( !(((sint32)GET_S_TJASLC_StrongReady_bool()) != 0)) || (((sint32) GET_S_TJASLC_Cancel_bool()) != 0))) && ((!(((sint32) GET_S_TJALKA_StrongReady_bool()) != 0)) || (!(((sint32) GET_S_TJALKA_WeakReady_bool()) != 0))))) || (((((((sint32)BI_tjastm_LatCtrlMode_nu) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC))) && ((!(((sint32)GET_S_TJALKA_StrongReady_bool()) != 0)) || (((sint32) rtb_DataTypeConversion) != 0))) && ((!(((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0)) || (!(((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)))) && ((!(((sint32) GET_S_TJASLC_StrongReady_bool()) != 0)) || (!(((sint32) GET_S_TJASLC_WeakReady_bool()) != 0)))) && ((!(((sint32) GET_S_TJACMB_StrongReady_bool()) != 0)) || (!(((sint32) GET_S_TJACMB_WeakReady_bool()) != 0))))) || (((((((sint32)BI_tjastm_LatCtrlMode_nu) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) && ((!(((sint32)GET_S_TJACMB_StrongReady_bool()) != 0)) || (((sint32) GET_S_TJACMB_Cancel_bool()) != 0))) && ((!(((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0)) || (!(((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)))) && ((!(((sint32) GET_S_TJASLC_StrongReady_bool()) != 0)) || (!(((sint32) GET_S_TJASLC_WeakReady_bool()) != 0)))) && (!(((sint32) GET_S_TJALKA_StrongReady_bool()) != 0)))) || (((((sint32) rtb_DataTypeConversion) != 0) && (((sint32)rtb_DataTypeConversion_b) != 0)) && (((sint32)GET_S_TJACMB_Cancel_bool()) != 0)));
    /* Chart: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/StateMachineTJA' incorporates:
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition10'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition11'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition3'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition6'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition7'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition8'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_TJACMB_StrongReady_bool'
         *  Inport: '<Root>/S_TJACMB_WeakReady_bool'
         *  Inport: '<Root>/S_TJAGEN_Clearance_bool'
         *  Inport: '<Root>/S_TJAGEN_CodeFunction_bool'
         *  Inport: '<Root>/S_TJAGEN_Degradation_bool'
         *  Inport: '<Root>/S_TJAGEN_Error_bool'
         *  Inport: '<Root>/S_TJAGEN_FunctionSwitch_bool'
         *  Inport: '<Root>/S_TJAGEN_StrongReady_bool'
         *  Inport: '<Root>/S_TJAGEN_WeakReady_bool'
         *  Inport: '<Root>/S_TJALKA_StrongReady_bool'
         *  Inport: '<Root>/S_TJALKA_WeakReady_bool'
         *  Inport: '<Root>/S_TJAOBF_StrongReady_bool'
         *  Inport: '<Root>/S_TJAOBF_WeakReady_bool'
         *  Inport: '<Root>/S_TJASLC_StrongReady_bool'
         *
         * Block description for 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/StateMachineTJA':
         *  X.2.1.1.2
         */
    /* Gateway: TJASTM_cg/TJASTM_SenProcess/M_TJASTM/StateMachineTJA */
    /* During: TJASTM_cg/TJASTM_SenProcess/M_TJASTM/StateMachineTJA */
    if (((uint32)((sint32)DW_tjastm_is_active_c10_TJASTM_cg)) == 0U) {
        /* Entry: TJASTM_cg/TJASTM_SenProcess/M_TJASTM/StateMachineTJA */
        DW_tjastm_is_active_c10_TJASTM_cg = 1U;
        /* Entry Internal: TJASTM_cg/TJASTM_SenProcess/M_TJASTM/StateMachineTJA */
        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':139' */
        DW_tjastm_is_c10_TJASTM_cg = IN_NOT_PRESENT;
        /* Entry 'NOT_PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':3' */
        BI_tjastm_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
    } else {
        switch (DW_tjastm_is_c10_TJASTM_cg) {
        case IN_ERROR:
            /* During 'ERROR': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':12' */
            if ((((sint32)GET_S_TJAGEN_CodeFunction_bool()) != 0) && (!(((sint32) GET_S_TJAGEN_Error_bool()) != 0))) {
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':83' */
                DW_tjastm_is_c10_TJASTM_cg = IN_PRESENT;
                /* Entry Internal 'PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':107' */
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':72' */
                if (((sint32)GET_S_TJAGEN_FunctionSwitch_bool()) != 0) {
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':70' */
                    DW_tjastm_is_PRESENT = IN_PASSIVE;
                    /* Entry 'PASSIVE': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':8' */
                    BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                } else {
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':71' */
                    DW_tjastm_is_PRESENT = IN_DISABLED;
                    /* Entry 'DISABLED': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':1' */
                    BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                }
            } else {
                if (!(((sint32)GET_S_TJAGEN_CodeFunction_bool()) != 0)) {
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':59' */
                    DW_tjastm_is_c10_TJASTM_cg = IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':3' */
                    BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                }
            }
            break;
        case IN_NOT_PRESENT:
            /* During 'NOT_PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':3' */
            if ((((sint32)GET_S_TJAGEN_CodeFunction_bool()) != 0) && (((sint32) GET_S_TJAGEN_Error_bool()) != 0)) {
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':82' */
                DW_tjastm_is_c10_TJASTM_cg = IN_ERROR;
                /* Entry 'ERROR': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':12' */
                BI_tjastm_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            } else {
                if (((sint32)GET_S_TJAGEN_CodeFunction_bool()) != 0) {
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':81' */
                    DW_tjastm_is_c10_TJASTM_cg = IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':107' */
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':72' */
                    if (((sint32)GET_S_TJAGEN_FunctionSwitch_bool()) != 0) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':70' */
                        DW_tjastm_is_PRESENT = IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':8' */
                        BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    } else {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':71' */
                        DW_tjastm_is_PRESENT = IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':1' */
                        BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    }
                }
            }
            break;
        default:
            /* During 'PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':107' */
            if (!(((sint32)GET_S_TJAGEN_CodeFunction_bool()) != 0)) {
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':58' */
                /* Exit Internal 'PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':107' */
                DW_tjastm_is_PRESENT = IN_NO_ACTIVE_CHILD;
                DW_tjastm_is_c10_TJASTM_cg = IN_NOT_PRESENT;
                /* Entry 'NOT_PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':3' */
                BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
            } else if ((((sint32)GET_S_TJAGEN_Error_bool()) != 0) && (((sint32) GET_S_TJAGEN_CodeFunction_bool()) != 0)) {
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':76' */
                /* Exit Internal 'PRESENT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':107' */
                DW_tjastm_is_PRESENT = IN_NO_ACTIVE_CHILD;
                DW_tjastm_is_c10_TJASTM_cg = IN_ERROR;
                /* Entry 'ERROR': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':12' */
                BI_tjastm_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            } else {
                switch (DW_tjastm_is_PRESENT) {
                case IN_CONTROLLING:
                    /* During 'CONTROLLING': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':10' */
                    if ((((((((!(((sint32)GET_S_TJALKA_StrongReady_bool()) != 0)) && (!(((sint32)GET_S_TJAOBF_StrongReady_bool()) != 0))) && (!(((sint32)GET_S_TJASLC_StrongReady_bool()) != 0))) && (!(((sint32)GET_S_TJACMB_StrongReady_bool()) != 0))) || (!(((sint32)GET_S_TJAGEN_StrongReady_bool()) != 0))) || (!(((sint32)GET_S_TJAGEN_Clearance_bool()) != 0))) || (!(((sint32)GET_S_TJAGEN_FunctionSwitch_bool()) != 0))) || (((sint32)rtb_DataTypeConversion_b) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':65' */
                        DW_tjastm_is_PRESENT = IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':64' */
                        BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    }
                    break;
                case IN_DISABLED:
                    /* During 'DISABLED': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':1' */
                    if (((sint32)GET_S_TJAGEN_FunctionSwitch_bool()) != 0) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':17' */
                        DW_tjastm_is_PRESENT = IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':8' */
                        BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                    break;
                case IN_PASSIVE:
                    /* During 'PASSIVE': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':8' */
                    if (!(((sint32)GET_S_TJAGEN_FunctionSwitch_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':18' */
                        DW_tjastm_is_PRESENT = IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':1' */
                        BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        if ((((((sint32)GET_S_TJAGEN_FunctionSwitch_bool()) != 0) && (((sint32)GET_S_TJAGEN_StrongReady_bool()) != 0)) && (((sint32) GET_S_TJAGEN_WeakReady_bool()) != 0)) && ((((((sint32) GET_S_TJALKA_StrongReady_bool()) != 0) && (((sint32) GET_S_TJALKA_WeakReady_bool()) != 0)) || ((((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0))) || ((((sint32) GET_S_TJACMB_StrongReady_bool()) != 0) && (((sint32) GET_S_TJACMB_WeakReady_bool()) != 0)))) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':80' */
                            DW_tjastm_is_PRESENT = IN_REQUEST;
                            /* Entry 'REQUEST': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':9' */
                            BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu);
                        }
                    }
                    break;
                case IN_RAMPOUT:
                    /* During 'RAMPOUT': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':64' */
                    if (((sint32)GET_S_TJAGEN_Degradation_bool()) != 0) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':78' */
                        if (((sint32)GET_S_TJAGEN_FunctionSwitch_bool()) != 0) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':70' */
                            DW_tjastm_is_PRESENT = IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':8' */
                            BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        } else {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':71' */
                            DW_tjastm_is_PRESENT = IN_DISABLED;
                            /* Entry 'DISABLED': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':1' */
                            BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                        }
                    }
                    break;
                default:
                    /* During 'REQUEST': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':9' */
                    if ((((((sint32)GET_S_TJAGEN_Clearance_bool()) != 0) && (((sint32) GET_S_TJAGEN_StrongReady_bool()) != 0)) && (((sint32) GET_S_TJAGEN_WeakReady_bool()) != 0)) && ((((((sint32) GET_S_TJALKA_StrongReady_bool()) != 0) && (((sint32) GET_S_TJALKA_WeakReady_bool()) != 0)) || ((((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0))) || ((((sint32) GET_S_TJACMB_StrongReady_bool()) != 0) && (((sint32) GET_S_TJACMB_WeakReady_bool()) != 0)))) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':20' */
                        DW_tjastm_is_PRESENT = IN_CONTROLLING;
                        /* Entry 'CONTROLLING': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':10' */
                        BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu);
                    } else {
                        if (((!(((sint32)GET_S_TJAGEN_FunctionSwitch_bool()) != 0)) || ((!(((sint32)GET_S_TJAGEN_StrongReady_bool()) != 0)) || (!(((sint32)GET_S_TJAGEN_WeakReady_bool()) != 0)))) || ((((!(((sint32)GET_S_TJALKA_StrongReady_bool()) != 0)) || (!(((sint32)GET_S_TJALKA_WeakReady_bool()) != 0))) && ((!(((sint32)GET_S_TJAOBF_StrongReady_bool()) != 0)) || (!(((sint32)GET_S_TJAOBF_WeakReady_bool()) != 0)))) && ((!(((sint32)GET_S_TJACMB_StrongReady_bool()) != 0)) || (!(((sint32)GET_S_TJACMB_WeakReady_bool()) != 0))))) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':22' */
                            DW_tjastm_is_PRESENT = IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/StateMachineTJA':8' */
                            BI_tjastm_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/StateMachineTJA' */
    /* RelationalOperator: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition14'/state_source'
         */
    rtb_Unit_Delay = (uint8)(((sint32)BI_tjastm_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* RelationalOperator: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition5'/state_source'
         */
    rtb_EQ_et = (uint8)(((sint32)BI_tjastm_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)));
    /* RelationalOperator: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition15'/state_source'
         */
    rtb_EQ_i = (uint8)(((sint32)BI_tjastm_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu)));
    /* RelationalOperator: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition19'/state_source'
         */
    rtb_EQ_n = (uint8)(((sint32)BI_tjastm_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu)));
    /* Chart: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/LatCtrlMode' incorporates:
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition12'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition13'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition16'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition17'/state_source'
         *  Constant: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/from_data_definition18'/state_source'
         *  Inport: '<Root>/S_TJACMB_Cancel_bool'
         *  Inport: '<Root>/S_TJACMB_StrongReady_bool'
         *  Inport: '<Root>/S_TJACMB_WeakReady_bool'
         *  Inport: '<Root>/S_TJAGEN_Degradation_bool'
         *  Inport: '<Root>/S_TJALKA_StrongReady_bool'
         *  Inport: '<Root>/S_TJALKA_WeakReady_bool'
         *  Inport: '<Root>/S_TJAOBF_StrongReady_bool'
         *  Inport: '<Root>/S_TJAOBF_WeakReady_bool'
         *  Inport: '<Root>/S_TJASLC_Cancel_bool'
         *  Inport: '<Root>/S_TJASLC_StrongReady_bool'
         *  Inport: '<Root>/S_TJASLC_WeakReady_bool'
         *
         * Block description for 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/LatCtrlMode':
         *  X.2.1.1.1
         */
    /* Gateway: TJASTM_cg/TJASTM_SenProcess/M_TJASTM/LatCtrlMode */
    /* During: TJASTM_cg/TJASTM_SenProcess/M_TJASTM/LatCtrlMode */
    if (((uint32)((sint32)DW_tjastm_is_active_c14_TJASTM_cg)) == 0U) {
        /* Entry: TJASTM_cg/TJASTM_SenProcess/M_TJASTM/LatCtrlMode */
        DW_tjastm_is_active_c14_TJASTM_cg = 1U;
        /* Entry Internal: TJASTM_cg/TJASTM_SenProcess/M_TJASTM/LatCtrlMode */
        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':530' */
        DW_tjastm_is_c14_TJASTM_cg = IN_Passive;
        /* Entry 'Passive': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':1' */
        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_PASSIVE);
    } else {
        switch (DW_tjastm_is_c14_TJASTM_cg) {
        case IN_Controlling:
            /* During 'Controlling': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':507' */
            if ((((!(((sint32)rtb_Unit_Delay) != 0)) && (((sint32) GET_S_TJAGEN_Degradation_bool()) != 0)) || (((sint32)rtb_EQ_i) != 0)) || (((sint32)rtb_EQ_n) != 0)) {
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':192' */
                /* Exit Internal 'Controlling': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':507' */
                DW_tjastm_is_Controlling = IN_NO_ACTIVE_CHILD;
                DW_tjastm_is_c14_TJASTM_cg = IN_Passive;
                /* Entry 'Passive': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':1' */
                BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_PASSIVE);
            } else {
                switch (DW_tjastm_is_Controlling) {
                case IN_Combined:
                    /* During 'Combined': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':528' */
                    if ((((sint32)GET_S_TJALKA_StrongReady_bool()) != 0) && ((!(((sint32) GET_S_TJACMB_StrongReady_bool()) != 0)) || (((sint32) GET_S_TJACMB_Cancel_bool()) != 0))) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':517' */
                        DW_tjastm_is_Controlling = IN_LaneCentering;
                        /* Entry 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':527' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC);
                    } else if ((((!(((sint32)GET_S_TJACMB_StrongReady_bool()) != 0)) || (((sint32)GET_S_TJACMB_Cancel_bool()) != 0)) && (((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0)) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':525' */
                        DW_tjastm_is_Controlling = IN_ObjectFollowing_g;
                        /* Entry 'ObjectFollowing': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':529' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF);
                    } else {
                        if ((((sint32)GET_S_TJASLC_StrongReady_bool()) != 0) && (((sint32) GET_S_TJASLC_WeakReady_bool()) != 0)) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':538' */
                            DW_tjastm_is_Controlling = IN_LaneChange;
                            /* Entry 'LaneChange': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':526' */
                            BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC);
                        }
                    }
                    break;
                case IN_LaneCentering:
                    /* During 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':527' */
                    if ((((sint32)GET_S_TJACMB_StrongReady_bool()) != 0) && (((sint32) GET_S_TJACMB_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':516' */
                        DW_tjastm_is_Controlling = IN_Combined;
                        /* Entry 'Combined': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':528' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB);
                    } else if ((((!(((sint32)GET_S_TJALKA_StrongReady_bool()) != 0)) || (((sint32)rtb_DataTypeConversion) != 0)) && (((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0)) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':518' */
                        DW_tjastm_is_Controlling = IN_ObjectFollowing_g;
                        /* Entry 'ObjectFollowing': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':529' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF);
                    } else {
                        if ((((sint32)GET_S_TJASLC_StrongReady_bool()) != 0) && (((sint32) GET_S_TJASLC_WeakReady_bool()) != 0)) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':514' */
                            DW_tjastm_is_Controlling = IN_LaneChange;
                            /* Entry 'LaneChange': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':526' */
                            BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC);
                        }
                    }
                    break;
                case IN_LaneChange:
                    /* During 'LaneChange': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':526' */
                    if ((((!(((sint32)GET_S_TJASLC_StrongReady_bool()) != 0)) || (((sint32) GET_S_TJASLC_Cancel_bool()) != 0)) && (((sint32) GET_S_TJALKA_StrongReady_bool()) != 0)) && (((sint32) GET_S_TJALKA_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':515' */
                        DW_tjastm_is_Controlling = IN_LaneCentering;
                        /* Entry 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':527' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC);
                    }
                    break;
                default:
                    /* During 'ObjectFollowing': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':529' */
                    if ((((sint32)GET_S_TJACMB_StrongReady_bool()) != 0) && (((sint32) GET_S_TJACMB_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':524' */
                        DW_tjastm_is_Controlling = IN_Combined;
                        /* Entry 'Combined': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':528' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB);
                    } else {
                        if ((((sint32)GET_S_TJALKA_StrongReady_bool()) != 0) && (((sint32) GET_S_TJALKA_WeakReady_bool()) != 0)) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':519' */
                            DW_tjastm_is_Controlling = IN_LaneCentering;
                            /* Entry 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':527' */
                            BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC);
                        }
                    }
                    break;
                }
            }
            break;
        case IN_Passive:
            /* During 'Passive': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':1' */
            if (((sint32)rtb_EQ_et) != 0) {
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':472' */
                DW_tjastm_is_c14_TJASTM_cg = IN_Request;
                /* Entry Internal 'Request': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':561' */
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':563' */
                if ((((sint32)GET_S_TJACMB_StrongReady_bool()) != 0) && (((sint32) GET_S_TJACMB_WeakReady_bool()) != 0)) {
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':564' */
                    DW_tjastm_is_Request = IN_Combined;
                    /* Entry 'Combined': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':578' */
                    BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB);
                } else if ((((sint32)GET_S_TJALKA_StrongReady_bool()) != 0) && (((sint32) GET_S_TJALKA_WeakReady_bool()) != 0)) {
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':566' */
                    DW_tjastm_is_Request = IN_LaneCentering;
                    /* Entry 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':577' */
                    BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC);
                } else {
                    if ((((sint32)GET_S_TJAOBF_StrongReady_bool()) != 0) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':565' */
                        DW_tjastm_is_Request = IN_ObjectFollowing;
                        /* Entry 'ObjectFollowing': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':579' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF);
                    }
                }
            }
            break;
        default:
            /* During 'Request': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':561' */
            if (((sint32)rtb_Unit_Delay) != 0) {
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':169' */
                /* Exit Internal 'Request': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':561' */
                DW_tjastm_is_Request = IN_NO_ACTIVE_CHILD;
                DW_tjastm_is_c14_TJASTM_cg = IN_Controlling;
                /* Entry Internal 'Controlling': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':507' */
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':509' */
                if ((((sint32)GET_S_TJACMB_StrongReady_bool()) != 0) && (((sint32) GET_S_TJACMB_WeakReady_bool()) != 0)) {
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':510' */
                    DW_tjastm_is_Controlling = IN_Combined;
                    /* Entry 'Combined': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':528' */
                    BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB);
                } else if ((((sint32)GET_S_TJALKA_StrongReady_bool()) != 0) && (((sint32) GET_S_TJALKA_WeakReady_bool()) != 0)) {
                    /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':512' */
                    DW_tjastm_is_Controlling = IN_LaneCentering;
                    /* Entry 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':527' */
                    BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC);
                } else {
                    if ((((sint32)GET_S_TJAOBF_StrongReady_bool()) != 0) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':511' */
                        DW_tjastm_is_Controlling = IN_ObjectFollowing_g;
                        /* Entry 'ObjectFollowing': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':529' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF);
                    }
                }
            } else if (((!(((sint32)rtb_EQ_et) != 0)) || (((sint32)rtb_EQ_i) != 0)) || (((sint32)rtb_EQ_n) != 0)) {
                /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':473' */
                /* Exit Internal 'Request': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':561' */
                DW_tjastm_is_Request = IN_NO_ACTIVE_CHILD;
                DW_tjastm_is_c14_TJASTM_cg = IN_Passive;
                /* Entry 'Passive': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':1' */
                BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_PASSIVE);
            } else {
                switch (DW_tjastm_is_Request) {
                case IN_Combined:
                    /* During 'Combined': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':578' */
                    if ((((sint32)GET_S_TJALKA_StrongReady_bool()) != 0) && ((!(((sint32) GET_S_TJACMB_StrongReady_bool()) != 0)) || (((sint32) GET_S_TJACMB_Cancel_bool()) != 0))) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':572' */
                        DW_tjastm_is_Request = IN_LaneCentering;
                        /* Entry 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':577' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC);
                    } else {
                        if ((((!(((sint32)GET_S_TJACMB_StrongReady_bool()) != 0)) || (((sint32)GET_S_TJACMB_Cancel_bool()) != 0)) && (((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0)) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':575' */
                            DW_tjastm_is_Request = IN_ObjectFollowing;
                            /* Entry 'ObjectFollowing': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':579' */
                            BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF);
                        }
                    }
                    break;
                case IN_LaneCentering:
                    /* During 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':577' */
                    if ((((sint32)GET_S_TJACMB_StrongReady_bool()) != 0) && (((sint32) GET_S_TJACMB_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':569' */
                        DW_tjastm_is_Request = IN_Combined;
                        /* Entry 'Combined': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':578' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB);
                    } else {
                        if ((((!(((sint32)GET_S_TJALKA_StrongReady_bool()) != 0)) || (((sint32)rtb_DataTypeConversion) != 0)) && (((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0)) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':570' */
                            DW_tjastm_is_Request = IN_ObjectFollowing;
                            /* Entry 'ObjectFollowing': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':579' */
                            BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF);
                        }
                    }
                    break;
                default:
                    /* During 'ObjectFollowing': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':579' */
                    if ((((sint32)GET_S_TJACMB_StrongReady_bool()) != 0) && (((sint32) GET_S_TJACMB_WeakReady_bool()) != 0)) {
                        /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':574' */
                        DW_tjastm_is_Request = IN_Combined;
                        /* Entry 'Combined': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':578' */
                        BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB);
                    } else {
                        if ((((sint32)GET_S_TJALKA_StrongReady_bool()) != 0) && (((sint32) GET_S_TJALKA_WeakReady_bool()) != 0)) {
                            /* Transition: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':571' */
                            DW_tjastm_is_Request = IN_LaneCentering;
                            /* Entry 'LaneCentering': 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/LatCtrlMode':577' */
                            BI_tjastm_LatCtrlMode_nu = ((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC);
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM'/LatCtrlMode' */
    /* SignalConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/MappingUint16'/ConcatBufferAtVector ConcatenateIn11' */
    rtb_VectorConcatenate[10] = rtb_DataTypeConversion_b;
    /* SignalConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/MappingUint16'/ConcatBufferAtVector ConcatenateIn13' incorporates:
         *  Inport: '<Root>/S_TJAGEN_Degradation_bool'
         */
    rtb_VectorConcatenate[12] = GET_S_TJAGEN_Degradation_bool();
    /* SignalConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/MappingUint16'/ConcatBufferAtVector ConcatenateIn16' incorporates:
         *  Inport: '<Root>/S_TJAGEN_Error_bool'
         */
    rtb_VectorConcatenate[15] = GET_S_TJAGEN_Error_bool();
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAGEN_StrongReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate[0] = (uint8)(!(((sint32)GET_S_TJAGEN_StrongReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAGEN_WeakReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate[1] = (uint8)(!(((sint32)GET_S_TJAGEN_WeakReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJALKA_StrongReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate[2] = (uint8)(!(((sint32)GET_S_TJALKA_StrongReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJALKA_WeakReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate[3] = (uint8)(!(((sint32)GET_S_TJALKA_WeakReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAOBF_StrongReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate[4] = (uint8)(!(((sint32)GET_S_TJAOBF_StrongReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAOBF_WeakReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate[5] = (uint8)(!(((sint32)GET_S_TJAOBF_WeakReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJASLC_StrongReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate[6] = (uint8)(!(((sint32)GET_S_TJASLC_StrongReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJASLC_WeakReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate[7] = (uint8)(!(((sint32)GET_S_TJASLC_WeakReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT10/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJACMB_StrongReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT10/Functionality'/NOT'
         */
    rtb_VectorConcatenate[8] = (uint8)(!(((sint32)GET_S_TJACMB_StrongReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT11/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJACMB_WeakReady_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT11/Functionality'/NOT'
         */
    rtb_VectorConcatenate[9] = (uint8)(!(((sint32)GET_S_TJACMB_WeakReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT9/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAGEN_FunctionSwitch_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT9/Functionality'/NOT'
         */
    rtb_VectorConcatenate[11] = (uint8)(!(((sint32) GET_S_TJAGEN_FunctionSwitch_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT8/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAGEN_Clearance_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT8/Functionality'/NOT'
         */
    rtb_VectorConcatenate[13] = (uint8)(!(((sint32)GET_S_TJAGEN_Clearance_bool()) != 0));
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT12/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAGEN_CodeFunction_bool'
         *  Logic: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/NOT12/Functionality'/NOT'
         */
    rtb_VectorConcatenate[14] = (uint8)(!(((sint32) GET_S_TJAGEN_CodeFunction_bool()) != 0));
    /* S-Function (sfun_setbit): 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
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
    /* DataTypeConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/MappingUint16/set_bit1/Functionality'/DTC_out' */
    SET_D_TJASTM_TJAInvalid_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/branch'/copy1' */
    SET_S_TJASTM_SysStateTJA_nu(BI_tjastm_SysState_nu);
    /* SignalConversion: 'sda:TJASTM/TJASTM/TJASTM_SenProcess/M_TJASTM/branch4'/copy1' */
    SET_S_TJASTM_LatCtrlMode_nu(BI_tjastm_LatCtrlMode_nu);
}
#include "Pse_TJASTM.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
