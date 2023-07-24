/**************************************************************************
COPYRIGHT (C) $Date: 2020/11/04 09:16:38CET $
$CompanyInfo: Customer Version - data base tag will be adapted on check-in by your data base$
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ES/1T/0C/SDA/Customer_Version/SDA_Source/SDA_Toolboxes/ACG/Toolboxes/sdatarget/sdatarget/tlc_helper/project.pj $
$Log: $
File          : JCNCTR
Generated on  : Thu 06.07.2023 at 10:29:06 (UTC+01:00)
MD5           : [1834120908   869062287  3655736075  3753800008 0](JCNCTR)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.1012177 (R2016b) Update 7
SDA version   : 10.0ADAS
Hot fixes     : SDA-Core: 1,2
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "JCNCTR_private.h"  //MFC5J3CN15
#include "LCFPRM/LCFPRM_data.h"  //MFC5J3CN15
#include "JCNCTR.h"
/* Specific Includes */
/* End of Specific Includes */
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
#define JCNCTR_START_SEC_DATA_8
#include "JCNCTR_MemMap.h"
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_h;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_c;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_k;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_b;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_i;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_f;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_l;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_d;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_fk;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_m;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_lx;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_ba;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_it;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_j;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_bw;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_dl;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_g;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_o;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_p;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_a;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_c3;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_bj;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_dy;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_e;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_g5;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_bv;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_ck;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_dn;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_mo;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_n;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_h1;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_gb;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_gn;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_me;
static uint8 DW_jcnctr_Unit_Delay2_DSTATE_pb;
#define JCNCTR_STOP_SEC_DATA_8
#include "JCNCTR_MemMap.h"
#define JCNCTR_START_SEC_DATA_32
#include "JCNCTR_MemMap.h"
static float32 DW_jcnctr_Unit_Delay_DSTATE;
static float32 DW_jcnctr_Unit_Delay1_DSTATE;
static float32 DW_jcnctr_Unit_Delay_DSTATE_o;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_g;
static float32 DW_jcnctr_Unit_Delay_DSTATE_g;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_i;
static float32 DW_jcnctr_Unit_Delay_DSTATE_oh;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_d;
static float32 DW_jcnctr_Unit_Delay_DSTATE_n;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_go;
static float32 DW_jcnctr_Unit_Delay_DSTATE_i;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_p;
static float32 DW_jcnctr_Unit_Delay_DSTATE_l;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_h;
static float32 DW_jcnctr_Unit_Delay_DSTATE_m;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_pp;
static float32 DW_jcnctr_Unit_Delay_DSTATE_f;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_c;
static float32 DW_jcnctr_Unit_Delay_DSTATE_go;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_f;
static float32 DW_jcnctr_Unit_Delay_DSTATE_p;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_a;
static float32 DW_jcnctr_Unit_Delay_DSTATE_mt;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_o;
static float32 DW_jcnctr_Unit_Delay_DSTATE_ph;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_hu;
static float32 DW_jcnctr_Unit_Delay_DSTATE_gn;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_j;
static float32 DW_jcnctr_Unit_Delay_DSTATE_d;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_p3;
static float32 DW_jcnctr_Unit_Delay_DSTATE_b;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_b;
static float32 DW_jcnctr_Unit_Delay_DSTATE_n4;
static float32 DW_jcnctr_Unit_Delay2_DSTATE;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_ge;
static float32 DW_jcnctr_Unit_Delay_DSTATE_ma;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_gf;
static float32 DW_jcnctr_Unit_Delay_DSTATE_h;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_dc;
static float32 DW_jcnctr_Unit_Delay_DSTATE_pv;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_pa;
static float32 DW_jcnctr_Unit_Delay_DSTATE_hh;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_hb;
static float32 DW_jcnctr_Unit_Delay_DSTATE_e;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_iu;
static float32 DW_jcnctr_Unit_Delay_DSTATE_da;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_dg;
static float32 DW_jcnctr_Unit_Delay_DSTATE_oy;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_bf;
static float32 DW_jcnctr_Unit_Delay_DSTATE_oyh;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_jz;
static float32 DW_jcnctr_Unit_Delay_DSTATE_db;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_n;
static float32 DW_jcnctr_Unit_Delay_DSTATE_os;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_e;
static float32 DW_jcnctr_Unit_Delay_DSTATE_pb;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_h1;
static float32 DW_jcnctr_Unit_Delay_DSTATE_ov;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_o4;
static float32 DW_jcnctr_Unit_Delay_DSTATE_il;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_nb;
static float32 DW_jcnctr_Unit_Delay_DSTATE_bs;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_iv;
static float32 DW_jcnctr_Unit_Delay_DSTATE_bv;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_k;
static float32 DW_jcnctr_Unit_Delay_DSTATE_iv;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_ke;
static float32 DW_jcnctr_Unit_Delay_DSTATE_hy;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_dq;
static float32 DW_jcnctr_Unit_Delay_DSTATE_c;
static float32 DW_jcnctr_Unit_Delay1_DSTATE_m;
#define JCNCTR_STOP_SEC_DATA_32
#include "JCNCTR_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:JCNCTR/JCNCTR'/JCNCTR_SenReset'
 * Block description for: 'sda:JCNCTR/JCNCTR'/JCNCTR_SenReset'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_JCNCTR_SenReset
#include "Pse_JCNCTR.h"
/* Short description:  */
void JCNCTR_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenReset/Constant'/Constant' */
    SET_S_JCNCTR_PrjSpecQu_btf(0U);
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenReset/Constant1'/Constant' */
    SET_S_JCNCTR_LDWPrjSpecQu_btf(0U);
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenReset/Constant2'/Constant' */
    SET_S_JCNCTR_LKAPrjSpecQu_btf(0U);
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenReset/Constant3'/Constant' */
    SET_S_JCNCTR_ELKPrjSpecQu_btf(0U);
}
#include "Pse_JCNCTR.h"
/*
 * Output and update for function-call system: 'sda:JCNCTR/JCNCTR'/JCNCTR_SenProcess'
 * Block description for: 'sda:JCNCTR/JCNCTR'/JCNCTR_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_JCNCTR_SenProcess
#include "Pse_JCNCTR.h"
/* Short description:  */
void JCNCTR_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    uint16 rtb_sfun_setbit;
    uint16 rtb_sfun_setbit_a;
    uint16 rtb_sfun_setbit_n;
    uint16 rtb_sfun_setbit_j;
    uint8 rtb_VectorConcatenate1[16];
    uint8 rtb_VectorConcatenate2[16];
    uint8 rtb_VectorConcatenate[16];
    uint8 rtb_S_JCNCTR_PrjSpecQu_btf[16];
    float32 rtb_Abs_o;
    float32 rtb_Switch;
    uint8 rtb_DataTypeConversion_it;
    float32 rtb_Switch_iy;
    float32 rtb_Switch_ps;
    float32 rtb_Switch_k2;
    float32 rtb_Switch_c;
    float32 rtb_Switch_mt;
    uint8 rtb_Switch_gjt;
    uint8 rtb_Switch_ks;
    float32 rtb_Switch_az;
    float32 rtb_Switch_hph;
    uint8 rtb_Switch_h0;
    uint8 rtb_Switch_i;
    float32 rtb_Switch_d3;
    float32 rtb_Switch_bh;
    float32 rtb_Switch_k;
    float32 rtb_Switch_pm;
    float32 rtb_Switch_ko;
    float32 rtb_Switch_fv;
    float32 rtb_Switch_gw;
    float32 rtb_Switch_g1;
    float32 rtb_Switch_ci;
    float32 rtb_Abs;
    float32 rtb_Switch_jvf;
    float32 rtb_Switch_a1;
    uint8 rtb_Switch_bxr;
    uint8 rtb_Switch_jf;
    float32 rtb_Switch_nqz;
    float32 rtb_Switch_gg0;
    uint8 rtb_Switch_jo4;
    uint8 rtb_Switch_ic;
    float32 rtb_Switch_j;
    float32 rtb_Switch_ng;
    float32 rtb_Switch_po;
    float32 rtb_Switch_kx;
    uint8 rtb_DataTypeConversion_l3;
    float32 rtb_Switch_fs;
    float32 rtb_Switch_e;
    float32 rtb_Switch_p;
    float32 rtb_Switch_fz;
    float32 rtb_Switch_mg;
    uint8 rtb_Switch_lnh;
    uint8 rtb_Switch_in;
    float32 rtb_Switch_cz;
    float32 rtb_Switch_da;
    uint8 rtb_Switch_ib;
    uint8 rtb_Switch_l2;
    float32 rtb_Switch_g5;
    float32 rtb_Switch_o;
    float32 rtb_Switch_gi;
    float32 rtb_Switch_ab;
    float32 rtb_Switch_eg4;
    float32 rtb_Switch_mk;
    float32 rtb_Switch_gt;
    float32 rtb_Switch_l3;
    float32 rtb_Switch_nq;
    float32 rtb_Switch_jd;
    float32 rtb_Switch_dc;
    float32 rtb_Switch_h;
    float32 rtb_Switch_jk;
    float32 rtb_Switch_oi;
    float32 rtb_Switch_a;
    float32 rtb_Switch_g;
    float32 rtb_Switch_b;
    float32 rtb_Switch_m;
    float32 rtb_Switch_la;
    float32 rtb_Switch_l;
    float32 rtb_Switch_f;
    float32 rtb_Switch_kj;
    float32 rtb_Switch_mo;
    float32 rtb_Switch_n1;
    float32 rtb_Switch_ne;
    float32 rtb_Switch_pu;
    float32 rtb_Switch_hv;
    float32 rtb_Switch_n;
    float32 rtb_Switch_cy;
    float32 rtb_Switch_al5;
    float32 rtb_Switch_mv;
    float32 rtb_Switch_gq;
    float32 rtb_Switch_f4;
    float32 rtb_Switch_cf;
    float32 rtb_Switch_at;
    float32 rtb_Switch_m3;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs12/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_VehYawRate_rps());
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant61'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT8/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_LKAYawRateSup_rps()) {
        rtb_Switch = DW_jcnctr_Unit_Delay_DSTATE + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant14'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT8/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_LKAYawRateNoSup_rps()) {
        rtb_Switch_ab = DW_jcnctr_Unit_Delay1_DSTATE + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_ab = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant72'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant83'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKAYawRateSupDur_sec() <= rtb_Switch) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_LKAYawRateNoSupDur_sec() <= rtb_Switch_ab) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_h;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_h = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate1In1' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1[0] = rtb_DataTypeConversion_it;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs3/Functionality'/Abs' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant55'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndCurvature_1pm'
         *  Selector: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/Selector2'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_AnyBndCurvature_1pm(8));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant64'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT9/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_LKACurvatureSup_1pm()) {
        rtb_Switch_iy = DW_jcnctr_Unit_Delay_DSTATE_o + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_iy = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant63'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT9/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_LKACurvatureNoSup_1pm()) {
        rtb_Switch_eg4 = DW_jcnctr_Unit_Delay1_DSTATE_g + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_eg4 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant65'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant99'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKACurvatureSupDur_sec() <= rtb_Switch_iy) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_LKACurvatureNoSupDur_sec() <= rtb_Switch_eg4) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_c;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_c = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate1In2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1[1] = rtb_DataTypeConversion_it;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs5/Functionality'/Abs' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant89'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndCurvature_1pm'
         *  Selector: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/Selector3'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_AnyBndCurvature_1pm(9));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant91'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT14/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_LKACurvatureSup_1pm()) {
        rtb_Switch_ps = DW_jcnctr_Unit_Delay_DSTATE_g + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_ps = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant90'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT14/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_LKACurvatureNoSup_1pm()) {
        rtb_Switch_mk = DW_jcnctr_Unit_Delay1_DSTATE_i + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_mk = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant92'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant93'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKACurvatureSupDur_sec() <= rtb_Switch_ps) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_LKACurvatureNoSupDur_sec() <= rtb_Switch_mk) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_k;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_k = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1[2] = rtb_DataTypeConversion_it;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs4/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm());
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant71'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT10/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_LKAManualTrqSup_Nm()) {
        rtb_Switch_k2 = DW_jcnctr_Unit_Delay_DSTATE_oh + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_k2 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant73'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT10/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_LKAManualTrqNoSup_Nm()) {
        rtb_Switch_gt = DW_jcnctr_Unit_Delay1_DSTATE_d + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_gt = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant74'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant75'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKAManualTrqSupDur_sec() <= rtb_Switch_k2) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_LKAManualTrqNoSupDur_sec() <= rtb_Switch_gt) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_b;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_b = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate1In4' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1[3] = rtb_DataTypeConversion_it;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant220'/Constant' */
    rtb_VectorConcatenate1[4] = 0U;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant565'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT53/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35'/Unit_Delay'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() > GET_P_JCNCTR_LKAMaxLaneWidthSup_met()) {
        rtb_Switch_c = DW_jcnctr_Unit_Delay_DSTATE_n + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_c = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant561'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT34/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() < GET_P_JCNCTR_LKAMaxLaneWidthNoSup_met()) {
        rtb_Switch_l3 = DW_jcnctr_Unit_Delay1_DSTATE_go + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_l3 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant563'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant564'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKAMaxLaneWidthSupDur_sec() <= rtb_Switch_c) {
        rtb_Switch_gjt = 1U;
    } else if (GET_P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec() <= rtb_Switch_l3) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_gjt = 0U;
    } else {
        rtb_Switch_gjt = DW_jcnctr_Unit_Delay2_DSTATE_i;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35/SRFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant81'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT11/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15'/Unit_Delay'
         */
    if (GET_S_ABPLBP_LaneWidth_met() > GET_P_JCNCTR_LKAMaxLaneWidthSup_met()) {
        rtb_Switch_mt = DW_jcnctr_Unit_Delay_DSTATE_i + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_mt = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant101'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT11/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_LaneWidth_met() < GET_P_JCNCTR_LKAMaxLaneWidthNoSup_met()) {
        rtb_Switch_nq = DW_jcnctr_Unit_Delay1_DSTATE_p + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_nq = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant76'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant77'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKAMaxLaneWidthSupDur_sec() <= rtb_Switch_mt) {
        rtb_Switch_ks = 1U;
    } else if (GET_P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec() <= rtb_Switch_nq) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_ks = 0U;
    } else {
        rtb_Switch_ks = DW_jcnctr_Unit_Delay2_DSTATE_f;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15/SRFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR75/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR75/Functionality'/OR'
         */
    rtb_VectorConcatenate1[5] = (uint8)((((sint32)rtb_Switch_gjt) != 0) || (((sint32)rtb_Switch_ks) != 0));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant84'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT13/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16'/Unit_Delay'
         */
    if (GET_S_ABPLBP_LaneWidth_met() < GET_P_JCNCTR_LKAMinLaneWidthSup_met()) {
        rtb_Switch_az = DW_jcnctr_Unit_Delay_DSTATE_l + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_az = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant85'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT13/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_LaneWidth_met() > GET_P_JCNCTR_LKAMinLaneWidthNoSup_met()) {
        rtb_Switch_jd = DW_jcnctr_Unit_Delay1_DSTATE_h + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_jd = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant16'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant82'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKAMinLaneWidthSupDur_sec() <= rtb_Switch_az) {
        rtb_Switch_h0 = 1U;
    } else if (GET_P_JCNCTR_LKAMinLaneWidthNoSupDur_sec() <= rtb_Switch_jd) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_h0 = 0U;
    } else {
        rtb_Switch_h0 = DW_jcnctr_Unit_Delay2_DSTATE_l;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16/SRFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant567'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT30/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36'/Unit_Delay'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() < GET_P_JCNCTR_LKAMinLaneWidthSup_met()) {
        rtb_Switch_hph = DW_jcnctr_Unit_Delay_DSTATE_m + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_hph = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant568'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT54/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() > GET_P_JCNCTR_LKAMinLaneWidthNoSup_met()) {
        rtb_Switch_dc = DW_jcnctr_Unit_Delay1_DSTATE_pp + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_dc = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant562'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant566'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKAMinLaneWidthSupDur_sec() <= rtb_Switch_hph) {
        rtb_Switch_i = 1U;
    } else if (GET_P_JCNCTR_LKAMinLaneWidthNoSupDur_sec() <= rtb_Switch_dc) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_i = 0U;
    } else {
        rtb_Switch_i = DW_jcnctr_Unit_Delay2_DSTATE_d;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36/SRFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR13/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR13/Functionality'/OR'
         */
    rtb_VectorConcatenate1[6] = (uint8)((((sint32)rtb_Switch_h0) != 0) || (((sint32)rtb_Switch_i) != 0));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant67'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant68'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND4/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ18/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ19/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12'/Unit_Delay'
         */
    if ((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) == 1) && (((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) == 1)) {
        rtb_Switch_d3 = DW_jcnctr_Unit_Delay_DSTATE_f + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_d3 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant66'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant100'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND3/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NEQ3/Functionality'/NE'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12'/Unit_Delay1'
         */
    if ((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) != 1) && (((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) != 1)) {
        rtb_Switch_h = DW_jcnctr_Unit_Delay1_DSTATE_c + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_h = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant69'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant70'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKABothLaneInvalidSupDur_sec() <= rtb_Switch_d3) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_LKABothLaneValidNoSupDur_sec() <= rtb_Switch_h) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_fk;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_fk = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate1In8' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1[7] = rtb_DataTypeConversion_it;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant54'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlABS_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlESC_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR5/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ20/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ28/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ34/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ35/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17'/Unit_Delay'
         */
    if ((((((sint32)GET_S_LCFRCV_ActiveStCtrlABS_bool()) == 1) || (((sint32) GET_S_LCFRCV_ActiveStCtrlEBA_bool()) == 1)) || (((sint32) GET_S_LCFRCV_ActiveStCtrlTCS_bool()) == 1)) || (((sint32) GET_S_LCFRCV_ActiveStCtrlESC_bool()) == 1)) {
        rtb_Switch_bh = DW_jcnctr_Unit_Delay_DSTATE_go + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_bh = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant87'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlABS_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlESC_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND5/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ21/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ22/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ23/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ29/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17'/Unit_Delay1'
         */
    if ((((0 == ((sint32)GET_S_LCFRCV_ActiveStCtrlABS_bool())) && (((sint32) GET_S_LCFRCV_ActiveStCtrlEBA_bool()) == 0)) && (((sint32) GET_S_LCFRCV_ActiveStCtrlTCS_bool()) == 0)) && (((sint32) GET_S_LCFRCV_ActiveStCtrlESC_bool()) == 0)) {
        rtb_Switch_jk = DW_jcnctr_Unit_Delay1_DSTATE_f + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_jk = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant86'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant88'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKAActiveStCtrSupTime_sec() <= rtb_Switch_bh) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_LKAActiveStCtrNoSupTime_sec() <= rtb_Switch_jk) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_m;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_m = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate1In9' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1[8] = rtb_DataTypeConversion_it;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant56'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant111'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_BrkPedlPressed_bool'
         *  Inport: '<Root>/S_LCFRCV_MainCylPressure_pa'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND14/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ42/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT15/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19'/Unit_Delay'
         */
    if ((GET_S_LCFRCV_MainCylPressure_pa() > GET_P_JCNCTR_LKAMainCylPresSup_pa()) && (((sint32)GET_S_LCFRCV_BrkPedlPressed_bool()) == 1)) {
        rtb_Switch_k = DW_jcnctr_Unit_Delay_DSTATE_p + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_k = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant97'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_MainCylPressure_pa'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT15/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19'/Unit_Delay1'
         */
    if (GET_S_LCFRCV_MainCylPressure_pa() < GET_P_JCNCTR_LKAMainCylPresNoSup_pa()) {
        rtb_Switch_oi = DW_jcnctr_Unit_Delay1_DSTATE_a + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_oi = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant95'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant96'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LKAMainCylPresSupDur_sec() <= rtb_Switch_k) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_LKAMainCylPresNoSupDur_sec() <= rtb_Switch_oi) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_lx;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_lx = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate1In10' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1[9] = rtb_DataTypeConversion_it;
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition10'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition11'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition12'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition7'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition8'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ24/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ25/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ26/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ27/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ30/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ31/Functionality'/EQ'
         */
    rtb_VectorConcatenate1[10] = (uint8)((((((((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)))) || (((sint32) GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32) GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((sint32) GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition31'/state_source'
         *  Inport: '<Root>/S_LCFRCV_SysStateIACC_nu'
         */
    rtb_VectorConcatenate1[11] = (uint8)(((sint32)GET_S_LCFRCV_SysStateIACC_nu()) == ((sint32)((uint8)E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_ACTIVE)));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant57'/Constant'
         *  Inport: '<Root>/S_LCFRCV_BrakePedalPostion_mm'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT30/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38'/Unit_Delay'
         */
    if (GET_S_LCFRCV_BrakePedalPostion_mm() > GET_P_JCNCTR_BrakePedalPostionSup_mm ()) {
        rtb_Switch_pm = DW_jcnctr_Unit_Delay_DSTATE_mt + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_pm = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant113'/Constant'
         *  Inport: '<Root>/S_LCFRCV_BrakePedalPostion_mm'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT35/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38'/Unit_Delay1'
         */
    if (GET_S_LCFRCV_BrakePedalPostion_mm() < GET_P_JCNCTR_BrakePedalPostionNoSup_mm()) {
        rtb_Switch_a = DW_jcnctr_Unit_Delay1_DSTATE_o + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_a = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant230'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant53'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_BrakePedalPostionSupDur_sec() <= rtb_Switch_pm) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_BrakePedalPostionNoSupDur_sec() <= rtb_Switch_a) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_ba;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_ba = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate1In13' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate1[12] = rtb_DataTypeConversion_it;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant60'/Constant' */
    rtb_VectorConcatenate1[13] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant58'/Constant' */
    rtb_VectorConcatenate1[14] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant62'/Constant' */
    rtb_VectorConcatenate1[15] = 0U;
    /* S-Function (sfun_setbit): 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate1[0];
                for (i1=0; i1 < 16; i1++) {
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
        rtb_sfun_setbit = temp;
    }
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs13/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_VehYawRate_rps());
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant115'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT22/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_ELKYawRateSup_rps()) {
        rtb_Switch_ko = DW_jcnctr_Unit_Delay_DSTATE_ph + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_ko = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant106'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT22/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_ELKYawRateNoSup_rps()) {
        rtb_Switch_g = DW_jcnctr_Unit_Delay1_DSTATE_hu + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_g = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant126'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant137'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKYawRateSupDur_sec() <= rtb_Switch_ko) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_ELKYawRateNoSupDur_sec() <= rtb_Switch_g) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_it;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_it = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate2In1' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate2[0] = rtb_DataTypeConversion_it;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs6/Functionality'/Abs' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant109'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndCurvature_1pm'
         *  Selector: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/Selector4'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_AnyBndCurvature_1pm(8));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant118'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT23/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_ELKCurvatureSup_1pm()) {
        rtb_Switch_fv = DW_jcnctr_Unit_Delay_DSTATE_gn + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_fv = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant117'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT23/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_ELKCurvatureNoSup_1pm()) {
        rtb_Switch_b = DW_jcnctr_Unit_Delay1_DSTATE_j + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_b = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant153'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant119'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKCurvatureSupDur_sec() <= rtb_Switch_fv) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_ELKCurvatureNoSupDur_sec() <= rtb_Switch_b) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_j;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_j = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate2In2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate2[1] = rtb_DataTypeConversion_it;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs8/Functionality'/Abs' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant143'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndCurvature_1pm'
         *  Selector: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/Selector5'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_AnyBndCurvature_1pm(9));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant145'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT20/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_ELKCurvatureSup_1pm()) {
        rtb_Switch_gw = DW_jcnctr_Unit_Delay_DSTATE_d + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_gw = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant144'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT20/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_ELKCurvatureNoSup_1pm()) {
        rtb_Switch_m = DW_jcnctr_Unit_Delay1_DSTATE_p3 + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_m = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant146'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant147'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKCurvatureSupDur_sec() <= rtb_Switch_gw) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_ELKCurvatureNoSupDur_sec() <= rtb_Switch_m) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_bw;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_bw = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate2[2] = rtb_DataTypeConversion_it;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs7/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm());
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant125'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT16/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_ELKManualTrqSup_Nm()) {
        rtb_Switch_g1 = DW_jcnctr_Unit_Delay_DSTATE_b + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_g1 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant127'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT16/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_ELKManualTrqNoSup_Nm()) {
        rtb_Switch_la = DW_jcnctr_Unit_Delay1_DSTATE_b + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_la = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant128'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant129'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKManualTrqSupDur_sec() <= rtb_Switch_g1) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_ELKManualTrqNoSupDur_sec() <= rtb_Switch_la) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_dl;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_dl = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate2In4' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate2[3] = rtb_DataTypeConversion_it;
    /* Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Sum3/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_AccelPedalPos_nu'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/Unit_Delay2'
         */
    rtb_Abs_o = GET_S_LCFRCV_AccelPedalPos_nu() - DW_jcnctr_Unit_Delay2_DSTATE;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant105'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT18/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_ELKAccPedalPosSup_nu()) {
        rtb_Switch_ci = DW_jcnctr_Unit_Delay_DSTATE_n4 + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_ci = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant132'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT18/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_ELKAccPedalPosNoSup_nu()) {
        rtb_Switch_l = DW_jcnctr_Unit_Delay1_DSTATE_ge + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_l = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant133'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant134'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKAccPedalPosSupDur_sec() <= rtb_Switch_ci) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_ELKAccPedalPosNoSupDur_sec() <= rtb_Switch_l) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_g;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_g = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate2In5' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate2[4] = rtb_DataTypeConversion_it;
    /* Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0SIF_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0SIF_met'
         */
    rtb_Abs_o = GET_S_ABPLBP_LeLnClthPosY0SIF_met() - GET_S_ABPLBP_RiLnClthPosY0SIF_met();
    /* Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Sum5/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         */
    rtb_Abs = GET_S_ABPLBP_LeLnClthPosY0_met() - GET_S_ABPLBP_RiLnClthPosY0_met();
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant135'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR11/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT17/Functionality'/GT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT28/Functionality'/GT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT29/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25'/Unit_Delay'
         */
    if (((GET_S_ABPLBP_LaneWidth_met() > GET_P_JCNCTR_ELKMaxLaneWidthSup_met()) || (rtb_Abs_o > GET_P_JCNCTR_ELKMaxLaneWidthSup_met())) || (rtb_Abs > GET_P_JCNCTR_ELKMaxLaneWidthSup_met())) {
        rtb_Switch_jvf = DW_jcnctr_Unit_Delay_DSTATE_ma + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_jvf = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant104'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR12/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT17/Functionality'/LT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT28/Functionality'/LT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT29/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25'/Unit_Delay1'
         */
    if (((GET_S_ABPLBP_LaneWidth_met() < GET_P_JCNCTR_ELKMaxLaneWidthNoSup_met()) || (rtb_Abs_o < GET_P_JCNCTR_ELKMaxLaneWidthNoSup_met())) || (rtb_Abs < GET_P_JCNCTR_ELKMaxLaneWidthNoSup_met())) {
        rtb_Switch_f = DW_jcnctr_Unit_Delay1_DSTATE_gf + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_f = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant130'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant131'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKMaxLaneWidthSupDur_sec() <= rtb_Switch_jvf) {
        rtb_Switch_bxr = 1U;
    } else if (GET_P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec() <= rtb_Switch_f) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_bxr = 0U;
    } else {
        rtb_Switch_bxr = DW_jcnctr_Unit_Delay2_DSTATE_o;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25/SRFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant573'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT55/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34'/Unit_Delay'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() > GET_P_JCNCTR_ELKMaxLaneWidthSup_met()) {
        rtb_Switch_a1 = DW_jcnctr_Unit_Delay_DSTATE_h + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_a1 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant569'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT31/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() < GET_P_JCNCTR_ELKMaxLaneWidthNoSup_met()) {
        rtb_Switch_kj = DW_jcnctr_Unit_Delay1_DSTATE_dc + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_kj = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant571'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant572'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKMaxLaneWidthSupDur_sec() <= rtb_Switch_a1) {
        rtb_Switch_jf = 1U;
    } else if (GET_P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec() <= rtb_Switch_kj) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_jf = 0U;
    } else {
        rtb_Switch_jf = DW_jcnctr_Unit_Delay2_DSTATE_p;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34/SRFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR81/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR81/Functionality'/OR'
         */
    rtb_VectorConcatenate2[5] = (uint8)((((sint32)rtb_Switch_bxr) != 0) || (((sint32)rtb_Switch_jf) != 0));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant138'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR7/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT26/Functionality'/LT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT27/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26'/Unit_Delay'
         */
    if ((GET_S_ABPLBP_LaneWidth_met() < GET_P_JCNCTR_ELKMinLaneWidthSup_met()) || (rtb_Abs < GET_P_JCNCTR_ELKMinLaneWidthSup_met())) {
        rtb_Switch_nqz = DW_jcnctr_Unit_Delay_DSTATE_pv + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_nqz = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant139'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR6/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT19/Functionality'/GT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT26/Functionality'/GT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT27/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26'/Unit_Delay1'
         */
    if (((GET_S_ABPLBP_LaneWidth_met() > GET_P_JCNCTR_ELKMinLaneWidthNoSup_met()) || (rtb_Abs_o > GET_P_JCNCTR_ELKMinLaneWidthNoSup_met())) || (rtb_Abs > GET_P_JCNCTR_ELKMinLaneWidthNoSup_met())) {
        rtb_Switch_mo = DW_jcnctr_Unit_Delay1_DSTATE_pa + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_mo = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant107'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant136'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKMinLaneWidthSupDur_sec() <= rtb_Switch_nqz) {
        rtb_Switch_jo4 = 1U;
    } else if (GET_P_JCNCTR_ELKMinLaneWidthNoSupDur_sec() <= rtb_Switch_mo) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_jo4 = 0U;
    } else {
        rtb_Switch_jo4 = DW_jcnctr_Unit_Delay2_DSTATE_a;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26/SRFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant575'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT44/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37'/Unit_Delay'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() < GET_P_JCNCTR_ELKMinLaneWidthSup_met()) {
        rtb_Switch_gg0 = DW_jcnctr_Unit_Delay_DSTATE_hh + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_gg0 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant576'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT56/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() > GET_P_JCNCTR_ELKMinLaneWidthNoSup_met()) {
        rtb_Switch_n1 = DW_jcnctr_Unit_Delay1_DSTATE_hb + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_n1 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant570'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant574'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKMinLaneWidthSupDur_sec() <= rtb_Switch_gg0) {
        rtb_Switch_ic = 1U;
    } else if (GET_P_JCNCTR_ELKMinLaneWidthNoSupDur_sec() <= rtb_Switch_n1) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_ic = 0U;
    } else {
        rtb_Switch_ic = DW_jcnctr_Unit_Delay2_DSTATE_c3;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37/SRFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR14/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR14/Functionality'/OR'
         */
    rtb_VectorConcatenate2[6] = (uint8)((((sint32)rtb_Switch_jo4) != 0) || (((sint32)rtb_Switch_ic) != 0));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant121'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant122'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND7/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ36/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ37/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22'/Unit_Delay'
         */
    if ((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) == 1) && (((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) == 1)) {
        rtb_Switch_j = DW_jcnctr_Unit_Delay_DSTATE_e + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_j = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant103'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant120'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND6/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NEQ5/Functionality'/NE'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22'/Unit_Delay1'
         */
    if ((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) != 1) && (((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) != 1)) {
        rtb_Switch_ne = DW_jcnctr_Unit_Delay1_DSTATE_iu + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_ne = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant123'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant124'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKBothLaneInvalidSupDur_sec() <= rtb_Switch_j) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_ELKBothLaneValidNoSupDur_sec() <= rtb_Switch_ne) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_bj;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_bj = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate2In8' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate2[7] = rtb_DataTypeConversion_it;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant108'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlABS_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlESC_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR8/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ38/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ46/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ52/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ53/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27'/Unit_Delay'
         */
    if ((((((sint32)GET_S_LCFRCV_ActiveStCtrlABS_bool()) == 1) || (((sint32) GET_S_LCFRCV_ActiveStCtrlEBA_bool()) == 1)) || (((sint32) GET_S_LCFRCV_ActiveStCtrlTCS_bool()) == 1)) || (((sint32) GET_S_LCFRCV_ActiveStCtrlESC_bool()) == 1)) {
        rtb_Switch_ng = DW_jcnctr_Unit_Delay_DSTATE_da + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_ng = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant141'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlABS_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlESC_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND8/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ39/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ40/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ41/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ47/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27'/Unit_Delay1'
         */
    if ((((0 == ((sint32)GET_S_LCFRCV_ActiveStCtrlABS_bool())) && (((sint32) GET_S_LCFRCV_ActiveStCtrlEBA_bool()) == 0)) && (((sint32) GET_S_LCFRCV_ActiveStCtrlTCS_bool()) == 0)) && (((sint32) GET_S_LCFRCV_ActiveStCtrlESC_bool()) == 0)) {
        rtb_Switch_pu = DW_jcnctr_Unit_Delay1_DSTATE_dg + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_pu = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant140'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant142'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKActiveStCtrSupTime_sec() <= rtb_Switch_ng) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_ELKActiveStCtrNoSupTime_sec() <= rtb_Switch_pu) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_dy;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_dy = rtb_DataTypeConversion_it;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate2In9' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate2[8] = rtb_DataTypeConversion_it;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant152'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant110'/Constant'
         *  Inport: '<Root>/S_LCFRCV_BrkPedlPressed_bool'
         *  Inport: '<Root>/S_LCFRCV_MainCylPressure_pa'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND15/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ43/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT21/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29'/Unit_Delay'
         */
    if ((GET_S_LCFRCV_MainCylPressure_pa() > GET_P_JCNCTR_ELKMainCylPresSup_pa()) && (((sint32)GET_S_LCFRCV_BrkPedlPressed_bool()) == 1)) {
        rtb_Switch_po = DW_jcnctr_Unit_Delay_DSTATE_oy + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_po = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant151'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_MainCylPressure_pa'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT21/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29'/Unit_Delay1'
         */
    if (GET_S_LCFRCV_MainCylPressure_pa() < GET_P_JCNCTR_ELKMainCylPresNoSup_pa()) {
        rtb_Switch_hv = DW_jcnctr_Unit_Delay1_DSTATE_bf + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_hv = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant149'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant150'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_ELKMainCylPresSupDur_sec() <= rtb_Switch_po) {
        rtb_DataTypeConversion_it = 1U;
    } else if (GET_P_JCNCTR_ELKMainCylPresNoSupDur_sec() <= rtb_Switch_hv) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_it = 0U;
    } else {
        rtb_DataTypeConversion_it = DW_jcnctr_Unit_Delay2_DSTATE_e;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/SRFLIPFLOP/Functionality'/Switch' */
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector Concatenate2In10' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate2[9] = rtb_DataTypeConversion_it;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant114'/Constant' */
    rtb_VectorConcatenate2[10] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant154'/Constant' */
    rtb_VectorConcatenate2[11] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant155'/Constant' */
    rtb_VectorConcatenate2[12] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant156'/Constant' */
    rtb_VectorConcatenate2[13] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant112'/Constant' */
    rtb_VectorConcatenate2[14] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant116'/Constant' */
    rtb_VectorConcatenate2[15] = 0U;
    /* S-Function (sfun_setbit): 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/set_bit2/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate2[0];
                for (i1=0; i1 < 16; i1++) {
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
        rtb_sfun_setbit_a = temp;
    }
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         */
    rtb_Abs = f32_abs_f32(GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm());
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs11/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_VehYawRate_rps());
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_LDWYawRateSup_rps()) {
        rtb_Switch_kx = DW_jcnctr_Unit_Delay_DSTATE_oyh + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_kx = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant1'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_LDWYawRateNoSup_rps()) {
        rtb_Switch_n = DW_jcnctr_Unit_Delay1_DSTATE_jz + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_n = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant3'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant4'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWYawRateSupDur_sec() <= rtb_Switch_kx) {
        rtb_DataTypeConversion_l3 = 1U;
    } else if (GET_P_JCNCTR_LDWYawRateNoSupDur_sec() <= rtb_Switch_n) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_l3 = 0U;
    } else {
        rtb_DataTypeConversion_l3 = DW_jcnctr_Unit_Delay2_DSTATE_g5;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_g5 = rtb_DataTypeConversion_l3;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector ConcatenateIn1' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate[0] = rtb_DataTypeConversion_l3;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs/Functionality'/Abs' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant12'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndCurvature_1pm'
         *  Selector: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/Selector'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_AnyBndCurvature_1pm(8));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant22'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT1/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_LDWCurvatureSup_1pm()) {
        rtb_Switch_fs = DW_jcnctr_Unit_Delay_DSTATE_db + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_fs = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant21'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT1/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_LDWCurvatureNoSup_1pm()) {
        rtb_Switch_cy = DW_jcnctr_Unit_Delay1_DSTATE_n + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_cy = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant23'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant6'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/SRFLIPFLOP/Functionality'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWCurvatureSupDur_sec() <= rtb_Switch_fs) {
        rtb_DataTypeConversion_l3 = 1U;
    } else if (GET_P_JCNCTR_LDWCurvatureNoSupDur_sec() <= rtb_Switch_cy) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_l3 = 0U;
    } else {
        rtb_DataTypeConversion_l3 = DW_jcnctr_Unit_Delay2_DSTATE_bv;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_bv = rtb_DataTypeConversion_l3;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector ConcatenateIn2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate[1] = rtb_DataTypeConversion_l3;
    /* Abs: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Abs2/Functionality'/Abs' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant45'/Constant'
         *  Inport: '<Root>/S_LCFRCV_AnyBndCurvature_1pm'
         *  Selector: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/Selector1'
         */
    rtb_Abs_o = f32_abs_f32(GET_S_LCFRCV_AnyBndCurvature_1pm(9));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant47'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT6/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8'/Unit_Delay'
         */
    if (rtb_Abs_o > GET_P_JCNCTR_LDWCurvatureSup_1pm()) {
        rtb_Switch_e = DW_jcnctr_Unit_Delay_DSTATE_os + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_e = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant46'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT6/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8'/Unit_Delay1'
         */
    if (rtb_Abs_o < GET_P_JCNCTR_LDWCurvatureNoSup_1pm()) {
        rtb_Abs_o = DW_jcnctr_Unit_Delay1_DSTATE_e + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Abs_o = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant48'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant49'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWCurvatureSupDur_sec() <= rtb_Switch_e) {
        rtb_DataTypeConversion_l3 = 1U;
    } else if (GET_P_JCNCTR_LDWCurvatureNoSupDur_sec() <= rtb_Abs_o) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_l3 = 0U;
    } else {
        rtb_DataTypeConversion_l3 = DW_jcnctr_Unit_Delay2_DSTATE_ck;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_ck = rtb_DataTypeConversion_l3;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate[2] = rtb_DataTypeConversion_l3;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant29'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition13'/state_source'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Inport: '<Root>/S_LCFRCV_SysStateIACC_nu'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND16/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ44/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT2/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3'/Unit_Delay'
         */
    if ((rtb_Abs > GET_P_JCNCTR_LDWManualTrqSup_Nm()) && (((sint32) GET_S_LCFRCV_SysStateIACC_nu()) == ((sint32)((uint8) E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_SUSPEND)))) {
        rtb_Switch_p = DW_jcnctr_Unit_Delay_DSTATE_pb + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_p = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant30'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition13'/state_source'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Inport: '<Root>/S_LCFRCV_SysStateIACC_nu'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT2/Functionality'/LT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NEQ7/Functionality'/NE'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3'/Unit_Delay1'
         */
    if ((rtb_Abs < GET_P_JCNCTR_LDWManualTrqNoSup_Nm()) || (((sint32) GET_S_LCFRCV_SysStateIACC_nu()) != ((sint32)((uint8) E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_SUSPEND)))) {
        rtb_Abs = DW_jcnctr_Unit_Delay1_DSTATE_h1 + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Abs = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant31'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant32'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWManualTrqSupDur_sec() <= rtb_Switch_p) {
        rtb_DataTypeConversion_l3 = 1U;
    } else if (GET_P_JCNCTR_LDWManualTrqNoSupDur_sec() <= rtb_Abs) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_l3 = 0U;
    } else {
        rtb_DataTypeConversion_l3 = DW_jcnctr_Unit_Delay2_DSTATE_dn;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_dn = rtb_DataTypeConversion_l3;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate[3] = rtb_DataTypeConversion_l3;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant221'/Constant' */
    rtb_VectorConcatenate[4] = 0U;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant555'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT47/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32'/Unit_Delay'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() > GET_P_JCNCTR_LDWMaxLaneWidthSup_met()) {
        rtb_Switch_fz = DW_jcnctr_Unit_Delay_DSTATE_ov + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_fz = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant556'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT19/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() < GET_P_JCNCTR_LDWMaxLaneWidthNoSup_met()) {
        rtb_Switch_al5 = DW_jcnctr_Unit_Delay1_DSTATE_o4 + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_al5 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant241'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant386'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWMaxLaneWidthSupDur_sec() <= rtb_Switch_fz) {
        rtb_Switch_lnh = 1U;
    } else if (GET_P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec() <= rtb_Switch_al5) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_lnh = 0U;
    } else {
        rtb_Switch_lnh = DW_jcnctr_Unit_Delay2_DSTATE_mo;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32/SRFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant38'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT3/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5'/Unit_Delay'
         */
    if (GET_S_ABPLBP_LaneWidth_met() > GET_P_JCNCTR_LDWMaxLaneWidthSup_met()) {
        rtb_Switch_mg = DW_jcnctr_Unit_Delay_DSTATE_il + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_mg = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant8'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT3/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_LaneWidth_met() < GET_P_JCNCTR_LDWMaxLaneWidthNoSup_met()) {
        rtb_Switch_mv = DW_jcnctr_Unit_Delay1_DSTATE_nb + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_mv = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant33'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant34'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWMaxLaneWidthSupDur_sec() <= rtb_Switch_mg) {
        rtb_Switch_in = 1U;
    } else if (GET_P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec() <= rtb_Switch_mv) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_in = 0U;
    } else {
        rtb_Switch_in = DW_jcnctr_Unit_Delay2_DSTATE_n;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5/SRFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR72/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR72/Functionality'/OR'
         */
    rtb_VectorConcatenate[5] = (uint8)((((sint32)rtb_Switch_lnh) != 0) || (((sint32)rtb_Switch_in) != 0));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant559'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT33/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33'/Unit_Delay'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() < GET_P_JCNCTR_LDWMinLaneWidthSup_met()) {
        rtb_Switch_cz = DW_jcnctr_Unit_Delay_DSTATE_bs + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_cz = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant560'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CoupledLaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT48/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_CoupledLaneWidth_met() > GET_P_JCNCTR_LDWMinLaneWidthNoSup_met()) {
        rtb_Switch_gq = DW_jcnctr_Unit_Delay1_DSTATE_iv + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_gq = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant557'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant558'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWMinLaneWidthSupDur_sec() <= rtb_Switch_cz) {
        rtb_Switch_ib = 1U;
    } else if (GET_P_JCNCTR_LDWMinLaneWidthNoSupDur_sec() <= rtb_Switch_gq) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_ib = 0U;
    } else {
        rtb_Switch_ib = DW_jcnctr_Unit_Delay2_DSTATE_h1;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33/SRFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant40'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT5/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6'/Unit_Delay'
         */
    if (GET_S_ABPLBP_LaneWidth_met() < GET_P_JCNCTR_LDWMinLaneWidthSup_met()) {
        rtb_Switch_da = DW_jcnctr_Unit_Delay_DSTATE_bv + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_da = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant41'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT5/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6'/Unit_Delay1'
         */
    if (GET_S_ABPLBP_LaneWidth_met() > GET_P_JCNCTR_LDWMinLaneWidthNoSup_met()) {
        rtb_Switch_f4 = DW_jcnctr_Unit_Delay1_DSTATE_k + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_f4 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant39'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant10'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWMinLaneWidthSupDur_sec() <= rtb_Switch_da) {
        rtb_Switch_l2 = 1U;
    } else if (GET_P_JCNCTR_LDWMinLaneWidthNoSupDur_sec() <= rtb_Switch_f4) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_l2 = 0U;
    } else {
        rtb_Switch_l2 = DW_jcnctr_Unit_Delay2_DSTATE_gb;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6/SRFLIPFLOP/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR73/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR73/Functionality'/OR'
         */
    rtb_VectorConcatenate[6] = (uint8)((((sint32)rtb_Switch_ib) != 0) || (((sint32)rtb_Switch_l2) != 0));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant25'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant26'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ1/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2'/Unit_Delay'
         */
    if ((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) == 1) && (((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) == 1)) {
        rtb_Switch_g5 = DW_jcnctr_Unit_Delay_DSTATE_iv + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_g5 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant24'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant7'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnInvalidQu_btf'
         *  Inport: '<Root>/S_ABPLBP_RiLnInvalidQu_btf'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NEQ1/Functionality'/NE'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2'/Unit_Delay1'
         */
    if ((((sint32)GET_S_ABPLBP_LeLnInvalidQu_btf()) != 1) && (((sint32) GET_S_ABPLBP_RiLnInvalidQu_btf()) != 1)) {
        rtb_Switch_cf = DW_jcnctr_Unit_Delay1_DSTATE_ke + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_cf = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant27'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant28'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWBothLaneInvalidSupDur_sec() <= rtb_Switch_g5) {
        rtb_DataTypeConversion_l3 = 1U;
    } else if (GET_P_JCNCTR_LDWBothLaneValidNoSupDur_sec() <= rtb_Switch_cf) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_l3 = 0U;
    } else {
        rtb_DataTypeConversion_l3 = DW_jcnctr_Unit_Delay2_DSTATE_gn;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_gn = rtb_DataTypeConversion_l3;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate[7] = rtb_DataTypeConversion_l3;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant11'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlABS_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlESC_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ10/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ8/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ9/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7'/Unit_Delay'
         */
    if ((((((sint32)GET_S_LCFRCV_ActiveStCtrlABS_bool()) == 1) || (((sint32) GET_S_LCFRCV_ActiveStCtrlEBA_bool()) == 1)) || (((sint32) GET_S_LCFRCV_ActiveStCtrlTCS_bool()) == 1)) || (((sint32) GET_S_LCFRCV_ActiveStCtrlESC_bool()) == 1)) {
        rtb_Switch_o = DW_jcnctr_Unit_Delay_DSTATE_hy + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_o = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant43'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlABS_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlEBA_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlESC_bool'
         *  Inport: '<Root>/S_LCFRCV_ActiveStCtrlTCS_bool'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ11/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ12/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ13/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ3/Functionality'/EQ'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7'/Unit_Delay1'
         */
    if ((((0 == ((sint32)GET_S_LCFRCV_ActiveStCtrlABS_bool())) && (((sint32) GET_S_LCFRCV_ActiveStCtrlEBA_bool()) == 0)) && (((sint32) GET_S_LCFRCV_ActiveStCtrlTCS_bool()) == 0)) && (((sint32) GET_S_LCFRCV_ActiveStCtrlESC_bool()) == 0)) {
        rtb_Switch_at = DW_jcnctr_Unit_Delay1_DSTATE_dq + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_at = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant42'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant44'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWActiveStCtrSupTime_sec() <= rtb_Switch_o) {
        rtb_DataTypeConversion_l3 = 1U;
    } else if (GET_P_JCNCTR_LDWActiveStCtrNoSupTime_sec() <= rtb_Switch_at) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_l3 = 0U;
    } else {
        rtb_DataTypeConversion_l3 = DW_jcnctr_Unit_Delay2_DSTATE_me;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/SRFLIPFLOP/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_me = rtb_DataTypeConversion_l3;
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector ConcatenateIn9' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate[8] = rtb_DataTypeConversion_l3;
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/Constant'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant98'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant13'/Constant'
         *  Inport: '<Root>/S_LCFRCV_BrkPedlPressed_bool'
         *  Inport: '<Root>/S_LCFRCV_MainCylPressure_pa'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND13/Functionality'/AND'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ33/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/GT7/Functionality'/GT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9'/Unit_Delay'
         */
    if ((GET_S_LCFRCV_MainCylPressure_pa() > GET_P_JCNCTR_LDWMainCylPresSup_pa()) && (((sint32)GET_S_LCFRCV_BrkPedlPressed_bool()) == 1)) {
        rtb_Switch_gi = DW_jcnctr_Unit_Delay_DSTATE_c + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_gi = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/Switch/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/Constant2'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant52'/Constant'
         *  Inport: '<Root>/S_LCFRCV_MainCylPressure_pa'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/LT7/Functionality'/LT'
         *  Sum: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9'/Unit_Delay1'
         */
    if (GET_S_LCFRCV_MainCylPressure_pa() < GET_P_JCNCTR_LDWMainCylPresNoSup_pa()) {
        rtb_Switch_m3 = DW_jcnctr_Unit_Delay1_DSTATE_m + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_m3 = 0.0F;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/SRFLIPFLOP/Functionality'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant50'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant51'/Constant'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/LE1/Functionality'/LE'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9'/Unit_Delay2'
         */
    if (GET_P_JCNCTR_LDWMainCylPresSupDur_sec() <= rtb_Switch_gi) {
        rtb_DataTypeConversion_l3 = 1U;
    } else if (GET_P_JCNCTR_LDWMainCylPresNoSupDur_sec() <= rtb_Switch_m3) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_DataTypeConversion_l3 = 0U;
    } else {
        rtb_DataTypeConversion_l3 = DW_jcnctr_Unit_Delay2_DSTATE_pb;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/SRFLIPFLOP/Functionality'/Switch' */
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/ConcatBufferAtVector ConcatenateIn10' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    rtb_VectorConcatenate[9] = rtb_DataTypeConversion_l3;
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition1'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition2'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition3'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition4'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition5'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSMI_SysStateRDP_nu'
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ14/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ15/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ16/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ17/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ5/Functionality'/EQ'
         */
    rtb_VectorConcatenate[10] = (uint8)((((((((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((sint32) GET_S_DPRSMI_SysStateRDP_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)))) || (((sint32) GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32) GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((sint32) GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/from_data_definition41'/state_source'
         *  Inport: '<Root>/S_LCFRCV_SysStateIACC_nu'
         */
    rtb_VectorConcatenate[11] = (uint8)(((sint32)GET_S_LCFRCV_SysStateIACC_nu()) == ((sint32)((uint8)E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_ACTIVE)));
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant18'/Constant' */
    rtb_VectorConcatenate[12] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant19'/Constant' */
    rtb_VectorConcatenate[13] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant17'/Constant' */
    rtb_VectorConcatenate[14] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant20'/Constant' */
    rtb_VectorConcatenate[15] = 0U;
    /* S-Function (sfun_setbit): 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate[0];
                for (i1=0; i1 < 16; i1++) {
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
        rtb_sfun_setbit_n = temp;
    }
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant158'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[7] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant222'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[8] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant223'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[9] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant224'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[10] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant225'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[11] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant226'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[12] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant227'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[13] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant228'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[14] = 0U;
    /* Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant229'/Constant' */
    rtb_S_JCNCTR_PrjSpecQu_btf[15] = 0U;
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant160'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant161'/Constant'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ54/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND9/Functionality'/AND'
         */
    rtb_S_JCNCTR_PrjSpecQu_btf[0] = (uint8)(!((((sint32)rtb_sfun_setbit_n) & ((sint32)GET_P_JCNCTR_LDWCustom_btm())) == 0));
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant162'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant163'/Constant'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NOT1/Functionality'/NOT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ55/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND10/Functionality'/AND'
         */
    rtb_S_JCNCTR_PrjSpecQu_btf[1] = (uint8)(!((((sint32)rtb_sfun_setbit) & ((sint32)GET_P_JCNCTR_LKACustom_btm())) == 0));
    /* DataTypeConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant164'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant165'/Constant'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/NOT2/Functionality'/NOT'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/EQ56/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/AND11/Functionality'/AND'
         */
    rtb_S_JCNCTR_PrjSpecQu_btf[2] = (uint8)(!((((sint32)rtb_sfun_setbit_a) & ((sint32)GET_P_JCNCTR_ELKCustom_btm())) == 0));
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Constant157'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/from_data_definition82'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/from_data_definition83'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/from_data_definition84'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/from_data_definition85'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant238'/Constant'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnLeRDP_mps'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/OR26/Functionality'/OR'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/OR27/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/EQ105/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/EQ106/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/EQ107/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/EQ108/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/GT34/Functionality'/GT'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Switch2/Functionality'/Switch'
         */
    if ((((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG)))) {
        rtb_S_JCNCTR_PrjSpecQu_btf[3] = (uint8)(GET_S_DPRSIA_VelLatLnLeRDP_mps() > GET_P_JCNCTR_VelLatLeRDP_mps());
    } else if ((((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))) || (((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY)))) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant238'/Constant'
                 *  Inport: '<Root>/S_DPRSIA_VelLatReLeRDP_mps'
                 *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/GT35/Functionality'/GT'
                 */
        rtb_S_JCNCTR_PrjSpecQu_btf[3] = (uint8)(GET_S_DPRSIA_VelLatReLeRDP_mps() > GET_P_JCNCTR_VelLatLeRDP_mps());
    } else {
        rtb_S_JCNCTR_PrjSpecQu_btf[3] = 0U;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Constant158'/Constant'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/from_data_definition86'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/from_data_definition87'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/from_data_definition88'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/from_data_definition89'/state_source'
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant239'/Constant'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDP_mps'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/OR28/Functionality'/OR'
         *  Logic: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/OR29/Functionality'/OR'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/EQ109/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/EQ110/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/EQ111/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/EQ115/Functionality'/EQ'
         *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/LT32/Functionality'/LT'
         *  Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Switch4/Functionality'/Switch'
         */
    if ((((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32) GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG)))) {
        rtb_S_JCNCTR_PrjSpecQu_btf[4] = (uint8)(GET_S_DPRSIA_VelLatLnRiRDP_mps() < GET_P_JCNCTR_VelLatRiRDP_mps());
    } else if ((((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))) || (((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY)))) {
        /* Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant239'/Constant'
                 *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDP_mps'
                 *  RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/LT30/Functionality'/LT'
                 */
        rtb_S_JCNCTR_PrjSpecQu_btf[4] = (uint8)(GET_S_DPRSIA_VelLatReRiRDP_mps() < GET_P_JCNCTR_VelLatRiRDP_mps());
    } else {
        rtb_S_JCNCTR_PrjSpecQu_btf[4] = 0U;
    }
    /* End of Switch: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/GT33/Functionality'/GT' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant237'/Constant'
         *  Inport: '<Root>/S_LCRSIA_VelLatLeALCA_mps'
         */
    rtb_S_JCNCTR_PrjSpecQu_btf[5] = (uint8)(GET_S_LCRSIA_VelLatLeALCA_mps() > GET_P_JCNCTR_VelLatLeALCA_mps());
    /* RelationalOperator: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Subsystem3/LT31/Functionality'/LT' incorporates:
         *  Constant: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/Constant59'/Constant'
         *  Inport: '<Root>/S_LCRSIA_VelLatRiALCA_mps'
         */
    rtb_S_JCNCTR_PrjSpecQu_btf[6] = (uint8)(GET_S_LCRSIA_VelLatRiALCA_mps() < GET_P_JCNCTR_VelLatRiALCA_mps());
    /* S-Function (sfun_setbit): 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/set_bit3/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_S_JCNCTR_PrjSpecQu_btf[0];
                for (i1=0; i1 < 16; i1++) {
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
        rtb_sfun_setbit_j = temp;
    }
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/branch'/copy1' */
    SET_S_JCNCTR_PrjSpecQu_btf(rtb_sfun_setbit_j);
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/branch1'/copy1' */
    SET_S_JCNCTR_LDWPrjSpecQu_btf(rtb_sfun_setbit_n);
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/branch2'/copy1' */
    SET_S_JCNCTR_LKAPrjSpecQu_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/branch3'/copy1' */
    SET_S_JCNCTR_ELKPrjSpecQu_btf(rtb_sfun_setbit_a);
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem10'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE = rtb_Switch_ab;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_o = rtb_Switch_iy;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem11'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_g = rtb_Switch_eg4;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_g = rtb_Switch_ps;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem18'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_i = rtb_Switch_mk;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_oh = rtb_Switch_k2;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem13'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_d = rtb_Switch_gt;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_n = rtb_Switch_c;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_go = rtb_Switch_l3;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem35'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_i = rtb_Switch_gjt;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_i = rtb_Switch_mt;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_p = rtb_Switch_nq;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem15'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_f = rtb_Switch_ks;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_l = rtb_Switch_az;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_h = rtb_Switch_jd;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem16'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_l = rtb_Switch_h0;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_m = rtb_Switch_hph;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_pp = rtb_Switch_dc;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem36'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_d = rtb_Switch_i;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_f = rtb_Switch_d3;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem12'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_c = rtb_Switch_h;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_go = rtb_Switch_bh;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem17'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_f = rtb_Switch_jk;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_p = rtb_Switch_k;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem19'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_a = rtb_Switch_oi;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_mt = rtb_Switch_pm;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem38'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_o = rtb_Switch_a;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_ph = rtb_Switch_ko;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem20'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_hu = rtb_Switch_g;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_gn = rtb_Switch_fv;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem21'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_j = rtb_Switch_b;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_d = rtb_Switch_gw;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem28'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_p3 = rtb_Switch_m;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_b = rtb_Switch_g1;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem23'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_b = rtb_Switch_la;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_n4 = rtb_Switch_ci;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM'/Unit_Delay2' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_AccelPedalPos_nu'
         */
    DW_jcnctr_Unit_Delay2_DSTATE = GET_S_LCFRCV_AccelPedalPos_nu();
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem24'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_ge = rtb_Switch_l;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_ma = rtb_Switch_jvf;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_gf = rtb_Switch_f;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem25'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_o = rtb_Switch_bxr;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_h = rtb_Switch_a1;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_dc = rtb_Switch_kj;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem34'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_p = rtb_Switch_jf;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_pv = rtb_Switch_nqz;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_pa = rtb_Switch_mo;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem26'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_a = rtb_Switch_jo4;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_hh = rtb_Switch_gg0;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_hb = rtb_Switch_n1;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem37'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_c3 = rtb_Switch_ic;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_e = rtb_Switch_j;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem22'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_iu = rtb_Switch_ne;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_da = rtb_Switch_ng;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem27'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_dg = rtb_Switch_pu;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_oy = rtb_Switch_po;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_bf = rtb_Switch_hv;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem29/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_e = rtb_DataTypeConversion_it;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_oyh = rtb_Switch_kx;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_jz = rtb_Switch_n;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_db = rtb_Switch_fs;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem1'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_n = rtb_Switch_cy;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_os = rtb_Switch_e;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem8'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_e = rtb_Abs_o;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_pb = rtb_Switch_p;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem3'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_h1 = rtb_Abs;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_ov = rtb_Switch_fz;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_o4 = rtb_Switch_al5;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem32'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_mo = rtb_Switch_lnh;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_il = rtb_Switch_mg;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_nb = rtb_Switch_mv;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem5'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_n = rtb_Switch_in;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_bs = rtb_Switch_cz;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_iv = rtb_Switch_gq;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem33'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_h1 = rtb_Switch_ib;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_bv = rtb_Switch_da;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_k = rtb_Switch_f4;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem6'/Unit_Delay2' */
    DW_jcnctr_Unit_Delay2_DSTATE_gb = rtb_Switch_l2;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_iv = rtb_Switch_g5;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem2'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_ke = rtb_Switch_cf;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_hy = rtb_Switch_o;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem7'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_dq = rtb_Switch_at;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9'/Unit_Delay' */
    DW_jcnctr_Unit_Delay_DSTATE_c = rtb_Switch_gi;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9'/Unit_Delay1' */
    DW_jcnctr_Unit_Delay1_DSTATE_m = rtb_Switch_m3;
    /* Update for UnitDelay: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:JCNCTR/JCNCTR/JCNCTR_SenProcess/OPM/SubSystem9/SRFLIPFLOP/Functionality'/Signal Conversion'
         */
    DW_jcnctr_Unit_Delay2_DSTATE_pb = rtb_DataTypeConversion_l3;
}
#include "Pse_JCNCTR.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
