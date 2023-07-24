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
 * File          : DPRTTG
 * Generated on  : Mon 11.03.2019 at 13:49:52 (UTC+01:00)
 * MD5           : [2002560138  2166562733  3559905229  3822990096 0](DPRTTG)
 *
 * Purpose       : <Purpose>
 * Specification : <Specification>
 *
 * Environment information:
 * Processor     : 32 Bit generic
 * Platform      : EMS3
 * SDA version   : 10.0
 * Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,70
 * Add-ons       : -
 *
 * Version management information:
 * Filename      : $Workfile: $
 * Revision      : $Revision: 1.3 $
 * Author        : $Author: Diaz Bravo, Jose Luis (uidg8685) $
 * Date          : $Date: 2019/04/05 13:17:32CEST $
 * Changes       :
 * $Log: DPRTTG.c  $
 * Revision 1.3 2019/04/05 13:17:32CEST Diaz Bravo, Jose Luis (uidg8685) 
 * B2B tests
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "DPRTTG.h"
#include "DPRTTG_private.h"
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
#define DPRTTG_START_SEC_DATA_8
#include "DPRTTG_MemMap.h"
static uint8 BI_dprttg_LogicalOperator;
/* 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 DW_dprttg_FixPtUnitDelay4_DSTATE_d;
static uint8 DW_dprttg_FixPtUnitDelay1_DSTATE;
static uint8 DW_dprttg_FixPtUnitDelay1_DSTATE_f;
static uint8 DW_dprttg_FixPtUnitDelay1_DSTATE_m;
static uint8 DW_dprttg_FixPtUnitDelay1_DSTATE_m0;
static uint8 DW_dprttg_FixPtUnitDelay1_DSTATE_p;
static uint8 DW_dprttg_Unit_Delay_DSTATE;
#define DPRTTG_STOP_SEC_DATA_8
#include "DPRTTG_MemMap.h"
#define DPRTTG_START_SEC_DATA_32
#include "DPRTTG_MemMap.h"
static float32 DW_dprttg_FixPtUnitDelay2_DSTATE;
static float32 DW_dprttg_FixPtUnitDelay4_DSTATE;
static float32 DW_dprttg_FixPtUnitDelay4_DSTATE_f;
static float32 DW_dprttg_FixPtUnitDelay4_DSTATE_m;
static float32 DW_dprttg_FixPtUnitDelay4_DSTATE_j;
static float32 DW_dprttg_FixPtUnitDelay2_DSTATE_f;
static float32 DW_dprttg_FixPtUnitDelay5_DSTATE;
static float32 DW_dprttg_FixPtUnitDelay4_DSTATE_h;
static float32 DW_dprttg_FixPtUnitDelay5_DSTATE_b;
static float32 DW_dprttg_FixPtUnitDelay4_DSTATE_c;
static float32 DW_dprttg_Unit_Delay1_DSTATE;
static float32 DW_dprttg_Unit_Delay1_DSTATE_c;
static float32 DW_dprttg_Unit_Delay1_DSTATE_i;
static float32 DW_dprttg_Unit_Delay1_DSTATE_b;
static float32 DW_dprttg_Unit_Delay1_DSTATE_e;
static float32 DW_dprttg_Unit_Delay1_DSTATE_ik;
static float32 DW_dprttg_Unit_Delay1_DSTATE_a;
static float32 DW_dprttg_Unit_Delay1_DSTATE_ac;
static float32 DW_dprttg_Unit_Delay1_DSTATE_o;
static float32 DW_dprttg_Unit_Delay1_DSTATE_bh;
static float32 DW_dprttg_Unit_Delay1_DSTATE_l;
static float32 DW_dprttg_Unit_Delay1_DSTATE_n;
static float32 DW_dprttg_Unit_Delay1_DSTATE_p;
static float32 DW_dprttg_Unit_Delay1_DSTATE_nr;
static float32 DW_dprttg_Unit_Delay1_DSTATE_e1;
static float32 DW_dprttg_Unit_Delay1_DSTATE_pg;
static float32 DW_dprttg_Unit_Delay1_DSTATE_ar;
static float32 DW_dprttg_Unit_Delay1_DSTATE_g;
static float32 DW_dprttg_Unit_Delay_1_DSTATE;
static float32 DW_dprttg_Unit_Delay_10_DSTATE;
static float32 DW_dprttg_Unit_Delay_11_DSTATE;
static float32 DW_dprttg_Unit_Delay_12_DSTATE;
static float32 DW_dprttg_Unit_Delay_13_DSTATE;
static float32 DW_dprttg_Unit_Delay_14_DSTATE;
static float32 DW_dprttg_Unit_Delay_15_DSTATE;
static float32 DW_dprttg_Unit_Delay_16_DSTATE;
static float32 DW_dprttg_Unit_Delay_17_DSTATE;
static float32 DW_dprttg_Unit_Delay_18_DSTATE;
static float32 DW_dprttg_Unit_Delay_2_DSTATE;
static float32 DW_dprttg_Unit_Delay_3_DSTATE;
static float32 DW_dprttg_Unit_Delay_4_DSTATE;
static float32 DW_dprttg_Unit_Delay_5_DSTATE;
static float32 DW_dprttg_Unit_Delay_6_DSTATE;
static float32 DW_dprttg_Unit_Delay_7_DSTATE;
static float32 DW_dprttg_Unit_Delay_8_DSTATE;
static float32 DW_dprttg_Unit_Delay_9_DSTATE;
#define DPRTTG_STOP_SEC_DATA_32
#include "DPRTTG_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPRTTG/DPRTTG/INI'/DPRTTG_SenReset'
 * Block description for: 'sda:DPRTTG/DPRTTG/INI'/DPRTTG_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRTTG_SenReset
#include "Pse_DPRTTG.h"
/* Short description: Not synchronized with ARAMIS */
void DPRTTG_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant1'/Constant' */
    SET_S_DPRTTG_LeCridrBndPosX0_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant10'/Constant' */
    SET_S_DPRTTG_RiCridrBndCrv_1pm(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant11'/Constant' */
    SET_S_DPRTTG_RiCridrBndCrvChng_1pm2(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant12'/Constant' */
    SET_S_DPRTTG_RiCridrBndLength_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant13'/Constant' */
    SET_S_DPRTTG_TgtTrajPosX0_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant14'/Constant' */
    SET_S_DPRTTG_TgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant15'/Constant' */
    SET_S_DPRTTG_TgtTrajHeadAng_rad(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant16'/Constant' */
    SET_S_DPRTTG_TgtTrajCrv_1pm(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant17'/Constant' */
    SET_S_DPRTTG_TgtTrajLength_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant19'/Constant' */
    SET_S_DPRTTG_LeTgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant2'/Constant' */
    SET_S_DPRTTG_LeCridrBndPosY0_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant20'/Constant' */
    SET_S_DPRTTG_RiTgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant24'/Constant' */
    SET_S_DPRTTG_TgtTrajCrvChng_1pm2(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant3'/Constant' */
    SET_S_DPRTTG_LeCridrBndHeadAng_rad(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant4'/Constant' */
    SET_S_DPRTTG_LeCridrBndCrv_1pm(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant5'/Constant' */
    SET_S_DPRTTG_LeCridrBndCrvChng_1pm2(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant6'/Constant' */
    SET_S_DPRTTG_LeCridrBndLength_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant7'/Constant' */
    SET_S_DPRTTG_RiCridrBndPosX0_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant8'/Constant' */
    SET_S_DPRTTG_RiCridrBndPosY0_met(0.0F);
    /* Constant: 'sda:DPRTTG/DPRTTG/INI/DPRTTG_SenReset/Constant9'/Constant' */
    SET_S_DPRTTG_RiCridrBndHeadAng_rad(0.0F);
}
#include "Pse_DPRTTG.h"
/*
 * Output and update for function-call system: 'sda:DPRTTG/DPRTTG'/DPRTTG_SenProcess'
 * Block description for: 'sda:DPRTTG/DPRTTG'/DPRTTG_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRTTG_SenProcess
#include "Pse_DPRTTG.h"
/* Short description: Not synchronized with ARAMIS */
void DPRTTG_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_S_DPRTTG_LeCridrBndPosX0_met;
    float32 rtb_S_DPRTTG_RiCridrBndCrv_1pm;
    float32 rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2;
    float32 rtb_S_DPRTTG_RiCridrBndLength_met;
    float32 rtb_S_DPRTTG_TgtTrajPosX0_met;
    float32 rtb_S_DPRTTG_TgtTrajPosY0_met;
    float32 rtb_S_DPRTTG_TgtTrajHeadAng_rad;
    float32 rtb_S_DPRTTG_TgtTrajCrv_1pm;
    float32 rtb_S_DPRTTG_TgtTrajCrvChng_1pm2;
    float32 rtb_S_DPRTTG_TgtTrajLength_met;
    float32 rtb_S_DPRTTG_LeCridrBndPosY0_met;
    float32 rtb_S_DPRTTG_LeCridrBndHeadAng_rad;
    float32 rtb_S_DPRTTG_LeCridrBndCrv_1pm;
    float32 rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2;
    float32 rtb_S_DPRTTG_LeCridrBndLength_met;
    float32 rtb_S_DPRTTG_RiCridrBndPosX0_met;
    float32 rtb_S_DPRTTG_RiCridrBndPosY0_met;
    float32 rtb_S_DPRTTG_RiCridrBndHeadAng_rad;
    float32 rtb_Div;
    float32 rtb_Unit_Delay1;
    float32 rtb_SFunction;
    float32 rtb_Div_d;
    float32 rtb_Unit_Delay1_i;
    float32 rtb_SFunction_g;
    float32 rtb_Div_b;
    float32 rtb_Unit_Delay1_p;
    float32 rtb_SFunction_o;
    float32 rtb_Div_h;
    float32 rtb_Unit_Delay1_if;
    float32 rtb_SFunction_e;
    float32 rtb_Div_f;
    float32 rtb_Unit_Delay1_e;
    float32 rtb_SFunction_a;
    float32 rtb_Div_m;
    float32 rtb_Unit_Delay1_o;
    float32 rtb_SFunction_p;
    float32 rtb_Div_e;
    float32 rtb_Unit_Delay1_o5;
    float32 rtb_SFunction_b;
    float32 rtb_Div_o;
    float32 rtb_Unit_Delay1_c;
    float32 rtb_SFunction_d;
    float32 rtb_Div_hs;
    float32 rtb_Unit_Delay1_h;
    float32 rtb_SFunction_c;
    float32 rtb_Div_j;
    float32 rtb_Unit_Delay1_pk;
    float32 rtb_SFunction_n;
    float32 rtb_Div_a;
    float32 rtb_Unit_Delay1_m;
    float32 rtb_SFunction_nx;
    float32 rtb_Div_bl;
    float32 rtb_Unit_Delay1_a;
    float32 rtb_SFunction_aw;
    float32 rtb_Div_br;
    float32 rtb_Unit_Delay1_o2;
    float32 rtb_SFunction_ai;
    float32 rtb_Div_mx;
    float32 rtb_Unit_Delay1_ifv;
    float32 rtb_SFunction_h;
    float32 rtb_Div_dt;
    float32 rtb_Unit_Delay1_n;
    float32 rtb_SFunction_k;
    float32 rtb_Div_c;
    float32 rtb_Unit_Delay1_oo;
    float32 rtb_SFunction_py;
    float32 rtb_Div_ey;
    float32 rtb_Unit_Delay1_nu;
    float32 rtb_SFunction_nxq;
    float32 rtb_Div_n;
    float32 rtb_Unit_Delay1_j;
    float32 rtb_SFunction_l;
    uint8 rtb_EQ_j0;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_g;
    uint8 rtb_EQ_e;
    uint8 rtb_DataTypeConversion_o;
    float32 rtb_S_DPRTTG_TgtTrajPosX0_met_m;
    float32 rtb_S_DPRTTG_TgtTrajPosY0_met_c;
    float32 rtb_S_DPRTTG_TgtTrajHeadAng_rad_h;
    float32 rtb_S_DPRTTG_TgtTrajCrv_1pm_hj;
    float32 rtb_S_DPRTTG_TgtTrajCrvChng_1pm2_p;
    float32 rtb_S_DPRTTG_TgtTrajLength_met_i;
    float32 rtb_S_DPRTTG_LeCridrBndPosY0_met_eq;
    float32 rtb_S_DPRTTG_LeCridrBndHeadAng_rad_m;
    float32 rtb_S_DPRTTG_LeCridrBndCrv_1pm_c;
    float32 rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2_p;
    float32 rtb_S_DPRTTG_LeCridrBndLength_met_m;
    float32 rtb_S_DPRTTG_RiCridrBndPosX0_met_a;
    float32 rtb_S_DPRTTG_RiCridrBndPosY0_met_l;
    float32 rtb_S_DPRTTG_RiCridrBndHeadAng_rad_j;
    float32 rtb_Switch;
    float32 rtb_Switch_l1;
    float32 rtb_Switch_n4;
    float32 rtb_Switch_b;
    float32 rtb_Sum_o;
    float32 rtb_Switch_n;
    float32 rtb_Switch_ds;
    float32 rtb_Switch_g;
    float32 rtb_Switch_l;
    float32 rtb_Sum_pl;
    float32 rtb_Sum;
    float32 rtb_Sum_d;
    float32 rtb_Sum_p;
    float32 rtb_Sum_f;
    /* RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ9/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
         */
    rtb_EQ_j0 = (uint8)(((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)));
    /* DataTypeConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))));
    /* DataTypeConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition8'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ3/Functionality'/EQ'
         */
    rtb_DataTypeConversion_g = (uint8)((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/LaneRoadWidth/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPREP_LeRePosY0_met'
         */
    rtb_Sum = GET_S_ABPREP_LeRePosY0_met() - GET_S_ABPLBP_RiLnClthPosY0_met();
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_LaneWidthRDP_met'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch3/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft'/FixPt Unit Delay2'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft'/FixPt Unit Delay4'
         */
    if (((sint32)DW_dprttg_FixPtUnitDelay4_DSTATE_d) != 0) {
        rtb_Switch = DW_dprttg_FixPtUnitDelay2_DSTATE;
    } else if (((sint32)rtb_EQ_j0) != 0) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch3/Functionality'/Switch' */
        rtb_Switch = rtb_Sum;
    } else {
        rtb_Switch = GET_S_DPRSIA_LaneWidthRDP_met();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Constant1'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Constant2'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/P_DPLTTG_TargetLaneCenterEnable_nu1'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/P_DPLTTG_TargetLaneCenterEnable_nu2'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeRePosY0_met'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/AND/Functionality'/AND'
         *  MinMax: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Min/Functionality'/Min'
         *  Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Div/Functionality/DivDefault'/Div'
         *  Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Div1/Functionality/DivDefault'/Div'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Sum1/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Sum3/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Sum8/Functionality'/Sum'
         */
    if ((((sint32)rtb_EQ_j0) != 0) && (((sint32)GET_P_DPRTTG_TgtCntrRdEnable_bool()) != 0)) {
        rtb_Switch_l1 = GET_S_ABPREP_LeRePosY0_met() - (rtb_Sum / 2.0F);
    } else {
        rtb_Switch_l1 = GET_S_ABPREP_LeRePosY0_met() - ((GET_P_VEH_Width_met() / 2.0F) + f32_min_f32_f32(GET_P_DPRTTG_TargetLatDistRe_met(), GET_P_DPRTTG_TgtMaxDistanceRe_met()));
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Switch10/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/from_data_definition'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Relational Operator1/Functionality'/EQ'
         */
    rtb_EQ_j0 = (uint8)((((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))));
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/GT/Functionality'/GT'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Switch1/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Neg/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev'/FixPt Unit Delay4'
         */
    if (((sint32)rtb_EQ_j0) != 0) {
        rtb_Sum = DW_dprttg_FixPtUnitDelay4_DSTATE_f;
    } else if ((-GET_P_DPRTTG_TgtMaxLatDevRe_met()) > rtb_Switch_l1) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
                 *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Sum6/Functionality'/Sum'
                 *  UnaryMinus: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Neg/Functionality'/Unary Minus'
                 */
        rtb_Sum = rtb_Switch_l1 - (-GET_P_DPRTTG_TgtMaxLatDevRe_met());
    } else {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Constant1'/Constant'
                 */
        rtb_Sum = 0.0F;
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Switch10/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_LeRePosY0_met'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev/Sum7/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Sum7/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe'/FixPt Unit Delay4'
         */
    if (((sint32)DW_dprttg_FixPtUnitDelay1_DSTATE) != 0) {
        rtb_Switch_l1 = DW_dprttg_FixPtUnitDelay4_DSTATE;
    } else {
        rtb_Switch_l1 = GET_S_ABPREP_LeRePosY0_met() - (rtb_Switch_l1 - rtb_Sum);
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/Sum2/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPREP_LeRePosY0_met'
         */
    rtb_Sum_o = GET_S_ABPREP_LeRePosY0_met() - rtb_Switch_l1;
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Constant2'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/P_DPLTTG_TargetLaneCenterEnable_nu1'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/P_DPLTTG_TargetLaneCenterEnable_nu2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_DPRSIA_TgtCntrLnEnable_bool'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/AND1/Functionality'/AND'
         *  MinMax: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Min/Functionality'/Min'
         *  Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Div/Functionality/DivDefault'/Div'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Sum1/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Sum8/Functionality'/Sum'
         */
    if ((((sint32)GET_S_DPRSIA_TgtCntrLnEnable_bool()) != 0) && (((sint32) GET_P_DPRTTG_TgtCntrLnEnable_bool()) != 0)) {
        rtb_Switch_n4 = GET_S_ABPLBP_CntrLnClthPosY0_met();
    } else {
        rtb_Switch_n4 = GET_S_ABPLBP_LeLnClthPosY0_met() - ((GET_P_VEH_Width_met() / 2.0F) + f32_min_f32_f32(GET_P_DPRTTG_TargetLatDistLn_met(), GET_P_DPRTTG_TgtMaxDistanceLn_met()));
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Switch10/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/GT/Functionality'/GT'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Switch1/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Neg/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev'/FixPt Unit Delay4'
         */
    if (((sint32)rtb_EQ_j0) != 0) {
        rtb_Switch_b = DW_dprttg_FixPtUnitDelay4_DSTATE_j;
    } else if ((-GET_P_DPRTTG_TgtMaxLatDevLn_met()) > rtb_Switch_n4) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
                 *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Sum6/Functionality'/Sum'
                 *  UnaryMinus: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Neg/Functionality'/Unary Minus'
                 */
        rtb_Switch_b = rtb_Switch_n4 - (-GET_P_DPRTTG_TgtMaxLatDevLn_met());
    } else {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Constant1'/Constant'
                 */
        rtb_Switch_b = 0.0F;
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Switch10/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev/Sum7/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Sum7/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn'/FixPt Unit Delay4'
         */
    if (((sint32)DW_dprttg_FixPtUnitDelay1_DSTATE_f) != 0) {
        rtb_Switch_n4 = DW_dprttg_FixPtUnitDelay4_DSTATE_m;
    } else {
        rtb_Switch_n4 = GET_S_ABPLBP_LeLnClthPosY0_met() - (rtb_Switch_n4 - rtb_Switch_b);
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/Sum2/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         */
    rtb_Sum_p = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_Switch_n4;
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition9'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Constant4'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition10'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/OR2/Functionality'/OR'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/EQ7/Functionality'/EQ'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch6/Functionality'/Switch'
         */
    if ((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) {
        SET_S_DPRTTG_LeTgtTrajPosY0_met(rtb_Sum_o);
    } else if ((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH)))) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch6/Functionality'/Switch' */
        SET_S_DPRTTG_LeTgtTrajPosY0_met(rtb_Sum_p);
    } else {
        SET_S_DPRTTG_LeTgtTrajPosY0_met(0.0F);
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ9/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
         */
    rtb_EQ_e = (uint8)(((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)));
    /* DataTypeConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_o = (uint8)((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))));
    /* Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/LaneRoadWidth/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPREP_RiRePosY0_met'
         */
    rtb_Sum_d = GET_S_ABPLBP_LeLnClthPosY0_met() - GET_S_ABPREP_RiRePosY0_met();
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_LaneWidthRDP_met'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch3/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight'/FixPt Unit Delay2'
         */
    if (((sint32)DW_dprttg_FixPtUnitDelay1_DSTATE_m) != 0) {
        rtb_Switch_n = DW_dprttg_FixPtUnitDelay2_DSTATE_f;
    } else if (((sint32)rtb_EQ_e) != 0) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch3/Functionality'/Switch' */
        rtb_Switch_n = rtb_Sum_d;
    } else {
        rtb_Switch_n = GET_S_DPRSIA_LaneWidthRDP_met();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Constant2'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Constant3'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/P_DPLTTG_TargetLaneCenterEnable_nu1'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/P_DPLTTG_TargetLaneCenterEnable_nu2'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiRePosY0_met'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/AND/Functionality'/AND'
         *  MinMax: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Min1/Functionality'/Min'
         *  Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Div/Functionality/DivDefault'/Div'
         *  Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Div1/Functionality/DivDefault'/Div'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Sum1/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Sum3/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Sum8/Functionality'/Sum'
         */
    if ((((sint32)rtb_EQ_e) != 0) && (((sint32)GET_P_DPRTTG_TgtCntrRdEnable_bool()) != 0)) {
        rtb_Switch_ds = (rtb_Sum_d / 2.0F) + GET_S_ABPREP_RiRePosY0_met();
    } else {
        rtb_Switch_ds = ((GET_P_VEH_Width_met() / 2.0F) + f32_min_f32_f32 (GET_P_DPRTTG_TargetLatDistRe_met(), GET_P_DPRTTG_TgtMaxDistanceRe_met())) + GET_S_ABPREP_RiRePosY0_met();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/LT/Functionality'/LT'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev'/FixPt Unit Delay4'
         */
    if (((sint32)rtb_EQ_j0) != 0) {
        rtb_Sum_d = DW_dprttg_FixPtUnitDelay4_DSTATE_h;
    } else if (GET_P_DPRTTG_TgtMaxLatDevRe_met() < rtb_Switch_ds) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
                 *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/Sum6/Functionality'/Sum'
                 */
        rtb_Sum_d = rtb_Switch_ds - GET_P_DPRTTG_TgtMaxLatDevRe_met();
    } else {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/Constant1'/Constant'
                 */
        rtb_Sum_d = 0.0F;
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/Switch10/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Switch11/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_RiRePosY0_met'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev/Sum7/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Sum6/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe'/FixPt Unit Delay5'
         */
    if (((sint32)DW_dprttg_FixPtUnitDelay1_DSTATE_m0) != 0) {
        rtb_Switch_ds = DW_dprttg_FixPtUnitDelay5_DSTATE;
    } else {
        rtb_Switch_ds = (rtb_Switch_ds - rtb_Sum_d) - GET_S_ABPREP_RiRePosY0_met();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Switch11/Functionality'/Switch' */
    /* Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/Sum9/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPREP_RiRePosY0_met'
         */
    rtb_Sum_pl = GET_S_ABPREP_RiRePosY0_met() + rtb_Switch_ds;
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Constant2'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/P_DPLTTG_TargetLaneCenterEnable_nu1'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/P_DPLTTG_TargetLaneCenterEnable_nu2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Inport: '<Root>/S_DPRSIA_TgtCntrLnEnable_bool'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/AND1/Functionality'/AND'
         *  MinMax: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Min1/Functionality'/Min'
         *  Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Div/Functionality/DivDefault'/Div'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Sum1/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Sum8/Functionality'/Sum'
         */
    if ((((sint32)GET_S_DPRSIA_TgtCntrLnEnable_bool()) != 0) && (((sint32) GET_P_DPRTTG_TgtCntrLnEnable_bool()) != 0)) {
        rtb_Switch_g = GET_S_ABPLBP_CntrLnClthPosY0_met();
    } else {
        rtb_Switch_g = ((GET_P_VEH_Width_met() / 2.0F) + f32_min_f32_f32 (GET_P_DPRTTG_TargetLatDistLn_met(), GET_P_DPRTTG_TgtMaxDistanceLn_met())) + GET_S_ABPLBP_RiLnClthPosY0_met();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Switch10/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/LT/Functionality'/LT'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev'/FixPt Unit Delay4'
         */
    if (((sint32)rtb_EQ_j0) != 0) {
        rtb_Switch_l = DW_dprttg_FixPtUnitDelay4_DSTATE_c;
    } else if (GET_P_DPRTTG_TgtMaxLatDevLn_met() < rtb_Switch_g) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
                 *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/Sum6/Functionality'/Sum'
                 */
        rtb_Switch_l = rtb_Switch_g - GET_P_DPRTTG_TgtMaxLatDevLn_met();
    } else {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/Constant1'/Constant'
                 */
        rtb_Switch_l = 0.0F;
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/Switch10/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Switch11/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev/Sum7/Functionality'/Sum'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Sum6/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn'/FixPt Unit Delay5'
         */
    if (((sint32)DW_dprttg_FixPtUnitDelay1_DSTATE_p) != 0) {
        rtb_Switch_g = DW_dprttg_FixPtUnitDelay5_DSTATE_b;
    } else {
        rtb_Switch_g = (rtb_Switch_g - rtb_Switch_l) - GET_S_ABPLBP_RiLnClthPosY0_met();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Switch11/Functionality'/Switch' */
    /* Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/Sum9/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         */
    rtb_Sum_f = GET_S_ABPLBP_RiLnClthPosY0_met() + rtb_Switch_g;
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Constant4'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition10'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/OR2/Functionality'/OR'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ7/Functionality'/EQ'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch6/Functionality'/Switch'
         */
    if ((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) {
        SET_S_DPRTTG_RiTgtTrajPosY0_met(rtb_Sum_pl);
    } else if ((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH)))) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch6/Functionality'/Switch' */
        SET_S_DPRTTG_RiTgtTrajPosY0_met(rtb_Sum_f);
    } else {
        SET_S_DPRTTG_RiTgtTrajPosY0_met(0.0F);
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPRSMI_DangerousSide_nu'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Relational Operator3/Functionality'/EQ'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch'
         */
    if (((sint32)GET_S_DPRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant4'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant5'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant6'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant7'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant8'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant9'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant4'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant7'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant8'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant9'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant4'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant5'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant6'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant7'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant8'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant9'/Constant'
                 *  Inport: '<Root>/S_ABPREP_LeReClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPREP_LeReClthPosX0_met'
                 *  Inport: '<Root>/S_ABPREP_LeReHeading_rad'
                 *  Inport: '<Root>/S_ABPREP_LeReLength_met'
                 *  Inport: '<Root>/S_ABPREP_LeRePosY0_met'
                 *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Sum2/Functionality'/Sum'
                 *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_g) != 0) {
            rtb_S_DPRTTG_LeCridrBndPosX0_met = GET_S_ABPREP_LeReClthPosX0_met();
            rtb_S_DPRTTG_RiCridrBndCrv_1pm = GET_S_ABPREP_LeReClthCrv_1pm();
            rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2 = GET_S_ABPREP_LeReClthCrvChng_1pm2();
            rtb_S_DPRTTG_RiCridrBndLength_met = GET_S_ABPREP_LeReLength_met();
            rtb_S_DPRTTG_TgtTrajPosX0_met = GET_S_ABPREP_LeReClthPosX0_met();
            rtb_S_DPRTTG_TgtTrajPosY0_met = rtb_Sum_o;
            rtb_S_DPRTTG_TgtTrajHeadAng_rad = GET_S_ABPREP_LeReHeading_rad();
            rtb_S_DPRTTG_TgtTrajCrv_1pm = GET_S_ABPREP_LeReClthCrv_1pm();
            rtb_S_DPRTTG_TgtTrajCrvChng_1pm2 = GET_S_ABPREP_LeReClthCrvChng_1pm2();
            rtb_S_DPRTTG_TgtTrajLength_met = GET_S_ABPREP_LeReLength_met();
            rtb_S_DPRTTG_LeCridrBndPosY0_met = GET_S_ABPREP_LeRePosY0_met();
            rtb_S_DPRTTG_LeCridrBndHeadAng_rad = GET_S_ABPREP_LeReHeading_rad();
            rtb_S_DPRTTG_LeCridrBndCrv_1pm = GET_S_ABPREP_LeReClthCrv_1pm();
            rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2 = GET_S_ABPREP_LeReClthCrvChng_1pm2();
            rtb_S_DPRTTG_LeCridrBndLength_met = GET_S_ABPREP_LeReLength_met();
            rtb_S_DPRTTG_RiCridrBndPosX0_met = GET_S_ABPREP_LeReClthPosX0_met();
            rtb_Sum_o = GET_S_ABPREP_LeRePosY0_met() - rtb_Switch;
            rtb_S_DPRTTG_RiCridrBndHeadAng_rad = GET_S_ABPREP_LeReHeading_rad();
        } else {
            if (((sint32)rtb_DataTypeConversion) != 0) {
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                                 */
                rtb_S_DPRTTG_LeCridrBndPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                                 */
                rtb_S_DPRTTG_RiCridrBndCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                                 */
                rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                                 */
                rtb_S_DPRTTG_RiCridrBndLength_met = GET_S_ABPLBP_LeLnClthLength_met();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                                 */
                rtb_S_DPRTTG_TgtTrajPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' */
                rtb_S_DPRTTG_TgtTrajPosY0_met = rtb_Sum_p;
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                                 */
                rtb_S_DPRTTG_TgtTrajHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                                 */
                rtb_S_DPRTTG_TgtTrajCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                                 */
                rtb_S_DPRTTG_TgtTrajCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                                 */
                rtb_S_DPRTTG_TgtTrajLength_met = GET_S_ABPLBP_LeLnClthLength_met();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                                 */
                rtb_S_DPRTTG_LeCridrBndPosY0_met = GET_S_ABPLBP_LeLnClthPosY0_met();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                                 */
                rtb_S_DPRTTG_LeCridrBndHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                                 */
                rtb_S_DPRTTG_LeCridrBndCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                                 */
                rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                                 */
                rtb_S_DPRTTG_LeCridrBndLength_met = GET_S_ABPLBP_LeLnClthLength_met();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                                 */
                rtb_S_DPRTTG_RiCridrBndPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                                 *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Sum1/Functionality'/Sum'
                                 */
                rtb_Sum_o = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_Switch;
            } else {
                rtb_S_DPRTTG_LeCridrBndPosX0_met = 0.0F;
                rtb_S_DPRTTG_RiCridrBndCrv_1pm = 0.0F;
                rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2 = 0.0F;
                rtb_S_DPRTTG_RiCridrBndLength_met = 0.0F;
                rtb_S_DPRTTG_TgtTrajPosX0_met = 0.0F;
                rtb_S_DPRTTG_TgtTrajPosY0_met = 0.0F;
                rtb_S_DPRTTG_TgtTrajHeadAng_rad = 0.0F;
                rtb_S_DPRTTG_TgtTrajCrv_1pm = 0.0F;
                rtb_S_DPRTTG_TgtTrajCrvChng_1pm2 = 0.0F;
                rtb_S_DPRTTG_TgtTrajLength_met = 0.0F;
                rtb_S_DPRTTG_LeCridrBndPosY0_met = 10.0F;
                rtb_S_DPRTTG_LeCridrBndHeadAng_rad = 0.0F;
                rtb_S_DPRTTG_LeCridrBndCrv_1pm = 0.0F;
                rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2 = 0.0F;
                rtb_S_DPRTTG_LeCridrBndLength_met = 0.0F;
                rtb_S_DPRTTG_RiCridrBndPosX0_met = 0.0F;
                /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant4'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant5'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant6'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant7'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant8'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant9'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant4'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant5'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant7'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant8'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant9'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant4'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant5'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant6'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant7'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant8'/Constant'
                                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant9'/Constant'
                                 *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch'
                                 */
                rtb_Sum_o = -10.0F;
            }
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant4'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant5'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant6'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant7'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant8'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Left/Constant9'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant4'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant6'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant7'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant8'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Right/Constant9'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant4'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant5'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant6'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant7'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant8'/Constant'
                         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Target/Constant9'/Constant'
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch'
                         */
            if (((sint32)rtb_DataTypeConversion) != 0) {
                rtb_S_DPRTTG_RiCridrBndHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
            } else {
                rtb_S_DPRTTG_RiCridrBndHeadAng_rad = 0.0F;
            }
            /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch2/Functionality'/Switch' */
        }
        /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/Switch1/Functionality'/Switch' */
        rtb_S_DPRTTG_RiCridrBndPosY0_met = rtb_Sum_o;
    } else if (((sint32)GET_S_DPRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition6'/state_source'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/from_data_definition8'/state_source'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Left/Constant4'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Left/Constant5'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Left/Constant6'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Left/Constant7'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Left/Constant8'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Left/Constant9'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Right/Constant4'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Right/Constant5'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Right/Constant6'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Right/Constant7'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Right/Constant8'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Right/Constant9'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Target/Constant4'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Target/Constant5'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Target/Constant6'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Target/Constant7'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Target/Constant8'/Constant'
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Target/Constant9'/Constant'
                 *  Inport: '<Root>/S_ABPREP_RiReClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPREP_RiReClthPosX0_met'
                 *  Inport: '<Root>/S_ABPREP_RiReHeading_rad'
                 *  Inport: '<Root>/S_ABPREP_RiReLength_met'
                 *  Inport: '<Root>/S_ABPREP_RiRePosY0_met'
                 *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
                 *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/OR1/Functionality'/OR'
                 *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ2/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/EQ3/Functionality'/EQ'
                 *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch'
                 */
        if ((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) {
            rtb_S_DPRTTG_LeCridrBndPosX0_met = GET_S_ABPREP_RiReClthPosX0_met();
            rtb_S_DPRTTG_RiCridrBndCrv_1pm = GET_S_ABPREP_RiReClthCrv_1pm();
            rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2 = GET_S_ABPREP_RiReClthCrvChng_1pm2();
            rtb_S_DPRTTG_RiCridrBndLength_met = GET_S_ABPREP_RiReLength_met();
            rtb_S_DPRTTG_TgtTrajPosX0_met = GET_S_ABPREP_RiReClthPosX0_met();
            rtb_S_DPRTTG_TgtTrajPosY0_met = rtb_Sum_pl;
            rtb_S_DPRTTG_TgtTrajHeadAng_rad = GET_S_ABPREP_RiReHeading_rad();
            rtb_S_DPRTTG_TgtTrajCrv_1pm = GET_S_ABPREP_RiReClthCrv_1pm();
            rtb_S_DPRTTG_TgtTrajCrvChng_1pm2 = GET_S_ABPREP_RiReClthCrvChng_1pm2();
            rtb_S_DPRTTG_TgtTrajLength_met = GET_S_ABPREP_RiReLength_met();
            rtb_S_DPRTTG_LeCridrBndPosY0_met = rtb_Switch_n + GET_S_ABPREP_RiRePosY0_met();
            rtb_S_DPRTTG_LeCridrBndHeadAng_rad = GET_S_ABPREP_RiReHeading_rad();
            rtb_S_DPRTTG_LeCridrBndCrv_1pm = GET_S_ABPREP_RiReClthCrv_1pm();
            rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2 = GET_S_ABPREP_RiReClthCrvChng_1pm2();
            rtb_S_DPRTTG_LeCridrBndLength_met = GET_S_ABPREP_RiReLength_met();
            rtb_S_DPRTTG_RiCridrBndPosX0_met = GET_S_ABPREP_RiReClthPosX0_met();
            rtb_S_DPRTTG_RiCridrBndPosY0_met = GET_S_ABPREP_RiRePosY0_met();
            rtb_S_DPRTTG_RiCridrBndHeadAng_rad = GET_S_ABPREP_RiReHeading_rad();
        } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                         */
            rtb_S_DPRTTG_LeCridrBndPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         */
            rtb_S_DPRTTG_RiCridrBndCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                         */
            rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                         */
            rtb_S_DPRTTG_RiCridrBndLength_met = GET_S_ABPLBP_RiLnClthLength_met();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                         */
            rtb_S_DPRTTG_TgtTrajPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' */
            rtb_S_DPRTTG_TgtTrajPosY0_met = rtb_Sum_f;
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                         */
            rtb_S_DPRTTG_TgtTrajHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         */
            rtb_S_DPRTTG_TgtTrajCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                         */
            rtb_S_DPRTTG_TgtTrajCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                         */
            rtb_S_DPRTTG_TgtTrajLength_met = GET_S_ABPLBP_RiLnClthLength_met();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Sum/Functionality'/Sum'
                         */
            rtb_S_DPRTTG_LeCridrBndPosY0_met = rtb_Switch_n + GET_S_ABPLBP_RiLnClthPosY0_met();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                         */
            rtb_S_DPRTTG_LeCridrBndHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         */
            rtb_S_DPRTTG_LeCridrBndCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                         */
            rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                         */
            rtb_S_DPRTTG_LeCridrBndLength_met = GET_S_ABPLBP_RiLnClthLength_met();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                         */
            rtb_S_DPRTTG_RiCridrBndPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                         */
            rtb_S_DPRTTG_RiCridrBndPosY0_met = GET_S_ABPLBP_RiLnClthPosY0_met();
            /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                         */
            rtb_S_DPRTTG_RiCridrBndHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
        } else {
            rtb_S_DPRTTG_LeCridrBndPosX0_met = 0.0F;
            rtb_S_DPRTTG_RiCridrBndCrv_1pm = 0.0F;
            rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2 = 0.0F;
            rtb_S_DPRTTG_RiCridrBndLength_met = 0.0F;
            rtb_S_DPRTTG_TgtTrajPosX0_met = 0.0F;
            rtb_S_DPRTTG_TgtTrajPosY0_met = 0.0F;
            rtb_S_DPRTTG_TgtTrajHeadAng_rad = 0.0F;
            rtb_S_DPRTTG_TgtTrajCrv_1pm = 0.0F;
            rtb_S_DPRTTG_TgtTrajCrvChng_1pm2 = 0.0F;
            rtb_S_DPRTTG_TgtTrajLength_met = 0.0F;
            rtb_S_DPRTTG_LeCridrBndPosY0_met = 10.0F;
            rtb_S_DPRTTG_LeCridrBndHeadAng_rad = 0.0F;
            rtb_S_DPRTTG_LeCridrBndCrv_1pm = 0.0F;
            rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2 = 0.0F;
            rtb_S_DPRTTG_LeCridrBndLength_met = 0.0F;
            rtb_S_DPRTTG_RiCridrBndPosX0_met = 0.0F;
            rtb_S_DPRTTG_RiCridrBndPosY0_met = -10.0F;
            rtb_S_DPRTTG_RiCridrBndHeadAng_rad = 0.0F;
        }
        /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/Switch1/Functionality'/Switch' */
    } else {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Left/Constant4'/Constant'
                 */
        rtb_S_DPRTTG_LeCridrBndPosX0_met = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Right/Constant7'/Constant'
                 */
        rtb_S_DPRTTG_RiCridrBndCrv_1pm = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Right/Constant8'/Constant'
                 */
        rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2 = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Right/Constant9'/Constant'
                 */
        rtb_S_DPRTTG_RiCridrBndLength_met = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Target/Constant4'/Constant'
                 */
        rtb_S_DPRTTG_TgtTrajPosX0_met = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Target/Constant5'/Constant'
                 */
        rtb_S_DPRTTG_TgtTrajPosY0_met = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Target/Constant6'/Constant'
                 */
        rtb_S_DPRTTG_TgtTrajHeadAng_rad = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Target/Constant7'/Constant'
                 */
        rtb_S_DPRTTG_TgtTrajCrv_1pm = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Target/Constant8'/Constant'
                 */
        rtb_S_DPRTTG_TgtTrajCrvChng_1pm2 = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Target/Constant9'/Constant'
                 */
        rtb_S_DPRTTG_TgtTrajLength_met = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Left/Constant5'/Constant'
                 */
        rtb_S_DPRTTG_LeCridrBndPosY0_met = 10.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Left/Constant6'/Constant'
                 */
        rtb_S_DPRTTG_LeCridrBndHeadAng_rad = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Left/Constant7'/Constant'
                 */
        rtb_S_DPRTTG_LeCridrBndCrv_1pm = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Left/Constant8'/Constant'
                 */
        rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2 = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Left/Constant9'/Constant'
                 */
        rtb_S_DPRTTG_LeCridrBndLength_met = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Right/Constant4'/Constant'
                 */
        rtb_S_DPRTTG_RiCridrBndPosX0_met = 0.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Right/Constant5'/Constant'
                 */
        rtb_S_DPRTTG_RiCridrBndPosY0_met = -10.0F;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Right/Constant6'/Constant'
                 */
        rtb_S_DPRTTG_RiCridrBndHeadAng_rad = 0.0F;
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/from_data_definition'/state_source'
         *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
         */
    rtb_DataTypeConversion = (uint8)(((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj'/Unit_Delay'
         */
    BI_dprttg_LogicalOperator = (uint8)((!(((sint32)DW_dprttg_Unit_Delay_DSTATE) != 0)) && (((sint32)rtb_DataTypeConversion) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING'/fcg' */
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckLe/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckLe/Constant'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckLe/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckLe/GT/Functionality'/GT'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckLe/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_DPRTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Sum_o = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Sum_o = GET_P_DPRTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckLe/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckLe/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckLe/Constant1'/Constant'
         */
    rtb_Sum_o = f32_max_f32_f32(rtb_Sum_o, 1.0E-5F);
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1 = DW_dprttg_Unit_Delay1_DSTATE;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction = rtb_S_DPRTTG_LeCridrBndPosX0_met;
    } else {
        rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay1, rtb_S_DPRTTG_LeCridrBndPosX0_met, rtb_Div);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_d = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_i = DW_dprttg_Unit_Delay1_DSTATE_c;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_g = rtb_S_DPRTTG_LeCridrBndPosY0_met;
    } else {
        rtb_SFunction_g = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_i, rtb_S_DPRTTG_LeCridrBndPosY0_met, rtb_Div_d);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_b = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_p = DW_dprttg_Unit_Delay1_DSTATE_i;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_o = rtb_S_DPRTTG_LeCridrBndHeadAng_rad;
    } else {
        rtb_SFunction_o = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_p, rtb_S_DPRTTG_LeCridrBndHeadAng_rad, rtb_Div_b);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_h = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_if = DW_dprttg_Unit_Delay1_DSTATE_b;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_e = rtb_S_DPRTTG_LeCridrBndCrv_1pm;
    } else {
        rtb_SFunction_e = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_if, rtb_S_DPRTTG_LeCridrBndCrv_1pm, rtb_Div_h);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_f = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_e = DW_dprttg_Unit_Delay1_DSTATE_e;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_a = rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2;
    } else {
        rtb_SFunction_a = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_e, rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2, rtb_Div_f);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_m = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_o = DW_dprttg_Unit_Delay1_DSTATE_ik;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_p = rtb_S_DPRTTG_LeCridrBndLength_met;
    } else {
        rtb_SFunction_p = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_o, rtb_S_DPRTTG_LeCridrBndLength_met, rtb_Div_m);
    }
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckRi/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckRi/Constant'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckRi/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckRi/GT/Functionality'/GT'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckRi/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_DPRTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Sum_o = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Sum_o = GET_P_DPRTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckRi/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckRi/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckRi/Constant1'/Constant'
         */
    rtb_Sum_o = f32_max_f32_f32(rtb_Sum_o, 1.0E-5F);
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_e = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1_o5 = DW_dprttg_Unit_Delay1_DSTATE_a;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_b = rtb_S_DPRTTG_RiCridrBndPosX0_met;
    } else {
        rtb_SFunction_b = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_o5, rtb_S_DPRTTG_RiCridrBndPosX0_met, rtb_Div_e);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_o = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_c = DW_dprttg_Unit_Delay1_DSTATE_ac;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_d = rtb_S_DPRTTG_RiCridrBndPosY0_met;
    } else {
        rtb_SFunction_d = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_c, rtb_S_DPRTTG_RiCridrBndPosY0_met, rtb_Div_o);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_hs = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_h = DW_dprttg_Unit_Delay1_DSTATE_o;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_c = rtb_S_DPRTTG_RiCridrBndHeadAng_rad;
    } else {
        rtb_SFunction_c = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_h, rtb_S_DPRTTG_RiCridrBndHeadAng_rad, rtb_Div_hs);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_j = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_pk = DW_dprttg_Unit_Delay1_DSTATE_bh;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_n = rtb_S_DPRTTG_RiCridrBndCrv_1pm;
    } else {
        rtb_SFunction_n = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_pk, rtb_S_DPRTTG_RiCridrBndCrv_1pm, rtb_Div_j);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_a = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_m = DW_dprttg_Unit_Delay1_DSTATE_l;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_nx = rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2;
    } else {
        rtb_SFunction_nx = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_m, rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2, rtb_Div_a);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_bl = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_a = DW_dprttg_Unit_Delay1_DSTATE_n;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_aw = rtb_S_DPRTTG_RiCridrBndLength_met;
    } else {
        rtb_SFunction_aw = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_a, rtb_S_DPRTTG_RiCridrBndLength_met, rtb_Div_bl);
    }
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckTgt/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckTgt/Constant'/Constant'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckTgt/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckTgt/GT/Functionality'/GT'
         *  Sum: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckTgt/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_DPRTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Sum_o = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Sum_o = GET_P_DPRTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckTgt/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckTgt/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/TimeConstCheckTgt/Constant1'/Constant'
         */
    rtb_Sum_o = f32_max_f32_f32(rtb_Sum_o, 1.0E-5F);
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_br = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1_o2 = DW_dprttg_Unit_Delay1_DSTATE_p;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_ai = rtb_S_DPRTTG_TgtTrajPosX0_met;
    } else {
        rtb_SFunction_ai = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_o2, rtb_S_DPRTTG_TgtTrajPosX0_met, rtb_Div_br);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_mx = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_ifv = DW_dprttg_Unit_Delay1_DSTATE_nr;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_h = rtb_S_DPRTTG_TgtTrajPosY0_met;
    } else {
        rtb_SFunction_h = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_ifv, rtb_S_DPRTTG_TgtTrajPosY0_met, rtb_Div_mx);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_dt = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_n = DW_dprttg_Unit_Delay1_DSTATE_e1;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_k = rtb_S_DPRTTG_TgtTrajHeadAng_rad;
    } else {
        rtb_SFunction_k = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_n, rtb_S_DPRTTG_TgtTrajHeadAng_rad, rtb_Div_dt);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_c = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_oo = DW_dprttg_Unit_Delay1_DSTATE_pg;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_py = rtb_S_DPRTTG_TgtTrajCrv_1pm;
    } else {
        rtb_SFunction_py = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_oo, rtb_S_DPRTTG_TgtTrajCrv_1pm, rtb_Div_c);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_ey = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_nu = DW_dprttg_Unit_Delay1_DSTATE_ar;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_nxq = rtb_S_DPRTTG_TgtTrajCrvChng_1pm2;
    } else {
        rtb_SFunction_nxq = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_nu, rtb_S_DPRTTG_TgtTrajCrvChng_1pm2, rtb_Div_ey);
    }
    /* Product: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_n = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Sum_o;
    /* UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_j = DW_dprttg_Unit_Delay1_DSTATE_g;
    /* S-Function (sfun_mmv): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dprttg_LogicalOperator != 0U) {
        rtb_SFunction_l = rtb_S_DPRTTG_TgtTrajLength_met;
    } else {
        rtb_SFunction_l = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_j, rtb_S_DPRTTG_TgtTrajLength_met, rtb_Div_n);
    }
    /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
         *  Logic: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Logical Operator/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Relational Operator2/Functionality'/EQ'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch'
         *  Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay'
         */
    if (((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) {
        rtb_Sum_o = DW_dprttg_Unit_Delay_1_DSTATE;
        rtb_Sum_p = DW_dprttg_Unit_Delay_10_DSTATE;
        rtb_Sum_pl = DW_dprttg_Unit_Delay_11_DSTATE;
        rtb_Sum_f = DW_dprttg_Unit_Delay_12_DSTATE;
        rtb_S_DPRTTG_TgtTrajPosX0_met_m = DW_dprttg_Unit_Delay_13_DSTATE;
        rtb_S_DPRTTG_TgtTrajPosY0_met_c = DW_dprttg_Unit_Delay_14_DSTATE;
        rtb_S_DPRTTG_TgtTrajHeadAng_rad_h = DW_dprttg_Unit_Delay_15_DSTATE;
        rtb_S_DPRTTG_TgtTrajCrv_1pm_hj = DW_dprttg_Unit_Delay_16_DSTATE;
        rtb_S_DPRTTG_TgtTrajCrvChng_1pm2_p = DW_dprttg_Unit_Delay_17_DSTATE;
        rtb_S_DPRTTG_TgtTrajLength_met_i = DW_dprttg_Unit_Delay_18_DSTATE;
        rtb_S_DPRTTG_LeCridrBndPosY0_met_eq = DW_dprttg_Unit_Delay_2_DSTATE;
        rtb_S_DPRTTG_LeCridrBndHeadAng_rad_m = DW_dprttg_Unit_Delay_3_DSTATE;
        rtb_S_DPRTTG_LeCridrBndCrv_1pm_c = DW_dprttg_Unit_Delay_4_DSTATE;
        rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2_p = DW_dprttg_Unit_Delay_5_DSTATE;
        rtb_S_DPRTTG_LeCridrBndLength_met_m = DW_dprttg_Unit_Delay_6_DSTATE;
        rtb_S_DPRTTG_RiCridrBndPosX0_met_a = DW_dprttg_Unit_Delay_7_DSTATE;
        rtb_S_DPRTTG_RiCridrBndPosY0_met_l = DW_dprttg_Unit_Delay_8_DSTATE;
        rtb_S_DPRTTG_RiCridrBndHeadAng_rad_j = DW_dprttg_Unit_Delay_9_DSTATE;
    } else if (!(((sint32)GET_P_DPRTTG_TargetTrajPT1Active_nu()) != 0)) {
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Sum_o = rtb_S_DPRTTG_LeCridrBndPosX0_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Sum_p = rtb_S_DPRTTG_RiCridrBndCrv_1pm;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Sum_pl = rtb_S_DPRTTG_RiCridrBndCrvChng_1pm2;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Sum_f = rtb_S_DPRTTG_RiCridrBndLength_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_TgtTrajPosX0_met_m = rtb_S_DPRTTG_TgtTrajPosX0_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_TgtTrajPosY0_met_c = rtb_S_DPRTTG_TgtTrajPosY0_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_TgtTrajHeadAng_rad_h = rtb_S_DPRTTG_TgtTrajHeadAng_rad;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_TgtTrajCrv_1pm_hj = rtb_S_DPRTTG_TgtTrajCrv_1pm;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_TgtTrajCrvChng_1pm2_p = rtb_S_DPRTTG_TgtTrajCrvChng_1pm2;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_TgtTrajLength_met_i = rtb_S_DPRTTG_TgtTrajLength_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_LeCridrBndPosY0_met_eq = rtb_S_DPRTTG_LeCridrBndPosY0_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_LeCridrBndHeadAng_rad_m = rtb_S_DPRTTG_LeCridrBndHeadAng_rad;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_LeCridrBndCrv_1pm_c = rtb_S_DPRTTG_LeCridrBndCrv_1pm;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2_p = rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_LeCridrBndLength_met_m = rtb_S_DPRTTG_LeCridrBndLength_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_RiCridrBndPosX0_met_a = rtb_S_DPRTTG_RiCridrBndPosX0_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_RiCridrBndPosY0_met_l = rtb_S_DPRTTG_RiCridrBndPosY0_met;
        /* Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPRTTG_RiCridrBndHeadAng_rad_j = rtb_S_DPRTTG_RiCridrBndHeadAng_rad;
    } else {
        rtb_Sum_o = rtb_SFunction;
        rtb_Sum_p = rtb_SFunction_n;
        rtb_Sum_pl = rtb_SFunction_nx;
        rtb_Sum_f = rtb_SFunction_aw;
        rtb_S_DPRTTG_TgtTrajPosX0_met_m = rtb_SFunction_ai;
        rtb_S_DPRTTG_TgtTrajPosY0_met_c = rtb_SFunction_h;
        rtb_S_DPRTTG_TgtTrajHeadAng_rad_h = rtb_SFunction_k;
        rtb_S_DPRTTG_TgtTrajCrv_1pm_hj = rtb_SFunction_py;
        rtb_S_DPRTTG_TgtTrajCrvChng_1pm2_p = rtb_SFunction_nxq;
        rtb_S_DPRTTG_TgtTrajLength_met_i = rtb_SFunction_l;
        rtb_S_DPRTTG_LeCridrBndPosY0_met_eq = rtb_SFunction_g;
        rtb_S_DPRTTG_LeCridrBndHeadAng_rad_m = rtb_SFunction_o;
        rtb_S_DPRTTG_LeCridrBndCrv_1pm_c = rtb_SFunction_e;
        rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2_p = rtb_SFunction_a;
        rtb_S_DPRTTG_LeCridrBndLength_met_m = rtb_SFunction_p;
        rtb_S_DPRTTG_RiCridrBndPosX0_met_a = rtb_SFunction_b;
        rtb_S_DPRTTG_RiCridrBndPosY0_met_l = rtb_SFunction_d;
        rtb_S_DPRTTG_RiCridrBndHeadAng_rad_j = rtb_SFunction_c;
    }
    /* End of Switch: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_LeCridrBndPosX0_met(rtb_Sum_o);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_RiCridrBndCrv_1pm(rtb_Sum_p);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_RiCridrBndCrvChng_1pm2(rtb_Sum_pl);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_RiCridrBndLength_met(rtb_Sum_f);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_TgtTrajPosX0_met(rtb_S_DPRTTG_TgtTrajPosX0_met_m);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_TgtTrajPosY0_met(rtb_S_DPRTTG_TgtTrajPosY0_met_c);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_TgtTrajHeadAng_rad(rtb_S_DPRTTG_TgtTrajHeadAng_rad_h);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_TgtTrajCrv_1pm(rtb_S_DPRTTG_TgtTrajCrv_1pm_hj);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_TgtTrajCrvChng_1pm2(rtb_S_DPRTTG_TgtTrajCrvChng_1pm2_p);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_TgtTrajLength_met(rtb_S_DPRTTG_TgtTrajLength_met_i);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_LeCridrBndPosY0_met(rtb_S_DPRTTG_LeCridrBndPosY0_met_eq);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_LeCridrBndHeadAng_rad(rtb_S_DPRTTG_LeCridrBndHeadAng_rad_m);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_LeCridrBndCrv_1pm(rtb_S_DPRTTG_LeCridrBndCrv_1pm_c);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_LeCridrBndCrvChng_1pm2(rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2_p);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_LeCridrBndLength_met(rtb_S_DPRTTG_LeCridrBndLength_met_m);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_RiCridrBndPosX0_met(rtb_S_DPRTTG_RiCridrBndPosX0_met_a);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_RiCridrBndPosY0_met(rtb_S_DPRTTG_RiCridrBndPosY0_met_l);
    /* SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState/branch25'/copy1' */
    SET_S_DPRTTG_RiCridrBndHeadAng_rad(rtb_S_DPRTTG_RiCridrBndHeadAng_rad_j);
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft'/FixPt Unit Delay2' */
    DW_dprttg_FixPtUnitDelay2_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft'/FixPt Unit Delay4' */
    DW_dprttg_FixPtUnitDelay4_DSTATE_d = rtb_EQ_j0;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe'/FixPt Unit Delay4' */
    DW_dprttg_FixPtUnitDelay4_DSTATE = rtb_Switch_l1;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe'/FixPt Unit Delay1' */
    DW_dprttg_FixPtUnitDelay1_DSTATE = rtb_EQ_j0;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationRe/LeTgtMaxLatDev'/FixPt Unit Delay4' */
    DW_dprttg_FixPtUnitDelay4_DSTATE_f = rtb_Sum;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn'/FixPt Unit Delay4' */
    DW_dprttg_FixPtUnitDelay4_DSTATE_m = rtb_Switch_n4;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn'/FixPt Unit Delay1' */
    DW_dprttg_FixPtUnitDelay1_DSTATE_f = rtb_EQ_j0;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationLeft/TargetLateralDistanceCalculationLn/LeTgtMaxLatDev'/FixPt Unit Delay4' */
    DW_dprttg_FixPtUnitDelay4_DSTATE_j = rtb_Switch_b;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight'/FixPt Unit Delay1' */
    DW_dprttg_FixPtUnitDelay1_DSTATE_m = rtb_EQ_j0;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight'/FixPt Unit Delay2' */
    DW_dprttg_FixPtUnitDelay2_DSTATE_f = rtb_Switch_n;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe'/FixPt Unit Delay5' */
    DW_dprttg_FixPtUnitDelay5_DSTATE = rtb_Switch_ds;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe'/FixPt Unit Delay1' */
    DW_dprttg_FixPtUnitDelay1_DSTATE_m0 = rtb_EQ_j0;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationRe/RiTgtMaxLatDev'/FixPt Unit Delay4' */
    DW_dprttg_FixPtUnitDelay4_DSTATE_h = rtb_Sum_d;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn'/FixPt Unit Delay5' */
    DW_dprttg_FixPtUnitDelay5_DSTATE_b = rtb_Switch_g;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn'/FixPt Unit Delay1' */
    DW_dprttg_FixPtUnitDelay1_DSTATE_p = rtb_EQ_j0;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/CorridorClothoids/DangerousSituationRight/TargetLateralDistanceCalculationLn/RiTgtMaxLatDev'/FixPt Unit Delay4' */
    DW_dprttg_FixPtUnitDelay4_DSTATE_c = rtb_Switch_l;
    /* S-Function (fcncallgen): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprttg_Unit_Delay_DSTATE = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE = rtb_SFunction;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_c = rtb_SFunction_g;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_i = rtb_SFunction_o;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_b = rtb_SFunction_e;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_e = rtb_SFunction_a;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_ik = rtb_SFunction_p;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_a = rtb_SFunction_b;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_ac = rtb_SFunction_d;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_o = rtb_SFunction_c;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_bh = rtb_SFunction_n;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_l = rtb_SFunction_nx;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_n = rtb_SFunction_aw;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_p = rtb_SFunction_ai;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_nr = rtb_SFunction_h;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_e1 = rtb_SFunction_k;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_pg = rtb_SFunction_py;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_ar = rtb_SFunction_nxq;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/Filter_RDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5'/Unit_Delay1' */
    DW_dprttg_Unit_Delay1_DSTATE_g = rtb_SFunction_l;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_1_DSTATE = rtb_Sum_o;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_10_DSTATE = rtb_Sum_p;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_11_DSTATE = rtb_Sum_pl;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_12_DSTATE = rtb_Sum_f;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_13_DSTATE = rtb_S_DPRTTG_TgtTrajPosX0_met_m;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_14_DSTATE = rtb_S_DPRTTG_TgtTrajPosY0_met_c;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_15_DSTATE = rtb_S_DPRTTG_TgtTrajHeadAng_rad_h;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_16_DSTATE = rtb_S_DPRTTG_TgtTrajCrv_1pm_hj;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_17_DSTATE = rtb_S_DPRTTG_TgtTrajCrvChng_1pm2_p;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_18_DSTATE = rtb_S_DPRTTG_TgtTrajLength_met_i;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_2_DSTATE = rtb_S_DPRTTG_LeCridrBndPosY0_met_eq;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_3_DSTATE = rtb_S_DPRTTG_LeCridrBndHeadAng_rad_m;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_4_DSTATE = rtb_S_DPRTTG_LeCridrBndCrv_1pm_c;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_5_DSTATE = rtb_S_DPRTTG_LeCridrBndCrvChng_1pm2_p;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_6_DSTATE = rtb_S_DPRTTG_LeCridrBndLength_met_m;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_7_DSTATE = rtb_S_DPRTTG_RiCridrBndPosX0_met_a;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_8_DSTATE = rtb_S_DPRTTG_RiCridrBndPosY0_met_l;
    /* Update for UnitDelay: 'sda:DPRTTG/DPRTTG/DPRTTG_SenProcess/OPM/M_DPRTTG/RampoutState'/Unit_Delay' */
    DW_dprttg_Unit_Delay_9_DSTATE = rtb_S_DPRTTG_RiCridrBndHeadAng_rad_j;
}
#include "Pse_DPRTTG.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
