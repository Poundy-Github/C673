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
 * File          : DPRTVG
 * Generated on  : Mon 11.03.2019 at 14:05:49 (UTC+01:00)
 * MD5           : [1858368990  2649417683  3002613324  1834134524 0](DPRTVG)
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
 * Date          : $Date: 2019/05/29 09:52:23CEST $
 * Changes       :
 * $Log: DPRTVG.c  $
 * Revision 1.2.1.1 2019/05/29 09:52:23CEST Diaz Bravo, Jose Luis (uidg8685) 
 * B2B
 * Revision 1.29 2019/03/14 12:52:58CET Diaz Bravo, Jose Luis (uidg8685) 
 * automatically created
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "DPRTVG.h"
#include "DPRTVG_private.h"
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
#define DPRTVG_START_SEC_DATA_8
#include "DPRTVG_MemMap.h"
static uint8 DW_dprtvg_Unit_Delay1_DSTATE_f;
static uint8 DW_dprtvg_Unit_Delay3_DSTATE;
#define DPRTVG_STOP_SEC_DATA_8
#include "DPRTVG_MemMap.h"
#define DPRTVG_START_SEC_DATA_32
#include "DPRTVG_MemMap.h"
static float32 DW_dprtvg_Unit_Delay_DSTATE;
static float32 DW_dprtvg_Unit_Delay2_DSTATE;
static float32 DW_dprtvg_Unit_Delay_DSTATE_f;
static float32 DW_dprtvg_Unit_Delay1_DSTATE;
#define DPRTVG_STOP_SEC_DATA_32
#include "DPRTVG_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPRTVG/DPRTVG/INI'/DPRTVG_SenReset'
 * Block description for: 'sda:DPRTVG/DPRTVG/INI'/DPRTVG_SenReset'
 *   .1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRTVG_SenReset
#include "Pse_DPRTVG.h"
/* Short description: Not synchronized with ARAMIS */
void DPRTVG_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant1'/Constant' */
    SET_S_DPRTVG_TrajPlanServQu_nu(0U);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant10'/Constant' */
    SET_S_DPRTVG_PredTimeCrv_sec(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant11'/Constant' */
    SET_S_DPRTVG_PredTimeHeadAng_sec(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant12'/Constant' */
    SET_S_DPRTVG_TriggerReplan_bool(0U);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant13'/Constant' */
    SET_S_DPRTVG_MaxCrvTrajGuiCtrl_1pm(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant14'/Constant' */
    SET_S_DPRTVG_MaxCrvGrdBuildup_1pms(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant15'/Constant' */
    SET_S_DPRTVG_MaxCrvGrdRed_1pms(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant16'/Constant' */
    SET_S_DPRTVG_GrdLimitTgtCrvTGC_1pms(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant17'/Constant' */
    SET_S_DPRTVG_PlanningHorizon_sec(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant18'/Constant' */
    SET_S_DPRTVG_DeratingLevel_nu(0U);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant19'/Constant' */
    SET_S_DPRTVG_StrWhStifLimit_nu(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant2'/Constant' */
    SET_S_DPRTVG_DistYTolLeTgtArea_met(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant20'/Constant' */
    SET_S_DPRTVG_MaxTrqScalLimit_nu(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant21'/Constant' */
    SET_S_DPRTVG_ObstacleVelX_mps(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant22'/Constant' */
    SET_S_DPRTVG_ObstacleAclX_mps2(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant23'/Constant' */
    SET_S_DPRTVG_ObstacleWidth_met(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant24'/Constant' */
    SET_S_DPRTVG_ObstacleDistX_met(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant25'/Constant' */
    SET_S_DPRTVG_ObstacleDistY_met(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant26'/Constant' */
    SET_S_DPRTVG_LtcyCompActivated_bool(0U);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant28'/Constant' */
    SET_S_DPRTVG_LimiterActivated_bool(0U);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant3'/Constant' */
    SET_S_DPRTVG_DistYTolRiTgtArea_met(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant30'/Constant' */
    SET_S_DPRTVG_LimiterTimeDuration_sec(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant32'/Constant' */
    SET_S_DPRTVG_HighStatAccu_bool(0U);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant33'/Constant' */
    SET_S_DPRTVG_StrWhStifGrad_1ps(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant34'/Constant' */
    SET_S_DPRTVG_TrqRampGrad_1ps(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant35'/Constant' */
    SET_S_DPRTVG_MaxJerkAllowed_mps3(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant4'/Constant' */
    SET_S_DPRTVG_FTireAclMax_mps2(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant5'/Constant' */
    SET_S_DPRTVG_FTireAclMin_mps2(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant6'/Constant' */
    SET_S_DPRTVG_WeightTgtDistY_nu(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant7'/Constant' */
    SET_S_DPRTVG_WeightEndTime_nu(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant8'/Constant' */
    SET_S_DPRTVG_MaxTrqScalGrad_1ps(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/Constant9'/Constant' */
    SET_S_DPRTVG_SensorTStamp_sec(0.0F);
    /* SignalConversion: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/from_data_definition3'/Signal Conversion3' incorporates:
                                            *  Constant: 'sda:DPRTVG/DPRTVG/INI/DPRTVG_SenReset/from_data_definition3'/state_source'
                                            */
    SET_S_DPRTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
}
#include "Pse_DPRTVG.h"
/*
 * Output and update for function-call system: 'sda:DPRTVG/DPRTVG'/DPRTVG_SenProcess'
 * Block description for: 'sda:DPRTVG/DPRTVG'/DPRTVG_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRTVG_SenProcess
#include "Pse_DPRTVG.h"
/* Short description: Not synchronized with ARAMIS */
void DPRTVG_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Abs;
    float32 rtb_Abs_b;
    float32 rtb_Switch;
    float32 rtb_Abs_j;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_Abs_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_o;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_ii;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_fa;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_EQ_l;
    float32 rtb_Switch_kc;
    float32 rtb_Switch_b4;
    float32 rtb_Switch_jl;
    float32 rtb_Switch_c;
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Application Parameter5'/Constant' */
    SET_S_DPRTVG_FTireAclMax_mps2(GET_P_DPRTVG_FTireAccelMax_mps2());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Application Parameter2'/Constant' */
    SET_S_DPRTVG_FTireAclMin_mps2(GET_P_DPRTVG_FTireAccelMin_mps2());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Application Parameter6'/Constant' */
    SET_S_DPRTVG_DistYTolLeTgtArea_met(GET_P_DPRTVG_DistYTolLeTgtArea_met());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Application Parameter7'/Constant' */
    SET_S_DPRTVG_DistYTolRiTgtArea_met(GET_P_DPRTVG_DistYTolRiTgtArea_met());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Application Parameter12'/Constant' */
    SET_S_DPRTVG_WeightTgtDistY_nu(GET_P_DPRTVG_WeightTgtDistY_nu());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Application Parameter1'/Constant' */
    SET_S_DPRTVG_TrajPlanServQu_nu(GET_P_DPRTVG_TrajPlanServQu_nu());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Application Parameter9'/Constant' */
    SET_S_DPRTVG_PredTimeCrv_sec(GET_P_DPRTVG_PredTimeCrv_sec());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Application Parameter10'/Constant' */
    SET_S_DPRTVG_PredTimeHeadAng_sec(GET_P_DPRTVG_PredTimeHeadAng_sec());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Constant2'/Constant' */
    SET_S_DPRTVG_LtcyCompActivated_bool(GET_P_DPRTVG_UseLtcyComp_nu());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Constant3'/Constant' */
    SET_S_DPRTVG_LimiterActivated_bool(GET_P_DPRTVG_LimiterActivated_bool());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Constant5'/Constant' */
    SET_S_DPRTVG_LimiterTimeDuration_sec(GET_P_DPRTVG_LimiterTimeDuration_sec());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Constant1'/Constant' */
    SET_S_DPRTVG_MaxJerkAllowed_mps3(GET_P_DPRTVG_MaxJerkAllowed_mps3());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetParamOutputs/Constant4'/Constant' */
    SET_S_DPRTVG_TriggerReplan_bool(GET_P_DPRTVG_TriggerReplan_bool());
    /* DataTypeConversion: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
                                                                          *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/from_data_definition'/state_source'
                                                                          *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/from_data_definition1'/state_source'
                                                                          *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
                                                                          *  Logic: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Logical Operator8/Functionality'/OR'
                                                                          *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/RelatOperator2/Functionality'/EQ'
                                                                          *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/RelatOperator3/Functionality'/EQ'
                                                                          */
    rtb_DataTypeConversion = (uint8)((((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))));
    /* RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/RelatOperator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
         */
    rtb_EQ_l = (uint8)(((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Constant4'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDP_mps'
         *  Inport: '<Root>/S_DPRSMI_DangerousSide_nu'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/RelatOperator5/Functionality'/EQ'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Switch12/Functionality'/Switch'
         */
    if (((sint32)GET_S_DPRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        rtb_Switch_kc = GET_S_DPRSIA_VelLatLnRiRDP_mps();
    } else if (((sint32)GET_S_DPRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Switch12/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_DPRSIA_VelLatLnLeRDP_mps'
                 */
        rtb_Switch_kc = GET_S_DPRSIA_VelLatLnLeRDP_mps();
    } else {
        rtb_Switch_kc = 0.0F;
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Switch8/Functionality'/Switch' */
    /* Abs: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Abs2/Functionality'/Abs' */
    rtb_Abs = f32_abs_f32(rtb_Switch_kc);
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Constant1'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDP_mps'
         *  Inport: '<Root>/S_DPRSMI_DangerousSide_nu'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/RelatOperator2/Functionality'/EQ'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Switch1/Functionality'/Switch'
         */
    if (((sint32)GET_S_DPRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        rtb_Switch_kc = GET_S_DPRSIA_VelLatReRiRDP_mps();
    } else if (((sint32)GET_S_DPRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_DPRSIA_VelLatReLeRDP_mps'
                 */
        rtb_Switch_kc = GET_S_DPRSIA_VelLatReLeRDP_mps();
    } else {
        rtb_Switch_kc = 0.0F;
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Switch3/Functionality'/Switch' */
    /* Abs: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/VelLatDetermination/Abs3/Functionality'/Abs' */
    rtb_Abs_b = f32_abs_f32(rtb_Switch_kc);
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
         *  Logic: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Relational Operator2/Functionality'/EQ'
         */
    if ((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32) GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH)))) {
        rtb_Switch = rtb_Abs;
    } else {
        rtb_Switch = rtb_Abs_b;
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch8/Functionality'/Switch' */
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch/Functionality'/Switch' incorporates:
         *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Y_DPRTVG_VYStrWhStifRIGrad_1ps/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Y_DPRTVG_VYStrWhStifRIGrad_1ps/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu'/Unit_Delay'
         *  UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu'/Unit_Delay1'
         */
    if (((sint32)DW_dprtvg_Unit_Delay1_DSTATE_f) != 0) {
        rtb_Switch_kc = DW_dprtvg_Unit_Delay_DSTATE;
    } else {
        /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Y_DPRTVG_VYStrWhStifRIGrad_1ps/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Switch, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_fa = F32_PTR_IP1D (GETA_Y_DPRTVG_VYStrWhStifRIGrad_1ps(), &dps_result_ln);
        }
        rtb_Switch_kc = rtb_ip_lookup_fxpt_sfun_7_fa;
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant2'/Constant'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        SET_S_DPRTVG_MaxTrqScalGrad_1ps(GET_P_DPRTVG_MaxTrqScalRampInGrd_1ps());
    } else if (((sint32)rtb_EQ_l) != 0) {
        /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter5'/Constant'
                 */
        SET_S_DPRTVG_MaxTrqScalGrad_1ps(GET_P_DPRTVG_MaxTrqScalRampOutGrd_1ps());
    } else {
        SET_S_DPRTVG_MaxTrqScalGrad_1ps(0.0F);
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch13/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant14'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_DrivingMode_nu'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Relational Operator8/Functionality'/EQ'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch12/Functionality'/Switch'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch15/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu'/Unit_Delay2'
         *  UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu'/Unit_Delay3'
         */
    if (((sint32)DW_dprtvg_Unit_Delay3_DSTATE) != 0) {
        rtb_Switch_c = DW_dprtvg_Unit_Delay2_DSTATE;
    } else if (((sint32)GET_S_LCFRCV_DrivingMode_nu()) == 3) {
        /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Y_DPRTVG_VYMD3DeratingLevel_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Switch, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ii = F32_PTR_IP1D (GETA_Y_DPRTVG_VYMD3DeratingLevel_nu(), &dps_result_ln);
        }
        rtb_Switch_c = rtb_ip_lookup_fxpt_sfun_7_ii;
    } else if (((sint32)GET_S_LCFRCV_DrivingMode_nu()) == 2) {
        /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Y_DPRTVG_VYMD2DeratingLevel_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Switch, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_DPRTVG_VYMD2DeratingLevel_nu(), &dps_result_ln);
        }
        rtb_Switch_c = rtb_ip_lookup_fxpt_sfun_7_g;
    } else {
        /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Y_DPRTVG_VYMD1DeratingLevel_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Switch, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_DPRTVG_VYMD1DeratingLevel_nu(), &dps_result_ln);
        }
        rtb_Switch_c = rtb_ip_lookup_fxpt_sfun_7_j;
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch13/Functionality'/Switch' */
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch14/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant1'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant3'/Constant'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant6'/Constant'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch2/Functionality'/Switch'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch4/Functionality'/Switch'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch6/Functionality'/Switch'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch9/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        SET_S_DPRTVG_DeratingLevel_nu(u8_f32(rtb_Switch_c));
        SET_S_DPRTVG_StrWhStifGrad_1ps(rtb_Switch_kc);
        SET_S_DPRTVG_StrWhStifLimit_nu(GET_P_DPRTVG_StrWhStifLimit_nu());
        SET_S_DPRTVG_MaxTrqScalLimit_nu(GET_P_DPRTVG_MaxTrqScalLimit_nu());
        SET_S_DPRTVG_TrqRampGrad_1ps(GET_P_DPRTVG_TrqRampInGrad_1ps());
    } else {
        SET_S_DPRTVG_DeratingLevel_nu(0U);
        /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch3/Functionality'/Switch' incorporates:
                                                *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant'/Constant'
                                                *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant5'/Constant'
                                                *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Constant6'/Constant'
                                                *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch10/Functionality'/Switch'
                                                */
        if (((sint32)rtb_EQ_l) != 0) {
            /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter2'/Constant'
                         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter7'/Constant'
                         *  Inport: '<Root>/S_DPRSMI_FunctionAborted_bool'
                         */
            if (((sint32)GET_S_DPRSMI_FunctionAborted_bool()) != 0) {
                SET_S_DPRTVG_StrWhStifGrad_1ps(GET_P_DPRTVG_StrWhStifAbortROGrd_1ps());
            } else {
                SET_S_DPRTVG_StrWhStifGrad_1ps(GET_P_DPRTVG_StrWhStifROGrad_1ps());
            }
            /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch7/Functionality'/Switch' */
            /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch11/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter12'/Constant'
                         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter8'/Constant'
                         *  Inport: '<Root>/S_DPRSMI_FunctionAborted_bool'
                         */
            if (((sint32)GET_S_DPRSMI_FunctionAborted_bool()) != 0) {
                SET_S_DPRTVG_TrqRampGrad_1ps(GET_P_DPRTVG_TrqAbortROGrad_1ps());
            } else {
                SET_S_DPRTVG_TrqRampGrad_1ps(GET_P_DPRTVG_TrqRampOutGrad_1ps());
            }
            /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch11/Functionality'/Switch' */
        } else {
            SET_S_DPRTVG_StrWhStifGrad_1ps(0.0F);
            SET_S_DPRTVG_TrqRampGrad_1ps(0.0F);
        }
        /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch3/Functionality'/Switch' */
        SET_S_DPRTVG_StrWhStifLimit_nu(0.0F);
        SET_S_DPRTVG_MaxTrqScalLimit_nu(0.0F);
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Switch14/Functionality'/Switch' */
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu/Application Parameter10'/Constant' */
    SET_S_DPRTVG_HighStatAccu_bool(GET_P_DPRTVG_HighStatAccu_bool());
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/Switch3/Functionality'/Switch' incorporates:
                                                                        *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/from_data_definition'/state_source'
                                                                        *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/from_data_definition1'/state_source'
                                                                        *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/from_data_definition3'/state_source'
                                                                        *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/from_data_definition4'/state_source'
                                                                        *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/from_data_definition5'/state_source'
                                                                        *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
                                                                        *  Logic: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/OR/Functionality'/OR'
                                                                        *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/Relational Operator1/Functionality'/EQ'
                                                                        *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/Relational Operator2/Functionality'/EQ'
                                                                        *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/Relational Operator5/Functionality'/EQ'
                                                                        *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/Switch5/Functionality'/Switch'
                                                                        */
    if (((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) {
        SET_S_DPRTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE));
    } else if ((((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) {
        /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/from_data_definition2'/state_source'
                 */
        SET_S_DPRTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ));
    } else {
        SET_S_DPRTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineTrajGuiQualifier/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/OR1/Functionality'/OR'
         *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Mul/Functionality'/Mul'
         *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Mul1/Functionality'/Mul'
         *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Mul2/Functionality'/Mul'
         *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality/odtc'/Product'
         *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu1/Functionality/odtc'/Product'
         *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_CrvPlanHorizonScal_nu/Functionality/odtc'/Product'
         *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_D2TPlanHorizonScal_nu/Functionality/odtc'/Product'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Relational Operator4/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_CrvPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_D2TPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs'/Unit_Delay'
         *  UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs'/Unit_Delay1'
         */
    if ((((sint32)GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)))) {
        rtb_Switch_b4 = DW_dprtvg_Unit_Delay_DSTATE_f;
        rtb_Switch_jl = DW_dprtvg_Unit_Delay1_DSTATE;
    } else {
        /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_DPRTVG_VXWeightEndtime_nu(), &dps_result_ln);
        }
        rtb_Switch_b4 = rtb_ip_lookup_fxpt_sfun_7_p;
        /* Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/from_data_definition4'/state_source'
                 *  Inport: '<Root>/S_DPRSMI_TriggerReason_nu'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Logic: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/OR2/Functionality'/OR'
                 *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality/odtc'/Product'
                 *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_VYPlanHorizonLn_sec/Functionality/odtc'/Product'
                 *  Product: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_VYPlanHorizonRe_sec/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Relational Operator1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Relational Operator2/Functionality'/EQ'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_VYPlanHorizonLn_sec/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_VYPlanHorizonRe_sec/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        if ((((sint32)GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32) GET_S_DPRSMI_TriggerReason_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH)))) {
            /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_VYPlanHorizonLn_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_VelY_mps */
                FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D (GETA_Y_DPRTVG_VYPlanHorizonLn_sec(), &dps_result_ln);
            }
            rtb_Switch_jl = rtb_ip_lookup_fxpt_sfun_7_f;
        } else {
            /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_VYPlanHorizonRe_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_VelY_mps */
                FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs_b, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D (GETA_Y_DPRTVG_VYPlanHorizonRe_sec(), &dps_result_ln);
            }
            rtb_Switch_jl = rtb_ip_lookup_fxpt_sfun_7_i;
        }
        /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Switch2/Functionality'/Switch' */
        /* Abs: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Abs1/Functionality'/Abs' incorporates:
                 *  Inport: '<Root>/S_DPRTTG_TgtTrajPosY0_met'
                 */
        rtb_Abs_j = f32_abs_f32(GET_S_DPRTTG_TgtTrajPosY0_met());
        /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_D2TPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_DistY_met */
            FDPS_PTR_F32(GETA_X_LCF_DistY_met(), rtb_Abs_j, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D (GETA_Y_DPRTVG_D2TPlanHorizonScal_nu(), &dps_result_ln);
        }
        /* Abs: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Abs/Functionality'/Abs' incorporates:
                 *  Inport: '<Root>/S_DPRTTG_TgtTrajCrv_1pm'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_D2TPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_Abs_a = f32_abs_f32(GET_S_DPRTTG_TgtTrajCrv_1pm());
        /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPRTVG_CrvPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_a, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_o = F32_PTR_IP1D (GETA_Y_DPRTVG_CrvPlanHorizonScal_nu(), &dps_result_ln);
        }
        /* S-Function Block sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_DPRTVG_VXPlanHorizonScal_nu(), &dps_result_ln);
        }
        rtb_Switch_jl *= (rtb_ip_lookup_fxpt_sfun_7_m * rtb_ip_lookup_fxpt_sfun_7_o) * rtb_ip_lookup_fxpt_sfun_7;
    }
    /* End of Switch: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/branch'/copy1' */
    SET_S_DPRTVG_PlanningHorizon_sec(rtb_Switch_jl);
    /* SignalConversion: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs/branch1'/copy1' */
    SET_S_DPRTVG_WeightEndTime_nu(rtb_Switch_b4);
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/CrvLimitation/Application Parameter6'/Constant' */
    SET_S_DPRTVG_MaxCrvTrajGuiCtrl_1pm(GET_P_DPRTVG_LimiterMaxCrv_1pm());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/CrvLimitation/Application Parameter2'/Constant' */
    SET_S_DPRTVG_MaxCrvGrdBuildup_1pms(GET_P_DPRTVG_LimiterMaxCrvGrd_1pms());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/CrvLimitation/Application Parameter1'/Constant' */
    SET_S_DPRTVG_MaxCrvGrdRed_1pms(GET_P_DPRTVG_LimiterMaxCrvGrd_1pms());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/CrvLimitation/Application Parameter3'/Constant' */
    SET_S_DPRTVG_GrdLimitTgtCrvTGC_1pms(GET_P_DPRTVG_LimiterMaxCrvGrd_1pms());
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetConstOutputs/Constant87'/Constant' */
    SET_S_DPRTVG_ObstacleVelX_mps(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetConstOutputs/Constant88'/Constant' */
    SET_S_DPRTVG_ObstacleAclX_mps2(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetConstOutputs/Constant85'/Constant' */
    SET_S_DPRTVG_ObstacleWidth_met(0.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetConstOutputs/Constant86'/Constant' */
    SET_S_DPRTVG_ObstacleDistX_met(100.0F);
    /* Constant: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetConstOutputs/Constant84'/Constant' */
    SET_S_DPRTVG_ObstacleDistY_met(100.0F);
    /* SignalConversion: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/branch1'/copy1' incorporates:
                                              *  Inport: '<Root>/S_ABPLBP_ABDTimeStamp_sec'
                                              */
    SET_S_DPRTVG_SensorTStamp_sec(GET_S_ABPLBP_ABDTimeStamp_sec());
    /* Update for UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu'/Unit_Delay' */
    DW_dprtvg_Unit_Delay_DSTATE = rtb_Switch_kc;
    /* Update for UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu'/Unit_Delay1' */
    DW_dprtvg_Unit_Delay1_DSTATE_f = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu'/Unit_Delay2' */
    DW_dprtvg_Unit_Delay2_DSTATE = rtb_Switch_c;
    /* Update for UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/DetermineStiffnessAndStatAccu'/Unit_Delay3' */
    DW_dprtvg_Unit_Delay3_DSTATE = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs'/Unit_Delay' */
    DW_dprtvg_Unit_Delay_DSTATE_f = rtb_Switch_b4;
    /* Update for UnitDelay: 'sda:DPRTVG/DPRTVG/DPRTVG_SenProcess/OPM/M_DPRTVG/SetLookupOutputs'/Unit_Delay1' */
    DW_dprtvg_Unit_Delay1_DSTATE = rtb_Switch_jl;
}
#include "Pse_DPRTVG.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
