#ifndef cct_stl_algorithm_h__
#define cct_stl_algorithm_h__

/// @file cct_stl_algorithm.h Reimplemantation of STL algorithm without using heap and/or DSP efficient.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

namespace cct
{
  /// Find a value in range.
  /// Returns an iterator to the first element in the range [@a first ,@a last ) that satisfies the condition given by the unary predicate.
  /// If no such element is found, the function returns iterator to @a last.
  /// The predicate should have an overloaded operator()(const type&) if it is a class or be a function pointer to a method accepting (const type&).
  /// @tparam          InputIterator  Iterator to the element array
  /// @tparam          UnaryPredicate Type of the unary predicate.
  /// @param[in]       first          Iterator to the start address of array of elements
  /// @param[in]       last           Iterator to the element after the last element to be examined.
  /// @param[in]       pred           Unary predicate which returns true for the required element.
  /// @return                         Iterator to the first element satisfying the condition or @a last if no such element is found.
  template<class InputIterator, class UnaryPredicate>
  static InputIterator find_if (InputIterator first, const InputIterator last, const UnaryPredicate& pred)
  {
    for (; first != last; ++first)
    {
      if (pred(*first))
      {
        break;
      }
    }
    return first;
  }
}
#endif // cct_stl_algorithm_h__
