// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.9 $  

/* PRQA S 839 16 */
/* Multiple includes of Platform_Types.h are caused implicitly by other components and can therefore not be avoided here. */

#include <MTSI.h>
#include <MTSI_Callouts.h>
#include <MTSI_Driver.h>
#include <MTSI_Statistics.h>
#include <MTSI_Pal.h>
#include <MTSI_Cfg.h>
#include <MtsiAdapter.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* PRQA S 2052 EOF *//* This line comment appears to comment out source code. */
/* Required to properly visualize the #if/#else/#endif matching conditions */
/* PRQA S 5087 EOF */
/* Multiple include of MTSI_MemMap_Cfg.h within source code is required for core specific memory mapping of static variables. */
/* PRQA S 2211 EOF *//* '%s' is not aligned with the previously declared identifier. */
/* The current indentation method works, no need to change it. */

#if (defined(CFG_MTSI_MAX_SYNC_FRAME_LOG) && (TRUE == CFG_MTSI_MAX_SYNC_FRAME_LOG))
typedef struct {
  uint32 VirtualAddress;
  uint32 Length;
  uint16 FunctionId;
  uint8  CoreID;
} t_SyncSizeMon;

t_SyncSizeMon SyncSizeMon[5u] = {0};
uint8 ui8_MaxCnt = 0u;
#endif /*(defined(CFG_MTSI_MAX_SYNC_FRAME_LOG) && (TRUE == CFG_MTSI_MAX_SYNC_FRAME_LOG))*/

#define MTSI_START_SEC_VAR_INIT_ASIL_B_CACHED_UNSPECIFIED
#include <MTSI_MemMap_Cfg.h>

/// @brief    Indicates if initialization of MTSI service module is done
/// @range    b_FALSE, b_TRUE
static boolean InitDone = b_FALSE;

uint32 MTSI_MainCnt;

#if (defined(CFG_MTSI_DEM_RECORDING_ENABLED) && (TRUE == CFG_MTSI_DEM_RECORDING_ENABLED))
/// @brief    Indicates if a measfreeze has been lost
/// @range    b_FALSE, b_TRUE
static boolean MTSI_MeasFreezeLost = b_FALSE;

static  MTSI_t_FreezeLostInfo FreezeLostInfo = { 0u };
#endif /*(defined(CFG_MTSI_DEM_RECORDING_ENABLED) && (TRUE == CFG_MTSI_DEM_RECORDING_ENABLED))*/

#define MTSI_STOP_SEC_VAR_INIT_ASIL_B_CACHED_UNSPECIFIED
#include <MTSI_MemMap_Cfg.h>

#define MTSI_SIZE_LOST_FREEZE 10u

#define MTSI_MAX_LENGTH_OF_DATA 0xFFFFFFu

/// @brief 10s = 20ms task period * 500
#define MTSI_STARTUP_WAIT_FPGA  500u

/// Start of reserved area for virtual addresses.
#define MTSI_MAX_VIRTUAL_ADDRESS 0xF0000000uL

typedef enum{
  STIMULI_MTSI_NO_TEST             = 0,               ///< No test stimuli
  STIMULI_MTSI_MAX_VIRTUAL_ADDRESS = 1,               ///< Stimuli for max virtual address
  STIMULI_MTSI__FORCE_32           = 65536            ///< Should not be used - force to 32 bits.
}StimuliMTSI_t;


#if (defined(CFG_MTSI_TST_ENABLED) && (CFG_MTSI_TST_ENABLED == TRUE))
/// @brief Description: Standard interface for MTSI Test_Stimuli \n
///      
/// @pre
///   DEM has to be initialized
/// @post
///   none
/// @param  [in] u_TestCaseId :   ID representing the particular test case to be triggered \n
/// @param  [in] u_TestAction :  Action that determines the behavior of the particular test case \n
/// @param  [in] u_Value      : The value to be used (number for the stimuli max virtual address)
/// @return
///   void
/// @globals
///   none
/// @InOutCorrelation
///   Function called by MTSI_v_Dem_TestManager and will call the MEASFreezeDataMTS function if u_TestAction == SHORTTERMADJUSTMENT (the signal is locked and adjust to the given value), and
///   set the virtual address of the Freeze info to MTSI_MAX_VIRTUAL_ADDRESS in case the value for the stimuli is the maximal virtual address (STIMULI_MTSI_MAX_VIRTUAL_ADDRESS).
/// @callsequence
///		None
/// @testmethod
///   Tested by the MTSI_v_Dem_TestManager function. \n
///   1) TEST_MTSI_v_Dem_TestManager_1 : Code coverage for function MTSI_v_Dem_TestManager() when the signal is locked and the stimuli are set for max virtual address. \n
///   2) TEST_MTSI_v_Dem_TestManager_2 : Code coverage for function MTSI_v_Dem_TestManager() when the signal is locked and adjust to the given value (0x03) \n
///   3) TEST_MTSI_v_Dem_TestManager_3 : Code coverage for function MTSI_v_Dem_TestManager() when the signal is unlock.
/// @traceability
static void v_MTSIDem(const uint16 u_TestCaseId, const uint8 u_TestAction, const uint32 u_Value);
#endif

#define MTSI_START_SEC_CODE_ASIL_B
#include <MTSI_MemMap_Cfg.h>

void MTSI_Init(void)
{  
  // Initialize statistic module
  MTSI_StatsInit(MTSI_MODULE_MAJOR_VERSION, MTSI_MODULE_MINOR_VERSION, MTSI_MODULE_PATCH_VERSION);
  
  // Initialize driver module (PAL and custom module will hereby be initialized implicitly)
  MTSI_DriverInit();

  // Set flag for done initialization
  InitDone = b_TRUE;

  MTSI_MainCnt = 0;
}

void MTSI_DeInit(void)
{ 
  // Deinitialize driver module (PAL will hereby be deinitialized implicitly)
  MTSI_DriverDeInit();
  
  // Reset flag regarding initialization status
  InitDone = b_FALSE;
}

void MTSI_MainFunction(void)
{
#if (defined(CFG_MTSI_DEM_RECORDING_ENABLED) && (TRUE == CFG_MTSI_DEM_RECORDING_ENABLED))
  uint8 PreExtData[MTSI_SIZE_LOST_FREEZE] = {0u};
#endif

  if(MTSI_MainCnt < (MTSI_STARTUP_WAIT_FPGA*2) )
  {MTSI_MainCnt++;}//in case over flow

  MTSI_StatsSetEvent(MTSI_EVENT_TYPE_START, ((uint8)MTSI_MAIN_FUNCTION), 0u);

  // Call cyclic runnable at driver module
  MTSI_DriverMainFunction();

#if (defined(CFG_MTSI_DEM_RECORDING_ENABLED) && (TRUE == CFG_MTSI_DEM_RECORDING_ENABLED))
  if(MTSI_MeasFreezeLost == b_TRUE)
  {
    (void)memcpy((void *)&PreExtData, (void *)&FreezeLostInfo, MTSI_SIZE_LOST_FREEZE);
    MTSI_Dem_ReportErrorStatus(MTSI_DEM_MEASFREEZE_LOST, MTSI_DEM_EVENT_STATUS_FAILED, &PreExtData[0], MTSI_SIZE_LOST_FREEZE);

    MTSI_MeasFreezeLost = b_FALSE;
  }
#endif

    MTSI_StatsSetEvent(MTSI_EVENT_TYPE_END, ((uint8)MTSI_MAIN_FUNCTION), 0u);
}


#if (defined(CFG_MTSI_TST_ENABLED) && (CFG_MTSI_TST_ENABLED == TRUE))

//*************************************************************************************************
// Stimuli for Dem reporting
// *************************************************************************************************
void MTSI_v_Dem_TestManager(const uint16 u_TestModuleId, const uint16 u_TestCaseId, const uint8 u_TestAction, const uint32 u_Value)
{
  MEASInfo_t TestMEASInfo;
  uint32 u_FreezeTestId = u_TestCaseId;

  TestMEASInfo.VirtualAddress = 0x0u;
  TestMEASInfo.Length = 10;
  TestMEASInfo.FuncID = 0x0u;

  if (SHORTTERMADJUSTMENT == u_TestAction)
  {
    if(u_Value == (uint32)STIMULI_MTSI_MAX_VIRTUAL_ADDRESS)
    {
      TestMEASInfo.VirtualAddress = MTSI_MAX_VIRTUAL_ADDRESS;
    }
    else
    {
      // Nothing needs to be done
    }

    (void)MEASFreezeDataMTS(&TestMEASInfo, (void *)&u_FreezeTestId, NULL_PTR);
  }
  else
  {
    // Nothing needs to be done
  }
}
#endif // (defined(CFG_MTSI_TST_ENABLED) && (CFG_MTSI_TST_ENABLED == TRUE)) */


MEASReturn_t MTSI_FreezeData(MTSI_t_FreezeInfo const * const p_FreezeInfo, void const * const p_Data, const MTSI_t_Callback p_Callback)
{
  MEASReturn_t MEASReturn_FreezeData = MEAS_NOT_OK;

  // Local variables
  MTSI_t_Header Header = { 0u };

  MTSI_StatsSetEvent(MTSI_EVENT_TYPE_START, ((uint8)MTSI_CHKPT_ID_FUNC_FREEZE_DATA), 0u);

  // Check if component is initialized
  if( b_TRUE == InitDone )
  {
    // Check validity of input parameters
    if( (NULL != p_FreezeInfo) && (NULL != p_Data) )
    {
      // Check if virtual address is within allowed range
      if( MTSI_MAX_VIRTUAL_ADDRESS > p_FreezeInfo->VirtualAddress )
      {
        //Enter ExclusiveArea
        (void)MTSI_PalEnterExclusiveArea();

        // Map function ID to lane
        const uint8 LaneId = MTSI_CustomGetLaneId(p_FreezeInfo->FunctionId);
        
        // Prepare MTS header
        MTSI_DriverPrepareHeader(p_FreezeInfo, &Header);

        // Check kind of job and store it
        if( /*(NULL == p_Callback) ||//force to use AsynJob*/
            (CFG_MTSI_MINIMUM_SIZE_OF_ASYNC_JOB > p_FreezeInfo->Length) ||
            ((p_FreezeInfo->Options & MTSI_OPTION_BUFFERED) == MTSI_OPTION_BUFFERED) )
        {
          // Store synchronous job
          MEASReturn_FreezeData = MTSI_DriverStoreSyncJob(&Header, p_Data, p_Callback);

#if (defined(CFG_MTSI_MAX_SYNC_FRAME_LOG) && (TRUE == CFG_MTSI_MAX_SYNC_FRAME_LOG))
          for (ui8_MaxCnt=0; ui8_MaxCnt<5; ui8_MaxCnt++)
          {
            if (p_FreezeInfo->Length >= SyncSizeMon[ui8_MaxCnt].Length)
            {
              SyncSizeMon[ui8_MaxCnt].VirtualAddress = p_FreezeInfo->VirtualAddress;
              SyncSizeMon[ui8_MaxCnt].FunctionId     = p_FreezeInfo->FunctionId;
              SyncSizeMon[ui8_MaxCnt].Length         = p_FreezeInfo->Length;
              SyncSizeMon[ui8_MaxCnt].CoreID         = MTSI_PalGetCoreId();
              break;
            }
          }
#endif /*(defined(CFG_MTSI_MAX_SYNC_FRAME_LOG) && (TRUE == CFG_MTSI_MAX_SYNC_FRAME_LOG))*/

        }
        else
        {
          // Store asynchronous job
          MEASReturn_FreezeData = MTSI_DriverStoreAsyncJob(LaneId, &Header, p_Data, p_Callback);
        }

        //Enter ExclusiveArea
        MTSI_PalExitExclusiveArea();
      }
      else
      {
        // Invalid VirtualAddress. Prepare MTS header for checkpoint storage.
        MTSI_DriverPrepareHeader(p_FreezeInfo, &Header);

        // Set checkpoint because of invalid virtual address
        MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_FREEZE_DATA, (uint8)MTSI_CHKPT_ERR_ID_1, &Header);

        MEASReturn_FreezeData = MEAS_FREEZE_DATA_INVALID_ADD;
      }
    }
    else
    {
      //Invalid data pointer
      if (NULL != p_FreezeInfo)
      {
        // Invalid data address. Prepare MTS header for checkpoint storage.
        MTSI_DriverPrepareHeader(p_FreezeInfo, &Header);
      }

      // Set checkpoint because of invalid input parameters
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_FREEZE_DATA, (uint8)MTSI_CHKPT_ERR_ID_0, &Header);

      MEASReturn_FreezeData = MEAS_FREEZE_DATA_INPUT_PARAM;
    }
  }
  else
  {
    // Nothing needs to be done
  }

  // Check if the return code is OK (freeze was accepted) and return MEAS_OK
  if ((MEAS_SYNC_JOB_ACCEPTED == MEASReturn_FreezeData) || (MEAS_ASYNC_JOB_ACCEPTED == MEASReturn_FreezeData))
  {
    MEASReturn_FreezeData = MEAS_OK;
  }
  else
  {
#if (defined(CFG_MTSI_DEM_RECORDING_ENABLED) && (TRUE == CFG_MTSI_DEM_RECORDING_ENABLED))
    // Check validity of input parameter
  if(NULL != p_FreezeInfo)
  {
    // Recording the Lost MeasFreeze
    FreezeLostInfo.VirtualAddress       = p_FreezeInfo->VirtualAddress;
    // Check validity of data length of meas freeze
    if (MTSI_MAX_LENGTH_OF_DATA >= p_FreezeInfo->Length)
    {
      FreezeLostInfo.Length         = p_FreezeInfo->Length;
    }
    else
    {
      FreezeLostInfo.Length         = MTSI_MAX_LENGTH_OF_DATA;
    }
    FreezeLostInfo.RejectReason       = (uint8)MEASReturn_FreezeData;
    FreezeLostInfo.FunctionId           = p_FreezeInfo->FunctionId;
  }
  else
  {
    FreezeLostInfo.RejectReason     = (uint8)MEASReturn_FreezeData;
  }
  MTSI_MeasFreezeLost = b_TRUE;
#endif
  }


  MTSI_StatsSetEvent(MTSI_EVENT_TYPE_END, ((uint8)MTSI_CHKPT_ID_FUNC_FREEZE_DATA), 0u);

  return MEASReturn_FreezeData;
}


/* PRQA S 3673 1 */ /* Constant declaration avoided to keep compatibility with SIM environment, which is sharing this interface. - Reviewed by M. Limbrunner, G. Fischer on 2016-09-13 */
MEASReturn_t MEASFreezeDataMTS(const MEASInfo_t * p_MeasInfo, void * p_MeasData, MEAS_Callback_t p_MeasFct)
{  
  MTSI_t_FreezeInfo FreezeInfo;
  MEASReturn_t MEASReturn_MEASFreezeDataMTS = MEAS_OK;
  
  FreezeInfo.VirtualAddress    = p_MeasInfo->VirtualAddress;
  FreezeInfo.Length            = p_MeasInfo->Length;
  FreezeInfo.FunctionId        = p_MeasInfo->FuncID;
  FreezeInfo.Options           = MTSI_OPTION_NONE;

  if (MTSI_MainCnt > MTSI_STARTUP_WAIT_FPGA)
  {
    //white list for Fct, Lcf module
    switch (FreezeInfo.FunctionId)
    {
      MTSI_FUNCTION_ID_FILTER
        MEASReturn_MEASFreezeDataMTS = MTSI_FreezeData(&FreezeInfo, p_MeasData, p_MeasFct);
        break;
      default:
        break;
    }
  }
  
  return MEASReturn_MEASFreezeDataMTS;
}

#define MTSI_STOP_SEC_CODE_ASIL_B
#include <MTSI_MemMap_Cfg.h>

#ifdef __cplusplus
}
#endif


