/**************************************************************************
COPYRIGHT (C) $Date: 2019/09/20 15:34:25CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJCTR/TCTLGC_VEH/TCTLGC/i/project.pj $
$Log: TCTLGC.c  $
Revision 1.3.1.5 2019/09/20 15:34:25CEST Schrader, Moritz (uia92406) (uia92406) 
automatically created
File          : TCTLGC
Generated on  : Fri 20.09.2019 at 14:25:24 (UTC+01:00)
MD5           : [279332705   457807960  3268438237   952629683 0](TCTLGC)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.1012177 (R2016b) Update 7
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,86,87,88,90
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TCTLGC.h"
#include "TCTLGC_private.h"
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
#define TCTLGC_START_SEC_DATA_8
#include "TCTLGC_MemMap.h"
static uint8 DW_tctlgc_Unit_Delay_DSTATE_cc;
static uint8 DW_tctlgc_Unit_Delay_DSTATE_j;
static uint8 DW_tctlgc_Unit_Delay1_DSTATE_lc;
static uint8 DW_tctlgc_Unit_Delay_DSTATE_lt2;
static uint8 DW_tctlgc_Unit_Delay1_DSTATE_lu;
static uint8 DW_tctlgc_Unit_Delay_DSTATE_af;
static uint8 DW_tctlgc_Unit_Delay1_DSTATE_ph;
#define TCTLGC_STOP_SEC_DATA_8
#include "TCTLGC_MemMap.h"
#define TCTLGC_START_SEC_DATA_32
#include "TCTLGC_MemMap.h"
static float32 DW_tctlgc_Unit_Delay_DSTATE;
static float32 DW_tctlgc_Unit_Delay1_DSTATE;
static float32 DW_tctlgc_Unit_Delay3_DSTATE;
static float32 DW_tctlgc_Unit_Delay_DSTATE_a;
static float32 DW_tctlgc_Unit_Delay1_DSTATE_p;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_n;
static float32 DW_tctlgc_Unit_Delay_DSTATE_l;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_e;
static float32 DW_tctlgc_Unit_Delay_DSTATE_f;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_k;
static float32 DW_tctlgc_Unit_Delay_DSTATE_i;
static float32 DW_tctlgc_Unit_Delay2_DSTATE;
static float32 DW_tctlgc_Unit_Delay_DSTATE_b;
static float32 DW_tctlgc_Unit_Delay1_DSTATE_o;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_eo;
static float32 DW_tctlgc_Unit_Delay_DSTATE_n;
static float32 DW_tctlgc_Unit_Delay1_DSTATE_g;
static float32 DW_tctlgc_Unit_Delay_DSTATE_bb;
static float32 DW_tctlgc_Unit_Delay_DSTATE_g;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_f;
static float32 DW_tctlgc_Unit_Delay_DSTATE_m;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_p;
static float32 DW_tctlgc_Unit_Delay_DSTATE_fe;
static float32 DW_tctlgc_Unit_Delay2_DSTATE_e;
static float32 DW_tctlgc_Unit_Delay_DSTATE_bf;
static float32 DW_tctlgc_Unit_Delay1_DSTATE_n;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_m;
static float32 DW_tctlgc_Unit_Delay_DSTATE_i1;
static float32 DW_tctlgc_Unit_Delay1_DSTATE_l;
static float32 DW_tctlgc_Unit_Delay_DSTATE_lt;
static float32 DW_tctlgc_Unit_Delay_DSTATE_im;
static float32 DW_tctlgc_Unit_Delay_DSTATE_l3;
static float32 DW_tctlgc_Unit_Delay1_DSTATE_e;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_ep;
static float32 DW_tctlgc_Unit_Delay_DSTATE_feo;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_ex;
static float32 DW_tctlgc_Unit_Delay_DSTATE_o;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_h;
static float32 DW_tctlgc_Unit_Delay_DSTATE_c;
static float32 DW_tctlgc_Unit_Delay2_DSTATE_j;
static float32 DW_tctlgc_Unit_Delay_DSTATE_k;
static float32 DW_tctlgc_Unit_Delay1_DSTATE_gf;
static float32 DW_tctlgc_Unit_Delay3_DSTATE_ms;
static float32 DW_tctlgc_Unit_Delay_DSTATE_d;
static float32 DW_tctlgc_Unit_Delay1_DSTATE_f;
static float32 DW_tctlgc_Unit_Delay_DSTATE_p;
static float32 DW_tctlgc_Unit_Delay_DSTATE_h;
static float32 DW_tctlgc_Unit_Delay_DSTATE_gr;
static float32 DW_tctlgc_Unit_Delay_DSTATE_ir;
static float32 DW_tctlgc_UnitDelay2_DSTATE;
static float32 DW_tctlgc_UnitDelay2_DSTATE_d;
static float32 DW_tctlgc_UnitDelay_DSTATE;
static float32 DW_tctlgc_UnitDelay2_DSTATE_f;
static float32 DW_tctlgc_UnitDelay2_DSTATE_g;
static float32 DW_tctlgc_UnitDelay_DSTATE_c;
static float32 DW_tctlgc_UnitDelay2_DSTATE_dd;
static float32 DW_tctlgc_UnitDelay2_DSTATE_o;
static float32 DW_tctlgc_UnitDelay_DSTATE_a;
#define TCTLGC_STOP_SEC_DATA_32
#include "TCTLGC_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TCTLGC/TCTLGC/INI'/TCTLGC_VehReset'
 * Block description for: 'sda:TCTLGC/TCTLGC/INI'/TCTLGC_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTLGC_VehReset
#include "Pse_TCTLGC.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTLGC_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant'/Constant' */
    SET_S_TCTLGC_DeltaFCmd_deg(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant1'/Constant' */
    SET_S_TCTLGC_TgtCrv_DE_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant10'/Constant' */
    SET_S_TCTLGC_CtrlCrv_DE_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant11'/Constant' */
    SET_D_TCTLGC_DeltaFBAC_deg(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant12'/Constant' */
    SET_D_TCTLGC_CrvReqBAC_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant13'/Constant' */
    SET_D_TCTLGC_ActiveLgcParamSet_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant14'/Constant' */
    SET_D_TCTLGC_CacPT1Reset_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant15'/Constant' */
    SET_D_TCTLGC_LdcAlonePT1YErr_met(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant16'/Constant' */
    SET_D_TCTLGC_LdcAloneLaDmcComp_met(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant17'/Constant' */
    SET_D_TCTLGC_SumCrvReqFb_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant18'/Constant' */
    SET_D_TCTLGC_CrvReqFfcGrdLim_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant19'/Constant' */
    SET_D_TCTLGC_SumCrvReqFbGrdLim_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant2'/Constant' */
    SET_S_TCTLGC_TgtCrv_NoDE_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant20'/Constant' */
    SET_D_TCTLGC_SumCrvReqFbSatLim_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant21'/Constant' */
    SET_D_TCTLGC_SumCrvReqFbFrz_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant22'/Constant' */
    SET_D_TCTLGC_CrvReqFfcGrdLimT1_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant23'/Constant' */
    SET_D_TCTLGC_CrvReqFfcGrdLimT2_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant24'/Constant' */
    SET_D_TCTLGC_LdcAlonePT1Cmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant25'/Constant' */
    SET_D_TCTLGC_CrvReqDte_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant26'/Constant' */
    SET_D_TCTLGC_LdcPT1Input_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant27'/Constant' */
    SET_D_TCTLGC_LdcLaDmcComp_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant28'/Constant' */
    SET_D_TCTLGC_LdcPT1Cmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant29'/Constant' */
    SET_D_TCTLGC_PGainCacGrdLimTrig_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant3'/Constant' */
    SET_S_TCTLGC_TgtCrv_DENoLatSlp_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant30'/Constant' */
    SET_D_TCTLGC_PGainLdcGrdLimTrig_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant31'/Constant' */
    SET_D_TCTLGC_EnableCtrl_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant32'/Constant' */
    SET_D_TCTLGC_DeltaFCmdUnlimited_deg(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant33'/Constant' */
    SET_D_TCTLGC_DeltaFCmdDC_deg(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant34'/Constant' */
    SET_D_TCTLGC_LdcIntReset_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant35'/Constant' */
    SET_D_TCTLGC_CacIntReset_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant36'/Constant' */
    SET_D_TCTLGC_LdcAlonePT1Reset_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant37'/Constant' */
    SET_D_TCTLGC_CrvReqFfcFrz_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant38'/Constant' */
    SET_D_TCTLGC_Hold_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant39'/Constant' */
    SET_D_TCTLGC_DeltaFCmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant4'/Constant' */
    SET_S_TCTLGC_CtrlCrv_1pm(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant40'/Constant' */
    SET_D_TCTLGC_Reset_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant41'/Constant' */
    SET_D_TCTLGC_LdcAlonePCmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant42'/Constant' */
    SET_D_TCTLGC_LdcAloneDT1Cmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant43'/Constant' */
    SET_D_TCTLGC_LdcAloneICmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant44'/Constant' */
    SET_D_TCTLGC_LdcAloneCmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant45'/Constant' */
    SET_D_TCTLGC_LdcPCmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant46'/Constant' */
    SET_D_TCTLGC_LdcDT1Cmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant47'/Constant' */
    SET_D_TCTLGC_LdcICmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant48'/Constant' */
    SET_D_TCTLGC_LdcCmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant49'/Constant' */
    SET_D_TCTLGC_CacPT1CoAnErr_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant5'/Constant' */
    SET_S_TCTLGC_CtrlErrHeadAglCrtd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant50'/Constant' */
    SET_D_TCTLGC_CacLaDmcComp_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant51'/Constant' */
    SET_D_TCTLGC_CacPT1Cmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant52'/Constant' */
    SET_D_TCTLGC_LdcAloneIntReset_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant53'/Constant' */
    SET_D_TCTLGC_CacCmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant54'/Constant' */
    SET_D_TCTLGC_CacPCmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant55'/Constant' */
    SET_D_TCTLGC_CacDT1Cmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant56'/Constant' */
    SET_D_TCTLGC_CacICmd_rad(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant6'/Constant' */
    SET_D_TCTLGC_DeltaFCmdFFC_deg(0.0F);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant7'/Constant' */
    SET_D_TCTLGC_SafetyFunctionActive_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant8'/Constant' */
    SET_D_TCTLGC_LdcPT1Reset_nu(0U);
    /* Constant: 'sda:TCTLGC/TCTLGC/INI/TCTLGC_VehReset/Constant9'/Constant' */
    SET_S_TCTLGC_FFCrv_1pm(0.0F);
}
#include "Pse_TCTLGC.h"
/*
 * Output and update for function-call system: 'sda:TCTLGC/TCTLGC'/TCTLGC_VehProcess'
 * Block description for: 'sda:TCTLGC/TCTLGC'/TCTLGC_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTLGC_VehProcess
#include "Pse_TCTLGC.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTLGC_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_k0;
    float32 rtb_Div;
    float32 rtb_SFunction;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_Div_d;
    float32 rtb_SFunction_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_Div_l;
    float32 rtb_SFunction_o;
    float32 rtb_Mul_f;
    float32 rtb_Div_c;
    float32 rtb_SFunction_d;
    float32 rtb_Switch_j;
    float32 rtb_Div_e;
    float32 rtb_SFunction_d4;
    float32 rtb_ip_lookup_fxpt_sfun_7_n1;
    float32 rtb_Div_cv;
    float32 rtb_SFunction_l;
    float32 rtb_Mul_dl;
    float32 rtb_Div_a;
    float32 rtb_SFunction_h;
    float32 rtb_S_TCTCDC_CtrlErrHeadAglPrev_rad;
    float32 rtb_ip_lookup_fxpt_sfun_7_l1;
    float32 rtb_Div_f;
    float32 rtb_SFunction_m;
    float32 rtb_Div_cd;
    float32 rtb_SFunction_g;
    float32 rtb_Div_i;
    float32 rtb_SFunction_hn;
    float32 rtb_Mul_ge;
    float32 rtb_Div_ah;
    float32 rtb_SFunction_c;
    float32 rtb_Div_o;
    float32 rtb_ip_lookup_fxpt_sfun_7_o;
    float32 rtb_Div_j;
    float32 rtb_SFunction_dr;
    float32 rtb_ip_lookup_fxpt_sfun_7_ow;
    float32 rtb_Div_mg;
    float32 rtb_SFunction_j;
    float32 rtb_Mul_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_Mul_oq;
    float32 rtb_ip_lookup_fxpt_sfun_7_lw;
    float32 rtb_ip_lookup_fxpt_sfun_7_ou;
    float32 rtb_ip_lookup_fxpt_sfun_7_nd;
    float32 rtb_ip_lookup_fxpt_sfun_7_je;
    float32 rtb_ip_lookup_fxpt_sfun_7_kv;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_ep;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_kb;
    float32 rtb_ip_lookup_fxpt_sfun_7_ku;
    float32 rtb_ip_lookup_fxpt_sfun_7_el;
    float32 rtb_ip_lookup_fxpt_sfun_7_k1;
    float32 rtb_ip_lookup_fxpt_sfun_7_f5;
    float32 rtb_ip_lookup_fxpt_sfun_7_d2;
    float32 rtb_ip_lookup_fxpt_sfun_7_iz;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_om;
    float32 rtb_ip_lookup_fxpt_sfun_7_aa;
    float32 rtb_ip_lookup_fxpt_sfun_7_fi;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_aj;
    float32 rtb_ip_lookup_fxpt_sfun_7_o3;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_p4;
    float32 rtb_ip_lookup_fxpt_sfun_7_nb;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_jg;
    float32 rtb_ip_lookup_fxpt_sfun_7_ae;
    float32 rtb_ip_lookup_fxpt_sfun_7_dl;
    float32 rtb_ip_lookup_fxpt_sfun_7_lb;
    float32 rtb_ip_lookup_fxpt_sfun_7_fh;
    float32 rtb_ip_lookup_fxpt_sfun_7_i3;
    float32 rtb_ip_lookup_fxpt_sfun_7_ei;
    float32 rtb_ip_lookup_fxpt_sfun_7_cj;
    float32 rtb_Mul_kz;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_le;
    uint8 rtb_DataTypeConversion_dx;
    float32 rtb_Div_go;
    float32 rtb_Switch_id;
    uint8 rtb_Switch_m3;
    float32 rtb_Sum_ly;
    float32 rtb_Switch_d3;
    float32 rtb_Switch_h0;
    float32 rtb_Switch_by;
    uint8 rtb_EQ;
    uint8 rtb_NE;
    uint8 rtb_DataTypeConversion_l;
    float32 rtb_Div_i1;
    float32 rtb_Div_mp;
    uint8 rtb_DataTypeConversion_g;
    float32 rtb_Switch;
    float32 rtb_MultiportSwitch7;
    float32 rtb_Switch_i;
    float32 rtb_MultiportSwitch6;
    float32 rtb_Switch6_d;
    uint8 rtb_EQ_l;
    float32 rtb_Mul;
    float32 rtb_MultiportSwitch2;
    uint8 rtb_RelationalOperator;
    float32 rtb_Mul_ei;
    uint8 rtb_RelationalOperator1;
    uint8 rtb_DataTypeConversion_lj;
    uint8 rtb_DataTypeConversion_dg;
    float32 rtb_Mul_cn;
    uint8 rtb_EQ_e;
    uint8 rtb_GE;
    uint8 rtb_DataTypeConversion_no;
    uint8 rtb_DataTypeConversion_hp;
    float32 rtb_Sum_fw;
    float32 rtb_Mul_m;
    float32 rtb_MultiportSwitch2_l;
    uint8 rtb_RelationalOperator_fv;
    float32 rtb_Mul_ey;
    uint8 rtb_RelationalOperator1_e4;
    uint8 rtb_DataTypeConversion_m;
    float32 rtb_Mul_gh;
    float32 rtb_MultiportSwitch1;
    float32 rtb_Sum_pj;
    float32 rtb_Switch_kl;
    float32 rtb_UnitDelay2;
    float32 rtb_UnitDelay2_h;
    uint8 rtb_RelationalOperator_i;
    uint8 rtb_RelationalOperator1_c;
    uint8 rtb_DataTypeConversion_a;
    float32 rtb_Mul_og;
    float32 rtb_Mul_bp;
    float32 rtb_Max;
    float32 rtb_Sum_bv;
    float32 rtb_Sum_gw;
    float32 rtb_Sum_mq;
    float32 rtb_Switch7_f;
    float32 rtb_Switch_h;
    float32 rtb_Sum_o;
    float32 rtb_Switch_fu;
    float32 rtb_Switch_hf;
    float32 rtb_Sum_d;
    float32 rtb_Sum_fz;
    float32 rtb_Switch_cw;
    float32 rtb_Sum_p;
    float32 rtb_Sum;
    sint32 rtb_DataTypeConversion_o;
    /* Outputs for Atomic SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC'
         *
         * Block description for 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC':
         *  X.2.1
         */
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Freeze and Enable/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Freeze and Enable/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_NE = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) != ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF)));
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Freeze and Enable/Equality/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Freeze and Enable/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) == ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE)));
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/NOT/Functionality'/NOT'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/OR1/Functionality'/OR'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset'/Unit_Delay'
         */
    rtb_DataTypeConversion = (uint8)(((((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0) || (!(((sint32)rtb_NE) != 0))) || ((((sint32) DW_tctlgc_Unit_Delay_DSTATE_cc) != 0) && (!(((sint32)rtb_EQ) != 0))));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING'/fcg' */
    /* MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant5'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         */
    rtb_Max = f32_max_f32_f32(GET_S_LCFRCV_SysCycleTimeVeh_sec(), GET_P_LCF_AlmostZero_nu());
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/AvoidDivisionByZero/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/AvoidDivisionByZero/Application Parameter1'/Constant'
         */
    if (rtb_Max >= 0.005F) {
        rtb_Switch = rtb_Max;
    } else {
        rtb_Switch = 0.005F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/AvoidDivisionByZero/Switch8/Functionality'/Switch' */
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompPole1_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TCTLGC_GLaDmcCompPole1_nu(), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompPole1_nu/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompPole1_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum = rtb_ip_lookup_fxpt_sfun_7;
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompPole2_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D(GETA_Y_TCTLGC_GLaDmcCompPole2_nu(), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompPole2_nu/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompPole2_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_p = rtb_ip_lookup_fxpt_sfun_7_i;
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompNumS0_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D(GETA_Y_TCTLGC_GLaDmcCompNumS0_nu(), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompNumS0_nu/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompNumS0_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_fz = rtb_ip_lookup_fxpt_sfun_7_k;
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1 Low Pass/Y_TCTLGC_PT1YErrTime_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k0 = F32_PTR_IP1D(GETA_Y_TCTLGC_PT1YErrTime_sec(), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1 Low Pass/Y_TCTLGC_PT1YErrTime_sec/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1 Low Pass/Y_TCTLGC_PT1YErrTime_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_MultiportSwitch7 = rtb_ip_lookup_fxpt_sfun_7_k0;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1 Low Pass/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1 Low Pass/Max/Functionality'/Max'
         */
    rtb_Div = rtb_Switch / f32_max_f32_f32(rtb_MultiportSwitch7, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1 Low Pass'/Unit_Delay' */
    rtb_MultiportSwitch7 = DW_tctlgc_Unit_Delay_DSTATE_l;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1 Low Pass/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction = GET_S_TCTCDC_CtrlErrDistY_met();
    } else {
        rtb_SFunction = f32_mmv_f32_f32_f32( rtb_MultiportSwitch7, GET_S_TCTCDC_CtrlErrDistY_met(), rtb_Div);
    }
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Constant1'/Constant'
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    if (((sint32)GET_P_TCTLGC_PT1YErrEnable_nu()) != 0) {
        rtb_Switch_i = rtb_SFunction;
    } else {
        rtb_Switch_i = GET_S_TCTCDC_CtrlErrDistY_met();
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Switch2/Functionality'/Switch' */
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompNumS1_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D(GETA_Y_TCTLGC_GLaDmcCompNumS1_nu(), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompNumS1_nu/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Y_TCTLGC_GLaDmcCompNumS1_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_d = rtb_ip_lookup_fxpt_sfun_7_l;
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay3' */
    rtb_MultiportSwitch7 = DW_tctlgc_Unit_Delay3_DSTATE_e;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_MultiportSwitch7 = rtb_Switch_i;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Div2/Functionality/Div'/Div' incorporates:
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Sum4/Functionality'/Sum'
         */
    rtb_MultiportSwitch7 = (rtb_Switch_i - rtb_MultiportSwitch7) / rtb_Switch;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Constant'/Constant'
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Max/Functionality'/Max'
         */
    rtb_Div_d = rtb_Switch / f32_max_f32_f32(0.03F, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay' */
    rtb_MultiportSwitch6 = DW_tctlgc_Unit_Delay_DSTATE_f;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_i = rtb_MultiportSwitch7;
    } else {
        rtb_SFunction_i = f32_mmv_f32_f32_f32( rtb_MultiportSwitch6, rtb_MultiportSwitch7, rtb_Div_d);
    }
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/IV'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Add/Functionality'/Sum'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_fu = 0.0F;
    } else {
        if (((sint32)rtb_NE) != 0) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2'/Unit_Delay3'
                         */
            if (((sint32)rtb_DataTypeConversion) != 0) {
                rtb_Switch_id = rtb_SFunction_i;
            } else {
                rtb_Switch_id = DW_tctlgc_Unit_Delay3_DSTATE_k;
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch' incorporates:
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Div2/Functionality/Div'/Div'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul4/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul9/Functionality'/Mul'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum3/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum5/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Neg/Functionality'/Unary Minus'
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Neg1/Functionality'/Unary Minus'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay3'
                         */
            rtb_Switch_fu = ((((rtb_Sum_fz * rtb_Switch_i) + (rtb_Sum_d * rtb_SFunction_i)) + ((rtb_SFunction_i - rtb_Switch_id) / rtb_Switch)) - (((-rtb_Sum) + (-rtb_Sum_p)) * DW_tctlgc_Unit_Delay1_DSTATE_p)) - (((-rtb_Sum) * (-rtb_Sum_p)) * DW_tctlgc_Unit_Delay3_DSTATE_n);
        } else {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Constant2'/Constant'
                         */
            rtb_Switch_fu = 0.0F;
        }
        rtb_Switch_fu = (rtb_Switch * rtb_Switch_fu) + DW_tctlgc_Unit_Delay1_DSTATE_p;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MN'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MX'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch1'
         */
    if (rtb_Switch_fu >= 100.0F) {
        rtb_Switch_fu = 100.0F;
    } else {
        if (rtb_Switch_fu <= -100.0F) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MN'
                         */
            rtb_Switch_fu = -100.0F;
        }
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch6_d = 0.0F;
    } else {
        rtb_Switch6_d = (rtb_Switch * rtb_Switch_fu) + DW_tctlgc_Unit_Delay_DSTATE_a;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch6_d >= 100.0F) {
        rtb_Switch6_d = 100.0F;
    } else {
        if (rtb_Switch6_d <= -100.0F) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch6_d = -100.0F;
        }
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Constant'/Constant'
         */
    if (((sint32)GET_P_TCTLGC_LdcLaDmcCompEnable_nu()) != 0) {
        rtb_MultiportSwitch6 = rtb_Switch6_d;
    } else {
        rtb_MultiportSwitch6 = rtb_Switch_i;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Comfort or Safety Function/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Comfort or Safety Function/from_data_definition'/state_source'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Comfort or Safety Function/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Comfort or Safety Function/AND/Functionality'/AND'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Comfort or Safety Function/NOT/Functionality'/NOT'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Comfort or Safety Function/NOT1/Functionality'/NOT'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Comfort or Safety Function/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Comfort or Safety Function/EQ2/Functionality'/EQ'
         */
    rtb_DataTypeConversion_dx = (uint8)((!(((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()))) && (!(((sint32) GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)))));
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/from_data_definition'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    rtb_EQ_l = (uint8)(((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu()));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Active Parameter Set/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Active Parameter Set/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Active Parameter Set/Constant4'/Constant'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Active Parameter Set/Switch6/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_dx) != 0) {
        rtb_Switch_m3 = 3U;
    } else if (((sint32)rtb_EQ_l) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Active Parameter Set/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Active Parameter Set/Constant3'/Constant'
                 */
        rtb_Switch_m3 = 2U;
    } else {
        rtb_Switch_m3 = 1U;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Determine Active Parameter Set/Switch5/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch7' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/P_TCTLGC_LdcP_radpm'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/P_TCTLGC_LdcSfP_radpm'/Constant'
         */
    switch (rtb_Switch_m3) {
    case 1:
        rtb_MultiportSwitch7 = GET_P_TCTLGC_LdcP_radpm();
        break;
    case 2:
        rtb_MultiportSwitch7 = GET_P_TCTLGC_LdcOfP_radpm();
        break;
    default:
        rtb_MultiportSwitch7 = GET_P_TCTLGC_LdcSfP_radpm();
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch7' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Mul4/Functionality'/Mul' */
    rtb_Mul = rtb_MultiportSwitch6 * rtb_MultiportSwitch7;
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcPGainCrv_radpm1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_CrvFFC_1pm */
        FDPS_PTR_F32(GETA_X_TCTLGC_CrvFFC_1pm(), GET_S_TCTFFC_Crv_1pm(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcPGainCrv_radpm(), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcPGainCrv_radpm1/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTFFC_Crv_1pm'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcPGainCrv_radpm1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_gw = rtb_ip_lookup_fxpt_sfun_7_n;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch2' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Mul2/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfP_radpm1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcP_radpm1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfP_radpm1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcP_radpm1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_kv = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcP_radpm(), &x_dps);
    }
    rtb_MultiportSwitch2 = rtb_Sum_gw * rtb_ip_lookup_fxpt_sfun_7_kv;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfP_radpm1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcOfP_radpm(), &x_dps);
    }
    rtb_MultiportSwitch2 = rtb_ip_lookup_fxpt_sfun_7_e;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfP_radpm1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcSfP_radpm(), &x_dps);
    }
    rtb_MultiportSwitch2 = rtb_ip_lookup_fxpt_sfun_7_f * rtb_Sum_gw;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch2' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Constant'/Constant'
         */
    rtb_Sum_gw = GET_P_TCTLGC_PGainGrdLimit_1ps() * rtb_Switch;
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain'/Unit_Delay'
         */
    rtb_MultiportSwitch6 = rtb_MultiportSwitch2 - DW_tctlgc_Unit_Delay_DSTATE_i;
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator = (uint8)(rtb_MultiportSwitch6 > rtb_Sum_gw);
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Constant'/Constant'
         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Neg/Functionality'/Unary Minus'
         */
    rtb_Mul_ei = (-GET_P_TCTLGC_PGainGrdLimit_1ps()) * rtb_Switch;
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1 = (uint8)(rtb_MultiportSwitch6 < rtb_Mul_ei);
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_lj = (uint8)((((sint32)rtb_DataTypeConversion_dx) != 0) || (((sint32)rtb_EQ_l) != 0));
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI'/Functionality'
         */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI'/IV'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_DataTypeConversion_no = 0U;
    } else {
        rtb_DataTypeConversion_no = DW_tctlgc_Unit_Delay_DSTATE_j;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI/Functionality'/Relational Operator'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain'/Unit_Delay1'
         */
    rtb_DataTypeConversion_dg = (uint8)((((sint32)rtb_DataTypeConversion_lj) != ((sint32)rtb_DataTypeConversion_no)) || (((sint32) DW_tctlgc_Unit_Delay1_DSTATE_lc) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI'/fcg' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum_gw = rtb_MultiportSwitch2;
    } else if (((sint32)rtb_DataTypeConversion_dg) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3'
                 *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain'/Unit_Delay'
                 */
        if (((sint32)rtb_RelationalOperator) != 0) {
            rtb_Sum_gw += DW_tctlgc_Unit_Delay_DSTATE_i;
        } else if (((sint32)rtb_RelationalOperator1) != 0) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain'/Unit_Delay'
                         */
            rtb_Sum_gw = rtb_Mul_ei + DW_tctlgc_Unit_Delay_DSTATE_i;
        } else {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
            rtb_Sum_gw = rtb_MultiportSwitch2;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    } else {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain'/Unit_Delay'
                 */
        rtb_Sum_gw = DW_tctlgc_Unit_Delay_DSTATE_i;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_dg) != 0) {
        rtb_MultiportSwitch6 = rtb_Sum_gw;
    } else {
        rtb_MultiportSwitch6 = rtb_MultiportSwitch2;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Switch1/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Mul8/Functionality'/Mul' */
    rtb_MultiportSwitch2 = rtb_Mul * rtb_MultiportSwitch6;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/Constant'/Constant'
         */
    rtb_Mul_cn = GET_P_TCTLGC_LdcPT1MaxGrd_radpms() * rtb_Switch;
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator'/Unit_Delay' */
    rtb_MultiportSwitch6 = DW_tctlgc_Unit_Delay_DSTATE_b;
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator/Sign1/Functionality'/Sign' */
    if (rtb_MultiportSwitch6 < 0.0F) {
        rtb_MultiportSwitch7 = -1.0F;
    } else if (rtb_MultiportSwitch6 > 0.0F) {
        rtb_MultiportSwitch7 = 1.0F;
    } else if (rtb_MultiportSwitch6 == 0.0F) {
        rtb_MultiportSwitch7 = 0.0F;
    } else {
        rtb_MultiportSwitch7 = rtb_MultiportSwitch6;
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator/Sign1/Functionality'/Sign' */
    /* Abs: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/DynResetPreconditions/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    rtb_MultiportSwitch6 = f32_abs_f32(GET_S_TCTCDC_CtrlErrDistY_met());
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/DynResetPreconditions/GE/Functionality'/GE' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/DynResetPreconditions/Constant1'/Constant'
         */
    rtb_GE = (uint8)(rtb_MultiportSwitch6 >= GET_P_TCTLGC_IntResMaxLatErr_m());
    /* Abs: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/DynResetPreconditions/Abs2/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_TCTFFC_Crv_1pm'
         */
    rtb_MultiportSwitch6 = f32_abs_f32(GET_S_TCTFFC_Crv_1pm());
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/DynResetPreconditions/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/DynResetPreconditions/Constant5'/Constant'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/DynResetPreconditions/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/DynResetPreconditions/LE1/Functionality'/LE'
         */
    rtb_GE = (uint8)((((sint32)rtb_GE) != 0) && (rtb_MultiportSwitch6 <= GET_P_TCTLGC_IntResMaxCrv_1pm()));
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
        rtb_Switch_id = -1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
        rtb_Switch_id = 1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
        rtb_Switch_id = 0.0F;
    } else {
        rtb_Switch_id = GET_S_TCTCDC_CtrlErrDistY_met();
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator/Sign/Functionality'/Sign' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit5/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator/Constant2'/Constant'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND6/Functionality'/AND'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator/AND/Functionality'/AND'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator/EQ/Functionality'/EQ'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit5/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_g = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)0U)))) != 0) && (((rtb_Switch_id * rtb_MultiportSwitch7) == -1.0F) && (((sint32)rtb_GE) != 0)));
    /* Abs: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         */
    rtb_MultiportSwitch6 = f32_abs_f32(GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm());
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/GE1/Functionality'/GE' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Constant'/Constant'
         */
    rtb_EQ_e = (uint8)(rtb_MultiportSwitch6 >= GET_P_TCTLGC_IntResMaxManTrq_Nm());
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant7'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit4/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND4/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit4/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_no = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)1U)))) != 0) && (((sint32) rtb_EQ_e) != 0));
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/LE/Functionality'/LE' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Constant4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_DataTypeConversion_hp = (uint8)(GET_S_LCFRCV_VehVelX_mps() <= GET_P_TCTLGC_StandstillThreshVel_mps());
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant10'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit3/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND5/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit3/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)2U)))) != 0) && (((sint32) rtb_DataTypeConversion_hp) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_g = (uint8)(((((sint32)rtb_DataTypeConversion_g) != 0) || (((sint32)rtb_DataTypeConversion_no) != 0)) || (((sint32) rtb_DataTypeConversion_le) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/OR2/Functionality'/OR'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)rtb_DataTypeConversion_g) != 0) || (((sint32)rtb_DataTypeConversion) != 0));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL'/IV'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/NOT/Functionality'/NOT'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch7'
         */
    if (((sint32)rtb_DataTypeConversion_le) != 0) {
        rtb_Mul_ei = 0.0F;
    } else if (!(((sint32)rtb_EQ) != 0)) {
        /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch1' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcIGain_radpsm/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfIGain_radpsm/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfIGain_radpsm/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch7'
                 */
        switch (rtb_Switch_m3) {
        case 1:
            /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcIGain_radpsm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTLGC_Vel_mps */
            FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ou = F32_PTR_IP1D (GETA_Y_TCTLGC_LdcIGain_radpsm(), &x_dps);
        }
        rtb_Mul_ei = rtb_ip_lookup_fxpt_sfun_7_ou;
        break;
        case 2:
            /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfIGain_radpsm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTLGC_Vel_mps */
            FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_nd = F32_PTR_IP1D (GETA_Y_TCTLGC_LdcOfIGain_radpsm(), &x_dps);
        }
        rtb_Mul_ei = rtb_ip_lookup_fxpt_sfun_7_nd;
        break;
        default:
            /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfIGain_radpsm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTLGC_Vel_mps */
            FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_je = F32_PTR_IP1D (GETA_Y_TCTLGC_LdcSfIGain_radpsm(), &x_dps);
        }
        rtb_Mul_ei = rtb_ip_lookup_fxpt_sfun_7_je;
        break;
        }
        /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch1' */
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch7' incorporates:
                 *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
                 *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc'/Unit_Delay1'
                 */
        rtb_Mul_ei = ((rtb_Mul_ei * rtb_Switch) * rtb_MultiportSwitch2) + DW_tctlgc_Unit_Delay1_DSTATE_o;
    } else {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch7' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc'/Unit_Delay1'
                 */
        rtb_Mul_ei = DW_tctlgc_Unit_Delay1_DSTATE_o;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/P_TCTLGC_LdcILimit_rad'/Constant'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch1'
         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/Neg/Functionality'/Unary Minus'
         */
    if (rtb_Mul_ei >= GET_P_TCTLGC_LdcILimit_rad()) {
        rtb_Mul_ei = GET_P_TCTLGC_LdcILimit_rad();
    } else {
        if (rtb_Mul_ei <= (-GET_P_TCTLGC_LdcILimit_rad())) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/Neg/Functionality'/Unary Minus'
                         */
            rtb_Mul_ei = -GET_P_TCTLGC_LdcILimit_rad();
        }
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc'/Unit_Delay2'
         */
    rtb_Sum_fw = rtb_Mul_ei - DW_tctlgc_Unit_Delay2_DSTATE;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc'/Unit_Delay2'
         */
    if (rtb_Sum_fw > rtb_Mul_cn) {
        rtb_Mul_cn += DW_tctlgc_Unit_Delay2_DSTATE;
    } else {
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/Constant'/Constant'
                 *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/Neg1/Functionality'/Unary Minus'
                 */
        rtb_Mul_cn = (-GET_P_TCTLGC_LdcPT1MaxGrd_radpms()) * rtb_Switch;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc'/Unit_Delay2'
                 */
        if (rtb_Sum_fw < rtb_Mul_cn) {
            rtb_Mul_cn += DW_tctlgc_Unit_Delay2_DSTATE;
        } else {
            rtb_Mul_cn = rtb_Mul_ei;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_le = (uint8)(!(((sint32)rtb_EQ) != 0));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative/Constant'/Constant'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative/Div2/Functionality/Div'/Div'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative/Sum4/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_le) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative/Switch1/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative'/Unit_Delay3'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_Switch_id = rtb_MultiportSwitch2;
        } else {
            rtb_Switch_id = DW_tctlgc_Unit_Delay3_DSTATE_eo;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative/Switch1/Functionality'/Switch' */
        rtb_MultiportSwitch6 = (rtb_MultiportSwitch2 - rtb_Switch_id) / rtb_Switch;
    } else {
        rtb_MultiportSwitch6 = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch9' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Constant5'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Constant6'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch8'
         */
    if (((sint32)rtb_DataTypeConversion_dg) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Constant4'
                 */
        if (((sint32)rtb_RelationalOperator) != 0) {
            rtb_DataTypeConversion_no = 0U;
        } else {
            rtb_DataTypeConversion_no = rtb_RelationalOperator1;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' */
        rtb_DataTypeConversion_le = rtb_RelationalOperator;
    } else {
        rtb_DataTypeConversion_no = 0U;
        rtb_DataTypeConversion_le = 0U;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch9' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/OR/Functionality'/OR'
         */
    rtb_RelationalOperator = (uint8)((((sint32)rtb_DataTypeConversion_no) != 0) || (((sint32)rtb_DataTypeConversion_le) != 0));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Constant1'/Constant'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Mul1/Functionality'/Mul'
         */
    if (((sint32)rtb_RelationalOperator) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Constant1'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Constant2'/Constant'
                 */
        if (((sint32)rtb_DataTypeConversion_no) != 0) {
            rtb_DataTypeConversion_o = -1;
        } else {
            rtb_DataTypeConversion_o = 1;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain/Switch/Functionality'/Switch' */
        rtb_MultiportSwitch7 = (GET_P_TCTLGC_PGainGrdLimit_1ps() * ((float32) rtb_DataTypeConversion_o)) * rtb_Mul;
    } else {
        rtb_MultiportSwitch7 = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Sum/Functionality'/Sum' */
    rtb_Mul = rtb_MultiportSwitch6 - rtb_MultiportSwitch7;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch3' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcDGain_radspm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfDGain_radspm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfDGain_radspm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcDGain_radspm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_ep = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcDGain_radspm(), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_ep;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfDGain_radspm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcOfDGain_radspm (), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_a;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfDGain_radspm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcSfDGain_radspm (), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_d;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch3' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Mul4/Functionality'/Mul' */
    rtb_MultiportSwitch6 *= rtb_Mul;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch4' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcDT1_sec(), &x_dps);
    }
    rtb_MultiportSwitch7 = rtb_ip_lookup_fxpt_sfun_7_b;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_kb = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcOfDT1_sec(), &x_dps);
    }
    rtb_MultiportSwitch7 = rtb_ip_lookup_fxpt_sfun_7_kb;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_ku = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcSfDT1_sec(), &x_dps);
    }
    rtb_MultiportSwitch7 = rtb_ip_lookup_fxpt_sfun_7_ku;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch4' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Max/Functionality'/Max'
         */
    rtb_Div_l = rtb_Switch / f32_max_f32_f32(rtb_MultiportSwitch7, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc'/Unit_Delay' */
    rtb_MultiportSwitch7 = DW_tctlgc_Unit_Delay_DSTATE_n;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_o = rtb_MultiportSwitch6;
    } else {
        rtb_SFunction_o = f32_mmv_f32_f32_f32( rtb_MultiportSwitch7, rtb_MultiportSwitch6, rtb_Div_l);
    }
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/Constant'/Constant'
         */
    rtb_Mul = GET_P_TCTLGC_LdcPT1MaxGrd_radpms() * rtb_Switch;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch5' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_el = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcPT1Gain_nu(), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_el;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k1 = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcOfPT1Gain_nu(), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_k1;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_f5 = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcSfPT1Gain_nu(), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_f5;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch5' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/Mul/Functionality'/Mul' */
    rtb_Mul_f = rtb_MultiportSwitch2 * rtb_MultiportSwitch6;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch6' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_d2 = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcPT1Time_sec(), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_d2;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcOfPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_iz = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcOfPT1Time_sec (), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_iz;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains/Y_TCTLGC_LdcSfPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D(GETA_Y_TCTLGC_LdcSfPT1Time_sec(), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_p;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Ldc Gains'/Multiport Switch6' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/Max/Functionality'/Max'
         */
    rtb_Div_c = rtb_Switch / f32_max_f32_f32(rtb_MultiportSwitch6, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1'/Unit_Delay' */
    rtb_MultiportSwitch6 = DW_tctlgc_Unit_Delay_DSTATE_bb;
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
        rtb_Switch_id = -1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
        rtb_Switch_id = 1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
        rtb_Switch_id = 0.0F;
    } else {
        rtb_Switch_id = GET_S_TCTCDC_CtrlErrDistY_met();
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/Sign/Functionality'/Sign' */
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/Sign1/Functionality'/Sign' */
    if (rtb_MultiportSwitch6 < 0.0F) {
        rtb_MultiportSwitch6 = -1.0F;
    } else if (rtb_MultiportSwitch6 > 0.0F) {
        rtb_MultiportSwitch6 = 1.0F;
    } else {
        if (rtb_MultiportSwitch6 == 0.0F) {
            rtb_MultiportSwitch6 = 0.0F;
        }
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/Sign1/Functionality'/Sign' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/Constant2'/Constant'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/AND/Functionality'/AND'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1/EQ/Functionality'/EQ'
         */
    rtb_DataTypeConversion_le = (uint8)(((rtb_Switch_id * rtb_MultiportSwitch6) == -1.0F) && (((sint32)rtb_GE) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant8'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit2/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND3/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit2/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)0U)))) != 0) && (((sint32) rtb_DataTypeConversion_le) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant3'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit1/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND1/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit1/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_no = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)1U)))) != 0) && (((sint32) rtb_EQ_e) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant6'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND2/Functionality'/AND'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR/Functionality'/OR'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_dg = (uint8)(((((sint32)rtb_DataTypeConversion_le) != 0) || (((sint32)rtb_DataTypeConversion_no) != 0)) || ((((sint32)((uint8) flag_get_u8_u8(GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)2U)))) != 0) && (((sint32)rtb_DataTypeConversion_hp) != 0)));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)rtb_DataTypeConversion) != 0) || (((sint32)rtb_DataTypeConversion_dg) != 0));
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc'/Unit_Delay' */
    rtb_MultiportSwitch6 = DW_tctlgc_Unit_Delay_DSTATE_g;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_le != 0U) {
        rtb_SFunction_d = 0.0F;
    } else {
        rtb_SFunction_d = f32_mmv_f32_f32_f32( rtb_MultiportSwitch6, rtb_Mul_f, rtb_Div_c);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc'/Unit_Delay1'
         */
    rtb_Sum_fw = rtb_SFunction_d - DW_tctlgc_Unit_Delay1_DSTATE_g;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc'/Unit_Delay1'
         */
    if (rtb_Sum_fw > rtb_Mul) {
        rtb_Mul += DW_tctlgc_Unit_Delay1_DSTATE_g;
    } else {
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/Constant'/Constant'
                 *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/Neg/Functionality'/Unary Minus'
                 */
        rtb_Mul = (-GET_P_TCTLGC_LdcPT1MaxGrd_radpms()) * rtb_Switch;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc'/Unit_Delay1'
                 */
        if (rtb_Sum_fw < rtb_Mul) {
            rtb_Mul += DW_tctlgc_Unit_Delay1_DSTATE_g;
        } else {
            rtb_Mul = rtb_SFunction_d;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate Controller/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate Controller/Constant16'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate Controller/P_TCTLGC_LdcMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate Controller/get_bit1/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate DT1-Part/P_TCTLGC_LdcMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate DT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate I-Part/P_TCTLGC_LdcMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate I-Part/get_bit1/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate PT1-Part/P_TCTLGC_LdcMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate PT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate Controller/get_bit1/Functionality'/S-Function'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Sum3/Functionality'/Sum'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_LdcMode_nu(), ((uint8)0U)))) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate PT1-Part/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate PT1-Part/Constant16'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate PT1-Part/P_TCTLGC_LdcMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate PT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate PT1-Part/get_bit1/Functionality'/S-Function'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_LdcMode_nu(), ((uint8) 3U)))) != 0) {
            rtb_Sum_fw = rtb_Mul;
        } else {
            rtb_Sum_fw = 0.0F;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate PT1-Part/Switch8/Functionality'/Switch' */
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate DT1-Part/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate DT1-Part/Constant16'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate DT1-Part/P_TCTLGC_LdcMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate DT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate DT1-Part/get_bit1/Functionality'/S-Function'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_LdcMode_nu(), ((uint8) 1U)))) != 0) {
            rtb_Switch_hf = rtb_SFunction_o;
        } else {
            rtb_Switch_hf = 0.0F;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate DT1-Part/Switch8/Functionality'/Switch' */
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate I-Part/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate I-Part/Constant16'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate I-Part/P_TCTLGC_LdcMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate I-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate I-Part/get_bit1/Functionality'/S-Function'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_LdcMode_nu(), ((uint8) 2U)))) != 0) {
            rtb_Switch_id = rtb_Mul_cn;
        } else {
            rtb_Switch_id = 0.0F;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate I-Part/Switch8/Functionality'/Switch' */
        rtb_Switch_j = ((rtb_MultiportSwitch2 + rtb_Switch_id) + rtb_Switch_hf) + rtb_Sum_fw;
    } else {
        rtb_Switch_j = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Activate Controller/Switch8/Functionality'/Switch' */
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay3' */
    rtb_MultiportSwitch6 = DW_tctlgc_Unit_Delay3_DSTATE_f;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_MultiportSwitch6 = rtb_Switch_j;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Div2/Functionality/Div'/Div' incorporates:
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Sum4/Functionality'/Sum'
         */
    rtb_MultiportSwitch6 = (rtb_Switch_j - rtb_MultiportSwitch6) / rtb_Switch;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Constant'/Constant'
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Max/Functionality'/Max'
         */
    rtb_Div_e = rtb_Switch / f32_max_f32_f32(0.03F, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay' */
    rtb_MultiportSwitch7 = DW_tctlgc_Unit_Delay_DSTATE_m;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_d4 = rtb_MultiportSwitch6;
    } else {
        rtb_SFunction_d4 = f32_mmv_f32_f32_f32( rtb_MultiportSwitch7, rtb_MultiportSwitch6, rtb_Div_e);
    }
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/IV'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Add/Functionality'/Sum'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum_fw = 0.0F;
    } else {
        if (((sint32)rtb_NE) != 0) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2'/Unit_Delay3'
                         */
            if (((sint32)rtb_DataTypeConversion) != 0) {
                rtb_Switch_id = rtb_SFunction_d4;
            } else {
                rtb_Switch_id = DW_tctlgc_Unit_Delay3_DSTATE_p;
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch' incorporates:
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Div2/Functionality/Div'/Div'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Mul4/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Mul9/Functionality'/Mul'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Sum3/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Sum5/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Neg/Functionality'/Unary Minus'
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Neg1/Functionality'/Unary Minus'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay3'
                         */
            rtb_Sum_fw = ((((rtb_Sum_fz * rtb_Switch_j) + (rtb_Sum_d * rtb_SFunction_d4)) + ((rtb_SFunction_d4 - rtb_Switch_id) / rtb_Switch)) - (((-rtb_Sum) + (-rtb_Sum_p)) * DW_tctlgc_Unit_Delay1_DSTATE)) - (((-rtb_Sum) * (-rtb_Sum_p)) * DW_tctlgc_Unit_Delay3_DSTATE);
        } else {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Constant2'/Constant'
                         */
            rtb_Sum_fw = 0.0F;
        }
        rtb_Sum_fw = (rtb_Switch * rtb_Sum_fw) + DW_tctlgc_Unit_Delay1_DSTATE;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MN'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MX'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch1'
         */
    if (rtb_Sum_fw >= 100.0F) {
        rtb_Sum_fw = 100.0F;
    } else {
        if (rtb_Sum_fw <= -100.0F) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MN'
                         */
            rtb_Sum_fw = -100.0F;
        }
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_hf = 0.0F;
    } else {
        rtb_Switch_hf = (rtb_Switch * rtb_Sum_fw) + DW_tctlgc_Unit_Delay_DSTATE;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch_hf >= 100.0F) {
        rtb_Switch_hf = 100.0F;
    } else {
        if (rtb_Switch_hf <= -100.0F) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch_hf = -100.0F;
        }
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/P_TCTLGC_CacLaDmcCompEnable_nu'/Constant'
         */
    if (((sint32)GET_P_TCTLGC_CacLaDmcCompEnable_nu()) != 0) {
        rtb_MultiportSwitch6 = rtb_Switch_hf;
    } else {
        rtb_MultiportSwitch6 = rtb_Switch_j;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Switch1/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch7' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/P_TCTLGC_CacPGain_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/P_TCTLGC_CacSfPGain_nu'/Constant'
         */
    switch (rtb_Switch_m3) {
    case 1:
        rtb_MultiportSwitch7 = GET_P_TCTLGC_CacPGain_nu();
        break;
    case 2:
        rtb_MultiportSwitch7 = GET_P_TCTLGC_CacOfPGain_nu();
        break;
    default:
        rtb_MultiportSwitch7 = GET_P_TCTLGC_CacSfPGain_nu();
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch7' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Mul4/Functionality'/Mul' */
    rtb_Mul_m = rtb_MultiportSwitch6 * rtb_MultiportSwitch7;
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPGainCrv_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_CrvFFC_1pm */
        FDPS_PTR_F32(GETA_X_TCTLGC_CrvFFC_1pm(), GET_S_TCTFFC_Crv_1pm(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_n1 = F32_PTR_IP1D(GETA_Y_TCTLGC_CacPGainCrv_nu(), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPGainCrv_nu/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTFFC_Crv_1pm'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPGainCrv_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_mq = rtb_ip_lookup_fxpt_sfun_7_n1;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch2' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Mul2/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfPGain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPGain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfPGain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPGain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D(GETA_Y_TCTLGC_CacPGain_nu(), &x_dps);
    }
    rtb_MultiportSwitch2_l = rtb_Sum_mq * rtb_ip_lookup_fxpt_sfun_7_h;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfPGain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_aj = F32_PTR_IP1D(GETA_Y_TCTLGC_CacOfPGain_nu(), &x_dps);
    }
    rtb_MultiportSwitch2_l = rtb_ip_lookup_fxpt_sfun_7_aj;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfPGain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_o3 = F32_PTR_IP1D(GETA_Y_TCTLGC_CacSfPGain_nu(), &x_dps);
    }
    rtb_MultiportSwitch2_l = rtb_ip_lookup_fxpt_sfun_7_o3 * rtb_Sum_mq;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch2' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Constant'/Constant'
         */
    rtb_Sum_mq = GET_P_TCTLGC_PGainGrdLimit_1ps() * rtb_Switch;
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain'/Unit_Delay'
         */
    rtb_MultiportSwitch6 = rtb_MultiportSwitch2_l - DW_tctlgc_Unit_Delay_DSTATE_fe;
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_fv = (uint8)(rtb_MultiportSwitch6 > rtb_Sum_mq);
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Constant'/Constant'
         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Neg/Functionality'/Unary Minus'
         */
    rtb_Mul_ey = (-GET_P_TCTLGC_PGainGrdLimit_1ps()) * rtb_Switch;
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_e4 = (uint8)(rtb_MultiportSwitch6 < rtb_Mul_ey);
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/OR1/Functionality'/OR'
         */
    rtb_RelationalOperator1 = (uint8)((((sint32)rtb_DataTypeConversion_dx) != 0) || (((sint32)rtb_EQ_l) != 0));
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain'/Unit_Delay1' */
    rtb_DataTypeConversion_le = DW_tctlgc_Unit_Delay1_DSTATE_lu;
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI'/Functionality'
         */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI'/IV'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_DataTypeConversion_no = 0U;
    } else {
        rtb_DataTypeConversion_no = DW_tctlgc_Unit_Delay_DSTATE_lt2;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI/Functionality'/Relational Operator'
         */
    rtb_DataTypeConversion_m = (uint8)((((sint32)rtb_RelationalOperator1) != ((sint32)rtb_DataTypeConversion_no)) || (((sint32)rtb_DataTypeConversion_le) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI'/fcg' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum_mq = rtb_MultiportSwitch2_l;
    } else if (((sint32)rtb_DataTypeConversion_m) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3'
                 *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain'/Unit_Delay'
                 */
        if (((sint32)rtb_RelationalOperator_fv) != 0) {
            rtb_Sum_mq += DW_tctlgc_Unit_Delay_DSTATE_fe;
        } else if (((sint32)rtb_RelationalOperator1_e4) != 0) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain'/Unit_Delay'
                         */
            rtb_Sum_mq = rtb_Mul_ey + DW_tctlgc_Unit_Delay_DSTATE_fe;
        } else {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
            rtb_Sum_mq = rtb_MultiportSwitch2_l;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    } else {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain'/Unit_Delay'
                 */
        rtb_Sum_mq = DW_tctlgc_Unit_Delay_DSTATE_fe;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_m) != 0) {
        rtb_MultiportSwitch6 = rtb_Sum_mq;
    } else {
        rtb_MultiportSwitch6 = rtb_MultiportSwitch2_l;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Switch1/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Mul8/Functionality'/Mul' */
    rtb_Mul_ey = rtb_Mul_m * rtb_MultiportSwitch6;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/Constant'/Constant'
         */
    rtb_Mul_gh = GET_P_TCTLGC_LdcPT1MaxGrd_radpms() * rtb_Switch;
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator'/Unit_Delay' */
    rtb_MultiportSwitch6 = DW_tctlgc_Unit_Delay_DSTATE_bf;
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
        rtb_Switch_id = -1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
        rtb_Switch_id = 1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
        rtb_Switch_id = 0.0F;
    } else {
        rtb_Switch_id = GET_S_TCTCDC_CtrlErrDistY_met();
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/Sign/Functionality'/Sign' */
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/Sign1/Functionality'/Sign' */
    if (rtb_MultiportSwitch6 < 0.0F) {
        rtb_MultiportSwitch6 = -1.0F;
    } else if (rtb_MultiportSwitch6 > 0.0F) {
        rtb_MultiportSwitch6 = 1.0F;
    } else {
        if (rtb_MultiportSwitch6 == 0.0F) {
            rtb_MultiportSwitch6 = 0.0F;
        }
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/Sign1/Functionality'/Sign' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/Constant2'/Constant'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/AND/Functionality'/AND'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator/EQ/Functionality'/EQ'
         */
    rtb_DataTypeConversion_le = (uint8)(((rtb_Switch_id * rtb_MultiportSwitch6) == -1.0F) && (((sint32)rtb_GE) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND18/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant9'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit17/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND18/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit17/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)4U)))) != 0) && (((sint32) rtb_DataTypeConversion_le) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND16/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant18'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit16/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND16/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit16/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_no = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)5U)))) != 0) && (((sint32) rtb_EQ_e) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant17'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit15/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND17/Functionality'/AND'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR5/Functionality'/OR'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit15/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_l = (uint8)(((((sint32)rtb_DataTypeConversion_le) != 0) || (((sint32)rtb_DataTypeConversion_no) != 0)) || ((((sint32)((uint8) flag_get_u8_u8(GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)6U)))) != 0) && (((sint32)rtb_DataTypeConversion_hp) != 0)));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)rtb_DataTypeConversion) != 0) || (((sint32)rtb_DataTypeConversion_l) != 0));
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacIGain_1ps/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfIGain_1ps/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfIGain_1ps/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacIGain_1ps/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_om = F32_PTR_IP1D(GETA_Y_TCTLGC_CacIGain_1ps(), &x_dps);
    }
    rtb_MultiportSwitch1 = rtb_ip_lookup_fxpt_sfun_7_om;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfIGain_1ps/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_aa = F32_PTR_IP1D(GETA_Y_TCTLGC_CacOfIGain_1ps(), &x_dps);
    }
    rtb_MultiportSwitch1 = rtb_ip_lookup_fxpt_sfun_7_aa;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfIGain_1ps/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_fi = F32_PTR_IP1D(GETA_Y_TCTLGC_CacSfIGain_1ps(), &x_dps);
    }
    rtb_MultiportSwitch1 = rtb_ip_lookup_fxpt_sfun_7_fi;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch1' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL'/IV'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/NOT/Functionality'/NOT'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch7'
         */
    if (((sint32)rtb_DataTypeConversion_le) != 0) {
        rtb_Switch7_f = 0.0F;
    } else if (!(((sint32)rtb_EQ) != 0)) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch7' incorporates:
                 *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
                 *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc'/Unit_Delay1'
                 */
        rtb_Switch7_f = ((rtb_MultiportSwitch1 * rtb_Switch) * rtb_Mul_ey) + DW_tctlgc_Unit_Delay1_DSTATE_n;
    } else {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch7' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc'/Unit_Delay1'
                 */
        rtb_Switch7_f = DW_tctlgc_Unit_Delay1_DSTATE_n;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/P_TCTLGC_CacILimit_rad'/Constant'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch1'
         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/Neg/Functionality'/Unary Minus'
         */
    if (rtb_Switch7_f >= GET_P_TCTLGC_CacILimit_rad()) {
        rtb_Switch7_f = GET_P_TCTLGC_CacILimit_rad();
    } else {
        if (rtb_Switch7_f <= (-GET_P_TCTLGC_CacILimit_rad())) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/Neg/Functionality'/Unary Minus'
                         */
            rtb_Switch7_f = -GET_P_TCTLGC_CacILimit_rad();
        }
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc'/Unit_Delay2'
         */
    rtb_Sum_pj = rtb_Switch7_f - DW_tctlgc_Unit_Delay2_DSTATE_e;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc'/Unit_Delay2'
         */
    if (rtb_Sum_pj > rtb_Mul_gh) {
        rtb_Mul_gh += DW_tctlgc_Unit_Delay2_DSTATE_e;
    } else {
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/Constant'/Constant'
                 *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/Neg1/Functionality'/Unary Minus'
                 */
        rtb_Mul_gh = (-GET_P_TCTLGC_LdcPT1MaxGrd_radpms()) * rtb_Switch;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc'/Unit_Delay2'
                 */
        if (rtb_Sum_pj < rtb_Mul_gh) {
            rtb_Mul_gh += DW_tctlgc_Unit_Delay2_DSTATE_e;
        } else {
            rtb_Mul_gh = rtb_Switch7_f;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_le = (uint8)(!(((sint32)rtb_EQ) != 0));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative/Constant'/Constant'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative/Div2/Functionality/Div'/Div'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative/Sum4/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_le) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative/Switch1/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative'/Unit_Delay3'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_Switch_id = rtb_Mul_ey;
        } else {
            rtb_Switch_id = DW_tctlgc_Unit_Delay3_DSTATE_m;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative/Switch1/Functionality'/Switch' */
        rtb_MultiportSwitch6 = (rtb_Mul_ey - rtb_Switch_id) / rtb_Switch;
    } else {
        rtb_MultiportSwitch6 = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch9' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Constant5'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Constant6'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch8'
         */
    if (((sint32)rtb_DataTypeConversion_m) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Constant4'
                 */
        if (((sint32)rtb_RelationalOperator_fv) != 0) {
            rtb_DataTypeConversion_no = 0U;
        } else {
            rtb_DataTypeConversion_no = rtb_RelationalOperator1_e4;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' */
        rtb_DataTypeConversion_le = rtb_RelationalOperator_fv;
    } else {
        rtb_DataTypeConversion_no = 0U;
        rtb_DataTypeConversion_le = 0U;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch9' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/OR/Functionality'/OR'
         */
    rtb_RelationalOperator_fv = (uint8)((((sint32)rtb_DataTypeConversion_no) != 0) || (((sint32)rtb_DataTypeConversion_le) != 0));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Constant1'/Constant'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Mul1/Functionality'/Mul'
         */
    if (((sint32)rtb_RelationalOperator_fv) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Constant1'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Constant2'/Constant'
                 */
        if (((sint32)rtb_DataTypeConversion_no) != 0) {
            rtb_DataTypeConversion_o = -1;
        } else {
            rtb_DataTypeConversion_o = 1;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain/Switch/Functionality'/Switch' */
        rtb_Mul_kz = (GET_P_TCTLGC_PGainGrdLimit_1ps() * ((float32) rtb_DataTypeConversion_o)) * rtb_Mul_m;
    } else {
        rtb_Mul_kz = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Switch2/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Sum/Functionality'/Sum' */
    rtb_Mul_m = rtb_MultiportSwitch6 - rtb_Mul_kz;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch3' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacDGain_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfDGain_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfDGain_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacDGain_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D(GETA_Y_TCTLGC_CacDGain_sec(), &x_dps);
    }
    rtb_Mul_kz = rtb_ip_lookup_fxpt_sfun_7_c;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfDGain_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_p4 = F32_PTR_IP1D(GETA_Y_TCTLGC_CacOfDGain_sec(), &x_dps);
    }
    rtb_Mul_kz = rtb_ip_lookup_fxpt_sfun_7_p4;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfDGain_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_nb = F32_PTR_IP1D(GETA_Y_TCTLGC_CacSfDGain_sec(), &x_dps);
    }
    rtb_Mul_kz = rtb_ip_lookup_fxpt_sfun_7_nb;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch3' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Mul4/Functionality'/Mul' */
    rtb_MultiportSwitch6 = rtb_Mul_m * rtb_Mul_kz;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch4' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D(GETA_Y_TCTLGC_CacDT1_sec(), &x_dps);
    }
    rtb_Mul_bp = rtb_ip_lookup_fxpt_sfun_7_m;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_jg = F32_PTR_IP1D(GETA_Y_TCTLGC_CacOfDT1_sec(), &x_dps);
    }
    rtb_Mul_bp = rtb_ip_lookup_fxpt_sfun_7_jg;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfDT1_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_ae = F32_PTR_IP1D(GETA_Y_TCTLGC_CacSfDT1_sec(), &x_dps);
    }
    rtb_Mul_bp = rtb_ip_lookup_fxpt_sfun_7_ae;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch4' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Max/Functionality'/Max'
         */
    rtb_Div_cv = rtb_Switch / f32_max_f32_f32(rtb_Mul_bp, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc'/Unit_Delay' */
    rtb_Switch_kl = DW_tctlgc_Unit_Delay_DSTATE_i1;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_l = rtb_MultiportSwitch6;
    } else {
        rtb_SFunction_l = f32_mmv_f32_f32_f32( rtb_Switch_kl, rtb_MultiportSwitch6, rtb_Div_cv);
    }
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/Constant'/Constant'
         */
    rtb_Mul_m = GET_P_TCTLGC_LdcPT1MaxGrd_radpms() * rtb_Switch;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch5' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_dl = F32_PTR_IP1D(GETA_Y_TCTLGC_CacPT1Gain_nu(), &x_dps);
    }
    rtb_Switch_kl = rtb_ip_lookup_fxpt_sfun_7_dl;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_lb = F32_PTR_IP1D(GETA_Y_TCTLGC_CacOfPT1Gain_nu(), &x_dps);
    }
    rtb_Switch_kl = rtb_ip_lookup_fxpt_sfun_7_lb;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfPT1Gain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_fh = F32_PTR_IP1D(GETA_Y_TCTLGC_CacSfPT1Gain_nu(), &x_dps);
    }
    rtb_Switch_kl = rtb_ip_lookup_fxpt_sfun_7_fh;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch5' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/Mul/Functionality'/Mul' */
    rtb_Mul_dl = rtb_Mul_ey * rtb_Switch_kl;
    /* MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch6' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m3) {
    case 1:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_i3 = F32_PTR_IP1D(GETA_Y_TCTLGC_CacPT1Time_sec(), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_i3;
    break;
    case 2:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacOfPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_ei = F32_PTR_IP1D(GETA_Y_TCTLGC_CacOfPT1Time_sec (), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_ei;
    break;
    default:
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains/Y_TCTLGC_CacSfPT1Time_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_cj = F32_PTR_IP1D(GETA_Y_TCTLGC_CacSfPT1Time_sec (), &x_dps);
    }
    rtb_MultiportSwitch6 = rtb_ip_lookup_fxpt_sfun_7_cj;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Calculate Cac Gains'/Multiport Switch6' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/Max/Functionality'/Max'
         */
    rtb_Div_a = rtb_Switch / f32_max_f32_f32(rtb_MultiportSwitch6, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1'/Unit_Delay' */
    rtb_UnitDelay2 = DW_tctlgc_Unit_Delay_DSTATE_lt;
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
        rtb_Switch_id = -1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
        rtb_Switch_id = 1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
        rtb_Switch_id = 0.0F;
    } else {
        rtb_Switch_id = GET_S_TCTCDC_CtrlErrDistY_met();
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/Sign/Functionality'/Sign' */
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/Sign1/Functionality'/Sign' */
    if (rtb_UnitDelay2 < 0.0F) {
        rtb_UnitDelay2 = -1.0F;
    } else if (rtb_UnitDelay2 > 0.0F) {
        rtb_UnitDelay2 = 1.0F;
    } else {
        if (rtb_UnitDelay2 == 0.0F) {
            rtb_UnitDelay2 = 0.0F;
        }
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/Sign1/Functionality'/Sign' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/Constant2'/Constant'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/AND/Functionality'/AND'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1/EQ/Functionality'/EQ'
         */
    rtb_DataTypeConversion_le = (uint8)(((rtb_Switch_id * rtb_UnitDelay2) == -1.0F) && (((sint32)rtb_GE) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND15/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant5'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit14/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND15/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit14/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)4U)))) != 0) && (((sint32) rtb_DataTypeConversion_le) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND13/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit13/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND13/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit13/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_no = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)5U)))) != 0) && (((sint32) rtb_EQ_e) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant4'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit12/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND14/Functionality'/AND'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR4/Functionality'/OR'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit12/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_m = (uint8)(((((sint32)rtb_DataTypeConversion_le) != 0) || (((sint32)rtb_DataTypeConversion_no) != 0)) || ((((sint32)((uint8) flag_get_u8_u8(GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)6U)))) != 0) && (((sint32)rtb_DataTypeConversion_hp) != 0)));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/OR2/Functionality'/OR'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)rtb_DataTypeConversion_m) != 0) || (((sint32)rtb_DataTypeConversion) != 0));
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc'/Unit_Delay' */
    rtb_UnitDelay2 = DW_tctlgc_Unit_Delay_DSTATE_im;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_le != 0U) {
        rtb_SFunction_h = 0.0F;
    } else {
        rtb_SFunction_h = f32_mmv_f32_f32_f32( rtb_UnitDelay2, rtb_Mul_dl, rtb_Div_a);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc'/Unit_Delay1'
         */
    rtb_Sum_pj = rtb_SFunction_h - DW_tctlgc_Unit_Delay1_DSTATE_l;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc'/Unit_Delay1'
         */
    if (rtb_Sum_pj > rtb_Mul_m) {
        rtb_Mul_m += DW_tctlgc_Unit_Delay1_DSTATE_l;
    } else {
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/Constant'/Constant'
                 *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/Neg/Functionality'/Unary Minus'
                 */
        rtb_Mul_m = (-GET_P_TCTLGC_LdcPT1MaxGrd_radpms()) * rtb_Switch;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc'/Unit_Delay1'
                 */
        if (rtb_Sum_pj < rtb_Mul_m) {
            rtb_Mul_m += DW_tctlgc_Unit_Delay1_DSTATE_l;
        } else {
            rtb_Mul_m = rtb_SFunction_h;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Check if Ldc is active/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate Controller/P_TCTLGC_CacMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate Controller/get_bit1/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Check if Ldc is active/Constant16'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Check if Ldc is active/P_TCTLGC_LdcMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Check if Ldc is active/get_bit1/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Check if Ldc is active/get_bit1/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_LdcMode_nu(), ((uint8)0U)))) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate Controller/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate Controller/P_TCTLGC_CacMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate Controller/get_bit1/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate DT1-Part/P_TCTLGC_CacMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate DT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate I-Part/P_TCTLGC_CacMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate I-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate PT1-Part/P_TCTLGC_CacMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate PT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate Controller/get_bit1/Functionality'/S-Function'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Sum3/Functionality'/Sum'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CacMode_nu(), ((uint8) 0U)))) != 0) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate PT1-Part/Switch8/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate PT1-Part/Constant16'/Constant'
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate PT1-Part/P_TCTLGC_CacMode_nu'/Constant'
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate PT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
                         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate PT1-Part/get_bit1/Functionality'/S-Function'
                         */
            if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CacMode_nu(), ((uint8) 3U)))) != 0) {
                rtb_Sum_pj = rtb_Mul_m;
            } else {
                rtb_Sum_pj = 0.0F;
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate PT1-Part/Switch8/Functionality'/Switch' */
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate DT1-Part/Switch8/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate DT1-Part/Constant16'/Constant'
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate DT1-Part/P_TCTLGC_CacMode_nu'/Constant'
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate DT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
                         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate DT1-Part/get_bit1/Functionality'/S-Function'
                         */
            if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CacMode_nu(), ((uint8) 1U)))) != 0) {
                rtb_Switch_cw = rtb_SFunction_l;
            } else {
                rtb_Switch_cw = 0.0F;
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate DT1-Part/Switch8/Functionality'/Switch' */
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate I-Part/Switch8/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate I-Part/Constant16'/Constant'
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate I-Part/P_TCTLGC_CacMode_nu'/Constant'
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate I-Part/get_bit1/Functionality'/Const_bit_sel_param'
                         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate I-Part/get_bit1/Functionality'/S-Function'
                         */
            if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CacMode_nu(), ((uint8) 2U)))) != 0) {
                rtb_Switch_id = rtb_Mul_gh;
            } else {
                rtb_Switch_id = 0.0F;
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate I-Part/Switch8/Functionality'/Switch' */
            rtb_Sum_pj += (rtb_Mul_ey + rtb_Switch_id) + rtb_Switch_cw;
        } else {
            rtb_Sum_pj = rtb_Switch_j;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Activate Controller/Switch8/Functionality'/Switch' */
    } else {
        rtb_Sum_pj = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Check if Ldc is active/Switch8/Functionality'/Switch' */
    /* Inport: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC'/S_TCTCDC_CtrlErrHeadAglPrev_rad' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrHeadAglPrev_rad'
         *
         * Block description for 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC'/S_TCTCDC_CtrlErrHeadAglPrev_rad':
         *
         *  FAS35up.Name=TrajCtrl_CalcCtrlVar_CtrlErrHeadingAnglePred_rad
         */
    rtb_S_TCTCDC_CtrlErrHeadAglPrev_rad = GET_S_TCTCDC_CtrlErrHeadAglPrev_rad();
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1 Low Pass/Y_TCTLGC_PT1CoAnErrTime_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l1 = F32_PTR_IP1D(GETA_Y_TCTLGC_PT1CoAnErrTime_sec (), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1 Low Pass/Y_TCTLGC_PT1CoAnErrTime_sec/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1 Low Pass/Y_TCTLGC_PT1CoAnErrTime_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_UnitDelay2 = rtb_ip_lookup_fxpt_sfun_7_l1;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1 Low Pass/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1 Low Pass/Max/Functionality'/Max'
         */
    rtb_Div_f = rtb_Switch / f32_max_f32_f32(rtb_UnitDelay2, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1 Low Pass'/Unit_Delay' */
    rtb_UnitDelay2 = DW_tctlgc_Unit_Delay_DSTATE_feo;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1 Low Pass/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_m = rtb_S_TCTCDC_CtrlErrHeadAglPrev_rad;
    } else {
        rtb_SFunction_m = f32_mmv_f32_f32_f32( rtb_UnitDelay2, rtb_S_TCTCDC_CtrlErrHeadAglPrev_rad, rtb_Div_f);
    }
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Constant'/Constant'
         */
    if (((sint32)GET_P_TCTLGC_PT1CoAnErrEnable_nu()) != 0) {
        rtb_Switch_cw = rtb_SFunction_m;
    } else {
        rtb_Switch_cw = rtb_S_TCTCDC_CtrlErrHeadAglPrev_rad;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Switch2/Functionality'/Switch' */
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay3' */
    rtb_UnitDelay2 = DW_tctlgc_Unit_Delay3_DSTATE_ex;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_UnitDelay2 = rtb_Switch_cw;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Div2/Functionality/Div'/Div' incorporates:
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Sum4/Functionality'/Sum'
         */
    rtb_UnitDelay2 = (rtb_Switch_cw - rtb_UnitDelay2) / rtb_Switch;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Constant'/Constant'
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/Max/Functionality'/Max'
         */
    rtb_Div_cd = rtb_Switch / f32_max_f32_f32(0.03F, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay' */
    rtb_UnitDelay2_h = DW_tctlgc_Unit_Delay_DSTATE_o;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_g = rtb_UnitDelay2;
    } else {
        rtb_SFunction_g = f32_mmv_f32_f32_f32( rtb_UnitDelay2_h, rtb_UnitDelay2, rtb_Div_cd);
    }
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/IV'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality/Add/Functionality'/Sum'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum = 0.0F;
    } else {
        if (((sint32)rtb_NE) != 0) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2'/Unit_Delay3'
                         */
            if (((sint32)rtb_DataTypeConversion) != 0) {
                rtb_Switch_id = rtb_SFunction_g;
            } else {
                rtb_Switch_id = DW_tctlgc_Unit_Delay3_DSTATE_h;
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch' incorporates:
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Div2/Functionality/Div'/Div'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul4/Functionality'/Mul'
                         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Mul9/Functionality'/Mul'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum3/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Sum5/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Neg/Functionality'/Unary Minus'
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Neg1/Functionality'/Unary Minus'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay3'
                         */
            rtb_Sum = ((((rtb_Sum_fz * rtb_Switch_cw) + (rtb_Sum_d * rtb_SFunction_g)) + ((rtb_SFunction_g - rtb_Switch_id) / rtb_Switch)) - (((-rtb_Sum) + (-rtb_Sum_p)) * DW_tctlgc_Unit_Delay1_DSTATE_e)) - (((-rtb_Sum) * (-rtb_Sum_p)) * DW_tctlgc_Unit_Delay3_DSTATE_ep);
        } else {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Constant2'/Constant'
                         */
            rtb_Sum = 0.0F;
        }
        rtb_Sum = (rtb_Switch * rtb_Sum) + DW_tctlgc_Unit_Delay1_DSTATE_e;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MN'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MX'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch1'
         */
    if (rtb_Sum >= 100.0F) {
        rtb_Sum = 100.0F;
    } else {
        if (rtb_Sum <= -100.0F) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4'/MN'
                         */
            rtb_Sum = -100.0F;
        }
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL4/Functionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum_p = 0.0F;
    } else {
        rtb_Sum_p = (rtb_Switch * rtb_Sum) + DW_tctlgc_Unit_Delay_DSTATE_l3;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Sum_p >= 100.0F) {
        rtb_Sum_p = 100.0F;
    } else {
        if (rtb_Sum_p <= -100.0F) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL'/MN'
                         */
            rtb_Sum_p = -100.0F;
        }
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/P_TCTLGC_CacLaDmcCompEnable_nu'/Constant'
         */
    if (((sint32)GET_P_TCTLGC_CacLaDmcCompEnable_nu()) != 0) {
        rtb_UnitDelay2_h = rtb_Sum_p;
    } else {
        rtb_UnitDelay2_h = rtb_Switch_cw;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Switch1/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Mul4/Functionality'/Mul' */
    rtb_MultiportSwitch7 *= rtb_UnitDelay2_h;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Constant'/Constant'
         */
    rtb_Sum_fz = GET_P_TCTLGC_PGainGrdLimit_1ps() * rtb_Switch;
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain'/Unit_Delay'
         */
    rtb_UnitDelay2_h = rtb_MultiportSwitch2_l - DW_tctlgc_Unit_Delay_DSTATE_c;
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_i = (uint8)(rtb_UnitDelay2_h > rtb_Sum_fz);
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Constant'/Constant'
         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Neg/Functionality'/Unary Minus'
         */
    rtb_Sum_d = (-GET_P_TCTLGC_PGainGrdLimit_1ps()) * rtb_Switch;
    /* RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_c = (uint8)(rtb_UnitDelay2_h < rtb_Sum_d);
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/OR1/Functionality'/OR'
         */
    rtb_EQ_l = (uint8)((((sint32)rtb_DataTypeConversion_dx) != 0) || (((sint32) rtb_EQ_l) != 0));
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain'/Unit_Delay1' */
    rtb_DataTypeConversion_le = DW_tctlgc_Unit_Delay1_DSTATE_ph;
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI'/Functionality'
         */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI'/IV'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_DataTypeConversion_no = 0U;
    } else {
        rtb_DataTypeConversion_no = DW_tctlgc_Unit_Delay_DSTATE_af;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI/Functionality'/Relational Operator'
         */
    rtb_DataTypeConversion_a = (uint8)((((sint32)rtb_EQ_l) != ((sint32) rtb_DataTypeConversion_no)) || (((sint32)rtb_DataTypeConversion_le) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI'/fcg' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum_fz = rtb_MultiportSwitch2_l;
    } else if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3'
                 *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain'/Unit_Delay'
                 */
        if (((sint32)rtb_RelationalOperator_i) != 0) {
            rtb_Sum_fz += DW_tctlgc_Unit_Delay_DSTATE_c;
        } else if (((sint32)rtb_RelationalOperator1_c) != 0) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain'/Unit_Delay'
                         */
            rtb_Sum_fz = rtb_Sum_d + DW_tctlgc_Unit_Delay_DSTATE_c;
        } else {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
            rtb_Sum_fz = rtb_MultiportSwitch2_l;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    } else {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain'/Unit_Delay'
                 */
        rtb_Sum_fz = DW_tctlgc_Unit_Delay_DSTATE_c;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        rtb_UnitDelay2_h = rtb_Sum_fz;
    } else {
        rtb_UnitDelay2_h = rtb_MultiportSwitch2_l;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Switch1/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Mul8/Functionality'/Mul' */
    rtb_Sum_d = rtb_MultiportSwitch7 * rtb_UnitDelay2_h;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/Constant'/Constant'
         */
    rtb_Mul_og = GET_P_TCTLGC_LdcPT1MaxGrd_radpms() * rtb_Switch;
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator'/Unit_Delay' */
    rtb_UnitDelay2_h = DW_tctlgc_Unit_Delay_DSTATE_k;
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
        rtb_Switch_id = -1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
        rtb_Switch_id = 1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
        rtb_Switch_id = 0.0F;
    } else {
        rtb_Switch_id = GET_S_TCTCDC_CtrlErrDistY_met();
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/Sign/Functionality'/Sign' */
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/Sign1/Functionality'/Sign' */
    if (rtb_UnitDelay2_h < 0.0F) {
        rtb_UnitDelay2_h = -1.0F;
    } else if (rtb_UnitDelay2_h > 0.0F) {
        rtb_UnitDelay2_h = 1.0F;
    } else {
        if (rtb_UnitDelay2_h == 0.0F) {
            rtb_UnitDelay2_h = 0.0F;
        }
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/Sign1/Functionality'/Sign' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/Constant2'/Constant'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/AND/Functionality'/AND'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator/EQ/Functionality'/EQ'
         */
    rtb_DataTypeConversion_le = (uint8)(((rtb_Switch_id * rtb_UnitDelay2_h) == -1.0F) && (((sint32)rtb_GE) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND12/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant14'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit11/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND12/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit11/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)4U)))) != 0) && (((sint32) rtb_DataTypeConversion_le) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND10/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant16'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit10/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND10/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit10/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_no = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)5U)))) != 0) && (((sint32) rtb_EQ_e) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant15'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit9/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND11/Functionality'/AND'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR3/Functionality'/OR'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit9/Functionality'/S-Function'
         */
    rtb_RelationalOperator1_e4 = (uint8)(((((sint32)rtb_DataTypeConversion_le) != 0) || (((sint32)rtb_DataTypeConversion_no) != 0)) || ((((sint32)((uint8) flag_get_u8_u8(GET_P_TCTLGC_DynIntResetSelect_nu(), ((uint8)6U)))) != 0) && (((sint32)rtb_DataTypeConversion_hp) != 0)));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)rtb_DataTypeConversion) != 0) || (((sint32)rtb_RelationalOperator1_e4) != 0));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL'/IV'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/NOT/Functionality'/NOT'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch7'
         */
    if (((sint32)rtb_DataTypeConversion_le) != 0) {
        rtb_UnitDelay2_h = 0.0F;
    } else if (!(((sint32)rtb_EQ) != 0)) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch7' incorporates:
                 *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
                 *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac'/Unit_Delay1'
                 */
        rtb_UnitDelay2_h = ((rtb_MultiportSwitch1 * rtb_Switch) * rtb_Sum_d) + DW_tctlgc_Unit_Delay1_DSTATE_gf;
    } else {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch7' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac'/Unit_Delay1'
                 */
        rtb_UnitDelay2_h = DW_tctlgc_Unit_Delay1_DSTATE_gf;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/P_TCTLGC_CacILimit_rad'/Constant'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch1'
         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/Neg/Functionality'/Unary Minus'
         */
    if (rtb_UnitDelay2_h >= GET_P_TCTLGC_CacILimit_rad()) {
        rtb_MultiportSwitch2_l = GET_P_TCTLGC_CacILimit_rad();
    } else if (rtb_UnitDelay2_h <= (-GET_P_TCTLGC_CacILimit_rad())) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                 *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/Neg/Functionality'/Unary Minus'
                 */
        rtb_MultiportSwitch2_l = -GET_P_TCTLGC_CacILimit_rad();
    } else {
        rtb_MultiportSwitch2_l = rtb_UnitDelay2_h;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac'/Unit_Delay2'
         */
    rtb_UnitDelay2_h = rtb_MultiportSwitch2_l - DW_tctlgc_Unit_Delay2_DSTATE_j;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac'/Unit_Delay2'
         */
    if (rtb_UnitDelay2_h > rtb_Mul_og) {
        rtb_MultiportSwitch1 = rtb_Mul_og + DW_tctlgc_Unit_Delay2_DSTATE_j;
    } else {
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/Constant'/Constant'
                 *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/Neg1/Functionality'/Unary Minus'
                 */
        rtb_MultiportSwitch1 = (-GET_P_TCTLGC_LdcPT1MaxGrd_radpms()) * rtb_Switch;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac'/Unit_Delay2'
                 */
        if (rtb_UnitDelay2_h < rtb_MultiportSwitch1) {
            rtb_MultiportSwitch1 += DW_tctlgc_Unit_Delay2_DSTATE_j;
        } else {
            rtb_MultiportSwitch1 = rtb_MultiportSwitch2_l;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_le = (uint8)(!(((sint32)rtb_EQ) != 0));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative/Constant'/Constant'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative/Div2/Functionality/Div'/Div'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative/Sum4/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_le) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative/Switch1/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative'/Unit_Delay3'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_Switch_id = rtb_Sum_d;
        } else {
            rtb_Switch_id = DW_tctlgc_Unit_Delay3_DSTATE_ms;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative/Switch1/Functionality'/Switch' */
        rtb_UnitDelay2_h = (rtb_Sum_d - rtb_Switch_id) / rtb_Switch;
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch9' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Constant5'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Constant6'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch8'
         */
    if (((sint32)rtb_DataTypeConversion_a) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Constant4'
                 */
        if (((sint32)rtb_RelationalOperator_i) != 0) {
            rtb_DataTypeConversion_no = 0U;
        } else {
            rtb_DataTypeConversion_no = rtb_RelationalOperator1_c;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' */
        rtb_DataTypeConversion_le = rtb_RelationalOperator_i;
    } else {
        rtb_DataTypeConversion_no = 0U;
        rtb_DataTypeConversion_le = 0U;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/GRADIENTLIMITER/Functionality'/Switch9' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/OR1/Functionality'/OR'
         */
    rtb_RelationalOperator_i = (uint8)((((sint32)rtb_DataTypeConversion_no) != 0) || (((sint32)rtb_DataTypeConversion_le) != 0));
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Constant1'/Constant'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Mul1/Functionality'/Mul'
         */
    if (((sint32)rtb_RelationalOperator_i) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Constant1'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Constant2'/Constant'
                 */
        if (((sint32)rtb_DataTypeConversion_no) != 0) {
            rtb_DataTypeConversion_o = -1;
        } else {
            rtb_DataTypeConversion_o = 1;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain/Switch/Functionality'/Switch' */
        rtb_UnitDelay2 = (GET_P_TCTLGC_PGainGrdLimit_1ps() * ((float32) rtb_DataTypeConversion_o)) * rtb_MultiportSwitch7;
    } else {
        rtb_UnitDelay2 = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Switch2/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Mul4/Functionality'/Mul' incorporates:
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Sum/Functionality'/Sum'
         */
    rtb_Mul_kz *= rtb_UnitDelay2_h - rtb_UnitDelay2;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Max/Functionality'/Max'
         */
    rtb_Div_i = rtb_Switch / f32_max_f32_f32(rtb_Mul_bp, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac'/Unit_Delay' */
    rtb_UnitDelay2_h = DW_tctlgc_Unit_Delay_DSTATE_d;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_hn = rtb_Mul_kz;
    } else {
        rtb_SFunction_hn = f32_mmv_f32_f32_f32( rtb_UnitDelay2_h, rtb_Mul_kz, rtb_Div_i);
    }
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/Constant'/Constant'
         */
    rtb_Mul_bp = GET_P_TCTLGC_LdcPT1MaxGrd_radpms() * rtb_Switch;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/Mul/Functionality'/Mul' */
    rtb_Mul_ge = rtb_Sum_d * rtb_Switch_kl;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/Max/Functionality'/Max'
         */
    rtb_Div_ah = rtb_Switch / f32_max_f32_f32(rtb_MultiportSwitch6, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1'/Unit_Delay' */
    rtb_UnitDelay2_h = DW_tctlgc_Unit_Delay_DSTATE_p;
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
         */
    if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
        rtb_Switch_id = -1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
        rtb_Switch_id = 1.0F;
    } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
        rtb_Switch_id = 0.0F;
    } else {
        rtb_Switch_id = GET_S_TCTCDC_CtrlErrDistY_met();
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/Sign/Functionality'/Sign' */
    /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/Sign1/Functionality'/Sign' */
    if (rtb_UnitDelay2_h < 0.0F) {
        rtb_UnitDelay2_h = -1.0F;
    } else if (rtb_UnitDelay2_h > 0.0F) {
        rtb_UnitDelay2_h = 1.0F;
    } else {
        if (rtb_UnitDelay2_h == 0.0F) {
            rtb_UnitDelay2_h = 0.0F;
        }
    }
    /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/Sign1/Functionality'/Sign' */
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/Constant2'/Constant'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/AND/Functionality'/AND'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1/EQ/Functionality'/EQ'
         */
    rtb_DataTypeConversion_le = (uint8)(((rtb_Switch_id * rtb_UnitDelay2_h) == -1.0F) && (((sint32)rtb_GE) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant13'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit8/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND9/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit8/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)4U)))) != 0) && (((sint32) rtb_DataTypeConversion_le) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant11'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit7/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND7/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit7/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_no = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)5U)))) != 0) && (((sint32) rtb_EQ_e) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/Constant12'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit6/Functionality'/Const_bit_sel_param'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/AND8/Functionality'/AND'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/get_bit6/Functionality'/S-Function'
         */
    rtb_DataTypeConversion_hp = (uint8)((((sint32)((uint8)flag_get_u8_u8 (GET_P_TCTLGC_DynPT1ResetSelect_nu(), ((uint8)6U)))) != 0) && (((sint32) rtb_DataTypeConversion_hp) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/Reset Bitmasks/OR2/Functionality'/OR'
         */
    rtb_GE = (uint8)(((((sint32)rtb_DataTypeConversion_le) != 0) || (((sint32) rtb_DataTypeConversion_no) != 0)) || (((sint32)rtb_DataTypeConversion_hp) != 0));
    /* DataTypeConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/OR2/Functionality'/OR'
         */
    rtb_DataTypeConversion_le = (uint8)((((sint32)rtb_GE) != 0) || (((sint32) rtb_DataTypeConversion) != 0));
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc'/Unit_Delay' */
    rtb_UnitDelay2_h = DW_tctlgc_Unit_Delay_DSTATE_h;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_le != 0U) {
        rtb_SFunction_c = 0.0F;
    } else {
        rtb_SFunction_c = f32_mmv_f32_f32_f32( rtb_UnitDelay2_h, rtb_Mul_ge, rtb_Div_ah);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc'/Unit_Delay1'
         */
    rtb_UnitDelay2_h = rtb_SFunction_c - DW_tctlgc_Unit_Delay1_DSTATE_f;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc'/Unit_Delay1'
         */
    if (rtb_UnitDelay2_h > rtb_Mul_bp) {
        rtb_MultiportSwitch6 = rtb_Mul_bp + DW_tctlgc_Unit_Delay1_DSTATE_f;
    } else {
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/Constant'/Constant'
                 *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/Neg/Functionality'/Unary Minus'
                 */
        rtb_Switch_kl = (-GET_P_TCTLGC_LdcPT1MaxGrd_radpms()) * rtb_Switch;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc'/Unit_Delay1'
                 */
        if (rtb_UnitDelay2_h < rtb_Switch_kl) {
            rtb_MultiportSwitch6 = rtb_Switch_kl + DW_tctlgc_Unit_Delay1_DSTATE_f;
        } else {
            rtb_MultiportSwitch6 = rtb_SFunction_c;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate Controller/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate Controller/Constant16'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate Controller/P_TCTLGC_CacMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate Controller/get_bit1/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate DT1-Part/P_TCTLGC_CacMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate DT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate I-Part/P_TCTLGC_CacMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate I-Part/get_bit1/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate PT1-Part/P_TCTLGC_CacMode_nu'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate PT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate Controller/get_bit1/Functionality'/S-Function'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Sum3/Functionality'/Sum'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CacMode_nu(), ((uint8)0U)))) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate PT1-Part/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate PT1-Part/Constant16'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate PT1-Part/P_TCTLGC_CacMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate PT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate PT1-Part/get_bit1/Functionality'/S-Function'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CacMode_nu(), ((uint8) 3U)))) != 0) {
            rtb_UnitDelay2_h = rtb_MultiportSwitch6;
        } else {
            rtb_UnitDelay2_h = 0.0F;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate PT1-Part/Switch8/Functionality'/Switch' */
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate DT1-Part/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate DT1-Part/Constant16'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate DT1-Part/P_TCTLGC_CacMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate DT1-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate DT1-Part/get_bit1/Functionality'/S-Function'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CacMode_nu(), ((uint8) 1U)))) != 0) {
            rtb_Switch_kl = rtb_SFunction_hn;
        } else {
            rtb_Switch_kl = 0.0F;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate DT1-Part/Switch8/Functionality'/Switch' */
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate I-Part/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate I-Part/Constant16'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate I-Part/P_TCTLGC_CacMode_nu'/Constant'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate I-Part/get_bit1/Functionality'/Const_bit_sel_param'
                 *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate I-Part/get_bit1/Functionality'/S-Function'
                 */
        if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CacMode_nu(), ((uint8) 2U)))) != 0) {
            rtb_Switch_id = rtb_MultiportSwitch1;
        } else {
            rtb_Switch_id = 0.0F;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate I-Part/Switch8/Functionality'/Switch' */
        rtb_MultiportSwitch7 = ((rtb_Sum_d + rtb_Switch_id) + rtb_Switch_kl) + rtb_UnitDelay2_h;
    } else {
        rtb_MultiportSwitch7 = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Activate Controller/Switch8/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Sum/Functionality'/Sum' */
    rtb_Mul_og = rtb_Sum_pj + rtb_MultiportSwitch7;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg/Div1/Functionality/DivDefault'/Div' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg/Constant3'/Constant'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg/Mul1/Functionality'/Mul'
         */
    rtb_Div_o = (180.0F * rtb_Mul_og) / 3.14159274F;
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/PT1 Low Pass/Y_TCTLGC_PT1DeltaFCmdTime_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_o = F32_PTR_IP1D (GETA_Y_TCTLGC_PT1DeltaFCmdTime_sec(), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/PT1 Low Pass/Y_TCTLGC_PT1DeltaFCmdTime_sec/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/PT1 Low Pass/Y_TCTLGC_PT1DeltaFCmdTime_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_UnitDelay2_h = rtb_ip_lookup_fxpt_sfun_7_o;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/PT1 Low Pass/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/PT1 Low Pass/Max/Functionality'/Max'
         */
    rtb_Div_j = rtb_Max / f32_max_f32_f32(rtb_UnitDelay2_h, rtb_Max);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/PT1 Low Pass'/Unit_Delay' */
    rtb_UnitDelay2_h = DW_tctlgc_Unit_Delay_DSTATE_gr;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/PT1 Low Pass/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_dr = rtb_Div_o;
    } else {
        rtb_SFunction_dr = f32_mmv_f32_f32_f32( rtb_UnitDelay2_h, rtb_Div_o, rtb_Div_j);
    }
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit3/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit3/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssDeltaF_nu(), ((uint8) 0U)))) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant13'/Constant'
                 */
        if (((sint32)GET_P_TCTLGC_PT1DeltaFCmdEnable_nu()) != 0) {
            rtb_UnitDelay2_h = rtb_SFunction_dr;
        } else {
            rtb_UnitDelay2_h = rtb_Div_o;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Switch2/Functionality'/Switch' */
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch2/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Sum/Functionality'/Sum' */
    rtb_Switch_kl = rtb_UnitDelay2_h;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg1/Div1/Functionality/DivDefault'/Div' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg1/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg1/Constant3'/Constant'
         *  Inport: '<Root>/S_TCTDTE_DeltaSetDstrbComp_rad'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg1/Mul1/Functionality'/Mul'
         */
    rtb_Div_i1 = (180.0F * GET_S_TCTDTE_DeltaSetDstrbComp_rad()) / 3.14159274F;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Constant4'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit5/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit5/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssDeltaF_nu(), ((uint8) 2U)))) != 0) {
        rtb_UnitDelay2_h = rtb_Div_i1;
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Sum1/Functionality'/Sum' */
    rtb_Switch_kl += rtb_UnitDelay2_h;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Constant'/Constant'
         *  Inport: '<Root>/S_TCTDTE_DeltaSetBnkAglComp_rad'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Mul2/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Y_TCTLGC_DynBacGain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    if (((sint32)GET_P_TCTLGC_ActivateDynBacGain_nu()) != 0) {
        /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Sign/Functionality'/Sign' incorporates:
                 *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
                 */
        if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
            rtb_Switch_id = -1.0F;
        } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
            rtb_Switch_id = 1.0F;
        } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
            rtb_Switch_id = 0.0F;
        } else {
            rtb_Switch_id = GET_S_TCTCDC_CtrlErrDistY_met();
        }
        /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Sign/Functionality'/Sign' */
        /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Sign1/Functionality'/Sign' incorporates:
                 *  Inport: '<Root>/S_TCTDTE_DeltaSetBnkAglComp_rad'
                 */
        if (GET_S_TCTDTE_DeltaSetBnkAglComp_rad() < 0.0F) {
            rtb_Mul_bp = -1.0F;
        } else if (GET_S_TCTDTE_DeltaSetBnkAglComp_rad() > 0.0F) {
            rtb_Mul_bp = 1.0F;
        } else if (GET_S_TCTDTE_DeltaSetBnkAglComp_rad() == 0.0F) {
            rtb_Mul_bp = 0.0F;
        } else {
            rtb_Mul_bp = GET_S_TCTDTE_DeltaSetBnkAglComp_rad();
        }
        /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Sign1/Functionality'/Sign' */
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Mul1/Functionality'/Mul' incorporates:
                 *  Abs: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Abs/Functionality'/Abs'
                 *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
                 *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Mul/Functionality'/Mul'
                 */
        rtb_Mul_oq = (rtb_Switch_id * rtb_Mul_bp) * f32_abs_f32 (GET_S_TCTCDC_CtrlErrDistY_met());
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Y_TCTLGC_DynBacGain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTLGC_CtrlErrDistY_met */
            FDPS_PTR_F32(GETA_X_TCTLGC_CtrlErrDistY_met(), rtb_Mul_oq, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_lw = F32_PTR_IP1D(GETA_Y_TCTLGC_DynBacGain_nu(), &x_dps);
        }
        rtb_UnitDelay2_h = rtb_ip_lookup_fxpt_sfun_7_lw * GET_S_TCTDTE_DeltaSetBnkAglComp_rad();
    } else {
        rtb_UnitDelay2_h = GET_S_TCTDTE_DeltaSetBnkAglComp_rad();
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg3/Div1/Functionality/DivDefault'/Div' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg3/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg3/Constant3'/Constant'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg3/Mul1/Functionality'/Mul'
         */
    rtb_Div_go = (180.0F * rtb_UnitDelay2_h) / 3.14159274F;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit1/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit1/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssDeltaF_nu(), ((uint8) 3U)))) != 0) {
        rtb_UnitDelay2_h = rtb_Div_go;
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Sum3/Functionality'/Sum' */
    rtb_Switch_kl += rtb_UnitDelay2_h;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Constant5'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit2/Functionality'/Const_bit_sel_param'
         *  Inport: '<Root>/S_TCTDEV_DeltaFCmdTestSignal_deg'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit2/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssDeltaF_nu(), ((uint8) 4U)))) != 0) {
        rtb_UnitDelay2_h = GET_S_TCTDEV_DeltaFCmdTestSignal_deg();
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Sum2/Functionality'/Sum' */
    rtb_Switch_kl += rtb_UnitDelay2_h;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg4/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg4/Constant3'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Constant6'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit6/Functionality'/Const_bit_sel_param'
         *  Inport: '<Root>/S_TCTDTE_DeltaSetCroWiComp_rad'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg4/Div1/Functionality/DivDefault'/Div'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/rad_to_deg4/Mul1/Functionality'/Mul'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/get_bit6/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssDeltaF_nu(), ((uint8) 5U)))) != 0) {
        rtb_UnitDelay2_h = (180.0F * GET_S_TCTDTE_DeltaSetCroWiComp_rad()) / 3.14159274F;
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Switch6/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select/Sum4/Functionality'/Sum' */
    rtb_Sum_o = rtb_Switch_kl + rtb_UnitDelay2_h;
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Constant4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Sum/Functionality'/Sum'
         */
    rtb_UnitDelay2_h = (((GET_S_LCFRCV_VehVelX_mps() * GET_S_LCFRCV_VehVelX_mps()) * GET_P_VEH_SelfSteeringGrd_nu()) + GET_P_VEH_DistCogToFrontAxle_m()) + GET_P_VEH_DistCogToRearAxle_m();
    /* Abs: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Division/Abs/Functionality'/Abs' */
    rtb_UnitDelay2 = f32_abs_f32(rtb_UnitDelay2_h);
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Division/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Division/GT/Functionality'/GT'
         */
    if (!(rtb_UnitDelay2 > GET_P_LCF_AlmostZero_nu())) {
        rtb_UnitDelay2_h = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Division/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Conversion of steer angle rqeuest to curvature request/Division/Div1/Functionality/Div'/Div' */
    rtb_Div_mp = rtb_Mul_og / rtb_UnitDelay2_h;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Constant2'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/get_bit3/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/get_bit3/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssCrv_nu(), ((uint8)0U)))) != 0) {
        rtb_UnitDelay2_h = rtb_Div_mp;
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Constant4'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/get_bit5/Functionality'/Const_bit_sel_param'
         *  Inport: '<Root>/S_TCTDTE_CrvReqDstrbComp_1pm'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/get_bit5/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssCrv_nu(), ((uint8)2U)))) != 0) {
        rtb_UnitDelay2 = GET_S_TCTDTE_CrvReqDstrbComp_1pm();
    } else {
        rtb_UnitDelay2 = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Sum1/Functionality'/Sum' */
    rtb_Switch_kl = rtb_UnitDelay2_h + rtb_UnitDelay2;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Constant'/Constant'
         *  Inport: '<Root>/S_TCTDTE_CrvReqBnkAglComp_1pm'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Mul2/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Y_TCTLGC_DynBacGain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    if (((sint32)GET_P_TCTLGC_ActivateDynBacGain_nu()) != 0) {
        /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Sign/Functionality'/Sign' incorporates:
                 *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
                 */
        if (GET_S_TCTCDC_CtrlErrDistY_met() < 0.0F) {
            rtb_Switch_id = -1.0F;
        } else if (GET_S_TCTCDC_CtrlErrDistY_met() > 0.0F) {
            rtb_Switch_id = 1.0F;
        } else if (GET_S_TCTCDC_CtrlErrDistY_met() == 0.0F) {
            rtb_Switch_id = 0.0F;
        } else {
            rtb_Switch_id = GET_S_TCTCDC_CtrlErrDistY_met();
        }
        /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Sign/Functionality'/Sign' */
        /* Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Sign1/Functionality'/Sign' incorporates:
                 *  Inport: '<Root>/S_TCTDTE_CrvReqBnkAglComp_1pm'
                 */
        if (GET_S_TCTDTE_CrvReqBnkAglComp_1pm() < 0.0F) {
            rtb_Mul_bp = -1.0F;
        } else if (GET_S_TCTDTE_CrvReqBnkAglComp_1pm() > 0.0F) {
            rtb_Mul_bp = 1.0F;
        } else if (GET_S_TCTDTE_CrvReqBnkAglComp_1pm() == 0.0F) {
            rtb_Mul_bp = 0.0F;
        } else {
            rtb_Mul_bp = GET_S_TCTDTE_CrvReqBnkAglComp_1pm();
        }
        /* End of Signum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Sign1/Functionality'/Sign' */
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Mul1/Functionality'/Mul' incorporates:
                 *  Abs: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Abs/Functionality'/Abs'
                 *  Inport: '<Root>/S_TCTCDC_CtrlErrDistY_met'
                 *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Mul/Functionality'/Mul'
                 */
        rtb_Mul_a = (rtb_Switch_id * rtb_Mul_bp) * f32_abs_f32 (GET_S_TCTCDC_CtrlErrDistY_met());
        /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Y_TCTLGC_DynBacGain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTLGC_CtrlErrDistY_met */
            FDPS_PTR_F32(GETA_X_TCTLGC_CtrlErrDistY_met(), rtb_Mul_a, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D(GETA_Y_TCTLGC_DynBacGain_nu(), &x_dps);
        }
        rtb_Switch_id = rtb_ip_lookup_fxpt_sfun_7_j * GET_S_TCTDTE_CrvReqBnkAglComp_1pm();
    } else {
        rtb_Switch_id = GET_S_TCTDTE_CrvReqBnkAglComp_1pm();
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Dynamic BAC Gain1/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Constant1'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/get_bit1/Functionality'/Const_bit_sel_param'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/get_bit1/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssCrv_nu(), ((uint8)3U)))) != 0) {
        rtb_UnitDelay2_h = rtb_Switch_id;
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Sum3/Functionality'/Sum' */
    rtb_Switch_kl += rtb_UnitDelay2_h;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Constant3'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/get_bit2/Functionality'/Const_bit_sel_param'
         *  Inport: '<Root>/S_TCTDEV_CrvTestSignal_1pm'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/get_bit2/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssCrv_nu(), ((uint8)4U)))) != 0) {
        rtb_UnitDelay2_h = GET_S_TCTDEV_CrvTestSignal_1pm();
    } else {
        rtb_UnitDelay2_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CSS - Command Source Select1/Sum2/Functionality'/Sum' */
    rtb_Sum_ly = rtb_Switch_kl + rtb_UnitDelay2_h;
    /* S-Function Block sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1 Low Pass/Y_TCTLGC_PT1CoAnErrTime_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTLGC_Vel_mps */
        FDPS_PTR_F32(GETA_X_TCTLGC_Vel_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_ow = F32_PTR_IP1D(GETA_Y_TCTLGC_PT1CoAnErrTime_sec (), &x_dps);
    }
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1 Low Pass/Y_TCTLGC_PT1CoAnErrTime_sec/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1 Low Pass/Y_TCTLGC_PT1CoAnErrTime_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_UnitDelay2_h = rtb_ip_lookup_fxpt_sfun_7_ow;
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1 Low Pass/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  MinMax: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1 Low Pass/Max/Functionality'/Max'
         */
    rtb_Div_mg = rtb_Switch / f32_max_f32_f32(rtb_UnitDelay2_h, rtb_Switch);
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1 Low Pass'/Unit_Delay' */
    rtb_UnitDelay2_h = DW_tctlgc_Unit_Delay_DSTATE_ir;
    /* S-Function (sfun_mmv): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1 Low Pass/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_j = rtb_Switch_j;
    } else {
        rtb_SFunction_j = f32_mmv_f32_f32_f32( rtb_UnitDelay2_h, rtb_Switch_j, rtb_Div_mg);
    }
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze1'/Unit Delay2' */
    rtb_UnitDelay2_h = DW_tctlgc_UnitDelay2_DSTATE;
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/FreezeCrv2'/Unit Delay2' */
    rtb_UnitDelay2 = DW_tctlgc_UnitDelay2_DSTATE_d;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/FreezeCrv2/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Logic: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Logical NOT1/Functionality'/NOT'
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Add1/Functionality'/Sum'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch = rtb_UnitDelay2;
    } else {
        if (!(((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0)) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Switch/Functionality'/Switch' incorporates:
                         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient'/Unit Delay'
                         */
            rtb_Switch = DW_tctlgc_UnitDelay_DSTATE;
        } else {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Switch/Functionality'/Switch' */
            rtb_Switch = rtb_Sum_ly;
        }
        /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Add/Functionality'/Sum' */
        rtb_Switch_kl = rtb_Sum_ly - rtb_Switch;
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Product/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_CSCLTA_GrdLimitTgtCrvTGC_1pms'
                 */
        rtb_Mul_bp = GET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms() * rtb_Max;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Saturation Dynamic1/Functionality'/Switch' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Saturation Dynamic1/Functionality'/Relational Operator'
                 */
        if (rtb_Mul_bp >= rtb_Switch_kl) {
            /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Gain/Functionality'/Mul' */
            rtb_Mul_bp = -rtb_Mul_bp;
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Saturation Dynamic1/Functionality'/Switch1' incorporates:
                         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Saturation Dynamic1/Functionality'/Relational Operator1'
                         */
            if (rtb_Mul_bp <= rtb_Switch_kl) {
                rtb_Mul_bp = rtb_Switch_kl;
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Saturation Dynamic1/Functionality'/Switch1' */
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/Saturation Dynamic1/Functionality'/Switch' */
        rtb_Switch += rtb_Mul_bp;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/FreezeCrv2/Switch2/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Saturation of the curvature command/Gain1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_CSCLTA_MaxCrvTrajGuiCtrl_1pm'
         */
    rtb_UnitDelay2 = -GET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm();
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Saturation of the curvature command/Saturation/Switch/Functionality'/Switch' incorporates:
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Saturation of the curvature command/Saturation/Relational Operator/Functionality'/GE'
         */
    if (rtb_Switch >= rtb_UnitDelay2) {
        rtb_UnitDelay2 = rtb_Switch;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Saturation of the curvature command/Saturation/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Saturation of the curvature command/Saturation/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_CSCLTA_MaxCrvTrajGuiCtrl_1pm'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Saturation of the curvature command/Saturation/Relational Operator1/Functionality'/LE'
         */
    if (rtb_UnitDelay2 <= GET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm()) {
        rtb_Switch_d3 = rtb_UnitDelay2;
    } else {
        rtb_Switch_d3 = GET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm();
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Saturation of the curvature command/Saturation/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze1/Switch2/Functionality'/Switch' */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_h0 = rtb_UnitDelay2_h;
    } else {
        rtb_Switch_h0 = rtb_Switch_d3;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze1/Switch2/Functionality'/Switch' */
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze2'/Unit Delay2' */
    rtb_UnitDelay2_h = DW_tctlgc_UnitDelay2_DSTATE_f;
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/FreezeCrv2'/Unit Delay2' */
    rtb_UnitDelay2 = DW_tctlgc_UnitDelay2_DSTATE_g;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TCTFFC_Crv_1pm'
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC'/Unit Delay'
         */
    if (((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0) {
        rtb_Switch_kl = GET_S_TCTFFC_Crv_1pm();
    } else {
        rtb_Switch_kl = DW_tctlgc_UnitDelay_DSTATE_c;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Add/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTFFC_Crv_1pm'
         */
    rtb_Sum_bv = GET_S_TCTFFC_Crv_1pm() - rtb_Switch_kl;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Constant2'/Constant'
         *  Inport: '<Root>/S_CSCLTA_MaxCrvGrdRed_1pms'
         *  Inport: '<Root>/S_TCTFFC_Crv_1pm'
         *  Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Product/Functionality'/Mul'
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Relational Operator1/Functionality'/GE'
         *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC'/Unit Delay'
         */
    if ((GET_S_TCTFFC_Crv_1pm() * DW_tctlgc_UnitDelay_DSTATE_c) >= 0.0F) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Switch2/Functionality'/Switch' incorporates:
                 *  Abs: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Abs/Functionality'/Abs'
                 *  Abs: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Abs1/Functionality'/Abs'
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Constant1'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_MaxCrvGrdBuildup_1pms'
                 *  Inport: '<Root>/S_CSCLTA_MaxCrvGrdRed_1pms'
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Relational Operator/Functionality'/GE'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Add4/Functionality'/Sum'
                 */
        if ((f32_abs_f32(GET_S_TCTFFC_Crv_1pm()) - f32_abs_f32 (DW_tctlgc_UnitDelay_DSTATE_c)) >= 0.0F) {
            rtb_Switch_by = GET_S_CSCLTA_MaxCrvGrdBuildup_1pms();
        } else {
            rtb_Switch_by = GET_S_CSCLTA_MaxCrvGrdRed_1pms();
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Switch2/Functionality'/Switch' */
    } else {
        rtb_Switch_by = GET_S_CSCLTA_MaxCrvGrdRed_1pms();
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/CalcGrd/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Product/Functionality'/Mul' */
    rtb_Mul_bp = rtb_Switch_by * rtb_Max;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Saturation Dynamic/Functionality'/Switch' incorporates:
         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Saturation Dynamic/Functionality'/Relational Operator'
         */
    if (rtb_Mul_bp >= rtb_Sum_bv) {
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Gain/Functionality'/Mul' */
        rtb_Mul_bp = -rtb_Mul_bp;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Saturation Dynamic/Functionality'/Switch1' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Saturation Dynamic/Functionality'/Relational Operator1'
                 */
        if (rtb_Mul_bp <= rtb_Sum_bv) {
            rtb_Mul_bp = rtb_Sum_bv;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Saturation Dynamic/Functionality'/Switch1' */
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Saturation Dynamic/Functionality'/Switch' */
    /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/GrdLimit/Add1/Functionality'/Sum' */
    rtb_Switch_kl += rtb_Mul_bp;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/FreezeCrv2/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze2/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Mul_bp = rtb_UnitDelay2;
        rtb_Sum_bv = rtb_UnitDelay2_h;
    } else {
        rtb_Mul_bp = rtb_Switch_kl;
        rtb_Sum_bv = rtb_Switch_kl;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/FreezeCrv2/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/get_bit4/Functionality'/Const_bit_sel_param'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant15'/Constant'
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant3'/Constant'
         *  S-Function (sfun_getbit_77): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/get_bit4/Functionality'/S-Function'
         */
    if (((sint32)((uint8)flag_get_u8_u8(GET_P_TCTLGC_CssCrv_nu(), ((uint8)1U)))) != 0) {
        rtb_Switch_h = rtb_Sum_bv;
    } else {
        rtb_Switch_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output1/Switch4/Functionality'/Switch' */
    if (((sint32)rtb_NE) != 0) {
        /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch3'/copy1' incorporates:
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Subtract2/Functionality'/Sum'
                 */
        SET_S_TCTLGC_TgtCrv_DE_1pm(rtb_Switch_h0 + rtb_Switch_h);
    } else {
        /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch3'/copy1' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output1/Constant6'/Constant'
                 */
        SET_S_TCTLGC_TgtCrv_DE_1pm(0.0F);
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output1/Switch4/Functionality'/Switch' */
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze'/Unit Delay2' */
    rtb_UnitDelay2_h = DW_tctlgc_UnitDelay2_DSTATE_dd;
    /* UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/FreezeCrv2'/Unit Delay2' */
    rtb_UnitDelay2 = DW_tctlgc_UnitDelay2_DSTATE_o;
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/FreezeCrv2/Switch2/Functionality'/Switch' incorporates:
         *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Add1/Functionality'/Sum'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_EQ) == 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
                 *  UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand'/Unit Delay'
                 */
        if (((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0) {
            rtb_UnitDelay2_h = rtb_Sum_o;
        } else {
            rtb_UnitDelay2_h = DW_tctlgc_UnitDelay_DSTATE_a;
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Switch/Functionality'/Switch' */
        /* Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Add/Functionality'/Sum' */
        rtb_UnitDelay2 = rtb_Sum_o - rtb_UnitDelay2_h;
        /* Product: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Product/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/Constant'/Constant'
                 */
        rtb_Max *= GET_P_TCTLGC_MaxDeltaFGrd_dps();
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Saturation Dynamic/Functionality'/Switch' incorporates:
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Saturation Dynamic/Functionality'/Relational Operator'
                 */
        if (rtb_Max >= rtb_UnitDelay2) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Saturation Dynamic/Functionality'/Switch1' incorporates:
                         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Saturation Dynamic/Functionality'/Relational Operator1'
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Neg/Functionality'/Unary Minus'
                         */
            if ((-rtb_Max) <= rtb_UnitDelay2) {
                rtb_Max = rtb_UnitDelay2;
            } else {
                rtb_Max = -rtb_Max;
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Saturation Dynamic/Functionality'/Switch1' */
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Saturation Dynamic/Functionality'/Switch' */
        rtb_UnitDelay2 = rtb_Max + rtb_UnitDelay2_h;
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limit Command Signal/Limit/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant12'/Constant'
                 *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limit Command Signal/Limit/Functionality'/Relational Operator'
                 *  Sum: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/GrdLimit/Add1/Functionality'/Sum'
                 */
        if (GET_P_TCTLGC_MaxDeltaF_deg() >= rtb_UnitDelay2) {
            /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limit Command Signal/Limit/Functionality'/Switch1' incorporates:
                         *  RelationalOperator: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limit Command Signal/Limit/Functionality'/Relational Operator1'
                         *  UnaryMinus: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limit Command Signal/Neg/Functionality'/Unary Minus'
                         */
            if ((-GET_P_TCTLGC_MaxDeltaF_deg()) <= rtb_UnitDelay2) {
                rtb_UnitDelay2_h = rtb_UnitDelay2;
            } else {
                rtb_UnitDelay2_h = -GET_P_TCTLGC_MaxDeltaF_deg();
            }
            /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limit Command Signal/Limit/Functionality'/Switch1' */
        } else {
            rtb_UnitDelay2_h = GET_P_TCTLGC_MaxDeltaF_deg();
        }
        /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limit Command Signal/Limit/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/FreezeCrv2/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant2'/Constant'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output/Switch4/Functionality'/Switch'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output3/Switch4/Functionality'/Switch'
         *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Switch8/Functionality'/Switch'
         */
    if (((sint32)GET_P_TCTLGC_ActivateOverride_nu()) != 0) {
        /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch1'/copy1' */
        SET_S_TCTLGC_CtrlCrv_DE_1pm(rtb_Sum_ly);
        /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch'/copy1' */
        SET_S_TCTLGC_DeltaFCmd_deg(rtb_Sum_o);
    } else if (((sint32)rtb_NE) != 0) {
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output/Switch4/Functionality'/Switch' incorporates:
                 *  SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch1'/copy1'
                 */
        SET_S_TCTLGC_CtrlCrv_DE_1pm(rtb_Switch_h0);
        /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output3/Switch4/Functionality'/Switch' incorporates:
                                                        *  SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch'/copy1'
                                                        */
        SET_S_TCTLGC_DeltaFCmd_deg(rtb_UnitDelay2_h);
    } else {
        /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch1'/copy1' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output/Constant6'/Constant'
                 *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output/Switch4/Functionality'/Switch'
                 */
        SET_S_TCTLGC_CtrlCrv_DE_1pm(0.0F);
        /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch'/copy1' incorporates:
                                                *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output3/Constant6'/Constant'
                                                *  Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output3/Switch4/Functionality'/Switch'
                                                */
        SET_S_TCTLGC_DeltaFCmd_deg(0.0F);
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tctlgc_Unit_Delay_DSTATE_cc = rtb_EQ;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Determine Reset/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE = rtb_Switch_hf;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE = rtb_Sum_fw;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE = rtb_Switch_hf;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_a = rtb_Switch6_d;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_p = rtb_Switch_fu;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_n = rtb_Switch6_d;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1 Low Pass'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_l = rtb_SFunction;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_e = rtb_Switch_i;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_f = rtb_SFunction_i;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_k = rtb_SFunction_i;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_i = rtb_Sum_gw;
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI/Functionality'/Signal Conversion'
         */
    DW_tctlgc_Unit_Delay_DSTATE_j = rtb_DataTypeConversion_lj;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/EDGEBI'/fcg' */
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/Gradient Limit PGain'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_lc = rtb_RelationalOperator;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc'/Unit_Delay2' */
    DW_tctlgc_Unit_Delay2_DSTATE = rtb_Mul_cn;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_Integrator'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_b = rtb_Mul_cn;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/I-Part of the Ldc'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_o = rtb_Mul_ei;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc/Discrete Derivative'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_eo = rtb_MultiportSwitch2;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/DT1-Part of the Ycc'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_n = rtb_SFunction_o;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_g = rtb_Mul;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdcAlone_PT1'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_bb = rtb_Mul;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Ldc of Cascade Structure/PT1-Part of Ldc'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_g = rtb_SFunction_d;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_f = rtb_Switch_j;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_m = rtb_SFunction_d4;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_p = rtb_SFunction_d4;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_fe = rtb_Sum_mq;
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI/Functionality'/Signal Conversion'
         */
    DW_tctlgc_Unit_Delay_DSTATE_lt2 = rtb_RelationalOperator1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/EDGEBI'/fcg' */
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/Gradient Limit PGain'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_lu = rtb_RelationalOperator_fv;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc'/Unit_Delay2' */
    DW_tctlgc_Unit_Delay2_DSTATE_e = rtb_Mul_gh;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_Integrator'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_bf = rtb_Mul_gh;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/I-Part of the Cac for Ldc'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_n = rtb_Switch7_f;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc/Discrete Derivative'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_m = rtb_Mul_ey;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/DT1-Part of the Cac for Ldc'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_i1 = rtb_SFunction_l;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_l = rtb_Mul_m;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrLdc_PT1'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_lt = rtb_Mul_m;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1-Part of Cdc'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_im = rtb_SFunction_h;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_l3 = rtb_Sum_p;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_e = rtb_Sum;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_ep = rtb_Sum_p;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1 Low Pass'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_feo = rtb_SFunction_m;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_ex = rtb_Switch_cw;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 1'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_o = rtb_SFunction_g;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Filter to compensate the conjugated complex Poles of the LaDMC/Discrete Derivative 2'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_h = rtb_SFunction_g;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_c = rtb_Sum_fz;
    /* S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI/Functionality'/Signal Conversion'
         */
    DW_tctlgc_Unit_Delay_DSTATE_af = rtb_EQ_l;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/EDGEBI'/fcg' */
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/Gradient Limit PGain'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_ph = rtb_RelationalOperator_i;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac'/Unit_Delay2' */
    DW_tctlgc_Unit_Delay2_DSTATE_j = rtb_MultiportSwitch1;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_Integrator'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_k = rtb_MultiportSwitch1;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/I-Part of the Cac'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_gf = rtb_MultiportSwitch2_l;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac/Discrete Derivative'/Unit_Delay3' */
    DW_tctlgc_Unit_Delay3_DSTATE_ms = rtb_Sum_d;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/DT1-Part of the Cac'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_d = rtb_SFunction_hn;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc'/Unit_Delay1' */
    DW_tctlgc_Unit_Delay1_DSTATE_f = rtb_MultiportSwitch6;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Reset PT1s and Integrators/ResetLatErrCac_PT1'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_p = rtb_MultiportSwitch6;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cdc of Cascade Structure/PT1-Part of Cdc'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_h = rtb_SFunction_c;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/PT1 Low Pass'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_gr = rtb_SFunction_dr;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/CalcNonLinearParams/Cac of Cascade Structure for Ldc/PT1 Low Pass'/Unit_Delay' */
    DW_tctlgc_Unit_Delay_DSTATE_ir = rtb_SFunction_j;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze1'/Unit Delay2' */
    DW_tctlgc_UnitDelay2_DSTATE = rtb_Switch_h0;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient/FreezeCrv2'/Unit Delay2' */
    DW_tctlgc_UnitDelay2_DSTATE_d = rtb_Switch;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Limitation of the summed curvature command's gradient'/Unit Delay' */
    DW_tctlgc_UnitDelay_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze2'/Unit Delay2' */
    DW_tctlgc_UnitDelay2_DSTATE_f = rtb_Sum_bv;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC/FreezeCrv2'/Unit Delay2' */
    DW_tctlgc_UnitDelay2_DSTATE_g = rtb_Mul_bp;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_CrvReqFFC'/Unit Delay' */
    DW_tctlgc_UnitDelay_DSTATE_c = rtb_Mul_bp;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Freeze'/Unit Delay2' */
    DW_tctlgc_UnitDelay2_DSTATE_dd = rtb_UnitDelay2_h;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand/FreezeCrv2'/Unit Delay2' */
    DW_tctlgc_UnitDelay2_DSTATE_o = rtb_UnitDelay2;
    /* Update for UnitDelay: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/LimitGradient_DeltaFCommand'/Unit Delay' */
    DW_tctlgc_UnitDelay_DSTATE_a = rtb_UnitDelay2;
    /* End of Outputs for SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC' */
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch10'/copy1' */
    SET_D_TCTLGC_LdcAlonePCmd_rad(rtb_MultiportSwitch2);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch11'/copy1' */
    SET_D_TCTLGC_LdcAloneICmd_rad(rtb_Mul_cn);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch12'/copy1' */
    SET_D_TCTLGC_LdcAloneDT1Cmd_rad(rtb_SFunction_o);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch13'/copy1' */
    SET_D_TCTLGC_LdcAloneCmd_rad(rtb_Switch_j);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch14'/copy1' */
    SET_D_TCTLGC_LdcPCmd_rad(rtb_Mul_ey);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch15'/copy1' */
    SET_D_TCTLGC_LdcICmd_rad(rtb_Mul_gh);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch16'/copy1' */
    SET_D_TCTLGC_LdcDT1Cmd_rad(rtb_SFunction_l);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch17'/copy1' */
    SET_D_TCTLGC_LdcCmd_rad(rtb_Sum_pj);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch18'/copy1' */
    SET_D_TCTLGC_CacPCmd_rad(rtb_Sum_d);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch19'/copy1' */
    SET_D_TCTLGC_CacICmd_rad(rtb_MultiportSwitch1);
    /* Outputs for Atomic SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC'
                                                      *
                                                      * Block description for 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC':
                                                      *  X.2.1
                                                      */
    /* Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output2/Switch4/Functionality'/Switch' */
    if (((sint32)rtb_NE) != 0) {
        /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch2'/copy1' */
        SET_S_TCTLGC_FFCrv_1pm(rtb_Switch_h);
    } else {
        /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch2'/copy1' incorporates:
                 *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output2/Constant6'/Constant'
                 */
        SET_S_TCTLGC_FFCrv_1pm(0.0F);
    }
    /* End of Switch: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Enable Output2/Switch4/Functionality'/Switch' */
    /* End of Outputs for SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC' */
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch20'/copy1' */
    SET_D_TCTLGC_CacDT1Cmd_rad(rtb_SFunction_hn);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch21'/copy1' */
    SET_D_TCTLGC_CacCmd_rad(rtb_MultiportSwitch7);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch22'/copy1' */
    SET_D_TCTLGC_SafetyFunctionActive_nu(rtb_DataTypeConversion_dx);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch23'/copy1' */
    SET_D_TCTLGC_LdcPT1Reset_nu(rtb_DataTypeConversion_m);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch24'/copy1' */
    SET_D_TCTLGC_DeltaFBAC_deg(rtb_Div_go);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch25'/copy1' */
    SET_D_TCTLGC_CrvReqBAC_1pm(rtb_Switch_id);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch26'/copy1' */
    SET_D_TCTLGC_ActiveLgcParamSet_nu(rtb_Switch_m3);
    /* Outputs for Atomic SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC'
                                                        *
                                                        * Block description for 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC':
                                                        *  X.2.1
                                                        */
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch27'/copy1' incorporates:
         *  Inport: '<Root>/S_TCTDTE_CrvReqDstrbComp_1pm'
         */
    SET_D_TCTLGC_CrvReqDte_1pm(GET_S_TCTDTE_CrvReqDstrbComp_1pm());
    /* End of Outputs for SubSystem: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess'/M_TCTLGC' */
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch28'/copy1' */
    SET_D_TCTLGC_SumCrvReqFb_1pm(rtb_Sum_ly);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch29'/copy1' */
    SET_D_TCTLGC_SumCrvReqFbGrdLim_1pm(rtb_Switch);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch30'/copy1' */
    SET_D_TCTLGC_SumCrvReqFbSatLim_1pm(rtb_Switch_d3);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch31'/copy1' */
    SET_D_TCTLGC_SumCrvReqFbFrz_1pm(rtb_Switch_h0);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch32'/copy1' */
    SET_D_TCTLGC_CrvReqFfcGrdLimT1_1pm(rtb_Switch_by);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch33'/copy1' */
    SET_D_TCTLGC_CrvReqFfcGrdLimT2_1pm(rtb_Switch_kl);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch34'/copy1' */
    SET_D_TCTLGC_CrvReqFfcGrdLim_1pm(rtb_Mul_bp);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch35'/copy1' */
    SET_D_TCTLGC_CacPT1Reset_nu(rtb_GE);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch36'/copy1' */
    SET_D_TCTLGC_CrvReqFfcFrz_1pm(rtb_Sum_bv);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch37'/copy1' */
    SET_D_TCTLGC_Hold_nu(rtb_EQ);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch38'/copy1' */
    SET_D_TCTLGC_PGainLdcGrdLimTrig_nu(rtb_RelationalOperator);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch39'/copy1' */
    SET_D_TCTLGC_EnableCtrl_nu(rtb_NE);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch4'/copy1' incorporates:
                                            *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant7'/Constant'
                                            */
    SET_S_TCTLGC_TgtCrv_DENoLatSlp_1pm(0.0F);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch40'/copy1' */
    SET_D_TCTLGC_Reset_nu(rtb_DataTypeConversion);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch41'/copy1' */
    SET_D_TCTLGC_PGainCacGrdLimTrig_nu(rtb_RelationalOperator_fv);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch42'/copy1' */
    SET_D_TCTLGC_LdcIntReset_nu(rtb_DataTypeConversion_l);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch43'/copy1' */
    SET_D_TCTLGC_CacIntReset_nu(rtb_RelationalOperator1_e4);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch44'/copy1' */
    SET_D_TCTLGC_DeltaFCmdDC_deg(rtb_Div_i1);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch45'/copy1' */
    SET_D_TCTLGC_DeltaFCmdFFC_deg(0.0F);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch46'/copy1' */
    SET_D_TCTLGC_LdcAlonePT1Reset_nu(rtb_DataTypeConversion_dg);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch47'/copy1' */
    SET_D_TCTLGC_LdcAlonePT1YErr_met(rtb_SFunction);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch48'/copy1' */
    SET_D_TCTLGC_LdcAloneLaDmcComp_met(rtb_Switch6_d);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch49'/copy1' */
    SET_D_TCTLGC_LdcAlonePT1Cmd_rad(rtb_Mul);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch5'/copy1' incorporates:
                                                *  Constant: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/M_TCTLGC/Constant8'/Constant'
                                                */
    SET_S_TCTLGC_TgtCrv_NoDE_1pm(0.0F);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch50'/copy1' */
    SET_D_TCTLGC_LdcPT1Input_rad(rtb_SFunction_j);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch51'/copy1' */
    SET_D_TCTLGC_LdcLaDmcComp_rad(rtb_Switch_hf);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch52'/copy1' */
    SET_D_TCTLGC_LdcPT1Cmd_rad(rtb_Mul_m);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch53'/copy1' */
    SET_D_TCTLGC_CacPT1CoAnErr_rad(rtb_SFunction_m);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch54'/copy1' */
    SET_D_TCTLGC_CacLaDmcComp_rad(rtb_Sum_p);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch55'/copy1' */
    SET_D_TCTLGC_CacPT1Cmd_rad(rtb_MultiportSwitch6);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch56'/copy1' */
    SET_D_TCTLGC_LdcAloneIntReset_nu(rtb_DataTypeConversion_g);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch6'/copy1' */
    SET_S_TCTLGC_CtrlCrv_1pm(rtb_Div_mp);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch7'/copy1' */
    SET_S_TCTLGC_CtrlErrHeadAglCrtd_rad(rtb_S_TCTCDC_CtrlErrHeadAglPrev_rad);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch8'/copy1' */
    SET_D_TCTLGC_DeltaFCmd_rad(rtb_Mul_og);
    /* SignalConversion: 'sda:TCTLGC/TCTLGC/TCTLGC_VehProcess/branch9'/copy1' */
    SET_D_TCTLGC_DeltaFCmdUnlimited_deg(rtb_Div_o);
}
#include "Pse_TCTLGC.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
