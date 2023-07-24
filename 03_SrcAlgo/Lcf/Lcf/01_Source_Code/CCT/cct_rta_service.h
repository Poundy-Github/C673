#ifndef cct_rta_service_h__
#define cct_rta_service_h__

/// @file cct_rta_service.h RTA service helper functions.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

#include "algo_glob.h"

namespace cct
{
  /// Wrapper class to ease the use of RTA algo service functions.
  /// @tparam COMP_ID The unique component id out of @a glob_comp_id.h
  template <uint8 COMP_ID>
  class CRtaService
  {
  public:
    /// Constructor to set the function pointer to RTA algo service function
    /// @param[in] pfRtaAlgoServiceAddEvent The function pointer to RTA algo service function
    CRtaService( const AS_t_RTAAlgoServiceAddEvent pfRtaAlgoServiceAddEvent )
      : m_pfRtaAlgoServiceAddEvent(pfRtaAlgoServiceAddEvent)
    {}

    /// Add start event to RTA buffer.
    /// Has to be called equally often as @a RtaAddEventEnd with equal @a id.
    /// @param[in] id      The component-unique RTA ID. Typically defined in @a $cmp$_rta.h.
    /// @param[in] optData Optional data to be stored. Maximum 8 Bits. Default is 0.
    void RtaAddEventStart( const uint8 id, const uint8 optData = 0U )
    {
      if( m_pfRtaAlgoServiceAddEvent != NULL )
      {
        m_pfRtaAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID, id, optData); // polyspace RTE:COR [Not a defect: Low] "Null-Ptr is checked above. Validity of FctPtr is checked on the outside."
      }
    }

    /// Add end event to RTA buffer.
    /// Has to be called equally often as @a RtaAddEventStart with equal @a id.
    /// @param[in] id      The component-unique RTA ID. Typically defined in @a $cmp$_rta.h.
    /// @param[in] optData Optional data to be stored. Maximum 8 Bits. Default is 0.
    void RtaAddEventEnd  ( const uint8 id, const uint8 optData = 0U )
    {
      if( m_pfRtaAlgoServiceAddEvent != NULL )
      {
        m_pfRtaAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd  , COMP_ID, id, optData); // polyspace RTE:COR [Not a defect: Low] "Null-Ptr is checked above. Validity of FctPtr is checked on the outside."
      }
    }

  private:
    CRtaService( const CRtaService& );           ///< Forbid copy constructor.
    CRtaService& operator= (const CRtaService&); ///< Forbid assignment operator. @return Not implemented.

    const AS_t_RTAAlgoServiceAddEvent m_pfRtaAlgoServiceAddEvent; ///< The function pointer to RTA algo service function.
  };
}

#endif // cct_rta_service_h__
