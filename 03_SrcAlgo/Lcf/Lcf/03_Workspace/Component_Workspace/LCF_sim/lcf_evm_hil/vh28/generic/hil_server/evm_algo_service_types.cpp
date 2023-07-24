#include "evm_algo_service_types.h"
#include "rta_service.h"
#include "image_fingerprint.h"
#include <cassert>
#include <cstring>
#include <cstdlib>
//ti only provides c version; <cstdint> does not exist
#include <stdint.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>

#ifdef _TMS320C6X
#ifdef _TMS320C6600
#include <ti/sysbios/family/c66/Cache.h>
#else
#include <ti/sysbios/family/c64p/Cache.h>
#endif
#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/drv/src/edma3.h>
#include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>
#elif __TI_ARM_V7M4__
#include <ti/sysbios/hal/unicache/Cache.h>
// GCC defines __ARM_ARCH_7A__ for both CA15 and CA8. 
// For CA15 __ARM_ARCH_EXT_IDIV__ is defined additionally.
#elif (defined(__TI_ARM_V7A8__) | (defined(__ARM_ARCH_7A__) & !defined(__ARM_ARCH_EXT_IDIV__)))
#include <ti/sysbios/family/arm/a8/Cache.h>
#elif (defined(__ARM_ARCH_7A__) & defined(__ARM_ARCH_EXT_IDIV__))
#include <ti/sysbios/family/arm/a15/Cache.h>
#endif
#define REPORT_ERROR(InfoMessage, ModuleName)

#ifdef _TMS320C6X
// Static class member attribute
enum ERROR_EDMA_CODE
{
      RETURN_ERROR_EDMA               = 30,
      RETURN_ERROR_EDMA_HANDLE        = 31,
      RETURN_ERROR_CHANNELREQUEST     = 32,
      RETURN_NOERROR                  = 40,
      RETURN_ERROR_DSTBUFFER          = 42,
      RETURN_ERROR_SRCBUFFER          = 43,
      RETURN_ERROR_CHANNELINDEX       = 44,
      RETURN_ERROR_EDMA_ERRORBIT      = 45,
      RETURN_ERROR_FREECHANNEL        = 46,
      RETURN_ERROR_EDMA_SRCPARAM      = 47,
      RETURN_ERROR_EDMA_DSTPARAM      = 48,
      RETURN_ERROR_EDMA_TRANSFERPARAM = 49,
      RETURN_ERROR_EDMA_SRCIND        = 50,
      RETURN_ERROR_EDMA_DSTIND        = 51,
      RETURN_ERROR_EDMA_TCINT         = 52,
      RETURN_ERROR_EDMA_ITCINT        = 53,
      RETURN_ERROR_EDMA_STATIC        = 54,
      RETURN_ERROR_EDMA_TCC           = 55,
      RETURN_ERROR_EDMA_ENABLE        = 56,
      RETURN_ERROR_EDMASERVICE        = 57,
      RETURN_ERROR_EDMA_CFGTRG_CHAIN  = 58,
      RETURN_ERROR_EDMA_CFGTRG_2D     = 60,
      RETURN_ERROR_EDMA_WAIT          = 97,
      RETURN_ERROR_CHECKTCC           = 98,
      RETURN_INDEX_NOCHAINING         = 99
};


#define EDMA_AB_COUNT_MIN     (     1)
#define EDMA_AB_COUNT_MAX     ( 65535)
#define EDMA_BC_INDEX_MIN     (-32768)
#define EDMA_BC_INDEX_MAX     ( 32767)

#define DSP_L2_RAM_BASE_L3    (0x40800000u)
#define DSP_L2_RAM_MASK       (0xFFFC0000u)
#define EDMA_DST_ALIGN_MASK   (0x7F)

EDMA3_DRV_Handle p_edmaHandle = NULL;
EDMA3_DRV_Result edmaResult = 0;
#endif

evm::as::CServiceTypes::CServiceTypes()
  : m_memoryState(AS_MEM_L2FREE_L3FREE)
  , m_pParamBuff(NULL)
  , m_pFlag_RunEVE(NULL)
  , m_pEVEContainer(NULL)
  , m_pEVEReturnValue(NULL)
{
  assert( AS_SERVICEFUNC_VERSION==6);
#ifdef _TMS320C6X
  sint32 si_Ind = 0;
#endif
  //set the interface version
  u_Version = 4;

  // assign function pointers
  pfMeasFreeze                   =               (AS_t_MeasHdlr)s_measHdlr;
  pfGetCoreTicksuS64             =       (AS_t_GetCoreTicksuS64)s_GetCoreTicksuS64;
  pfGetTimestampuS32             =       (AS_t_GetTimestampuS32)s_GetTimestampuS32;
  pfGetTimestampuS64             =       (AS_t_GetTimestampuS64)s_GetTimestampuS64;
  pfCacheInv                     =               (AS_t_CacheInv)s_CacheInv;
  pfCacheWbInv                   =             (AS_t_CacheWbInv)s_CacheWbInv;
  pfCacheWbInvAll                =          (AS_t_CacheWbInvAll)s_CacheWbInvAll;
  pfDem_SetEventStatus           =     (AS_t_Dem_SetEventStatus)s_Dem_SetEventStatus;
  pfDem_SetEventStatusPreExtData = (AS_t_Dem_SetEventStatusPreExtData)s_Dem_SetEventStatusPreExtData;
#ifdef _TMS320C6X
  //DSP
  pfEDMACopy                     =        (AS_t_EDMACopy)s_EDMACopy;
  pfEDMACopy2D                   =      (AS_t_EDMACopy2D)s_EDMACopy2D;
  pfEDMACopyChained              = (AS_t_EDMACopyChained)s_EDMACopyChained;
  pfEDMAMemSet                   =      (AS_t_EDMAMemSet)NULL;
  pfEDMAWait                     =        (AS_t_EDMAWait)s_EDMAWait;

  pfEDMAGet                      =              (AS_t_EDMAGet)s_EDMAGet;
  pfEDMARelease                  =          (AS_t_EDMARelease)s_EDMARelease;
  pfEDMATranslateAddress         = (AS_t_EDMATranslateAddress)s_EDMATranslateAddress;

#else
  //Cortex A8
  pfEDMACopy                     =             (AS_t_EDMACopy)NULL;
  pfEDMACopy2D                   =           (AS_t_EDMACopy2D)NULL;
  pfEDMACopyChained              =      (AS_t_EDMACopyChained)NULL;
  pfEDMAMemSet                   =           (AS_t_EDMAMemSet)NULL;
  pfEDMAWait                     =             (AS_t_EDMAWait)NULL;

  pfEDMAGet                      =              (AS_t_EDMAGet)NULL;
  pfEDMARelease                  =          (AS_t_EDMARelease)NULL;
  pfEDMATranslateAddress         = (AS_t_EDMATranslateAddress)NULL;
#endif
  pfEVETrigger                   =          (AS_t_EVETrigger)s_EveTrigger;
  pfEVEWait                      =             (AS_t_EVEWait)s_EveWait;
	
  pfMemLock                      =               (AS_t_MemLock)s_memLock;
  pfMemUnlock                    =             (AS_t_MemUnlock)s_memUnlock;
  pfRTAAlgoServiceAddEvent       = (AS_t_RTAAlgoServiceAddEvent)Rta_AlgoServiceAddEvent;
  p_SchedSetSubMode              =       (AS_t_Sched_SetSubMode)NULL;

  pfMemLockL2                    =        (AS_t_MemLockL2)s_memLockL2;
  pfMemUnlockL3                  =      (AS_t_MemUnlockL3)s_memUnlockL3;
  pfMemLockL3                    =        (AS_t_MemLockL3)s_memLockL3;
  pfMemUnlockL2                  =      (AS_t_MemUnlockL2)s_memUnlockL2;
  pfMemScratchLock               =   (AS_t_MemScratchLock)s_memScratchLock;
  pfMemScratchUnlock             = (AS_t_MemScratchUnlock)s_memScratchUnlock;

  pfMeasStartFuncCycle           = (AS_t_MeasStartFuncCycle)s_MeasStartFuncCycle;
  pfTaskWaitForTime              =    (AS_t_TaskWaitForTime)NULL;
  pfTaskWaitForEvent             =   (AS_t_TaskWaitForEvent)NULL;
  pfEVESetLockOutState           = (AS_t_EVESetLockOutState)NULL;

  pfComputeImageFingerPrint_ui16                 = (AS_t_ComputeImageFingerPrint_ui16)s_ComputeImageFingerPrint_ui16;
  pfComputeImageFingerPrint_ui8                  = (AS_t_ComputeImageFingerPrint_ui8)s_ComputeImageFingerPrint_ui8;
  pfComputeImageFingerPrint_DisparityImage       = (AS_t_ComputeImageFingerPrint_DisparityImage)s_ComputeImageFingerPrint_DisparityImage;
  pfComputeImageFingerPrint_FlowImage            = (AS_t_ComputeImageFingerPrint_FlowImage)s_ComputeImageFingerPrint_FlowImage;
  pfCheckImageFingerPrintValidity_ui16           = (AS_t_CheckImageFingerPrintValidity_ui16)s_CheckImageFingerPrintValidity_ui16;
  pfCheckImageFingerPrintValidity_ui8            = (AS_t_CheckImageFingerPrintValidity_ui8)s_CheckImageFingerPrintValidity_ui8;
  pfCheckImageFingerPrintValidity_DisparityImage = (AS_t_CheckImageFingerPrintValidity_DisparityImage)s_CheckImageFingerPrintValidity_DisparityImage;
  pfCheckImageFingerPrintValidity_FlowImage      = (AS_t_CheckImageFingerPrintValidity_FlowImage)s_CheckImageFingerPrintValidity_FlowImage;

#ifdef _TMS320C6X
  // get EDMA handler
  edmaResult = EDMA3_DRV_E_INVALID_PARAM;
  p_edmaHandle = edma3init(0, &edmaResult);

  // fix me - not necessary
  // Initialize EDMA channel IDs; Init ChainedChannels
  for (si_Ind = 0; si_Ind < si_MAX_NUM_EDMACHANNELS; si_Ind++)
  {
    m_ab_FreeEDMAChannels[si_Ind] = b_TRUE;
    m_aui_EDMAChannelTCC[si_Ind] = 0;
    m_aui_EDMAChannelIDs[si_Ind] = 0;
    m_asi_ChainedChannelIndexes[si_Ind] = RETURN_INDEX_NOCHAINING;
  }
#endif
}

evm::as::CServiceTypes& evm::as::CServiceTypes::getInstance()
{
  static CServiceTypes service;
  return (service);
}

sint32 evm::as::CServiceTypes::memLock( void ** p_L2Buffer, sint32 * p_L2BuffSize, void ** p_L3Buffer, sint32 * p_L3BuffSize, AS_t_MemState * p_State )
{
  sint32 returnCode = RETURN_SUCCESS;
  *p_L2Buffer=NULL;
  *p_L3Buffer=NULL;

  if(p_State!=NULL)
  {
    // p_State must return the memory state, before this lock-request
    *p_State = m_memoryState;
  }
  if(m_memoryState != AS_MEM_L2FREE_L3FREE)
  {
    assert(0);
    returnCode=RETURN_ERROR_MEMLOCK_INUSE;
  }
  else if ((p_L2BuffSize == NULL) || (p_L3BuffSize == NULL)  )
  {
    // invalid pointer input
    returnCode = RETURN_ERROR_INPUT;
  }
  else
  {
    // valid call, give away the memory
    memLockL2( p_L2Buffer, p_L2BuffSize, NULL );
    m_memoryState = AS_MEM_L2FREE_L3FREE;
    memLockL3( p_L3Buffer, p_L3BuffSize, NULL );

    //mark memory as used
    m_memoryState=AS_MEM_L2USED_L3USED;
  }

  return returnCode;
}


sint32 evm::as::CServiceTypes::memLockL2( void ** p_L2Buffer, sint32 * p_L2BuffSize, AS_t_MemState * p_State )
{
  sint32 returnCode = RETURN_SUCCESS;
  *p_L2Buffer=NULL;

  if(p_State!=NULL)
  {
    // p_State must return the memory state, before this lock-request
    *p_State = m_memoryState;
  }

  if(m_memoryState != AS_MEM_L2FREE_L3FREE)
  {
      // One algorithm must not lock L2 and L3, using the seperate services for L2 and L3
      // => Since only one algorithm exists on EVM, both RAMs must be free, otherwise we get an error
      assert(0);
      returnCode=RETURN_ERROR_MEMLOCK_INUSE;
  }
  else if ((p_L2BuffSize == NULL) )
  {
    // invalid pointer input
    returnCode = RETURN_ERROR_INPUT;
  }
  else
  {
    // valid call, give away the memory
#ifdef _TMS320C6X
    //DSP
    *p_L2Buffer = (void *) L2_DSP_BASE_ADDR;
    *p_L2BuffSize = L2_AVAILABLE_BUFFER_SIZE_BYTES;
#else
    //CortexA8
    //*p_L2Buffer   = (void *) 0x402F0400;
    *p_L2Buffer   = (void *) L2_CORETEXA8_BASE_ADDR;       //location of L2 of CortexA8 is not known yet
    *p_L2BuffSize = L2_AVAILABLE_BUFFER_SIZE_BYTES_CORTEX_A8;
#endif

    //mark memory as used
    m_memoryState=AS_MEM_L2USED;
  }

  return returnCode;
}

sint32 evm::as::CServiceTypes::memLockL3( void ** p_L3Buffer, sint32 * p_L3BuffSize, AS_t_MemState * p_State )
{
  sint32 returnCode = RETURN_SUCCESS;
  *p_L3Buffer=NULL;

  if(p_State!=NULL)
  {
    // p_State must return the memory state, before this lock-request
    *p_State = m_memoryState;
  }

  if(m_memoryState != AS_MEM_L2FREE_L3FREE)
  {
    // One algorithm must not lock L2 and L3, using the seperate services for L2 and L3
    // => Since only one algorithm exists on EVM, both RAMs must be free, otherwise we get an error
    assert(0);
    returnCode=RETURN_ERROR_MEMLOCK_INUSE;
  }
  else if ((p_L3BuffSize == NULL)  )
  {
    // invalid pointer input
    returnCode = RETURN_ERROR_INPUT;
  }
  else
  {
    // valid call, give away the memory
    *p_L3Buffer   = (void *) L3_BASE_ADDR; // tms320dm8146.pdf page 25
    *p_L3BuffSize = L3_AVAILABLE_BUFFER_SIZE_BYTES;

    //mark memory as used
    m_memoryState=AS_MEM_L3USED;
  }

  return returnCode;
}



sint32 evm::as::CServiceTypes::memUnlock (AS_t_MemState * p_State)
{
  assert(m_memoryState==AS_MEM_L2USED_L3USED);
  sint32 returnCode = RETURN_SUCCESS;

  if(p_State!=NULL)
  {
    // p_State must return the memory state, before this Unlock-request
    *p_State = m_memoryState;
  }

  if(m_memoryState==AS_MEM_L2USED_L3USED)
  {
    //free memory
    m_memoryState=AS_MEM_L2FREE_L3FREE;
  }
  else
  {
    //memory wasn't locked correctly
    returnCode = RETURN_ERROR_MEMUNLOCK_NOTASSIGNED;
  }

  return (returnCode);
}

sint32 evm::as::CServiceTypes::memUnlockL2 (AS_t_MemState * p_State)
{
  assert(m_memoryState==AS_MEM_L2USED);
  sint32 returnCode = RETURN_SUCCESS;

  if(p_State!=NULL)
  {
    // p_State must return the memory state, before this Unlock-request
    *p_State = m_memoryState;
  }
  if(m_memoryState==AS_MEM_L2USED)
  {
    //free memory
    m_memoryState=AS_MEM_L2FREE_L3FREE;
  }
  else
  {
    //memory wasn't locked correctly
    returnCode = RETURN_ERROR_MEMUNLOCK_NOTASSIGNED;
  }

  return (returnCode);
}

sint32 evm::as::CServiceTypes::memUnlockL3 (AS_t_MemState * p_State)
{
  assert(m_memoryState==AS_MEM_L3USED);
  sint32 returnCode = RETURN_SUCCESS;

  if(p_State!=NULL)
  {
    // p_State must return the memory state, before this Unlock-request
    *p_State = m_memoryState;
  }

  if(m_memoryState==AS_MEM_L3USED)
  {
    //free memory
    m_memoryState=AS_MEM_L2FREE_L3FREE;
  }
  else
  {
    //memory wasn't locked correctly
    returnCode = RETURN_ERROR_MEMUNLOCK_NOTASSIGNED;
  }

  return (returnCode);
}


AS_t_MemScratchReturnCode evm::as::CServiceTypes::memScratchLock(const AS_t_MemScratchReqPort * const reqPort, AS_t_MemScratchProPort * const proPort)
{
  assert (reqPort != NULL);
  assert (proPort != NULL);

  AS_t_MemScratchReturnCode returnCode = AS_MEM_SCRATCH_SRV_SUCCESS;

  /* init provide ports */
  proPort->u_sizeL2 = 0;
  proPort->p_memL2 = NULL;
  proPort->u_sizeL3 = 0;
  proPort->p_memL3 = NULL;

  if ((reqPort == NULL) || (proPort == NULL))
  {
    // invalid pointer input
    returnCode = AS_MEM_SCRATCH_SRV_NOT_AVL;
  }
  else
  {
    if ((reqPort->u_sizeL3 > 0) && ((m_memoryState == AS_MEM_L2FREE_L3USED || m_memoryState == AS_MEM_L2USED_L3USED)))
    {
      // L3 memory already locked
      returnCode = AS_MEM_SCRATCH_L3_NOT_FREE;
    }
    else
    {
      // valid call
      if (reqPort->u_sizeL3 > 0)
      {
        /* check if requested size fits into L3 memory */
        if (reqPort->u_sizeL3 > L3_AVAILABLE_BUFFER_SIZE_BYTES)
        {
          returnCode = AS_MEM_SCRATCH_ERR_L3_SIZE;
        }
        else
        {
          // valid call, give away the memory
          proPort->p_memL3  = (void *) L3_BASE_ADDR;
          proPort->u_sizeL3 = L3_AVAILABLE_BUFFER_SIZE_BYTES;

          // set mem state to L3 used
          if (m_memoryState == AS_MEM_L2FREE_L3FREE)
          {
            m_memoryState = AS_MEM_L2FREE_L3USED;
          }
          else if (m_memoryState == AS_MEM_L2USED_L3FREE)
          {
            m_memoryState = AS_MEM_L2USED_L3USED;
          }
        }
      }
    }

    if ((reqPort->u_sizeL2 > 0) && ((m_memoryState == AS_MEM_L2USED_L3FREE || m_memoryState == AS_MEM_L2USED_L3USED)))
    {
      // L2 memory already locked
      returnCode = AS_MEM_SCRATCH_L2_NOT_FREE;
    }
    else
    {
      // valid call
      if (reqPort->u_sizeL2 > 0)
      {
        /* check if requested size fits into L2 memory */
#ifdef _TMS320C6X
        if(reqPort->u_sizeL2 > L2_AVAILABLE_BUFFER_SIZE_BYTES)
#else
        if(reqPort->u_sizeL2 > L2_AVAILABLE_BUFFER_SIZE_BYTES_CORTEX_A8)
#endif
        {
          returnCode = AS_MEM_SCRATCH_ERR_L2_SIZE;
        }
        else
        {
#ifdef _TMS320C6X
          //DSP
          proPort->p_memL2  = (void *) L2_DSP_BASE_ADDR;
          proPort->u_sizeL2 = L2_AVAILABLE_BUFFER_SIZE_BYTES;
#else
          //CortexA8
          proPort->p_memL2  = (void *) L2_CORETEXA8_BASE_ADDR;       // location of L2 of CortexA8 is not known yet
          proPort->u_sizeL2 = L2_AVAILABLE_BUFFER_SIZE_BYTES_CORTEX_A8;
#endif

          // set mem state to L2 used
          if (m_memoryState == AS_MEM_L2FREE_L3FREE)
          {
            m_memoryState = AS_MEM_L2USED_L3FREE;
          }
          else if (m_memoryState == AS_MEM_L2FREE_L3USED)
          {
            m_memoryState = AS_MEM_L2USED_L3USED;
          }
        }
      }
    }
  }

  return returnCode;
}

AS_t_MemScratchReturnCode evm::as::CServiceTypes::memScratchUnlock(const uint32 u_compId, const uint32 u_memReqId)
{
  AS_t_MemScratchReturnCode returnCode = AS_MEM_SCRATCH_SRV_SUCCESS;

  if (u_compId == 0)
  {
    // invalid component ID
    returnCode = AS_MEM_SCRATCH_ERR_ID_NOT_IN_USE;
  }
  else
  {
    // at least input is ok, check further stuff
    if (m_memoryState == AS_MEM_L2FREE_L3FREE)
    {
      // memory not locked
      returnCode = AS_MEM_SCRATCH_ERR_ID_NOT_IN_USE;
    }
    else
    {
      // unlock memory
      m_memoryState = AS_MEM_L2FREE_L3FREE;
    }
  }

  return returnCode;
}


AS_t_MeasReturn evm::as::CServiceTypes::measHdlr (const AS_t_MeasInfo *p_MeasInfo, void *p_Buff, AS_t_MeasCallback pf_MeasCallback)
{
  return (MEAS_OK);
}


uint64 evm::as::CServiceTypes::GetTimestampuS64(void)
{
    Types_Timestamp64 ts;
    Types_FreqHz      freq;

    uint64 ui_ts;
    uint64 ui_freq;

    Timestamp_get64(&ts);
    Timestamp_getFreq(&freq);

    ui_ts   = (uint64)ts.hi   * (uint64)0x100000000 + (uint64)ts.lo;
    ui_freq = (uint64)freq.hi * (uint64)0x100000000 + (uint64)freq.lo;

    ui_freq = ui_freq / 1e6;  /* convert to MHz */

    return (ui_ts/ui_freq);
}

uint64 evm::as::CServiceTypes::GetCoreTicksuS64(void)
{
    Types_Timestamp64 ts;

    uint64 ui_ts;

    Timestamp_get64(&ts);

    ui_ts   = (uint64)ts.hi   * (uint64)0x100000000 + (uint64)ts.lo;
    return (ui_ts);
}

#ifdef _TMS320C6X
sint32 evm::as::CServiceTypes::EDMACopy (void *p_Dst, void *p_Src, sint32 s_SizeBytes, sint32 *p_ChIndexOut)
{
  ERROR_EDMA_CODE e_error = RETURN_NOERROR;
  evm::as::CServiceTypes* pc_Service = NULL;

  // Precondition check;
  if (0 == m_pv_EDMAService)  {

      e_error = RETURN_ERROR_EDMASERVICE;
      goto ERROR_EXIT;
  }

  // Set the pointer to handler;
  pc_Service = reinterpret_cast<evm::as::CServiceTypes*>(m_pv_EDMAService);

  // Wrap the 2D Trigger function
  e_error = (ERROR_EDMA_CODE)pc_Service->si_ConfigTrigger_EDMAChannel_2D(p_Dst, p_Src, 0, 0, s_SizeBytes, 1, p_ChIndexOut);

  if (RETURN_NOERROR != e_error)  {

      e_error = RETURN_ERROR_EDMA_CFGTRG_CHAIN;
      goto ERROR_EXIT;
  }

  return 0;

  ERROR_EXIT:

  REPORT_ERROR(e_error, pch_MODULE_NAME);
  return (sint32)e_error;
}

sint32 evm::as::CServiceTypes::EDMACopy2D (void *p_Dst, void *p_Src, sint32 s_DstPitch, sint32 s_SrcPitch, sint32 s_Width, sint32 s_Height, sint32 *p_ChIndexOut)
{
  ERROR_EDMA_CODE e_error = RETURN_NOERROR;

  evm::as::CServiceTypes* pc_Service = NULL;

  // Precondition check;
  if (0 == m_pv_EDMAService)  {

      e_error = RETURN_ERROR_EDMASERVICE;
      goto ERROR_EXIT;
  }

  // Set the pointer to handler;
  pc_Service = reinterpret_cast<evm::as::CServiceTypes*>(m_pv_EDMAService);

  // Call the trigger function for EDMA channel;
  e_error = (ERROR_EDMA_CODE)pc_Service->si_ConfigTrigger_EDMAChannel_2D(p_Dst, p_Src, s_DstPitch, s_SrcPitch, s_Width, s_Height, p_ChIndexOut);
  if (RETURN_NOERROR != e_error)  {

      e_error = RETURN_ERROR_EDMA_CFGTRG_2D;
      goto ERROR_EXIT;
  }

  return 0;

  ERROR_EXIT:

  REPORT_ERROR(e_error, pch_MODULE_NAME);
  return e_error;
}

sint32 evm::as::CServiceTypes::EDMACopyChained(void *p_PreDst, void *p_PreSrc, sint32 s_PreNumBytes, void *p_PostDst, void *p_PostSrc, sint32 s_PostNumBytes, sint32 *p_PostChIndexOut)
{
  ERROR_EDMA_CODE e_error = RETURN_NOERROR;

  evm::as::CServiceTypes* pc_Service = NULL;

  // Precondition check;
  if (0 == m_pv_EDMAService)  {

    e_error = RETURN_ERROR_EDMASERVICE;
    goto ERROR_EXIT;
  }

  // Set the pointer to handler;
  pc_Service = reinterpret_cast<evm::as::CServiceTypes*>(m_pv_EDMAService);

  // Call the trigger function for EDMA channel;
  e_error = (ERROR_EDMA_CODE)pc_Service->si_ConfigTrigger_EDMAChannel_Chained(p_PreDst, p_PreSrc, s_PreNumBytes, p_PostDst, p_PostSrc, s_PostNumBytes, p_PostChIndexOut);
  if (RETURN_NOERROR != e_error)  {

    e_error = RETURN_ERROR_EDMA_CFGTRG_2D;
    goto ERROR_EXIT;
  }

  return 0;

  ERROR_EXIT:

  REPORT_ERROR(e_error, pch_MODULE_NAME);
  return e_error;

}

sint32 evm::as::CServiceTypes::EDMAGet (AS_t_EdmaFlags Flags, AS_t_EdmaHandle *Regs)
{
   ERROR_EDMA_CODE e_error = RETURN_NOERROR;
   EDMA3_DRV_Result e_result = EDMA3_DRV_SOK;

   sint32 si_Ind = 0;
   bool b_Find = b_FALSE;
   EDMA3_DRV_Instance *drvInst = NULL;
   EDMA3_DRV_Object *drvObject = NULL;
   volatile EDMA3_CCRL_Regs *globalRegs = NULL;
   volatile EDMA3_CCRL_ShadowRegs *shadowRegs = NULL;
   uint32 PaAddr = 0, Version_Id;
   uint32 tccNo, lCH;

   drvInst = (EDMA3_DRV_Instance *) p_edmaHandle;
   drvObject = drvInst->pDrvObjectHandle;


   Version_Id = EDMA3_DRV_getVersion ();

   for (si_Ind = 0; si_Ind < si_MAX_NUM_EDMACHANNELS; si_Ind++)
   {
      if (b_TRUE == m_ab_FreeEDMAChannels[si_Ind])
      {
         // Free channel found in array;
         b_Find = b_TRUE;

         // Channel shall be used;
         m_ab_FreeEDMAChannels[si_Ind] = b_FALSE;

         // Leave the loop;
         break;
      }
   }

   // Postcondition check;
   if (b_FALSE == b_Find)
   {
      e_error = RETURN_ERROR_FREECHANNEL;
      goto ERROR_EXIT;
   }

   Regs->Flags = 0;
   Regs->ChIndex     = si_Ind;
   lCH   = Regs->lCh = m_aui_EDMAChannelIDs[si_Ind];
   tccNo = Regs->TCC = m_aui_EDMAChannelTCC[si_Ind];

   e_result = EDMA3_DRV_clearErrorBits(m_pv_EDMAHandle, lCH);

   if (EDMA3_DRV_SOK != e_result)
   {
     e_error = RETURN_ERROR_EDMA;
     goto ERROR_EXIT;
   }

   EDMA3_DRV_getPaRAMPhyAddr(m_pv_EDMAHandle, lCH, &PaAddr);

   Regs->PaRAMEntry = (EDMASRC_CSL_EdmaccParamentryRegs *) PaAddr;

   if (lCH < 32u)
   {
      Regs->shadowRegs_ESR = (volatile uint32 *) &drvInst->shadowRegs->ESR;
      Regs->TriggerMask = (1UL << lCH);
   }
   else
   {
      Regs->shadowRegs_ESR = (volatile uint32 *) &drvInst->shadowRegs->ESRH;
      Regs->TriggerMask = (1UL << (lCH-32u));
   }

   globalRegs = (volatile EDMA3_CCRL_Regs *)(drvObject->gblCfgParams.globalRegs);
   shadowRegs = (volatile EDMA3_CCRL_ShadowRegs *)(&globalRegs->SHADOW[drvInst->regionId]);

   if(tccNo < 32u)
   {
      Regs->WaitMask       = (1u << tccNo);
      Regs->shadowRegs_IPR = (volatile uint32 *) &shadowRegs->IPR;
      Regs->shadowRegs_ICR = (volatile uint32 *) &shadowRegs->ICR;
   }
   else
   {
      Regs->WaitMask       = (1u << (tccNo - 32u));
      Regs->shadowRegs_IPR = (volatile uint32 *) &shadowRegs->IPRH;
      Regs->shadowRegs_ICR = (volatile uint32 *) &shadowRegs->ICRH;
   }

   return RETURN_NOERROR;
ERROR_EXIT:
/* Clear for error handling */
   std::memset(Regs, 0, sizeof(*Regs));
   Regs->ChIndex = -1;

   REPORT_ERROR(e_error, pch_MODULE_NAME);
   return e_error;
}

sint32 evm::as::CServiceTypes::EDMARelease (AS_t_EdmaHandle *Regs)
{
   uint16 puw_Status = 0;
   ERROR_EDMA_CODE e_error = RETURN_NOERROR;
   sint32 ChIndex = Regs->ChIndex;

   // Test if channel was in use
   if (m_ab_FreeEDMAChannels[ChIndex] == b_TRUE)
   {
     e_error = RETURN_ERROR_EDMA_HANDLE;
     goto ERROR_EXIT;
   }

   EDMA3_DRV_checkAndClearTcc(m_pv_EDMAHandle, m_aui_EDMAChannelTCC[ChIndex], &puw_Status);

   // Free the channel;
   m_ab_FreeEDMAChannels[ChIndex] = b_TRUE;

   return RETURN_NOERROR;

ERROR_EXIT:
    REPORT_ERROR(e_error, pch_MODULE_NAME);
    return e_error;
}


sint32 evm::as::CServiceTypes::s_EDMAGet (AS_t_EdmaFlags Flags, AS_t_EdmaHandle *Regs)
{
  return evm::as::CServiceTypes::getInstance().EDMAGet (Flags, Regs);
}

sint32 evm::as::CServiceTypes::s_EDMARelease (AS_t_EdmaHandle *Regs)
{
  return evm::as::CServiceTypes::getInstance().EDMARelease (Regs);
}

uint32 evm::as::CServiceTypes::EDMATranslateAddress(uint32 Address)
{
   void *pIn, *pOut;
   pIn = (void *) Address;
   pOut = pv_getGlobalAddr(pIn);
   return  (uint32)pOut;
}

uint32 evm::as::CServiceTypes::s_EDMATranslateAddress(uint32 Address)
{
   return evm::as::CServiceTypes::getInstance().EDMATranslateAddress(Address);
}

#if 0
sint32 evm::as::CServiceTypes::s_EDMASetTriggerWord (sint32 ChIndex, uint32 TriggWord)
{
  return evm::as::CServiceTypes::getInstance().EDMASetTriggerWord (ChIndex, TriggWord);
}
#endif

sint32 evm::as::CServiceTypes::EDMAWait(sint32 s_ChIndex)
{
  ERROR_EDMA_CODE e_error = RETURN_NOERROR;

  evm::as::CServiceTypes* pc_Service = 0;

  // Precondition check;
  if (0 == m_pv_EDMAService)  {

      e_error = RETURN_ERROR_EDMASERVICE;
      goto ERROR_EXIT;
  }

  // Set the pointer to handler;
  pc_Service = reinterpret_cast<evm::as::CServiceTypes*>(m_pv_EDMAService);

  // Call the wait function for EDMA channel;
  e_error = (ERROR_EDMA_CODE) pc_Service->si_Wait_EDMAChannel(s_ChIndex);
  if (RETURN_NOERROR != e_error)  {

      e_error = RETURN_ERROR_EDMA_WAIT;
      goto ERROR_EXIT;
  }

  return 0;

  ERROR_EXIT:

  REPORT_ERROR(e_error, pch_MODULE_NAME);
  return e_error;
}
#endif


void evm::as::CServiceTypes::InitEvmService_Eve(AS_t_EVEContainer* pEVEContainer, void* pParamBuf, volatile sint32* pFlag_RunEVE, volatile sint32* pEVEReturnValue)
{
  m_pEVEContainer = pEVEContainer;
  m_pParamBuff    = pParamBuf;
  m_pFlag_RunEVE  = pFlag_RunEVE;
  m_pEVEReturnValue = pEVEReturnValue;
}

uint32 evm::as::CServiceTypes::EveTrigger(const AS_t_EVEContainer *p_Container, sint32 *p_Handle, uint32 u_ComponentId)
{
  assert(m_pParamBuff != 0);    // EveInitEvmService() has to be called in C674x-wrapper, before EveTrigger can be used!
  assert(m_pEVEContainer != 0); // EveInitEvmService() has to be called in C674x-wrapper, before EveTrigger can be used!
  assert(m_pFlag_RunEVE != 0);  // EveInitEvmService() has to be called in C674x-wrapper, before EveTrigger can be used!
  assert(p_Handle);             //EveTrigger has to return a handle that is used for EveWait

  //generate a random EVE request handle
  m_sEVERequestHandle=std::rand();
  if(p_Handle){*p_Handle=m_sEVERequestHandle;}

  std::memcpy(m_pParamBuff, p_Container->eveParams.parBuf.p_Buff, p_Container->eveParams.parBuf.u_BuffLength);
  std::memcpy(m_pEVEContainer, p_Container, sizeof(AS_t_EVEContainer));
  m_pEVEContainer->eveParams.parBuf.p_Buff = m_pParamBuff;

  //write back memory for eve
  s_CacheWbInv(m_pParamBuff, s_CeilSizeToNextCacheLine(p_Container->eveParams.parBuf.u_BuffLength)); // needed, to avoid possible race-condition, when Flag_RunDSP would be written back, first, before the actual shared data is written back
  s_CacheWbInv(m_pEVEContainer, s_CeilSizeToNextCacheLine(sizeof(AS_t_EVEContainer))); // needed, to avoid possible race-condition, when Flag_RunDSP would be written back, first, before the actual shared data is written back

  *m_pFlag_RunEVE = 1;

  //write back the trigger flag
  s_CacheWbInv((void *)m_pFlag_RunEVE, s_CeilSizeToNextCacheLine(sizeof(*m_pFlag_RunEVE)));
  return 0;
}


uint32 evm::as::CServiceTypes::EveWait(sint32 u_Handle, sint32 *p_EveLibReturnCode)
{
  if(p_EveLibReturnCode!=NULL)
  {
    *p_EveLibReturnCode=0;
  }
  assert(u_Handle==m_sEVERequestHandle);        //check if the handle is corresponding to the EveTrigger handle
  assert(m_pFlag_RunEVE != 0);      // EveInitEvmService() has to be called in C674x-wrapper, before EveTrigger can be used!
  assert(p_EveLibReturnCode != 0);  // You have to provide a valid address for the return code parameter
  assert(m_pEVEReturnValue != 0);   // EveInitEvmService() has to be called in C674x-wrapper, before EveTrigger can be used!
  while (1 == *m_pFlag_RunEVE) {
    s_CacheInv((void*)m_pFlag_RunEVE   , s_CeilSizeToNextCacheLine(sizeof(*m_pFlag_RunEVE)));
  }
  if (0 != m_pEVEReturnValue)
  {
    s_CacheInv((void*)m_pEVEReturnValue, s_CeilSizeToNextCacheLine(sizeof(*m_pEVEReturnValue)));
    *p_EveLibReturnCode = *m_pEVEReturnValue;
  }
  return 0;
}

//////////////////////////////////
// Static functions:
//////////////////////////////////

sint32 evm::as::CServiceTypes::s_memLock( void ** p_L2Buffer,
    sint32 * p_L2BuffSize,
    void ** p_L3Buffer,
    sint32 * p_L3BuffSize,
    AS_t_MemState * p_State,
    AS_t_MemWaitCondition WaitCondition )
{
  //wait condition is ignored on the evm
  return evm::as::CServiceTypes::getInstance().memLock(p_L2Buffer, p_L2BuffSize, p_L3Buffer, p_L3BuffSize, p_State);
}
sint32 evm::as::CServiceTypes::s_memLockL2( void ** p_L2Buffer,
    sint32 * p_L2BuffSize,
    AS_t_MemState * p_State,
    AS_t_MemWaitCondition WaitCondition )
{
  sint32 ret;

  if ((AS_MEM_L2WAIT == WaitCondition) || (AS_MEM_L2NOWAIT == WaitCondition))
  {
    //wait condition is ignored on the evm
    ret = evm::as::CServiceTypes::getInstance().memLockL2(p_L2Buffer, p_L2BuffSize, p_State);
  }
  else
  {
    ret = RETURN_ERROR_INPUT;
  }

  return ret;
}
sint32 evm::as::CServiceTypes::s_memLockL3( void ** p_L3Buffer,
    sint32 * p_L3BuffSize,
    AS_t_MemState * p_State,
    AS_t_MemWaitCondition WaitCondition )
{
  sint32 ret;

  if ((AS_MEM_L3WAIT == WaitCondition) || (AS_MEM_L3NOWAIT == WaitCondition))
  {
    //wait condition is ignored on the evm
    ret = evm::as::CServiceTypes::getInstance().memLockL3(p_L3Buffer, p_L3BuffSize, p_State);
  }
  else
  {
    ret = RETURN_ERROR_INPUT;
  }

  return ret;
}

sint32 evm::as::CServiceTypes::s_memUnlock (AS_t_MemState * p_State)
{
  return evm::as::CServiceTypes::getInstance().memUnlock(p_State);
}
sint32 evm::as::CServiceTypes::s_memUnlockL2 (AS_t_MemState * p_State)
{
  return evm::as::CServiceTypes::getInstance().memUnlockL2(p_State);
}
sint32 evm::as::CServiceTypes::s_memUnlockL3 (AS_t_MemState * p_State)
{
  return evm::as::CServiceTypes::getInstance().memUnlockL3(p_State);
}

AS_t_MemScratchReturnCode  evm::as::CServiceTypes::s_memScratchLock (const AS_t_MemScratchReqPort * const reqPort, AS_t_MemScratchProPort * const proPort)
{
  return evm::as::CServiceTypes::getInstance().memScratchLock(reqPort, proPort);
}

AS_t_MemScratchReturnCode  evm::as::CServiceTypes::s_memScratchUnlock (const uint32 u_compId, const uint32 u_memReqId)
{
  return evm::as::CServiceTypes::getInstance().memScratchUnlock(u_compId, u_memReqId);
}

AS_t_MeasReturn evm::as::CServiceTypes::s_measHdlr( const AS_t_MeasInfo *p_MeasInfo, void *p_Buff, AS_t_MeasCallback pf_MeasCallback )
{
  return evm::as::CServiceTypes::getInstance().measHdlr(p_MeasInfo, p_Buff, pf_MeasCallback);
}
AS_t_MeasErrors evm::as::CServiceTypes::s_MeasStartFuncCycle(const AS_t_MeasFuncID)
{
  // Dummy implementation on EVM => don't do anything!
  return e_MEAS_OK;
}

uint64 evm::as::CServiceTypes::s_GetTimestampuS64(void)
{
  return evm::as::CServiceTypes::getInstance().GetTimestampuS64();
}

uint32 evm::as::CServiceTypes::s_GetTimestampuS32(void)
{
  uint64 time64bit = evm::as::CServiceTypes::getInstance().GetTimestampuS64();
  uint32 time32bit = static_cast<uint32>(time64bit);
  return time32bit;
}

uint64 evm::as::CServiceTypes::s_GetCoreTicksuS64(void)
{
  return evm::as::CServiceTypes::getInstance().GetCoreTicksuS64();
}
#ifdef _TMS320C6X
sint32 evm::as::CServiceTypes::s_EDMACopy(void *p_Dst, void *p_Src, sint32 s_SizeBytes, sint32 *p_ChIndexOut)
{
  return evm::as::CServiceTypes::getInstance().EDMACopy(p_Dst, p_Src, s_SizeBytes, p_ChIndexOut);
}
sint32 evm::as::CServiceTypes::s_EDMACopy2D(void *p_Dst, void *p_Src, sint32 s_DstPitch, sint32 s_SrcPitch, sint32 s_Width, sint32 s_Height, sint32 *p_ChIndexOut)
{
  return evm::as::CServiceTypes::getInstance().EDMACopy2D(p_Dst, p_Src, s_DstPitch, s_SrcPitch, s_Width, s_Height, p_ChIndexOut);
}

sint32 evm::as::CServiceTypes::s_EDMACopyChained(void *p_PreDst, void *p_PreSrc, sint32 s_PreNumBytes, void *p_PostDst, void *p_PostSrc, sint32 s_PostNumBytes, sint32 *p_PostChIndexOut)
{
  return evm::as::CServiceTypes::getInstance().EDMACopyChained(p_PreDst, p_PreSrc, s_PreNumBytes, p_PostDst, p_PostSrc, s_PostNumBytes, p_PostChIndexOut);
}

sint32 evm::as::CServiceTypes::s_EDMAWait(sint32 s_ChIndex)
{
  return evm::as::CServiceTypes::getInstance().EDMAWait(s_ChIndex);
}
#endif
void* evm::as::CServiceTypes::pv_getGlobalAddr(void *addr)
{
   unsigned long h = (unsigned long) addr;

   if ((h & 0xFFF00000) == 0x10800000)
   {
     h = (h & 0x0FFFFFFF) | 0x40000000;
   }

   addr = (void *) h;
   return addr;
}
#ifdef _TMS320C6X
sint32 evm::as::CServiceTypes::si_EDMA_Init()
{
  ERROR_EDMA_CODE e_error = RETURN_NOERROR;
  sint32 si_Ind = 0;
  uint32 ui_TCC = 0u;
  EDMA3_DRV_Result si_EDMA_Ret = EDMA3_DRV_SOK;

  // Precondition check;
  if (0 == p_edmaHandle)  {
      e_error = RETURN_ERROR_EDMA_HANDLE;
      goto ERROR_EXIT;
  }

  // Setup handle for EDMA;
  m_pv_EDMAHandle = (void *)p_edmaHandle;

  // Allocate channels for EDMA processing;
  for (si_Ind = 0; si_Ind < si_MAX_NUM_EDMACHANNELS; si_Ind++)  {
      // Take any TCC;
      ui_TCC = EDMA3_DRV_TCC_ANY;

#ifdef QDMA
      // Take any free empty channel;
      m_aui_EDMAChannelIDs[si_Ind] = EDMA3_DRV_QDMA_CHANNEL_ANY;
#else
      // Take any free empty channel;
      m_aui_EDMAChannelIDs[si_Ind] = EDMA3_DRV_DMA_CHANNEL_ANY;
#endif    
      // Request the EDMA channel;
      si_EDMA_Ret = EDMA3_DRV_requestChannel(m_pv_EDMAHandle,
          &m_aui_EDMAChannelIDs[si_Ind],
          &ui_TCC, 0u,
          reinterpret_cast<EDMA3_RM_TccCallback>(0),
          reinterpret_cast<void*>(0));
      m_aui_EDMAChannelTCC[si_Ind] = ui_TCC;

      if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

          e_error = RETURN_ERROR_CHANNELREQUEST;
          goto ERROR_EXIT;
      }
#ifdef QDMA
      EDMA3_DRV_setQdmaTrigWord (m_pv_EDMAHandle, m_aui_EDMAChannelIDs[si_Ind], EDMA3_RM_QDMA_TRIG_CCNT);
#endif
  }

  // Assign service this pointer;
  m_pv_EDMAService = reinterpret_cast<void*>(this);

  return RETURN_NOERROR;

  ERROR_EXIT:

  REPORT_ERROR(e_error, pch_MODULE_NAME);
  return e_error;

}

sint32 evm::as::CServiceTypes::si_ConfigTrigger_EDMAChannel_2D(void* pv_DstBuffer, void* pv_SrcBuffer, sint32 si_DstPitch, sint32 si_SrcPitch, sint32 si_Width, sint32 si_Height, sint32* psi_ChannelIndex)
{
  ERROR_EDMA_CODE e_error = RETURN_NOERROR;
  sint32 si_Ind = 0;

  EDMA3_DRV_PaRAMRegs paramSet = {0,0,0,0,0,0,0,0,0,0,0,0,0};

  bool b_Find = b_FALSE;

  EDMA3_DRV_Result si_EDMA_Ret = EDMA3_DRV_SOK;
  void *pDstGlob, *pSrcGlob;

  pDstGlob = pv_getGlobalAddr(pv_DstBuffer);
  pSrcGlob = pv_getGlobalAddr(pv_SrcBuffer);

  // Precondition checks;

  if (0 == m_pv_EDMAHandle)  {

      e_error = RETURN_ERROR_EDMA_HANDLE;
      goto ERROR_EXIT;
  }

  if (0 == pDstGlob)  {

      e_error = RETURN_ERROR_DSTBUFFER;
      goto ERROR_EXIT;
  }

  if (0 == pSrcGlob)  {

      e_error = RETURN_ERROR_SRCBUFFER;
      goto ERROR_EXIT;
  }

  if (0 == psi_ChannelIndex)  {

      e_error = RETURN_ERROR_CHANNELINDEX;
      goto ERROR_EXIT;
  }

  if ((si_DstPitch < EDMA_BC_INDEX_MIN) || (si_DstPitch > EDMA_BC_INDEX_MAX)) {

      e_error = RETURN_ERROR_EDMA_DSTIND;
      goto ERROR_EXIT;
  }

  if ((si_SrcPitch < EDMA_BC_INDEX_MIN) || (si_SrcPitch > EDMA_BC_INDEX_MAX)) {

      e_error = RETURN_ERROR_EDMA_SRCIND;
      goto ERROR_EXIT;
  }

  if ((si_Width < EDMA_AB_COUNT_MIN) || (si_Width > EDMA_AB_COUNT_MAX)) {

      e_error = RETURN_ERROR_EDMA_SRCPARAM;
      goto ERROR_EXIT;
  }

  if ((si_Height < EDMA_AB_COUNT_MIN) || (si_Height > EDMA_AB_COUNT_MAX)) {

      e_error = RETURN_ERROR_EDMA_SRCPARAM;
      goto ERROR_EXIT;
  }

  if (DSP_L2_RAM_BASE_L3 == ((uint32) pv_DstBuffer & DSP_L2_RAM_MASK))
  {
    if ((0 != ((uint32) pv_DstBuffer & EDMA_DST_ALIGN_MASK)) || (0 != (si_DstPitch & EDMA_DST_ALIGN_MASK)))
    {
      e_error = RETURN_ERROR_EDMA_DSTPARAM;
      goto ERROR_EXIT;
    }
  }

  // Setup number of bytes in array;
  paramSet.aCnt = static_cast<uint32>(si_Width);

  // Setup number of arrays in frame;
  paramSet.bCnt = static_cast<uint32>(si_Height);

  // Setup number of frames in transfer;
  paramSet.cCnt = 1u;

  // Setup reload value for BCNT;
  paramSet.bCntReload = static_cast<uint32>(si_Height);

  // Source offset between arrays within frame in bytes;
  paramSet.srcBIdx = si_SrcPitch;

  // Source offset between frames within block in bytes;
  paramSet.srcCIdx = 0;

  // Destination offset between arrays within frame in bytes;
  paramSet.destBIdx = si_DstPitch;

  // Destination offset between frames within block in bytes;
  paramSet.destCIdx = 0;

  // Find free channel in array;
  for (si_Ind = 0; si_Ind < si_MAX_NUM_EDMACHANNELS; si_Ind++)  {

      if (b_TRUE == m_ab_FreeEDMAChannels[si_Ind])  {

          // Free channel found in array;
          b_Find = b_TRUE;

          // Channel shall be used;
          m_ab_FreeEDMAChannels[si_Ind] = b_FALSE;

          // Leave the loop;
          break;
      }
  }

  // Postcondition check;
  if (b_FALSE == b_Find)  {

      e_error = RETURN_ERROR_FREECHANNEL;
      goto ERROR_EXIT;
  }

  // Assign index value;
  *psi_ChannelIndex = si_Ind;

  // Clear previous errors if they were;
  si_EDMA_Ret = EDMA3_DRV_clearErrorBits(m_pv_EDMAHandle,
      m_aui_EDMAChannelIDs[si_Ind]);
  if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

      e_error = RETURN_ERROR_EDMA_ERRORBIT;
      goto ERROR_EXIT;
  }

  paramSet.srcAddr    = (unsigned int)pSrcGlob;
  paramSet.destAddr   = (unsigned int)pDstGlob;

  // No Linking
  paramSet.linkAddr   = 0xFFFFu;

  // Disable all options by default
  paramSet.opt = 0;

  // Program the TCC
  paramSet.opt |= EDMA3_DRV_OPT_TCC_SET_MASK(m_aui_EDMAChannelTCC[si_Ind]);

  // Enable Final transfer completion interrupt
  paramSet.opt |= EDMA3_DRV_OPT_TCINTEN_SET_MASK(1u);

  // AB-synchronized transfer
  paramSet.opt |= EDMA3_DRV_OPT_SYNCDIM_SET_MASK(1u);

  EDMA3_DRV_setPaRAM (m_pv_EDMAHandle, m_aui_EDMAChannelIDs[si_Ind], &paramSet);

#ifndef QDMA
  // Trigger the transfer;
  si_EDMA_Ret = EDMA3_DRV_enableTransfer(m_pv_EDMAHandle,
      m_aui_EDMAChannelIDs[si_Ind],
      EDMA3_DRV_TRIG_MODE_MANUAL);
  if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

      e_error = RETURN_ERROR_EDMA_ENABLE;
      goto ERROR_EXIT;
  }
#endif
  return RETURN_NOERROR;

  ERROR_EXIT:

  REPORT_ERROR(e_error, pch_MODULE_NAME);
  return e_error;

}

sint32 evm::as::CServiceTypes::si_ConfigTrigger_EDMAChannel_Chained(void *pv_PreDstBuffer, void *pv_PreSrcBuffer, sint32 s_PreNumBytes, void *pv_PostDstBuffer, void *pv_PostSrcBuffer, sint32 s_PostNumBytes, sint32 *psi_PostChIndexOut)
{
  ERROR_EDMA_CODE e_error = RETURN_NOERROR;
  EDMA3_DRV_PaRAMRegs paramSet = {0,0,0,0,0,0,0,0,0,0,0,0};

  bool b_Find = b_FALSE;
  sint32 si_Ind = 0;
  sint32 si_PreInd = 0;

  EDMA3_DRV_Result si_EDMA_Ret = EDMA3_DRV_SOK;
  void *pPreDstGlob, *pPreSrcGlob;
  void *pPostDstGlob, *pPostSrcGlob;

  pPreDstGlob = pv_getGlobalAddr(pv_PreDstBuffer);
  pPreSrcGlob = pv_getGlobalAddr(pv_PreSrcBuffer);
  pPostDstGlob = pv_getGlobalAddr(pv_PostDstBuffer);
  pPostSrcGlob = pv_getGlobalAddr(pv_PostSrcBuffer);
  // Precondition checks;

  if (0 == m_pv_EDMAHandle)  {

      e_error = RETURN_ERROR_EDMA_HANDLE;
      goto ERROR_EXIT;
  }

  if (0 == pPreDstGlob)  {

      e_error = RETURN_ERROR_DSTBUFFER;
      goto ERROR_EXIT;
  }

  if (0 == pPreSrcGlob)  {

      e_error = RETURN_ERROR_SRCBUFFER;
      goto ERROR_EXIT;
  }

  if (0 == pPostDstGlob)  {

     e_error = RETURN_ERROR_DSTBUFFER;
      goto ERROR_EXIT;
  }

   if (0 == pPostSrcGlob)  {

     e_error = RETURN_ERROR_SRCBUFFER;
     goto ERROR_EXIT;
   }

  if (0 == psi_PostChIndexOut)  {

    e_error = RETURN_ERROR_CHANNELINDEX;
    goto ERROR_EXIT;
  }

  if ((s_PreNumBytes < EDMA_AB_COUNT_MIN) || (s_PreNumBytes > EDMA_AB_COUNT_MAX)) {

      e_error = RETURN_ERROR_EDMA_SRCPARAM;
      goto ERROR_EXIT;
  }

  if ((s_PostNumBytes < EDMA_AB_COUNT_MIN) || (s_PostNumBytes > EDMA_AB_COUNT_MAX)) {

      e_error = RETURN_ERROR_EDMA_SRCPARAM;
      goto ERROR_EXIT;
  }

  if (DSP_L2_RAM_BASE_L3 == ((uint32) pv_PreDstBuffer & DSP_L2_RAM_MASK))
  {
    if (0 != ((uint32) pv_PreDstBuffer & EDMA_DST_ALIGN_MASK))
    {
      e_error = RETURN_ERROR_EDMA_DSTPARAM;
      goto ERROR_EXIT;
    }
  }

  if (DSP_L2_RAM_BASE_L3 == ((uint32) pv_PostDstBuffer & DSP_L2_RAM_MASK))
  {
    if (0 != ((uint32) pv_PostDstBuffer & EDMA_DST_ALIGN_MASK))
    {
      e_error = RETURN_ERROR_EDMA_DSTPARAM;
      goto ERROR_EXIT;
    }
  }

  // Find free channel for Pre transfer;
  for (si_PreInd = 0; si_PreInd < si_MAX_NUM_EDMACHANNELS; si_PreInd++)  {

    if (b_TRUE == m_ab_FreeEDMAChannels[si_PreInd])  {

      // Free channel found in array;
      b_Find = b_TRUE;

      // Channel shall be used;
      m_ab_FreeEDMAChannels[si_PreInd] = b_FALSE;

      // Leave the loop;
      break;
    }
  }

  // Postcondition check;
  if (b_FALSE == b_Find)  {

    e_error = RETURN_ERROR_FREECHANNEL;
    goto ERROR_EXIT;
  }

  b_Find = b_FALSE;

  // Find free channel for Post transfer;
  for (si_Ind = (si_PreInd+1); si_Ind < si_MAX_NUM_EDMACHANNELS; si_Ind++)  {

      if (b_TRUE == m_ab_FreeEDMAChannels[si_Ind])  {

          // Free channel found in array;
          b_Find = b_TRUE;

          // Channel shall be used;
          m_ab_FreeEDMAChannels[si_Ind] = b_FALSE;

          // Leave the loop;
          break;
      }
  }

  // Postcondition check;
  if (b_FALSE == b_Find)  {
    //free already locked pre channel
    m_ab_FreeEDMAChannels[si_PreInd] = b_TRUE;
      e_error = RETURN_ERROR_FREECHANNEL;
      goto ERROR_EXIT;
  }

  // Assign index value;
  *psi_PostChIndexOut = si_Ind;

  m_asi_ChainedChannelIndexes[si_Ind] = si_PreInd;

  // Configure parameters common to both transfers
  // Setup number of arrays in frame;
  paramSet.bCnt = 1u;

  // Setup number of frames in transfer;
  paramSet.cCnt = 1u;

  // Setup reload value for BCNT;
  paramSet.bCntReload = 1u;

  // Source offset between arrays within frame in bytes;
  paramSet.srcBIdx = 0;

  // Source offset between frames within block in bytes;
  paramSet.srcCIdx =  0;

  // Destination offset between arrays within frame in bytes;
  paramSet.destBIdx = 0;

  // Destination offset between frames within block in bytes;
  paramSet.destCIdx = 0;

  // No linking
  paramSet.linkAddr   = 0xFFFFu;

  // Disable all options by default
  paramSet.opt = 0;

  // Configure Pre transfer
  // Clear previous errors if they were;
  si_EDMA_Ret = EDMA3_DRV_clearErrorBits(m_pv_EDMAHandle,
      m_aui_EDMAChannelIDs[si_PreInd]);
  if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

    e_error = RETURN_ERROR_EDMA_ERRORBIT;
      goto ERROR_EXIT;
  }

  // Setup number of bytes in array;
  paramSet.aCnt = static_cast<uint32>(s_PreNumBytes);

  // Src and Dst addresses
  paramSet.srcAddr    = (unsigned int)pPreSrcGlob;
  paramSet.destAddr   = (unsigned int)pPreDstGlob;

  // Program the TCC as the Post transfer
  paramSet.opt |= EDMA3_DRV_OPT_TCC_SET_MASK(m_aui_EDMAChannelIDs[si_Ind]);

  // Enable final transfer completion chaining
  paramSet.opt |= EDMA3_DRV_OPT_TCCHEN_SET_MASK(1u);

  EDMA3_DRV_setPaRAM (m_pv_EDMAHandle, m_aui_EDMAChannelIDs[si_PreInd], &paramSet);

  // Configure Post transfer
  // Clear previous errors if they were;
  si_EDMA_Ret = EDMA3_DRV_clearErrorBits(m_pv_EDMAHandle,
      m_aui_EDMAChannelIDs[si_Ind]);
  if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

    e_error = RETURN_ERROR_EDMA_ERRORBIT;
      goto ERROR_EXIT;
  }

  // Setup number of bytes in array;
  paramSet.aCnt = static_cast<uint32>(s_PostNumBytes);

  // Src and Dst addresses
  paramSet.srcAddr    = (unsigned int)pPostSrcGlob;
  paramSet.destAddr   = (unsigned int)pPostDstGlob;

  // TCC should already be set to correct transfer
  // We do not program TCC here

  // Disable final transfer completion chaining
  paramSet.opt &= EDMA3_DRV_OPT_TCCHEN_CLR_MASK;

  // Enable final transfer completion interrupt
  paramSet.opt |= EDMA3_DRV_OPT_TCINTEN_SET_MASK(1u);

  EDMA3_DRV_setPaRAM (m_pv_EDMAHandle, m_aui_EDMAChannelIDs[si_Ind], &paramSet);

#ifndef QDMA
  // Trigger the transfer;
  si_EDMA_Ret = EDMA3_DRV_enableTransfer(m_pv_EDMAHandle,
      m_aui_EDMAChannelIDs[si_PreInd],
      EDMA3_DRV_TRIG_MODE_MANUAL);
  if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

      e_error = RETURN_ERROR_EDMA_ENABLE;
      goto ERROR_EXIT;
  }
#endif
  return RETURN_NOERROR;

  ERROR_EXIT:

  REPORT_ERROR(e_error, pch_MODULE_NAME);
  return e_error;

}

sint32 evm::as::CServiceTypes::si_Wait_EDMAChannel(sint32 si_Index)
{
  ERROR_EDMA_CODE e_error = RETURN_NOERROR, si_PreIndex = RETURN_INDEX_NOCHAINING;

  uint16 *puw_Status = 0;
  uint16 auw_Status[1];
  uint32 uw_TransferNotFinished = (uint32) 0;

  EDMA3_DRV_Result si_EDMA_Ret = EDMA3_DRV_SOK;

  // Precondition check;
  if (0 == m_pv_EDMAHandle)  {

      e_error = RETURN_ERROR_EDMA_HANDLE;
      goto ERROR_EXIT;
  }

  // Channel in use check
  if (this->m_ab_FreeEDMAChannels[si_Index] == 1)
    {
      e_error = RETURN_ERROR_EDMA_HANDLE;
      goto ERROR_EXIT;
    }

  // Initialize buffer;
  auw_Status[0] = uw_TransferNotFinished;

  // Create indirection;
  puw_Status = &auw_Status[0];

  // Check if there was chaining;
  if (RETURN_INDEX_NOCHAINING == m_asi_ChainedChannelIndexes[si_Index])  {

      // As long as status not finished;
      while (uw_TransferNotFinished == *puw_Status)  {

          // Check the status of TCC;
          si_EDMA_Ret = EDMA3_DRV_checkAndClearTcc(m_pv_EDMAHandle,
              m_aui_EDMAChannelTCC /*m_aui_EDMAChannelIDs*/[si_Index],
              puw_Status);
          if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

              e_error = RETURN_ERROR_CHECKTCC;
              goto ERROR_EXIT;
          }
      }

      // Free the channel;
      m_ab_FreeEDMAChannels[si_Index] = b_TRUE;
  }
  else  {

      // As long as status not finished;
      while (uw_TransferNotFinished == *puw_Status)  {

          // Check the status of TCC;
          si_EDMA_Ret = EDMA3_DRV_checkAndClearTcc(m_pv_EDMAHandle,
              m_aui_EDMAChannelTCC /*m_aui_EDMAChannelIDs*/[si_Index],
              puw_Status);
          if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

              e_error = RETURN_ERROR_CHECKTCC;
              goto ERROR_EXIT;
          }
      }

      // Find index of pre edma;
      si_PreIndex = (ERROR_EDMA_CODE) m_asi_ChainedChannelIndexes[si_Index];

      // Free the channel;
      m_ab_FreeEDMAChannels[si_PreIndex] = b_TRUE;

      // Free the channel;
      m_ab_FreeEDMAChannels[si_Index] = b_TRUE;

      // Chaining finished;
      m_asi_ChainedChannelIndexes[si_Index] = RETURN_INDEX_NOCHAINING;

      // Unchain the channel, delete content of TCC field;
      si_EDMA_Ret = EDMA3_DRV_unchainChannel(m_pv_EDMAHandle,
          m_aui_EDMAChannelIDs[si_PreIndex]);
      if (EDMA3_DRV_SOK != si_EDMA_Ret)  {

          e_error = RETURN_ERROR_CHECKTCC;
          goto ERROR_EXIT;
      }
  }

  return RETURN_NOERROR;

  ERROR_EXIT:

  REPORT_ERROR(e_error, pch_MODULE_NAME);
  return e_error;
}
#endif
void evm::as::CServiceTypes::s_CacheWbInv (void *p_MemLoc, uint32 u_NumBytes)
{
  /* SPRUG82A - 2.4.3 Usage Guidelines for L2 Cache Coherence Operations:
   * It is important to note that although a start address and a byte count is specified,
   * the cache controller operates always on whole lines. Therefore, for the purpose of
   * maintaining coherence, arrays must be:
   * � a multiple of L2 cache lines large
   * � aligned at an L2 cache line boundary
   */
  assert((uintptr_t)p_MemLoc % L2_CACHE_LINE_SIZE == 0);        //start address must be aligned
  assert(         u_NumBytes % L2_CACHE_LINE_SIZE == 0);        //size must be multiple of cache line size

  /* 04_Engineering/02_Development_Tools/ti_tools/bios/packages/ti/sysbios/family/c64p/Cache.c:
   * Writes back and invalidates the range of memory within the specified starting
   * address and byte count. The range of addresses operated on gets quantized to
   * whole cache lines in each cache. All lines within the range are written back
   * to the source memory and then invalidated for all 'type' caches
   */
  Cache_wbInv((Ptr)p_MemLoc, (SizeT) u_NumBytes, Cache_Type_ALL, true);

}
void evm::as::CServiceTypes::s_CacheWbInvAll (void)
{
  /* 04_Engineering/02_Development_Tools/ti_tools/bios/packages/ti/sysbios/family/c64p/Cache.c:
   * Performs a global write back and invalidate. All cache lines are invalidated
   * in L1P cache. All cache lines are written back to L2 or external and then
   * invalidated in L1D cache. All cache lines are written back to external and
   * then invalidated in L2 cache.
   */
  Cache_wbInvAll();
}
void evm::as::CServiceTypes::s_CacheInv(void *p_MemLoc, uint32 u_NumBytes)
{
  /* SPRUG82A - 2.4.3 Usage Guidelines for L2 Cache Coherence Operations:
   * It is important to note that although a start address and a byte count is specified,
   * the cache controller operates always on whole lines. Therefore, for the purpose of
   * maintaining coherence, arrays must be:
   * � a multiple of L2 cache lines large
   * � aligned at an L2 cache line boundary
   */
  assert((uintptr_t)p_MemLoc % L2_CACHE_LINE_SIZE == 0);        //start address must be aligned
  assert(         u_NumBytes % L2_CACHE_LINE_SIZE == 0);        //size must be multiple of cache line size

  /* 04_Engineering/02_Development_Tools/ti_tools/bios/packages/ti/sysbios/family/c64p/Cache.c:
   * Invalidate the range of memory within the specified starting address and byte
   * count. The range of addresses operated on gets quantized to whole cache lines
   * in each cache. All lines in range are invalidated for all the 'type' caches
   */
  Cache_inv((Ptr)p_MemLoc, (SizeT) u_NumBytes, Cache_Type_ALL, true);
}


AS_t_Dem_ReturnType evm::as::CServiceTypes::s_Dem_SetEventStatus (const AS_t_Dem_EventIDType u_Dem_EventIdRaw,
                                   const AS_t_Dem_EventStatusType u_Dem_EventStatus)
{
  return 0; // dummy-implementation
}

AS_t_Dem_ReturnType evm::as::CServiceTypes::s_Dem_SetEventStatusPreExtData (const AS_t_Dem_EventIDType u_Dem_EventIdRaw,
                                   const AS_t_Dem_EventStatusType u_Dem_EventStatus,
                                   const uint8* const p_Dem_pui8_PreExtData,
                                   uint8 u_Dem_PreExtDataSize)
{
  return 0; // dummy-implementation
}

uint32 evm::as::CServiceTypes::s_EveTrigger(const AS_t_EVEContainer *p_Container, sint32 *p_Handle, uint32 u_ComponentId)
{
  return evm::as::CServiceTypes::getInstance().EveTrigger(p_Container, p_Handle, u_ComponentId);
}


uint32 evm::as::CServiceTypes::s_EveWait(sint32 u_Handle, sint32 *p_EveLibReturnCode)
{
  return evm::as::CServiceTypes::getInstance().EveWait(u_Handle, p_EveLibReturnCode);
}


////
void evm::as::CServiceTypes::s_ComputeImageFingerPrint_ui16( ImageU16_t * const image )
{
  ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_ui16(image);
}
void evm::as::CServiceTypes::s_ComputeImageFingerPrint_ui8( ImageU8_t * const image )
{
  ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_ui8(image);
}
void evm::as::CServiceTypes::s_ComputeImageFingerPrint_DisparityImage( DisparityImage_t * const image )
{
  ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_DisparityImage(image);
}
void evm::as::CServiceTypes::s_ComputeImageFingerPrint_FlowImage( FlowImage_t * const image )
{
  ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_FlowImage(image);
}

uint8 evm::as::CServiceTypes::s_CheckImageFingerPrintValidity_ui16( const ImageU16_t * const image )
{
  return ifp::CImageFingerPrint::getInstance().CheckImageFingerPrintValidity_ui16(image);
}
uint8 evm::as::CServiceTypes::s_CheckImageFingerPrintValidity_ui8( const ImageU8_t * const image )
{
  return ifp::CImageFingerPrint::getInstance().CheckImageFingerPrintValidity_ui8(image);
}
uint8 evm::as::CServiceTypes::s_CheckImageFingerPrintValidity_DisparityImage( const DisparityImage_t * const image )
{
  return ifp::CImageFingerPrint::getInstance().CheckImageFingerPrintValidity_DisparityImage(image);
}
uint8 evm::as::CServiceTypes::s_CheckImageFingerPrintValidity_FlowImage( const FlowImage_t * const image )
{
  return ifp::CImageFingerPrint::getInstance().CheckImageFingerPrintValidity_FlowImage(image);
}
