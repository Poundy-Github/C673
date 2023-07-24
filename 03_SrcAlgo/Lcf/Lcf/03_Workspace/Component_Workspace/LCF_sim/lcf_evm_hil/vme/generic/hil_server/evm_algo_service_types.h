#ifndef evm_algo_service_types_h__
#define evm_algo_service_types_h__

#include "algo_service_types.h"
#ifdef _TMS320C6X
#define si_MAX_NUM_EDMACHANNELS 5
#endif

namespace evm
{
  namespace as
  {
    class CServiceTypes : public AS_t_ServiceFuncts
    {
    public:
      static const sint32 RETURN_SUCCESS       = 0;
      static const sint32 RETURN_ERROR_UNKNOWN = 1;
      static const sint32 RETURN_ERROR_INPUT   = 2;

      static const sint32 RETURN_ERROR_MEMLOCK_L2_OVERFLOW = 10;
      static const sint32 RETURN_ERROR_MEMLOCK_L3_OVERFLOW = 11;
      static const sint32 RETURN_ERROR_MEMLOCK_INUSE       = 12;

      static const sint32 RETURN_ERROR_MEMUNLOCK_NOTASSIGNED = 20;

      /* DSP:
       * L1 cache line size is  64 bytes (SPRU862 Table 1-4. L1D Cache Characteristics)
       * L2 cache line size is 128 bytes (SPRU862 Table 1-6. L2 Cache Characteristics)
       */

      static const uint32 L2_CACHE_LINE_SIZE = 128;
      static const uint32 L3_AVAILABLE_BUFFER_SIZE_BYTES = 124 * 1024;  //i310 limit 124kB
      static const uint32 L2_AVAILABLE_BUFFER_SIZE_BYTES = 124 * 1024;  //i310 limit 124kB
      static const uint32 L2_AVAILABLE_BUFFER_SIZE_BYTES_CORTEX_A8 = 63 * 1024;  //i310 limit 124kB
      static const uint32 L2_DSP_BASE_ADDR       = 0x10800000u;  // sprug82a.pdf page 25
      static const uint32 L2_CORETEXA8_BASE_ADDR = 0x402F0400u;
      static const uint32 L3_BASE_ADDR           = 0x40300000u;

      /// gives the one and only instance of the service types handler. singleton pattern.
      /// \return the reference to the instance of the class
      static CServiceTypes& getInstance();

      sint32          memLock   (void ** p_L2Buffer, sint32 * p_L2BuffSize, void ** p_L3Buffer, sint32 * p_L3BuffSize, AS_t_MemState * p_State);
      sint32          memLockL2 (void ** p_L2Buffer, sint32 * p_L2BuffSize, AS_t_MemState * p_State);
      sint32          memLockL3 (void ** p_L3Buffer, sint32 * p_L3BuffSize, AS_t_MemState * p_State);
      sint32          memUnlock (AS_t_MemState * p_State);
      sint32          memUnlockL2 (AS_t_MemState * p_State);
      sint32          memUnlockL3 (AS_t_MemState * p_State);

      /* Roland Stark (ITK, +49 69 8700008 290):
       * THE NEXT LINES WILL RISE THE FOLLOWING COMPILER ERRORS IF THE COMMON CHECKPOINT IS OUT OF DATE!
       * ...\evm_algo_service_types.h", line ???: error #20: identifier "AS_t_MemScratchReturnCode" is undefined
       * ...\evm_algo_service_types.h", line ???: error #20: identifier "AS_t_MemScratchReturnCode" is undefined
       */
      AS_t_MemScratchReturnCode memScratchLock   (const AS_t_MemScratchReqPort * const reqPort, AS_t_MemScratchProPort * const proPort);
      AS_t_MemScratchReturnCode memScratchUnlock (const uint32 u_compId, const uint32 u_memReqId);

      AS_t_MeasReturn measHdlr  (const AS_t_MeasInfo *p_MeasInfo, void *p_Buff, AS_t_MeasCallback pf_MeasCallback);
      uint64          GetTimestampuS64(void);
      uint64          GetCoreTicksuS64(void);
#ifdef _TMS320C6X
      sint32          EDMACopy (void *p_Dst, void *p_Src, sint32 s_SizeBytes, sint32 *p_ChIndexOut);
      sint32          EDMACopy2D (void *p_Dst, void *p_Src, sint32 s_DstPitch, sint32 s_SrcPitch, sint32 s_Width, sint32 s_Height, sint32 *p_ChIndexOut);
      sint32          EDMACopyChained(void *p_PreDst, void *p_PreSrc, sint32 s_PreNumBytes, void *p_PostDst, void *p_PostSrc, sint32 s_PostNumBytes, sint32 *p_PostChIndexOut);
      sint32          EDMAWait (sint32 s_ChIndex);
      sint32          EDMAGet (AS_t_EdmaFlags Flags, AS_t_EdmaHandle *Regs);
      sint32          EDMARelease (AS_t_EdmaHandle *Regs);
      uint32          EDMATranslateAddress(uint32 Address);

      // EDMA init
      sint32          si_EDMA_Init();
      sint32          si_ConfigTrigger_EDMAChannel_2D(void* pv_DstBuffer, void* pv_SrcBuffer, sint32 si_DstPitch, sint32 si_SrcPitch, sint32 si_Width, sint32 si_Height, sint32* psi_ChannelIndex);
      sint32          si_ConfigTrigger_EDMAChannel_Chained(void *pv_PreDstBuffer, void *pv_PreSrcBuffer, sint32 s_PreNumBytes, void *pv_PostDstBuffer, void *pv_PostSrcBuffer, sint32 s_PostNumBytes, sint32 *psi_PostChIndexOut);
      sint32          si_Wait_EDMAChannel(sint32 si_Index);
#endif
      void*           pv_getGlobalAddr(void* addr);
      void            InitEvmService_Eve(AS_t_EVEContainer *pEVEContainer, void *pParamBuf, volatile sint32 *pFlag_RunEVE,  volatile sint32* pEVEReturnValue);

    private:
      static CServiceTypes* m_instance;

      uint8* m_cacheL2;
      uint8* m_cacheL3;

      AS_t_MemState m_memoryState;

      CServiceTypes ();
      CServiceTypes (const CServiceTypes &) {}
      CServiceTypes & operator= (const CServiceTypes &) {return (* this);}

      /// destroy the service type handler and its assigned memory
      //~CServiceTypes() {}

      // EVE-Services...
      void*               m_pParamBuff;
      volatile sint32*    m_pFlag_RunEVE;
      AS_t_EVEContainer*  m_pEVEContainer;
      volatile sint32*    m_pEVEReturnValue;

      sint32              m_sEVERequestHandle;

      uint32 EveTrigger(const AS_t_EVEContainer *p_Container, sint32 *p_Handle, uint32 u_ComponentId);
      uint32 EveWait(sint32 u_Handle, sint32 *p_EveLibReturnCode);

      /////////////////////////////////////
      // Static functions...
      /////////////////////////////////////
      static sint32          s_memLock   ( void ** p_L2Buffer, sint32 * p_L2BuffSize, void ** p_L3Buffer, sint32 * p_L3BuffSize, AS_t_MemState * p_State, AS_t_MemWaitCondition WaitCondition );
      static sint32          s_memLockL2   ( void ** p_L2Buffer, sint32 * p_L2BuffSize, AS_t_MemState * p_State, AS_t_MemWaitCondition WaitCondition );
      static sint32          s_memLockL3   ( void ** p_L3Buffer, sint32 * p_L3BuffSize, AS_t_MemState * p_State, AS_t_MemWaitCondition WaitCondition );
      static sint32          s_memUnlock (AS_t_MemState * p_State);
      static sint32          s_memUnlockL2 (AS_t_MemState * p_State);
      static sint32          s_memUnlockL3 (AS_t_MemState * p_State);

      /* Roland Stark (ITK, +49 69 8700008 290):
       * THE NEXT LINES WILL RISE THE FOLLOWING COMPILER ERRORS IF THE COMMON CHECKPOINT IS OUT OF DATE!
       * ...\evm_algo_service_types.h", line ???: error #20: identifier "AS_t_MemScratchReturnCode" is undefined
       * ...\evm_algo_service_types.h", line ???: error #20: identifier "AS_t_MemScratchReturnCode" is undefined
       */
      static AS_t_MemScratchReturnCode s_memScratchLock   (const AS_t_MemScratchReqPort * const reqPort, AS_t_MemScratchProPort * const proPort);
      static AS_t_MemScratchReturnCode s_memScratchUnlock (const uint32 u_compId, const uint32 u_memReqId);

      static AS_t_MeasReturn s_measHdlr  (const AS_t_MeasInfo *p_MeasInfo, void *p_Buff, AS_t_MeasCallback pf_MeasCallback);

      static uint64          s_GetTimestampuS64(void);
      static uint32          s_GetTimestampuS32(void);
      static uint64          s_GetCoreTicksuS64(void);

      static void            s_CacheWbInv (void *p_MemLoc, uint32 u_NumBytes);
      static void            s_CacheInv (void *p_MemLoc, uint32 u_NumBytes);
      static void            s_CacheWbInvAll ();

      static AS_t_Dem_ReturnType s_Dem_SetEventStatus (const AS_t_Dem_EventIDType u_Dem_EventIdRaw,
                                         const AS_t_Dem_EventStatusType u_Dem_EventStatus);

      static AS_t_Dem_ReturnType s_Dem_SetEventStatusPreExtData (const AS_t_Dem_EventIDType u_Dem_EventIdRaw,
                                         const AS_t_Dem_EventStatusType u_Dem_EventStatus,
                                         const uint8* const p_Dem_pui8_PreExtData,
                                         uint8 u_Dem_PreExtDataSize);

      static AS_t_MeasErrors s_MeasStartFuncCycle(const AS_t_MeasFuncID);

      static uint32          s_EveTrigger(const AS_t_EVEContainer *p_Container, sint32 *p_Handle, uint32 u_ComponentId);
      static uint32          s_EveWait(sint32 u_Handle, sint32 *p_EveLibReturnCode);
#ifdef _TMS320C6X
      static sint32          s_EDMACopy(void *p_Dst, void *p_Src, sint32 s_SizeBytes, sint32 *p_ChIndexOut);
      static sint32          s_EDMACopy2D(void *p_Dst, void *p_Src, sint32 s_DstPitch, sint32 s_SrcPitch, sint32 s_Width, sint32 s_Height, sint32 *p_ChIndexOut);
      static sint32          s_EDMACopyChained(void *p_PreDst, void *p_PreSrc, sint32 s_PreNumBytes, void *p_PostDst, void *p_PostSrc, sint32 s_PostNumBytes, sint32 *p_PostChIndexOut);
      static sint32          s_EDMAWait(sint32 s_ChIndex);
      static sint32          s_EDMAGet (AS_t_EdmaFlags Flags, AS_t_EdmaHandle *Regs);
      static sint32          s_EDMARelease (AS_t_EdmaHandle *Regs);
      static uint32          s_EDMATranslateAddress(uint32 Address);
#endif			
      static uint32          s_CeilSizeToNextCacheLine(uint32 size)
                             { //use c integer rounding to get the next multiple of the L2_CACHE_LINE_SIZE
                               return ((size+L2_CACHE_LINE_SIZE-1)/L2_CACHE_LINE_SIZE)*L2_CACHE_LINE_SIZE;
                             };
#ifdef _TMS320C6X														 
      void*                  m_pv_EDMAHandle;
      void*                  m_pv_EDMAService;
      uint32                 m_aui_EDMAChannelIDs[si_MAX_NUM_EDMACHANNELS];
      uint32                 m_aui_EDMAChannelTCC[si_MAX_NUM_EDMACHANNELS];
      bool                   m_ab_FreeEDMAChannels[si_MAX_NUM_EDMACHANNELS];
      sint32                 m_asi_ChainedChannelIndexes[si_MAX_NUM_EDMACHANNELS];
#endif


      /// @name Image Finger Print service
      /// @{
      static  void  s_ComputeImageFingerPrint_ui16(ImageU16_t * const image);
      static  void  s_ComputeImageFingerPrint_ui8(ImageU8_t * const image);
      static  void  s_ComputeImageFingerPrint_DisparityImage(DisparityImage_t * const image);
      static  void  s_ComputeImageFingerPrint_FlowImage(FlowImage_t * const image);
      static  uint8 s_CheckImageFingerPrintValidity_ui16(const ImageU16_t * const image);
      static  uint8 s_CheckImageFingerPrintValidity_ui8(const ImageU8_t * const image);
      static  uint8 s_CheckImageFingerPrintValidity_DisparityImage(const DisparityImage_t * const image);
      static  uint8 s_CheckImageFingerPrintValidity_FlowImage(const FlowImage_t * const image);
      /// @}
    };
  }
}


#endif // sim_algo_service_types_h__
