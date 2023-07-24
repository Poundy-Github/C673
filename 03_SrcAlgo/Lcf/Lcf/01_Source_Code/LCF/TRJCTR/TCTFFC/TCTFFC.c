/**************************************************************************
COPYRIGHT (C) $Date: 2020/02/13 11:14:22CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJCTR/TCTFFC_VEH/TCTFFC/i/project.pj $
$Log: TCTFFC.c  $
Revision 1.6.1.3 2020/02/13 11:14:22CET Yoshida, Kohei (uidn0774) 
For input of DynFfcUpDwnHill and DynFfcDecel, use DynFfcGeneral instead of planner curvature
File          : TCTFFC
Generated on  : Thu 13.02.2020 at 18:13:47 (UTC+01:00)
MD5           : [3069004827  2962338637  3637997213  2049892905 0](TCTFFC)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.1012177 (R2016b) Update 7
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,105,106
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TCTFFC.h"
#include "TCTFFC_Private.h"
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
#define TCTFFC_START_SEC_DATA_8
#include "TCTFFC_MemMap.h"
static uint8 DW_tctffc_Unit_Delay_DSTATE_o;
static uint8 DW_tctffc_Unit_Delay3_DSTATE_c;
static uint8 DW_tctffc_Unit_Delay2_DSTATE_j = 3U;
static uint8 DW_tctffc_Unit_Delay_DSTATE_m;
#define TCTFFC_STOP_SEC_DATA_8
#include "TCTFFC_MemMap.h"
#define TCTFFC_START_SEC_DATA_32
#include "TCTFFC_MemMap.h"
static float32 DW_tctffc_Unit_Delay_DSTATE;
static float32 DW_tctffc_Unit_Delay1_DSTATE;
static float32 DW_tctffc_Unit_Delay1_DSTATE_d;
static float32 DW_tctffc_Unit_Delay2_DSTATE;
static float32 DW_tctffc_Unit_Delay3_DSTATE;
static float32 DW_tctffc_Unit_Delay4_DSTATE;
static float32 DW_tctffc_Unit_Delay1_DSTATE_k;
static float32 DW_tctffc_UnitDelay2_DSTATE;
#define TCTFFC_STOP_SEC_DATA_32
#include "TCTFFC_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TCTFFC/TCTFFC/INI'/TCTFFC_VehReset'
 * Block description for: 'sda:TCTFFC/TCTFFC/INI'/TCTFFC_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTFFC_VehReset
#include "Pse_TCTFFC.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTFFC_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TCTFFC/TCTFFC/INI/TCTFFC_VehReset/Constant1'/Constant' */
    SET_D_TCTFFC_DynGainPrecFulfilled_nu(0U);
    /* Constant: 'sda:TCTFFC/TCTFFC/INI/TCTFFC_VehReset/Constant2'/Constant' */
    SET_D_TCTFFC_TrajTgtCrvFilt_1pm(0.0F);
    /* Constant: 'sda:TCTFFC/TCTFFC/INI/TCTFFC_VehReset/Constant3'/Constant' */
    SET_S_TCTFFC_Crv_1pm(0.0F);
    /* Constant: 'sda:TCTFFC/TCTFFC/INI/TCTFFC_VehReset/Constant4'/Constant' */
    SET_D_TCTFFC_DynFfcGeneral_1pm(0.0F);
    /* Constant: 'sda:TCTFFC/TCTFFC/INI/TCTFFC_VehReset/Constant5'/Constant' */
    SET_D_TCTFFC_DynFfcUpDwnHill_1pm(0.0F);
    /* Constant: 'sda:TCTFFC/TCTFFC/INI/TCTFFC_VehReset/Constant6'/Constant' */
    SET_D_TCTFFC_DynFfcDecel_1pm(0.0F);
    /* Constant: 'sda:TCTFFC/TCTFFC/INI/TCTFFC_VehReset/Constant7'/Constant' */
    SET_D_TCTFFC_DynFfc_1pm(0.0F);
    /* Constant: 'sda:TCTFFC/TCTFFC/INI/TCTFFC_VehReset/Constant8'/Constant' */
    SET_D_TCTFFC_DiffMeasEstKappa_1pm(0.0F);
}
#include "Pse_TCTFFC.h"
/* System initialize for function-call system: 'sda:TCTFFC/TCTFFC'/TCTFFC_VehProcess' */
/*
 * Output and update for function-call system: 'sda:TCTFFC/TCTFFC'/TCTFFC_VehProcess'
 * Block description for: 'sda:TCTFFC/TCTFFC'/TCTFFC_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTFFC_VehProcess
#include "Pse_TCTFFC.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTFFC_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Div;
    float32 rtb_SFunction;
    uint8 rtb_NE;
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_VectorConcatenate_h[8];
    uint8 rtb_sfun_setbit_n;
    float32 rtb_MultiportSwitch;
    float32 rtb_Abs;
    float32 rtb_Div_k;
    float32 rtb_Max;
    uint8 rtb_DataTypeConversion_fi;
    uint8 rtb_EQ;
    uint8 rtb_DataTypeConversion_n;
    float32 rtb_Abs_k;
    float32 rtb_Switch_mt;
    uint8 rtb_AND;
    uint8 rtb_DataTypeConversion_c;
    uint8 rtb_DataTypeConversion_j;
    uint8 rtb_DataTypeConversion_g;
    uint8 rtb_Unit_Delay2_b;
    float32 rtb_Mul;
    float32 rtb_Switch_k;
    float32 rtb_Abs_g;
    float32 rtb_Switch_lu;
    float32 rtb_Mul_b;
    float32 rtb_Switch2_p;
    sint32 tmp;
    /* Outputs for Atomic SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess'/M_TCTFFC ' */
    /* Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Abs2/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_TCTEST_KObsKappa_1pm'
         */
    rtb_Div_k = f32_abs_f32(GET_S_TCTEST_KObsKappa_1pm());
    /* MinMax: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant11'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         */
    rtb_Max = f32_max_f32_f32(GET_S_LCFRCV_SysCycleTimeVeh_sec(), GET_P_LCF_AlmostZero_nu());
    /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Low Pass/LOWPASST_RE1/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant10'/Constant'
         *  MinMax: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Low Pass/Max/Functionality'/Max'
         */
    rtb_Div = rtb_Max / f32_max_f32_f32(GET_P_TCTFFC_PT1TgtCrvFiltTime_sec(), rtb_Max);
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Freeze and Enable/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Freeze and Enable/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_NE = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) != ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF)));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Freeze and Enable/Equality/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Freeze and Enable/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) == ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE)));
    /* S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/NOT/Functionality'/NOT'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/OR1/Functionality'/OR'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset'/Unit_Delay'
         */
    rtb_DataTypeConversion_fi = (uint8)(((((sint32) GET_S_TPLCEN_ReplanCurValues_nu()) != 0) || (!(((sint32)rtb_NE) != 0))) || ((((sint32)DW_tctffc_Unit_Delay_DSTATE_o) != 0) && (!(((sint32)rtb_EQ) != 0))));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant12'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit8/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT7/Functionality'/NOT'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit8/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_n = (uint8)(!(((sint32)((uint8)flag_get_u16_u8 (GET_P_TCTFFC_DynGainPrecSelect_btm(), ((uint8)3U)))) != 0));
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR7/Functionality'/OR'
         */
    rtb_DataTypeConversion_n = (uint8)((((sint32)rtb_DataTypeConversion_fi) != 0) || (((sint32)rtb_DataTypeConversion_n) != 0));
    /* UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Low Pass'/Unit_Delay' */
    rtb_Abs_k = DW_tctffc_Unit_Delay_DSTATE;
    /* S-Function (sfun_mmv): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Low Pass/LOWPASST_RE1/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_n != 0U) {
        rtb_SFunction = GET_S_TPLFBT_TrajTgtCrv_1pm();
    } else {
        if (rtb_NE != 0U) {
            rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Abs_k, GET_S_TPLFBT_TrajTgtCrv_1pm(), rtb_Div);
        } else {
            rtb_SFunction = rtb_Abs_k;
        }
    }
    /* Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Abs3/Functionality'/Abs' */
    rtb_Abs_k = f32_abs_f32(rtb_SFunction);
    /* Signum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
        rtb_Mul_b = -1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
        rtb_Mul_b = 1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
        rtb_Mul_b = 0.0F;
    } else {
        rtb_Mul_b = GET_S_TCTCDC_CtrlErrDistY_met();
    }
    /* End of Signum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sign/Functionality'/Sign' */
    /* Signum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sign1/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
         */
    if (GET_S_TPLFBT_TrajTgtCrv_1pm() < 0.0F) {
        rtb_Switch2_p = -1.0F;
    } else if (GET_S_TPLFBT_TrajTgtCrv_1pm() > 0.0F) {
        rtb_Switch2_p = 1.0F;
    } else if (GET_S_TPLFBT_TrajTgtCrv_1pm() == 0.0F) {
        rtb_Switch2_p = 0.0F;
    } else {
        rtb_Switch2_p = GET_S_TPLFBT_TrajTgtCrv_1pm();
    }
    /* End of Signum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sign1/Functionality'/Sign' */
    /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Mul3/Functionality'/Mul' */
    rtb_Switch_mt = rtb_Mul_b * rtb_Switch2_p;
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit2/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT/Functionality'/NOT'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit2/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_n = (uint8)(!(((sint32)((uint8)flag_get_u16_u8 (GET_P_TCTFFC_DynGainPrecSelect_btm(), ((uint8)0U)))) != 0));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/from_data_definition'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_VectorConcatenate[0] = (uint8)(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_VectorConcatenate[1] = (uint8)(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_VectorConcatenate[2] = (uint8)(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDP_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_VectorConcatenate[3] = (uint8)(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_LDPOC_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/EQ4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_VectorConcatenate[4] = (uint8)(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_RDP_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/EQ5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_VectorConcatenate[5] = (uint8)(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/EQ6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_VectorConcatenate[6] = (uint8)(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_AOLC_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/EQ7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_VectorConcatenate[7] = (uint8)(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ESA_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()));
    /* S-Function (sfun_setbit): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/set_bit1/Functionality'/sfun_setbit' */
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
    /* S-Function (sfix_bitop): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/AND/Functionality'/AND' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant1'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/Constant5'/Constant'
         *  S-Function (sfun_setbit): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Controlling Function bitmask/set_bit1/Functionality'/sfun_setbit'
         */
    rtb_AND = (uint8)(((sint32)rtb_sfun_setbit) & ((sint32) GET_P_TCTFFC_DynGainPrecCtrlFcn_btm()));
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_n = (uint8)((((sint32)rtb_DataTypeConversion_n) != 0) || (((sint32)rtb_AND) != 0));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/from_data_definition'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    rtb_VectorConcatenate_h[0] = (uint8)(((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_PASSIVE)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    rtb_VectorConcatenate_h[1] = (uint8)(((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    rtb_VectorConcatenate_h[2] = (uint8)(((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    rtb_VectorConcatenate_h[3] = (uint8)(((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()));
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/EQ4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    rtb_VectorConcatenate_h[4] = (uint8)(((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()));
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/Constant1'/Constant'
         */
    rtb_VectorConcatenate_h[5] = 0U;
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/Constant1'/Constant'
         */
    rtb_VectorConcatenate_h[6] = 0U;
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/Constant1'/Constant'
         */
    rtb_VectorConcatenate_h[7] = 0U;
    /* S-Function (sfun_setbit): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_h[0];
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
        rtb_sfun_setbit_n = temp;
    }
    /* S-Function (sfix_bitop): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/AND1/Functionality'/AND' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant2'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/Constant5'/Constant'
         *  S-Function (sfun_setbit): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Create Lateral Control Mode bitmask/set_bit1/Functionality'/sfun_setbit'
         */
    rtb_AND = (uint8)(((sint32)rtb_sfun_setbit_n) & ((sint32) GET_P_TCTFFC_DynGainPrecCtrlMode_btm()));
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant5'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit1/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR1/Functionality'/OR'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit1/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_c = (uint8)((!(((sint32)((uint8)flag_get_u16_u8 (GET_P_TCTFFC_DynGainPrecSelect_btm(), ((uint8)1U)))) != 0)) || (((sint32) rtb_AND) != 0));
    /* Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_TCTEST_KObsKappa_1pm'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Sum/Functionality'/Sum'
         */
    rtb_Abs = f32_abs_f32(rtb_SFunction - GET_S_TCTEST_KObsKappa_1pm());
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant3'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant6'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit3/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT2/Functionality'/NOT'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/GT/Functionality'/GT'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit3/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_j = (uint8)((!(((sint32)((uint8)flag_get_u16_u8 (GET_P_TCTFFC_DynGainPrecSelect_btm(), ((uint8)2U)))) != 0)) || (rtb_Abs > GET_P_TCTFFC_DynGainPrecThrKappa_1pm()));
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR3/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant4'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant9'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit4/Functionality'/Const_bit_sel_param'
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT3/Functionality'/NOT'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/GT1/Functionality'/GT'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit4/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_g = (uint8)((!(((sint32)((uint8)flag_get_u16_u8 (GET_P_TCTFFC_DynGainPrecSelect_btm(), ((uint8)4U)))) != 0)) || (f32_abs_f32(GET_S_TCTCDC_CtrlErrDistY_met()) > GET_P_TCTFFC_DynGainPreThrDY_met()));
    /* Signum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TCTCLM_DeltaFCmd_deg'
         */
    if (GET_S_TCTCLM_DeltaFCmd_deg() < 0.0F) {
        rtb_Mul_b = -1.0F;
    } else if (GET_S_TCTCLM_DeltaFCmd_deg() > 0.0F) {
        rtb_Mul_b = 1.0F;
    } else if (GET_S_TCTCLM_DeltaFCmd_deg() == 0.0F) {
        rtb_Mul_b = 0.0F;
    } else {
        rtb_Mul_b = GET_S_TCTCLM_DeltaFCmd_deg();
    }
    /* End of Signum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Sign/Functionality'/Sign' */
    /* Signum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Sign1/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
         */
    if (GET_S_TPLFBT_TrajTgtCrv_1pm() < 0.0F) {
        rtb_Switch2_p = -1.0F;
    } else if (GET_S_TPLFBT_TrajTgtCrv_1pm() > 0.0F) {
        rtb_Switch2_p = 1.0F;
    } else if (GET_S_TPLFBT_TrajTgtCrv_1pm() == 0.0F) {
        rtb_Switch2_p = 0.0F;
    } else {
        rtb_Switch2_p = GET_S_TPLFBT_TrajTgtCrv_1pm();
    }
    /* End of Signum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Sign1/Functionality'/Sign' */
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant7'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit5/Functionality'/Const_bit_sel_param'
         *  DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/DTC'/Data Type Conversion'
         *  DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/DTC1'/Data Type Conversion'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT4/Functionality'/NOT'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NEQ/Functionality'/NE'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit5/Functionality'/S-Function'
         */
    rtb_Unit_Delay2_b = (uint8)((!(((sint32)((uint8)flag_get_u16_u8 (GET_P_TCTFFC_DynGainPrecSelect_btm(), ((uint8)5U)))) != 0)) || (((sint32) s8_f32(rtb_Mul_b)) != ((sint32)s8_f32(rtb_Switch2_p))));
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant8'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit6/Functionality'/Const_bit_sel_param'
         *  Inport: '<Root>/D_TPLFBT_UseTargetCorridor_nu'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT5/Functionality'/NOT'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR5/Functionality'/OR'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit6/Functionality'/S-Function'
         */
    rtb_AND = (uint8)((!(((sint32)((uint8)flag_get_u16_u8 (GET_P_TCTFFC_DynGainPrecSelect_btm(), ((uint8)6U)))) != 0)) || (((sint32) GET_D_TPLFBT_UseTargetCorridor_nu()) != 0));
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Abs2/Functionality'/Abs'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant11'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Constant13'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit7/Functionality'/Const_bit_sel_param'
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/AND2/Functionality'/AND'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/NOT6/Functionality'/NOT'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/OR6/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/LT/Functionality'/LT'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/get_bit7/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_n = (uint8)(((((((((sint32)rtb_DataTypeConversion_n) != 0) && (((sint32)rtb_DataTypeConversion_c) != 0)) && (((sint32) rtb_DataTypeConversion_j) != 0)) && (((sint32)rtb_DataTypeConversion_g) != 0)) && (((sint32)rtb_Unit_Delay2_b) != 0)) && (((sint32)rtb_AND) != 0)) && ((!(((sint32)((uint8)flag_get_u16_u8(GET_P_TCTFFC_DynGainPrecSelect_btm(), ((uint8)7U)))) != 0)) || (f32_abs_f32 (GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm()) < GET_P_TCTFFC_DynGainPreThrDriver_Nm())));
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant'/Constant'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/GT/Functionality'/GT'
         */
    rtb_DataTypeConversion_j = (uint8)(((rtb_Div_k > rtb_Abs_k) && (rtb_Switch_mt == 1.0F)) && (((sint32)rtb_DataTypeConversion_n) != 0));
    /* DataTypeConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant1'/Constant'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/GT1/Functionality'/GT'
         */
    rtb_DataTypeConversion_g = (uint8)(((((sint32)rtb_DataTypeConversion_n) != 0) && (rtb_Switch_mt == -1.0F)) && (rtb_Abs_k > rtb_Div_k));
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Constant2'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Constant4'/Constant'
         *  Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Switch6/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_j) != 0) {
        rtb_AND = 1U;
    } else if (((sint32)rtb_DataTypeConversion_g) != 0) {
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Constant3'/Constant'
                 */
        rtb_AND = 2U;
    } else {
        rtb_AND = 3U;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Constant5'/Constant'
         */
    rtb_DataTypeConversion_c = (uint8)(((sint32)rtb_AND) == 3);
    /* S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Constant1'/Constant'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State'/Unit_Delay3'
         */
    if ((!(((sint32)DW_tctffc_Unit_Delay3_DSTATE_c) != 0)) && (((sint32) rtb_DataTypeConversion_c) != 0)) {
        rtb_Switch2_p = GET_P_TCTFFC_DynGainFadingTime_sec();
    } else if (((sint32)rtb_NE) != 0) {
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
                 *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Switch1'
                 *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State'/Unit_Delay1'
                 */
        if (DW_tctffc_Unit_Delay1_DSTATE > rtb_Max) {
            rtb_Switch2_p = DW_tctffc_Unit_Delay1_DSTATE - rtb_Max;
        } else {
            rtb_Switch2_p = 0.0F;
        }
        /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Switch2' */
    } else {
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Switch1' incorporates:
                 *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State'/Unit_Delay1'
                 */
        rtb_Switch2_p = DW_tctffc_Unit_Delay1_DSTATE;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING'/fcg' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State'/Unit_Delay2'
         */
    if (rtb_Switch2_p > 0.0F) {
        rtb_AND = DW_tctffc_Unit_Delay2_DSTATE_j;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant2'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant3'/Constant'
         *  MinMax: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Max2/Functionality'/Max'
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Div/Functionality/Div'/Div'
         */
    rtb_Mul = (1.0F / f32_max_f32_f32(GET_P_TCTFFC_DynGainFadingTime_sec(), rtb_Max)) * rtb_Max;
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Switch1/Functionality'/Switch' incorporates:
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sum2/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Unit_Delay1'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Unit_Delay2'
         */
    if (((sint32)rtb_DataTypeConversion_j) != 0) {
        rtb_Switch_k = DW_tctffc_Unit_Delay1_DSTATE_d + rtb_Mul;
    } else {
        rtb_Switch_k = DW_tctffc_Unit_Delay2_DSTATE - rtb_Mul;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit'/MX'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit/Functionality'/Relational Operator'
         */
    if (1.0F >= rtb_Switch_k) {
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit'/MN'
                 *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit/Functionality'/Relational Operator1'
                 */
        if (!(0.0F <= rtb_Switch_k)) {
            rtb_Switch_k = 0.0F;
        }
        /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit/Functionality'/Switch1' */
    } else {
        rtb_Switch_k = 1.0F;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit/Functionality'/Switch' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Switch3/Functionality'/Switch' incorporates:
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sum3/Functionality'/Sum'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sum4/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Unit_Delay3'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion_g) != 0) {
        rtb_Mul += DW_tctffc_Unit_Delay3_DSTATE;
    } else {
        rtb_Mul = DW_tctffc_Unit_Delay4_DSTATE - rtb_Mul;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit1'/MX'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit1/Functionality'/Relational Operator'
         */
    if (1.0F >= rtb_Mul) {
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit1/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit1'/MN'
                 *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit1/Functionality'/Relational Operator1'
                 */
        if (!(0.0F <= rtb_Mul)) {
            rtb_Mul = 0.0F;
        }
        /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit1/Functionality'/Switch1' */
    } else {
        rtb_Mul = 1.0F;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Limit1/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Multiport Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/get_bit1/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/get_bit2/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant6'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant7'/Constant'
         *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/fading/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/fading1/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/fading/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/fading/Functionality/B_minus_A/Functionality'/Sum'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/fading1/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/fading1/Functionality/B_minus_A/Functionality'/Sum'
         */
    switch (rtb_AND) {
    case 1:
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/get_bit1/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant10'/Constant'
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant4'/Constant'
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant7'/Constant'
                 *  Inport: '<Root>/S_TCTEST_KObsKappa_1pm'
                 *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
                 *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Div2/Functionality/Div'/Div'
                 *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Mul/Functionality'/Mul'
                 *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/get_bit1/Functionality'/S-Function'
                 *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sum/Functionality'/Sum'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTFFC_DynGainMode_btm(), ((uint8)0U)))) != 0) {
            rtb_Mul_b = ((GET_S_TPLFBT_TrajTgtCrv_1pm() * GET_P_TCTFFC_DynGainMaxAdaption_perc()) / 100.0F) + GET_S_TPLFBT_TrajTgtCrv_1pm();
        } else {
            rtb_Mul_b = GET_S_TCTEST_KObsKappa_1pm();
        }
        /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Switch/Functionality'/Switch' */
        rtb_MultiportSwitch = ((rtb_Mul_b - GET_S_TPLFBT_TrajTgtCrv_1pm()) * rtb_Switch_k) + GET_S_TPLFBT_TrajTgtCrv_1pm();
        break;
    case 2:
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/get_bit2/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant11'/Constant'
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant5'/Constant'
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Constant6'/Constant'
                 *  Inport: '<Root>/S_TCTEST_KObsKappa_1pm'
                 *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
                 *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Div1/Functionality/Div'/Div'
                 *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Mul2/Functionality'/Mul'
                 *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/get_bit2/Functionality'/S-Function'
                 *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Sum5/Functionality'/Sum'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTFFC_DynGainMode_btm(), ((uint8)0U)))) != 0) {
            rtb_Mul_b = GET_S_TPLFBT_TrajTgtCrv_1pm() - ((GET_S_TPLFBT_TrajTgtCrv_1pm() * GET_P_TCTFFC_DynGainMaxAdaption_perc()) / 100.0F);
        } else {
            rtb_Mul_b = GET_S_TCTEST_KObsKappa_1pm();
        }
        /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Switch4/Functionality'/Switch' */
        rtb_MultiportSwitch = ((rtb_Mul_b - GET_S_TPLFBT_TrajTgtCrv_1pm()) * rtb_Mul) + GET_S_TPLFBT_TrajTgtCrv_1pm();
        break;
    default:
        rtb_MultiportSwitch = GET_S_TPLFBT_TrajTgtCrv_1pm();
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Multiport Switch' */
    /* Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Abs2/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         */
    rtb_Abs_g = f32_abs_f32(GET_S_LCFRCV_VehAclX_mps2());
    /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Div4/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant7'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/P_TCTFFC_DecelReduction_perc'/Constant'
         */
    rtb_Abs_k = ((float32)GET_P_TCTFFC_DecelReduction_perc()) / 100.0F;
    /* Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Sum8/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant12'/Constant'
         */
    rtb_Div_k = 100.0F - ((float32)GET_P_TCTFFC_UpDwnHllThres_perc());
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant12'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division/Constant18'/Constant'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division/GT/Functionality'/GT'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Sum8/Functionality'/Sum'
         */
    if (!((100.0F - ((float32)GET_P_TCTFFC_UpDwnHllThres_perc())) > GET_P_LCF_AlmostZero_nu())) {
        rtb_Div_k = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division/Switch2/Functionality'/Switch' */
    /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division/Div5/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant16'/Constant'
         */
    rtb_Div_k = 1.0F / rtb_Div_k;
    /* Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Sum6/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant5'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant8'/Constant'
         */
    rtb_Switch_lu = GET_P_TCTFFC_DecelThrsAxEnd_mps2() - GET_P_TCTFFC_DecelThrsAxStart_mps2();
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division1/Switch2/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division1/Abs3/Functionality'/Abs'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division1/Constant18'/Constant'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division1/GT/Functionality'/GT'
         */
    if (!(f32_abs_f32(rtb_Switch_lu) > GET_P_LCF_AlmostZero_nu())) {
        rtb_Switch_lu = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division1/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Abs/Functionality'/Abs'
         *  Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Abs1/Functionality'/Abs'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant6'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant9'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/HYSTERESIS/Functionality'/Relational Operator1'
         *  Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case'/Unit_Delay'
         */
    if (rtb_Abs_g > f32_abs_f32(GET_P_TCTFFC_DecelThrsAxEnd_mps2())) {
        rtb_DataTypeConversion_j = 1U;
    } else if (rtb_Abs_g < f32_abs_f32(GET_P_TCTFFC_DecelHystLSP_mps2())) {
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_DataTypeConversion_j = 0U;
    } else {
        rtb_DataTypeConversion_j = DW_tctffc_Unit_Delay_DSTATE_m;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/HYSTERESIS/Functionality'/Switch3' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant10'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         */
    if (((sint32)rtb_DataTypeConversion_j) != 0) {
        rtb_Abs_g = GET_P_TCTFFC_DecelThrsAxEnd_mps2();
    } else {
        rtb_Abs_g = GET_S_LCFRCV_VehAclX_mps2();
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_fi) == 0) {
        /* Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC'/Unit_Delay1'
                 */
        rtb_Switch_mt = rtb_Abs_g - DW_tctffc_Unit_Delay1_DSTATE_k;
        /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant13'/Constant'
                 */
        rtb_Mul_b = GET_P_TCTFFC_DecelAclXGrdLU_mps3() * rtb_Max;
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC'/Unit_Delay1'
                 */
        if (rtb_Switch_mt > rtb_Mul_b) {
            rtb_Abs_g = rtb_Mul_b + DW_tctffc_Unit_Delay1_DSTATE_k;
        } else {
            /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant14'/Constant'
                         */
            rtb_Max *= GET_P_TCTFFC_DecelAclXGrdLD_mps3();
            /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC'/Unit_Delay1'
                         */
            if (rtb_Switch_mt < rtb_Max) {
                rtb_Abs_g = rtb_Max + DW_tctffc_Unit_Delay1_DSTATE_k;
            }
            /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
        }
        /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant11'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         */
    if (((sint32)GET_P_TCTFFC_DecelModeHyst_nu()) != 0) {
        rtb_Mul_b = rtb_Abs_g;
    } else {
        rtb_Mul_b = GET_S_LCFRCV_VehAclX_mps2();
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Switch1/Functionality'/Switch' */
    /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Mul2/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant3'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant5'/Constant'
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Division1/Div5/Functionality/Div'/Div'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Sum7/Functionality'/Sum'
         */
    rtb_Max = (1.0F / rtb_Switch_lu) * (rtb_Mul_b - GET_P_TCTFFC_DecelThrsAxStart_mps2());
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit1'/MX'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit1/Functionality'/Relational Operator'
         */
    if (1.0F >= rtb_Max) {
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit1/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit1'/MN'
                 *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit1/Functionality'/Relational Operator1'
                 */
        if (!(0.0F <= rtb_Max)) {
            rtb_Max = 0.0F;
        }
        /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit1/Functionality'/Switch1' */
    } else {
        rtb_Max = 1.0F;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit1/Functionality'/Switch' */
    /* Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Sum9/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_UpDownHillDtct_perc'
         */
    tmp = ((sint32)GET_S_ABPLBP_UpDownHillDtct_perc()) - ((sint32) GET_P_TCTFFC_UpDwnHllThres_perc());
    if (tmp < 0) {
        tmp = 0;
    }
    /* Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Mul4/Functionality'/Mul' incorporates:
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Sum9/Functionality'/Sum'
         */
    rtb_Switch_lu = rtb_Div_k * ((float32)tmp);
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit3'/MX'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit3/Functionality'/Relational Operator'
         */
    if (1.0F >= rtb_Switch_lu) {
        /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit3/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit3'/MN'
                 *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit3/Functionality'/Relational Operator1'
                 */
        if (!(0.0F <= rtb_Switch_lu)) {
            rtb_Switch_lu = 0.0F;
        }
        /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit3/Functionality'/Switch1' */
    } else {
        rtb_Switch_lu = 1.0F;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Limit3/Functionality'/Switch' */
    /* Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/fading1/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum' incorporates:
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/fading1/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/fading1/Functionality/B_minus_A/Functionality'/Sum'
         */
    rtb_Max = (((rtb_MultiportSwitch - (rtb_MultiportSwitch * rtb_Abs_k)) - rtb_MultiportSwitch) * rtb_Max) + rtb_MultiportSwitch;
    /* Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/fading3/Functionality/A_plus_F_times_B_minus_A/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant1'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Constant2'/Constant'
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Div2/Functionality/Div'/Div'
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Mul3/Functionality'/Mul'
         *  Product: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/fading3/Functionality/F_times_B_minus_A/Functionality'/Mul'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Sum5/Functionality'/Sum'
         *  Sum: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/fading3/Functionality/B_minus_A/Functionality'/Sum'
         */
    rtb_Div_k = (((rtb_MultiportSwitch - ((((float32) GET_P_TCTFFC_UpDwnHllReduction_perc()) / 100.0F) * rtb_MultiportSwitch)) - rtb_MultiportSwitch) * rtb_Switch_lu) + rtb_MultiportSwitch;
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant3'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /get_bit5/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /get_bit5/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u16_u8(GET_P_TCTFFC_OssDynGain_btm(), ((uint8)0U)))) != 0) {
        rtb_Switch_lu = rtb_MultiportSwitch;
    } else {
        rtb_Switch_lu = 0.15F;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant1'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant5'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /get_bit1/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /get_bit1/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u16_u8(GET_P_TCTFFC_OssDynGain_btm(), ((uint8)1U)))) != 0) {
        rtb_Switch_mt = rtb_Div_k;
    } else {
        rtb_Switch_mt = 0.15F;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch2/Functionality'/Switch' */
    /* Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/Abs1/Functionality'/Abs' */
    rtb_Abs_k = f32_abs_f32(rtb_Switch_mt);
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/Switch5/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/Abs/Functionality'/Abs'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/LT/Functionality'/LT'
         */
    if (!(f32_abs_f32(rtb_Switch_lu) < rtb_Abs_k)) {
        rtb_Switch_lu = rtb_Switch_mt;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant6'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant7'/Constant'
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /get_bit2/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /get_bit2/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u16_u8(GET_P_TCTFFC_OssDynGain_btm(), ((uint8)2U)))) != 0) {
        rtb_Switch_mt = rtb_Max;
    } else {
        rtb_Switch_mt = 0.15F;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch3/Functionality'/Switch' */
    /* Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/Abs2/Functionality'/Abs' */
    rtb_Abs_k = f32_abs_f32(rtb_Switch_mt);
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/Switch6/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/Abs3/Functionality'/Abs'
         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/LT1/Functionality'/LT'
         */
    if (f32_abs_f32(rtb_Switch_lu) < rtb_Abs_k) {
        rtb_Abs_k = rtb_Switch_lu;
    } else {
        rtb_Abs_k = rtb_Switch_mt;
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Seleect absolute minimum/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Freeze kappa/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant9'/Constant'
         *  Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch5/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Freeze kappa'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_lu = DW_tctffc_UnitDelay2_DSTATE;
    } else {
        if (((sint32)GET_P_TCTFFC_UseAltOBFApproach_nu()) != 0) {
            /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant10'/Constant'
                         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant2'/Constant'
                         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /from_data_definition'/state_source'
                         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
                         *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /EQ/Functionality'/EQ'
                         *  Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch5/Functionality'/Switch'
                         */
            if (((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) {
                rtb_DataTypeConversion_fi = 0U;
            } else {
                rtb_DataTypeConversion_fi = GET_P_TCTFFC_OssFfcCrv_nu();
            }
            /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch6/Functionality'/Switch' */
        } else {
            /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch5/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant2'/Constant'
                         */
            rtb_DataTypeConversion_fi = GET_P_TCTFFC_OssFfcCrv_nu();
        }
        /* MultiPortSwitch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC '/Multiport Switch' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant4'/Constant'
                 *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
                 */
        switch (rtb_DataTypeConversion_fi) {
        case 0:
            rtb_Switch_lu = 0.0F;
            break;
        case 1:
            rtb_Switch_lu = GET_S_TPLFBT_TrajTgtCrv_1pm();
            break;
        default:
            /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/D_TPLFBT_UseTargetCorridor_nu'
                         *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
                         */
            if (((sint32)GET_D_TPLFBT_UseTargetCorridor_nu()) != 0) {
                /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Constant8'/Constant'
                                 *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
                                 *  RelationalOperator: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /GT/Functionality'/GT'
                                 */
                if (rtb_Abs_k > 0.14F) {
                    rtb_Switch_lu = GET_S_TPLFBT_TrajTgtCrv_1pm();
                } else {
                    rtb_Switch_lu = rtb_Abs_k;
                }
                /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch4/Functionality'/Switch' */
            } else {
                rtb_Switch_lu = GET_S_TPLFBT_TrajTgtCrv_1pm();
            }
            /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Switch/Functionality'/Switch' */
            break;
        }
        /* End of MultiPortSwitch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC '/Multiport Switch' */
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Freeze kappa/Switch2/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tctffc_Unit_Delay_DSTATE_o = rtb_EQ;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Determine Reset/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Preconditions for the dynamic feedforward gain/Low Pass'/Unit_Delay' */
    DW_tctffc_Unit_Delay_DSTATE = rtb_SFunction;
    /* S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tctffc_Unit_Delay3_DSTATE_c = rtb_DataTypeConversion_c;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State'/Unit_Delay2' */
    DW_tctffc_Unit_Delay2_DSTATE_j = rtb_AND;
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain/Determine State'/Unit_Delay1' */
    DW_tctffc_Unit_Delay1_DSTATE = rtb_Switch2_p;
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Unit_Delay1' */
    DW_tctffc_Unit_Delay1_DSTATE_d = rtb_Switch_k;
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Unit_Delay2' */
    DW_tctffc_Unit_Delay2_DSTATE = rtb_Switch_k;
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Unit_Delay3' */
    DW_tctffc_Unit_Delay3_DSTATE = rtb_Mul;
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the dynamic feedforward gain'/Unit_Delay4' */
    DW_tctffc_Unit_Delay4_DSTATE = rtb_Mul;
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case/Gradient Limiter to avoid jumps in FFC'/Unit_Delay1' */
    DW_tctffc_Unit_Delay1_DSTATE_k = rtb_Abs_g;
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Calculation of the up downhill and deceleration case'/Unit_Delay' */
    DW_tctffc_Unit_Delay_DSTATE_m = rtb_DataTypeConversion_j;
    /* Update for UnitDelay: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Freeze kappa'/Unit Delay2' */
    DW_tctffc_UnitDelay2_DSTATE = rtb_Switch_lu;
    /* Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Enable Output kappa/Switch4/Functionality'/Switch' */
    if (((sint32)rtb_NE) != 0) {
        /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch'/copy1' */
        SET_S_TCTFFC_Crv_1pm(rtb_Switch_lu);
    } else {
        /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch'/copy1' incorporates:
                 *  Constant: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Enable Output kappa/Constant6'/Constant'
                 */
        SET_S_TCTFFC_Crv_1pm(0.0F);
    }
    /* End of Switch: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/M_TCTFFC /Enable Output kappa/Switch4/Functionality'/Switch' */
    /* End of Outputs for SubSystem: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess'/M_TCTFFC ' */
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch1'/copy1' */
    SET_D_TCTFFC_DynGainPrecFulfilled_nu(rtb_DataTypeConversion_n);
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch2'/copy1' */
    SET_D_TCTFFC_DynFfcGeneral_1pm(rtb_MultiportSwitch);
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch3'/copy1' */
    SET_D_TCTFFC_TrajTgtCrvFilt_1pm(rtb_SFunction);
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch4'/copy1' */
    SET_D_TCTFFC_DynFfcUpDwnHill_1pm(rtb_Div_k);
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch5'/copy1' */
    SET_D_TCTFFC_DynFfcDecel_1pm(rtb_Max);
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch6'/copy1' */
    SET_D_TCTFFC_DynFfc_1pm(rtb_Abs_k);
    /* SignalConversion: 'sda:TCTFFC/TCTFFC/TCTFFC_VehProcess/branch7'/copy1' */
    SET_D_TCTFFC_DiffMeasEstKappa_1pm(rtb_Abs);
}
#include "Pse_TCTFFC.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
