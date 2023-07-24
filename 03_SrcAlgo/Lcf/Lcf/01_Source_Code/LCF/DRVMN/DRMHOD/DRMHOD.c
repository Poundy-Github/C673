/**************************************************************************
COPYRIGHT (C) $Date: 2019/12/13 08:54:08CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/DRVMN/DRMHOD_VEH/DRMHOD/i/project.pj $
$Log: DRMHOD.c  $
Revision 1.4.1.1 2019/12/13 08:54:08CET Grama, Victor (uib08724) (uib08724) 
automatically created
File          : DRMHOD
Generated on  : Fri 13.12.2019 at 09:38:08 (UTC+01:00)
MD5           : [4249011611   266036450  1807093220  3968122703 0](DRMHOD)
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
#include "DRMHOD.h"
#include "DRMHOD_private.h"
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
/* Named constants for Chart: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/HandTorqueStateMachine' */
#define IN_IQF_HANDS_OFF_START_LEFT_RIGHT_STATE ((uint8)1U)
#define IN_IQF_HANDS_OFF_START_LEFT_STATE ((uint8)2U)
#define IN_IQF_HANDS_OFF_START_RIGHT_STATE ((uint8)3U)
#define IN_IQF_HANDS_OFF_STATE         ((uint8)4U)
#define IN_IQF_HANDS_ON_LEFT_STATE     ((uint8)5U)
#define IN_IQF_HANDS_ON_RIGHT_STATE    ((uint8)6U)
#define IN_IQF_HANDS_ON_START_STATE    ((uint8)7U)
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
#define DRMHOD_START_SEC_DATA_8
#include "DRMHOD_MemMap.h"
static uint8 BI_drmhod_D_DRMHOD_EstHandTorState_nu_e;
/* 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/HandTorqueStateMachine' */
static uint8 DW_drmhod_Unit_Delay1_DSTATE;
static uint8 DW_drmhod_Unit_Delay_DSTATE_f = 3U;
static uint8 DW_drmhod_Unit_Delay5_DSTATE = 5U;
static uint8 DW_drmhod_is_active_c3_DRMHOD_cg;
static uint8 DW_drmhod_is_c3_DRMHOD_cg;
#define DRMHOD_STOP_SEC_DATA_8
#include "DRMHOD_MemMap.h"
#define DRMHOD_START_SEC_DATA_16
#include "DRMHOD_MemMap.h"
static uint16 DW_drmhod_Unit_Delay4_DSTATE_h;
static uint16 DW_drmhod_Unit_Delay2_DSTATE_p;
#define DRMHOD_STOP_SEC_DATA_16
#include "DRMHOD_MemMap.h"
#define DRMHOD_START_SEC_DATA_32
#include "DRMHOD_MemMap.h"
static float32 DW_drmhod_Unit_Delay_DSTATE;
static float32 DW_drmhod_Unit_Delay4_DSTATE;
static float32 DW_drmhod_Unit_Delay2_DSTATE;
static float32 DW_drmhod_Unit_Delay3_DSTATE;
#define DRMHOD_STOP_SEC_DATA_32
#include "DRMHOD_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DRMHOD/DRMHOD/INI'/DRMHOD_VehReset'
 * Block description for: 'sda:DRMHOD/DRMHOD/INI'/DRMHOD_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DRMHOD_VehReset
#include "Pse_DRMHOD.h"
/* Short description:  */
void DRMHOD_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DRMHOD/DRMHOD/INI/DRMHOD_VehReset/Constant'/Constant' */
    SET_S_DRMHOD_HandsOffConfirmed_bool(0U);
    /* Constant: 'sda:DRMHOD/DRMHOD/INI/DRMHOD_VehReset/Constant1'/Constant' */
    SET_D_DRMHOD_EstHandTor_Nm(0.0F);
    /* Constant: 'sda:DRMHOD/DRMHOD/INI/DRMHOD_VehReset/Constant2'/Constant' */
    SET_D_DRMHOD_HdOffDtctStatus_nu(0U);
    /* Constant: 'sda:DRMHOD/DRMHOD/INI/DRMHOD_VehReset/Constant3'/Constant' */
    SET_D_DRMHOD_EstHandTorState_nu(0U);
    /* Constant: 'sda:DRMHOD/DRMHOD/INI/DRMHOD_VehReset/Constant4'/Constant' */
    SET_D_DRMHOD_EstHandTorCounter_nu(0U);
    /* Constant: 'sda:DRMHOD/DRMHOD/INI/DRMHOD_VehReset/Constant5'/Constant' */
    SET_D_DRMHOD_CorrectedTorque_Nm(0.0F);
    /* Constant: 'sda:DRMHOD/DRMHOD/INI/DRMHOD_VehReset/Constant6'/Constant' */
    SET_D_DRMHOD_LowPassC(0.0F);
}
#include "Pse_DRMHOD.h"
/* System initialize for function-call system: 'sda:DRMHOD/DRMHOD'/DRMHOD_VehProcess' */
/*
 * Output and update for function-call system: 'sda:DRMHOD/DRMHOD'/DRMHOD_VehProcess'
 * Block description for: 'sda:DRMHOD/DRMHOD'/DRMHOD_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DRMHOD_VehProcess
#include "Pse_DRMHOD.h"
/* Short description:  */
void DRMHOD_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_Sum_g;
    float32 rtb_Sum_m;
    float32 rtb_Sum_h5;
    float32 rtb_Switch_k3;
    float32 rtb_Sum_f;
    uint8 rtb_DataTypeConversion;
    float32 rtb_Sum_ee;
    uint8 rtb_DataTypeConversion_ak;
    uint8 rtb_LE;
    uint16 rtb_Switch_p;
    uint8 rtb_DataTypeConversion_o0;
    uint8 rtb_DataTypeConversion_f;
    uint8 rtb_GE;
    uint16 rtb_Switch_mw;
    uint16 rtb_Switch_a;
    uint8 rtb_DataTypeConversion_iq;
    uint8 rtb_Switch_mj;
    uint16 rtb_Switch_ofv;
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/P_DRMHOD_EstHandTqOffsetP_Nm'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/P_DRMHOD_EstHandTqOffsetP_Nm1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/LT/Functionality'/LT'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/Switch1/Functionality'/Switch'
         */
    if (GET_P_DRMHOD_EstHandTqOffsetP_Nm() < GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm()) {
        rtb_Sum_g = GET_P_DRMHOD_EstHandTqOffsetP_Nm();
    } else if (GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm() > GET_P_DRMHOD_EstHandTqOffsetN_Nm()) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/Switch1/Functionality'/Switch' */
        rtb_Sum_g = GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm();
    } else {
        rtb_Sum_g = GET_P_DRMHOD_EstHandTqOffsetN_Nm();
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/Switch/Functionality'/Switch' */
    /* Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/Offset clearing/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         */
    rtb_Sum_g = GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm() - rtb_Sum_g;
    /* S-Function Block sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_DRMHOD_VXLowPassC_nu(), &x_dps);
    }
    /* Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_m = rtb_ip_lookup_fxpt_sfun_7;
    /* Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/LowPassFilter/Sum1/Functionality'/Sum' incorporates:
         *  Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/LowPassFilter/Product/Functionality'/Mul'
         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/LowPassFilter/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/LowPassFilter'/Unit_Delay'
         */
    rtb_Sum_h5 = ((rtb_Sum_g - DW_drmhod_Unit_Delay_DSTATE) * rtb_Sum_m) + DW_drmhod_Unit_Delay_DSTATE;
    /* Abs: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/Abs/Functionality'/Abs' */
    rtb_Switch_k3 = f32_abs_f32(rtb_Sum_h5);
    /* S-Function Block sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Y_DPLSTM_VXCrvThresHyst_1pm1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_DRMHOD_VelX_mps */
        FDPS_PTR_F32(GETA_X_DRMHOD_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D(GETA_Y_DRMHOD_HandsOnTqLim_Nm(), &x_dps);
    }
    /* Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Y_DPLSTM_VXCrvThresHyst_1pm1/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Y_DPLSTM_VXCrvThresHyst_1pm1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_f = rtb_ip_lookup_fxpt_sfun_7_a;
    /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/Hands_off1'/Constant'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/GT/Functionality'/GT'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay1'
         */
    rtb_DataTypeConversion = (uint8)((1 == ((sint32)DW_drmhod_Unit_Delay1_DSTATE)) && (rtb_Switch_k3 > rtb_Sum_f));
    /* S-Function Block sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_DRMHOD_VelX_mps */
        FDPS_PTR_F32(GETA_X_DRMHOD_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D(GETA_Y_DRMHOD_HandsOffTqLim_Nm(), &x_dps);
    }
    /* Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_ee = rtb_ip_lookup_fxpt_sfun_7_h;
    /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/Hands_on1'/Constant'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/LT/Functionality'/LT'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay1'
         */
    rtb_DataTypeConversion_ak = (uint8)((rtb_Switch_k3 < rtb_Sum_ee) && (0 == ((sint32)DW_drmhod_Unit_Delay1_DSTATE)));
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Constant1'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Constant1'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Relational Operator1'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay1'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay2'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay4'
         */
    if ((DW_drmhod_Unit_Delay4_DSTATE <= 0.0F) && (((sint32) rtb_DataTypeConversion_ak) != 0)) {
        rtb_Switch_mj = 1U;
    } else if ((DW_drmhod_Unit_Delay2_DSTATE <= 0.0F) && (((sint32) rtb_DataTypeConversion) != 0)) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_mj = 0U;
    } else {
        rtb_Switch_mj = DW_drmhod_Unit_Delay1_DSTATE;
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/SRFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_ak) != 0) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay4'
                 */
        if (DW_drmhod_Unit_Delay4_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay4' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_drmhod_Unit_Delay4_DSTATE -= GET_S_LCFRCV_SysCycleTimeVeh_sec();
        }
        /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay4' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/P_DRMHOD_HandsOffCntLim_nu1'/Constant'
                 */
        DW_drmhod_Unit_Delay4_DSTATE = GET_P_DRMHOD_HandsOffQlfTime_sec();
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay2'
                 */
        if (DW_drmhod_Unit_Delay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality/Add/Functionality'/Sum'
                         */
            DW_drmhod_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeVeh_sec();
        }
        /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/P_DRMHOD_HandsOffCntLim_nu2'/Constant'
                 */
        DW_drmhod_Unit_Delay2_DSTATE = GET_P_DRMHOD_HandsOnQlfTime_sec();
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce/TURNONDELAYTIME1/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/LE/Functionality'/LE' incorporates:
         *  UnaryMinus: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/Neg/Functionality'/Unary Minus'
         */
    rtb_LE = (uint8)(rtb_Sum_h5 <= (-rtb_Sum_f));
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Div2/Functionality/DivDefault'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/P_DRMHOD_HandsOffCntLim_nu3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Div2/Functionality/DivDefault'/Div'
         */
    rtb_Switch_p = (uint16)(GET_P_DRMHOD_HandsOffQlfMaxTime_sec() / GET_S_LCFRCV_SysCycleTimeVeh_sec());
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Div/Functionality/DivDefault'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/P_DRMHOD_HandsOffCntLim_nu1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Div/Functionality/DivDefault'/Div'
         */
    rtb_Switch_ofv = (uint16)(GET_P_DRMHOD_HandsOffQlfTime_sec() / GET_S_LCFRCV_SysCycleTimeVeh_sec());
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Constant1'/Constant'
         *  Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Div/Functionality/DivDefault'/Div'
         *  Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Div1/Functionality/DivDefault'/Div'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/GT1/Functionality'/GT'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay4'
         */
    if (((sint32)DW_drmhod_Unit_Delay4_DSTATE_h) > ((sint32)(((uint32)rtb_Switch_p) >> 1))) {
        rtb_Switch_k3 = rtb_Sum_ee / 4.0F;
    } else {
        if (((sint32)DW_drmhod_Unit_Delay4_DSTATE_h) > ((sint32)rtb_Switch_ofv)) {
            /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Constant2'/Constant'
                         *  Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Div2/Functionality/DivDefault'/Div'
                         */
            rtb_Sum_ee /= 2.0F;
        }
        rtb_Switch_k3 = rtb_Sum_ee;
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/HandsOffLimit Calibration/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/Constant5'/Constant'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/LE2/Functionality'/LE'
         *  UnaryMinus: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/Neg1/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_o0 = (uint8)((rtb_Sum_h5 > (-rtb_Switch_k3)) && (rtb_Sum_h5 <= 0.0F));
    /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/Constant5'/Constant'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/GT3/Functionality'/GT'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/LE3/Functionality'/LE'
         */
    rtb_DataTypeConversion_f = (uint8)((rtb_Sum_h5 > 0.0F) && (rtb_Sum_h5 <= rtb_Switch_k3));
    /* RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/ Estimated Hand Torque Intervals/GE/Functionality'/GE' */
    rtb_GE = (uint8)(rtb_Sum_h5 >= rtb_Sum_f);
    /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/from_data_definition'/state_source'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/from_data_definition1'/state_source'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/EQ3/Functionality'/EQ'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay5'
         */
    rtb_DataTypeConversion_ak = (uint8)((((sint32)DW_drmhod_Unit_Delay5_DSTATE) == ((sint32)((uint8)E_DRMHOD_IntStateType_E_DRMHOD_HOFF_SUSP_L))) || (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == ((sint32)((uint8) E_DRMHOD_IntStateType_E_DRMHOD_HOFF_SUSP_R))));
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Constant4'/Constant'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/EQ/Functionality'/EQ'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay2'
         */
    if (((sint32)DW_drmhod_Unit_Delay2_DSTATE_p) == 0) {
        rtb_Switch_mw = rtb_Switch_ofv;
    } else {
        rtb_Switch_mw = DW_drmhod_Unit_Delay2_DSTATE_p;
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Div1/Functionality/DivDefault'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/P_DRMHOD_HandsOffCntLim_nu2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Div1/Functionality/DivDefault'/Div'
         */
    rtb_Switch_a = (uint16)(GET_P_DRMHOD_HandsOnQlfTime_sec() / GET_S_LCFRCV_SysCycleTimeVeh_sec());
    /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/AND7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/from_data_definition3'/state_source'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/P_DRMHOD_HandsOnTorLimAbs_Nm'/Constant'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/AND7/Functionality'/AND'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/OR6/Functionality'/OR'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/EQ9/Functionality'/EQ'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/GE/Functionality'/GE'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/GT3/Functionality'/GT'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/LE1/Functionality'/LE'
         *  UnaryMinus: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/Neg/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay4'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay5'
         */
    rtb_DataTypeConversion_iq = (uint8)((((sint32)((uint8) E_DRMHOD_IntStateType_E_DRMHOD_HON_SUSP)) == ((sint32) DW_drmhod_Unit_Delay5_DSTATE)) && (((((sint32)DW_drmhod_Unit_Delay4_DSTATE_h) >= ((sint32)rtb_Switch_a)) || (rtb_Sum_h5 > GET_P_DRMHOD_HandsOnTorLimAbs_Nm())) || (rtb_Sum_h5 <= (-GET_P_DRMHOD_HandsOnTorLimAbs_Nm()))));
    /* RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/GT7/Functionality'/GT' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/Constant19'/Constant'
         */
    rtb_DataTypeConversion = (uint8)(rtb_Sum_h5 > 0.0F);
    /* Chart: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/HandTorqueStateMachine' incorporates:
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/AND4/Functionality'/AND'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/AND8/Functionality'/AND'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/AND9/Functionality'/AND'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Suspicious ON_OFF State signals/GE1/Functionality'/GE'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay4'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay5'
         *
         * Block description for 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/HandTorqueStateMachine':
         *  X.2.1.1.2.1
         */
    /* Gateway: DRMHOD_cg/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine */
    /* During: DRMHOD_cg/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine */
    if (((uint32)((sint32)DW_drmhod_is_active_c3_DRMHOD_cg)) == 0U) {
        /* Entry: DRMHOD_cg/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine */
        DW_drmhod_is_active_c3_DRMHOD_cg = 1U;
        /* Entry Internal: DRMHOD_cg/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine */
        /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':126' */
        if ((((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 3) || (((sint32) DW_drmhod_Unit_Delay5_DSTATE) == 4)) {
            /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':153' */
            DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_START_LEFT_RIGHT_STATE;
        } else if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 1) {
            /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':48' */
            DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_RIGHT_STATE;
            /* Entry 'IQF_HANDS_ON_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':41' */
            BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 1U;
            /* IQF_HANDS_ON_RIGHT; */
        } else if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 5) {
            /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':103' */
            DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_STATE;
            /* Entry 'IQF_HANDS_OFF_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':98' */
            BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 5U;
            /* IQF_HANDS_OFF */
        } else {
            if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 0) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':35' */
                DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_LEFT_STATE;
                /* Entry 'IQF_HANDS_ON_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':34' */
                BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 0U;
                /* IQF_HANDS_ON_LEFT */
            }
        }
    } else {
        switch (DW_drmhod_is_c3_DRMHOD_cg) {
        case IN_IQF_HANDS_OFF_START_LEFT_RIGHT_STATE:
            /* During 'IQF_HANDS_OFF_START_LEFT_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':53' */
            if ((((sint32)rtb_DataTypeConversion_ak) != 0) && (((sint32) DW_drmhod_Unit_Delay4_DSTATE_h) >= ((sint32)rtb_Switch_mw))) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':145' */
                DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_STATE;
                /* Entry 'IQF_HANDS_OFF_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':98' */
                BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 5U;
                /* IQF_HANDS_OFF */
            } else if (((sint32)rtb_LE) == 1) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':144' */
                DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_RIGHT_STATE;
                /* Entry 'IQF_HANDS_ON_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':41' */
                BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 1U;
                /* IQF_HANDS_ON_RIGHT; */
            } else {
                if (((sint32)rtb_GE) == 1) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':143' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_LEFT_STATE;
                    /* Entry 'IQF_HANDS_ON_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':34' */
                    BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 0U;
                    /* IQF_HANDS_ON_LEFT */
                }
            }
            break;
        case IN_IQF_HANDS_OFF_START_LEFT_STATE:
            /* During 'IQF_HANDS_OFF_START_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':148' */
            if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 3) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':149' */
                if ((((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 3) || (((sint32) DW_drmhod_Unit_Delay5_DSTATE) == 4)) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':153' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_START_LEFT_RIGHT_STATE;
                } else if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 1) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':48' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_RIGHT_STATE;
                    /* Entry 'IQF_HANDS_ON_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':41' */
                    BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 1U;
                    /* IQF_HANDS_ON_RIGHT; */
                } else if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 5) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':103' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_STATE;
                    /* Entry 'IQF_HANDS_OFF_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':98' */
                    BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 5U;
                    /* IQF_HANDS_OFF */
                } else {
                    if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 0) {
                        /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':35' */
                        DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_LEFT_STATE;
                        /* Entry 'IQF_HANDS_ON_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':34' */
                        BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 0U;
                        /* IQF_HANDS_ON_LEFT */
                    }
                }
            }
            break;
        case IN_IQF_HANDS_OFF_START_RIGHT_STATE:
            /* During 'IQF_HANDS_OFF_START_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':150' */
            if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 4) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':152' */
                if ((((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 3) || (((sint32) DW_drmhod_Unit_Delay5_DSTATE) == 4)) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':153' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_START_LEFT_RIGHT_STATE;
                } else if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 1) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':48' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_RIGHT_STATE;
                    /* Entry 'IQF_HANDS_ON_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':41' */
                    BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 1U;
                    /* IQF_HANDS_ON_RIGHT; */
                } else if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 5) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':103' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_STATE;
                    /* Entry 'IQF_HANDS_OFF_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':98' */
                    BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 5U;
                    /* IQF_HANDS_OFF */
                } else {
                    if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 0) {
                        /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':35' */
                        DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_LEFT_STATE;
                        /* Entry 'IQF_HANDS_ON_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':34' */
                        BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 0U;
                        /* IQF_HANDS_ON_LEFT */
                    }
                }
            }
            break;
        case IN_IQF_HANDS_OFF_STATE:
            /* During 'IQF_HANDS_OFF_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':98' */
            if (((((sint32)rtb_DataTypeConversion_f) == 0) || (((sint32) rtb_DataTypeConversion_o0) == 0)) && ((((sint32)rtb_GE) == 1) || (((sint32)rtb_LE) == 1))) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':146' */
                DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_START_STATE;
                /* Entry 'IQF_HANDS_ON_START_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':109' */
                BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 2U;
                /* IQF_HANDS_ON_START */
            } else {
                if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) != 5) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':104' */
                    if ((((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 3) || (((sint32) DW_drmhod_Unit_Delay5_DSTATE) == 4)) {
                        /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':153' */
                        DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_START_LEFT_RIGHT_STATE;
                    } else if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 1) {
                        /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':48' */
                        DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_RIGHT_STATE;
                        /* Entry 'IQF_HANDS_ON_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':41' */
                        BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 1U;
                        /* IQF_HANDS_ON_RIGHT; */
                    } else if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 5) {
                        /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':103' */
                        DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_STATE;
                        /* Entry 'IQF_HANDS_OFF_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':98' */
                        BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 5U;
                        /* IQF_HANDS_OFF */
                    } else {
                        if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == 0) {
                            /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':35' */
                            DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_LEFT_STATE;
                            /* Entry 'IQF_HANDS_ON_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':34' */
                            BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 0U;
                            /* IQF_HANDS_ON_LEFT */
                        }
                    }
                }
            }
            break;
        case IN_IQF_HANDS_ON_LEFT_STATE:
            /* During 'IQF_HANDS_ON_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':34' */
            if ((((sint32)rtb_DataTypeConversion_f) != 0) || (((sint32) rtb_DataTypeConversion_o0) != 0)) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':136' */
                DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_START_LEFT_STATE;
                /* Entry 'IQF_HANDS_OFF_START_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':148' */
                BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 3U;
                /* IQF_HANDS_OFF_START_LEFT; */
            } else {
                if (((sint32)rtb_LE) == 1) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':42' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_RIGHT_STATE;
                    /* Entry 'IQF_HANDS_ON_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':41' */
                    BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 1U;
                    /* IQF_HANDS_ON_RIGHT; */
                }
            }
            break;
        case IN_IQF_HANDS_ON_RIGHT_STATE:
            /* During 'IQF_HANDS_ON_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':41' */
            if ((((sint32)rtb_DataTypeConversion_f) != 0) || (((sint32) rtb_DataTypeConversion_o0) != 0)) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':151' */
                DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_START_RIGHT_STATE;
                /* Entry 'IQF_HANDS_OFF_START_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':150' */
                BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 4U;
                /* IQF_HANDS_OFF_START_LEFT; */
            } else {
                if (((sint32)rtb_GE) == 1) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':47' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_LEFT_STATE;
                    /* Entry 'IQF_HANDS_ON_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':34' */
                    BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 0U;
                    /* IQF_HANDS_ON_LEFT */
                }
            }
            break;
        default:
            /* During 'IQF_HANDS_ON_START_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':109' */
            if ((((sint32)rtb_DataTypeConversion_iq) != 0) && (!(((sint32) rtb_DataTypeConversion) != 0))) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':142' */
                DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_RIGHT_STATE;
                /* Entry 'IQF_HANDS_ON_RIGHT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':41' */
                BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 1U;
                /* IQF_HANDS_ON_RIGHT; */
            } else if ((((sint32)rtb_DataTypeConversion_f) == 1) || (((sint32) rtb_DataTypeConversion_o0) == 1)) {
                /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':113' */
                DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_OFF_STATE;
                /* Entry 'IQF_HANDS_OFF_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':98' */
                BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 5U;
                /* IQF_HANDS_OFF */
            } else {
                if ((((sint32)rtb_DataTypeConversion_iq) != 0) && (((sint32) rtb_DataTypeConversion) != 0)) {
                    /* Transition: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':141' */
                    DW_drmhod_is_c3_DRMHOD_cg = IN_IQF_HANDS_ON_LEFT_STATE;
                    /* Entry 'IQF_HANDS_ON_LEFT_STATE': 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/HandTorqueStateMachine':34' */
                    BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 0U;
                    /* IQF_HANDS_ON_LEFT */
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/HandTorqueStateMachine' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Constant2'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Constant4'/Constant'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/EQ4/Functionality'/EQ'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay'
         */
    if (((sint32)DW_drmhod_Unit_Delay_DSTATE_f) == 3) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Constant3'/Constant'
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Constant5'/Constant'
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Constant6'/Constant'
                 *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/EQ1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/EQ2/Functionality'/EQ'
                 */
        if ((1 == ((sint32)BI_drmhod_D_DRMHOD_EstHandTorState_nu_e)) || (((sint32) BI_drmhod_D_DRMHOD_EstHandTorState_nu_e) == 0)) {
            rtb_DataTypeConversion = 0U;
        } else {
            rtb_DataTypeConversion = DW_drmhod_Unit_Delay_DSTATE_f;
        }
        /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Switch2/Functionality'/Switch' */
    } else if (((sint32)BI_drmhod_D_DRMHOD_EstHandTorState_nu_e) == 5) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Constant1'/Constant'
                 */
        rtb_DataTypeConversion = 3U;
    } else {
        rtb_DataTypeConversion = DW_drmhod_Unit_Delay_DSTATE_f;
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/FinalDecision/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/Switch11/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/from_data_definition1'/state_source'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/OR9/Functionality'/OR'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/EQ10/Functionality'/EQ'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/EQ11/Functionality'/EQ'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/Switch9/Functionality'/Switch'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay3'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay5'
         */
    if ((((sint32)DW_drmhod_Unit_Delay5_DSTATE) == ((sint32)((uint8) E_DRMHOD_IntStateType_E_DRMHOD_HON_L))) || (((sint32) DW_drmhod_Unit_Delay5_DSTATE) == ((sint32)((uint8) E_DRMHOD_IntStateType_E_DRMHOD_HON_R)))) {
        rtb_Switch_k3 = GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm();
        rtb_Switch_mw = rtb_Switch_ofv;
    } else {
        rtb_Switch_k3 = DW_drmhod_Unit_Delay3_DSTATE;
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/from_data_definition3'/state_source'
                 *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/EQ5/Functionality'/EQ'
                 *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay3'
                 */
        if (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == ((sint32)((uint8) E_DRMHOD_IntStateType_E_DRMHOD_HON_SUSP))) {
            rtb_Switch_mw = rtb_Switch_a;
        }
        /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/Switch6/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter Limit initialisation_reset/Switch11/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/OR11/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/OR11/Functionality'/OR'
         */
    rtb_DataTypeConversion_o0 = (uint8)((((sint32)rtb_DataTypeConversion_f) != 0) || (((sint32)rtb_DataTypeConversion_o0) != 0));
    /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/OR3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/OR3/Functionality'/OR'
         */
    rtb_DataTypeConversion_iq = (uint8)((((sint32)rtb_LE) != 0) || (((sint32) rtb_GE) != 0));
    /* RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/EQ7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/from_data_definition3'/state_source'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay5'
         */
    rtb_LE = (uint8)(((sint32)DW_drmhod_Unit_Delay5_DSTATE) == ((sint32)((uint8) E_DRMHOD_IntStateType_E_DRMHOD_HON_SUSP)));
    /* Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Div4/Functionality/DivDefault'/Div' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Constant14'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/P_DRMHOD_HandsOnTorLimAbs_Nm'/Constant'
         */
    rtb_Sum_f = GET_P_DRMHOD_HandsOnTorLimAbs_Nm() / 2.0F;
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Constant10'/Constant'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/OR8/Functionality'/OR'
         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Sum4/Functionality'/Sum'
         *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay4'
         */
    if ((((sint32)rtb_DataTypeConversion_ak) != 0) || (((sint32) rtb_DataTypeConversion_iq) != 0)) {
        rtb_Switch_a = u16_u32(1U + ((uint32)((sint32)DW_drmhod_Unit_Delay4_DSTATE_h)));
    } else {
        rtb_Switch_a = DW_drmhod_Unit_Delay4_DSTATE_h;
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Constant17'/Constant'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/AND5/Functionality'/AND'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/AND6/Functionality'/AND'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/OR4/Functionality'/OR'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/OR5/Functionality'/OR'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/GT5/Functionality'/GT'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/LT4/Functionality'/LT'
         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Sum6/Functionality'/Sum'
         *  UnaryMinus: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Neg/Functionality'/Unary Minus'
         */
    if (((((sint32)rtb_DataTypeConversion_iq) != 0) && (((sint32)rtb_LE) != 0)) || ((((sint32)rtb_LE) != 0) && ((rtb_Sum_h5 > rtb_Sum_f) || (rtb_Sum_h5 < (-rtb_Sum_f))))) {
        rtb_Switch_a = u16_u32(1U + ((uint32)((sint32)rtb_Switch_a)));
    } else {
        /* DataTypeConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/OR12/Functionality'/Data Type Conversion' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/from_data_definition1'/state_source'
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/from_data_definition2'/state_source'
                 *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/OR12/Functionality'/OR'
                 *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/EQ13/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/EQ14/Functionality'/EQ'
                 *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay5'
                 */
        rtb_DataTypeConversion_iq = (uint8)((((sint32)DW_drmhod_Unit_Delay5_DSTATE) == ((sint32)((uint8)E_DRMHOD_IntStateType_E_DRMHOD_HOFF_SUSP_L))) || (((sint32)DW_drmhod_Unit_Delay5_DSTATE) == ((sint32)((uint8) E_DRMHOD_IntStateType_E_DRMHOD_HOFF_SUSP_R))));
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Constant11'/Constant'
                 *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/AND1/Functionality'/AND'
                 *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/NOT1/Functionality'/NOT'
                 *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/NOT2/Functionality'/NOT'
                 *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/OR7/Functionality'/OR'
                 */
        if ((!(((sint32)rtb_DataTypeConversion_iq) != 0)) || ((((sint32) rtb_DataTypeConversion_iq) != 0) && (!(((sint32) rtb_DataTypeConversion_o0) != 0)))) {
            rtb_Switch_a = 0U;
        }
        /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Switch8/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter increment and reset/Switch10/Functionality'/Switch' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/P_DRMHOD_HandsOffCntLim_nu4'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/P_DRMHOD_HdOffSensedTqDelta_Nm'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/AND/Functionality'/AND'
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/AND2/Functionality'/AND'
         *  Product: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Div3/Functionality/DivDefault'/Div'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/LT1/Functionality'/LT'
         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Sum/Functionality'/Sum'
         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Sum1/Functionality'/Sum'
         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Sum2/Functionality'/Sum'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/Div3/Functionality/DivDefault'/Switch'
         */
    if (((rtb_Switch_k3 < (rtb_Switch_k3 - GET_P_DRMHOD_HdOffSensedTqDelta_Nm())) && (rtb_Switch_k3 > (GET_P_DRMHOD_HdOffSensedTqDelta_Nm() + rtb_Switch_k3))) && (((sint32)rtb_Switch_mw) <= ((sint32)rtb_Switch_p))) {
        rtb_Switch_mw = u16_u32(((uint32)((uint16) (GET_P_DRMHOD_HdOffDltProlTime_sec() / GET_S_LCFRCV_SysCycleTimeVeh_sec()))) + ((uint32)((sint32)rtb_Switch_mw)));
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Switch12/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/OR10/Functionality'/OR'
         */
    if ((((sint32)rtb_DataTypeConversion_o0) != 0) || (((sint32) rtb_DataTypeConversion_ak) != 0)) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Switch2/Functionality'/Switch' incorporates:
                 *  Abs: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Abs/Functionality'/Abs'
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchAngleTorque1/P_DRMHOD_HdOffTqStepLim_Nm'/Constant'
                 *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/LT2/Functionality'/LT'
                 *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/LowPassFilter/Sum2/Functionality'/Sum'
                 *  UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/LowPassFilter'/Unit_Delay'
                 */
        if (f32_abs_f32(rtb_Sum_h5 - DW_drmhod_Unit_Delay_DSTATE) < GET_P_DRMHOD_HdOffTqStepLim_Nm()) {
            /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay2' incorporates:
                         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Constant7'/Constant'
                         *  Sum: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Sum3/Functionality'/Sum'
                         */
            DW_drmhod_Unit_Delay2_DSTATE_p = u16_s32(((sint32)rtb_Switch_mw) - 1);
        } else {
            /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay2' */
            DW_drmhod_Unit_Delay2_DSTATE_p = rtb_Switch_ofv;
        }
        /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Switch2/Functionality'/Switch' */
    } else {
        /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay2' */
        DW_drmhod_Unit_Delay2_DSTATE_p = rtb_Switch_mw;
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Switch12/Functionality'/Switch' */
    /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_Off_Detect/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Hands_off1'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/P_DRMHOD_BasicDebounceOnly_bool'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/P_DRMHOD_OverrideHandsOn_nu1'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/P_DRMHOD_OverrideHandsOn_nu2'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/P_DRMHOD_OverrideHandsOn_nu3'/Constant'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/from_data_definition1'/state_source'
         *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/from_data_definition2'/state_source'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/EQ1/Functionality'/EQ'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_Off_Detect2/Functionality'/Switch'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_Off_Detect3/Functionality'/Switch'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_On/Functionality'/Switch'
         */
    if (((sint32)GET_P_DRMHOD_DebugMode_nu()) == ((sint32)((uint8) E_DRMHOD_DebugModeType_E_DRMHOD_ALWAYS_HANDS_OFF))) {
        rtb_DataTypeConversion_ak = 1U;
    } else if (((sint32)GET_P_DRMHOD_DebugMode_nu()) == ((sint32)((uint8) E_DRMHOD_DebugModeType_E_DRMHOD_ALWAYS_HANDS_ON))) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_On/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Hands_on1'/Constant'
                 */
        rtb_DataTypeConversion_ak = 0U;
    } else if (((sint32)GET_P_DRMHOD_ExternalSensorUsed_bool()) != 0) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_Off_Detect2/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_HandsOffConfirmedExt_bool'
                 *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_On/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_ak = GET_S_LCFRCV_HandsOffConfirmedExt_bool();
    } else if (((sint32)GET_P_DRMHOD_BasicDebounceOnly_bool()) != 0) {
        /* Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_Off_Detect3/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_Off_Detect2/Functionality'/Switch'
                 *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_On/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_ak = rtb_Switch_mj;
    } else {
        rtb_DataTypeConversion_ak = rtb_DataTypeConversion;
    }
    /* End of Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_Off_Detect/Functionality'/Switch' */
    /* SignalConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/branch'/copy1' incorporates:
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/SwitchDebugMode/Override_Hands_Off_Detect1/Functionality'/Switch'
         */
    SET_S_DRMHOD_HandsOffConfirmed_bool((uint8)(((sint32) rtb_DataTypeConversion_ak) != 0));
    /* SignalConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/branch2'/copy1' */
    SET_D_DRMHOD_EstHandTorState_nu(BI_drmhod_D_DRMHOD_EstHandTorState_nu_e);
    /* SignalConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/branch3'/copy1' */
    SET_D_DRMHOD_EstHandTor_Nm(rtb_Sum_h5);
    /* SignalConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/branch4'/copy1' */
    SET_D_DRMHOD_HdOffDtctStatus_nu(rtb_DataTypeConversion);
    /* SignalConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/branch5'/copy1' */
    SET_D_DRMHOD_EstHandTorCounter_nu(rtb_Switch_a);
    /* SignalConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/branch6'/copy1' */
    SET_D_DRMHOD_CorrectedTorque_Nm(rtb_Sum_g);
    /* SignalConversion: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/branch7'/copy1' */
    SET_D_DRMHOD_LowPassC(rtb_Sum_m);
    /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/BasicDebounce'/Unit_Delay1' */
    DW_drmhod_Unit_Delay1_DSTATE = rtb_Switch_mj;
    /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/HandTorqueEstimaton/TorqueFilter/LowPassFilter'/Unit_Delay' */
    DW_drmhod_Unit_Delay_DSTATE = rtb_Sum_h5;
    /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay' */
    DW_drmhod_Unit_Delay_DSTATE_f = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay4' */
    DW_drmhod_Unit_Delay4_DSTATE_h = rtb_Switch_a;
    /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay5' */
    DW_drmhod_Unit_Delay5_DSTATE = BI_drmhod_D_DRMHOD_EstHandTorState_nu_e;
    /* Update for UnitDelay: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc'/Unit_Delay3' incorporates:
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Switch13/Functionality'/Switch'
         *  Switch: 'sda:DRMHOD/DRMHOD/DRMHOD_VehProcess/OPM/M_DRMHOD/IQFHandsOffCalc/State Machine Signal Emitor/Counter limit update/Switch4/Functionality'/Switch'
         */
    DW_drmhod_Unit_Delay3_DSTATE = rtb_Switch_k3;
}
#include "Pse_DRMHOD.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
