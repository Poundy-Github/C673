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
 * File          : VDPDRV
 * Generated on  : Fri 13.09.2019 at 09:00:29 (UTC+01:00)
 * MD5           : [1284137253   819960391  1112818795  3462040762 0](VDPDRV)
 *
 * Purpose       : <Purpose>
 * Specification : <Specification>
 *
 * Environment information:
 * Processor     : 32 Bit generic
 * Platform      : EMS3
 * ASIL class    : QM
 * Matlab version: 9.1.0.441655 (R2016b)
 * SDA version   : 10.0
 * Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,86,87,88,89,90
 * Add-ons       : -
 *
 * Version management information:
 * Filename      : $Workfile: $
 * Revision      : $Revision: 1.6 $
 * Author        : $Author: Werum, Gregor (uidq2175) $
 * Date          : $Date: 2019/09/13 09:15:14CEST $
 * Changes       :
 * $Log: VDPDRV.c  $
 * Revision 1.6 2019/09/13 09:15:14CEST Werum, Gregor (uidq2175) 
 * Re-insert brightness detection implementation from Rev 1.22
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "VDPDRV.h"
#include "VDPDRV_private.h"
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
#define VDPDRV_START_SEC_DATA_8
#include "VDPDRV_MemMap.h"
static uint8 DW_vdpdrv_Unit_Delay2_DSTATE_m[8];
static uint8 DW_vdpdrv_Unit_Delay1_DSTATE_f[8];
static uint8 DW_vdpdrv_Unit_Delay_DSTATE_ce;
static uint8 DW_vdpdrv_Unit_Delay_DSTATE_g;
#define VDPDRV_STOP_SEC_DATA_8
#include "VDPDRV_MemMap.h"
#define VDPDRV_START_SEC_DATA_32
#include "VDPDRV_MemMap.h"
static float32 DW_vdpdrv_Unit_Delay_DSTATE;
static float32 DW_vdpdrv_Unit_Delay1_DSTATE;
static float32 DW_vdpdrv_Unit_Delay_DSTATE_k[2];
static float32 DW_vdpdrv_Unit_Delay_DSTATE_o;
static float32 DW_vdpdrv_Unit_Delay_DSTATE_c[7];
static float32 DW_vdpdrv_Unit_Delay_DSTATE_f[8];
static float32 DW_vdpdrv_Unit_Delay7_DSTATE[8];
static float32 DW_vdpdrv_Unit_Delay3_DSTATE[8];
static float32 DW_vdpdrv_Unit_Delay3_DSTATE_o;
static float32 DW_vdpdrv_Unit_Delay_DSTATE_l;
static float32 DW_vdpdrv_Unit_Delay2_DSTATE;
static float32 DW_vdpdrv_Unit_Delay_DSTATE_e;
static float32 DW_vdpdrv_Unit_Delay2_DSTATE_g;
#define VDPDRV_STOP_SEC_DATA_32
#include "VDPDRV_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:VDPDRV/VDPDRV/INI'/VDPDRV_SenReset'
 * Block description for: 'sda:VDPDRV/VDPDRV/INI'/VDPDRV_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_VDPDRV_SenReset
#include "Pse_VDPDRV.h"
/* Short description: Not synchronized with ARAMIS */
void VDPDRV_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:VDPDRV/VDPDRV/INI/VDPDRV_SenReset/Constant1'/Constant' */
    SET_S_VDPDRV_ActiveStCtrl_btf(0U);
    /* Constant: 'sda:VDPDRV/VDPDRV/INI/VDPDRV_SenReset/Constant2'/Constant' */
    SET_S_VDPDRV_SysStNotAvailable_btf(0U);
    /* Constant: 'sda:VDPDRV/VDPDRV/INI/VDPDRV_SenReset/Constant3'/Constant' */
    SET_S_VDPDRV_SysStError_btf(0U);
    /* Constant: 'sda:VDPDRV/VDPDRV/INI/VDPDRV_SenReset/Constant4'/Constant' */
    SET_S_VDPDRV_DrvStInvalid_btf(0U);
    /* Constant: 'sda:VDPDRV/VDPDRV/INI/VDPDRV_SenReset/Constant6'/Constant' */
    SET_S_VDPDRV_VehStInvalid_btf(0U);
}
#include "Pse_VDPDRV.h"
/*
 * Output and update for function-call system: 'sda:VDPDRV/VDPDRV'/VDPDRV_SenProcess'
 * Block description for: 'sda:VDPDRV/VDPDRV'/VDPDRV_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_VDPDRV_SenProcess
#include "Pse_VDPDRV.h"
/* Short description: Not synchronized with ARAMIS */
void VDPDRV_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    uint16 rtb_sfun_setbit;
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate_a[8];
    uint8 rtb_VectorConcatenate_k[8];
    uint8 rtb_VectorConcatenate_m[16];
    uint8 rtb_DataTypeConversion_lu;
    uint8 rtb_LogicalOperator_a[8];
    sint8 rtb_LogicalOperator[8];
    float32 rtb_Switch[8];
    uint8 rtb_Switch_c[8];
    float32 rtb_Abs;
    uint8 rtb_LogicalOperator_e;
    uint8 rtb_LogicalOperator_j5;
    sint32 i;
    sint8 tmp[2];
    sint8 tmp_0[7];
    sint8 tmp_1[8];
    uint8 rtb_LogicalOperator_o_idx_0;
    uint8 rtb_LogicalOperator_o_idx_1;
    /* RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccelPedalPos_nu'
         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck'/Unit_Delay'
         */
    rtb_DataTypeConversion_lu = (uint8)((GET_S_LCFRCV_AccelPedalPos_nu() - DW_vdpdrv_Unit_Delay_DSTATE) > GET_P_VDPDRV_MaxAccelPedalRate_nu());
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck'/Unit_Delay1'
         */
    rtb_VectorConcatenate[0] = (uint8)((((sint32)rtb_DataTypeConversion_lu) != 0) || (DW_vdpdrv_Unit_Delay1_DSTATE > 0.0F));
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_lu) != 0) {
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck'/Unit_Delay1' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/Constant3'/Constant'
                 */
        DW_vdpdrv_Unit_Delay1_DSTATE = GET_P_VDPDRV_DebTimeAccPedRate_sec();
    } else {
        if (DW_vdpdrv_Unit_Delay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck'/Unit_Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Switch2'
                         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck'/Unit_Delay1'
                         */
            DW_vdpdrv_Unit_Delay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/branch'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_DriverNotBuckledUp_bool'
         */
    rtb_VectorConcatenate[1] = GET_S_LCFRCV_DriverNotBuckledUp_bool();
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/OR/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_TurnSignalLeft_bool'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalRight_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_lu = (uint8)((((sint32) GET_S_LCFRCV_TurnSignalLeft_bool()) != 0) || (((sint32) GET_S_LCFRCV_TurnSignalRight_bool()) != 0));
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalHazard_bool'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive'/Unit_Delay'
         */
    rtb_LogicalOperator_o_idx_0 = (uint8)((((sint32) GET_S_LCFRCV_TurnSignalHazard_bool()) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_k [0] > 0.0F));
    rtb_LogicalOperator_o_idx_1 = (uint8)((((sint32)rtb_DataTypeConversion_lu) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_k[1] > 0.0F));
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_TurnSignalHazard_bool'
         */
    tmp[0] = (sint8)GET_S_LCFRCV_TurnSignalHazard_bool();
    tmp[1] = (sint8)rtb_DataTypeConversion_lu;
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Relational Operator'
                 *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Switch2'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive'/Unit_Delay'
                 */
        if (((sint32)tmp[i]) != 0) {
            /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive'/Unit_Delay' incorporates:
                         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/Constant'/Constant'
                         */
            DW_vdpdrv_Unit_Delay_DSTATE_k[i] = GET_P_VDPDRV_DebTimeTurnSignal_sec();
        } else {
            if (DW_vdpdrv_Unit_Delay_DSTATE_k[i] > 0.0F) {
                /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive'/Unit_Delay'
                                 *  Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/TurnSignalActive'/Unit_Delay'
                                 */
                DW_vdpdrv_Unit_Delay_DSTATE_k[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
        }
    }
    /* RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/DrvInattentiveness/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/DrvInattentiveness/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DRMDAE_SysWarning_nu'
         */
    rtb_VectorConcatenate[4] = (uint8)(((sint32)GET_S_DRMDAE_SysWarning_nu()) == ((sint32)((uint8)E_DRMDAE_SysWarnType_E_DRMDAE_DEGRTRIG)));
    /* RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/Relational Operator/Functionality'/GE' incorporates:
         *  Abs: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/Abs/Functionality'/Abs'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         */
    rtb_DataTypeConversion_lu = (uint8)(f32_abs_f32 (GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm()) >= GET_P_VDPDRV_ManTrqOvrrdMaxTrq_Nm());
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride'/Unit_Delay'
         */
    rtb_VectorConcatenate[5] = (uint8)((DW_vdpdrv_Unit_Delay_DSTATE_o <= 0.0F) && (((sint32)rtb_DataTypeConversion_lu) != 0));
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_lu) != 0) {
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride'/Unit_Delay'
                 */
        if (DW_vdpdrv_Unit_Delay_DSTATE_o > 0.0F) {
            /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride'/Unit_Delay' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_vdpdrv_Unit_Delay_DSTATE_o -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride'/Unit_Delay' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/Application Parameter4'/Constant'
                 */
        DW_vdpdrv_Unit_Delay_DSTATE_o = GET_P_VDPDRV_ManTrqOvrrdTrnOnTm_sec();
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/ManualTorqueOverride/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint8'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_LogicalOperator_o_idx_0;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint8'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_LogicalOperator_o_idx_1;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint8'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/Constant'/Constant'
         */
    rtb_VectorConcatenate[6] = 0U;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint8'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/Constant'/Constant'
         */
    rtb_VectorConcatenate[7] = 0U;
    /* S-Function (sfun_setbit): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint8/set_bit1/Functionality'/sfun_setbit' */
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
        rtb_DataTypeConversion_lu = temp;
    }
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint8/set_bit1/Functionality'/DTC_out' */
    SET_S_VDPDRV_DrvStInvalid_btf(rtb_DataTypeConversion_lu);
    /* Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/Constant'/Constant' */
    rtb_VectorConcatenate_a[7] = 0U;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlABS_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
         */
    rtb_VectorConcatenate_a[0] = (uint8)((((sint32) GET_S_LCFRCV_ActiveStCtrlABS_bool()) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_c[0] > 0.0F));
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2'/ConcatBufferAtVector ConcatenateIn2' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlACC_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
         */
    rtb_VectorConcatenate_a[1] = (uint8)((((sint32) GET_S_LCFRCV_ActiveStCtrlACC_bool()) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_c[1] > 0.0F));
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2'/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlESC_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
         */
    rtb_VectorConcatenate_a[2] = (uint8)((((sint32) GET_S_LCFRCV_ActiveStCtrlESC_bool()) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_c[2] > 0.0F));
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2'/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTCS_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
         */
    rtb_VectorConcatenate_a[3] = (uint8)((((sint32) GET_S_LCFRCV_ActiveStCtrlTCS_bool()) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_c[3] > 0.0F));
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2'/ConcatBufferAtVector ConcatenateIn5' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlVSM_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
         */
    rtb_VectorConcatenate_a[4] = (uint8)((((sint32) GET_S_LCFRCV_ActiveStCtrlVSM_bool()) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_c[4] > 0.0F));
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlEBA_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
         */
    rtb_VectorConcatenate_a[5] = (uint8)((((sint32) GET_S_LCFRCV_ActiveStCtrlEBA_bool()) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_c[5] > 0.0F));
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTSA_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
         */
    rtb_VectorConcatenate_a[6] = (uint8)((((sint32) GET_S_LCFRCV_ActiveStCtrlTSA_bool()) != 0) || (DW_vdpdrv_Unit_Delay_DSTATE_c[6] > 0.0F));
    /* S-Function (sfun_setbit): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_a[0];
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
        rtb_DataTypeConversion_lu = temp;
    }
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint2/set_bit1/Functionality'/DTC_out' */
    SET_S_VDPDRV_ActiveStCtrl_btf(rtb_DataTypeConversion_lu);
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT/Functionality'/Data Type Conversion' incorporates:
                                                                *  Inport: '<Root>/S_LCFRCV_SysStAvailableABS_bool'
                                                                *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT/Functionality'/NOT'
                                                                */
    rtb_LogicalOperator_a[0] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStAvailableABS_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStAvailableACC_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT1/Functionality'/NOT'
         */
    rtb_LogicalOperator_a[1] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStAvailableACC_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStAvailableESC_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT2/Functionality'/NOT'
         */
    rtb_LogicalOperator_a[2] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStAvailableESC_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStAvailableTCS_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT3/Functionality'/NOT'
         */
    rtb_LogicalOperator_a[3] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStAvailableTCS_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStAvailableVSM_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT4/Functionality'/NOT'
         */
    rtb_LogicalOperator_a[4] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStAvailableVSM_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStAvailableEBA_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT5/Functionality'/NOT'
         */
    rtb_LogicalOperator_a[5] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStAvailableEBA_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStAvailableTSA_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/NOT6/Functionality'/NOT'
         */
    rtb_LogicalOperator_a[6] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStAvailableTSA_bool()) != 0));
    /* Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateAvailable/Constant'/Constant' */
    rtb_LogicalOperator_a[7] = 0U;
    /* S-Function (sfun_setbit): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint3/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_LogicalOperator_a[0];
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
        rtb_DataTypeConversion_lu = temp;
    }
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint3/set_bit1/Functionality'/DTC_out' */
    SET_S_VDPDRV_SysStNotAvailable_btf(rtb_DataTypeConversion_lu);
    /* RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Relational Operator1' incorporates:
                                                                     *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Constant1'
                                                                     *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay'
                                                                     */
    for (i = 0; i < 8; i++) {
        rtb_LogicalOperator_a[i] = (uint8)(DW_vdpdrv_Unit_Delay_DSTATE_f[i] <= 0.0F);
    }
    /* End of RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Relational Operator1' */
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStErrorABS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorACC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorESC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorLatDMC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorTSA_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorVSM_bool'
         */
    rtb_LogicalOperator[0] = (sint8)((((sint32)rtb_LogicalOperator_a[0]) != 0) && (((sint32)GET_S_LCFRCV_SysStErrorABS_bool()) != 0));
    rtb_LogicalOperator[1] = (sint8)((((sint32)rtb_LogicalOperator_a[1]) != 0) && (((sint32)GET_S_LCFRCV_SysStErrorACC_bool()) != 0));
    rtb_LogicalOperator[2] = (sint8)((((sint32)rtb_LogicalOperator_a[2]) != 0) && (((sint32)GET_S_LCFRCV_SysStErrorESC_bool()) != 0));
    rtb_LogicalOperator[3] = (sint8)((((sint32)rtb_LogicalOperator_a[3]) != 0) && (((sint32)GET_S_LCFRCV_SysStErrorTCS_bool()) != 0));
    rtb_LogicalOperator[4] = (sint8)((((sint32)rtb_LogicalOperator_a[4]) != 0) && (((sint32)GET_S_LCFRCV_SysStErrorVSM_bool()) != 0));
    rtb_LogicalOperator[5] = (sint8)((((sint32)rtb_LogicalOperator_a[5]) != 0) && (((sint32)GET_S_LCFRCV_SysStErrorTSA_bool()) != 0));
    rtb_LogicalOperator[6] = (sint8)((((sint32)rtb_LogicalOperator_a[6]) != 0) && (((sint32)GET_S_LCFRCV_SysStErrorLatDMC_bool()) != 0));
    rtb_LogicalOperator[7] = (sint8)((((sint32)rtb_LogicalOperator_a[7]) != 0) && (((sint32)GET_S_LCFRCV_SysStErrorEBA_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStErrorABS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorACC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorESC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorLatDMC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorTSA_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorVSM_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/NOT/Functionality'/NOT'
         */
    rtb_LogicalOperator_a[0] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStErrorABS_bool()) != 0));
    rtb_LogicalOperator_a[1] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStErrorACC_bool()) != 0));
    rtb_LogicalOperator_a[2] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStErrorESC_bool()) != 0));
    rtb_LogicalOperator_a[3] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStErrorTCS_bool()) != 0));
    rtb_LogicalOperator_a[4] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStErrorVSM_bool()) != 0));
    rtb_LogicalOperator_a[5] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStErrorTSA_bool()) != 0));
    rtb_LogicalOperator_a[6] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStErrorLatDMC_bool()) != 0));
    rtb_LogicalOperator_a[7] = (uint8)(!(((sint32) GET_S_LCFRCV_SysStErrorEBA_bool()) != 0));
    for (i = 0; i < 8; i++) {
        /* S-Function (fcncallgen): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality'/Comparison'
                 */
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/Constant2'/Constant'
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality'/Logical Operator2'
                 *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality/Comparison'/Logical Operator'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
                 *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality'/Switch2'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay2'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay7'
                 */
        if ((!(((sint32)DW_vdpdrv_Unit_Delay2_DSTATE_m[i]) != 0)) && (((sint32) rtb_LogicalOperator[i]) != 0)) {
            rtb_Abs = GET_P_VDPDRV_HoldTimeErrorSt_sec();
        } else if (DW_vdpdrv_Unit_Delay7_DSTATE[i] > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
            /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay7'
                         */
            rtb_Abs = DW_vdpdrv_Unit_Delay7_DSTATE[i] - GET_S_LCFRCV_SysCycleTimeSen_sec ();
        } else {
            rtb_Abs = 0.0F;
        }
        /* End of Outputs for S-Function (fcncallgen): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING'/fcg' */
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/SRFLIPFLOP/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/SRFLIPFLOP/Functionality'/Constant'
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality'/Constant'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
                 *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/SRFLIPFLOP/Functionality'/Switch1'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay1'
                 */
        if (rtb_Abs > 0.0F) {
            rtb_LogicalOperator_o_idx_0 = 1U;
        } else if (((sint32)rtb_LogicalOperator_a[i]) != 0) {
            /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/SRFLIPFLOP/Functionality'/Constant1'
                         */
            rtb_LogicalOperator_o_idx_0 = 0U;
        } else {
            rtb_LogicalOperator_o_idx_0 = DW_vdpdrv_Unit_Delay1_DSTATE_f[i];
        }
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TIMERRETRIGGER_RE/Functionality'/Switch' */
        rtb_Switch[i] = rtb_Abs;
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/SRFLIPFLOP/Functionality'/Switch' */
        rtb_Switch_c[i] = rtb_LogicalOperator_o_idx_0;
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Constant1'
                 *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Logical Operator'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay3'
                 */
        rtb_LogicalOperator_a[i] = (uint8)((((sint32)rtb_LogicalOperator_o_idx_0) != 0) || (DW_vdpdrv_Unit_Delay3_DSTATE[i] > 0.0F));
    }
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_k[0] = rtb_LogicalOperator_a[0];
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_k[1] = rtb_LogicalOperator_a[1];
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_k[2] = rtb_LogicalOperator_a[2];
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_k[3] = rtb_LogicalOperator_a[3];
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_k[4] = rtb_LogicalOperator_a[4];
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_k[5] = rtb_LogicalOperator_a[5];
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_k[6] = rtb_LogicalOperator_a[6];
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_k[7] = rtb_LogicalOperator_a[7];
    /* S-Function (sfun_setbit): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_k[0];
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
        rtb_DataTypeConversion_lu = temp;
    }
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint1/set_bit1/Functionality'/DTC_out' */
    SET_S_VDPDRV_SysStError_btf(rtb_DataTypeConversion_lu);
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16'/ConcatBufferAtVector ConcatenateIn12' incorporates:
                                                              *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/Constant'/Constant'
                                                              */
    rtb_VectorConcatenate_m[11] = 0U;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16'/ConcatBufferAtVector ConcatenateIn13' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/Constant'/Constant'
         */
    rtb_VectorConcatenate_m[12] = 0U;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16'/ConcatBufferAtVector ConcatenateIn14' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/Constant'/Constant'
         */
    rtb_VectorConcatenate_m[13] = 0U;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16'/ConcatBufferAtVector ConcatenateIn15' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/Constant'/Constant'
         */
    rtb_VectorConcatenate_m[14] = 0U;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16'/ConcatBufferAtVector ConcatenateIn16' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/Constant'/Constant'
         */
    rtb_VectorConcatenate_m[15] = 0U;
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_CurrentGearNeutral_bool'
         *  Inport: '<Root>/S_LCFRCV_CurrentGearParking_bool'
         *  Inport: '<Root>/S_LCFRCV_CurrentGearReverse_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_lu = (uint8)(((((sint32) GET_S_LCFRCV_CurrentGearReverse_bool()) != 0) || (((sint32) GET_S_LCFRCV_CurrentGearParking_bool()) != 0)) || (((sint32) GET_S_LCFRCV_CurrentGearNeutral_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/Logical NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/Logical NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_lu = (uint8)(!(((sint32)rtb_DataTypeConversion_lu) != 0));
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_LCFRCV_CurrentGearParking_bool'
         *  Inport: '<Root>/S_LCFRCV_CurrentGearReverse_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/Logical Operator1/Functionality'/OR'
         *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_lu) != 0) {
        rtb_DataTypeConversion_lu = 0U;
    } else if ((((sint32)GET_S_LCFRCV_CurrentGearReverse_bool()) != 0) || (((sint32)GET_S_LCFRCV_CurrentGearParking_bool()) != 0)) {
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_lu = 1U;
    } else {
        rtb_DataTypeConversion_lu = DW_vdpdrv_Unit_Delay_DSTATE_ce;
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/RSFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/RSFLIPFLOP/Functionality'/Signal Conversion1'
         */
    DW_vdpdrv_Unit_Delay_DSTATE_ce = rtb_DataTypeConversion_lu;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16'/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckReverseGearEngaged/RSFLIPFLOP/Functionality'/Signal Conversion1'
         */
    rtb_VectorConcatenate_m[3] = rtb_DataTypeConversion_lu;
    /* Abs: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SteeringAngleFrontAxleEff_rad'
         */
    rtb_Abs = f32_abs_f32(GET_S_LCFRCV_SteeringAngleFrontAxleEff_rad());
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/P_VDPDRV_MaxVelLimStrngStp_mps'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/P_VDPDRV_ThStrngStpDtctd_rad'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/Logical Operator/Functionality'/AND'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/Relational Operator2/Functionality'/GE'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/Relational Operator4/Functionality'/LT'
         */
    rtb_DataTypeConversion_lu = (uint8)((GET_S_LCFRCV_VehVelX_mps() < GET_P_VDPDRV_MaxVelLimStrngStp_mps()) && (rtb_Abs >= GET_P_VDPDRV_ThStrngStpDtctd_rad()));
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/SRFLIPFLOP/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/P_VDPDRV_ThStrngStpNotDtctd_rad'/Constant'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/Relational Operator3/Functionality'/LT'
         *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/SRFLIPFLOP/Functionality'/Switch'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection'/Unit_Delay'
         */
    if ((((sint32)rtb_DataTypeConversion_lu) == 0) && (!(rtb_Abs < GET_P_VDPDRV_ThStrngStpNotDtctd_rad()))) {
        rtb_DataTypeConversion_lu = DW_vdpdrv_Unit_Delay_DSTATE_g;
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/SRFLIPFLOP/Functionality'/Switch1' */
    /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_vdpdrv_Unit_Delay_DSTATE_g = rtb_DataTypeConversion_lu;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16'/ConcatBufferAtVector ConcatenateIn9' incorporates:
         *  SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/SteeringStopDetection/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate_m[8] = rtb_DataTypeConversion_lu;
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/branch1'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_DoorOpen_bool'
         */
    rtb_VectorConcatenate_m[0] = GET_S_LCFRCV_DoorOpen_bool();
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehReadyToStart_bool'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[1] = (uint8)(!(((sint32) GET_S_LCFRCV_VehReadyToStart_bool()) != 0));
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/branch3'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_TrailerPresent_bool'
         */
    rtb_VectorConcatenate_m[2] = GET_S_LCFRCV_TrailerPresent_bool();
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/branch8'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehMovesBckwd_bool'
         */
    rtb_VectorConcatenate_m[4] = GET_S_LCFRCV_VehMovesBckwd_bool();
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/branch4'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_OversteeringDetected_bool'
         */
    rtb_VectorConcatenate_m[5] = GET_S_LCFRCV_OversteeringDetected_bool();
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/branch5'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_UndersteeringDetected_bool'
         */
    rtb_VectorConcatenate_m[6] = GET_S_LCFRCV_UndersteeringDetected_bool();
    /* SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/branch6'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_RollerBenchDetected_bool'
         */
    rtb_VectorConcatenate_m[7] = GET_S_LCFRCV_RollerBenchDetected_bool();
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/P_VDPDRV_MaxVelLimStrngStp_mps4'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_LCFRCV_WiperState_nu'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ/Functionality'/EQ'
         */
    rtb_DataTypeConversion_lu = (uint8)((((sint32)GET_S_LCFRCV_WiperState_nu()) == ((sint32)((uint8)E_LCF_WIPER_STATE_E_VEH_SIG_WIPER_STATE_ACTIVE))) || (((sint32)GET_P_VDPDRV_DebugWiperStateActive_bool()) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/Constant1'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/Constant15'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/Constant2'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/Constant3'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/Constant4'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/Constant5'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/Constant6'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/Constant7'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/P_VDPDRV_MaxVelLimStrngStp_mps1'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/from_data_definition2'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/from_data_definition3'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/from_data_definition4'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/from_data_definition5'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/from_data_definition6'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/from_data_definition7'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_LCFRCV_WiperStage_nu'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND1/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND2/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND3/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND4/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND5/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND6/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/AND7/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ7/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/EQ8/Functionality'/EQ'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/get_bit/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/get_bit1/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/get_bit2/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/get_bit3/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/get_bit4/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/get_bit5/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/get_bit6/Functionality'/S-Function'
         */
    rtb_LogicalOperator_o_idx_0 = (uint8)((((sint32)rtb_DataTypeConversion_lu) != 0) && (((((((((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_WiperStageActive_btm(), ((uint8)0U)))) != 0) && (((sint32) ((uint8)E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_OFF)) == ((sint32) GET_S_LCFRCV_WiperStage_nu()))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_WiperStageActive_btm(), ((uint8)1U)))) != 0) && (((sint32) ((uint8)E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_INTERVAL1)) == ((sint32) GET_S_LCFRCV_WiperStage_nu())))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_WiperStageActive_btm(), ((uint8)2U)))) != 0) && (((sint32) ((uint8)E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_INTERVAL2)) == ((sint32) GET_S_LCFRCV_WiperStage_nu())))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_WiperStageActive_btm(), ((uint8)3U)))) != 0) && (((sint32) ((uint8)E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_INTERVAL3)) == ((sint32) GET_S_LCFRCV_WiperStage_nu())))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_WiperStageActive_btm(), ((uint8)4U)))) != 0) && (((sint32) ((uint8)E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_INTERVAL4)) == ((sint32) GET_S_LCFRCV_WiperStage_nu())))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_WiperStageActive_btm(), ((uint8)5U)))) != 0) && (((sint32) ((uint8)E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_STAGE1)) == ((sint32) GET_S_LCFRCV_WiperStage_nu())))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_WiperStageActive_btm(), ((uint8)6U)))) != 0) && (((sint32) ((uint8)E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_STAGE2)) == ((sint32) GET_S_LCFRCV_WiperStage_nu())))) || (255 == ((sint32) GET_P_VDPDRV_WiperStageActive_btm()))));
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay'
         */
    rtb_LogicalOperator_o_idx_1 = (uint8)((DW_vdpdrv_Unit_Delay_DSTATE_l <= 0.0F) && (((sint32)rtb_LogicalOperator_o_idx_0) != 0));
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay2'
         */
    rtb_LogicalOperator_j5 = (uint8)((((sint32)rtb_LogicalOperator_o_idx_1) != 0) || (DW_vdpdrv_Unit_Delay2_DSTATE > 0.0F));
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay3'
         */
    rtb_VectorConcatenate_m[9] = (uint8)((DW_vdpdrv_Unit_Delay3_DSTATE_o <= 0.0F) && (((sint32)rtb_LogicalOperator_j5) != 0));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/Constant4'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/P_VDPDRV_MaxVelLimStrngStp_mps1'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_LCFRCV_BrightnessState_nu'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/AND5/Functionality'/AND'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/EQ5/Functionality'/EQ'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/get_bit4/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_lu = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_NoDaytBrightState_btm(), ((uint8)4U)))) != 0) && (((sint32) ((uint8)E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_TWILIGHT_3)) == ((sint32) GET_S_LCFRCV_BrightnessState_nu())));
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/Constant1'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/Constant15'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/Constant2'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/Constant3'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/Constant5'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/Constant7'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/P_VDPDRV_MaxVelLimStrngStp_mps1'/Constant'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/from_data_definition'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/from_data_definition1'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/from_data_definition2'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/from_data_definition3'/state_source'
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_LCFRCV_BrightnessState_nu'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/AND1/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/AND2/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/AND3/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/AND4/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/AND6/Functionality'/AND'
         *  Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/EQ8/Functionality'/EQ'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/get_bit/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/get_bit1/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/get_bit2/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/get_bit3/Functionality'/S-Function'
         *  S-Function (sfun_getbit_77): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/get_bit5/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_lu = (uint8)((((((((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_NoDaytBrightState_btm(), ((uint8)0U)))) != 0) && (((sint32) ((uint8)E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_UNKWN)) == ((sint32) GET_S_LCFRCV_BrightnessState_nu()))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_NoDaytBrightState_btm(), ((uint8)1U)))) != 0) && (((sint32) ((uint8)E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_DAY)) == ((sint32) GET_S_LCFRCV_BrightnessState_nu())))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_NoDaytBrightState_btm(), ((uint8)2U)))) != 0) && (((sint32) ((uint8)E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_TWILIGHT_1)) == ((sint32) GET_S_LCFRCV_BrightnessState_nu())))) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_NoDaytBrightState_btm(), ((uint8)3U)))) != 0) && (((sint32) ((uint8)E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_TWILIGHT_2)) == ((sint32) GET_S_LCFRCV_BrightnessState_nu())))) || (((sint32)rtb_DataTypeConversion_lu) != 0)) || ((((sint32)((uint8)flag_get_u8_u8 (GET_P_VDPDRV_NoDaytBrightState_btm(), ((uint8)5U)))) != 0) && (((sint32) ((uint8)E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_NIGHT)) == ((sint32) GET_S_LCFRCV_BrightnessState_nu())))) || (255 == ((sint32) GET_P_VDPDRV_NoDaytBrightState_btm())));
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay'
         */
    rtb_LogicalOperator_e = (uint8)((DW_vdpdrv_Unit_Delay_DSTATE_e <= 0.0F) && (((sint32)rtb_DataTypeConversion_lu) != 0));
    /* Logic: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay2'
         */
    rtb_VectorConcatenate_m[10] = (uint8)((((sint32)rtb_LogicalOperator_e) != 0) || (DW_vdpdrv_Unit_Delay2_DSTATE_g > 0.0F));
    /* S-Function (sfun_setbit): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_m[0];
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
    /* DataTypeConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/MappingUint16/set_bit1/Functionality'/DTC_out' */
    SET_S_VDPDRV_VehStInvalid_btf(rtb_sfun_setbit);
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LogicalOperator_o_idx_0) != 0) {
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay'
                 */
        if (DW_vdpdrv_Unit_Delay_DSTATE_l > 0.0F) {
            /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_vdpdrv_Unit_Delay_DSTATE_l -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/P_VDPDRV_MaxVelLimStrngStp_mps'/Constant'
                 */
        DW_vdpdrv_Unit_Delay_DSTATE_l = GET_P_VDPDRV_WiperActiveTimeMin_sec();
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Switch2' */
    if (((sint32)rtb_LogicalOperator_j5) != 0) {
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Constant'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay3'
                 */
        if (DW_vdpdrv_Unit_Delay3_DSTATE_o > 0.0F) {
            /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay3' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality/Add/Functionality'/Sum'
                         */
            DW_vdpdrv_Unit_Delay3_DSTATE_o -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay3' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/P_VDPDRV_MaxVelLimStrngStp_mps3'/Constant'
                 */
        DW_vdpdrv_Unit_Delay3_DSTATE_o = GET_P_VDPDRV_WiperMinContinTime_sec();
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNONDELAYTIME1/Functionality'/Switch2' */
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_lu) != 0) {
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay'
                 */
        if (DW_vdpdrv_Unit_Delay_DSTATE_e > 0.0F) {
            /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_vdpdrv_Unit_Delay_DSTATE_e -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/P_VDPDRV_MaxVelLimStrngStp_mps'/Constant'
                 */
        DW_vdpdrv_Unit_Delay_DSTATE_e = GET_P_VDPDRV_NoDaytCndTimeMin_sec();
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/DriverStatus/AccelerationPedalRateCheck'/Unit_Delay' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_AccelPedalPos_nu'
         */
    DW_vdpdrv_Unit_Delay_DSTATE = GET_S_LCFRCV_AccelPedalPos_nu();
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlABS_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlACC_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlESC_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTSA_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlVSM_bool'
         */
    tmp_0[0] = (sint8)GET_S_LCFRCV_ActiveStCtrlABS_bool();
    tmp_0[1] = (sint8)GET_S_LCFRCV_ActiveStCtrlACC_bool();
    tmp_0[2] = (sint8)GET_S_LCFRCV_ActiveStCtrlESC_bool();
    tmp_0[3] = (sint8)GET_S_LCFRCV_ActiveStCtrlTCS_bool();
    tmp_0[4] = (sint8)GET_S_LCFRCV_ActiveStCtrlVSM_bool();
    tmp_0[5] = (sint8)GET_S_LCFRCV_ActiveStCtrlEBA_bool();
    tmp_0[6] = (sint8)GET_S_LCFRCV_ActiveStCtrlTSA_bool();
    /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay' */
    for (i = 0; i < 7; i++) {
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/Constant1'/Constant'
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Relational Operator'
                 *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Switch2'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
                 */
        if (((sint32)tmp_0[i]) != 0) {
            DW_vdpdrv_Unit_Delay_DSTATE_c[i] = GET_P_VDPDRV_DebTimeActStCtrl_sec();
        } else {
            if (DW_vdpdrv_Unit_Delay_DSTATE_c[i] > 0.0F) {
                /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay'
                                 */
                DW_vdpdrv_Unit_Delay_DSTATE_c[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
        }
    }
    /* End of Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/ActiveStateControlling'/Unit_Delay' */
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Switch2' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStErrorABS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorACC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorESC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorLatDMC_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorTSA_bool'
         *  Inport: '<Root>/S_LCFRCV_SysStErrorVSM_bool'
         */
    tmp_1[0] = (sint8)GET_S_LCFRCV_SysStErrorABS_bool();
    tmp_1[1] = (sint8)GET_S_LCFRCV_SysStErrorACC_bool();
    tmp_1[2] = (sint8)GET_S_LCFRCV_SysStErrorESC_bool();
    tmp_1[3] = (sint8)GET_S_LCFRCV_SysStErrorTCS_bool();
    tmp_1[4] = (sint8)GET_S_LCFRCV_SysStErrorVSM_bool();
    tmp_1[5] = (sint8)GET_S_LCFRCV_SysStErrorTSA_bool();
    tmp_1[6] = (sint8)GET_S_LCFRCV_SysStErrorLatDMC_bool();
    tmp_1[7] = (sint8)GET_S_LCFRCV_SysStErrorEBA_bool();
    for (i = 0; i < 8; i++) {
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Switch2' */
        if (((sint32)tmp_1[i]) != 0) {
            /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Constant'
                         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Relational Operator'
                         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay'
                         */
            if (DW_vdpdrv_Unit_Delay_DSTATE_f[i] > 0.0F) {
                /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                                 */
                DW_vdpdrv_Unit_Delay_DSTATE_f[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
            /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNONDELAYTIME/Functionality'/Switch4' */
        } else {
            /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay' incorporates:
                         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/Constant1'/Constant'
                         */
            DW_vdpdrv_Unit_Delay_DSTATE_f[i] = GET_P_VDPDRV_TurnOnTimeErrorSt_sec();
        }
        /* S-Function (fcncallgen): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality'/SignalConversion'
                 */
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay2' incorporates:
                 *  SignalConversion: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
                 */
        DW_vdpdrv_Unit_Delay2_DSTATE_m[i] = (uint8)rtb_LogicalOperator[i];
        /* End of Outputs for S-Function (fcncallgen): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/EDGERISING'/fcg' */
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay7' */
        DW_vdpdrv_Unit_Delay7_DSTATE[i] = rtb_Switch[i];
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay1' */
        DW_vdpdrv_Unit_Delay1_DSTATE_f[i] = rtb_Switch_c[i];
        /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Relational Operator'
                 *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Switch2'
                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay3'
                 */
        if (((sint32)rtb_Switch_c[i]) != 0) {
            /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay3' incorporates:
                         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/Constant3'/Constant'
                         */
            DW_vdpdrv_Unit_Delay3_DSTATE[i] = GET_P_VDPDRV_TurnOffTimeErrorSt_sec();
        } else {
            if (DW_vdpdrv_Unit_Delay3_DSTATE[i] > 0.0F) {
                /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                                 *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay3'
                                 *  Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime'/Unit_Delay3'
                                 */
                DW_vdpdrv_Unit_Delay3_DSTATE[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
        }
        /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/SystemStateError/DelayAndHoldSignals/TurnOnOffAndHoldTime/TURNOFFDELAYTIME/Functionality'/Switch1' */
    }
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay2'
         */
    if (((sint32)rtb_LogicalOperator_o_idx_1) != 0) {
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/P_VDPDRV_MaxVelLimStrngStp_mps2'/Constant'
                 */
        DW_vdpdrv_Unit_Delay2_DSTATE = GET_P_VDPDRV_WiperEventsGapTimeMax_sec();
    } else {
        if (DW_vdpdrv_Unit_Delay2_DSTATE > 0.0F) {
            /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay2'
                         *  Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState'/Unit_Delay2'
                         */
            DW_vdpdrv_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/CheckWiperState/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay2'
         */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        /* Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/P_VDPDRV_MaxVelLimStrngStp_mps2'/Constant'
                 */
        DW_vdpdrv_Unit_Delay2_DSTATE_g = GET_P_VDPDRV_NoDaytCndTrnOff_sec();
    } else {
        if (DW_vdpdrv_Unit_Delay2_DSTATE_g > 0.0F) {
            /* Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay2'
                         *  Update for UnitDelay: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond'/Unit_Delay2'
                         */
            DW_vdpdrv_Unit_Delay2_DSTATE_g -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:VDPDRV/VDPDRV/VDPDRV_SenProcess/M_VDPDRV/VehicleStatus/NoDaytimeCond/TURNOFFDELAYTIME/Functionality'/Switch1' */
}
#include "Pse_VDPDRV.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
