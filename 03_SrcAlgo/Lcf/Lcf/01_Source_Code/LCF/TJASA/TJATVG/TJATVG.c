/**************************************************************************
COPYRIGHT (C) $Date: 2019/08/29 10:04:40CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJATVG_SEN/TJATVG/i/project.pj $
$Log: TJATVG.c  $
Revision 1.5 2019/08/29 10:04:40CEST Werum, Gregor (uidq2175) 
Module test update according to findings (FCT_CMP_TJASA_1577, FCT_CMP_TJASA_2145)
Revision 1.32.1.2 2019/06/14 15:00:39CEST Fen, Alexander (TFPE05) 
ZDV protection added
File          : TJATVG
Generated on  : Fri 14.06.2019 at 14:57:16 (UTC+01:00)
MD5           : [3572222990   884349471  3886424488  1568402311 0](TJATVG)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-Core: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,79
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TJATVG.h"
#include "TJATVG_private.h"
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
#define TJATVG_START_SEC_DATA_8
#include "TJATVG_MemMap.h"
static uint8 DW_tjatvg_Unit_Delay2_DSTATE;
static uint8 DW_tjatvg_Unit_Delay_DSTATE;
static uint8 DW_tjatvg_Unit_Delay_DSTATE_h;
#define TJATVG_STOP_SEC_DATA_8
#include "TJATVG_MemMap.h"
#define TJATVG_START_SEC_DATA_32
#include "TJATVG_MemMap.h"
static float32 DW_tjatvg_Unit_Delay1_DSTATE;
#define TJATVG_STOP_SEC_DATA_32
#include "TJATVG_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TJATVG/TJATVG/INI'/TJATVG_SenReset'
 * Block description for: 'sda:TJATVG/TJATVG/INI'/TJATVG_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TJATVG_SenReset
#include "Pse_TJATVG.h"
/* Short description: Not synchronized with ARAMIS */
void TJATVG_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/Constant'/Constant' */
    SET_S_TJATVG_StrWhStifLimit_nu(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/Constant1'/Constant' */
    SET_S_TJATVG_MaxTrqScalLimit_nu(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/Constant2'/Constant' */
    SET_S_TJATVG_StrWhStifGrad_1ps(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/Constant3'/Constant' */
    SET_S_TJATVG_MaxTrqScalGrad_1ps(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/Constant4'/Constant' */
    SET_S_TJATVG_MaxJerkAllowed_mps3(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/Constant5'/Constant' */
    SET_S_TJATVG_SensorTStamp_sec(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/Constant6'/Constant' */
    SET_S_TJATVG_DeratingLevel_nu(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value1'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value1'/Constant'
                                            */
    SET_S_TJATVG_LimiterTimeDuration_sec(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value10'/Signal Conversion' incorporates:
                                                  *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value10'/Constant'
                                                  */
    SET_S_TJATVG_ObstacleVelX_mps(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value11'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value11'/Constant'
                                            */
    SET_S_TJATVG_HighStatAccu_bool(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value12'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value12'/Constant'
                                            */
    SET_S_TJATVG_TrqRampGrad_1ps(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value13'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value13'/Constant'
                                            */
    SET_S_TJATVG_TrajGuiQu_nu(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value14'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value14'/Constant'
                                            */
    SET_S_TJATVG_PlanningHorizon_sec(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value15'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value15'/Constant'
                                              */
    SET_S_TJATVG_GrdLimitTgtCrvTGC_1pms(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value16'/Signal Conversion' incorporates:
                                                 *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value16'/Constant'
                                                 */
    SET_S_TJATVG_MaxCrvGrdRed_1pms(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value17'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value17'/Constant'
                                            */
    SET_S_TJATVG_MaxCrvGrdBuildup_1pms(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value18'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value18'/Constant'
                                                */
    SET_S_TJATVG_WeightTgtDistY_nu(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value19'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value19'/Constant'
                                            */
    SET_S_TJATVG_FTireAclMin_mps2(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value2'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value2'/Constant'
                                            */
    SET_S_TJATVG_LimiterType_nu(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value20'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value20'/Constant'
                                            */
    SET_S_TJATVG_FTireAclMax_mps2(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value21'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value21'/Constant'
                                            */
    SET_S_TJATVG_DistYTolRiTgtArea_met(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value22'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value22'/Constant'
                                                */
    SET_S_TJATVG_DistYTolLeTgtArea_met(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value23'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value23'/Constant'
                                                */
    SET_S_TJATVG_TrajPlanServQu_nu(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value24'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value24'/Constant'
                                            */
    SET_S_TJATVG_MaxCrvTrajGuiCtrl_1pm(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value25'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value25'/Constant'
                                                */
    SET_S_TJATVG_TriggerReplan_nu(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value26'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value26'/Constant'
                                            */
    SET_S_TJATVG_PredTimeHeadAng_sec(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value27'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value27'/Constant'
                                              */
    SET_S_TJATVG_PredTimeCrv_sec(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value3'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value3'/Constant'
                                            */
    SET_S_TJATVG_LimiterActivated_nu(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value31'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value31'/Constant'
                                            */
    SET_S_TJATVG_WeightEndTime_nu(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value4'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value4'/Constant'
                                            */
    SET_S_TJATVG_CrvAmplActivated_nu(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value5'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value5'/Constant'
                                            */
    SET_S_TJATVG_LtcyCompActivated_nu(0U);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value6'/Signal Conversion' incorporates:
                                             *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value6'/Constant'
                                             */
    SET_S_TJATVG_ObstacleDistY_met(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value7'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value7'/Constant'
                                            */
    SET_S_TJATVG_ObstacleDistX_met(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value8'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value8'/Constant'
                                            */
    SET_S_TJATVG_ObstacleWidth_met(0.0F);
    /* SignalConversion: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value9'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:TJATVG/TJATVG/INI/TJATVG_SenReset/constant_value9'/Constant'
                                            */
    SET_S_TJATVG_ObstacleAclX_mps2(0.0F);
}
#include "Pse_TJATVG.h"
/*
 * Output and update for function-call system: 'sda:TJATVG/TJATVG'/TJATVG_SenProcess'
 * Block description for: 'sda:TJATVG/TJATVG'/TJATVG_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TJATVG_SenProcess
#include "Pse_TJATVG.h"
/* Short description: Not synchronized with ARAMIS */
void TJATVG_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_Abs_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_gj;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_Switch_hw;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_EQ_e;
    float32 rtb_Div;
    uint8 rtb_DataTypeConversion_dm;
    uint8 rtb_DataTypeConversion_b;
    uint8 rtb_Switch_ai;
    uint8 rtb_Switch_jz;
    /* DataTypeConversion: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/VDY_Bugfix_Issue_969832/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/VDY_Bugfix_Issue_969832/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehStopped_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/VDY_Bugfix_Issue_969832/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/VDY_Bugfix_Issue_969832/LT/Functionality'/LT'
         */
    rtb_DataTypeConversion = (uint8)((((sint32)GET_S_LCFRCV_VehStopped_nu()) != 0) && (GET_S_LCFRCV_VehVelX_mps() < 5.0F));
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/from_data_definition12'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/from_data_definition13'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/AND1/Functionality'/AND'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Relational Operator6/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Relational Operator7/Functionality'/EQ'
         */
    if ((((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)) == ((sint32)GET_S_TJASTM_SysStateTJA_nu())) || ((((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) && (((sint32) rtb_DataTypeConversion) != 0))) {
        SET_S_TJATVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE));
    } else {
        /* DataTypeConversion: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/AND/Functionality'/Data Type Conversion' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/from_data_definition3'/state_source'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/from_data_definition6'/state_source'
                 *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/AND/Functionality'/AND'
                 *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/NOT/Functionality'/NOT'
                 *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Relational Operator2/Functionality'/EQ'
                 *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Relational Operator5/Functionality'/EQ'
                 */
        rtb_DataTypeConversion = (uint8)((!(((sint32)rtb_DataTypeConversion) != 0)) && ((((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)) == ((sint32)GET_S_TJASTM_SysStateTJA_nu())) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))));
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Constant1'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/from_data_definition7'/state_source'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/from_data_definition9'/state_source'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/ObserveModeTransitions/SALC_NewTargetLane/from_data_definition11'/state_source'
                 *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
                 *  Inport: '<Root>/S_TJATTG_TransTriggerReplan_bool'
                 *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/AND2/Functionality'/AND'
                 *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/AND3/Functionality'/AND'
                 *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/OR2/Functionality'/OR'
                 *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/ObserveModeTransitions/SALC_NewTargetLane/Relational Operator3/Functionality'/EQ'
                 *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Switch2/Functionality'/Switch'
                 */
        if (((((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) || ((((sint32) GET_S_TJATTG_TransTriggerReplan_bool()) != 0) && (((sint32) GET_P_TJATVG_ModeTransTrigReplan_bool()) != 0))) && (((sint32) rtb_DataTypeConversion) != 0)) {
            SET_S_TJATVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_REFCHNG));
        } else if (((sint32)rtb_DataTypeConversion) != 0) {
            /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/from_data_definition8'/state_source'
                         */
            SET_S_TJATVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ));
        } else {
            SET_S_TJATVG_TrajGuiQu_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
        }
        /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Switch1/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/DetermineTrajGuiQualifier/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         */
    rtb_EQ_e = (uint8)(((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection1/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection1'/Unit_Delay2'
         */
    if (((sint32)rtb_EQ_e) != 0) {
        rtb_DataTypeConversion = DW_tjatvg_Unit_Delay2_DSTATE;
    } else {
        rtb_DataTypeConversion = GET_S_TJASTM_LatCtrlMode_nu();
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection1/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/CreateSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/from_data_definition5'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/CreateSwitch/Constant'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/CreateSwitch/Constant2'/Constant'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/EQ3/Functionality'/EQ'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/CreateSwitch/Switch1/Functionality'/Switch'
         */
    if ((((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) {
        rtb_EQ_e = 0U;
    } else {
        if (((sint32)rtb_EQ_e) == 0) {
            rtb_EQ_e = 2U;
        }
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/CreateSwitch/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Application Parameter3'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Application Parameter9'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/from_data_definition2'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/from_data_definition3'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/from_data_definition4'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/from_data_definition5'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/from_data_definition6'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/from_data_definition7'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/OR/Functionality'/OR'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/OR1/Functionality'/OR'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/OR2/Functionality'/OR'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/EQ7/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/EQ8/Functionality'/EQ'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch3/Functionality'/Switch'
         */
    if ((((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC_RQ)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()))) {
        SET_S_TJATVG_LtcyCompActivated_nu(GET_P_TJATVG_UseLtcyCompLC_bool());
    } else if ((((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ)))) {
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Application Parameter1'/Constant'
                 */
        SET_S_TJATVG_LtcyCompActivated_nu(GET_P_TJATVG_UseLtcyCompOF_bool());
    } else if ((((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB_RQ)))) {
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Application Parameter2'/Constant'
                 *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch1/Functionality'/Switch'
                 */
        SET_S_TJATVG_LtcyCompActivated_nu(GET_P_TJATVG_UseLtcyCompCMB_bool());
    } else if ((((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC_RQ)))) {
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Application Parameter4'/Constant'
                 *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch2/Functionality'/Switch'
                 */
        SET_S_TJATVG_LtcyCompActivated_nu(GET_P_TJATVG_UseLtcyCompSALC_bool());
    } else {
        SET_S_TJATVG_LtcyCompActivated_nu(0U);
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/LatencyCompensationSwitch/Switch/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/Constant4'/Constant'
         */
    switch (rtb_EQ_e) {
    case 0:
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection/from_data_definition1'/state_source'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection/from_data_definition3'/state_source'
                 *  Inport: '<Root>/S_ABPLBP_ABDTimeStamp_sec'
                 *  Inport: '<Root>/S_ODPFOP_AccFRObjTStamp_sec'
                 *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
                 *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection/EQ1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection/EQ2/Functionality'/EQ'
                 */
        if ((((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ)))) {
            SET_S_TJATVG_SensorTStamp_sec(GET_S_ODPFOP_AccFRObjTStamp_sec());
        } else {
            SET_S_TJATVG_SensorTStamp_sec(GET_S_ABPLBP_ABDTimeStamp_sec());
        }
        /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection/Switch1/Functionality'/Switch' */
        break;
    case 1:
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection1/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection1/from_data_definition1'/state_source'
                 *  Inport: '<Root>/S_ABPLBP_ABDTimeStamp_sec'
                 *  Inport: '<Root>/S_ODPFOP_AccFRObjTStamp_sec'
                 *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection1/EQ2/Functionality'/EQ'
                 */
        if (((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32)rtb_DataTypeConversion)) {
            SET_S_TJATVG_SensorTStamp_sec(GET_S_ODPFOP_AccFRObjTStamp_sec());
        } else {
            SET_S_TJATVG_SensorTStamp_sec(GET_S_ABPLBP_ABDTimeStamp_sec());
        }
        /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection1/Switch1/Functionality'/Switch' */
        break;
    default:
        SET_S_TJATVG_SensorTStamp_sec(0.0F);
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp'/Multiport_Switch' */
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition13'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Relational Operator7/Functionality'/EQ'
         *  UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon'/Unit_Delay'
         */
    if (((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)) == ((sint32)GET_S_TJASTM_SysStateTJA_nu())) {
        rtb_EQ_e = DW_tjatvg_Unit_Delay_DSTATE;
    } else {
        rtb_EQ_e = GET_S_TJASTM_LatCtrlMode_nu();
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition2'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition3'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition4'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition5'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition6'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition7'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/from_data_definition8'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Constant1'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Constant8'/Constant'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/OR/Functionality'/OR'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/OR1/Functionality'/OR'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/EQ7/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/EQ8/Functionality'/EQ'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Switch3/Functionality'/Switch'
         */
    if ((((((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC_RQ)) == ((sint32)rtb_EQ_e)) || (((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)) == ((sint32)rtb_EQ_e))) || (((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB_RQ)) == ((sint32)rtb_EQ_e))) || (((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)) == ((sint32)rtb_EQ_e))) {
        rtb_Switch_jz = 0U;
    } else if ((((sint32)rtb_EQ_e) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF))) || (((sint32) rtb_EQ_e) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ)))) {
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Constant5'/Constant'
                 */
        rtb_Switch_jz = 1U;
    } else if ((((sint32)rtb_EQ_e) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC_RQ))) || (((sint32)rtb_EQ_e) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)))) {
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Constant4'/Constant'
                 *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Switch3/Functionality'/Switch'
                 */
        rtb_Switch_jz = 2U;
    } else {
        rtb_Switch_jz = 3U;
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Index_Generator/Switch1/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/Else/Constant'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneChange/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneCentering/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneCentering/Y_TJATVG_PlanningHorizonVal_sec/Functionality/odtc'/Product'
         *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneCentering/Y_TJATVG_PlanningHorizonVal_sec1/Functionality/odtc'/Product'
         *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/ObjectFollowing/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/ObjectFollowing/Y_TJATVG_PlanningHorizonVal_sec/Functionality/odtc'/Product'
         *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/ObjectFollowing/Y_TJATVG_PlanningHorizonVal_sec1/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneCentering/Y_TJATVG_PlanningHorizonVal_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneCentering/Y_TJATVG_PlanningHorizonVal_sec1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/ObjectFollowing/Y_TJATVG_PlanningHorizonVal_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/ObjectFollowing/Y_TJATVG_PlanningHorizonVal_sec1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_jz) {
    case 0:
        /* Abs: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneCentering/Abs/Functionality'/Abs' incorporates:
                 *  Inport: '<Root>/S_TJATTG_TgtTrajCrv_1pm'
                 */
        rtb_Abs = f32_abs_f32(GET_S_TJATTG_TgtTrajCrv_1pm());
        /* S-Function Block sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneCentering/Y_TJATVG_PlanningHorizonVal_sec1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TJATVG_CrvPlanHorizon_1pm */
            FDPS_PTR_F32(GETA_X_TJATVG_CrvPlanHorizon_1pm(), rtb_Abs, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_TJATVG_PlanHorizonScalFact_nu(), &dps_result_ln);
        }
        /* S-Function Block sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/LaneCentering/Y_TJATVG_PlanningHorizonVal_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TJATVG_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_TJATVG_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D (GETA_Y_TJATVG_PlanningHorizonVal_sec(), &dps_result_ln);
        }
        SET_S_TJATVG_PlanningHorizon_sec(rtb_ip_lookup_fxpt_sfun_7_a * rtb_ip_lookup_fxpt_sfun_7_g);
        break;
    case 1:
        /* Abs: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/ObjectFollowing/Abs/Functionality'/Abs' incorporates:
                 *  Inport: '<Root>/S_TJATTG_TgtTrajCrv_1pm'
                 */
        rtb_Abs_l = f32_abs_f32(GET_S_TJATTG_TgtTrajCrv_1pm());
        /* S-Function Block sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/ObjectFollowing/Y_TJATVG_PlanningHorizonVal_sec1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TJATVG_CrvPlanHorizon_1pm */
            FDPS_PTR_F32(GETA_X_TJATVG_CrvPlanHorizon_1pm(), rtb_Abs_l, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_gj = F32_PTR_IP1D (GETA_Y_TJATVG_PlanHorizonScalFact_nu(), &dps_result_ln);
        }
        /* S-Function Block sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon/ObjectFollowing/Y_TJATVG_PlanningHorizonVal_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TJATVG_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_TJATVG_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_TJATVG_PlanHorizonObjFolVal_sec(), &dps_result_ln);
        }
        SET_S_TJATVG_PlanningHorizon_sec(rtb_ip_lookup_fxpt_sfun_7_p * rtb_ip_lookup_fxpt_sfun_7_gj);
        break;
    case 2:
        SET_S_TJATVG_PlanningHorizon_sec(GET_P_TJATVG_PlanHorzLaneChange_sec());
        break;
    default:
        SET_S_TJATVG_PlanningHorizon_sec(0.0F);
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon'/Multiport_Switch' */
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter5'/Constant' */
    SET_S_TJATVG_FTireAclMax_mps2(GET_P_TJATVG_FTireAccelMax_mps2());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter2'/Constant' */
    SET_S_TJATVG_FTireAclMin_mps2(GET_P_TJATVG_FTireAccelMin_mps2());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter6'/Constant' */
    SET_S_TJATVG_DistYTolLeTgtArea_met(GET_P_TJATVG_DistYToleranceLeftTgtArea_met());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter7'/Constant' */
    SET_S_TJATVG_DistYTolRiTgtArea_met(GET_P_TJATVG_DistYToleranceRightTgtArea_met ());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter12'/Constant' */
    SET_S_TJATVG_WeightTgtDistY_nu(GET_P_TJATVG_WeightTgtDistY_nu());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter11'/Constant' */
    SET_S_TJATVG_WeightEndTime_nu(GET_P_TJATVG_WeightEndtime_nu());
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Switch/Functionality'/Switch' incorporates:
                                                                      *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter1'/Constant'
                                                                      *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter3'/Constant'
                                                                      *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/SALC_ActiveCheck/from_data_definition11'/state_source'
                                                                      *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/SALC_ActiveCheck/from_data_definition5'/state_source'
                                                                      *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
                                                                      *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/SALC_ActiveCheck/OR3/Functionality'/OR'
                                                                      *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/SALC_ActiveCheck/Relational Operator1/Functionality'/EQ'
                                                                      *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/SALC_ActiveCheck/Relational Operator3/Functionality'/EQ'
                                                                      */
    if ((((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC_RQ)))) {
        SET_S_TJATVG_TrajPlanServQu_nu(GET_P_TJATVG_TrajPlanValSrvQuSALC_nu());
    } else {
        SET_S_TJATVG_TrajPlanServQu_nu(GET_P_TJATVG_TrajPlanValServQu_nu());
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Switch/Functionality'/Switch' */
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter9'/Constant' */
    SET_S_TJATVG_PredTimeCrv_sec(GET_P_TJATVG_PredictionTimeCrv_sec());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter10'/Constant' */
    SET_S_TJATVG_PredTimeHeadAng_sec(GET_P_TJATVG_PredTimeHeadAng_sec());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter8'/Constant' */
    SET_S_TJATVG_TriggerReplan_nu(GET_P_TJATVG_TriggerReplan_bool());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant87'/Constant' */
    SET_S_TJATVG_ObstacleVelX_mps(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant88'/Constant' */
    SET_S_TJATVG_ObstacleAclX_mps2(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant85'/Constant' */
    SET_S_TJATVG_ObstacleWidth_met(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant86'/Constant' */
    SET_S_TJATVG_ObstacleDistX_met(999.0F);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant84'/Constant' */
    SET_S_TJATVG_ObstacleDistY_met(100.0F);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant5'/Constant' */
    SET_S_TJATVG_CrvAmplActivated_nu(0U);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant6'/Constant' */
    SET_S_TJATVG_LimiterActivated_nu(0U);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant7'/Constant' */
    SET_S_TJATVG_LimiterType_nu(0U);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant8'/Constant' */
    SET_S_TJATVG_LimiterTimeDuration_sec(0.0F);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter4'/Constant' */
    SET_S_TJATVG_MaxJerkAllowed_mps3(GET_P_TJATVG_MaxJerkAllowed_mps3());
    /* S-Function Block sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Y_TJATVG_LWDeratLvlScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Switch_hw = F32_PTR_IP1D(GETA_Y_TJATVG_LWDeratLvlScalFact_nu(), &dps_result_ln);
    }
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Switch15/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter15'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter16'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant14'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Constant4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_DrivingMode_nu'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Relational Operator8/Functionality'/EQ'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Switch12/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_DrivingMode_nu()) == 3) {
        rtb_Switch_jz = GET_P_TJATVG_MD3DeratingLevel_perc();
    } else if (((sint32)GET_S_LCFRCV_DrivingMode_nu()) == 2) {
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Switch12/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Application Parameter14'/Constant'
                 */
        rtb_Switch_jz = GET_P_TJATVG_MD2DeratingLevel_perc();
    } else {
        rtb_Switch_jz = GET_P_TJATVG_MD1DeratingLevel_perc();
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Switch15/Functionality'/Switch' */
    /* Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/SetConstOutputs/Mul/Functionality'/Mul' */
    SET_S_TJATVG_DeratingLevel_nu(u8_f32(((float32)rtb_Switch_jz) * rtb_Switch_hw));
    /* Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Product/Functionality/Div'/Div' incorporates:
                                                                          *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter7'/Constant'
                                                                          *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Constant'/Constant'
                                                                          *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Constant4'/Constant'
                                                                          *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/constant_value1'/Constant'
                                                                          *  MinMax: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Max/Functionality'/Max'
                                                                          *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Deg2Rad/Functionality'/Mul'
                                                                          */
    rtb_Div = (0.0174532924F * GET_P_TJATVG_MaxSteeringAngle_deg()) / f32_max_f32_f32(0.01F, GET_P_VEH_Wheelbase_met());
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/from_data_definition4'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_OF/Application Parameter2'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_OF/Application Parameter3'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_OF/Application Parameter4'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_OF/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/EQ3/Functionality'/EQ'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/Switch3/Functionality'/Switch'
         */
    if ((((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))) {
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter1'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter10'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter2'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter3'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter4'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter5'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter6'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter8'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Application Parameter9'/Constant'
                 *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Product1/Functionality'/Mul'
                 *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Product2/Functionality'/Mul'
                 *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Product3/Functionality'/Mul'
                 *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Product4/Functionality'/Mul'
                 *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Product5/Functionality'/Mul'
                 *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Switch/Functionality'/Switch'
                 */
        if (((sint32)GET_P_TJATVG_SetMaxCrvAndGrdLims_nu()) != 0) {
            SET_S_TJATVG_MaxCrvTrajGuiCtrl_1pm(GET_P_TJATVG_LimiterMaxCrv_1pm());
            SET_S_TJATVG_MaxCrvGrdBuildup_1pms(GET_P_TJATVG_LimiterMaxCrvGrd_1pms());
            SET_S_TJATVG_MaxCrvGrdRed_1pms(GET_P_TJATVG_LimiterMaxCrvGrd_1pms());
            SET_S_TJATVG_GrdLimitTgtCrvTGC_1pms(GET_P_TJATVG_LimiterMaxCrvGrd_1pms());
        } else {
            SET_S_TJATVG_MaxCrvTrajGuiCtrl_1pm(GET_P_TJATVG_MinFactorCrvGrd_nu() * rtb_Div);
            SET_S_TJATVG_MaxCrvGrdBuildup_1pms((rtb_Div * GET_P_TJATVG_FactorCrvGrdBuildUp_nu()) * GET_P_TJATVG_MinFactorCrvGrd_nu ());
            SET_S_TJATVG_MaxCrvGrdRed_1pms((rtb_Div * GET_P_TJATVG_FactorCrvGrdRed_nu()) * GET_P_TJATVG_MinFactorCrvGrd_nu());
            SET_S_TJATVG_GrdLimitTgtCrvTGC_1pms(GET_P_TJATVG_GrdLimitTgtCrvTGC_1pms());
        }
        /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/TargetCurvatureGradient_LCorCB/Switch/Functionality'/Switch' */
    } else {
        SET_S_TJATVG_MaxCrvTrajGuiCtrl_1pm(GET_P_TJATVG_LimiterMaxCrv_1pm());
        SET_S_TJATVG_MaxCrvGrdBuildup_1pms(GET_P_TJATVG_LimiterMaxCrvGrd_1pms());
        SET_S_TJATVG_MaxCrvGrdRed_1pms(GET_P_TJATVG_LimiterMaxCrvGrd_1pms());
        SET_S_TJATVG_GrdLimitTgtCrvTGC_1pms(GET_P_TJATVG_LimiterMaxCrvGrd_1pms());
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TargetCurvatureGradients/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/from_data_definition2'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Relational Operator5/Functionality'/EQ'
         */
    rtb_Switch_jz = (uint8)((((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))));
    /* DataTypeConversion: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Constant2'/Constant'
         *  Inport: '<Root>/S_TJATTG_PredictionEnable_bool'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_dm = (uint8)((((sint32) GET_S_TJATTG_PredictionEnable_bool()) != 0) && (((sint32) GET_P_TJALKA_RampoutPredictOn_bool()) != 0));
    /* DataTypeConversion: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/AND1/Functionality'/AND'
         *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/NOT/Functionality'/NOT'
         *  UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling'/Unit_Delay'
         */
    rtb_DataTypeConversion_b = (uint8)((((sint32)DW_tjatvg_Unit_Delay_DSTATE_h) != 0) && (!(((sint32)rtb_DataTypeConversion_dm) != 0)));
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Index_Generator/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Index_Generator/Constant4'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Index_Generator/Constant8'/Constant'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Relational Operator1/Functionality'/EQ'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Index_Generator/Switch3/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_jz) != 0) {
        rtb_Switch_ai = 0U;
    } else if (((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) {
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Index_Generator/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Index_Generator/Constant5'/Constant'
                 */
        rtb_Switch_ai = 1U;
    } else {
        rtb_Switch_ai = 2U;
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Index_Generator/Switch1/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant7'/Constant'
         */
    switch (rtb_Switch_ai) {
    case 0:
        /* Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Constant1'
                 *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
                 *  UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling'/Unit_Delay1'
                 */
        rtb_Switch_ai = (uint8)((((sint32)rtb_DataTypeConversion_b) != 0) || (DW_tjatvg_Unit_Delay1_DSTATE > 0.0F));
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant11'/Constant'
                 *  Logic: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/OR/Functionality'/OR'
                 */
        if ((((sint32)rtb_DataTypeConversion_dm) != 0) || (((sint32)rtb_Switch_ai) != 0)) {
            /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Constant10'/Constant'
                         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Constant11'/Constant'
                         */
            if (((sint32)rtb_Switch_ai) != 0) {
                SET_S_TJATVG_StrWhStifGrad_1ps(GET_P_TJATVG_StrWhStifRampInGrd_1ps());
            } else {
                SET_S_TJATVG_StrWhStifGrad_1ps(GET_P_TJATVG_StrWhStifRampOutGrd_1ps());
            }
            /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Switch1/Functionality'/Switch' */
        } else {
            SET_S_TJATVG_StrWhStifGrad_1ps(GET_P_TJATVG_StrWhStifRampInGrd_1ps());
        }
        /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Switch2/Functionality'/Switch' */
        /* MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients'/Multiport_Switch1' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant6'/Constant'
                 */
        SET_S_TJATVG_MaxTrqScalGrad_1ps(GET_P_TJATVG_MaxTrqScalRampInGrd_1ps());
        /* MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients'/Multiport_Switch2' incorporates:
                                                                              *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant1'/Constant'
                                                                              */
        SET_S_TJATVG_TrqRampGrad_1ps(GET_P_TJATVG_TrqRampInGrad_1ps());
        break;
    case 1:
        /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant10'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant12'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant4'/Constant'
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant8'/Constant'
                 *  Inport: '<Root>/S_TJAGEN_Abort_bool'
                 *  MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients'/Multiport_Switch2'
                 *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Switch1/Functionality'/Switch'
                 */
        if (((sint32)GET_S_TJAGEN_Abort_bool()) != 0) {
            SET_S_TJATVG_StrWhStifGrad_1ps(GET_P_TJATVG_StrWhStifAbortGrd_1ps());
            SET_S_TJATVG_TrqRampGrad_1ps(GET_P_TJATVG_TrqAbortGrad_1ps());
        } else {
            SET_S_TJATVG_StrWhStifGrad_1ps(GET_P_TJATVG_StrWhStifRampOutGrd_1ps());
            SET_S_TJATVG_TrqRampGrad_1ps(GET_P_TJATVG_TrqRampOutGrad_1ps());
        }
        /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Switch/Functionality'/Switch' */
        /* MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients'/Multiport_Switch1' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant3'/Constant'
                 */
        SET_S_TJATVG_MaxTrqScalGrad_1ps(GET_P_TJATVG_MaxTrqScalRampOutGrd_1ps());
        break;
    default:
        SET_S_TJATVG_StrWhStifGrad_1ps(0.0F);
        /* MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients'/Multiport_Switch1' incorporates:
                                                  *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant2'/Constant'
                                                  *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant7'/Constant'
                                                  */
        SET_S_TJATVG_MaxTrqScalGrad_1ps(0.0F);
        /* MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients'/Multiport_Switch2' incorporates:
                                                   *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients/Constant9'/Constant'
                                                   */
        SET_S_TJATVG_TrqRampGrad_1ps(0.0F);
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Gradients'/Multiport_Switch' */
    /* S-Function Block sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Y_DPRTVG_VYMD1DeratingLevel_nu2/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TJATVG_VehVelX_RedFact_mps */
        FDPS_PTR_F32(GETA_X_TJATVG_VehVelX_RedFact_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TJATVG_RedFact_Vel_nu(), &dps_result_ln);
    }
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Constant4'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Constant7'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_dm) != 0) {
        rtb_Switch_hw = GET_P_TJATVG_StrWhStifLimitPredct_nu();
    } else {
        rtb_Switch_hw = 1.0F;
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Switch/Functionality'/Switch' */
    /* Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Mul/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Y_DPRTVG_VYMD1DeratingLevel_nu2/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Y_DPRTVG_VYMD1DeratingLevel_nu2/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div = rtb_ip_lookup_fxpt_sfun_7 * rtb_Switch_hw;
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Limiter/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Limiter/Constant4'/Constant'
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Limiter/Constant7'/Constant'
         */
    if (((sint32)rtb_Switch_jz) != 0) {
        rtb_Switch_hw = GET_P_TJATVG_StrWhStifLimit_nu();
    } else {
        rtb_Switch_hw = 0.0F;
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Limiter/Switch/Functionality'/Switch' */
    /* Product: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Limiter/Mul/Functionality'/Mul' */
    SET_S_TJATVG_StrWhStifLimit_nu(rtb_Div * rtb_Switch_hw);
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Limiter/Constant6'/Constant' */
    SET_S_TJATVG_MaxTrqScalLimit_nu(GET_P_TJATVG_MaxTrqScalLimit_nu());
    /* Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/Constant1'/Constant' */
    SET_S_TJATVG_HighStatAccu_bool(GET_P_TJATVG_HighStatAccu_bool());
    /* Update for UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/GenerateTimeStamp/ClothoidSelection1'/Unit_Delay2' */
    DW_tjatvg_Unit_Delay2_DSTATE = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/PlanningHorizon'/Unit_Delay' */
    DW_tjatvg_Unit_Delay_DSTATE = rtb_EQ_e;
    /* Update for UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling'/Unit_Delay' */
    DW_tjatvg_Unit_Delay_DSTATE_h = rtb_DataTypeConversion_dm;
    /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_b) != 0) {
        /* Update for UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling'/Unit_Delay1' incorporates:
                 *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Constant8'/Constant'
                 */
        DW_tjatvg_Unit_Delay1_DSTATE = GET_P_TJATTG_TransDurationPredct_sec();
    } else {
        if (DW_tjatvg_Unit_Delay1_DSTATE > 0.0F) {
            /* Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/Constant1'/Constant'
                         *  Sum: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling'/Unit_Delay1'
                         *  Update for UnitDelay: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling'/Unit_Delay1'
                         */
            DW_tjatvg_Unit_Delay1_DSTATE -= 0.06F;
        }
    }
    /* End of Switch: 'sda:TJATVG/TJATVG/TJATVG_SenProcess/M_TJATVG/TorqueLimitationAndGradients/PredictionRampoutHandling/TURNOFFDELAYTIME/Functionality'/Switch1' */
}
#include "Pse_TJATVG.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
