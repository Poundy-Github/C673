#ifndef cct_circular_shift_h__
#define cct_circular_shift_h__

#include "glob_type.h"

namespace cct
{
  /// Perform left circular bit shift of the number.
  /// @param[in] val number on which bit shifting is performed.
  /// @param[in] n number of bit shifts.
  /// @return n bits circularly left shifted value.
  template <sint8 NBITS>
  static inline sint8 circShiftLeft(const sint8 val, const sint8 n) 
  {
    const sint8 mask = std::numeric_limits<sint8>::max() & ~(std::numeric_limits<sint8>::max() << NBITS);
    assert(NBITS > 0);
    assert ((val >= 0) && (val <= mask));
    assert ((n <= NBITS) && (n >= 0));
    return (((val << n) | (val >> (NBITS - n))) & mask);
  }

  /// Perform right circular bit shift of the number.
  /// @param[in] val number on which bit shifting is performed.
  /// @param[in] n number of bit shifts.
  /// @return n bits circularly right shifted value.
  template <sint8 NBITS>
  static inline sint8 circShiftRight(const sint8 val, const sint8 n) 
  {
    const sint8 mask = std::numeric_limits<sint8>::max() & ~(std::numeric_limits<sint8>::max() << NBITS);
    assert(NBITS > 0);
    assert ((val >= 0) && (val <= mask));
    assert ((n <= NBITS) && (n >= 0));
    return (((val >> n) | val << ((NBITS - n))) & mask);
  }
}
#endif
