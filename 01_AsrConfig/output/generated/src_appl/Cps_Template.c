/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \version 6.6.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * This file contains an Rte component template / example code
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Wed May 24 10:36:52 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_Cps.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define Cps_START_SEC_CODE
#include <Cps_MemMap.h>
FUNC(void, RTE_CODE) Cps_DataProcessFunction (void)
{

} /* FUNC(void, RTE_CODE) Cps_DataProcessFunction (void) */

#define Cps_STOP_SEC_CODE
#include <Cps_MemMap.h>

#define Cps_START_SEC_CODE
#include <Cps_MemMap.h>
FUNC(void, RTE_CODE) Cps_InitFunction (void)
{

} /* FUNC(void, RTE_CODE) Cps_InitFunction (void) */

#define Cps_STOP_SEC_CODE
#include <Cps_MemMap.h>

#define Cps_START_SEC_CODE
#include <Cps_MemMap.h>
FUNC(void, RTE_CODE) Cps_MainFunction (void)
{
  Com_Send_ACC_HostLaneLeftStatus arg_Read_data;
  Std_ReturnType ret_Read;
  Com_Send_ACC_HostLaneRightStatus arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  Com_Send_ACC_LatAngReq arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  Com_Send_ACC_LatAngReqActive arg_Read_data_2;
  Std_ReturnType ret_Read_2;
  Com_Send_FC_HostLaneLeftStatus arg_Read_data_3;
  Std_ReturnType ret_Read_3;
  uint8_least arg_Read_data_4;
  Std_ReturnType ret_Read_4;
  Com_Send_FC_AEBActive arg_Read_data_5;
  Std_ReturnType ret_Read_5;
  Com_Send_FC_AEBTargetmode arg_Read_data_6;
  Std_ReturnType ret_Read_6;
  Com_Send_FC_AEBTextInfo arg_Read_data_7;
  Std_ReturnType ret_Read_7;
  Com_Send_FC_AEBVehilceHoldReq arg_Read_data_8;
  Std_ReturnType ret_Read_8;
  Com_Send_FC_OBJ_AEB_ID arg_Read_data_9;
  Std_ReturnType ret_Read_9;
  Com_Send_FC_AEBStatus arg_Read_data_10;
  Std_ReturnType ret_Read_10;
  Com_Send_FC_AEBTargetAy arg_Read_data_11;
  Std_ReturnType ret_Read_11;
  Com_Send_FC_AEBTargetAx arg_Read_data_12;
  Std_ReturnType ret_Read_12;
  Com_Send_FC_AEBTargetProb arg_Read_data_13;
  Std_ReturnType ret_Read_13;
  Com_Send_FC_AEBTargetLatRelSpeed arg_Read_data_14;
  Std_ReturnType ret_Read_14;
  Com_Send_FC_FCWStatus arg_Read_data_15;
  Std_ReturnType ret_Read_15;
  Com_Send_FC_AEBCtrlType arg_Read_data_16;
  Std_ReturnType ret_Read_16;
  Com_Send_FC_PrefillActive arg_Read_data_17;
  Std_ReturnType ret_Read_17;
  Com_Send_FC_AWBlevel arg_Read_data_18;
  Std_ReturnType ret_Read_18;
  Com_Send_FC_AWBActive arg_Read_data_19;
  Std_ReturnType ret_Read_19;
  Com_Send_FC_FCWActive arg_Read_data_20;
  Std_ReturnType ret_Read_20;
  Com_Send_FC_ABAlevel arg_Read_data_21;
  Std_ReturnType ret_Read_21;
  Com_Send_FC_ABAActive arg_Read_data_22;
  Std_ReturnType ret_Read_22;
  Com_Send_FC_FCWPreWarning arg_Read_data_23;
  Std_ReturnType ret_Read_23;
  Com_Send_FC_FCWLatentWarning arg_Read_data_24;
  Std_ReturnType ret_Read_24;
  Com_Send_FC_FCWSettingStatus arg_Read_data_25;
  Std_ReturnType ret_Read_25;
  Com_Send_FC_LatAngReqActive arg_Read_data_26;
  Std_ReturnType ret_Read_26;
  Com_Send_FC_AEBEnable arg_Read_data_27;
  Std_ReturnType ret_Read_27;
  Com_Send_FC_LDWStatus arg_Read_data_28;
  Std_ReturnType ret_Read_28;
  Com_Send_FC_LDWVibrationWarningReq arg_Read_data_29;
  Std_ReturnType ret_Read_29;
  Com_Send_FC_LKAStatus arg_Read_data_30;
  Std_ReturnType ret_Read_30;
  Com_Send_FC_LKATakeoverReq arg_Read_data_31;
  Std_ReturnType ret_Read_31;
  Com_Send_FC_LASModeSelectionStatus arg_Read_data_32;
  Std_ReturnType ret_Read_32;
  Com_Send_FC_LASWarningModeSelectionSts arg_Read_data_33;
  Std_ReturnType ret_Read_33;
  Com_Send_FC_LDWShakeLevStatus arg_Read_data_34;
  Std_ReturnType ret_Read_34;
  Com_Send_FC_ELKMode arg_Read_data_35;
  Std_ReturnType ret_Read_35;
  Com_Send_FC_ELKInterventionMode arg_Read_data_36;
  Std_ReturnType ret_Read_36;
  Com_Send_FC_ELKEnableStatus arg_Read_data_37;
  Std_ReturnType ret_Read_37;
  Com_Send_FC_AEBTargetDeceleration arg_Read_data_38;
  Std_ReturnType ret_Read_38;
  Com_Send_FC_LatAngReq arg_Read_data_39;
  Std_ReturnType ret_Read_39;
  Com_Send_FC_MotorTorqueMaxLimitRequest arg_Read_data_40;
  Std_ReturnType ret_Read_40;
  Com_Send_FC_MotorTorqueMinLimitRequest arg_Read_data_41;
  Std_ReturnType ret_Read_41;
  Com_Send_FC_Voiceinfo arg_Read_data_42;
  Std_ReturnType ret_Read_42;
  Com_Send_FC_HMALightDistribution arg_Read_data_43;
  Std_ReturnType ret_Read_43;
  Com_Send_FC_HMAEnableStatus arg_Read_data_44;
  Std_ReturnType ret_Read_44;
  Com_Send_FC_HMAStatus arg_Read_data_45;
  Std_ReturnType ret_Read_45;
  Com_Send_FC_HostLaneRightStatus arg_Read_data_46;
  Std_ReturnType ret_Read_46;
  Com_Send_FC_LLaneDistanceFus arg_Read_data_47;
  Std_ReturnType ret_Read_47;
  Com_Send_FC_RLaneDistanceFus arg_Read_data_48;
  Std_ReturnType ret_Read_48;
  Com_Send_FC_AEBTargetDetection arg_Read_data_49;
  Std_ReturnType ret_Read_49;
  Com_Send_FC_LLaneMarkerType arg_Read_data_50;
  Std_ReturnType ret_Read_50;
  Com_Send_FC_RLaneMarkerType arg_Read_data_51;
  Std_ReturnType ret_Read_51;
  Com_Send_FC_AEBTargetLatRange arg_Read_data_52;
  Std_ReturnType ret_Read_52;
  Com_Send_FC_AEBTargetLngRange arg_Read_data_53;
  Std_ReturnType ret_Read_53;
  Com_Send_FC_AEBTargetRelSpeed arg_Read_data_54;
  Std_ReturnType ret_Read_54;
  Com_Send_FC_AEBTargetType arg_Read_data_55;
  Std_ReturnType ret_Read_55;

  ret_Read = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_HostLaneLeftStatus(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_HostLaneRightStatus(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_LatAngReq(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_LatAngReqActive(&arg_Read_data_2);
  (void)ret_Read_2;
  ret_Read_3 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_HostLaneLeftStatus(&arg_Read_data_3);
  (void)ret_Read_3;
  ret_Read_4 = Rte_Read_RP_Cps_SRI_TxSignal_Acc_Cps_SignalPhyData_FC_ACC_temp(&arg_Read_data_4);
  (void)ret_Read_4;
  ret_Read_5 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBActive(&arg_Read_data_5);
  (void)ret_Read_5;
  ret_Read_6 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetmode(&arg_Read_data_6);
  (void)ret_Read_6;
  ret_Read_7 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTextInfo(&arg_Read_data_7);
  (void)ret_Read_7;
  ret_Read_8 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBVehilceHoldReq(&arg_Read_data_8);
  (void)ret_Read_8;
  ret_Read_9 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_OBJ_AEB_ID(&arg_Read_data_9);
  (void)ret_Read_9;
  ret_Read_10 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBStatus(&arg_Read_data_10);
  (void)ret_Read_10;
  ret_Read_11 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetAy(&arg_Read_data_11);
  (void)ret_Read_11;
  ret_Read_12 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetAx(&arg_Read_data_12);
  (void)ret_Read_12;
  ret_Read_13 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetProb(&arg_Read_data_13);
  (void)ret_Read_13;
  ret_Read_14 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLatRelSpeed(&arg_Read_data_14);
  (void)ret_Read_14;
  ret_Read_15 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWStatus(&arg_Read_data_15);
  (void)ret_Read_15;
  ret_Read_16 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBCtrlType(&arg_Read_data_16);
  (void)ret_Read_16;
  ret_Read_17 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_PrefillActive(&arg_Read_data_17);
  (void)ret_Read_17;
  ret_Read_18 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AWBlevel(&arg_Read_data_18);
  (void)ret_Read_18;
  ret_Read_19 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AWBActive(&arg_Read_data_19);
  (void)ret_Read_19;
  ret_Read_20 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWActive(&arg_Read_data_20);
  (void)ret_Read_20;
  ret_Read_21 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_ABAlevel(&arg_Read_data_21);
  (void)ret_Read_21;
  ret_Read_22 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_ABAActive(&arg_Read_data_22);
  (void)ret_Read_22;
  ret_Read_23 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWPreWarning(&arg_Read_data_23);
  (void)ret_Read_23;
  ret_Read_24 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWLatentWarning(&arg_Read_data_24);
  (void)ret_Read_24;
  ret_Read_25 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWSettingStatus(&arg_Read_data_25);
  (void)ret_Read_25;
  ret_Read_26 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LatAngReqActive(&arg_Read_data_26);
  (void)ret_Read_26;
  ret_Read_27 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBEnable(&arg_Read_data_27);
  (void)ret_Read_27;
  ret_Read_28 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWStatus(&arg_Read_data_28);
  (void)ret_Read_28;
  ret_Read_29 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWVibrationWarningReq(&arg_Read_data_29);
  (void)ret_Read_29;
  ret_Read_30 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LKAStatus(&arg_Read_data_30);
  (void)ret_Read_30;
  ret_Read_31 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LKATakeoverReq(&arg_Read_data_31);
  (void)ret_Read_31;
  ret_Read_32 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LASModeSelectionStatus(&arg_Read_data_32);
  (void)ret_Read_32;
  ret_Read_33 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LASWarningModeSelectionSts(&arg_Read_data_33);
  (void)ret_Read_33;
  ret_Read_34 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWShakeLevStatus(&arg_Read_data_34);
  (void)ret_Read_34;
  ret_Read_35 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKMode(&arg_Read_data_35);
  (void)ret_Read_35;
  ret_Read_36 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKInterventionMode(&arg_Read_data_36);
  (void)ret_Read_36;
  ret_Read_37 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKEnableStatus(&arg_Read_data_37);
  (void)ret_Read_37;
  ret_Read_38 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetDeceleration(&arg_Read_data_38);
  (void)ret_Read_38;
  ret_Read_39 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LatAngReq(&arg_Read_data_39);
  (void)ret_Read_39;
  ret_Read_40 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_MotorTorqueMaxLimitRequest(&arg_Read_data_40);
  (void)ret_Read_40;
  ret_Read_41 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_MotorTorqueMinLimitRequest(&arg_Read_data_41);
  (void)ret_Read_41;
  ret_Read_42 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_Voiceinfo(&arg_Read_data_42);
  (void)ret_Read_42;
  ret_Read_43 = Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMALightDistribution(&arg_Read_data_43);
  (void)ret_Read_43;
  ret_Read_44 = Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMAEnableStatus(&arg_Read_data_44);
  (void)ret_Read_44;
  ret_Read_45 = Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMAStatus(&arg_Read_data_45);
  (void)ret_Read_45;
  ret_Read_46 = Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_HostLaneRightStatus(&arg_Read_data_46);
  (void)ret_Read_46;
  ret_Read_47 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_LLaneDistanceFus(&arg_Read_data_47);
  (void)ret_Read_47;
  ret_Read_48 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_RLaneDistanceFus(&arg_Read_data_48);
  (void)ret_Read_48;
  ret_Read_49 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetDetection(&arg_Read_data_49);
  (void)ret_Read_49;
  ret_Read_50 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_LLaneMarkerType(&arg_Read_data_50);
  (void)ret_Read_50;
  ret_Read_51 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_RLaneMarkerType(&arg_Read_data_51);
  (void)ret_Read_51;
  ret_Read_52 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLatRange(&arg_Read_data_52);
  (void)ret_Read_52;
  ret_Read_53 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLngRange(&arg_Read_data_53);
  (void)ret_Read_53;
  ret_Read_54 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetRelSpeed(&arg_Read_data_54);
  (void)ret_Read_54;
  ret_Read_55 = Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetType(&arg_Read_data_55);
  (void)ret_Read_55;

} /* FUNC(void, RTE_CODE) Cps_MainFunction (void) */

#define Cps_STOP_SEC_CODE
#include <Cps_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
