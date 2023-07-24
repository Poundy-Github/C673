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
 * File          : DPLTVG
 * Generated on  : Tue 19.03.2019 at 10:11:51 (UTC+01:00)
 * MD5           : [1110171761  2726976392  2764735055  4091939359 0](DPLTVG)
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
 * Date          : $Date: 2019/05/29 09:54:51CEST $
 * Changes       :
 * $Log: DPLTVG.c  $
 * Revision 1.2.1.1 2019/05/29 09:54:51CEST Diaz Bravo, Jose Luis (uidg8685) 
 * B2B
 * Revision 1.30 2019/03/19 10:43:30CET Diaz Bravo, Jose Luis (uidg8685) 
 * Inner/outer curve logic
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "DPLTVG.h"
#include "DPLTVG_private.h"
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
#define DPLTVG_START_SEC_DATA_8
#include "DPLTVG_MemMap.h"
static uint8 DW_dpltvg_Unit_Delay3_DSTATE;
static uint8 DW_dpltvg_Unit_Delay1_DSTATE_i;
#define DPLTVG_STOP_SEC_DATA_8
#include "DPLTVG_MemMap.h"
#define DPLTVG_START_SEC_DATA_32
#include "DPLTVG_MemMap.h"
static float32 DW_dpltvg_Unit_Delay2_DSTATE;
static float32 DW_dpltvg_Unit_Delay_DSTATE;
static float32 DW_dpltvg_Unit_Delay_DSTATE_o;
static float32 DW_dpltvg_Unit_Delay1_DSTATE;
#define DPLTVG_STOP_SEC_DATA_32
#include "DPLTVG_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPLTVG/DPLTVG/INI'/DPLTVG_SenReset'
 * Block description for: 'sda:DPLTVG/DPLTVG/INI'/DPLTVG_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLTVG_SenReset
#include "Pse_DPLTVG.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLTVG_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant1'/Constant' */
    SET_S_DPLTVG_SensorTStamp_sec(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant10'/Constant' */
    SET_S_DPLTVG_PredTimeCrv_sec(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant11'/Constant' */
    SET_S_DPLTVG_PredTimeHeadAng_sec(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant12'/Constant' */
    SET_S_DPLTVG_TriggerReplan_bool(0U);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant13'/Constant' */
    SET_S_DPLTVG_MaxCrvTrajGuiCtrl_1pm(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant14'/Constant' */
    SET_S_DPLTVG_MaxCrvGrdBuildup_1pms(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant15'/Constant' */
    SET_S_DPLTVG_MaxCrvGrdRed_1pms(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant16'/Constant' */
    SET_S_DPLTVG_GrdLimitTgtCrvTGC_1pms(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant17'/Constant' */
    SET_S_DPLTVG_PlanningHorizon_sec(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant18'/Constant' */
    SET_S_DPLTVG_TrajPlanServQu_nu(0U);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant19'/Constant' */
    SET_S_DPLTVG_StrWhStifLimit_nu(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant2'/Constant' */
    SET_S_DPLTVG_DistYTolLeTgtArea_met(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant20'/Constant' */
    SET_S_DPLTVG_MaxTrqScalLimit_nu(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant21'/Constant' */
    SET_S_DPLTVG_ObstacleVelX_mps(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant22'/Constant' */
    SET_S_DPLTVG_ObstacleAclX_mps2(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant23'/Constant' */
    SET_S_DPLTVG_ObstacleWidth_met(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant24'/Constant' */
    SET_S_DPLTVG_ObstacleDistX_met(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant25'/Constant' */
    SET_S_DPLTVG_ObstacleDistY_met(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant26'/Constant' */
    SET_S_DPLTVG_LtcyCompActivated_bool(0U);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant28'/Constant' */
    SET_S_DPLTVG_LimiterActivated_bool(0U);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant3'/Constant' */
    SET_S_DPLTVG_DistYTolRiTgtArea_met(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant30'/Constant' */
    SET_S_DPLTVG_LimiterTimeDuration_sec(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant32'/Constant' */
    SET_S_DPLTVG_MaxTrqScalGrad_1ps(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant33'/Constant' */
    SET_S_DPLTVG_HighStatAccu_bool(0U);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant34'/Constant' */
    SET_S_DPLTVG_StrWhStifGrad_1ps(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant35'/Constant' */
    SET_S_DPLTVG_TrqRampGrad_1ps(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant4'/Constant' */
    SET_S_DPLTVG_FTireAclMax_mps2(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant5'/Constant' */
    SET_S_DPLTVG_FTireAclMin_mps2(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant6'/Constant' */
    SET_S_DPLTVG_WeightTgtDistY_nu(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant7'/Constant' */
    SET_S_DPLTVG_WeightEndTime_nu(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant8'/Constant' */
    SET_S_DPLTVG_MaxJerkAllowed_mps3(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/Constant9'/Constant' */
    SET_S_DPLTVG_DeratingLevel_nu(0U);
    /* SignalConversion: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/from_data_definition3'/Signal Conversion3' incorporates:
                                            *  Constant: 'sda:DPLTVG/DPLTVG/INI/DPLTVG_SenReset/from_data_definition3'/state_source'
                                            */
    SET_S_DPLTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
}
#include "Pse_DPLTVG.h"
/*
 * Output and update for function-call system: 'sda:DPLTVG/DPLTVG'/DPLTVG_SenProcess'
 * Block description for: 'sda:DPLTVG/DPLTVG'/DPLTVG_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLTVG_SenProcess
#include "Pse_DPLTVG.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLTVG_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Abs;
    float32 rtb_Abs_o;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_Abs_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_j5;
    float32 rtb_Switch_ah;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_EQ_f;
    float32 rtb_Switch_ko;
    float32 rtb_Switch_as;
    uint8 rtb_EQ_br;
    float32 rtb_Switch_fj;
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Application Parameter5'/Constant' */
    SET_S_DPLTVG_FTireAclMax_mps2(GET_P_DPLTVG_FTireAclMax_mps2());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Application Parameter2'/Constant' */
    SET_S_DPLTVG_FTireAclMin_mps2(GET_P_DPLTVG_FTireAclMin_mps2());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Application Parameter6'/Constant' */
    SET_S_DPLTVG_DistYTolLeTgtArea_met(GET_P_DPLTVG_DistYTolLeTgtArea_met());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Application Parameter7'/Constant' */
    SET_S_DPLTVG_DistYTolRiTgtArea_met(GET_P_DPLTVG_DistYTolRiTgtArea_met());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Application Parameter12'/Constant' */
    SET_S_DPLTVG_WeightTgtDistY_nu(GET_P_DPLTVG_WeightTgtDistY_nu());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Application Parameter1'/Constant' */
    SET_S_DPLTVG_TrajPlanServQu_nu(GET_P_DPLTVG_TrajPlanServQu_nu());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Application Parameter9'/Constant' */
    SET_S_DPLTVG_PredTimeCrv_sec(GET_P_DPLTVG_PredTimeCrv_sec());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Application Parameter10'/Constant' */
    SET_S_DPLTVG_PredTimeHeadAng_sec(GET_P_DPLTVG_PredTimeHeadAng_sec());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Constant2'/Constant' */
    SET_S_DPLTVG_LtcyCompActivated_bool(GET_P_DPLTVG_UseLtcyComp_nu());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Constant4'/Constant' */
    SET_S_DPLTVG_LimiterActivated_bool(GET_P_DPLTVG_LimiterActivated_bool());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Constant6'/Constant' */
    SET_S_DPLTVG_LimiterTimeDuration_sec(GET_P_DPLTVG_LimiterTimeDuration_sec());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Constant1'/Constant' */
    SET_S_DPLTVG_MaxJerkAllowed_mps3(GET_P_DPLTVG_MaxJerkAllowed_mps3());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetParamOutputs/Constant3'/Constant' */
    SET_S_DPLTVG_TriggerReplan_bool(GET_P_DPLTVG_TriggerReplan_bool());
    /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/Switch8/Functionality'/Switch' incorporates:
                                                                          *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/Constant4'/Constant'
                                                                          *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/from_data_definition2'/state_source'
                                                                          *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/from_data_definition3'/state_source'
                                                                          *  Inport: '<Root>/S_DPLSIA_VelLatRiLDP_mps'
                                                                          *  Inport: '<Root>/S_DPLSMI_DangerousSide_nu'
                                                                          *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/RelatOperator4/Functionality'/EQ'
                                                                          *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/RelatOperator5/Functionality'/EQ'
                                                                          *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/Switch12/Functionality'/Switch'
                                                                          */
    if (((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        rtb_Switch_ah = GET_S_DPLSIA_VelLatRiLDP_mps();
    } else if (((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/Switch12/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_DPLSIA_VelLatLeLDP_mps'
                 */
        rtb_Switch_ah = GET_S_DPLSIA_VelLatLeLDP_mps();
    } else {
        rtb_Switch_ah = 0.0F;
    }
    /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/Switch8/Functionality'/Switch' */
    /* Abs: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/VelLatCalculation/Abs2/Functionality'/Abs' */
    rtb_Abs = f32_abs_f32(rtb_Switch_ah);
    /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch13/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant14'/Constant'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_DrivingMode_nu'
         *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Relational Operator8/Functionality'/EQ'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch12/Functionality'/Switch'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch8/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu'/Unit_Delay2'
         *  UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu'/Unit_Delay3'
         */
    if (((sint32)DW_dpltvg_Unit_Delay3_DSTATE) != 0) {
        rtb_Switch_ah = DW_dpltvg_Unit_Delay2_DSTATE;
    } else if (((sint32)GET_S_LCFRCV_DrivingMode_nu()) == 3) {
        /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Y_DPLTVG_TLCTrqRampInGrad_1ps2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_DPLTVG_VYMD3DeratingLevel_nu(), &dps_result_ln);
        }
        rtb_Switch_ah = rtb_ip_lookup_fxpt_sfun_7_j;
    } else if (((sint32)GET_S_LCFRCV_DrivingMode_nu()) == 2) {
        /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Y_DPLTVG_TLCTrqRampInGrad_1ps3/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_DPLTVG_VYMD2DeratingLevel_nu(), &dps_result_ln);
        }
        rtb_Switch_ah = rtb_ip_lookup_fxpt_sfun_7_b;
    } else {
        /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Y_DPLTVG_TLCTrqRampInGrad_1ps4/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D (GETA_Y_DPLTVG_VYMD1DeratingLevel_nu(), &dps_result_ln);
        }
        rtb_Switch_ah = rtb_ip_lookup_fxpt_sfun_7_a;
    }
    /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch13/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/from_data_definition'/state_source'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
         *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Logical Operator8/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/RelatOperator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/RelatOperator3/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)((((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))));
    /* RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/RelatOperator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
         */
    rtb_EQ_f = (uint8)(((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch/Functionality'/Switch' incorporates:
         *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Y_DPLTVG_TLCTrqRampInGrad_1ps1/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Y_DPLTVG_TLCTrqRampInGrad_1ps1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu'/Unit_Delay'
         *  UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu'/Unit_Delay1'
         */
    if (((sint32)DW_dpltvg_Unit_Delay1_DSTATE_i) != 0) {
        rtb_Switch_as = DW_dpltvg_Unit_Delay_DSTATE;
    } else {
        /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Y_DPLTVG_TLCTrqRampInGrad_1ps1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_j5 = F32_PTR_IP1D (GETA_Y_DPLTVG_VYStrWhStifRIGrad_1ps(), &dps_result_ln);
        }
        rtb_Switch_as = rtb_ip_lookup_fxpt_sfun_7_j5;
    }
    /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter5'/Constant'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant1'/Constant'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant2'/Constant'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant3'/Constant'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant6'/Constant'
         *  DataTypeConversion: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/DTC'/Data Type Conversion'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch14/Functionality'/Switch'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch2/Functionality'/Switch'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch3/Functionality'/Switch'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch4/Functionality'/Switch'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch6/Functionality'/Switch'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch9/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        SET_S_DPLTVG_MaxTrqScalGrad_1ps(GET_P_DPLTVG_MaxTrqScalRampInGrd_1ps());
        SET_S_DPLTVG_DeratingLevel_nu(u8_f32(rtb_Switch_ah));
        SET_S_DPLTVG_StrWhStifGrad_1ps(rtb_Switch_as);
        SET_S_DPLTVG_StrWhStifLimit_nu(GET_P_DPLTVG_StrWhStifLimit_nu());
        SET_S_DPLTVG_MaxTrqScalLimit_nu(GET_P_DPLTVG_MaxTrqScalLimit_nu());
        SET_S_DPLTVG_TrqRampGrad_1ps(GET_P_DPLTVG_TrqRampInGrad_1ps());
    } else {
        if (((sint32)rtb_EQ_f) != 0) {
            /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter8'/Constant'
                         */
            SET_S_DPLTVG_MaxTrqScalGrad_1ps(GET_P_DPLTVG_MaxTrqScalRampOutGrd_1ps());
            /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch7/Functionality'/Switch' incorporates:
                                                                                  *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter2'/Constant'
                                                                                  *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter7'/Constant'
                                                                                  *  Inport: '<Root>/S_DPLSMI_FunctionAborted_bool'
                                                                                  *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch3/Functionality'/Switch'
                                                                                  */
            if (((sint32)GET_S_DPLSMI_FunctionAborted_bool()) != 0) {
                SET_S_DPLTVG_StrWhStifGrad_1ps(GET_P_DPLTVG_StrWhStifAbortROGrd_1ps());
            } else {
                SET_S_DPLTVG_StrWhStifGrad_1ps(GET_P_DPLTVG_StrWhStifROGrad_1ps());
            }
            /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch7/Functionality'/Switch' */
        } else {
            SET_S_DPLTVG_MaxTrqScalGrad_1ps(0.0F);
            /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch3/Functionality'/Switch' incorporates:
                                                         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant'/Constant'
                                                         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant2'/Constant'
                                                         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch'
                                                         */
            SET_S_DPLTVG_StrWhStifGrad_1ps(0.0F);
        }
        SET_S_DPLTVG_DeratingLevel_nu(0U);
        SET_S_DPLTVG_StrWhStifLimit_nu(0.0F);
        SET_S_DPLTVG_MaxTrqScalLimit_nu(0.0F);
        /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch10/Functionality'/Switch' incorporates:
                                                   *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant1'/Constant'
                                                   *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant2'/Constant'
                                                   *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant3'/Constant'
                                                   *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant5'/Constant'
                                                   *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Constant6'/Constant'
                                                   *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch'
                                                   */
        if (((sint32)rtb_EQ_f) != 0) {
            /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch11/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter12'/Constant'
                         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter13'/Constant'
                         *  Inport: '<Root>/S_DPLSMI_FunctionAborted_bool'
                         */
            if (((sint32)GET_S_DPLSMI_FunctionAborted_bool()) != 0) {
                SET_S_DPLTVG_TrqRampGrad_1ps(GET_P_DPLTVG_TrqAbortROGrd_1ps());
            } else {
                SET_S_DPLTVG_TrqRampGrad_1ps(GET_P_DPLTVG_TrqRampOutGrad_1ps());
            }
            /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch11/Functionality'/Switch' */
        } else {
            SET_S_DPLTVG_TrqRampGrad_1ps(0.0F);
        }
        /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch10/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Switch1/Functionality'/Switch' */
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu/Application Parameter10'/Constant' */
    SET_S_DPLTVG_HighStatAccu_bool(GET_P_DPLTVG_HighStatAccu_bool());
    /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/Switch3/Functionality'/Switch' incorporates:
                                                                        *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/from_data_definition'/state_source'
                                                                        *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/from_data_definition1'/state_source'
                                                                        *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/from_data_definition2'/state_source'
                                                                        *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/from_data_definition3'/state_source'
                                                                        *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/from_data_definition5'/state_source'
                                                                        *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
                                                                        *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/OR/Functionality'/OR'
                                                                        *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/Relational Operator1/Functionality'/EQ'
                                                                        *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/Relational Operator2/Functionality'/EQ'
                                                                        *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/Relational Operator5/Functionality'/EQ'
                                                                        *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/Switch5/Functionality'/Switch'
                                                                        */
    if (((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) {
        SET_S_DPLTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE));
    } else if ((((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32) GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) {
        /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/from_data_definition4'/state_source'
                 */
        SET_S_DPLTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ));
    } else {
        SET_S_DPLTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
    }
    /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineTrajGuiQualifier/Switch3/Functionality'/Switch' */
    /* Abs: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_DPLTTG_TgtTrajCrv_1pm'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_DPLTTG_TgtTrajCrv_1pm());
    /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/OR1/Functionality'/OR'
         *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Mul/Functionality'/Mul'
         *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Mul1/Functionality'/Mul'
         *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Mul2/Functionality'/Mul'
         *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_D2TPlanHorizonScal_nu/Functionality/odtc'/Product'
         *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_TLCPlanningHorizon_sec/Functionality/odtc'/Product'
         *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality/odtc'/Product'
         *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu1/Functionality/odtc'/Product'
         *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Relational Operator4/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_D2TPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_TLCPlanningHorizon_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs'/Unit_Delay'
         *  UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs'/Unit_Delay1'
         */
    if ((((sint32)GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) GET_S_DPLSMI_SysStateLDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)))) {
        rtb_Switch_ko = DW_dpltvg_Unit_Delay_DSTATE_o;
        rtb_Switch_fj = DW_dpltvg_Unit_Delay1_DSTATE;
    } else {
        /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_DPLTVG_VXWeightEndtime_nu(), &dps_result_ln);
        }
        rtb_Switch_ko = rtb_ip_lookup_fxpt_sfun_7_m;
        /* RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/RelatOperator4/Functionality'/EQ' incorporates:
                 *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/from_data_definition8'/state_source'
                 *  Inport: '<Root>/S_DPLSMI_DangerousSide_nu'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality/odtc'/Product'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_EQ_f = (uint8)(((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT)));
        /* RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/RelatOperator5/Functionality'/EQ' incorporates:
                 *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/from_data_definition7'/state_source'
                 *  Inport: '<Root>/S_DPLSMI_DangerousSide_nu'
                 */
        rtb_EQ_br = (uint8)(((sint32)GET_S_DPLSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT)));
        /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_TLCPlanningHorizon_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D (GETA_Y_DPLTVG_VYPlanningHorizon_sec(), &dps_result_ln);
        }
        /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/from_data_definition4'/state_source'
                 *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/from_data_definition5'/state_source'
                 *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/from_data_definition6'/state_source'
                 *  Inport: '<Root>/S_DPLSIA_CurveTypeLe_enum'
                 *  Inport: '<Root>/S_DPLSIA_CurveTypeRi_enum'
                 *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/AND/Functionality'/AND'
                 *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/AND1/Functionality'/AND'
                 *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/AND2/Functionality'/AND'
                 *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/AND3/Functionality'/AND'
                 *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/OR/Functionality'/OR'
                 *  Logic: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/OR2/Functionality'/OR'
                 *  Product: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_CrvPlanHorizonScal_nu/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/EQ/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/EQ1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/EQ2/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/EQ3/Functionality'/EQ'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_CrvPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_TLCPlanningHorizon_sec/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Switch3/Functionality'/Switch'
                 */
        if (((((sint32)rtb_EQ_br) != 0) && (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8)E_LCF_CurveType_E_LCF_CURVE_INNER)))) || ((((sint32)rtb_EQ_f) != 0) && (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8)E_LCF_CurveType_E_LCF_CURVE_INNER))))) {
            /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_CrvPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_o, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_DPLTVG_CrvICPlanHorizonScal_nu(), &dps_result_ln);
            }
            rtb_Switch_fj = rtb_ip_lookup_fxpt_sfun_7_c;
        } else if (((((sint32)rtb_EQ_br) != 0) && (((sint32) GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER)))) || ((((sint32)rtb_EQ_f) != 0) && (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))))) {
            /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_CrvPlanHorizonScal_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_o, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D (GETA_Y_DPLTVG_CrvOCPlanHorizonScal_nu(), &dps_result_ln);
            }
            rtb_Switch_fj = rtb_ip_lookup_fxpt_sfun_7_f;
        } else {
            /* Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Switch3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Constant1'/Constant'
                         */
            rtb_Switch_fj = 1.0F;
        }
        /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Switch2/Functionality'/Switch' */
        /* Abs: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Abs/Functionality'/Abs' incorporates:
                 *  Inport: '<Root>/S_DPLTTG_TgtTrajPosY0_met'
                 */
        rtb_Abs_g = f32_abs_f32(GET_S_DPLTTG_TgtTrajPosY0_met());
        /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_D2TPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_DistY_met */
            FDPS_PTR_F32(GETA_X_LCF_DistY_met(), rtb_Abs_g, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D (GETA_Y_DPLTVG_D2TPlanHorizonScal_nu(), &dps_result_ln);
        }
        /* S-Function Block sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Y_DPLTVG_VXWeightEndtime_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D (GETA_Y_DPLTVG_VXPlanHorizonScal_nu(), &dps_result_ln);
        }
        rtb_Switch_fj = ((rtb_ip_lookup_fxpt_sfun_7_n * rtb_ip_lookup_fxpt_sfun_7_e) * rtb_Switch_fj) * rtb_ip_lookup_fxpt_sfun_7;
    }
    /* End of Switch: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/branch'/copy1' */
    SET_S_DPLTVG_PlanningHorizon_sec(rtb_Switch_fj);
    /* SignalConversion: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs/branch1'/copy1' */
    SET_S_DPLTVG_WeightEndTime_nu(rtb_Switch_ko);
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/CrvLimitation/Application Parameter6'/Constant' */
    SET_S_DPLTVG_MaxCrvTrajGuiCtrl_1pm(GET_P_DPLTVG_LimiterMaxCrv_1pm());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/CrvLimitation/Application Parameter2'/Constant' */
    SET_S_DPLTVG_MaxCrvGrdBuildup_1pms(GET_P_DPLTVG_LimiterMaxCrvGrd_1pms());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/CrvLimitation/Application Parameter1'/Constant' */
    SET_S_DPLTVG_MaxCrvGrdRed_1pms(GET_P_DPLTVG_LimiterMaxCrvGrd_1pms());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/CrvLimitation/Application Parameter3'/Constant' */
    SET_S_DPLTVG_GrdLimitTgtCrvTGC_1pms(GET_P_DPLTVG_LimiterMaxCrvGrd_1pms());
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetConstOutputs/Constant87'/Constant' */
    SET_S_DPLTVG_ObstacleVelX_mps(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetConstOutputs/Constant88'/Constant' */
    SET_S_DPLTVG_ObstacleAclX_mps2(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetConstOutputs/Constant85'/Constant' */
    SET_S_DPLTVG_ObstacleWidth_met(0.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetConstOutputs/Constant86'/Constant' */
    SET_S_DPLTVG_ObstacleDistX_met(100.0F);
    /* Constant: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetConstOutputs/Constant84'/Constant' */
    SET_S_DPLTVG_ObstacleDistY_met(100.0F);
    /* SignalConversion: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/branch1'/copy1' incorporates:
                                              *  Inport: '<Root>/S_ABPLBP_ABDTimeStamp_sec'
                                              */
    SET_S_DPLTVG_SensorTStamp_sec(GET_S_ABPLBP_ABDTimeStamp_sec());
    /* Update for UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu'/Unit_Delay2' */
    DW_dpltvg_Unit_Delay2_DSTATE = rtb_Switch_ah;
    /* Update for UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu'/Unit_Delay3' */
    DW_dpltvg_Unit_Delay3_DSTATE = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu'/Unit_Delay' */
    DW_dpltvg_Unit_Delay_DSTATE = rtb_Switch_as;
    /* Update for UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/DetermineStiffnessAndStatAccu'/Unit_Delay1' */
    DW_dpltvg_Unit_Delay1_DSTATE_i = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs'/Unit_Delay' */
    DW_dpltvg_Unit_Delay_DSTATE_o = rtb_Switch_ko;
    /* Update for UnitDelay: 'sda:DPLTVG/DPLTVG/DPLTVG_SenProcess/OPM/M_DPLTVG/SetLookupOutputs'/Unit_Delay1' */
    DW_dpltvg_Unit_Delay1_DSTATE = rtb_Switch_fj;
}
#include "Pse_DPLTVG.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
