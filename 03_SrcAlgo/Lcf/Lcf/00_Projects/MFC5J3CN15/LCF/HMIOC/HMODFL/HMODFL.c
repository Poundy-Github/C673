/**************************************************************************
COPYRIGHT (C) $Date: 2021/01/25 09:33:24CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Project_Specific/MFC431VA21/LCF/Model/HMIOC/HMODFL_SEN/HMODFL/i/project.pj $
$Log: HMODFL.c  $
Revision 1.3 2021/01/25 09:33:24CET uib56746 
Update warning alert according to asima mapping
File          : HMODFL
Generated on  : Tue 19.01.2021 at 13:56:22 (UTC+01:00)
MD5           : [1535119288  1691103307  3943362748  2657509560 0](HMODFL)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0 (R2016b)
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "HMODFL.h"
#include "HMODFL_private.h"
/* Specific Includes */

//MFC5J3CN15
#ifndef S_DPLSMI_SysStateLDP_nu
#define S_DPLSMI_SysStateLDP_nu (DPLSMI_SenGetOutPtr().S_DPLSMI_SysStateLDP_nu) //!< DPLSMI output macro.
#define GET_S_DPLSMI_SysStateLDP_nu() (S_DPLSMI_SysStateLDP_nu) //!< DPLSMI output macro getter.
#endif // S_DPLSMI_SysStateLDP_nu

/* Code Analysis Options */
// PRQA S 0380,0857 ++ // 2020-02-18; uidj2187; summary: too many macro definitions; reason: all output signals and parameters are macros and are generated
// PRQA S 0404 ++ // 2020-02-13; uidj2187; summary: more than one read access to volatile object between�sequence points; reason: no side effects since volatile parameters are independent of each other
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
#define HMODFL_START_SEC_DATA_8
#include "HMODFL_MemMap.h"
static uint8 DW_hmodfl_Unit_Delay_DSTATE;
static uint8 DW_hmodfl_Unit_Delay4_DSTATE;
static uint8 DW_hmodfl_Unit_Delay3_DSTATE;
static uint8 DW_hmodfl_Unit_Delay1_DSTATE;
static uint8 DW_hmodfl_Unit_Delay2_DSTATE;
#define HMODFL_STOP_SEC_DATA_8
#include "HMODFL_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:HMODFL/HMODFL'/HMODFL_SenReset'
 * Block description for: 'sda:HMODFL/HMODFL'/HMODFL_SenReset'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_HMODFL_SenReset
#include "Pse_HMODFL.h"
/* Short description:  */
void HMODFL_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:HMODFL/HMODFL/HMODFL_SenReset/Constant'/Constant' */
    SET_S_HMODFL_AvailableFunction_btf(0U);
    /* Constant: 'sda:HMODFL/HMODFL/HMODFL_SenReset/Constant1'/Constant' */
    SET_S_HMODFL_LKAInforStatus_nu(0U);
    /* Constant: 'sda:HMODFL/HMODFL/HMODFL_SenReset/Constant2'/Constant' */
    SET_S_HMODFL_LKAStatusChange_nu(0U);
}
#include "Pse_HMODFL.h"
/*
 * Output and update for function-call system: 'sda:HMODFL/HMODFL'/HMODFL_SenProcess'
 * Block description for: 'sda:HMODFL/HMODFL'/HMODFL_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_HMODFL_SenProcess
#include "Pse_HMODFL.h"
/* Short description:  */
void HMODFL_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_Switch_l;
    uint8 rtb_Switch2;
    /* DataTypeConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/Constant2'/Constant'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/EQ4/Functionality'/EQ'
         */
    rtb_sfun_setbit = (uint8)((((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu)) == ((sint32) GET_S_DPLSMI_SysStateLDP_nu())) && (((sint32) GET_P_HMODFL_UsePassiveAvlbFct_bool()) != 0));
    /* DataTypeConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/Constant1'/Constant'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/from_data_definition'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/from_data_definition1'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/from_data_definition2'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/AND/Functionality'/AND'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/EQ3/Functionality'/EQ'
         */
    rtb_VectorConcatenate[0] = (uint8)(((((((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu))) && (((sint32)GET_P_HMODFL_UsePassiveAvlbFct_bool()) != 0)) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* DataTypeConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/from_data_definition5'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/from_data_definition6'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/EQ7/Functionality'/EQ'
         */
    rtb_VectorConcatenate[1] = (uint8)((((((sint32)rtb_sfun_setbit) != 0) || (((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((sint32) GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32) GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value1'/Signal Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value1'/Constant'
         */
    rtb_VectorConcatenate[2] = 0U;
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value2'/Signal Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value2'/Constant'
         */
    rtb_VectorConcatenate[3] = 0U;
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value3'/Signal Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value3'/Constant'
         */
    rtb_VectorConcatenate[4] = 0U;
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value4'/Signal Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value4'/Constant'
         */
    rtb_VectorConcatenate[5] = 0U;
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value5'/Signal Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value5'/Constant'
         */
    rtb_VectorConcatenate[6] = 0U;
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value6'/Signal Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/logical_value6'/Constant'
         */
    rtb_VectorConcatenate[7] = 0U;
    /* S-Function (sfun_setbit): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/AvaliableFunction/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit = temp;
    }
    /* Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant'/Constant'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/from_data_definition'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/from_data_definition1'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/from_data_definition2'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/from_data_definition3'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/from_data_definition4'/state_source'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/OR/Functionality'/OR'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/OR1/Functionality'/OR'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EQ5/Functionality'/EQ'
         *  Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch1/Functionality'/Switch'
         *  Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch2/Functionality'/Switch'
         */
    if ((((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu))) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu)))) {
        rtb_Switch_l = 0U;
    } else if ((((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu))) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) {
        /* Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant1'/Constant'
                 */
        rtb_Switch_l = 1U;
    } else if ((((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)))) {
        /* Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant2'/Constant'
                 *  Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch1/Functionality'/Switch'
                 */
        rtb_Switch_l = 2U;
    } else {
        /* Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant3'/Constant'
                 *  Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch2/Functionality'/Switch'
                 */
        rtb_Switch_l = 4U;
    }
    /* End of Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant10'/Constant'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant4'/Constant'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant7'/Constant'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant8'/Constant'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant9'/Constant'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/AND1/Functionality'/AND'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/AND2/Functionality'/AND'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/AND3/Functionality'/AND'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/NOT/Functionality'/NOT'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/OR2/Functionality'/OR'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EQ7/Functionality'/EQ'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/NEQ2/Functionality'/NE'
         *  UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay'
         *  UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay3'
         *  UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay4'
         */
    rtb_DataTypeConversion = (uint8)((((((sint32)rtb_Switch_l) != 4) && (((sint32)rtb_Switch_l) > ((sint32)DW_hmodfl_Unit_Delay_DSTATE))) && (!((((sint32)DW_hmodfl_Unit_Delay4_DSTATE) == 0) && (((sint32)rtb_Switch_l) == 1)))) || (((((sint32)rtb_Switch_l) != 4) && (((sint32)rtb_Switch_l) != 0)) && (((sint32)rtb_Switch_l) < ((sint32)DW_hmodfl_Unit_Delay3_DSTATE))));
    /* S-Function (fcncallgen): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Constant1'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant5'/Constant'
         *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant6'/Constant'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay1'
         *  UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay2'
         */
    if (((!(((sint32)DW_hmodfl_Unit_Delay1_DSTATE) != 0)) && (((sint32) rtb_DataTypeConversion) != 0)) && (((sint32)DW_hmodfl_Unit_Delay2_DSTATE) <= 0)) {
        rtb_Switch2 = GET_P_HMODFL_WarningCycle_nu();
    } else if (((sint32)DW_hmodfl_Unit_Delay2_DSTATE) > 1) {
        /* Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/Constant5'/Constant'
                 *  Sum: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality/Sum/Functionality'/Sum'
                 */
        rtb_Switch2 = (uint8)(((sint32)DW_hmodfl_Unit_Delay2_DSTATE) - 1);
    } else {
        /* Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2 = 0U;
    }
    /* End of Switch: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING'/fcg' */
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/branch'/copy1' */
    SET_S_HMODFL_AvailableFunction_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/branch1'/copy1' incorporates:
                                                           *  Constant: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Constant'
                                                           *  RelationalOperator: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/TIMER_RE/Functionality'/Relational Operator1'
                                                           */
    SET_S_HMODFL_LKAStatusChange_nu((uint8)(((sint32)rtb_Switch2) > 0));
    /* SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/branch2'/copy1' */
    SET_S_HMODFL_LKAInforStatus_nu(rtb_Switch_l);
    /* Update for UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay' */
    DW_hmodfl_Unit_Delay_DSTATE = rtb_Switch_l;
    /* Update for UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay4' */
    DW_hmodfl_Unit_Delay4_DSTATE = rtb_Switch_l;
    /* Update for UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay3' */
    DW_hmodfl_Unit_Delay3_DSTATE = rtb_Switch_l;
    /* S-Function (fcncallgen): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_hmodfl_Unit_Delay1_DSTATE = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:HMODFL/HMODFL/HMODFL_SenProcess/OPM/Subsystem'/Unit_Delay2' */
    DW_hmodfl_Unit_Delay2_DSTATE = rtb_Switch2;
}
#include "Pse_HMODFL.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
