#ifndef cct_double_buffer_h__
#define cct_double_buffer_h__

/// @file cct_double_buffer.h Simple double buffer template class.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

#include "cml_ext_cpp.h"

namespace cct
{
  /// Simple double buffer container.
  /// Carries a two-elemented cml::CArray to hold the contents and
  /// offers the typical use cases to get the front and back of the buffer
  /// as well as the swapping.
  /// It realizes its functionality by using 2 indices that point to the
  /// front and back element, such that the getting of front and back is as
  /// fast as possible (simple array access). The swap() method does the only
  /// calculation.
  /// @tparam T Container element type.
  template<class T>
  class CDoubleBuffer
  {
  public:
    /// Constructor.
    /// Initializes the front and back indices.
    /// @pre  None
    /// @post Ready to use buffer
    CDoubleBuffer() : m_idxFront(0), m_idxBack(1) {}

    /// Writable front element accessor.
    /// Can be used to retrieve and to write data to the front element.
    /// @pre  Initialized class instance
    /// @post None
    /// @return A reference to the element out of the internal array that is configured as front (the one that m_idxFront points to).
    T& front() { return m_data[m_idxFront]; }

    /// Writable back element accessor.
    /// Can be used to retrieve and to write data to the back element.
    /// @pre  Initialized class instance
    /// @post None
    /// @return A reference to the element out of the internal array that is configured as back (the one that m_idxBack points to).
    T& back()  { return m_data[m_idxBack ]; }

    /// Read-only front element accessor.
    /// @pre  Initialized class instance
    /// @post None
    /// @return A const reference to the element out of the internal array that is configured as front (the one that m_idxFront points to).
    const T& front() const { return m_data[m_idxFront]; }

    /// Read-only back element accessor.
    /// @pre  Initialized class instance
    /// @post None
    /// @return A const reference to the element out of the internal array that is configured as back (the one that m_idxBack points to).
    const T& back()  const { return m_data[m_idxBack ]; }

    /// Exchanges front and back element.
    /// It realizes it by adding 1 to both index members and applying a modulo of 2 on them.
    /// That efficiently just swaps the front and the back index.
    /// @pre Initialized class instance
    /// @post m_idxFront and m_idxBack are now exchanged.
    void swap()
    {
      m_idxFront = (m_idxFront + 1) % 2;
      m_idxBack  = (m_idxBack  + 1) % 2;
    }

  private:
    cml::CArray<T,2> m_data;     ///< The data container holding two elements of @a T. Written by non-const front() or back() methods. @sa cml::CArray.
    sint8            m_idxFront; ///< The index of the current front element. Initialized by the constructor to 0.
    sint8            m_idxBack;  ///< The index of the current back element. Initialized by the constructor to 1.
  };
}

#endif // cct_double_buffer_h__
