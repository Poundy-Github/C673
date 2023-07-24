/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_autocode_cfg.c

DESCRIPTION:               Implementation of the autocode parameters (for the generic state machine and the HEAD SPM) in the HEAD module

AUTHOR:                    $Author: $ 

CREATION DATE:             $Date: $ 

VERSION:                   $Revision: $ 

HPX:                       MFC5J3_C673_v8.7.2_SOP1.hpx

**************************************************************************** */

/**
@defgroup head_autocode_cfg HEAD_AUTOCODE_CFG
@ingroup Medic_head
@{ **/

/* DO NOT MANUALLY EDIT THIS FILE - use cgeb_head_generate_code.py instead! */

/*CHECKSUMCODE*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#include "head/head_int.h"
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*PRQA S 97, 779, 2203, 2205, 2217, 3120, 3121, 3122, 3132, 3199, 3212, 3218, 3355, 3358, 3455, 4152, 7004, 7012, 7013 AUTOCODER_QAC*/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS AND VARIABLES 
*****************************************************************************/
static HEADSPMCheck_t rgHEADAutoCodeSPMRules[HEAD_AUTO_CFG_NO_SPM_RULES];
static HEADSPMRules_t sHEADAutoCodeSPMRules;
static HEADModuleInternalGSM_t HEADInternalState_LatPreWarn;
static HEADParameterScalar_t LatPreWarn_Inhibition;
static HEADParameterScalar_t LatPreWarn_MinEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_MaxEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_HypProb;
static HEADParameterScalar_t LatPreWarn_ObjProb;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_TTC4_Middle;
static HEADParameterScalar_t LatPreWarn_DrvActivity;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_DrvActivity_Leave;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_LockTime;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_MaxTime;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_Driver_Seatbelt;
static HEADParameterScalar_t LatPreWarnSensorSource;
static HEADParameterScalar_t LatPreWarn_SteeringGrad_Levae;
static HEADParameterTable_t LatPreWarn_AllConditionsTRUEYawStat;
static const float32 LatPreWarn_AllConditionsTRUEYawStat_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 0.0f, 0.008f, 0.0f, 0.009f, 0.2f, 0.01f, 0.2f, 0.02f, 0.3f};
static HEADParameterScalar_t LatPreWarn_TTSPre_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_TTSPre_middle;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_TTSPre_late;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarnMaxLateralDistance;
static HEADParameterScalar_t LatPreWarnHypothesisLifeTime;
static HEADParameterTable_t LatPreWarning_EgoAccX_NAcc;
static float32 LatPreWarning_EgoAccX_NAcc_table[2*8];  /*!<@values:float32[8][2]*/
static HEADParameterScalar_t LatPreWarn_OnlyIfVehBrkNotActive;
static HEADParameterScalar_t LatPreWarn_OnlyIfCrossVRUBrkNotActive;/*!<@allow: all_cust */
static HEADParameterScalar_t LatPreWarn_OnlyIfLongVruBrkNotActive;
static HEADParameterScalar_t LatPreWarnego_accel_min;
static HEADParameterScalar_t LatPreWarnego_accel_max;
static HEADParameterScalar_t LatPreWarn_vrel_min;
static HEADParameterScalar_t LatPreWarn_vrel_max;
static HEADParameterScalar_t LatPreWarn_TTC4_Early;
static HEADParameterScalar_t LatPreWarn_TTC4_Late;
static HEADModuleInternalGSM_t HEADInternalState_LatAcuteWarn;
static HEADParameterScalar_t LatAcuteWarnStayInOFF;
static HEADModuleInternalGSM_t HEADInternalState_DynPreWarn;
static HEADParameterScalar_t DynPreWarnStayInOFF;
static HEADModuleInternalGSM_t HEADInternalState_DynAcuteWarn;
static HEADModOutWarnFunctionPar_t HEADFuncOut_DynAcuteWarnPar;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_Inhibition;
static HEADParameterScalar_t DynAcuteWarn_MinEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_MaxEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_MaxEgoVel_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_HypProb;
static HEADParameterScalar_t DynAcuteWarn_ObjProb;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_ObjProb_HypStat;/*!<@allow: all_cust */
static HEADParameterTable_t DynAcuteWarn_TTBAcute;
static const float32 DynAcuteWarn_TTBAcute_table[2*9] /*!<@values:float32[9][2]*/ = {-52.7777777778f, 0.0f, -45.0f, 0.0f, -23.0555555556f, 2.1f, -17.2222222222f, 2.1f, -13.8888888889f, 2.1f, -5.55555555556f, 1.95f, -2.77777777778f, 1.95f, -2.08333333333f, 1.95f, 0.0f, 1.95f};
static HEADParameterScalar_t DynAcuteWarn_TTBAcute_HypBrk;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_TTCMin;
static HEADParameterScalar_t DynAcuteWarn_TTSPre_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_TTSAcute_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_MinDistX;
static HEADParameterScalar_t DynAcuteWarn_MaxTime;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_LockTime;/*!<@allow: all_cust */
static HEADParameterTable_t DynAcuteWarnAllConditionsTRUEVelMov;
static float32 DynAcuteWarnAllConditionsTRUEVelMov_table[2*4];  /*!<@values:float32[4][2]*/
static HEADParameterScalar_t DynAcuteWarn_AllConditionsTRUE;
static HEADParameterTable_t DynAcuteWarnAllConditionsTRUEStat;
static float32 DynAcuteWarnAllConditionsTRUEStat_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterTable_t DynAcuteWarn_AllConditionsTRUEActivityStat;
static const float32 DynAcuteWarn_AllConditionsTRUEActivityStat_table[2*4] /*!<@values:float32[4][2]*/ = {0.0f, 0.0f, 30.0f, 0.3f, 70.0f, 0.3f, 100.0f, 0.3f};
static HEADParameterScalar_t DynAcuteWarn_MinTime;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_KeepIfVehAutoBrkIsActive;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_DrvActivity_Leave;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_Driver_Seatbelt;
static HEADParameterTable_t DynAcuteWarn_ObjDist_Lifetime;
static float32 DynAcuteWarn_ObjDist_Lifetime_table[2*4];  /*!<@allow: all_cust *//*!<@values:float32[4][2]*/
static HEADParameterTable_t DynAcuteWarn_Hypo_Lifetime;
static float32 DynAcuteWarn_Hypo_Lifetime_table[2*4];  /*!<@allow: all_cust *//*!<@values:float32[4][2]*/
static HEADParameterScalar_t DynAcutelSensorSource;
static HEADParameterScalar_t DynAcuteWarn_SteerGrad_Leave;
static HEADParameterTable_t DynAcuteWarn_TTCMax_middle;
static const float32 DynAcuteWarn_TTCMax_middle_table[2*7] /*!<@values:float32[7][2]*/ = {-13.8888888889f, 2.3f, -13.0555555556f, 2.3f, -12.7777777778f, 1.7f, -8.33333333333f, 1.7f, -5.55555555556f, 1.7f, -4.16666666667f, 1.5f, 0.0f, 0.7f};
static HEADParameterTable_t DynAcuteWarn_TTCMax_early;
static const float32 DynAcuteWarn_TTCMax_early_table[2*7] /*!<@values:float32[7][2]*/ = {-13.8888888889f, 2.6f, -13.0555555556f, 2.6f, -12.7777777778f, 1.7f, -8.33333333333f, 1.7f, -5.55555555556f, 1.7f, -4.16666666667f, 1.6f, 0.0f, 0.7f};
static HEADParameterTable_t DynAcuteWarn_TTCMax_late;
static const float32 DynAcuteWarn_TTCMax_late_table[2*7] /*!<@values:float32[7][2]*/ = {-13.8888888889f, 2.0f, -13.0555555556f, 2.0f, -12.7777777778f, 1.7f, -8.33333333333f, 1.7f, -5.55555555556f, 1.7f, -4.16666666667f, 1.4f, 0.0f, 0.7f};
static HEADParameterTable_t DynAcuteWarn_Hypo_RunupLifetime;
static float32 DynAcuteWarn_Hypo_RunupLifetime_table[2*4];  /*!<@allow: all_cust *//*!<@values:float32[4][2]*/
static HEADParameterTable_t DynAcuteWarn_ObjDistY_RunupBraking;
static float32 DynAcuteWarn_ObjDistY_RunupBraking_table[2*5];  /*!<@allow: all_cust *//*!<@values:float32[5][2]*/
static HEADParameterTable_t DynAcuteWarn_ObjDistY_RunupStatVRU;
static float32 DynAcuteWarn_ObjDistY_RunupStatVRU_table[2*5];  /*!<@allow: all_cust *//*!<@values:float32[5][2]*/
static HEADParameterTable_t DynAcuteWarn_Hypo_RunupBrakingLifetime;
static float32 DynAcuteWarn_Hypo_RunupBrakingLifetime_table[2*7];  /*!<@allow: all_cust *//*!<@values:float32[7][2]*/
static HEADParameterTable_t DynAcuteWarn_TTCMax_middle_mov;
static const float32 DynAcuteWarn_TTCMax_middle_mov_table[2*6] /*!<@values:float32[6][2]*/ = {-8.33333333333f, 2.3f, -7.77777777778f, 2.3f, -7.5f, 1.7f, -5.55555555556f, 1.7f, -4.16666666667f, 1.5f, 0.0f, 0.7f};
static HEADParameterTable_t DynAcuteWarn_TTCMax_early_mov;
static const float32 DynAcuteWarn_TTCMax_early_mov_table[2*6] /*!<@values:float32[6][2]*/ = {-8.33333333333f, 2.6f, -7.77777777778f, 2.6f, -7.5f, 1.7f, -5.55555555556f, 1.7f, -4.16666666667f, 1.6f, 0.0f, 0.7f};
static HEADParameterTable_t DynAcuteWarn_TTCMax_late_mov;
static const float32 DynAcuteWarn_TTCMax_late_mov_table[2*6] /*!<@values:float32[6][2]*/ = {-8.33333333333f, 2.0f, -7.77777777778f, 2.0f, -7.5f, 1.7f, -5.55555555556f, 1.7f, -4.16666666667f, 1.4f, 0.0f, 0.7f};
static HEADParameterTable_t DynAcuteWarn_EgoAccX_NAcc;
static HEADParameterScalar_t DynAcuteWarnFP_CurveMAX;
static HEADParameterScalar_t DynAcuteWarnFP_CurveMin;
static HEADParameterScalar_t DynAcuteWarn_TTSPre;/*!<@allow: all_cust */
static HEADParameterTable_t DynAcuteWarn_TTSAcute;
static float32 DynAcuteWarn_TTSAcute_table[2*8];  /*!<@allow: all_cust *//*!<@values:float32[8][2]*/
static HEADParameterScalar_t CrossVru_DynAcuteWarnOb_OncomingKeepPassive;
static HEADParameterTable_t ObjCorridorOccupancFCW_YawRate;
static float32 ObjCorridorOccupancFCW_YawRate_table[2*6];  /*!<@allow: all_cust *//*!<@values:float32[6][2]*/
static HEADParameterTable_t DynAcuteWarnAllConditionsTRUE_MovingYawrate;
static float32 DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t DynAcuteWarnTTC_HypBrk;
static float32 DynAcuteWarnTTC_HypBrk_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterTable_t Veh_FCWEgoSpd_MinDistX;
static float32 Veh_FCWEgoSpd_MinDistX_table[2*3];  /*!<@values:float32[3][2]*/
static HEADParameterTable_t Veh_FCWEgoSpd_Timer;
static float32 Veh_FCWEgoSpd_Timer_table[2*3];  /*!<@values:float32[3][2]*/
static HEADParameterTable_t DynAcuteWarnRunupStat_YawRate_AllConditin;
static float32 DynAcuteWarnRunupStat_YawRate_AllConditin_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterScalar_t DynAcuteWarnFP_DistYMax;
static HEADParameterScalar_t DynAcuteWarnFP_DistYMin;
static HEADParameterScalar_t FCWDriverbrake_lowspeed;
static HEADParameterTable_t ObjCorridorOccupancFCW_CCRSYawRate;
static float32 ObjCorridorOccupancFCW_CCRSYawRate_table[2*5];  /*!<@allow: all_cust *//*!<@values:float32[5][2]*/
static HEADParameterTable_t DynAcuteWarn_TTBAcuteClosingVelFactorHypBrk;
static const float32 DynAcuteWarn_TTBAcuteClosingVelFactorHypBrk_table[2*4] /*!<@values:float32[4][2]*/ = {0.0f, 0.82f, 8.0f, 0.82f, 8.7f, 1.1f, 15.0f, 1.1f};
static HEADParameterTable_t DynAcuteWarn_TTBAcuteDistXFactorHypBrk;
static const float32 DynAcuteWarn_TTBAcuteDistXFactorHypBrk_table[2*4] /*!<@values:float32[4][2]*/ = {0.0f, 1.2f, 12.0f, 1.2f, 13.0f, 0.9f, 15.0f, 0.9f};
static HEADParameterTable_t DynAcuteWarn_TTBAcuteDrvFactor_HypMov;
static const float32 DynAcuteWarn_TTBAcuteDrvFactor_HypMov_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 0.85f, 66.0f, 0.5f, 90.0f, 0.4f, 100.0f, 0.4f};
static HEADParameterTable_t DynAcuteWarn_TTBAcuteDrvFactor_HypBrk;
static HEADParameterTable_t DynAcuteWarn_TTBAcuteDrvFactor_HypStat;
static HEADParameterScalar_t DynAcuteWarn_TTBAcuteKeepFactor;/*!<@allow: all_cust */
static HEADParameterTable_t DynAcuteWarn_TTSPreVelFactor_HypStat;
static const float32 DynAcuteWarn_TTSPreVelFactor_HypStat_table[2*6] /*!<@values:float32[6][2]*/ = {0.0f, 1.0f, 8.33333333333f, 1.93f, 11.1111111111f, 2.2f, 22.2222222222f, 2.73f, 25.0f, 1.0f, 27.7777777778f, 1.0f};
static HEADParameterTable_t DynAcuteWarn_TTSPreDrvFactor_HypStat;
static const float32 DynAcuteWarn_TTSPreDrvFactor_HypStat_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 0.7f, 66.0f, 0.5f, 90.0f, 0.4f, 100.0f, 0.4f};
static HEADParameterTable_t DynAcuteWarn_TTSAcuteVelFactor_HypStat;
static const float32 DynAcuteWarn_TTSAcuteVelFactor_HypStat_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 0.5f, 8.33333333333f, 0.96f, 22.2222222222f, 1.4f, 23.6111111111f, 1.0f, 27.7777777778f, 1.0f};
static HEADParameterTable_t DynAcuteWarn_TTSAcuteDrvFactor_HypStat;
static const float32 DynAcuteWarn_TTSAcuteDrvFactor_HypStat_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 0.8f, 66.0f, 0.7f, 90.0f, 0.63f, 100.0f, 0.6f};
static HEADParameterScalar_t DynAcuteWarn_TTSAcuteKeepFactor_HypStat;
static HEADParameterTable_t DynAcuteWarnHypLifetime_YawRateFactor;
static float32 DynAcuteWarnHypLifetime_YawRateFactor_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterTable_t DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk;
static float32 DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk_table[2*3];  /*!<@allow: all_cust *//*!<@values:float32[3][2]*/
static HEADParameterTable_t DynAcuteWarn_TTCMax_middle_mov_SpeedFactor;
static const float32 DynAcuteWarn_TTCMax_middle_mov_SpeedFactor_table[2*4] /*!<@values:float32[4][2]*/ = {2.77777777778f, 0.8f, 13.8888888889f, 0.8f, 14.1666666667f, 1.0f, 16.6666666667f, 1.0f};
static HEADParameterTable_t DynAcuteWarn_TTSAcuteYawrateFactor;
static float32 DynAcuteWarn_TTSAcuteYawrateFactor_table[2*5];  /*!<@allow: all_cust *//*!<@values:float32[5][2]*/
static HEADModuleInternalGSM_t HEADInternalState_HaptDynWarn;
static HEADParameterScalar_t HaptDynWarn_Inhibition;
static HEADParameterTable_t HaptDynWarn_OnlyIfDynAcute;
static const float32 HaptDynWarn_OnlyIfDynAcute_table[2*6] /*!<@values:float32[6][2]*/ = {0.0f, 0.0f, 5.55555555556f, 0.0f, 8.33333333333f, 0.18f, 22.2222222222f, 0.18f, 23.6111111111f, 0.28f, 69.4444444444f, 0.28f};
static HEADParameterTable_t HaptDynWarn_OnlyIfDynAcuteBrk;
static HEADParameterScalar_t HaptDynWarn_OnlyIfDynAcuteWarnActive;
static HEADParameterScalar_t HaptDynWarn_AutoBrk2NotActive;
static HEADParameterScalar_t HaptDynWarn_AutoBrk3NotActive;
static HEADParameterScalar_t HaptDynWarn_MinEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_MaxEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_MaxEgoVelStat;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_HypProb;
static HEADParameterScalar_t HaptDynWarn_ObjProb;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_ObjProb_Stat;/*!<@allow: all_cust */
static HEADParameterScalar_t HauptDynWarn_ObjProb_Keep;/*!<@allow: all_cust */
static HEADParameterTable_t HaptDynWarn_TTBPre;
static float32 HaptDynWarn_TTBPre_table[2*8];  /*!<@allow: all_cust *//*!<@values:float32[8][2]*/
static HEADParameterScalar_t HaptDynWarn_TTBPre_HypBrk;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynTTC;
static HEADParameterScalar_t HaptDynWarn_TTSPre_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_TTSAcute_Early_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_DrvActivity_leave;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_LockTime;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_AutoBrk2KeepWait;
static HEADParameterScalar_t HaptDynWarn_MaxTime;
static HEADParameterScalar_t HaptDynWarnDriverFeedback_BrakePedal;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarnSensorSource;
static HEADParameterScalar_t HaptDynWarn_Driver_Seatbelt;
static HEADParameterScalar_t HaptDynWarn_WarnChainState;
static HEADParameterScalar_t HaptDyn_OnlyIf_LongVru_HaptDynWarn_NotActive;
static HEADParameterScalar_t HaptDyn_OnlyIf_CrossVru_HaptDynWarn_NoInActive;/*!<@allow: all_cust */
static HEADParameterScalar_t HaptDynWarn_WarnChainState_leave;
static HEADParameterScalar_t HaptDynWarn_SteerGrad_Leave;
static HEADParameterTable_t HaptDynWarn_TTBPreClosingVelFactorHypBrk;
static const float32 HaptDynWarn_TTBPreClosingVelFactorHypBrk_table[2*4] /*!<@values:float32[4][2]*/ = {0.0f, 0.82f, 8.0f, 0.82f, 9.0f, 1.1f, 15.0f, 1.1f};
static HEADParameterTable_t HaptDynWarn_TTBPreDistXFactorHypBrk;
static const float32 HaptDynWarn_TTBPreDistXFactorHypBrk_table[2*4] /*!<@values:float32[4][2]*/ = {0.0f, 1.2f, 12.0f, 1.2f, 13.0f, 1.0f, 15.0f, 1.0f};
static HEADParameterTable_t HaptDynWarn_TTBPreDrvFactor_HypMov;
static const float32 HaptDynWarn_TTBPreDrvFactor_HypMov_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 0.9f, 66.0f, 0.8f, 90.0f, 0.8f, 100.0f, 0.6f};
static HEADParameterTable_t HaptDynWarn_TTBPreDrvFactor_HypBrk;
static HEADParameterTable_t HaptDynWarn_DrvActFactTTBPre_HypStat;
static HEADParameterScalar_t HaptDynTTBAcuteKeepFactor;/*!<@allow: all_cust */
static HEADParameterTable_t HaptDynWarn_TTSPreVelFactor_HypStat;
static const float32 HaptDynWarn_TTSPreVelFactor_HypStat_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 8.33333333333f, 2.75f, 22.2222222222f, 3.3f, 25.0f, 1.0f, 27.7777777778f, 1.0f};
static HEADParameterTable_t HaptDynWarn_TTSPreDrvFactor_HypStat;
static const float32 HaptDynWarn_TTSPreDrvFactor_HypStat_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 0.7f, 66.0f, 0.7f, 90.0f, 0.4f, 100.0f, 0.4f};
static HEADParameterScalar_t HaptDynWarn_TTSPreKeepFactor_HypStat;
static HEADParameterTable_t HaptDynWarn_TTSAcuteVelFactor_HypStat;
static const float32 HaptDynWarn_TTSAcuteVelFactor_HypStat_table[2*6] /*!<@values:float32[6][2]*/ = {0.0f, 0.56f, 8.33333333333f, 0.96f, 19.4444444444f, 1.24f, 22.2222222222f, 1.28f, 23.6111111111f, 1.0f, 27.7777777778f, 1.0f};
static HEADParameterTable_t HaptDynWarn_TTSAcuteDrvFactor_HypStat;
static const float32 HaptDynWarn_TTSAcuteDrvFactor_HypStat_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 0.8f, 66.0f, 0.8f, 90.0f, 0.8f, 100.0f, 0.6f};
static HEADParameterScalar_t HaptDynWarn_TTSAcuteKeepFactor_HypStat;
static HEADModuleInternalGSM_t HEADInternalState_Prefill;
static HEADParameterScalar_t Prefill_Inhibition;
static HEADParameterScalar_t Prefill_OnlyIfDynAcuteWarnActive;
static HEADParameterScalar_t Prefill_OnlyIfVehAutoBrk1NotActive;
static HEADParameterScalar_t Prefill_OnlyIfVehAutoBrk2NotActive;
static HEADParameterScalar_t Prefill_OnlyIfVehAutoBrk3NotActive;
static HEADParameterScalar_t Prefill_OnlyIfCrossVruPreBrkNotActive;
static HEADParameterScalar_t Prefill_OnlyIfLongVruBrk1NotActive;
static HEADParameterScalar_t Prefill_LockTime;/*!<@allow: all_cust */
static HEADParameterScalar_t Prefill_MaxTime;/*!<@allow: all_cust */
static HEADParameterScalar_t Prefill_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t PrefillDriverFeedback_BrakePedal;/*!<@allow: all_cust */
static HEADParameterScalar_t prefill_DrvActivity_keeppasive;/*!<@allow: all_cust */
static HEADParameterScalar_t Prefill_Driver_Seatbelt;
static HEADParameterScalar_t Prefill_PrefillQualifier;
static HEADParameterScalar_t Prefill_AEBSwitch;
static HEADParameterScalar_t Prefill_AEBSwitch_Leave;
static HEADParameterScalar_t Prefill_DriverFeedback_leave;
static HEADParameterScalar_t Prefill_DriverActivity;/*!<@allow: all_cust */
static HEADParameterScalar_t PrefillSensorSource;
static HEADParameterScalar_t Prefill_PrefillQualifier_leave;
static HEADParameterScalar_t Prefill_SteerGrad_Leave;
static HEADParameterScalar_t Prefill_SteerGrad_Keep;
static HEADModuleInternalGSM_t HEADInternalState_Veh_AutoBrk1;
static HEADModOutBrakeFunctionPar_t HEADFuncOut_Veh_AutoBrk1Par;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_Inhibition;
static HEADParameterTable_t VehAutoBrk1_OnlyIfDynAcuteActive;
static const float32 VehAutoBrk1_OnlyIfDynAcuteActive_table[2*6] /*!<@values:float32[6][2]*/ = {0.0f, 0.0f, 5.55555555556f, 0.0f, 8.33333333333f, 0.2f, 22.2222222222f, 0.2f, 23.6111111111f, 0.3f, 69.4444444444f, 0.3f};
static HEADParameterScalar_t VehAutoBrk1_OnlyIfCrossVruPreBrkNotActive;
static HEADParameterScalar_t VehAutoBrk1_OnlyIfCrossVruPreBrkNotWait;
static HEADParameterScalar_t VehAutoBrk1_OnlyIfLongVruBrkNotActive;
static HEADParameterScalar_t VehAutoBrk1_OnlyIfLongVruBrkNotWait;
static HEADParameterScalar_t VehAutoBrk1_MinEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_MaxEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_MaxEgoVel_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_HypProb;
static HEADParameterScalar_t VehAutoBrk1_HypProb_keep;
static HEADParameterScalar_t VehAutoBrk1_ObjProb;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_ObjProb_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_ObjProb_Keep;/*!<@allow: all_cust */
static HEADParameterTable_t VehAutoBrk1_ObjProb_keep_HypStat;
static float32 VehAutoBrk1_ObjProb_keep_HypStat_table[2*4];  /*!<@allow: all_cust *//*!<@values:float32[4][2]*/
static HEADParameterScalar_t VehAutoBrk1_DriverActivity;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_DriverFeedback;/*!<@allow: all_cust */
static HEADParameterTable_t VehAutoBrk1_TTBAcute;
static float32 VehAutoBrk1_TTBAcute_table[2*9];  /*!<@allow: all_cust *//*!<@values:float32[9][2]*/
static HEADParameterTable_t VehAutoBrk1_TTBAcute_HypBrk;
static float32 VehAutoBrk1_TTBAcute_HypBrk_table[2*5];  /*!<@allow: all_cust *//*!<@values:float32[5][2]*/
static HEADParameterScalar_t VehAutoBrk1_TTCMin;
static HEADParameterScalar_t VehAutoBrk1_TTCMax;
static HEADParameterScalar_t VehAutoBrk1_TTSAcute_HypStat;/*!<@allow: all_cust */
static HEADParameterTable_t VehAutoBrk1_ANecLong_keep;
static float32 VehAutoBrk1_ANecLong_keep_table[2*6];  /*!<@allow: all_cust *//*!<@values:float32[6][2]*/
static HEADParameterScalar_t VehAutoBrk1_ANecLong_keep_HypStat;
static HEADParameterScalar_t VehAutoBrk1_ClosingVel;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_VrelX_keep;
static HEADParameterScalar_t VehAutoBrk1_DistXSafe;/*!<@allow: all_cust */
static HEADParameterTable_t VehAutoBrk1_AllConditionsTRUEActivityStat;
static HEADParameterScalar_t VehAutoBrk1_LockTime;/*!<@allow: all_cust */
static HEADParameterTable_t VehAutoBrk1_AllowedMaxTime_BrkReq_leave;
static float32 VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterScalar_t VehAutoBrk1_HypProb_keep_OR1;
static HEADParameterScalar_t VehAutoBrk1_ObjProb_keep_OR1;/*!<@allow: all_cust */
static HEADParameterTable_t VehAutoBrk1_ObjProb_keep_HypStat_OR1;
static HEADParameterTable_t VehAutoBrk1_ANecLong_Keep_OR1;
static HEADParameterScalar_t VehAutoBrk1_VRel_KeepWait_OR1;
static HEADParameterScalar_t VehAutoBrk1_AutoBrk3InWait_Leave_OR2;
static HEADParameterScalar_t VehAutoBrk1_DriverFeedback_leave;
static HEADParameterScalar_t VehAutoBrk1_DriverActivity_Leave_OR4;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk1_MinEgoVel_Leave_OR5;/*!<@allow: all_cust */
static HEADParameterScalar_t Veh_AutoBrk1_BrakeChainState_leave;
static HEADParameterScalar_t Veh_AutoBrk1SensorSource;
static HEADParameterScalar_t Autobrk1_Driver_Seatbelt;
static HEADParameterScalar_t Veh_AutoBrk1_BrakeChainState;
static HEADParameterScalar_t Veh_AutoBrk1_AEBSwitch;
static HEADParameterScalar_t Veh_AutoBrk1_AEBSwitch_Leave;
static HEADParameterScalar_t VehAutoBrk1_SteerGrad_Leave;
static HEADParameterScalar_t VehAutoBrk1_SteerGrad_Keep;
static HEADParameterScalar_t CrossVru_Brk1_OncomingKeepPassive;
static HEADParameterTable_t VehAutoBrk1_ANecLong;
static float32 VehAutoBrk1_ANecLong_table[2*8];  /*!<@allow: all_cust *//*!<@values:float32[8][2]*/
static HEADParameterTable_t ObjCorridorOccupancy_YawRate;
static HEADParameterTable_t ObjCorridorOccupancy_stationYawRate;
static float32 ObjCorridorOccupancy_stationYawRate_table[2*6];  /*!<@allow: all_cust *//*!<@values:float32[6][2]*/
static HEADParameterTable_t VehBrk1_NecLat;
static float32 VehBrk1_NecLat_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t Veh_AutoBrk1EgoSpd_Timer;
static float32 Veh_AutoBrk1EgoSpd_Timer_table[2*6];  /*!<@values:float32[6][2]*/
static HEADParameterTable_t Veh_AutoBrk1EgoSpd_MinDistX;
static float32 Veh_AutoBrk1EgoSpd_MinDistX_table[2*8];  /*!<@values:float32[8][2]*/
static HEADParameterTable_t BRK1AllConditionsTRUE_MovingYawrate;
static float32 BRK1AllConditionsTRUE_MovingYawrate_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterScalar_t BRKFP_DistYMax;
static HEADParameterScalar_t BRK1FP_DistYMin;
static HEADParameterScalar_t Veh_AutoBrk1Driverbrake_lowspeed;
static HEADParameterTable_t VehAutoBrk1_AllConditionsTRUE_DriverBrake;
static const float32 VehAutoBrk1_AllConditionsTRUE_DriverBrake_table[2*2] /*!<@values:float32[2][2]*/ = {0.0f, 0.0f, 1.0f, 0.05f};
static HEADParameterTable_t DynAcuteWarn_EgoAccX_NAcc_Brk;
static float32 DynAcuteWarn_EgoAccX_NAcc_Brk_table[2*8];  /*!<@values:float32[8][2]*/
static HEADParameterTable_t VehAutoBrk1_TTBAcuteClosingVelFactorHypBrk;
static HEADParameterTable_t VehAutoBrk1_TTBAcuteDistXFactorHypBrk;
static HEADParameterTable_t VehAutoBrk1_TTBAcuteDrvFactor_HypMov;
static const float32 VehAutoBrk1_TTBAcuteDrvFactor_HypMov_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 1.0f, 66.0f, 0.8f, 90.0f, 0.7f, 100.0f, 0.6f};
static HEADParameterTable_t VehAutoBrk1_TTBAcuteDrvFactor_HypBrk;
static HEADParameterTable_t VehAutoBrk1_TTBAcuteDrvFactor_HypStat;
static const float32 VehAutoBrk1_TTBAcuteDrvFactor_HypStat_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 1.0f, 66.0f, 0.7f, 90.0f, 0.63f, 100.0f, 0.6f};
static HEADParameterTable_t VehAutoBrk1_TTSAcuteVelFactor_HypStat;
static const float32 VehAutoBrk1_TTSAcuteVelFactor_HypStat_table[2*6] /*!<@values:float32[6][2]*/ = {0.0f, 0.45f, 2.77777777778f, 0.45f, 5.55555555556f, 0.58f, 13.8888888889f, 1.12f, 22.2222222222f, 1.66f, 23.6111111111f, 1.66f};
static HEADParameterTable_t VehAutoBrk1_TTSAcuteDrvFactor_HypStat;
static HEADModuleInternalGSM_t HEADInternalState_Veh_AutoBrk2;
static HEADModOutBrakeFunctionPar_t HEADFuncOut_Veh_AutoBrk2Par;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk2_Inhibition;
static HEADParameterScalar_t VehAutoBrk2_OnlyIfAutoBrk1Active;
static HEADParameterScalar_t VehAutoBrk2_WaitForAutoBrk1Passive;
static HEADParameterScalar_t Veh_AutoBrk2SensorSource;
static HEADParameterScalar_t Veh_AutoBrk2_BrakeChainState;
static HEADParameterScalar_t VehAutoBrk2_MaxEgoVel_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk2_OnlyIfAutoBrk1Active_CCRB;
static HEADModuleInternalGSM_t HEADInternalState_Veh_AutoBrk3;
static HEADModOutBrakeFunctionPar_t HEADFuncOut_Veh_AutoBrk3Par;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk3_Inhibition;
static HEADParameterScalar_t VehAutoBrk3_OnlyIfVehAutoBrk2Active;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk3_WaitForAutoBrk1Passive;
static HEADParameterScalar_t VehAutoBrk3_MinEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk3_MaxEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk3_HypProb;
static HEADParameterScalar_t VehAutoBrk3_ObjProb;
static HEADParameterScalar_t VehAutoBrk3_TTC;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk3_TTC3;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk3_TTC4;/*!<@allow: all_cust */
static HEADParameterScalar_t VehAutoBrk3_ANecLong;/*!<@allow: all_cust */
static HEADParameterTable_t VehAutoBrk3_AllowedMaxTime_leave;
static float32 VehAutoBrk3_AllowedMaxTime_leave_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterScalar_t Veh_AutoBrk3SensorSource;
static HEADParameterScalar_t Veh_AutoBrk3_BrakeChainState;
static HEADParameterScalar_t VehAutoBrk3_MaxEgoVel_HypStat;/*!<@allow: all_cust */
static HEADModuleInternalGSM_t HEADInternalState_HBA_TA;
static HEADModuleOutputHBAFunctionPar_t HEADFuncOut_HBA_TAPar;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_TA_Inhibition;
static HEADParameterScalar_t HBA_TA_MinEgoVel;
static HEADParameterScalar_t HBA_TA_MaxEgoVel_Veh;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_TA_MaxEgoVel_HypStat_Veh;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_TA_MaxEgoVel_LongVru;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_TA_HypProb;
static HEADParameterScalar_t HBA_TA_ObjProb_HypMov;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_TA_ObjProb_HypStat;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_TA_DrvAcitivity;
static HEADParameterScalar_t HBA_TA_TTC;
static HEADParameterScalar_t HBA_TA_ANecLong;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_TA_ANecLong_Keep;
static HEADParameterScalar_t HBA_TA_LockTime;/*!<@allow: all_cust */
static HEADParameterScalar_t HBATA_DrvActivity_leave;/*!<@allow: all_cust */
static HEADParameterScalar_t HBATA_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_TA_Driver_Seatbelt;
static HEADParameterScalar_t HBA_TA_HBAQualifier;
static HEADParameterScalar_t HBA_TA_AEBSwitch;
static HEADParameterScalar_t HBA_TA_AEBSwitch_Leave;
static HEADParameterScalar_t HBA_TA_HBAQualifier_leave;
static HEADParameterScalar_t HBA_TA_DriverFeedback_leave;
static HEADParameterScalar_t HBATASensorSource;
static HEADParameterScalar_t HBA_SteerGrad_Leave;
static HEADParameterScalar_t HBA_SteerGrad_Keep;
static HEADParameterScalar_t HBA_TATTSPre;
static HEADParameterScalar_t HBA_TAAllContiditionTrue;
static HEADModuleInternalGSM_t HEADInternalState_HBA_VDS;
static HEADModuleOutputHBAFunctionPar_t HEADFuncOut_HBA_VDSPar;/*!<@allow: all_cust */
static HEADParameterScalar_t HBA_VDS_StayInOFF;
static HEADModuleInternalGSM_t HEADInternalState_CrossVru_DynAcuteWarn;
static const HEADModOutWarnFunctionPar_t HEADFuncOut_CrossVru_DynAcuteWarnPar = {0};
static HEADParameterScalar_t CrossVruDynAcuteWarn_Inhibition;
static HEADParameterScalar_t CrossVruDynAcuteWarn_MinEgoVel;
static HEADParameterScalar_t CrossVruDynAcuteWarn_MaxEgoVel;
static HEADParameterScalar_t CrossVruDynAcuteWarn_HypProb;
static HEADParameterTable_t CrossVruDynAcuteWarn_TTC4;
static float32 CrossVruDynAcuteWarn_TTC4_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterScalar_t CrossVruDynAcuteWarn_TTC3min;
static HEADParameterTable_t CrossVruDynAcuteWarn_TTSPre;
static float32 CrossVruDynAcuteWarn_TTSPre_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterTable_t CrossVruDynAcuteWarn_TTSAcute;
static float32 CrossVruDynAcuteWarn_TTSAcute_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterScalar_t CrossVruDynAcuteWarn_MaxTime;
static HEADParameterScalar_t CrossVruDynAcuteWarn_LockTime;
static HEADParameterScalar_t CrossVruDynAcuteWarn_MinTime;
static HEADParameterScalar_t CrossVruDynAcuteWarn_KeepIfPedBrkActive;
static HEADParameterTable_t CrossVru_DynAcuteWarnAllConditionsTRUEStat;
static float32 CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterScalar_t Brake_Passive_Tran4_CondG0_CheckwithinCorridorPed_Warn;
static HEADParameterTable_t VehAutoBrk1_AllConditionsTRUEDrivActPedcoll_warn;
static const float32 VehAutoBrk1_AllConditionsTRUEDrivActPedcoll_warn_table[2*4] /*!<@values:float32[4][2]*/ = {0.0f, 0.0f, 30.0f, 0.12f, 70.0f, 0.12f, 100.0f, 0.12f};
static HEADParameterScalar_t CrossVru_FPS_Warn_Inhibition;
static HEADParameterScalar_t CrossVru_DynAcuteSensorSource;
static HEADParameterScalar_t CrossVRU_DynAcutewarn_Driver_Seatbelt;
static HEADParameterScalar_t CrossVruDynAcuteWarn_DrvActivity_Leave;
static HEADParameterScalar_t CrossVru_DynAcuteWarn_SteerGrad_Leave;
static HEADParameterScalar_t CrossVruDynAcuteWarn_TTCmax_Late;
static HEADParameterScalar_t CrossVru_DynAcuteWarnObjMovDir;
static HEADParameterScalar_t CrossVru_DynAcuteWarnObjMovDir_Cross;
static HEADParameterTable_t CrossVRUDynAcuteWarn_EgoAccX_NAcc;
static float32 CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[2*8];  /*!<@values:float32[8][2]*/
static HEADParameterTable_t CrossVruDynAcuteWarn_NecLat;
static float32 CrossVruDynAcuteWarn_NecLat_table[2*8];  /*!<@values:float32[8][2]*/
static HEADParameterScalar_t CrossVruDynAcuteWarn_HypProb_Keep;
static HEADParameterScalar_t CrossVruDynAcuteWarn_MaxDistX;
static HEADParameterTable_t CrossVru_DynAcuteWarnAllConditionsLowSpeed;
static float32 CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[2*6];  /*!<@values:float32[6][2]*/
static HEADParameterScalar_t CrossVruDynAcuteWarn_ObjVelY;
static HEADParameterTable_t CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad;
static float32 CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[2*4];  /*!<@values:float32[4][2]*/
static HEADParameterScalar_t FCWCrossVRUbrake_lowspeed;
static HEADParameterTable_t CrossVruDynAcuteWarn_TTC4DrvFactor;
static float32 CrossVruDynAcuteWarn_TTC4DrvFactor_table[2*4];  /*!<@values:float32[4][2]*/
static HEADParameterScalar_t CrossVruDynAcuteWarn_TTC4KeepFactor;
static HEADParameterScalar_t CrossVru_DynAcuteWarnTTC4Late_Factor;
static HEADParameterScalar_t CrossVru_DynAcuteWarnTTC4Early_Factor;
static HEADParameterTable_t CrossVruDynAcuteWarn_HypProbFactor;
static float32 CrossVruDynAcuteWarn_HypProbFactor_table[2*5];  /*!<@values:float32[5][2]*/
static HEADParameterTable_t CrossVruDynAcuteWarn_TTSAcuteFactor;
static float32 CrossVruDynAcuteWarn_TTSAcuteFactor_table[2*6];  /*!<@values:float32[6][2]*/
static HEADModuleInternalGSM_t HEADInternalState_CrossVru_HaptDynWarn;
static HEADParameterScalar_t CrossVru_HaptDynWarn_Inhibition;
static HEADParameterScalar_t CrossVru_OnlyIfDynAcuteActive;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVru_HaptDynWarnOnlyIf_HaptDynWarn_NotActive;
static HEADParameterScalar_t CrossVru_OnlyIf_LongVru_HaptDynWarn_NotActive;
static HEADParameterScalar_t CrossVru_HaptDynWarn_MinEgoVel;
static HEADParameterScalar_t CrossVru_HaptDynWarn_MaxEgoVel;
static HEADParameterScalar_t CrossVru_HaptDynWarn_HypProb;
static HEADParameterTable_t CrossVruHaptWarn_TTC4EgoVel;
static float32 CrossVruHaptWarn_TTC4EgoVel_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterScalar_t CrossVru_HaptDynWarn_TTCmax;
static HEADParameterScalar_t CrossVru_HaptDynWarn_TTC3min;
static HEADParameterScalar_t CrossVru_HaptDynWarn_MaxTime;
static HEADParameterScalar_t CrossVru_HaptDynWarn_LockTime;
static HEADParameterScalar_t CrossVru_HaptDynWarn_MinTime;
static HEADParameterScalar_t CrossVru_HaptDynWarn_DynAcuteSensorSource;
static HEADParameterScalar_t CrossVru_HaptDynWarn_DynAcutewarn_Driver_Seatbelt;
static HEADParameterScalar_t CrossVru_HaptDynWarn_DrvActivity_Leave;
static HEADParameterScalar_t CrossVruHaptDyn_ANecLong;
static HEADParameterScalar_t CrossVruHaptDyn_ANecLong_Keep;
static HEADParameterScalar_t CrossVruHaptDynWarn_WarnChainState;
static HEADParameterScalar_t CrossVruHaptDynWarn_WarnChainState_leave;
static HEADParameterScalar_t CrossVru_HaptDynWarn_SteeringGrad_leave;
static HEADParameterScalar_t CrossVru_HaptDynWarnOnlyIf_CrossVru_PreBrk_Not_In_Actv;
static HEADParameterScalar_t CrossVruHaptDynWarn_HypProb_KeepPassive;
static HEADParameterTable_t CrossVru_HaptDynWarn_TTC4DrvFactor;
static HEADParameterScalar_t CrossVru_HaptDynWarn_TTC4KeepFactor;
static HEADModuleInternalGSM_t HEADInternalState_CrossVru_HBA;
static const HEADModuleOutputHBAFunctionPar_t HEADFuncOut_CrossVru_HBAPar = {1u, {-10.0f, 3.0f, -6.0f, 2.0f, -6.0f, 2.0f}, 3u, 0u, {0u, 0u, 0u, 0u}, 2u, -1, 0u, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}, 3u, -0.5f, 0u};
static HEADParameterScalar_t CrossVruHBA_Inhibition;
static HEADParameterScalar_t CrossVruHBA_OnlyIfCrossVruAcuteWarn;
static HEADParameterScalar_t CrossVruHBA_MinEgoVel;
static HEADParameterScalar_t CrossVruHBA_MaxEgoVel;
static HEADParameterScalar_t CrossVruHBA_HypProb;
static HEADParameterScalar_t CrossVruHBA_DrvActivity;
static HEADParameterScalar_t CrossVruHBA_ANecLong;
static HEADParameterScalar_t CrossVruHBA_ANecLong_Keep;
static HEADParameterScalar_t CrossVruHBA_LockTime;
static HEADParameterScalar_t CrossVruHBA_KeepIfCrossVruPreBrkActive;
static HEADParameterScalar_t CrossVru_HBASensorSource;
static HEADParameterScalar_t CrossHBATA_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVru_HBADriverActivity_Leave;
static HEADParameterScalar_t CrossVru_HBA_Driver_Seatbelt;
static HEADParameterScalar_t CrossVru_HBA_HBAQualifier;
static HEADParameterScalar_t HBA_AEBSwitch;
static HEADParameterScalar_t HBA_AEBSwitch_Leave;
static HEADParameterScalar_t CrossVru_HBA_DriverFeedback_leave;
static HEADParameterScalar_t CrossVru_HBA_HBAQualifier_leave;
static HEADParameterScalar_t CrossVru_HBA_SteerGrad_Leave;
static HEADParameterScalar_t CrossVru_HBA_SteerGrad_Keep;
static HEADParameterScalar_t CrossVruHBA_HypProb_KeepPassive;
static HEADModuleInternalGSM_t HEADInternalState_CrossVru_Prefill;
static HEADParameterScalar_t CrossVru_PreFill_Inhibition;
static HEADParameterScalar_t CrossVruPreFill_OnlyIfVehAutoBrk1NotActive;
static HEADParameterScalar_t CrossVruPreFill_OnlyIfCrossVruPreBrkNotActive;
static HEADParameterScalar_t CrossVruPreFill_OnlyIfLongVruPreBrkNotActive;
static HEADParameterScalar_t CrossVruPreFill_MinEgoVel;
static HEADParameterScalar_t CrossVruPreFill_MaxEgoVel;
static HEADParameterScalar_t CrossVruPreFill_HypProb;
static HEADParameterTable_t CrossVruPrefill_TTC4;
static float32 CrossVruPrefill_TTC4_table[2*4];  /*!<@values:float32[4][2]*/
static HEADParameterScalar_t CrossVruPrefill_ANecLong;
static HEADParameterScalar_t CrossVruPrefill_MaxTime;
static HEADParameterScalar_t CrossVruPrefill_LockTime;
static HEADParameterScalar_t CrossVru_PrefillSensorSource;
static HEADParameterScalar_t CrossPrefill_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossPrefillDriverFeedback_BrakePedal;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVRU_Prefill_Driver_Seatbelt;
static HEADParameterScalar_t CrossVru_Prefill_PrefillQualifier;
static HEADParameterScalar_t CrossVru_Prefill_AEBSwitch;
static HEADParameterScalar_t CrossVru_Prefill_AEBSwitch_Leave;
static HEADParameterScalar_t CrossVru_DriverFeedback_leave;
static HEADParameterScalar_t CrossVru_Prefill_DriverActivity;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVru_DrvActivity_keeppasive;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVru_Prefill_PrefillQualifier_leave;
static HEADParameterScalar_t CrossVru_Prefill_SteerGrad_Leave;
static HEADParameterScalar_t CrossVruPrefill_OnlyIfCrossVruAcuteWarn;
static HEADParameterScalar_t CrossVru_Prefill_SteerGrad_Keep;
static HEADParameterScalar_t CrossVruPrefill_HypProb_KeepPassive;
static HEADModuleInternalGSM_t HEADInternalState_CrossVru_PreBrk;
static const HEADModOutBrakeFunctionPar_t HEADFuncOut_CrossVru_PreBrkPar = {0.0f, {13.6111111111f, 13.8888888889f, 13.8888888889f, 13.8888888889f, 16.1111111111f, 16.6666666667f, 18.0555555556f, 16.6666666667f, 18.0555555556f, 16.6666666667f}, 5u, {0.0f, 13.8888888889f, 13.6111111111f, 13.8888888889f, 13.8888888889f, 13.8888888889f, 16.1111111111f, 16.6666666667f, 18.0555555556f, 16.6666666667f}, 5u, {0.0f, -4.0f, 0.0f, -4.0f, 0.0f, -4.0f, 0.0f, -4.0f, 0.0f, -4.0f, 0.0f, -4.0f, 0.0f, -4.0f}, 7u, {8.33333333333f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f}, 7u, {8.33333333333f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f}, 7u, {8.33333333333f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f}, 7u, {8.33333333333f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f, 11.1111111111f, -4.0f}, 5u, 0, 65.0f, 65.0f, 65.0f, 65.0f, 85.0f, {-71.0f, 0.0f, -70.0f, 1.0f, -70.0f, 1.0f, -70.0f, 1.0f, -70.0f, 1.0f}, 5u, 50, 4u, 0};
static HEADParameterScalar_t CrossVruPreBrk_Inhibition;
static HEADParameterScalar_t CrossVruPreBrk_OnlyIfCrossVruDynWarnActive;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVruPreBrk_OnlyIfVehAutoBrk1NotActive;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVruPreBrk_OnlyIfVehAutoBrk1NotWait;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVruPreBrk_OnlyIfLongVruBrk1NotActive;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVruPreBrk_OnlyIfLongVruBrk1NotWait;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVruPreBrk_MinEgoVel;
static HEADParameterScalar_t CrossVruPreBrk_MinEgoVel_Keep;
static HEADParameterScalar_t CrossVruPreBrk_MaxEgoVel;
static HEADParameterScalar_t CrossVruPreBrk_HypProb;
static HEADParameterScalar_t CrossVruPreBrk_HypProb_Keep;
static HEADParameterScalar_t CrossVruPreBrk_DrvFeedback;
static HEADParameterScalar_t CrossVruPreBrk_DrvActivity;
static HEADParameterTable_t CrossVruPreBrk_TTC4EgoVel;
static float32 CrossVruPreBrk_TTC4EgoVel_table[2*9];  /*!<@values:float32[9][2]*/
static HEADParameterScalar_t CrossVruPreBrk_TTC3min;
static HEADParameterScalar_t CrossVruPreBrk_ANecLong;
static HEADParameterScalar_t CrossVruPreBrk_ANecLong_Keep;
static HEADParameterScalar_t CrossVruPreBrk_DistXSafe;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVruPreBrk_ClosingVel;
static HEADParameterScalar_t CrossVruPreBrk_LockTime;
static HEADParameterScalar_t CrossVruPreBrk_VRel_KeepWait_OR1;
static HEADParameterScalar_t Brake_Passive_Tran4_CondG0_CheckwithinCorridorPed;
static HEADParameterTable_t VehAutoBrk1_AllConditionsTRUEDrivActPedcoll;
static HEADParameterScalar_t CrossVru_FPS_PreBrk_Inhibition;
static HEADParameterScalar_t CrossVru_PreBrkSensorSource;
static HEADParameterScalar_t CrossVru_Prebrk_Driver_Seatbelt;
static HEADParameterScalar_t CrossVru_PreBrk_BrakeChainState;
static HEADParameterScalar_t CrossVru_Brk1_Curve_Min;
static HEADParameterScalar_t CrossVru_Brk1_Curve_Max;
static HEADParameterScalar_t CrossVru_PreBrk_LatDistY_Thr_min;
static HEADParameterScalar_t CrossVru_AutoBrk1_AEBSwitch;
static HEADParameterScalar_t CrossVru_AutoBrk1_AEBSwitch_Leave;
static HEADParameterScalar_t CrossVru_PreBrk_DriverFeedback_leave;
static HEADParameterScalar_t CrossVru_DriverActivity_Leave_OR4;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVru_PreBrk_BrakeChainState_leave;
static HEADParameterScalar_t CrossVru_PreBrk_SteerGrad_Leave;
static HEADParameterScalar_t CrossVru_PreBrk_SteerGrad_Keep;
static HEADParameterScalar_t CrossVru_PreBrk1_ObjMovDir;
static HEADParameterScalar_t CrossVru_PreBrk_ObjVelY;
static HEADParameterTable_t CrsVRUBRK1AllConditionsTRUE_MovingYawrate;
static HEADParameterScalar_t CrossVru_PreBrkDriverBrake_lowspeed;
static HEADParameterTable_t CrossVRUPreBrakeAllConditionsTRUE_SteerGrad;
static HEADParameterTable_t CrossVruPreBrk_TTC4DrvFactor;
static const float32 CrossVruPreBrk_TTC4DrvFactor_table[2*5] /*!<@values:float32[5][2]*/ = {0.0f, 1.0f, 33.0f, 1.0f, 66.0f, 0.75f, 90.0f, 0.65f, 100.0f, 0.65f};
static HEADModuleInternalGSM_t HEADInternalState_CrossVru_PreBrk2;
static const HEADModOutBrakeFunctionPar_t HEADFuncOut_CrossVru_PreBrk2Par = {0.0f, {0.0f, 13.8888888889f, 13.6111111111f, 13.8888888889f, 13.8888888889f, 13.8888888889f, 16.1111111111f, 16.6666666667f, 18.0555555556f, 16.6666666667f}, 5u, {0.0f, 13.8888888889f, 13.6111111111f, 13.8888888889f, 13.8888888889f, 13.8888888889f, 16.1111111111f, 16.6666666667f, 18.0555555556f, 16.6666666667f}, 5u, {0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f}, 7u, {0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f}, 7u, {0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f}, 7u, {0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f, 0.0f, -10.0f}, 7u, {0.0f, -4.0f, 0.0f, -4.0f, 0.0f, -4.0f, 0.0f, -4.0f, 0.0f, -4.0f}, 5u, 0, 65.0f, 65.0f, 65.0f, 65.0f, 85.0f, {-71.0f, 0.0f, -70.0f, 1.0f, -70.0f, 1.0f, -70.0f, 1.0f, -70.0f, 1.0f}, 5u, 50, 4u, 0};
static HEADParameterScalar_t CrossVruPreBrk2_Inhibition;
static HEADParameterScalar_t CrossVruPreBrk2_OnlyIfCrossVruPreBrk1;
static HEADParameterScalar_t CrossVruPreBrk2_HypProb;
static HEADParameterScalar_t CrossVruPreBrk2_WaitForCrossVruBrk1Passive;/*!<@allow: all_cust */
static HEADParameterScalar_t CrossVru_PreBrklSensorSource;
static HEADParameterScalar_t CrossVru_PreBrk2_BrakeChainState;
static HEADParameterScalar_t CrossVruPreBrk2_HypProb_keep;
static HEADModuleInternalGSM_t HEADInternalState_LongVru_DynAcuteWarn;
static const HEADModOutWarnFunctionPar_t HEADFuncOut_LongVru_DynAcuteWarnPar = {1};
static HEADParameterScalar_t LongVruDynAcuteWarn_Inhibition;
static HEADParameterScalar_t LongVruDynAcuteWarn_MinEgoVel;
static HEADParameterScalar_t LongVruDynAcuteWarn_MaxEgoVel;
static HEADParameterScalar_t LongVruDynAcuteWarn_HypProb;
static HEADParameterScalar_t LongVruDynAcuteWarn_HypProb_Keep;
static HEADParameterScalar_t LongVruDynAcuteWarn_ObjProb;
static HEADParameterScalar_t LongVruDynAcuteWarn_TTBAcute;
static HEADParameterScalar_t LongVruDynAcuteWarn_TTCMin;
static HEADParameterScalar_t LongVruDynAcuteWarn_MinDistX;
static HEADParameterScalar_t LongVruDynAcuteWarn_TTSPre;
static HEADParameterScalar_t LongVruDynAcuteWarn_TTSAcute;
static HEADParameterScalar_t LongVruDynAcuteWarn_MaxTime;
static HEADParameterScalar_t LongVruDynAcuteWarn_LockTime;
static HEADParameterScalar_t LongVruDynAcuteWarn_MinTime;
static HEADParameterScalar_t LongVruDynAcuteWarn_KeepIfLongVruBrkActive;
static HEADParameterScalar_t LongVru_DynAcutelSensorSource;
static HEADParameterScalar_t LongVru_DynAcute_Driver_Seatbelt;
static HEADParameterScalar_t LongVruDynAcute_DrvActivity_Leave;
static HEADParameterScalar_t LongVru_DynAcuteWarn_SteerGrad_Leave;
static HEADParameterScalar_t LongVruDynAcuteWarn_HypProb_StationVRU;
static HEADParameterScalar_t LongVruDynAcuteWarn_HypProb_StationVRU_Keep;
static HEADParameterTable_t LongVRUDynAcuteWarn_ObjCorridor_Stat;
static float32 LongVRUDynAcuteWarn_ObjCorridor_Stat_table[2*7];  /*!<@allow: all_cust *//*!<@values:float32[7][2]*/
static HEADParameterScalar_t LongVru_DynAcuteWarnObjMovDir;
static HEADParameterTable_t LongVruDynAcuteWarn_TTCMax_middle_ped;
static float32 LongVruDynAcuteWarn_TTCMax_middle_ped_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVruDynAcuteWarn_TTCMax_early_ped;
static float32 LongVruDynAcuteWarn_TTCMax_early_ped_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVruDynAcuteWarn_TTCMax_late_ped;
static float32 LongVruDynAcuteWarn_TTCMax_late_ped_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVruDynAcuteWarn_TTCMax_middle_cyclist;
static float32 LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVruDynAcuteWarn_TTCMax_early_cyclist;
static float32 LongVruDynAcuteWarn_TTCMax_early_cyclist_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVruDynAcuteWarn_TTCMax_late_cyclist;
static float32 LongVruDynAcuteWarn_TTCMax_late_cyclist_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVRUDynAcuteWarn_EgoAccX_NAcc;
static float32 LongVRUDynAcuteWarn_EgoAccX_NAcc_table[2*10];  /*!<@values:float32[10][2]*/
static HEADParameterScalar_t LongVru_DynAcuteWarnMaxDistX;
static HEADParameterTable_t LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate;
static float32 LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVruDynAcuteWarn_NecLatAcc;
static float32 LongVruDynAcuteWarn_NecLatAcc_table[2*6];  /*!<@values:float32[6][2]*/
static HEADParameterTable_t LongVRUDynAcuteWarn_ObjCorridor_Sta;
static float32 LongVRUDynAcuteWarn_ObjCorridor_Sta_table[2*7];  /*!<@allow: all_cust *//*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVRUDynAcuteWarn_AllCondtionLowSpd;
static float32 LongVRUDynAcuteWarn_AllCondtionLowSpd_table[2*4];  /*!<@allow: all_cust *//*!<@values:float32[4][2]*/
static HEADParameterTable_t LongVruDynAcuteWarn_TTC4;
static float32 LongVruDynAcuteWarn_TTC4_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterScalar_t LongVru_DynAcuteWarnMaxVrelY;
static HEADParameterTable_t LongVRUDynAcuteWarnAllConditionsTRUE_SteerGrad;
static HEADParameterScalar_t FCWLongVRUbrake_lowspeed;
static HEADParameterTable_t LongVruFCW_VelXDealy;
static float32 LongVruFCW_VelXDealy_table[2*3];  /*!<@values:float32[3][2]*/
static HEADParameterScalar_t LongVruDynAcuteWarn_TTBAcuteKeepFactor;
static HEADParameterTable_t LongVruDynAcuteWarn_NecLat;
static float32 LongVruDynAcuteWarn_NecLat_table[2*6];  /*!<@values:float32[6][2]*/
static HEADParameterTable_t LongVRUFCW_EgoAccX_NAcc_Factor;
static float32 LongVRUFCW_EgoAccX_NAcc_Factor_table[2*10];  /*!<@values:float32[10][2]*/
static HEADModuleInternalGSM_t HEADInternalState_LongVru_HaptDynWarn;
static HEADParameterScalar_t LongVru_HaptDynWarn_Inhibition;
static HEADParameterScalar_t LongVru_OnlyIfDynAcuteActive;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVru_OnlyIfHaptDynWarn_NoInActive;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVru_OnlyIf_CrossVru_HaptDynWarn_NoInActive;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVru_HaptDynWarn_MinEgoVel;
static HEADParameterScalar_t LongVru_HaptDynWarn_MaxEgoVel;
static HEADParameterScalar_t LongVru_HaptDynWarn_HypProb;
static HEADParameterTable_t LongVruHaptWarn_TTC4EgoVel;
static float32 LongVruHaptWarn_TTC4EgoVel_table[2*7];  /*!<@values:float32[7][2]*/
static HEADParameterScalar_t LongVru_HaptDynWarn_TTCmax;
static HEADParameterScalar_t LongVru_HaptDynWarn_TTC3min;
static HEADParameterScalar_t LongVru_HaptDynWarn_MaxTime;
static HEADParameterScalar_t LongVru_HaptDynWarn_LockTime;
static HEADParameterScalar_t LongVru_HaptDynWarn_MinTime;
static HEADParameterScalar_t LongVru_HaptDynWarn_DynAcuteSensorSource;
static HEADParameterScalar_t LongVru_HaptDynWarn_DynAcutewarn_Driver_Seatbelt;
static HEADParameterScalar_t LongVru_HaptDynWarn_DrvActivity_Leave;
static HEADParameterScalar_t LongVruHaptDyn_ANecLong;
static HEADParameterScalar_t LongVruHaptDyn_ANecLong_Keep;
static HEADParameterScalar_t LongVruHaptDyn_TTBAcute;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruHaptDynWarn_WarnChainState;
static HEADParameterScalar_t LongVruHaptDynWarn_WarnChainState_leave;
static HEADParameterScalar_t LongVru_HaptDynWarn_SteeringGrad_leave;
static HEADParameterScalar_t LongVru_HaptDynWarnOnlyIf_LongBru_Brk1;
static HEADParameterScalar_t LongVru_HaptDynWarn_HypProb_KeepPassive;
static HEADParameterScalar_t LongVruHaptDynWarn_HypProb_StationVRU;
static HEADModuleInternalGSM_t HEADInternalState_LongVru_HBA;
static const HEADModuleOutputHBAFunctionPar_t HEADFuncOut_LongVru_HBAPar = {1u, {-10.0f, 3.0f, -6.0f, 2.0f, -6.0f, 2.0f}, 3u, 0u, {0u, 0u, 0u, 0u}, 2u, -1, 0u, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}, 3u, -0.5f, 0u};
static HEADParameterScalar_t LongVruHBA_Inhibition;
static HEADParameterScalar_t LongVruHBA_OnlyIfLongVruAcuteWarn;
static HEADParameterScalar_t LongVruHBA_MinEgoVel;
static HEADParameterScalar_t LongVruHBA_MaxEgoVel;
static HEADParameterScalar_t LongVruHBA_HypProb;
static HEADParameterScalar_t LongVruHBA_DrvActivity;
static HEADParameterScalar_t LongVruHBA_ANecLong;
static HEADParameterScalar_t LongVruHBA_ANecLong_Keep;
static HEADParameterScalar_t LongVruHBA_LockTime;
static HEADParameterScalar_t LongVruHBA_KeepIfLongVruPreBrkActive;
static HEADParameterScalar_t LongVru_HBASensorSource;
static HEADParameterScalar_t LongHBATA_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVru_HBADriverActivity_Leave;
static HEADParameterScalar_t LongVru_HBA_Driver_Seatbelt;
static HEADParameterScalar_t LongVru_HBA_HBAQualifier;
static HEADParameterScalar_t LongVruHBA_AEBSwitch;
static HEADParameterScalar_t LongVruHBA_AEBSwitch_Leave;
static HEADParameterScalar_t LongVru_HBA_DriverFeedback_leave;
static HEADParameterScalar_t LongVru_HBA_HBAQualifier_leave;
static HEADParameterScalar_t LongVru_HBA_SteerGrad_Leave;
static HEADParameterScalar_t LongVru_HBA_SteerGrad_Keep;
static HEADParameterScalar_t LongVru_HBA_HypProb_KeepPassive;
static HEADParameterScalar_t LongVruHBA_HypProb_StationVRU;
static HEADParameterScalar_t LongVruHBA_HypProb_StationVRU_Keep;
static HEADModuleInternalGSM_t HEADInternalState_LongVru_Prefill;
static HEADParameterScalar_t LongVruPreFill_Inhibition;
static HEADParameterScalar_t LongVruPrefill_OnlyIfVehAutoBrk1NotActive;
static HEADParameterScalar_t LongVruPrefill_OnlyIfCrossVruPreBrkNotActive;
static HEADParameterScalar_t LongVruPrefill_OnlyIfLongVruBrk1NotActive;
static HEADParameterScalar_t LongVruPrefill_MinEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruPrefill_MaxEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruPreFill_HypProb;
static HEADParameterScalar_t LongVruPrefill_TTBAcute;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruPrefill_ANecLong;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruPrefil_MaxTime;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruPrefill_LockTime;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVru_PrefillSensorSource;
static HEADParameterScalar_t LongPrefill_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t LongPrefillDriverFeedback_BrakePedal;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVru_PrefillDriverActivity;
static HEADParameterScalar_t LongVru_Prefill_Driver_Seatbelt;
static HEADParameterScalar_t LongVru_Prefill_PrefillQualifier;
static HEADParameterScalar_t LongVru_Prefill_AEBSwitch;
static HEADParameterScalar_t LongVru_Prefill_AEBSwitch_Leave;
static HEADParameterScalar_t LongVru_Prefill_PrefillQualifier_leave;
static HEADParameterScalar_t LongVru_Prefill_DriverFeedback_leave;
static HEADParameterScalar_t LongVru_Prefill_DriverActivity_Leave_OR4;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVru_Prefill_SteerGrad_Leave;
static HEADParameterScalar_t LongVruPrefill_OnlyIfLongVruAcuteWarn;
static HEADParameterScalar_t LongVru_Prefill_SteerGrad_Keep;
static HEADParameterScalar_t LongVru_Prefill_HypProb_KeepPassive;
static HEADParameterScalar_t LongVruPrefill_HypProb_StationVRU;
static HEADParameterScalar_t LongVruPrefill_HypProb_StationVRU_Keep;
static HEADModuleInternalGSM_t HEADInternalState_LongVru_Brk1;
static HEADModOutBrakeFunctionPar_t HEADFuncOut_LongVru_Brk1Par;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_Inhibition;
static HEADParameterScalar_t LongVruBrk1_OnlyIfDynAcuteWarnActive;
static HEADParameterScalar_t LongVruBrk1_OnlyIfVehPreBrkNotActive;
static HEADParameterScalar_t LongVruBrk1_OnlyIfVehPreBrkNotWait;
static HEADParameterScalar_t LongVruBrk1_OnlyIfCrossVruPreBrkNotActive;
static HEADParameterScalar_t LongVruBrk1_OnlyIfCrossVruPreBrkNotWait;
static HEADParameterScalar_t LongVruBrk1_MinEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_MaxEgoVel;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_HypProb;
static HEADParameterScalar_t LongVruBrk1_HypProb_keep;
static HEADParameterScalar_t LongVruBrk1_ObjProb;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_DrvFeedback;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_DrvActivity;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_TTBAcute;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_TTCMin;
static HEADParameterScalar_t LongVruBrk1_VrelX_keep;
static HEADParameterTable_t LongVruBrk1_ANecLong_Keep;
static HEADParameterScalar_t LongVruBrk1_DistXSafe;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_LockTime;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_MinEgoVel_Leave;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk1_InitWaitVRel;
static HEADParameterScalar_t LongVru_Brk1lSensorSource;
static HEADParameterScalar_t LongVru_Brk1_Driver_Seatbelt;
static HEADParameterScalar_t LongVru_PreBrk_BrakeChainState;
static HEADParameterScalar_t LongVru_Brk1_LongVRU_Curve_Min;
static HEADParameterScalar_t LongVru_Brk1_LongVRU_Curve_Max;
static HEADParameterScalar_t LongVru_AutoBrk1_AEBSwitch;
static HEADParameterScalar_t LongVru_AutoBrk1_AEBSwitch_Leave;
static HEADParameterScalar_t LongVru_Brk1_DriverFeedback_leave;
static HEADParameterScalar_t LongVru_DriverActivity_Leave_OR4;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVru_PreBrk_BrakeChainState_leave;
static HEADParameterScalar_t LongVruBrk1_SteeringGrad_Leave;
static HEADParameterScalar_t LongVruBrk1_SteeringGrad_Keep;
static HEADParameterScalar_t LongVruBrk1_HypProb_StationVRU;
static HEADParameterScalar_t LongVruBrk1_HypProb_KeepActive;
static HEADParameterScalar_t LongVru_Brk1_ObjMovDir;
static HEADParameterScalar_t LongVru_Brk1MaxVrelY;
static HEADParameterTable_t LongVruBrk1StationVRU_ANecLong;
static float32 LongVruBrk1StationVRU_ANecLong_table[2*7];  /*!<@allow: all_cust *//*!<@values:float32[7][2]*/
static HEADParameterTable_t LongVRUBRK1AllConditionsTRUE_MovingYawrate;
static HEADParameterScalar_t LongVru_Brk1DriverBrake_lowspeed;
static HEADParameterTable_t LongVRUBrk1AllConditionsTRUE_SteerGrad;
static HEADParameterTable_t LongVruBrk1_TTC4;
static float32 LongVruBrk1_TTC4_table[2*6];  /*!<@values:float32[6][2]*/
static HEADParameterTable_t LongVruBrk_VelXDealy;
static HEADParameterTable_t LongVRUBrk_EgoAccX_NAcc;
static HEADParameterTable_t LongVRUBrk1_EgoAccX_NAcc_Factor;
static HEADModuleInternalGSM_t HEADInternalState_LongVru_Brk2;
static HEADModOutBrakeFunctionPar_t HEADFuncOut_LongVru_Brk2Par;/*!<@allow: all_cust */
static HEADParameterScalar_t LongVruBrk2_Inhibition;
static HEADParameterScalar_t LongVruBrk2_OnlyIfLongVruBrk1Active;
static HEADParameterScalar_t LongVruBrk2_WaitForLongVruBrk1_Passive;
static HEADParameterScalar_t LongVruBrk2_ANecLong;
static HEADParameterScalar_t LongVru_Brk2lSensorSource;
static HEADParameterScalar_t LongVru_PreBrk2_BrakeChainState;
static HEADParameterScalar_t LongVruBrk2_OnlyIfLongVruBrk1_StationVruActive;
static HEADParameterScalar_t LongVruBrk2_OnlyIfLongVruBrk1_StationVruKeepActive;
static HEADParameterScalar_t LongVruBrk2_OnlyIfLongVruBrk1ActiveStation;
static HEADModuleInternalGSM_t HEADInternalState_EgoVehStandstill;
static HEADParameterScalar_t EgoVehStopped_EgoVel;
static HEADParameterScalar_t EgoVehStopped_EgoVel_Keep;
static HEADModuleInternalGSM_t HEADInternalState_HoldBrakeInStandstill;
static HEADParameterScalar_t Standstill_VehAutoBrk1_Active;
static HEADParameterScalar_t Standstill_CrossVruPreBrk_Active;
static HEADParameterScalar_t Standstill_LongVru_Brk1_Active;
static HEADParameterScalar_t Standstill_EgoVehStopped_Not_Active;
static HEADParameterScalar_t Standstill_External_Deactivation;
static HEADParameterScalar_t StandstillMaxTime;
static HEADParameterScalar_t StandstillLockTime;
static HEADModuleInternalGSM_t HEADInternalState_OncomingLatentWarn;
static HEADParameterScalar_t OncomingLatentWarnStayInOFF;
static HEADModuleInternalGSM_t HEADInternalState_OncomingDriveOffPrevention;
static HEADParameterScalar_t OncomingDriveOffPreventionStayInOFF;
static HEADModuleInternalGSM_t HEADInternalState_OncomingWarn;
static HEADParameterScalar_t OncomingWarnStayInOFF;
static HEADModuleInternalGSM_t HEADInternalState_OncomingBrake;
static HEADParameterScalar_t OncomingBrakeStayInOFF;
static HEADModuleInternalGSM_t HEADInternalState_DynAcuteWarn_TRUCK;
static HEADModOutWarnFunctionPar_t HEADFuncOut_DynAcuteWarn_TRUCKPar;/*!<@allow: all_cust */
static HEADParameterScalar_t DynAcuteWarn_TRUCKStayInOff;
/*! @brief          HEAD Module Output Data
    @description    Holds Output information of all the modules which are configured in the HEAD GUI.
                    The Output Differs based on the Requested Output function, it can be HEADModuleOutputToggleFunction_t,
                    HEADModuleOutputWarnFunction_t, HEADModuleOutputBrakeFunction_t, or HEADModuleOutputHBAFunction_t
*/
HEADModuleOutputStruct_t HEADModuleOutputData;
/*! @brief          HEAD Module Array
    @description    Contains information about all the modules which are configured in the HEAD GUI
*/

static struct HEADModule_t HEADModule[HEAD_AUTO_CFG_NO_MODULES];

 /* defines the number of OR_Group in each of the module. */
#define HEAD_OR_GROUP_NUM_LatPreWarn  (3u)
#define HEAD_OR_GROUP_NUM_LatAcuteWarn  (1u)
#define HEAD_OR_GROUP_NUM_DynPreWarn  (1u)
#define HEAD_OR_GROUP_NUM_DynAcuteWarn  (5u)
#define HEAD_OR_GROUP_NUM_HaptDynWarn  (7u)
#define HEAD_OR_GROUP_NUM_Prefill  (5u)
#define HEAD_OR_GROUP_NUM_Veh_AutoBrk1  (8u)
#define HEAD_OR_GROUP_NUM_Veh_AutoBrk2  (1u)
#define HEAD_OR_GROUP_NUM_Veh_AutoBrk3  (1u)
#define HEAD_OR_GROUP_NUM_HBA_TA  (6u)
#define HEAD_OR_GROUP_NUM_HBA_VDS  (1u)
#define HEAD_OR_GROUP_NUM_CrossVru_DynAcuteWarn  (5u)
#define HEAD_OR_GROUP_NUM_CrossVru_HaptDynWarn  (5u)
#define HEAD_OR_GROUP_NUM_CrossVru_HBA  (6u)
#define HEAD_OR_GROUP_NUM_CrossVru_Prefill  (5u)
#define HEAD_OR_GROUP_NUM_CrossVru_PreBrk  (7u)
#define HEAD_OR_GROUP_NUM_CrossVru_PreBrk2  (1u)
#define HEAD_OR_GROUP_NUM_LongVru_DynAcuteWarn  (3u)
#define HEAD_OR_GROUP_NUM_LongVru_HaptDynWarn  (5u)
#define HEAD_OR_GROUP_NUM_LongVru_HBA  (6u)
#define HEAD_OR_GROUP_NUM_LongVru_Prefill  (6u)
#define HEAD_OR_GROUP_NUM_LongVru_Brk1  (7u)
#define HEAD_OR_GROUP_NUM_LongVru_Brk2  (1u)
#define HEAD_OR_GROUP_NUM_EgoVehStandstill  (1u)
#define HEAD_OR_GROUP_NUM_HoldBrakeInStandstill  (4u)
#define HEAD_OR_GROUP_NUM_OncomingLatentWarn  (1u)
#define HEAD_OR_GROUP_NUM_OncomingDriveOffPrevention  (1u)
#define HEAD_OR_GROUP_NUM_OncomingWarn  (1u)
#define HEAD_OR_GROUP_NUM_OncomingBrake  (1u)
#define HEAD_OR_GROUP_NUM_DynAcuteWarn_TRUCK  (1u)

 /* Defines the Timer array for Each Module, it defines 2-timer for each OR-Group one for self transition and
 other for transition to other state. it is used to check other OR_Group in the same module is active or not */
static float32 HEAD_OR_GROUP_TIMER_LatPreWarn[HEAD_OR_GROUP_NUM_LatPreWarn*2];
static float32 HEAD_OR_GROUP_TIMER_LatAcuteWarn[HEAD_OR_GROUP_NUM_LatAcuteWarn*2];
static float32 HEAD_OR_GROUP_TIMER_DynPreWarn[HEAD_OR_GROUP_NUM_DynPreWarn*2];
static float32 HEAD_OR_GROUP_TIMER_DynAcuteWarn[HEAD_OR_GROUP_NUM_DynAcuteWarn*2];
static float32 HEAD_OR_GROUP_TIMER_HaptDynWarn[HEAD_OR_GROUP_NUM_HaptDynWarn*2];
static float32 HEAD_OR_GROUP_TIMER_Prefill[HEAD_OR_GROUP_NUM_Prefill*2];
static float32 HEAD_OR_GROUP_TIMER_Veh_AutoBrk1[HEAD_OR_GROUP_NUM_Veh_AutoBrk1*2];
static float32 HEAD_OR_GROUP_TIMER_Veh_AutoBrk2[HEAD_OR_GROUP_NUM_Veh_AutoBrk2*2];
static float32 HEAD_OR_GROUP_TIMER_Veh_AutoBrk3[HEAD_OR_GROUP_NUM_Veh_AutoBrk3*2];
static float32 HEAD_OR_GROUP_TIMER_HBA_TA[HEAD_OR_GROUP_NUM_HBA_TA*2];
static float32 HEAD_OR_GROUP_TIMER_HBA_VDS[HEAD_OR_GROUP_NUM_HBA_VDS*2];
static float32 HEAD_OR_GROUP_TIMER_CrossVru_DynAcuteWarn[HEAD_OR_GROUP_NUM_CrossVru_DynAcuteWarn*2];
static float32 HEAD_OR_GROUP_TIMER_CrossVru_HaptDynWarn[HEAD_OR_GROUP_NUM_CrossVru_HaptDynWarn*2];
static float32 HEAD_OR_GROUP_TIMER_CrossVru_HBA[HEAD_OR_GROUP_NUM_CrossVru_HBA*2];
static float32 HEAD_OR_GROUP_TIMER_CrossVru_Prefill[HEAD_OR_GROUP_NUM_CrossVru_Prefill*2];
static float32 HEAD_OR_GROUP_TIMER_CrossVru_PreBrk[HEAD_OR_GROUP_NUM_CrossVru_PreBrk*2];
static float32 HEAD_OR_GROUP_TIMER_CrossVru_PreBrk2[HEAD_OR_GROUP_NUM_CrossVru_PreBrk2*2];
static float32 HEAD_OR_GROUP_TIMER_LongVru_DynAcuteWarn[HEAD_OR_GROUP_NUM_LongVru_DynAcuteWarn*2];
static float32 HEAD_OR_GROUP_TIMER_LongVru_HaptDynWarn[HEAD_OR_GROUP_NUM_LongVru_HaptDynWarn*2];
static float32 HEAD_OR_GROUP_TIMER_LongVru_HBA[HEAD_OR_GROUP_NUM_LongVru_HBA*2];
static float32 HEAD_OR_GROUP_TIMER_LongVru_Prefill[HEAD_OR_GROUP_NUM_LongVru_Prefill*2];
static float32 HEAD_OR_GROUP_TIMER_LongVru_Brk1[HEAD_OR_GROUP_NUM_LongVru_Brk1*2];
static float32 HEAD_OR_GROUP_TIMER_LongVru_Brk2[HEAD_OR_GROUP_NUM_LongVru_Brk2*2];
static float32 HEAD_OR_GROUP_TIMER_EgoVehStandstill[HEAD_OR_GROUP_NUM_EgoVehStandstill*2];
static float32 HEAD_OR_GROUP_TIMER_HoldBrakeInStandstill[HEAD_OR_GROUP_NUM_HoldBrakeInStandstill*2];
static float32 HEAD_OR_GROUP_TIMER_OncomingLatentWarn[HEAD_OR_GROUP_NUM_OncomingLatentWarn*2];
static float32 HEAD_OR_GROUP_TIMER_OncomingDriveOffPrevention[HEAD_OR_GROUP_NUM_OncomingDriveOffPrevention*2];
static float32 HEAD_OR_GROUP_TIMER_OncomingWarn[HEAD_OR_GROUP_NUM_OncomingWarn*2];
static float32 HEAD_OR_GROUP_TIMER_OncomingBrake[HEAD_OR_GROUP_NUM_OncomingBrake*2];
static float32 HEAD_OR_GROUP_TIMER_DynAcuteWarn_TRUCK[HEAD_OR_GROUP_NUM_DynAcuteWarn_TRUCK*2];


/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
static eGDBError_t HEADAutoCodeSetCfg(HEADModuleList_t *pModuleList);
static eGDBError_t HEADAutoCodeSetSPM(const HEADModuleList_t *pModuleList, struct HEADInputData_t *pHEADInputData, void *pAddInputValueList);

/*****************************************************************************
  CHECKSUM
*****************************************************************************/
#define HEAD_CONFIG_LEN (1)
static const uint8 HEAD_CONFIG[HEAD_CONFIG_LEN] = {0};

/* ****************************************************************************
  Functionname:           HEADAutoCodeSetCfg                                     */ /*!  
  @brief                  Configure HEAD Auto Code to internal structure 
  @description          This Function is used to create HEAD Module List and configure each module Conditional prameters
                        (generic parameter information @ref HEADParameterType_t and Parameter Value), Ouput Parameters
                        and output function to internal Structure.
                        @startuml
                        Start
                        :Update HEAD module list Data;
                            Note 
                            Assign the total number of modules and 
                            Module Array to HEAD Module list structure.
                            End note
                        Partition ForAllModules {
                            #Orange:Set parameters
                            <b>HEADParamSetScalarWithBitPack</b> or
                            <b>HEADParamSetTableWithBitPack</b> >
                                Note
                                For each module Set the corresponding parameter and
                                group it as related.
                                The parameter can be scalar or vector.
                                End note
                            :Set Output Function type;
                                Note
                                Output Function can be either Break, Warn, Toggle or HBA function
                                End note
                            #Orange:Create Module
                            <b>HEADGSMCreateTypicalModule</b> >
                                 Note: Create module in the HEAD Module list array
                            :Set Module Output Parameters;
                                 Note: Defines module Output.
                        }
                        Stop
                        @enduml
  @return               eGDBError_t : GDB_ERROR_NONE in case of no error, else returns forwarded Error
  @param[in,out]        pModuleList : Pointer to HEAD module list
  @glob_in 
  @glob_out
  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  @pre                  None
  @post                 None
  @InOutCorrelation     Not defined
  @testmethod           Test of output data (dynamic module test)
  @traceability
  @author       autocode
**************************************************************************** */
static eGDBError_t HEADAutoCodeSetCfg(HEADModuleList_t *pModuleList)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if(pModuleList != NULL)
  {
    pModuleList->uiNrOfModules = HEAD_AUTO_CFG_NO_MODULES;
    pModuleList->rgModules = &(HEADModule[0]);


    /*---------------LatPreWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_LAT_WARN)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      15.796875f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      55.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_ObjProb)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      80.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_TTC4_Middle)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_TTC4,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.7f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_DrvActivity)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      49.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_DrvActivity_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      3.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarnSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_SteeringGrad_Levae)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LatPreWarn_AllConditionsTRUEYawStat)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(LatPreWarn_AllConditionsTRUEYawStat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_TTSPre_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      (uint16) (HEADParameterMode_ACC | HEADParameterMode_Early),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_TTSPre_middle)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      (uint16) (HEADParameterMode_Middle),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.2f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_TTSPre_late)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      (uint16) (HEADParameterMode_Late),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarnMaxLateralDistance)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarnHypothesisLifeTime)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_HypLifetime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LatPreWarning_EgoAccX_NAcc_table[0] = -7.0f;
    LatPreWarning_EgoAccX_NAcc_table[1] = -4.0f;
    LatPreWarning_EgoAccX_NAcc_table[2] = -6.0f;
    LatPreWarning_EgoAccX_NAcc_table[3] = -4.0f;
    LatPreWarning_EgoAccX_NAcc_table[4] = -5.0f;
    LatPreWarning_EgoAccX_NAcc_table[5] = -6.0f;
    LatPreWarning_EgoAccX_NAcc_table[6] = -4.0f;
    LatPreWarning_EgoAccX_NAcc_table[7] = -5.0f;
    LatPreWarning_EgoAccX_NAcc_table[8] = -3.0f;
    LatPreWarning_EgoAccX_NAcc_table[9] = -4.5f;
    LatPreWarning_EgoAccX_NAcc_table[10] = -2.0f;
    LatPreWarning_EgoAccX_NAcc_table[11] = -3.5f;
    LatPreWarning_EgoAccX_NAcc_table[12] = -1.0f;
    LatPreWarning_EgoAccX_NAcc_table[13] = -2.5f;
    LatPreWarning_EgoAccX_NAcc_table[14] = 0.0f;
    LatPreWarning_EgoAccX_NAcc_table[15] = -1.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LatPreWarning_EgoAccX_NAcc)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostAccel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      8u,
      ((const void *)&(LatPreWarning_EgoAccX_NAcc_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_OnlyIfVehBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_OnlyIfCrossVRUBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_OnlyIfLongVruBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarnego_accel_min)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_EgoAccel,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -0.4f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarnego_accel_max)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_EgoAccel,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_vrel_min)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_VRelX,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -3.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_vrel_max)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_VRelX,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_TTC4_Early)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_TTC4,
      (uint16) (HEADParameterMode_ACC | HEADParameterMode_Early),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.9f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatPreWarn_TTC4_Late)),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      HEADParamOutType_TTC4,
      (uint16) (HEADParameterMode_Late),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.LatPreWarn.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"LatPreWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_LatPreWarn]),
      &(HEADInternalState_LatPreWarn),
      (HEADParameterEmpty_t *)((void *)&(LatPreWarn_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.LatPreWarn)),
      NULL, HEAD_OR_GROUP_TIMER_LatPreWarn, HEAD_OR_GROUP_NUM_LatPreWarn))



    /*---------------LatAcuteWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LatAcuteWarnStayInOFF)),
      (HEADParameterEmpty_t *)((void *)&(LatAcuteWarnStayInOFF)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit),
      -1000.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.LatAcuteWarn.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"LatAcuteWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_LatAcuteWarn]),
      &(HEADInternalState_LatAcuteWarn),
      (HEADParameterEmpty_t *)((void *)&(LatAcuteWarnStayInOFF)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.LatAcuteWarn)),
      NULL, HEAD_OR_GROUP_TIMER_LatAcuteWarn, HEAD_OR_GROUP_NUM_LatAcuteWarn))



    /*---------------DynPreWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynPreWarnStayInOFF)),
      (HEADParameterEmpty_t *)((void *)&(DynPreWarnStayInOFF)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit),
      -1000.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.DynPreWarn.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"DynPreWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_DynPreWarn]),
      &(HEADInternalState_DynPreWarn),
      (HEADParameterEmpty_t *)((void *)&(DynPreWarnStayInOFF)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.DynPreWarn)),
      NULL, HEAD_OR_GROUP_TIMER_DynPreWarn, HEAD_OR_GROUP_NUM_DynPreWarn))



    /*---------------DynAcuteWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_ACU_WARN)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_MaxEgoVel_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      65.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_ObjProb)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      65.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_ObjProb_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      65.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTBAcute)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      9u,
      ((const void *)&(DynAcuteWarn_TTBAcute_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      -10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_TTBAcute_HypBrk)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_TTCMin)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.3f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_TTSPre_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.7f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_TTSAcute_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.8f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_MinDistX)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjectDist,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      3.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.3f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

  
    DynAcuteWarnAllConditionsTRUEVelMov_table[0] = 0.0f;
    DynAcuteWarnAllConditionsTRUEVelMov_table[1] = 0.0f;
    DynAcuteWarnAllConditionsTRUEVelMov_table[2] = 22.2222222222f;
    DynAcuteWarnAllConditionsTRUEVelMov_table[3] = 0.0f;
    DynAcuteWarnAllConditionsTRUEVelMov_table[4] = 27.7777777778f;
    DynAcuteWarnAllConditionsTRUEVelMov_table[5] = 0.2f;
    DynAcuteWarnAllConditionsTRUEVelMov_table[6] = 50.0f;
    DynAcuteWarnAllConditionsTRUEVelMov_table[7] = 0.4f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarnAllConditionsTRUEVelMov)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(DynAcuteWarnAllConditionsTRUEVelMov_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_AllConditionsTRUE)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarnAllConditionsTRUEStat_table[0] = 0.0f;
    DynAcuteWarnAllConditionsTRUEStat_table[1] = 0.1f;
    DynAcuteWarnAllConditionsTRUEStat_table[2] = 0.02f;
    DynAcuteWarnAllConditionsTRUEStat_table[3] = 0.1f;
    DynAcuteWarnAllConditionsTRUEStat_table[4] = 0.04f;
    DynAcuteWarnAllConditionsTRUEStat_table[5] = 0.2f;
    DynAcuteWarnAllConditionsTRUEStat_table[6] = 0.1f;
    DynAcuteWarnAllConditionsTRUEStat_table[7] = 0.265f;
    DynAcuteWarnAllConditionsTRUEStat_table[8] = 0.2f;
    DynAcuteWarnAllConditionsTRUEStat_table[9] = 0.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarnAllConditionsTRUEStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarnAllConditionsTRUEStat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_AllConditionsTRUEActivityStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_DriverActivity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(DynAcuteWarn_AllConditionsTRUEActivityStat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_MinTime)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_KeepIfVehAutoBrkIsActive)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_DrvActivity_Leave)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

  
    DynAcuteWarn_ObjDist_Lifetime_table[0] = 0.0f;
    DynAcuteWarn_ObjDist_Lifetime_table[1] = 5.0f;
    DynAcuteWarn_ObjDist_Lifetime_table[2] = 1.0f;
    DynAcuteWarn_ObjDist_Lifetime_table[3] = 5.0f;
    DynAcuteWarn_ObjDist_Lifetime_table[4] = 2.5f;
    DynAcuteWarn_ObjDist_Lifetime_table[5] = 3.0f;
    DynAcuteWarn_ObjDist_Lifetime_table[6] = 4.0f;
    DynAcuteWarn_ObjDist_Lifetime_table[7] = 0.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_ObjDist_Lifetime)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjectDist,
      HEADParamTableType_CustomPar_01_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(DynAcuteWarn_ObjDist_Lifetime_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_Hypo_Lifetime_table[0] = 0.0f;
    DynAcuteWarn_Hypo_Lifetime_table[1] = 3.0f;
    DynAcuteWarn_Hypo_Lifetime_table[2] = 5.55555555556f;
    DynAcuteWarn_Hypo_Lifetime_table[3] = 3.0f;
    DynAcuteWarn_Hypo_Lifetime_table[4] = 8.33333333333f;
    DynAcuteWarn_Hypo_Lifetime_table[5] = 2.5f;
    DynAcuteWarn_Hypo_Lifetime_table[6] = 8.61111111111f;
    DynAcuteWarn_Hypo_Lifetime_table[7] = 0.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_Hypo_Lifetime)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_HypLifetime,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(DynAcuteWarn_Hypo_Lifetime_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcutelSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTCMax_middle)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_Middle),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(DynAcuteWarn_TTCMax_middle_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTCMax_early)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_ACC | HEADParameterMode_Early),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(DynAcuteWarn_TTCMax_early_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTCMax_late)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_Late),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(DynAcuteWarn_TTCMax_late_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_Hypo_RunupLifetime_table[0] = 0.0f;
    DynAcuteWarn_Hypo_RunupLifetime_table[1] = 1.0f;
    DynAcuteWarn_Hypo_RunupLifetime_table[2] = 5.55555555556f;
    DynAcuteWarn_Hypo_RunupLifetime_table[3] = 1.0f;
    DynAcuteWarn_Hypo_RunupLifetime_table[4] = 8.33333333333f;
    DynAcuteWarn_Hypo_RunupLifetime_table[5] = 1.0f;
    DynAcuteWarn_Hypo_RunupLifetime_table[6] = 8.61111111111f;
    DynAcuteWarn_Hypo_RunupLifetime_table[7] = 0.2f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_Hypo_RunupLifetime)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_HypLifetime,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(DynAcuteWarn_Hypo_RunupLifetime_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_ObjDistY_RunupBraking_table[0] = 0.0f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[1] = 0.6f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[2] = 5.55555555556f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[3] = 0.6f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[4] = 8.33333333333f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[5] = 0.6f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[6] = 8.61111111111f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[7] = 0.5f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[8] = 16.6666666667f;
    DynAcuteWarn_ObjDistY_RunupBraking_table[9] = 0.4f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_ObjDistY_RunupBraking)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_ObjDistY_RunupBraking_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[0] = 0.0f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[1] = 0.2f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[2] = 5.55555555556f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[3] = 0.2f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[4] = 8.33333333333f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[5] = 0.2f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[6] = 8.61111111111f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[7] = 0.2f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[8] = 16.6666666667f;
    DynAcuteWarn_ObjDistY_RunupStatVRU_table[9] = 0.2f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_ObjDistY_RunupStatVRU)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_ObjDistY_RunupStatVRU_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[0] = 0.0f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[1] = 0.5f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[2] = 5.55555555556f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[3] = 0.5f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[4] = 8.33333333333f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[5] = 0.5f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[6] = 11.1111111111f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[7] = 0.5f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[8] = 12.5f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[9] = 0.4f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[10] = 13.8888888889f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[11] = 0.0f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[12] = 16.6666666667f;
    DynAcuteWarn_Hypo_RunupBrakingLifetime_table[13] = 0.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_Hypo_RunupBrakingLifetime)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_HypLifetime,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(DynAcuteWarn_Hypo_RunupBrakingLifetime_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTCMax_middle_mov)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_Middle),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(DynAcuteWarn_TTCMax_middle_mov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTCMax_early_mov)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_ACC | HEADParameterMode_Early),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(DynAcuteWarn_TTCMax_early_mov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTCMax_late_mov)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_Late),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(DynAcuteWarn_TTCMax_late_mov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_EgoAccX_NAcc)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostAccel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      8u,
      ((const void *)&(LatPreWarning_EgoAccX_NAcc_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarnFP_CurveMAX)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoLatCurvature,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarnFP_CurveMin)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoLatCurvature,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_TTSPre)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.2f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_TTSAcute_table[0] = 0.0f;
    DynAcuteWarn_TTSAcute_table[1] = 1.1f;
    DynAcuteWarn_TTSAcute_table[2] = 2.77777777778f;
    DynAcuteWarn_TTSAcute_table[3] = 1.1f;
    DynAcuteWarn_TTSAcute_table[4] = 5.55555555556f;
    DynAcuteWarn_TTSAcute_table[5] = 1.1f;
    DynAcuteWarn_TTSAcute_table[6] = 8.33333333333f;
    DynAcuteWarn_TTSAcute_table[7] = 1.1f;
    DynAcuteWarn_TTSAcute_table[8] = 11.1111111111f;
    DynAcuteWarn_TTSAcute_table[9] = 1.1f;
    DynAcuteWarn_TTSAcute_table[10] = 13.8888888889f;
    DynAcuteWarn_TTSAcute_table[11] = 1.6f;
    DynAcuteWarn_TTSAcute_table[12] = 16.6666666667f;
    DynAcuteWarn_TTSAcute_table[13] = 1.6f;
    DynAcuteWarn_TTSAcute_table[14] = 19.4444444444f;
    DynAcuteWarn_TTSAcute_table[15] = 1.8f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTSAcute)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      8u,
      ((const void *)&(DynAcuteWarn_TTSAcute_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DynAcuteWarnOb_OncomingKeepPassive)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjMoveDir,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    ObjCorridorOccupancFCW_YawRate_table[0] = 0.0f;
    ObjCorridorOccupancFCW_YawRate_table[1] = 0.4f;
    ObjCorridorOccupancFCW_YawRate_table[2] = 0.01f;
    ObjCorridorOccupancFCW_YawRate_table[3] = 0.4f;
    ObjCorridorOccupancFCW_YawRate_table[4] = 0.02f;
    ObjCorridorOccupancFCW_YawRate_table[5] = 0.5f;
    ObjCorridorOccupancFCW_YawRate_table[6] = 0.03f;
    ObjCorridorOccupancFCW_YawRate_table[7] = 0.6f;
    ObjCorridorOccupancFCW_YawRate_table[8] = 0.04f;
    ObjCorridorOccupancFCW_YawRate_table[9] = 0.6f;
    ObjCorridorOccupancFCW_YawRate_table[10] = 0.05f;
    ObjCorridorOccupancFCW_YawRate_table[11] = 0.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(ObjCorridorOccupancFCW_YawRate)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(ObjCorridorOccupancFCW_YawRate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[0] = 0.0f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[1] = 0.0f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[2] = 0.005f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[3] = 0.0f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[4] = 0.006f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[5] = 0.1f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[6] = 0.02f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[7] = 0.2f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[8] = 0.04f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[9] = 0.2f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[10] = 0.1f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[11] = 0.265f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[12] = 0.2f;
    DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[13] = 0.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarnAllConditionsTRUE_MovingYawrate)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(DynAcuteWarnAllConditionsTRUE_MovingYawrate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarnTTC_HypBrk_table[0] = 0.0f;
    DynAcuteWarnTTC_HypBrk_table[1] = 0.8f;
    DynAcuteWarnTTC_HypBrk_table[2] = 11.1111111111f;
    DynAcuteWarnTTC_HypBrk_table[3] = 1.36f;
    DynAcuteWarnTTC_HypBrk_table[4] = 12.7777777778f;
    DynAcuteWarnTTC_HypBrk_table[5] = 1.7f;
    DynAcuteWarnTTC_HypBrk_table[6] = 17.7777777778f;
    DynAcuteWarnTTC_HypBrk_table[7] = 1.7f;
    DynAcuteWarnTTC_HypBrk_table[8] = 18.0555555556f;
    DynAcuteWarnTTC_HypBrk_table[9] = 2.6f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarnTTC_HypBrk)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarnTTC_HypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    Veh_FCWEgoSpd_MinDistX_table[0] = 0.0f;
    Veh_FCWEgoSpd_MinDistX_table[1] = 45.0f;
    Veh_FCWEgoSpd_MinDistX_table[2] = 22.7777777778f;
    Veh_FCWEgoSpd_MinDistX_table[3] = 50.0f;
    Veh_FCWEgoSpd_MinDistX_table[4] = 23.0555555556f;
    Veh_FCWEgoSpd_MinDistX_table[5] = 30.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(Veh_FCWEgoSpd_MinDistX)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjectDist,
      HEADParamTableType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      3u,
      ((const void *)&(Veh_FCWEgoSpd_MinDistX_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    Veh_FCWEgoSpd_Timer_table[0] = 0.0f;
    Veh_FCWEgoSpd_Timer_table[1] = 0.0f;
    Veh_FCWEgoSpd_Timer_table[2] = 22.7777777778f;
    Veh_FCWEgoSpd_Timer_table[3] = 0.0f;
    Veh_FCWEgoSpd_Timer_table[4] = 23.0555555556f;
    Veh_FCWEgoSpd_Timer_table[5] = 0.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(Veh_FCWEgoSpd_Timer)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      3u,
      ((const void *)&(Veh_FCWEgoSpd_Timer_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[0] = 0.0f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[1] = 0.0f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[2] = 0.007f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[3] = 0.0f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[4] = 0.008f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[5] = 0.1f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[6] = 0.01f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[7] = 0.2f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[8] = 0.02f;
    DynAcuteWarnRunupStat_YawRate_AllConditin_table[9] = 0.4f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarnRunupStat_YawRate_AllConditin)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarnRunupStat_YawRate_AllConditin_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarnFP_DistYMax)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjectDistLat,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.4f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarnFP_DistYMin)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjectDistLat,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -1.4f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(FCWDriverbrake_lowspeed)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_08_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

  
    ObjCorridorOccupancFCW_CCRSYawRate_table[0] = 0.0f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[1] = 0.3f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[2] = 0.005f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[3] = 0.35f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[4] = 0.01f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[5] = 0.4f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[6] = 0.02f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[7] = 0.5f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[8] = 0.03f;
    ObjCorridorOccupancFCW_CCRSYawRate_table[9] = 0.6f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(ObjCorridorOccupancFCW_CCRSYawRate)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(ObjCorridorOccupancFCW_CCRSYawRate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTBAcuteClosingVelFactorHypBrk)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_ClosingVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      4u,
      ((const void *)&(DynAcuteWarn_TTBAcuteClosingVelFactorHypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      5.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTBAcuteDistXFactorHypBrk)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_Distance,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      4u,
      ((const void *)&(DynAcuteWarn_TTBAcuteDistXFactorHypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      5.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTBAcuteDrvFactor_HypMov)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_TTBAcuteDrvFactor_HypMov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTBAcuteDrvFactor_HypBrk)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_TTBAcuteDrvFactor_HypMov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTBAcuteDrvFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_TTBAcuteDrvFactor_HypMov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_TTBAcuteKeepFactor)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTSPreVelFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(DynAcuteWarn_TTSPreVelFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      20.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTSPreDrvFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_TTSPreDrvFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTSAcuteVelFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      5u,
      ((const void *)&(DynAcuteWarn_TTSAcuteVelFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      20.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTSAcuteDrvFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_TTSAcuteDrvFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_TTSAcuteKeepFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarnHypLifetime_YawRateFactor_table[0] = 0.0f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[1] = 1.0f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[2] = 0.025f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[3] = 0.7f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[4] = 0.05f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[5] = 0.6f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[6] = 0.075f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[7] = 0.5f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[8] = 0.1f;
    DynAcuteWarnHypLifetime_YawRateFactor_table[9] = 0.5f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarnHypLifetime_YawRateFactor)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_HypLifetime,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarnHypLifetime_YawRateFactor_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk_table[0] = 2.77777777778f;
    DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk_table[1] = 1.0f;
    DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk_table[2] = 17.7777777778f;
    DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk_table[3] = 1.0f;
    DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk_table[4] = 18.0555555556f;
    DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk_table[5] = 1.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      3u,
      ((const void *)&(DynAcuteWarn_TTBAcuteSpeedFactor_HypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTCMax_middle_mov_SpeedFactor)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(DynAcuteWarn_TTCMax_middle_mov_SpeedFactor_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_TTSAcuteYawrateFactor_table[0] = 0.0f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[1] = 1.0f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[2] = 0.008f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[3] = 1.0f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[4] = 0.009f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[5] = 0.8f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[6] = 0.01f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[7] = 0.7f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[8] = 0.02f;
    DynAcuteWarn_TTSAcuteYawrateFactor_table[9] = 0.5f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_TTSAcuteYawrateFactor)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_TTSAcuteYawrateFactor_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.DynAcuteWarn.fpCustomOutput = &HEADOutWarnFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"DynAcuteWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_DynAcuteWarn]),
      &(HEADInternalState_DynAcuteWarn),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.DynAcuteWarn)),
      (const void*)&HEADFuncOut_DynAcuteWarnPar, HEAD_OR_GROUP_TIMER_DynAcuteWarn, HEAD_OR_GROUP_NUM_DynAcuteWarn))

    HEADFuncOut_DynAcuteWarnPar.HEAD_LAST_WARN_MODULE = 0;


    /*---------------HaptDynWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_ACU_WARN | FPS_EBA_INH_BRAKE_L1)))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_OnlyIfDynAcute)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(HaptDynWarn_OnlyIfDynAcute_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_OnlyIfDynAcuteBrk)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(HaptDynWarn_OnlyIfDynAcute_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LatPreWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_OnlyIfDynAcuteWarnActive)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_AutoBrk2NotActive)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk2, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_AutoBrk3NotActive)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk3, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7.625f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_MaxEgoVelStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      55.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_ObjProb)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      65.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_ObjProb_Stat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      98.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HauptDynWarn_ObjProb_Keep)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      65.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HaptDynWarn_TTBPre_table[0] = -41.6666666667f;
    HaptDynWarn_TTBPre_table[1] = 0.0f;
    HaptDynWarn_TTBPre_table[2] = -28.8888888889f;
    HaptDynWarn_TTBPre_table[3] = 0.0f;
    HaptDynWarn_TTBPre_table[4] = -23.0555555556f;
    HaptDynWarn_TTBPre_table[5] = 0.51f;
    HaptDynWarn_TTBPre_table[6] = -17.2222222222f;
    HaptDynWarn_TTBPre_table[7] = 0.88f;
    HaptDynWarn_TTBPre_table[8] = -5.55555555556f;
    HaptDynWarn_TTBPre_table[9] = 1.34f;
    HaptDynWarn_TTBPre_table[10] = -2.77777777778f;
    HaptDynWarn_TTBPre_table[11] = 1.43f;
    HaptDynWarn_TTBPre_table[12] = -1.38888888889f;
    HaptDynWarn_TTBPre_table[13] = 1.4f;
    HaptDynWarn_TTBPre_table[14] = 0.0f;
    HaptDynWarn_TTBPre_table[15] = 1.4f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTBPre)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_PRE,
      HEADParamTableType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      8u,
      ((const void *)&(HaptDynWarn_TTBPre_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      -10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_TTBPre_HypBrk)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_PRE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.4f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynTTC)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      6.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_TTSPre_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.55f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_TTSAcute_Early_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      2.12f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_DrvActivity_leave)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_AutoBrk2KeepWait)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk2, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.2f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarnDriverFeedback_BrakePedal)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarnSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_WarnChainState)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_05_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDyn_OnlyIf_LongVru_HaptDynWarn_NotActive)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDyn_OnlyIf_CrossVru_HaptDynWarn_NoInActive)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_WarnChainState_leave)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_05_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      5u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      6u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTBPreClosingVelFactorHypBrk)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_PRE,
      HEADParamTableType_ClosingVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      4u,
      ((const void *)&(HaptDynWarn_TTBPreClosingVelFactorHypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      5.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTBPreDistXFactorHypBrk)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_PRE,
      HEADParamTableType_Distance,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      4u,
      ((const void *)&(HaptDynWarn_TTBPreDistXFactorHypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      15.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTBPreDrvFactor_HypMov)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_PRE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(HaptDynWarn_TTBPreDrvFactor_HypMov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTBPreDrvFactor_HypBrk)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_PRE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(HaptDynWarn_TTBPreDrvFactor_HypMov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_DrvActFactTTBPre_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_PRE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(HaptDynWarn_TTBPreDrvFactor_HypMov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynTTBAcuteKeepFactor)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_PRE,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTSPreVelFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      5u,
      ((const void *)&(HaptDynWarn_TTSPreVelFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      20.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTSPreDrvFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(HaptDynWarn_TTSPreDrvFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_TTSPreKeepFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTSAcuteVelFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      6u,
      ((const void *)&(HaptDynWarn_TTSAcuteVelFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      20.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(HaptDynWarn_TTSAcuteDrvFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(HaptDynWarn_TTSAcuteDrvFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HaptDynWarn_TTSAcuteKeepFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.HaptDynWarn.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"HaptDynWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_HaptDynWarn]),
      &(HEADInternalState_HaptDynWarn),
      (HEADParameterEmpty_t *)((void *)&(HaptDynWarn_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.HaptDynWarn)),
      NULL, HEAD_OR_GROUP_TIMER_HaptDynWarn, HEAD_OR_GROUP_NUM_HaptDynWarn))



    /*---------------Prefill----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_PRE_FILL)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_OnlyIfDynAcuteWarnActive)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_OnlyIfVehAutoBrk1NotActive)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_OnlyIfVehAutoBrk2NotActive)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk2, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_OnlyIfVehAutoBrk3NotActive)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk3, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_OnlyIfCrossVruPreBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_OnlyIfLongVruBrk1NotActive)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(PrefillDriverFeedback_BrakePedal)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(prefill_DrvActivity_keeppasive)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_PrefillQualifier)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_CustomPar_06_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_DriverActivity)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(PrefillSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_PrefillQualifier_leave)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_CustomPar_06_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Prefill_SteerGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.Prefill.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"Prefill"),
      &(HEADModule[HEAD_AUTOCODE_MOD_Prefill]),
      &(HEADInternalState_Prefill),
      (HEADParameterEmpty_t *)((void *)&(Prefill_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.Prefill)),
      NULL, HEAD_OR_GROUP_TIMER_Prefill, HEAD_OR_GROUP_NUM_Prefill))



    /*---------------Veh_AutoBrk1----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_BRAKE_L1)))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_OnlyIfDynAcuteActive)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(VehAutoBrk1_OnlyIfDynAcuteActive_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_OnlyIfCrossVruPreBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_OnlyIfCrossVruPreBrkNotWait)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_WAIT, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_OnlyIfLongVruBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_OnlyIfLongVruBrkNotWait)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_WAIT, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_MaxEgoVel_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      85.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_HypProb_keep)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      80.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_ObjProb)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      90.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_ObjProb_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      98.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_ObjProb_Keep)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      85.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    VehAutoBrk1_ObjProb_keep_HypStat_table[0] = 0.0f;
    VehAutoBrk1_ObjProb_keep_HypStat_table[1] = 96.0f;
    VehAutoBrk1_ObjProb_keep_HypStat_table[2] = 3.0f;
    VehAutoBrk1_ObjProb_keep_HypStat_table[3] = 96.0f;
    VehAutoBrk1_ObjProb_keep_HypStat_table[4] = 3.1f;
    VehAutoBrk1_ObjProb_keep_HypStat_table[5] = 98.0f;
    VehAutoBrk1_ObjProb_keep_HypStat_table[6] = 50.0f;
    VehAutoBrk1_ObjProb_keep_HypStat_table[7] = 98.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_ObjProb_keep_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjProb,
      HEADParamTableType_Distance,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      4u,
      ((const void *)&(VehAutoBrk1_ObjProb_keep_HypStat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      20.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_DriverActivity)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_DriverFeedback)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -70.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

  
    VehAutoBrk1_TTBAcute_table[0] = -41.6666666667f;
    VehAutoBrk1_TTBAcute_table[1] = 0.0f;
    VehAutoBrk1_TTBAcute_table[2] = -34.7222222222f;
    VehAutoBrk1_TTBAcute_table[3] = 0.0f;
    VehAutoBrk1_TTBAcute_table[4] = -23.0555555556f;
    VehAutoBrk1_TTBAcute_table[5] = 0.65f;
    VehAutoBrk1_TTBAcute_table[6] = -17.2222222222f;
    VehAutoBrk1_TTBAcute_table[7] = 0.75f;
    VehAutoBrk1_TTBAcute_table[8] = -13.8888888889f;
    VehAutoBrk1_TTBAcute_table[9] = 0.78f;
    VehAutoBrk1_TTBAcute_table[10] = -11.1111111111f;
    VehAutoBrk1_TTBAcute_table[11] = 0.76f;
    VehAutoBrk1_TTBAcute_table[12] = -5.55555555556f;
    VehAutoBrk1_TTBAcute_table[13] = 0.52f;
    VehAutoBrk1_TTBAcute_table[14] = -2.77777777778f;
    VehAutoBrk1_TTBAcute_table[15] = 0.65f;
    VehAutoBrk1_TTBAcute_table[16] = 0.0f;
    VehAutoBrk1_TTBAcute_table[17] = 0.65f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTBAcute)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      9u,
      ((const void *)&(VehAutoBrk1_TTBAcute_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      -10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    VehAutoBrk1_TTBAcute_HypBrk_table[0] = 0.0f;
    VehAutoBrk1_TTBAcute_HypBrk_table[1] = 0.65f;
    VehAutoBrk1_TTBAcute_HypBrk_table[2] = 4.16666666667f;
    VehAutoBrk1_TTBAcute_HypBrk_table[3] = 0.65f;
    VehAutoBrk1_TTBAcute_HypBrk_table[4] = 6.94444444444f;
    VehAutoBrk1_TTBAcute_HypBrk_table[5] = 0.76f;
    VehAutoBrk1_TTBAcute_HypBrk_table[6] = 13.8888888889f;
    VehAutoBrk1_TTBAcute_HypBrk_table[7] = 0.78f;
    VehAutoBrk1_TTBAcute_HypBrk_table[8] = 22.2222222222f;
    VehAutoBrk1_TTBAcute_HypBrk_table[9] = 0.78f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTBAcute_HypBrk)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(VehAutoBrk1_TTBAcute_HypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      15.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_TTCMin)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.15f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_TTCMax)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_TTSAcute_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.1f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    VehAutoBrk1_ANecLong_keep_table[0] = 0.0f;
    VehAutoBrk1_ANecLong_keep_table[1] = 0.0f;
    VehAutoBrk1_ANecLong_keep_table[2] = 10.0f;
    VehAutoBrk1_ANecLong_keep_table[3] = 0.0f;
    VehAutoBrk1_ANecLong_keep_table[4] = 20.0f;
    VehAutoBrk1_ANecLong_keep_table[5] = -0.6f;
    VehAutoBrk1_ANecLong_keep_table[6] = 30.0f;
    VehAutoBrk1_ANecLong_keep_table[7] = -0.8f;
    VehAutoBrk1_ANecLong_keep_table[8] = 40.0f;
    VehAutoBrk1_ANecLong_keep_table[9] = -0.8f;
    VehAutoBrk1_ANecLong_keep_table[10] = 60.0f;
    VehAutoBrk1_ANecLong_keep_table[11] = -0.8f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_ANecLong_keep)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_Distance,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      6u,
      ((const void *)&(VehAutoBrk1_ANecLong_keep_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_ANecLong_keep_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_ClosingVel)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ClosingVel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_VrelX_keep)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_DistXSafe)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjectDist,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_AllConditionsTRUEActivityStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_DriverActivity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(DynAcuteWarn_AllConditionsTRUEActivityStat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

  
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[0] = 5.55555555556f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[1] = 4.5f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[2] = 11.1111111111f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[3] = 4.5f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[4] = 22.2222222222f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[5] = 4.5f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[6] = 58.0555555556f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[7] = 4.5f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[8] = 58.3333333333f;
    VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[9] = 0.5f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_AllowedMaxTime_BrkReq_leave)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_StateActiveTime,
      HEADParamTableType_HostSpeed,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      5u,
      ((const void *)&(VehAutoBrk1_AllowedMaxTime_BrkReq_leave_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_HypProb_keep_OR1)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      80.0f,
      HEADParamOperator_GREATERTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_ObjProb_keep_OR1)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      85.0f,
      HEADParamOperator_GREATERTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_ObjProb_keep_HypStat_OR1)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjProb,
      HEADParamTableType_Distance,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      4u,
      ((const void *)&(VehAutoBrk1_ObjProb_keep_HypStat_table[0])),
      HEADParamOperator_GREATERTHAN,
      1u,
      20.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_ANecLong_Keep_OR1)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_Distance,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      6u,
      ((const void *)&(VehAutoBrk1_ANecLong_keep_table[0])),
      HEADParamOperator_LESSTHAN,
      1u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_VRel_KeepWait_OR1)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit | HEADParameterState_KeepWaitBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_AutoBrk3InWait_Leave_OR2)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk3, (uint32)HEADSMState_WAIT, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_DriverActivity_Leave_OR4)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_MinEgoVel_Leave_OR5)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.09f,
      HEADParamOperator_LESSTHAN,
      5u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk1_BrakeChainState_leave)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      6u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk1SensorSource)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Autobrk1_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk1_BrakeChainState)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk1_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk1_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      7u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk1_SteerGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      7u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Brk1_OncomingKeepPassive)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjMoveDir,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    VehAutoBrk1_ANecLong_table[0] = 0.0f;
    VehAutoBrk1_ANecLong_table[1] = 0.0f;
    VehAutoBrk1_ANecLong_table[2] = 1.11111111111f;
    VehAutoBrk1_ANecLong_table[3] = -0.8f;
    VehAutoBrk1_ANecLong_table[4] = 1.38888888889f;
    VehAutoBrk1_ANecLong_table[5] = -1.0f;
    VehAutoBrk1_ANecLong_table[6] = 1.66666666667f;
    VehAutoBrk1_ANecLong_table[7] = -1.5f;
    VehAutoBrk1_ANecLong_table[8] = 1.94444444444f;
    VehAutoBrk1_ANecLong_table[9] = -2.0f;
    VehAutoBrk1_ANecLong_table[10] = 2.22222222222f;
    VehAutoBrk1_ANecLong_table[11] = -2.0f;
    VehAutoBrk1_ANecLong_table[12] = 2.5f;
    VehAutoBrk1_ANecLong_table[13] = -3.0f;
    VehAutoBrk1_ANecLong_table[14] = 2.77777777778f;
    VehAutoBrk1_ANecLong_table[15] = -3.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      8u,
      ((const void *)&(VehAutoBrk1_ANecLong_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(ObjCorridorOccupancy_YawRate)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(ObjCorridorOccupancFCW_YawRate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    ObjCorridorOccupancy_stationYawRate_table[0] = 0.0f;
    ObjCorridorOccupancy_stationYawRate_table[1] = 0.3f;
    ObjCorridorOccupancy_stationYawRate_table[2] = 0.005f;
    ObjCorridorOccupancy_stationYawRate_table[3] = 0.35f;
    ObjCorridorOccupancy_stationYawRate_table[4] = 0.01f;
    ObjCorridorOccupancy_stationYawRate_table[5] = 0.4f;
    ObjCorridorOccupancy_stationYawRate_table[6] = 0.02f;
    ObjCorridorOccupancy_stationYawRate_table[7] = 0.5f;
    ObjCorridorOccupancy_stationYawRate_table[8] = 0.03f;
    ObjCorridorOccupancy_stationYawRate_table[9] = 0.6f;
    ObjCorridorOccupancy_stationYawRate_table[10] = 0.04f;
    ObjCorridorOccupancy_stationYawRate_table[11] = 0.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(ObjCorridorOccupancy_stationYawRate)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(ObjCorridorOccupancy_stationYawRate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    VehBrk1_NecLat_table[0] = -16.6666666667f;
    VehBrk1_NecLat_table[1] = 1.4f;
    VehBrk1_NecLat_table[2] = -13.8888888889f;
    VehBrk1_NecLat_table[3] = 1.3f;
    VehBrk1_NecLat_table[4] = -11.1111111111f;
    VehBrk1_NecLat_table[5] = 1.2f;
    VehBrk1_NecLat_table[6] = -8.33333333333f;
    VehBrk1_NecLat_table[7] = 1.1f;
    VehBrk1_NecLat_table[8] = -5.55555555556f;
    VehBrk1_NecLat_table[9] = 1.0f;
    VehBrk1_NecLat_table[10] = -2.77777777778f;
    VehBrk1_NecLat_table[11] = 1.0f;
    VehBrk1_NecLat_table[12] = 0.0f;
    VehBrk1_NecLat_table[13] = 1.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehBrk1_NecLat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ANecLatAbs,
      HEADParamTableType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(VehBrk1_NecLat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    Veh_AutoBrk1EgoSpd_Timer_table[0] = 1.11111111111f;
    Veh_AutoBrk1EgoSpd_Timer_table[1] = 0.19f;
    Veh_AutoBrk1EgoSpd_Timer_table[2] = 1.38888888889f;
    Veh_AutoBrk1EgoSpd_Timer_table[3] = 0.19f;
    Veh_AutoBrk1EgoSpd_Timer_table[4] = 1.66666666667f;
    Veh_AutoBrk1EgoSpd_Timer_table[5] = 0.19f;
    Veh_AutoBrk1EgoSpd_Timer_table[6] = 1.94444444444f;
    Veh_AutoBrk1EgoSpd_Timer_table[7] = 0.19f;
    Veh_AutoBrk1EgoSpd_Timer_table[8] = 2.22222222222f;
    Veh_AutoBrk1EgoSpd_Timer_table[9] = 0.19f;
    Veh_AutoBrk1EgoSpd_Timer_table[10] = 2.5f;
    Veh_AutoBrk1EgoSpd_Timer_table[11] = 0.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(Veh_AutoBrk1EgoSpd_Timer)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(Veh_AutoBrk1EgoSpd_Timer_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    Veh_AutoBrk1EgoSpd_MinDistX_table[0] = 1.11111111111f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[1] = 1.8f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[2] = 1.38888888889f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[3] = 1.9f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[4] = 1.66666666667f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[5] = 2.2f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[6] = 1.94444444444f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[7] = 2.5f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[8] = 2.22222222222f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[9] = 2.5f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[10] = 2.5f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[11] = 45.0f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[12] = 16.6666666667f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[13] = 45.0f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[14] = 16.9444444444f;
    Veh_AutoBrk1EgoSpd_MinDistX_table[15] = 30.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(Veh_AutoBrk1EgoSpd_MinDistX)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjectDist,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      8u,
      ((const void *)&(Veh_AutoBrk1EgoSpd_MinDistX_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    BRK1AllConditionsTRUE_MovingYawrate_table[0] = 0.0f;
    BRK1AllConditionsTRUE_MovingYawrate_table[1] = 0.0f;
    BRK1AllConditionsTRUE_MovingYawrate_table[2] = 0.008f;
    BRK1AllConditionsTRUE_MovingYawrate_table[3] = 0.0f;
    BRK1AllConditionsTRUE_MovingYawrate_table[4] = 0.009f;
    BRK1AllConditionsTRUE_MovingYawrate_table[5] = 0.1f;
    BRK1AllConditionsTRUE_MovingYawrate_table[6] = 0.02f;
    BRK1AllConditionsTRUE_MovingYawrate_table[7] = 0.2f;
    BRK1AllConditionsTRUE_MovingYawrate_table[8] = 0.04f;
    BRK1AllConditionsTRUE_MovingYawrate_table[9] = 0.2f;
    BRK1AllConditionsTRUE_MovingYawrate_table[10] = 0.1f;
    BRK1AllConditionsTRUE_MovingYawrate_table[11] = 0.265f;
    BRK1AllConditionsTRUE_MovingYawrate_table[12] = 0.2f;
    BRK1AllConditionsTRUE_MovingYawrate_table[13] = 0.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(BRK1AllConditionsTRUE_MovingYawrate)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(BRK1AllConditionsTRUE_MovingYawrate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(BRKFP_DistYMax)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjectDistLat,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.4f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(BRK1FP_DistYMin)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ObjectDistLat,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -1.4f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk1Driverbrake_lowspeed)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_CustomPar_08_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_AllConditionsTRUE_DriverBrake)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      2u,
      ((const void *)&(VehAutoBrk1_AllConditionsTRUE_DriverBrake_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[0] = -7.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[1] = -4.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[2] = -6.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[3] = -4.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[4] = -5.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[5] = -6.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[6] = -4.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[7] = -6.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[8] = -3.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[9] = -6.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[10] = -2.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[11] = -6.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[12] = -1.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[13] = -5.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[14] = 0.0f;
    DynAcuteWarn_EgoAccX_NAcc_Brk_table[15] = -1.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(DynAcuteWarn_EgoAccX_NAcc_Brk)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostAccel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      8u,
      ((const void *)&(DynAcuteWarn_EgoAccX_NAcc_Brk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTBAcuteClosingVelFactorHypBrk)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_ClosingVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(HaptDynWarn_TTBPreClosingVelFactorHypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      5.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTBAcuteDistXFactorHypBrk)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_Distance,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(HaptDynWarn_TTBPreDistXFactorHypBrk_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      5.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTBAcuteDrvFactor_HypMov)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(VehAutoBrk1_TTBAcuteDrvFactor_HypMov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTBAcuteDrvFactor_HypBrk)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(VehAutoBrk1_TTBAcuteDrvFactor_HypMov_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTBAcuteDrvFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(VehAutoBrk1_TTBAcuteDrvFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTSAcuteVelFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(VehAutoBrk1_TTSAcuteVelFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      20.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_TTSAcuteDrvFactor_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(DynAcuteWarn_TTSAcuteDrvFactor_HypStat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.Veh_AutoBrk1.fpCustomOutput = &HEADOutBrakeFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"Veh_AutoBrk1"),
      &(HEADModule[HEAD_AUTOCODE_MOD_Veh_AutoBrk1]),
      &(HEADInternalState_Veh_AutoBrk1),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.Veh_AutoBrk1)),
      (const void*)&HEADFuncOut_Veh_AutoBrk1Par, HEAD_OR_GROUP_TIMER_Veh_AutoBrk1, HEAD_OR_GROUP_NUM_Veh_AutoBrk1))

    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParBrakeReactionTime = 0.1f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[1] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[2] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[3] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[4] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[5] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[6] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[8] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxCtrlVeloReduct_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[1] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[2] = 27.7777777778f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[3] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[4] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[5] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[6] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[8] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParMaxAllowVeloReduct_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[1] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[2] = 5.5f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[3] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[4] = 6.2f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[5] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[6] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[7] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[8] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[9] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[10] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[11] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[12] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel[13] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabBrakeDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[1] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[2] = 5.5f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[3] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[4] = 6.2f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[5] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[6] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[7] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[8] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[9] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[10] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[11] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[12] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel[13] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabStatDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[1] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[2] = 5.5f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[3] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[4] = 6.2f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[5] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[6] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[7] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[8] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[9] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[10] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[11] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[12] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel[13] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMovDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[1] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[2] = 5.5f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[3] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[4] = 6.2f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[5] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[6] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[7] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[8] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[9] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[10] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[11] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[12] = 11.11f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel[13] = -4.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabCommonDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[0] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[1] = -3.5f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[2] = 11.1111111111f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[3] = -3.5f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[4] = 16.6666666667f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[5] = -3.5f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[6] = 23.6111111111f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[7] = -3.5f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[8] = 23.6111111111f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel[9] = -3.5f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabMaxDecel_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk1Par.HEAD_BRK_ANEC_CTRL = 0;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParCtrlMaxVelStat = 60.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParCtrlMaxVelBrake = 60.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParCtrlMaxVelMov = 60.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParCtrlMaxStartVrel = 83.3333333333f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParRampOutGrad = 85.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[1] = 1.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[2] = 50.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[3] = 1.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[4] = 50.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[5] = 1.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[6] = 50.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[7] = 1.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[8] = 50.0f;     HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut[9] = 1.0f;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParTabDrvFdkToRampOut_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk1Par.AutoBrkParDrvActToRampOut = 85;
    HEADFuncOut_Veh_AutoBrk1Par.Veh_BrkLevelNr = 1u;
    HEADFuncOut_Veh_AutoBrk1Par.HEAD_LAST_MODULE = 0;


    /*---------------Veh_AutoBrk2----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk2_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk2_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_BRAKE_L2)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk2_OnlyIfAutoBrk1Active)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk2_WaitForAutoBrk1Passive)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_PASSIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk2SensorSource)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk2_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk2_BrakeChainState)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk2_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk2_MaxEgoVel_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk2_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk2_OnlyIfAutoBrk1Active_CCRB)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.35f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEADModuleOutputData.Veh_AutoBrk2.fpCustomOutput = &HEADOutBrakeFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"Veh_AutoBrk2"),
      &(HEADModule[HEAD_AUTOCODE_MOD_Veh_AutoBrk2]),
      &(HEADInternalState_Veh_AutoBrk2),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk2_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.Veh_AutoBrk2)),
      (const void*)&HEADFuncOut_Veh_AutoBrk2Par, HEAD_OR_GROUP_TIMER_Veh_AutoBrk2, HEAD_OR_GROUP_NUM_Veh_AutoBrk2))

    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParBrakeReactionTime = 0.1f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[1] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[2] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[3] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[4] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[5] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[6] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[8] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxCtrlVeloReduct_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[1] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[2] = 27.7777777778f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[3] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[4] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[5] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[6] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[8] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParMaxAllowVeloReduct_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[1] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[3] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[4] = 11.1111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[5] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[6] = 16.6666666667f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[7] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[8] = 23.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[9] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[10] = 58.0555555556f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[11] = -6.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[12] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel[13] = -6.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabBrakeDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[1] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[3] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[4] = 11.1111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[5] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[6] = 16.6666666667f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[7] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[8] = 23.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[9] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[10] = 58.0555555556f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[11] = -6.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[12] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel[13] = -6.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabStatDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[1] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[3] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[4] = 11.1111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[5] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[6] = 16.6666666667f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[7] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[8] = 23.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[9] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[10] = 58.0555555556f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[11] = -6.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[12] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel[13] = -6.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMovDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[1] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[3] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[4] = 11.1111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[5] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[6] = 16.6666666667f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[7] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[8] = 23.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[9] = -9.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[10] = 58.0555555556f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[11] = -6.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[12] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel[13] = -6.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabCommonDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[0] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[1] = -3.5f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[2] = 11.1111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[3] = -3.5f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[4] = 16.6666666667f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[5] = -3.5f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[6] = 23.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[7] = -3.5f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[8] = 23.6111111111f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel[9] = -3.5f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabMaxDecel_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk2Par.HEAD_BRK_ANEC_CTRL = 1;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParCtrlMaxVelStat = 60.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParCtrlMaxVelBrake = 60.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParCtrlMaxVelMov = 60.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParCtrlMaxStartVrel = 83.3333333333f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParRampOutGrad = 85.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[1] = 1.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[2] = 50.0f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[3] = 1.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[4] = 50.0f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[5] = 1.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[6] = 50.0f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[7] = 1.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[8] = 50.0f;     HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut[9] = 1.0f;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParTabDrvFdkToRampOut_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk2Par.AutoBrkParDrvActToRampOut = 85;
    HEADFuncOut_Veh_AutoBrk2Par.Veh_BrkLevelNr = 2u;
    HEADFuncOut_Veh_AutoBrk2Par.HEAD_LAST_MODULE = 0;


    /*---------------Veh_AutoBrk3----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_BRAKE_L3)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_OnlyIfVehAutoBrk2Active)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.1f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk2, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_WaitForAutoBrk1Passive)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_PASSIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      90.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_ObjProb)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      99.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_TTC)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.6f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_TTC3)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_TTC3,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_TTC4)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_TTC4,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -6.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    VehAutoBrk3_AllowedMaxTime_leave_table[0] = 5.55555555556f;
    VehAutoBrk3_AllowedMaxTime_leave_table[1] = 2.0f;
    VehAutoBrk3_AllowedMaxTime_leave_table[2] = 11.1111111111f;
    VehAutoBrk3_AllowedMaxTime_leave_table[3] = 2.0f;
    VehAutoBrk3_AllowedMaxTime_leave_table[4] = 22.2222222222f;
    VehAutoBrk3_AllowedMaxTime_leave_table[5] = 2.0f;
    VehAutoBrk3_AllowedMaxTime_leave_table[6] = 58.0555555556f;
    VehAutoBrk3_AllowedMaxTime_leave_table[7] = 2.0f;
    VehAutoBrk3_AllowedMaxTime_leave_table[8] = 58.3333333333f;
    VehAutoBrk3_AllowedMaxTime_leave_table[9] = 2.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk3_AllowedMaxTime_leave)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_StateActiveTime,
      HEADParamTableType_HostSpeed,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      5u,
      ((const void *)&(VehAutoBrk3_AllowedMaxTime_leave_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk3SensorSource)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Veh_AutoBrk3_BrakeChainState)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(VehAutoBrk3_MaxEgoVel_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.Veh_AutoBrk3.fpCustomOutput = &HEADOutBrakeFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"Veh_AutoBrk3"),
      &(HEADModule[HEAD_AUTOCODE_MOD_Veh_AutoBrk3]),
      &(HEADInternalState_Veh_AutoBrk3),
      (HEADParameterEmpty_t *)((void *)&(VehAutoBrk3_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.Veh_AutoBrk3)),
      (const void*)&HEADFuncOut_Veh_AutoBrk3Par, HEAD_OR_GROUP_TIMER_Veh_AutoBrk3, HEAD_OR_GROUP_NUM_Veh_AutoBrk3))

    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParBrakeReactionTime = 0.1f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[1] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[2] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[3] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[4] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[5] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[6] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[8] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxCtrlVeloReduct_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[1] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[2] = 27.7777777778f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[3] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[4] = 58.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[5] = 16.1111111111f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[6] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[8] = 58.6111111111f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParMaxAllowVeloReduct_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[1] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[3] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[4] = 22.2222222222f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[5] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[6] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[7] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[8] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[9] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[10] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[11] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[12] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel[13] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabBrakeDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[1] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[3] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[4] = 22.2222222222f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[5] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[6] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[7] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[8] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[9] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[10] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[11] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[12] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel[13] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabStatDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[1] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[3] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[4] = 22.2222222222f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[5] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[6] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[7] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[8] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[9] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[10] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[11] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[12] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel[13] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMovDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[1] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[3] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[4] = 22.2222222222f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[5] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[6] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[7] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[8] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[9] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[10] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[11] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[12] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel[13] = -9.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabCommonDecel_Rows = 7u;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[0] = 5.55555555556f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[1] = -3.5f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[2] = 8.33333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[3] = -3.5f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[4] = 22.2222222222f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[5] = -3.5f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[6] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[7] = -3.5f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[8] = 33.3333333333f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel[9] = -3.5f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabMaxDecel_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk3Par.HEAD_BRK_ANEC_CTRL = 1;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParCtrlMaxVelStat = 60.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParCtrlMaxVelBrake = 60.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParCtrlMaxVelMov = 60.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParCtrlMaxStartVrel = 83.3333333333f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParRampOutGrad = 85.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[0] = 0.0f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[1] = 1.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[2] = 50.0f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[3] = 1.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[4] = 50.0f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[5] = 1.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[6] = 50.0f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[7] = 1.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[8] = 50.0f;     HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut[9] = 1.0f;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParTabDrvFdkToRampOut_Rows = 5u;
    HEADFuncOut_Veh_AutoBrk3Par.AutoBrkParDrvActToRampOut = 85;
    HEADFuncOut_Veh_AutoBrk3Par.Veh_BrkLevelNr = 3u;
    HEADFuncOut_Veh_AutoBrk3Par.HEAD_LAST_MODULE = 0;


    /*---------------HBA_TA----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_HBA_THRD)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_EgoVelocity,
      (uint16) (HEADParameterMode_ACC | HEADParameterMode_Early | HEADParameterMode_Late | HEADParameterMode_Middle),
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_MaxEgoVel_Veh)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_MaxEgoVel_HypStat_Veh)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_MaxEgoVel_LongVru)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      50.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_ObjProb_HypMov)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      50.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_ObjProb_HypStat)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      50.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_DrvAcitivity)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_TTC)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      3.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -5.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_ANecLong_Keep)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      -4.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.3f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBATA_DrvActivity_leave)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBATA_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_HBAQualifier)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_CustomPar_07_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_HBAQualifier_leave)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_CustomPar_07_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TA_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBATASensorSource)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      5u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_SteerGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      5u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TATTSPre)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_TTS_PRE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      3.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_TAAllContiditionTrue)),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CutIn) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunUpBraking) | HEADParameterHypothesisBit(CDHypothesisType_RunUpStationary)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.2f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.HBA_TA.fpCustomOutput = &HEADOutHBAFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"HBA_TA"),
      &(HEADModule[HEAD_AUTOCODE_MOD_HBA_TA]),
      &(HEADInternalState_HBA_TA),
      (HEADParameterEmpty_t *)((void *)&(HBA_TA_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.HBA_TA)),
      (const void*)&HEADFuncOut_HBA_TAPar, HEAD_OR_GROUP_TIMER_HBA_TA, HEAD_OR_GROUP_NUM_HBA_TA))

    HEADFuncOut_HBA_TAPar.HBADefaultLevel = 1u;
    HEADFuncOut_HBA_TAPar.HEADHBAaNecToLevelRelation[0] = -10.0f;     HEADFuncOut_HBA_TAPar.HEADHBAaNecToLevelRelation[1] = 3.0f;
    HEADFuncOut_HBA_TAPar.HEADHBAaNecToLevelRelation[2] = -6.0f;     HEADFuncOut_HBA_TAPar.HEADHBAaNecToLevelRelation[3] = 2.0f;
    HEADFuncOut_HBA_TAPar.HEADHBAaNecToLevelRelation[4] = -6.0f;     HEADFuncOut_HBA_TAPar.HEADHBAaNecToLevelRelation[5] = 2.0f;
    HEADFuncOut_HBA_TAPar.HEADHBAaNecToLevelRelation_Rows = 3u;
    HEADFuncOut_HBA_TAPar.HEADHBAEvalOrGroupToLevel = 0u;
    HEADFuncOut_HBA_TAPar.HEADHBAOrGroupToLevelTable[0] = 0u;     HEADFuncOut_HBA_TAPar.HEADHBAOrGroupToLevelTable[1] = 0u;
    HEADFuncOut_HBA_TAPar.HEADHBAOrGroupToLevelTable[2] = 0u;     HEADFuncOut_HBA_TAPar.HEADHBAOrGroupToLevelTable[3] = 0u;
    HEADFuncOut_HBA_TAPar.HEADHBAOrGroupToLevelTable_Rows = 2u;
    HEADFuncOut_HBA_TAPar.HEADHBAKeepLevelFirstOrGroup = -1;
    HEADFuncOut_HBA_TAPar.HEADHBAUseLevelToReqDecel = 1u;
    HEADFuncOut_HBA_TAPar.HEADHBALevelToReqDecelTable[0] = 1.0f;     HEADFuncOut_HBA_TAPar.HEADHBALevelToReqDecelTable[1] = -6.0f;
    HEADFuncOut_HBA_TAPar.HEADHBALevelToReqDecelTable[2] = 2.0f;     HEADFuncOut_HBA_TAPar.HEADHBALevelToReqDecelTable[3] = -10.0f;
    HEADFuncOut_HBA_TAPar.HEADHBALevelToReqDecelTable[4] = 3.0f;     HEADFuncOut_HBA_TAPar.HEADHBALevelToReqDecelTable[5] = -12.0f;
    HEADFuncOut_HBA_TAPar.HEADHBALevelToReqDecelTable_Rows = 3u;
    HEADFuncOut_HBA_TAPar.HEADHBAAccelerationOffset = 0.0f;
    HEADFuncOut_HBA_TAPar.FirstHBAModule = 1u;


    /*---------------HBA_VDS----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_VDS_StayInOFF)),
      (HEADParameterEmpty_t *)((void *)&(HBA_VDS_StayInOFF)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit),
      -1000.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.HBA_VDS.fpCustomOutput = &HEADOutHBAFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"HBA_VDS"),
      &(HEADModule[HEAD_AUTOCODE_MOD_HBA_VDS]),
      &(HEADInternalState_HBA_VDS),
      (HEADParameterEmpty_t *)((void *)&(HBA_VDS_StayInOFF)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.HBA_VDS)),
      (const void*)&HEADFuncOut_HBA_VDSPar, HEAD_OR_GROUP_TIMER_HBA_VDS, HEAD_OR_GROUP_NUM_HBA_VDS))

    HEADFuncOut_HBA_VDSPar.HBADefaultLevel = 4u;
    HEADFuncOut_HBA_VDSPar.HEADHBAaNecToLevelRelation[0] = -10.0f;     HEADFuncOut_HBA_VDSPar.HEADHBAaNecToLevelRelation[1] = 6.0f;
    HEADFuncOut_HBA_VDSPar.HEADHBAaNecToLevelRelation[2] = -6.0f;     HEADFuncOut_HBA_VDSPar.HEADHBAaNecToLevelRelation[3] = 5.0f;
    HEADFuncOut_HBA_VDSPar.HEADHBAaNecToLevelRelation[4] = -6.0f;     HEADFuncOut_HBA_VDSPar.HEADHBAaNecToLevelRelation[5] = 5.0f;
    HEADFuncOut_HBA_VDSPar.HEADHBAaNecToLevelRelation_Rows = 3u;
    HEADFuncOut_HBA_VDSPar.HEADHBAEvalOrGroupToLevel = 0u;
    HEADFuncOut_HBA_VDSPar.HEADHBAOrGroupToLevelTable[0] = 0u;     HEADFuncOut_HBA_VDSPar.HEADHBAOrGroupToLevelTable[1] = 0u;
    HEADFuncOut_HBA_VDSPar.HEADHBAOrGroupToLevelTable[2] = 0u;     HEADFuncOut_HBA_VDSPar.HEADHBAOrGroupToLevelTable[3] = 0u;
    HEADFuncOut_HBA_VDSPar.HEADHBAOrGroupToLevelTable_Rows = 2u;
    HEADFuncOut_HBA_VDSPar.HEADHBAKeepLevelFirstOrGroup = -1;
    HEADFuncOut_HBA_VDSPar.HEADHBAUseLevelToReqDecel = 0u;
    HEADFuncOut_HBA_VDSPar.HEADHBALevelToReqDecelTable[0] = 0.0f;     HEADFuncOut_HBA_VDSPar.HEADHBALevelToReqDecelTable[1] = 0.0f;
    HEADFuncOut_HBA_VDSPar.HEADHBALevelToReqDecelTable[2] = 0.0f;     HEADFuncOut_HBA_VDSPar.HEADHBALevelToReqDecelTable[3] = 0.0f;
    HEADFuncOut_HBA_VDSPar.HEADHBALevelToReqDecelTable[4] = 0.0f;     HEADFuncOut_HBA_VDSPar.HEADHBALevelToReqDecelTable[5] = 0.0f;
    HEADFuncOut_HBA_VDSPar.HEADHBALevelToReqDecelTable_Rows = 3u;
    HEADFuncOut_HBA_VDSPar.HEADHBAAccelerationOffset = -0.5f;
    HEADFuncOut_HBA_VDSPar.FirstHBAModule = 0u;


    /*---------------CrossVru_DynAcuteWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_ACU_WARN | FPS_EBA_INH_BRAKE_L1)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVruDynAcuteWarn_TTC4_table[0] = 0.0f;
    CrossVruDynAcuteWarn_TTC4_table[1] = 0.9f;
    CrossVruDynAcuteWarn_TTC4_table[2] = 9.72222222222f;
    CrossVruDynAcuteWarn_TTC4_table[3] = 1.2f;
    CrossVruDynAcuteWarn_TTC4_table[4] = 11.1111111111f;
    CrossVruDynAcuteWarn_TTC4_table[5] = 1.25f;
    CrossVruDynAcuteWarn_TTC4_table[6] = 12.5f;
    CrossVruDynAcuteWarn_TTC4_table[7] = 1.3f;
    CrossVruDynAcuteWarn_TTC4_table[8] = 13.8888888889f;
    CrossVruDynAcuteWarn_TTC4_table[9] = 1.35f;
    CrossVruDynAcuteWarn_TTC4_table[10] = 15.2777777778f;
    CrossVruDynAcuteWarn_TTC4_table[11] = 1.4f;
    CrossVruDynAcuteWarn_TTC4_table[12] = 16.6666666667f;
    CrossVruDynAcuteWarn_TTC4_table[13] = 1.6f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruDynAcuteWarn_TTC4)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      7u,
      ((const void *)&(CrossVruDynAcuteWarn_TTC4_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_TTC3min)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC3,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.3f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVruDynAcuteWarn_TTSPre_table[0] = 0.0f;
    CrossVruDynAcuteWarn_TTSPre_table[1] = 1.0f;
    CrossVruDynAcuteWarn_TTSPre_table[2] = 5.55555555556f;
    CrossVruDynAcuteWarn_TTSPre_table[3] = 1.0f;
    CrossVruDynAcuteWarn_TTSPre_table[4] = 15.5555555556f;
    CrossVruDynAcuteWarn_TTSPre_table[5] = 1.6f;
    CrossVruDynAcuteWarn_TTSPre_table[6] = 19.4444444444f;
    CrossVruDynAcuteWarn_TTSPre_table[7] = 1.2f;
    CrossVruDynAcuteWarn_TTSPre_table[8] = 27.7777777778f;
    CrossVruDynAcuteWarn_TTSPre_table[9] = 1.2f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruDynAcuteWarn_TTSPre)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(CrossVruDynAcuteWarn_TTSPre_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVruDynAcuteWarn_TTSAcute_table[0] = 0.0f;
    CrossVruDynAcuteWarn_TTSAcute_table[1] = 1.2f;
    CrossVruDynAcuteWarn_TTSAcute_table[2] = 5.55555555556f;
    CrossVruDynAcuteWarn_TTSAcute_table[3] = 1.2f;
    CrossVruDynAcuteWarn_TTSAcute_table[4] = 15.5555555556f;
    CrossVruDynAcuteWarn_TTSAcute_table[5] = 1.8f;
    CrossVruDynAcuteWarn_TTSAcute_table[6] = 19.4444444444f;
    CrossVruDynAcuteWarn_TTSAcute_table[7] = 1.4f;
    CrossVruDynAcuteWarn_TTSAcute_table[8] = 27.7777777778f;
    CrossVruDynAcuteWarn_TTSAcute_table[9] = 1.4f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruDynAcuteWarn_TTSAcute)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      5u,
      ((const void *)&(CrossVruDynAcuteWarn_TTSAcute_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      3.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.3f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_MinTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_KeepIfPedBrkActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 1u)))

  
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[0] = 0.0f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[1] = 0.1f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[2] = 0.008f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[3] = 0.1f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[4] = 0.009f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[5] = 0.2f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[6] = 0.1f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[7] = 0.3f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[8] = 0.2f;
    CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[9] = 0.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVru_DynAcuteWarnAllConditionsTRUEStat)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(CrossVru_DynAcuteWarnAllConditionsTRUEStat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Brake_Passive_Tran4_CondG0_CheckwithinCorridorPed_Warn)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_05_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_AllConditionsTRUEDrivActPedcoll_warn)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_DriverActivity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(VehAutoBrk1_AllConditionsTRUEDrivActPedcoll_warn_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_FPS_Warn_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_00_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DynAcuteSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVRU_DynAcutewarn_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_DrvActivity_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      3u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DynAcuteWarn_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_TTCmax_Late)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.8f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DynAcuteWarnObjMovDir)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjMoveDir,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DynAcuteWarnObjMovDir_Cross)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjMoveDir,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[0] = -7.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[1] = -4.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[2] = -6.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[3] = -4.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[4] = -5.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[5] = -6.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[6] = -4.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[7] = -5.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[8] = -3.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[9] = -4.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[10] = -2.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[11] = -3.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[12] = -1.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[13] = -2.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[14] = 0.0f;
    CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[15] = 0.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVRUDynAcuteWarn_EgoAccX_NAcc)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostAccel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      8u,
      ((const void *)&(CrossVRUDynAcuteWarn_EgoAccX_NAcc_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVruDynAcuteWarn_NecLat_table[0] = 0.0f;
    CrossVruDynAcuteWarn_NecLat_table[1] = 1.0f;
    CrossVruDynAcuteWarn_NecLat_table[2] = 2.77777777778f;
    CrossVruDynAcuteWarn_NecLat_table[3] = 1.0f;
    CrossVruDynAcuteWarn_NecLat_table[4] = 5.55555555556f;
    CrossVruDynAcuteWarn_NecLat_table[5] = 1.0f;
    CrossVruDynAcuteWarn_NecLat_table[6] = 8.33333333333f;
    CrossVruDynAcuteWarn_NecLat_table[7] = 1.1f;
    CrossVruDynAcuteWarn_NecLat_table[8] = 11.1111111111f;
    CrossVruDynAcuteWarn_NecLat_table[9] = 1.2f;
    CrossVruDynAcuteWarn_NecLat_table[10] = 13.3333333333f;
    CrossVruDynAcuteWarn_NecLat_table[11] = 0.0f;
    CrossVruDynAcuteWarn_NecLat_table[12] = 15.8333333333f;
    CrossVruDynAcuteWarn_NecLat_table[13] = 0.0f;
    CrossVruDynAcuteWarn_NecLat_table[14] = 17.2222222222f;
    CrossVruDynAcuteWarn_NecLat_table[15] = 0.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruDynAcuteWarn_NecLat)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ANecLatAbs,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      8u,
      ((const void *)&(CrossVruDynAcuteWarn_NecLat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_HypProb_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      30.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_MaxDistX)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjectDist,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      26.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[0] = 1.11111111111f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[1] = 0.15f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[2] = 1.38888888889f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[3] = 0.15f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[4] = 1.66666666667f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[5] = 0.15f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[6] = 1.94444444444f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[7] = 0.15f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[8] = 2.22222222222f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[9] = 0.1f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[10] = 2.5f;
    CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[11] = 0.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVru_DynAcuteWarnAllConditionsLowSpeed)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(CrossVru_DynAcuteWarnAllConditionsLowSpeed_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_ObjVelY)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_07_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.555555555556f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[0] = 0.0f;
    CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[1] = 0.0f;
    CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[2] = 19.0f;
    CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[3] = 0.0f;
    CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[4] = 20.0f;
    CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[5] = 0.1f;
    CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[6] = 40.0f;
    CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[7] = 0.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(FCWCrossVRUbrake_lowspeed)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_08_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

  
    CrossVruDynAcuteWarn_TTC4DrvFactor_table[0] = 0.0f;
    CrossVruDynAcuteWarn_TTC4DrvFactor_table[1] = 1.0f;
    CrossVruDynAcuteWarn_TTC4DrvFactor_table[2] = 33.0f;
    CrossVruDynAcuteWarn_TTC4DrvFactor_table[3] = 0.9f;
    CrossVruDynAcuteWarn_TTC4DrvFactor_table[4] = 66.0f;
    CrossVruDynAcuteWarn_TTC4DrvFactor_table[5] = 0.75f;
    CrossVruDynAcuteWarn_TTC4DrvFactor_table[6] = 90.0f;
    CrossVruDynAcuteWarn_TTC4DrvFactor_table[7] = 0.65f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruDynAcuteWarn_TTC4DrvFactor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(CrossVruDynAcuteWarn_TTC4DrvFactor_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruDynAcuteWarn_TTC4KeepFactor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC4,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DynAcuteWarnTTC4Late_Factor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC4,
      (uint16) (HEADParameterMode_Late),
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      0.98f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DynAcuteWarnTTC4Early_Factor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC4,
      (uint16) (HEADParameterMode_ACC | HEADParameterMode_Early),
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      1.1f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

  
    CrossVruDynAcuteWarn_HypProbFactor_table[0] = 0.0f;
    CrossVruDynAcuteWarn_HypProbFactor_table[1] = 1.0f;
    CrossVruDynAcuteWarn_HypProbFactor_table[2] = 0.008f;
    CrossVruDynAcuteWarn_HypProbFactor_table[3] = 1.0f;
    CrossVruDynAcuteWarn_HypProbFactor_table[4] = 0.009f;
    CrossVruDynAcuteWarn_HypProbFactor_table[5] = 1.3f;
    CrossVruDynAcuteWarn_HypProbFactor_table[6] = 0.01f;
    CrossVruDynAcuteWarn_HypProbFactor_table[7] = 1.3f;
    CrossVruDynAcuteWarn_HypProbFactor_table[8] = 0.02f;
    CrossVruDynAcuteWarn_HypProbFactor_table[9] = 1.8f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruDynAcuteWarn_HypProbFactor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_HypProb,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(CrossVruDynAcuteWarn_HypProbFactor_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[0] = 1.11111111111f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[1] = 0.6f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[2] = 1.38888888889f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[3] = 0.6f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[4] = 1.66666666667f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[5] = 0.6f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[6] = 1.94444444444f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[7] = 0.7f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[8] = 2.22222222222f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[9] = 0.8f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[10] = 2.5f;
    CrossVruDynAcuteWarn_TTSAcuteFactor_table[11] = 1.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruDynAcuteWarn_TTSAcuteFactor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(CrossVruDynAcuteWarn_TTSAcuteFactor_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.CrossVru_DynAcuteWarn.fpCustomOutput = &HEADOutWarnFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"CrossVru_DynAcuteWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn]),
      &(HEADInternalState_CrossVru_DynAcuteWarn),
      (HEADParameterEmpty_t *)((void *)&(CrossVruDynAcuteWarn_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.CrossVru_DynAcuteWarn)),
      (const void*)&HEADFuncOut_CrossVru_DynAcuteWarnPar, HEAD_OR_GROUP_TIMER_CrossVru_DynAcuteWarn, HEAD_OR_GROUP_NUM_CrossVru_DynAcuteWarn))



    /*---------------CrossVru_HaptDynWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_ACU_WARN | FPS_EBA_INH_BRAKE_L1)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_OnlyIfDynAcuteActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarnOnlyIf_HaptDynWarn_NotActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_HaptDynWarn, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_OnlyIf_LongVru_HaptDynWarn_NotActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7.625f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      40.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVruHaptWarn_TTC4EgoVel_table[0] = 0.0f;
    CrossVruHaptWarn_TTC4EgoVel_table[1] = 1.05f;
    CrossVruHaptWarn_TTC4EgoVel_table[2] = 4.16666666667f;
    CrossVruHaptWarn_TTC4EgoVel_table[3] = 1.05f;
    CrossVruHaptWarn_TTC4EgoVel_table[4] = 5.55555555556f;
    CrossVruHaptWarn_TTC4EgoVel_table[5] = 1.11f;
    CrossVruHaptWarn_TTC4EgoVel_table[6] = 6.94444444444f;
    CrossVruHaptWarn_TTC4EgoVel_table[7] = 1.2f;
    CrossVruHaptWarn_TTC4EgoVel_table[8] = 11.1111111111f;
    CrossVruHaptWarn_TTC4EgoVel_table[9] = 1.374f;
    CrossVruHaptWarn_TTC4EgoVel_table[10] = 13.8888888889f;
    CrossVruHaptWarn_TTC4EgoVel_table[11] = 1.512f;
    CrossVruHaptWarn_TTC4EgoVel_table[12] = 16.6666666667f;
    CrossVruHaptWarn_TTC4EgoVel_table[13] = 1.533f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruHaptWarn_TTC4EgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(CrossVruHaptWarn_TTC4EgoVel_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_TTCmax)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_TTC3min)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC3,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.3f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.15f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_MinTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_DynAcuteSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_DynAcutewarn_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_DrvActivity_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      3u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHaptDyn_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHaptDyn_ANecLong_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHaptDynWarn_WarnChainState)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_05_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHaptDynWarn_WarnChainState_leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_05_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_SteeringGrad_leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarnOnlyIf_CrossVru_PreBrk_Not_In_Actv)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.001f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHaptDynWarn_HypProb_KeepPassive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVru_HaptDynWarn_TTC4DrvFactor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(CrossVruDynAcuteWarn_TTC4DrvFactor_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HaptDynWarn_TTC4KeepFactor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC4,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.CrossVru_HaptDynWarn.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"CrossVru_HaptDynWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn]),
      &(HEADInternalState_CrossVru_HaptDynWarn),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_HaptDynWarn_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.CrossVru_HaptDynWarn)),
      NULL, HEAD_OR_GROUP_TIMER_CrossVru_HaptDynWarn, HEAD_OR_GROUP_NUM_CrossVru_HaptDynWarn))



    /*---------------CrossVru_HBA----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_HBA_THRD)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_OnlyIfCrossVruAcuteWarn)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      35.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_DrvActivity)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -3.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_ANecLong_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      -0.1f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.3f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_KeepIfCrossVruPreBrkActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HBASensorSource)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossHBATA_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HBADriverActivity_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HBA_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HBA_HBAQualifier)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_07_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(HBA_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HBA_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HBA_HBAQualifier_leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_07_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      4u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HBA_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      5u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_HBA_SteerGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      5u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruHBA_HypProb_KeepPassive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.CrossVru_HBA.fpCustomOutput = &HEADOutHBAFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"CrossVru_HBA"),
      &(HEADModule[HEAD_AUTOCODE_MOD_CrossVru_HBA]),
      &(HEADInternalState_CrossVru_HBA),
      (HEADParameterEmpty_t *)((void *)&(CrossVruHBA_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.CrossVru_HBA)),
      (const void*)&HEADFuncOut_CrossVru_HBAPar, HEAD_OR_GROUP_TIMER_CrossVru_HBA, HEAD_OR_GROUP_NUM_CrossVru_HBA))



    /*---------------CrossVru_Prefill----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreFill_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_PRE_FILL)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreFill_OnlyIfVehAutoBrk1NotActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreFill_OnlyIfCrossVruPreBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreFill_OnlyIfLongVruPreBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreFill_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreFill_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreFill_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      30.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    CrossVruPrefill_TTC4_table[0] = 0.0f;
    CrossVruPrefill_TTC4_table[1] = 1.5f;
    CrossVruPrefill_TTC4_table[2] = 5.55555555556f;
    CrossVruPrefill_TTC4_table[3] = 1.5f;
    CrossVruPrefill_TTC4_table[4] = 11.1111111111f;
    CrossVruPrefill_TTC4_table[5] = 1.7f;
    CrossVruPrefill_TTC4_table[6] = 16.6666666667f;
    CrossVruPrefill_TTC4_table[7] = 1.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruPrefill_TTC4)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(CrossVruPrefill_TTC4_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPrefill_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      -0.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPrefill_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPrefill_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PrefillSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossPrefill_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossPrefillDriverFeedback_BrakePedal)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVRU_Prefill_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Prefill_PrefillQualifier)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_CustomPar_06_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Prefill_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Prefill_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Prefill_DriverActivity)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DrvActivity_keeppasive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Prefill_PrefillQualifier_leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_CustomPar_06_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Prefill_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPrefill_OnlyIfCrossVruAcuteWarn)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Prefill_SteerGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPrefill_HypProb_KeepPassive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.CrossVru_Prefill.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"CrossVru_Prefill"),
      &(HEADModule[HEAD_AUTOCODE_MOD_CrossVru_Prefill]),
      &(HEADInternalState_CrossVru_Prefill),
      (HEADParameterEmpty_t *)((void *)&(CrossVru_PreFill_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.CrossVru_Prefill)),
      NULL, HEAD_OR_GROUP_TIMER_CrossVru_Prefill, HEAD_OR_GROUP_NUM_CrossVru_Prefill))



    /*---------------CrossVru_PreBrk----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_BRAKE_L1)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_OnlyIfCrossVruDynWarnActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_OnlyIfVehAutoBrk1NotActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_OnlyIfVehAutoBrk1NotWait)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_WAIT, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_OnlyIfLongVruBrk1NotActive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_OnlyIfLongVruBrk1NotWait)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_WAIT, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_MinEgoVel_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      22.859375f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_HypProb_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      30.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -70.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_DrvActivity)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

  
    CrossVruPreBrk_TTC4EgoVel_table[0] = 0.0f;
    CrossVruPreBrk_TTC4EgoVel_table[1] = 0.9f;
    CrossVruPreBrk_TTC4EgoVel_table[2] = 4.16666666667f;
    CrossVruPreBrk_TTC4EgoVel_table[3] = 0.9f;
    CrossVruPreBrk_TTC4EgoVel_table[4] = 5.55555555556f;
    CrossVruPreBrk_TTC4EgoVel_table[5] = 0.97f;
    CrossVruPreBrk_TTC4EgoVel_table[6] = 6.94444444444f;
    CrossVruPreBrk_TTC4EgoVel_table[7] = 1.09f;
    CrossVruPreBrk_TTC4EgoVel_table[8] = 8.33333333333f;
    CrossVruPreBrk_TTC4EgoVel_table[9] = 0.9f;
    CrossVruPreBrk_TTC4EgoVel_table[10] = 9.72222222222f;
    CrossVruPreBrk_TTC4EgoVel_table[11] = 1.0f;
    CrossVruPreBrk_TTC4EgoVel_table[12] = 11.1111111111f;
    CrossVruPreBrk_TTC4EgoVel_table[13] = 1.27f;
    CrossVruPreBrk_TTC4EgoVel_table[14] = 13.8888888889f;
    CrossVruPreBrk_TTC4EgoVel_table[15] = 1.44f;
    CrossVruPreBrk_TTC4EgoVel_table[16] = 16.6666666667f;
    CrossVruPreBrk_TTC4EgoVel_table[17] = 1.46f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruPreBrk_TTC4EgoVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      9u,
      ((const void *)&(CrossVruPreBrk_TTC4EgoVel_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_TTC3min)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_TTC3,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.15f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_ANecLong_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_DistXSafe)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_ObjectDist,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_ClosingVel)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_ClosingVel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk_VRel_KeepWait_OR1)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit | HEADParameterState_KeepWaitBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Brake_Passive_Tran4_CondG0_CheckwithinCorridorPed)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_05_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(VehAutoBrk1_AllConditionsTRUEDrivActPedcoll)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_DriverActivity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(VehAutoBrk1_AllConditionsTRUEDrivActPedcoll_warn_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_FPS_PreBrk_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_00_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrkSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Prebrk_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk_BrakeChainState)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Brk1_Curve_Min)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_EgoLatCurvature,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_Brk1_Curve_Max)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_EgoLatCurvature,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk_LatDistY_Thr_min)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_ObjectDistLat,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -3.7f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_AutoBrk1_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_AutoBrk1_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_DriverActivity_Leave_OR4)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk_BrakeChainState_leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      5u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      6u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk_SteerGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      6u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk1_ObjMovDir)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_ObjMoveDir,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk_ObjVelY)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_07_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.555555555556f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrsVRUBRK1AllConditionsTRUE_MovingYawrate)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(BRK1AllConditionsTRUE_MovingYawrate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrkDriverBrake_lowspeed)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_CustomPar_08_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVRUPreBrakeAllConditionsTRUE_SteerGrad)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(CrossVruPreBrk_TTC4DrvFactor)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_DriverAttention,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      5u,
      ((const void *)&(CrossVruPreBrk_TTC4DrvFactor_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      8.33333333333f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.CrossVru_PreBrk.fpCustomOutput = &HEADOutBrakeFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"CrossVru_PreBrk"),
      &(HEADModule[HEAD_AUTOCODE_MOD_CrossVru_PreBrk]),
      &(HEADInternalState_CrossVru_PreBrk),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.CrossVru_PreBrk)),
      (const void*)&HEADFuncOut_CrossVru_PreBrkPar, HEAD_OR_GROUP_TIMER_CrossVru_PreBrk, HEAD_OR_GROUP_NUM_CrossVru_PreBrk))



    /*---------------CrossVru_PreBrk2----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk2_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk2_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_BRAKE_L2)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk2_OnlyIfCrossVruPreBrk1)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk2_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk2_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      50.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk2_WaitForCrossVruBrk1Passive)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_PASSIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrklSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk2_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVru_PreBrk2_BrakeChainState)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk2_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(CrossVruPreBrk2_HypProb_keep)),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk2_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      32.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.CrossVru_PreBrk2.fpCustomOutput = &HEADOutBrakeFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"CrossVru_PreBrk2"),
      &(HEADModule[HEAD_AUTOCODE_MOD_CrossVru_PreBrk2]),
      &(HEADInternalState_CrossVru_PreBrk2),
      (HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk2_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.CrossVru_PreBrk2)),
      (const void*)&HEADFuncOut_CrossVru_PreBrk2Par, HEAD_OR_GROUP_TIMER_CrossVru_PreBrk2, HEAD_OR_GROUP_NUM_CrossVru_PreBrk2))



    /*---------------LongVru_DynAcuteWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_ACU_WARN)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      50.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_HypProb_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      40.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_ObjProb)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      90.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_TTBAcute)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.45f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_TTCMin)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.3f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_MinDistX)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjectDist,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_TTSPre)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_PRE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.85f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_TTSAcute)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTS_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      3.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.3f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_MinTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_KeepIfLongVruBrkActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_DynAcutelSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_DynAcute_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcute_DrvActivity_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      50.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_DynAcuteWarn_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_HypProb_StationVRU)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      38.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_HypProb_StationVRU_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      30.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[0] = 0.0f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[1] = 0.35f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[2] = 5.55555555556f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[3] = 0.35f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[4] = 8.33333333333f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[5] = 0.35f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[6] = 8.61111111111f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[7] = 0.35f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[8] = 16.6666666667f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[9] = 0.35f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[10] = 18.0555555556f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[11] = 0.35f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[12] = 19.4444444444f;
    LongVRUDynAcuteWarn_ObjCorridor_Stat_table[13] = 0.35f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUDynAcuteWarn_ObjCorridor_Stat)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVRUDynAcuteWarn_ObjCorridor_Stat_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_DynAcuteWarnObjMovDir)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjMoveDir,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[0] = -13.8888888889f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[1] = 1.9f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[2] = -12.7777777778f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[3] = 1.9f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[4] = -12.5f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[5] = 1.9f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[6] = -11.1111111111f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[7] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[8] = -5.55555555556f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[9] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[10] = -4.16666666667f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[11] = 1.5f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[12] = 0.0f;
    LongVruDynAcuteWarn_TTCMax_middle_ped_table[13] = 0.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_TTCMax_middle_ped)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_Middle),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruDynAcuteWarn_TTCMax_middle_ped_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruDynAcuteWarn_TTCMax_early_ped_table[0] = -13.8888888889f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[1] = 1.9f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[2] = -12.7777777778f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[3] = 1.9f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[4] = -12.5f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[5] = 1.9f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[6] = -11.1111111111f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[7] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[8] = -5.55555555556f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[9] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[10] = -4.16666666667f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[11] = 1.6f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[12] = 0.0f;
    LongVruDynAcuteWarn_TTCMax_early_ped_table[13] = 0.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_TTCMax_early_ped)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_ACC | HEADParameterMode_Early),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruDynAcuteWarn_TTCMax_early_ped_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruDynAcuteWarn_TTCMax_late_ped_table[0] = -13.8888888889f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[1] = 1.6f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[2] = -12.7777777778f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[3] = 1.6f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[4] = -12.5f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[5] = 1.6f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[6] = -11.1111111111f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[7] = 1.5f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[8] = -5.55555555556f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[9] = 1.5f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[10] = -4.16666666667f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[11] = 1.4f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[12] = 0.0f;
    LongVruDynAcuteWarn_TTCMax_late_ped_table[13] = 0.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_TTCMax_late_ped)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_Late),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruDynAcuteWarn_TTCMax_late_ped_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[0] = -13.8888888889f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[1] = 1.9f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[2] = -8.88888888889f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[3] = 1.9f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[4] = -8.61111111111f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[5] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[6] = -8.33333333333f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[7] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[8] = -5.55555555556f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[9] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[10] = -4.16666666667f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[11] = 1.5f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[12] = 0.0f;
    LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[13] = 0.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_TTCMax_middle_cyclist)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_Middle),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruDynAcuteWarn_TTCMax_middle_cyclist_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[0] = -13.8888888889f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[1] = 2.2f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[2] = -8.88888888889f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[3] = 2.2f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[4] = -8.61111111111f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[5] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[6] = -8.33333333333f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[7] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[8] = -5.55555555556f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[9] = 1.7f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[10] = -4.16666666667f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[11] = 1.6f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[12] = 0.0f;
    LongVruDynAcuteWarn_TTCMax_early_cyclist_table[13] = 0.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_TTCMax_early_cyclist)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_ACC | HEADParameterMode_Early),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruDynAcuteWarn_TTCMax_early_cyclist_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[0] = -13.8888888889f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[1] = 1.6f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[2] = -8.88888888889f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[3] = 1.6f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[4] = -8.61111111111f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[5] = 1.5f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[6] = -8.33333333333f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[7] = 1.5f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[8] = -5.55555555556f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[9] = 1.5f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[10] = -4.16666666667f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[11] = 1.4f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[12] = 0.0f;
    LongVruDynAcuteWarn_TTCMax_late_cyclist_table[13] = 0.7f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_TTCMax_late_cyclist)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC,
      HEADParamTableType_VRelX,
      (uint16) (HEADParameterMode_Late),
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruDynAcuteWarn_TTCMax_late_cyclist_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[0] = -7.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[1] = -4.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[2] = -6.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[3] = -4.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[4] = -5.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[5] = -6.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[6] = -4.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[7] = -5.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[8] = -3.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[9] = -4.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[10] = -2.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[11] = -3.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[12] = -1.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[13] = -2.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[14] = -0.9f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[15] = -1.5f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[16] = -0.8f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[17] = -0.5f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[18] = 0.0f;
    LongVRUDynAcuteWarn_EgoAccX_NAcc_table[19] = -0.5f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUDynAcuteWarn_EgoAccX_NAcc)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostAccel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      10u,
      ((const void *)&(LongVRUDynAcuteWarn_EgoAccX_NAcc_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_DynAcuteWarnMaxDistX)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ObjectDist,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[0] = 0.0f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[1] = 0.0f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[2] = 0.006f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[3] = 0.0f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[4] = 0.007f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[5] = 0.1f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[6] = 0.02f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[7] = 0.3f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[8] = 0.04f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[9] = 0.3f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[10] = 0.1f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[11] = 0.4f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[12] = 0.2f;
    LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[13] = 0.5f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVRUDynAcuteWarnAllConditionsTRUE_Yawrate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruDynAcuteWarn_NecLatAcc_table[0] = 0.0f;
    LongVruDynAcuteWarn_NecLatAcc_table[1] = 0.0f;
    LongVruDynAcuteWarn_NecLatAcc_table[2] = 0.008f;
    LongVruDynAcuteWarn_NecLatAcc_table[3] = 0.0f;
    LongVruDynAcuteWarn_NecLatAcc_table[4] = 0.009f;
    LongVruDynAcuteWarn_NecLatAcc_table[5] = 0.8f;
    LongVruDynAcuteWarn_NecLatAcc_table[6] = 0.01f;
    LongVruDynAcuteWarn_NecLatAcc_table[7] = 1.0f;
    LongVruDynAcuteWarn_NecLatAcc_table[8] = 0.02f;
    LongVruDynAcuteWarn_NecLatAcc_table[9] = 2.0f;
    LongVruDynAcuteWarn_NecLatAcc_table[10] = 0.03f;
    LongVruDynAcuteWarn_NecLatAcc_table[11] = 3.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_NecLatAcc)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ANecLatAbs,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(LongVruDynAcuteWarn_NecLatAcc_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[0] = 0.0f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[1] = 0.3f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[2] = 5.55555555556f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[3] = 0.3f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[4] = 8.33333333333f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[5] = 0.3f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[6] = 8.61111111111f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[7] = 0.3f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[8] = 16.6666666667f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[9] = 0.3f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[10] = 18.0555555556f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[11] = 0.3f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[12] = 19.4444444444f;
    LongVRUDynAcuteWarn_ObjCorridor_Sta_table[13] = 0.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUDynAcuteWarn_ObjCorridor_Sta)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CorridorOccupancy,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVRUDynAcuteWarn_ObjCorridor_Sta_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVRUDynAcuteWarn_AllCondtionLowSpd_table[0] = 1.11111111111f;
    LongVRUDynAcuteWarn_AllCondtionLowSpd_table[1] = 0.2f;
    LongVRUDynAcuteWarn_AllCondtionLowSpd_table[2] = 1.38888888889f;
    LongVRUDynAcuteWarn_AllCondtionLowSpd_table[3] = 0.2f;
    LongVRUDynAcuteWarn_AllCondtionLowSpd_table[4] = 2.22222222222f;
    LongVRUDynAcuteWarn_AllCondtionLowSpd_table[5] = 0.2f;
    LongVRUDynAcuteWarn_AllCondtionLowSpd_table[6] = 2.5f;
    LongVRUDynAcuteWarn_AllCondtionLowSpd_table[7] = 0.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUDynAcuteWarn_AllCondtionLowSpd)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(LongVRUDynAcuteWarn_AllCondtionLowSpd_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruDynAcuteWarn_TTC4_table[0] = 0.0f;
    LongVruDynAcuteWarn_TTC4_table[1] = 0.0f;
    LongVruDynAcuteWarn_TTC4_table[2] = 1.11111111111f;
    LongVruDynAcuteWarn_TTC4_table[3] = 0.9f;
    LongVruDynAcuteWarn_TTC4_table[4] = 1.38888888889f;
    LongVruDynAcuteWarn_TTC4_table[5] = 0.9f;
    LongVruDynAcuteWarn_TTC4_table[6] = 1.66666666667f;
    LongVruDynAcuteWarn_TTC4_table[7] = 1.0f;
    LongVruDynAcuteWarn_TTC4_table[8] = 1.94444444444f;
    LongVruDynAcuteWarn_TTC4_table[9] = 1.0f;
    LongVruDynAcuteWarn_TTC4_table[10] = 2.22222222222f;
    LongVruDynAcuteWarn_TTC4_table[11] = 5.0f;
    LongVruDynAcuteWarn_TTC4_table[12] = 2.5f;
    LongVruDynAcuteWarn_TTC4_table[13] = 5.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_TTC4)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruDynAcuteWarn_TTC4_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_DynAcuteWarnMaxVrelY)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_07_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.555555555556f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUDynAcuteWarnAllConditionsTRUE_SteerGrad)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(FCWLongVRUbrake_lowspeed)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_CustomPar_08_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

  
    LongVruFCW_VelXDealy_table[0] = 0.0f;
    LongVruFCW_VelXDealy_table[1] = 0.0f;
    LongVruFCW_VelXDealy_table[2] = 0.8f;
    LongVruFCW_VelXDealy_table[3] = 0.0f;
    LongVruFCW_VelXDealy_table[4] = 0.9f;
    LongVruFCW_VelXDealy_table[5] = 0.5f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruFCW_VelXDealy)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_08_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      3u,
      ((const void *)&(LongVruFCW_VelXDealy_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruDynAcuteWarn_TTBAcuteKeepFactor)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.7f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

  
    LongVruDynAcuteWarn_NecLat_table[0] = 0.0f;
    LongVruDynAcuteWarn_NecLat_table[1] = 1.0f;
    LongVruDynAcuteWarn_NecLat_table[2] = 0.008f;
    LongVruDynAcuteWarn_NecLat_table[3] = 1.0f;
    LongVruDynAcuteWarn_NecLat_table[4] = 0.009f;
    LongVruDynAcuteWarn_NecLat_table[5] = 0.8f;
    LongVruDynAcuteWarn_NecLat_table[6] = 0.01f;
    LongVruDynAcuteWarn_NecLat_table[7] = 0.8f;
    LongVruDynAcuteWarn_NecLat_table[8] = 0.02f;
    LongVruDynAcuteWarn_NecLat_table[9] = 0.6f;
    LongVruDynAcuteWarn_NecLat_table[10] = 0.03f;
    LongVruDynAcuteWarn_NecLat_table[11] = 0.3f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruDynAcuteWarn_NecLat)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ANecLatAbs,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(LongVruDynAcuteWarn_NecLat_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVRUFCW_EgoAccX_NAcc_Factor_table[0] = -7.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[1] = 2.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[2] = -6.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[3] = 2.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[4] = -5.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[5] = 2.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[6] = -4.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[7] = 2.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[8] = -3.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[9] = 2.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[10] = -2.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[11] = 2.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[12] = -1.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[13] = 2.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[14] = -0.9f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[15] = 1.5f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[16] = -0.8f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[17] = 1.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[18] = 0.0f;
    LongVRUFCW_EgoAccX_NAcc_Factor_table[19] = 1.0f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUFCW_EgoAccX_NAcc_Factor)),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostAccel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      10u,
      ((const void *)&(LongVRUFCW_EgoAccX_NAcc_Factor_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.LongVru_DynAcuteWarn.fpCustomOutput = &HEADOutWarnFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"LongVru_DynAcuteWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn]),
      &(HEADInternalState_LongVru_DynAcuteWarn),
      (HEADParameterEmpty_t *)((void *)&(LongVruDynAcuteWarn_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.LongVru_DynAcuteWarn)),
      (const void*)&HEADFuncOut_LongVru_DynAcuteWarnPar, HEAD_OR_GROUP_TIMER_LongVru_DynAcuteWarn, HEAD_OR_GROUP_NUM_LongVru_DynAcuteWarn))



    /*---------------LongVru_HaptDynWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_ACU_WARN | FPS_EBA_INH_BRAKE_L1)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_OnlyIfDynAcuteActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.15f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_OnlyIfHaptDynWarn_NoInActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_HaptDynWarn, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_OnlyIf_CrossVru_HaptDynWarn_NoInActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7.625f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      40.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruHaptWarn_TTC4EgoVel_table[0] = 0.0f;
    LongVruHaptWarn_TTC4EgoVel_table[1] = 1.226f;
    LongVruHaptWarn_TTC4EgoVel_table[2] = 4.16666666667f;
    LongVruHaptWarn_TTC4EgoVel_table[3] = 1.23f;
    LongVruHaptWarn_TTC4EgoVel_table[4] = 5.55555555556f;
    LongVruHaptWarn_TTC4EgoVel_table[5] = 1.23f;
    LongVruHaptWarn_TTC4EgoVel_table[6] = 6.94444444444f;
    LongVruHaptWarn_TTC4EgoVel_table[7] = 1.4f;
    LongVruHaptWarn_TTC4EgoVel_table[8] = 11.1111111111f;
    LongVruHaptWarn_TTC4EgoVel_table[9] = 1.68f;
    LongVruHaptWarn_TTC4EgoVel_table[10] = 13.8888888889f;
    LongVruHaptWarn_TTC4EgoVel_table[11] = 1.85f;
    LongVruHaptWarn_TTC4EgoVel_table[12] = 16.6666666667f;
    LongVruHaptWarn_TTC4EgoVel_table[13] = 1.99f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruHaptWarn_TTC4EgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruHaptWarn_TTC4EgoVel_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_TTCmax)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      2.3f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_TTC3min)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTC3,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.3f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.2f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_MinTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.01f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_DynAcuteSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_DynAcutewarn_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_DrvActivity_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      3u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHaptDyn_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHaptDyn_ANecLong_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHaptDyn_TTBAcute)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.3f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHaptDynWarn_WarnChainState)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_05_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHaptDynWarn_WarnChainState_leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_05_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_SteeringGrad_leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarnOnlyIf_LongBru_Brk1)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.001f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HaptDynWarn_HypProb_KeepPassive)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHaptDynWarn_HypProb_StationVRU)),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      30.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.LongVru_HaptDynWarn.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"LongVru_HaptDynWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn]),
      &(HEADInternalState_LongVru_HaptDynWarn),
      (HEADParameterEmpty_t *)((void *)&(LongVru_HaptDynWarn_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.LongVru_HaptDynWarn)),
      NULL, HEAD_OR_GROUP_TIMER_LongVru_HaptDynWarn, HEAD_OR_GROUP_NUM_LongVru_HaptDynWarn))



    /*---------------LongVru_HBA----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_HBA_THRD)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_OnlyIfLongVruAcuteWarn)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      35.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_DrvActivity)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -3.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_ANecLong_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      -0.1f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.3f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_KeepIfLongVruPreBrkActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBASensorSource)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongHBATA_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBADriverActivity_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBA_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBA_HBAQualifier)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_07_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBA_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBA_HBAQualifier_leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_07_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      4u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBA_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      5u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBA_SteerGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      5u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_HBA_HypProb_KeepPassive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_HypProb_StationVRU)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      35.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruHBA_HypProb_StationVRU_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      35.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.LongVru_HBA.fpCustomOutput = &HEADOutHBAFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"LongVru_HBA"),
      &(HEADModule[HEAD_AUTOCODE_MOD_LongVru_HBA]),
      &(HEADInternalState_LongVru_HBA),
      (HEADParameterEmpty_t *)((void *)&(LongVruHBA_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.LongVru_HBA)),
      (const void*)&HEADFuncOut_LongVru_HBAPar, HEAD_OR_GROUP_TIMER_LongVru_HBA, HEAD_OR_GROUP_NUM_LongVru_HBA))



    /*---------------LongVru_Prefill----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPreFill_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_PRE_FILL)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_OnlyIfVehAutoBrk1NotActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_OnlyIfCrossVruPreBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_OnlyIfLongVruBrk1NotActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPreFill_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      60.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_TTBAcute)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.7f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      -0.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefil_MaxTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_PrefillSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongPrefill_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongPrefillDriverFeedback_BrakePedal)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_PrefillDriverActivity)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_PrefillQualifier)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_CustomPar_06_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_PrefillQualifier_leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_CustomPar_06_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      2u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_DriverActivity_Leave_OR4)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_SteerGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      5u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_OnlyIfLongVruAcuteWarn)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_SteerGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      5u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Prefill_HypProb_KeepPassive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_HypProb_StationVRU)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      35.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruPrefill_HypProb_StationVRU_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      35.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.LongVru_Prefill.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"LongVru_Prefill"),
      &(HEADModule[HEAD_AUTOCODE_MOD_LongVru_Prefill]),
      &(HEADInternalState_LongVru_Prefill),
      (HEADParameterEmpty_t *)((void *)&(LongVruPreFill_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.LongVru_Prefill)),
      NULL, HEAD_OR_GROUP_TIMER_LongVru_Prefill, HEAD_OR_GROUP_NUM_LongVru_Prefill))



    /*---------------LongVru_Brk1----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_BRAKE_L1)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_OnlyIfDynAcuteWarnActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_OnlyIfVehPreBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_OnlyIfVehPreBrkNotWait)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_WAIT, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_OnlyIfCrossVruPreBrkNotActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_OnlyIfCrossVruPreBrkNotWait)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Obstacle) | HEADObjectClassBit(EBAObjectClass_Pedestrian) | HEADObjectClassBit(EBAObjectClass_Vehicle)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_WAIT, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_MinEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.125f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_MaxEgoVel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      40.546875f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_HypProb)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      80.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_HypProb_keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      50.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_ObjProb)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_ObjProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_DrvFeedback)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -70.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_DrvActivity)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      20.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_TTBAcute)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_TTB_ACUTE,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_TTCMin)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_TTC,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.15f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_VrelX_keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruBrk1_ANecLong_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_Distance,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      6u,
      ((const void *)&(VehAutoBrk1_ANecLong_keep_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_DistXSafe)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_ObjectDist,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_LockTime)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_MinEgoVel_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.09f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_InitWaitVRel)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_VRelX,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit | HEADParameterState_KeepWaitBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk1lSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk1_Driver_Seatbelt)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_03_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_PreBrk_BrakeChainState)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk1_LongVRU_Curve_Min)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_EgoLatCurvature,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk1_LongVRU_Curve_Max)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_EgoLatCurvature,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.01f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_AutoBrk1_AEBSwitch)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_AutoBrk1_AEBSwitch_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_02_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      1u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk1_DriverFeedback_leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_DriverFeedbackProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit | HEADParameterState_LeaveActiveBit),
      -89.0f,
      HEADParamOperator_LESSTHAN,
      3u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_DriverActivity_Leave_OR4)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_DriverActivityProb,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      69.0f,
      HEADParamOperator_GREATERTHAN,
      4u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_PreBrk_BrakeChainState_leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      5u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_SteeringGrad_Leave)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      180.0f,
      HEADParamOperator_GREATERTHAN,
      6u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_SteeringGrad_Keep)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      100.0f,
      HEADParamOperator_GREATERTHAN,
      6u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_HypProb_StationVRU)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      50.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk1_HypProb_KeepActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_HypProb,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      30.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk1_ObjMovDir)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_ObjMoveDir,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk1MaxVrelY)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_07_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.555555555556f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruBrk1StationVRU_ANecLong_table[0] = 0.0f;
    LongVruBrk1StationVRU_ANecLong_table[1] = 0.0f;
    LongVruBrk1StationVRU_ANecLong_table[2] = 2.77777777778f;
    LongVruBrk1StationVRU_ANecLong_table[3] = -5.0f;
    LongVruBrk1StationVRU_ANecLong_table[4] = 5.55555555556f;
    LongVruBrk1StationVRU_ANecLong_table[5] = -5.0f;
    LongVruBrk1StationVRU_ANecLong_table[6] = 8.33333333333f;
    LongVruBrk1StationVRU_ANecLong_table[7] = -5.0f;
    LongVruBrk1StationVRU_ANecLong_table[8] = 11.1111111111f;
    LongVruBrk1StationVRU_ANecLong_table[9] = -5.3f;
    LongVruBrk1StationVRU_ANecLong_table[10] = 13.8888888889f;
    LongVruBrk1StationVRU_ANecLong_table[11] = -5.8f;
    LongVruBrk1StationVRU_ANecLong_table[12] = 16.6666666667f;
    LongVruBrk1StationVRU_ANecLong_table[13] = -6.4f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruBrk1StationVRU_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(LongVruBrk1StationVRU_ANecLong_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUBRK1AllConditionsTRUE_MovingYawrate)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_00_HypIndependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      7u,
      ((const void *)&(BRK1AllConditionsTRUE_MovingYawrate_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk1DriverBrake_lowspeed)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_CustomPar_08_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUBrk1AllConditionsTRUE_SteerGrad)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_04_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      4u,
      ((const void *)&(CrossVRUDynAcuteWarnAllConditionsTRUE_SteerGrad_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    LongVruBrk1_TTC4_table[0] = 0.0f;
    LongVruBrk1_TTC4_table[1] = 0.0f;
    LongVruBrk1_TTC4_table[2] = 1.11111111111f;
    LongVruBrk1_TTC4_table[3] = 0.9f;
    LongVruBrk1_TTC4_table[4] = 1.38888888889f;
    LongVruBrk1_TTC4_table[5] = 0.9f;
    LongVruBrk1_TTC4_table[6] = 11.1111111111f;
    LongVruBrk1_TTC4_table[7] = 1.2f;
    LongVruBrk1_TTC4_table[8] = 13.8888888889f;
    LongVruBrk1_TTC4_table[9] = 1.3f;
    LongVruBrk1_TTC4_table[10] = 16.6666666667f;
    LongVruBrk1_TTC4_table[11] = 1.4f;
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruBrk1_TTC4)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_TTC4,
      HEADParamTableType_HostSpeed,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      6u,
      ((const void *)&(LongVruBrk1_TTC4_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      10.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVruBrk_VelXDealy)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_AllConditionsForOrGroupMet,
      HEADParamTableType_CustomPar_08_HypDependent,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      3u,
      ((const void *)&(LongVruFCW_VelXDealy_table[0])),
      HEADParamOperator_GREATERTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUBrk_EgoAccX_NAcc)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostAccel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      10u,
      ((const void *)&(LongVRUDynAcuteWarn_EgoAccX_NAcc_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

  
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetTableWithBitPack(((void *)&(LongVRUBrk1_EgoAccX_NAcc_Factor)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      HEADParamOutType_ANecLong,
      HEADParamTableType_HostAccel,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_EnableBit),
      10u,
      ((const void *)&(LongVRUFCW_EgoAccX_NAcc_Factor_table[0])),
      HEADParamOperator_LESSTHAN,
      0u,
      0.0f,
      HEADParameterTableFloatType_f32,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEADModuleOutputData.LongVru_Brk1.fpCustomOutput = &HEADOutBrakeFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"LongVru_Brk1"),
      &(HEADModule[HEAD_AUTOCODE_MOD_LongVru_Brk1]),
      &(HEADInternalState_LongVru_Brk1),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk1_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.LongVru_Brk1)),
      (const void*)&HEADFuncOut_LongVru_Brk1Par, HEAD_OR_GROUP_TIMER_LongVru_Brk1, HEAD_OR_GROUP_NUM_LongVru_Brk1))

    HEADFuncOut_LongVru_Brk1Par.AutoBrkParBrakeReactionTime = 0.1f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[0] = 0.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[1] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[2] = 58.3333333333f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[3] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[4] = 58.6111111111f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[5] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[6] = 58.6111111111f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[8] = 58.6111111111f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxCtrlVeloReduct_Rows = 5u;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[0] = 0.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[1] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[2] = 27.7777777778f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[3] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[4] = 58.3333333333f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[5] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[6] = 58.6111111111f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[8] = 58.6111111111f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParMaxAllowVeloReduct_Rows = 5u;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[0] = 0.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[1] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[2] = 5.5f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[3] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[4] = 6.2f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[5] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[6] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[7] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[8] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[9] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[10] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[11] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[12] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel[13] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabBrakeDecel_Rows = 7u;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[0] = 0.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[1] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[2] = 5.5f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[3] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[4] = 6.2f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[5] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[6] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[7] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[8] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[9] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[10] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[11] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[12] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel[13] = -2.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabStatDecel_Rows = 7u;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[0] = 0.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[1] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[2] = 5.5f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[3] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[4] = 6.2f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[5] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[6] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[7] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[8] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[9] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[10] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[11] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[12] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel[13] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMovDecel_Rows = 7u;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[0] = 0.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[1] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[2] = 5.5f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[3] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[4] = 6.2f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[5] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[6] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[7] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[8] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[9] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[10] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[11] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[12] = 11.11f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel[13] = -4.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabCommonDecel_Rows = 7u;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[0] = 8.33333333333f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[1] = -3.5f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[2] = 11.1111111111f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[3] = -3.5f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[4] = 16.6666666667f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[5] = -3.5f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[6] = 23.6111111111f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[7] = -3.5f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[8] = 23.6111111111f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel[9] = -3.5f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabMaxDecel_Rows = 5u;
    HEADFuncOut_LongVru_Brk1Par.HEAD_BRK_ANEC_CTRL = 0;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParCtrlMaxVelStat = 60.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParCtrlMaxVelBrake = 60.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParCtrlMaxVelMov = 60.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParCtrlMaxStartVrel = 83.3333333333f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParRampOutGrad = 85.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[0] = 0.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[1] = 1.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[2] = 50.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[3] = 1.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[4] = 50.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[5] = 1.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[6] = 50.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[7] = 1.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[8] = 50.0f;     HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut[9] = 1.0f;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParTabDrvFdkToRampOut_Rows = 5u;
    HEADFuncOut_LongVru_Brk1Par.AutoBrkParDrvActToRampOut = 50;
    HEADFuncOut_LongVru_Brk1Par.Veh_BrkLevelNr = 1u;
    HEADFuncOut_LongVru_Brk1Par.HEAD_LAST_MODULE = 0;


    /*---------------LongVru_Brk2----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk2_Inhibition)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_OrGroupInhibition,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (FPS_EBA_INH_BRAKE_L2)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk2_OnlyIfLongVruBrk1Active)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.5f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk2_WaitForLongVruBrk1_Passive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      0.01f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_PASSIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk2_ANecLong)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_ANecLong,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp) | HEADParameterHypothesisBit(CDHypothesisType_RunupCoMoving)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      -4.0f,
      HEADParamOperator_LESSTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_Brk2lSensorSource)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_SensorSource,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision) | HEADParameterHypothesisBit(CDHypothesisType_RunUp)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0u,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      (uint16) (EM_GEN_OBJECT_MS_CAM | EM_GEN_OBJECT_MS_LRR)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVru_PreBrk2_BrakeChainState)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_CustomPar_04_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk2_OnlyIfLongVruBrk1_StationVruActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk2_OnlyIfLongVruBrk1_StationVruKeepActive)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(LongVruBrk2_OnlyIfLongVruBrk1ActiveStation)),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      (uint16) (HEADParameterHypothesisBit(CDHypothesisType_CyclColl) | HEADParameterHypothesisBit(CDHypothesisType_PedCollision)),
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      (uint16) (HEADObjectClassBit(EBAObjectClass_Cyclist) | HEADObjectClassBit(EBAObjectClass_Pedestrian)),
      (uint16) (HEADDynPropBit(EBADynProp_Mov) | HEADDynPropBit(EBADynProp_Stat)),
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEADModuleOutputData.LongVru_Brk2.fpCustomOutput = &HEADOutBrakeFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"LongVru_Brk2"),
      &(HEADModule[HEAD_AUTOCODE_MOD_LongVru_Brk2]),
      &(HEADInternalState_LongVru_Brk2),
      (HEADParameterEmpty_t *)((void *)&(LongVruBrk2_Inhibition)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.LongVru_Brk2)),
      (const void*)&HEADFuncOut_LongVru_Brk2Par, HEAD_OR_GROUP_TIMER_LongVru_Brk2, HEAD_OR_GROUP_NUM_LongVru_Brk2))

    HEADFuncOut_LongVru_Brk2Par.AutoBrkParBrakeReactionTime = 0.1f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[0] = 0.0f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[1] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[2] = 58.3333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[3] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[4] = 58.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[5] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[6] = 58.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[8] = 58.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxCtrlVeloReduct_Rows = 5u;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[0] = 0.0f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[1] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[2] = 27.7777777778f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[3] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[4] = 58.3333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[5] = 16.6666666667f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[6] = 58.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[7] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[8] = 58.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct[9] = 2.77777777778f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParMaxAllowVeloReduct_Rows = 5u;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[0] = 5.55555555556f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[1] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[2] = 8.33333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[3] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[4] = 11.1111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[5] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[6] = 16.6666666667f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[7] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[8] = 23.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[9] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[10] = 58.0555555556f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[11] = -6.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[12] = 58.3333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel[13] = -6.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabBrakeDecel_Rows = 7u;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[0] = 5.55555555556f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[1] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[2] = 8.33333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[3] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[4] = 11.1111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[5] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[6] = 16.6666666667f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[7] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[8] = 23.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[9] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[10] = 58.0555555556f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[11] = -6.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[12] = 58.3333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel[13] = -6.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabStatDecel_Rows = 7u;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[0] = 5.55555555556f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[1] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[2] = 8.33333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[3] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[4] = 11.1111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[5] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[6] = 16.6666666667f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[7] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[8] = 23.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[9] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[10] = 58.0555555556f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[11] = -6.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[12] = 58.3333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel[13] = -6.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMovDecel_Rows = 7u;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[0] = 5.55555555556f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[1] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[2] = 8.33333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[3] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[4] = 11.1111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[5] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[6] = 16.6666666667f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[7] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[8] = 23.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[9] = -9.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[10] = 58.0555555556f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[11] = -6.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[12] = 58.3333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel[13] = -6.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabCommonDecel_Rows = 7u;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[0] = 8.33333333333f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[1] = -3.5f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[2] = 11.1111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[3] = -3.5f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[4] = 16.6666666667f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[5] = -3.5f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[6] = 23.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[7] = -3.5f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[8] = 23.6111111111f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel[9] = -3.5f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabMaxDecel_Rows = 5u;
    HEADFuncOut_LongVru_Brk2Par.HEAD_BRK_ANEC_CTRL = 1;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParCtrlMaxVelStat = 60.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParCtrlMaxVelBrake = 60.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParCtrlMaxVelMov = 60.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParCtrlMaxStartVrel = 83.3333333333f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParRampOutGrad = 85.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[0] = 0.0f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[1] = 1.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[2] = 50.0f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[3] = 1.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[4] = 50.0f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[5] = 1.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[6] = 50.0f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[7] = 1.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[8] = 50.0f;     HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut[9] = 1.0f;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParTabDrvFdkToRampOut_Rows = 5u;
    HEADFuncOut_LongVru_Brk2Par.AutoBrkParDrvActToRampOut = 50;
    HEADFuncOut_LongVru_Brk2Par.Veh_BrkLevelNr = 2u;
    HEADFuncOut_LongVru_Brk2Par.HEAD_LAST_MODULE = 1;


    /*---------------EgoVehStandstill----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(EgoVehStopped_EgoVel)),
      (HEADParameterEmpty_t *)((void *)&(EgoVehStopped_EgoVel)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit | HEADParameterState_KeepActiveBit),
      1.38888888889f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(EgoVehStopped_EgoVel_Keep)),
      (HEADParameterEmpty_t *)((void *)&(EgoVehStopped_EgoVel)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Factor,
      (uint16) (HEADParameterState_KeepActiveBit),
      1.1f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.EgoVehStandstill.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"EgoVehStandstill"),
      &(HEADModule[HEAD_AUTOCODE_MOD_EgoVehStandstill]),
      &(HEADInternalState_EgoVehStandstill),
      (HEADParameterEmpty_t *)((void *)&(EgoVehStopped_EgoVel)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.EgoVehStandstill)),
      NULL, HEAD_OR_GROUP_TIMER_EgoVehStandstill, HEAD_OR_GROUP_NUM_EgoVehStandstill))



    /*---------------HoldBrakeInStandstill----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Standstill_VehAutoBrk1_Active)),
      (HEADParameterEmpty_t *)((void *)&(Standstill_VehAutoBrk1_Active)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.2f,
      HEADParamOperator_GREATERTHAN,
      1u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_Veh_AutoBrk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Standstill_CrossVruPreBrk_Active)),
      (HEADParameterEmpty_t *)((void *)&(Standstill_VehAutoBrk1_Active)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.2f,
      HEADParamOperator_GREATERTHAN,
      2u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_CrossVru_PreBrk, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Standstill_LongVru_Brk1_Active)),
      (HEADParameterEmpty_t *)((void *)&(Standstill_VehAutoBrk1_Active)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_EnableBit),
      0.2f,
      HEADParamOperator_GREATERTHAN,
      3u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_LongVru_Brk1, (uint32)HEADSMState_ACTIVE, 1u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Standstill_EgoVehStopped_Not_Active)),
      (HEADParameterEmpty_t *)((void *)&(Standstill_VehAutoBrk1_Active)),
      HEADParamOutType_OtherModuleStateTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepPassiveBit),
      0.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      HEADOtherModuleStateTime2BitPack((uint32)HEAD_AUTOCODE_MOD_EgoVehStandstill, (uint32)HEADSMState_ACTIVE, 0u)))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(Standstill_External_Deactivation)),
      (HEADParameterEmpty_t *)((void *)&(Standstill_VehAutoBrk1_Active)),
      HEADParamOutType_CustomPar_01_HypIndependent,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepActiveBit),
      0.5f,
      HEADParamOperator_LESSTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(StandstillMaxTime)),
      (HEADParameterEmpty_t *)((void *)&(Standstill_VehAutoBrk1_Active)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_LeaveActiveBit),
      5.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(StandstillLockTime)),
      (HEADParameterEmpty_t *)((void *)&(Standstill_VehAutoBrk1_Active)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_KeepWaitBit),
      2.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.HoldBrakeInStandstill.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"HoldBrakeInStandstill"),
      &(HEADModule[HEAD_AUTOCODE_MOD_HoldBrakeInStandstill]),
      &(HEADInternalState_HoldBrakeInStandstill),
      (HEADParameterEmpty_t *)((void *)&(Standstill_VehAutoBrk1_Active)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.HoldBrakeInStandstill)),
      NULL, HEAD_OR_GROUP_TIMER_HoldBrakeInStandstill, HEAD_OR_GROUP_NUM_HoldBrakeInStandstill))



    /*---------------OncomingLatentWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(OncomingLatentWarnStayInOFF)),
      (HEADParameterEmpty_t *)((void *)&(OncomingLatentWarnStayInOFF)),
      HEADParamOutType_EgoVelocity,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit),
      -1000.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.OncomingLatentWarn.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"OncomingLatentWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_OncomingLatentWarn]),
      &(HEADInternalState_OncomingLatentWarn),
      (HEADParameterEmpty_t *)((void *)&(OncomingLatentWarnStayInOFF)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.OncomingLatentWarn)),
      NULL, HEAD_OR_GROUP_TIMER_OncomingLatentWarn, HEAD_OR_GROUP_NUM_OncomingLatentWarn))



    /*---------------OncomingDriveOffPrevention----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(OncomingDriveOffPreventionStayInOFF)),
      (HEADParameterEmpty_t *)((void *)&(OncomingDriveOffPreventionStayInOFF)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit),
      -1000.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.OncomingDriveOffPrevention.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"OncomingDriveOffPrevention"),
      &(HEADModule[HEAD_AUTOCODE_MOD_OncomingDriveOffPrevention]),
      &(HEADInternalState_OncomingDriveOffPrevention),
      (HEADParameterEmpty_t *)((void *)&(OncomingDriveOffPreventionStayInOFF)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.OncomingDriveOffPrevention)),
      NULL, HEAD_OR_GROUP_TIMER_OncomingDriveOffPrevention, HEAD_OR_GROUP_NUM_OncomingDriveOffPrevention))



    /*---------------OncomingWarn----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(OncomingWarnStayInOFF)),
      (HEADParameterEmpty_t *)((void *)&(OncomingWarnStayInOFF)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit),
      -1000.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.OncomingWarn.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"OncomingWarn"),
      &(HEADModule[HEAD_AUTOCODE_MOD_OncomingWarn]),
      &(HEADInternalState_OncomingWarn),
      (HEADParameterEmpty_t *)((void *)&(OncomingWarnStayInOFF)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.OncomingWarn)),
      NULL, HEAD_OR_GROUP_TIMER_OncomingWarn, HEAD_OR_GROUP_NUM_OncomingWarn))



    /*---------------OncomingBrake----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(OncomingBrakeStayInOFF)),
      (HEADParameterEmpty_t *)((void *)&(OncomingBrakeStayInOFF)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit),
      -1000.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.OncomingBrake.fpCustomOutput = &HEADOutToggleFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"OncomingBrake"),
      &(HEADModule[HEAD_AUTOCODE_MOD_OncomingBrake]),
      &(HEADInternalState_OncomingBrake),
      (HEADParameterEmpty_t *)((void *)&(OncomingBrakeStayInOFF)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.OncomingBrake)),
      NULL, HEAD_OR_GROUP_TIMER_OncomingBrake, HEAD_OR_GROUP_NUM_OncomingBrake))



    /*---------------DynAcuteWarn_TRUCK----------------*/
    HEAD_CALL_NO_ERROR(retValue, HEADParamSetScalarWithBitPack(((void *)&(DynAcuteWarn_TRUCKStayInOff)),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_TRUCKStayInOff)),
      HEADParamOutType_StateActiveTime,
      0u,
      HEADParameterHypothesisIndependent,
      HEADParamMainValueType_Value,
      (uint16) (HEADParameterState_InitBit),
      -1000.0f,
      HEADParamOperator_GREATERTHAN,
      0u,
      0u,
      0u,
      0u))

    HEADModuleOutputData.DynAcuteWarn_TRUCK.fpCustomOutput = &HEADOutWarnFunction;
    HEAD_CALL_NO_ERROR(retValue, HEADGSMCreateTypicalModule(
      (const uint8*)((const void *)"DynAcuteWarn_TRUCK"),
      &(HEADModule[HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK]),
      &(HEADInternalState_DynAcuteWarn_TRUCK),
      (HEADParameterEmpty_t *)((void *)&(DynAcuteWarn_TRUCKStayInOff)),
      (struct HEADModuleOutputInterface_t *)((void *)&(HEADModuleOutputData.DynAcuteWarn_TRUCK)),
      (const void*)&HEADFuncOut_DynAcuteWarn_TRUCKPar, HEAD_OR_GROUP_TIMER_DynAcuteWarn_TRUCK, HEAD_OR_GROUP_NUM_DynAcuteWarn_TRUCK))

    HEADFuncOut_DynAcuteWarn_TRUCKPar.HEAD_LAST_WARN_MODULE = 0;
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  return retValue;
}

/* **************************************************************************** 
  Functionname:         HEADAutoCodeSetSPM                                     */ /*!  
  @brief        Configure Signal performance monitoring(SPM) Rules 
  @description          This function is used to Add SPM Rules to SPM Rules array.
                      @startuml
                      Start
                      :Assign SPM Rules Array(Empty Array) to HEAD Input Data;
                          Note
                         Assign SPM Rules Array and total number of SPM Rules
                          to HEAD input data
                          End note
                      Partition GoThroughAllSPMRules {
                      #Orange:Set SPM Rules
                      <b>HEADSPMAddSigCheck</b> >
                          Note
                          Go through all SPM Rules configured and
                          Update those SPM Rule to SPM rules array
                          End note
                      }
                      Stop
                      @enduml
  @return               eGDBError_t : GDB_ERROR_NONE in case of no error, else returns forwarded Error
  @param[in]            pModuleList : Pointer to HEAD module list
  @param[in,out]        pHEADInputData : Pointer to HEAD Input Data
  @param[in]            pAddInputValueList : Extra Input value list
  @glob_in              None
  @glob_out             None
  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  @pre                  None
  @post                 None
  @InOutCorrelation     Not defined
  @testmethod           Test of output data (dynamic module test)
  @traceability
  @author       autocode
**************************************************************************** */
static eGDBError_t HEADAutoCodeSetSPM(const HEADModuleList_t *pModuleList, struct HEADInputData_t *pHEADInputData, void *pAddInputValueList)
{
  uint32 uiRuleNr = 0uL;
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ( (pModuleList != NULL) && (pHEADInputData != NULL) && (pAddInputValueList != NULL) )
  {
    pHEADInputData->pSPMRules = &sHEADAutoCodeSPMRules;
    pHEADInputData->pSPMRules->uiNrOfSPMRules = HEAD_AUTO_CFG_NO_SPM_RULES;
    pHEADInputData->pSPMRules->rgSPMRules = &rgHEADAutoCodeSPMRules[0];
    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->LongVelocity, eHEADMTSInSigIdent_Velocity,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->LongVelocity, eHEADMTSInSigIdent_Velocity,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.2f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Critical))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->LongVelocity, eHEADMTSInSigIdent_Velocity,
      HEADSPMCheckBitsSignal_Signal,
      HEADSPMCheckBitsOp_Smaller,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)-1.0f,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationKeep,
      HEADModuleRepError_NoError))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->LongAcceleration, eHEADMTSInSigIdent_Acceleration,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->LongAcceleration, eHEADMTSInSigIdent_Acceleration,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.2f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationShutDown,
      HEADModuleRepError_Normal))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->YawRate, eHEADMTSInSigIdent_YawRate,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->YawRate, eHEADMTSInSigIdent_YawRate,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.2f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Critical))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DrivingDirection, eHEADMTSInSigIdent_DrivinDirection,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DrivingDirection, eHEADMTSInSigIdent_DrivinDirection,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.2f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Critical))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DrivingDirection, eHEADMTSInSigIdent_DrivinDirection,
      HEADSPMCheckBitsSignal_Signal,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)1.0f,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationKeep,
      HEADModuleRepError_NoError))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DriverFeedback, eHEADMTSInSigIdent_DriverFeedback,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DriverFeedback, eHEADMTSInSigIdent_DriverFeedback,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.2f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Critical))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DriverFeedback, eHEADMTSInSigIdent_DriverFeedback,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill)),
      HEADModuleQoS_DegradationShutDown,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DriverAttention, eHEADMTSInSigIdent_DriverAttention,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationShutDown,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DriverAttention, eHEADMTSInSigIdent_DriverAttention,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      1.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationShutDown,
      HEADModuleRepError_Normal))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DriverActivity, eHEADMTSInSigIdent_DriverActivity,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->DriverActivity, eHEADMTSInSigIdent_DriverActivity,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.2f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Critical))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &((HEADExtraInputValueList_t *)pAddInputValueList)->DIMInputsValid,
      eHEADMTSInSigIdent_DIMInputsValid,
      HEADSPMCheckBitsSignal_Signal,
      HEADSPMCheckBitsOp_Equals,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)0.0f,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationShutDown,
      HEADModuleRepError_Normal))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &((HEADExtraInputValueList_t *)pAddInputValueList)->DIMInputsValid,
      eHEADMTSInSigIdent_DIMInputsValid,
      HEADSPMCheckBitsSignal_Signal,
      HEADSPMCheckBitsOp_Equals,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)1.0f,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationShutDown,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->CDHypotheses, eHEADMTSInSigIdent_CDHypotheses,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.0f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Silent))
    uiRuleNr++;

    HEAD_CALL_NO_ERROR(retValue, HEADSPMAddSigCheck(pHEADInputData->pSPMRules,
      uiRuleNr,
      &pHEADInputData->pInputValueList->CDHypotheses, eHEADMTSInSigIdent_CDHypotheses,
      HEADSPMCheckBitsSignal_SigState,
      HEADSPMCheckBitsOp_EqualsNot,
      HEADSPMCheckBitsFunction_No,
      HEADSPMCheckBitsStdDeviation_No,
      (float32)HEADInputSignalState_OK,
      0.2f,
      (uint32) (HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_CrossVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_DynPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_EgoVehStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_TA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HBA_VDS) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_HoldBrakeInStandstill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LatPreWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Brk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HBA) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_LongVru_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Prefill) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk1) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk2) | HEADSPMGetModuleBit(HEAD_AUTOCODE_MOD_Veh_AutoBrk3)),
      HEADModuleQoS_DegradationStop,
      HEADModuleRepError_Normal))
    uiRuleNr++;

  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  return retValue;
}

/* **************************************************************************** 
  Functionname:         HEADAutoCodeCreate                                     */ /*!  
  @brief                HEAD Auto Code Create
  @description          This function is used to create HEAD SPM Rules and Modules
                        @startuml 
                        Start
                        :set Error as None;
                        #Orange:Create HEAD Module
                        Error=<b>HEADAutoCodeSetCfg</b> >
                        #Orange:Set SPM Rules
                        Error=<b>HEADAutoCodeSetSPM</b> >
                        :return Error;
                        Stop 
                        @enduml
  @return               eGDBError_t : GDB_ERROR_NONE in case of no error, else returns forwarded Error
  @param[in]            pModuleList : Pointer to HEAD module list
  @param[in,out]        pHEADInputData : Pointer to HEAD Input Data
  @param[in]            pAddInputValueList : Extra Input value list
  @glob_in              None
  @glob_out             None
  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  @pre                  None
  @post                 None
  @InOutCorrelation     Not defined
  @testmethod           Test of output data (dynamic module test)
  @traceability 
  @author       autocode 
**************************************************************************** */
eGDBError_t HEADAutoCodeCreate(HEADModuleList_t *pModuleList, struct HEADInputData_t *pHEADInputData, void *pAddInputValueList)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  HEAD_CALL_NO_ERROR(retValue, HEADAutoCodeSetCfg(pModuleList))
  HEAD_CALL_NO_ERROR(retValue, HEADAutoCodeSetSPM(pModuleList, pHEADInputData, pAddInputValueList))
  return retValue;
}

/* **************************************************************************** 
  Functionname:         HEADAutoCodeUpdateParams                                     */ /*! 
 @brief                update Auto Code parameters
 @description          This function is used to update Auto coded Parameters in Run time
                       @startuml
                       Start
                       :set Error as None;
                       #Orange:Update Auto code parameter
                       Error=<b>CalibrationFunction</b> >
                       Note 
                       The Calibration function actually does the Parameter update.
                       We need to send the parameter and corresponding parameter ID
                       In order to update the parameter.
                       End note
                       :return Error;
                       Stop 
                       @enduml
  @return               eGDBError_t : GDB_ERROR_NONE in case of no error, else returns forwarded Error
  @param[in]            Void
  @glob_in              None
  @glob_out             None
  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 
  @pre                  None
  @post                 None
  @InOutCorrelation     Not defined
  @testmethod           Test of output data (dynamic module test)
  @traceability 
  @author       autocode 
**************************************************************************** */
eGDBError_t HEADAutoCodeUpdateParams(void)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  eGDBError_t tmpValue;
  tmpValue = CalibrationFunction((HEADParameterEmpty_t *)((void *)&(VehAutoBrk1_DistXSafe)), HEAD_PARID_PREBRK_SAFETY_DIST);
  retValue = (tmpValue != GDB_ERROR_NONE)? tmpValue : retValue;
  tmpValue = CalibrationFunction((HEADParameterEmpty_t *)((void *)&(CrossVruPreBrk_DistXSafe)), HEAD_PARID_PREBRK_SAFETY_DIST);
  retValue = (tmpValue != GDB_ERROR_NONE)? tmpValue : retValue;
  tmpValue = CalibrationFunction((HEADParameterEmpty_t *)((void *)&(LongVruBrk1_DistXSafe)), HEAD_PARID_PREBRK_SAFETY_DIST);
  retValue = (tmpValue != GDB_ERROR_NONE)? tmpValue : retValue;
  return retValue;
}

/* **************************************************************************** 
  Functionname:         HEADSendCfgToMTS                                     */ /*!  
  @brief                Send HEAD config Data to MTS
  @description          Send HEAD Config Date to MTS
                        @startuml
                        Start
                        #Orange:Send HEAD Config to MTS
                        <b>HEADMTSSendConfigData</b> >
                        Stop
                        @enduml
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.
  @param[in]            pStaticData :Pointer to HEAD MTS Static Data
  @param[in]            pCfgData : Pointer to HEAD MTS Config Date
  @glob_in              @rer HEAD_CONFIG
  @glob_out             None
  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  @pre                  None
  @post                 None
  @InOutCorrelation     Not defined
  @testmethod           Test of output data (dynamic module test)
  @traceability
  @author               autocode
**************************************************************************** */ 
eGDBError_t HEADSendCfgToMTS(HEADMTSStaticData_t *pStaticData, HEADMTSCfgData_t *pCfgData)
{
  return HEADMTSSendConfigData(pStaticData, pCfgData, (const uint8 *)((const void *)&(HEAD_CONFIG[0])), HEAD_CONFIG_LEN);
}



/*this file was generated using the following parameter set (don't change this comment):*/
/*HEADAUTOCODE
QlpoOTFBWSZTWbqLMjUBKQFfgAAQc2f:/:/7:/://+S:/:/:/:/xYEztPtlFKvun0qgefAPhVfDxfNCzW3cE0rWr
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:/:/+f:/://
wX:/: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:/://P:/://4L:/:/:/:/FgQVp9Oqx75YD
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:/:/MUFZJlNZS+cwNgSfYl+AQBBT
5:/://P:/://5L:/:/:/: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
yiqde3ovMdZKj/+LuSKcKEgpBUl5gA==

/HEADAUTOCODE*/

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* !(MEDIC_CFG_HEAD20) */

/*/CHECKSUMCODE*/

/*PRQA L:AUTOCODER_QAC*/
/**@}*/

/*AUTOCHECKSUM_SHA256*/
/*ec90e9cc12963b6644a71513f8d15ff6276cb76948800216afffcc8f7292aa1a*/
/*/AUTOCHECKSUM_SHA256*/

/*PRQA S 7013 *//* Date: 2019-06-28, Reviewer: Rajkumar Ayyalusamy, Reason: suppress warning for number of executable lines per file */ 
