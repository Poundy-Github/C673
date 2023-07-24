#ifndef cct_rta_service_h__
#define cct_rta_service_h__

#include "algo_type.h"
#include "algo_service_types.h"

namespace cct
{
  template <uint8 COMP_ID>
  class CRtaService
  {
  public:
    CRtaService( const AS_t_RTAAlgoServiceAddEvent pfRtaAlgoServiceAddEvent )
      : m_pfRtaAlgoServiceAddEvent(pfRtaAlgoServiceAddEvent)
    {}

    void RtaAddEventStart( const uint8 id, const uint8 optData = 0U )
    {
      if( m_pfRtaAlgoServiceAddEvent != NULL )
      {
        m_pfRtaAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID, static_cast<uint8>(id), optData);
      }
    }

    void RtaAddEventEnd  ( const uint8 id, const uint8 optData = 0U )
    {
      if( m_pfRtaAlgoServiceAddEvent != NULL )
      {
        m_pfRtaAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd  , COMP_ID, static_cast<uint8>(id), optData);
      }
    }

  private:

    CRtaService( const CRtaService& );
    CRtaService& operator= (const CRtaService&);

    const AS_t_RTAAlgoServiceAddEvent m_pfRtaAlgoServiceAddEvent;
  };
}

#endif // cct_rta_service_h__
