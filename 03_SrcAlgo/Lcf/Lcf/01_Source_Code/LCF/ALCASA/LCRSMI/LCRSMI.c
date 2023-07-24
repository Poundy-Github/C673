/**************************************************************************
COPYRIGHT (C) $Date: 2019/12/10 09:51:55CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/ALCASA/LCRSMI_SEN/LCRSMI/i/project.pj $
$Log: LCRSMI.c  $
Revision 1.1.1.8 2019/12/10 09:51:55CET Mariut, Felix (uidp0906) 
automatically created
File          : LCRSMI
Generated on  : Tue 10.12.2019 at 10:14:32 (UTC+01:00)
MD5           : [3889275  3940519781  1974620033  2064579467 0](LCRSMI)
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
#include "LCRSMI.h"
#include "LCRSMI_private.h"
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
/* Named constants for Chart: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM'/StateMachineALCA' */
#define IN_ACTIVE                      ((uint8)1U)
#define IN_DISABLED                    ((uint8)2U)
#define IN_ERROR                       ((uint8)1U)
#define IN_NOT_PRESENT                 ((uint8)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8)0U)
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
#define LCRSMI_START_SEC_DATA_8
#include "LCRSMI_MemMap.h"
static uint8 BI_lcrsmi_SysState_nu;
/* 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM'/StateMachineALCA' */
static uint8 DW_lcrsmi_Unit_Delay_DSTATE_a;
static uint8 DW_lcrsmi_Unit_Delay_DSTATE_b;
static uint8 DW_lcrsmi_Unit_Delay_DSTATE_g;
static uint8 DW_lcrsmi_Unit_Delay_DSTATE_p;
static uint8 DW_lcrsmi_Template_DSTATE;
static uint8 DW_lcrsmi_Unit_Delay1_DSTATE;
static uint8 DW_lcrsmi_Unit_Delay2_DSTATE_m;
static uint8 DW_lcrsmi_UnitDelay5_DSTATE;
static uint8 DW_lcrsmi_Unit_Delay4_DSTATE;
static uint8 DW_lcrsmi_Unit_Delay1_DSTATE_n;
static uint8 DW_lcrsmi_Template_DSTATE_o;
static uint8 DW_lcrsmi_Template1_DSTATE;
static uint8 DW_lcrsmi_Unit_Delay1_DSTATE_f;
static uint8 DW_lcrsmi_Template_DSTATE_a;
static uint8 DW_lcrsmi_Template1_DSTATE_e;
static uint8 DW_lcrsmi_is_active_c3_LCRSMI_cg;
static uint8 DW_lcrsmi_is_c3_LCRSMI_cg;
static uint8 DW_lcrsmi_is_PRESENT;
#define LCRSMI_STOP_SEC_DATA_8
#include "LCRSMI_MemMap.h"
#define LCRSMI_START_SEC_DATA_32
#include "LCRSMI_MemMap.h"
static float32 DW_lcrsmi_Unit_Delay2_DSTATE;
static float32 DW_lcrsmi_UnitDelay1_DSTATE;
static float32 DW_lcrsmi_Unit_Delay_DSTATE;
static float32 DW_lcrsmi_Unit_Delay2_DSTATE_o;
static float32 DW_lcrsmi_UnitDelay1_DSTATE_b;
static float32 DW_lcrsmi_Unit_Delay_DSTATE_e;
static float32 DW_lcrsmi_Unit_Delay_DSTATE_l;
static float32 DW_lcrsmi_Unit_Delay_DSTATE_m;
static float32 DW_lcrsmi_UnitDelay1_DSTATE_j;
static float32 DW_lcrsmi_Unit_Delay3_DSTATE;
static float32 DW_lcrsmi_Unit_Delay_DSTATE_c;
#define LCRSMI_STOP_SEC_DATA_32
#include "LCRSMI_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:LCRSMI/LCRSMI'/LCRSMI_SenReset'
 * Block description for: 'sda:LCRSMI/LCRSMI'/LCRSMI_SenReset'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_LCRSMI_SenReset
#include "Pse_LCRSMI.h"
/* Short description:  */
void LCRSMI_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant1'/Constant' */
    SET_S_LCRSMI_SysStateALCA_nu(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant10'/Constant' */
    SET_S_LCRSMI_SysStateALCARi_nu(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant11'/Constant' */
    SET_D_LCRSMI_DlcLeThreshold_met(0.0F);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant12'/Constant' */
    SET_D_LCRSMI_DlcRiThreshold_met(0.0F);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant13'/Constant' */
    SET_D_LCRSMI_TlcLeThreshold_sec(0.0F);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant14'/Constant' */
    SET_D_LCRSMI_TlcRiThreshold_sec(0.0F);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant2'/Constant' */
    SET_S_LCRSMI_DangerousSide_nu(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant3'/Constant' */
    SET_D_LCRSMI_SysStateALCA_btf(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant4'/Constant' */
    SET_D_LCRSMI_StrongReady_btf(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant5'/Constant' */
    SET_D_LCRSMI_WeakReady_btf(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant6'/Constant' */
    SET_D_LCRSMI_Cancel_btf(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant7'/Constant' */
    SET_S_LCRSMI_ReadyToTrigger_bool(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant8'/Constant' */
    SET_S_LCRSMI_FunctionAborted_bool(0U);
    /* Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenReset/Constant9'/Constant' */
    SET_S_LCRSMI_SysStateALCALe_nu(0U);
}
#include "Pse_LCRSMI.h"
/*
 * Output and update for function-call system: 'sda:LCRSMI/LCRSMI'/LCRSMI_SenProcess'
 * Block description for: 'sda:LCRSMI/LCRSMI'/LCRSMI_SenProcess'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_LCRSMI_SenProcess
#include "Pse_LCRSMI.h"
/* Short description:  */
void LCRSMI_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_UnaryMinus;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_Abs_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_gc;
    float32 rtb_Abs_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_Abs_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_pl;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_Abs_o;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_Abs_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_ph;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_Abs_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_lv;
    float32 rtb_Abs_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_nk;
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_VectorConcatenate_f[8];
    uint8 rtb_VectorConcatenate_b[8];
    uint8 rtb_VectorConcatenate_j[8];
    uint8 rtb_sfun_setbit_n;
    uint8 rtb_sfun_setbit_i;
    uint8 rtb_sfun_setbit_ic;
    uint8 rtb_Switch_kf;
    uint8 rtb_UnitDelay1_o;
    uint8 rtb_EQ_m;
    float32 rtb_Mul;
    uint8 rtb_Switch_h;
    uint8 rtb_GT;
    float32 rtb_Mul_bd;
    uint8 rtb_LT_l1;
    uint8 rtb_EQ_dwy;
    uint8 rtb_EQ_db;
    uint8 rtb_LT_a;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_bd;
    uint8 rtb_EQ_ed;
    uint8 rtb_LT_j;
    uint8 rtb_DataTypeConversion_j;
    uint8 rtb_DataTypeConversion_f4;
    uint8 rtb_EQ_lf;
    uint8 rtb_EQ_bm;
    uint8 rtb_EQ_pu;
    uint8 rtb_DataTypeConversion_kw;
    uint8 rtb_DataTypeConversion_l5;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_DataTypeConversion_m;
    uint8 rtb_EQ_gq;
    uint8 rtb_EQ_ow;
    uint8 rtb_EQ_al;
    uint8 rtb_EQ_bk;
    uint8 rtb_EQ_g5;
    uint8 rtb_EQ_n;
    uint8 rtb_EQ_mc;
    uint8 rtb_UnitDelay2;
    uint8 rtb_DataTypeConversion_ff;
    uint8 rtb_DataTypeConversion_hd;
    uint8 rtb_DataTypeConversion_o3;
    uint8 rtb_EQ_ob;
    uint8 rtb_NE_j3;
    uint8 rtb_NE_c2;
    uint8 rtb_DataTypeConversion_l;
    uint8 rtb_NE_l4;
    uint8 rtb_NE_en;
    uint8 rtb_NE_lh;
    uint8 rtb_NE_lm;
    uint8 rtb_DataTypeConversion_dg;
    uint8 rtb_LogicalOperator_d;
    uint8 rtb_DataTypeConversion_mz;
    uint8 rtb_DataTypeConversion_cy;
    uint8 rtb_EQ_an;
    uint8 rtb_DataTypeConversion_kt;
    uint8 rtb_Switch_d1;
    uint8 rtb_DataTypeConversion_fr;
    float32 rtb_Switch;
    uint8 rtb_S_ODPROP_DanRearObjFOV_RearLe_nu;
    uint8 rtb_S_ODPSOP_DanRearObjBS_RearLe_nu;
    float32 rtb_Switch_ou;
    uint8 rtb_S_ODPROP_DanRearObjFOV_RearRi_nu;
    uint8 rtb_S_ODPSOP_DanRearObjBS_RearRi_nu;
    float32 rtb_Switch2_p;
    float32 rtb_Switch2_p4;
    float32 rtb_Switch2_hq;
    uint8 rtb_Switch_l;
    uint8 rtb_Switch_aq;
    float32 rtb_Switch_c;
    float32 rtb_Switch2_i;
    float32 rtb_Switch_lu;
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/ALCASwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/ALCASwitch/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/ALCASwitch/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ALCASwitch_bool'
         */
    if (((sint32)GET_P_LCRSMI_ALCASwitchEnable_bool()) != 0) {
        rtb_Switch_kf = GET_S_LCFRCV_ALCASwitch_bool();
    } else {
        rtb_Switch_kf = GET_P_LCRSMI_ALCASwitch_bool();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/ALCASwitch/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_Switch_kf;
    /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_LCRSMI_VXMD1TrigDlc_met(), &x_dps);
    }
    /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_LCRSIA_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D (GETA_Y_LCRSMI_LWTrigDlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Divide1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_LCRSIA_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul = rtb_ip_lookup_fxpt_sfun_7 * rtb_ip_lookup_fxpt_sfun_7_n;
    /* UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Neg4/Functionality'/Unary Minus' incorporates:
         *  Inport: '<Root>/S_LCRSIA_VelLatLeALCA_mps'
         */
    rtb_UnaryMinus = -GET_S_LCRSIA_VelLatLeALCA_mps();
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/LaneBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/LaneBoundaryInterface/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         */
    if (((sint32)GET_P_LCRSIA_SafetyIfaceALCAOn_bool()) != 0) {
        rtb_Switch = GET_S_ABPLBP_LeLnClthCrvSIF_1pm();
    } else {
        rtb_Switch = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/LaneBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/from_data_definition'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_CUSTOM_ALCADlcTrgLe_met'
         *  Inport: '<Root>/S_LCRSIA_CurveTypeLe_enum'
         *  Product: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Divide3/Functionality'/Mul'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/EQ1/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Sum/Functionality'/Sum'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch1/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch2/Functionality'/Switch'
         */
    if (((sint32)GET_P_ALCA_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_c = GET_S_CUSTOM_ALCADlcTrgLe_met();
    } else {
        if (((sint32)GET_S_LCRSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Abs2/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Abs_f = f32_abs_f32(rtb_Switch);
            /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_f, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_lv = F32_PTR_IP1D (GETA_Y_LCRSMI_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_c = -rtb_ip_lookup_fxpt_sfun_7_lv;
        } else if (((sint32)GET_S_LCRSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Abs1/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch2/Functionality'/Switch'
                         */
            rtb_Abs_p = f32_abs_f32(rtb_Switch);
            /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_p, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_nk = F32_PTR_IP1D (GETA_Y_LCRSMI_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_c = rtb_ip_lookup_fxpt_sfun_7_nk;
        } else {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Constant8'/Constant'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_c = 0.0F;
        }
        /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_LCRSMI_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Switch_c += rtb_Mul * rtb_ip_lookup_fxpt_sfun_7_m;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant5'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant6'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant9'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition1'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition2'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_LCRSIA_DlcLeALCA_met'
         *  Inport: '<Root>/S_LCRSIA_LnBndLeValidALCA_bool'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND8/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND9/Functionality'/AND'
         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Sum/Functionality'/Sum'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs'/Unit Delay1'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay'
         */
    if ((((((((((sint32)GET_P_LCRSMI_SafeSituationState_btm()) & 1) != 0) & (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) != 0) || ((((((sint32)GET_P_LCRSMI_SafeSituationState_btm()) & 2) != 0) & (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) != 0)) || ((((((sint32)GET_P_LCRSMI_SafeSituationState_btm()) & 4) != 0) & (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)))) != 0)) || ((((((sint32)GET_P_LCRSMI_SafeSituationState_btm()) & 8) != 0) & ((sint32) GET_S_ABPLBP_LaneChangeDetected_bool())) != 0)) || ((((((sint32) GET_P_LCRSMI_SafeSituationState_btm()) & 16) != 0) & (!(((sint32) GET_S_LCRSIA_LnBndLeValidALCA_bool()) != 0))) != 0)) {
        rtb_Switch_h = 0U;
    } else if (GET_S_LCRSIA_DlcLeALCA_met() > (rtb_Switch_c + GET_P_LCRSMI_SafeSituationOffset_met())) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_h = 1U;
    } else {
        rtb_Switch_h = DW_lcrsmi_Unit_Delay_DSTATE_a;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_LCRSIA_DlcLeALCA_met'
         */
    rtb_GT = (uint8)(GET_S_LCRSIA_DlcLeALCA_met() > GET_P_LCRSMI_DlcLimitMin_met ());
    /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_VXTrigTlc_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D(GETA_Y_LCRSMI_VXTrigTlc_sec(), &x_dps);
    }
    /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_LCRSIA_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_LCRSMI_LWTrigTlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Divide1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_LCRSIA_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_VXTrigTlc_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul_bd = rtb_ip_lookup_fxpt_sfun_7_k * rtb_ip_lookup_fxpt_sfun_7_j;
    /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_LCRSMI_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/from_data_definition'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCRSIA_CurveTypeLe_enum'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/EQ1/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Neg1/Functionality'/Unary Minus'
         */
    if (((sint32)GET_S_LCRSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
        /* Abs: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Abs2/Functionality'/Abs' */
        rtb_Abs_m = f32_abs_f32(rtb_Switch);
        /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_m, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_LCRSMI_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch = -rtb_ip_lookup_fxpt_sfun_7_p;
    } else if (((sint32)GET_S_LCRSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
        /* Abs: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Abs1/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch2/Functionality'/Switch'
                 */
        rtb_Abs_l = f32_abs_f32(rtb_Switch);
        /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_l, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_pl = F32_PTR_IP1D (GETA_Y_LCRSMI_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch = rtb_ip_lookup_fxpt_sfun_7_pl;
    } else {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Constant8'/Constant'
                 */
        rtb_Switch = 0.0F;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Sum/Functionality'/Sum' incorporates:
         *  Product: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Divide3/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch += rtb_Mul_bd * rtb_ip_lookup_fxpt_sfun_7_g;
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/LT2/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_LCRSIA_TlcLeALCA_sec'
         */
    rtb_LT_l1 = (uint8)(GET_S_LCRSIA_TlcLeALCA_sec() < rtb_Switch);
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_ALCADlcLimitLe_met'
         */
    if (((sint32)GET_P_ALCA_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_lu = (float32)GET_S_CUSTOM_ALCADlcLimitLe_met();
    } else {
        rtb_Switch_lu = GET_P_LCRSMI_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Application Parameter4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant11'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant5'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant9'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCRSIA_DlcLeALCA_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator5/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Relational Operator/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND4/Functionality'/AND'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic'/Unit Delay1'
         */
    rtb_EQ_dwy = (uint8)((GET_S_LCRSIA_DlcLeALCA_met() < rtb_Switch_lu) && ((((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 1) != 0) && (GET_S_LCRSIA_DlcLeALCA_met() < rtb_Switch_c)) || ((((((sint32) GET_P_LCRSMI_TriggerCondEnable_btm()) & 2) != 0) && (GET_S_LCRSIA_DlcLeALCA_met() < GET_P_LCRSMI_TlcDistanceMin_met())) && ((DW_lcrsmi_UnitDelay1_DSTATE <= 0.0F) && (((sint32)rtb_LT_l1) != 0)))));
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant12'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant19'/Constant'
         *  Inport: '<Root>/S_LCRSIA_SideCondALCALe_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND9/Functionality'/AND'
         */
    rtb_EQ_m = (uint8)((((sint32)GET_S_LCRSIA_SideCondALCALe_btf()) & 1) == 1);
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant4'/Constant'
         *  Inport: '<Root>/S_ODPROP_OIQualifierFlag_RearLe_nu'
         */
    if (((sint32)GET_P_LCRSMI_BypassSRRSignal_bool()) != 0) {
        rtb_S_ODPROP_DanRearObjFOV_RearRi_nu = GET_P_LCRSMI_BVQualifRearLe_bool();
    } else {
        rtb_S_ODPROP_DanRearObjFOV_RearRi_nu = GET_S_ODPROP_OIQualifierFlag_RearLe_nu();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant15'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant17'/Constant'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch12/Functionality'/Switch'
         */
    if (((sint32)rtb_S_ODPROP_DanRearObjFOV_RearRi_nu) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant3'/Constant'
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant5'/Constant'
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant7'/Constant'
                 *  Inport: '<Root>/S_ODPROP_DanRearObjFOV_RearLe_nu'
                 *  Inport: '<Root>/S_ODPSOP_DanRearObjBS_RearLe_nu'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch5/Functionality'/Switch'
                 */
        if (((sint32)GET_P_LCRSMI_BypassSRRSignal_bool()) != 0) {
            rtb_S_ODPROP_DanRearObjFOV_RearLe_nu = GET_P_LCRSMI_BVDanRearObjFOVRearLe_bool();
            rtb_S_ODPSOP_DanRearObjBS_RearLe_nu = GET_P_LCRSMI_BVDanRearObjBSRearLe_bool();
        } else {
            rtb_S_ODPROP_DanRearObjFOV_RearLe_nu = GET_S_ODPROP_DanRearObjFOV_RearLe_nu();
            rtb_S_ODPSOP_DanRearObjBS_RearLe_nu = GET_S_ODPSOP_DanRearObjBS_RearLe_nu();
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch3/Functionality'/Switch' */
    } else {
        rtb_S_ODPROP_DanRearObjFOV_RearLe_nu = 0U;
        rtb_S_ODPSOP_DanRearObjBS_RearLe_nu = 0U;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant13'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant14'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant6'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm5'/Constant'
         *  DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/OR/Functionality'/Data Type Conversion'
         *  DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/OR1/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_LCFRCV_BSD_ActiveLeft_nu'
         *  Inport: '<Root>/S_LCFRCV_BSD_WarningLeft_nu'
         *  Inport: '<Root>/S_LCFRCV_LCA_ActiveLeft_nu'
         *  Inport: '<Root>/S_LCFRCV_LCA_WarningLeft_nu'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND8/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator8/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/OR/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NEQ5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND7/Functionality'/AND'
         */
    if (((sint32)GET_P_LCRSMI_ALCALightEnable_bool()) != 0) {
        rtb_LT_a = (uint8)((((((sint32)GET_S_LCFRCV_LCA_ActiveLeft_nu()) != 0) && (((sint32)GET_S_LCFRCV_LCA_WarningLeft_nu()) != 0)) && ((((sint32) GET_P_LCRSMI_TriggerCondEnable_btm()) & 4) != 0)) || ((((((sint32) GET_P_LCRSMI_TriggerCondEnable_btm()) & 8) != 0) && (((sint32) GET_S_LCFRCV_BSD_WarningLeft_nu()) != 0)) && (((sint32) GET_S_LCFRCV_BSD_ActiveLeft_nu()) != 0)));
    } else {
        rtb_LT_a = (uint8)(((((sint32)rtb_S_ODPROP_DanRearObjFOV_RearLe_nu) != 0) && ((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 4) != 0)) || ((((sint32)rtb_S_ODPSOP_DanRearObjBS_RearLe_nu) != 0) && ((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 8) != 0)));
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant15'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant16'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm4'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator6/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND10/Functionality'/AND'
         */
    rtb_EQ_db = (uint8)(((((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 16) != 0) && (((sint32)rtb_EQ_dwy) != 0)) && (!(((sint32)rtb_EQ_m) != 0))) && (((sint32)rtb_LT_a) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Constant12'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm6'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Logical Operator9/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/NEQ7/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/AND5/Functionality'/AND'
         */
    rtb_LT_a = (uint8)((((((sint32)rtb_EQ_dwy) != 0) && (((sint32)rtb_EQ_m) != 0)) && ((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 32) != 0)) && (((sint32)rtb_LT_a) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/OR2/Functionality'/OR'
         */
    rtb_DataTypeConversion = (uint8)((((sint32)rtb_EQ_db) != 0) || (((sint32) rtb_LT_a) != 0));
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant6'/Constant'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit_Delay'
         */
    if (((sint32)rtb_GT) >= 1) {
        rtb_Switch2_i = DW_lcrsmi_Unit_Delay_DSTATE;
    } else {
        rtb_Switch2_i = 0.0F;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter5'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising'/Unit_Delay'
         */
    if ((!(((sint32)DW_lcrsmi_Unit_Delay_DSTATE_b) != 0)) && (((sint32) rtb_DataTypeConversion) != 0)) {
        rtb_Switch2_i = GET_P_LCRSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT) != 0) {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_i > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_i -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_i = 0.0F;
            }
            /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Constant1'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_LCRSIA_SideCondALCALe_btf'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator4/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND5/Functionality'/AND'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2'
         */
    rtb_DataTypeConversion_bd = (uint8)(((((DW_lcrsmi_Unit_Delay2_DSTATE <= 0.0F) && (((sint32)rtb_Switch_h) != 0)) && ((((sint32)rtb_GT) != 0) && (rtb_Switch2_i > 0.0F))) && ((((sint32)GET_S_LCRSIA_SideCondALCALe_btf()) & ((sint32) GET_P_LCRSMI_SideCondEnable_btm())) == 0)) && ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_LCRSMI_FctCustomTrgLe_btm())) == 0));
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/LaneBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/LaneBoundaryInterface/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    if (((sint32)GET_P_LCRSIA_SafetyIfaceALCAOn_bool()) != 0) {
        rtb_Switch_ou = GET_S_ABPLBP_RiLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_ou = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/LaneBoundaryInterface/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Application Parameter4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/from_data_definition2'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_CUSTOM_ALCADlcTrgRi_met'
         *  Inport: '<Root>/S_LCRSIA_CurveTypeRi_enum'
         *  Inport: '<Root>/S_LCRSIA_VelLatRiALCA_mps'
         *  Product: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Divide4/Functionality'/Mul'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/EQ3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu2/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Sum1/Functionality'/Sum'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch5/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch6/Functionality'/Switch'
         */
    if (((sint32)GET_P_ALCA_DlcTriggerCustom_bool()) != 0) {
        rtb_Mul = GET_S_CUSTOM_ALCADlcTrgRi_met();
    } else {
        if (((sint32)GET_S_LCRSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Abs3/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_o = f32_abs_f32(rtb_Switch_ou);
            /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_o, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D (GETA_Y_LCRSMI_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_lu = -rtb_ip_lookup_fxpt_sfun_7_f;
        } else if (((sint32)GET_S_LCRSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Abs4/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch5/Functionality'/Switch'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch6/Functionality'/Switch'
                         */
            rtb_Abs_c = f32_abs_f32(rtb_Switch_ou);
            /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_c, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_ph = F32_PTR_IP1D (GETA_Y_LCRSMI_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_lu = rtb_ip_lookup_fxpt_sfun_7_ph;
        } else {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Constant9'/Constant'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Switch_lu = 0.0F;
        }
        /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_LCRSIA_VelLatRiALCA_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_LCRSMI_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Mul = (rtb_Mul * rtb_ip_lookup_fxpt_sfun_7_c) + rtb_Switch_lu;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/DLCThresholds/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant5'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant6'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant9'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition1'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition2'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_LCRSIA_DlcRiALCA_met'
         *  Inport: '<Root>/S_LCRSIA_LnBndRiValidALCA_bool'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND3/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND5/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND6/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND8/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND9/Functionality'/AND'
         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Sum/Functionality'/Sum'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch1'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg2/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs'/Unit Delay1'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_LCRSMI_SafeSituationState_btm()) & 1) != 0) && (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_LCRSMI_SafeSituationState_btm()) & 2) != 0) && (((sint32) BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_LCRSMI_SafeSituationState_btm()) & 4) != 0) && (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_LCRSMI_SafeSituationState_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_LCRSMI_SafeSituationState_btm()) & 16) != 0) && (!(((sint32) GET_S_LCRSIA_LnBndRiValidALCA_bool()) != 0)))) {
        rtb_UnitDelay1_o = 0U;
    } else if (GET_S_LCRSIA_DlcRiALCA_met() < ((-rtb_Mul) - GET_P_LCRSMI_SafeSituationOffset_met())) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_UnitDelay1_o = 1U;
    } else {
        rtb_UnitDelay1_o = DW_lcrsmi_Unit_Delay_DSTATE_g;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_LCRSIA_DlcRiALCA_met'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg1/Functionality'/Unary Minus'
         */
    rtb_LT_j = (uint8)(GET_S_LCRSIA_DlcRiALCA_met() < (-GET_P_LCRSMI_DlcLimitMin_met()));
    /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu2/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_LCRSIA_VelLatRiALCA_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_LCRSMI_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/from_data_definition2'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_LCRSIA_CurveTypeRi_enum'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/EQ3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Neg2/Functionality'/Unary Minus'
         */
    if (((sint32)GET_S_LCRSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
        /* Abs: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Abs3/Functionality'/Abs' */
        rtb_Abs = f32_abs_f32(rtb_Switch_ou);
        /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_LCRSMI_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_ou = -rtb_ip_lookup_fxpt_sfun_7_l;
    } else if (((sint32)GET_S_LCRSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
        /* Abs: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Abs4/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch6/Functionality'/Switch'
                 */
        rtb_Abs_h = f32_abs_f32(rtb_Switch_ou);
        /* S-Function Block sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_h, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_gc = F32_PTR_IP1D (GETA_Y_LCRSMI_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_ou = rtb_ip_lookup_fxpt_sfun_7_gc;
    } else {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Constant9'/Constant'
                 */
        rtb_Switch_ou = 0.0F;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCRSIA_VelLatRiALCA_mps'
         *  Product: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Divide4/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/TLCThresholds/Y_LCRSMI_LWTrigDlcScalFact_nu2/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_ou += rtb_Mul_bd * rtb_ip_lookup_fxpt_sfun_7_b;
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/LT2/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_LCRSIA_TlcRiALCA_sec'
         */
    rtb_LT_a = (uint8)(GET_S_LCRSIA_TlcRiALCA_sec() < rtb_Switch_ou);
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_ALCADlcLimitRi_met'
         */
    if (((sint32)GET_P_ALCA_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_lu = (float32)GET_S_CUSTOM_ALCADlcLimitRi_met();
    } else {
        rtb_Switch_lu = GET_P_LCRSMI_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Constant1'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Application Parameter4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant11'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant5'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant9'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm7'/Constant'
         *  Inport: '<Root>/S_LCRSIA_DlcRiALCA_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator5/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NEQ1/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND4/Functionality'/AND'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Neg3/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic'/Unit Delay1'
         */
    rtb_EQ_ed = (uint8)((GET_S_LCRSIA_DlcRiALCA_met() > (-rtb_Switch_lu)) && ((((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 1) != 0) && (GET_S_LCRSIA_DlcRiALCA_met() > (-rtb_Mul))) || ((((((sint32) GET_P_LCRSMI_TriggerCondEnable_btm()) & 2) != 0) && (GET_S_LCRSIA_DlcRiALCA_met() > (-GET_P_LCRSMI_TlcDistanceMin_met()))) && ((DW_lcrsmi_UnitDelay1_DSTATE_b <= 0.0F) && (((sint32)rtb_LT_a) != 0)))));
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant12'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant19'/Constant'
         *  Inport: '<Root>/S_LCRSIA_SideCondALCARi_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND9/Functionality'/AND'
         */
    rtb_EQ_db = (uint8)((((sint32)GET_S_LCRSIA_SideCondALCARi_btf()) & 1) == 1);
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant9'/Constant'
         *  Inport: '<Root>/S_ODPROP_OIQualifierFlag_RearRi_nu'
         */
    if (((sint32)GET_P_LCRSMI_BypassSRRSignal_bool()) != 0) {
        rtb_S_ODPROP_DanRearObjFOV_RearRi_nu = GET_P_LCRSMI_BVQualifRearRi_bool();
    } else {
        rtb_S_ODPROP_DanRearObjFOV_RearRi_nu = GET_S_ODPROP_OIQualifierFlag_RearRi_nu();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant20'/Constant'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch13/Functionality'/Switch'
         */
    if (((sint32)rtb_S_ODPROP_DanRearObjFOV_RearRi_nu) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant11'/Constant'
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant13'/Constant'
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Constant9'/Constant'
                 *  Inport: '<Root>/S_ODPROP_DanRearObjFOV_RearRi_nu'
                 *  Inport: '<Root>/S_ODPSOP_DanRearObjBS_RearRi_nu'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch10/Functionality'/Switch'
                 */
        if (((sint32)GET_P_LCRSMI_BypassSRRSignal_bool()) != 0) {
            rtb_S_ODPROP_DanRearObjFOV_RearRi_nu = GET_P_LCRSMI_BVDanRearObjFOVRearRi_bool();
            rtb_S_ODPSOP_DanRearObjBS_RearRi_nu = GET_P_LCRSMI_BVDanRearObjBSRearRi_bool();
        } else {
            rtb_S_ODPROP_DanRearObjFOV_RearRi_nu = GET_S_ODPROP_DanRearObjFOV_RearRi_nu();
            rtb_S_ODPSOP_DanRearObjBS_RearRi_nu = GET_S_ODPSOP_DanRearObjBS_RearRi_nu();
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch8/Functionality'/Switch' */
    } else {
        rtb_S_ODPROP_DanRearObjFOV_RearRi_nu = 0U;
        rtb_S_ODPSOP_DanRearObjBS_RearRi_nu = 0U;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SRRSignals/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant13'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant14'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant6'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm5'/Constant'
         *  DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/OR/Functionality'/Data Type Conversion'
         *  DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/OR1/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_LCFRCV_BSD_ActiveRight_nu'
         *  Inport: '<Root>/S_LCFRCV_BSD_WarningRight_nu'
         *  Inport: '<Root>/S_LCFRCV_LCA_ActiveRight_nu'
         *  Inport: '<Root>/S_LCFRCV_LCA_WarningRight_nu'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND8/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator8/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/OR/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NEQ5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND7/Functionality'/AND'
         */
    if (((sint32)GET_P_LCRSMI_ALCALightEnable_bool()) != 0) {
        rtb_EQ_m = (uint8)((((((sint32)GET_S_LCFRCV_LCA_ActiveRight_nu()) != 0) && (((sint32)GET_S_LCFRCV_LCA_WarningRight_nu()) != 0)) && ((((sint32) GET_P_LCRSMI_TriggerCondEnable_btm()) & 4) != 0)) || ((((((sint32) GET_P_LCRSMI_TriggerCondEnable_btm()) & 8) != 0) && (((sint32) GET_S_LCFRCV_BSD_ActiveRight_nu()) != 0)) && (((sint32) GET_S_LCFRCV_BSD_WarningRight_nu()) != 0)));
    } else {
        rtb_EQ_m = (uint8)(((((sint32)rtb_S_ODPROP_DanRearObjFOV_RearRi_nu) != 0) && ((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 4) != 0)) || ((((sint32)rtb_S_ODPSOP_DanRearObjBS_RearRi_nu) != 0) && ((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 8) != 0)));
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant15'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant16'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm4'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator6/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND10/Functionality'/AND'
         */
    rtb_EQ_dwy = (uint8)(((((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 16) != 0) && (((sint32)rtb_EQ_ed) != 0)) && (!(((sint32)rtb_EQ_db) != 0))) && (((sint32)rtb_EQ_m) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Constant12'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/P_LDPSA_TriggerConditionEnable_btm6'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Logical Operator9/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/NEQ7/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/AND5/Functionality'/AND'
         */
    rtb_EQ_ed = (uint8)((((((sint32)rtb_EQ_ed) != 0) && (((sint32)rtb_EQ_db) != 0)) && ((((sint32)GET_P_LCRSMI_TriggerCondEnable_btm()) & 32) != 0)) && (((sint32)rtb_EQ_m) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/OR2/Functionality'/OR'
         */
    rtb_GT = (uint8)((((sint32)rtb_EQ_dwy) != 0) || (((sint32)rtb_EQ_ed) != 0));
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant6'/Constant'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit_Delay'
         */
    if (((sint32)rtb_LT_j) >= 1) {
        rtb_Mul_bd = DW_lcrsmi_Unit_Delay_DSTATE_e;
    } else {
        rtb_Mul_bd = 0.0F;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter5'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising'/Unit_Delay'
         */
    if ((!(((sint32)DW_lcrsmi_Unit_Delay_DSTATE_p) != 0)) && (((sint32)rtb_GT) != 0)) {
        rtb_Mul_bd = GET_P_LCRSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_j) != 0) {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Mul_bd > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Mul_bd -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Mul_bd = 0.0F;
            }
            /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Constant1'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_LCRSIA_SideCondALCARi_btf'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND5/Functionality'/AND'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2'
         */
    rtb_DataTypeConversion_j = (uint8)(((((DW_lcrsmi_Unit_Delay2_DSTATE_o <= 0.0F) && (((sint32)rtb_UnitDelay1_o) != 0)) && ((((sint32)rtb_LT_j) != 0) && (rtb_Mul_bd > 0.0F))) && ((((sint32)GET_S_LCRSIA_SideCondALCARi_btf()) & ((sint32)GET_P_LCRSMI_SideCondEnable_btm())) == 0)) && ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_LCRSMI_FctCustomTrgRi_btm())) == 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_f4 = (uint8)((((sint32)rtb_DataTypeConversion_bd) != 0) || (((sint32)rtb_DataTypeConversion_j) != 0));
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_DataTypeConversion_f4;
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_LCRSIA_SpecificALCA_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/AND1/Functionality'/AND'
         */
    rtb_EQ_ed = (uint8)((((sint32)GET_S_LCRSIA_SpecificALCA_btf()) & ((sint32) GET_P_LCRSMI_StrgRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/AND3/Functionality'/AND'
         */
    rtb_EQ_db = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_LCRSMI_StrgRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter12'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter13'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/AND6/Functionality'/AND'
         */
    rtb_EQ_dwy = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_LCRSMI_StrgRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/AND2/Functionality'/AND'
         */
    rtb_EQ_m = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_LCRSMI_StrgRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/AND4/Functionality'/AND'
         */
    rtb_EQ_lf = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_LCRSMI_StrgRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/AND5/Functionality'/AND'
         */
    rtb_EQ_bm = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_LCRSMI_StrgRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter14'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Application Parameter15'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/AND7/Functionality'/AND'
         */
    rtb_EQ_pu = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_LCRSMI_StrgRdyFctCustom_btm())) == 0);
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter11'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter12'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter13'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter14'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter5'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter6'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_LCRSIA_SpecificALCA_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Abort/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_kw = (uint8)((((((((((sint32) GET_S_LCRSIA_SpecificALCA_btf()) & ((sint32)GET_P_LCRSMI_AbortSpecific_btm())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_LCRSMI_AbortVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_LCRSMI_AbortDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_LCRSMI_AbortFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_LCRSMI_AbortFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_LCRSMI_AbortFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_LCRSMI_AbortFctCustom_btm())) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_l5 = (uint8)(!(((sint32)rtb_DataTypeConversion_kw) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_o = (uint8)((((((((((sint32)rtb_EQ_ed) != 0) && (((sint32)rtb_EQ_db) != 0)) && (((sint32)rtb_EQ_dwy) != 0)) && (((sint32) rtb_EQ_m) != 0)) && (((sint32)rtb_EQ_lf) != 0)) && (((sint32)rtb_EQ_bm) != 0)) && (((sint32)rtb_EQ_pu) != 0)) && (((sint32)rtb_DataTypeConversion_l5) != 0));
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_DataTypeConversion_o;
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Not1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter11'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter12'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter13'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter14'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter5'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter6'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_LCRSIA_SpecificALCA_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Not1/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Suppresion/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_m = (uint8)(!((((((((((sint32) GET_S_LCRSIA_SpecificALCA_btf()) & ((sint32) GET_P_LCRSMI_SuppressSpecific_btm())) != 0) || ((((sint32) GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32)GET_P_LCRSMI_SuppressVehSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_LCRSMI_SuppressDrvSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_LCRSMI_SuppressFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_LCRSMI_SuppressFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_LCRSMI_SuppressFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_LCRSMI_SuppressFctCustom_btm())) != 0)));
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_LCRSIA_SpecificALCA_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/AND1/Functionality'/AND'
         */
    rtb_EQ_gq = (uint8)((((sint32)GET_S_LCRSIA_SpecificALCA_btf()) & ((sint32) GET_P_LCRSMI_WeakRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/AND3/Functionality'/AND'
         */
    rtb_EQ_ow = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_LCRSMI_WeakRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter11'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter12'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/AND6/Functionality'/AND'
         */
    rtb_EQ_al = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_LCRSMI_WeakRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/AND2/Functionality'/AND'
         */
    rtb_EQ_bk = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_LCRSMI_WeakRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/AND4/Functionality'/AND'
         */
    rtb_EQ_g5 = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_LCRSMI_WeakRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/AND5/Functionality'/AND'
         */
    rtb_EQ_n = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_LCRSMI_WeakRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter13'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/AND7/Functionality'/AND'
         */
    rtb_EQ_mc = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_LCRSMI_WeakRdyFctCustom_btm())) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/RelatOperator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/from_data_definition5'/state_source'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady'/Unit Delay2'
         */
    rtb_LT_j = (uint8)(((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/P_LDPSA_BlockingTimeDuration_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling'/Template'
         */
    if ((((sint32)DW_lcrsmi_Template_DSTATE) != 0) && (!(((sint32)rtb_LT_j) != 0))) {
        rtb_Switch_lu = GET_P_LCRSMI_BlockingTimeDuration_sec();
    } else if (DW_lcrsmi_Unit_Delay_DSTATE_l > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
                 */
        rtb_Switch_lu = DW_lcrsmi_Unit_Delay_DSTATE_l - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch_lu = 0.0F;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Not/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/from_data_definition1'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/OR/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/OR1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Not/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady'/Unit Delay2'
         */
    rtb_DataTypeConversion_ff = (uint8)(!(((((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32)rtb_LT_j) != 0)) || (rtb_Switch_lu > 0.0F)));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_hd = (uint8)(((((((((((sint32) rtb_DataTypeConversion_m) != 0) && (((sint32)rtb_EQ_gq) != 0)) && (((sint32) rtb_EQ_ow) != 0)) && (((sint32)rtb_EQ_al) != 0)) && (((sint32)rtb_EQ_bk) != 0)) && (((sint32)rtb_EQ_g5) != 0)) && (((sint32)rtb_EQ_n) != 0)) && (((sint32)rtb_EQ_mc) != 0)) && (((sint32)rtb_DataTypeConversion_ff) != 0));
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_DataTypeConversion_hd;
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/from_data_definition2'/state_source'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation'/Unit Delay1'
         */
    rtb_UnitDelay2 = (uint8)(((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay1'
         */
    if ((!(((sint32)DW_lcrsmi_Unit_Delay1_DSTATE) != 0)) && (((sint32)rtb_UnitDelay2) != 0)) {
        rtb_Switch2_p = GET_P_LCRSMI_DegrTimeOut_sec();
    } else if (DW_lcrsmi_Unit_Delay_DSTATE_m > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay'
                 */
        rtb_Switch2_p = DW_lcrsmi_Unit_Delay_DSTATE_m - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_p = 0.0F;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' */
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/Equality1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_EQ_ob = (uint8)(((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8)E_LCF_FunctionV3Type_E_LCF_ALCA_nu)));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysStOffLatDMC_bool'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/AND1/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/AND2/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/AND3/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/NOT/Functionality'/NOT'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/NOT/Functionality'/NOT'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/NOT1/Functionality'/NOT'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation'/Unit_Delay2'
         */
    rtb_DataTypeConversion_l = (uint8)((((sint32)rtb_UnitDelay2) != 0) && (((!(rtb_Switch2_p > 0.0F)) || (!(((sint32)rtb_EQ_ob) != 0))) || ((((sint32) rtb_EQ_ob) != 0) && ((((sint32)GET_S_LCFRCV_SysStOffLatDMC_bool()) != 0) && (!(((sint32)DW_lcrsmi_Unit_Delay2_DSTATE_m) != 0))))));
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_l;
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Constant6'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/AND1/Functionality'/AND'
         */
    rtb_NE_c2 = (uint8)((((sint32)GET_P_LCRSMI_FinishCondEnable_btm()) & 1) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Constant3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Constant7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_o3 = (uint8)((((sint32) GET_P_LCRSMI_FinishCondEnable_btm()) & 2) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Constant2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Constant4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/AND3/Functionality'/AND'
         */
    rtb_NE_en = (uint8)((((sint32)GET_P_LCRSMI_FinishCondEnable_btm()) & 4) == 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Constant5'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Constant8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/AND4/Functionality'/AND'
         */
    rtb_NE_lm = (uint8)((((sint32)GET_P_LCRSMI_FinishCondEnable_btm()) & 8) == 0);
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_NoHazardFinishTol_met'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         *  Inport: '<Root>/S_LCRSIA_DlcLeALCA_met'
         *  Inport: '<Root>/S_LCRSIA_VelLatLeALCA_mps'
         *  Inport: '<Root>/S_LCRTTG_LeTgtTrajPosY0_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator4/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator5/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator8/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator9/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR2/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator1/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator11/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator16/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator17/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator2/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator5/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator6/Functionality'/GT'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Neg/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Neg1/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Neg4/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_dg = (uint8)(((((((sint32)DW_lcrsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((((sint32)rtb_NE_c2) != 0) || ((GET_S_LCRTTG_LeTgtTrajPosY0_met() > (-GET_P_LCRSMI_HazardFinishTol_met())) && (GET_S_LCRTTG_LeTgtTrajPosY0_met() < GET_P_LCRSMI_NoHazardFinishTol_met())))) && ((((sint32) rtb_DataTypeConversion_o3) != 0) || ((GET_S_ABPLBP_LeLnClthHeading_rad() < GET_P_LCRSMI_NoHazardFinishHeadAng_rad()) && (GET_S_ABPLBP_LeLnClthHeading_rad() > (-GET_P_LCRSMI_HazardFinishHeadAng_rad ()))))) && ((((sint32)rtb_NE_en) != 0) || ((GET_S_LCRSIA_VelLatLeALCA_mps() < GET_P_LCRSMI_HazardFinishDlc_met()) && (GET_S_LCRSIA_VelLatLeALCA_mps() > (-GET_P_LCRSMI_NoHazardFinishDlc_met()))))) && ((((sint32)rtb_NE_lm) != 0) || ((GET_S_LCRSIA_DlcLeALCA_met() > GET_P_LCRSMI_HazardFinishDlc_met()) && (GET_S_LCRSIA_DlcLeALCA_met() < GET_P_LCRSMI_NoHazardFinishDlc_met()))));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps5'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps6'/Constant'
         *  Inport: '<Root>/S_LCRSIA_VelLatRiALCA_mps'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator11/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator12/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator13/Functionality'/LT'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Neg6/Functionality'/Unary Minus'
         */
    rtb_NE_en = (uint8)((((sint32)rtb_NE_en) != 0) || ((GET_S_LCRSIA_VelLatRiALCA_mps() > (-GET_P_LCRSMI_NoHazardFinishVelLat_mps())) && (GET_S_LCRSIA_VelLatRiALCA_mps() < GET_P_LCRSMI_HazardFinishVelLat_mps())));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps9'/Constant'
         *  Inport: '<Root>/S_LCRSIA_DlcRiALCA_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR6/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator14/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator15/Functionality'/LT'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Neg5/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Neg8/Functionality'/Unary Minus'
         */
    rtb_NE_lm = (uint8)((((sint32)rtb_NE_lm) != 0) || ((GET_S_LCRSIA_DlcRiALCA_met() < (-GET_P_LCRSMI_HazardFinishDlc_met())) && (GET_S_LCRSIA_DlcRiALCA_met() > (-GET_P_LCRSMI_NoHazardFinishDlc_met()))));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_NoHazardFinishTol_met1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         *  Inport: '<Root>/S_LCRTTG_RiTgtTrajPosY0_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator6/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR3/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator10/Functionality'/GT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator7/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator8/Functionality'/LT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator9/Functionality'/GT'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Neg3/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs'/Unit Delay5'
         */
    rtb_NE_lm = (uint8)(((((((sint32)DW_lcrsmi_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && ((((sint32) rtb_NE_c2) != 0) || ((GET_S_LCRTTG_RiTgtTrajPosY0_met() < GET_P_LCRSMI_HazardFinishTol_met()) && (GET_S_LCRTTG_RiTgtTrajPosY0_met() > (-GET_P_LCRSMI_NoHazardFinishTol_met()))))) && ((((sint32) rtb_DataTypeConversion_o3) != 0) || ((GET_S_ABPLBP_RiLnClthHeading_rad() > ( -GET_P_LCRSMI_NoHazardFinishHeadAng_rad())) && (GET_S_ABPLBP_RiLnClthHeading_rad() < GET_P_LCRSMI_HazardFinishHeadAng_rad())))) && (((sint32)rtb_NE_en) != 0)) && (((sint32)rtb_NE_lm) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_dg = (uint8)((((sint32)rtb_DataTypeConversion_dg) != 0) || (((sint32)rtb_NE_lm) != 0));
    /* Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
         */
    rtb_LogicalOperator_d = (uint8)((DW_lcrsmi_UnitDelay1_DSTATE_j <= 0.0F) && (((sint32)rtb_DataTypeConversion_dg) != 0));
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate[5] = rtb_LogicalOperator_d;
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_LCRSIA_SpecificALCA_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND1/Functionality'/AND'
         */
    rtb_NE_lm = (uint8)((((sint32)GET_S_LCRSIA_SpecificALCA_btf()) & ((sint32) GET_P_LCRSMI_CancelSpecific_btm())) != 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter11'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND3/Functionality'/AND'
         */
    rtb_NE_lh = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_LCRSMI_CancelVehSt_btm())) != 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ5/Functionality'/NE' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter12'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND6/Functionality'/AND'
         */
    rtb_NE_en = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_LCRSMI_CancelDrvSt_btm())) != 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ2/Functionality'/NE' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND2/Functionality'/AND'
         */
    rtb_NE_l4 = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_LCRSMI_CancelFctStCtr_btm())) != 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ3/Functionality'/NE' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND4/Functionality'/AND'
         */
    rtb_NE_c2 = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_LCRSMI_CancelFctStErr_btm())) != 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ4/Functionality'/NE' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter10'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND5/Functionality'/AND'
         */
    rtb_NE_j3 = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_LCRSMI_CancelFctStNotAv_btm())) != 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator1/Functionality'/GT' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Constant'/Constant'
         *  Inport: '<Root>/S_LCRSIA_VelLatLeALCA_mps'
         */
    rtb_DataTypeConversion_o3 = (uint8)(GET_S_LCRSIA_VelLatLeALCA_mps() > 0.0F);
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/P_LDPSA_HazardCancelTol_met1'/Constant'
         *  Inport: '<Root>/S_LCRSIA_DlcLeALCA_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator10/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator10/Functionality'/GT'
         */
    rtb_Switch_l = (uint8)((((sint32)rtb_DataTypeConversion_o3) != 0) && (GET_S_LCRSIA_DlcLeALCA_met() > GET_P_LCRSMI_NoHazardCancelDlc_met()));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator11/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/P_LDPSA_NoHazardCancelTol_met'/Constant'
         *  Inport: '<Root>/S_LCRTTG_LeTgtTrajPosY0_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator11/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator7/Functionality'/GT'
         */
    rtb_DataTypeConversion_o3 = (uint8)((((sint32)rtb_DataTypeConversion_o3) != 0) && (GET_S_LCRTTG_LeTgtTrajPosY0_met() > GET_P_LCRSMI_NoHazardCancelTol_met()));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/P_LDPSA_HazardCancelTol_met'/Constant'
         *  Inport: '<Root>/S_LCRSIA_DlcLeALCA_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator4/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator3/Functionality'/LT'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_mz = (uint8)(((GET_S_LCRSIA_DlcLeALCA_met() < (-GET_P_LCRSMI_HazardCancelTol_met())) || (((sint32)rtb_Switch_l) != 0)) || (((sint32)rtb_DataTypeConversion_o3) != 0));
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator2/Functionality'/LT' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Constant1'/Constant'
         *  Inport: '<Root>/S_LCRSIA_VelLatRiALCA_mps'
         */
    rtb_DataTypeConversion_o3 = (uint8)(GET_S_LCRSIA_VelLatRiALCA_mps() < 0.0F);
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator13/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/P_LDPSA_HazardCancelTol_met2'/Constant'
         *  Inport: '<Root>/S_LCRSIA_DlcRiALCA_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator13/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator11/Functionality'/LT'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Neg2/Functionality'/Unary Minus'
         */
    rtb_Switch_aq = (uint8)((((sint32)rtb_DataTypeConversion_o3) != 0) && (GET_S_LCRSIA_DlcRiALCA_met() < (-GET_P_LCRSMI_NoHazardCancelDlc_met())));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator14/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/P_LDPSA_NoHazardCancelTol_met1'/Constant'
         *  Inport: '<Root>/S_LCRTTG_RiTgtTrajPosY0_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator14/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator12/Functionality'/LT'
         *  UnaryMinus: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Neg1/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_o3 = (uint8)((((sint32)rtb_DataTypeConversion_o3) != 0) && (GET_S_LCRTTG_RiTgtTrajPosY0_met() < (-GET_P_LCRSMI_NoHazardCancelTol_met())));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/P_LDPSA_HazardCancelTol_met'/Constant'
         *  Inport: '<Root>/S_LCRSIA_DlcRiALCA_met'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator6/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator9/Functionality'/GT'
         */
    rtb_DataTypeConversion_cy = (uint8)(((GET_S_LCRSIA_DlcRiALCA_met() > GET_P_LCRSMI_HazardCancelTol_met()) || (((sint32)rtb_Switch_aq) != 0)) || (((sint32)rtb_DataTypeConversion_o3) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/from_data_definition1'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/from_data_definition2'/state_source'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator3/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator5/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator6/Functionality'/EQ'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs'/Unit Delay5'
         */
    rtb_Switch_aq = (uint8)(((((sint32)DW_lcrsmi_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && (((sint32) rtb_DataTypeConversion_mz) != 0)) || ((((sint32)DW_lcrsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && (((sint32)rtb_DataTypeConversion_cy) != 0)));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator12/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/from_data_definition3'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/from_data_definition4'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/Constant2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/Constant1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/Constant2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_LCRSIA_LnBndLeValidALCA_bool'
         *  Inport: '<Root>/S_LCRSIA_LnBndRiValidALCA_bool'
         *  Inport: '<Root>/S_LCRSIA_SideCondALCALe_btf'
         *  Inport: '<Root>/S_LCRSIA_SideCondALCARi_btf'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator12/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator9/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/NOT/Functionality'/NOT'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/OR/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/NOT/Functionality'/NOT'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Relational Operator8/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/NEQ2/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondLe/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/SideCondRi/AND3/Functionality'/AND'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs'/Unit Delay5'
         */
    rtb_Switch_l = (uint8)(((((sint32)DW_lcrsmi_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((((((sint32)GET_S_LCRSIA_SideCondALCALe_btf()) & ((sint32) GET_P_LCRSMI_SideCondCancel_btm())) != 0) || (!(((sint32) GET_S_LCRSIA_LnBndLeValidALCA_bool()) != 0))) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_LCRSMI_CancelFctCustomLe_btm())) != 0))) || ((((sint32)DW_lcrsmi_UnitDelay5_DSTATE) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && ((((((sint32) GET_S_LCRSIA_SideCondALCARi_btf()) & ((sint32) GET_P_LCRSMI_SideCondCancel_btm())) != 0) || (!(((sint32) GET_S_LCRSIA_LnBndRiValidALCA_bool()) != 0))) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_LCRSMI_CancelFctCustomRi_btm())) != 0))));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter15'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter16'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter17'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter18'/Constant'
         *  Inport: '<Root>/S_TCTCLM_QuServTrajCtr_nu'
         *  Inport: '<Root>/S_TPLFBT_QuStatusTrajPlan_nu'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ7/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ8/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND8/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND9/Functionality'/AND'
         */
    rtb_DataTypeConversion_o3 = (uint8)(((((sint32) GET_S_TPLFBT_QuStatusTrajPlan_nu()) & ((sint32) GET_P_LCRSMI_QuTrajPlanCancel_btm())) != 0) || ((((sint32) GET_S_TCTCLM_QuServTrajCtr_nu()) & ((sint32)GET_P_LCRSMI_QuTrajCtrCancel_btm ())) != 0));
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/Relational Operator11/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/from_data_definition'/state_source'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs'/Unit Delay3'
         */
    rtb_EQ_an = (uint8)(((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/P_LDPSA_ControllingMaxDuration_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4'
         */
    if ((!(((sint32)DW_lcrsmi_Unit_Delay4_DSTATE) != 0)) && (((sint32)rtb_EQ_an) != 0)) {
        rtb_Switch2_p4 = GET_P_LCRSMI_ControllingMaxDuration_sec();
    } else if (DW_lcrsmi_Unit_Delay3_DSTATE > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
                 */
        rtb_Switch2_p4 = DW_lcrsmi_Unit_Delay3_DSTATE - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 */
        rtb_Switch2_p4 = 0.0F;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         */
    rtb_sfun_setbit_ic = (uint8)(!(rtb_Switch2_p4 > 0.0F));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/AND'
         */
    rtb_sfun_setbit_ic = (uint8)((((sint32)rtb_EQ_an) != 0) && (((sint32) rtb_sfun_setbit_ic) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter13'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_kt = (uint8)(((((((((((((sint32)rtb_NE_lm) != 0) || (((sint32)rtb_NE_lh) != 0)) || (((sint32)rtb_NE_en) != 0)) || (((sint32) rtb_NE_l4) != 0)) || (((sint32)rtb_NE_c2) != 0)) || (((sint32)rtb_NE_j3) != 0)) || (((sint32)rtb_Switch_aq) != 0)) || (((sint32)rtb_Switch_l) != 0)) || (((sint32)rtb_DataTypeConversion_o3) != 0)) || (((sint32)rtb_sfun_setbit_ic) != 0)) || ((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_LCRSMI_CancelFctCustom_btm())) != 0));
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_DataTypeConversion_kt;
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/ErrorStateALCA/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/ErrorStateALCA/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/ErrorStateALCA/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ErrorStateALCA_bool'
         */
    if (((sint32)GET_P_LCRSMI_ErrorStateALCAEnable_bool()) != 0) {
        rtb_Switch_d1 = GET_S_LCFRCV_ErrorStateALCA_bool();
    } else {
        rtb_Switch_d1 = GET_P_LCRSMI_ErrorStateALCA_bool();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/ErrorStateALCA/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Switch_d1;
    /* S-Function (sfun_setbit): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/D_SysStateALCA/set_bit/Functionality'/sfun_setbit' */
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
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/Application Parameter2'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/NOT/Functionality'/NOT'
         */
    rtb_sfun_setbit_i = (uint8)(!(((sint32)GET_P_LCRSMI_LatDMCClearEnable_bool()) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/OR/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStOnLatDMC_bool'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/OR/Functionality'/OR'
         */
    rtb_sfun_setbit_i = (uint8)((((sint32)rtb_sfun_setbit_i) != 0) || (((sint32) GET_S_LCFRCV_SysStOnLatDMC_bool()) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/Constant'/Constant'
         *  Inport: '<Root>/S_TPLFBT_QuStatusTrajPlan_nu'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/AND/Functionality'/AND'
         */
    rtb_sfun_setbit_n = (uint8)(((sint32)GET_S_TPLFBT_QuStatusTrajPlan_nu()) & ((sint32)GET_P_LCRSMI_QuTrajPlanClearance_btm()));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/Constant1'/Constant'
         *  Inport: '<Root>/S_TCTCLM_QuServTrajCtr_nu'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/EQ1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/ALCAClearance/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_fr = (uint8)((((((sint32)rtb_sfun_setbit_i) != 0) && (((sint32)rtb_sfun_setbit_n) == 0)) && ((((sint32) GET_S_TCTCLM_QuServTrajCtr_nu()) & ((sint32) GET_P_LCRSMI_QuTrajCtrClearance_btm())) == 0)) && (((sint32)rtb_EQ_ob) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/AND/Functionality'/AND'
         */
    rtb_EQ_ob = (uint8)(((((sint32)rtb_DataTypeConversion_o) != 0) && (((sint32) rtb_DataTypeConversion_hd) != 0)) && (((sint32)rtb_DataTypeConversion_f4) != 0));
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/P_LDPSA_BlockingTimeDuration_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut'/Unit_Delay'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut'/Unit_Delay1'
         */
    if ((!(((sint32)DW_lcrsmi_Unit_Delay1_DSTATE_n) != 0)) && (((sint32)rtb_EQ_ob) != 0)) {
        rtb_Switch2_hq = GET_P_LCRSMI_RequestTimeOut_sec();
    } else if (DW_lcrsmi_Unit_Delay_DSTATE_c > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut'/Unit_Delay'
                 */
        rtb_Switch2_hq = DW_lcrsmi_Unit_Delay_DSTATE_c - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_hq = 0.0F;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING'/fcg' */
    /* Chart: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM'/StateMachineALCA' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/from_data_definition1'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/from_data_definition2'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/from_data_definition3'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/from_data_definition4'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/from_data_definition5'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/from_data_definition6'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/from_data_definition8'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/Constant'/Constant'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *
         * Block description for 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM'/StateMachineALCA':
         *  X.1.1.8
         */
    /* Gateway: LCRSMI_cg/LCRSMI_SenProcess/OPM/StateMachineALCA */
    /* During: LCRSMI_cg/LCRSMI_SenProcess/OPM/StateMachineALCA */
    if (((uint32)((sint32)DW_lcrsmi_is_active_c3_LCRSMI_cg)) == 0U) {
        /* Entry: LCRSMI_cg/LCRSMI_SenProcess/OPM/StateMachineALCA */
        DW_lcrsmi_is_active_c3_LCRSMI_cg = 1U;
        /* Entry Internal: LCRSMI_cg/LCRSMI_SenProcess/OPM/StateMachineALCA */
        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':66' */
        if (!(((sint32)GET_P_ALCA_Existing_nu()) != 0)) {
            /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':74' */
            DW_lcrsmi_is_c3_LCRSMI_cg = IN_NOT_PRESENT;
            /* Entry 'NOT_PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':3' */
            BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
        } else if ((((sint32)GET_P_ALCA_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_d1) != 0))) {
            /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':83' */
            DW_lcrsmi_is_c3_LCRSMI_cg = IN_PRESENT;
            /* Entry Internal 'PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':107' */
            /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':72' */
            if (!(((sint32)rtb_Switch_kf) != 0)) {
                /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':71' */
                DW_lcrsmi_is_PRESENT = IN_DISABLED;
                /* Entry 'DISABLED': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':1' */
                BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
            } else {
                /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':70' */
                DW_lcrsmi_is_PRESENT = IN_PASSIVE;
                /* Entry 'PASSIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':8' */
                BI_lcrsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
            }
        } else {
            if ((((sint32)GET_P_ALCA_Existing_nu()) != 0) && (((sint32)rtb_Switch_d1) != 0)) {
                /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':82' */
                DW_lcrsmi_is_c3_LCRSMI_cg = IN_ERROR;
                /* Entry 'ERROR': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':12' */
                BI_lcrsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            }
        }
    } else {
        switch (DW_lcrsmi_is_c3_LCRSMI_cg) {
        case IN_ERROR:
            /* During 'ERROR': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':12' */
            if ((!(((sint32)rtb_Switch_d1) != 0)) || (!(((sint32) GET_P_ALCA_Existing_nu()) != 0))) {
                /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':59' */
                if (!(((sint32)GET_P_ALCA_Existing_nu()) != 0)) {
                    /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':74' */
                    DW_lcrsmi_is_c3_LCRSMI_cg = IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':3' */
                    BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_ALCA_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_d1) != 0))) {
                    /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':83' */
                    DW_lcrsmi_is_c3_LCRSMI_cg = IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':107' */
                    /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':72' */
                    if (!(((sint32)rtb_Switch_kf) != 0)) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':71' */
                        DW_lcrsmi_is_PRESENT = IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':1' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':70' */
                        DW_lcrsmi_is_PRESENT = IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':8' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                } else {
                    if ((((sint32)GET_P_ALCA_Existing_nu()) != 0) && (((sint32) rtb_Switch_d1) != 0)) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':82' */
                        DW_lcrsmi_is_c3_LCRSMI_cg = IN_ERROR;
                        /* Entry 'ERROR': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':12' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        case IN_NOT_PRESENT:
            /* During 'NOT_PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':3' */
            if (((sint32)GET_P_ALCA_Existing_nu()) != 0) {
                /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':81' */
                if (!(((sint32)GET_P_ALCA_Existing_nu()) != 0)) {
                    /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':74' */
                    DW_lcrsmi_is_c3_LCRSMI_cg = IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':3' */
                    BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_ALCA_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_d1) != 0))) {
                    /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':83' */
                    DW_lcrsmi_is_c3_LCRSMI_cg = IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':107' */
                    /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':72' */
                    if (!(((sint32)rtb_Switch_kf) != 0)) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':71' */
                        DW_lcrsmi_is_PRESENT = IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':1' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':70' */
                        DW_lcrsmi_is_PRESENT = IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':8' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                } else {
                    if ((((sint32)GET_P_ALCA_Existing_nu()) != 0) && (((sint32) rtb_Switch_d1) != 0)) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':82' */
                        DW_lcrsmi_is_c3_LCRSMI_cg = IN_ERROR;
                        /* Entry 'ERROR': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':12' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        default:
            /* During 'PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':107' */
            if (!(((sint32)GET_P_ALCA_Existing_nu()) != 0)) {
                /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':58' */
                /* Exit Internal 'PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':107' */
                DW_lcrsmi_is_PRESENT = IN_NO_ACTIVE_CHILD;
                DW_lcrsmi_is_c3_LCRSMI_cg = IN_NOT_PRESENT;
                /* Entry 'NOT_PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':3' */
                BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
            } else if ((((sint32)rtb_Switch_d1) != 0) && (((sint32) GET_P_ALCA_Existing_nu()) != 0)) {
                /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':76' */
                /* Exit Internal 'PRESENT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':107' */
                DW_lcrsmi_is_PRESENT = IN_NO_ACTIVE_CHILD;
                DW_lcrsmi_is_c3_LCRSMI_cg = IN_ERROR;
                /* Entry 'ERROR': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':12' */
                BI_lcrsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            } else {
                switch (DW_lcrsmi_is_PRESENT) {
                case IN_ACTIVE:
                    /* During 'ACTIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':10' */
                    if ((((((sint32)rtb_LogicalOperator_d) != 0) || (((sint32) rtb_DataTypeConversion_kt) != 0)) || (!(((sint32) rtb_DataTypeConversion_o) != 0))) || (!(((sint32) rtb_DataTypeConversion_fr) != 0))) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':65' */
                        DW_lcrsmi_is_PRESENT = IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':64' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    }
                    break;
                case IN_DISABLED:
                    /* During 'DISABLED': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':1' */
                    if (((sint32)rtb_Switch_kf) != 0) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':17' */
                        DW_lcrsmi_is_PRESENT = IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':8' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                    break;
                case IN_PASSIVE:
                    /* During 'PASSIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':8' */
                    if (!(((sint32)rtb_Switch_kf) != 0)) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':18' */
                        DW_lcrsmi_is_PRESENT = IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':1' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        if (((((sint32)rtb_DataTypeConversion_o) != 0) && (((sint32) rtb_DataTypeConversion_hd) != 0)) && (((sint32) rtb_DataTypeConversion_f4) != 0)) {
                            /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':80' */
                            DW_lcrsmi_is_PRESENT = IN_REQUEST;
                            /* Entry 'REQUEST': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':9' */
                            BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu);
                        }
                    }
                    break;
                case IN_RAMPOUT:
                    /* During 'RAMPOUT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':64' */
                    if (((sint32)rtb_DataTypeConversion_l) != 0) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':78' */
                        if (!(((sint32)rtb_Switch_kf) != 0)) {
                            /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':71' */
                            DW_lcrsmi_is_PRESENT = IN_DISABLED;
                            /* Entry 'DISABLED': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':1' */
                            BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                        } else {
                            /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':70' */
                            DW_lcrsmi_is_PRESENT = IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':8' */
                            BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                default:
                    /* During 'REQUEST': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':9' */
                    if ((((sint32)rtb_DataTypeConversion_fr) != 0) && (!(((sint32) rtb_DataTypeConversion_o) != 0))) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':143' */
                        DW_lcrsmi_is_PRESENT = IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':64' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    } else if ((((sint32)rtb_DataTypeConversion_fr) != 0) && (((sint32) rtb_DataTypeConversion_o) != 0)) {
                        /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':20' */
                        DW_lcrsmi_is_PRESENT = IN_ACTIVE;
                        /* Entry 'ACTIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':10' */
                        BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu);
                    } else {
                        if ((!(((sint32)rtb_DataTypeConversion_fr) != 0)) && ((!(rtb_Switch2_hq > 0.0F)) || (!(((sint32) rtb_DataTypeConversion_o) != 0)))) {
                            /* Transition: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':22' */
                            DW_lcrsmi_is_PRESENT = IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineALCA':8' */
                            BI_lcrsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM'/StateMachineALCA' */
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_f[0] = rtb_NE_lm;
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_f[2] = rtb_NE_l4;
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_f[4] = rtb_Switch_aq;
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_f[5] = rtb_Switch_l;
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_f[6] = rtb_sfun_setbit_ic;
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_f[7] = rtb_DataTypeConversion_o3;
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate_f[1] = (uint8)((((sint32)rtb_NE_lh) != 0) || (((sint32) rtb_NE_en) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/OR1/Functionality'/OR'
         */
    rtb_VectorConcatenate_f[3] = (uint8)((((sint32)rtb_NE_c2) != 0) || (((sint32) rtb_NE_j3) != 0));
    /* S-Function (sfun_setbit): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_f[0];
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
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/from_data_definition'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/from_data_definition1'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/from_data_definition5'/state_source'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Relational Operator2/Functionality'/EQ'
         */
    rtb_Switch_kf = (uint8)(((((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide'/Template'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide'/Template1'
         */
    if (((sint32)DW_lcrsmi_Template1_DSTATE) != 0) {
        rtb_DataTypeConversion_bd = DW_lcrsmi_Template_DSTATE_o;
    } else if (((sint32)rtb_DataTypeConversion_bd) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_bd = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT);
    } else if (((sint32)rtb_DataTypeConversion_j) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition2'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_bd = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT);
    } else {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition3'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_bd = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/from_data_definition3'/state_source'
         */
    if (((sint32)rtb_Switch_kf) != 0) {
        rtb_DataTypeConversion_j = rtb_DataTypeConversion_bd;
    } else {
        rtb_DataTypeConversion_j = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/Switch4/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation'/Unit_Delay1'
         */
    if (((sint32)rtb_UnitDelay2) != 0) {
        rtb_DataTypeConversion_f4 = DW_lcrsmi_Unit_Delay1_DSTATE_f;
    } else {
        rtb_DataTypeConversion_f4 = rtb_DataTypeConversion_kw;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_dg) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
                 */
        if (DW_lcrsmi_UnitDelay1_DSTATE_j > 0.0F) {
            /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_lcrsmi_UnitDelay1_DSTATE_j -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_OnTargetFinishTime_sec'/Constant'
                 */
        DW_lcrsmi_UnitDelay1_DSTATE_j = GET_P_LCRSMI_OnTargetFinishTime_sec();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_h) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2'
                 */
        if (DW_lcrsmi_Unit_Delay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_lcrsmi_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter1'/Constant'
                 */
        DW_lcrsmi_Unit_Delay2_DSTATE = GET_P_LCRSMI_SafeSituationDelay_sec();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_l1) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic'/Unit Delay1'
                 */
        if (DW_lcrsmi_UnitDelay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_lcrsmi_UnitDelay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic'/Unit Delay1' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/Application Parameter2'/Constant'
                 */
        DW_lcrsmi_UnitDelay1_DSTATE = GET_P_LCRSMI_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLogic/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_UnitDelay1_o) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2'
                 */
        if (DW_lcrsmi_Unit_Delay2_DSTATE_o > 0.0F) {
            /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_lcrsmi_Unit_Delay2_DSTATE_o -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter1'/Constant'
                 */
        DW_lcrsmi_Unit_Delay2_DSTATE_o = GET_P_LCRSMI_SafeSituationDelay_sec();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_a) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic'/Unit Delay1'
                 */
        if (DW_lcrsmi_UnitDelay1_DSTATE_b > 0.0F) {
            /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_lcrsmi_UnitDelay1_DSTATE_b -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic'/Unit Delay1' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/Application Parameter2'/Constant'
                 */
        DW_lcrsmi_UnitDelay1_DSTATE_b = GET_P_LCRSMI_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLogic/TURNONDELAYTIME/Functionality'/Switch2' */
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Logical Operator1/Functionality'/AND'
         */
    rtb_LT_l1 = (uint8)((((sint32)rtb_DataTypeConversion_hd) != 0) && (((sint32) rtb_DataTypeConversion_o) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[0] = (uint8)(!(((sint32)rtb_EQ_ed) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[1] = (uint8)(!(((sint32)rtb_EQ_db) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[2] = (uint8)(!(((sint32)rtb_EQ_dwy) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[3] = (uint8)(!(((sint32)rtb_EQ_m) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[4] = (uint8)(!(((sint32)rtb_EQ_lf) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[5] = (uint8)(!(((sint32)rtb_EQ_bm) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[6] = (uint8)(!(((sint32)rtb_EQ_pu) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_l5) != 0));
    /* S-Function (sfun_setbit): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/StrongReady/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_b[0];
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
        rtb_sfun_setbit_i = temp;
    }
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_j[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_m) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_j[1] = (uint8)(!(((sint32)rtb_EQ_gq) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT2/Functionality'/NOT'
         */
    rtb_sfun_setbit_ic = (uint8)(!(((sint32)rtb_EQ_ow) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_j[3] = (uint8)(!(((sint32)rtb_EQ_bk) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_j[4] = (uint8)(!(((sint32)rtb_EQ_g5) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_j[5] = (uint8)(!(((sint32)rtb_EQ_n) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_j[6] = (uint8)(!(((sint32)rtb_EQ_mc) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_j[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_ff) != 0));
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/NOT8/Functionality'/NOT'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate_j[2] = (uint8)((((sint32)rtb_sfun_setbit_ic) != 0) || (!(((sint32)rtb_EQ_al) != 0)));
    /* S-Function (sfun_setbit): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_j[0];
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
        rtb_sfun_setbit_ic = temp;
    }
    /* DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/NOT/Functionality'/NOT'
         */
    rtb_EQ_dwy = (uint8)(!(((sint32)rtb_Switch_d1) != 0));
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/OR/Functionality'/Data Type Conversion'
         *  DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/OR1/Functionality'/Data Type Conversion'
         *  DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/OR2/Functionality'/Data Type Conversion'
         *  DataTypeConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/OR3/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_LCFRCV_BSD_WarningLeft_nu'
         *  Inport: '<Root>/S_LCFRCV_BSD_WarningRight_nu'
         *  Inport: '<Root>/S_LCFRCV_LCA_WarningLeft_nu'
         *  Inport: '<Root>/S_LCFRCV_LCA_WarningRight_nu'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/OR/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/OR1/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/OR2/Functionality'/OR'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/OR3/Functionality'/OR'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch6/Functionality'/Switch'
         */
    if (((sint32)GET_P_LCRSMI_ALCALightEnable_bool()) != 0) {
        rtb_S_ODPROP_DanRearObjFOV_RearLe_nu = (uint8)((((sint32) GET_S_LCFRCV_LCA_WarningLeft_nu()) != 0) || (((sint32) GET_S_LCFRCV_BSD_WarningLeft_nu()) != 0));
        rtb_S_ODPSOP_DanRearObjBS_RearLe_nu = (uint8)((((sint32) GET_S_LCFRCV_LCA_WarningRight_nu()) != 0) || (((sint32) GET_S_LCFRCV_BSD_WarningRight_nu()) != 0));
    } else {
        rtb_S_ODPROP_DanRearObjFOV_RearLe_nu = (uint8)((((sint32) rtb_S_ODPROP_DanRearObjFOV_RearLe_nu) != 0) || (((sint32) rtb_S_ODPSOP_DanRearObjBS_RearLe_nu) != 0));
        rtb_S_ODPSOP_DanRearObjBS_RearLe_nu = (uint8)((((sint32) rtb_S_ODPROP_DanRearObjFOV_RearRi_nu) != 0) || (((sint32) rtb_S_ODPSOP_DanRearObjBS_RearRi_nu) != 0));
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Application Parameter1'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Constant11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND11/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/OR3/Functionality'/OR'
         */
    rtb_EQ_m = (uint8)((((sint32)((uint8)(((sint32)((uint8)(((sint32) GET_P_LCRSMI_StrgRdyDrvSt_btm()) & ((sint32)GET_P_LCRSMI_DebugDrvSt_btm())))) | ((sint32)((uint8)(((sint32)GET_P_LCRSMI_DebugDrvSt_btm()) & ((sint32) GET_P_LCRSMI_CancelDrvSt_btm()))))))) & ((sint32) GET_S_VDPDRV_DrvStInvalid_btf())) != 0);
    /* RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Application Parameter4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Application Parameter7'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Constant9'/Constant'
         *  Inport: '<Root>/S_LCRSIA_SpecificALCA_btf'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/OR2/Functionality'/OR'
         */
    rtb_EQ_db = (uint8)((((sint32)((uint8)(((sint32)((uint8)(((sint32) GET_P_LCRSMI_StrgRdySpecific_btm()) & ((sint32) GET_P_LCRSMI_DebugSpecific_btm())))) | ((sint32)((uint8)(((sint32) GET_P_LCRSMI_DebugSpecific_btm()) & ((sint32)GET_P_LCRSMI_CancelSpecific_btm ()))))))) & ((sint32)GET_S_LCRSIA_SpecificALCA_btf())) != 0);
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Application Parameter8'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Constant4'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_LCRSIA_LnBndRiValidALCA_bool'
         *  Inport: '<Root>/S_LCRSIA_SideCondALCARi_btf'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/NOT1/Functionality'/NOT'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/NOT2/Functionality'/NOT'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/NEQ6/Functionality'/NE'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Relational Operator2/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND7/Functionality'/AND'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch11/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch12/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch13/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch5/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch8/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch9/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState'/Template'
         *  UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState'/Template1'
         */
    if (((sint32)DW_lcrsmi_Template1_DSTATE_e) != 0) {
        rtb_DataTypeConversion_kw = DW_lcrsmi_Template_DSTATE_a;
    } else if (((sint32)rtb_LogicalOperator_d) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_SUCCESSFUL);
    } else if (((sint32)rtb_DataTypeConversion_kw) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition9'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_ABORT);
    } else if (((sint32)rtb_DataTypeConversion_j) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Application Parameter5'/Constant'
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Constant13'/Constant'
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition15'/state_source'
                 *  Inport: '<Root>/S_LCRSIA_LnBndLeValidALCA_bool'
                 *  Inport: '<Root>/S_LCRSIA_SideCondALCALe_btf'
                 *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/NOT/Functionality'/NOT'
                 *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/NOT3/Functionality'/NOT'
                 *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/NEQ2/Functionality'/NE'
                 *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND3/Functionality'/AND'
                 *  S-Function (sfix_bitop): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/AND5/Functionality'/AND'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch14/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        if (((((((sint32)GET_P_LCRSMI_SideCondDebug_btm()) & ((sint32) GET_P_LCRSMI_SideCondCancel_btm())) & ((sint32) GET_S_LCRSIA_SideCondALCALe_btf())) != 0) || (((sint32)rtb_EQ_m) != 0)) || (((sint32)rtb_EQ_db) != 0)) {
            rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_DRV);
        } else if (((sint32)rtb_DataTypeConversion_mz) != 0) {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition14'/state_source'
                         */
            rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_LAT_DEV);
        } else if (!(((sint32)rtb_S_ODPROP_DanRearObjFOV_RearLe_nu) != 0)) {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch14/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition18'/state_source'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch10/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_OBJ_IFACE);
        } else if (!(((sint32)GET_S_LCRSIA_LnBndLeValidALCA_bool()) != 0)) {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition13'/state_source'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch10/Functionality'/Switch'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch14/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_LANE);
        } else {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch14/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition2'/state_source'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch10/Functionality'/Switch'
                         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch7/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_OTHER);
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch6/Functionality'/Switch' */
    } else if (((((sint32)rtb_EQ_m) != 0) || (((sint32)rtb_EQ_db) != 0)) || (((((sint32)GET_P_LCRSMI_SideCondDebug_btm()) & ((sint32) GET_P_LCRSMI_SideCondCancel_btm())) & ((sint32) GET_S_LCRSIA_SideCondALCARi_btf())) != 0)) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch11/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition11'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_DRV);
    } else if (((sint32)rtb_DataTypeConversion_cy) != 0) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition10'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_LAT_DEV);
    } else if (!(((sint32)rtb_S_ODPSOP_DanRearObjBS_RearLe_nu) != 0)) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch13/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition17'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch8/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_OBJ_IFACE);
    } else if (!(((sint32)GET_S_LCRSIA_LnBndRiValidALCA_bool()) != 0)) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch12/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition8'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch13/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch8/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_LANE);
    } else {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch13/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition16'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch12/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch8/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_kw = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_OTHER);
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition3'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition4'/state_source'
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition6'/state_source'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Relational Operator5/Functionality'/EQ'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch3/Functionality'/Switch'
         */
    if (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) {
        rtb_Switch_aq = ((uint8)E_LCF_SysStateDirObjType_E_LCF_SSDO_TRIGGER);
    } else if (((sint32)BI_lcrsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition5'/state_source'
                 */
        rtb_Switch_aq = ((uint8)E_LCF_SysStateDirObjType_E_LCF_SSDO_RUNNING);
    } else {
        rtb_Switch_aq = rtb_DataTypeConversion_kw;
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_LCRSIA_LnBndLeValidALCA_bool'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/AND2/Functionality'/AND'
         *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/AND8/Functionality'/AND'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Relational Operator2/Functionality'/EQ'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch2/Functionality'/Switch'
         *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch5/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_j) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch'/copy1' */
        SET_S_LCRSMI_SysStateALCALe_nu(rtb_Switch_aq);
    } else if (((((sint32)rtb_LT_l1) != 0) && (((sint32) GET_S_LCRSIA_LnBndLeValidALCA_bool()) != 0)) && (((sint32) rtb_EQ_dwy) != 0)) {
        /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch'/copy1' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/from_data_definition5'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch2/Functionality'/Switch'
                 */
        SET_S_LCRSMI_SysStateALCALe_nu(((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_LN_AVL));
    } else if ((((sint32)rtb_S_ODPROP_DanRearObjFOV_RearLe_nu) != 0) && (((sint32) rtb_LT_l1) != 0)) {
        /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch'/copy1' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/from_data_definition3'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch5/Functionality'/Switch'
                 */
        SET_S_LCRSMI_SysStateALCALe_nu(((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_OBJ_IFACE_AVL));
    } else {
        /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch'/copy1' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/from_data_definition2'/state_source'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch5/Functionality'/Switch'
                 */
        SET_S_LCRSMI_SysStateALCALe_nu(((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_LN_OBJ_IF_NOT_AVL));
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/from_data_definition10'/state_source'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Relational Operator1/Functionality'/EQ'
         */
    if (((sint32)rtb_DataTypeConversion_j) != ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/from_data_definition1'/state_source'
                 *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/from_data_definition6'/state_source'
                 *  Inport: '<Root>/S_LCRSIA_LnBndRiValidALCA_bool'
                 *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/AND1/Functionality'/AND'
                 *  Logic: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/AND3/Functionality'/AND'
                 *  Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch7/Functionality'/Switch'
                 */
        if (((((sint32)rtb_LT_l1) != 0) && (((sint32) GET_S_LCRSIA_LnBndRiValidALCA_bool()) != 0)) && (((sint32)rtb_EQ_dwy) != 0)) {
            rtb_Switch_aq = ((uint8)E_LCF_SysStateDirObjType_E_LCF_SSDO_LN_AVL);
        } else if ((((sint32)rtb_LT_l1) != 0) && (((sint32) rtb_S_ODPSOP_DanRearObjBS_RearLe_nu) != 0)) {
            /* Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/from_data_definition8'/state_source'
                         */
            rtb_Switch_aq = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_OBJ_IFACE_AVL);
        } else {
            rtb_Switch_aq = ((uint8) E_LCF_SysStateDirObjType_E_LCF_SSDO_LN_OBJ_IF_NOT_AVL);
        }
        /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch4/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch1'/copy1' */
    SET_S_LCRSMI_SysStateALCARi_nu(rtb_Switch_aq);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch10'/copy1' */
    SET_D_LCRSMI_DlcLeThreshold_met(rtb_Switch_c);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch11'/copy1' */
    SET_D_LCRSMI_DlcRiThreshold_met(rtb_Mul);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch12'/copy1' */
    SET_D_LCRSMI_TlcLeThreshold_sec(rtb_Switch);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch13'/copy1' */
    SET_D_LCRSMI_TlcRiThreshold_sec(rtb_Switch_ou);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch2'/copy1' */
    SET_S_LCRSMI_FunctionAborted_bool(rtb_DataTypeConversion_f4);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch3'/copy1' */
    SET_D_LCRSMI_StrongReady_btf(rtb_sfun_setbit_i);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch4'/copy1' */
    SET_D_LCRSMI_WeakReady_btf(rtb_sfun_setbit_ic);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch5'/copy1' */
    SET_D_LCRSMI_Cancel_btf(rtb_sfun_setbit_n);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch6'/copy1' */
    SET_S_LCRSMI_ReadyToTrigger_bool(rtb_LT_l1);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch7'/copy1' */
    SET_D_LCRSMI_SysStateALCA_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch8'/copy1' */
    SET_S_LCRSMI_DangerousSide_nu(rtb_DataTypeConversion_j);
    /* SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/branch9'/copy1' */
    SET_S_LCRSMI_SysStateALCA_nu(BI_lcrsmi_SysState_nu);
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay' */
    DW_lcrsmi_Unit_Delay_DSTATE_a = rtb_Switch_h;
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrsmi_Unit_Delay_DSTATE_b = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit_Delay' */
    DW_lcrsmi_Unit_Delay_DSTATE = rtb_Switch2_i;
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay' */
    DW_lcrsmi_Unit_Delay_DSTATE_g = rtb_UnitDelay1_o;
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrsmi_Unit_Delay_DSTATE_p = rtb_GT;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit_Delay' */
    DW_lcrsmi_Unit_Delay_DSTATE_e = rtb_Mul_bd;
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling'/Template' incorporates:
         *  SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrsmi_Template_DSTATE = rtb_LT_j;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay' */
    DW_lcrsmi_Unit_Delay_DSTATE_l = rtb_Switch_lu;
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrsmi_Unit_Delay1_DSTATE = rtb_UnitDelay2;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay' */
    DW_lcrsmi_Unit_Delay_DSTATE_m = rtb_Switch2_p;
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation'/Unit_Delay2' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_SysStOffLatDMC_bool'
         */
    DW_lcrsmi_Unit_Delay2_DSTATE_m = GET_S_LCFRCV_SysStOffLatDMC_bool();
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs'/Unit Delay5' */
    DW_lcrsmi_UnitDelay5_DSTATE = rtb_DataTypeConversion_j;
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrsmi_Unit_Delay4_DSTATE = rtb_EQ_an;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3' */
    DW_lcrsmi_Unit_Delay3_DSTATE = rtb_Switch2_p4;
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrsmi_Unit_Delay1_DSTATE_n = rtb_EQ_ob;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/TimeOut'/Unit_Delay' */
    DW_lcrsmi_Unit_Delay_DSTATE_c = rtb_Switch2_hq;
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide'/Template' */
    DW_lcrsmi_Template_DSTATE_o = rtb_DataTypeConversion_bd;
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/DangerousSide'/Template1' */
    DW_lcrsmi_Template1_DSTATE = rtb_Switch_kf;
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/StateMachineInputs/Degradation'/Unit_Delay1' */
    DW_lcrsmi_Unit_Delay1_DSTATE_f = rtb_DataTypeConversion_f4;
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState'/Template' */
    DW_lcrsmi_Template_DSTATE_a = rtb_DataTypeConversion_kw;
    /* Update for UnitDelay: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState'/Template1' incorporates:
         *  Constant: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/from_data_definition12'/state_source'
         *  RelationalOperator: 'sda:LCRSMI/LCRSMI/LCRSMI_SenProcess/OPM/SysState/SysState/Relational Operator1/Functionality'/EQ'
         */
    DW_lcrsmi_Template1_DSTATE_e = (uint8)(((sint32)BI_lcrsmi_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
}
#include "Pse_LCRSMI.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
