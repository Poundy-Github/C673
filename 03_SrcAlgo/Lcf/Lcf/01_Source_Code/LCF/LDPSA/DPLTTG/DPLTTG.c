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
 * File          : DPLTTG
 * Generated on  : Tue 19.03.2019 at 09:15:14 (UTC+01:00)
 * MD5           : [2345686512  1837122436  1572594093  2011095752 0](DPLTTG)
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
 * Revision      : $Revision: 1.2.1.1 $
 * Author        : $Author: Diaz Bravo, Jose Luis (uidg8685) $
 * Date          : $Date: 2019/05/29 09:54:59CEST $
 * Changes       :
 * $Log: DPLTTG.c  $
 * Revision 1.2.1.1 2019/05/29 09:54:59CEST Diaz Bravo, Jose Luis (uidg8685) 
 * B2B
 * Revision 1.20 2019/03/19 09:32:10CET Diaz Bravo, Jose Luis (uidg8685) 
 * Inner/Outer Curve logic
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "DPLTTG.h"
#include "DPLTTG_private.h"
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
#define DPLTTG_START_SEC_DATA_8
#include "DPLTTG_MemMap.h"
static uint8 BI_dplttg_LogicalOperator;
/* 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 DW_dplttg_Unit_Delay_DSTATE;
static uint8 DW_dplttg_FixPtUnitDelay3_DSTATE;
static uint8 DW_dplttg_FixPtUnitDelay3_DSTATE_f;
#define DPLTTG_STOP_SEC_DATA_8
#include "DPLTTG_MemMap.h"
#define DPLTTG_START_SEC_DATA_32
#include "DPLTTG_MemMap.h"
static float32 DW_dplttg_Unit_Delay1_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay1_DSTATE;
static float32 DW_dplttg_Unit_Delay1_DSTATE_c;
static float32 DW_dplttg_Unit_Delay1_DSTATE_o;
static float32 DW_dplttg_Unit_Delay1_DSTATE_m;
static float32 DW_dplttg_Unit_Delay1_DSTATE_b;
static float32 DW_dplttg_Unit_Delay1_DSTATE_n;
static float32 DW_dplttg_Unit_Delay1_DSTATE_g;
static float32 DW_dplttg_Unit_Delay1_DSTATE_o1;
static float32 DW_dplttg_Unit_Delay1_DSTATE_ch;
static float32 DW_dplttg_Unit_Delay1_DSTATE_mq;
static float32 DW_dplttg_Unit_Delay1_DSTATE_d;
static float32 DW_dplttg_Unit_Delay1_DSTATE_bc;
static float32 DW_dplttg_Unit_Delay1_DSTATE_e;
static float32 DW_dplttg_FixPtUnitDelay4_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay1_DSTATE_o;
static float32 DW_dplttg_FixPtUnitDelay4_DSTATE_f;
static float32 DW_dplttg_FixPtUnitDelay5_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay4_DSTATE_g;
static float32 DW_dplttg_Unit_Delay1_DSTATE_i;
static float32 DW_dplttg_Unit_Delay1_DSTATE_me;
static float32 DW_dplttg_Unit_Delay1_DSTATE_j;
static float32 DW_dplttg_Unit_Delay1_DSTATE_dv;
static float32 DW_dplttg_Unit_Delay1_DSTATE_nh;
static float32 DW_dplttg_FixPtUnitDelay2_1_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_10_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_11_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_12_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_13_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_14_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_15_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_16_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_17_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_18_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_2_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_3_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_4_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_5_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_6_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_7_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_8_DSTATE;
static float32 DW_dplttg_FixPtUnitDelay2_9_DSTATE;
#define DPLTTG_STOP_SEC_DATA_32
#include "DPLTTG_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPLTTG/DPLTTG/INI'/DPLTTG_SenReset'
 * Block description for: 'sda:DPLTTG/DPLTTG/INI'/DPLTTG_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLTTG_SenReset
#include "Pse_DPLTTG.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLTTG_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant1'/Constant' */
    SET_S_DPLTTG_LeCridrBndPosX0_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant10'/Constant' */
    SET_S_DPLTTG_RiCridrBndCrv_1pm(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant11'/Constant' */
    SET_S_DPLTTG_RiCridrBndCrvChng_1pm2(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant12'/Constant' */
    SET_S_DPLTTG_RiCridrBndLength_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant13'/Constant' */
    SET_S_DPLTTG_TgtTrajPosX0_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant14'/Constant' */
    SET_S_DPLTTG_LeTgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant15'/Constant' */
    SET_S_DPLTTG_TgtTrajHeadAng_rad(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant16'/Constant' */
    SET_S_DPLTTG_TgtTrajCrv_1pm(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant17'/Constant' */
    SET_S_DPLTTG_TgtTrajLength_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant19'/Constant' */
    SET_S_DPLTTG_RiTgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant2'/Constant' */
    SET_S_DPLTTG_LeCridrBndPosY0_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant20'/Constant' */
    SET_S_DPLTTG_TgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant24'/Constant' */
    SET_S_DPLTTG_TgtTrajCrvChng_1pm2(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant3'/Constant' */
    SET_S_DPLTTG_LeCridrBndHeadAng_rad(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant4'/Constant' */
    SET_S_DPLTTG_LeCridrBndCrv_1pm(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant5'/Constant' */
    SET_S_DPLTTG_LeCridrBndCrvChng_1pm2(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant6'/Constant' */
    SET_S_DPLTTG_LeCridrBndLength_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant7'/Constant' */
    SET_S_DPLTTG_RiCridrBndPosX0_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant8'/Constant' */
    SET_S_DPLTTG_RiCridrBndPosY0_met(0.0F);
    /* Constant: 'sda:DPLTTG/DPLTTG/INI/DPLTTG_SenReset/Constant9'/Constant' */
    SET_S_DPLTTG_RiCridrBndHeadAng_rad(0.0F);
}
#include "Pse_DPLTTG.h"
/*
 * Output and update for function-call system: 'sda:DPLTTG/DPLTTG'/DPLTTG_SenProcess'
 * Block description for: 'sda:DPLTTG/DPLTTG'/DPLTTG_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLTTG_SenProcess
#include "Pse_DPLTTG.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLTTG_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_S_DPLTTG_LeCridrBndPosX0_met;
    float32 rtb_Div;
    float32 rtb_Unit_Delay1;
    float32 rtb_SFunction;
    float32 rtb_S_DPLTTG_LeCridrBndPosY0_met;
    float32 rtb_Div_d;
    float32 rtb_Unit_Delay1_h;
    float32 rtb_SFunction_e;
    float32 rtb_S_DPLTTG_LeCridrBndHeadAng_rad;
    float32 rtb_Div_a;
    float32 rtb_Unit_Delay1_h5;
    float32 rtb_SFunction_o;
    float32 rtb_S_DPLTTG_LeCridrBndCrv_1pm;
    float32 rtb_Div_dt;
    float32 rtb_Unit_Delay1_j;
    float32 rtb_SFunction_ec;
    float32 rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2;
    float32 rtb_Div_al;
    float32 rtb_Unit_Delay1_c;
    float32 rtb_SFunction_m;
    float32 rtb_S_DPLTTG_LeCridrBndLength_met;
    float32 rtb_Div_di;
    float32 rtb_Unit_Delay1_d;
    float32 rtb_SFunction_f;
    float32 rtb_S_DPLTTG_RiCridrBndPosX0_met;
    float32 rtb_Div_k;
    float32 rtb_Unit_Delay1_hu;
    float32 rtb_SFunction_g;
    float32 rtb_S_DPLTTG_RiCridrBndPosY0_met;
    float32 rtb_Div_ae;
    float32 rtb_Unit_Delay1_hx;
    float32 rtb_SFunction_l;
    float32 rtb_S_DPLTTG_RiCridrBndHeadAng_rad;
    float32 rtb_Div_f;
    float32 rtb_Unit_Delay1_h4;
    float32 rtb_SFunction_la;
    float32 rtb_S_DPLTTG_RiCridrBndCrv_1pm;
    float32 rtb_Div_e;
    float32 rtb_Unit_Delay1_k;
    float32 rtb_SFunction_i;
    float32 rtb_S_DPLTTG_RiCridrBndCrvChng_1pm2;
    float32 rtb_Div_kq;
    float32 rtb_Unit_Delay1_m;
    float32 rtb_SFunction_fd;
    float32 rtb_S_DPLTTG_RiCridrBndLength_met;
    float32 rtb_Div_l;
    float32 rtb_Unit_Delay1_p;
    float32 rtb_SFunction_fi;
    float32 rtb_S_DPLTTG_TgtTrajPosX0_met;
    float32 rtb_Div_k0;
    float32 rtb_Unit_Delay1_ko;
    float32 rtb_SFunction_ie;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_S_DPLTTG_TgtTrajPosY0_met;
    float32 rtb_Div_dn;
    float32 rtb_Unit_Delay1_f;
    float32 rtb_SFunction_n;
    float32 rtb_S_DPLTTG_TgtTrajHeadAng_rad;
    float32 rtb_Div_ep;
    float32 rtb_Unit_Delay1_i;
    float32 rtb_SFunction_k;
    float32 rtb_S_DPLTTG_TgtTrajCrv_1pm;
    float32 rtb_Div_h;
    float32 rtb_Unit_Delay1_j2;
    float32 rtb_SFunction_b;
    float32 rtb_S_DPLTTG_TgtTrajCrvChng_1pm2;
    float32 rtb_Div_aw;
    float32 rtb_Unit_Delay1_hh;
    float32 rtb_SFunction_c;
    float32 rtb_S_DPLTTG_TgtTrajLength_met;
    float32 rtb_Div_hh;
    float32 rtb_Unit_Delay1_id;
    float32 rtb_SFunction_a;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_Abs_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_Abs_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_Abs_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    uint8 rtb_EQ;
    uint8 rtb_EQ_fe;
    uint8 rtb_DataTypeConversion_a;
    float32 rtb_Max;
    uint8 rtb_EQ_m;
    float32 rtb_Div_go;
    float32 rtb_Sum_nrb;
    float32 rtb_Sum_b;
    float32 rtb_S_DPLTTG_TgtTrajPosX0_met_d;
    float32 rtb_S_DPLTTG_TgtTrajPosY0_met_p;
    float32 rtb_S_DPLTTG_TgtTrajHeadAng_rad_iu;
    float32 rtb_S_DPLTTG_TgtTrajCrv_1pm_gc;
    float32 rtb_S_DPLTTG_TgtTrajCrvChng_1pm2_nn;
    float32 rtb_S_DPLTTG_TgtTrajLength_met_e5;
    float32 rtb_S_DPLTTG_LeCridrBndPosY0_met_bl;
    float32 rtb_S_DPLTTG_LeCridrBndHeadAng_rad_cth;
    float32 rtb_S_DPLTTG_LeCridrBndCrv_1pm_hr;
    float32 rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2_l;
    float32 rtb_S_DPLTTG_LeCridrBndLength_met_fz;
    float32 rtb_S_DPLTTG_RiCridrBndPosX0_met_l;
    float32 rtb_S_DPLTTG_RiCridrBndPosY0_met_i;
    float32 rtb_S_DPLTTG_RiCridrBndHeadAng_rad_a;
    float32 rtb_Switch;
    float32 rtb_Switch_fy;
    float32 rtb_Switch_nw;
    float32 rtb_Switch_e4;
    float32 rtb_Sum;
    float32 rtb_Switch_bq;
    float32 rtb_Switch_p;
    /* RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/from_data_definition'/state_source'
         *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising'/Unit_Delay'
         */
    BI_dplttg_LogicalOperator = (uint8)((!(((sint32)DW_dplttg_Unit_Delay_DSTATE) != 0)) && (((sint32)rtb_EQ) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING'/fcg' */
    /* RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_DPLSMI_DangerousSide_nu'
         */
    rtb_EQ_fe = (uint8)(((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT)));
    /* DataTypeConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/from_data_definition'/state_source'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
         *  Logic: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Relational Operator1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_a = (uint8)((((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))));
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Left/Constant4'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_LeCridrBndPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
        } else {
            rtb_S_DPLTTG_LeCridrBndPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_LeCridrBndPosX0_met = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckLe/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckLe/Constant'/Constant'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckLe/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckLe/GT/Functionality'/GT'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckLe/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_DPLTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Max = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Max = GET_P_DPLTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckLe/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckLe/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckLe/Constant1'/Constant'
         */
    rtb_Max = f32_max_f32_f32(rtb_Max, 1.0E-5F);
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1 = DW_dplttg_Unit_Delay1_DSTATE;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction = rtb_S_DPLTTG_LeCridrBndPosX0_met;
    } else {
        rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay1, rtb_S_DPLTTG_LeCridrBndPosX0_met, rtb_Div);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor'/FixPt Unit Delay3'
         */
    if (((sint32)DW_dplttg_FixPtUnitDelay3_DSTATE) != 0) {
        rtb_Switch = DW_dplttg_FixPtUnitDelay1_DSTATE;
    } else {
        rtb_Switch = GET_S_DPLSIA_LaneWidthLDP_met();
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Left/Constant5'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                 *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Sum/Functionality'/Sum'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_LeCridrBndPosY0_met = GET_S_ABPLBP_LeLnClthPosY0_met();
        } else {
            rtb_S_DPLTTG_LeCridrBndPosY0_met = rtb_Switch + GET_S_ABPLBP_RiLnClthPosY0_met();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_LeCridrBndPosY0_met = 10.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_d = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_h = DW_dplttg_Unit_Delay1_DSTATE_c;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_e = rtb_S_DPLTTG_LeCridrBndPosY0_met;
    } else {
        rtb_SFunction_e = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_h, rtb_S_DPLTTG_LeCridrBndPosY0_met, rtb_Div_d);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Left/Constant6'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_LeCridrBndHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
        } else {
            rtb_S_DPLTTG_LeCridrBndHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_LeCridrBndHeadAng_rad = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_a = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_h5 = DW_dplttg_Unit_Delay1_DSTATE_o;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_o = rtb_S_DPLTTG_LeCridrBndHeadAng_rad;
    } else {
        rtb_SFunction_o = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_h5, rtb_S_DPLTTG_LeCridrBndHeadAng_rad, rtb_Div_a);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Left/Constant7'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_LeCridrBndCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
        } else {
            rtb_S_DPLTTG_LeCridrBndCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_LeCridrBndCrv_1pm = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_dt = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_j = DW_dplttg_Unit_Delay1_DSTATE_m;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_ec = rtb_S_DPLTTG_LeCridrBndCrv_1pm;
    } else {
        rtb_SFunction_ec = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_j, rtb_S_DPLTTG_LeCridrBndCrv_1pm, rtb_Div_dt);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Left/Constant8'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
        } else {
            rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2 = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_al = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_c = DW_dplttg_Unit_Delay1_DSTATE_b;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_m = rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2;
    } else {
        rtb_SFunction_m = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_c, rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2, rtb_Div_al);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Left/Constant9'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_LeCridrBndLength_met = GET_S_ABPLBP_LeLnClthLength_met();
        } else {
            rtb_S_DPLTTG_LeCridrBndLength_met = GET_S_ABPLBP_RiLnClthLength_met();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_LeCridrBndLength_met = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_di = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_d = DW_dplttg_Unit_Delay1_DSTATE_n;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_f = rtb_S_DPLTTG_LeCridrBndLength_met;
    } else {
        rtb_SFunction_f = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_d, rtb_S_DPLTTG_LeCridrBndLength_met, rtb_Div_di);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Right/Constant4'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_RiCridrBndPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
        } else {
            rtb_S_DPLTTG_RiCridrBndPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_RiCridrBndPosX0_met = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckRi/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckRi/Constant'/Constant'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckRi/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckRi/GT/Functionality'/GT'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckRi/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_DPLTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Max = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Max = GET_P_DPLTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckRi/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckRi/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckRi/Constant1'/Constant'
         */
    rtb_Max = f32_max_f32_f32(rtb_Max, 1.0E-5F);
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_k = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1_hu = DW_dplttg_Unit_Delay1_DSTATE_g;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_g = rtb_S_DPLTTG_RiCridrBndPosX0_met;
    } else {
        rtb_SFunction_g = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_hu, rtb_S_DPLTTG_RiCridrBndPosX0_met, rtb_Div_k);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Right/Constant5'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                 *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Sum1/Functionality'/Sum'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_RiCridrBndPosY0_met = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_Switch;
        } else {
            rtb_S_DPLTTG_RiCridrBndPosY0_met = GET_S_ABPLBP_RiLnClthPosY0_met();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_RiCridrBndPosY0_met = -10.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_ae = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_hx = DW_dplttg_Unit_Delay1_DSTATE_o1;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_l = rtb_S_DPLTTG_RiCridrBndPosY0_met;
    } else {
        rtb_SFunction_l = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_hx, rtb_S_DPLTTG_RiCridrBndPosY0_met, rtb_Div_ae);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Right/Constant6'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_RiCridrBndHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
        } else {
            rtb_S_DPLTTG_RiCridrBndHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_RiCridrBndHeadAng_rad = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_f = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_h4 = DW_dplttg_Unit_Delay1_DSTATE_ch;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_la = rtb_S_DPLTTG_RiCridrBndHeadAng_rad;
    } else {
        rtb_SFunction_la = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_h4, rtb_S_DPLTTG_RiCridrBndHeadAng_rad, rtb_Div_f);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Right/Constant7'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_RiCridrBndCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
        } else {
            rtb_S_DPLTTG_RiCridrBndCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_RiCridrBndCrv_1pm = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_e = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_k = DW_dplttg_Unit_Delay1_DSTATE_mq;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_i = rtb_S_DPLTTG_RiCridrBndCrv_1pm;
    } else {
        rtb_SFunction_i = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_k, rtb_S_DPLTTG_RiCridrBndCrv_1pm, rtb_Div_e);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Right/Constant8'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_RiCridrBndCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
        } else {
            rtb_S_DPLTTG_RiCridrBndCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_RiCridrBndCrvChng_1pm2 = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_kq = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_m = DW_dplttg_Unit_Delay1_DSTATE_d;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_fd = rtb_S_DPLTTG_RiCridrBndCrvChng_1pm2;
    } else {
        rtb_SFunction_fd = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_m, rtb_S_DPLTTG_RiCridrBndCrvChng_1pm2, rtb_Div_kq);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Right/Constant9'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_RiCridrBndLength_met = GET_S_ABPLBP_LeLnClthLength_met();
        } else {
            rtb_S_DPLTTG_RiCridrBndLength_met = GET_S_ABPLBP_RiLnClthLength_met();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_RiCridrBndLength_met = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_l = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_p = DW_dplttg_Unit_Delay1_DSTATE_bc;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_fi = rtb_S_DPLTTG_RiCridrBndLength_met;
    } else {
        rtb_SFunction_fi = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_p, rtb_S_DPLTTG_RiCridrBndLength_met, rtb_Div_l);
    }
    /* RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_DPLSMI_DangerousSide_nu'
         */
    rtb_EQ_fe = (uint8)(((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT)));
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Target/Constant4'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_TgtTrajPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
        } else {
            rtb_S_DPLTTG_TgtTrajPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_TgtTrajPosX0_met = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckTgt/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckTgt/Constant'/Constant'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckTgt/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckTgt/GT/Functionality'/GT'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckTgt/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_DPLTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Max = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Max = GET_P_DPLTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckTgt/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckTgt/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/TimeConstCheckTgt/Constant1'/Constant'
         */
    rtb_Max = f32_max_f32_f32(rtb_Max, 1.0E-5F);
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_k0 = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1_ko = DW_dplttg_Unit_Delay1_DSTATE_e;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_ie = rtb_S_DPLTTG_TgtTrajPosX0_met;
    } else {
        rtb_SFunction_ie = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_ko, rtb_S_DPLTTG_TgtTrajPosX0_met, rtb_Div_k0);
    }
    /* DataTypeConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/P_DPLTTG_TargetLaneCenterEnable_nu'/Constant'
         *  Inport: '<Root>/S_DPLSIA_TgtCntrLnEnable_bool'
         *  Logic: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/AND/Functionality'/AND'
         */
    rtb_EQ_m = (uint8)((((sint32)GET_S_DPLSIA_TgtCntrLnEnable_bool()) != 0) && (((sint32)GET_P_DPLTTG_TgtCntrLnEnable_nu()) != 0));
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Divide/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Constant1'/Constant'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/P_VEH_Width_met'/Constant'
         */
    rtb_Div_go = GET_P_VEH_Width_met() / 2.0F;
    /* S-Function Block sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_LWTargetLatDist_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDP_met(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_DPLTTG_LWTargetLatDist_met(), &dps_result_ln);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/P_DPLTTG_TargetLaneCenterEnable_nu1'/Constant'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeLe_enum'
         *  MinMax: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Min/Functionality'/Min'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/EQ1/Functionality'/EQ'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum4/Functionality'/Sum'
         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch4/Functionality'/Switch'
         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch5/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay3'
         */
    if (((sint32)DW_dplttg_FixPtUnitDelay3_DSTATE_f) != 0) {
        rtb_Switch_bq = DW_dplttg_FixPtUnitDelay1_DSTATE_o;
    } else {
        if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Abs2/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch4/Functionality'/Switch'
                         */
            rtb_Abs_e = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
            /* S-Function Block sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_CrvICTgtOffset_met2/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_e, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_DPLTTG_CrvICTgtOffset_met(), &dps_result_ln);
            }
            rtb_Switch_bq = -rtb_ip_lookup_fxpt_sfun_7_c;
        } else if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Abs1/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch4/Functionality'/Switch'
                         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_h = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
            /* S-Function Block sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_CrvOCTgtOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_h, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_DPLTTG_CrvOCTgtOffset_met(), &dps_result_ln);
            }
            rtb_Switch_bq = rtb_ip_lookup_fxpt_sfun_7_p;
        } else {
            /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch5/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Constant8'/Constant'
                         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch4/Functionality'/Switch'
                         */
            rtb_Switch_bq = 0.0F;
        }
        /* Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum2/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/from_data_definition2'/state_source'
                 *  Inport: '<Root>/S_DPLSIA_CurveTypeLe_enum'
                 *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
                 *  Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_LWTargetLatDist_met/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/EQ1/Functionality'/EQ'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_LWTargetLatDist_met/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch5/Functionality'/Switch'
                 */
        rtb_Switch_bq += rtb_ip_lookup_fxpt_sfun_7;
        rtb_Switch_bq = rtb_Div_go + f32_min_f32_f32(rtb_Switch_bq, GET_P_DPLTTG_TgtMaxDistance_met());
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum/Functionality'/Sum'
         */
    if (((sint32)rtb_EQ_m) != 0) {
        rtb_Switch_fy = GET_S_ABPLBP_CntrLnClthPosY0_met();
    } else {
        rtb_Switch_fy = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_Switch_bq;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/GT/Functionality'/GT'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Sum7/Functionality'/Sum'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum7/Functionality'/Sum'
         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch10/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Neg/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay3'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay4'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev'/FixPt Unit Delay4'
         */
    if (((sint32)DW_dplttg_FixPtUnitDelay3_DSTATE_f) != 0) {
        rtb_Switch_nw = DW_dplttg_FixPtUnitDelay4_DSTATE_f;
        rtb_Switch_fy = DW_dplttg_FixPtUnitDelay4_DSTATE;
    } else {
        if ((-GET_P_DPLTTG_TgtMaxLatDev_met()) > rtb_Switch_fy) {
            /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
                         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Sum6/Functionality'/Sum'
                         *  UnaryMinus: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Neg/Functionality'/Unary Minus'
                         */
            rtb_Switch_nw = rtb_Switch_fy - (-GET_P_DPLTTG_TgtMaxLatDev_met());
        } else {
            /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Constant1'/Constant'
                         */
            rtb_Switch_nw = 0.0F;
        }
        rtb_Switch_fy = GET_S_ABPLBP_LeLnClthPosY0_met() - (rtb_Switch_fy - rtb_Switch_nw);
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev/Switch10/Functionality'/Switch' */
    /* Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum8/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         */
    rtb_Sum_b = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_Switch_fy;
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/P_DPLTTG_TargetLaneCenterEnable_nu2'/Constant'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/from_data_definition3'/state_source'
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeRi_enum'
         *  MinMax: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Min1/Functionality'/Min'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/EQ3/Functionality'/EQ'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum5/Functionality'/Sum'
         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch6/Functionality'/Switch'
         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch7/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay2'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay3'
         */
    if (((sint32)DW_dplttg_FixPtUnitDelay3_DSTATE_f) != 0) {
        rtb_Div_go = DW_dplttg_FixPtUnitDelay2_DSTATE;
    } else {
        if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Abs3/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch6/Functionality'/Switch'
                         */
            rtb_Abs = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
            /* S-Function Block sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_CrvICTgtOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D (GETA_Y_DPLTTG_CrvICTgtOffset_met(), &dps_result_ln);
            }
            rtb_Switch_p = -rtb_ip_lookup_fxpt_sfun_7_h;
        } else if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Abs4/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch6/Functionality'/Switch'
                         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch7/Functionality'/Switch'
                         */
            rtb_Abs_m = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
            /* S-Function Block sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_CrvOCTgtOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_m, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_DPLTTG_CrvOCTgtOffset_met(), &dps_result_ln);
            }
            rtb_Switch_p = rtb_ip_lookup_fxpt_sfun_7_m;
        } else {
            /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Constant9'/Constant'
                         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch6/Functionality'/Switch'
                         */
            rtb_Switch_p = 0.0F;
        }
        /* Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum3/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/from_data_definition3'/state_source'
                 *  Inport: '<Root>/S_DPLSIA_CurveTypeRi_enum'
                 *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
                 *  Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_LWTargetLatDist_met/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/EQ3/Functionality'/EQ'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Y_DPLTTG_LWTargetLatDist_met/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch6/Functionality'/Switch'
                 *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch7/Functionality'/Switch'
                 */
        rtb_Switch_p += rtb_ip_lookup_fxpt_sfun_7;
        rtb_Div_go += f32_min_f32_f32(rtb_Switch_p, GET_P_DPLTTG_TgtMaxDistance_met());
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch8/Functionality'/Switch' */
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch9/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_EQ_m) != 0) {
        rtb_Switch_p = GET_S_ABPLBP_CntrLnClthPosY0_met();
    } else {
        rtb_Switch_p = GET_S_ABPLBP_RiLnClthPosY0_met() + rtb_Div_go;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch9/Functionality'/Switch' */
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/LT/Functionality'/LT'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/Sum7/Functionality'/Sum'
         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum6/Functionality'/Sum'
         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch11/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay3'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay5'
         *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev'/FixPt Unit Delay4'
         */
    if (((sint32)DW_dplttg_FixPtUnitDelay3_DSTATE_f) != 0) {
        rtb_Sum = DW_dplttg_FixPtUnitDelay4_DSTATE_g;
        rtb_Switch_p = DW_dplttg_FixPtUnitDelay5_DSTATE;
    } else {
        if (GET_P_DPLTTG_TgtMaxLatDev_met() < rtb_Switch_p) {
            /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
                         *  Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/Sum6/Functionality'/Sum'
                         */
            rtb_Sum = rtb_Switch_p - GET_P_DPLTTG_TgtMaxLatDev_met();
        } else {
            /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/Constant1'/Constant'
                         */
            rtb_Sum = 0.0F;
        }
        rtb_Switch_p = (rtb_Switch_p - rtb_Sum) - GET_S_ABPLBP_RiLnClthPosY0_met();
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev/Switch10/Functionality'/Switch' */
    /* Sum: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Sum9/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         */
    rtb_Sum_nrb = GET_S_ABPLBP_RiLnClthPosY0_met() + rtb_Switch_p;
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Target/Constant5'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Constant'/Constant'
                 *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/from_data_definition'/state_source'
                 *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/from_data_definition1'/state_source'
                 *  Inport: '<Root>/S_DPLSMI_DangerousSide_nu'
                 *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Relational Operator1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Relational Operator2/Functionality'/EQ'
                 *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch1/Functionality'/Switch'
                 */
        if (((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
            rtb_S_DPLTTG_TgtTrajPosY0_met = rtb_Sum_b;
        } else if (((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
            /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch1/Functionality'/Switch' */
            rtb_S_DPLTTG_TgtTrajPosY0_met = rtb_Sum_nrb;
        } else {
            rtb_S_DPLTTG_TgtTrajPosY0_met = 0.0F;
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_TgtTrajPosY0_met = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_dn = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_f = DW_dplttg_Unit_Delay1_DSTATE_i;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_n = rtb_S_DPLTTG_TgtTrajPosY0_met;
    } else {
        rtb_SFunction_n = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_f, rtb_S_DPLTTG_TgtTrajPosY0_met, rtb_Div_dn);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Target/Constant6'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_TgtTrajHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
        } else {
            rtb_S_DPLTTG_TgtTrajHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_TgtTrajHeadAng_rad = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_ep = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_i = DW_dplttg_Unit_Delay1_DSTATE_me;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_k = rtb_S_DPLTTG_TgtTrajHeadAng_rad;
    } else {
        rtb_SFunction_k = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_i, rtb_S_DPLTTG_TgtTrajHeadAng_rad, rtb_Div_ep);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Target/Constant7'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_TgtTrajCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
        } else {
            rtb_S_DPLTTG_TgtTrajCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_TgtTrajCrv_1pm = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_h = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_j2 = DW_dplttg_Unit_Delay1_DSTATE_j;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_b = rtb_S_DPLTTG_TgtTrajCrv_1pm;
    } else {
        rtb_SFunction_b = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_j2, rtb_S_DPLTTG_TgtTrajCrv_1pm, rtb_Div_h);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Target/Constant8'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_TgtTrajCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
        } else {
            rtb_S_DPLTTG_TgtTrajCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_TgtTrajCrvChng_1pm2 = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_aw = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_hh = DW_dplttg_Unit_Delay1_DSTATE_dv;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_c = rtb_S_DPLTTG_TgtTrajCrvChng_1pm2;
    } else {
        rtb_SFunction_c = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_hh, rtb_S_DPLTTG_TgtTrajCrvChng_1pm2, rtb_Div_aw);
    }
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/DefaultValues/Target/Constant9'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                 */
        if (((sint32)rtb_EQ_fe) != 0) {
            rtb_S_DPLTTG_TgtTrajLength_met = GET_S_ABPLBP_LeLnClthLength_met();
        } else {
            rtb_S_DPLTTG_TgtTrajLength_met = GET_S_ABPLBP_RiLnClthLength_met();
        }
        /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_DPLTTG_TgtTrajLength_met = 0.0F;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* Product: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_hh = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Max;
    /* UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_id = DW_dplttg_Unit_Delay1_DSTATE_nh;
    /* S-Function (sfun_mmv): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_dplttg_LogicalOperator != 0U) {
        rtb_SFunction_a = rtb_S_DPLTTG_TgtTrajLength_met;
    } else {
        rtb_SFunction_a = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_id, rtb_S_DPLTTG_TgtTrajLength_met, rtb_Div_hh);
    }
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/branch1'/copy1' */
    SET_S_DPLTTG_RiTgtTrajPosY0_met(rtb_Sum_nrb);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/branch10'/copy1' */
    SET_S_DPLTTG_LeTgtTrajPosY0_met(rtb_Sum_b);
    /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/Switch1/Functionality'/Switch' incorporates:
                                                  *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Application Parameter2'/Constant'
                                                  *  Constant: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/from_data_definition1'/state_source'
                                                  *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
                                                  *  Logic: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Logical Operator/Functionality'/NOT'
                                                  *  RelationalOperator: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/Relational Operator2/Functionality'/EQ'
                                                  *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch'
                                                  *  Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/Switch1/Functionality'/Switch'
                                                  *  UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2'
                                                  */
    if (((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) {
        rtb_Max = DW_dplttg_FixPtUnitDelay2_1_DSTATE;
        rtb_Sum_b = DW_dplttg_FixPtUnitDelay2_10_DSTATE;
        rtb_Sum_nrb = DW_dplttg_FixPtUnitDelay2_11_DSTATE;
        rtb_Switch_e4 = DW_dplttg_FixPtUnitDelay2_12_DSTATE;
        rtb_S_DPLTTG_TgtTrajPosX0_met_d = DW_dplttg_FixPtUnitDelay2_13_DSTATE;
        rtb_S_DPLTTG_TgtTrajPosY0_met_p = DW_dplttg_FixPtUnitDelay2_14_DSTATE;
        rtb_S_DPLTTG_TgtTrajHeadAng_rad_iu = DW_dplttg_FixPtUnitDelay2_15_DSTATE;
        rtb_S_DPLTTG_TgtTrajCrv_1pm_gc = DW_dplttg_FixPtUnitDelay2_16_DSTATE;
        rtb_S_DPLTTG_TgtTrajCrvChng_1pm2_nn = DW_dplttg_FixPtUnitDelay2_17_DSTATE;
        rtb_S_DPLTTG_TgtTrajLength_met_e5 = DW_dplttg_FixPtUnitDelay2_18_DSTATE;
        rtb_S_DPLTTG_LeCridrBndPosY0_met_bl = DW_dplttg_FixPtUnitDelay2_2_DSTATE;
        rtb_S_DPLTTG_LeCridrBndHeadAng_rad_cth = DW_dplttg_FixPtUnitDelay2_3_DSTATE;
        rtb_S_DPLTTG_LeCridrBndCrv_1pm_hr = DW_dplttg_FixPtUnitDelay2_4_DSTATE;
        rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2_l = DW_dplttg_FixPtUnitDelay2_5_DSTATE;
        rtb_S_DPLTTG_LeCridrBndLength_met_fz = DW_dplttg_FixPtUnitDelay2_6_DSTATE;
        rtb_S_DPLTTG_RiCridrBndPosX0_met_l = DW_dplttg_FixPtUnitDelay2_7_DSTATE;
        rtb_S_DPLTTG_RiCridrBndPosY0_met_i = DW_dplttg_FixPtUnitDelay2_8_DSTATE;
        rtb_S_DPLTTG_RiCridrBndHeadAng_rad_a = DW_dplttg_FixPtUnitDelay2_9_DSTATE;
    } else if (!(((sint32)GET_P_DPLTTG_TargetTrajPT1Active_nu()) != 0)) {
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Max = rtb_S_DPLTTG_LeCridrBndPosX0_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Sum_b = rtb_S_DPLTTG_RiCridrBndCrv_1pm;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Sum_nrb = rtb_S_DPLTTG_RiCridrBndCrvChng_1pm2;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Switch_e4 = rtb_S_DPLTTG_RiCridrBndLength_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_TgtTrajPosX0_met_d = rtb_S_DPLTTG_TgtTrajPosX0_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_TgtTrajPosY0_met_p = rtb_S_DPLTTG_TgtTrajPosY0_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_TgtTrajHeadAng_rad_iu = rtb_S_DPLTTG_TgtTrajHeadAng_rad;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_TgtTrajCrv_1pm_gc = rtb_S_DPLTTG_TgtTrajCrv_1pm;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_TgtTrajCrvChng_1pm2_nn = rtb_S_DPLTTG_TgtTrajCrvChng_1pm2;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_TgtTrajLength_met_e5 = rtb_S_DPLTTG_TgtTrajLength_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_LeCridrBndPosY0_met_bl = rtb_S_DPLTTG_LeCridrBndPosY0_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_LeCridrBndHeadAng_rad_cth = rtb_S_DPLTTG_LeCridrBndHeadAng_rad;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_LeCridrBndCrv_1pm_hr = rtb_S_DPLTTG_LeCridrBndCrv_1pm;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2_l = rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_LeCridrBndLength_met_fz = rtb_S_DPLTTG_LeCridrBndLength_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_RiCridrBndPosX0_met_l = rtb_S_DPLTTG_RiCridrBndPosX0_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_RiCridrBndPosY0_met_i = rtb_S_DPLTTG_RiCridrBndPosY0_met;
        /* Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_DPLTTG_RiCridrBndHeadAng_rad_a = rtb_S_DPLTTG_RiCridrBndHeadAng_rad;
    } else {
        rtb_Max = rtb_SFunction;
        rtb_Sum_b = rtb_SFunction_i;
        rtb_Sum_nrb = rtb_SFunction_fd;
        rtb_Switch_e4 = rtb_SFunction_fi;
        rtb_S_DPLTTG_TgtTrajPosX0_met_d = rtb_SFunction_ie;
        rtb_S_DPLTTG_TgtTrajPosY0_met_p = rtb_SFunction_n;
        rtb_S_DPLTTG_TgtTrajHeadAng_rad_iu = rtb_SFunction_k;
        rtb_S_DPLTTG_TgtTrajCrv_1pm_gc = rtb_SFunction_b;
        rtb_S_DPLTTG_TgtTrajCrvChng_1pm2_nn = rtb_SFunction_c;
        rtb_S_DPLTTG_TgtTrajLength_met_e5 = rtb_SFunction_a;
        rtb_S_DPLTTG_LeCridrBndPosY0_met_bl = rtb_SFunction_e;
        rtb_S_DPLTTG_LeCridrBndHeadAng_rad_cth = rtb_SFunction_o;
        rtb_S_DPLTTG_LeCridrBndCrv_1pm_hr = rtb_SFunction_ec;
        rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2_l = rtb_SFunction_m;
        rtb_S_DPLTTG_LeCridrBndLength_met_fz = rtb_SFunction_f;
        rtb_S_DPLTTG_RiCridrBndPosX0_met_l = rtb_SFunction_g;
        rtb_S_DPLTTG_RiCridrBndPosY0_met_i = rtb_SFunction_l;
        rtb_S_DPLTTG_RiCridrBndHeadAng_rad_a = rtb_SFunction_la;
    }
    /* End of Switch: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_LeCridrBndPosX0_met(rtb_Max);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_RiCridrBndCrv_1pm(rtb_Sum_b);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_RiCridrBndCrvChng_1pm2(rtb_Sum_nrb);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_RiCridrBndLength_met(rtb_Switch_e4);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_TgtTrajPosX0_met(rtb_S_DPLTTG_TgtTrajPosX0_met_d);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_TgtTrajPosY0_met(rtb_S_DPLTTG_TgtTrajPosY0_met_p);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_TgtTrajHeadAng_rad(rtb_S_DPLTTG_TgtTrajHeadAng_rad_iu);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_TgtTrajCrv_1pm(rtb_S_DPLTTG_TgtTrajCrv_1pm_gc);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_TgtTrajCrvChng_1pm2(rtb_S_DPLTTG_TgtTrajCrvChng_1pm2_nn);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_TgtTrajLength_met(rtb_S_DPLTTG_TgtTrajLength_met_e5);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_LeCridrBndPosY0_met(rtb_S_DPLTTG_LeCridrBndPosY0_met_bl);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_LeCridrBndHeadAng_rad(rtb_S_DPLTTG_LeCridrBndHeadAng_rad_cth);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_LeCridrBndCrv_1pm(rtb_S_DPLTTG_LeCridrBndCrv_1pm_hr);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_LeCridrBndCrvChng_1pm2(rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2_l);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_LeCridrBndLength_met(rtb_S_DPLTTG_LeCridrBndLength_met_fz);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_RiCridrBndPosX0_met(rtb_S_DPLTTG_RiCridrBndPosX0_met_l);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_RiCridrBndPosY0_met(rtb_S_DPLTTG_RiCridrBndPosY0_met_i);
    /* SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout/branch16'/copy1' */
    SET_S_DPLTTG_RiCridrBndHeadAng_rad(rtb_S_DPLTTG_RiCridrBndHeadAng_rad_a);
    /* S-Function (fcncallgen): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING'/fcg' incorporates:
                                                                          *  SubSystem: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING'/Functionality'
                                                                          */
    /* S-Function (fcncallgen): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplttg_Unit_Delay_DSTATE = rtb_EQ;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/EdgeRising/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE = rtb_SFunction;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor'/FixPt Unit Delay1' */
    DW_dplttg_FixPtUnitDelay1_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/LeftRightCorridor'/FixPt Unit Delay3' */
    DW_dplttg_FixPtUnitDelay3_DSTATE = rtb_DataTypeConversion_a;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_c = rtb_SFunction_e;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_o = rtb_SFunction_o;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_m = rtb_SFunction_ec;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_b = rtb_SFunction_m;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_n = rtb_SFunction_f;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_g = rtb_SFunction_g;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_o1 = rtb_SFunction_l;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_ch = rtb_SFunction_la;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_mq = rtb_SFunction_i;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_d = rtb_SFunction_fd;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_bc = rtb_SFunction_fi;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_e = rtb_SFunction_ie;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay4' */
    DW_dplttg_FixPtUnitDelay4_DSTATE = rtb_Switch_fy;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay3' */
    DW_dplttg_FixPtUnitDelay3_DSTATE_f = rtb_DataTypeConversion_a;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay1' */
    DW_dplttg_FixPtUnitDelay1_DSTATE_o = rtb_Switch_bq;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/LeTgtMaxLatDev'/FixPt Unit Delay4' */
    DW_dplttg_FixPtUnitDelay4_DSTATE_f = rtb_Switch_nw;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay5' */
    DW_dplttg_FixPtUnitDelay5_DSTATE = rtb_Switch_p;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_DSTATE = rtb_Div_go;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /LDP_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation/RiTgtMaxLatDev'/FixPt Unit Delay4' */
    DW_dplttg_FixPtUnitDelay4_DSTATE_g = rtb_Sum;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_i = rtb_SFunction_n;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_me = rtb_SFunction_k;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_j = rtb_SFunction_b;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_dv = rtb_SFunction_c;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Filter_LDP_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5'/Unit_Delay1' */
    DW_dplttg_Unit_Delay1_DSTATE_nh = rtb_SFunction_a;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_1_DSTATE = rtb_Max;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_10_DSTATE = rtb_Sum_b;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_11_DSTATE = rtb_Sum_nrb;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_12_DSTATE = rtb_Switch_e4;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_13_DSTATE = rtb_S_DPLTTG_TgtTrajPosX0_met_d;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_14_DSTATE = rtb_S_DPLTTG_TgtTrajPosY0_met_p;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_15_DSTATE = rtb_S_DPLTTG_TgtTrajHeadAng_rad_iu;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_16_DSTATE = rtb_S_DPLTTG_TgtTrajCrv_1pm_gc;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_17_DSTATE = rtb_S_DPLTTG_TgtTrajCrvChng_1pm2_nn;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_18_DSTATE = rtb_S_DPLTTG_TgtTrajLength_met_e5;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_2_DSTATE = rtb_S_DPLTTG_LeCridrBndPosY0_met_bl;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_3_DSTATE = rtb_S_DPLTTG_LeCridrBndHeadAng_rad_cth;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_4_DSTATE = rtb_S_DPLTTG_LeCridrBndCrv_1pm_hr;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_5_DSTATE = rtb_S_DPLTTG_LeCridrBndCrvChng_1pm2_l;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_6_DSTATE = rtb_S_DPLTTG_LeCridrBndLength_met_fz;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_7_DSTATE = rtb_S_DPLTTG_RiCridrBndPosX0_met_l;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_8_DSTATE = rtb_S_DPLTTG_RiCridrBndPosY0_met_i;
    /* Update for UnitDelay: 'sda:DPLTTG/DPLTTG/DPLTTG_SenProcess/OPM/M_LDPSA_TargetTrajGenerator /Rampout'/FixPt Unit Delay2' */
    DW_dplttg_FixPtUnitDelay2_9_DSTATE = rtb_S_DPLTTG_RiCridrBndHeadAng_rad_a;
}
#include "Pse_DPLTTG.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
