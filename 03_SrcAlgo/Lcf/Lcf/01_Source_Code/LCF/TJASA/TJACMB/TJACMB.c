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
 * File          : TJACMB
 * Generated on  : Fri 26.07.2019 at 09:15:41 (UTC+01:00)
 * MD5           : [3184760498   774817070  4161642723  2450785647 0](TJACMB)
 *
 * Purpose       : <Purpose>
 * Specification : <Specification>
 *
 * Environment information:
 * Processor     : 32 Bit generic
 * Platform      : EMS3
 * SDA version   : 10.0
 * Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,79,81,82
 * Add-ons       : -
 *
 * Version management information:
 * Filename      : $Workfile: $
 * Revision      : $Revision: 1.4 $
 * Author        : $Author: Nastasa, Elena (uidt4846) $
 * Date          : $Date: 2019/11/29 09:05:07CET $
 * Changes       :
 * $Log: TJACMB.c  $
 * Revision 1.4 2019/11/29 09:05:07CET Nastasa, Elena (uidt4846) 
 * Update LCF code for new auxCodeGen 4.1
 * Revision 1.4 2019/08/29 10:04:47CEST Werum, Gregor (uidq2175) 
 * Module test update according to findings (FCT_CMP_TJASA_1577, FCT_CMP_TJASA_2145)
 * Revision 1.9.1.16 2019/07/26 13:30:49CEST Werum, Gregor (uidq2175) 
 * Bugfix for mode toggling between OF and CMB_OF mode
 *
 *************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TJACMB.h"
#include "TJACMB_private.h"
#include "sda_sil_dummy.h"
#include "fusionKalmanFilter.h"
/* Specific Includes */
/* End of Specific Includes */
/* Private Definitions */
/* General Defines */
/* Named constants for Chart: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine'/CombinedModeStateMachine' */
#define IN_LaneCentering               ((uint8)1U)
#define IN_OF_Debug                    ((uint8)2U)
#define IN_ObjectFollowing             ((uint8)3U)
#define IN_Passive                     ((uint8)4U)
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
#define TJACMB_START_SEC_DATA_8
#include "TJACMB_MemMap.h"
static uint8 BI_tjacmb_CombinedMode_nu;
/* 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine'/CombinedModeStateMachine' */
static uint8 DW_tjacmb_Unit_Delay_DSTATE_gs;
static uint8 DW_tjacmb_Unit_Delay1_DSTATE_c;
static uint8 DW_tjacmb_Unit_Delay2_DSTATE_l;
static uint8 DW_tjacmb_Unit_Delay2_DSTATE_dm;
static uint8 DW_tjacmb_Unit_Delay_DSTATE_fr;
static uint8 DW_tjacmb_Unit_Delay1_DSTATE_k;
static uint8 DW_tjacmb_Unit_Delay1_DSTATE_ch;
static uint8 DW_tjacmb_Unit_Delay2_DSTATE_g;
static uint8 DW_tjacmb_Unit_Delay_DSTATE_p;
static uint8 DW_tjacmb_Unit_Delay1_DSTATE_i;
static uint8 DW_tjacmb_Unit_Delay2_DSTATE_b;
static uint8 DW_tjacmb_Unit_Delay2_DSTATE_j;
static uint8 DW_tjacmb_Unit_Delay_DSTATE_l;
static uint8 DW_tjacmb_Unit_Delay_DSTATE_fi;
static uint8 DW_tjacmb_Unit_Delay1_DSTATE_p;
static uint8 DW_tjacmb_Unit_Delay2_DSTATE_os;
static uint8 DW_tjacmb_Unit_Delay2_DSTATE_gn;
static uint8 DW_tjacmb_Unit_Delay4_DSTATE;
static uint8 DW_tjacmb_Unit_Delay1_DSTATE_ke;
static uint8 DW_tjacmb_Unit_Delay3_DSTATE;
static uint8 DW_tjacmb_Unit_Delay1_DSTATE_bhr;
static uint8 DW_tjacmb_Unit_Delay2_DSTATE_a;
static uint8 DW_tjacmb_is_active_c14_TJACMB_cg;
static uint8 DW_tjacmb_is_c14_TJACMB_cg;
#define TJACMB_STOP_SEC_DATA_8
#include "TJACMB_MemMap.h"
#define TJACMB_START_SEC_DATA_32
#include "TJACMB_MemMap.h"
static float32 DW_tjacmb_Unit_Delay1_DSTATE;
static float32 DW_tjacmb_Unit_Delay2_DSTATE;
static float32 DW_tjacmb_Unit_Delay2_DSTATE_d;
static float32 DW_tjacmb_Unit_Delay1_DSTATE_b;
static float32 DW_tjacmb_Unit_Delay_DSTATE;
static float32 DW_tjacmb_Unit_Delay_DSTATE_h;
static float32 DW_tjacmb_Unit_Delay2_DSTATE_e;
static float32 DW_tjacmb_Unit_Delay_DSTATE_g;
static float32 DW_tjacmb_Unit_Delay_DSTATE_d;
static float32 DW_tjacmb_Unit_Delay1_DSTATE_bv;
static float32 DW_tjacmb_Unit_Delay5_DSTATE;
static float32 DW_tjacmb_Unit_Delay2_DSTATE_f;
static float32 DW_tjacmb_Unit_Delay_2_DSTATE;
static float32 DW_tjacmb_Unit_Delay_3_DSTATE;
static float32 DW_tjacmb_Unit_Delay_4_DSTATE;
static float32 DW_tjacmb_Unit_Delay_5_DSTATE;
static float32 DW_tjacmb_Unit_Delay1_DSTATE_bh;
static float32 DW_tjacmb_Unit_Delay5_DSTATE_k;
static float32 DW_tjacmb_Unit_Delay1_DSTATE_m;
static float32 DW_tjacmb_Unit_Delay2_DSTATE_o;
static float32 DW_tjacmb_Unit_Delay_DSTATE_f;
#define TJACMB_STOP_SEC_DATA_32
#include "TJACMB_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TJACMB/TJACMB'/TJACMB_SenReset'
 * Block description for: 'sda:TJACMB/TJACMB'/TJACMB_SenReset'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TJACMB_SenReset
#include "Pse_TJACMB.h"
/* Short description:  */
void TJACMB_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant'/Constant' */
    SET_S_TJACMB_StrongReady_bool(0U);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant1'/Constant' */
    SET_S_TJACMB_WeakReady_bool(0U);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant11'/Constant' */
    SET_D_TJACMB_CombinedInvalid_btf(0U);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant12'/Constant' */
    SET_S_TJACMB_CombinedMode_nu(0U);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant13'/Constant' */
    SET_D_TJACMB_TransitionInvalid_btf(0U);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant18'/Constant' */
    //ElNa, SET_S_TJACMB_KalmanLePosY0_met(0.0F);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant19'/Constant' */
    //ElNa, SET_S_TJACMB_KalmanRiPosY0_met(0.0F);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant2'/Constant' */
    SET_S_TJACMB_Cancel_bool(0U);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant3'/Constant' */
    SET_S_TJACMB_CombinedPosX0_met(0.0F);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant4'/Constant' */
    SET_S_TJACMB_CombinedPosY0_met(0.0F);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant5'/Constant' */
    SET_S_TJACMB_CombinedHeading_rad(0.0F);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant6'/Constant' */
    SET_S_TJACMB_CombinedCrv_1pm(0.0F);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant7'/Constant' */
    SET_S_TJACMB_CombinedCrvChng_1pm2(0.0F);
    /* Constant: 'sda:TJACMB/TJACMB/TJACMB_SenReset/Constant8'/Constant' */
    SET_S_TJACMB_CombinedLength_met(0.0F);
}
#include "Pse_TJACMB.h"
/*
 * Output and update for function-call system: 'sda:TJACMB/TJACMB'/TJACMB_SenProcess'
 * Block description for: 'sda:TJACMB/TJACMB'/TJACMB_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TJACMB_SenProcess
#include "Pse_TJACMB.h"
/* Short description:  */
void TJACMB_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    fusionKFInput rtb_TJA_FusionKalmanIn;
    fusionKFOutput rtb_sfun_fusionKalman;
    uint16 rtb_sfun_setbit;
    uint16 rtb_sfun_setbit_k;
    uint8 rtb_VectorConcatenate[16];
    uint8 rtb_VectorConcatenate_m[16];
    uint8 rtb_DataTypeConversion_mh;
    uint8 rtb_DataTypeConversion;
    float32 rtb_Switch;
    uint8 rtb_Switch3_o;
    uint8 rtb_Switch3_j;
    uint8 rtb_DataTypeConversion_fj;
    uint8 rtb_DataTypeConversion_m;
    uint8 rtb_DataTypeConversion_jw;
    uint8 rtb_DataTypeConversion_mn;
    uint8 rtb_Unit_Delay1_b;
    uint8 rtb_EQ_o;
    uint8 rtb_DataTypeConversion_n5;
    uint8 rtb_LogicalOperator_m0;
    uint8 rtb_DataTypeConversion_ok;
    uint8 rtb_Switch3_c;
    uint8 rtb_DataTypeConversion_m2;
    uint8 rtb_DataTypeConversion_mx;
    uint8 rtb_DataTypeConversion_c;
    uint8 rtb_Switch3_kd;
    uint8 rtb_Switch3_g;
    uint8 rtb_LogicalOperator_l;
    uint8 rtb_Switch3_e;
    uint8 rtb_DataTypeConversion_di;
    uint8 rtb_Switch3_ci;
    uint8 rtb_EQ_bg;
    uint8 rtb_DataTypeConversion_dk;
    uint8 rtb_DataTypeConversion_df;
    uint8 rtb_Switch3_lw;
    uint8 rtb_GT_m;
    uint8 rtb_DataTypeConversion_el;
    uint8 rtb_DataTypeConversion_hl;
    uint8 rtb_DataTypeConversion_bb;
    uint8 rtb_EQ_nj;
    uint8 rtb_DataTypeConversion_hf;
    uint8 rtb_EQ_ah;
    uint8 rtb_DataTypeConversion_lj;
    uint8 rtb_DataTypeConversion_o;
    float32 rtb_Switch_es1;
    uint8 rtb_DataTypeConversion_g;
    float32 rtb_Min_jl;
    float32 rtb_Switch_n1;
    float32 rtb_Sign;
    uint8 rtb_Switch_dc;
    uint8 rtb_Switch_l;
    uint8 rtb_Switch_f;
    uint8 rtb_NE_ck;
    float32 rtb_Sign_g;
    float32 rtb_Min_a;
    float32 rtb_Min_c;
    float32 rtb_Switch3;
    float32 rtb_Sum_mk;
    uint8 rtb_Switch_eb;
    float32 rtb_Switch_k3;
    uint8 rtb_Switch_k;
    float32 rtb_Multiport_Switch1;
    float32 rtb_Switch_hn;
    uint8 LogicalOperator_d;
    uint8 LogicalOperator_h;
    uint8 LogicalOperator_m;
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/LateralControlModeValidity/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_TJALKA_Cancel_bool'
         *  Inport: '<Root>/S_TJAOBF_Cancel_bool'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/LateralControlModeValidity/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/LateralControlModeValidity/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/LateralControlModeValidity/Relational Operator2/Functionality'/EQ'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/LateralControlModeValidity'/Unit_Delay'
         */
    rtb_DataTypeConversion = (uint8)(((((sint32)GET_S_TJALKA_Cancel_bool()) != 0) || (((sint32)GET_S_TJAOBF_Cancel_bool()) != 0)) || ((((sint32) GET_S_TJASTM_LatCtrlMode_nu()) != ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) && (((sint32) DW_tjacmb_Unit_Delay_DSTATE_gs) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant10'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant2'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant4'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant6'/Constant'
         *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Min/Functionality'/Min'
         */
    if (((sint32)GET_P_TJACMB_IndVelLimitsEnable_bool()) != 0) {
        rtb_Switch = GET_P_TJACMB_VelXMax_kph();
    } else {
        rtb_Switch = f32_min_f32_f32(GET_P_TJAOBF_VelXMax_kph(), GET_P_TJALKA_VelXMax_kph());
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS1/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Sum1/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck'/Unit_Delay1'
         */
    if (GET_S_LCFRCV_VDy_VehVelocity_kph() > (rtb_Switch + GET_P_TJALKA_VelXHyst_kph())) {
        rtb_Switch3_o = 1U;
    } else if (GET_S_LCFRCV_VDy_VehVelocity_kph() < rtb_Switch) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_o = 0U;
    } else {
        rtb_Switch3_o = DW_tjacmb_Unit_Delay1_DSTATE_c;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS1/Functionality'/Switch3' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant7'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant8'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant9'/Constant'
         *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Max/Functionality'/Max'
         */
    if (((sint32)GET_P_TJACMB_IndVelLimitsEnable_bool()) != 0) {
        rtb_Switch = GET_P_TJACMB_VelXMin_kph();
    } else {
        rtb_Switch = f32_max_f32_f32(GET_P_TJAOBF_VelXMin_kph(), GET_P_TJALKA_VelXMin_kph());
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Constant5'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/Sum2/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck'/Unit_Delay2'
         */
    if (GET_S_LCFRCV_VDy_VehVelocity_kph() > rtb_Switch) {
        rtb_Switch3_j = 1U;
    } else if (GET_S_LCFRCV_VDy_VehVelocity_kph() < (rtb_Switch - GET_P_TJALKA_VelXHyst_kph())) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3_j = 0U;
    } else {
        rtb_Switch3_j = DW_tjacmb_Unit_Delay2_DSTATE_l;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/HYSTERESIS2/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck/NOT1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_mh = (uint8)((!(((sint32)rtb_Switch3_o) != 0)) && (((sint32)rtb_Switch3_j) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/ConstructionSite/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/ConstructionSite/Constant1'/Constant'
         *  Inport: '<Root>/S_ABPLBP_ConstructionSite_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/ConstructionSite/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/ConstructionSite/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_fj = (uint8)(!((((sint32) GET_S_ABPLBP_ConstructionSite_bool()) != 0) && (((sint32) GET_P_TJACMB_ConstSiteCheckOn_bool()) != 0)));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/Constant2'/Constant'
         *  Inport: '<Root>/S_TJAGEN_LKAOnlySwitch_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/AND2/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT9/Functionality'/NOT'
         */
    rtb_DataTypeConversion_m = (uint8)((((sint32)GET_P_TJACMB_CMB_Enabled_bool()) != 0) && (!(((sint32)GET_S_TJAGEN_LKAOnlySwitch_bool()) != 0)));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/SystemStateValidity/from_data_definition1'/state_source'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/SystemStateValidity/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/SystemStateValidity/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/SystemStateValidity/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/SystemStateValidity/Relational Operator2/Functionality'/EQ'
         */
    rtb_DataTypeConversion_mn = (uint8)((((((sint32)rtb_DataTypeConversion_mh) != 0) && (((sint32)rtb_DataTypeConversion_fj) != 0)) && (((sint32) rtb_DataTypeConversion_m) != 0)) && ((((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)))));
    /* RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/from_data_definition3'/state_source'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB'/Unit_Delay1'
         */
    rtb_EQ_o = (uint8)(((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_PASSIVE)));
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising'/Unit_Delay2'
         */
    LogicalOperator_d = (uint8)((!(((sint32)DW_tjacmb_Unit_Delay2_DSTATE_dm) != 0)) && (((sint32)rtb_EQ_o) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck'/Unit_Delay1'
         */
    rtb_DataTypeConversion_n5 = (uint8)(!((((sint32)LogicalOperator_d) != 0) || (DW_tjacmb_Unit_Delay1_DSTATE > 0.0F)));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/Application Parameter1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/Application Parameter2'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/HYSTERESIS/Functionality'/Constant1'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthLength_met'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/Sum/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck'/Unit_Delay'
         */
    if (GET_S_ABPLBP_CntrLnClthLength_met() > GET_P_TJACMB_MinLnLengthLC_met()) {
        rtb_Switch3_c = 1U;
    } else if (GET_S_ABPLBP_CntrLnClthLength_met() < (GET_P_TJACMB_MinLnLengthLC_met() - GET_P_TJACMB_MinLnLengthHystLC_met())) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3_c = 0U;
    } else {
        rtb_Switch3_c = DW_tjacmb_Unit_Delay_DSTATE_fr;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck/HYSTERESIS/Functionality'/Switch3' */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/Constant4'/Constant'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection'/Unit_Delay1'
         */
    LogicalOperator_h = (uint8)((!(((sint32)DW_tjacmb_Unit_Delay1_DSTATE_k) != 0)) && (((sint32)GET_P_TJACMB_InjectLaneError_bool()) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/Constant1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/OR/Functionality'/OR'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection'/Unit_Delay2'
         */
    rtb_LogicalOperator_m0 = (uint8)(((((sint32)LogicalOperator_h) != 0) || (DW_tjacmb_Unit_Delay2_DSTATE > 0.0F)) || (((sint32) GET_P_TJACMB_SetLaneCondInvalid_bool()) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT3/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ok = (uint8)(!(((sint32)rtb_LogicalOperator_m0) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_TJALKA_CombinedLaneSR_bool'
         *  Inport: '<Root>/S_TJALKA_StrongReady_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/AND1/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/AND3/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT4/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_mx = (uint8)(((!(((sint32) GET_P_TJACMB_OF_Enabled_bool()) != 0)) && (((sint32) GET_S_TJALKA_StrongReady_bool()) != 0)) || (((((((sint32) GET_S_TJALKA_StrongReady_bool()) != 0) && (((sint32) GET_P_TJACMB_OF_Enabled_bool()) != 0)) && (((sint32) GET_S_TJALKA_CombinedLaneSR_bool()) != 0)) && (((sint32)rtb_Switch3_c) != 0)) && (((sint32)rtb_DataTypeConversion_ok) != 0)));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_TJALKA_CombinedLaneWR_bool'
         *  Inport: '<Root>/S_TJALKA_WeakReady_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/AND2/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_c = (uint8)(((!(((sint32)GET_P_TJACMB_OF_Enabled_bool ()) != 0)) && (((sint32)GET_S_TJALKA_WeakReady_bool()) != 0)) || (((((sint32) GET_S_TJALKA_WeakReady_bool()) != 0) && (((sint32) GET_P_TJACMB_OF_Enabled_bool()) != 0)) && (((sint32) GET_S_TJALKA_CombinedLaneWR_bool()) != 0)));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/Constant1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/Constant4'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS1/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/Sum1/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck'/Unit_Delay1'
         */
    if (GET_S_LCFRCV_VDy_VehVelocity_kph() > (GET_P_TJACMB_VelXMaxOF_kph() + GET_P_TJALKA_VelXHyst_kph())) {
        rtb_Switch3_kd = 1U;
    } else if (GET_S_LCFRCV_VDy_VehVelocity_kph() < GET_P_TJACMB_VelXMaxOF_kph()) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_kd = 0U;
    } else {
        rtb_Switch3_kd = DW_tjacmb_Unit_Delay1_DSTATE_ch;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS1/Functionality'/Switch3' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS2/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/Constant3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/Constant5'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS2/Functionality'/Constant1'
         *  Inport: '<Root>/S_LCFRCV_VDy_VehVelocity_kph'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS2/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS2/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/Sum2/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS2/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck'/Unit_Delay2'
         */
    if (GET_S_LCFRCV_VDy_VehVelocity_kph() > GET_P_TJAOBF_VelXMinOF_kph()) {
        rtb_Switch3_g = 1U;
    } else if (GET_S_LCFRCV_VDy_VehVelocity_kph() < (GET_P_TJAOBF_VelXMinOF_kph() - GET_P_TJALKA_VelXHyst_kph())) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS2/Functionality'/Constant'
                 */
        rtb_Switch3_g = 0U;
    } else {
        rtb_Switch3_g = DW_tjacmb_Unit_Delay2_DSTATE_g;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/HYSTERESIS2/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck/NOT1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_m2 = (uint8)((!(((sint32)rtb_Switch3_kd) != 0)) && (((sint32)rtb_Switch3_g) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/Constant1'/Constant'
         *  Inport: '<Root>/S_TJAOBF_ObjInLaneValid_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_jw = (uint8)((((sint32) GET_S_TJAOBF_ObjInLaneValid_bool()) != 0) || (!(((sint32) GET_P_TJACMB_LaneCheckEnabled_bool()) != 0)));
    /* Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity'/Unit_Delay2'
         */
    rtb_LogicalOperator_l = (uint8)((DW_tjacmb_Unit_Delay2_DSTATE_d <= 0.0F) && (((sint32)rtb_DataTypeConversion_jw) != 0));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/Application Parameter2'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/Application Parameter3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS/Functionality'/Constant1'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/Sum/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity'/Unit_Delay'
         */
    if (GET_S_ODPFOP_AccObjPosX_met() > GET_P_TJACMB_ObjMinPosXOF_met()) {
        rtb_Switch3_ci = 1U;
    } else if (GET_S_ODPFOP_AccObjPosX_met() < (GET_P_TJACMB_ObjMinPosXOF_met() - GET_P_TJACMB_ObjHystPosXOF_met())) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3_ci = 0U;
    } else {
        rtb_Switch3_ci = DW_tjacmb_Unit_Delay_DSTATE_p;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS/Functionality'/Switch3' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS1/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/Application Parameter1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/Application Parameter4'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS1/Functionality'/Constant1'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS1/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS1/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/Sum1/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity'/Unit_Delay1'
         */
    if (GET_S_ODPFOP_AccObjPosX_met() > (GET_P_TJACMB_ObjMaxPosXOF_met() + GET_P_TJACMB_ObjHystPosXOF_met())) {
        rtb_Switch3_e = 1U;
    } else if (GET_S_ODPFOP_AccObjPosX_met() < GET_P_TJACMB_ObjMaxPosXOF_met()) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS1/Functionality'/Constant'
                 */
        rtb_Switch3_e = 0U;
    } else {
        rtb_Switch3_e = DW_tjacmb_Unit_Delay1_DSTATE_i;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/HYSTERESIS1/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_di = (uint8)((((sint32)rtb_Switch3_ci) != 0) && (!(((sint32)rtb_Switch3_e) != 0)));
    /* RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/from_data_definition3'/state_source'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB'/Unit_Delay1'
         */
    rtb_EQ_bg = (uint8)(((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF)));
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising'/Unit_Delay2'
         */
    LogicalOperator_m = (uint8)((!(((sint32)DW_tjacmb_Unit_Delay2_DSTATE_b) != 0)) && (((sint32)rtb_EQ_bg) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/Application Parameter2'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/Application Parameter1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_TJAOBF_AccObjValid_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/AND2/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/OR/Functionality'/OR'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck'/Unit_Delay1'
         */
    rtb_DataTypeConversion_df = (uint8)((((((((sint32)rtb_DataTypeConversion_m2) != 0) && (((sint32)GET_S_TJAOBF_AccObjValid_bool()) != 0)) && (((sint32) rtb_LogicalOperator_l) != 0)) && (((sint32)rtb_DataTypeConversion_di) != 0)) && (((sint32)GET_P_TJACMB_OF_Enabled_bool()) != 0)) && (((!(((sint32) GET_P_TJACMB_MaxTimeObjCtrlOn_bool()) != 0)) || (!(((sint32)rtb_EQ_bg) != 0))) || ((((sint32)LogicalOperator_m) != 0) || (DW_tjacmb_Unit_Delay1_DSTATE_b > 0.0F))));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/HYSTERESIS/Functionality'/Switch3' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/Application Parameter3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/Application Parameter4'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/HYSTERESIS/Functionality'/Constant1'
         *  Inport: '<Root>/S_ABPLBP_StraightPathDtct_nu'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/HYSTERESIS/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/HYSTERESIS/Functionality'/Relational Operator1'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/Sum/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/HYSTERESIS/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck'/Unit_Delay2'
         */
    if (((sint32)GET_S_ABPLBP_StraightPathDtct_nu()) > ((sint32)u8_u32(((uint32) GET_P_TJACMB_LnCurveMaxPerc_perc()) + ((uint32)((sint32) GET_P_TJACMB_LnCurveMaxPercHyst_perc()))))) {
        rtb_Switch3_lw = 1U;
    } else if (((sint32)GET_S_ABPLBP_StraightPathDtct_nu()) < ((sint32) GET_P_TJACMB_LnCurveMaxPerc_perc())) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/HYSTERESIS/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/HYSTERESIS/Functionality'/Constant'
                 */
        rtb_Switch3_lw = 0U;
    } else {
        rtb_Switch3_lw = DW_tjacmb_Unit_Delay2_DSTATE_j;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/HYSTERESIS/Functionality'/Switch3' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/Application Parameter2'/Constant'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_dk = (uint8)(((((sint32)rtb_LogicalOperator_m0) != 0) || (!(((sint32)GET_P_TJACMB_LnCurveDtctEnable_bool()) != 0))) || (!(((sint32) rtb_Switch3_lw) != 0)));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/from_data_definition3'/state_source'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/EQ/Functionality'/EQ'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB'/Unit_Delay'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB'/Unit_Delay1'
         */
    rtb_Unit_Delay1_b = (uint8)((((sint32)DW_tjacmb_Unit_Delay_DSTATE_l) != 0) && (((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_LC))));
    /* Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState'/Unit_Delay'
         */
    rtb_LogicalOperator_m0 = (uint8)((DW_tjacmb_Unit_Delay_DSTATE <= 0.0F) && (((sint32)rtb_Unit_Delay1_b) != 0));
    /* RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_ODPFOH_ObjTraceStraight_perc'
         */
    rtb_GT_m = (uint8)(((sint32)GET_S_ODPFOH_ObjTraceStraight_perc()) > ((sint32) GET_P_TJACMB_MinObjStraightProb_perc()));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_TJAOBF_Cancel_bool'
         *  Inport: '<Root>/S_TJAOBF_StrongReady_bool'
         *  Inport: '<Root>/S_TJAOBF_WeakReady_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/AND1/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority'/Unit_Delay'
         */
    rtb_DataTypeConversion_el = (uint8)(!(((DW_tjacmb_Unit_Delay_DSTATE_h <= 0.0F) && (((sint32)rtb_GT_m) != 0)) && (((((sint32)GET_S_TJAOBF_StrongReady_bool()) != 0) && (((sint32)GET_S_TJAOBF_WeakReady_bool()) != 0)) && (!(((sint32) GET_S_TJAOBF_Cancel_bool()) != 0)))));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_hl = (uint8)(((((sint32)rtb_DataTypeConversion_dk) != 0) && (((sint32)rtb_LogicalOperator_m0) != 0)) && (((sint32) rtb_DataTypeConversion_el) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_TJAOBF_AccObjValid_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion_bb = (uint8)(((((((sint32)rtb_DataTypeConversion_di) != 0) && (((sint32)rtb_LogicalOperator_l) != 0)) && (((sint32) GET_S_TJAOBF_AccObjValid_bool()) != 0)) && (((sint32) rtb_DataTypeConversion_m2) != 0)) && (((sint32)GET_P_TJACMB_OF_Debug_bool()) != 0));
    /* Chart: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine'/CombinedModeStateMachine' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/from_data_definition12'/state_source'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/from_data_definition3'/state_source'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/from_data_definition4'/state_source'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_TJAOBF_StrongReady_bool'
         *  Inport: '<Root>/S_TJAOBF_WeakReady_bool'
         *
         * Block description for 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine'/CombinedModeStateMachine':
         *  X.2.1.1.4
         */
    /* Gateway: TJACMB_cg/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine */
    /* During: TJACMB_cg/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine */
    if (((uint32)((sint32)DW_tjacmb_is_active_c14_TJACMB_cg)) == 0U) {
        /* Entry: TJACMB_cg/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine */
        DW_tjacmb_is_active_c14_TJACMB_cg = 1U;
        /* Entry Internal: TJACMB_cg/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine */
        /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':530' */
        DW_tjacmb_is_c14_TJACMB_cg = IN_Passive;
        /* Entry 'Passive': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':1' */
        BI_tjacmb_CombinedMode_nu = ((uint8)E_TJACMB_CombModeType_E_TJACMB_CMBMD_PASSIVE);
    } else {
        switch (DW_tjacmb_is_c14_TJACMB_cg) {
        case IN_LaneCentering:
            /* During 'LaneCentering': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':576' */
            if (((sint32)rtb_DataTypeConversion_bb) != 0) {
                /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':588' */
                DW_tjacmb_is_c14_TJACMB_cg = IN_OF_Debug;
                /* Entry 'OF_Debug': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':584' */
                BI_tjacmb_CombinedMode_nu = ((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF_DEBUG);
            } else if (((!(((sint32)rtb_DataTypeConversion_mx) != 0)) && (((sint32) rtb_DataTypeConversion_df) != 0)) && (((sint32) rtb_DataTypeConversion_hl) != 0)) {
                /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':575' */
                DW_tjacmb_is_c14_TJACMB_cg = IN_ObjectFollowing;
                /* Entry 'ObjectFollowing': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':577' */
                BI_tjacmb_CombinedMode_nu = ((uint8)E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF);
            } else {
                if ((((((sint32)rtb_DataTypeConversion) != 0) || (!(((sint32) rtb_DataTypeConversion_mn) != 0))) || (!(((sint32) rtb_DataTypeConversion_mx) != 0))) || ((!(((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0)) && (!(((sint32) rtb_DataTypeConversion_df) != 0)))) {
                    /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':578' */
                    DW_tjacmb_is_c14_TJACMB_cg = IN_Passive;
                    /* Entry 'Passive': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':1' */
                    BI_tjacmb_CombinedMode_nu = ((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_PASSIVE);
                }
            }
            break;
        case IN_OF_Debug:
            /* During 'OF_Debug': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':584' */
            if ((!(((sint32)rtb_DataTypeConversion_bb) != 0)) || (((sint32) rtb_DataTypeConversion) != 0)) {
                /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':586' */
                DW_tjacmb_is_c14_TJACMB_cg = IN_Passive;
                /* Entry 'Passive': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':1' */
                BI_tjacmb_CombinedMode_nu = ((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_PASSIVE);
            }
            break;
        case IN_ObjectFollowing:
            /* During 'ObjectFollowing': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':577' */
            if (((sint32)rtb_DataTypeConversion_bb) != 0) {
                /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':589' */
                DW_tjacmb_is_c14_TJACMB_cg = IN_OF_Debug;
                /* Entry 'OF_Debug': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':584' */
                BI_tjacmb_CombinedMode_nu = ((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF_DEBUG);
            } else if ((((sint32)rtb_DataTypeConversion_c) != 0) && (((sint32) rtb_DataTypeConversion_mx) != 0)) {
                /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':580' */
                DW_tjacmb_is_c14_TJACMB_cg = IN_LaneCentering;
                /* Entry 'LaneCentering': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':576' */
                BI_tjacmb_CombinedMode_nu = ((uint8)E_TJACMB_CombModeType_E_TJACMB_CMBMD_LC);
            } else {
                if (((((sint32)rtb_DataTypeConversion) != 0) || (!(((sint32) rtb_DataTypeConversion_mn) != 0))) || (!(((sint32) rtb_DataTypeConversion_df) != 0))) {
                    /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':574' */
                    DW_tjacmb_is_c14_TJACMB_cg = IN_Passive;
                    /* Entry 'Passive': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':1' */
                    BI_tjacmb_CombinedMode_nu = ((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_PASSIVE);
                }
            }
            break;
        default:
            /* During 'Passive': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':1' */
            if (((sint32)rtb_DataTypeConversion_bb) != 0) {
                /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':585' */
                DW_tjacmb_is_c14_TJACMB_cg = IN_OF_Debug;
                /* Entry 'OF_Debug': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':584' */
                BI_tjacmb_CombinedMode_nu = ((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF_DEBUG);
            } else {
                if (((((((sint32)rtb_DataTypeConversion_mn) != 0) && (((sint32) rtb_DataTypeConversion_n5) != 0)) && (((sint32) rtb_DataTypeConversion_mx) != 0)) && (((sint32) rtb_DataTypeConversion_c) != 0)) && (((((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0) && (((sint32) GET_S_TJAOBF_WeakReady_bool()) != 0)) || (((sint32) rtb_DataTypeConversion_df) != 0))) {
                    /* Transition: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':566' */
                    DW_tjacmb_is_c14_TJACMB_cg = IN_LaneCentering;
                    /* Entry 'LaneCentering': 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/CombinedModeStateMachine':576' */
                    BI_tjacmb_CombinedMode_nu = ((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_LC);
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine'/CombinedModeStateMachine' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Subsystem1/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Subsystem1/from_data_definition1'/state_source'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Subsystem1/from_data_definition3'/state_source'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Subsystem1/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Subsystem1/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Subsystem1/EQ2/Functionality'/EQ'
         */
    rtb_DataTypeConversion_bb = (uint8)((((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8)E_TJACMB_CombModeType_E_TJACMB_CMBMD_LC))) || (((sint32) BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF_DEBUG))));
    /* RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Subsystem1/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Subsystem1/from_data_definition4'/state_source'
         */
    rtb_EQ_nj = (uint8)(((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF)));
    /* RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/from_data_definition1'/state_source'
         */
    rtb_DataTypeConversion_hf = (uint8)(((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8)E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF_DEBUG)));
    /* RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/from_data_definition1'/state_source'
         */
    rtb_EQ_ah = (uint8)(((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_LC)));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Constant3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Constant4'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Constant6'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Switch3/Functionality'/Switch'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Switch5/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_hf) != 0) {
        rtb_Min_a = 0.0F;
        rtb_Min_c = 0.0F;
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/Constant7'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Constant3'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Constant4'/Constant'
                 *  Inport: '<Root>/S_TJAOBF_ObjectCrv_1pm'
                 */
        if (((sint32)GET_P_TJACMB_UseInterCmbCrvCalc_bool()) != 0) {
            /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/from_data_definition2'/state_source'
                         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/from_data_definition3'/state_source'
                         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Application Parameter1'/Constant'
                         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Constant'/Constant'
                         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Constant1'/Constant'
                         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
                         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/OR/Functionality'/OR'
                         *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Max/Functionality'/Max'
                         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Div/Functionality/Div'/Div'
                         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Mul/Functionality'/Mul'
                         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Mul1/Functionality'/Mul'
                         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/EQ1/Functionality'/EQ'
                         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/EQ2/Functionality'/EQ'
                         */
            if (((((sint32)rtb_EQ_ah) != 0) || (((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8)E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF)))) || (((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF_DEBUG)))) {
                rtb_Switch_hn = (2.0F * GET_S_ODPFOP_AccObjPosY_met()) / f32_max_f32_f32 (GET_S_ODPFOP_AccObjPosX_met() * GET_S_ODPFOP_AccObjPosX_met(), GET_P_LCF_AlmostZero_nu());
            } else {
                rtb_Switch_hn = 0.0F;
            }
            /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv/Switch/Functionality'/Switch' */
        } else {
            rtb_Switch_hn = GET_S_TJAOBF_ObjectCrv_1pm();
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/Switch6/Functionality'/Switch' */
        rtb_Switch = 0.0F;
    } else {
        rtb_Min_a = GET_S_ABPLBP_CntrLnClthPosY0_met();
        rtb_Min_c = GET_S_ABPLBP_CntrLnClthHeading_rad();
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/Constant7'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Constant1'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Constant2'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Constant5'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem/Constant1'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem1/Constant1'/Constant'
                 *  Inport: '<Root>/S_ABPLBP_CntrLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_CntrLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_CntrLnClthHeading_rad'
                 *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
                 *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/NOT/Functionality'/NOT'
                 *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem1/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem1/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem1/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Subsystem1/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Switch1/Functionality'/Switch'
                 */
        if (!(((sint32)GET_P_TJACMB_CombinedCrvEnable_bool()) != 0)) {
            rtb_Switch_hn = GET_S_ABPLBP_CntrLnClthCrv_1pm();
            rtb_Switch = GET_S_ABPLBP_CntrLnClthCrvChng_1pm2();
        } else {
            if (((sint32)GET_P_TJACMB_UseInterCmbCrvCalc_bool()) != 0) {
                /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Switch/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Application Parameter1'/Constant'
                                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Constant'/Constant'
                                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Constant1'/Constant'
                                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                                 *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
                                 *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Max/Functionality'/Max'
                                 *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Div/Functionality/Div'/Div'
                                 *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Mul/Functionality'/Mul'
                                 *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Mul1/Functionality'/Mul'
                                 *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Mul2/Functionality'/Mul'
                                 *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Sum/Functionality'/Sum'
                                 *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Sum1/Functionality'/Sum'
                                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/Switch7/Functionality'/Switch'
                                 *  Trigonometry: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Trigonom/Functionality'/Trigonometric Function'
                                 */
                if (((sint32)rtb_EQ_ah) != 0) {
                    rtb_Switch = (((GET_S_ODPFOP_AccObjPosY_met() - GET_S_ABPLBP_CntrLnClthPosY0_met()) - (f32_tan_f32 (GET_S_ABPLBP_CntrLnClthHeading_rad()) * GET_S_ODPFOP_AccObjPosX_met ())) * 2.0F) / f32_max_f32_f32(GET_S_ODPFOP_AccObjPosX_met() * GET_S_ODPFOP_AccObjPosX_met(), GET_P_LCF_AlmostZero_nu());
                } else {
                    rtb_Switch = 0.0F;
                }
                /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/GetAccObjCrv1/Switch/Functionality'/Switch' */
            } else {
                /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CalculateObjectCurvatures/Switch7/Functionality'/Switch' incorporates:
                                 *  Inport: '<Root>/S_TJAOBF_CombObjectCrv_1pm'
                                 */
                rtb_Switch = GET_S_TJAOBF_CombObjectCrv_1pm();
            }
            rtb_Switch_hn = ((1.0F - GET_P_TJACMB_CombinedCrvObjWeight_nu()) * GET_S_ABPLBP_CntrLnClthCrv_1pm()) + (GET_P_TJACMB_CombinedCrvObjWeight_nu() * rtb_Switch);
            rtb_Switch = ((1.0F - GET_P_TJACMB_CombinedCrvObjWeight_nu()) * GET_S_ABPLBP_CntrLnClthCrvChng_1pm2()) + (GET_P_TJACMB_CombinedCrvObjWeight_nu() * 0.0F);
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Switch/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/CrvWeighting/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/from_data_definition4'/state_source'
         */
    rtb_EQ_ah = (uint8)(((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF)));
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/Application Parameter2'/Constant'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/AND1/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising'/Unit_Delay'
         */
    rtb_DataTypeConversion_lj = (uint8)(((!(((sint32) DW_tjacmb_Unit_Delay_DSTATE_fi) != 0)) && (((sint32)rtb_EQ_ah) != 0)) && (((sint32)GET_P_TJACMB_TransitionHandleOn_bool()) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/OR1/Functionality'/OR'
         */
    rtb_DataTypeConversion_o = (uint8)(((sint32)rtb_DataTypeConversion_lj) != 0);
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset'/Unit_Delay'
         */
    rtb_Switch_es1 = DW_tjacmb_Unit_Delay_DSTATE_d;
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/from_data_definition1'/state_source'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EQ2/Functionality'/EQ'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset'/Unit_Delay'
         */
    rtb_DataTypeConversion_g = (uint8)((!(((sint32)BI_tjacmb_CombinedMode_nu) == ((sint32)((uint8)E_TJACMB_CombModeType_E_TJACMB_CMBMD_PASSIVE)))) && ((((sint32)rtb_DataTypeConversion_o) != 0) || (DW_tjacmb_Unit_Delay_DSTATE_d > 0.0F)));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Freeze_IV/Switch1/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_g) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Freeze_IV/Switch2/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Freeze_IV/NOT/Functionality'/NOT'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX'/Unit_Delay'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Freeze_IV'/Unit_Delay2'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o) != 0)) {
            rtb_Switch_n1 = DW_tjacmb_Unit_Delay2_DSTATE_e;
        } else {
            rtb_Switch_n1 = DW_tjacmb_Unit_Delay_DSTATE_g;
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Freeze_IV/Switch2/Functionality'/Switch' */
    } else {
        rtb_Switch_n1 = DW_tjacmb_Unit_Delay_DSTATE_g;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Freeze_IV/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Constant6'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3'
         */
    if (((sint32)rtb_DataTypeConversion_o) != 0) {
        rtb_Switch3 = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_g) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality/Sum1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA'/Unit_Delay1'
                 */
        rtb_Switch3 = DW_tjacmb_Unit_Delay1_DSTATE_bv + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA'/Unit_Delay1'
                 */
        rtb_Switch3 = DW_tjacmb_Unit_Delay1_DSTATE_bv;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch2' */
    /* Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Application Parameter1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Application Parameter2'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Constant1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Constant3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Constant4'/Constant'
         *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Max/Functionality'/Max'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Div/Functionality/Div'/Div'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Mul/Functionality'/Mul'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Sum/Functionality'/Sum'
         *  Trigonometry: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA/Trigonom/Functionality'/Trigonometric Function'
         */
    rtb_Min_jl = (f32_cos_f32((rtb_Switch3 / f32_max_f32_f32 (GET_P_LCF_AlmostZero_nu(), GET_P_TJACMB_AccObjTransitionTime_sec())) * 3.14159274F) + 1.0F) / 2.0F;
    /* Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/A_Filter/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/A_Filter/Constant'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         */
    rtb_Sum_mk = ((1.0F - rtb_Min_jl) * GET_S_ODPFOP_AccObjPosX_met()) + (rtb_Switch_n1 * rtb_Min_jl);
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset/NOT/Functionality'/NOT'
         */
    if (!(((sint32)rtb_DataTypeConversion_g) != 0)) {
        rtb_Sign_g = GET_S_ODPFOP_AccObjPosX_met();
    } else {
        rtb_Sign_g = rtb_Sum_mk;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         */
    rtb_Sign = GET_S_ODPFOP_AccObjPosX_met() - rtb_Sign_g;
    /* Signum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset/Sign1/Functionality'/Sign' */
    if (rtb_Sign < 0.0F) {
        rtb_Sign = -1.0F;
    } else if (rtb_Sign > 0.0F) {
        rtb_Sign = 1.0F;
    } else {
        if (rtb_Sign == 0.0F) {
            rtb_Sign = 0.0F;
        }
    }
    /* End of Signum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset/Sign1/Functionality'/Sign' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset/NEQ1/Functionality'/NE'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions'/Unit_Delay2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay5'
         */
    if ((rtb_Sign != DW_tjacmb_Unit_Delay5_DSTATE) && (((sint32) DW_tjacmb_Unit_Delay1_DSTATE_p) != 0)) {
        rtb_Switch_eb = 0U;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_eb = 1U;
    } else {
        rtb_Switch_eb = DW_tjacmb_Unit_Delay2_DSTATE_os;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/Constant'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/Constant1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/Constant2'/Constant'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch5/Functionality'/Switch'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch7/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_g) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/Constant'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/Constant1'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/Constant2'/Constant'
                 *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/NOT/Functionality'/NOT'
                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch6/Functionality'/Switch'
                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch8/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier'/Unit_Delay1'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier'/Unit_Delay2'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier'/Unit_Delay3'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier'/Unit_Delay4'
                 */
        if (!(((sint32)rtb_DataTypeConversion_o) != 0)) {
            rtb_Switch_dc = DW_tjacmb_Unit_Delay2_DSTATE_gn;
            rtb_Switch_l = DW_tjacmb_Unit_Delay4_DSTATE;
            rtb_Switch_f = DW_tjacmb_Unit_Delay1_DSTATE_ke;
            rtb_DataTypeConversion_lj = DW_tjacmb_Unit_Delay3_DSTATE;
        } else {
            rtb_Switch_dc = 0U;
            rtb_Switch_l = 0U;
            rtb_Switch_f = 0U;
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch3/Functionality'/Switch' */
    } else {
        rtb_Switch_dc = 0U;
        rtb_Switch_l = 0U;
        rtb_Switch_f = 0U;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_hf = (uint8)((((((sint32)rtb_Switch_dc) != 0) || (((sint32)rtb_Switch_l) != 0)) || (((sint32)rtb_Switch_f) != 0)) || (((sint32)rtb_DataTypeConversion_lj) != 0));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         */
    if (((sint32)rtb_DataTypeConversion_hf) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                 */
        if (((sint32)rtb_Switch_eb) == 0) {
            rtb_Sum_mk = GET_S_ODPFOP_AccObjPosX_met();
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Switch1/Functionality'/Switch' */
    } else {
        rtb_Sum_mk = GET_S_ODPFOP_AccObjPosX_met();
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Constant3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Constant1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Constant2'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/OR/Functionality'/OR'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/OR1/Functionality'/OR'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Mul/Functionality'/Mul'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Mul3/Functionality'/Mul'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Mul4/Functionality'/Mul'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Mul5/Functionality'/Mul'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Mul6/Functionality'/Mul'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Sum2/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter'/Unit_Delay'
         */
    if ((((sint32)rtb_DataTypeConversion_lj) != 0) || (((sint32)rtb_Switch_dc) != 0)) {
        /* Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Subsystem1/Mul1/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                 */
        rtb_Switch_k3 = GET_S_ODPFOP_AccObjPosX_met() * GET_S_ODPFOP_AccObjPosX_met();
        rtb_Switch_k3 = (((DW_tjacmb_Unit_Delay_3_DSTATE * GET_S_ODPFOP_AccObjPosX_met ()) + DW_tjacmb_Unit_Delay_2_DSTATE) + ((rtb_Switch_k3 * DW_tjacmb_Unit_Delay_4_DSTATE) * 0.5F)) + (((rtb_Switch_k3 * GET_S_ODPFOP_AccObjPosX_met()) * 0.1667F) * DW_tjacmb_Unit_Delay_5_DSTATE);
    } else if ((((sint32)rtb_Switch_l) != 0) || (((sint32)rtb_Switch_f) != 0)) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Switch4/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection'/Unit_Delay1'
                 */
        rtb_Switch_k3 = DW_tjacmb_Unit_Delay1_DSTATE_bh;
    } else {
        rtb_Switch_k3 = 0.0F;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/Freeze_IV/Switch2/Functionality'/Switch' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/Freeze_IV/NOT/Functionality'/NOT'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/Freeze_IV/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/Freeze_IV'/Unit_Delay2'
         */
    if ((((sint32)rtb_DataTypeConversion_g) != 0) && (!(((sint32) rtb_DataTypeConversion_o) != 0))) {
        rtb_Switch_k3 = DW_tjacmb_Unit_Delay2_DSTATE_f;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/Freeze_IV/Switch2/Functionality'/Switch' */
    /* Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/A_Filter/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/A_Filter/Constant'/Constant'
         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         */
    rtb_Min_jl = ((1.0F - rtb_Min_jl) * GET_S_ODPFOP_AccObjPosY_met()) + (rtb_Switch_k3 * rtb_Min_jl);
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/NOT/Functionality'/NOT'
         */
    if (!(((sint32)rtb_DataTypeConversion_g) != 0)) {
        rtb_Sign_g = GET_S_ODPFOP_AccObjPosY_met();
    } else {
        rtb_Sign_g = rtb_Min_jl;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
         */
    rtb_Sign_g = GET_S_ODPFOP_AccObjPosY_met() - rtb_Sign_g;
    /* Signum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Sign1/Functionality'/Sign' */
    if (rtb_Sign_g < 0.0F) {
        rtb_Sign_g = -1.0F;
    } else if (rtb_Sign_g > 0.0F) {
        rtb_Sign_g = 1.0F;
    } else {
        if (rtb_Sign_g == 0.0F) {
            rtb_Sign_g = 0.0F;
        }
    }
    /* End of Signum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/Sign1/Functionality'/Sign' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset/NEQ1/Functionality'/NE'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions'/Unit_Delay2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay5'
         */
    if ((rtb_Sign_g != DW_tjacmb_Unit_Delay5_DSTATE_k) && (((sint32) DW_tjacmb_Unit_Delay1_DSTATE_bhr) != 0)) {
        rtb_Switch_k = 0U;
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_k = 1U;
    } else {
        rtb_Switch_k = DW_tjacmb_Unit_Delay2_DSTATE_a;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
         */
    if (((sint32)rtb_DataTypeConversion_hf) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
                 */
        if (((sint32)rtb_Switch_k) == 0) {
            rtb_Min_jl = GET_S_ODPFOP_AccObjPosY_met();
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/Switch1/Functionality'/Switch' */
    } else {
        rtb_Min_jl = GET_S_ODPFOP_AccObjPosY_met();
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/Switch/Functionality'/Switch' */
    /* BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter'/TJA_FusionKalmanIn' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant10'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant11'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant12'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant2'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant4'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant5'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant6'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant7'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant8'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FilterParams_Default/Constant9'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Constant2'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Constant3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Constant5'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/Constant6'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    rtb_TJA_FusionKalmanIn.bLnValid_nu = rtb_DataTypeConversion_bb;
    rtb_TJA_FusionKalmanIn.bObjValid_nu = rtb_EQ_nj;
    rtb_TJA_FusionKalmanIn.bPrediction_bool = 0U;
    rtb_TJA_FusionKalmanIn.bResetPosYState_bool = 0U;
    rtb_TJA_FusionKalmanIn.fLnPosY0_met = rtb_Min_a;
    rtb_TJA_FusionKalmanIn.fLnHeading_rad = rtb_Min_c;
    rtb_TJA_FusionKalmanIn.fLnCrv_1pm = rtb_Switch_hn;
    rtb_TJA_FusionKalmanIn.fLnChngOfCrv_1pm2 = rtb_Switch;
    rtb_TJA_FusionKalmanIn.fObjXPos_met = rtb_Sum_mk;
    rtb_TJA_FusionKalmanIn.fObjYPos_met = rtb_Min_jl;
    rtb_TJA_FusionKalmanIn.fObjXPosStdDev_met = GET_P_TJACMB_AccObjPosXStdDev_met();
    rtb_TJA_FusionKalmanIn.fObjYPosStdDev_met = GET_P_TJACMB_AccObjPosYStdDev_met();
    rtb_TJA_FusionKalmanIn.fCycleTime_sec = GET_S_LCFRCV_SysCycleTimeSen_sec();
    rtb_TJA_FusionKalmanIn.fYawRate_rps = GET_S_LCFRCV_VehYawRate_rps();
    rtb_TJA_FusionKalmanIn.fVelX_mps = GET_S_LCFRCV_VehVelX_mps();
    rtb_TJA_FusionKalmanIn.PredYawRtVar_r2ps2 = GET_P_TJATTG_PredYawRtVar_r2ps2();
    rtb_TJA_FusionKalmanIn.PredVelXVar_m2 = GET_P_TJATTG_PredVelXVar_m2();
    rtb_TJA_FusionKalmanIn.ModelPosYVar_m2 = GET_P_TJATTG_ModelPosYVar_m2();
    rtb_TJA_FusionKalmanIn.ModelYawVar_rad2 = GET_P_TJATTG_ModelYawVar_rad2();
    rtb_TJA_FusionKalmanIn.ModelCrvVar_1pm2 = GET_P_TJATTG_ModelCrvVar_1pm2();
    rtb_TJA_FusionKalmanIn.ModelCrvChngVar_1pm4 = GET_P_TJATTG_ModelCrvChngVar_1pm4();
    rtb_TJA_FusionKalmanIn.ObjMeasPosYVar_m2 = GET_P_TJATTG_ObjMeasPosYVar_m2();
    rtb_TJA_FusionKalmanIn.ObjMeasPosXVar_m2 = GET_P_TJATTG_ObjMeasPosXVar_m2();
    rtb_TJA_FusionKalmanIn.LnMeasPosYVar_m2 = GET_P_TJATTG_LnMeasPosYVar_m2();
    rtb_TJA_FusionKalmanIn.LnMeasHeadVar_rad2 = GET_P_TJATTG_LnMeasHeadVar_rad2();
    rtb_TJA_FusionKalmanIn.LnMeasCrvVar_1pm2 = GET_P_TJATTG_LnMeasCrvVar_1pm2();
    rtb_TJA_FusionKalmanIn.LnMeasCrvChngVar_1pm4 = GET_P_TJATTG_LnMeasCrvChngVar_1pm4();
    rtb_TJA_FusionKalmanIn.CrvChngDecay_nu = GET_P_TJATTG_CrvChngDecay_nu();
    /* S-Function (sfun_fusionKalman): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter'/sfun_fusionKalman' */
    fusionTgtCorridor((fusionKFInput*)&rtb_TJA_FusionKalmanIn, &rtb_sfun_fusionKalman);
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MatrixInversionCheck/AND/Functionality'/Data Type Conversion' incorporates:
         *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MatrixInversionCheck/AND/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MatrixInversionCheck/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MatrixInversionCheck/OR1/Functionality'/OR'
         */
    rtb_NE_ck = (uint8)(((((sint32)rtb_DataTypeConversion_bb) != 0) || (((sint32) rtb_EQ_nj) != 0)) && (!(((sint32)rtb_sfun_fusionKalman.bTrajValid_nu) != 0)));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MaxCurvatureCheck/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MaxCurvatureCheck/Abs/Functionality'/Abs'
         *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MaxCurvatureCheck/Constant3'/Constant'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MaxCurvatureCheck/AND1/Functionality'/AND'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MaxCurvatureCheck/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MaxCurvatureCheck/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/MaxCurvatureCheck/GT/Functionality'/GT'
         */
    rtb_DataTypeConversion_hf = (uint8)((((!(((sint32)rtb_DataTypeConversion_bb) != 0)) || (((sint32)rtb_EQ_nj) != 0)) && (((sint32) rtb_sfun_fusionKalman.bTrajValid_nu) != 0)) && (f32_abs_f32 (rtb_sfun_fusionKalman.fCrv_1pm) > GET_P_TJACMB_CurvatureMaxOF_1pm()));
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch2'/copy1' incorporates:
         *  DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CheckKalmanState/OR/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CheckKalmanState/OR/Functionality'/OR'
         */
    SET_S_TJACMB_Cancel_bool((uint8)(((((sint32)rtb_DataTypeConversion) != 0) || (((sint32)rtb_NE_ck) != 0)) || (((sint32)rtb_DataTypeConversion_hf) != 0)));
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CheckKalmanState/branch'/copy1' */
    rtb_VectorConcatenate_m[10] = rtb_NE_ck;
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CheckKalmanState/branch1'/copy1' */
    rtb_VectorConcatenate_m[11] = rtb_DataTypeConversion_hf;
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT/Functionality'/NOT'
         */
    rtb_VectorConcatenate[3] = (uint8)(!(((sint32)rtb_DataTypeConversion_m) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate[2] = (uint8)(!(((sint32)rtb_DataTypeConversion_fj) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate[1] = (uint8)(!(((sint32)rtb_DataTypeConversion_mh) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_n5) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT10/Functionality'/NOT'
         */
    rtb_VectorConcatenate[7] = (uint8)(!(((sint32)rtb_Switch3_c) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT11/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT11/Functionality'/NOT'
         */
    rtb_VectorConcatenate[4] = (uint8)(!(((sint32)rtb_DataTypeConversion_ok) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJALKA_CombinedLaneWR_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate[5] = (uint8)(!(((sint32) GET_S_TJALKA_CombinedLaneWR_bool()) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT9/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJALKA_CombinedLaneSR_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT9/Functionality'/NOT'
         */
    rtb_VectorConcatenate[6] = (uint8)(!(((sint32) GET_S_TJALKA_CombinedLaneSR_bool()) != 0));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_jw) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity'/Unit_Delay2'
                 */
        if (DW_tjacmb_Unit_Delay2_DSTATE_d > 0.0F) {
            /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjacmb_Unit_Delay2_DSTATE_d -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/Constant3'/Constant'
                 */
        DW_tjacmb_Unit_Delay2_DSTATE_d = GET_P_TJACMB_MinDurObjLnValidWR_sec();
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity/TURNONDELAYTIME/Functionality'/Switch2' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate[11] = (uint8)(!(((sint32)rtb_DataTypeConversion_m2) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAOBF_AccObjValid_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate[8] = (uint8)(!(((sint32)GET_S_TJAOBF_AccObjValid_bool()) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate[9] = (uint8)(!(((sint32)rtb_LogicalOperator_l) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/NOT9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/NOT9/Functionality'/NOT'
         */
    rtb_VectorConcatenate[10] = (uint8)(!(((sint32)rtb_DataTypeConversion_di) != 0));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Unit_Delay1_b) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState'/Unit_Delay'
                 */
        if (DW_tjacmb_Unit_Delay_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState'/Unit_Delay' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjacmb_Unit_Delay_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState'/Unit_Delay' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/Application Parameter3'/Constant'
                 */
        DW_tjacmb_Unit_Delay_DSTATE = GET_P_TJACMB_KalmanMinValidTime_sec();
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CheckKalmanState/TURNONDELAYTIME/Functionality'/Switch2' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate[13] = (uint8)(!(((sint32)rtb_LogicalOperator_m0) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/NOT2/Functionality'/NOT'
         */
    rtb_VectorConcatenate[14] = (uint8)(!(((sint32)rtb_DataTypeConversion_el) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate[12] = (uint8)(!(((sint32)rtb_DataTypeConversion_dk) != 0));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_GT_m) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority'/Unit_Delay'
                 */
        if (DW_tjacmb_Unit_Delay_DSTATE_h > 0.0F) {
            /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority'/Unit_Delay' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_tjacmb_Unit_Delay_DSTATE_h -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority'/Unit_Delay' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/Application Parameter2'/Constant'
                 */
        DW_tjacmb_Unit_Delay_DSTATE_h = GET_P_TJACMB_MinObjStraightProb_sec();
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/PureObjectFollowingPriority/TURNONDELAYTIME/Functionality'/Switch2' */
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Debug/OR/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJALKA_StrongReady_bool'
         *  Inport: '<Root>/S_TJALKA_WeakReady_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT6/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/NOT8/Functionality'/NOT'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Debug/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate[15] = (uint8)((!(((sint32)GET_S_TJALKA_WeakReady_bool()) != 0)) || (!(((sint32)GET_S_TJALKA_StrongReady_bool()) != 0)));
    /* S-Function (sfun_setbit): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Debug/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit = temp;
    }
    /* RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/from_data_definition5'/state_source'
         */
    rtb_NE_ck = (uint8)(((sint32)BI_tjacmb_CombinedMode_nu) != ((sint32)((uint8) E_TJACMB_CombModeType_E_TJACMB_CMBMD_PASSIVE)));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT10/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_mn) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT11/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT11/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[3] = (uint8)(!(((sint32)rtb_DataTypeConversion_mx) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT12/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAOBF_StrongReady_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT12/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[5] = (uint8)(!(((sint32) GET_S_TJAOBF_StrongReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT13/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT13/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[4] = (uint8)(!(((sint32)rtb_DataTypeConversion_c) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT14/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TJAOBF_WeakReady_bool'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT14/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[6] = (uint8)(!(((sint32)GET_S_TJAOBF_WeakReady_bool()) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT15/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT15/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_df) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT16/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT16/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[8] = (uint8)(!(((sint32)rtb_DataTypeConversion_hl) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT17/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Application Parameter1'/Constant'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT17/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[9] = (uint8)(!(((sint32)GET_P_TJACMB_OF_Enabled_bool ()) != 0));
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/NOT9/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[1] = (uint8)(!(((sint32)rtb_DataTypeConversion_n5) != 0));
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn13' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/Constant'/Constant'
         */
    rtb_VectorConcatenate_m[12] = 0U;
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn14' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/Constant'/Constant'
         */
    rtb_VectorConcatenate_m[13] = 0U;
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn15' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/Constant'/Constant'
         */
    rtb_VectorConcatenate_m[14] = 0U;
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn16' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/Constant'/Constant'
         */
    rtb_VectorConcatenate_m[15] = 0U;
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_m[2] = rtb_DataTypeConversion;
    /* S-Function (sfun_setbit): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/Debug/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_m[0];
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
        rtb_sfun_setbit_k = temp;
    }
    /* DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_hf = (uint8)(!(((sint32)rtb_DataTypeConversion_hf) != 0));
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/Application Parameter2'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_o) != 0) {
        rtb_Switch_es1 = GET_P_TJACMB_AccObjTransitionTime_sec();
    } else {
        if (DW_tjacmb_Unit_Delay_DSTATE_d > 0.0F) {
            /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset'/Unit_Delay'
                         */
            rtb_Switch_es1 = DW_tjacmb_Unit_Delay_DSTATE_d - GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Switch3/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Sum1/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling'/Unit_Delay1'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling'/Unit_Delay2'
         */
    if (((sint32)rtb_EQ_nj) != 0) {
        rtb_Min_a = DW_tjacmb_Unit_Delay1_DSTATE_m;
        rtb_Min_c = DW_tjacmb_Unit_Delay2_DSTATE_o;
    } else {
        rtb_Min_a = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_sfun_fusionKalman.fPosY0_met;
        rtb_Min_c = GET_S_ABPLBP_RiLnClthPosY0_met() - rtb_sfun_fusionKalman.fPosY0_met;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Switch1/Functionality'/Switch' incorporates:
         *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Constant1'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Constant2'/Constant'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/OR/Functionality'/OR'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Sum3/Functionality'/Sum'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Switch2/Functionality'/Switch'
         */
    if ((((sint32)rtb_DataTypeConversion_bb) != 0) || (((sint32)rtb_EQ_nj) != 0)) {
        rtb_Sum_mk = rtb_Min_c + rtb_sfun_fusionKalman.fPosY0_met;
        rtb_Min_jl = rtb_Min_a + rtb_sfun_fusionKalman.fPosY0_met;
    } else {
        rtb_Sum_mk = 0.0F;
        rtb_Min_jl = 0.0F;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant2'/Constant'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_bb) != 0) {
        rtb_DataTypeConversion = 0U;
    } else if (((sint32)rtb_EQ_nj) != 0) {
        /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant1'/Constant'
                 */
        rtb_DataTypeConversion = 1U;
    } else {
        rtb_DataTypeConversion = 2U;
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Switch/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant3'/Constant'
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant4'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosX0_met'
         */
    switch (rtb_DataTypeConversion) {
    case 0:
        rtb_Switch = GET_S_ABPLBP_CntrLnClthPosX0_met();
        /* MultiPortSwitch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Multiport_Switch2' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_CntrLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosX0_met'
                 */
        rtb_Switch_hn = GET_S_ABPLBP_CntrLnClthCrvChng_1pm2();
        /* MultiPortSwitch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Multiport_Switch1' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_CntrLnClthLength_met'
                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Switch2/Functionality'/Switch'
                 */
        rtb_Multiport_Switch1 = GET_S_ABPLBP_CntrLnClthLength_met();
        break;
    case 1:
        rtb_Switch = 0.0F;
        /* MultiPortSwitch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Multiport_Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant3'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant6'/Constant'
                 */
        rtb_Switch_hn = 0.0F;
        /* MultiPortSwitch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Multiport_Switch1' incorporates:
                 *  Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Switch2/Functionality'/Switch'
                 */
        rtb_Multiport_Switch1 = GET_S_ODPFOP_AccObjPosX_met();
        break;
    default:
        rtb_Switch = 0.0F;
        /* MultiPortSwitch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Multiport_Switch2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant4'/Constant'
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant7'/Constant'
                 */
        rtb_Switch_hn = 0.0F;
        /* MultiPortSwitch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Multiport_Switch1' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Constant5'/Constant'
                 *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling/Switch2/Functionality'/Switch'
                 */
        rtb_Multiport_Switch1 = 0.0F;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Multiport_Switch' */
    /* MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant'/Constant'
         */
    rtb_Switch = f32_max_f32_f32(rtb_Switch, 0.0F);
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch3'/copy1' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant2'/Constant'
         *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter/Min/Functionality'/Min'
         */
    SET_S_TJACMB_CombinedPosX0_met(f32_min_f32_f32(10.0F, rtb_Switch));
    /* MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter6/Max/Functionality'/Max' incorporates:
                                                                          *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant14'/Constant'
                                                                          */
    rtb_Min_jl = f32_max_f32_f32(rtb_Min_jl, 0.0F);
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch18'/copy1' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant15'/Constant'
         *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter6/Min/Functionality'/Min'
         */
    SET_S_TJACMB_CombinedLePosY0_met(f32_min_f32_f32(6.0F, rtb_Min_jl));
    /* MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter7/Max/Functionality'/Max' incorporates:
                                                                          *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant16'/Constant'
                                                                          */
    rtb_Sum_mk = f32_max_f32_f32(rtb_Sum_mk, -6.0F);
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch19'/copy1' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant17'/Constant'
         *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter7/Min/Functionality'/Min'
         */
    SET_S_TJACMB_CombinedRiPosY0_met(f32_min_f32_f32(0.0F, rtb_Sum_mk));
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch'/copy1' */
    SET_S_TJACMB_StrongReady_bool(rtb_NE_ck);
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch1'/copy1' */
    SET_S_TJACMB_WeakReady_bool(rtb_NE_ck);
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch11'/copy1' */
    SET_D_TJACMB_CombinedInvalid_btf(rtb_sfun_setbit_k);
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch12'/copy1' */
    SET_S_TJACMB_CombinedMode_nu(BI_tjacmb_CombinedMode_nu);
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch13'/copy1' */
    SET_D_TJACMB_TransitionInvalid_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch4'/copy1' incorporates:
                                                           *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
                                                           *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant4'/Constant'
                                                           *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant5'/Constant'
                                                           *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter1/Max/Functionality'/Max'
                                                           *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter1/Min/Functionality'/Min'
                                                           */
    SET_S_TJACMB_CombinedPosY0_met(f32_min_f32_f32(2.5F, f32_max_f32_f32 (rtb_sfun_fusionKalman.fPosY0_met, -2.5F)));
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch5'/copy1' incorporates:
                                                     *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
                                                     *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant6'/Constant'
                                                     *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant7'/Constant'
                                                     *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter2/Max/Functionality'/Max'
                                                     *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter2/Min/Functionality'/Min'
                                                     */
    SET_S_TJACMB_CombinedHeading_rad(f32_min_f32_f32(0.35F, f32_max_f32_f32 (rtb_sfun_fusionKalman.fHeading_rad, -0.35F)));
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch6'/copy1' incorporates:
                                                        *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant1'/Constant'
                                                        *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant3'/Constant'
                                                        *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter4/Max/Functionality'/Max'
                                                        *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter4/Min/Functionality'/Min'
                                                        */
    SET_S_TJACMB_CombinedCrvChng_1pm2(f32_min_f32_f32(0.0006F, f32_max_f32_f32 (rtb_Switch_hn, -0.0006F)));
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch7'/copy1' incorporates:
                                            *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant12'/Constant'
                                            *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant13'/Constant'
                                            *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter5/Max/Functionality'/Max'
                                            *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter5/Min/Functionality'/Min'
                                            */
    SET_S_TJACMB_CombinedLength_met(f32_min_f32_f32(300.0F, f32_max_f32_f32 (rtb_Multiport_Switch1, 0.0F)));
    /* SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/branch8'/copy1' incorporates:
                                            *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
                                            *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant8'/Constant'
                                            *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/Constant9'/Constant'
                                            *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter3/Max/Functionality'/Max'
                                            *  MinMax: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/MinMaxLimitation/MinMaxLimiter3/Min/Functionality'/Min'
                                            */
    SET_S_TJACMB_CombinedCrv_1pm(f32_min_f32_f32(0.006F, f32_max_f32_f32 (rtb_sfun_fusionKalman.fCrv_1pm, -0.006F)));
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/LateralControlModeValidity'/Unit_Delay' incorporates:
                                                     *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
                                                     */
    DW_tjacmb_Unit_Delay_DSTATE_gs = GET_S_TJASTM_LatCtrlMode_nu();
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck'/Unit_Delay1' */
    DW_tjacmb_Unit_Delay1_DSTATE_c = rtb_Switch3_o;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/VelocityCheck'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_l = rtb_Switch3_j;
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjacmb_Unit_Delay2_DSTATE_dm = rtb_EQ_o;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/EdgeRising/EDGERISING'/fcg' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck'/Unit_Delay1'
         */
    if (((sint32)LogicalOperator_d) != 0) {
        /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck'/Unit_Delay1' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/Constant2'/Constant'
                 */
        DW_tjacmb_Unit_Delay1_DSTATE = GET_P_TJACMB_PassivModeMinTime_sec();
    } else {
        if (DW_tjacmb_Unit_Delay1_DSTATE > 0.0F) {
            /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck'/Unit_Delay1'
                         *  Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck'/Unit_Delay1'
                         */
            DW_tjacmb_Unit_Delay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_GenericConditionCheck/CombinedModeStateCheck/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_LaneConditionCheck/LaneLengthCheck'/Unit_Delay' */
    DW_tjacmb_Unit_Delay_DSTATE_fr = rtb_Switch3_c;
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection'/Unit_Delay1' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/Constant4'/Constant'
         *  SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjacmb_Unit_Delay1_DSTATE_k = GET_P_TJACMB_InjectLaneError_bool();
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/EDGERISING'/fcg' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection'/Unit_Delay2'
         */
    if (((sint32)LogicalOperator_h) != 0) {
        /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/Constant2'/Constant'
                 */
        DW_tjacmb_Unit_Delay2_DSTATE = GET_P_TJACMB_LaneInvalidTime_sec();
    } else {
        if (DW_tjacmb_Unit_Delay2_DSTATE > 0.0F) {
            /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection'/Unit_Delay2'
                         *  Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection'/Unit_Delay2'
                         */
            DW_tjacmb_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/LaneErrorInjection/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck'/Unit_Delay1' */
    DW_tjacmb_Unit_Delay1_DSTATE_ch = rtb_Switch3_kd;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CMB_OF_VelocityCheck'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_g = rtb_Switch3_g;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity'/Unit_Delay' */
    DW_tjacmb_Unit_Delay_DSTATE_p = rtb_Switch3_ci;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/CheckAccObjectValidity'/Unit_Delay1' */
    DW_tjacmb_Unit_Delay1_DSTATE_i = rtb_Switch3_e;
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising'/Unit_Delay2' incorporates:
         *  SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjacmb_Unit_Delay2_DSTATE_b = rtb_EQ_bg;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/EdgeRising/EDGERISING'/fcg' */
    /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Switch2'
         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck'/Unit_Delay1'
         */
    if (((sint32)LogicalOperator_m) != 0) {
        /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck'/Unit_Delay1' incorporates:
                 *  Constant: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/Application Parameter2'/Constant'
                 */
        DW_tjacmb_Unit_Delay1_DSTATE_b = GET_P_TJACMB_MaxTimeObjCntrl_sec();
    } else {
        if (DW_tjacmb_Unit_Delay1_DSTATE_b > 0.0F) {
            /* Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck'/Unit_Delay1'
                         *  Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck'/Unit_Delay1'
                         */
            DW_tjacmb_Unit_Delay1_DSTATE_b -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/CMB_OF_SR_ConditionCheck/MaxTimeCheck/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/CombinedModeStateMachine/Combined_ObjectConditionCheck/LaneCurveCheck'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_j = rtb_Switch3_lw;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB'/Unit_Delay' incorporates:
         *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
         *  DataTypeConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/AND/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/KalmanValidityCheck/AND/Functionality'/AND'
         */
    DW_tjacmb_Unit_Delay_DSTATE_l = (uint8)((((sint32)rtb_DataTypeConversion_hf) != 0) && (((sint32)rtb_sfun_fusionKalman.bTrajValid_nu) != 0));
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/Freeze_IV'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_e = rtb_Switch_n1;
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjacmb_Unit_Delay_DSTATE_fi = rtb_EQ_ah;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/TransitionControl/EdgeRising/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX'/Unit_Delay' incorporates:
         *  Update for Inport: '<Root>/S_ODPFOP_AccObjPosX_met'
         */
    DW_tjacmb_Unit_Delay_DSTATE_g = GET_S_ODPFOP_AccObjPosX_met();
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/SetTransitionTime/TurnOffDelayTime_CustomizedReset'/Unit_Delay' */
    DW_tjacmb_Unit_Delay_DSTATE_d = rtb_Switch_es1;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/CalculateTransitionFactorA'/Unit_Delay1' */
    DW_tjacmb_Unit_Delay1_DSTATE_bv = rtb_Switch3;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay5' */
    DW_tjacmb_Unit_Delay5_DSTATE = rtb_Sign;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay1' */
    DW_tjacmb_Unit_Delay1_DSTATE_p = rtb_DataTypeConversion_g;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosX/A_Filtering/EnableFilterConditions'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_os = rtb_Switch_eb;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_gn = rtb_Switch_dc;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier'/Unit_Delay4' */
    DW_tjacmb_Unit_Delay4_DSTATE = rtb_Switch_l;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier'/Unit_Delay1' */
    DW_tjacmb_Unit_Delay1_DSTATE_ke = rtb_Switch_f;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionControl/DefineTransitionQualifier'/Unit_Delay3' */
    DW_tjacmb_Unit_Delay3_DSTATE = rtb_DataTypeConversion_lj;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/Freeze_IV'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_f = rtb_Switch_k3;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter'/Unit_Delay' incorporates:
         *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
         */
    DW_tjacmb_Unit_Delay_2_DSTATE = rtb_sfun_fusionKalman.fPosY0_met;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter'/Unit_Delay' incorporates:
         *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
         */
    DW_tjacmb_Unit_Delay_3_DSTATE = rtb_sfun_fusionKalman.fHeading_rad;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter'/Unit_Delay' incorporates:
         *  BusCreator: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus'/TJA_FusionKalmanOut'
         */
    DW_tjacmb_Unit_Delay_4_DSTATE = rtb_sfun_fusionKalman.fCrv_1pm;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter'/Unit_Delay' */
    DW_tjacmb_Unit_Delay_5_DSTATE = rtb_Switch_hn;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/IV_Selection'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_ODPFOP_AccObjPosY_met'
         */
    DW_tjacmb_Unit_Delay1_DSTATE_bh = GET_S_ODPFOP_AccObjPosY_met();
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay5' */
    DW_tjacmb_Unit_Delay5_DSTATE_k = rtb_Sign_g;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions/Reset'/Unit_Delay1' */
    DW_tjacmb_Unit_Delay1_DSTATE_bhr = rtb_DataTypeConversion_g;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/ToObjectTransitionHandling/CalculatePosYRampDuringObj2ObjTransition/TransitionFilterPosY/A_Filtering/EnableFilterConditions'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_a = rtb_Switch_k;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling'/Unit_Delay1' */
    DW_tjacmb_Unit_Delay1_DSTATE_m = rtb_Min_a;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/LePosY0_RiPosY0_Handling'/Unit_Delay2' */
    DW_tjacmb_Unit_Delay2_DSTATE_o = rtb_Min_c;
    /* Update for UnitDelay: 'sda:TJACMB/TJACMB/TJACMB_SenProcess/TJACMB/FusionKalmanFilter/FusionKalmanFilter/WriteKalmanFilterOutput2Bus/PosX0_Length_Handling'/Unit_Delay' */
    DW_tjacmb_Unit_Delay_DSTATE_f = rtb_Multiport_Switch1;
}
#include "Pse_TJACMB.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
