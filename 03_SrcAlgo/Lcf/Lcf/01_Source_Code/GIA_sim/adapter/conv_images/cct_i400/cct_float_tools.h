#ifndef float_tools_h__
#define float_tools_h__

#include "algo_type.h"

#include "cct_static_assert.h"

#include <cassert>
#include <limits>

namespace cct
{
  /// Implements a mathematical floor from float32 to given type.
  /// \return result = static_cast<R>(\a val)
  template <typename R> inline R cast (const float32& val)
  {
    cct::STATIC_ASSERT<std::numeric_limits<R>::is_integer>();

    assert (val <= static_cast<float32>(std::numeric_limits<R>::max()));
    assert (val >= static_cast<float32>(std::numeric_limits<R>::min()));

    return static_cast<R>(val);
  }

  /// Implements a mathematical floor from float32 to given type.
  /// \return result = floor<R>(\a val)
  template <typename R> inline R floorToInt (const float32& val)
  {
    return cast<R>(std::floor(val));
  }

  /// Implements a mathematical round from float32 to given type.
  /// \return result = floor<R>(\a val + 0.5)
  template <typename R> inline R roundToInt (const float32& val)
  {
    const float32 offset = (val < 0.0F) ? -0.5F : 0.5F;
    return cast<R>(val + offset);
  }

  /// Implements a mathematical ceil from float32 to given type.
  /// \return result = ceil<R>(\a val)
  template <typename R> inline R ceilToInt (const float32& val)
  {
    return cast<R>(std::ceil(val));
  }

  /// Implements a mathematical division from float32 to float32.
  /// \return result = float32(1.0F / \a f_val)
  inline float32 invert (const float32 f_val)
  {
    assert(std::abs(f_val) > std::numeric_limits<float32>::epsilon());

#if defined(CCT_USE_INTRINSICS)

    // _TMS320C6700 implementation
    // Fast DSP implementation, using intrinsic for approximating Reciprocal calculation
    // Newton-Rhapson algorithm further extends the mantissa's precision:
    // x[n + 1] = x[n](2 - v × x[n]) (see SPRUFE8B - RCPSP p.411)

    // DSP intrinsics can be emulated(bit exact) with Ti's Host Intrinsic Package
    float32 f_val_inv = _rcpsp(f_val);                    // accuracy 8 bit
    f_val_inv = f_val_inv * (2.0F - f_val * f_val_inv);   // accuracy 16 bit
    f_val_inv = f_val_inv * (2.0F - f_val * f_val_inv);   // full accuracy

#else
    // platform unspecific implementation
    float32 f_val_inv = ( 1.0F / f_val );
#endif

    return f_val_inv;
  }

  /// Implements the power of N for floats using a recursive template.
  /// @return @a val to the power of @a POWER
  template <uint32 POWER>
#ifdef _MSC_VER
  __declspec(deprecated("** This function is deprecated! Use cml::pow **"))
#endif
  inline float32 pow(const float32& val)
  {
    return val * pow<POWER-1>(val);
  }

  /// Implements the power of 0 for floats
  /// @return 1.0F
  template <> inline float32 pow<0>(const float32&)
  {
    return 1.0F;
  }
}

#endif // float_tools_h__
