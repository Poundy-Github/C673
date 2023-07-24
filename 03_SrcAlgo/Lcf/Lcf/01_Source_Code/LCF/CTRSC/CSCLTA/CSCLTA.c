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
 * File          : CSCLTA
 * Generated on  : Tue 12.03.2019 at 09:14:44 (UTC+01:00)
 * MD5           : [499868884   118013518  1885638305  3276441104 0](CSCLTA)
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
 * Date          : $Date: 2019/05/29 09:53:26CEST $
 * Changes       :
 * $Log: CSCLTA.c  $
 * Revision 1.2.1.1 2019/05/29 09:53:26CEST Diaz Bravo, Jose Luis (uidg8685) 
 * B2B
 * Revision 1.22 2019/03/12 09:50:13CET Diaz Bravo, Jose Luis (uidg8685) 
 * automatically created
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "CSCLTA.h"
#include "CSCLTA_private.h"
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
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:CSCLTA/CSCLTA/INI'/CSCLTA_SenReset'
 * Block description for: 'sda:CSCLTA/CSCLTA/INI'/CSCLTA_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_CSCLTA_SenReset
#include "Pse_CSCLTA.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void CSCLTA_SenReset(void)
{
    /* Function local data */
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value'/Signal Conversion' incorporates:
         *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value'/Constant'
         */
    SET_S_CSCLTA_ObstacleAclX_mps2(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value1'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value1'/Constant'
                                            */
    SET_S_CSCLTA_ObstacleVelX_mps(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value10'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value10'/Constant'
                                            */
    SET_S_CSCLTA_DistYTolLeTgtArea_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value11'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value11'/Constant'
                                                */
    SET_S_CSCLTA_WeightEndTime_nu(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value12'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value12'/Constant'
                                            */
    SET_S_CSCLTA_WeightTgtDistY_nu(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value13'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value13'/Constant'
                                            */
    SET_S_CSCLTA_TrajPlanServQu_nu(0U);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value14'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value14'/Constant'
                                            */
    SET_S_CSCLTA_TgtTrajLength_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value15'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value15'/Constant'
                                            */
    SET_S_CSCLTA_TgtTrajCrvChng_1pm2(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value16'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value16'/Constant'
                                              */
    SET_S_CSCLTA_TgtTrajCrv_1pm(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value17'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value17'/Constant'
                                            */
    SET_S_CSCLTA_TgtTrajHeadAng_rad(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value18'/Signal Conversion' incorporates:
                                             *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value18'/Constant'
                                             */
    SET_S_CSCLTA_LeCridrBndLength_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value19'/Signal Conversion' incorporates:
                                               *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value19'/Constant'
                                               */
    SET_S_CSCLTA_LeCridrBndCrvChng_1pm2(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value2'/Signal Conversion' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value2'/Constant'
                                                 */
    SET_S_CSCLTA_PlanningHorizon_sec(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value20'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value20'/Constant'
                                              */
    SET_S_CSCLTA_LeCridrBndCrv_1pm(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value21'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value21'/Constant'
                                            */
    SET_S_CSCLTA_LeCridrBndHeadAng_rad(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value22'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value22'/Constant'
                                                */
    SET_S_CSCLTA_LeCridrBndPosY0_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value23'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value23'/Constant'
                                              */
    SET_S_CSCLTA_LeCridrBndPosX0_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value24'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value24'/Constant'
                                              */
    SET_S_CSCLTA_TgtTrajPosY0_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value25'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value25'/Constant'
                                            */
    SET_S_CSCLTA_TgtTrajPosX0_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value26'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value26'/Constant'
                                            */
    SET_S_CSCLTA_RiCridrBndLength_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value27'/Signal Conversion' incorporates:
                                               *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value27'/Constant'
                                               */
    SET_S_CSCLTA_RiCridrBndCrvChng_1pm2(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value28'/Signal Conversion' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value28'/Constant'
                                                 */
    SET_S_CSCLTA_RiCridrBndCrv_1pm(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value29'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value29'/Constant'
                                            */
    SET_S_CSCLTA_RiCridrBndHeadAng_rad(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value3'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value3'/Constant'
                                                */
    SET_S_CSCLTA_PredictionTimeCrv_sec(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value30'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value30'/Constant'
                                                */
    SET_S_CSCLTA_RiCridrBndPosY0_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value31'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value31'/Constant'
                                              */
    SET_S_CSCLTA_RiCridrBndPosX0_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value32'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value32'/Constant'
                                              */
    SET_S_CSCLTA_StrWhStifGrad_1ps(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value33'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value33'/Constant'
                                            */
    SET_S_CSCLTA_LimiterActivated_nu(0U);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value35'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value35'/Constant'
                                            */
    SET_S_CSCLTA_SensorTStamp_sec(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value36'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value36'/Constant'
                                            */
    SET_S_CSCLTA_LatencyCompActivated_nu(0U);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value37'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value37'/Constant'
                                                */
    SET_S_CSCLTA_ObstacleDistY_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value38'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value38'/Constant'
                                            */
    SET_S_CSCLTA_ObstacleDistX_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value39'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value39'/Constant'
                                            */
    SET_S_CSCLTA_ObstacleWidth_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value4'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value4'/Constant'
                                            */
    SET_S_CSCLTA_PredTimeHeadAng_sec(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value41'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value41'/Constant'
                                              */
    SET_S_CSCLTA_LimiterTimeDuration_sec(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value43'/Signal Conversion' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value43'/Constant'
                                                  */
    SET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value44'/Signal Conversion' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value44'/Constant'
                                                 */
    SET_S_CSCLTA_MaxCrvGrdRed_1pms(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value45'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value45'/Constant'
                                            */
    SET_S_CSCLTA_MaxCrvGrdBuildup_1pms(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value46'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value46'/Constant'
                                                */
    SET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value48'/Signal Conversion' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value48'/Constant'
                                                */
    SET_S_CSCLTA_TrqRampGrad_1ps(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value49'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value49'/Constant'
                                            */
    SET_S_CSCLTA_StrWhStifLimit_nu(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value5'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value5'/Constant'
                                            */
    SET_S_CSCLTA_TriggerReplan_nu(0U);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value50'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value50'/Constant'
                                            */
    SET_S_CSCLTA_MaxTrqScalLimit_nu(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value51'/Signal Conversion' incorporates:
                                             *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value51'/Constant'
                                             */
    SET_S_CSCLTA_MaxTrqScalGrad_1ps(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value52'/Signal Conversion' incorporates:
                                             *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value52'/Constant'
                                             */
    SET_S_CSCLTA_HighStatAccu_bool(0U);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value53'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value53'/Constant'
                                            */
    SET_S_CSCLTA_MaxJerkAllowed_mps3(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value6'/Signal Conversion' incorporates:
                                              *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value6'/Constant'
                                              */
    SET_S_CSCLTA_DeratingLevel_nu(0U);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value7'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value7'/Constant'
                                            */
    SET_S_CSCLTA_FTireAclMin_mps2(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value8'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value8'/Constant'
                                            */
    SET_S_CSCLTA_FTireAclMax_mps2(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value9'/Signal Conversion' incorporates:
                                            *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/constant_value9'/Constant'
                                            */
    SET_S_CSCLTA_DistYTolRiTgtArea_met(0.0F);
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/from_data_definition1'/Signal Conversion3' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/from_data_definition1'/state_source'
                                                */
    SET_S_CSCLTA_SysStateLCF_enum(((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu));
    /* SignalConversion: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/from_data_definition3'/Signal Conversion3' incorporates:
                                                           *  Constant: 'sda:CSCLTA/CSCLTA/INI/CSCLTA_SenReset/from_data_definition3'/state_source'
                                                           */
    SET_S_CSCLTA_TrajGuiQualifier_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
}
#include "Pse_CSCLTA.h"
/*
 * Output and update for function-call system: 'sda:CSCLTA/CSCLTA'/CSCLTA_SenProcess'
 * Block description for: 'sda:CSCLTA/CSCLTA'/CSCLTA_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_CSCLTA_SenProcess
#include "Pse_CSCLTA.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void CSCLTA_SenProcess(void)
{
    /* Function local data */
    uint8 tmp;
    /* Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Constant3'/Constant'
         *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/from_data_definition1'/state_source'
         *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/from_data_definition2'/state_source'
         *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/from_data_definition3'/state_source'
         *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/from_data_definition4'/state_source'
         *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  RelationalOperator: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Equality/Functionality'/EQ'
         *  RelationalOperator: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Equality1/Functionality'/EQ'
         *  RelationalOperator: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Equality2/Functionality'/EQ'
         *  RelationalOperator: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Equality4/Functionality'/EQ'
         *  RelationalOperator: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Equality5/Functionality'/EQ'
         *  Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch1/Functionality'/Switch'
         *  Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch2/Functionality'/Switch'
         *  Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch5/Functionality'/Switch'
         */
    if (((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_ALCA_nu))) {
        tmp = 5U;
    } else if (((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32) ((uint8)E_LCF_FunctionV3Type_E_LCF_LDPOC_nu))) {
        /* Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Constant1'/Constant'
                 */
        tmp = 4U;
    } else if (((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32) ((uint8)E_LCF_FunctionV3Type_E_LCF_RDP_nu))) {
        /* Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Constant6'/Constant'
                 *  Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch5/Functionality'/Switch'
                 */
        tmp = 3U;
    } else if (((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32) ((uint8)E_LCF_FunctionV3Type_E_LCF_LDP_nu))) {
        /* Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Constant2'/Constant'
                 *  Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch5/Functionality'/Switch'
                 */
        tmp = 2U;
    } else {
        tmp = (uint8)(((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32) ((uint8)E_LCF_FunctionV3Type_E_LCF_TJA_nu)));
    }
    /* End of Switch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Selection/Switch6/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch' */
    switch (tmp) {
    case 1:
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch18'/copy1' incorporates:
                 *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
                 */
        SET_S_CSCLTA_SysStateLCF_enum(GET_S_TJASTM_SysStateTJA_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch8'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_TJATTG_RiCridrBndHeadAng_rad'
                                                                          *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                          */
        SET_S_CSCLTA_RiCridrBndHeadAng_rad(GET_S_TJATTG_RiCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch9'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_RiCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrv_1pm(GET_S_TJATTG_RiCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch10'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_RiCridrBndCrvChng_1pm2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrvChng_1pm2(GET_S_TJATTG_RiCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch11'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_RiCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndLength_met(GET_S_TJATTG_RiCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch12'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_TgtTrajPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajPosX0_met(GET_S_TJATTG_TgtTrajPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch13'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATTG_TgtTrajPosY0_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajPosY0_met(GET_S_TJATTG_TgtTrajPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch14'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATTG_TgtTrajHeadAng_rad'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajHeadAng_rad(GET_S_TJATTG_TgtTrajHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch15'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_TgtTrajCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajCrv_1pm(GET_S_TJATTG_TgtTrajCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch16'/copy1' incorporates:
                                                                        *  Inport: '<Root>/S_TJATTG_TgtTrajCrvChng_1pm2'
                                                                        *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                        */
        SET_S_CSCLTA_TgtTrajCrvChng_1pm2(GET_S_TJATTG_TgtTrajCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch17'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_TgtTrajLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajLength_met(GET_S_TJATTG_TgtTrajLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_LeCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosX0_met(GET_S_TJATTG_LeCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch24'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_TrajPlanServQu_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrajPlanServQu_nu(GET_S_TJATVG_TrajPlanServQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch25'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_WeightTgtDistY_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightTgtDistY_nu(GET_S_TJATVG_WeightTgtDistY_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch26'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_WeightEndTime_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightEndTime_nu(GET_S_TJATVG_WeightEndTime_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch27'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATVG_DistYTolLeTgtArea_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_DistYTolLeTgtArea_met(GET_S_TJATVG_DistYTolLeTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch28'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_DistYTolRiTgtArea_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DistYTolRiTgtArea_met(GET_S_TJATVG_DistYTolRiTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch29'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_FTireAclMax_mps2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_FTireAclMax_mps2(GET_S_TJATVG_FTireAclMax_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch30'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATVG_FTireAclMin_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_FTireAclMin_mps2(GET_S_TJATVG_FTireAclMin_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch31'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATVG_TrajGuiQu_nu'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TrajGuiQualifier_nu(GET_S_TJATVG_TrajGuiQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch20'/copy1' incorporates:
                                                                           *  Inport: '<Root>/S_TJATVG_TriggerReplan_nu'
                                                                           *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                           */
        SET_S_CSCLTA_TriggerReplan_nu(GET_S_TJATVG_TriggerReplan_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch21'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATVG_PredTimeHeadAng_sec'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_PredTimeHeadAng_sec(GET_S_TJATVG_PredTimeHeadAng_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch1'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_LeCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosY0_met(GET_S_TJATTG_LeCridrBndPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch22'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_PredTimeCrv_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredictionTimeCrv_sec(GET_S_TJATVG_PredTimeCrv_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch23'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_PlanningHorizon_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PlanningHorizon_sec(GET_S_TJATVG_PlanningHorizon_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch32'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_ObstacleVelX_mps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleVelX_mps(GET_S_TJATVG_ObstacleVelX_mps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch33'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATVG_ObstacleAclX_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_ObstacleAclX_mps2(GET_S_TJATVG_ObstacleAclX_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch40'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_ObstacleWidth_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleWidth_met(GET_S_TJATVG_ObstacleWidth_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch41'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_ObstacleDistX_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistX_met(GET_S_TJATVG_ObstacleDistX_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch42'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_ObstacleDistY_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistY_met(GET_S_TJATVG_ObstacleDistY_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch43'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_LtcyCompActivated_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LatencyCompActivated_nu(GET_S_TJATVG_LtcyCompActivated_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch44'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_SensorTStamp_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_SensorTStamp_sec(GET_S_TJATVG_SensorTStamp_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch47'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATVG_MaxCrvTrajGuiCtrl_1pm'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(GET_S_TJATVG_MaxCrvTrajGuiCtrl_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch2'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_LeCridrBndHeadAng_rad'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndHeadAng_rad(GET_S_TJATTG_LeCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch34'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_MaxCrvGrdBuildup_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdBuildup_1pms(GET_S_TJATVG_MaxCrvGrdBuildup_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch35'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_MaxCrvGrdRed_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdRed_1pms(GET_S_TJATVG_MaxCrvGrdRed_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch36'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_GrdLimitTgtCrvTGC_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms(GET_S_TJATVG_GrdLimitTgtCrvTGC_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch37'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_StrWhStifLimit_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifLimit_nu(GET_S_TJATVG_StrWhStifLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch38'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_StrWhStifGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifGrad_1ps(GET_S_TJATVG_StrWhStifGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch51'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_TrqRampGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrqRampGrad_1ps(GET_S_TJATVG_TrqRampGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch52'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_TJATVG_MaxTrqScalLimit_nu'
                                                                          *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                          */
        SET_S_CSCLTA_MaxTrqScalLimit_nu(GET_S_TJATVG_MaxTrqScalLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch53'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_MaxTrqScalGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxTrqScalGrad_1ps(GET_S_TJATVG_MaxTrqScalGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch19'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_HighStatAccu_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_HighStatAccu_bool(GET_S_TJATVG_HighStatAccu_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch48'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_LimiterActivated_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterActivated_nu(GET_S_TJATVG_LimiterActivated_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch3'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_LeCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndCrv_1pm(GET_S_TJATTG_LeCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch50'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_LimiterTimeDuration_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterTimeDuration_sec(GET_S_TJATVG_LimiterTimeDuration_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch54'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_MaxJerkAllowed_mps3'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxJerkAllowed_mps3(GET_S_TJATVG_MaxJerkAllowed_mps3());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch39'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATVG_DeratingLevel_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DeratingLevel_nu(GET_S_TJATVG_DeratingLevel_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch4'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_TJATTG_LeCridrBndCrvChng_1pm2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_LeCridrBndCrvChng_1pm2(GET_S_TJATTG_LeCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch5'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_LeCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndLength_met(GET_S_TJATTG_LeCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch6'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_RiCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosX0_met(GET_S_TJATTG_RiCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch7'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_TJATTG_RiCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosY0_met(GET_S_TJATTG_RiCridrBndPosY0_met());
        break;
    case 2:
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch18'/copy1' incorporates:
                 *  Inport: '<Root>/S_DPLSMI_SysStateLDP_nu'
                 */
        SET_S_CSCLTA_SysStateLCF_enum(GET_S_DPLSMI_SysStateLDP_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch8'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_DPLTTG_RiCridrBndHeadAng_rad'
                                                                          *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                          */
        SET_S_CSCLTA_RiCridrBndHeadAng_rad(GET_S_DPLTTG_RiCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch9'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_RiCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrv_1pm(GET_S_DPLTTG_RiCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch10'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_RiCridrBndCrvChng_1pm2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrvChng_1pm2(GET_S_DPLTTG_RiCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch11'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_RiCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndLength_met(GET_S_DPLTTG_RiCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch12'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_TgtTrajPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajPosX0_met(GET_S_DPLTTG_TgtTrajPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch13'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPLTTG_TgtTrajPosY0_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajPosY0_met(GET_S_DPLTTG_TgtTrajPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch14'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPLTTG_TgtTrajHeadAng_rad'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajHeadAng_rad(GET_S_DPLTTG_TgtTrajHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch15'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_TgtTrajCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajCrv_1pm(GET_S_DPLTTG_TgtTrajCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch16'/copy1' incorporates:
                                                                        *  Inport: '<Root>/S_DPLTTG_TgtTrajCrvChng_1pm2'
                                                                        *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                        */
        SET_S_CSCLTA_TgtTrajCrvChng_1pm2(GET_S_DPLTTG_TgtTrajCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch17'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_TgtTrajLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajLength_met(GET_S_DPLTTG_TgtTrajLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_LeCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosX0_met(GET_S_DPLTTG_LeCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch24'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_TrajPlanServQu_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrajPlanServQu_nu(GET_S_DPLTVG_TrajPlanServQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch25'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_WeightTgtDistY_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightTgtDistY_nu(GET_S_DPLTVG_WeightTgtDistY_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch26'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_WeightEndTime_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightEndTime_nu(GET_S_DPLTVG_WeightEndTime_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch27'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPLTVG_DistYTolLeTgtArea_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_DistYTolLeTgtArea_met(GET_S_DPLTVG_DistYTolLeTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch28'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_DistYTolRiTgtArea_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DistYTolRiTgtArea_met(GET_S_DPLTVG_DistYTolRiTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch29'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_FTireAclMax_mps2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_FTireAclMax_mps2(GET_S_DPLTVG_FTireAclMax_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch30'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPLTVG_FTireAclMin_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_FTireAclMin_mps2(GET_S_DPLTVG_FTireAclMin_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch31'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPLTVG_TrajGuiQu_nu'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TrajGuiQualifier_nu(GET_S_DPLTVG_TrajGuiQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch20'/copy1' incorporates:
                                                                           *  Inport: '<Root>/S_DPLTVG_TriggerReplan_bool'
                                                                           *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                           */
        SET_S_CSCLTA_TriggerReplan_nu(GET_S_DPLTVG_TriggerReplan_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch21'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_PredTimeHeadAng_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredTimeHeadAng_sec(GET_S_DPLTVG_PredTimeHeadAng_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch1'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_LeCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosY0_met(GET_S_DPLTTG_LeCridrBndPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch22'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_PredTimeCrv_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredictionTimeCrv_sec(GET_S_DPLTVG_PredTimeCrv_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch23'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_PlanningHorizon_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PlanningHorizon_sec(GET_S_DPLTVG_PlanningHorizon_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch32'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_ObstacleVelX_mps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleVelX_mps(GET_S_DPLTVG_ObstacleVelX_mps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch33'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPLTVG_ObstacleAclX_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_ObstacleAclX_mps2(GET_S_DPLTVG_ObstacleAclX_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch40'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_ObstacleWidth_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleWidth_met(GET_S_DPLTVG_ObstacleWidth_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch41'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_ObstacleDistX_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistX_met(GET_S_DPLTVG_ObstacleDistX_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch42'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_ObstacleDistY_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistY_met(GET_S_DPLTVG_ObstacleDistY_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch43'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_LtcyCompActivated_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LatencyCompActivated_nu(GET_S_DPLTVG_LtcyCompActivated_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch44'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_SensorTStamp_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_SensorTStamp_sec(GET_S_DPLTVG_SensorTStamp_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch47'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPLTVG_MaxCrvTrajGuiCtrl_1pm'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(GET_S_DPLTVG_MaxCrvTrajGuiCtrl_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch2'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_LeCridrBndHeadAng_rad'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndHeadAng_rad(GET_S_DPLTTG_LeCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch34'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_MaxCrvGrdBuildup_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdBuildup_1pms(GET_S_DPLTVG_MaxCrvGrdBuildup_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch35'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_MaxCrvGrdRed_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdRed_1pms(GET_S_DPLTVG_MaxCrvGrdRed_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch36'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_GrdLimitTgtCrvTGC_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms(GET_S_DPLTVG_GrdLimitTgtCrvTGC_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch37'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_StrWhStifLimit_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifLimit_nu(GET_S_DPLTVG_StrWhStifLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch38'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_StrWhStifGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifGrad_1ps(GET_S_DPLTVG_StrWhStifGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch51'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_TrqRampGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrqRampGrad_1ps(GET_S_DPLTVG_TrqRampGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch52'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_DPLTVG_MaxTrqScalLimit_nu'
                                                                          *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                          */
        SET_S_CSCLTA_MaxTrqScalLimit_nu(GET_S_DPLTVG_MaxTrqScalLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch53'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_MaxTrqScalGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxTrqScalGrad_1ps(GET_S_DPLTVG_MaxTrqScalGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch19'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_HighStatAccu_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_HighStatAccu_bool(GET_S_DPLTVG_HighStatAccu_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch48'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_LimiterActivated_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterActivated_nu(GET_S_DPLTVG_LimiterActivated_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch3'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_LeCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndCrv_1pm(GET_S_DPLTTG_LeCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch50'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_LimiterTimeDuration_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterTimeDuration_sec(GET_S_DPLTVG_LimiterTimeDuration_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch54'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_MaxJerkAllowed_mps3'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxJerkAllowed_mps3(GET_S_DPLTVG_MaxJerkAllowed_mps3());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch39'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTVG_DeratingLevel_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DeratingLevel_nu(GET_S_DPLTVG_DeratingLevel_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch4'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPLTTG_LeCridrBndCrvChng_1pm2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_LeCridrBndCrvChng_1pm2(GET_S_DPLTTG_LeCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch5'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_LeCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndLength_met(GET_S_DPLTTG_LeCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch6'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_RiCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosX0_met(GET_S_DPLTTG_RiCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch7'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPLTTG_RiCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosY0_met(GET_S_DPLTTG_RiCridrBndPosY0_met());
        break;
    case 3:
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch18'/copy1' incorporates:
                 *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
                 */
        SET_S_CSCLTA_SysStateLCF_enum(GET_S_DPRSMI_SysStateRDP_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch8'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_DPRTTG_RiCridrBndHeadAng_rad'
                                                                          *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                          */
        SET_S_CSCLTA_RiCridrBndHeadAng_rad(GET_S_DPRTTG_RiCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch9'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_RiCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrv_1pm(GET_S_DPRTTG_RiCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch10'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_RiCridrBndCrvChng_1pm2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrvChng_1pm2(GET_S_DPRTTG_RiCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch11'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_RiCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndLength_met(GET_S_DPRTTG_RiCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch12'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_TgtTrajPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajPosX0_met(GET_S_DPRTTG_TgtTrajPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch13'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPRTTG_TgtTrajPosY0_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajPosY0_met(GET_S_DPRTTG_TgtTrajPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch14'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPRTTG_TgtTrajHeadAng_rad'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajHeadAng_rad(GET_S_DPRTTG_TgtTrajHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch15'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_TgtTrajCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajCrv_1pm(GET_S_DPRTTG_TgtTrajCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch16'/copy1' incorporates:
                                                                        *  Inport: '<Root>/S_DPRTTG_TgtTrajCrvChng_1pm2'
                                                                        *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                        */
        SET_S_CSCLTA_TgtTrajCrvChng_1pm2(GET_S_DPRTTG_TgtTrajCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch17'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_TgtTrajLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajLength_met(GET_S_DPRTTG_TgtTrajLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_LeCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosX0_met(GET_S_DPRTTG_LeCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch24'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_TrajPlanServQu_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrajPlanServQu_nu(GET_S_DPRTVG_TrajPlanServQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch25'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_WeightTgtDistY_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightTgtDistY_nu(GET_S_DPRTVG_WeightTgtDistY_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch26'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_WeightEndTime_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightEndTime_nu(GET_S_DPRTVG_WeightEndTime_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch27'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPRTVG_DistYTolLeTgtArea_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_DistYTolLeTgtArea_met(GET_S_DPRTVG_DistYTolLeTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch28'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_DistYTolRiTgtArea_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DistYTolRiTgtArea_met(GET_S_DPRTVG_DistYTolRiTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch29'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_FTireAclMax_mps2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_FTireAclMax_mps2(GET_S_DPRTVG_FTireAclMax_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch30'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPRTVG_FTireAclMin_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_FTireAclMin_mps2(GET_S_DPRTVG_FTireAclMin_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch31'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPRTVG_TrajGuiQu_nu'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TrajGuiQualifier_nu(GET_S_DPRTVG_TrajGuiQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch20'/copy1' incorporates:
                                                                           *  Inport: '<Root>/S_DPRTVG_TriggerReplan_bool'
                                                                           *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                           */
        SET_S_CSCLTA_TriggerReplan_nu(GET_S_DPRTVG_TriggerReplan_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch21'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_PredTimeHeadAng_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredTimeHeadAng_sec(GET_S_DPRTVG_PredTimeHeadAng_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch1'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_LeCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosY0_met(GET_S_DPRTTG_LeCridrBndPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch22'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_PredTimeCrv_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredictionTimeCrv_sec(GET_S_DPRTVG_PredTimeCrv_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch23'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_PlanningHorizon_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PlanningHorizon_sec(GET_S_DPRTVG_PlanningHorizon_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch32'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_ObstacleVelX_mps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleVelX_mps(GET_S_DPRTVG_ObstacleVelX_mps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch33'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPRTVG_ObstacleAclX_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_ObstacleAclX_mps2(GET_S_DPRTVG_ObstacleAclX_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch40'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_ObstacleWidth_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleWidth_met(GET_S_DPRTVG_ObstacleWidth_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch41'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_ObstacleDistX_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistX_met(GET_S_DPRTVG_ObstacleDistX_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch42'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_ObstacleDistY_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistY_met(GET_S_DPRTVG_ObstacleDistY_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch43'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_LtcyCompActivated_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LatencyCompActivated_nu(GET_S_DPRTVG_LtcyCompActivated_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch44'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_SensorTStamp_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_SensorTStamp_sec(GET_S_DPRTVG_SensorTStamp_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch47'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPRTVG_MaxCrvTrajGuiCtrl_1pm'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(GET_S_DPRTVG_MaxCrvTrajGuiCtrl_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch2'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_LeCridrBndHeadAng_rad'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndHeadAng_rad(GET_S_DPRTTG_LeCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch34'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_MaxCrvGrdBuildup_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdBuildup_1pms(GET_S_DPRTVG_MaxCrvGrdBuildup_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch35'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_MaxCrvGrdRed_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdRed_1pms(GET_S_DPRTVG_MaxCrvGrdRed_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch36'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_GrdLimitTgtCrvTGC_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms(GET_S_DPRTVG_GrdLimitTgtCrvTGC_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch37'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_StrWhStifLimit_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifLimit_nu(GET_S_DPRTVG_StrWhStifLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch38'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_StrWhStifGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifGrad_1ps(GET_S_DPRTVG_StrWhStifGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch51'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_TrqRampGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrqRampGrad_1ps(GET_S_DPRTVG_TrqRampGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch52'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_DPRTVG_MaxTrqScalLimit_nu'
                                                                          *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                          */
        SET_S_CSCLTA_MaxTrqScalLimit_nu(GET_S_DPRTVG_MaxTrqScalLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch53'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_MaxTrqScalGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxTrqScalGrad_1ps(GET_S_DPRTVG_MaxTrqScalGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch19'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_HighStatAccu_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_HighStatAccu_bool(GET_S_DPRTVG_HighStatAccu_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch48'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_LimiterActivated_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterActivated_nu(GET_S_DPRTVG_LimiterActivated_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch3'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_LeCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndCrv_1pm(GET_S_DPRTTG_LeCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch50'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_LimiterTimeDuration_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterTimeDuration_sec(GET_S_DPRTVG_LimiterTimeDuration_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch54'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_MaxJerkAllowed_mps3'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxJerkAllowed_mps3(GET_S_DPRTVG_MaxJerkAllowed_mps3());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch39'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTVG_DeratingLevel_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DeratingLevel_nu(GET_S_DPRTVG_DeratingLevel_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch4'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPRTTG_LeCridrBndCrvChng_1pm2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_LeCridrBndCrvChng_1pm2(GET_S_DPRTTG_LeCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch5'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_LeCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndLength_met(GET_S_DPRTTG_LeCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch6'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_RiCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosX0_met(GET_S_DPRTTG_RiCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch7'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPRTTG_RiCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosY0_met(GET_S_DPRTTG_RiCridrBndPosY0_met());
        break;
    case 4:
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch18'/copy1' incorporates:
                 *  Inport: '<Root>/S_DPOSTM_SysStateLDPOC_nu'
                 */
        SET_S_CSCLTA_SysStateLCF_enum(GET_S_DPOSTM_SysStateLDPOC_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch8'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTTG_RiCridrBndHeadAng_rad'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_RiCridrBndHeadAng_rad(GET_S_DPOTTG_RiCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch9'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_RiCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrv_1pm(GET_S_DPOTTG_RiCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch10'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_RiCridrBndCrvChng_1pm2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrvChng_1pm2(GET_S_DPOTTG_RiCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch11'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_RiCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndLength_met(GET_S_DPOTTG_RiCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch12'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_TgtTrajPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajPosX0_met(GET_S_DPOTTG_TgtTrajPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch13'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTTG_TgtTrajPosY0_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajPosY0_met(GET_S_DPOTTG_TgtTrajPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch14'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTTG_TgtTrajHeadAng_rad'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajHeadAng_rad(GET_S_DPOTTG_TgtTrajHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch15'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_TgtTrajCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajCrv_1pm(GET_S_DPOTTG_TgtTrajCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch16'/copy1' incorporates:
                                                                        *  Inport: '<Root>/S_DPOTTG_TgtTrajCrvChng_1pm2'
                                                                        *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                        */
        SET_S_CSCLTA_TgtTrajCrvChng_1pm2(GET_S_DPOTTG_TgtTrajCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch17'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_TgtTrajLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajLength_met(GET_S_DPOTTG_TgtTrajLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_LeCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosX0_met(GET_S_DPOTTG_LeCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch24'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_TrajPlanServQu_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrajPlanServQu_nu(GET_S_DPOTVG_TrajPlanServQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch25'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_WeightTgtDistY_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightTgtDistY_nu(GET_S_DPOTVG_WeightTgtDistY_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch26'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_WeightEndTime_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightEndTime_nu(GET_S_DPOTVG_WeightEndTime_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch27'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTVG_DistYTolLeTgtArea_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_DistYTolLeTgtArea_met(GET_S_DPOTVG_DistYTolLeTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch28'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_DistYTolRiTgtArea_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DistYTolRiTgtArea_met(GET_S_DPOTVG_DistYTolRiTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch29'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_FTireAclMax_mps2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_FTireAclMax_mps2(GET_S_DPOTVG_FTireAclMax_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch30'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTVG_FTireAclMin_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_FTireAclMin_mps2(GET_S_DPOTVG_FTireAclMin_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch31'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTVG_TrajGuiQu_nu'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TrajGuiQualifier_nu(GET_S_DPOTVG_TrajGuiQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch20'/copy1' incorporates:
                                                                           *  Inport: '<Root>/S_DPOTVG_TriggerReplan_bool'
                                                                           *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                           */
        SET_S_CSCLTA_TriggerReplan_nu(GET_S_DPOTVG_TriggerReplan_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch21'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_PredTimeHeadAng_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredTimeHeadAng_sec(GET_S_DPOTVG_PredTimeHeadAng_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch1'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_LeCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosY0_met(GET_S_DPOTTG_LeCridrBndPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch22'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_PredTimeCrv_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredictionTimeCrv_sec(GET_S_DPOTVG_PredTimeCrv_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch23'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_PlanningHorizon_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PlanningHorizon_sec(GET_S_DPOTVG_PlanningHorizon_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch32'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_ObstacleVelX_mps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleVelX_mps(GET_S_DPOTVG_ObstacleVelX_mps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch33'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTVG_ObstacleAclX_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_ObstacleAclX_mps2(GET_S_DPOTVG_ObstacleAclX_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch40'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_ObstacleWidth_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleWidth_met(GET_S_DPOTVG_ObstacleWidth_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch41'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_ObstacleDistX_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistX_met(GET_S_DPOTVG_ObstacleDistX_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch42'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_ObstacleDistY_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistY_met(GET_S_DPOTVG_ObstacleDistY_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch43'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_LtcyCompActivated_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LatencyCompActivated_nu(GET_S_DPOTVG_LtcyCompActivated_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch44'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_SensorTStamp_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_SensorTStamp_sec(GET_S_DPOTVG_SensorTStamp_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch47'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTVG_MaxCrvTrajGuiCtrl_1pm'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(GET_S_DPOTVG_MaxCrvTrajGuiCtrl_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch2'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_LeCridrBndHeadAng_rad'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndHeadAng_rad(GET_S_DPOTTG_LeCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch34'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_MaxCrvGrdBuildup_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdBuildup_1pms(GET_S_DPOTVG_MaxCrvGrdBuildup_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch35'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_MaxCrvGrdRed_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdRed_1pms(GET_S_DPOTVG_MaxCrvGrdRed_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch36'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_GrdLimitTgtCrvTGC_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms(GET_S_DPOTVG_GrdLimitTgtCrvTGC_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch37'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_StrWhStifLimit_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifLimit_nu(GET_S_DPOTVG_StrWhStifLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch38'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_StrWhStifGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifGrad_1ps(GET_S_DPOTVG_StrWhStifGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch51'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_TrqRampGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrqRampGrad_1ps(GET_S_DPOTVG_TrqRampGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch52'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_DPOTVG_MaxTrqScalLimit_nu'
                                                                          *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                          */
        SET_S_CSCLTA_MaxTrqScalLimit_nu(GET_S_DPOTVG_MaxTrqScalLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch53'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_MaxTrqScalGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxTrqScalGrad_1ps(GET_S_DPOTVG_MaxTrqScalGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch19'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_HighStatAccu_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_HighStatAccu_bool(GET_S_DPOTVG_HighStatAccu_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch48'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_LimiterActivated_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterActivated_nu(GET_S_DPOTVG_LimiterActivated_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch3'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_LeCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndCrv_1pm(GET_S_DPOTTG_LeCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch50'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_LimiterTimeDuration_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterTimeDuration_sec(GET_S_DPOTVG_LimiterTimeDuration_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch54'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_MaxJerkAllowed_mps3'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxJerkAllowed_mps3(GET_S_DPOTVG_MaxJerkAllowed_mps3());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch39'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTVG_DeratingLevel_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DeratingLevel_nu(GET_S_DPOTVG_DeratingLevel_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch4'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_DPOTTG_LeCridrBndCrvChng_1pm2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_LeCridrBndCrvChng_1pm2(GET_S_DPOTTG_LeCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch5'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_LeCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndLength_met(GET_S_DPOTTG_LeCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch6'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_RiCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosX0_met(GET_S_DPOTTG_RiCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch7'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_DPOTTG_RiCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosY0_met(GET_S_DPOTTG_RiCridrBndPosY0_met());
        break;
    case 5:
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch18'/copy1' incorporates:
                 *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
                 */
        SET_S_CSCLTA_SysStateLCF_enum(GET_S_LCRSMI_SysStateALCA_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch8'/copy1' incorporates:
                                                                           *  Inport: '<Root>/S_LCRTTG_RiCridrBndHeadAng_rad'
                                                                           *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                           */
        SET_S_CSCLTA_RiCridrBndHeadAng_rad(GET_S_LCRTTG_RiCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch9'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_RiCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrv_1pm(GET_S_LCRTTG_RiCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch10'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_RiCridrBndCrvChng_1pm2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndCrvChng_1pm2(GET_S_LCRTTG_RiCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch11'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_RiCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndLength_met(GET_S_LCRTTG_RiCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch12'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_TgtTrajPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajPosX0_met(GET_S_LCRTTG_TgtTrajPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch13'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_LCRTTG_TgtTrajPosY0_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajPosY0_met(GET_S_LCRTTG_TgtTrajPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch14'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_LCRTTG_TgtTrajHeadAng_rad'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TgtTrajHeadAng_rad(GET_S_LCRTTG_TgtTrajHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch15'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_TgtTrajCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajCrv_1pm(GET_S_LCRTTG_TgtTrajCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch16'/copy1' incorporates:
                                                                        *  Inport: '<Root>/S_LCRTTG_TgtTrajCrvChng_1pm2'
                                                                        *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                        */
        SET_S_CSCLTA_TgtTrajCrvChng_1pm2(GET_S_LCRTTG_TgtTrajCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch17'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_TgtTrajLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TgtTrajLength_met(GET_S_LCRTTG_TgtTrajLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_LeCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosX0_met(GET_S_LCRTTG_LeCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch24'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_TrajPlanServQu_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrajPlanServQu_nu(GET_S_LCRTVG_TrajPlanServQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch25'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_WeightTgtDistY_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightTgtDistY_nu(GET_S_LCRTVG_WeightTgtDistY_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch26'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_WeightEndTime_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_WeightEndTime_nu(GET_S_LCRTVG_WeightEndTime_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch27'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_LCRTVG_DistYTolLeTgtArea_met'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_DistYTolLeTgtArea_met(GET_S_LCRTVG_DistYTolLeTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch28'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_DistYTolRiTgtArea_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DistYTolRiTgtArea_met(GET_S_LCRTVG_DistYTolRiTgtArea_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch29'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_FTireAclMax_mps2'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_FTireAclMax_mps2(GET_S_LCRTVG_FTireAclMax_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch30'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_LCRTVG_FTireAclMin_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_FTireAclMin_mps2(GET_S_LCRTVG_FTireAclMin_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch31'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_LCRTVG_TrajGuiQu_nu'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_TrajGuiQualifier_nu(GET_S_LCRTVG_TrajGuiQu_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch20'/copy1' incorporates:
                                                                           *  Inport: '<Root>/S_LCRTVG_TriggerReplan_bool'
                                                                           *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                           */
        SET_S_CSCLTA_TriggerReplan_nu(GET_S_LCRTVG_TriggerReplan_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch21'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_PredTimeHeadAng_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredTimeHeadAng_sec(GET_S_LCRTVG_PredTimeHeadAng_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch1'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_LeCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndPosY0_met(GET_S_LCRTTG_LeCridrBndPosY0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch22'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_PredTimeCrv_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PredictionTimeCrv_sec(GET_S_LCRTVG_PredTimeCrv_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch23'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_PlanningHorizon_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_PlanningHorizon_sec(GET_S_LCRTVG_PlanningHorizon_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch32'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_ObstacleVelX_mps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleVelX_mps(GET_S_LCRTVG_ObstacleVelX_mps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch33'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_LCRTVG_ObstacleAclX_mps2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_ObstacleAclX_mps2(GET_S_LCRTVG_ObstacleAclX_mps2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch40'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_ObstacleWidth_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleWidth_met(GET_S_LCRTVG_ObstacleWidth_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch41'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_ObstacleDistX_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistX_met(GET_S_LCRTVG_ObstacleDistX_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch42'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_ObstacleDistY_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_ObstacleDistY_met(GET_S_LCRTVG_ObstacleDistY_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch43'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_LtcyCompActivated_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LatencyCompActivated_nu(GET_S_LCRTVG_LtcyCompActivated_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch44'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_SensorTStamp_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_SensorTStamp_sec(GET_S_LCRTVG_SensorTStamp_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch47'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_LCRTVG_MaxCrvTrajGuiCtrl_1pm'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(GET_S_LCRTVG_MaxCrvTrajGuiCtrl_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch2'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_LeCridrBndHeadAng_rad'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndHeadAng_rad(GET_S_LCRTTG_LeCridrBndHeadAng_rad());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch34'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_MaxCrvGrdBuildup_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdBuildup_1pms(GET_S_LCRTVG_MaxCrvGrdBuildup_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch35'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_MaxCrvGrdRed_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxCrvGrdRed_1pms(GET_S_LCRTVG_MaxCrvGrdRed_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch36'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_GrdLimitTgtCrvTGC_1pms'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms(GET_S_LCRTVG_GrdLimitTgtCrvTGC_1pms());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch37'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_StrWhStifLimit_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifLimit_nu(GET_S_LCRTVG_StrWhStifLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch38'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_StrWhStifGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_StrWhStifGrad_1ps(GET_S_LCRTVG_StrWhStifGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch51'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_TrqRampGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TrqRampGrad_1ps(GET_S_LCRTVG_TrqRampGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch52'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_LCRTVG_MaxTrqScalLimit_nu'
                                                                          *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                          */
        SET_S_CSCLTA_MaxTrqScalLimit_nu(GET_S_LCRTVG_MaxTrqScalLimit_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch53'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_MaxTrqScalGrad_1ps'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxTrqScalGrad_1ps(GET_S_LCRTVG_MaxTrqScalGrad_1ps());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch19'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_HighStatAccu_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_HighStatAccu_bool(GET_S_LCRTVG_HighStatAccu_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch48'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_LimiterActivated_bool'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterActivated_nu(GET_S_LCRTVG_LimiterActivated_bool());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch3'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_LeCridrBndCrv_1pm'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndCrv_1pm(GET_S_LCRTTG_LeCridrBndCrv_1pm());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch50'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_LimiterTimeDuration_sec'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LimiterTimeDuration_sec(GET_S_LCRTVG_LimiterTimeDuration_sec());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch54'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_MaxJerkAllowed_mps3'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_MaxJerkAllowed_mps3(GET_S_LCRTVG_MaxJerkAllowed_mps3());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch39'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTVG_DeratingLevel_nu'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_DeratingLevel_nu(GET_S_LCRTVG_DeratingLevel_nu());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch4'/copy1' incorporates:
                                                                            *  Inport: '<Root>/S_LCRTTG_LeCridrBndCrvChng_1pm2'
                                                                            *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                            */
        SET_S_CSCLTA_LeCridrBndCrvChng_1pm2(GET_S_LCRTTG_LeCridrBndCrvChng_1pm2());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch5'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_LeCridrBndLength_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_LeCridrBndLength_met(GET_S_LCRTTG_LeCridrBndLength_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch6'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_RiCridrBndPosX0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosX0_met(GET_S_LCRTTG_RiCridrBndPosX0_met());
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch7'/copy1' incorporates:
                                                                              *  Inport: '<Root>/S_LCRTTG_RiCridrBndPosY0_met'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_RiCridrBndPosY0_met(GET_S_LCRTTG_RiCridrBndPosY0_met());
        break;
    default:
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch18'/copy1' incorporates:
                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/from_data_definition1'/state_source'
                 */
        SET_S_CSCLTA_SysStateLCF_enum(((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu));
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch8'/copy1' incorporates:
                                                                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant26'/Constant'
                                                                 *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                 */
        SET_S_CSCLTA_RiCridrBndHeadAng_rad(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch9'/copy1' incorporates:
                                                      *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant27'/Constant'
                                                      *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                      */
        SET_S_CSCLTA_RiCridrBndCrv_1pm(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch10'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant28'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_RiCridrBndCrvChng_1pm2(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch11'/copy1' incorporates:
                                                       *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant29'/Constant'
                                                       *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                       */
        SET_S_CSCLTA_RiCridrBndLength_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch12'/copy1' incorporates:
                                                     *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant30'/Constant'
                                                     *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                     */
        SET_S_CSCLTA_TgtTrajPosX0_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch13'/copy1' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant31'/Constant'
                                                 *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                 */
        SET_S_CSCLTA_TgtTrajPosY0_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch14'/copy1' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant32'/Constant'
                                                 *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                 */
        SET_S_CSCLTA_TgtTrajHeadAng_rad(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch15'/copy1' incorporates:
                                                   *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant33'/Constant'
                                                   *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                   */
        SET_S_CSCLTA_TgtTrajCrv_1pm(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch16'/copy1' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant34'/Constant'
                                                *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                */
        SET_S_CSCLTA_TgtTrajCrvChng_1pm2(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch17'/copy1' incorporates:
                                                    *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant35'/Constant'
                                                    *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                    */
        SET_S_CSCLTA_TgtTrajLength_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant15'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_LeCridrBndPosX0_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch24'/copy1' incorporates:
                                                    *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant36'/Constant'
                                                    *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                    */
        SET_S_CSCLTA_TrajPlanServQu_nu(0U);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch25'/copy1' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant74'/Constant'
                                                *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                */
        SET_S_CSCLTA_WeightTgtDistY_nu(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch26'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant75'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_WeightEndTime_nu(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch27'/copy1' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant37'/Constant'
                                                 *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                 */
        SET_S_CSCLTA_DistYTolLeTgtArea_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch28'/copy1' incorporates:
                                                      *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant47'/Constant'
                                                      *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                      */
        SET_S_CSCLTA_DistYTolRiTgtArea_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch29'/copy1' incorporates:
                                                      *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant58'/Constant'
                                                      *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                      */
        SET_S_CSCLTA_FTireAclMax_mps2(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch30'/copy1' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant69'/Constant'
                                                 *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                 */
        SET_S_CSCLTA_FTireAclMin_mps2(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch31'/copy1' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/from_data_definition2'/state_source'
                                                 *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                 */
        SET_S_CSCLTA_TrajGuiQualifier_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch20'/copy1' incorporates:
                                                                              *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant83'/Constant'
                                                                              *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                                              */
        SET_S_CSCLTA_TriggerReplan_nu(0U);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch21'/copy1' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant81'/Constant'
                                                *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                */
        SET_S_CSCLTA_PredTimeHeadAng_sec(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch1'/copy1' incorporates:
                                                    *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant18'/Constant'
                                                    *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                    */
        SET_S_CSCLTA_LeCridrBndPosY0_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch22'/copy1' incorporates:
                                                    *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant82'/Constant'
                                                    *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                    */
        SET_S_CSCLTA_PredictionTimeCrv_sec(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch23'/copy1' incorporates:
                                                      *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant77'/Constant'
                                                      *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                      */
        SET_S_CSCLTA_PlanningHorizon_sec(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch32'/copy1' incorporates:
                                                    *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant87'/Constant'
                                                    *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                    */
        SET_S_CSCLTA_ObstacleVelX_mps(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch33'/copy1' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant88'/Constant'
                                                 *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                 */
        SET_S_CSCLTA_ObstacleAclX_mps2(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch40'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant85'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_ObstacleWidth_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch41'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant86'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_ObstacleDistX_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch42'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant84'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_ObstacleDistY_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch43'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant89'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_LatencyCompActivated_nu(0U);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch44'/copy1' incorporates:
                                                      *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant90'/Constant'
                                                      *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                      */
        SET_S_CSCLTA_SensorTStamp_sec(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch47'/copy1' incorporates:
                                                 *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant91'/Constant'
                                                 *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                 */
        SET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch2'/copy1' incorporates:
                                                      *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant20'/Constant'
                                                      *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                      */
        SET_S_CSCLTA_LeCridrBndHeadAng_rad(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch34'/copy1' incorporates:
                                                      *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant92'/Constant'
                                                      *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                      */
        SET_S_CSCLTA_MaxCrvGrdBuildup_1pms(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch35'/copy1' incorporates:
                                                      *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant93'/Constant'
                                                      *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                      */
        SET_S_CSCLTA_MaxCrvGrdRed_1pms(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch36'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant94'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch37'/copy1' incorporates:
                                                       *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant95'/Constant'
                                                       *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                       */
        SET_S_CSCLTA_StrWhStifLimit_nu(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch38'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant3'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_StrWhStifGrad_1ps(100.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch51'/copy1' incorporates:
                                                    *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant4'/Constant'
                                                    *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                    */
        SET_S_CSCLTA_TrqRampGrad_1ps(100.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch52'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant96'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_MaxTrqScalLimit_nu(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch53'/copy1' incorporates:
                                                   *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant1'/Constant'
                                                   *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                   */
        SET_S_CSCLTA_MaxTrqScalGrad_1ps(100.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch19'/copy1' incorporates:
                                                     *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant2'/Constant'
                                                     *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                     */
        SET_S_CSCLTA_HighStatAccu_bool(0U);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch48'/copy1' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant100'/Constant'
                                                *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                */
        SET_S_CSCLTA_LimiterActivated_nu(0U);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch3'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant21'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_LeCridrBndCrv_1pm(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch50'/copy1' incorporates:
                                                  *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant99'/Constant'
                                                  *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                  */
        SET_S_CSCLTA_LimiterTimeDuration_sec(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch54'/copy1' incorporates:
                                                        *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant7'/Constant'
                                                        *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                        */
        SET_S_CSCLTA_MaxJerkAllowed_mps3(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch39'/copy1' incorporates:
                                                    *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant5'/Constant'
                                                    *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                    */
        SET_S_CSCLTA_DeratingLevel_nu(0U);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch4'/copy1' incorporates:
                                                *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant22'/Constant'
                                                *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                */
        SET_S_CSCLTA_LeCridrBndCrvChng_1pm2(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch5'/copy1' incorporates:
                                                       *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant23'/Constant'
                                                       *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                       */
        SET_S_CSCLTA_LeCridrBndLength_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch6'/copy1' incorporates:
                                                     *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant24'/Constant'
                                                     *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                     */
        SET_S_CSCLTA_RiCridrBndPosX0_met(0.0F);
        /* SignalConversion: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/branch7'/copy1' incorporates:
                                                    *  Constant: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA/Signal_Preparation_for_SwitchDefault/Constant25'/Constant'
                                                    *  MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch'
                                                    */
        SET_S_CSCLTA_RiCridrBndPosY0_met(0.0F);
        break;
    }
    /* End of MultiPortSwitch: 'sda:CSCLTA/CSCLTA/CSCLTA_SenProcess/OPM/M_CSCLTA'/Multiport Switch' */
}
#include "Pse_CSCLTA.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
