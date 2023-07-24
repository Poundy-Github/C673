/// @file cct_check_data.h Base class implementation for in-/outputs signal checking.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision 1.15 $
#ifndef cct_check_data_h__
#define cct_check_data_h__

// PRQA S 1021 EOF
// 2020-2-5; uic58113
// summary < Msg(3:1021) This macro is replaced with a literal.>
// reason < Need to use RTE defines hence macros are replaced by literals.>

#include "algo_glob.h"
#include "cml_ext_cpp.h"
#include <cassert>

namespace cct
{
  /// Operator to compare two signal headers.
  /// Specifically the measurement counter and the timestamp of signal headers will be compared.
  /// @param[in] lhs Constant reference to one signal header.
  /// @param[in] rhs Constant reference to the other signal header.
  /// @return        Returns \a true if the two signal headers are identical, otherwise \a false.
  inline static bool operator==(const SignalHeader_t& lhs, const SignalHeader_t& rhs)
  {
    return (lhs.uiMeasurementCounter == rhs.uiMeasurementCounter)
      ||   (lhs.uiTimeStamp          == rhs.uiTimeStamp         );
  }

  /// Operator to compare two signal headers.
  /// Specifically the measurement counter and the timestamp of signal headers will be compared.
  /// @param[in] lhs Constant reference to one signal header.
  /// @param[in] rhs Constant reference to the other signal header.
  /// @return        Returns \a true if the two signal headers are not identical, otherwise \a false.
  inline static bool operator!=(const SignalHeader_t& lhs, const SignalHeader_t& rhs)
  {
    return ! operator==(lhs, rhs);
  }

  /// Base class implementation for in-/outputs signal checking.
  /// There are several pre-defined error codes to represent different system errors.
  /// For each in-/output signal there is an unique error category defined.
  /// Based on the error code and the error category, we can identify the exact errors.
  /// @tparam CAT_COUNT               The counter of error category.
  /// @tparam ERR_TYPE                The data type for encoded errors. Default is sint32.
  /// @tparam ERR_CAT                 The data type for error categories. Default is sint32.
  /// @tparam CCT_CCHECKDATA_NO_ERROR The encoded value for no error. Default is 0.
  template <sint32 CAT_COUNT, typename ERR_TYPE = sint32, typename ERR_CAT = sint32, ERR_TYPE CCT_CCHECKDATA_NO_ERROR = static_cast<ERR_TYPE>(0)>
  class CCheckData
  {
  public:
    typedef ERR_TYPE Error_t;         ///< The internal data type for encoded errors.
    typedef ERR_CAT  ErrorCategory_t; ///< The internal data type for error categories.

    /// Default empty constructor.
    /// \a m_haveError is initialized with false, meaning no error detected.
    CCheckData()
      : m_haveError(false)
    {
    }

    /// Structure for a complex error information container, which contains the error code
    /// and a counter for this error.
    struct SError
    {
      Error_t error;   /// The error code.
      sint32  counter; /// The counter for this error.
    };

    /// A array data type for error information for all categories.
    typedef cml::CArray<SError, CAT_COUNT> ErrorArray_t;

    /// Reset function to set to no error state.
    /// Specifically error code will be set to no error and the counter will be set to 0.
    /// The internal flag for having error will be set to false (no error).
    void reset()
    {
      static const SError CCT_CCHECKDATA_NO_ERROR_PROTOTYPE = { CCT_CCHECKDATA_NO_ERROR, 0 };

      m_errorArray.fill(CCT_CCHECKDATA_NO_ERROR_PROTOTYPE);
      m_haveError = false;
    }

    /// Basic operation to be executed on every cycle start (the first operation mode of a component called by the global scheduler).
    void cycleStart()
    {
      for ( typename ErrorArray_t::it errorIt = m_errorArray.begin(); errorIt != m_errorArray.end(); ++errorIt )
      {
        SError& error = *errorIt;

        // Reset counter if no error was detected in previous cycle
        if ( error.error == CCT_CCHECKDATA_NO_ERROR )
        {
          error.counter = 0;
        }

        error.error = CCT_CCHECKDATA_NO_ERROR;
      }
    }

    /// Returns if currently having any error.
    /// @return If currently having any error.
    bool isError() const
    {
      return m_haveError;
    }

    /// Returns if having error on a given category.
    /// @param[in] id Error category to be queried if having error.
    /// @return       If having error on a given category.
    bool isError( const ErrorCategory_t id ) const
    {
      return( getError(id) != CCT_CCHECKDATA_NO_ERROR );
    }

    /// Returns the error code for a given category.
    /// @param[in] id Error category to be queried for error code.
    /// @return       The saved error code for a given category.
    Error_t getError( const ErrorCategory_t id ) const
    {
      return m_errorArray[id].error;
    }

    /// Returns the error counter for a given category.
    /// @param[in] id Error category to be queried for error counter.
    /// @return       The error counter for a given category.
    sint32 getErrorCount( const ErrorCategory_t id ) const
    {
      return m_errorArray[id].counter;
    }

    /// Returns a const reference to the error container array.
    /// @return A const reference to the error container array.
    const ErrorArray_t& getErrorArray() const { return m_errorArray; }

  protected:
    /// Template structure to store the last value of data and its initialization information.
    /// @tparam T The data type of the data to be saved.
    template <typename T>
    struct SPastValue
    {
      bool isInitialized; /// Initialization information, if the last value is stored.
      T         val;      /// Memory to store the last value.

      /// Default empty constructor.
      /// \a isInitialized is initialized with false, meaning no data stored.
      SPastValue() : isInitialized(false) {};

      /// Reset function to set initialization information to false.
      // PRQA S 2505 5
      // date: 2015-23-07, reviewer: Christian Exner
      // reason: The hidden member declaration (cct::CCheckData::reset()) is an instance method. So there is
      //         no risk to call the wrong method from within the cct::CCheckData::SPastValue scope, since it
      //         does not have any instance of the cct::CCheckData class.
      void reset() { isInitialized = false; }

      /// Store given data and set initialization information to true.
      /// @param[in] setVal The value to be stored.
      void set(const T setVal)
      {
        isInitialized = true;
        val           = setVal; // polyspace RTE:NIVL [Not a defect: Low] "It is not important if this value is initialized or not, the class does only store it and compare it."
      }
    };

    /// Store the given error code into the error container array under corresponding category and
    /// increase the error counter for this category. The global error flag will be set to \a true if
    /// an error is stored.
    /// Only the first occurred error of a category will be stored. Newer error code won't be stored
    /// if there is already an error stored for this category.
    /// @param[in] id        The error category.
    /// @param[in] errorCode The error code.
    void setError( const ErrorCategory_t& id, const Error_t& errorCode )
    {
      SError& error = m_errorArray[id];

      // first error wins, do not change something if already a error exists
      // if no error is given nothing happens
      if ( ( errorCode   != CCT_CCHECKDATA_NO_ERROR )
        && ( error.error == CCT_CCHECKDATA_NO_ERROR ) )
      {
        // Only first error in each category is stored
        error.error = errorCode;

        ++error.counter;
        m_haveError = true;
      }
    }

    /// Check if a pointer to a signal is NULL. If NULL, set error with given error code under
    /// the given error category.
    /// @tparam    T         The data type of the data pointer.
    /// @param[in] pVal      The data pointer.
    /// @param[in] errorCat  The error category.
    /// @param[in] errorCode The error code.
    /// @return              If the pointer is valid.
    template <typename T>
    bool verifyPointer( const T& pVal, const ErrorCategory_t errorCat, const Error_t errorCode )
    {
      const bool ret = pVal != NULL;
      if ( !ret )
      {
        setError( errorCat, errorCode );
      }
      return ret;
    }

    /// Check if a signal header is valid and store this signal header for next cycle.
    /// If the signal header is not valid, set error code correspondingly.
    /// @param[in]      signalHeader      The signal header to be checked.
    /// @param[in]      pastSignalHeader  The signal header from last cycle.
    /// @param[in, out] errorCategory     The error category.
    /// @param[in]      errorCodeSigState The error code for wrong signal state.
    /// @param[in]      errorCodeFrozen   The error code for frozen signal header.
    /// @return                           If the signal header is valid.
    bool verifySignalHeader(
      const SignalHeader_t&       signalHeader,
      SPastValue<SignalHeader_t>& pastSignalHeader,
      const ErrorCategory_t&      errorCategory,
      const Error_t&              errorCodeSigState,
      const Error_t&              errorCodeFrozen)
    {
      bool ret;

      if ( signalHeader.eSigStatus != AL_SIG_STATE_OK )
      {
        setError( errorCategory, errorCodeSigState );
        ret = (errorCodeSigState == CCT_CCHECKDATA_NO_ERROR) ? true : false;
      }
      else if ( notChanging(signalHeader, pastSignalHeader) )
      {
        setError( errorCategory, errorCodeFrozen );
        ret = (errorCodeFrozen == CCT_CCHECKDATA_NO_ERROR) ? true : false;
      }
      else
      {
        ret = true;
      }

      return ret;
    }

    /// Check if a value is within a given range [minimum, maximum]
    /// @tparam    T       The data type of the value.
    /// @param[in] val     The value to be checked.
    /// @param[in] minimum The minimum value of the given range.
    /// @param[in] maximum The maximum value of the given range.
    /// @return            Returns \a true if the value is within the given range, otherwise \a false.
    template <typename T>
    static bool isInRange (const T& val, const T& minimum, const T& maximum)
    {
      return ( (val >= minimum) && (val <= maximum) );
    }

    /// Check if a value is outside of a given range [minimum, maximum]
    /// @tparam    T       The data type of the value.
    /// @param[in] val     The value to be checked.
    /// @param[in] minimum The minimum value of the given range.
    /// @param[in] maximum The maximum value of the given range.
    /// @return            Returns \a true if the value is outside of the given range, otherwise \a false.
    template <typename T>
    static bool notInRange (const T& val, const T& minimum, const T& maximum)
    {
      return !isInRange(val, minimum, maximum);
    }

    /// Check if a value is equal to its last stored value.
    /// The current value will be stored for next check.
    /// @tparam         T       The data type of the value.
    /// @param[in]      val     The value to be checked.
    /// @param[in, out] pastVal The last stored value with initialization information.
    /// @return                 Returns \a true if the value is not equal to its last value, otherwise \a false.
    template <typename T>
    static bool isChanging (const T& val, SPastValue<T>& pastVal)
    {
      const bool ret = pastVal.isInitialized && isChanging(val, pastVal.val);
      pastVal.set(val);
      return ret;
    }

    /// Check if a value is equal to a given value.
    /// @tparam    T       The data type of the value.
    /// @param[in] val     The value to be checked.
    /// @param[in] pastVal The given value to be compared with.
    /// @return            Returns \a true if the value is not equal to the given value, otherwise \a false.
    template <typename T>
    static bool isChanging (const T& val, const T& pastVal)
    {
      return val != pastVal;
    }

    /// Check if a value is equal to its last stored value.
    /// The current value will be stored for next check.
    /// @tparam         T       The data type of the value.
    /// @param[in]      val     The value to be checked.
    /// @param[in, out] pastVal The last stored value with initialization information.
    /// @return                 Returns \a true if the value is equal to its last value, otherwise \a false.
    template <typename T>
    static bool notChanging (const T& val, SPastValue<T>& pastVal)
    {
      const bool ret = pastVal.isInitialized && notChanging(val, pastVal.val);
      pastVal.set(val);
      return ret;
    }

    /// Check if a value is equal to a given value.
    /// @tparam    T       The data type of the value.
    /// @param[in] val     The value to be checked.
    /// @param[in] pastVal The given value to be compared with.
    /// @return            Returns \a true if the value is equal to the given value, otherwise \a false.
    template <typename T>
    static bool notChanging (const T& val, const T& pastVal)
    {
      return !isChanging(val, pastVal);
    }

    /// Check if the absolute difference between a value and its last stored value is within a given range.
    /// The current value will be stored for next check.
    /// @tparam         T              The data type of the value.
    /// @param[in]      val            The value to be checked.
    /// @param[in, out] pastVal        The last stored value with initialization information.
    /// @param[in]      maxDiffAllowed The given range for the absolute difference.
    /// @return                        Returns \a true if the absolute difference is not within the given range, otherwise \a false.
    template <typename T>
    static bool changingTooMuch (const T& val, SPastValue<T>& pastVal, const T& maxDiffAllowed)
    {
      bool ret;

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
    /// @tparam    T   Type of values given and result.
    /// @param[in] lhs First operand of operation
    /// @param[in] rhs Second operand of operation
    /// @return        Positive delta between @a lhs and @a rhs.
    template <typename T>
    static T absDiff( const T& lhs, const T& rhs )
    {
      return (lhs > rhs) ? (lhs - rhs) : (rhs - lhs);
    }

    /// Check if the absolute difference between a value and a given value is within a given range.
    /// @tparam    T              The data type of the value.
    /// @param[in] val            The value to be checked.
    /// @param[in] pastVal        The given value to be compared with.
    /// @param[in] maxDiffAllowed The given range for the absolute difference.
    /// @return                   Returns \a true if absolute difference is not within the given range, otherwise \a false.
    template <typename T>
    static bool changingTooMuch (const T& val, const T& pastVal, const T& maxDiffAllowed)
    {
      typedef typename cml::make_signed<T>::type SignedT;
      
      return isOutOfRange(val, pastVal, -static_cast<SignedT>(maxDiffAllowed), static_cast<SignedT>(maxDiffAllowed));
    }

    /// Checks whether @a val is within range [@a base + @a lowerLimit .. @a base + @a upperLimit]
    /// Limitation: difference between @a val and @a base must not be greater then max of the signed type variant of @a T
    /// @tparam    T          Type of @a val and @a base
    /// @tparam    TL         Type of @a lowerLimit since it could be different from @a T (typically used for signed vs. unsigned use-cases)
    /// @tparam    TU         Type of @a upperLimit since it could be different from @a T (typically used for signed vs. unsigned use-cases)
    /// @param[in] val        Value to be checked
    /// @param[in] base       Base for the range
    /// @param[in] lowerLimit Lower boundary of range
    /// @param[in] upperLimit Upper boundary of range
    /// @return               True if out of range, false if within range
    template <typename T, typename TL, typename TU>
    static bool isOutOfRange ( const T& val, const T& base, const TL& lowerLimit, const TU& upperLimit )
    {
      typedef typename cml::make_signed<T>::type SignedT;

      // This is overflow resistant due to two's complement representation of int
      const SignedT delta = static_cast<SignedT>(val - base);
      return (delta > static_cast<SignedT>(upperLimit))
        ||   (delta < static_cast<SignedT>(lowerLimit));
    }

    ErrorArray_t m_errorArray; /// Array containing error code and error counter for every error category.

  private:
    bool m_haveError; /// Flag for having any error.

    /// Copy constructor. Hidden to prevent multiple copies.
    CCheckData( const CCheckData& );
    /// Copy operator. Hidden to prevent multiple copies.
    CCheckData& operator=(const CCheckData&);

  public:
    enum { MAX_SIZE = ErrorArray_t::MAX_SIZE }; /// Enumerates MAX_SIZE with the size of the error container array.
  };
}

#endif // em_check_data_h__
