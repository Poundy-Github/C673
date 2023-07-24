// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements all functions for the core feature of the RTA.

#include <Std_Types.h>
#include <rta.h>
#include <rta_globalids.h>
#include <rta_req_if.h>
#include <rta_basics.h>
#include <rta_defs.h>
#include <rta_version.h>
#include <rta_basic_cfg.h>
#include <rta_add_event.h>
#include <rta_aux_cores_priv.h>
#include <rta_suspend_priv.h>

#ifdef __cplusplus
extern "C"
{
#endif


/// This macro calculates the size of the rtaEventBuffer for the current core in bytes.
#define RTA_BUFFER_SIZE_BYTE (((uint32)sizeof(RTA_t_BufferHeader)) + ((uint32)sizeof(RTA_t_EventData) * p_dataSet->p_params->u_maxNumberOfRtaEvents))


/// \brief This function initializes all dataSets using the lookupTables eg. a_CORE_ID_LIST, a_VIRTUAL_ADRR_LIST, ...
///
/// \pre    None
/// \post   The dataSetHandler is ready to use.
///
/// \param  p_dataSet
///         - Description: Pointer to the dataSet which shall be initialized, details see in type declaration.\n
///
/// \return Always RTA_NO_ERROR
///
/// globals
///         [out]  a_dataSetList \n
///         - Description: Array containing all datatSets. \n
///                        See description of a_dataSetList for details
///         [in] a_VIRTUAL_ADRR_LIST  \n
///         - Description: Array containing the virtualAddresses for all cores \n
///                        See description of a_VIRTUAL_ADRR_LIST for details
///         [in] a_FUNC_ID_LIST  \n
///         - Description: Array containing the funcIds for all cores \n
///                        See description of a_FUNC_ID_LIST for details
///         [in]  a_FUNC_CH_ID_LIST \n
///         - Description: Array containing funcChannelIds for all cores \n
///                        See description ofa_FUNC_CH_ID_LIST  for details
///
/// \traceability
///           <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-404-0005ebe0">Link to L4 Design Spec</a>
static void v_InitDataSet(const RTA_t_DataSet* const p_dataSet);


#define CddSwc_RTA_START_SEC_INIT_CODE
#include <rta_memmap_cfg.h>

void RTA_v_Init(void)
{
  // Request dataSet and check if we got it
  const RTA_t_DataSet* const p_dataSet = RTA_p_GetDataSet();
  if(NULL != p_dataSet)
  {
    if(b_TRUE == p_dataSet->p_ctrl->b_initialized)
    {
      //Already initialized - set related flag in statusField
      p_dataSet->p_ctrl->componentInfo.status.u_warnings |= (uint32)(1uL << (uint32)RTA_ALREADY_INIT);
    }
    else
    {
      // Finally initialize the dataSet
      v_InitDataSet(p_dataSet);
    }
  }

  RTA_v_AuxCoresInit();
}

#define CddSwc_RTA_STOP_SEC_INIT_CODE
#include <rta_memmap_cfg.h>


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

void RTA_v_MainFunction(void)
{
  RTA_v_SwitchBuffer();

  RTA_v_FreezeBuffer();
}


void RTA_v_SwitchBuffer(void)
{
  // Request dataSet of current core and check if we got one
  const RTA_t_DataSet* const p_dataSet = RTA_p_GetDataSet();

  if(NULL != p_dataSet)
  {
    if(b_FALSE == p_dataSet->p_ctrl->b_initialized)
    {
      // Not initialized up to now Update warningStatus
      p_dataSet->p_ctrl->componentInfo.status.u_warnings |= (uint32)(1uL << (uint32)RTA_NOT_INIT);
    }
    else
    {
      RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTA_GLOBALID_RTA, (uint8)RTA_SWITCH_FUNC, p_dataSet->p_ctrl->u_bufferSwitchCnt);
      {
        // Disable interrupts
        RTA_ReqIf_v_DisableInterrupts();

        if(b_FALSE == RTA_b_Suspended())

        {
          if(  (b_TRUE                == p_dataSet->p_ctrl->b_freezeRtaBuffer      )
             &&(RTA_CYCLES_TO_RECOVER >  p_dataSet->p_ctrl->u_rtaBufferNotFrozenCnt)
            )
          {
            // rtaBuffer has not  been frozen since last switch and it is too early for recovery
            p_dataSet->p_ctrl->u_rtaBufferNotFrozenCnt++;
            p_dataSet->p_ctrl->componentInfo.u_BufferNotFrozenCnt++;
            p_dataSet->p_ctrl->componentInfo.status.u_errors |= (uint32)(1uL << (uint32)RTA_BUFFER_NOT_FROZEN);

            RTA_v_AddEvent(RTA_EVT_MARKER, RTA_GLOBALID_RTA, (uint8)RTA_WARNING_BUFFER_NOT_FROZEN, (uint8)p_dataSet->p_ctrl->u_rtaBufferNotFrozenCnt);
          }
          else
          {
            // Check if the previously started bufferFreeze has been finished already
            if(  (*(p_dataSet->p_callbackCnt) != p_dataSet->p_ctrl->u_expectedCallBackCntValue)
               &&(RTA_CYCLES_TO_RECOVER       >  p_dataSet->p_ctrl->u_freezePendingCnt        )
              )
            {
              // bufferFreeze is still ongoing and it is too early for recovery
              p_dataSet->p_ctrl->u_freezePendingCnt++;
              p_dataSet->p_ctrl->componentInfo.u_asyncFreezeNotFinishedCnt++;
              p_dataSet->p_ctrl->componentInfo.status.u_errors |= (uint32)(1uL << (uint32)RTA_ASYNC_FREEZE_NOT_FINISHED);
              RTA_v_AddEvent(RTA_EVT_MARKER, RTA_GLOBALID_RTA, (uint8)RTA_WARNING_BUFFER_FREEZE_PENDING, (uint8)p_dataSet->p_ctrl->u_freezePendingCnt);
            }
            else
            {

              RTA_t_BufferGeneric* const p_oldRtaBuffer = p_dataSet->p_params->a_ptrRtaBuffer[p_dataSet->p_ctrl->u_rtaBufferIndex];
              RTA_t_BufferGeneric*       p_newRtaBuffer;

              // Create an markerEvent showing the bufferSwitch
              RTA_v_AddEvent(RTA_EVT_MARKER, RTA_GLOBALID_RTA, (uint8)RTA_SWITCH_BUFFER, p_dataSet->p_ctrl->u_bufferSwitchCnt);

              // Do the bufferSwitch
              p_dataSet->p_ctrl->u_rtaBufferIndex = ((p_dataSet->p_ctrl-> u_rtaBufferIndex + (uint32)1) & (uint32)1);
              // Do not use increment/decrement operator (++ or --) in case of volatile variables as it causes QAC warnings
              p_dataSet->p_ctrl->u_bufferSwitchCnt = p_dataSet->p_ctrl->u_bufferSwitchCnt + (uint8)1;

              p_newRtaBuffer = p_dataSet->p_params->a_ptrRtaBuffer[p_dataSet->p_ctrl->u_rtaBufferIndex];


              RTA_v_PrepareBuffersAtBufferswitch(p_dataSet, p_oldRtaBuffer, p_newRtaBuffer);

              //Prepare index and refTimestamp for next run
              p_newRtaBuffer->RtaBufferHeader.u_MaxEventIndex = 0u;
              p_newRtaBuffer->RtaBufferHeader.u_RefTs_us = RTA_u_GetSystemTime();
              // Also clear bufferOverflow flag and update bufferCnt
              p_newRtaBuffer->RtaBufferHeader.u_CtrlFlags &= (~RTA_BUFFER_OVERFLOW_FLAG);
              p_newRtaBuffer->RtaBufferHeader.u_BufferCnt =  p_dataSet->p_ctrl->u_bufferSwitchCnt;

              // PRQA S 0314 ++
              // Date: 18 Jan 2022, Reviewer: uic90251 (Farcas A.),
              // reason: [Severity 3: 0314]: [I] Cast from a pointer to object type to a pointer to void.
              // Non-critical.

              // Do cacheWriteback if activated - This is necessary when rtaBufferInjector is used.
              // Note: cachWriteback is done quite after updating the RefTs_us, as the debugToolBox checks whether the timeStamp has been changed.
              RTA_ReqIf_v_WritebackCache((void*)p_dataSet->p_params->a_ptrRtaBuffer[0], RTA_BUFFER_SIZE_BYTE * RTA_NO_OF_BUFFERS);
              // PRQA S 0314 --

              p_dataSet->p_ctrl->u_localTime = RTA_ReqIf_u_GetLocalTimeInUs();

              // Set the sendBufferFlag indicating that there was a bufferSwitch and the rtaBuffer has to be frozen and reset related recovery counters
              p_dataSet->p_ctrl->b_freezeRtaBuffer            = b_TRUE;
              p_dataSet->p_ctrl->u_rtaBufferNotFrozenCnt      = 0u;
              p_dataSet->p_ctrl->u_freezePendingCnt           = 0u;

            }
          }
        }
       // Enable interrupts again
        RTA_ReqIf_v_EnableInterrupts();
      }
      RTA_v_AddEvent(RTA_EVT_ALGOEND, RTA_GLOBALID_RTA, (uint8)RTA_SWITCH_FUNC, p_dataSet->p_ctrl->u_bufferSwitchCnt);
    }
  }

  // Switch all AuxiliaryCores buffers
  RTA_v_AuxCoresSwitchAllBuffers();
}


void RTA_v_FreezeBuffer(void)
{
  // Request dataSet and check if we got it
  const RTA_t_DataSet* const p_dataSet = RTA_p_GetDataSet();
  if(NULL != p_dataSet)
  {
    uint32                u_freezeResult;
    RTA_t_MeasFreezeInfo  measInfo;

    // Fill u_functionId of measInfo as these are the same for both the bufferFreeze and the infoFreeze as well
    measInfo.u_functionId          = p_dataSet->p_params->u_functionId;

    // Generate the startEvent
    RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTA_GLOBALID_RTA, (uint8)RTA_FREEZE_FUNC, p_dataSet->p_ctrl->u_bufferSwitchCnt);

    // Check if we should freeze the rtaBuffer
    if(b_TRUE == p_dataSet->p_ctrl->b_freezeRtaBuffer)
    {
      // Get the address of currently active rtaBuffer
      RTA_t_BufferGeneric* const p_rtaBuffer = p_dataSet->p_params->a_ptrRtaBuffer[(p_dataSet->p_ctrl->u_rtaBufferIndex + 1uL) & 1uL];

      if(NULL != p_rtaBuffer)
      {

        //The RtaBuffer shall be frozen asynchronously - set u_expectedCallBackCntValue to 1 higher than the counter incremented by callbackFunction
        p_dataSet->p_ctrl->u_expectedCallBackCntValue   = *(p_dataSet->p_callbackCnt) + 1u;

        // PRQA S 0315 ++
        // Date: 18 Jan 2022, Reviewer: uic90251 (Farcas A.),
        // reason: [Severity 3: 0315]: [I] Implicit conversion from a pointer to object type to a pointer to void.
        // Non-critical.

        // Initialize the rest of  measInfo
        measInfo.p_data      = p_rtaBuffer;
        // PRQA S 0315 --

        measInfo.u_lenght    = (uint32)sizeof(RTA_t_BufferHeader) + ((uint32)sizeof(RTA_t_EventData) * p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex);
        measInfo.u_virtAddr  = p_dataSet->p_params->u_virtAddrRtaBuffer;
        measInfo.p_callBack  = p_dataSet->p_params->p_measCallbackFct;

        //Trigger the bufferFreeze
        u_freezeResult = RTA_ReqIf_u_MeasFreezeData(&measInfo);

        if(0uL != u_freezeResult)
        {
          // Any error occurred during the freeze, set related status and increment related counter
          p_dataSet->p_ctrl->componentInfo.status.u_errors |= (uint32)(1uL << (uint32)RTA_BUFFER_FREEZE_ERROR);
          p_dataSet->p_ctrl->componentInfo.u_bufferFreezeErrorCnt++;
          // And set the expectedValue to the current callbackCounter as the callbackFct most probable will not be called by MTSI
          p_dataSet->p_ctrl->u_expectedCallBackCntValue   = *(p_dataSet->p_callbackCnt);
        }

        // Calculate current buffer usage
        p_dataSet->p_ctrl->componentInfo.u_eventBufferCurrentUsagePerc = (uint8)((p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex * RTA_QUOTIENT_2_PERCENT) / p_dataSet->p_params->u_maxNumberOfRtaEvents);
        // Update maxUsage if needed
        if(p_dataSet->p_ctrl->componentInfo.u_eventBufferMaxUsagePerc < p_dataSet->p_ctrl->componentInfo.u_eventBufferCurrentUsagePerc)
        {
          p_dataSet->p_ctrl->componentInfo.u_eventBufferMaxUsagePerc = p_dataSet->p_ctrl->componentInfo.u_eventBufferCurrentUsagePerc;
        }
        // Check if current buffer usage is beyond limit, increment counter and set related warningFlag in case
        if(RTA_LIMIT_MAX_BUFFER_USAGE_PERC < p_dataSet->p_ctrl->componentInfo.u_eventBufferCurrentUsagePerc)
        {
          p_dataSet->p_ctrl->componentInfo.status.u_warnings |= (uint32)(1uL << (uint32)RTA_EVENTBUFFER_LIMIT_EXCEEDED);
          p_dataSet->p_ctrl->componentInfo.u_eventBufferLimitCnt++;
        }

        // Check whether there was a bufferOverflow
        if(RTA_BUFFER_OVERFLOW_FLAG == (RTA_BUFFER_OVERFLOW_FLAG & p_rtaBuffer->RtaBufferHeader.u_CtrlFlags))
        {
          // OK we had a bufferOverflow in the last cycle - increment related counter and set errorFlag
          p_dataSet->p_ctrl->componentInfo.status.u_errors |= (uint32)1 << (uint32)RTA_EVENTBUFFER_FULL;
          p_dataSet->p_ctrl->componentInfo.u_eventBufferFullCnt++;
        }

        //Reset the freeze flag in order to avoid double freezing of the same buffer
        p_dataSet->p_ctrl->b_freezeRtaBuffer = b_FALSE;
      }
    }

    // PRQA S 0315 ++
    // Date: 18 Jan 2022, Reviewer: uic90251 (Farcas A.),
    // reason: [Severity 3: 0315]: [I] Implicit conversion from a pointer to object type to a pointer to void.
    // Non-critical.

    // Do cyclic statusInfoFreeze and check result
    // Initialize the rest of measInfo
    measInfo.p_data      = &p_dataSet->p_ctrl->componentInfo;
    // PRQA S 0315 --

    measInfo.u_lenght    = (uint32)sizeof(RTA_t_Info);
    measInfo.u_virtAddr  = p_dataSet->p_params->u_virtAddrRtaInfo;
    measInfo.p_callBack  = NULL;

    u_freezeResult = RTA_ReqIf_u_MeasFreezeData(&measInfo);
    if(0uL != u_freezeResult)
    {
      //Any error occurred during the freeze, set related status
      p_dataSet->p_ctrl->componentInfo.status.u_warnings |= (uint32)(1uL << (uint32)RTA_INFO_FREEZE_ERROR);
    }
    // Finally report all occurred warnings and errors
    // TODO: Check what to do here - RTL is not supported anymore, report the errors via errorTrackerFeature in RTA ???

    //Generate the endEvent - provide the current bufferUsage in optData
    RTA_v_AddEvent(RTA_EVT_ALGOEND, RTA_GLOBALID_RTA, (uint8)RTA_FREEZE_FUNC, p_dataSet->p_ctrl->componentInfo.u_eventBufferCurrentUsagePerc);

  } // if(NULL != p_dataSet)

  // Freeze all AuxiliaryCore buffers
  RTA_v_AuxCoresFreezeAllBuffers();
}


void RTA_v_AddEvent(const RTA_t_Events event, const RTA_t_GlobalID u_globalID, const RTA_t_LocalID u_localID, const RTA_t_OptData u_optData)
{
  // Request dataSet and check if we got it
  const RTA_t_DataSet* const p_dataSet = RTA_p_GetDataSet();
  if(NULL != p_dataSet)
  {
    if(b_TRUE                    == p_dataSet->p_ctrl->b_initialized)
    {
      if(b_TRUE == RTA_ReqIf_v_IsGlobalIdEnabled(u_globalID))
      {
        //GlobalID shall not be suppressed - add the desired rtaEvent
        RTA_t_EventData eventData;
        eventData.u_EventType  = (uint8)event;
        eventData.u_GlobalId   = (uint8)u_globalID;
        eventData.u_LocalId    = (uint8)u_localID;
        eventData.u_OptData    = u_optData;

        RTA_v_InternalAddEvent(p_dataSet, &eventData);
      }
    }
    else
    {
      // Update warningStatus
      p_dataSet->p_ctrl->componentInfo.status.u_warnings |= (uint32)(1uL << (uint32)RTA_NOT_INIT);
    }
  }
}


static void v_InitDataSet(const RTA_t_DataSet* const p_dataSet)
{
  uint32 u_BufferIndex;

  if((NULL != p_dataSet) && (NULL != p_dataSet->p_ctrl))
  {

    // PRQA S 0315 ++
    // Date: 18 Jan 2022, Reviewer: uic90251 (Farcas A.),
    // reason: [Severity 3: 0315]: [I] Implicit conversion from a pointer to object type to a pointer to void.
    // Non-critical.
    RTA_ReqIf_v_MemSet(p_dataSet->p_ctrl, 0, sizeof(RTA_t_Ctrl));
    // PRQA S 0315 --

    // Get relevant addresses
    p_dataSet->p_ctrl->componentInfo.u_rtaVersion = RTA_COMPONENT_VERSION;

    p_dataSet->p_ctrl->u_localTime                = RTA_ReqIf_u_GetLocalTimeInUs();

    // Initialize callbackCounter
    *(p_dataSet->p_callbackCnt)                   = 0u;
    // Loop over both buffers in the dataSet and initialize the bufferHeaders
    for(u_BufferIndex = 0u; RTA_NO_OF_BUFFERS > u_BufferIndex; u_BufferIndex++)
    {
      RTA_t_BufferGeneric* p_buffer = p_dataSet->p_params->a_ptrRtaBuffer[u_BufferIndex];

      // Initialize all member variables
      p_buffer->RtaBufferHeader.u_Version         = RTA_IF_VERSION;
      p_buffer->RtaBufferHeader.u_CoreID          = p_dataSet->p_params->u_CoreID;
      p_buffer->RtaBufferHeader.u_RefTs_us        = RTA_ReqIf_u_GetSystemTimeInUs();
      p_buffer->RtaBufferHeader.u_Padding_00      = 0u;  // Not in use
      p_buffer->RtaBufferHeader.u_Padding_01      = 0u;  // Not in use
      p_buffer->RtaBufferHeader.u_Padding_02      = 0u;  // Not in use
      p_buffer->RtaBufferHeader.u_CtrlFlags       = 0u;  // Clear all ctrlFlags
      p_buffer->RtaBufferHeader.u_Padding_10      = 0u;  // Not in use
      p_buffer->RtaBufferHeader.u_Padding_11      = 0u;  // Not in use
      p_buffer->RtaBufferHeader.u_Padding_12      = 0u;  // Not in use
      p_buffer->RtaBufferHeader.u_BufferCnt       = 0u;  // Running bufferNumber starts with 0
      p_buffer->RtaBufferHeader.u_MaxEventIndex   = 0u;
      p_buffer->RtaBufferHeader.u_ContainerSize   = p_dataSet->p_params->u_maxNumberOfRtaEvents;

      // PRQA S 0315 ++
      // Date: 18 Jan 2022, Reviewer: uic90251 (Farcas A.),
      // reason: [Severity 3: 0315]: [I] Implicit conversion from a pointer to object type to a pointer to void.
      // Non-critical.

      // Fill the whole eventContainer with 0xFF. This is required for lockless RTA
      RTA_ReqIf_v_MemSet(p_buffer->a_EventContainer, (sint16)UINT8_MAX_VALUE,   (uint32)sizeof(RTA_t_EventData) * (p_dataSet->p_params->u_maxNumberOfRtaEvents));

      // PRQA S 0315 --
    }

    // Finally set the initFlag
    p_dataSet->p_ctrl->b_initialized = b_TRUE;
  }

  return;
}


#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif
