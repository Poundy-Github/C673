/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CT_SA_Diagnostics_DEM_SC_XX_V1.c
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *     SW-C Type:  CT_SA_Diagnostics_DEM_SC_XX_V1
 *  Generated at:  Wed May 25 10:08:00 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  C-Code implementation template for SW-C <CT_SA_Diagnostics_DEM_SC_XX_V1>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  REC_Eng_Rs_EngCtrl_1j00gxu3p5exa8awg915k1zy
    (degraded)

  REC_Ign_Stat_b0ko81o0x5jgvwtduf99gvzi0
    (degraded)

  REC_PN14_SupBat_Stat_2is6fi0meeac78nkn35zc5ui3
    (degraded)


 Component Types:
 ================
  CT_SA_Diagnostics_DEM_SC_XX_V1
    Diagnostics Event Manager Storage Conditions


 Port Prototypes:
 ================
  R_DidA_ExtTest_Pres
    DidA Externer Tester erkannt

  R_Eng_Rs_EngCtrl
    Motoransprechverhalten Engine Control (degraded)

  R_Ign_Stat
    Zündungsstatus (degraded)

  R_Odo
    Kilometerstand (für alle, FFFFFEh: Signal ungültig)

  R_PN14_SupBat_Stat
    Bordnetz 14V Status Verbraucherbatterie (degraded)

  R_PN14_TransMd_Stat
    Bordnetz Status Transportmodus


 Data Element Prototypes:
 ========================
  DidA_ExtTest_Pres of Port Interface IF_DidA_ExtTest_Pres
    DidA Externer Tester erkannt

  Eng_Rs_EngCtrl of Port Interface IG_Eng_Rs_EngCtrl_1gxgy3qjn67dwbf6cgo48b4yw
    Motoransprechverhalten Engine Control (degraded)

  Ign_Stat of Port Interface IG_Ign_Stat_9bhu63hx0g75nr9rmuo7dc0ed
    Zündungsstatus (degraded)

  Odo of Port Interface IF_Odo
    Kilometerstand (für alle, FFFFFEh: Signal ungültig)

  PN14_SupBat_Stat of Port Interface IG_PN14_SupBat_Stat_11j4rxo0m2xh60rnncesieiwe
    Bordnetz 14V Status Verbraucherbatterie (degraded)

  PN14_TransMd_Stat of Port Interface IF_PN14_TransMd_Stat
    Bordnetz Status Transportmodus anzeigen

 *********************************************************************************************************************/

#include "Rte_CT_SA_Diagnostics_DEM_SC_XX_V1.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * DC_BOOL: Boolean
 *
 * Enumeration Types:
 * ==================
 * c02_BatCutSw_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_BATCUTSW_STAT_CLS (0u)
 *   I_C02_BATCUTSW_STAT_PREOPN (1u)
 *   I_C02_BATCUTSW_STAT_OPN (2u)
 *   I_C02_BATCUTSW_STAT_SNA (3u)
 * c02_TransMd_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_TRANSMD_STAT_OFF (0u)
 *   I_C02_TRANSMD_STAT_TEMP_OFF (1u)
 *   I_C02_TRANSMD_STAT_ACTV (2u)
 *   I_C02_TRANSMD_STAT_SNA (3u)
 * c03_EngRun_Stat: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ENGRUN_STAT_STOP (0u)
 *   I_C03_ENGRUN_STAT_START (1u)
 *   I_C03_ENGRUN_STAT_IDLE_UNSTBL (2u)
 *   I_C03_ENGRUN_STAT_IDLE_STBL (3u)
 *   I_C03_ENGRUN_STAT_UNLIMITED (4u)
 *   I_C03_ENGRUN_STAT_LIMITED (5u)
 *   I_C03_ENGRUN_STAT_NDEF6 (6u)
 *   I_C03_ENGRUN_STAT_SNA (7u)
 * c03_ISw_Stat: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ISW_STAT_IGN_LOCK (0u)
 *   I_C03_ISW_STAT_IGN_OFF (1u)
 *   I_C03_ISW_STAT_IGN_ACC (2u)
 *   I_C03_ISW_STAT_IGN_ON (4u)
 *   I_C03_ISW_STAT_IGN_START (5u)
 *   I_C03_ISW_STAT_SNA (7u)
 * c08_V_0_25k4_0k1: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_V_0_25K4_0K1_SNA (255u)
 * c24_km_0_999999k9_0k1: Enumeration of integer in interval [0...16777215] with enumerators
 *   I_C24_KM_0_999999K9_0K1_SNA (16777215u)
 *
 * Record Types:
 * =============
 * REC_Eng_Rs_EngCtrl_1j00gxu3p5exa8awg915k1zy: Record with elements
 *   EngRun_Stat of type c03_EngRun_Stat
 * REC_Ign_Stat_b0ko81o0x5jgvwtduf99gvzi0: Record with elements
 *   ISw_Stat of type c03_ISw_Stat
 * REC_PN14_SupBat_Stat_2is6fi0meeac78nkn35zc5ui3: Record with elements
 *   PN14_SupBatCutSw_Stat of type c02_BatCutSw_Stat
 *   PN14_SupBat_Volt of type c08_V_0_25k4_0k1
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CP_SA_NormDemSc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_DidA_ExtTest_Pres_DidA_ExtTest_Pres(DC_BOOL *data)
 *   Std_ReturnType Rte_Read_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl(REC_Eng_Rs_EngCtrl_1j00gxu3p5exa8awg915k1zy *data)
 *   Std_ReturnType Rte_Read_R_Ign_Stat_Ign_Stat(REC_Ign_Stat_b0ko81o0x5jgvwtduf99gvzi0 *data)
 *   Std_ReturnType Rte_Read_R_Odo_Odo(c24_km_0_999999k9_0k1 *data)
 *   Std_ReturnType Rte_Read_R_PN14_SupBat_Stat_PN14_SupBat_Stat(REC_PN14_SupBat_Stat_2is6fi0meeac78nkn35zc5ui3 *data)
 *   Std_ReturnType Rte_Read_R_PN14_TransMd_Stat_PN14_TransMd_Stat(c02_TransMd_Stat *data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_CODE) RE_CP_SA_NormDemSc(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CP_SA_NormDemSc
 *********************************************************************************************************************/

/* This function is left empty for future use, in case that an adaption of the bus signals is necessary. */
/* Here, now, the bus signals fit all to the SWC DEM_SC; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
