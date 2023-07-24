/***********************************************************************
  COMPANY:     Continental Automotive
  PROJECT:     Mainstream
  COMPONENT:   MTSI - MFC5xx custom implementation.
  VERSION:     $Revision: 1.5 $
 **********************************************************************/

#include "MTSI_Custom.h"
#include "MTSI_Callouts.h"
#include "MTSI_Driver.h"
#include "MTSI_Statistics.h"
#include "MTSI_Pal.h"
#include "glob_comp_id.h"


/* PRQA S 6000,6001,6011,6030,6040 EOF *//* Reviewer:TBD, ReviewDate:TBD, ReviewID:TBD */

#ifdef __cplusplus
extern "C"
{
#endif


/* Mode of the MTSI */
/* Range 0 - 2 (UNKNOWN, OFF, ON) */
/*PRQA S 3218, 3229 1*/ /*Needed as global for debug purposes.*/
static MTSI_t_ConfigMode ConfigMode = CONFIG_MODE_MTSI_ON;

typedef enum
{
  MTSI_MTA_SYNC_ON    = 0,
  MTSI_MTA_SYNC_LOST  = 1,
  MTSI_MTA_SYNC_DELAY = 2
} MTSI_t_CustResyncState;

MTSI_t_CustResyncState MTA_SynconizationState = MTSI_MTA_SYNC_DELAY;
uint32 ui32_MTA_SyncDelay    = 0u;
uint32 ui32_GPIO0_ReadInput  = 0u;

/* Task ID of core 0 */
#define MTSI_TASK_ID_CORE_0 ((uint16)CFG_MTSI_MTA_FRAME_TASK_BASE_ID)

#define MTSI_CUST_SIZE_LOST_FREEZE  10u
#define MTSI_CUST_RESYNC_DELAY_TIME 500u

/* Pin used as input for the Aurora Link Down monitor. (GP0_19 - DU_EXHSYNC/DU_HSYNC / MTI/Aurora backchannel on MTA and EDP )  */
#define MTSI_CUST_GPIO0_PIN19_UART_RX_MTA2SOC 0x00080000

#ifndef __IPL_CANTPP__
/* As per R-Car datasheet, 7.1.4 Register Configuration, reading the GP0 input data can be done by using
 * General input register 0 INDT0 R State of the port pins H'E605 000C Retained */
#define MTSI_PAL_GPIO0_INDT0    *((uint32*)0xE605000C)
#else
uint32 MTSI_PAL_GPIO0_INDT0 = 0;
#endif

/* Custom initialization */
Std_ReturnType MTSI_CustomInit(uint8* const p_Mode, uint8* const p_InstanceNr)
{
  /* Status of initialization */
  Std_ReturnType InitState = E_NOT_OK;

  /* Pass the DEMevent once at startup */
  //(void)Dem_ReportErrorStatusPreExtData(MTSI_DEM_MEASFREEZE_LOST, DGM_EVENT_STATUS_PASSED, NULL, 0u);

  /* Check validity of input parameters */
  if( (NULL != p_Mode) && (NULL != p_InstanceNr) )
  {
    /* Check if usage of NvM parameters is enabled */
    #if( (defined CFG_MTSI_NVM_PARAMETERS_ENABLED) && (TRUE == CFG_MTSI_NVM_PARAMETERS_ENABLED) )
    
    /* Initialize output mode */
    uint8 Mode = MTSI_OUTPUTMODE_OFF;
  
    /* Evaluate configured mode */
    switch(ConfigMode)
    {
      case CONFIG_MODE_MTSI_ON:
      Mode = MTSI_OUTPUTMODE_1;
      InitState = E_OK;
      break;
  
      case CONFIG_MODE_MTSI_OFF:
      Mode = MTSI_OUTPUTMODE_OFF;
      InitState = E_OK;
      break;
  
      default:
      Mode = MTSI_OUTPUTMODE_OFF;
      InitState = E_NOT_OK;
      break;
    }
  
    /* Set output mode */
    *p_Mode = Mode;
    
    /* Set instance number */
    *p_InstanceNr = (uint8)0x00;
    
    #else
  
    /* Set output mode */
    *p_Mode = MTSI_OUTPUTMODE_1;
    
    /* Set instance number */
    *p_InstanceNr = (uint8)0x00;
    
    /* Set state of initialization */
    InitState = E_OK;
    
    #endif
  }
  else
  {
    /* Set error checkpoint because of invalid input parameters */
    MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_CUSTOM_0, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
  }
  
  return InitState;
}


/* Custom function for getting the lane ID */
/* PRQA S 3206 3 */
/* Argument FunctionId is required due to the generic interface, but it is not used for this platform. */
uint8 MTSI_CustomGetLaneId(const uint16 FunctionId)
{
  return MTSI_ID_LANE_0;
}


/* Custom function for starting a new task cycle */
void MTSI_StartTaskCycle_BSWCyclic(void)
{
  static uint8 BSWCycleCounter = 0;

    MTSI_DriverStartTaskCycle(MTSI_TASK_ID_CORE_0);
  /* Update MTSi Pal statistic data and freeze it. Not really that important, but we need something to freeze
   * in every generic task, otherwise we get End2StartCnt errors in tasks where no data is freezed. */
  MTSI_PalUpdateStatistics();
  BSWCycleCounter++;
}

/* Custom function for starting a new MTA cycle */
void MTSI_StartMtaCycle(void)
{
  MTSI_DriverStartMTACycle(MTSI_ID_LANE_0);
}


void MTSI_Dem_ReportErrorStatus(const uint16 Dem_EventIdRaw, const uint8 Dem_EventStatus, const uint8* const Dem_pui8_PreExtData, uint8 Dem_PreExtDataSize)
{
  if (CONFIG_MODE_MTSI_ON == ConfigMode)
  {
    //(void)Dem_ReportErrorStatusPreExtData(Dem_EventIdRaw, Dem_EventStatus, Dem_pui8_PreExtData, Dem_PreExtDataSize);
  }
  else
  {
    /* no action */
  }
}

#ifdef __cplusplus
}
#endif

