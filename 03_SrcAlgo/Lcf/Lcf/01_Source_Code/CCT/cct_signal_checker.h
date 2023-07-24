#ifndef cct_signal_checker_h__
#define cct_signal_checker_h__

#include "algo_glob.h"
#include <limits>
#include <cassert>

namespace cct
{

  /**************************************************************************
  Classname         CSignalChecker                                       */ /*!   

  @brief            Contains generic methods to check RTE signals for validity
  @description      
  *
  * USAGE:
  * -Expected cycle time and maximum deviation of master time signal can be 
  *  specified in the constructor
  *
  * -Call setAndCheckMasterTime(...) in every cycle to update the master time
  *  which all other signals can be checked against in regard to synchronicity.
  *  This method returns true only if the master time has increased as expected
  *  since the last cycle.
  *
  * -Call checkRTESignal(...) to check if a signal is valid. If the second
  *  parameter is true, the method also checks if the signal's timestamp
  *  is identical to the master timestamp (up to a maximum deviation given
  *  in the constructor).
  *  
  *
  *****************************************************************************/
  class CSignalChecker
  {
  public:
    explicit CSignalChecker(
      AlgoDataTimeStamp_t masterCycletimeMuSec             = 60U * 1000U,
      AlgoDataTimeStamp_t masterCycletimeMaxDeviationMuSec =  1U * 1000U)
      : m_masterCycletimeMuSec            (masterCycletimeMuSec)
      , m_masterCycletimeMaxDeviationMuSec(masterCycletimeMaxDeviationMuSec)
    {
      clearMasterTimestamp();
      assert(m_masterCycletimeMuSec             >  0U                                                                                    );
      assert(m_masterCycletimeMaxDeviationMuSec <  m_masterCycletimeMuSec                                                                );
      assert(m_masterCycletimeMuSec             <= (std::numeric_limits<AlgoDataTimeStamp_t>::max() - m_masterCycletimeMaxDeviationMuSec));
    };

    void clearMasterTimestamp()
    {
      m_masterTime       = static_cast<AlgoDataTimeStamp_t>(0);
      m_masterTimeWasSet = false;
    }

    boolean_t setAndCheckMasterTime( AlgoDataTimeStamp_t t )
    {
      boolean_t ret;

      if(!m_masterTimeWasSet)
      {
        // set master time in the first call
        m_masterTime       = t;
        m_masterTimeWasSet = true;
        ret = true;
      }
      else
      {
        // calculate time delta between current and last call
        uint64 deltaT = static_cast<uint64>(0);
        if ( t <= m_masterTime )
        {
          // handle potential overflow
          const uint64 noOverflowT = static_cast<uint64>(std::numeric_limits<AlgoDataTimeStamp_t>::max()) + static_cast<uint64>(t);
          assert(noOverflowT >= m_masterTime);
          deltaT = noOverflowT - m_masterTime;
        }
        else
        {
          deltaT = t - m_masterTime;
          assert(deltaT > 0ULL);
        }

        m_masterTime       = t;
        m_masterTimeWasSet = true;

        // return true if time difference between calls is within valid interval
        ret = ( (deltaT <= static_cast<uint64>(m_masterCycletimeMuSec + m_masterCycletimeMaxDeviationMuSec))
          &&    (deltaT >= static_cast<uint64>(m_masterCycletimeMuSec - m_masterCycletimeMaxDeviationMuSec)) );
      }

      return ret;
    }

    AlgoDataTimeStamp_t getMasterTime() const { return m_masterTime; }

    template<class S>
    boolean_t checkRTESignal( const S* pRteStruct, const boolean_t checkSyncedToMaster = true ) const
    {
      typedef struct
      {
        AlgoInterfaceVersionNumber_t uiVersionNumber;
        SignalHeader_t sSignalHeader;
      } SigHead_t;

      boolean_t ret = false;

      if ( NULL != pRteStruct)
      {
        const SigHead_t& sigHead = *reinterpret_cast<const SigHead_t*>(pRteStruct);

        const boolean_t sigStateOk     = isSigStateOk(sigHead.sSignalHeader);
        const boolean_t syncedToMaster = checkSyncedToMaster ? isSyncedToMaster(sigHead.sSignalHeader) : true;

        ret = (sigStateOk && syncedToMaster);
      }

      return ret;
    }

  private:
    static boolean_t isSigStateOk(const SignalHeader_t &sh)
    {
      return (AL_SIG_STATE_OK == sh.eSigStatus);
    }

    boolean_t isSyncedToMaster( const SignalHeader_t &sh ) const
    {
      assert(m_masterTimeWasSet);

      boolean_t ret;

      const AlgoDataTimeStamp_t t = sh.uiTimeStamp;

      const uint64 masterTimeUInt64          = static_cast<uint64>(m_masterTime                                   );
      const uint64 masterTimeMaxDevUInt64    = static_cast<uint64>(m_masterCycletimeMaxDeviationMuSec             );
      static const uint64 timestampMaxUInt64 = static_cast<uint64>(std::numeric_limits<AlgoDataTimeStamp_t>::max());

      const AlgoDataTimeStamp_t lowerTimeBound = m_masterTime - m_masterCycletimeMaxDeviationMuSec;
      const AlgoDataTimeStamp_t upperTimeBound = m_masterTime + m_masterCycletimeMaxDeviationMuSec;

      if ( (masterTimeUInt64 + masterTimeMaxDevUInt64) > timestampMaxUInt64 )
      {
        // potential overflow in upperTimeBound, lowerTimeBound is ok
        assert(m_masterTime >= m_masterCycletimeMaxDeviationMuSec);

        ret = ((t >= lowerTimeBound) || (t <= upperTimeBound));
      }
      else if ( masterTimeUInt64 < masterTimeMaxDevUInt64 )
      {
        // potential overflow in lowerTimeBound, upperTimeBound  is ok
        assert( ( masterTimeUInt64 + masterTimeMaxDevUInt64) <= timestampMaxUInt64 );

        ret = ((t >= lowerTimeBound) || (t <= upperTimeBound));
      }
      else
      {
        // no overflow possible
        assert(m_masterTime                                >= m_masterCycletimeMaxDeviationMuSec);
        assert((masterTimeUInt64 + masterTimeMaxDevUInt64) <= timestampMaxUInt64                );

        ret = ((t >= lowerTimeBound) && (t <= upperTimeBound));
      }

      return ret;
    }

    CSignalChecker(const CSignalChecker&);
    CSignalChecker& operator=(const CSignalChecker&);

    const AlgoDataTimeStamp_t m_masterCycletimeMuSec;
    const AlgoDataTimeStamp_t m_masterCycletimeMaxDeviationMuSec;

    AlgoDataTimeStamp_t m_masterTime;
    boolean_t           m_masterTimeWasSet;
  };
}

#endif // cct_signal_checker_h__
