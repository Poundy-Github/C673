#ifndef cct_check_data_h__
#define cct_check_data_h__

#include "algo_type.h"
#include "cml_ext_cpp.h"
#include <cassert>

namespace cct
{
  inline boolean_t operator==(const SignalHeader_t& lhs, const SignalHeader_t& rhs)
  {
    return (lhs.uiMeasurementCounter == rhs.uiMeasurementCounter)
      ||   (lhs.uiTimeStamp          == rhs.uiTimeStamp         );
  }

  inline boolean_t operator!=(const SignalHeader_t& lhs, const SignalHeader_t& rhs)
  {
    return ! operator==(lhs, rhs);
  }

  template <sint32 CAT_COUNT, typename ERR_TYPE = sint32, typename ERR_CAT = sint32, ERR_TYPE CCT_CCHECKDATA_NO_ERROR = static_cast<ERR_TYPE>(0)>
  class CCheckData
  {
  public:
    typedef ERR_TYPE Error_t;
    typedef ERR_CAT  ErrorCategory_t;

    CCheckData()
      : m_haveError(false)
    {
    }

    void reset()
    {
      m_error.fill(static_cast<Error_t>(CCT_CCHECKDATA_NO_ERROR));
      m_haveError = false;
    }

    boolean_t isError() const
    {
      return m_haveError;
    }

    boolean_t isError( const ErrorCategory_t id ) const
    {
      return( getError(id) != CCT_CCHECKDATA_NO_ERROR );
    }

    Error_t getError( const ErrorCategory_t id ) const
    {
      return m_error[id];
    }

  protected:
    template <typename T>
    struct SPastValue
    {
      boolean_t isInitialized;
      T         val;

      SPastValue() : isInitialized(false) {};
      void reset() { isInitialized = false; }
      void set(const T setVal)
      {
        isInitialized = true;
        val           = setVal;
      }
    };

    void setError( const ErrorCategory_t& id, const Error_t& errorCode )
    {
      assert(id < CAT_COUNT);
      // safeguard category to detect wrongful usage
      const sint32 limitedCategory = (static_cast<sint32>(id) < CAT_COUNT) ? static_cast<sint32>(id) : CAT_COUNT;

      // first error wins, do not change something if already a error exists
      // if no error is given nothing happens
      if ( (m_error[limitedCategory] == CCT_CCHECKDATA_NO_ERROR)
        && (errorCode                != CCT_CCHECKDATA_NO_ERROR) )
      {
        m_error[limitedCategory] = errorCode;
        m_haveError              = true;
      }
    }

    template <typename T>
    boolean_t verifyPointer( const T& pVal, const ErrorCategory_t errorCat, const Error_t errorCode )
    {
      const boolean_t ret = pVal != NULL;
      if ( !ret )
      {
        setError( errorCat, errorCode );
      }
      return ret;
    }

    boolean_t verifySignalHeader(
      const SignalHeader_t&       signalHeader,
      SPastValue<SignalHeader_t>& pastSignalHeader,
      const ErrorCategory_t&      errorCategory,
      const Error_t&              errorCodeSigState,
      const Error_t&              errorCodeFreeze)
    {
      boolean_t ret;

      if ( signalHeader.eSigStatus != AL_SIG_STATE_OK )
      {
        setError( errorCategory, errorCodeSigState );
        ret = (errorCodeSigState == CCT_CCHECKDATA_NO_ERROR) ? true : false;
      }
      else if ( notChanging(signalHeader, pastSignalHeader) )
      {
        setError( errorCategory, errorCodeFreeze );
        ret = (errorCodeFreeze == CCT_CCHECKDATA_NO_ERROR) ? true : false;
      }
      else
      {
        ret = true;
      }

      return ret;
    }

    template <typename T>
    static boolean_t isInRange (const T& val, const T& minimum, const T& maximum)
    {
      return ( (val >= minimum) && (val <= maximum) );
    }

    template <typename T>
    static boolean_t notInRange (const T& val, const T& minimum, const T& maximum)
    {
      return !isInRange(val, minimum, maximum);
    }

    template <typename T>
    static boolean_t isChanging (const T& val, SPastValue<T>& pastVal)
    {
      const boolean_t ret = pastVal.isInitialized && isChanging(val, pastVal.val);
      pastVal.set(val);
      return ret;
    }

    template <typename T>
    static boolean_t isChanging (const T& val, const T& pastVal)
    {
      return val != pastVal;
    }

    template <typename T>
    static boolean_t notChanging (const T& val, SPastValue<T>& pastVal)
    {
      const boolean_t ret = pastVal.isInitialized && notChanging(val, pastVal.val);
      pastVal.set(val);
      return ret;
    }

    template <typename T>
    static boolean_t notChanging (const T& val, const T& pastVal)
    {
      return !isChanging(val, pastVal);
    }

    template <typename T>
    static boolean_t changingTooMuch (const T& val, SPastValue<T>& pastVal, const T& maxDiffAllowed)
    {
      boolean_t ret;

      if (!pastVal.isInitialized)
      {
        pastVal.set(val);
        ret = false;
      } 
      else
      {
        ret = changingTooMuch(val, pastVal.val, maxDiffAllowed);

        pastVal.val = val;
      }

      return ret;
    }

    /// Calculates the absolute difference between two values.
    /// Does work on signed and unsigned values.
    /// @tparam T   Type of values given and result.
    /// @param  lhs First operand of operation
    /// @param  rhs Second operand of operation
    /// @return Positive delta between @a lhs and @a rhs.
    template <typename T>
    static T absDiff( const T& lhs, const T& rhs )
    {
      return (lhs > rhs) ? (lhs - rhs) : (rhs - lhs);
    }

    template <typename T>
    static boolean_t changingTooMuch (const T& val, const T& pastVal, const T& maxDiffAllowed)
    {
      const T diff = absDiff(val, pastVal);
      return (diff > maxDiffAllowed);
    }

  private:
    // safeguarded category array, last category is for wrongful usage of setError()
    typedef cml::CArray<Error_t, CAT_COUNT + 1> ErrorArray_t;

    ErrorArray_t m_error;
    boolean_t    m_haveError;

    CCheckData( const CCheckData& );
    CCheckData& operator=(const CCheckData&);

  public:
    enum { MAX_SIZE = ErrorArray_t::MAX_SIZE };
  };
}

#endif // em_check_data_h__
