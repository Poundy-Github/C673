#ifndef float_tools_h__
#define float_tools_h__

/// @file cct_float_tools.h Simple floating point helper functions and DSP optimizations.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

#include "algo_type.h"

#include "cct_static_assert.h"

#ifdef CCT_USE_INTRINSICS
  #ifdef WIN32
    #pragma warning (disable: 4068)
extern "C"
{
    #include "C6xSimulator.h"
}
    #ifndef restrict
      #define restrict
    #endif
  #else
    #include "c6x.h"
  #endif
#endif

#include <cassert>
#include <limits>
#include <cmath>

namespace cct
{
  /// Implements a cast operation from float32 to given integer type.
  /// Mathematical this is equal to a floor operation.
  /// Decimal places are cut off. Overflow is only handled via assaert in debug.
  /// @tparam    R   The return type. Must be integer based, else compile error.
  /// @param[in] val The float value to be casted.
  /// @return static_cast<\a R>(\a val)
  template <typename R>
  static inline R cast (const float32 val)
  {
    cct::STATIC_ASSERT<std::numeric_limits<R>::is_integer>();

    // add or subtract one as decimal digits are cut off during cast
    assert (val < (static_cast<float32>(std::numeric_limits<R>::max()) + 1.0F)); // polyspace RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."
    assert (val > (static_cast<float32>(std::numeric_limits<R>::min()) - 1.0F)); // polyspace RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."

    return static_cast<R>(val);
  }

  /// Implements a mathematical floor from float32 to given integer type using standard library.
  /// @tparam    R   The return type. Must be integer based, else compile error.
  /// @param[in] val The float value to be floored.
  /// @return floor<\a R>(\a val)
  template <typename R>
  static inline R floorToInt (const float32 val)
  {
    return cast<R>(std::floor(val));
  }

  /// Implements a mathematical round from float32 to given integer type.
  /// @tparam    R   The return type. Must be integer based, else compile error.
  /// @param[in] val The float value to be rounded.
  /// @return cast<\a R>(\a val + 0.5 * sgn(\a val))
  template <typename R>
  static inline R roundToInt (const float32 val)
  {
    const float32 offset = (val < 0.0F) ? -0.5F : 0.5F;
    return cast<R>(val + offset);
  }

  /// Implements a mathematical ceil from float32 to given integer type using standard library.
  /// @tparam    R   The return type. Must be integer based, else compile error.
  /// @param[in] val The float value to be ceiled.
  /// @return ceil<\a R>(\a val)
  template <typename R>
  static inline R ceilToInt (const float32 val)
  {
    return cast<R>(std::ceil(val));
  }

  /// Calculates the mathematical reciprocal value of the input.
  /// This function has a variant optimized for TI compiler in case CCT_USE_INTRINSICS is defined.
  /// @param[in] val The float value to be inverted.
  /// @return 1.0F / \a val
  static inline float32 invert (const float32 val)
  {
    assert(val != 0.0f); // polyspace RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."

#if defined(CCT_USE_INTRINSICS)

    // _TMS320C6700 implementation
    // Fast DSP implementation, using intrinsic for approximating Reciprocal calculation
    // Newton-Rhapson algorithm further extends the mantissa's precision:
    // x[n + 1] = x[n](2 - v * x[n]) (see SPRUFE8B - RCPSP p.411)

    // DSP intrinsics can be emulated(bit exact) with Ti's Host Intrinsic Package
    float32 val_inv = _rcpsp(val);              // accuracy 8 bit
    val_inv = val_inv * (2.0F - val * val_inv); // accuracy 16 bit
    val_inv = val_inv * (2.0F - val * val_inv); // full accuracy

#else
    // platform unspecific implementation
    const float32 val_inv = 1.0F / val;
#endif

    return val_inv;
  }

  /// Calculates the mathematical reciprocal value of the square root of the input.
  /// This function has a variant optimized for TI compiler in case CCT_USE_INTRINSICS is defined.
  /// @param[in] val The float value to be rooted and inverted.
  /// @return 1.0F / sqrt(\a val)
  static inline float32 invertSqrt (const float32 val)
  {
    assert(val > 0.0f);

#if defined(CCT_USE_INTRINSICS)

    // _TMS320C6700 implementation
    // Fast DSP implementation, using intrinsic for approximating Reciprocal calculation
    // Newton-Rhapson algorithm further extends the mantissa's precision:
    // x[n + 1] = x[n](1.5 - 0.5*v*x[n]^2) (see SPRUFE8B - RCPSP p.411)

    // DSP intrinsics can be emulated(bit exact) with Ti's Host Intrinsic Package
    float32 val_inv = _rsqrsp(val);                              // 8 bit accuracy
    val_inv = val_inv * (1.5F - (val*0.5F) * (val_inv*val_inv)); // accuracy 16bit
    val_inv = val_inv * (1.5F - (val*0.5F) * (val_inv*val_inv)); // full accuracy

#else
    // platform unspecific implementation
    const float32 val_inv = 1.0F / std::sqrt(val);
#endif

    return val_inv;
  }
}

#endif // float_tools_h__
