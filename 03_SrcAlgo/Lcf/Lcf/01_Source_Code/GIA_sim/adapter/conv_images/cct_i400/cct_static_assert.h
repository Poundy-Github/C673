#ifndef cct_static_assert_h__
#define cct_static_assert_h__

#include "algo_type.h"

namespace cct
{
  /// Static assert for compile time checks.
  ///
  /// Usage:
  /// \code
  /// cct::STATIC_ASSERT< condition >();
  /// \endcode
  ///
  /// When condition is true, the code compiles. If it is false
  /// a compiler error is generated, that complains about the non-
  /// existent implementation of the constructor of the class.
  ///
  /// Example:
  /// \code
  /// cct::STATIC_ASSERT< 7 >  6 >(); // will compile
  /// cct::STATIC_ASSERT< 7 == 6 >(); // won't compile
  template <boolean_t COND> class STATIC_ASSERT{ public: STATIC_ASSERT(){}; }; //!< Static assert for the true case. Will compile
  template <>               class STATIC_ASSERT<false>;                        //!< Static assert for the false case. Won't compile
}

#endif // cct_static_assert_h__
