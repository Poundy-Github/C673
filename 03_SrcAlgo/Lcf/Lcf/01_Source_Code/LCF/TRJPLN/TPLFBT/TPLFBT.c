/**************************************************************************
COPYRIGHT (C) $Date: 2019/07/26 13:26:26CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJPLN/TPLFBT_VEH/TPLFBT/i/project.pj $
$Log: TPLFBT.c  $
Revision 1.7 2019/07/26 13:26:26CEST Zhu, Qiangqiang (uid41532) 
automatically created
File          : TPLFBT
Generated on  : Wed 10.07.2019 at 11:27:05 (UTC+01:00)
MD5           : [1795168555     6123479  4058939160  4072453018 0](TPLFBT)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,79,81,82
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TPLFBT.h"
#include "sda_sil_dummy.h"
#include "TPLFBT_Private.h"
#include "calFrenetBackTransformation.h"
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
#define TPLFBT_START_SEC_DATA_8
#include "TPLFBT_MemMap.h"
static uint8 BI_tplfbt_DataTypeConversion;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/AND/Functionality'/Data Type Conversion' */
static uint8 BI_tplfbt_SignalConversion1_a;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Signal Conversion1' */
static uint8 BI_tplfbt_RelationalOperator1;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Relational Operator1' */
static uint8 DW_tplfbt_Unit_Delay3_DSTATE;
static uint8 DW_tplfbt_Unit_Delay_DSTATE_e;
static uint8 DW_tplfbt_Unit_Delay1_DSTATE_n;
static boolean DW_tplfbt_TargetValueSelection_MODE;
#define TPLFBT_STOP_SEC_DATA_8
#include "TPLFBT_MemMap.h"
#define TPLFBT_START_SEC_DATA_16
#include "TPLFBT_MemMap.h"
static uint16 DW_tplfbt_Unit_Delay_DSTATE_pl;
#define TPLFBT_STOP_SEC_DATA_16
#include "TPLFBT_MemMap.h"
#define TPLFBT_START_SEC_DATA_32
#include "TPLFBT_MemMap.h"
static float32 BI_tplfbt_SignalConversion1;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
static float32 BI_tplfbt_SignalConversion1_d;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
static float32 BI_tplfbt_SignalConversion1_c;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
static float32 BI_tplfbt_SignalConversion1_dg;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
static float32 BI_tplfbt_copy1;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/branch13'/copy1' */
static float32 BI_tplfbt_copy1_k;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/branch14'/copy1' */
static float32 BI_tplfbt_copy1_n;
/* 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/branch15'/copy1' */
static float32 DW_tplfbt_Unit_Delay_DSTATE;
static float32 DW_tplfbt_Unit_Delay1_DSTATE;
static float32 DW_tplfbt_Unit_Delay2_DSTATE;
static float32 DW_tplfbt_Unit_Delay_DSTATE_d;
static float32 DW_tplfbt_Unit_Delay_DSTATE_k;
static float32 DW_tplfbt_Unit_Delay2_DSTATE_f;
static float32 DW_tplfbt_Unit_Delay_DSTATE_p;
static float32 DW_tplfbt_Unit_Delay_DSTATE_m;
#define TPLFBT_STOP_SEC_DATA_32
#include "TPLFBT_MemMap.h"
#define TPLFBT_START_SEC_CONST_SLOW
#include "TPLFBT_MemMap.h"
/* Computed Parameter: Const_bit_sel_param_Value   * Referenced by: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/get_bit1/Functionality'/Const_bit_sel_param'   */
const uint8 CP_tplfbt_Const_bit_sel_param_Value[6] = {0U,1U,2U,3U,4U,5U};
#define TPLFBT_STOP_SEC_CONST_SLOW
#include "TPLFBT_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TPLFBT/TPLFBT/INI'/TPLFBT_VehReset'
 * Block description for: 'sda:TPLFBT/TPLFBT/INI'/TPLFBT_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLFBT_VehReset
#include "Pse_TPLFBT.h"
/* Short description: Not synchronized with ARAMIS */
void TPLFBT_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant'/Constant' */
    SET_S_TPLFBT_TrajHeading_rad(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant1'/Constant' */
    SET_S_TPLFBT_TrajDistY_met(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant10'/Constant' */
    SET_S_TPLFBT_TrajHeadInclPrev_rad(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant11'/Constant' */
    SET_S_TPLFBT_CtrlErrDistY_met(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant12'/Constant' */
    SET_S_TPLFBT_CtrlErrHeadingAngle_rad(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant13'/Constant' */
    SET_S_TPLFBT_CtrlErrHeadAglPrev_rad(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant14'/Constant' */
    SET_D_TPLFBT_QuStatusTrajPlan_nu(0U);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant15'/Constant' */
    SET_D_TPLFBT_DeltaTargetCrv_1pm(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant16'/Constant' */
    SET_D_TPLFBT_DeltaTargetPosY0_met(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant17'/Constant' */
    SET_D_TPLFBT_DeltaTargetHeading_rad(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant18'/Constant' */
    SET_D_TPLFBT_UseTargetCorridor_nu(0U);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant19'/Constant' */
    SET_D_TPLFBT_TargetSwitch_nu(0U);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant2'/Constant' */
    SET_S_TPLFBT_TrajTgtCrv_1pm(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant20'/Constant' */
    SET_D_TPLFBT_GradLimitActive_nu(0U);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant21'/Constant' */
    SET_S_TPLFBT_QuStatusTrajPlan_nu(0U);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant22'/Constant' */
    SET_D_TPLFBT_TrajTgtCrvGrdPrev_1pms(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant24'/Constant' */
    SET_D_TPLFBT_TgtCorridorCrv_1pm(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant25'/Constant' */
    SET_D_TPLFBT_TgtCorridorCrvGrd_1pms(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant26'/Constant' */
    SET_D_TPLFBT_TgtTrjCrvPrvwDT_1pm(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant27'/Constant' */
    SET_D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant28'/Constant' */
    SET_D_TPLFBT_TrajHeadingPrvw_rad(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant29'/Constant' */
    SET_D_TPLFBT_TrajPlanInvalid_nu(0U);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant4'/Constant' */
    SET_D_TPLFBT_PlausiCheckStatus_nu(0U);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant5'/Constant' */
    SET_S_TPLFBT_TrajHeadingPrev_rad(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant6'/Constant' */
    SET_S_TPLFBT_TrajDistYPrev_met(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant7'/Constant' */
    SET_S_TPLFBT_TrajTgtCrvPrev_1pm(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant8'/Constant' */
    SET_S_TPLFBT_CurHeading_rad(0.0F);
    /* Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/Constant9'/Constant' */
    SET_S_TPLFBT_CurDistY_met(0.0F);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/from_data_definition'/Signal Conversion3' incorporates:
                                            *  Constant: 'sda:TPLFBT/TPLFBT/INI/TPLFBT_VehReset/from_data_definition'/state_source'
                                            */
    SET_S_TPLFBT_TrajGuiQualifier_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
}
#include "Pse_TPLFBT.h"
/*
 * Output and update for function-call system: 'sda:TPLFBT/TPLFBT'/TPLFBT_VehProcess'
 * Block description for: 'sda:TPLFBT/TPLFBT'/TPLFBT_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLFBT_VehProcess
#include "Pse_TPLFBT.h"
/* Short description: Not synchronized with ARAMIS */
void TPLFBT_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    calFBTInType rtb_FBTInputStruct;
    calFBTOutType rtb_sfun_calFrenetBackTransformation;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    uint16 rtb_sfun_setbit;
    uint16 rtb_sfun_setbit_k;
    uint16 rtb_sfun_setbit_o;
    uint16 rtb_sfun_setbit_a;
    uint8 rtb_NE_o;
    uint8 rtb_SFunction[6];
    uint8 rtb_NE_i;
    uint8 rtb_VectorConcatenate[2];
    uint8 rtb_sfun_setbit_n;
    float32 rtb_Switch;
    uint8 rtb_DataTypeConversion_b;
    uint8 rtb_NE_p;
    float32 rtb_Sum_k;
    float32 rtb_Sum_e;
    float32 rtb_Sum_g4;
    float32 rtb_Sum_c4;
    uint8 rtb_Switch_pn;
    uint16 rtb_Switch_j;
    uint16 rtb_Switch_ns;
    float32 rtb_Switch_g2;
    float32 rtb_Mul_ai;
    float32 rtb_Mul_a;
    float32 rtb_Sum_p;
    float32 rtb_Switch_ok;
    float32 rtb_Mul_dz;
    float32 rtb_Mul_l;
    float32 rtb_Mul_m;
    /* Outputs for Atomic SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM'/M_TPLFBT' */
    /* BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTInputStruct' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Constant2'/Constant'
         *  Inport: '<Root>/S_TPLCEN_ReplanModeArcLength_nu'
         *  Inport: '<Root>/S_TPLCEN_TrajPlanEnbl_nu'
         *  Inport: '<Root>/S_TPLFRT_CurDistY1stToPrev_mps'
         *  Inport: '<Root>/S_TPLFRT_CurDistYPreview_met'
         *  Inport: '<Root>/S_TPLFRT_TrajAclRefCurve_mps2'
         *  Inport: '<Root>/S_TPLFRT_TrajVelRefCurve_mps'
         *  Inport: '<Root>/S_TPLLCO_DevDistY_met'
         *  Inport: '<Root>/S_TPLLCO_DevHeading_rad'
         *  Inport: '<Root>/S_TPLLCO_RiCridrChngOfCrv_1pm2'
         *  Inport: '<Root>/S_TPLLCO_RightCorridorCrv_1pm'
         *  Inport: '<Root>/S_TPLTJC_QuStatusTrajPlan_nu'
         *  Inport: '<Root>/S_TPLTJC_TrajDistY1stDeriv_mps'
         *  Inport: '<Root>/S_TPLTJC_TrajDistY2ndDeriv_mps2'
         *  Inport: '<Root>/S_TPLTJC_TrajDistY3rdDeriv_mps3'
         *  Inport: '<Root>/S_TPLTJC_TrajDistY_met'
         *  Inport: '<Root>/S_TPLTJC_YDt2TrjFmKpPrevDT_mps2'
         *  Inport: '<Root>/S_TPLTJC_YDt2TrjFmKpPrev_mps2'
         *  Inport: '<Root>/S_TPLTJC_YDt3TrjFmKpPrevDT_mps3'
         *  Inport: '<Root>/S_TPLTJC_YDtTrjFmHeadPrev_mps'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/NEQ/Functionality'/NE'
         */
    rtb_FBTInputStruct.sfunc_NoTrajFound_nu = (uint8)(((sint32) GET_S_TPLTJC_QuStatusTrajPlan_nu()) != 0);
    rtb_FBTInputStruct.sfunc_TPLFBT_TrajGuiEnable_nu = GET_S_TPLCEN_TrajPlanEnbl_nu();
    rtb_FBTInputStruct.sfunc_TPLFBT_CridrRightSeg1_Crv_1pm = GET_S_TPLLCO_RightCorridorCrv_1pm();
    rtb_FBTInputStruct.sfunc_TPLFBT_CridrRightSeg1_ChngOfCrv_1pm2 = GET_S_TPLLCO_RiCridrChngOfCrv_1pm2();
    rtb_FBTInputStruct.sfunc_TPLFBT_TrajDistY_met = GET_S_TPLTJC_TrajDistY_met();
    rtb_FBTInputStruct.sfunc_TPLFBT_TrajDistY1stDeriv_nu = GET_S_TPLTJC_TrajDistY1stDeriv_mps();
    rtb_FBTInputStruct.sfunc_TPLFBT_TrajDistY2ndDeriv_nu = GET_S_TPLTJC_TrajDistY2ndDeriv_mps2();
    rtb_FBTInputStruct.sfunc_TPLFBT_TrajDistY3rdDeriv_nu = GET_S_TPLTJC_TrajDistY3rdDeriv_mps3();
    rtb_FBTInputStruct.sfunc_TPLFBT_TrajVelRefCurve_mps = GET_S_TPLFRT_TrajVelRefCurve_mps();
    rtb_FBTInputStruct.sfunc_TPLFBT_TrajAclRefCurve_mps2 = GET_S_TPLFRT_TrajAclRefCurve_mps2();
    rtb_FBTInputStruct.sfunc_ReplanModeArcLength_nu = GET_S_TPLCEN_ReplanModeArcLength_nu();
    rtb_FBTInputStruct.sfunc_DistYCurValuePreview_met = GET_S_TPLFRT_CurDistYPreview_met();
    rtb_FBTInputStruct.sfunc_DistY1stDerivCurValuePreview_mps = GET_S_TPLFRT_CurDistY1stToPrev_mps();
    rtb_FBTInputStruct.sfunc_DevHeading_rad = GET_S_TPLLCO_DevHeading_rad();
    rtb_FBTInputStruct.sfunc_DevDistY_met = GET_S_TPLLCO_DevDistY_met();
    rtb_FBTInputStruct.sfunc_YDotTrajFromHeadingPreview_nu = GET_S_TPLTJC_YDtTrjFmHeadPrev_mps();
    rtb_FBTInputStruct.sfunc_YDot2TrajFromKappaPrevAndDT_nu = GET_S_TPLTJC_YDt2TrjFmKpPrevDT_mps2();
    rtb_FBTInputStruct.sfunc_YDot3TrajFromKappaPrevAndDT_nu = GET_S_TPLTJC_YDt3TrjFmKpPrevDT_mps3();
    rtb_FBTInputStruct.sfunc_YDotDotTrajFromKappaPreview_nu = GET_S_TPLTJC_YDt2TrjFmKpPrev_mps2();
    /* S-Function (sfun_calFrenetBackTransformation): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/sfun_calFrenetBackTransformation' */
    rtb_sfun_calFrenetBackTransformation = calFrenetBackTransformation ((calFBTInType*)&rtb_FBTInputStruct);
    /* DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Constant'/Constant'
         *  Inport: '<Root>/S_TPLCEN_TrigTrajReplan_nu'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/OR/Functionality'/OR'
         */
    rtb_sfun_setbit_n = (uint8)((((sint32)GET_S_TPLCEN_TrigTrajReplan_nu()) != 0) || (((sint32)GET_P_TPLFBT_CrvPredictionEnbl_nu()) != 0));
    /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TPLCEN_DelayVehGui_sec'
         *  Inport: '<Root>/S_TPLCEN_PredictionTimeCrv_sec'
         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview'/Unit_Delay'
         */
    if (((sint32)rtb_sfun_setbit_n) != 0) {
        rtb_Switch = GET_S_TPLCEN_PredictionTimeCrv_sec() + GET_S_TPLCEN_DelayVehGui_sec();
    } else {
        rtb_Switch = DW_tplfbt_Unit_Delay_DSTATE;
    }
    /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Add/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Conv_TgtKappa_from_ClothoidModel/Constant'/Constant'
         *  Inport: '<Root>/S_TPLFRT_TrajVelRefCurve_mps'
         *  Inport: '<Root>/S_TPLLCO_TargetCorridorCrv_1pm'
         *  Inport: '<Root>/S_TPLLCO_TargetCorridorPosX0_met'
         *  Inport: '<Root>/S_TPLLCO_TargetCridrLength_met'
         *  Inport: '<Root>/S_TPLLCO_TgtCridrChngOfCrv_1pm2'
         *  MinMax: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/MinMax3/Functionality'/Min'
         *  Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Conv_TgtKappa_from_ClothoidModel/Product/Functionality'/Mul'
         *  Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Product/Functionality'/Mul'
         *  Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Product12/Functionality'/Mul'
         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Conv_TgtKappa_from_ClothoidModel/Add/Functionality'/Sum'
         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Conv_TgtKappa_from_ClothoidModel/Add1/Functionality'/Sum'
         */
    rtb_Sum_k = (((0.0F - GET_S_TPLLCO_TargetCorridorPosX0_met()) * GET_S_TPLLCO_TgtCridrChngOfCrv_1pm2()) + GET_S_TPLLCO_TargetCorridorCrv_1pm()) + (f32_min_f32_f32 (GET_S_TPLLCO_TargetCridrLength_met(), rtb_Switch * GET_S_TPLFRT_TrajVelRefCurve_mps()) * GET_S_TPLLCO_TgtCridrChngOfCrv_1pm2());
    /* Outputs for Enabled SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/TargetValueSelection' incorporates:
         *  EnablePort: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/Enable'
         *
         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/TargetValueSelection':
         *  .3
         */
    /* Inport: '<Root>/S_TPLCEN_TrajPlanEnbl_nu' */
    if (((sint32)GET_S_TPLCEN_TrajPlanEnbl_nu()) > 0) {
        if (!((sint32)DW_tplfbt_TargetValueSelection_MODE)) {
            DW_tplfbt_TargetValueSelection_MODE = (uint8)1U;
        }
        /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Sum4/Functionality'/Sum' incorporates:
                 *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                 */
        rtb_Sum_e = rtb_sfun_calFrenetBackTransformation.sfunc_TgtCrvInclPreviewAndDeadTime_1pm - rtb_Sum_k;
        /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Sum/Functionality'/Sum' incorporates:
                 *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                 *  Inport: '<Root>/S_TPLLCO_TargetPathY0_met'
                 */
        rtb_Sum_g4 = rtb_sfun_calFrenetBackTransformation.sfunc_TrajDistY_met - GET_S_TPLLCO_TargetPathY0_met();
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant14'/Constant'
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant15'/Constant'
                 *  Inport: '<Root>/S_TPLLCO_TargetPathHeading_rad'
                 */
        if (((sint32)GET_P_TPLFBT_UseTgtCridrHeading_nu()) != 0) {
            rtb_Sum_c4 = GET_S_TPLLCO_TargetPathHeading_rad();
        } else {
            rtb_Sum_c4 = 0.0F;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch8/Functionality'/Switch' */
        /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Sum2/Functionality'/Sum' incorporates:
                 *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                 */
        rtb_Sum_c4 = rtb_sfun_calFrenetBackTransformation.sfunc_TrajHeadingInclPreview_rad - rtb_Sum_c4;
        /* DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/AND/Functionality'/Data Type Conversion' incorporates:
                 *  Abs: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Abs/Functionality'/Abs'
                 *  Abs: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Abs2/Functionality'/Abs'
                 *  Abs: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Abs4/Functionality'/Abs'
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant1'/Constant'
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant2'/Constant'
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant3'/Constant'
                 *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/AND/Functionality'/AND'
                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/LE/Functionality'/LE'
                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/LE1/Functionality'/LE'
                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/LE2/Functionality'/LE'
                 */
        BI_tplfbt_DataTypeConversion = (uint8)(((f32_abs_f32(rtb_Sum_e) <= GET_P_TPLFBT_DeltaTargetCrv_1pm()) && (f32_abs_f32(rtb_Sum_g4) <= GET_P_TPLFBT_DeltaTargetPosY0_met())) && (f32_abs_f32(rtb_Sum_c4) <= GET_P_TPLFBT_DeltaTargetHeading_rad()));
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Constant'
                 *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
                 *  Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Switch1'
                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/Unit_Delay'
                 */
        if (((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0) {
            rtb_Switch_pn = 0U;
        } else if (((sint32)BI_tplfbt_DataTypeConversion) != 0) {
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Constant1'
                         */
            rtb_Switch_pn = 1U;
        } else {
            rtb_Switch_pn = DW_tplfbt_Unit_Delay_DSTATE_e;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Switch' */
        /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Signal Conversion1' */
        BI_tplfbt_SignalConversion1_a = rtb_Switch_pn;
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch/Functionality'/Switch' incorporates:
                 *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                 */
        if (((sint32)BI_tplfbt_SignalConversion1_a) != 0) {
            rtb_Switch_g2 = rtb_Sum_k;
        } else {
            rtb_Switch_g2 = rtb_sfun_calFrenetBackTransformation.sfunc_TgtCrvInclPreviewAndDeadTime_1pm;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch/Functionality'/Switch' */
        /* Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/RSFLIPFLOP/Functionality'/Logical Operator' */
        rtb_Switch_pn = (uint8)(!(((sint32)rtb_Switch_pn) != 0));
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Y_TPLFBT_GradLimitCrvFactor_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        if (((sint32)rtb_Switch_pn) == 0) {
            /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter'/Unit_Delay'
                         */
            rtb_Sum_p = rtb_Switch_g2 - DW_tplfbt_Unit_Delay_DSTATE_d;
            /* S-Function Block sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Y_TPLFBT_GradLimitCrvFactor_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_TPLFBT_VehVelX_mps */
                FDPS_PTR_F32(GETA_X_TPLFBT_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D (GETA_Y_TPLFBT_GradLimitCrvFactor_nu(), &dps_result_ln);
            }
            /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Mul1/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant8'/Constant'
                         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                         *  Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Mul/Functionality'/Mul'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Y_TPLFBT_GradLimitCrvFactor_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                         */
            rtb_Mul_ai = (GET_P_TPLFBT_GradLimitCrv_1pm2() * GET_S_LCFRCV_VehVelX_mps()) * rtb_ip_lookup_fxpt_sfun_7;
            /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         */
            rtb_Mul_a = rtb_Mul_ai * GET_S_LCFRCV_SysCycleTimeVeh_sec();
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter'/Unit_Delay'
                         */
            if (rtb_Sum_p > rtb_Mul_a) {
                rtb_Switch_g2 = rtb_Mul_a + DW_tplfbt_Unit_Delay_DSTATE_d;
            } else {
                /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                                 *  UnaryMinus: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/Neg/Functionality'/Unary Minus'
                                 */
                rtb_Mul_ai = (-rtb_Mul_ai) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
                /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                                 *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter'/Unit_Delay'
                                 */
                if (rtb_Sum_p < rtb_Mul_ai) {
                    rtb_Switch_g2 = rtb_Mul_ai + DW_tplfbt_Unit_Delay_DSTATE_d;
                }
                /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
        /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
        BI_tplfbt_SignalConversion1 = rtb_Switch_g2;
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch1/Functionality'/Switch' incorporates:
                 *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                 *  Inport: '<Root>/S_TPLLCO_TargetPathY0_met'
                 */
        if (((sint32)BI_tplfbt_SignalConversion1_a) != 0) {
            rtb_Sum_p = GET_S_TPLLCO_TargetPathY0_met();
        } else {
            rtb_Sum_p = rtb_sfun_calFrenetBackTransformation.sfunc_TrajDistY_met;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch1/Functionality'/Switch' */
        /* S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality'/Comparison'
                 */
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant7'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality'/Logical Operator2'
                 *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality/Comparison'/Logical Operator'
                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
                 *  Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Switch2'
                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/Unit_Delay1'
                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/Unit_Delay2'
                 */
        if ((!(((sint32)DW_tplfbt_Unit_Delay1_DSTATE_n) != 0)) && (((sint32) BI_tplfbt_SignalConversion1_a) != 0)) {
            rtb_Mul_ai = GET_P_TPLFBT_DurationGradLimit_sec();
        } else if (DW_tplfbt_Unit_Delay2_DSTATE_f > GET_S_LCFRCV_SysCycleTimeVeh_sec()) {
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/Unit_Delay2'
                         */
            rtb_Mul_ai = DW_tplfbt_Unit_Delay2_DSTATE_f - GET_S_LCFRCV_SysCycleTimeVeh_sec();
        } else {
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Constant2'
                         */
            rtb_Mul_ai = 0.0F;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Switch' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING'/fcg' */
        /* RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Relational Operator1' incorporates:
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/TIMERRETRIGGER_RE/Functionality'/Constant'
                 */
        BI_tplfbt_RelationalOperator1 = (uint8)(rtb_Mul_ai > 0.0F);
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
        if (((sint32)rtb_Switch_pn) == 0) {
            /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY'/Unit_Delay'
                         */
            rtb_Mul_a = rtb_Sum_p - DW_tplfbt_Unit_Delay_DSTATE_k;
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch5/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant4'/Constant'
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant9'/Constant'
                         */
            if (((sint32)BI_tplfbt_RelationalOperator1) != 0) {
                rtb_Switch_ok = GET_P_TPLFBT_GradLimitPosY_mps();
            } else {
                rtb_Switch_ok = GET_P_TPLFBT_GradLimitPosYHigh_mps();
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch5/Functionality'/Switch' */
            /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         */
            rtb_Mul_dz = rtb_Switch_ok * GET_S_LCFRCV_SysCycleTimeVeh_sec();
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY'/Unit_Delay'
                         */
            if (rtb_Mul_a > rtb_Mul_dz) {
                rtb_Sum_p = rtb_Mul_dz + DW_tplfbt_Unit_Delay_DSTATE_k;
            } else {
                /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                                 *  UnaryMinus: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/Neg/Functionality'/Unary Minus'
                                 */
                rtb_Switch_ok = (-rtb_Switch_ok) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
                /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                                 *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY'/Unit_Delay'
                                 */
                if (rtb_Mul_a < rtb_Switch_ok) {
                    rtb_Sum_p = rtb_Switch_ok + DW_tplfbt_Unit_Delay_DSTATE_k;
                }
                /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
        /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
        BI_tplfbt_SignalConversion1_d = rtb_Sum_p;
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch2/Functionality'/Switch' incorporates:
                 *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                 */
        if (((sint32)BI_tplfbt_SignalConversion1_a) != 0) {
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant18'/Constant'
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant19'/Constant'
                         *  Inport: '<Root>/S_TPLLCO_TargetPathHeading_rad'
                         */
            if (((sint32)GET_P_TPLFBT_UseTgtCridrHeading_nu()) != 0) {
                rtb_Mul_a = GET_S_TPLLCO_TargetPathHeading_rad();
            } else {
                rtb_Mul_a = 0.0F;
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch10/Functionality'/Switch' */
        } else {
            rtb_Mul_a = rtb_sfun_calFrenetBackTransformation.sfunc_TrajHeadingInclPreview_rad;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch2/Functionality'/Switch' */
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
        if (((sint32)rtb_Switch_pn) == 0) {
            /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading'/Unit_Delay'
                         */
            rtb_Switch_ok = rtb_Mul_a - DW_tplfbt_Unit_Delay_DSTATE_p;
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant10'/Constant'
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant5'/Constant'
                         */
            if (((sint32)BI_tplfbt_RelationalOperator1) != 0) {
                rtb_Mul_dz = GET_P_TPLFBT_GradLimitHead_rps();
            } else {
                rtb_Mul_dz = GET_P_TPLFBT_GradLimitHeadHigh_rps();
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch6/Functionality'/Switch' */
            /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         */
            rtb_Mul_l = rtb_Mul_dz * GET_S_LCFRCV_SysCycleTimeVeh_sec();
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading'/Unit_Delay'
                         */
            if (rtb_Switch_ok > rtb_Mul_l) {
                rtb_Mul_a = rtb_Mul_l + DW_tplfbt_Unit_Delay_DSTATE_p;
            } else {
                /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                                 *  UnaryMinus: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/Neg/Functionality'/Unary Minus'
                                 */
                rtb_Mul_dz = (-rtb_Mul_dz) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
                /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                                 *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading'/Unit_Delay'
                                 */
                if (rtb_Switch_ok < rtb_Mul_dz) {
                    rtb_Mul_a = rtb_Mul_dz + DW_tplfbt_Unit_Delay_DSTATE_p;
                }
                /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
        /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
        BI_tplfbt_SignalConversion1_c = rtb_Mul_a;
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch3/Functionality'/Switch' incorporates:
                 *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                 */
        if (((sint32)BI_tplfbt_SignalConversion1_a) != 0) {
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch9/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant16'/Constant'
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant17'/Constant'
                         *  Inport: '<Root>/S_TPLLCO_TargetPathHeading_rad'
                         */
            if (((sint32)GET_P_TPLFBT_UseTgtCridrHeading_nu()) != 0) {
                rtb_Switch_ok = GET_S_TPLLCO_TargetPathHeading_rad();
            } else {
                rtb_Switch_ok = 0.0F;
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch9/Functionality'/Switch' */
        } else {
            rtb_Switch_ok = rtb_sfun_calFrenetBackTransformation.sfunc_TrajHeading_rad;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch3/Functionality'/Switch' */
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
        if (((sint32)rtb_Switch_pn) == 0) {
            /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1'/Unit_Delay'
                         */
            rtb_Mul_dz = rtb_Switch_ok - DW_tplfbt_Unit_Delay_DSTATE_m;
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant11'/Constant'
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Constant6'/Constant'
                         */
            if (((sint32)BI_tplfbt_RelationalOperator1) != 0) {
                rtb_Mul_l = GET_P_TPLFBT_GradLimitHead_rps();
            } else {
                rtb_Mul_l = GET_P_TPLFBT_GradLimitHeadHigh_rps();
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/Switch7/Functionality'/Switch' */
            /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         */
            rtb_Mul_m = rtb_Mul_l * GET_S_LCFRCV_SysCycleTimeVeh_sec();
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1'/Unit_Delay'
                         */
            if (rtb_Mul_dz > rtb_Mul_m) {
                rtb_Switch_ok = rtb_Mul_m + DW_tplfbt_Unit_Delay_DSTATE_m;
            } else {
                /* Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                                 *  UnaryMinus: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/Neg/Functionality'/Unary Minus'
                                 */
                rtb_Mul_l = (-rtb_Mul_l) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
                /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                                 *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1'/Unit_Delay'
                                 */
                if (rtb_Mul_dz < rtb_Mul_l) {
                    rtb_Switch_ok = rtb_Mul_l + DW_tplfbt_Unit_Delay_DSTATE_m;
                }
                /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
            }
            /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
        /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
        BI_tplfbt_SignalConversion1_dg = rtb_Switch_ok;
        /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/branch13'/copy1' */
        BI_tplfbt_copy1 = rtb_Sum_e;
        /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/branch14'/copy1' */
        BI_tplfbt_copy1_k = rtb_Sum_g4;
        /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/branch15'/copy1' */
        BI_tplfbt_copy1_n = rtb_Sum_c4;
        /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/Unit_Delay' */
        DW_tplfbt_Unit_Delay_DSTATE_e = BI_tplfbt_SignalConversion1_a;
        /* S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality'/SignalConversion'
                 */
        /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/Unit_Delay1' incorporates:
                 *  SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
                 */
        DW_tplfbt_Unit_Delay1_DSTATE_n = BI_tplfbt_SignalConversion1_a;
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/EDGERISING'/fcg' */
        /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiter'/Unit_Delay' */
        DW_tplfbt_Unit_Delay_DSTATE_d = rtb_Switch_g2;
        /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterDisY'/Unit_Delay' */
        DW_tplfbt_Unit_Delay_DSTATE_k = rtb_Sum_p;
        /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/Unit_Delay2' */
        DW_tplfbt_Unit_Delay2_DSTATE_f = rtb_Mul_ai;
        /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading'/Unit_Delay' */
        DW_tplfbt_Unit_Delay_DSTATE_p = rtb_Mul_a;
        /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection/GradientLimiterHeading1'/Unit_Delay' */
        DW_tplfbt_Unit_Delay_DSTATE_m = rtb_Switch_ok;
    } else {
        if (DW_tplfbt_TargetValueSelection_MODE) {
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/S_TPLFBT_TrajDistY_met'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/S_TPLFBT_TrajDistY_met':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_SignalConversion1_d = 0.0F;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/S_TPLFBT_TrajHeadInclPrev_rad'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/S_TPLFBT_TrajHeadInclPrev_rad':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_SignalConversion1_c = 0.0F;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/S_TPLFBT_TrajHeading_rad'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/S_TPLFBT_TrajHeading_rad':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_SignalConversion1_dg = 0.0F;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/S_TPLFBT_TrajTgtCrv_1pm'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/S_TPLFBT_TrajTgtCrv_1pm':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_SignalConversion1 = 0.0F;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_DeltaTargetCrv_1pm'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_DeltaTargetCrv_1pm':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_copy1 = 0.0F;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_DeltaTargetPosY0_met'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_DeltaTargetPosY0_met':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_copy1_k = 0.0F;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_DeltaTargetHeading_rad'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_DeltaTargetHeading_rad':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_copy1_n = 0.0F;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_UseTargetCorridor_nu'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_UseTargetCorridor_nu':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_SignalConversion1_a = 0U;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_TargetSwitch_nu'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_TargetSwitch_nu':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_DataTypeConversion = 0U;
            /* Disable for Outport: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_GradLimitActive_nu'
                         *
                         * Block description for 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/TargetValueSelection'/D_TPLFBT_GradLimitActive_nu':
                         *
                         *  FAS35up.Name=TrajPlanFrenetBackTrafo_CurDistY_met
                         */
            BI_tplfbt_RelationalOperator1 = 0U;
            DW_tplfbt_TargetValueSelection_MODE = (uint8)0U;
        }
    }
    /* End of Outputs for SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/TargetValueSelection' */
    /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Add1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TPLLCO_DevDistY_met'
         */
    SET_S_TPLFBT_CtrlErrDistY_met(BI_tplfbt_SignalConversion1_d - GET_S_TPLLCO_DevDistY_met());
    /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Add2/Functionality'/Sum' incorporates:
                                            *  Inport: '<Root>/S_TPLLCO_DevHeading_rad'
                                            */
    SET_S_TPLFBT_CtrlErrHeadingAngle_rad(BI_tplfbt_SignalConversion1_dg - GET_S_TPLLCO_DevHeading_rad());
    /* Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Add3/Functionality'/Sum' incorporates:
                                            *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                            */
    SET_S_TPLFBT_CtrlErrHeadAglPrev_rad(BI_tplfbt_SignalConversion1_c - rtb_sfun_calFrenetBackTransformation.sfunc_HeadingCurValuePreview_rad);
    /* DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/AND/Functionality'/Data Type Conversion' incorporates:
                                                                          *  Inport: '<Root>/S_TPLLCO_DevDistY_met'
                                                                          *  Inport: '<Root>/S_TPLLCO_LeftCorridorPosY0_met'
                                                                          *  Inport: '<Root>/S_TPLLCO_RightCorridorPosY0_met'
                                                                          *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/AND/Functionality'/AND'
                                                                          *  MinMax: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/Max/Functionality'/Max'
                                                                          *  MinMax: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/Min/Functionality'/Min'
                                                                          *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/GE/Functionality'/GE'
                                                                          *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/GE1/Functionality'/GE'
                                                                          */
    rtb_sfun_setbit_n = (uint8)((f32_max_f32_f32 (GET_S_TPLLCO_LeftCorridorPosY0_met(), GET_S_TPLLCO_DevDistY_met()) >= BI_tplfbt_SignalConversion1_d) && (BI_tplfbt_SignalConversion1_d >= f32_min_f32_f32 (GET_S_TPLLCO_DevDistY_met(), GET_S_TPLLCO_RightCorridorPosY0_met())));
    /* DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate[0] = (uint8)(!(((sint32)rtb_sfun_setbit_n) != 0));
    /* DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/from_data_definition'/state_source'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/EQ1/Functionality'/EQ'
         */
    rtb_sfun_setbit_n = (uint8)((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ))));
    /* DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/EQ2/Functionality'/EQ'
         */
    rtb_sfun_setbit_n = (uint8)((((sint32)rtb_sfun_setbit_n) != 0) && (((sint32) GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))));
    /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/Constant'/Constant'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/Constant1'/Constant'
         */
    if (((sint32)rtb_sfun_setbit_n) != 0) {
        rtb_Sum_c4 = GET_P_TPLFBT_HeadCheckTolOBF_rad();
    } else {
        rtb_Sum_c4 = GET_P_TPLFBT_HeadCheckTolerance_rad();
    }
    /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/GE2/Functionality'/GE' incorporates:
         *  Abs: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/Abs/Functionality'/Abs'
         *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
         *  Inport: '<Root>/S_CSCLTA_RiCridrBndHeadAng_rad'
         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/Sum/Functionality'/Sum'
         */
    rtb_VectorConcatenate[1] = (uint8)(f32_abs_f32 (GET_S_CSCLTA_RiCridrBndHeadAng_rad() + rtb_sfun_calFrenetBackTransformation.sfunc_HeadingCurValuePreview_rad) >= rtb_Sum_c4);
    /* S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Tgt_DistY_and Current_Heading_Plausi_Check/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[2] = { 0U, 1U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate[0];
                for (i1=0; i1 < 2; i1++) {
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
    /* RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/NEQ2/Functionality'/NE' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant12'/Constant'
         */
    rtb_NE_o = (uint8)(((sint32)rtb_sfun_setbit_n) != 0);
    /* DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/from_data_definition'/state_source'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_b = (uint8)((((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)) == ((sint32) GET_S_CSCLTA_SysStateLCF_enum())) || (((sint32)GET_S_CSCLTA_SysStateLCF_enum ()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))));
    /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant5'/Constant'
         */
    if (((sint32)rtb_DataTypeConversion_b) != 0) {
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant10'/Constant'
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant11'/Constant'
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/get_bit1/Functionality'/Const_bit_sel_param'
                 *  Inport: '<Root>/S_TPLLCO_PlausiCheckStatus_nu'
                 *  Inport: '<Root>/S_TPLTJC_QuStatusTrajPlan_nu'
                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/NEQ1/Functionality'/NE'
                 *  S-Function (sfun_getbit_77): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/get_bit1/Functionality'/S-Function'
                 *  S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/set_bit1/Functionality'/sfun_setbit'
                 *  S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/set_bit2/Functionality'/sfun_setbit'
                 *  S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/set_bit3/Functionality'/sfun_setbit'
                 *  S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/set_bit4/Functionality'/sfun_setbit'
                 */
        if (((sint32)GET_P_TPLFBT_UseLongQuStatus_nu()) != 0) {
            /* S-Function (sfun_getbit_77): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/get_bit1/Functionality'/S-Function' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/get_bit1/Functionality'/Const_bit_sel_param'
                         */
            {
                sint32 index;
                for (index=0; index < 6; index++) {
                    rtb_SFunction[index] = flag_get_u8_u8 (GET_S_TPLLCO_PlausiCheckStatus_nu(), (CP_tplfbt_Const_bit_sel_param_Value[index]));
                }
            }
            /* S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/set_bit1/Functionality'/sfun_setbit' */
            {
                /* mask selection vector from setbit block */
                uint16 temp = GET_S_TPLTJC_QuStatusTrajPlan_nu();
                if (!rtb_NE_o) {
                    /* reset */
                    temp = temp & (~u16_bit_u8( (uint8) 9U));
                } else {
                    /* set */
                    temp = temp | u16_bit_u8( (uint8) 9U);
                }
                rtb_sfun_setbit = temp;
            }
            /* S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/set_bit2/Functionality'/sfun_setbit' */
            {
                /* mask selection vector from setbit block */
                uint16 temp = rtb_sfun_setbit;
                {
                    uint16 set_mask = 0;
                    uint16 reset_mask = 0;
                    const uint8 selection_vec[6] = { 10U, 11U, 12U, 13U, 14U, 15U };
                    {
                        sint32 i1;
                        const uint8 *u1 = rtb_SFunction;
                        for (i1=0; i1 < 6; i1++) {
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
                rtb_sfun_setbit_k = temp;
            }
            rtb_Switch_j = rtb_sfun_setbit_k;
        } else {
            /* RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/NEQ1/Functionality'/NE' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant11'/Constant'
                         *  Inport: '<Root>/S_TPLTJC_QuStatusTrajPlan_nu'
                         */
            rtb_NE_i = (uint8)(((sint32)GET_S_TPLTJC_QuStatusTrajPlan_nu()) != 0);
            /* S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/set_bit3/Functionality'/sfun_setbit' */
            {
                /* mask selection vector from setbit block */
                uint16 temp = GET_S_TPLLCO_PlausiCheckStatus_nu();
                if (!rtb_NE_o) {
                    /* reset */
                    temp = temp & (~u16_bit_u8( (uint8) 6U));
                } else {
                    /* set */
                    temp = temp | u16_bit_u8( (uint8) 6U);
                }
                rtb_sfun_setbit_o = temp;
            }
            /* S-Function (sfun_setbit): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/set_bit4/Functionality'/sfun_setbit' */
            {
                /* mask selection vector from setbit block */
                uint16 temp = rtb_sfun_setbit_o;
                if (!rtb_NE_i) {
                    /* reset */
                    temp = temp & (~u16_bit_u8( (uint8) 7U));
                } else {
                    /* set */
                    temp = temp | u16_bit_u8( (uint8) 7U);
                }
                rtb_sfun_setbit_a = temp;
            }
            rtb_Switch_j = rtb_sfun_setbit_a;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch5/Functionality'/Switch' */
    } else {
        rtb_Switch_j = 0U;
    }
    /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/NEQ3/Functionality'/NE' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant7'/Constant'
         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay'
         */
    rtb_NE_p = (uint8)(((sint32)DW_tplfbt_Unit_Delay_DSTATE_pl) != 0);
    /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant8'/Constant'
         *  DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/DTC'/Data Type Conversion'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/NOT2/Functionality'/NOT'
         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay'
         */
    if (!(((sint32)GET_P_TPLFBT_HoldAllBits_nu()) != 0)) {
        rtb_Switch_pn = rtb_NE_p;
    } else {
        rtb_Switch_pn = u8_u16(DW_tplfbt_Unit_Delay_DSTATE_pl);
    }
    /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch2/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant1'/Constant'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE1/Functionality'/Switch'
         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay1'
         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay3'
         */
    if ((!(((sint32)DW_tplfbt_Unit_Delay3_DSTATE) != 0)) && (((sint32)rtb_Switch_pn) != 0)) {
        rtb_Sum_e = GET_P_TPLFBT_MaxQuStatusHold_sec();
        rtb_Sum_g4 = GET_P_TPLFBT_MinQuStatusHold_sec();
    } else {
        if (DW_tplfbt_Unit_Delay1_DSTATE > GET_S_LCFRCV_SysCycleTimeVeh_sec()) {
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay1'
                         */
            rtb_Sum_e = DW_tplfbt_Unit_Delay1_DSTATE - GET_S_LCFRCV_SysCycleTimeVeh_sec();
        } else {
            /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Constant2'
                         */
            rtb_Sum_e = 0.0F;
        }
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                 *  Sum: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay2'
                 */
        if (DW_tplfbt_Unit_Delay2_DSTATE > GET_S_LCFRCV_SysCycleTimeVeh_sec()) {
            rtb_Sum_g4 = DW_tplfbt_Unit_Delay2_DSTATE - GET_S_LCFRCV_SysCycleTimeVeh_sec ();
        } else {
            rtb_Sum_g4 = 0.0F;
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
    }
    /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING'/fcg' */
    /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant6'/Constant'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/AND1/Functionality'/AND'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         */
    if ((((((sint32)GET_P_TPLFBT_QuStatusHold_nu()) != 0) && (((sint32)rtb_NE_p) != 0)) && (rtb_Sum_e > 0.0F)) && ((rtb_Sum_g4 > 0.0F) || (((sint32) rtb_DataTypeConversion_b) != 0))) {
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant9'/Constant'
                 *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/NOT1/Functionality'/NOT'
                 *  S-Function (sfix_bitop): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/OR2/Functionality'/OR'
                 *  UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay'
                 */
        if (!(((sint32)GET_P_TPLFBT_HoldAllBits_nu()) != 0)) {
            rtb_Switch_ns = DW_tplfbt_Unit_Delay_DSTATE_pl;
        } else {
            rtb_Switch_ns = (uint16)(((sint32)DW_tplfbt_Unit_Delay_DSTATE_pl) | ((sint32)rtb_Switch_j));
        }
        /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch3/Functionality'/Switch' */
    } else {
        rtb_Switch_ns = rtb_Switch_j;
    }
    /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant'/Constant'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/Constant2'/Constant'
         *  S-Function (sfix_bitop): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_b = (uint8)((((sint32)rtb_Switch_ns) & ((sint32) GET_P_TPLFBT_CheckTrajPlanStatus_nu())) != 0);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/branch'/copy1' */
    SET_D_TPLFBT_QuStatusTrajPlan_nu(rtb_Switch_j);
    /* DataTypeConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Logical Operator/Functionality'/Data Type Conversion' incorporates:
                                                      *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Constant2'/Constant'
                                                      *  Inport: '<Root>/S_TPLCEN_TrajPlanEnbl_nu'
                                                      *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Logical Operator/Functionality'/OR'
                                                      *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Equality/Functionality'/EQ'
                                                      */
    rtb_NE_p = (uint8)((((sint32)rtb_DataTypeConversion_b) != 0) || (((sint32) GET_S_TPLCEN_TrajPlanEnbl_nu()) == 0));
    /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/from_data_definition'/state_source'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/from_data_definition1'/state_source'
         *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         *  Inport: '<Root>/S_CSCLTA_TrajGuiQualifier_nu'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Logical Operator3/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Equality1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Equality4/Functionality'/EQ'
         *  Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Switch/Functionality'/Switch'
         */
    if ((((sint32)rtb_NE_p) != 0) && (((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)) == ((sint32) GET_S_CSCLTA_SysStateLCF_enum()))) {
        SET_S_TPLFBT_TrajGuiQualifier_nu(((uint8) E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE));
    } else if ((((sint32)GET_S_CSCLTA_SysStateLCF_enum()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) && (((sint32) rtb_NE_p) != 0)) {
        /* Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/from_data_definition2'/state_source'
                 */
        SET_S_TPLFBT_TrajGuiQualifier_nu(((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF));
    } else {
        SET_S_TPLFBT_TrajGuiQualifier_nu(GET_S_CSCLTA_TrajGuiQualifier_nu());
    }
    /* End of Switch: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Setup_TrajGui_from_Qualifier_Status/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch11'/copy1' */
    SET_S_TPLFBT_TrajTgtCrv_1pm(BI_tplfbt_SignalConversion1);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch12'/copy1' */
    SET_D_TPLFBT_GradLimitActive_nu(BI_tplfbt_RelationalOperator1);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch13'/copy1' */
    SET_D_TPLFBT_TargetSwitch_nu(BI_tplfbt_DataTypeConversion);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch14'/copy1' */
    SET_D_TPLFBT_UseTargetCorridor_nu(BI_tplfbt_SignalConversion1_a);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch15'/copy1' */
    SET_D_TPLFBT_DeltaTargetHeading_rad(BI_tplfbt_copy1_n);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch16'/copy1' */
    SET_D_TPLFBT_DeltaTargetPosY0_met(BI_tplfbt_copy1_k);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch17'/copy1' */
    SET_D_TPLFBT_DeltaTargetCrv_1pm(BI_tplfbt_copy1);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch18'/copy1' */
    SET_D_TPLFBT_PlausiCheckStatus_nu(rtb_sfun_setbit_n);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch19'/copy1' */
    SET_S_TPLFBT_QuStatusTrajPlan_nu(rtb_Switch_ns);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch2'/copy1' incorporates:
                                                       *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                                       */
    SET_S_TPLFBT_TrajDistYPrev_met (rtb_sfun_calFrenetBackTransformation.sfunc_TrajDistY_met);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch20'/copy1' incorporates:
                                                                    *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                                                    */
    SET_D_TPLFBT_TrajTgtCrvGrdPrev_1pms (rtb_sfun_calFrenetBackTransformation.sfunc_TrajTgtCrvGrd_1pms);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch22'/copy1' */
    SET_D_TPLFBT_TgtCorridorCrv_1pm(rtb_Sum_k);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch23'/copy1' incorporates:
                                                  *  Inport: '<Root>/S_TPLFRT_TrajVelRefCurve_mps'
                                                  *  Inport: '<Root>/S_TPLLCO_TgtCridrChngOfCrv_1pm2'
                                                  *  Product: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview/Mul6/Functionality'/Mul'
                                                  */
    SET_D_TPLFBT_TgtCorridorCrvGrd_1pms(GET_S_TPLFRT_TrajVelRefCurve_mps() * GET_S_TPLLCO_TgtCridrChngOfCrv_1pm2());
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch24'/copy1' incorporates:
                                                *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                                */
    SET_D_TPLFBT_TgtTrjCrvPrvwDT_1pm (rtb_sfun_calFrenetBackTransformation.sfunc_TgtCrvInclPreviewAndDeadTime_1pm);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch25'/copy1' incorporates:
                                                                          *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                                                          */
    SET_D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms (rtb_sfun_calFrenetBackTransformation.sfunc_TgtCrvGrdTrajInclPrevAndDT_1pms);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch26'/copy1' incorporates:
                                                                          *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                                                          */
    SET_D_TPLFBT_TrajHeadingPrvw_rad (rtb_sfun_calFrenetBackTransformation.sfunc_TrajHeadingInclPreview_rad);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch27'/copy1' */
    SET_D_TPLFBT_TrajPlanInvalid_nu(rtb_DataTypeConversion_b);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch3'/copy1' */
    SET_S_TPLFBT_TrajHeading_rad(BI_tplfbt_SignalConversion1_dg);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch4'/copy1' incorporates:
                                                              *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                                              */
    SET_S_TPLFBT_TrajHeadingPrev_rad (rtb_sfun_calFrenetBackTransformation.sfunc_TrajHeading_rad);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch5'/copy1' incorporates:
                                                                      *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                                                      */
    SET_S_TPLFBT_TrajTgtCrvPrev_1pm (rtb_sfun_calFrenetBackTransformation.sfunc_TrajTgtCrv_1pm);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch6'/copy1' incorporates:
                                                                     *  BusCreator: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT'/FBTOuputStruct'
                                                                     */
    SET_S_TPLFBT_CurHeading_rad (rtb_sfun_calFrenetBackTransformation.sfunc_HeadingCurValuePreview_rad);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch7'/copy1' incorporates:
                                                                          *  Inport: '<Root>/S_TPLLCO_DevDistY_met'
                                                                          */
    SET_S_TPLFBT_CurDistY_met(GET_S_TPLLCO_DevDistY_met());
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch8'/copy1' */
    SET_S_TPLFBT_TrajHeadInclPrev_rad(BI_tplfbt_SignalConversion1_c);
    /* SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/branch9'/copy1' */
    SET_S_TPLFBT_TrajDistY_met(BI_tplfbt_SignalConversion1_d);
    /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Target_Corridor_Preview'/Unit_Delay' */
    DW_tplfbt_Unit_Delay_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay' */
    DW_tplfbt_Unit_Delay_DSTATE_pl = rtb_Switch_ns;
    /* S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tplfbt_Unit_Delay3_DSTATE = rtb_Switch_pn;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay1' */
    DW_tplfbt_Unit_Delay1_DSTATE = rtb_Sum_e;
    /* Update for UnitDelay: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM/M_TPLFBT/Check_TrajPlan_Status'/Unit_Delay2' */
    DW_tplfbt_Unit_Delay2_DSTATE = rtb_Sum_g4;
    /* End of Outputs for SubSystem: 'sda:TPLFBT/TPLFBT/TPLFBT_VehProcess/OPM'/M_TPLFBT' */
}
#include "Pse_TPLFBT.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
