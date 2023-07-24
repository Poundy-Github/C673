/**************************************************************************
COPYRIGHT (C) $Date: 2019/05/15 19:19:00CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJCTR/TCTCDC_VEH/TCTCDC/i/project.pj $
$Log: TCTCDC.c  $
Revision 1.3 2019/05/15 19:19:00CEST Schrader, Moritz (uia92406) (uia92406) 
automatically created
File          : TCTCDC
Generated on  : Wed 15.05.2019 at 18:37:09 (UTC+01:00)
MD5           : [3783241318  3365246682   221577024  1934354987 0](TCTCDC)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TCTCDC.h"
#include "TCTCDC_private.h"
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
#define TCTCDC_START_SEC_DATA_8
#include "TCTCDC_MemMap.h"
static uint8 DW_tctcdc_Unit_Delay_DSTATE_p;
static uint8 DW_tctcdc_Unit_Delay_DSTATE_e;
#define TCTCDC_STOP_SEC_DATA_8
#include "TCTCDC_MemMap.h"
#define TCTCDC_START_SEC_DATA_32
#include "TCTCDC_MemMap.h"
static float32 DW_tctcdc_Unit_Delay_DSTATE;
static float32 DW_tctcdc_Unit_Delay1_DSTATE;
static float32 DW_tctcdc_Unit_Delay2_DSTATE;
static float32 DW_tctcdc_Unit_Delay3_DSTATE;
static float32 DW_tctcdc_Unit_Delay4_DSTATE;
static float32 DW_tctcdc_Unit_Delay5_DSTATE;
static float32 DW_tctcdc_Unit_Delay6_DSTATE;
static float32 DW_tctcdc_Unit_Delay7_DSTATE;
static float32 DW_tctcdc_UnitDelay2_DSTATE;
static float32 DW_tctcdc_Unit_Delay2_DSTATE_p;
static float32 DW_tctcdc_UnitDelay2_DSTATE_c;
static float32 DW_tctcdc_Unit_Delay3_DSTATE_f;
#define TCTCDC_STOP_SEC_DATA_32
#include "TCTCDC_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TCTCDC/TCTCDC/INI'/TCTCDC_VehReset'
 * Block description for: 'sda:TCTCDC/TCTCDC/INI'/TCTCDC_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTCDC_VehReset
#include "Pse_TCTCDC.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTCDC_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant'/Constant' */
    SET_S_TCTCDC_CtrlErrDistY_met(0.0F);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant1'/Constant' */
    SET_S_TCTCDC_CtrlErrHeadAgl_rad(0.0F);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant10'/Constant' */
    SET_D_TCTCDC_DeltaThetaRaw_rad(0.0F);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant12'/Constant' */
    SET_D_TCTCDC_DeltaThetaPT1_rad(0.0F);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant2'/Constant' */
    SET_S_TCTCDC_CtrlErrHeadAglPrev_rad(0.0F);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant21'/Constant' */
    SET_S_TCTCDC_QualifierService_nu(0U);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant22'/Constant' */
    SET_D_TCTCDC_WatchdogStatus_nu(0U);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant23'/Constant' */
    SET_D_TCTCDC_QualifierService_nu(0U);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant3'/Constant' */
    SET_D_TCTCDC_DeltaYRaw_met(0.0F);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant4'/Constant' */
    SET_D_TCTCDC_DeltaYPT1_met(0.0F);
    /* Constant: 'sda:TCTCDC/TCTCDC/INI/TCTCDC_VehReset/Constant6'/Constant' */
    SET_D_TCTCDC_DeltaThetaEsti_rad(0.0F);
}
#include "Pse_TCTCDC.h"
/*
 * Output and update for function-call system: 'sda:TCTCDC/TCTCDC'/TCTCDC_VehProcess'
 * Block description for: 'sda:TCTCDC/TCTCDC'/TCTCDC_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTCDC_VehProcess
#include "Pse_TCTCDC.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTCDC_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Sum;
    float32 rtb_Sum_i;
    float32 rtb_Div;
    float32 rtb_SFunction;
    float32 rtb_Div_c;
    float32 rtb_SFunction_b;
    float32 rtb_Switch_p;
    float32 rtb_Switch_c;
    float32 rtb_Sum_fo;
    uint8 rtb_NE_c;
    uint8 rtb_Unit_Delay_m;
    uint8 rtb_EQ;
    uint8 rtb_EQ_i;
    float32 rtb_Abs;
    float32 rtb_Abs_o;
    float32 rtb_Switch_d;
    float32 rtb_Unit_Delay1;
    float32 rtb_Unit_Delay2;
    float32 rtb_Unit_Delay3;
    float32 rtb_Unit_Delay4;
    float32 rtb_Unit_Delay5;
    float32 rtb_Unit_Delay6;
    float32 rtb_Switch_mk;
    float32 rtb_MultiportSwitch;
    float32 rtb_MultiportSwitch1;
    uint8 tmp;
    sint32 rtb_Abs_h;
    /* Outputs for Atomic SubSystem: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess'/M_TCTCDC'
         *
         * Block description for 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess'/M_TCTCDC':
         *  X.2.1
         */
    /* Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Control Deviation Y-Coordinate/Add/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TPLFBT_CurDistY_met'
         *  Inport: '<Root>/S_TPLFBT_TrajDistY_met'
         */
    rtb_Sum = GET_S_TPLFBT_TrajDistY_met() - GET_S_TPLFBT_CurDistY_met();
    /* Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Control Deviation Yaw Angle1/Add/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTEST_SObsBeta_rad'
         *  Inport: '<Root>/S_TPLFBT_CurHeading_rad'
         *  Inport: '<Root>/S_TPLFBT_TrajHeadInclPrev_rad'
         *  Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Sum2/Functionality'/Sum'
         */
    rtb_Sum_i = GET_S_TPLFBT_TrajHeadInclPrev_rad() - (GET_S_TPLFBT_CurHeading_rad () + GET_S_TCTEST_SObsBeta_rad());
    /* RelationalOperator: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Freeze and Enable/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Freeze and Enable/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_NE_c = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) != ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF)));
    /* DataTypeConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/NOT/Functionality'/NOT'
         */
    rtb_Unit_Delay_m = (uint8)(!(((sint32)rtb_NE_c) != 0));
    /* DataTypeConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/OR/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Logic: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/OR/Functionality'/OR'
         */
    rtb_Unit_Delay_m = (uint8)((((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0) || (((sint32)rtb_Unit_Delay_m) != 0));
    /* RelationalOperator: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Freeze and Enable/Equality/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Freeze and Enable/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) == ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE)));
    /* S-Function (fcncallgen): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/OR1/Functionality'/OR'
         *  UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset'/Unit_Delay'
         */
    rtb_Unit_Delay_m = (uint8)((((sint32)rtb_Unit_Delay_m) != 0) || ((((sint32) DW_tctcdc_Unit_Delay_DSTATE_p) != 0) && (!(((sint32)rtb_EQ) != 0))));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING'/fcg' */
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation'/Unit_Delay' */
    rtb_Abs_o = DW_tctcdc_Unit_Delay_DSTATE;
    /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Constant5'/Constant'
         */
    if (((sint32)rtb_NE_c) != 0) {
        rtb_Switch_d = rtb_Abs_o;
    } else {
        rtb_Switch_d = 0.0F;
    }
    /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Switch5/Functionality'/Switch' */
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay1' */
    rtb_Unit_Delay1 = DW_tctcdc_Unit_Delay1_DSTATE;
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay2' */
    rtb_Unit_Delay2 = DW_tctcdc_Unit_Delay2_DSTATE;
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay3' */
    rtb_Unit_Delay3 = DW_tctcdc_Unit_Delay3_DSTATE;
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay4' */
    rtb_Unit_Delay4 = DW_tctcdc_Unit_Delay4_DSTATE;
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay5' */
    rtb_Unit_Delay5 = DW_tctcdc_Unit_Delay5_DSTATE;
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay6' */
    rtb_Unit_Delay6 = DW_tctcdc_Unit_Delay6_DSTATE;
    /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Kmc_delta_psi_obs_gain_const'/Constant'
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         *  Inport: '<Root>/S_TPLFBT_CurHeading_rad'
         *  Product: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Kmc_delta_psi_obs_gain/Functionality'/Mul'
         *  Product: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Mul2/Functionality'/Mul'
         *  Product: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Mul3/Functionality'/Mul'
         *  Product: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Mul4/Functionality'/Mul'
         *  Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Add1/Functionality'/Sum'
         *  Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Add3/Functionality'/Sum'
         *  Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Add4/Functionality'/Sum'
         *  Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Sum/Functionality'/Sum'
         *  UnaryMinus: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Neg1/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Neg3/Functionality'/Unary Minus'
         */
    if (((sint32)rtb_Unit_Delay_m) != 0) {
        rtb_Switch_mk = -GET_S_TPLFBT_CurHeading_rad();
    } else {
        /* MultiPortSwitch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Multiport_Switch' incorporates:
                 *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Constant1'/Constant'
                 *  UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay1'
                 *  UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay2'
                 *  UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay3'
                 *  UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay4'
                 *  UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay5'
                 *  UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay6'
                 *  UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay7'
                 */
        switch (GET_P_TCTCDC_DelayCycleNum_nu()) {
        case 0:
            rtb_Abs_o = rtb_Switch_d;
            break;
        case 1:
            rtb_Abs_o = DW_tctcdc_Unit_Delay1_DSTATE;
            break;
        case 2:
            rtb_Abs_o = DW_tctcdc_Unit_Delay2_DSTATE;
            break;
        case 3:
            rtb_Abs_o = DW_tctcdc_Unit_Delay3_DSTATE;
            break;
        case 4:
            rtb_Abs_o = DW_tctcdc_Unit_Delay4_DSTATE;
            break;
        case 5:
            rtb_Abs_o = DW_tctcdc_Unit_Delay5_DSTATE;
            break;
        case 6:
            rtb_Abs_o = DW_tctcdc_Unit_Delay6_DSTATE;
            break;
        default:
            rtb_Abs_o = DW_tctcdc_Unit_Delay7_DSTATE;
            break;
        }
        /* End of MultiPortSwitch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Multiport_Switch' */
        /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Constant4'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajCrv_1pm'
                 *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
                 */
        if (((sint32)GET_P_TCTCDC_UseTrajCrv_nu()) != 0) {
            rtb_Switch_mk = GET_S_TPLFBT_TrajTgtCrv_1pm();
        } else {
            rtb_Switch_mk = GET_S_CSCLTA_TgtTrajCrv_1pm();
        }
        /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Switch3/Functionality'/Switch' */
        rtb_Switch_mk = (((((GET_S_LCFRCV_VehVelX_mps() * rtb_Switch_mk) - GET_S_LCFRCV_VehYawRate_rps()) * GET_P_TCTCDC_KMCDeltaPsiAttenu_nu()) - ((rtb_Abs_o - (-GET_S_TPLFBT_CurHeading_rad())) * GET_P_TCTCDC_KMCDeltaPsiObsGain_nu())) * GET_S_LCFRCV_SysCycleTimeVeh_sec()) + rtb_Switch_d;
    }
    /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Switch4/Functionality'/Switch' */
    /* Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Control Deviation Yaw Angle2/Add/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTEST_SObsBeta_rad'
         *  Inport: '<Root>/S_TPLFBT_TrajHeadInclPrev_rad'
         *  Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Sum/Functionality'/Sum'
         *  UnaryMinus: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/Neg2/Functionality'/Unary Minus'
         */
    rtb_Sum_fo = GET_S_TPLFBT_TrajHeadInclPrev_rad() - ((-rtb_Switch_mk) + GET_S_TCTEST_SObsBeta_rad());
    /* RelationalOperator: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/from_data_definition'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    rtb_EQ_i = (uint8)(((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()));
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Freeze delta1'/Unit Delay2' */
    rtb_Abs_o = DW_tctcdc_UnitDelay2_DSTATE;
    /* Product: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter/LOWPASST_RE1/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter/P_TRJCTR_DE_TSteeringAngleFrontAxleEff_sec1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  MinMax: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter/Max/Functionality'/Max'
         */
    rtb_Div = GET_S_LCFRCV_SysCycleTimeVeh_sec() / f32_max_f32_f32 (GET_P_TCTCDC_PT1CurHeadingTime_sec(), GET_S_LCFRCV_SysCycleTimeVeh_sec());
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter'/Unit_Delay2' */
    rtb_Abs = DW_tctcdc_Unit_Delay2_DSTATE_p;
    /* S-Function (sfun_mmv): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter/LOWPASST_RE1/Functionality'/S-Function' */
    if (rtb_Unit_Delay_m != 0U) {
        rtb_SFunction = rtb_Sum_i;
    } else {
        rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Abs, rtb_Sum_i, rtb_Div);
    }
    /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Freeze delta1/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Constant2'/Constant'
         *  Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_MultiportSwitch = rtb_Abs_o;
    } else {
        if (((sint32)GET_P_TCTCDC_UseAltOBFApproach_nu()) != 0) {
            /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Constant3'/Constant'
                         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/P_TCTCDC_OssDeltaTheta_nu'/Constant'
                         *  Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch2/Functionality'/Switch'
                         */
            if (((sint32)rtb_EQ_i) != 0) {
                tmp = 1U;
            } else {
                tmp = GET_P_TCTCDC_OssDeltaTheta_nu();
            }
            /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch3/Functionality'/Switch' */
        } else {
            /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/P_TCTCDC_OssDeltaTheta_nu'/Constant'
                         */
            tmp = GET_P_TCTCDC_OssDeltaTheta_nu();
        }
        /* MultiPortSwitch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC'/Multiport Switch' incorporates:
                 *  Inport: '<Root>/S_TCTEST_PlObsDeltaTheta_rad'
                 */
        switch (tmp) {
        case 1:
            rtb_MultiportSwitch = rtb_Sum_i;
            break;
        case 2:
            rtb_MultiportSwitch = rtb_SFunction;
            break;
        case 3:
            rtb_MultiportSwitch = GET_S_TCTEST_PlObsDeltaTheta_rad();
            break;
        default:
            rtb_MultiportSwitch = rtb_Sum_fo;
            break;
        }
        /* End of MultiPortSwitch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC'/Multiport Switch' */
    }
    /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Freeze delta1/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Enable Output delta1/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Enable Output delta1/Constant6'/Constant'
         */
    if (((sint32)rtb_NE_c) != 0) {
        rtb_Switch_c = rtb_MultiportSwitch;
    } else {
        rtb_Switch_c = 0.0F;
    }
    /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Enable Output delta1/Switch4/Functionality'/Switch' */
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Freeze delta3'/Unit Delay2' */
    rtb_Abs = DW_tctcdc_UnitDelay2_DSTATE_c;
    /* Product: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter1/LOWPASST_RE2/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter1/P_TRJCTR_DE_TSteeringAngleFrontAxleEff_sec2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  MinMax: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter1/Max/Functionality'/Max'
         */
    rtb_Div_c = GET_S_LCFRCV_SysCycleTimeVeh_sec() / f32_max_f32_f32 (GET_P_TCTCDC_PT1CurDistYTime_sec(), GET_S_LCFRCV_SysCycleTimeVeh_sec());
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter1'/Unit_Delay3' */
    rtb_Abs_o = DW_tctcdc_Unit_Delay3_DSTATE_f;
    /* S-Function (sfun_mmv): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter1/LOWPASST_RE2/Functionality'/S-Function' */
    if (rtb_Unit_Delay_m != 0U) {
        rtb_SFunction_b = rtb_Sum;
    } else {
        rtb_SFunction_b = f32_mmv_f32_f32_f32( rtb_Abs_o, rtb_Sum, rtb_Div_c);
    }
    /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Freeze delta3/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Constant'/Constant'
         *  Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_MultiportSwitch1 = rtb_Abs;
    } else {
        if (((sint32)GET_P_TCTCDC_UseAltOBFApproach_nu()) != 0) {
            /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Constant1'/Constant'
                         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/P_TCTCDC_OssDeltaY_nu'/Constant'
                         *  Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch/Functionality'/Switch'
                         */
            if (((sint32)rtb_EQ_i) != 0) {
                rtb_Unit_Delay_m = 1U;
            } else {
                rtb_Unit_Delay_m = GET_P_TCTCDC_OssDeltaY_nu();
            }
            /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch1/Functionality'/Switch' */
        } else {
            /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/P_TCTCDC_OssDeltaY_nu'/Constant'
                         */
            rtb_Unit_Delay_m = GET_P_TCTCDC_OssDeltaY_nu();
        }
        /* MultiPortSwitch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC'/Multiport Switch1' incorporates:
                 *  Inport: '<Root>/S_TCTEST_PlObsDeltaY_met'
                 */
        switch (rtb_Unit_Delay_m) {
        case 1:
            rtb_MultiportSwitch1 = rtb_Sum;
            break;
        case 2:
            rtb_MultiportSwitch1 = rtb_SFunction_b;
            break;
        default:
            rtb_MultiportSwitch1 = GET_S_TCTEST_PlObsDeltaY_met();
            break;
        }
        /* End of MultiPortSwitch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC'/Multiport Switch1' */
    }
    /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Freeze delta3/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Enable Output delta3/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Enable Output delta3/Constant6'/Constant'
         */
    if (((sint32)rtb_NE_c) != 0) {
        rtb_Switch_p = rtb_MultiportSwitch1;
    } else {
        rtb_Switch_p = 0.0F;
    }
    /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Enable Output delta3/Switch4/Functionality'/Switch' */
    /* UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog'/Unit_Delay' */
    rtb_Unit_Delay_m = DW_tctcdc_Unit_Delay_DSTATE_e;
    /* DataTypeConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Logic: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/NEQ/Functionality'/NE'
         */
    rtb_NE_c = (uint8)((((sint32)rtb_Unit_Delay_m) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu())) && (((sint32) GET_S_MCTLFC_ControllingFunction_nu()) != ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu))));
    /* Abs: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Abs/Functionality'/Abs' */
    rtb_Abs = f32_abs_f32(rtb_Switch_p);
    /* Abs: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Abs1/Functionality'/Abs' */
    rtb_Abs_o = f32_abs_f32(rtb_Switch_c);
    /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Constant10'/Constant'
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Constant6'/Constant'
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/P_TCTCDC_WtchdgLimCoAnErr_rad'/Constant'
         *  RelationalOperator: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/GT1/Functionality'/GT'
         */
    if (rtb_Abs_o > GET_P_TCTCDC_WtchdgLimCoAnErr_rad()) {
        rtb_Abs_h = 2;
    } else {
        rtb_Abs_h = 0;
    }
    /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/P_TCTCDC_WtchdgLimYErr_m'/Constant'
         *  RelationalOperator: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/GT/Functionality'/GT'
         */
    rtb_Unit_Delay_m = (uint8)((rtb_Abs > GET_P_TCTCDC_WtchdgLimYErr_m()) + rtb_Abs_h);
    /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/P_TCTCDC_WtchdgActive_nu'/Constant'
         */
    if (((sint32)GET_P_TCTCDC_WtchdgActive_nu()) != 0) {
        /* Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Switch/Functionality'/Switch' */
        if (((sint32)rtb_NE_c) != 0) {
            /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch3'/copy1' */
            SET_S_TCTCDC_QualifierService_nu(rtb_Unit_Delay_m);
        } else {
            /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch3'/copy1' incorporates:
                         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Constant3'/Constant'
                         */
            SET_S_TCTCDC_QualifierService_nu(0U);
        }
        /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Switch/Functionality'/Switch' */
    } else {
        /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch3'/copy1' incorporates:
                 *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Constant4'/Constant'
                 */
        SET_S_TCTCDC_QualifierService_nu(0U);
    }
    /* End of Switch: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/Switch1/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tctcdc_Unit_Delay_DSTATE_p = rtb_EQ;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Determine Reset/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation'/Unit_Delay' */
    DW_tctcdc_Unit_Delay_DSTATE = rtb_Switch_mk;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay1' */
    DW_tctcdc_Unit_Delay1_DSTATE = rtb_Switch_d;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay2' */
    DW_tctcdc_Unit_Delay2_DSTATE = rtb_Unit_Delay1;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay3' */
    DW_tctcdc_Unit_Delay3_DSTATE = rtb_Unit_Delay2;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay4' */
    DW_tctcdc_Unit_Delay4_DSTATE = rtb_Unit_Delay3;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay5' */
    DW_tctcdc_Unit_Delay5_DSTATE = rtb_Unit_Delay4;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay6' */
    DW_tctcdc_Unit_Delay6_DSTATE = rtb_Unit_Delay5;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Delta_Psi_Estimation/KMC_Signal_Delay'/Unit_Delay7' */
    DW_tctcdc_Unit_Delay7_DSTATE = rtb_Unit_Delay6;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Freeze delta1'/Unit Delay2' */
    DW_tctcdc_UnitDelay2_DSTATE = rtb_MultiportSwitch;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter'/Unit_Delay2' */
    DW_tctcdc_Unit_Delay2_DSTATE_p = rtb_SFunction;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/Freeze delta3'/Unit Delay2' */
    DW_tctcdc_UnitDelay2_DSTATE_c = rtb_MultiportSwitch1;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/PT1Filter1'/Unit_Delay3' */
    DW_tctcdc_Unit_Delay3_DSTATE_f = rtb_SFunction_b;
    /* Update for UnitDelay: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog'/Unit_Delay' incorporates:
         *  Update for Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    DW_tctcdc_Unit_Delay_DSTATE_e = GET_S_MCTLFC_ControllingFunction_nu();
    /* End of Outputs for SubSystem: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess'/M_TCTCDC' */
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch'/copy1' */
    SET_S_TCTCDC_CtrlErrDistY_met(rtb_Switch_p);
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch1'/copy1' */
    SET_S_TCTCDC_CtrlErrHeadAgl_rad(rtb_Switch_c);
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch11'/copy1' */
    SET_D_TCTCDC_DeltaYPT1_met(rtb_SFunction_b);
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch12'/copy1' */
    SET_D_TCTCDC_DeltaThetaPT1_rad(rtb_SFunction);
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch14'/copy1' */
    SET_D_TCTCDC_DeltaThetaEsti_rad(rtb_Sum_fo);
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch2'/copy1' */
    SET_S_TCTCDC_CtrlErrHeadAglPrev_rad(rtb_Switch_c);
    /* Outputs for Atomic SubSystem: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess'/M_TCTCDC'
                                                         *
                                                         * Block description for 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess'/M_TCTCDC':
                                                         *  X.2.1
                                                         */
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch22'/copy1' incorporates:
         *  Constant: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/P_TCTCDC_WtchdgActive_nu'/Constant'
         *  DataTypeConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/AND1/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/M_TCTCDC/TCTCDC Watchdog/AND1/Functionality'/AND'
         */
    SET_D_TCTCDC_WatchdogStatus_nu((uint8)((((sint32) GET_P_TCTCDC_WtchdgActive_nu()) != 0) && (((sint32)rtb_NE_c) != 0)));
    /* End of Outputs for SubSystem: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess'/M_TCTCDC' */
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch23'/copy1' */
    SET_D_TCTCDC_QualifierService_nu(rtb_Unit_Delay_m);
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch4'/copy1' */
    SET_D_TCTCDC_DeltaYRaw_met(rtb_Sum);
    /* SignalConversion: 'sda:TCTCDC/TCTCDC/TCTCDC_VehProcess/branch6'/copy1' */
    SET_D_TCTCDC_DeltaThetaRaw_rad(rtb_Sum_i);
}
#include "Pse_TCTCDC.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
