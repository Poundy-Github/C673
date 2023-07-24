#ifndef cct_ring_buffer_h__
#define cct_ring_buffer_h__

/// @file cct_ring_buffer.h Ring buffer implementation without using heap (max size is template parameter).

#include "cml_ext_cpp.h"

namespace cct
{
  /// Class implementing a ring buffer of \a SIZE elements with dynamic array usage.
  /// The ring buffer is increasing dynamically its size until the size reaches \a SIZE.
  /// Afterwards it overwrites the oldest element in the buffer.
  /// @tparam T       The type of the elements
  /// @tparam SIZE    The size of the underlying array
  /// @tparam EXT_MEM Flag whether the memory of the elements of the array is inside
  ///                 of this class (\a false) or outside of this class (\a true).
  ///                 Default is false, meaning internal memory.
  template < class T, sint32 SIZE, bool EXT_MEM = false >
  class RingBuffer : public cml::CArrayStorage<T, SIZE, EXT_MEM>
  {
  public:
    typedef RingBuffer<T, SIZE, EXT_MEM>         self;            ///< The current specialization.
    typedef cml::CArrayStorage<T, SIZE, EXT_MEM> super;           ///< The father class.
    typedef sint32                               size_type;       ///< Integer as size type.
    typedef typename cml::remove_const<T>::type  type;            ///< The non-const type of \a T
    typedef typename    cml::add_const<T>::type  const_type;      ///< The const type of \a T
    typedef typename cml::remove_const<T>::type& reference;       ///< The non-const reference to \a T
    typedef typename    cml::add_const<T>::type& const_reference; ///< The const reference to \a T

    /// Default empty constructor.
    /// Default constructor of the father is called. \a m_size and \a m_nextPosition are initialized with 0.
    RingBuffer() : super(), m_nextPosition(0), m_size(0) {}

    /// Constructor with reference to array of possibly different size than this.
    /// @tparam          SIZE2         The size of the array
    /// @param[in]       _data         Data with \a SIZE2
    /// @param[in]       _size         Current size
    /// @param[in]       _nextPosition Position of the next element to insert
    template< sint32 SIZE2 >
    explicit RingBuffer(       type (&_data)[SIZE2], const size_type _size = 0, const size_type _nextPosition = 0 ) : super(_data), m_size(_size), m_nextPosition(_nextPosition) {}

    /// Constructor with reference to constant array of possibly different size than this.
    /// @tparam          SIZE2         The size of the array
    /// @param[in]       _data         Data with \a SIZE2
    /// @param[in]       _size         Current size
    /// @param[in]       _nextPosition Position of the next element to insert
    template< sint32 SIZE2 >
    explicit RingBuffer( const_type (&_data)[SIZE2], const size_type _size = 0, const size_type _nextPosition = 0 ) : super(_data), m_size(_size), m_nextPosition(_nextPosition) {}

    /// Constructor with a constant CArrayStorage object of data
    /// and possibly different size and EXT_MEM setting.
    /// @tparam          SIZE2         The size of the array
    /// @tparam          EXT_MEM2      Flag whether the memory of the elements of the array is inside
    ///                                of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs           External CArrayStorage data with \a SIZE2
    /// @param[in]       _size         Current size
    /// @param[in]       _nextPosition Position of the next element to insert
    template< sint32 SIZE2, bool EXT_MEM2 >
    explicit RingBuffer( const cml::CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs, const size_type _size = 0, const size_type _nextPosition = 0 ) : super(rhs), m_size(_size), m_nextPosition(_nextPosition) {}

    /// Constructor with a constant CArrayStorage object of constant data
    /// and possibly different size and EXT_MEM setting.
    /// @tparam          SIZE2         The size of the array
    /// @tparam          EXT_MEM2      Flag whether the memory of the elements of the array is inside
    ///                                of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs           External CArrayStorage data with \a SIZE2
    /// @param[in]       _size         Current size
    /// @param[in]       _nextPosition Position of the next element to insert
    template< sint32 SIZE2, bool EXT_MEM2 >
    explicit RingBuffer( const cml::CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs, const size_type _size = 0, const size_type _nextPosition = 0 ) : super(rhs), m_size(_size), m_nextPosition(_nextPosition) {}

    /// Constructor with a CArrayStorage object of data
    /// and possibly different size and EXT_MEM setting.
    /// @tparam          SIZE2         The size of the array
    /// @tparam          EXT_MEM2      Flag whether the memory of the elements of the array is inside
    ///                                of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs           External CArrayStorage data with \a SIZE2
    /// @param[in]       _size         Current size
    /// @param[in]       _nextPosition Position of the next element to insert
    template< sint32 SIZE2, bool EXT_MEM2 >
    explicit RingBuffer( cml::CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs, const size_type _size = 0, const size_type _nextPosition = 0 ) : super(rhs), m_size(_size), m_nextPosition(_nextPosition) {}

    /// Constructor with a CArrayStorage object of constant data
    /// and possibly different size and EXT_MEM setting.
    /// @tparam          SIZE2         The size of the array
    /// @tparam          EXT_MEM2      Flag whether the memory of the elements of the array is inside
    ///                                of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs           External CArrayStorage data with \a SIZE2
    /// @param[in]       _size         Current size
    /// @param[in]       _nextPosition Position of the next element to insert
    template< sint32 SIZE2, bool EXT_MEM2 >
    explicit RingBuffer( cml::CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs, const size_type _size = 0, const size_type _nextPosition = 0 ) : super(rhs), m_size(_size), m_nextPosition(_nextPosition) {}

    /// Copy constructor with an object of the same RingBuffer class
    /// @param[in]       rhs       External RingBuffer data with \a SIZE
    explicit RingBuffer(const self& rhs) : super(rhs), m_size(rhs.size()), m_nextPosition(rhs.nextPosition()) {}

    /// Copy constructor with a constant RingBuffer object of data
    /// and possibly different size and EXT_MEM setting.
    /// @tparam          SIZE2     The size of the ring buffer
    /// @tparam          EXT_MEM2  Flag whether the memory of the elements of the ring buffer is inside
    ///                            of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs       External RingBuffer data with \a SIZE2
    template< sint32 SIZE2, bool EXT_MEM2 >
    explicit RingBuffer( const RingBuffer<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(rhs.size()), m_nextPosition(rhs.nextPosition()) {}

    /// Copy constructor with a constant RingBuffer object of constant data
    /// and possibly different size and EXT_MEM setting.
    /// @tparam          SIZE2     The size of the ring buffer
    /// @tparam          EXT_MEM2  Flag whether the memory of the elements of the ring buffer is inside
    ///                            of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs       Reference to the constant external RingBuffer data with \a SIZE2
    template< sint32 SIZE2, bool EXT_MEM2 >
    explicit RingBuffer( const RingBuffer<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(rhs.size()), m_nextPosition(rhs.nextPosition()) {}

    /// Copy constructor with a RingBuffer object of data
    /// and possibly different size and EXT_MEM setting.
    /// @tparam          SIZE2     The size of the ring buffer
    /// @tparam          EXT_MEM2  Flag whether the memory of the elements of the ring buffer is inside
    ///                            of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs       External RingBuffer data with \a SIZE2
    template< sint32 SIZE2, bool EXT_MEM2 >
    explicit RingBuffer( RingBuffer<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(rhs.size()), m_nextPosition(rhs.nextPosition()) {}

    /// Copy constructor with a RingBuffer object of constant data
    /// and possibly different size and EXT_MEM setting.
    /// @tparam          SIZE2     The size of the ring buffer
    /// @tparam          EXT_MEM2  Flag whether the memory of the elements of the ring buffer is inside
    ///                            of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs       External RingBuffer data with \a SIZE2
    template< sint32 SIZE2, bool EXT_MEM2 >
    explicit RingBuffer( RingBuffer<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(rhs.size()), m_nextPosition(rhs.nextPosition()) {}

    /// Always makes a copy of the data and never attaches.
    /// This is not automatically generated by templated version
    /// according to Misra rule 14-5-3.
    /// @param[in]       rhs    External constant data buffer of identical size
    /// @return          Reference to this object
    self& operator=(const self& rhs)
    {
      super::operator=(rhs);
      m_size         = rhs.size();
      m_nextPosition = rhs.nextPosition();
      return *this;
    }

    /// Copies the constant RingBuffer object data to the buffer of this.
    /// @tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
    ///                            of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs       External RingBuffer data buffer of identical size
    /// @return          Reference to this object
    template< bool EXT_MEM2 >
    self& operator=(const RingBuffer<      type, SIZE, EXT_MEM2>& rhs)
    {
      super::operator=(rhs);
      m_size         = rhs.size();
      m_nextPosition = rhs.nextPosition();
      return *this;
    }

    /// Copies the constant RingBuffer object of constant data to the buffer of this.
    /// @tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
    ///                            of this class (\a false) or outside of this class (\a true).
    /// @param[in]       rhs       External data buffer of identical size
    /// @return          Reference to this object
    template< bool EXT_MEM2 >
    self& operator=(const RingBuffer<const_type, SIZE, EXT_MEM2>& rhs)
    {
      super::operator=(rhs);
      m_size         = rhs.size();
      m_nextPosition = rhs.nextPosition();
      return *this;
    }

    /// Clear the ring buffer by setting size to zero.
    /// Memory is not cleared.
    void clear()
    {
      m_size         = 0;
      m_nextPosition = 0;
    }

    // This is only required for TI-Compiler to be able to compile
    // PRQA S 2524 5
    // date: 2016-27-10, reviewer: Jan Fraedrich, reason:
    // QAC Bug, since this using declaration is within the class scope.
    // The according MISRA rule 7-3-6 states: "using-directives and using-declarations
    // (EXCLUDING CLASS SCOPE OR FUNCTION SCOPE USING-DECLARATIONS) shall not be used in header files."
    using super::max_size;
    // End of section required for TI-Compiler

    /// Function returning number of elements in the underlying array.
    /// Constant member function returning current number of elements
    /// in the ring buffer.
    /// @return Number of elements in the array
    size_type size() const
    {
      return m_size;
    }

    /// Function returning the position in the underlying array where the next element will be inserted.
    /// Constant member function returning current position for the next element to insert
    /// in the ring buffer.
    /// @return Index of next position an element will be inserted into the buffer
    size_type nextPosition() const
    {
      return m_nextPosition;
    }

    /// Check whether the ring buffer is empty or not.
    /// Constant member function to check whether the ring buffer
    /// is empty or not.
    /// @return Return \a true if vector list is empty, \a false if not
    bool empty() const
    {
      return (m_size == 0);
    }

    /// Check whether the ring buffer is full or not.
    /// Constant member function to check whether the ring buffer
    /// is full or not.
    /// @return Return \a true if vector list is full, \a false if not
    bool full() const
    {
      return (m_size >= SIZE);
    }

    /// Returns the current first element of the ring buffer.
    /// @return Reference to most recent updated element of the ring buffer.
    reference front()
    {
      return operator[](0);
    }

    /// Returns the current first element of the ring buffer
    /// @return Constant reference to most recent updated element of the ring buffer
    const_reference front() const
    {
      return operator[](0);
    }

    /// Returns the current last / oldest element in the ring buffer.
    /// @return Reference to oldest element in the ring buffer.
    reference back()
    {
      return operator[](size() - 1);
    }

    /// Returns the last / oldest element in the ring buffer
    /// @return Constant reference to oldest element of the ring buffer
    const_reference back() const
    {
      return operator[](size() - 1);
    }

    /// Returns the element at given position.
    /// The element at position 0 is the last element added and \ size() - 1 is the oldest element in the ring buffer.
    /// Asserts that position is inside of the array
    /// @param[in] position Position of the element
    /// @return             Reference to the array element at given position
    reference operator[](const size_type position)
    {
      // polyspace +2 RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."
      assert((position >= 0) && (position < size()));
      assert(position <= (m_nextPosition + (SIZE -1)));
      return m_data[(m_nextPosition + (SIZE - 1) - position)%SIZE];
    }

    /// Returns a constant reference to the element at given position.
    /// The element at position 0 is the last element added and \a size() - 1 is the oldest element in the ring buffer.
    /// Asserts that position is inside of the array.
    /// @param[in] position Position of the element
    /// @return             Constant reference to the array element at given position
    const_reference operator[](const size_type position) const
    {
      // polyspace +2 RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."
      assert((position >= 0) && (position < size()));
      assert(position <= (m_nextPosition + (SIZE -1)));
      return m_data[(m_nextPosition + (SIZE - 1) - position)%SIZE];
    }

    /// Append input element at the end of ring buffer. Enlarges the ring buffer if necessary or if the buffer is full it overwrites the oldest element.
    /// Asserts if size is less than \ SIZE and position of next element to insert is smaller or equal to current size.
    /// @param[in] x Constant reference to value to be filled
    void push_back(const_reference x)
    {
      // polyspace +2 RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."assert(size() <= SIZE);
      assert(size() <= SIZE);
      assert(m_nextPosition <= size());
      if(!full())
      {
        ++m_size;
      }
      ++m_nextPosition;
      m_nextPosition = m_nextPosition%SIZE;
      front() = x;
    }

    /// Returns the next element to overwrite. Enlarges the ring buffer if necessary and gives back the new element. If the buffer is full it gives back a reference to the oldest element.
    /// Asserts if size is less than \a SIZE and position of next element to insert is smaller or equal to current size.
    /// @return Reference to new element after push back
    reference push_back()
    {
      // polyspace +2 RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."
      assert(size() <= SIZE);
      assert(m_nextPosition <= size());
      if(!full())
      {
        ++m_size;
      }
      ++m_nextPosition;
      m_nextPosition = m_nextPosition%SIZE;
      return front();
    }

  private:
    size_type m_nextPosition; ///< Index of the last inserted element.
    size_type m_size;         ///< Current used size of the ring buffer.

  protected:
    // This is only required for TI-Compiler to be able to compile
    // PRQA S 2524 5
    // date: 2016-27-10, reviewer: Jan Fraedrich, reason:
    // QAC Bug, since this using declaration is within the class scope.
    // The according MISRA rule 7-3-6 states: "using-directives and using-declarations
    // (EXCLUDING CLASS SCOPE OR FUNCTION SCOPE USING-DECLARATIONS) shall not be used in header files."
    using super::m_data;
    // End of section required for TI-Compiler
  };
}
#endif // cct_ring_buffer_h__
