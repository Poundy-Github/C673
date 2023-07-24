/**************************************************************************
COPYRIGHT (C) $Date: 2019/12/11 09:17:05CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/ALCASA/LCRTVG_SEN/LCRTVG/i/project.pj $
$Log: LCRTVG.c  $
Revision 1.11 2019/12/11 09:17:05CET Mariut, Felix (uidp0906) 
automatically created
File          : LCRTVG
Generated on  : Wed 11.12.2019 at 10:02:10 (UTC+01:00)
MD5           : [2656492164  3867299488  4183234503   385937598 0](LCRTVG)
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
#include "LCRTVG.h"
#include "LCRTVG_private.h"
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
#define LCRTVG_START_SEC_DATA_8
#include "LCRTVG_MemMap.h"
static uint8 DW_lcrtvg_Unit_Delay3_DSTATE;
static uint8 DW_lcrtvg_Unit_Delay1_DSTATE_p;
#define LCRTVG_STOP_SEC_DATA_8
#include "LCRTVG_MemMap.h"
#define LCRTVG_START_SEC_DATA_32
#include "LCRTVG_MemMap.h"
static float32 DW_lcrtvg_Unit_Delay2_DSTATE;
static float32 DW_lcrtvg_Unit_Delay_DSTATE;
static float32 DW_lcrtvg_Unit_Delay_DSTATE_j;
static float32 DW_lcrtvg_Unit_Delay1_DSTATE;
#define LCRTVG_STOP_SEC_DATA_32
#include "LCRTVG_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:LCRTVG/LCRTVG'/LCRTVG_SenReset'
 * Block description for: 'sda:LCRTVG/LCRTVG'/LCRTVG_SenReset'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_LCRTVG_SenReset
#include "Pse_LCRTVG.h"
/* Short description:  */
void LCRTVG_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant'/Constant' */
    SET_S_LCRTVG_TrajPlanServQu_nu(0U);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant1'/Constant' */
    SET_S_LCRTVG_DistYTolLeTgtArea_met(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant10'/Constant' */
    SET_S_LCRTVG_PredTimeHeadAng_sec(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant11'/Constant' */
    SET_S_LCRTVG_TriggerReplan_bool(0U);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant12'/Constant' */
    SET_S_LCRTVG_MaxCrvTrajGuiCtrl_1pm(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant13'/Constant' */
    SET_S_LCRTVG_MaxCrvGrdBuildup_1pms(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant14'/Constant' */
    SET_S_LCRTVG_MaxCrvGrdRed_1pms(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant15'/Constant' */
    SET_S_LCRTVG_GrdLimitTgtCrvTGC_1pms(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant16'/Constant' */
    SET_S_LCRTVG_PlanningHorizon_sec(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant17'/Constant' */
    SET_S_LCRTVG_TrajGuiQu_nu(0U);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant18'/Constant' */
    SET_S_LCRTVG_ObstacleVelX_mps(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant19'/Constant' */
    SET_S_LCRTVG_ObstacleAclX_mps2(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant2'/Constant' */
    SET_S_LCRTVG_DistYTolRiTgtArea_met(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant20'/Constant' */
    SET_S_LCRTVG_ObstacleWidth_met(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant21'/Constant' */
    SET_S_LCRTVG_ObstacleDistX_met(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant22'/Constant' */
    SET_S_LCRTVG_ObstacleDistY_met(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant23'/Constant' */
    SET_S_LCRTVG_LtcyCompActivated_bool(0U);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant25'/Constant' */
    SET_S_LCRTVG_LimiterActivated_bool(0U);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant26'/Constant' */
    SET_S_LCRTVG_DeratingLevel_nu(0U);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant27'/Constant' */
    SET_S_LCRTVG_LimiterTimeDuration_sec(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant28'/Constant' */
    SET_S_LCRTVG_StrWhStifLimit_nu(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant29'/Constant' */
    SET_S_LCRTVG_StrWhStifGrad_1ps(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant3'/Constant' */
    SET_S_LCRTVG_FTireAclMax_mps2(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant30'/Constant' */
    SET_S_LCRTVG_TrqRampGrad_1ps(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant31'/Constant' */
    SET_S_LCRTVG_MaxTrqScalLimit_nu(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant32'/Constant' */
    SET_S_LCRTVG_MaxTrqScalGrad_1ps(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant33'/Constant' */
    SET_S_LCRTVG_HighStatAccu_bool(0U);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant34'/Constant' */
    SET_S_LCRTVG_MaxJerkAllowed_mps3(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant4'/Constant' */
    SET_S_LCRTVG_FTireAclMin_mps2(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant5'/Constant' */
    SET_S_LCRTVG_WeightTgtDistY_nu(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant6'/Constant' */
    SET_S_LCRTVG_WeightEndTime_nu(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant7'/Constant' */
    SET_S_LCRTVG_SensorTStamp_sec(0.0F);
    /* Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenReset/Subsystem/Constant9'/Constant' */
    SET_S_LCRTVG_PredTimeCrv_sec(0.0F);
}
#include "Pse_LCRTVG.h"
/*
 * Output and update for function-call system: 'sda:LCRTVG/LCRTVG'/LCRTVG_SenProcess'
 * Block description for: 'sda:LCRTVG/LCRTVG'/LCRTVG_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_LCRTVG_SenProcess
#include "Pse_LCRTVG.h"
/* Short description:  */
void LCRTVG_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Abs;
    float32 rtb_Abs_p;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_Abs_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_gn;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_ft;
    float32 rtb_Switch_e2;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_EQ_p;
    uint8 rtb_Switch_n;
    float32 rtb_Switch_o;
    float32 rtb_Switch_o2;
    float32 rtb_Switch_gl;
    float32 rtb_Switch_ay;
    uint8 rtb_EQ_cf;
    float32 rtb_Switch_gz;
    float32 rtb_Switch_b;
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch'/copy1' incorporates:
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant'/Constant'
         */
    SET_S_LCRTVG_FTireAclMax_mps2(GET_P_LCRTVG_FTireAclMax_mps2());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch1'/copy1' incorporates:
                                                                      *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant1'/Constant'
                                                                      */
    SET_S_LCRTVG_FTireAclMin_mps2(GET_P_LCRTVG_FTireAclMin_mps2());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch10'/copy1' incorporates:
                                                                      *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant14'/Constant'
                                                                      */
    SET_S_LCRTVG_LtcyCompActivated_bool(GET_P_LCRTVG_UseLtcyComp_nu());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch11'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant15'/Constant'
                                                                          */
    SET_S_LCRTVG_LimiterActivated_bool(GET_P_LCRTVG_LimiterActivated_bool());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch13'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant17'/Constant'
                                                                          */
    SET_S_LCRTVG_LimiterTimeDuration_sec(GET_P_LCRTVG_LimiterTimeDuration_sec());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch2'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant3'/Constant'
                                                                          */
    SET_S_LCRTVG_DistYTolLeTgtArea_met(GET_P_LCRTVG_DistYTolLeTgtArea_met());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch3'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant7'/Constant'
                                                                          */
    SET_S_LCRTVG_DistYTolRiTgtArea_met(GET_P_LCRTVG_DistYTolRiTgtArea_met());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch34'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant2'/Constant'
                                                                          */
    SET_S_LCRTVG_MaxJerkAllowed_mps3(GET_P_LCRTVG_MaxJerkAllowed_mps3());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch4'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant8'/Constant'
                                                                          */
    SET_S_LCRTVG_WeightTgtDistY_nu(GET_P_LCRTVG_WeightTgtDistY_nu());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch5'/copy1' incorporates:
                                                                        *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant9'/Constant'
                                                                        */
    SET_S_LCRTVG_TrajPlanServQu_nu(GET_P_LCRTVG_TrajPlanServQu_nu());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch8'/copy1' incorporates:
                                                                        *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant12'/Constant'
                                                                        */
    SET_S_LCRTVG_PredTimeCrv_sec(GET_P_LCRTVG_PredTimeCrv_sec());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch9'/copy1' incorporates:
                                                                    *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetParamOutputs/Constant13'/Constant'
                                                                    */
    SET_S_LCRTVG_PredTimeHeadAng_sec(GET_P_LCRTVG_PredTimeHeadAng_sec());
    /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/Switch3/Functionality'/Switch' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/from_data_definition'/state_source'
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/from_data_definition1'/state_source'
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/from_data_definition5'/state_source'
                                                                          *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
                                                                          *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/OR/Functionality'/OR'
                                                                          *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/Relational Operator1/Functionality'/EQ'
                                                                          *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/Relational Operator2/Functionality'/EQ'
                                                                          *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/Relational Operator5/Functionality'/EQ'
                                                                          *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/Switch5/Functionality'/Switch'
                                                                          */
    if (((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) {
        /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch25'/copy1' incorporates:
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/from_data_definition8'/state_source'
                 */
        SET_S_LCRTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE));
    } else if ((((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32) GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) {
        /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/from_data_definition7'/state_source'
                 *  SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch25'/copy1'
                 */
        SET_S_LCRTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ));
    } else {
        /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch25'/copy1' incorporates:
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/from_data_definition3'/state_source'
                 *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/Switch5/Functionality'/Switch'
                 */
        SET_S_LCRTVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
    }
    /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetTrajGuiQualifier/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/Constant4'/Constant'
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/from_data_definition2'/state_source'
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_LCRSIA_VelLatRiALCA_mps'
         *  Inport: '<Root>/S_LCRSMI_DangerousSide_nu'
         *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/RelatOperator5/Functionality'/EQ'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/Switch12/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        rtb_Switch_gz = GET_S_LCRSIA_VelLatRiALCA_mps();
    } else if (((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/Switch12/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_LCRSIA_VelLatLeALCA_mps'
                 */
        rtb_Switch_gz = GET_S_LCRSIA_VelLatLeALCA_mps();
    } else {
        rtb_Switch_gz = 0.0F;
    }
    /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/Switch8/Functionality'/Switch' */
    /* Abs: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/LatVelSelection/Abs/Functionality'/Abs' */
    rtb_Abs = f32_abs_f32(rtb_Switch_gz);
    /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch13/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant4'/Constant'
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant7'/Constant'
         *  Inport: '<Root>/S_LCFRCV_DrivingMode_nu'
         *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/EQ1/Functionality'/EQ'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch12/Functionality'/Switch'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch8/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu'/Unit_Delay2'
         *  UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu'/Unit_Delay3'
         */
    if (((sint32)DW_lcrtvg_Unit_Delay3_DSTATE) != 0) {
        rtb_Switch_gz = DW_lcrtvg_Unit_Delay2_DSTATE;
    } else if (((sint32)GET_S_LCFRCV_DrivingMode_nu()) == 3) {
        /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Y_LCRTVG_VYMD3DerLevel_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D(GETA_Y_LCRTVG_VYMD3DerLevel_nu(), &x_dps);
        }
        rtb_Switch_gz = rtb_ip_lookup_fxpt_sfun_7_m;
    } else if (((sint32)GET_S_LCFRCV_DrivingMode_nu()) == 2) {
        /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Y_LCRTVG_VYMD2DerLevel_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_gn = F32_PTR_IP1D(GETA_Y_LCRTVG_VYMD2DerLevel_nu (), &x_dps);
        }
        rtb_Switch_gz = rtb_ip_lookup_fxpt_sfun_7_gn;
    } else {
        /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Y_LCRTVG_VYMD1DerLevel_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D(GETA_Y_LCRTVG_VYMD1DerLevel_nu(), &x_dps);
        }
        rtb_Switch_gz = rtb_ip_lookup_fxpt_sfun_7_f;
    }
    /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch13/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/from_data_definition'/state_source'
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Logical Operator8/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/RelatOperator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/RelatOperator3/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)((((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))));
    /* RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/RelatOperator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         */
    rtb_EQ_p = (uint8)(((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch/Functionality'/Switch' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Y_LCRTVG_VYStrWhStifRIGrad_1ps/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu'/Unit_Delay'
         *  UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu'/Unit_Delay1'
         */
    if (((sint32)DW_lcrtvg_Unit_Delay1_DSTATE_p) != 0) {
        rtb_Switch_o2 = DW_lcrtvg_Unit_Delay_DSTATE;
    } else {
        /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Y_LCRTVG_VYStrWhStifRIGrad_1ps/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ft = F32_PTR_IP1D (GETA_Y_LCRTVG_VYStrWhStifRIGrad_1ps(), &x_dps);
        }
        rtb_Switch_o2 = rtb_ip_lookup_fxpt_sfun_7_ft;
    }
    /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch/Functionality'/Switch' */
    /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter3'/Constant'
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter5'/Constant'
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant2'/Constant'
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant6'/Constant'
         *  DataTypeConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/DTC'/Data Type Conversion'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch10/Functionality'/Switch'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch14/Functionality'/Switch'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch2/Functionality'/Switch'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch3/Functionality'/Switch'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch9/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_e2 = GET_P_LCRTVG_MaxTrqScalRampInGrd_1ps();
        rtb_Switch_n = u8_f32(rtb_Switch_gz);
        rtb_Switch_gl = rtb_Switch_o2;
        rtb_Switch_ay = GET_P_LCRTVG_TrqRampInGrad_1ps();
    } else {
        if (((sint32)rtb_EQ_p) != 0) {
            /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter8'/Constant'
                         */
            rtb_Switch_e2 = GET_P_LCRTVG_MaxTrqScalRampOutGrd_1ps();
            /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter12'/Constant'
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter13'/Constant'
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter2'/Constant'
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter7'/Constant'
                         *  Inport: '<Root>/S_LCRSMI_FunctionAborted_bool'
                         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch10/Functionality'/Switch'
                         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch11/Functionality'/Switch'
                         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch3/Functionality'/Switch'
                         */
            if (((sint32)GET_S_LCRSMI_FunctionAborted_bool()) != 0) {
                rtb_Switch_gl = GET_P_LCRTVG_StrWhStifAbortROGrd_1ps();
                rtb_Switch_ay = GET_P_LCRTVG_TrqAbortROGrd_1ps();
            } else {
                rtb_Switch_gl = GET_P_LCRTVG_StrWhStifRampOutGrd_1ps();
                rtb_Switch_ay = GET_P_LCRTVG_TrqRampOutGrad_1ps();
            }
            /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch7/Functionality'/Switch' */
        } else {
            rtb_Switch_e2 = 0.0F;
            /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant'/Constant'
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant2'/Constant'
                         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch5/Functionality'/Switch'
                         */
            rtb_Switch_gl = 0.0F;
            /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant5'/Constant'
                         */
            rtb_Switch_ay = 0.0F;
        }
        rtb_Switch_n = 0U;
    }
    /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch1/Functionality'/Switch' */
    /* Abs: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCRTTG_TgtTrajCrv_1pm'
         */
    rtb_Abs_p = f32_abs_f32(GET_S_LCRTTG_TgtTrajCrv_1pm());
    /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/from_data_definition2'/state_source'
         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/OR1/Functionality'/OR'
         *  Product: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Mul/Functionality'/Mul'
         *  Product: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Mul1/Functionality'/Mul'
         *  Product: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Mul2/Functionality'/Mul'
         *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Relational Operator4/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_D2TPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_VXPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_VYPlanningHorizon_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs'/Unit_Delay'
         *  UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs'/Unit_Delay1'
         */
    if ((((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)))) {
        rtb_Switch_o = DW_lcrtvg_Unit_Delay_DSTATE_j;
        rtb_Switch_b = DW_lcrtvg_Unit_Delay1_DSTATE;
    } else {
        /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_LCRTVG_VXWeightEndtime_nu(), &x_dps);
        }
        rtb_Switch_o = rtb_ip_lookup_fxpt_sfun_7_b;
        /* RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/EQ/Functionality'/EQ' incorporates:
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/from_data_definition'/state_source'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Inport: '<Root>/S_LCRSMI_DangerousSide_nu'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_VXWeightEndtime_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_EQ_p = (uint8)(((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT)));
        /* RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/EQ1/Functionality'/EQ' incorporates:
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/from_data_definition1'/state_source'
                 *  Inport: '<Root>/S_LCRSMI_DangerousSide_nu'
                 */
        rtb_EQ_cf = (uint8)(((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT)));
        /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_VYPlanningHorizon_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D (GETA_Y_LCRTVG_VYPlanningHorizon_sec(), &x_dps);
        }
        /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/from_data_definition4'/state_source'
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/from_data_definition5'/state_source'
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/from_data_definition6'/state_source'
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/from_data_definition7'/state_source'
                 *  Inport: '<Root>/S_LCRSIA_CurveTypeLe_enum'
                 *  Inport: '<Root>/S_LCRSIA_CurveTypeRi_enum'
                 *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/AND/Functionality'/AND'
                 *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/AND1/Functionality'/AND'
                 *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/AND2/Functionality'/AND'
                 *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/AND3/Functionality'/AND'
                 *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/OR/Functionality'/OR'
                 *  Logic: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/OR2/Functionality'/OR'
                 *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/EQ2/Functionality'/EQ'
                 *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/EQ3/Functionality'/EQ'
                 *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/EQ4/Functionality'/EQ'
                 *  RelationalOperator: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/EQ5/Functionality'/EQ'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_CrvICPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Switch3/Functionality'/Switch'
                 */
        if (((((sint32)rtb_EQ_p) != 0) && (((sint32)GET_S_LCRSIA_CurveTypeLe_enum()) == ((sint32)((uint8)E_LCF_CurveType_E_LCF_CURVE_INNER)))) || ((((sint32)rtb_EQ_cf) != 0) && (((sint32)GET_S_LCRSIA_CurveTypeRi_enum()) == ((sint32)((uint8)E_LCF_CurveType_E_LCF_CURVE_INNER))))) {
            /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_CrvICPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_p, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_LCRTVG_CrvICPlanHorizonScal_nu(), &x_dps);
            }
            rtb_Switch_b = rtb_ip_lookup_fxpt_sfun_7_g;
        } else if (((((sint32)rtb_EQ_p) != 0) && (((sint32) GET_S_LCRSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER)))) || ((((sint32)rtb_EQ_cf) != 0) && (((sint32)GET_S_LCRSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))))) {
            /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_CrvOCPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_p, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_LCRTVG_CrvOCPlanHorizonScal_nu(), &x_dps);
            }
            rtb_Switch_b = rtb_ip_lookup_fxpt_sfun_7_l;
        } else {
            /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Switch3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Constant'/Constant'
                         */
            rtb_Switch_b = 1.0F;
        }
        /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Switch2/Functionality'/Switch' */
        /* Abs: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Abs/Functionality'/Abs' incorporates:
                 *  Inport: '<Root>/S_LCRTTG_TgtTrajPosY0_met'
                 */
        rtb_Abs_b = f32_abs_f32(GET_S_LCRTTG_TgtTrajPosY0_met());
        /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_D2TPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_DistY_met */
            FDPS_PTR_F32(GETA_X_LCF_DistY_met(), rtb_Abs_b, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D (GETA_Y_LCRTVG_D2TPlanHorizonScal_nu(), &x_dps);
        }
        /* S-Function Block sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Y_LCRTVG_VXPlanHorizonScal_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D (GETA_Y_LCRTVG_VXPlanHorizonScal_nu(), &x_dps);
        }
        rtb_Switch_b = ((rtb_ip_lookup_fxpt_sfun_7_k * rtb_ip_lookup_fxpt_sfun_7_e) * rtb_Switch_b) * rtb_ip_lookup_fxpt_sfun_7;
    }
    /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch12'/copy1' */
    SET_S_LCRTVG_DeratingLevel_nu(rtb_Switch_n);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch26'/copy1' */
    SET_S_LCRTVG_WeightEndTime_nu(rtb_Switch_o);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch27'/copy1' */
    SET_S_LCRTVG_PlanningHorizon_sec(rtb_Switch_b);
    /* Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch4/Functionality'/Switch' incorporates:
                                                      *  Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch6/Functionality'/Switch'
                                                      */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch28'/copy1' incorporates:
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter4'/Constant'
                 */
        SET_S_LCRTVG_StrWhStifLimit_nu(GET_P_LCRTVG_StrWhStifLimit_nu());
        /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch31'/copy1' incorporates:
                                                                              *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter1'/Constant'
                                                                              */
        SET_S_LCRTVG_MaxTrqScalLimit_nu(GET_P_LCRTVG_MaxTrqScalLimit_nu());
    } else {
        /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch28'/copy1' incorporates:
                 *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant1'/Constant'
                 */
        SET_S_LCRTVG_StrWhStifLimit_nu(0.0F);
        /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch31'/copy1' incorporates:
                                                  *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Constant3'/Constant'
                                                  */
        SET_S_LCRTVG_MaxTrqScalLimit_nu(0.0F);
    }
    /* End of Switch: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Switch4/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch29'/copy1' */
    SET_S_LCRTVG_StrWhStifGrad_1ps(rtb_Switch_gl);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch30'/copy1' */
    SET_S_LCRTVG_TrqRampGrad_1ps(rtb_Switch_ay);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch32'/copy1' */
    SET_S_LCRTVG_MaxTrqScalGrad_1ps(rtb_Switch_e2);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch33'/copy1' incorporates:
                                                      *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu/Application Parameter10'/Constant'
                                                      */
    SET_S_LCRTVG_HighStatAccu_bool(GET_P_LCRTVG_HighStatAccu_bool());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch14'/copy1' incorporates:
                                                                        *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetConstOutputs/Constant'/Constant'
                                                                        */
    SET_S_LCRTVG_ObstacleVelX_mps(0.0F);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch15'/copy1' incorporates:
                                            *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetConstOutputs/Constant2'/Constant'
                                            */
    SET_S_LCRTVG_ObstacleAclX_mps2(0.0F);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch16'/copy1' incorporates:
                                            *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetConstOutputs/Constant3'/Constant'
                                            */
    SET_S_LCRTVG_ObstacleWidth_met(0.0F);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch17'/copy1' incorporates:
                                            *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetConstOutputs/Constant5'/Constant'
                                            */
    SET_S_LCRTVG_ObstacleDistX_met(100.0F);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch18'/copy1' incorporates:
                                              *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetConstOutputs/Constant6'/Constant'
                                              */
    SET_S_LCRTVG_ObstacleDistY_met(100.0F);
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch20'/copy1' incorporates:
                                              *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetConstOutputs/Constant1'/Constant'
                                              */
    SET_S_LCRTVG_TriggerReplan_bool(GET_P_LCRTVG_TriggerReplan_bool());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch21'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/CrvLimitation/Application Parameter6'/Constant'
                                                                          */
    SET_S_LCRTVG_MaxCrvTrajGuiCtrl_1pm(GET_P_LCRTVG_LimiterMaxCrv_1pm());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch22'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/CrvLimitation/Application Parameter2'/Constant'
                                                                          */
    SET_S_LCRTVG_MaxCrvGrdBuildup_1pms(GET_P_LCRTVG_LimiterMaxCrvGrd_1pms());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch23'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/CrvLimitation/Application Parameter3'/Constant'
                                                                          */
    SET_S_LCRTVG_MaxCrvGrdRed_1pms(GET_P_LCRTVG_LimiterMaxCrvGrd_1pms());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch24'/copy1' incorporates:
                                                                          *  Constant: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/CrvLimitation/Application Parameter4'/Constant'
                                                                          */
    SET_S_LCRTVG_GrdLimitTgtCrvTGC_1pms(GET_P_LCRTVG_LimiterMaxCrvGrd_1pms());
    /* SignalConversion: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/branch6'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_ABPLBP_ABDTimeStamp_sec'
                                                                          */
    SET_S_LCRTVG_SensorTStamp_sec(GET_S_ABPLBP_ABDTimeStamp_sec());
    /* Update for UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu'/Unit_Delay2' */
    DW_lcrtvg_Unit_Delay2_DSTATE = rtb_Switch_gz;
    /* Update for UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu'/Unit_Delay3' */
    DW_lcrtvg_Unit_Delay3_DSTATE = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu'/Unit_Delay' */
    DW_lcrtvg_Unit_Delay_DSTATE = rtb_Switch_o2;
    /* Update for UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/DetermineStiffnessAndStatAccu'/Unit_Delay1' */
    DW_lcrtvg_Unit_Delay1_DSTATE_p = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs'/Unit_Delay' */
    DW_lcrtvg_Unit_Delay_DSTATE_j = rtb_Switch_o;
    /* Update for UnitDelay: 'sda:LCRTVG/LCRTVG/LCRTVG_SenProcess/OPM1/Main/SetLookupOutputs'/Unit_Delay1' */
    DW_lcrtvg_Unit_Delay1_DSTATE = rtb_Switch_b;
}
#include "Pse_LCRTVG.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
