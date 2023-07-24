#ifndef cct_static_assert_h__
#define cct_static_assert_h__

/// @file cct_static_assert.h Implements a template method that resembles some use cases of the static_assert keyword of the C++11 specification.
/// @sa http://en.cppreference.com/w/cpp/keyword/static_assert
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

#include "algo_type.h"

namespace cct
{
  /// Static assert for compile time checks.
  /// It implements the concept of the static_assert keyword of the C++11 specification.
  ///
  /// This is the generic implementation with a generic condition.
  /// Since the specialization for @a COND = false is only declared not defined
  /// any evaluation of the @a COND that leads to false will lead to a compile error
  /// and any evaluation of the @a COND to true will just compile.
  ///
  /// Usage:
  /// @code
  /// cct::STATIC_ASSERT< condition >();
  /// @endcode
  ///
  /// When condition is true, the code compiles. If it is false
  /// a compiler error is generated, that complains about the non-
  /// existent implementation of the constructor of the class.
  ///
  /// Example:
  /// @code
  /// cct::STATIC_ASSERT< 7 >  6 >(); // will compile
  /// cct::STATIC_ASSERT< 7 == 6 >(); // won't compile
  /// @endcode
  /// @sa http://en.cppreference.com/w/cpp/keyword/static_assert
  /// @tparam COND The condition to be evaluated by the compiler.
  template <bool COND> class STATIC_ASSERT{ public: STATIC_ASSERT(){}; }; // Static assert for the true case. Will compile
  template <>          class STATIC_ASSERT<false>;                        // Static assert for the false case. Won't compile
}

#endif // cct_static_assert_h__
