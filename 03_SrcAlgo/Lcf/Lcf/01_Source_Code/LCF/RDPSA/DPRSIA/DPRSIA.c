/**************************************************************************
COPYRIGHT (C) $Date: 2019/12/17 15:59:06CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/RDPSA/DPRSIA_SEN/DPRSIA/i/project.pj $
$Log: DPRSIA.c  $
Revision 1.5.1.1 2019/12/17 15:59:06CET Diaz Bravo, Jose Luis (uidg8685) 
New bridging logic for lane markings and road edges.
File          : DPRSIA
Generated on  : Tue 17.12.2019 at 15:35:22 (UTC+01:00)
MD5           : [3241005287  2767744962  1672311146  2149197504 0](DPRSIA)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.441655 (R2016b)
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "DPRSIA.h"
#include "DPRSIA_private.h"
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
#define DPRSIA_START_SEC_DATA_8
#include "DPRSIA_MemMap.h"
static uint8 DW_dprsia_UnitDelay2_DSTATE_g;
static uint8 DW_dprsia_UnitDelay2_DSTATE_d;
static uint8 DW_dprsia_UnitDelay2_DSTATE_kh;
static uint8 DW_dprsia_UnitDelay2_DSTATE_j;
static uint8 DW_dprsia_UnitDelay2_DSTATE_jw;
static uint8 DW_dprsia_UnitDelay2_DSTATE_e1;
static uint8 DW_dprsia_UnitDelay2_DSTATE_a;
static uint8 DW_dprsia_UnitDelay2_DSTATE_l;
static uint8 DW_dprsia_UnitDelay2_DSTATE_pa;
static uint8 DW_dprsia_UnitDelay2_DSTATE_nz;
static uint8 DW_dprsia_UnitDelay2_DSTATE_j0;
static uint8 DW_dprsia_UnitDelay2_DSTATE_f;
static uint8 DW_dprsia_Unit_Delay_DSTATE;
static uint8 DW_dprsia_Unit_Delay_DSTATE_e;
static uint8 DW_dprsia_UnitDelay2_DSTATE_jv;
static uint8 DW_dprsia_UnitDelay2_DSTATE_oz;
static uint8 DW_dprsia_UnitDelay2_DSTATE_nr;
static uint8 DW_dprsia_UnitDelay1_DSTATE_n;
static uint8 DW_dprsia_UnitDelay2_DSTATE_ey;
static uint8 DW_dprsia_UnitDelay1_DSTATE_f0;
static uint8 DW_dprsia_UnitDelay2_DSTATE_h;
static uint8 DW_dprsia_UnitDelay2_DSTATE_lw;
static uint8 DW_dprsia_UnitDelay2_DSTATE_km;
static uint8 DW_dprsia_UnitDelay2_DSTATE_es;
static uint8 DW_dprsia_UnitDelay2_DSTATE_an;
static uint8 DW_dprsia_UnitDelay2_DSTATE_ew;
static uint8 DW_dprsia_UnitDelay2_DSTATE_pu;
static uint8 DW_dprsia_UnitDelay2_DSTATE_cc;
static uint8 DW_dprsia_UnitDelay2_DSTATE_ou;
static uint8 DW_dprsia_UnitDelay2_DSTATE_jx;
static uint8 DW_dprsia_UnitDelay2_DSTATE_j4;
static uint8 DW_dprsia_UnitDelay2_DSTATE_h4;
static uint8 DW_dprsia_UnitDelay2_DSTATE_m;
static uint8 DW_dprsia_UnitDelay2_DSTATE_ic;
static uint8 DW_dprsia_UnitDelay2_DSTATE_fm;
static uint8 DW_dprsia_UnitDelay1_DSTATE_h;
static uint8 DW_dprsia_UnitDelay2_DSTATE_k0;
static uint8 DW_dprsia_UnitDelay1_DSTATE_d;
static uint8 DW_dprsia_UnitDelay2_DSTATE_f2;
static uint8 DW_dprsia_UnitDelay2_DSTATE_nc;
static uint8 DW_dprsia_UnitDelay2_DSTATE_nk;
static uint8 DW_dprsia_UnitDelay1_DSTATE_ds;
static uint8 DW_dprsia_UnitDelay3_DSTATE_d;
static uint8 DW_dprsia_UnitDelay1_DSTATE_k;
static uint8 DW_dprsia_UnitDelay1_DSTATE_i;
static uint8 DW_dprsia_UnitDelay2_DSTATE_khn[2];
static uint8 DW_dprsia_UnitDelay1_DSTATE_o;
static uint8 DW_dprsia_UnitDelay2_DSTATE_jm[2];
static uint8 DW_dprsia_UnitDelay1_DSTATE_mz;
#define DPRSIA_STOP_SEC_DATA_8
#include "DPRSIA_MemMap.h"
#define DPRSIA_START_SEC_DATA_32
#include "DPRSIA_MemMap.h"
static float32 DW_dprsia_UnitDelay1_DSTATE;
static float32 DW_dprsia_UnitDelay2_DSTATE;
static float32 DW_dprsia_UnitDelay3_DSTATE;
static float32 DW_dprsia_UnitDelay4_DSTATE;
static float32 DW_dprsia_UnitDelay1_DSTATE_j;
static float32 DW_dprsia_UnitDelay2_DSTATE_n;
static float32 DW_dprsia_UnitDelay3_DSTATE_e;
static float32 DW_dprsia_UnitDelay4_DSTATE_l;
static float32 DW_dprsia_UnitDelay2_DSTATE_c;
static float32 DW_dprsia_UnitDelay2_DSTATE_p;
static float32 DW_dprsia_UnitDelay2_DSTATE_e;
static float32 DW_dprsia_UnitDelay2_DSTATE_k;
static float32 DW_dprsia_UnitDelay1_DSTATE_f;
static float32 DW_dprsia_UnitDelay1_DSTATE_m;
static float32 DW_dprsia_UnitDelay2_DSTATE_o;
static float32 DW_dprsia_UnitDelay2_DSTATE_ej;
static float32 DW_dprsia_UnitDelay2_DSTATE_pt;
static float32 DW_dprsia_UnitDelay2_DSTATE_i;
static float32 DW_dprsia_Unit_Delay1_DSTATE;
static float32 DW_dprsia_Unit_Delay1_DSTATE_d[8];
#define DPRSIA_STOP_SEC_DATA_32
#include "DPRSIA_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPRSIA/DPRSIA/INI'/DPRSIA_SenReset'
 * Block description for: 'sda:DPRSIA/DPRSIA/INI'/DPRSIA_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRSIA_SenReset
#include "Pse_DPRSIA.h"
/* Short description: Not synchronized with ARAMIS */
void DPRSIA_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant1'/Constant' */
    SET_S_DPRSIA_SpecificRDP_btf(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant10'/Constant' */
    SET_S_DPRSIA_DlcLeRDP_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant11'/Constant' */
    SET_S_DPRSIA_DrcLeRDP_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant12'/Constant' */
    SET_S_DPRSIA_TlcLeRDP_sec(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant13'/Constant' */
    SET_S_DPRSIA_DrcRiRDP_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant14'/Constant' */
    SET_S_DPRSIA_TrcRiRDP_sec(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant15'/Constant' */
    SET_S_DPRSIA_TrcLeRDP_sec(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant16'/Constant' */
    SET_S_DPRSIA_TlcRiRDP_sec(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant17'/Constant' */
    SET_D_DPRSIA_LnBndLeCancelValidRDP_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant18'/Constant' */
    SET_S_DPRSIA_LnBndValidRDP_nu(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant19'/Constant' */
    SET_S_DPRSIA_RdBndValidRDP_nu(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant2'/Constant' */
    SET_S_DPRSIA_TriggerReasonRiRDP_nu(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant20'/Constant' */
    SET_D_DPRSIA_RdBndRiTrgValidRDP_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant21'/Constant' */
    SET_D_DPRSIA_RdBndLeTrgValidRDP_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant22'/Constant' */
    SET_D_DPRSIA_RdBndLeCancelValidRDP_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant23'/Constant' */
    SET_D_DPRSIA_RdBndRiCancelValidRDP_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant24'/Constant' */
    SET_S_DPRSIA_VelLatLnRiRDP_mps(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant25'/Constant' */
    SET_S_DPRSIA_VelLatLnLeRDP_mps(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant26'/Constant' */
    SET_S_DPRSIA_SpecificRDW_btf(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant27'/Constant' */
    SET_S_DPRSIA_VelLatReRiRDP_mps(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant28'/Constant' */
    SET_S_DPRSIA_VelLatReLeRDP_mps(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant29'/Constant' */
    SET_S_DPRSIA_LaneWidthRDP_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant3'/Constant' */
    SET_S_DPRSIA_TriggerReasonLeRDP_nu(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant30'/Constant' */
    SET_S_DPRSIA_TgtCntrLnEnable_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant32'/Constant' */
    SET_S_DPRSIA_DlcLeRDW_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant33'/Constant' */
    SET_S_DPRSIA_DrcLeRDW_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant34'/Constant' */
    SET_S_DPRSIA_TlcLeRDW_sec(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant35'/Constant' */
    SET_S_DPRSIA_DrcRiRDW_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant36'/Constant' */
    SET_S_DPRSIA_TrcRiRDW_sec(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant37'/Constant' */
    SET_S_DPRSIA_TrcLeRDW_sec(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant38'/Constant' */
    SET_S_DPRSIA_TlcRiRDW_sec(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant39'/Constant' */
    SET_D_DPRSIA_LnBndLeCancelValidRDW_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant4'/Constant' */
    SET_S_DPRSIA_SideCondRDPLe_btf(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant40'/Constant' */
    SET_S_DPRSIA_LnBndValidRDW_nu(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant41'/Constant' */
    SET_S_DPRSIA_RdBndValidRDW_nu(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant42'/Constant' */
    SET_S_DPRSIA_TriggerReasonRiRDW_nu(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant43'/Constant' */
    SET_D_DPRSIA_RdBndRiTrgValidRDW_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant44'/Constant' */
    SET_D_DPRSIA_RdBndLeTrgValidRDW_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant45'/Constant' */
    SET_D_DPRSIA_RdBndLeCancelValidRDW_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant46'/Constant' */
    SET_D_DPRSIA_RdBndRiCancelValidRDW_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant47'/Constant' */
    SET_S_DPRSIA_VelLatLnRiRDW_mps(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant48'/Constant' */
    SET_S_DPRSIA_VelLatLnLeRDW_mps(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant5'/Constant' */
    SET_S_DPRSIA_SideCondRDPRi_btf(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant50'/Constant' */
    SET_S_DPRSIA_VelLatReRiRDW_mps(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant51'/Constant' */
    SET_S_DPRSIA_VelLatReLeRDW_mps(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant52'/Constant' */
    SET_S_DPRSIA_LaneWidthRDW_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant53'/Constant' */
    SET_S_DPRSIA_TriggerReasonLeRDW_nu(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant55'/Constant' */
    SET_S_DPRSIA_SideCondRDWLe_btf(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant56'/Constant' */
    SET_S_DPRSIA_SideCondRDWRi_btf(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant57'/Constant' */
    SET_D_DPRSIA_LnBndRiCancelValidRDW_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant58'/Constant' */
    SET_D_DPRSIA_LnBndLeTrgValidRDW_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant59'/Constant' */
    SET_D_DPRSIA_LnBndRiTrgValidRDW_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant6'/Constant' */
    SET_D_DPRSIA_LnBndRiCancelValidRDP_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant60'/Constant' */
    SET_S_DPRSIA_DlcRiRDW_met(0.0F);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant7'/Constant' */
    SET_D_DPRSIA_LnBndLeTrgValidRDP_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant8'/Constant' */
    SET_D_DPRSIA_LnBndRiTrgValidRDP_bool(0U);
    /* Constant: 'sda:DPRSIA/DPRSIA/INI/DPRSIA_SenReset/Constant9'/Constant' */
    SET_S_DPRSIA_DlcRiRDP_met(0.0F);
}
#include "Pse_DPRSIA.h"
/*
 * Output and update for function-call system: 'sda:DPRSIA/DPRSIA'/DPRSIA_SenProcess'
 * Block description for: 'sda:DPRSIA/DPRSIA'/DPRSIA_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRSIA_SenProcess
#include "Pse_DPRSIA.h"
/* Short description: Not synchronized with ARAMIS */
void DPRSIA_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_Abs_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_bu;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_mk;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_ip_lookup_fxpt_sfun_7_fz;
    float32 rtb_ip_lookup_fxpt_sfun_7_do;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_ke;
    float32 rtb_ip_lookup_fxpt_sfun_7_jc;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_ja;
    uint8 rtb_LogicalOperator_gq[8];
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate1[8];
    uint8 rtb_VectorConcatenate_b[8];
    uint8 rtb_VectorConcatenate1_l[8];
    uint8 rtb_VectorConcatenate1_n[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_sfun_setbit_j;
    uint8 rtb_sfun_setbit_a;
    uint8 rtb_sfun_setbit_h;
    uint8 rtb_sfun_setbit_hp;
    uint8 rtb_LogicalOperator_e;
    uint8 rtb_DataTypeConversion_j1;
    uint8 rtb_DataTypeConversion_oo;
    uint8 rtb_EQ;
    float32 rtb_Sum_mg;
    uint8 rtb_GT;
    uint8 rtb_LT_l1;
    float32 rtb_Switch;
    uint8 rtb_LT_fj;
    uint8 rtb_DataTypeConversion_cr;
    uint8 rtb_LogicalOperator;
    uint8 rtb_EQ_e;
    uint8 rtb_Switch_h5;
    uint8 rtb_GT_pn;
    uint8 rtb_LT_oe;
    float32 rtb_Switch_jo;
    uint8 rtb_LT_ff;
    uint8 rtb_DataTypeConversion_f5o;
    uint8 rtb_LogicalOperator_l;
    uint8 rtb_EQ_d3;
    float32 rtb_Switch_ct;
    uint8 rtb_GT_ec;
    uint8 rtb_LT_px;
    uint8 rtb_LT_c5;
    uint8 rtb_DataTypeConversion_ae;
    uint8 rtb_LogicalOperator_h;
    uint8 rtb_EQ_n;
    float32 rtb_Switch_mhg;
    uint8 rtb_GT_ft;
    uint8 rtb_LT_i;
    uint8 rtb_LT_oq;
    uint8 rtb_DataTypeConversion_kz;
    uint8 rtb_LogicalOperator_df;
    uint8 rtb_NE_e;
    uint8 rtb_NE_hm;
    float32 rtb_Switch_hh[2];
    float32 rtb_Switch_d;
    float32 rtb_Switch_jd;
    float32 rtb_Switch_l;
    float32 rtb_Switch_fr;
    uint8 rtb_GT_n;
    uint8 rtb_LT_ny;
    float32 rtb_Switch_p;
    uint8 rtb_GT_o;
    uint8 rtb_LT_n;
    float32 rtb_Div;
    uint8 rtb_DataTypeConversion_ke;
    uint8 rtb_LogicalOperator_f;
    uint8 rtb_EQ_mo;
    uint8 rtb_GT_mtz;
    uint8 rtb_LT_nke;
    float32 rtb_Switch_hi;
    uint8 rtb_LT_hd;
    uint8 rtb_DataTypeConversion_da;
    uint8 rtb_LogicalOperator_d;
    uint8 rtb_EQ_b;
    float32 rtb_Switch_pi;
    uint8 rtb_GT_fm;
    uint8 rtb_LT_c;
    uint8 rtb_LT_nt;
    uint8 rtb_DataTypeConversion_o3r;
    uint8 rtb_LogicalOperator_c;
    uint8 rtb_EQ_p;
    float32 rtb_Switch_n;
    uint8 rtb_GT_mh;
    uint8 rtb_LT_hr;
    uint8 rtb_LT_a;
    uint8 rtb_DataTypeConversion_ct;
    uint8 rtb_LogicalOperator_k;
    uint8 rtb_NE_c;
    uint8 rtb_NE_m;
    float32 rtb_Switch_ffx[2];
    float32 rtb_Switch_o;
    float32 rtb_Switch_c;
    uint8 rtb_DataTypeConversion_kq;
    uint8 rtb_LT_k4;
    float32 rtb_Div_io;
    uint8 rtb_Switch3_f;
    uint8 rtb_SignalConversion;
    uint8 rtb_Switch3_l;
    uint8 rtb_VectorConcatenate_n[8];
    sint8 rtb_DataTypeConversion_dp[2];
    sint8 rtb_DataTypeConversion_kt2[2];
    sint8 rtb_Switch_pv[2];
    sint8 rtb_Switch_nu[2];
    float32 rtb_Switch_c3;
    float32 rtb_Switch_k0;
    float32 rtb_Switch_a;
    float32 rtb_Switch_gv;
    float32 rtb_Switch_ky;
    float32 rtb_Switch_buc;
    float32 rtb_Abs_g;
    uint8 rtb_Switch_cq;
    uint8 rtb_Switch_pa;
    uint8 rtb_Switch_kz;
    uint8 rtb_Switch_ip;
    sint32 i;
    uint8 tmp;
    uint8 tmp_0;
    float32 rtb_Switch_ob;
    uint8 tmp_1;
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/AND/Functionality'/AND'
         */
    rtb_LogicalOperator_e = (uint8)((((sint32)GET_S_ABPLBP_ConstructionSite_bool ()) != 0) && (((sint32)GET_P_DPRSIA_ConstrSiteRe_bool()) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/AND1/Functionality'/AND'
         */
    rtb_sfun_setbit_a = (uint8)((((sint32)GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32)GET_P_DPRSIA_ConstrSiteLn_bool()) != 0));
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay2'
         */
    rtb_EQ = (uint8)((DW_dprsia_UnitDelay2_DSTATE <= 0.0F) && (((sint32) rtb_LogicalOperator_e) != 0));
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay1'
         */
    rtb_Switch_kz = (uint8)((((sint32)rtb_EQ) != 0) || (DW_dprsia_UnitDelay1_DSTATE > 0.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay1'
         */
    if (((sint32)rtb_EQ) != 0) {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/Application Parameter4'/Constant'
                 */
        DW_dprsia_UnitDelay1_DSTATE = GET_P_DPRSIA_ConstrSiteReTurnOff_sec();
    } else {
        if (DW_dprsia_UnitDelay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Switch2'
                         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay1'
                         */
            DW_dprsia_UnitDelay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay4'
         */
    rtb_EQ = (uint8)((DW_dprsia_UnitDelay4_DSTATE <= 0.0F) && (((sint32) rtb_sfun_setbit_a) != 0));
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay3'
         */
    rtb_Switch_ip = (uint8)((((sint32)rtb_EQ) != 0) || (DW_dprsia_UnitDelay3_DSTATE > 0.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Constant'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Relational Operator'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay3'
         */
    if (((sint32)rtb_EQ) != 0) {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay3' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/Application Parameter6'/Constant'
                 */
        DW_dprsia_UnitDelay3_DSTATE = GET_P_DPRSIA_ConstrSiteLnTurnOff_sec();
    } else {
        if (DW_dprsia_UnitDelay3_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay3' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Switch2'
                         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay3'
                         */
            DW_dprsia_UnitDelay3_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNOFFDELAYTIME1/Functionality'/Switch1' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/Application Parameter3'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE = GET_P_DPRSIA_ConstrSiteReTurnOn_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Switch2' */
    if (((sint32)rtb_sfun_setbit_a) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay4'
                 */
        if (DW_dprsia_UnitDelay4_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay4' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay4_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite'/Unit Delay4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/Application Parameter5'/Constant'
                 */
        DW_dprsia_UnitDelay4_DSTATE = GET_P_DPRSIA_ConstrSiteLnTurnOn_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ConstructionSite/TURNONDELAYTIME1/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/GE/Functionality'/GE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ExitLeft_perc'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_ABPLBP_ExitLeft_perc()) >= ((sint32) GET_P_DPRSIA_ExitRampProb_perc()));
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/GE1/Functionality'/GE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ExitRight_perc'
         */
    rtb_sfun_setbit_a = (uint8)(((sint32)GET_S_ABPLBP_ExitRight_perc()) >= ((sint32)GET_P_DPRSIA_ExitRampProb_perc()));
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay2'
         */
    rtb_LogicalOperator_e = (uint8)((DW_dprsia_UnitDelay2_DSTATE_n <= 0.0F) && (((sint32)rtb_EQ) != 0));
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay1'
         */
    rtb_DataTypeConversion_j1 = (uint8)((((sint32)rtb_LogicalOperator_e) != 0) || (DW_dprsia_UnitDelay1_DSTATE_j > 0.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay1'
         */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/Application Parameter4'/Constant'
                 */
        DW_dprsia_UnitDelay1_DSTATE_j = GET_P_DPRSIA_ExitRampTurnOff_sec();
    } else {
        if (DW_dprsia_UnitDelay1_DSTATE_j > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Switch2'
                         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay1'
                         */
            DW_dprsia_UnitDelay1_DSTATE_j -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay4'
         */
    rtb_LogicalOperator_e = (uint8)((DW_dprsia_UnitDelay4_DSTATE_l <= 0.0F) && (((sint32)rtb_sfun_setbit_a) != 0));
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay3'
         */
    rtb_DataTypeConversion_oo = (uint8)((((sint32)rtb_LogicalOperator_e) != 0) || (DW_dprsia_UnitDelay3_DSTATE_e > 0.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Constant'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Relational Operator'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay3'
         */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay3' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/Application Parameter6'/Constant'
                 */
        DW_dprsia_UnitDelay3_DSTATE_e = GET_P_DPRSIA_ExitRampTurnOff_sec();
    } else {
        if (DW_dprsia_UnitDelay3_DSTATE_e > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay3' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality/Add/Functionality'/Sum'
                         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Switch2'
                         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay3'
                         */
            DW_dprsia_UnitDelay3_DSTATE_e -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNOFFDELAYTIME1/Functionality'/Switch1' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_n > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_n -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/Application Parameter3'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_n = GET_P_DPRSIA_ExitRampTurnOn_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Switch2' */
    if (((sint32)rtb_sfun_setbit_a) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay4'
                 */
        if (DW_dprsia_UnitDelay4_DSTATE_l > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay4' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay4_DSTATE_l -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp'/Unit Delay4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/Application Parameter5'/Constant'
                 */
        DW_dprsia_UnitDelay4_DSTATE_l = GET_P_DPRSIA_ExitRampTurnOn_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/ExitRamp/TURNONDELAYTIME1/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Constant5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND2/Functionality'/AND'
         */
    rtb_EQ = (uint8)((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Application Parameter11'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Constant11'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND26/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQuSIF_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND26/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Relational Operator11/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND25/Functionality'/AND'
         */
    if (((sint32)GET_P_DPRSIA_SafetyIfaceLnOn_bool()) != 0) {
        rtb_EQ = (uint8)(((((sint32)GET_S_ABPLBP_LeLnInvalidQuSIF_btf()) & ((sint32)GET_P_DPRSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32)rtb_EQ) != 0));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Switch6/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPRSMI_DangerousSide_nu'
         */
    rtb_sfun_setbit_a = (uint8)(((sint32)GET_S_DPRSMI_DangerousSide_nu()) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE)));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/AND22/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Application Parameter1'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/AND22/Functionality'/AND'
         */
    rtb_LogicalOperator_e = (uint8)((((sint32)GET_P_DPRSIA_SafetyIfaceLnOn_bool()) != 0) && (((sint32)rtb_sfun_setbit_a) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        rtb_Switch = GET_S_ABPLBP_LeLnClthHeadingSIF_rad();
    } else {
        rtb_Switch = GET_S_ABPLBP_LeLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_g) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMin_rad() - GET_P_DPRSIA_LnHeadAngThresHyst_rad();
        rtb_Div_io = GET_P_DPRSIA_LnHeadAngThresHyst_rad() + GET_P_DPRSIA_LnHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMin_rad();
        rtb_Div_io = GET_P_DPRSIA_LnHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_GT = (uint8)(((-rtb_Switch) > rtb_Switch_ob) && ((-rtb_Switch) < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND10/Functionality'/AND'
         */
    rtb_EQ = (uint8)((((sint32)rtb_EQ) != 0) && (((sint32)rtb_GT) != 0));
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_DPRSIA_VXLnCrvThresMax_1pm(), &x_dps);
    }
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_a = rtb_ip_lookup_fxpt_sfun_7;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_d) != 0) {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ja = F32_PTR_IP1D (GETA_Y_DPRSIA_VXLnCrvThresHyst_1pm(), &x_dps);
        }
        rtb_Switch_a = rtb_ip_lookup_fxpt_sfun_7_ja + rtb_ip_lookup_fxpt_sfun_7;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        rtb_Switch_mhg = GET_S_ABPLBP_LeLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_mhg = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_l1 = (uint8)(f32_abs_f32(rtb_Switch_mhg) < rtb_Switch_a);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/NOT2/Functionality'/NOT'
         */
    rtb_EQ_e = (uint8)(!(((sint32)rtb_Switch_ip) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND16/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND16/Functionality'/AND'
         */
    rtb_EQ = (uint8)(((((sint32)rtb_EQ) != 0) && (((sint32)rtb_LT_l1) != 0)) && (((sint32)rtb_EQ_e) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_kh) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresHyst_rad() + GET_P_DPRSIA_LnHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_fj = (uint8)(f32_abs_f32(rtb_Switch) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND17/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Constant2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Constant7'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND17/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND32/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Relational Operator5/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/AND8/Functionality'/AND'
         */
    rtb_DataTypeConversion_cr = (uint8)((((((sint32)rtb_LT_fj) != 0) && (((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_l1) != 0)) && (((sint32)rtb_EQ_e) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Switch2/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_a) != 0) {
        rtb_EQ_e = rtb_EQ;
    } else {
        rtb_EQ_e = rtb_DataTypeConversion_cr;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Switch2/Functionality'/Switch' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP'/Unit Delay2'
         */
    rtb_LogicalOperator = (uint8)((DW_dprsia_UnitDelay2_DSTATE_c <= 0.0F) && (((sint32)rtb_EQ_e) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ_e) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_c > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_c -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/Application Parameter4'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_c = GET_P_DPRSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/TURNONDELAYTIME/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeReInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND1/Functionality'/AND'
         */
    rtb_EQ_e = (uint8)((((sint32)GET_S_ABPREP_LeReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadBitmask_btm())) == 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Application Parameter14'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Application Parameter9'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Constant9'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND22/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPREP_LeReInvalidQuSIF_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND22/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Relational Operator9/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND21/Functionality'/AND'
         */
    if (((sint32)GET_P_DPRSIA_SafetyIfaceReOn_bool()) != 0) {
        rtb_EQ_e = (uint8)(((((sint32)GET_S_ABPREP_LeReInvalidQuSIF_btf()) & ((sint32)GET_P_DPRSIA_RoadSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_e) != 0));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/AND22/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Application Parameter1'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/AND22/Functionality'/AND'
         */
    rtb_Switch_h5 = (uint8)((((sint32)GET_P_DPRSIA_SafetyIfaceReOn_bool()) != 0) && (((sint32)rtb_sfun_setbit_a) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_LeReClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPREP_LeReHeading_rad'
         */
    if (((sint32)rtb_Switch_h5) != 0) {
        rtb_Switch_jo = GET_S_ABPREP_LeReClthHeadingSIF_rad();
    } else {
        rtb_Switch_jo = GET_S_ABPREP_LeReHeading_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_j) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMin_rad() - GET_P_DPRSIA_ReHeadAngThresHyst_rad();
        rtb_Div_io = GET_P_DPRSIA_ReHeadAngThresHyst_rad() + GET_P_DPRSIA_ReHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMin_rad();
        rtb_Div_io = GET_P_DPRSIA_ReHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_GT_pn = (uint8)(((-rtb_Switch_jo) > rtb_Switch_ob) && ((-rtb_Switch_jo) < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND9/Functionality'/AND'
         */
    rtb_EQ_e = (uint8)((((sint32)rtb_EQ_e) != 0) && (((sint32)rtb_GT_pn) != 0));
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D(GETA_Y_DPRSIA_VXReCrvThresMax_1pm (), &x_dps);
    }
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_a = rtb_ip_lookup_fxpt_sfun_7_d;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_jw) != 0) {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D (GETA_Y_DPRSIA_VXReCrvThresHyst_1pm(), &x_dps);
        }
        rtb_Switch_a = rtb_ip_lookup_fxpt_sfun_7_a + rtb_ip_lookup_fxpt_sfun_7_d;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_LeReClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
         */
    if (((sint32)rtb_Switch_h5) != 0) {
        rtb_Switch_l = GET_S_ABPREP_LeReClthCrvSIF_1pm();
    } else {
        rtb_Switch_l = GET_S_ABPREP_LeReClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_oe = (uint8)(f32_abs_f32(rtb_Switch_l) < rtb_Switch_a);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/NOT2/Functionality'/NOT'
         */
    rtb_EQ_d3 = (uint8)(!(((sint32)rtb_Switch_kz) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND14/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND14/Functionality'/AND'
         */
    rtb_EQ_e = (uint8)(((((sint32)rtb_EQ_e) != 0) && (((sint32)rtb_LT_oe) != 0)) && (((sint32)rtb_EQ_d3) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_e1) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresHyst_rad() + GET_P_DPRSIA_ReHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_ff = (uint8)(f32_abs_f32(rtb_Switch_jo) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND15/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Constant1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Constant3'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeReInvalidQu_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND15/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND29/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Relational Operator3/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND13/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_f5o = (uint8)((((((sint32)rtb_LT_ff) != 0) && (((((sint32)GET_S_ABPREP_LeReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPREP_LeReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_oe) != 0)) && (((sint32)rtb_EQ_d3) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Switch10/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_a) != 0) {
        rtb_EQ_d3 = rtb_EQ_e;
    } else {
        rtb_EQ_d3 = rtb_DataTypeConversion_f5o;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Switch10/Functionality'/Switch' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP'/Unit Delay2'
         */
    rtb_LogicalOperator_l = (uint8)((DW_dprsia_UnitDelay2_DSTATE_p <= 0.0F) && (((sint32)rtb_EQ_d3) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ_d3) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_p > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_p -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/Application Parameter4'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_p = GET_P_DPRSIA_RdBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/TURNONDELAYTIME/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Constant4'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND4/Functionality'/AND'
         */
    rtb_EQ_d3 = (uint8)((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Application Parameter15'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Application Parameter16'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Constant12'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND28/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQuSIF_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND28/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Relational Operator12/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND27/Functionality'/AND'
         */
    if (((sint32)GET_P_DPRSIA_SafetyIfaceLnOn_bool()) != 0) {
        rtb_EQ_d3 = (uint8)(((((sint32)GET_S_ABPLBP_RiLnInvalidQuSIF_btf()) & ((sint32)GET_P_DPRSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_d3) != 0));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        rtb_Switch_ct = GET_S_ABPLBP_RiLnClthHeadingSIF_rad();
    } else {
        rtb_Switch_ct = GET_S_ABPLBP_RiLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_a) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMin_rad() - GET_P_DPRSIA_LnHeadAngThresHyst_rad();
        rtb_Div_io = GET_P_DPRSIA_LnHeadAngThresHyst_rad() + GET_P_DPRSIA_LnHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMin_rad();
        rtb_Div_io = GET_P_DPRSIA_LnHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_ec = (uint8)((rtb_Switch_ct > rtb_Switch_ob) && (rtb_Switch_ct < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND11/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND11/Functionality'/AND'
         */
    rtb_EQ_d3 = (uint8)((((sint32)rtb_EQ_d3) != 0) && (((sint32)rtb_GT_ec) != 0));
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D(GETA_Y_DPRSIA_VXLnCrvThresMax_1pm (), &x_dps);
    }
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_a = rtb_ip_lookup_fxpt_sfun_7_p;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_l) != 0) {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_jc = F32_PTR_IP1D (GETA_Y_DPRSIA_VXLnCrvThresHyst_1pm(), &x_dps);
        }
        rtb_Switch_a = rtb_ip_lookup_fxpt_sfun_7_jc + rtb_ip_lookup_fxpt_sfun_7_p;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        rtb_Switch_mhg = GET_S_ABPLBP_RiLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_mhg = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight/Abs/Functionality'/Abs'
         */
    rtb_LT_px = (uint8)(f32_abs_f32(rtb_Switch_mhg) < rtb_Switch_a);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/NOT2/Functionality'/NOT'
         */
    rtb_Switch_cq = (uint8)(!(((sint32)rtb_Switch_ip) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND19/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND19/Functionality'/AND'
         */
    rtb_EQ_d3 = (uint8)(((((sint32)rtb_EQ_d3) != 0) && (((sint32)rtb_LT_px) != 0)) && (((sint32)rtb_Switch_cq) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_pa) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresHyst_rad() + GET_P_DPRSIA_LnHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight/Abs/Functionality'/Abs'
         */
    rtb_LT_c5 = (uint8)(f32_abs_f32(rtb_Switch_ct) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND20/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Constant2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Constant8'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND20/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND33/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Relational Operator8/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/AND18/Functionality'/AND'
         */
    rtb_DataTypeConversion_ae = (uint8)((((((sint32)rtb_LT_c5) != 0) && (((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_px) != 0)) && (((sint32)rtb_Switch_cq) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Switch3/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_a) != 0) {
        rtb_Switch_cq = rtb_EQ_d3;
    } else {
        rtb_Switch_cq = rtb_DataTypeConversion_ae;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Switch3/Functionality'/Switch' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP'/Unit Delay2'
         */
    rtb_LogicalOperator_h = (uint8)((DW_dprsia_UnitDelay2_DSTATE_e <= 0.0F) && (((sint32)rtb_Switch_cq) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch9/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/AND/Functionality'/AND'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch10/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch11/Functionality'/Switch'
         */
    if ((((sint32)rtb_LogicalOperator) != 0) && (((sint32)rtb_LogicalOperator_h) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch1'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/from_data_definition1'/state_source'
                 */
        SET_S_DPRSIA_LnBndValidRDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE));
    } else if (((sint32)rtb_LogicalOperator) != 0) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch1'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/from_data_definition2'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch10/Functionality'/Switch'
                 */
        SET_S_DPRSIA_LnBndValidRDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY));
    } else if (((sint32)rtb_LogicalOperator_h) != 0) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch1'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch11/Functionality'/Switch'
                 */
        SET_S_DPRSIA_LnBndValidRDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY));
    } else {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch1'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch11/Functionality'/Switch'
                 */
        SET_S_DPRSIA_LnBndValidRDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LnBndValidRDP/Switch9/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiReInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND3/Functionality'/AND'
         */
    rtb_EQ_n = (uint8)((((sint32)GET_S_ABPREP_RiReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadBitmask_btm())) == 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Constant10'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND24/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPREP_RiReInvalidQuSIF_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND24/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Relational Operator10/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND23/Functionality'/AND'
         */
    if (((sint32)GET_P_DPRSIA_SafetyIfaceReOn_bool()) != 0) {
        rtb_EQ_n = (uint8)(((((sint32)GET_S_ABPREP_RiReInvalidQuSIF_btf()) & ((sint32)GET_P_DPRSIA_RoadSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_n) != 0));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_RiReClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPREP_RiReHeading_rad'
         */
    if (((sint32)rtb_Switch_h5) != 0) {
        rtb_Switch_mhg = GET_S_ABPREP_RiReClthHeadingSIF_rad();
    } else {
        rtb_Switch_mhg = GET_S_ABPREP_RiReHeading_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_nz) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMin_rad() - GET_P_DPRSIA_ReHeadAngThresHyst_rad();
        rtb_Div_io = GET_P_DPRSIA_ReHeadAngThresHyst_rad() + GET_P_DPRSIA_ReHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMin_rad();
        rtb_Div_io = GET_P_DPRSIA_ReHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_ft = (uint8)((rtb_Switch_mhg > rtb_Switch_ob) && (rtb_Switch_mhg < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND30/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND30/Functionality'/AND'
         */
    rtb_EQ_n = (uint8)((((sint32)rtb_EQ_n) != 0) && (((sint32)rtb_GT_ft) != 0));
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D(GETA_Y_DPRSIA_VXReCrvThresMax_1pm (), &x_dps);
    }
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_a = rtb_ip_lookup_fxpt_sfun_7_f;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_j0) != 0) {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ke = F32_PTR_IP1D (GETA_Y_DPRSIA_VXReCrvThresHyst_1pm(), &x_dps);
        }
        rtb_Switch_a = rtb_ip_lookup_fxpt_sfun_7_ke + rtb_ip_lookup_fxpt_sfun_7_f;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_RiReClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
         */
    if (((sint32)rtb_Switch_h5) != 0) {
        rtb_Switch_l = GET_S_ABPREP_RiReClthCrvSIF_1pm();
    } else {
        rtb_Switch_l = GET_S_ABPREP_RiReClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight/Abs/Functionality'/Abs'
         */
    rtb_LT_i = (uint8)(f32_abs_f32(rtb_Switch_l) < rtb_Switch_a);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/NOT2/Functionality'/NOT'
         */
    rtb_Switch_pa = (uint8)(!(((sint32)rtb_Switch_kz) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND6/Functionality'/AND'
         */
    rtb_EQ_n = (uint8)(((((sint32)rtb_EQ_n) != 0) && (((sint32)rtb_LT_i) != 0)) && (((sint32)rtb_Switch_pa) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_f) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresHyst_rad() + GET_P_DPRSIA_ReHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight/Abs/Functionality'/Abs'
         */
    rtb_LT_oq = (uint8)(f32_abs_f32(rtb_Switch_mhg) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Constant2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Constant6'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiReInvalidQu_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND31/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND7/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Relational Operator4/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/AND5/Functionality'/AND'
         */
    rtb_DataTypeConversion_kz = (uint8)((((((sint32)rtb_LT_oq) != 0) && (((((sint32)GET_S_ABPREP_RiReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPREP_RiReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_i) != 0)) && (((sint32)rtb_Switch_pa) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_a) != 0) {
        rtb_Switch_pa = rtb_EQ_n;
    } else {
        rtb_Switch_pa = rtb_DataTypeConversion_kz;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Switch1/Functionality'/Switch' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP'/Unit Delay2'
         */
    rtb_LogicalOperator_df = (uint8)((DW_dprsia_UnitDelay2_DSTATE_k <= 0.0F) && (((sint32)rtb_Switch_pa) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch9/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/AND/Functionality'/AND'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch10/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch11/Functionality'/Switch'
         */
    if ((((sint32)rtb_LogicalOperator_l) != 0) && (((sint32)rtb_LogicalOperator_df) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch5'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/from_data_definition1'/state_source'
                 */
        SET_S_DPRSIA_RdBndValidRDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE));
    } else if (((sint32)rtb_LogicalOperator_l) != 0) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch5'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/from_data_definition2'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch10/Functionality'/Switch'
                 */
        SET_S_DPRSIA_RdBndValidRDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY));
    } else if (((sint32)rtb_LogicalOperator_df) != 0) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch5'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch11/Functionality'/Switch'
                 */
        SET_S_DPRSIA_RdBndValidRDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY));
    } else {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch5'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch11/Functionality'/Switch'
                 */
        SET_S_DPRSIA_RdBndValidRDP_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RdBndValidRDP/Switch9/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_cq) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_e > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_e -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/Application Parameter4'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_e = GET_P_DPRSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_pa) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_k > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_k -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/Application Parameter2'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_k = GET_P_DPRSIA_RdBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/TURNONDELAYTIME/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Relational Operator1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Constant2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Constant5'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND10/Functionality'/AND'
         */
    rtb_Switch_cq = (uint8)((((sint32)GET_P_DPRSIA_TriggerCondEnable_btm()) & 4) != 0);
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Relational Operator4/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Constant1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Constant6'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND11/Functionality'/AND'
         */
    rtb_NE_e = (uint8)((((sint32)GET_P_DPRSIA_TriggerCondEnable_btm()) & 1) != 0);
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Relational Operator2/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Constant4'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Constant8'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND13/Functionality'/AND'
         */
    rtb_Switch_pa = (uint8)((((sint32)GET_P_DPRSIA_TriggerCondEnable_btm()) & 8) != 0);
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Relational Operator5/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Constant3'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Constant7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND12/Functionality'/AND'
         */
    rtb_NE_hm = (uint8)((((sint32)GET_P_DPRSIA_TriggerCondEnable_btm()) & 2) != 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch2/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND15/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND6/Functionality'/AND'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch3/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch4/Functionality'/Switch'
         */
    if ((((((sint32)rtb_Switch_pa) != 0) && (((sint32)rtb_LogicalOperator_l) != 0)) && (((sint32)rtb_LogicalOperator) != 0)) && (((sint32) rtb_LogicalOperator_h) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch11'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition5'/state_source'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH));
    } else if (((((sint32)rtb_Switch_cq) != 0) && (((sint32)rtb_LogicalOperator_l) != 0)) && (((sint32)rtb_LogicalOperator_h) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch11'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch1/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS));
    } else if (((((sint32)rtb_NE_hm) != 0) && (((sint32)rtb_LogicalOperator_l) != 0)) && (((sint32)rtb_LogicalOperator) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch11'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch3/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG));
    } else if ((((sint32)rtb_NE_e) != 0) && (((sint32)rtb_LogicalOperator_l) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch11'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition1'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch3/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch4/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY));
    } else {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch11'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition11'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch3/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch4/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch6/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND14/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND7/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/AND9/Functionality'/AND'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch7/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch8/Functionality'/Switch'
         */
    if ((((((sint32)rtb_Switch_pa) != 0) && (((sint32)rtb_LogicalOperator_df) != 0)) && (((sint32)rtb_LogicalOperator_h) != 0)) && (((sint32) rtb_LogicalOperator) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch16'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition9'/state_source'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH));
    } else if (((((sint32)rtb_Switch_cq) != 0) && (((sint32)rtb_LogicalOperator_df) != 0)) && (((sint32)rtb_LogicalOperator) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch16'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition8'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch5/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS));
    } else if (((((sint32)rtb_NE_hm) != 0) && (((sint32)rtb_LogicalOperator_df) != 0)) && (((sint32)rtb_LogicalOperator_h) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch16'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition7'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch7/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG));
    } else if ((((sint32)rtb_NE_e) != 0) && (((sint32)rtb_LogicalOperator_df) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch16'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition2'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch8/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY));
    } else {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch16'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/from_data_definition6'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch8/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDP_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/CurrentSituation/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch9/Functionality'/Switch'
         */
    if (((sint32)rtb_LogicalOperator_e) != 0) {
        rtb_Switch_l = GET_S_ABPLBP_RiLnClthPosY0SIF_met();
        rtb_Switch_fr = GET_S_ABPLBP_LeLnClthPosY0SIF_met();
    } else {
        rtb_Switch_l = GET_S_ABPLBP_RiLnClthPosY0_met();
        rtb_Switch_fr = GET_S_ABPLBP_LeLnClthPosY0_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_ABPLBP_UncoupledLaneWidth_met'
         */
    if (((sint32)GET_P_DPRSIA_UncoupledLWEnable_bool()) != 0) {
        rtb_Switch_hh[1] = GET_S_ABPLBP_UncoupledLaneWidth_met();
    } else {
        rtb_Switch_hh[1] = GET_S_ABPLBP_CoupledLaneWidth_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/LaneBoundaryInterface/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch9/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_LeReClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPREP_LeRePosY0_met'
         *  Inport: '<Root>/S_ABPREP_RiReClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPREP_RiRePosY0_met'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_h5) != 0) {
        rtb_Switch_d = GET_S_ABPREP_LeReClthPosY0SIF_met();
        rtb_Switch_jd = GET_S_ABPREP_RiReClthPosY0SIF_met();
    } else {
        rtb_Switch_d = GET_S_ABPREP_LeRePosY0_met();
        rtb_Switch_jd = GET_S_ABPREP_RiRePosY0_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Switch9/Functionality'/Switch' */
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/RoadBoundaryInterface/Sum/Functionality'/Sum' */
    rtb_Sum_mg = rtb_Switch_d - rtb_Switch_jd;
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalState_enum'
         */
    rtb_Switch_cq = (uint8)(((sint32)GET_S_LCFRCV_TurnSignalState_enum()) == ((sint32)((uint8)E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_RIGHT)));
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/from_data_definition'/state_source'
         *  Inport: '<Root>/S_LCFRCV_TurnSignalState_enum'
         */
    rtb_NE_e = (uint8)(((sint32)GET_S_LCFRCV_TurnSignalState_enum()) == ((sint32) ((uint8)E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_LEFT)));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Constant1'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1'/Unit_Delay'
         */
    if (((sint32)GET_P_DPRSIA_TurnSignReset_bool()) != 0) {
        /* S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1'/fcg' incorporates:
                 *  SubSystem: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality'/Comparison'
                 */
        tmp_1 = (uint8)((!(((sint32)DW_dprsia_Unit_Delay_DSTATE) != 0)) && (((sint32) rtb_NE_e) != 0));
        /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1'/fcg' */
    } else {
        tmp_1 = 0U;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Switch10/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Constant2'/Constant'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Switch/Functionality'/Switch'
         */
    if (((sint32)tmp_1) != 0) {
        rtb_Switch_a = 0.0F;
    } else if (((sint32)rtb_Switch_cq) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Application Parameter1'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Add2/Functionality'/Sum'
                 */
        rtb_Switch_a = GET_P_DPRSIA_TurnSignHoldingTime_sec() + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Switch/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi'/Unit Delay1'
                 */
        rtb_Switch_a = DW_dprsia_UnitDelay1_DSTATE_f;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Constant3'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Relational Operator8/Functionality'/GT'
         */
    rtb_Switch_h5 = (uint8)((((sint32)rtb_Switch_cq) != 0) || (rtb_Switch_a > 1.0E-5F));
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1[0] = rtb_Switch_h5;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In4' */
    rtb_VectorConcatenate1[3] = rtb_DataTypeConversion_oo;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In5' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/Constant4'/Constant'
         */
    rtb_VectorConcatenate1[4] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In6' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/Constant4'/Constant'
         */
    rtb_VectorConcatenate1[5] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In7' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/Constant4'/Constant'
         */
    rtb_VectorConcatenate1[6] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In8' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/Constant4'/Constant'
         */
    rtb_VectorConcatenate1[7] = 0U;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Switch9/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Constant4'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising'/Unit_Delay'
         */
    if (((sint32)GET_P_DPRSIA_TurnSignReset_bool()) != 0) {
        /* S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1'/fcg' incorporates:
                 *  SubSystem: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality'/Comparison'
                 */
        tmp_1 = (uint8)((!(((sint32)DW_dprsia_Unit_Delay_DSTATE_e) != 0)) && (((sint32)rtb_Switch_cq) != 0));
        /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1'/fcg' */
    } else {
        tmp_1 = 0U;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Switch9/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Constant2'/Constant'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch'
         */
    if (((sint32)tmp_1) != 0) {
        rtb_Switch_gv = 0.0F;
    } else if (((sint32)rtb_NE_e) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/Application Parameter5'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Add2/Functionality'/Sum'
                 */
        rtb_Switch_gv = GET_P_DPRSIA_TurnSignHoldingTime_sec() + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Switch/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe'/Unit Delay1'
                 */
        rtb_Switch_gv = DW_dprsia_UnitDelay1_DSTATE_m;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Constant3'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Relational Operator8/Functionality'/GT'
         */
    rtb_LogicalOperator_e = (uint8)((((sint32)rtb_NE_e) != 0) || (rtb_Switch_gv > 1.0E-5F));
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_LogicalOperator_e;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_DataTypeConversion_j1;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn5' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate[4] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate[5] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate[6] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate[7] = 0U;
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Add2/Functionality'/Sum' */
    rtb_Switch_buc = rtb_Switch_d - rtb_Switch_l;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/P_LDPSA_VelXMax_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_jv) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnRdWidthMin_met() - GET_P_DPRSIA_LnRdWidthHyst_met();
        rtb_Div_io = GET_P_DPRSIA_LnRdWidthHyst_met() + GET_P_DPRSIA_LnRdWidthMax_met();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnRdWidthMin_met();
        rtb_Div_io = GET_P_DPRSIA_LnRdWidthMax_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Relational Operator1/Functionality'/LT'
         */
    rtb_NE_hm = (uint8)((rtb_Switch_buc > rtb_Switch_ob) && (rtb_Switch_buc < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Logical Operator2/Functionality'/AND'
         */
    rtb_sfun_setbit_j = (uint8)((((sint32)rtb_LogicalOperator_l) != 0) && (((sint32)rtb_LogicalOperator_h) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Constant2'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Logical Operator/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Logical Operator/Functionality'/NOT'
         */
    if (((sint32)rtb_sfun_setbit_j) != 0) {
        rtb_VectorConcatenate[2] = (uint8)(!(((sint32)rtb_NE_hm) != 0));
    } else {
        rtb_VectorConcatenate[2] = 0U;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft/Switch2/Functionality'/Switch' */
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Add2/Functionality'/Sum' */
    rtb_Switch_ky = rtb_Switch_fr - rtb_Switch_jd;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/P_LDPSA_VelXMax_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_oz) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnRdWidthMin_met() - GET_P_DPRSIA_LnRdWidthHyst_met();
        rtb_Div_io = GET_P_DPRSIA_LnRdWidthHyst_met() + GET_P_DPRSIA_LnRdWidthMax_met();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnRdWidthMin_met();
        rtb_Div_io = GET_P_DPRSIA_LnRdWidthMax_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Relational Operator1/Functionality'/LT'
         */
    rtb_Switch_pa = (uint8)((rtb_Switch_ky > rtb_Switch_ob) && (rtb_Switch_ky < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Logical Operator2/Functionality'/AND'
         */
    rtb_sfun_setbit_j = (uint8)((((sint32)rtb_LogicalOperator_df) != 0) && (((sint32)rtb_LogicalOperator) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Constant2'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Logical Operator/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Logical Operator/Functionality'/NOT'
         */
    if (((sint32)rtb_sfun_setbit_j) != 0) {
        rtb_VectorConcatenate1[2] = (uint8)(!(((sint32)rtb_Switch_pa) != 0));
    } else {
        rtb_VectorConcatenate1[2] = 0U;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Product1/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator_l) != 0) {
        rtb_Switch_c3 = GET_S_LCFRCV_VehVelX_mps() * rtb_Switch_jo;
    } else {
        rtb_Switch_c3 = 0.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_nr) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMin_mps() - GET_P_DPRSIA_VelLatThresHyst_mps();
        rtb_Div_io = GET_P_DPRSIA_VelLatThresHyst_mps() + GET_P_DPRSIA_VelLatThresMax_mps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMin_mps();
        rtb_Div_io = GET_P_DPRSIA_VelLatThresMax_mps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_GT_n = (uint8)(((-rtb_Switch_c3) > rtb_Switch_ob) && ((-rtb_Switch_c3) < rtb_Div_io));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps5'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft'/Unit Delay1'
         */
    if (((sint32)DW_dprsia_UnitDelay1_DSTATE_n) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresHyst_mps() + GET_P_DPRSIA_VelLatThresMax_mps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMax_mps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Abs/Functionality'/Abs'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_LT_ny = (uint8)(f32_abs_f32(-rtb_Switch_c3) < rtb_Switch_ob);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Switch4/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_a) != 0) {
        rtb_sfun_setbit_j = rtb_GT_n;
    } else {
        rtb_sfun_setbit_j = rtb_LT_ny;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate[1] = (uint8)(!(((sint32)rtb_sfun_setbit_j) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Product3/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator_df) != 0) {
        rtb_Switch_p = GET_S_LCFRCV_VehVelX_mps() * rtb_Switch_mhg;
    } else {
        rtb_Switch_p = 0.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_ey) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMin_mps() - GET_P_DPRSIA_VelLatThresHyst_mps();
        rtb_Div_io = GET_P_DPRSIA_VelLatThresHyst_mps() + GET_P_DPRSIA_VelLatThresMax_mps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMin_mps();
        rtb_Div_io = GET_P_DPRSIA_VelLatThresMax_mps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_o = (uint8)((rtb_Switch_p > rtb_Switch_ob) && (rtb_Switch_p < rtb_Div_io));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps5'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight'/Unit Delay1'
         */
    if (((sint32)DW_dprsia_UnitDelay1_DSTATE_f0) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresHyst_mps() + GET_P_DPRSIA_VelLatThresMax_mps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMax_mps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Abs/Functionality'/Abs'
         */
    rtb_LT_n = (uint8)(f32_abs_f32(rtb_Switch_p) < rtb_Switch_ob);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Switch2/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_a) != 0) {
        rtb_sfun_setbit_a = rtb_GT_o;
    } else {
        rtb_sfun_setbit_a = rtb_LT_n;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate1[1] = (uint8)(!(((sint32)rtb_sfun_setbit_a) != 0));
    /* S-Function (sfun_setbit): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_j = temp;
    }
    /* S-Function (sfun_setbit): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate1[0];
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
        rtb_sfun_setbit_a = temp;
    }
    /* Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/Divide/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/Constant'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/P_VEH_Width_met'/Constant'
         */
    rtb_Div = GET_P_VEH_Width_met() / 2.0F;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Constant1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Constant6'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Product/Functionality'/Mul'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Add/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_LogicalOperator) != 0) {
        rtb_Switch_fr -= rtb_Div;
        rtb_Switch_k0 = GET_S_LCFRCV_VehVelX_mps() * rtb_Switch;
    } else {
        rtb_Switch_fr = 10.0F;
        rtb_Switch_k0 = 0.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Constant15'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Constant7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/P_VEH_Width_met3'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/AND7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/LT2/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Neg2/Functionality'/Unary Minus'
         */
    if (((rtb_Switch_fr > 0.0F) && (((sint32)rtb_LogicalOperator) != 0)) && (rtb_Switch < (-GET_P_DPRSIA_TlcHeadAngThres_rad()))) {
        /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Abs/Functionality'/Abs' */
        rtb_Switch = f32_abs_f32(rtb_Switch_k0);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Divide1/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Divide1/In3'/Constant'
                 *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Divide1/Functionality/DivDefault'/Div'
                 */
        if (rtb_Switch != 0.0F) {
            rtb_Switch_ky = rtb_Switch_fr / rtb_Switch;
        } else {
            rtb_Switch_ky = 10000.0F;
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Divide1/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_ky = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch22'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Constant7'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcLe/Min1/Functionality'/Min'
         */
    SET_S_DPRSIA_TlcLeRDP_sec(f32_min_f32_f32(rtb_Switch_ky, 10.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Switch5/Functionality'/Switch' incorporates:
                                                                        *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Constant1'/Constant'
                                                                        *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Constant9'/Constant'
                                                                        *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                                                                        *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Product2/Functionality'/Mul'
                                                                        *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Add1/Functionality'/Sum'
                                                                        *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Switch1/Functionality'/Switch'
                                                                        */
    if (((sint32)rtb_LogicalOperator_h) != 0) {
        rtb_Switch_l += rtb_Div;
        rtb_Switch = GET_S_LCFRCV_VehVelX_mps() * rtb_Switch_ct;
    } else {
        rtb_Switch_l = -10.0F;
        rtb_Switch = 0.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Constant10'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Constant17'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/P_VEH_Width_met4'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/AND8/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/GT3/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/LT3/Functionality'/LT'
         */
    if (((rtb_Switch_l < 0.0F) && (((sint32)rtb_LogicalOperator_h) != 0)) && (rtb_Switch_ct > GET_P_DPRSIA_TlcHeadAngThres_rad())) {
        /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Abs2/Functionality'/Abs' */
        rtb_Switch_ct = f32_abs_f32(rtb_Switch);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Divide2/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Divide2/In3'/Constant'
                 *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Divide2/Functionality/DivDefault'/Div'
                 *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Neg3/Functionality'/Unary Minus'
                 */
        if (rtb_Switch_ct != 0.0F) {
            rtb_Switch_buc = (-rtb_Switch_l) / rtb_Switch_ct;
        } else {
            rtb_Switch_buc = 10000.0F;
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Divide2/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_buc = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Switch6/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch23'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Constant10'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DlcTlcRi/Min3/Functionality'/Min'
         */
    SET_S_DPRSIA_TlcRiRDP_sec(f32_min_f32_f32(rtb_Switch_buc, 10.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Switch1/Functionality'/Switch' incorporates:
                                                                         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Constant3'/Constant'
                                                                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Add2/Functionality'/Sum'
                                                                         */
    if (((sint32)rtb_LogicalOperator_l) != 0) {
        rtb_Switch_d -= rtb_Div;
    } else {
        rtb_Switch_d = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Constant11'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Constant12'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/P_VEH_Width_met2'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/AND5/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Neg/Functionality'/Unary Minus'
         */
    if (((rtb_Switch_d > 0.0F) && (((sint32)rtb_LogicalOperator_l) != 0)) && (rtb_Switch_jo < (-GET_P_DPRSIA_TrcHeadAngThres_rad()))) {
        /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Abs1/Functionality'/Abs' */
        rtb_Switch_jo = f32_abs_f32(rtb_Switch_c3);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Divide3/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Divide3/In3'/Constant'
                 *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Divide3/Functionality/DivDefault'/Div'
                 */
        if (rtb_Switch_jo != 0.0F) {
            rtb_Switch_jo = rtb_Switch_d / rtb_Switch_jo;
        } else {
            rtb_Switch_jo = 10000.0F;
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Divide3/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_jo = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Switch7/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch21'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Constant11'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcLe/Min/Functionality'/Min'
         */
    SET_S_DPRSIA_TrcLeRDP_sec(f32_min_f32_f32(rtb_Switch_jo, 10.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Switch4/Functionality'/Switch' incorporates:
                                                                        *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Constant8'/Constant'
                                                                        *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Add3/Functionality'/Sum'
                                                                        */
    if (((sint32)rtb_LogicalOperator_df) != 0) {
        rtb_Switch_jd += rtb_Div;
    } else {
        rtb_Switch_jd = -10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Constant13'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Constant14'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/P_VEH_Width_met1'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/AND6/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/LT1/Functionality'/LT'
         */
    if (((rtb_Switch_jd < 0.0F) && (((sint32)rtb_LogicalOperator_df) != 0)) && (rtb_Switch_mhg > GET_P_DPRSIA_TrcHeadAngThres_rad())) {
        /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Abs3/Functionality'/Abs' */
        rtb_Switch_mhg = f32_abs_f32(rtb_Switch_p);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Divide4/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Divide4/In3'/Constant'
                 *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Divide4/Functionality/DivDefault'/Div'
                 *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Neg1/Functionality'/Unary Minus'
                 */
        if (rtb_Switch_mhg != 0.0F) {
            rtb_Switch_mhg = (-rtb_Switch_jd) / rtb_Switch_mhg;
        } else {
            rtb_Switch_mhg = 10000.0F;
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Divide4/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_mhg = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Switch8/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch26'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Constant13'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/VariableCalculation/DrcTrcRi/Min2/Functionality'/Min'
         */
    SET_S_DPRSIA_TrcRiRDP_sec(f32_min_f32_f32(rtb_Switch_mhg, 10.0F));
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Relational Operator7/Functionality'/EQ' incorporates:
                                                                         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Application Parameter1'/Constant'
                                                                         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Constant5'/Constant'
                                                                         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
                                                                         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND2/Functionality'/AND'
                                                                         */
    rtb_LogicalOperator = (uint8)((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32)GET_P_DPRSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Application Parameter11'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Constant11'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND26/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQuSIF_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND26/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Relational Operator11/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND25/Functionality'/AND'
         */
    if (((sint32)GET_P_DPRSIA_SafetyIfaceLnOn_bool()) != 0) {
        rtb_LogicalOperator = (uint8)(((((sint32)GET_S_ABPLBP_LeLnInvalidQuSIF_btf ()) & ((sint32)GET_P_DPRSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32) rtb_LogicalOperator) != 0));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Switch6/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPRSMW_DangerousSide_nu'
         */
    rtb_sfun_setbit_hp = (uint8)(((sint32)GET_S_DPRSMW_DangerousSide_nu()) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE)));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/AND22/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Application Parameter1'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/AND22/Functionality'/AND'
         */
    rtb_sfun_setbit = (uint8)((((sint32)GET_P_DPRSIA_SafetyIfaceLnOn_bool()) != 0) && (((sint32)rtb_sfun_setbit_hp) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         */
    if (((sint32)rtb_sfun_setbit) != 0) {
        rtb_Switch_buc = GET_S_ABPLBP_LeLnClthHeadingSIF_rad();
    } else {
        rtb_Switch_buc = GET_S_ABPLBP_LeLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_h) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMin_rad() - GET_P_DPRSIA_LnHeadAngThresHyst_rad();
        rtb_Div_io = GET_P_DPRSIA_LnHeadAngThresHyst_rad() + GET_P_DPRSIA_LnHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMin_rad();
        rtb_Div_io = GET_P_DPRSIA_LnHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_LogicalOperator_l = (uint8)(((-rtb_Switch_buc) > rtb_Switch_ob) && ((-rtb_Switch_buc) < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND10/Functionality'/AND'
         */
    rtb_LogicalOperator = (uint8)((((sint32)rtb_LogicalOperator) != 0) && (((sint32)rtb_LogicalOperator_l) != 0));
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D(GETA_Y_DPRSIA_VXLnCrvThresMax_1pm (), &x_dps);
    }
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_m;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_lw) != 0) {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_DPRSIA_VXLnCrvThresHyst_1pm(), &x_dps);
        }
        rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_j + rtb_ip_lookup_fxpt_sfun_7_m;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         */
    if (((sint32)rtb_sfun_setbit) != 0) {
        rtb_Switch_ob = GET_S_ABPLBP_LeLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_ob = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft/Abs/Functionality'/Abs'
         */
    rtb_LogicalOperator_h = (uint8)(f32_abs_f32(rtb_Switch_ob) < rtb_Abs_g);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/NOT2/Functionality'/NOT'
         */
    rtb_EQ_mo = (uint8)(!(((sint32)rtb_Switch_ip) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND16/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND16/Functionality'/AND'
         */
    rtb_LogicalOperator = (uint8)(((((sint32)rtb_LogicalOperator) != 0) && (((sint32)rtb_LogicalOperator_h) != 0)) && (((sint32)rtb_EQ_mo) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_km) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresHyst_rad() + GET_P_DPRSIA_LnHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft/Abs/Functionality'/Abs'
         */
    rtb_LogicalOperator_df = (uint8)(f32_abs_f32(rtb_Switch_buc) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND17/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Constant2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Constant7'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND17/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND32/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Relational Operator5/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/AND8/Functionality'/AND'
         */
    rtb_DataTypeConversion_ke = (uint8)((((((sint32)rtb_LogicalOperator_df) != 0) && (((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPLBP_LeLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneBridgedBitmask_btm())) != 0))) && (((sint32) rtb_LogicalOperator_h) != 0)) && (((sint32)rtb_EQ_mo) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Switch2/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        rtb_EQ_mo = rtb_LogicalOperator;
    } else {
        rtb_EQ_mo = rtb_DataTypeConversion_ke;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Switch2/Functionality'/Switch' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW'/Unit Delay2'
         */
    rtb_LogicalOperator_f = (uint8)((DW_dprsia_UnitDelay2_DSTATE_o <= 0.0F) && (((sint32)rtb_EQ_mo) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ_mo) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_o > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_o -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/Application Parameter4'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_o = GET_P_DPRSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/TURNONDELAYTIME/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeReInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND1/Functionality'/AND'
         */
    rtb_EQ_mo = (uint8)((((sint32)GET_S_ABPREP_LeReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadBitmask_btm())) == 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Application Parameter14'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Application Parameter9'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Constant9'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND22/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPREP_LeReInvalidQuSIF_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND22/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Relational Operator9/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND21/Functionality'/AND'
         */
    if (((sint32)GET_P_DPRSIA_SafetyIfaceReOn_bool()) != 0) {
        rtb_EQ_mo = (uint8)(((((sint32)GET_S_ABPREP_LeReInvalidQuSIF_btf()) & ((sint32)GET_P_DPRSIA_RoadSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_mo) != 0));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/AND22/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Application Parameter1'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/AND22/Functionality'/AND'
         */
    rtb_sfun_setbit_h = (uint8)((((sint32)GET_P_DPRSIA_SafetyIfaceReOn_bool()) != 0) && (((sint32)rtb_sfun_setbit_hp) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_LeReClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPREP_LeReHeading_rad'
         */
    if (((sint32)rtb_sfun_setbit_h) != 0) {
        rtb_Switch_hi = GET_S_ABPREP_LeReClthHeadingSIF_rad();
    } else {
        rtb_Switch_hi = GET_S_ABPREP_LeReHeading_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_es) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMin_rad() - GET_P_DPRSIA_ReHeadAngThresHyst_rad();
        rtb_Div_io = GET_P_DPRSIA_ReHeadAngThresHyst_rad() + GET_P_DPRSIA_ReHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMin_rad();
        rtb_Div_io = GET_P_DPRSIA_ReHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_GT_mtz = (uint8)(((-rtb_Switch_hi) > rtb_Switch_ob) && ((-rtb_Switch_hi) < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND9/Functionality'/AND'
         */
    rtb_EQ_mo = (uint8)((((sint32)rtb_EQ_mo) != 0) && (((sint32)rtb_GT_mtz) != 0));
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D(GETA_Y_DPRSIA_VXReCrvThresMax_1pm (), &x_dps);
    }
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_c;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_an) != 0) {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_do = F32_PTR_IP1D (GETA_Y_DPRSIA_VXReCrvThresHyst_1pm(), &x_dps);
        }
        rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_do + rtb_ip_lookup_fxpt_sfun_7_c;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_LeReClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
         */
    if (((sint32)rtb_sfun_setbit_h) != 0) {
        rtb_Switch_ob = GET_S_ABPREP_LeReClthCrvSIF_1pm();
    } else {
        rtb_Switch_ob = GET_S_ABPREP_LeReClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_nke = (uint8)(f32_abs_f32(rtb_Switch_ob) < rtb_Abs_g);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/NOT2/Functionality'/NOT'
         */
    rtb_EQ_b = (uint8)(!(((sint32)rtb_Switch_kz) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND14/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND14/Functionality'/AND'
         */
    rtb_EQ_mo = (uint8)(((((sint32)rtb_EQ_mo) != 0) && (((sint32)rtb_LT_nke) != 0)) && (((sint32)rtb_EQ_b) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_ew) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresHyst_rad() + GET_P_DPRSIA_ReHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft/Abs/Functionality'/Abs'
         */
    rtb_LT_hd = (uint8)(f32_abs_f32(rtb_Switch_hi) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND15/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Constant1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Constant3'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeReInvalidQu_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND15/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND29/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Relational Operator3/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND13/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_da = (uint8)((((((sint32)rtb_LT_hd) != 0) && (((((sint32)GET_S_ABPREP_LeReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPREP_LeReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_nke) != 0)) && (((sint32)rtb_EQ_b) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Switch10/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        rtb_EQ_b = rtb_EQ_mo;
    } else {
        rtb_EQ_b = rtb_DataTypeConversion_da;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Switch10/Functionality'/Switch' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW'/Unit Delay2'
         */
    rtb_LogicalOperator_d = (uint8)((DW_dprsia_UnitDelay2_DSTATE_ej <= 0.0F) && (((sint32)rtb_EQ_b) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_EQ_b) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_ej > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_ej -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/Application Parameter4'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_ej = GET_P_DPRSIA_RdBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/TURNONDELAYTIME/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Constant4'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND4/Functionality'/AND'
         */
    rtb_EQ_b = (uint8)((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneBitmask_btm())) == 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Application Parameter15'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Application Parameter16'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Constant12'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND28/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQuSIF_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND28/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Relational Operator12/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND27/Functionality'/AND'
         */
    if (((sint32)GET_P_DPRSIA_SafetyIfaceLnOn_bool()) != 0) {
        rtb_EQ_b = (uint8)(((((sint32)GET_S_ABPLBP_RiLnInvalidQuSIF_btf()) & ((sint32)GET_P_DPRSIA_LaneSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_b) != 0));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Switch7/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         */
    if (((sint32)rtb_sfun_setbit) != 0) {
        rtb_Switch_pi = GET_S_ABPLBP_RiLnClthHeadingSIF_rad();
    } else {
        rtb_Switch_pi = GET_S_ABPLBP_RiLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_pu) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMin_rad() - GET_P_DPRSIA_LnHeadAngThresHyst_rad();
        rtb_Div_io = GET_P_DPRSIA_LnHeadAngThresHyst_rad() + GET_P_DPRSIA_LnHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMin_rad();
        rtb_Div_io = GET_P_DPRSIA_LnHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_fm = (uint8)((rtb_Switch_pi > rtb_Switch_ob) && (rtb_Switch_pi < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND11/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND11/Functionality'/AND'
         */
    rtb_EQ_b = (uint8)((((sint32)rtb_EQ_b) != 0) && (((sint32)rtb_GT_fm) != 0));
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D(GETA_Y_DPRSIA_VXLnCrvThresMax_1pm (), &x_dps);
    }
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_b;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_cc) != 0) {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_fz = F32_PTR_IP1D (GETA_Y_DPRSIA_VXLnCrvThresHyst_1pm(), &x_dps);
        }
        rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_fz + rtb_ip_lookup_fxpt_sfun_7_b;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    if (((sint32)rtb_sfun_setbit) != 0) {
        rtb_Switch_ob = GET_S_ABPLBP_RiLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_ob = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight/Abs/Functionality'/Abs'
         */
    rtb_LT_c = (uint8)(f32_abs_f32(rtb_Switch_ob) < rtb_Abs_g);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/NOT2/Functionality'/NOT'
         */
    rtb_Switch_ip = (uint8)(!(((sint32)rtb_Switch_ip) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND19/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND19/Functionality'/AND'
         */
    rtb_EQ_b = (uint8)(((((sint32)rtb_EQ_b) != 0) && (((sint32)rtb_LT_c) != 0)) && (((sint32)rtb_Switch_ip) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_ou) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresHyst_rad() + GET_P_DPRSIA_LnHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight/Abs/Functionality'/Abs'
         */
    rtb_LT_nt = (uint8)(f32_abs_f32(rtb_Switch_pi) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND20/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Constant2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Constant8'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND20/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND33/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Relational Operator8/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/AND18/Functionality'/AND'
         */
    rtb_DataTypeConversion_o3r = (uint8)((((((sint32)rtb_LT_nt) != 0) && (((((sint32)GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_LaneBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_c) != 0)) && (((sint32)rtb_Switch_ip) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Switch3/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        rtb_Switch_ip = rtb_EQ_b;
    } else {
        rtb_Switch_ip = rtb_DataTypeConversion_o3r;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Switch3/Functionality'/Switch' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW'/Unit Delay2'
         */
    rtb_LogicalOperator_c = (uint8)((DW_dprsia_UnitDelay2_DSTATE_pt <= 0.0F) && (((sint32)rtb_Switch_ip) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch9/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/AND/Functionality'/AND'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch10/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch11/Functionality'/Switch'
         */
    if ((((sint32)rtb_LogicalOperator_f) != 0) && (((sint32)rtb_LogicalOperator_c) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch27'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/from_data_definition1'/state_source'
                 */
        SET_S_DPRSIA_LnBndValidRDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE));
    } else if (((sint32)rtb_LogicalOperator_f) != 0) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch27'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/from_data_definition2'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch10/Functionality'/Switch'
                 */
        SET_S_DPRSIA_LnBndValidRDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY));
    } else if (((sint32)rtb_LogicalOperator_c) != 0) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch27'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch11/Functionality'/Switch'
                 */
        SET_S_DPRSIA_LnBndValidRDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY));
    } else {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch27'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch11/Functionality'/Switch'
                 */
        SET_S_DPRSIA_LnBndValidRDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LnBndValidRDW/Switch9/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiReInvalidQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND3/Functionality'/AND'
         */
    rtb_EQ_p = (uint8)((((sint32)GET_S_ABPREP_RiReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadBitmask_btm())) == 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Constant10'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND24/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_ABPREP_RiReInvalidQuSIF_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND24/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Relational Operator10/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND23/Functionality'/AND'
         */
    if (((sint32)GET_P_DPRSIA_SafetyIfaceReOn_bool()) != 0) {
        rtb_EQ_p = (uint8)(((((sint32)GET_S_ABPREP_RiReInvalidQuSIF_btf()) & ((sint32)GET_P_DPRSIA_RoadSafetyBitmask_btm())) == 0) && (((sint32) rtb_EQ_p) != 0));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_RiReClthHeadingSIF_rad'
         *  Inport: '<Root>/S_ABPREP_RiReHeading_rad'
         */
    if (((sint32)rtb_sfun_setbit_h) != 0) {
        rtb_Switch_n = GET_S_ABPREP_RiReClthHeadingSIF_rad();
    } else {
        rtb_Switch_n = GET_S_ABPREP_RiReHeading_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_jx) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMin_rad() - GET_P_DPRSIA_ReHeadAngThresHyst_rad();
        rtb_Div_io = GET_P_DPRSIA_ReHeadAngThresHyst_rad() + GET_P_DPRSIA_ReHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMin_rad();
        rtb_Div_io = GET_P_DPRSIA_ReHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight/Relational Operator1/Functionality'/LT'
         */
    rtb_GT_mh = (uint8)((rtb_Switch_n > rtb_Switch_ob) && (rtb_Switch_n < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND30/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND30/Functionality'/AND'
         */
    rtb_EQ_p = (uint8)((((sint32)rtb_EQ_p) != 0) && (((sint32)rtb_GT_mh) != 0));
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D(GETA_Y_DPRSIA_VXReCrvThresMax_1pm (), &x_dps);
    }
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_k;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_j4) != 0) {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Y_DPLSTM_VXCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D (GETA_Y_DPRSIA_VXReCrvThresHyst_1pm(), &x_dps);
        }
        rtb_Abs_g = rtb_ip_lookup_fxpt_sfun_7_n + rtb_ip_lookup_fxpt_sfun_7_k;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_RiReClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
         */
    if (((sint32)rtb_sfun_setbit_h) != 0) {
        rtb_Switch_ob = GET_S_ABPREP_RiReClthCrvSIF_1pm();
    } else {
        rtb_Switch_ob = GET_S_ABPREP_RiReClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch5/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight/Abs/Functionality'/Abs'
         */
    rtb_LT_hr = (uint8)(f32_abs_f32(rtb_Switch_ob) < rtb_Abs_g);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/NOT2/Functionality'/NOT'
         */
    rtb_Switch_kz = (uint8)(!(((sint32)rtb_Switch_kz) != 0));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND6/Functionality'/AND'
         */
    rtb_EQ_p = (uint8)(((((sint32)rtb_EQ_p) != 0) && (((sint32)rtb_LT_hr) != 0)) && (((sint32)rtb_Switch_kz) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_h4) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresHyst_rad() + GET_P_DPRSIA_ReHeadAngThresMax_rad();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_ReHeadAngThresMax_rad();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight/Abs/Functionality'/Abs'
         */
    rtb_LT_a = (uint8)(f32_abs_f32(rtb_Switch_n) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Constant2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Constant6'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiReInvalidQu_btf'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND31/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND7/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Relational Operator4/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/AND5/Functionality'/AND'
         */
    rtb_DataTypeConversion_ct = (uint8)((((((sint32)rtb_LT_a) != 0) && (((((sint32)GET_S_ABPREP_RiReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadCancelBitmask_btm())) == 0) || ((((sint32) GET_S_ABPREP_RiReInvalidQu_btf()) & ((sint32) GET_P_DPRSIA_RoadBridgedBitmask_btm())) != 0))) && (((sint32)rtb_LT_hr) != 0)) && (((sint32)rtb_Switch_kz) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Switch1/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        rtb_Switch_kz = rtb_EQ_p;
    } else {
        rtb_Switch_kz = rtb_DataTypeConversion_ct;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Switch1/Functionality'/Switch' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW'/Unit Delay2'
         */
    rtb_LogicalOperator_k = (uint8)((DW_dprsia_UnitDelay2_DSTATE_i <= 0.0F) && (((sint32)rtb_Switch_kz) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch9/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/AND/Functionality'/AND'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch10/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch11/Functionality'/Switch'
         */
    if ((((sint32)rtb_LogicalOperator_d) != 0) && (((sint32)rtb_LogicalOperator_k) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch48'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/from_data_definition1'/state_source'
                 */
        SET_S_DPRSIA_RdBndValidRDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE));
    } else if (((sint32)rtb_LogicalOperator_d) != 0) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch48'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/from_data_definition2'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch10/Functionality'/Switch'
                 */
        SET_S_DPRSIA_RdBndValidRDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY));
    } else if (((sint32)rtb_LogicalOperator_k) != 0) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch48'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch11/Functionality'/Switch'
                 */
        SET_S_DPRSIA_RdBndValidRDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY));
    } else {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch48'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch11/Functionality'/Switch'
                 */
        SET_S_DPRSIA_RdBndValidRDW_nu(((uint8) E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RdBndValidRDW/Switch9/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_ip) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_pt > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_pt -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/Application Parameter4'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_pt = GET_P_DPRSIA_LnBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_kz) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW'/Unit Delay2'
                 */
        if (DW_dprsia_UnitDelay2_DSTATE_i > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW'/Unit Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_UnitDelay2_DSTATE_i -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW'/Unit Delay2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/Application Parameter2'/Constant'
                 */
        DW_dprsia_UnitDelay2_DSTATE_i = GET_P_DPRSIA_RdBndTurnOnTime_sec();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/TURNONDELAYTIME/Functionality'/Switch2' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Relational Operator1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Constant2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Constant5'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND10/Functionality'/AND'
         */
    rtb_Switch_kz = (uint8)((((sint32)GET_P_DPRSIA_TriggerCondEnable_btm()) & 4) != 0);
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Relational Operator4/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Constant1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Constant6'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND11/Functionality'/AND'
         */
    rtb_NE_c = (uint8)((((sint32)GET_P_DPRSIA_TriggerCondEnable_btm()) & 1) != 0);
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Relational Operator2/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Constant4'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Constant8'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND13/Functionality'/AND'
         */
    rtb_Switch_ip = (uint8)((((sint32)GET_P_DPRSIA_TriggerCondEnable_btm()) & 8) != 0);
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Relational Operator5/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Constant3'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Constant7'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND12/Functionality'/AND'
         */
    rtb_NE_m = (uint8)((((sint32)GET_P_DPRSIA_TriggerCondEnable_btm()) & 2) != 0);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch2/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND15/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND6/Functionality'/AND'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch3/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch4/Functionality'/Switch'
         */
    if ((((((sint32)rtb_Switch_ip) != 0) && (((sint32)rtb_LogicalOperator_d) != 0)) && (((sint32)rtb_LogicalOperator_f) != 0)) && (((sint32) rtb_LogicalOperator_c) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch29'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition5'/state_source'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH));
    } else if (((((sint32)rtb_Switch_kz) != 0) && (((sint32)rtb_LogicalOperator_d) != 0)) && (((sint32)rtb_LogicalOperator_c) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch29'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch1/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS));
    } else if (((((sint32)rtb_NE_m) != 0) && (((sint32)rtb_LogicalOperator_d) != 0)) && (((sint32)rtb_LogicalOperator_f) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch29'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch3/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG));
    } else if ((((sint32)rtb_NE_c) != 0) && (((sint32)rtb_LogicalOperator_d) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch29'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition1'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch3/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch4/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY));
    } else {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch29'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition11'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch3/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch4/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonLeRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch6/Functionality'/Switch' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND14/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND7/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/AND9/Functionality'/AND'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch7/Functionality'/Switch'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch8/Functionality'/Switch'
         */
    if ((((((sint32)rtb_Switch_ip) != 0) && (((sint32)rtb_LogicalOperator_k) != 0)) && (((sint32)rtb_LogicalOperator_c) != 0)) && (((sint32) rtb_LogicalOperator_f) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch34'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition9'/state_source'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH));
    } else if (((((sint32)rtb_Switch_kz) != 0) && (((sint32)rtb_LogicalOperator_k) != 0)) && (((sint32)rtb_LogicalOperator_f) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch34'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition8'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch5/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS));
    } else if (((((sint32)rtb_NE_m) != 0) && (((sint32)rtb_LogicalOperator_k) != 0)) && (((sint32)rtb_LogicalOperator_c) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch34'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition7'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch7/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG));
    } else if ((((sint32)rtb_NE_c) != 0) && (((sint32)rtb_LogicalOperator_k) != 0)) {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch34'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition2'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch8/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY));
    } else {
        /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch34'/copy1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/from_data_definition6'/state_source'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch8/Functionality'/Switch'
                 */
        SET_S_DPRSIA_TriggerReasonRiRDW_nu(((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG));
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/CurrentSituation/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch9/Functionality'/Switch'
         */
    if (((sint32)rtb_sfun_setbit) != 0) {
        rtb_Switch_ky = GET_S_ABPLBP_RiLnClthPosY0SIF_met();
        rtb_Switch_ct = GET_S_ABPLBP_LeLnClthPosY0SIF_met();
    } else {
        rtb_Switch_ky = GET_S_ABPLBP_RiLnClthPosY0_met();
        rtb_Switch_ct = GET_S_ABPLBP_LeLnClthPosY0_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_ABPLBP_UncoupledLaneWidth_met'
         */
    if (((sint32)GET_P_DPRSIA_UncoupledLWEnable_bool()) != 0) {
        rtb_Switch_ffx[1] = GET_S_ABPLBP_UncoupledLaneWidth_met();
    } else {
        rtb_Switch_ffx[1] = GET_S_ABPLBP_CoupledLaneWidth_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/LaneBoundaryInterface/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch9/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPREP_LeReClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPREP_LeRePosY0_met'
         *  Inport: '<Root>/S_ABPREP_RiReClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPREP_RiRePosY0_met'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_sfun_setbit_h) != 0) {
        rtb_Switch_o = GET_S_ABPREP_LeReClthPosY0SIF_met();
        rtb_Switch_c = GET_S_ABPREP_RiReClthPosY0SIF_met();
    } else {
        rtb_Switch_o = GET_S_ABPREP_LeRePosY0_met();
        rtb_Switch_c = GET_S_ABPREP_RiRePosY0_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Switch9/Functionality'/Switch' */
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/RoadBoundaryInterface/Sum/Functionality'/Sum' */
    rtb_Switch_mhg = rtb_Switch_o - rtb_Switch_c;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1_l[0] = rtb_Switch_h5;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In4' */
    rtb_VectorConcatenate1_l[3] = rtb_DataTypeConversion_oo;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In5' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/Constant4'/Constant'
         */
    rtb_VectorConcatenate1_l[4] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In6' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/Constant4'/Constant'
         */
    rtb_VectorConcatenate1_l[5] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In7' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/Constant4'/Constant'
         */
    rtb_VectorConcatenate1_l[6] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector Concatenate1In8' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/Constant4'/Constant'
         */
    rtb_VectorConcatenate1_l[7] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_b[0] = rtb_LogicalOperator_e;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_b[3] = rtb_DataTypeConversion_j1;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn5' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate_b[4] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate_b[5] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate_b[6] = 0U;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/Constant2'/Constant'
         */
    rtb_VectorConcatenate_b[7] = 0U;
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Add2/Functionality'/Sum' */
    rtb_Abs_g = rtb_Switch_o - rtb_Switch_ky;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/P_LDPSA_VelXMax_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_m) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnRdWidthMin_met() - GET_P_DPRSIA_LnRdWidthHyst_met();
        rtb_Div_io = GET_P_DPRSIA_LnRdWidthHyst_met() + GET_P_DPRSIA_LnRdWidthMax_met();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnRdWidthMin_met();
        rtb_Div_io = GET_P_DPRSIA_LnRdWidthMax_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Relational Operator1/Functionality'/LT'
         */
    rtb_Switch_kz = (uint8)((rtb_Abs_g > rtb_Switch_ob) && (rtb_Abs_g < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Logical Operator2/Functionality'/AND'
         */
    rtb_sfun_setbit_h = (uint8)((((sint32)rtb_LogicalOperator_d) != 0) && (((sint32)rtb_LogicalOperator_c) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Constant2'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Logical Operator/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Logical Operator/Functionality'/NOT'
         */
    if (((sint32)rtb_sfun_setbit_h) != 0) {
        rtb_VectorConcatenate_b[2] = (uint8)(!(((sint32)rtb_Switch_kz) != 0));
    } else {
        rtb_VectorConcatenate_b[2] = 0U;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft/Switch2/Functionality'/Switch' */
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Add2/Functionality'/Sum' */
    rtb_Abs_g = rtb_Switch_ct - rtb_Switch_c;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/P_LDPSA_VelXMax_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_ic) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_LnRdWidthMin_met() - GET_P_DPRSIA_LnRdWidthHyst_met();
        rtb_Div_io = GET_P_DPRSIA_LnRdWidthHyst_met() + GET_P_DPRSIA_LnRdWidthMax_met();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_LnRdWidthMin_met();
        rtb_Div_io = GET_P_DPRSIA_LnRdWidthMax_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Relational Operator1/Functionality'/LT'
         */
    rtb_NE_c = (uint8)((rtb_Abs_g > rtb_Switch_ob) && (rtb_Abs_g < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Logical Operator2/Functionality'/AND'
         */
    rtb_sfun_setbit_h = (uint8)((((sint32)rtb_LogicalOperator_k) != 0) && (((sint32)rtb_LogicalOperator_f) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Constant2'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Logical Operator/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Logical Operator/Functionality'/NOT'
         */
    if (((sint32)rtb_sfun_setbit_h) != 0) {
        rtb_VectorConcatenate1_l[2] = (uint8)(!(((sint32)rtb_NE_c) != 0));
    } else {
        rtb_VectorConcatenate1_l[2] = 0U;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Product1/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator_d) != 0) {
        rtb_Div = GET_S_LCFRCV_VehVelX_mps() * rtb_Switch_hi;
    } else {
        rtb_Div = 0.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_fm) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMin_mps() - GET_P_DPRSIA_VelLatThresHyst_mps();
        rtb_Div_io = GET_P_DPRSIA_VelLatThresHyst_mps() + GET_P_DPRSIA_VelLatThresMax_mps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMin_mps();
        rtb_Div_io = GET_P_DPRSIA_VelLatThresMax_mps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Relational Operator1/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_NE_m = (uint8)(((-rtb_Div) > rtb_Switch_ob) && ((-rtb_Div) < rtb_Div_io));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/P_LDPSA_VelXMin_mps5'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft'/Unit Delay1'
         */
    if (((sint32)DW_dprsia_UnitDelay1_DSTATE_h) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresHyst_mps() + GET_P_DPRSIA_VelLatThresMax_mps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMax_mps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Abs/Functionality'/Abs'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Neg/Functionality'/Unary Minus'
         */
    rtb_Switch_ip = (uint8)(f32_abs_f32(-rtb_Div) < rtb_Switch_ob);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Switch4/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        rtb_sfun_setbit_h = rtb_NE_m;
    } else {
        rtb_sfun_setbit_h = rtb_Switch_ip;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_b[1] = (uint8)(!(((sint32)rtb_sfun_setbit_h) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Product3/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator_k) != 0) {
        rtb_Switch_jo = GET_S_LCFRCV_VehVelX_mps() * rtb_Switch_n;
    } else {
        rtb_Switch_jo = 0.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps3'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Add/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Add1/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_k0) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMin_mps() - GET_P_DPRSIA_VelLatThresHyst_mps();
        rtb_Div_io = GET_P_DPRSIA_VelLatThresHyst_mps() + GET_P_DPRSIA_VelLatThresMax_mps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMin_mps();
        rtb_Div_io = GET_P_DPRSIA_VelLatThresMax_mps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Relational Operator1/Functionality'/LT'
         */
    rtb_DataTypeConversion_kq = (uint8)((rtb_Switch_jo > rtb_Switch_ob) && (rtb_Switch_jo < rtb_Div_io));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/P_LDPSA_VelXMin_mps5'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight'/Unit Delay1'
         */
    if (((sint32)DW_dprsia_UnitDelay1_DSTATE_d) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresHyst_mps() + GET_P_DPRSIA_VelLatThresMax_mps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelLatThresMax_mps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Relational Operator2/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Abs/Functionality'/Abs'
         */
    rtb_LT_k4 = (uint8)(f32_abs_f32(rtb_Switch_jo) < rtb_Switch_ob);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Switch2/Functionality'/Switch' */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        rtb_sfun_setbit_hp = rtb_DataTypeConversion_kq;
    } else {
        rtb_sfun_setbit_hp = rtb_LT_k4;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate1_l[1] = (uint8)(!(((sint32)rtb_sfun_setbit_hp) != 0));
    /* S-Function (sfun_setbit): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_h = temp;
    }
    /* S-Function (sfun_setbit): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate1_l[0];
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
    /* Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/Divide/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/Constant'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/P_VEH_Width_met'/Constant'
         */
    rtb_Div_io = GET_P_VEH_Width_met() / 2.0F;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Constant6'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Add/Functionality'/Sum'
         */
    if (((sint32)rtb_LogicalOperator_f) != 0) {
        rtb_Switch_ct -= rtb_Div_io;
    } else {
        rtb_Switch_ct = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/AND7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Constant15'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/P_VEH_Width_met3'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/AND7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/LT2/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Neg2/Functionality'/Unary Minus'
         */
    rtb_sfun_setbit_hp = (uint8)(((rtb_Switch_ct > 0.0F) && (((sint32) rtb_LogicalOperator_f) != 0)) && (rtb_Switch_buc < (-GET_P_DPRSIA_TlcHeadAngThres_rad())));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Product/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator_f) != 0) {
        rtb_Switch_buc *= GET_S_LCFRCV_VehVelX_mps();
    } else {
        rtb_Switch_buc = 0.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Constant7'/Constant'
         */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Abs/Functionality'/Abs' */
        rtb_Abs_g = f32_abs_f32(rtb_Switch_buc);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Divide1/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Divide1/In3'/Constant'
                 *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Divide1/Functionality/DivDefault'/Div'
                 */
        if (rtb_Abs_g != 0.0F) {
            rtb_Abs_g = rtb_Switch_ct / rtb_Abs_g;
        } else {
            rtb_Abs_g = 10000.0F;
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Divide1/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Abs_g = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch41'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Constant7'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcLe/Min1/Functionality'/Min'
         */
    SET_S_DPRSIA_TlcLeRDW_sec(f32_min_f32_f32(rtb_Abs_g, 10.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Switch5/Functionality'/Switch' incorporates:
                                                                    *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Constant9'/Constant'
                                                                    *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Add1/Functionality'/Sum'
                                                                    */
    if (((sint32)rtb_LogicalOperator_c) != 0) {
        rtb_Switch_ky += rtb_Div_io;
    } else {
        rtb_Switch_ky = -10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Switch5/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/AND8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Constant17'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/P_VEH_Width_met4'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/AND8/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/GT3/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/LT3/Functionality'/LT'
         */
    rtb_sfun_setbit_hp = (uint8)(((rtb_Switch_ky < 0.0F) && (((sint32) rtb_LogicalOperator_c) != 0)) && (rtb_Switch_pi > GET_P_DPRSIA_TlcHeadAngThres_rad()));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Product2/Functionality'/Mul'
         */
    if (((sint32)rtb_LogicalOperator_c) != 0) {
        rtb_Switch_pi *= GET_S_LCFRCV_VehVelX_mps();
    } else {
        rtb_Switch_pi = 0.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Constant10'/Constant'
         */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Abs2/Functionality'/Abs' */
        rtb_Abs_g = f32_abs_f32(rtb_Switch_pi);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Divide2/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Divide2/In3'/Constant'
                 *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Divide2/Functionality/DivDefault'/Div'
                 *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Neg3/Functionality'/Unary Minus'
                 */
        if (rtb_Abs_g != 0.0F) {
            rtb_Abs_g = (-rtb_Switch_ky) / rtb_Abs_g;
        } else {
            rtb_Abs_g = 10000.0F;
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Divide2/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Abs_g = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Switch6/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch42'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Constant10'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DlcTlcRi/Min3/Functionality'/Min'
         */
    SET_S_DPRSIA_TlcRiRDW_sec(f32_min_f32_f32(rtb_Abs_g, 10.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Switch1/Functionality'/Switch' incorporates:
                                                                    *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Constant3'/Constant'
                                                                    *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Add2/Functionality'/Sum'
                                                                    */
    if (((sint32)rtb_LogicalOperator_d) != 0) {
        rtb_Switch_o -= rtb_Div_io;
    } else {
        rtb_Switch_o = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Constant12'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/P_VEH_Width_met2'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/AND5/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/LT/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Neg/Functionality'/Unary Minus'
         */
    rtb_sfun_setbit_hp = (uint8)(((rtb_Switch_o > 0.0F) && (((sint32) rtb_LogicalOperator_d) != 0)) && (rtb_Switch_hi < (-GET_P_DPRSIA_TrcHeadAngThres_rad())));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Constant11'/Constant'
         */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Abs1/Functionality'/Abs' */
        rtb_Switch_hi = f32_abs_f32(rtb_Div);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Divide3/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Divide3/In3'/Constant'
                 *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Divide3/Functionality/DivDefault'/Div'
                 */
        if (rtb_Switch_hi != 0.0F) {
            rtb_Switch_hi = rtb_Switch_o / rtb_Switch_hi;
        } else {
            rtb_Switch_hi = 10000.0F;
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Divide3/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_hi = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Switch7/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch40'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Constant11'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcLe/Min/Functionality'/Min'
         */
    SET_S_DPRSIA_TrcLeRDW_sec(f32_min_f32_f32(rtb_Switch_hi, 10.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Switch4/Functionality'/Switch' incorporates:
                                                                        *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Constant8'/Constant'
                                                                        *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Add3/Functionality'/Sum'
                                                                        */
    if (((sint32)rtb_LogicalOperator_k) != 0) {
        rtb_Switch_c += rtb_Div_io;
    } else {
        rtb_Switch_c = -10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Constant14'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/P_VEH_Width_met1'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/AND6/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/LT1/Functionality'/LT'
         */
    rtb_sfun_setbit_hp = (uint8)(((rtb_Switch_c < 0.0F) && (((sint32) rtb_LogicalOperator_k) != 0)) && (rtb_Switch_n > GET_P_DPRSIA_TrcHeadAngThres_rad()));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Constant13'/Constant'
         */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Abs3/Functionality'/Abs' */
        rtb_Switch_n = f32_abs_f32(rtb_Switch_jo);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Divide4/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Divide4/In3'/Constant'
                 *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Divide4/Functionality/DivDefault'/Div'
                 *  UnaryMinus: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Neg1/Functionality'/Unary Minus'
                 */
        if (rtb_Switch_n != 0.0F) {
            rtb_Switch_n = (-rtb_Switch_c) / rtb_Switch_n;
        } else {
            rtb_Switch_n = 10000.0F;
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Divide4/Functionality/DivDefault'/Switch' */
    } else {
        rtb_Switch_n = 10.0F;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Switch8/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch45'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Constant13'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/VariableCalculation/DrcTrcRi/Min2/Functionality'/Min'
         */
    SET_S_DPRSIA_TrcRiRDW_sec(f32_min_f32_f32(rtb_Switch_n, 10.0F));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Switch3/Functionality'/Switch' incorporates:
                                                                       *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/P_LDPSA_VelXHyst_mps'/Constant'
                                                                       *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/P_LDPSA_VelXHyst_mps1'/Constant'
                                                                       *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/P_LDPSA_VelXMax_mps'/Constant'
                                                                       *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/P_LDPSA_VelXMin_mps'/Constant'
                                                                       *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Add/Functionality'/Sum'
                                                                       *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Add1/Functionality'/Sum'
                                                                       *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Switch1/Functionality'/Switch'
                                                                       *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp'/Unit Delay2'
                                                                       */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_f2) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_VelVehDispMin_kph() - GET_P_DPRSIA_VelVehDispHyst_kph();
        rtb_Div_io = GET_P_DPRSIA_VelVehDispHyst_kph() + GET_P_DPRSIA_VelVehDispMax_kph();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_VelVehDispMin_kph();
        rtb_Div_io = GET_P_DPRSIA_VelVehDispMax_kph();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Relational Operator1/Functionality'/LT'
         */
    rtb_LogicalOperator_f = (uint8)((GET_S_LCFRCV_VDy_VehVelocity_kph() > rtb_Switch_ob) && (GET_S_LCFRCV_VDy_VehVelocity_kph() < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp/Logical Operator/Functionality'/NOT'
         */
    rtb_sfun_setbit_hp = (uint8)(!(((sint32)rtb_LogicalOperator_f) != 0));
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1_n[0] = rtb_sfun_setbit_hp;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/P_LDPSA_VelXMax_mps'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_nc) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_StrWhlAngleHyst_deg() + GET_P_DPRSIA_StrWhlAngleMax_deg();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_StrWhlAngleMax_deg();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngle_deg'
         */
    rtb_LogicalOperator_d = (uint8)(f32_abs_f32(GET_S_LCFRCV_SteerWAngle_deg()) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle/Logical Operator/Functionality'/NOT'
         */
    rtb_Switch_h5 = (uint8)(!(((sint32)rtb_LogicalOperator_d) != 0));
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate1_n[1] = rtb_Switch_h5;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/P_LDPSA_VelXMax_mps'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/Add1/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed'/Unit Delay2'
         */
    if (((sint32)DW_dprsia_UnitDelay2_DSTATE_nk) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_StrWhlAngSpeedHyst_degps() + GET_P_DPRSIA_StrWhlAngSpeedMax_degps();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_StrWhlAngSpeedMax_degps();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/Relational Operator1/Functionality'/LT' incorporates:
         *  Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_SteerWAngleRate_degps'
         */
    rtb_LogicalOperator_c = (uint8)(f32_abs_f32 (GET_S_LCFRCV_SteerWAngleRate_degps()) < rtb_Switch_ob);
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed/Logical Operator/Functionality'/NOT'
         */
    rtb_DataTypeConversion_oo = (uint8)(!(((sint32)rtb_LogicalOperator_c) != 0));
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector Concatenate1In3' */
    rtb_VectorConcatenate1_n[2] = rtb_DataTypeConversion_oo;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/C_LCF_AclXHyst_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/C_LCF_AclXMax_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity'/Unit Delay1'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > (GET_P_DPRSIA_AclXMax_mps2() + GET_P_DPRSIA_AclXHyst_mps2())) {
        rtb_LogicalOperator_k = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < GET_P_DPRSIA_AclXMax_mps2()) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_LogicalOperator_k = 0U;
    } else {
        rtb_LogicalOperator_k = DW_dprsia_UnitDelay1_DSTATE_ds;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/C_LCF_AclXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/C_LCF_AclXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/Add4/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity'/Unit Delay3'
         */
    if (GET_S_LCFRCV_VehAclX_mps2() > GET_P_DPRSIA_AclXMin_mps2()) {
        rtb_Switch3_f = 1U;
    } else if (GET_S_LCFRCV_VehAclX_mps2() < (GET_P_DPRSIA_AclXMin_mps2() - GET_P_DPRSIA_AclXHyst_mps2())) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3_f = 0U;
    } else {
        rtb_Switch3_f = DW_dprsia_UnitDelay3_DSTATE_d;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/HYSTERESIS2/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/NOT1/Functionality'/NOT'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_j1 = (uint8)(!((!(((sint32)rtb_LogicalOperator_k) != 0)) && (((sint32)rtb_Switch3_f) != 0)));
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector Concatenate1In5' */
    rtb_VectorConcatenate1_n[4] = rtb_DataTypeConversion_j1;
    /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehAclY_mps2'
         */
    rtb_Switch_n = f32_abs_f32(GET_S_LCFRCV_VehAclY_mps2());
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/C_LCF_AclYHyst_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/C_LCF_AclYMax_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Relational Operator1'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity'/Unit Delay1'
         */
    if (rtb_Switch_n > (GET_P_DPRSIA_AclYMax_mps2() + GET_P_DPRSIA_AclYHyst_mps2())) {
        rtb_LogicalOperator_e = 1U;
    } else if (rtb_Switch_n < GET_P_DPRSIA_AclYMax_mps2()) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_LogicalOperator_e = 0U;
    } else {
        rtb_LogicalOperator_e = DW_dprsia_UnitDelay1_DSTATE_k;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Switch3' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Signal Conversion' */
    rtb_SignalConversion = rtb_LogicalOperator_e;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector Concatenate1In6' incorporates:
         *  SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity/HYSTERESIS3/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1_n[5] = rtb_LogicalOperator_e;
    /* Abs: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         */
    rtb_Abs_d = f32_abs_f32(GET_S_LCFRCV_VehCrv_1pm());
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_bu = F32_PTR_IP1D (GETA_Y_DPRSIA_VXVehCrvThresMax_1pm(), &x_dps);
    }
    /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelX_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_DPRSIA_VXVehCrvThresHyst_1pm(), &x_dps);
    }
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality/odtc'/Product'
         *  Product: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality/odtc'/Product'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Relational Operator1'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPLSIA_VXCrvThresMax_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPLSIA_VXVehCrvThresHyst_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature'/Unit Delay1'
         */
    if (rtb_Abs_d > (rtb_ip_lookup_fxpt_sfun_7_bu + rtb_ip_lookup_fxpt_sfun_7_g)) {
        rtb_Switch3_l = 1U;
    } else if (rtb_Abs_d < rtb_ip_lookup_fxpt_sfun_7_bu) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Constant'
                 */
        rtb_Switch3_l = 0U;
    } else {
        rtb_Switch3_l = DW_dprsia_UnitDelay1_DSTATE_i;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/HYSTERESIS3/Functionality'/Switch3' */
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature'/Unit_Delay1'
         */
    rtb_LogicalOperator_e = (uint8)((DW_dprsia_Unit_Delay1_DSTATE <= 0.0F) && (((sint32)rtb_Switch3_l) != 0));
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector Concatenate1In7' */
    rtb_VectorConcatenate1_n[6] = rtb_LogicalOperator_e;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_n[0] = rtb_sfun_setbit_hp;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_n[1] = rtb_Switch_h5;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_n[2] = rtb_DataTypeConversion_oo;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_n[4] = rtb_DataTypeConversion_j1;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_n[5] = rtb_SignalConversion;
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_n[6] = rtb_LogicalOperator_e;
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Switch2' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPRSIA_CrvVehCrvTurnOn_sec/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    if (((sint32)rtb_Switch3_l) != 0) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature'/Unit_Delay1'
                 */
        if (DW_dprsia_Unit_Delay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature'/Unit_Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsia_Unit_Delay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* S-Function Block sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPRSIA_CrvVehCrvTurnOn_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_d, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_mk = F32_PTR_IP1D (GETA_Y_DPRSIA_CrvVehCrvTurnOn_sec(), &x_dps);
        }
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature'/Unit_Delay1' incorporates:
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/Y_DPRSIA_CrvVehCrvTurnOn_sec/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        DW_dprsia_Unit_Delay1_DSTATE = rtb_ip_lookup_fxpt_sfun_7_mk;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Add/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXHyst_mps'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXMin_mps'/Constant'
         */
    rtb_Switch_n = GET_P_DPRSIA_LaneWidthMin_met() - GET_P_DPRSIA_LaneWidthHyst_met();
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Add1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXMax_mps'/Constant'
         */
    rtb_Div_io = GET_P_DPRSIA_LaneWidthHyst_met() + GET_P_DPRSIA_LaneWidthMax_met();
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         */
    rtb_Switch_hh[0] = GET_S_ABPLBP_LaneWidth_met();
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator6/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXHyst_mps5'/Constant'
         */
    tmp = (uint8)(((sint32)GET_P_DPRSIA_LaneWidthWideLn_bool()) != 0);
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator2/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXMin_mps2'/Constant'
         */
    tmp_0 = (uint8)(((sint32)GET_P_DPRSIA_LaneWidthSwitch_bool()) != 0);
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXMax_mps'/Constant'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Unit Delay2'
                 */
        if (((sint32)DW_dprsia_UnitDelay2_DSTATE_khn[i]) != 0) {
            rtb_Switch_ob = rtb_Div_io;
        } else {
            rtb_Switch_ob = GET_P_DPRSIA_LaneWidthMax_met();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch1/Functionality'/Switch' */
        /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Relational Operator1/Functionality'/LT' */
        rtb_DataTypeConversion_j1 = (uint8)(rtb_Switch_hh[i] < rtb_Switch_ob);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXMin_mps'/Constant'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Unit Delay2'
                 */
        if (((sint32)DW_dprsia_UnitDelay2_DSTATE_khn[i]) != 0) {
            rtb_Switch_ob = rtb_Switch_n;
        } else {
            rtb_Switch_ob = GET_P_DPRSIA_LaneWidthMin_met();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch3/Functionality'/Switch' */
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator1/Functionality'/AND'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Relational Operator/Functionality'/GT'
                 */
        rtb_DataTypeConversion_kt2[i] = (sint8)((rtb_Switch_hh[i] > rtb_Switch_ob) && (((sint32)rtb_DataTypeConversion_j1) != 0));
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator7/Functionality'/NOT'
                 */
        rtb_DataTypeConversion_j1 = (uint8)(!(((sint32)rtb_DataTypeConversion_j1) != 0));
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator6/Functionality'/AND'
                 */
        rtb_DataTypeConversion_j1 = (uint8)(((sint32)tmp) && (((sint32) rtb_DataTypeConversion_j1) != 0));
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator8/Functionality'/NOT'
                 */
        rtb_DataTypeConversion_j1 = (uint8)(!(((sint32)rtb_DataTypeConversion_j1) != 0));
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator2/Functionality'/AND'
                 */
        rtb_DataTypeConversion_j1 = (uint8)((((((sint32)rtb_DataTypeConversion_j1) != 0) && (((sint32)rtb_DataTypeConversion_ae) != 0)) && (((sint32) rtb_DataTypeConversion_cr) != 0)) && ((sint32)tmp_0));
        /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Relational Operator1/Functionality'/LT' */
        rtb_DataTypeConversion_dp[i] = (sint8)rtb_DataTypeConversion_j1;
    }
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXHyst_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXHyst_mps3'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXMax_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXMin_mps1'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Add2/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Unit Delay1'
         */
    if (((sint32)DW_dprsia_UnitDelay1_DSTATE_o) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_RoadWidthMin_met() - GET_P_DPRSIA_RoadWidthHyst_met();
        rtb_Div_io = GET_P_DPRSIA_RoadWidthHyst_met() + GET_P_DPRSIA_RoadWidthMax_met();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_RoadWidthMin_met();
        rtb_Div_io = GET_P_DPRSIA_RoadWidthMax_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch6/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator4/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Relational Operator2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Relational Operator3/Functionality'/LT'
         */
    rtb_LogicalOperator_e = (uint8)((rtb_Sum_mg > rtb_Switch_ob) && (rtb_Sum_mg < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXMin_mps3'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator5/Functionality'/AND'
         */
    rtb_sfun_setbit_hp = (uint8)(((((sint32)rtb_DataTypeConversion_kz) != 0) && (((sint32)rtb_DataTypeConversion_f5o) != 0)) && (((sint32) GET_P_DPRSIA_RoadWidthSwitch_bool()) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Constant2'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator/Functionality'/NOT'
         */
    for (i = 0; i < 2; i++) {
        if (((sint32)rtb_DataTypeConversion_dp[i]) != 0) {
            rtb_Switch_pv[i] = (sint8)(!(((sint32)rtb_DataTypeConversion_kt2[i]) != 0));
        } else {
            rtb_Switch_pv[i] = 0;
        }
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Constant1'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator3/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Logical Operator3/Functionality'/NOT'
         */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        rtb_sfun_setbit_hp = (uint8)(!(((sint32)rtb_LogicalOperator_e) != 0));
    } else {
        rtb_sfun_setbit_hp = 0U;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Constant5'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Constant6'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXHyst_mps6'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/OR1/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/OR1/Functionality'/OR'
         *  Selector: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Selector2'
         *  Selector: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Selector3'
         */
    if (((sint32)GET_P_DPRSIA_LaneWidthSIFOn_bool()) != 0) {
        tmp_1 = (uint8)((((sint32)rtb_Switch_pv[1]) != 0) || (((sint32) rtb_Switch_pv[0]) != 0));
    } else {
        tmp_1 = (uint8)rtb_Switch_pv[0];
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch8/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate_n[3] = (uint8)((((sint32)tmp_1) != 0) || (((sint32) rtb_sfun_setbit_hp) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/P_LDPSA_VelXHyst_mps4'/Constant'
         */
    for (i = 0; i < 2; i++) {
        rtb_Switch_ob = rtb_Switch_hh[i];
        if (((sint32)rtb_DataTypeConversion_dp[i]) == 0) {
            rtb_Switch_ob = GET_P_DPRSIA_LaneWidthWideLnDef_met();
        }
        rtb_Switch_hh[i] = rtb_Switch_ob;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Switch7/Functionality'/Switch' */
    /* Selector: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Selector1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Constant4'/Constant'
         */
    rtb_sfun_setbit_hp = (uint8)rtb_DataTypeConversion_dp[0];
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/branch1'/copy1' */
    SET_S_DPRSIA_TgtCntrLnEnable_bool(rtb_sfun_setbit_hp);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/branch2'/copy1' incorporates:
                                                             *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP/Constant3'/Constant'
                                                             *  Selector: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Selector'
                                                             */
    SET_S_DPRSIA_LaneWidthRDP_met(rtb_Switch_hh[0]);
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Add/Functionality'/Sum' incorporates:
                                                       *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXHyst_mps'/Constant'
                                                       *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXMin_mps'/Constant'
                                                       */
    rtb_Sum_mg = GET_P_DPRSIA_LaneWidthMin_met() - GET_P_DPRSIA_LaneWidthHyst_met();
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Add1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXHyst_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXMax_mps'/Constant'
         */
    rtb_Switch_n = GET_P_DPRSIA_LaneWidthHyst_met() + GET_P_DPRSIA_LaneWidthMax_met();
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         */
    rtb_Switch_ffx[0] = GET_S_ABPLBP_LaneWidth_met();
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator6/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXHyst_mps5'/Constant'
         */
    tmp = (uint8)(((sint32)GET_P_DPRSIA_LaneWidthWideLn_bool()) != 0);
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator2/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXMin_mps2'/Constant'
         */
    tmp_0 = (uint8)(((sint32)GET_P_DPRSIA_LaneWidthSwitch_bool()) != 0);
    for (i = 0; i < 2; i++) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXMax_mps'/Constant'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/Unit Delay2'
                 */
        if (((sint32)DW_dprsia_UnitDelay2_DSTATE_jm[i]) != 0) {
            rtb_Switch_ob = rtb_Switch_n;
        } else {
            rtb_Switch_ob = GET_P_DPRSIA_LaneWidthMax_met();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch1/Functionality'/Switch' */
        /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Relational Operator1/Functionality'/LT' */
        rtb_DataTypeConversion_j1 = (uint8)(rtb_Switch_ffx[i] < rtb_Switch_ob);
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXMin_mps'/Constant'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/Unit Delay2'
                 */
        if (((sint32)DW_dprsia_UnitDelay2_DSTATE_jm[i]) != 0) {
            rtb_Switch_ob = rtb_Sum_mg;
        } else {
            rtb_Switch_ob = GET_P_DPRSIA_LaneWidthMin_met();
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch3/Functionality'/Switch' */
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator1/Functionality'/AND'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Relational Operator/Functionality'/GT'
                 */
        rtb_Switch_pv[i] = (sint8)((rtb_Switch_ffx[i] > rtb_Switch_ob) && (((sint32) rtb_DataTypeConversion_j1) != 0));
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator7/Functionality'/NOT'
                 */
        rtb_DataTypeConversion_j1 = (uint8)(!(((sint32)rtb_DataTypeConversion_j1) != 0));
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator6/Functionality'/AND'
                 */
        rtb_DataTypeConversion_j1 = (uint8)(((sint32)tmp) && (((sint32) rtb_DataTypeConversion_j1) != 0));
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator8/Functionality'/NOT'
                 */
        rtb_DataTypeConversion_j1 = (uint8)(!(((sint32)rtb_DataTypeConversion_j1) != 0));
        /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator2/Functionality'/AND'
                 */
        rtb_DataTypeConversion_j1 = (uint8)((((((sint32)rtb_DataTypeConversion_j1) != 0) && (((sint32)rtb_DataTypeConversion_o3r) != 0)) && (((sint32) rtb_DataTypeConversion_ke) != 0)) && ((sint32)tmp_0));
        /* RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Relational Operator1/Functionality'/LT' */
        rtb_DataTypeConversion_dp[i] = (sint8)rtb_DataTypeConversion_j1;
    }
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXHyst_mps2'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXHyst_mps3'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXMax_mps1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXMin_mps1'/Constant'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Add2/Functionality'/Sum'
         *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Add3/Functionality'/Sum'
         *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/Unit Delay1'
         */
    if (((sint32)DW_dprsia_UnitDelay1_DSTATE_mz) != 0) {
        rtb_Switch_ob = GET_P_DPRSIA_RoadWidthMin_met() - GET_P_DPRSIA_RoadWidthHyst_met();
        rtb_Div_io = GET_P_DPRSIA_RoadWidthHyst_met() + GET_P_DPRSIA_RoadWidthMax_met();
    } else {
        rtb_Switch_ob = GET_P_DPRSIA_RoadWidthMin_met();
        rtb_Div_io = GET_P_DPRSIA_RoadWidthMax_met();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch6/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator4/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Relational Operator2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Relational Operator3/Functionality'/LT'
         */
    rtb_DataTypeConversion_j1 = (uint8)((rtb_Switch_mhg > rtb_Switch_ob) && (rtb_Switch_mhg < rtb_Div_io));
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXMin_mps3'/Constant'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator5/Functionality'/AND'
         */
    rtb_sfun_setbit_hp = (uint8)(((((sint32)rtb_DataTypeConversion_ct) != 0) && (((sint32)rtb_DataTypeConversion_da) != 0)) && (((sint32) GET_P_DPRSIA_RoadWidthSwitch_bool()) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Constant2'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator/Functionality'/NOT'
         */
    for (i = 0; i < 2; i++) {
        if (((sint32)rtb_DataTypeConversion_dp[i]) != 0) {
            rtb_Switch_nu[i] = (sint8)(!(((sint32)rtb_Switch_pv[i]) != 0));
        } else {
            rtb_Switch_nu[i] = 0;
        }
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Constant1'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator3/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Logical Operator3/Functionality'/NOT'
         */
    if (((sint32)rtb_sfun_setbit_hp) != 0) {
        rtb_sfun_setbit_hp = (uint8)(!(((sint32)rtb_DataTypeConversion_j1) != 0));
    } else {
        rtb_sfun_setbit_hp = 0U;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Constant5'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Constant6'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXHyst_mps6'/Constant'
         *  DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/OR1/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/OR1/Functionality'/OR'
         *  Selector: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/Selector2'
         *  Selector: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/Selector3'
         */
    if (((sint32)GET_P_DPRSIA_LaneWidthSIFOn_bool()) != 0) {
        tmp_1 = (uint8)((((sint32)rtb_Switch_nu[1]) != 0) || (((sint32) rtb_Switch_nu[0]) != 0));
    } else {
        tmp_1 = (uint8)rtb_Switch_nu[0];
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch8/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate1_n[3] = (uint8)((((sint32)tmp_1) != 0) || (((sint32) rtb_sfun_setbit_hp) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/P_LDPSA_VelXHyst_mps4'/Constant'
         */
    for (i = 0; i < 2; i++) {
        rtb_Switch_mhg = rtb_Switch_ffx[i];
        if (((sint32)rtb_DataTypeConversion_dp[i]) == 0) {
            rtb_Switch_mhg = GET_P_DPRSIA_LaneWidthWideLnDef_met();
        }
        rtb_Switch_ffx[i] = rtb_Switch_mhg;
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Switch7/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/branch2'/copy1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW/Constant3'/Constant'
         *  Selector: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/Selector'
         */
    SET_S_DPRSIA_LaneWidthRDW_met(rtb_Switch_ffx[0]);
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDPSwitch/Switch/Functionality'/Switch' incorporates:
                                                        *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDPSwitch/Application Parameter1'/Constant'
                                                        *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDPSwitch/Application Parameter2'/Constant'
                                                        *  Inport: '<Root>/S_LCFRCV_RDPSwitch_bool'
                                                        */
    if (((sint32)GET_P_DPRSMI_RDPSwitchEnable_bool()) != 0) {
        rtb_sfun_setbit_hp = GET_S_LCFRCV_RDPSwitch_bool();
    } else {
        rtb_sfun_setbit_hp = GET_P_DPRSMI_RDPSwitch_bool();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDPSwitch/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDPSwitch/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDPSwitch/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[7] = (uint8)(!(((sint32)rtb_sfun_setbit_hp) != 0));
    /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDWSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDWSwitch/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDWSwitch/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDWSwitch_bool'
         */
    if (((sint32)GET_P_DPRSMW_RDWSwitchEnable_bool()) != 0) {
        rtb_sfun_setbit_hp = GET_S_LCFRCV_RDWSwitch_bool();
    } else {
        rtb_sfun_setbit_hp = GET_P_DPRSMW_RDWSwitch_bool();
    }
    /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDWSwitch/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDWSwitch/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/RDWSwitch/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate1_n[7] = (uint8)(!(((sint32)rtb_sfun_setbit_hp) != 0));
    /* Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/Unit_Delay1'
         */
    for (i = 0; i < 8; i++) {
        rtb_LogicalOperator_gq[i] = (uint8)((((sint32)rtb_VectorConcatenate_n[i]) != 0) || (DW_dprsia_Unit_Delay1_DSTATE_d[i] > 0.0F));
    }
    /* End of Logic: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Logical Operator' */
    /* S-Function (sfun_setbit): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_LogicalOperator_gq[0];
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
        rtb_sfun_setbit_hp = temp;
    }
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/set_bit/Functionality'/DTC_out' */
    SET_S_DPRSIA_SpecificRDP_btf(rtb_sfun_setbit_hp);
    /* S-Function (sfun_setbit): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate1_n[0];
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
        rtb_sfun_setbit_hp = temp;
    }
    /* DataTypeConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/set_bit1/Functionality'/DTC_out' */
    SET_S_DPRSIA_SpecificRDW_btf(rtb_sfun_setbit_hp);
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Add1/Functionality'/Sum' incorporates:
                                                        *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                                        */
    rtb_Switch_gv -= GET_S_LCFRCV_SysCycleTimeSen_sec();
    /* Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Add1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Switch_a -= GET_S_LCFRCV_SysCycleTimeSen_sec();
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch10'/copy1' */
    SET_D_DPRSIA_RdBndRiCancelValidRDP_bool(rtb_DataTypeConversion_kz);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch12'/copy1' */
    SET_S_DPRSIA_DlcRiRDP_met(rtb_Switch_l);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch13'/copy1' */
    SET_S_DPRSIA_SideCondRDPLe_btf(rtb_sfun_setbit_j);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch14'/copy1' */
    SET_S_DPRSIA_SideCondRDPRi_btf(rtb_sfun_setbit_a);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch15'/copy1' */
    SET_S_DPRSIA_VelLatReLeRDP_mps(rtb_Switch_c3);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch17'/copy1' */
    SET_S_DPRSIA_VelLatReRiRDP_mps(rtb_Switch_p);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch18'/copy1' */
    SET_S_DPRSIA_VelLatLnLeRDP_mps(rtb_Switch_k0);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch19'/copy1' */
    SET_S_DPRSIA_VelLatLnRiRDP_mps(rtb_Switch);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch2'/copy1' */
    SET_D_DPRSIA_LnBndLeTrgValidRDP_bool(rtb_EQ);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch20'/copy1' */
    SET_S_DPRSIA_DlcLeRDP_met(rtb_Switch_fr);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch24'/copy1' */
    SET_S_DPRSIA_DrcLeRDP_met(rtb_Switch_d);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch25'/copy1' */
    SET_S_DPRSIA_DrcRiRDP_met(rtb_Switch_jd);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch28'/copy1' */
    SET_D_DPRSIA_RdBndRiCancelValidRDW_bool(rtb_DataTypeConversion_ct);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch3'/copy1' */
    SET_D_DPRSIA_LnBndRiTrgValidRDP_bool(rtb_EQ_d3);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch30'/copy1' */
    SET_S_DPRSIA_DlcRiRDW_met(rtb_Switch_ky);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch31'/copy1' */
    SET_S_DPRSIA_SideCondRDWLe_btf(rtb_sfun_setbit_h);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch32'/copy1' */
    SET_S_DPRSIA_SideCondRDWRi_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch33'/copy1' */
    SET_S_DPRSIA_VelLatReLeRDW_mps(rtb_Div);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch35'/copy1' */
    SET_S_DPRSIA_VelLatReRiRDW_mps(rtb_Switch_jo);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch36'/copy1' */
    SET_S_DPRSIA_VelLatLnLeRDW_mps(rtb_Switch_buc);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch37'/copy1' */
    SET_S_DPRSIA_VelLatLnRiRDW_mps(rtb_Switch_pi);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch38'/copy1' */
    SET_D_DPRSIA_LnBndLeTrgValidRDW_bool(rtb_LogicalOperator);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch39'/copy1' */
    SET_S_DPRSIA_DlcLeRDW_met(rtb_Switch_ct);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch4'/copy1' */
    SET_D_DPRSIA_LnBndLeCancelValidRDP_bool(rtb_DataTypeConversion_cr);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch43'/copy1' */
    SET_S_DPRSIA_DrcLeRDW_met(rtb_Switch_o);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch44'/copy1' */
    SET_S_DPRSIA_DrcRiRDW_met(rtb_Switch_c);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch46'/copy1' */
    SET_D_DPRSIA_LnBndRiTrgValidRDW_bool(rtb_EQ_b);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch47'/copy1' */
    SET_D_DPRSIA_LnBndLeCancelValidRDW_bool(rtb_DataTypeConversion_ke);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch49'/copy1' */
    SET_D_DPRSIA_LnBndRiCancelValidRDW_bool(rtb_DataTypeConversion_o3r);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch50'/copy1' */
    SET_D_DPRSIA_RdBndLeTrgValidRDW_bool(rtb_EQ_mo);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch51'/copy1' */
    SET_D_DPRSIA_RdBndRiTrgValidRDW_bool(rtb_EQ_p);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch52'/copy1' */
    SET_D_DPRSIA_RdBndLeCancelValidRDW_bool(rtb_DataTypeConversion_da);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch6'/copy1' */
    SET_D_DPRSIA_LnBndRiCancelValidRDP_bool(rtb_DataTypeConversion_ae);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch7'/copy1' */
    SET_D_DPRSIA_RdBndLeTrgValidRDP_bool(rtb_EQ_e);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch8'/copy1' */
    SET_D_DPRSIA_RdBndRiTrgValidRDP_bool(rtb_EQ_n);
    /* SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/branch9'/copy1' */
    SET_D_DPRSIA_RdBndLeCancelValidRDP_bool(rtb_DataTypeConversion_f5o);
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneTrgLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_g = rtb_GT;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/CurvatureLaneLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_d = rtb_LT_l1;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeLnBndValidRDP/HeadingLaneCncLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_kh = rtb_LT_fj;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadTrgLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_j = rtb_GT_pn;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/CurvatureRoadLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_jw = rtb_LT_oe;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/LeRdBndValidRDP/HeadingRoadCncLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_e1 = rtb_LT_ff;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneTrgRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_a = rtb_GT_ec;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/CurvatureLaneRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_l = rtb_LT_px;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiLnBndValidRDP/HeadingLaneCncRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_pa = rtb_LT_c5;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadTrgRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_nz = rtb_GT_ft;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/CurvatureRoadRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_j0 = rtb_LT_i;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/AnyBoundaryValidation/RiRdBndValidRDP/HeadingRoadCncRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_f = rtb_LT_oq;
    /* S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsia_Unit_Delay_DSTATE = rtb_NE_e;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising1/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi'/Unit Delay1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Constant1'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerRi/Max/Functionality'/Max'
         */
    DW_dprsia_UnitDelay1_DSTATE_f = f32_max_f32_f32(rtb_Switch_a, 0.0F);
    /* S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsia_Unit_Delay_DSTATE_e = rtb_Switch_cq;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe'/Unit Delay1' incorporates:
         *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Constant1'/Constant'
         *  MinMax: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/TurnSignal/FollowUpTimerLe/Max/Functionality'/Max'
         */
    DW_dprsia_UnitDelay1_DSTATE_m = f32_max_f32_f32(rtb_Switch_gv, 0.0F);
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_jv = rtb_NE_hm;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/RoadWidthRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_oz = rtb_Switch_pa;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_nr = rtb_GT_n;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatLeft'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_n = rtb_LT_ny;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_ey = rtb_GT_o;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDP/SideConditionsRDP/VelLatRight'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_f0 = rtb_LT_n;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneTrgLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_h = rtb_LogicalOperator_l;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/CurvatureLaneLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_lw = rtb_LogicalOperator_h;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeLnBndValidRDW/HeadingLaneCncLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_km = rtb_LogicalOperator_df;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadTrgLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_es = rtb_GT_mtz;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/CurvatureRoadLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_an = rtb_LT_nke;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/LeRdBndValidRDW/HeadingRoadCncLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_ew = rtb_LT_hd;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneTrgRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_pu = rtb_GT_fm;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/CurvatureLaneRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_cc = rtb_LT_c;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiLnBndValidRDW/HeadingLaneCncRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_ou = rtb_LT_nt;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadTrgRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_jx = rtb_GT_mh;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/CurvatureRoadRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_j4 = rtb_LT_hr;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/AnyBoundaryValidation/RiRdBndValidRDW/HeadingRoadCncRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_h4 = rtb_LT_a;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_m = rtb_Switch_kz;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/RoadWidthRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_ic = rtb_NE_c;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_fm = rtb_NE_m;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatLeft'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_h = rtb_Switch_ip;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_k0 = rtb_DataTypeConversion_kq;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/RDW/SideConditionsRDP/VelLatRight'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_d = rtb_LT_k4;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/VelVehDisp'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_f2 = rtb_LogicalOperator_f;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngle'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_nc = rtb_LogicalOperator_d;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/SteeringWheelAngleSpeed'/Unit Delay2' */
    DW_dprsia_UnitDelay2_DSTATE_nk = rtb_LogicalOperator_c;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_ds = rtb_LogicalOperator_k;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LongAclValidity'/Unit Delay3' */
    DW_dprsia_UnitDelay3_DSTATE_d = rtb_Switch3_f;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LatAclValidity'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_k = rtb_SignalConversion;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/EgoVehCurvature'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_i = rtb_Switch3_l;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_o = rtb_LogicalOperator_e;
    for (i = 0; i < 2; i++) {
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDP'/Unit Delay2' */
        DW_dprsia_UnitDelay2_DSTATE_khn[i] = (uint8)rtb_DataTypeConversion_kt2[i];
        /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/Unit Delay2' */
        DW_dprsia_UnitDelay2_DSTATE_jm[i] = (uint8)rtb_Switch_pv[i];
    }
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/LaneWidthRoadWidthRDW'/Unit Delay1' */
    DW_dprsia_UnitDelay1_DSTATE_mz = rtb_DataTypeConversion_j1;
    /* Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/Unit_Delay1' */
    for (i = 0; i < 8; i++) {
        /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/P_LDPSA_VelXHyst_mps'/Constant'
                 *  Constant: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Relational Operator'
                 *  Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Switch2'
                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/Unit_Delay1'
                 */
        if (((sint32)rtb_VectorConcatenate_n[i]) != 0) {
            DW_dprsia_Unit_Delay1_DSTATE_d[i] = GET_P_DPRSIA_RDPSpecificDebTime_sec((i));
        } else {
            if (DW_dprsia_Unit_Delay1_DSTATE_d[i] > 0.0F) {
                /* Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                                 *  Sum: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                                 *  UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/Unit_Delay1'
                                 */
                DW_dprsia_Unit_Delay1_DSTATE_d[i] -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            }
        }
        /* End of Switch: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW/TURNOFFDELAYTIME/Functionality'/Switch1' */
    }
    /* End of Update for UnitDelay: 'sda:DPRSIA/DPRSIA/DPRSIA_SenProcess/OPM/M_DPRSIA/SpecificConditionsRDP_RDW'/Unit_Delay1' */
}
#include "Pse_DPRSIA.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
