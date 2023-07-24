/**************************************************************************
COPYRIGHT (C) $Date: 2020/04/09 14:21:16CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/ODPR/ODPFOP/project.pj $
$Log: ODPFOP.c  $
Revision 1.5.1.1 2020/04/09 14:21:16CEST Craciun, Mihaela (uidl9730) (uidl9730) 
integrate new updates
Revision 1.5 2019/05/22 12:50:51CEST Nastasa, Elena (uidt4846) 
Update LCF for Sprint10
Revision 1.3 2019/05/15 19:49:58CEST Fen, Alexander (TFPE05) 
automatically created
File          : ODPFOP
Generated on  : Mon 13.05.2019 at 17:26:18 (UTC+01:00)
MD5           : [276980881   986483914   453158713  3458898134 0](ODPFOP)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-Core: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "ODPFOP.h"
#include "ODPFOP_private.h"
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
#define ODPFOP_START_SEC_DATA_8
#include "ODPFOP_MemMap.h"
static uint8 DW_odpfop_Unit_Delay_DSTATE_i;
static uint8 DW_odpfop_Unit_Delay5_DSTATE;
static uint8 DW_odpfop_Unit_Delay1_DSTATE_l;
static uint8 DW_odpfop_Unit_Delay2_DSTATE_n;
static uint8 DW_odpfop_Unit_Delay4_DSTATE_f;
static uint8 DW_odpfop_Unit_Delay10_DSTATE;
static uint8 DW_odpfop_Unit_Delay6_DSTATE_d;
static uint8 DW_odpfop_Unit_Delay5_DSTATE_a;
static uint8 DW_odpfop_Unit_Delay4_DSTATE_c;
static uint8 DW_odpfop_Unit_Delay_DSTATE_h;
static uint8 DW_odpfop_Unit_Delay_DSTATE_c;
static uint8 DW_odpfop_Unit_Delay1_DSTATE_g;
#define ODPFOP_STOP_SEC_DATA_8
#include "ODPFOP_MemMap.h"
#define ODPFOP_START_SEC_DATA_32
#include "ODPFOP_MemMap.h"
static float32 BI_odpfop_Div;
/* 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Div/Functionality/Div'/Div' */
static float32 DW_odpfop_Unit_Delay3_DSTATE;
static float32 DW_odpfop_Unit_Delay1_DSTATE;
static float32 DW_odpfop_Unit_Delay2_DSTATE;
static float32 DW_odpfop_Unit_Delay4_DSTATE;
static float32 DW_odpfop_Unit_Delay3_DSTATE_n;
static float32 DW_odpfop_Unit_Delay12_DSTATE;
static float32 DW_odpfop_Unit_Delay9_DSTATE;
static float32 DW_odpfop_Unit_Delay_DSTATE;
static float32 DW_odpfop_Unit_Delay8_DSTATE;
static float32 DW_odpfop_Unit_Delay2_DSTATE_m;
static float32 DW_odpfop_Unit_Delay3_DSTATE_o;
static float32 DW_odpfop_Unit_Delay2_DSTATE_e;
static float32 DW_odpfop_Unit_Delay1_DSTATE_c;
static float32 DW_odpfop_Unit_Delay4_DSTATE_m;
static float32 DW_odpfop_Unit_Delay6_DSTATE;
static float32 DW_odpfop_Unit_Delay_DSTATE_j;
static float32 DW_odpfop_Unit_Delay4_DSTATE_g;
static float32 DW_odpfop_Unit_Delay1_DSTATE_d;
static float32 DW_odpfop_Unit_Delay3_DSTATE_h;
#define ODPFOP_STOP_SEC_DATA_32
#include "ODPFOP_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:ODPFOP/ODPFOP/INI'/ODPFOP_SenReset'
 * Block description for: 'sda:ODPFOP/ODPFOP/INI'/ODPFOP_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_ODPFOP_SenReset
#include "Pse_ODPFOP.h"
/* Short description: Not synchronized with ARAMIS */
void ODPFOP_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant'/Constant' */
    SET_S_ODPFOP_AccObjRelAclX_mps2(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant1'/Constant' */
    SET_S_ODPFOP_AccObjRelVelX_mps(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant10'/Constant' */
    SET_S_ODPFOP_AccObjInvBitfield_btf(0U);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant11'/Constant' */
    SET_S_ODPFOP_AccFRObjTStamp_sec(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant12'/Constant' */
    SET_S_ODPFOP_AccObjRelYawAng_rad(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant2'/Constant' */
    SET_S_ODPFOP_AccObjRelAclY_mps2(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant3'/Constant' */
    SET_S_ODPFOP_AccObjRelVelY_mps(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant4'/Constant' */
    SET_S_ODPFOP_AccObjPosX_met(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant5'/Constant' */
    SET_S_ODPFOP_AccObjPosY_met(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant6'/Constant' */
    SET_S_ODPFOP_AccObjPosXStdDev_met(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant7'/Constant' */
    SET_S_ODPFOP_AccObjPosYStdDev_met(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant8'/Constant' */
    SET_S_ODPFOP_EstimatedObjPosX_met(0.0F);
    /* Constant: 'sda:ODPFOP/ODPFOP/INI/ODPFOP_SenReset/Constant9'/Constant' */
    SET_S_ODPFOP_EstimatedObjPosY_met(0.0F);
}
#include "Pse_ODPFOP.h"
/*
 * Output and update for function-call system: 'sda:ODPFOP/ODPFOP'/ODPFOP_SenProcess'
 * Block description for: 'sda:ODPFOP/ODPFOP'/ODPFOP_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_ODPFOP_SenProcess
#include "Pse_ODPFOP.h"
/* Short description: Not synchronized with ARAMIS */
void ODPFOP_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Div;
    float32 rtb_Unit_Delay9;
    float32 rtb_SFunction;
    float32 rtb_Div_e;
    float32 rtb_Unit_Delay8;
    float32 rtb_SFunction_o;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    uint16 rtb_sfun_setbit;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_sfun_and;
    uint8 rtb_VectorConcatenate1[11];
    uint8 rtb_VectorConcatenate3[13];
    float32 rtb_Sum;
    uint8 rtb_LT_a;
    uint8 rtb_LT_h;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_e;
    uint8 rtb_DataTypeConversion_ju;
    uint8 rtb_GT_n;
    uint8 rtb_DataTypeConversion_fc;
    float32 rtb_Switch;
    float32 rtb_Max;
    float32 rtb_Switch_m;
    uint8 rtb_LogicalOperator_b;
    uint8 rtb_DataTypeConversion_gk;
    uint8 rtb_DataTypeConversion_bv;
    uint8 rtb_GT_p;
    uint8 rtb_DataTypeConversion_mm;
    uint8 rtb_Switch_e;
    uint8 rtb_EQ;
    uint8 rtb_GT_h;
    float32 rtb_Abs;
    float32 rtb_Mul_jy;
    uint8 rtb_VectorConcatenate2[12];
    float32 rtb_Sum_at;
    uint8 rtb_Switch_d;
    float32 rtb_Switch3;
    float32 rtb_Switch7_o;
    float32 rtb_Switch7;
    float32 rtb_Min_c;
    sint32 i;
    /* Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjRelVelX_mps'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_Sum = GET_S_LCFRCV_VehVelX_mps() + GET_S_LCFRCV_AccFRObjRelVelX_mps();
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/LT2/Functionality'/LT' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Constant5'/Constant'
         */
    rtb_LT_a = (uint8)(rtb_Sum < GET_P_ODPFOP_StandstillVelX_mps());
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/LT3/Functionality'/LT' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Constant5'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_LT_h = (uint8)(GET_S_LCFRCV_VehVelX_mps() < GET_P_ODPFOP_StandstillVelX_mps());
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Constant1'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay3'
         */
    rtb_DataTypeConversion = (uint8)(((((sint32)rtb_LT_a) != 0) || (DW_odpfop_Unit_Delay3_DSTATE > 0.0F)) && ((((sint32)rtb_LT_h) != 0) || (DW_odpfop_Unit_Delay1_DSTATE > 0.0F)));
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/EDGEBI'/Functionality'
         */
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjID_nu'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/EDGEBI/Functionality'/Relational Operator'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange'/Unit_Delay'
         */
    rtb_DataTypeConversion_e = (uint8)(!(((sint32)GET_S_LCFRCV_AccFRObjID_nu()) != ((sint32)DW_odpfop_Unit_Delay_DSTATE_i)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/EDGEBI'/fcg' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Constant2'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/logical_value'/Constant'
         */
    if (((sint32)GET_P_ODPFOP_EnableLatMovFreeze_bool()) != 0) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/SRFLIPFLOP/Functionality'/Switch' incorporates:
                 *  Abs: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Abs1/Functionality'/Abs'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Constant15'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Constant3'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/SRFLIPFLOP/Functionality'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality'/Constant1'
                 *  Inport: '<Root>/S_LCFRCV_AccFRObjDetected_bool'
                 *  Inport: '<Root>/S_LCFRCV_AccFRObjPosY_met'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/AND1/Functionality'/AND'
                 *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/AND2/Functionality'/AND'
                 *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/NOT/Functionality'/NOT'
                 *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/NOT1/Functionality'/NOT'
                 *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/GT/Functionality'/GT'
                 *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/GT1/Functionality'/GT'
                 *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/LT1/Functionality'/LT'
                 *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality'/Relational Operator1'
                 *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/SRFLIPFLOP/Functionality'/Switch1'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay2'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay4'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay5'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_Switch_d = 1U;
        } else if ((((!(((sint32)GET_S_LCFRCV_AccFRObjDetected_bool()) != 0)) || (!(((sint32)rtb_DataTypeConversion_e) != 0))) || ((DW_odpfop_Unit_Delay2_DSTATE > 0.0F) && (f32_abs_f32 (GET_S_LCFRCV_AccFRObjPosY_met() - DW_odpfop_Unit_Delay4_DSTATE) < GET_P_ODPFOP_MaxPosYDev_met()))) || ((GET_S_LCFRCV_VehVelX_mps() > GET_P_ODPFOP_DriveoffVelReset_mps()) && (rtb_Sum > GET_P_ODPFOP_DriveoffVelReset_mps()))) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/SRFLIPFLOP/Functionality'/Constant1'
                         */
            rtb_Switch_d = 0U;
        } else {
            rtb_Switch_d = DW_odpfop_Unit_Delay5_DSTATE;
        }
        /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/SRFLIPFLOP/Functionality'/Switch' */
    } else {
        rtb_Switch_d = 0U;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/FreezeLateralKinematics/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/FreezeLateralKinematics/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjRelVelY_mps'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/FreezeLateralKinematics/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_d) != 0) {
        rtb_Sum = 0.0F;
        /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch7'/copy1' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/FreezeLateralKinematics/Constant1'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/FreezeLateralKinematics/Constant2'/Constant'
                 */
        SET_S_ODPFOP_AccObjRelAclY_mps2(0.0F);
    } else {
        rtb_Sum = GET_S_LCFRCV_AccFRObjRelVelY_mps();
        /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch7'/copy1' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AccFRObjRelAclY_mps2'
                 *  Inport: '<Root>/S_LCFRCV_AccFRObjRelVelY_mps'
                 */
        SET_S_ODPFOP_AccObjRelAclY_mps2(GET_S_LCFRCV_AccFRObjRelAclY_mps2());
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/FreezeLateralKinematics/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/AND/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjDetected_bool'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_o = (uint8)((((sint32)rtb_DataTypeConversion_e) != 0) && (((sint32)GET_S_LCFRCV_AccFRObjDetected_bool()) != 0));
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ju = (uint8)(!(((sint32)rtb_DataTypeConversion_e) != 0));
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/DELTAONESTEP1'/Functionality'
         */
    /* Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/DELTAONESTEP1/Functionality/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjDetected_bool'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay2'
         */
    i = ((sint32)GET_S_LCFRCV_AccFRObjDetected_bool()) - ((sint32) DW_odpfop_Unit_Delay2_DSTATE_n);
    if (i < 0) {
        i = 0;
    }
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/OR/Functionality'/OR'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/DELTAONESTEP1/Functionality/Sum/Functionality'/Sum'
         */
    rtb_DataTypeConversion_ju = (uint8)((((sint32)rtb_DataTypeConversion_ju) != 0) || (i != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/DELTAONESTEP1'/fcg' */
    /* MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/Constant7'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Max = f32_max_f32_f32(GET_S_LCFRCV_SysCycleTimeSen_sec(), GET_P_LCF_AlmostZero_nu());
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/STOPWATCH_RE/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/STOPWATCH_RE/Functionality'/Constant6'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/OR3/Functionality'/OR'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/STOPWATCH_RE/Functionality'/Switch3'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay1'
         */
    if ((((sint32)DW_odpfop_Unit_Delay1_DSTATE_l) != 0) || (((sint32) rtb_DataTypeConversion_ju) != 0)) {
        rtb_Switch3 = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/STOPWATCH_RE/Functionality/Sum1/Functionality'/Sum'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay3'
                 */
        rtb_Switch3 = DW_odpfop_Unit_Delay3_DSTATE_n + rtb_Max;
    } else {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay3'
                 */
        rtb_Switch3 = DW_odpfop_Unit_Delay3_DSTATE_n;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/STOPWATCH_RE/Functionality'/Switch2' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL'/IV'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/OR2/Functionality'/OR'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch7'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay4'
         */
    if ((((sint32)DW_odpfop_Unit_Delay4_DSTATE_f) != 0) || (((sint32) rtb_DataTypeConversion_ju) != 0)) {
        rtb_Switch7_o = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch7' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_AccFRObjRelVelX_mps'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality/Mul/Functionality'/Mul'
                 *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality/Add/Functionality'/Sum'
                 *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay12'
                 */
        rtb_Switch7_o = ((GET_S_LCFRCV_VehVelX_mps() + GET_S_LCFRCV_AccFRObjRelVelX_mps()) * rtb_Max) + DW_odpfop_Unit_Delay12_DSTATE;
    } else {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch7' incorporates:
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay12'
                 */
        rtb_Switch7_o = DW_odpfop_Unit_Delay12_DSTATE;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch6' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL'/MN'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL'/MX'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch1'
         */
    if (rtb_Switch7_o >= 300.0F) {
        rtb_Switch7_o = 300.0F;
    } else {
        if (rtb_Switch7_o <= 0.0F) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL'/MN'
                         */
            rtb_Switch7_o = 0.0F;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL/Functionality'/Switch2' */
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Constant4'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Constant6'/Constant'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/GT2/Functionality'/GT'
         */
    rtb_DataTypeConversion_fc = (uint8)((rtb_Switch3 > GET_P_ODPFOP_ObjYawSampleTime_sec()) && (rtb_Switch7_o > GET_P_ODPFOP_ObjYawSampleDist_met()));
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjPosY_met'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay4'
         */
    if (((sint32)rtb_Switch_d) != 0) {
        rtb_Switch = DW_odpfop_Unit_Delay4_DSTATE;
    } else {
        rtb_Switch = GET_S_LCFRCV_AccFRObjPosY_met();
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Constant1'/Constant'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Mul4/Functionality'/Mul'
         */
    rtb_Sum_at = (GET_P_ODPFOP_ObjSyncDelay_sec() * rtb_Sum) + rtb_Switch;
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Constant12'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjPosY_met'
         */
    if (((sint32)GET_P_ODPFOP_UseEstimPosY4Yaw_bool()) != 0) {
        rtb_Switch_m = rtb_Sum_at;
    } else {
        rtb_Switch_m = GET_S_LCFRCV_AccFRObjPosY_met();
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Switch1/Functionality'/Switch' */
    /* Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/LOWPASST_RE2/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Constant5'/Constant'
         *  MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Max1/Functionality'/Max'
         */
    rtb_Div = rtb_Max / f32_max_f32_f32(GET_P_ODPFOP_ObjPosYPT1Time4Yaw_sec(), rtb_Max);
    /* UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay9' */
    rtb_Unit_Delay9 = DW_odpfop_Unit_Delay9_DSTATE;
    /* S-Function (sfun_mmv): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/LOWPASST_RE2/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_ju != 0U) {
        rtb_SFunction = 0.0F;
    } else {
        if (rtb_DataTypeConversion_o != 0U) {
            rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay9, rtb_Switch_m, rtb_Div);
        } else {
            rtb_SFunction = rtb_Unit_Delay9;
        }
    }
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1'/IV'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/OR1/Functionality'/OR'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch7'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay10'
         */
    if ((((sint32)DW_odpfop_Unit_Delay10_DSTATE) != 0) || (((sint32) rtb_DataTypeConversion_ju) != 0)) {
        rtb_Switch7 = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch7' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
                 *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality/Mul/Functionality'/Mul'
                 *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality/Add/Functionality'/Sum'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay'
                 */
        rtb_Switch7 = (rtb_Max * GET_S_LCFRCV_VehYawRate_rps()) + DW_odpfop_Unit_Delay_DSTATE;
    } else {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch7' incorporates:
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay'
                 */
        rtb_Switch7 = DW_odpfop_Unit_Delay_DSTATE;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch6' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1'/MN'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1'/MX'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Relational Operator3'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch1'
         */
    if (rtb_Switch7 >= 3.1415F) {
        rtb_Switch7 = 3.1415F;
    } else {
        if (rtb_Switch7 <= -3.1415F) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1'/MN'
                         */
            rtb_Switch7 = -3.1415F;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/INTEGRATORT_REL1/Functionality'/Switch2' */
    /* Outputs for Enabled SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Enabled_Subsystem' incorporates:
         *  EnablePort: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem'/Enable'
         *
         * Block description for 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Enabled_Subsystem':
         *  X.2.1.4.1
         */
    if (((sint32)rtb_DataTypeConversion_fc) > 0) {
        /* MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Min/Functionality'/Min' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Constant7'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Constant4'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Constant5'/Constant'
                 *  MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Max/Functionality'/Max'
                 *  MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Max/Functionality'/Max'
                 *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Div1/Functionality/Div'/Div'
                 *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Mul1/Functionality'/Mul'
                 *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Mul3/Functionality'/Mul'
                 *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Sum2/Functionality'/Sum'
                 *  Trigonometry: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Trigonom1/Functionality'/Trigonometric Function'
                 *  Trigonometry: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/Trigonom3/Functionality'/Trigonometric Function'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem'/Unit_Delay3'
                 */
        rtb_Min_c = f32_min_f32_f32(f32_max_f32_f32((rtb_SFunction - (DW_odpfop_Unit_Delay3_DSTATE_h * f32_cos_f32(rtb_Switch7))) / f32_max_f32_f32(rtb_Switch7_o - (DW_odpfop_Unit_Delay3_DSTATE_h * f32_sin_f32(rtb_Switch7)), GET_P_LCF_AlmostZero_nu()), -1.0F), 1.0F);
        /* Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Constant'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Constant3'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Constant7'/Constant'
                 *  MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Max1/Functionality'/Max'
                 *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Mul/Functionality'/Mul'
                 *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem/ApproxAtanEq10/Sum1/Functionality'/Sum'
                 */
        BI_odpfop_Div = rtb_Min_c / f32_max_f32_f32(((rtb_Min_c * rtb_Min_c) * 0.28086F) + 1.0F, GET_P_LCF_AlmostZero_nu());
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Enabled_Subsystem'/Unit_Delay3' */
        DW_odpfop_Unit_Delay3_DSTATE_h = rtb_SFunction;
    }
    /* End of Outputs for SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Enabled_Subsystem' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjRelYawAng_rad'
         */
    if (((sint32)GET_P_ODPFOP_UseOwnObjYaw_bool()) != 0) {
        rtb_Switch_m = BI_odpfop_Div;
    } else {
        rtb_Switch_m = GET_S_LCFRCV_AccFRObjRelYawAng_rad();
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Switch/Functionality'/Switch' */
    /* Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/LOWPASST_RE1/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Constant2'/Constant'
         *  MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/Max/Functionality'/Max'
         */
    rtb_Div_e = rtb_Max / f32_max_f32_f32(GET_P_ODPFOP_ObjYawPT1Time_sec(), rtb_Max);
    /* UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay8' */
    rtb_Unit_Delay8 = DW_odpfop_Unit_Delay8_DSTATE;
    /* S-Function (sfun_mmv): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/LOWPASST_RE1/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_ju != 0U) {
        rtb_SFunction_o = 0.0F;
    } else {
        if (rtb_DataTypeConversion_o != 0U) {
            rtb_SFunction_o = f32_mmv_f32_f32_f32( rtb_Unit_Delay8, rtb_Switch_m, rtb_Div_e);
        } else {
            rtb_SFunction_o = rtb_Unit_Delay8;
        }
    }
    /* Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjDetected_bool'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject'/Unit_Delay2'
         */
    rtb_VectorConcatenate1[0] = (uint8)((((sint32) GET_S_LCFRCV_AccFRObjDetected_bool()) != 0) || (DW_odpfop_Unit_Delay2_DSTATE_m > 0.0F));
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectQuality/GE/Functionality'/GE' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectQuality/Constant9'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjQuality_perc'
         */
    rtb_VectorConcatenate1[1] = (uint8)(((sint32) GET_S_LCFRCV_AccFRObjQuality_perc()) >= ((sint32) GET_P_ODPFOP_MinObjQualitiy_perc()));
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Constant'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Constant3'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Constant7'/Constant'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Sum/Functionality'/Sum'
         */
    if (((sint32)GET_P_ODPFOP_ObjRelToRadar_bool()) != 0) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Constant1'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Constant4'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Constant5'/Constant'
                 */
        if (((sint32)GET_P_ODPFOP_RearAxleCoordSys_bool()) != 0) {
            rtb_Switch_m = GET_P_VEH_Wheelbase_met();
        } else {
            rtb_Switch_m = 0.0F;
        }
        /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Switch1/Functionality'/Switch' */
        rtb_Switch_m += GET_P_VEH_OverhangFront_met();
    } else {
        rtb_Switch_m = 0.0F;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/TransformObjectXPosition/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjPosX_met'
         */
    rtb_Min_c = GET_S_LCFRCV_AccFRObjPosX_met() + rtb_Switch_m;
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP1'/Functionality'
         */
    /* Abs: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/Abs/Functionality'/Abs' incorporates:
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP1/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay3'
         */
    rtb_Switch_m = f32_abs_f32(rtb_Min_c - DW_odpfop_Unit_Delay3_DSTATE_o);
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP1'/fcg' */
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/GT1/Functionality'/GT' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/Constant13'/Constant'
         */
    rtb_GT_n = (uint8)(rtb_Switch_m > GET_P_ODPFOP_MaxPosXDev_met());
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_ju = (uint8)((((sint32)rtb_GT_n) != 0) && (((sint32) rtb_DataTypeConversion_e) != 0));
    /* Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay2'
         */
    rtb_LogicalOperator_b = (uint8)((((sint32)rtb_DataTypeConversion_ju) != 0) || (DW_odpfop_Unit_Delay2_DSTATE_e > 0.0F));
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP2'/Functionality'
         */
    /* Abs: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjPosY_met'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP2/Functionality/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay1'
         */
    rtb_Switch_m = f32_abs_f32(GET_S_LCFRCV_AccFRObjPosY_met() - DW_odpfop_Unit_Delay1_DSTATE_c);
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP2'/fcg' */
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/GT2/Functionality'/GT' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/Constant15'/Constant'
         */
    rtb_DataTypeConversion_gk = (uint8)(rtb_Switch_m > GET_P_ODPFOP_MaxPosYDev_met());
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/AND1/Functionality'/AND'
         */
    rtb_DataTypeConversion_bv = (uint8)((((sint32)rtb_DataTypeConversion_e) != 0) && (((sint32)rtb_DataTypeConversion_gk) != 0));
    /* Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay4'
         */
    rtb_GT_p = (uint8)((((sint32)rtb_DataTypeConversion_bv) != 0) || (DW_odpfop_Unit_Delay4_DSTATE_m > 0.0F));
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_mm = (uint8)((((sint32)rtb_LogicalOperator_b) != 0) || (((sint32)rtb_GT_p) != 0));
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/OR2/Functionality'/OR'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay5'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay6'
         */
    rtb_Switch_e = (uint8)(((!(((sint32)DW_odpfop_Unit_Delay6_DSTATE_d) != 0)) && (((sint32)rtb_DataTypeConversion_mm) != 0)) || ((((sint32) DW_odpfop_Unit_Delay5_DSTATE_a) != 0) && (!(((sint32)rtb_DataTypeConversion_e) != 0))));
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1'/fcg' */
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/from_data_definition'/state_source'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjMeasState_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_LCFRCV_AccFRObjMeasState_nu()) == ((sint32) ((uint8)E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_MEASURED)));
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/from_data_definition1'/state_source'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjMeasState_nu'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/NOT/Functionality'/NOT'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/OR/Functionality'/OR'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/OR1/Functionality'/OR'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState'/Unit_Delay4'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState'/Unit_Delay6'
         */
    if ((((sint32)rtb_Switch_e) != 0) || (!((((sint32)rtb_EQ) != 0) || (((sint32) GET_S_LCFRCV_AccFRObjMeasState_nu()) == ((sint32)((uint8) E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_PREDICTED)))))) {
        rtb_GT_h = 0U;
    } else if ((DW_odpfop_Unit_Delay6_DSTATE <= 0.0F) && (((sint32)rtb_EQ) != 0)) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_GT_h = 1U;
    } else {
        rtb_GT_h = DW_odpfop_Unit_Delay4_DSTATE_c;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/RSFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/RSFLIPFLOP/Functionality'/Signal Conversion1'
         */
    DW_odpfop_Unit_Delay4_DSTATE_c = rtb_GT_h;
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation'/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/RSFLIPFLOP/Functionality'/Signal Conversion1'
         */
    rtb_VectorConcatenate1[2] = rtb_GT_h;
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/NOT/Functionality'/NOT'
         */
    rtb_GT_h = (uint8)(!(((sint32)rtb_GT_p) != 0));
    /* Abs: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjPosY_met'
         */
    rtb_Abs = f32_abs_f32(GET_S_LCFRCV_AccFRObjPosY_met());
    /* Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Mul1/Functionality'/Mul' */
    rtb_Mul_jy = rtb_Min_c * rtb_Min_c;
    /* Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjPosY_met'
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Mul/Functionality'/Mul'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Mul2/Functionality'/Mul'
         */
    rtb_Switch_m = ((rtb_Mul_jy * GET_S_LCFRCV_VehCrv_1pm()) * 0.5F) - GET_S_LCFRCV_AccFRObjPosY_met();
    /* Abs: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Abs/Functionality'/Abs' */
    rtb_Switch_m = f32_abs_f32(rtb_Switch_m);
    /* MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Min/Functionality'/Min' */
    rtb_Switch_m = f32_min_f32_f32(rtb_Switch_m, rtb_Abs);
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/AND2/Functionality'/AND'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/AND3/Functionality'/AND'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/NOT1/Functionality'/NOT'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation'/Unit_Delay'
         */
    rtb_GT_p = (uint8)(((((sint32)DW_odpfop_Unit_Delay_DSTATE_h) != 0) && (!((((sint32)rtb_GT_n) != 0) && (((sint32) rtb_DataTypeConversion_gk) != 0)))) && (((sint32)rtb_DataTypeConversion_e) != 0));
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant1'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant11'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant12'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant14'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant15'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant16'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant17'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant18'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant19'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Constant7'/Constant'
         *  DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/OR/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/OR/Functionality'/OR'
         *  MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Max/Functionality'/Max'
         *  MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Max1/Functionality'/Max'
         *  MinMax: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Min1/Functionality'/Min'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Div/Functionality/Div'/Div'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Div1/Functionality/Div'/Div'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Mul3/Functionality'/Mul'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Mul4/Functionality'/Mul'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Mul5/Functionality'/Mul'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Mul6/Functionality'/Mul'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/LT2/Functionality'/LT'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Sum3/Functionality'/Sum'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Sum4/Functionality'/Sum'
         */
    if (((sint32)rtb_GT_p) != 0) {
        rtb_DataTypeConversion_gk = (uint8)((rtb_Abs < ((((f32_min_f32_f32 (GET_P_ODPFOP_MaxSteerAngle_rad() / f32_max_f32_f32 (GET_P_VEH_Wheelbase_met(), GET_P_LCF_AlmostZero_nu()), GET_P_ODPFOP_MaxLatAcl_mps2() / f32_max_f32_f32(GET_P_LCF_AlmostZero_nu(), GET_S_LCFRCV_VehVelX_mps() * GET_S_LCFRCV_VehVelX_mps())) * rtb_Mul_jy) * 0.5F) * GET_P_ODPFOP_FacMaxDistYActive_nu()) + GET_P_ODPFOP_DistYMaxCrvOffset_met())) || (rtb_Switch_m < (GET_P_ODPFOP_MaxDistYHyst_met() + GET_P_ODPFOP_MaxDistY_met())));
    } else {
        rtb_DataTypeConversion_gk = (uint8)(rtb_Switch_m < GET_P_ODPFOP_MaxDistY_met());
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosY/AND/Functionality'/AND'
         */
    rtb_VectorConcatenate1[3] = (uint8)((((sint32)rtb_GT_h) != 0) && (((sint32) rtb_DataTypeConversion_gk) != 0));
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Constant'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Constant3'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Constant8'/Constant'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Sum/Functionality'/Sum'
         */
    if (((sint32)GET_P_ODPFOP_ObjRelToRadar_bool()) != 0) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Constant4'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Constant5'/Constant'
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Constant7'/Constant'
                 */
        if (((sint32)GET_P_ODPFOP_RearAxleCoordSys_bool()) != 0) {
            rtb_Switch_m = GET_P_VEH_Wheelbase_met();
        } else {
            rtb_Switch_m = 0.0F;
        }
        /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Switch1/Functionality'/Switch' */
        rtb_Switch_m += GET_P_VEH_OverhangFront_met();
    } else {
        rtb_Switch_m = 0.0F;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Switch/Functionality'/Switch' */
    /* Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Sum1/Functionality'/Sum' */
    rtb_Abs = rtb_Min_c - rtb_Switch_m;
    /* S-Function Block sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Y_ODPFOP_LongDistMax_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_ODPFOP_LongDistMaxVel_mps */
        FDPS_PTR_F32(GETA_X_ODPFOP_LongDistMaxVel_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_ODPFOP_LongDistMax_met(), &dps_result_ln);
    }
    /* Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Y_ODPFOP_LongDistMax_met/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Y_ODPFOP_LongDistMax_met/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Y_ODPFOP_LongDistMax_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_m = rtb_ip_lookup_fxpt_sfun_7;
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Constant1'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/HYSTERESIS/Functionality'/Constant1'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Sum2/Functionality'/Sum'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX'/Unit_Delay'
         */
    if (rtb_Abs > rtb_Switch_m) {
        rtb_GT_n = 1U;
    } else if (rtb_Abs < (rtb_Switch_m - GET_P_ODPFOP_LongDistMaxHyst_met())) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_GT_n = 0U;
    } else {
        rtb_GT_n = DW_odpfop_Unit_Delay_DSTATE_c;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/HYSTERESIS/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/Constant2'/Constant'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/AND/Functionality'/AND'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/NOT/Functionality'/NOT'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX/GT/Functionality'/GT'
         */
    rtb_VectorConcatenate1[4] = (uint8)((!((((sint32)rtb_LogicalOperator_b) != 0) || (((sint32)rtb_GT_n) != 0))) && (rtb_Abs > 0.1F));
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectWidth/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelX/Constant1'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelX/Constant2'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectWidth/Constant1'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectWidth/Constant2'/Constant'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelX/Sum/Functionality'/Sum'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectWidth/Sum/Functionality'/Sum'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelX/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_GT_p) != 0) {
        rtb_Switch_m = GET_P_ODPFOP_MinWidthTgtObj_met() - GET_P_ODPFOP_MinWidthTgtObjHyst_met();
        rtb_Abs = GET_P_ODPFOP_MaxLongVelHyst_mps() + GET_P_ODPFOP_MaxLongVel_mps();
    } else {
        rtb_Switch_m = GET_P_ODPFOP_MinWidthTgtObj_met();
        rtb_Abs = GET_P_ODPFOP_MaxLongVel_mps();
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectWidth/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectWidth/GT/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjWidth_met'
         */
    rtb_VectorConcatenate1[5] = (uint8)(GET_S_LCFRCV_AccFRObjWidth_met() > rtb_Switch_m);
    /* Abs: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelX/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjRelVelX_mps'
         */
    rtb_Switch_m = f32_abs_f32(GET_S_LCFRCV_AccFRObjRelVelX_mps());
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelX/LT/Functionality'/LT' */
    rtb_VectorConcatenate1[6] = (uint8)(rtb_Switch_m < rtb_Abs);
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelY/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelY/Constant1'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelY/Constant2'/Constant'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelY/Sum/Functionality'/Sum'
         */
    if (((sint32)rtb_GT_p) != 0) {
        rtb_Switch_m = GET_P_ODPFOP_MaxLatVelHyst_mps() + GET_P_ODPFOP_MaxLatVel_mps ();
    } else {
        rtb_Switch_m = GET_P_ODPFOP_MaxLatVel_mps();
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelY/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelY/LT/Functionality'/LT' incorporates:
         *  Abs: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelVelY/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjRelVelY_mps'
         */
    rtb_VectorConcatenate1[7] = (uint8)(f32_abs_f32 (GET_S_LCFRCV_AccFRObjRelVelY_mps()) < rtb_Switch_m);
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelAclX/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelAclX/Constant1'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelAclX/Constant2'/Constant'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelAclX/Sum/Functionality'/Sum'
         */
    if (((sint32)rtb_GT_p) != 0) {
        rtb_Switch_m = GET_P_ODPFOP_MaxLongAclHyst_mps2() + GET_P_ODPFOP_MaxLongAcl_mps2();
    } else {
        rtb_Switch_m = GET_P_ODPFOP_MaxLongAcl_mps2();
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelAclX/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelAclX/LT/Functionality'/LT' incorporates:
         *  Abs: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectRelAclX/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjRelAclX_mps2'
         */
    rtb_VectorConcatenate1[8] = (uint8)(f32_abs_f32 (GET_S_LCFRCV_AccFRObjRelAclX_mps2()) < rtb_Switch_m);
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/from_data_definition'/state_source'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjClassType_nu'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/EQ1/Functionality'/EQ'
         */
    rtb_LogicalOperator_b = (uint8)((((sint32)((uint8) E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_CAR)) == ((sint32) GET_S_LCFRCV_AccFRObjClassType_nu())) || (((sint32) GET_S_LCFRCV_AccFRObjClassType_nu()) == ((sint32)((uint8) E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_TRUCK))));
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification'/Unit_Delay'
         */
    if (((sint32)rtb_GT_p) != 0) {
        rtb_VectorConcatenate1[9] = (uint8)((((sint32)rtb_LogicalOperator_b) != 0) || (DW_odpfop_Unit_Delay_DSTATE_j > 0.0F));
    } else {
        rtb_VectorConcatenate1[9] = rtb_LogicalOperator_b;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/GT1/Functionality'/GT' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/Constant2'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjSensorSource_btf'
         *  S-Function (sfix_bitop): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/AND2/Functionality'/AND'
         */
    rtb_GT_h = (uint8)((((sint32)GET_S_LCFRCV_AccFRObjSensorSource_btf()) & ((sint32)GET_P_ODPFOP_FusionMCamFront_nu())) > 0);
    /* RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/Constant'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjSensorSource_btf'
         *  S-Function (sfix_bitop): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/AND3/Functionality'/AND'
         */
    rtb_GT_p = (uint8)((((sint32)GET_S_LCFRCV_AccFRObjSensorSource_btf()) & ((sint32)GET_P_ODPFOP_FusionRadarFront_nu())) > 0);
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/NOT/Functionality'/NOT'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/OR/Functionality'/OR'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/OR1/Functionality'/OR'
         */
    rtb_Switch_e = (uint8)((((sint32)rtb_Switch_e) != 0) || (!((((sint32) rtb_GT_h) != 0) || (((sint32)rtb_GT_p) != 0))));
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/AND1/Functionality'/AND'
         */
    rtb_GT_p = (uint8)((((sint32)rtb_GT_h) != 0) && (((sint32)rtb_GT_p) != 0));
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/RSFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Constant1'
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion'/Unit_Delay1'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion'/Unit_Delay4'
         */
    if (((sint32)rtb_Switch_e) != 0) {
        rtb_Switch_e = 0U;
    } else if ((DW_odpfop_Unit_Delay4_DSTATE_g <= 0.0F) && (((sint32)rtb_GT_p) != 0)) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_e = 1U;
    } else {
        rtb_Switch_e = DW_odpfop_Unit_Delay1_DSTATE_g;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/RSFLIPFLOP/Functionality'/Switch' */
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation'/ConcatBufferAtVector Concatenate1In11' incorporates:
         *  SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/RSFLIPFLOP/Functionality'/Signal Conversion1'
         */
    rtb_VectorConcatenate1[10] = rtb_Switch_e;
    /* S-Function (sfun_and): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/AND/Functionality'/sfun_and' */
    {
        /*vectorized operation*/
        sint32 i1;
        uint8 temp = rtb_VectorConcatenate1[0];
        for (i1=1; i1 < 11; i1++) {
            temp = temp && rtb_VectorConcatenate1[i1];
        }
        rtb_sfun_and = temp;
    }
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay2'
         */
    if (((sint32)rtb_DataTypeConversion_ju) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/Constant1'/Constant'
                 */
        DW_odpfop_Unit_Delay2_DSTATE_e = GET_P_ODPFOP_PosStepDebounceTime_sec();
    } else {
        if (DW_odpfop_Unit_Delay2_DSTATE_e > 0.0F) {
            /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay2' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Switch2'
                         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay2'
                         */
            DW_odpfop_Unit_Delay2_DSTATE_e -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation'/ConcatBufferAtVector Concatenate2In1' */
    for (i = 0; i < 11; i++) {
        rtb_VectorConcatenate2[i] = rtb_VectorConcatenate1[i];
    }
    /* End of SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation'/ConcatBufferAtVector Concatenate2In1' */
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation'/ConcatBufferAtVector Concatenate2In2' */
    rtb_VectorConcatenate2[11] = rtb_DataTypeConversion_e;
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation'/ConcatBufferAtVector Concatenate3In2' */
    rtb_VectorConcatenate3[12] = rtb_Switch_d;
    /* DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/NOT/Functionality'/NOT'
         */
    for (i = 0; i < 12; i++) {
        rtb_VectorConcatenate3[i] = (uint8)(!(((sint32)rtb_VectorConcatenate2[i]) != 0));
    }
    /* End of DataTypeConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/NOT/Functionality'/Data Type Conversion' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_GT_p) != 0) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion'/Unit_Delay4'
                 */
        if (DW_odpfop_Unit_Delay4_DSTATE_g > 0.0F) {
            /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion'/Unit_Delay4' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_odpfop_Unit_Delay4_DSTATE_g -= rtb_Max;
        }
        /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion'/Unit_Delay4' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/Constant4'/Constant'
                 */
        DW_odpfop_Unit_Delay4_DSTATE_g = GET_P_ODPFOP_MinDurCamFusBefBrid_sec();
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ) != 0) {
        /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState'/Unit_Delay6'
                 */
        if (DW_odpfop_Unit_Delay6_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState'/Unit_Delay6' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_odpfop_Unit_Delay6_DSTATE -= rtb_Max;
        }
        /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState'/Unit_Delay6' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/Constant3'/Constant'
                 */
        DW_odpfop_Unit_Delay6_DSTATE = GET_P_ODPFOP_MinMeasStateForPred_sec();
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMeasurementState/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[13] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate3[0];
                for (i1=0; i1 < 13; i1++) {
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
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjRelVelX_mps'
         */
    SET_S_ODPFOP_AccObjRelVelX_mps(GET_S_LCFRCV_AccFRObjRelVelX_mps());
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch10'/copy1' incorporates:
                                                                          *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Constant1'/Constant'
                                                                          *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Constant2'/Constant'
                                                                          *  Inport: '<Root>/S_LCFRCV_AccFRObjRelAclX_mps2'
                                                                          *  Inport: '<Root>/S_LCFRCV_AccFRObjRelVelX_mps'
                                                                          *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Mul/Functionality'/Mul'
                                                                          *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Mul1/Functionality'/Mul'
                                                                          *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Mul2/Functionality'/Mul'
                                                                          *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Mul3/Functionality'/Mul'
                                                                          *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Sum/Functionality'/Sum'
                                                                          *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/PositionEstimation/Sum2/Functionality'/Sum'
                                                                          */
    SET_S_ODPFOP_EstimatedObjPosX_met((((GET_S_LCFRCV_AccFRObjRelAclX_mps2() * 0.5F) * (GET_P_ODPFOP_ObjSyncDelay_sec() * GET_P_ODPFOP_ObjSyncDelay_sec())) + (GET_S_LCFRCV_AccFRObjRelVelX_mps() * GET_P_ODPFOP_ObjSyncDelay_sec())) + rtb_Min_c);
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch11'/copy1' */
    SET_S_ODPFOP_EstimatedObjPosY_met(rtb_Sum_at);
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch12'/copy1' */
    SET_S_ODPFOP_AccObjRelYawAng_rad(rtb_SFunction_o);
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch2'/copy1' */
    SET_S_ODPFOP_AccObjPosY_met(rtb_Switch);
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch5'/copy1' */
    SET_S_ODPFOP_AccObjPosX_met(rtb_Min_c);
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch6'/copy1' */
    SET_S_ODPFOP_AccObjRelVelY_mps(rtb_Sum);
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch8'/copy1' incorporates:
                                               *  Inport: '<Root>/S_LCFRCV_AccFRObjRelAclX_mps2'
                                               */
    SET_S_ODPFOP_AccObjRelAclX_mps2(GET_S_LCFRCV_AccFRObjRelAclX_mps2());
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch9'/copy1' */
    SET_S_ODPFOP_AccObjInvBitfield_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch3'/copy1' incorporates:
                                                           *  Inport: '<Root>/S_LCFRCV_AccFRObjPosXStdDev_met'
                                                           */
    SET_S_ODPFOP_AccObjPosXStdDev_met(GET_S_LCFRCV_AccFRObjPosXStdDev_met());
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch1'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_LCFRCV_AccFRObjPosYStdDev_met'
                                                                          */
    SET_S_ODPFOP_AccObjPosYStdDev_met(GET_S_LCFRCV_AccFRObjPosYStdDev_met());
    /* Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/Mul/Functionality'/Mul' incorporates:
                                                                          *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/constant_value'/Constant'
                                                                          *  Inport: '<Root>/S_LCFRCV_AccFRObjTStamp_usec'
                                                                          */
    rtb_Abs = ((float32)GET_S_LCFRCV_AccFRObjTStamp_usec()) * 1.0E-6F;
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/Constant13'/Constant'
         *  Product: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/Mul1/Functionality'/Mul'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/GT/Functionality'/GT'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/Sum/Functionality'/Sum'
         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion'/Unit_Delay1'
         */
    if (!((rtb_Abs - DW_odpfop_Unit_Delay1_DSTATE_d) > (0.99F * rtb_Max))) {
        rtb_Abs = rtb_Max + DW_odpfop_Unit_Delay1_DSTATE_d;
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/branch4'/copy1' */
    SET_S_ODPFOP_AccFRObjTStamp_sec(rtb_Abs);
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
                                                *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Constant'
                                                *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Relational Operator'
                                                *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Switch2'
                                                *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay3'
                                                */
    if (((sint32)rtb_LT_a) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay3' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Constant1'/Constant'
                 */
        DW_odpfop_Unit_Delay3_DSTATE = GET_P_ODPFOP_DriveoffDelayTime_sec();
    } else {
        if (DW_odpfop_Unit_Delay3_DSTATE > 0.0F) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay3'
                         *  Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay3'
                         */
            DW_odpfop_Unit_Delay3_DSTATE -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Constant'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay1'
         */
    if (((sint32)rtb_LT_h) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay1' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Constant1'/Constant'
                 */
        DW_odpfop_Unit_Delay1_DSTATE = GET_P_ODPFOP_DriveoffDelayTime_sec();
    } else {
        if (DW_odpfop_Unit_Delay1_DSTATE > 0.0F) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Switch2' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay1'
                         *  Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay1'
                         */
            DW_odpfop_Unit_Delay1_DSTATE -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME1/Functionality'/Switch1' */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/EDGEBI'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange'/Unit_Delay' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjID_nu'
         */
    DW_odpfop_Unit_Delay_DSTATE_i = GET_S_LCFRCV_AccFRObjID_nu();
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/CheckObjectIDChange/EDGEBI'/fcg' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality'/Constant'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay2'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/Constant6'/Constant'
                 */
        DW_odpfop_Unit_Delay2_DSTATE = GET_P_ODPFOP_DriveoffTolTime_sec();
    } else {
        if (DW_odpfop_Unit_Delay2_DSTATE > 0.0F) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality'/Switch2' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay2'
                         *  Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay2'
                         */
            DW_odpfop_Unit_Delay2_DSTATE -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState/TURNOFFDELAYTIME2/Functionality'/Switch1' */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay4' */
    DW_odpfop_Unit_Delay4_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectMovingState'/Unit_Delay5' */
    DW_odpfop_Unit_Delay5_DSTATE = rtb_Switch_d;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay1' */
    DW_odpfop_Unit_Delay1_DSTATE_l = rtb_DataTypeConversion_fc;
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/DELTAONESTEP1'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay2' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjDetected_bool'
         */
    DW_odpfop_Unit_Delay2_DSTATE_n = GET_S_LCFRCV_AccFRObjDetected_bool();
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation/DELTAONESTEP1'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay3' */
    DW_odpfop_Unit_Delay3_DSTATE_n = rtb_Switch3;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay4' */
    DW_odpfop_Unit_Delay4_DSTATE_f = rtb_DataTypeConversion_fc;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay12' */
    DW_odpfop_Unit_Delay12_DSTATE = rtb_Switch7_o;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay9' */
    DW_odpfop_Unit_Delay9_DSTATE = rtb_SFunction;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay10' */
    DW_odpfop_Unit_Delay10_DSTATE = rtb_DataTypeConversion_fc;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay' */
    DW_odpfop_Unit_Delay_DSTATE = rtb_Switch7;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjYawAngEstimation'/Unit_Delay8' */
    DW_odpfop_Unit_Delay8_DSTATE = rtb_SFunction_o;
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AccFRObjDetected_bool'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject'/Unit_Delay2'
         */
    if (((sint32)GET_S_LCFRCV_AccFRObjDetected_bool()) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/Constant6'/Constant'
                 */
        DW_odpfop_Unit_Delay2_DSTATE_m = GET_P_ODPFOP_ObjLossDebounceT_sec();
    } else {
        if (DW_odpfop_Unit_Delay2_DSTATE_m > 0.0F) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject'/Unit_Delay2'
                         *  Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject'/Unit_Delay2'
                         */
            DW_odpfop_Unit_Delay2_DSTATE_m -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/DebounceTargetObject/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP1'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP1/Functionality'/Signal Conversion'
         */
    DW_odpfop_Unit_Delay3_DSTATE_o = rtb_Min_c;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP2'/Functionality'
         */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccFRObjPosY_met'
         */
    DW_odpfop_Unit_Delay1_DSTATE_c = GET_S_LCFRCV_AccFRObjPosY_met();
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/DELTAONESTEP2'/fcg' */
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Constant'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion_bv) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay4' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/Constant1'/Constant'
                 */
        DW_odpfop_Unit_Delay4_DSTATE_m = GET_P_ODPFOP_PosStepDebounceTime_sec();
    } else {
        if (DW_odpfop_Unit_Delay4_DSTATE_m > 0.0F) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Switch2' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay4'
                         *  Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay4'
                         */
            DW_odpfop_Unit_Delay4_DSTATE_m -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/TURNOFFDELAYTIME1/Functionality'/Switch1' */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay6' incorporates:
         *  SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfop_Unit_Delay6_DSTATE_d = rtb_DataTypeConversion_mm;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis'/Unit_Delay5' incorporates:
         *  SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_odpfop_Unit_Delay5_DSTATE_a = rtb_DataTypeConversion_e;
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/CheckForPossibleHysteresis/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation'/Unit_Delay' */
    DW_odpfop_Unit_Delay_DSTATE_h = rtb_sfun_and;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectPosX'/Unit_Delay' */
    DW_odpfop_Unit_Delay_DSTATE_c = rtb_GT_n;
    /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification'/Unit_Delay'
         */
    if (((sint32)rtb_LogicalOperator_b) != 0) {
        /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification'/Unit_Delay' incorporates:
                 *  Constant: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/Constant2'/Constant'
                 */
        DW_odpfop_Unit_Delay_DSTATE_j = GET_P_ODPFOP_ObjTypeDebounceTime_sec();
    } else {
        if (DW_odpfop_Unit_Delay_DSTATE_j > 0.0F) {
            /* Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Sum: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification'/Unit_Delay'
                         *  Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification'/Unit_Delay'
                         */
            DW_odpfop_Unit_Delay_DSTATE_j -= rtb_Max;
        }
    }
    /* End of Switch: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/ValidateObjectTypeClassification/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/ObjectValidation/ValidateACCObject/EvaluateFrontRadarForFusion/RSFLIPFLOP/Functionality'/Signal Conversion1'
         */
    DW_odpfop_Unit_Delay1_DSTATE_g = rtb_Switch_e;
    /* Update for UnitDelay: 'sda:ODPFOP/ODPFOP/ODPFOP_SenProcess/ODPR_TJA/TimestampConversion'/Unit_Delay1' */
    DW_odpfop_Unit_Delay1_DSTATE_d = rtb_Abs;
}
#include "Pse_ODPFOP.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
