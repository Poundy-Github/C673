#ifndef cct_edma_service_h__
#define cct_edma_service_h__

/// @file cct_edma_service.h Wrapping the EDMA services of the frame software to make them more usable in C++ context.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

#include "algo_glob.h"

#include <cassert>

namespace cct
{
  /// Wraps the EDMA algo services to make them more usable for the C++ environment.
  class CEdmaServices
  {
  public:
    /// Constructs the class instance and initializes the function pointers to the
    /// algo service layer.
    /// @sa AS_t_EDMACopy2D, AS_t_EDMACopy, AS_t_EDMAWait
    /// @param pfEDMACopy2D Function pointer to the AS_t_EDMACopy2D interface of the algo services
    /// @param pfEDMACopy   Function pointer to the AS_t_EDMACopy interface of the algo services
    /// @param pfEDMAWait   Function pointer to the AS_t_EDMAWait interface of the algo services
    CEdmaServices(
      AS_t_EDMACopy2D pfEDMACopy2D,
      AS_t_EDMACopy   pfEDMACopy,
      AS_t_EDMAWait   pfEDMAWait)
      : m_pfEDMACopy2D(pfEDMACopy2D)
      , m_pfEDMACopy  (pfEDMACopy  )
      , m_pfEDMAWait  (pfEDMAWait  )
    {}

    /// Manages a normal data copy from source to destination via
    /// the AS_t_EDMACopy service.
    /// @sa AS_t_EDMACopy
    /// @tparam T1        Type of the destination memory
    /// @tparam T2        Type of the source memory
    /// @param Dst        Defines the destination of the data copy.
    /// @param Src        Defines the source of the data copy.
    /// @param numBytes   The used value defines the num of bytes being copied.
    /// @param ChannelIdx Is used to get the chosen EDMA channel.
    /// @return Output of the AS_t_EDMACopy service.
    template <typename T1, typename T2>
    sint32 Copy(
      T1&          Dst,
      const T2&    Src,
      const sint32 numBytes,
      sint32*      ChannelIdx)
    {
      assert (m_pfEDMACopy != NULL);

      void* p_vDst = static_cast<void*>(&Dst);
      void* p_vSrc = static_cast<void*>(const_cast<T2*>(&Src));

      const sint32 returnCode = m_pfEDMACopy(p_vDst, p_vSrc, numBytes, ChannelIdx);
      assert (returnCode == 0);
      return returnCode;
    }

    /// Manages a advanced data copy from source to destination single bytes may be picked up for transfer
    /// via the AS_t_EDMACopy2D service.
    /// @sa AS_t_EDMACopy2D
    /// @tparam T1        Type of the destination memory
    /// @tparam T2        Type of the source memory
    /// @param Dst        Defines the destination of the data copy.
    /// @param Src        Defines the source of the data copy.
    /// @param s_DstPitch Is the pitch from destination address to next address
    /// @param s_SrcPitch Is the pitch from source address to next address
    /// @param s_Width    Defines the 2D Width
    /// @param s_Height   Defines the 2D Height
    /// @param ChannelIdx Is used to get the chosen EDMA channel.
    /// @return Output of the AS_t_EDMACopy2D service.
    template <typename T1, typename T2>
    sint32 Copy2D(
      T1&          Dst,
      const T2&    Src,
      const sint32 s_DstPitch,
      const sint32 s_SrcPitch,
      const sint32 s_Width,
      const sint32 s_Height,
      sint32*      ChannelIdx)
    {
      assert (m_pfEDMACopy2D != NULL);

      void* p_vDst = static_cast<void*>(&Dst);
      void* p_vSrc = static_cast<void*>(const_cast<T2*>(&Src));

      const sint32 returnCode = m_pfEDMACopy2D(p_vDst, p_vSrc,s_DstPitch,s_SrcPitch,s_Width,s_Height,ChannelIdx);
      assert (returnCode == 0);
      return returnCode;
    }

    /// Waits for the actual triggered EDMA transfer on used ChannelIdx via
    /// the AS_t_EDMAWait service.
    /// @sa AS_t_EDMAWait
    /// @param ChannelIdx Defines the chosen EDMA channel.
    /// @return Output of the AS_t_EDMAWait service.
    sint32 WaitForTransfer(const sint32 ChannelIdx) const
    {
      assert (m_pfEDMAWait != NULL);

      const sint32 returnCode = m_pfEDMAWait(ChannelIdx);
      assert (returnCode == 0);
      return returnCode;
    }

  private:
    AS_t_EDMACopy2D m_pfEDMACopy2D; ///< Function pointer to the AS_t_EDMACopy2D service. Initialized by the constructor.
    AS_t_EDMACopy   m_pfEDMACopy;   ///< Function pointer to the AS_t_EDMACopy service. Initialized by the constructor.
    AS_t_EDMAWait   m_pfEDMAWait;   ///< Function pointer to the AS_t_EDMAWait service. Initialized by the constructor.
  };
}

#endif
