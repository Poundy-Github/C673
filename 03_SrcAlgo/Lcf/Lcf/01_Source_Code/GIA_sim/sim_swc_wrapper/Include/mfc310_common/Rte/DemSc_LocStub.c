/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  DemSc_LocStub.c
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *     SW-C Type:  DemSc_LocStub
 *  Generated at:  Wed May 25 10:08:00 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  C-Code implementation template for SW-C <DemSc_LocStub>
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

 Runnable Entities:
 ==================
  RE_CP_SA_DemSc_LocStub
    Init Port signal values;

 *********************************************************************************************************************/

#include "Rte_DemSc_LocStub.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "glob_defs.h"



#define DEM_SC_FACTOR_LOCAL_VOLT_2_DEM_VOLT  (100.f)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Enumeration Types:
 * ==================
 * SwcDemSc_StdReturnType: Enumeration of integer in interval [0...255] with enumerators
 *   SWCDEMSC_E_OK (0u)
 *   SWCDEMSC_E_NOT_OK (1u)
 *   SWCDEMSC_E_INVALID (255u)
 * c03_ISw_Stat: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ISW_STAT_IGN_LOCK (0u)
 *   I_C03_ISW_STAT_IGN_OFF (1u)
 *   I_C03_ISW_STAT_IGN_ACC (2u)
 *   I_C03_ISW_STAT_IGN_ON (4u)
 *   I_C03_ISW_STAT_IGN_START (5u)
 *   I_C03_ISW_STAT_SNA (7u)
 * c08_V_0_25k4_0k1: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_V_0_25K4_0K1_SNA (255u)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_DEMSC_LOCSTUB_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CP_SA_DemSc_LocStub
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SwcDemSc_LocIgnition_Ign_Stat(c03_ISw_Stat data)
 *   Std_ReturnType Rte_Write_SwcDemSc_LocIoDevice_Io_Stat(SwcDemSc_StdReturnType data)
 *   Std_ReturnType Rte_Write_SwcDemSc_LocVoltage_SupBat_Volt(c08_V_0_25k4_0k1 data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_DEMSC_LOCSTUB_APPL_CODE) RE_CP_SA_DemSc_LocStub(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CP_SA_DemSc_LocStub
 *********************************************************************************************************************/

  float32 fTemp32;
  RTE_t_AdcReads * ps_ADCReadData;

  ps_ADCReadData = Rte_IRead_RE_DemSc_LocStub_RPortDemScLocAdcData_DEPAdcData();

  SuspendAllInterrupts();
  fTemp32 = ROUND(ps_ADCReadData->ADC_UBATT / DEM_SC_FACTOR_LOCAL_VOLT_2_DEM_VOLT);
  ResumeAllInterrupts();

  if( fTemp32 > 254.F)
  {
    fTemp32 = 254.F;
  }

  if( fTemp32 < 0.F)
  {
    fTemp32 = 0.F;
  }

  (void)Rte_Write_SwcDemSc_LocVoltage_SupBat_Volt((c08_V_0_25k4_0k1)fTemp32);

  /* We do not have a local measured Ign_Stat nor a local IO_Stat.
   * Hence, these signals keep their init values:
   * Rte_Write_SwcDemSc_LocIgnition_Ign_Stat(c03_ISw_Stat data)
   * Rte_Write_SwcDemSc_LocIoDevice_Io_Stat(SwcDemSc_StdReturnType data) */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_DEMSC_LOCSTUB_APPL_CODE
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
