#ifndef memory_stack_h__
#define memory_stack_h__

#include "algo_type.h"
#include <new>
#include <cassert>

#ifdef CCT_SIM_DEBUG
#  ifndef NDEBUG
#    include<vector>
#  endif
#endif

namespace cct
{
  class CMemoryStack
  {
  public:
#ifndef NDEBUG
    /// Creates an empty memory stack
    CMemoryStack()
    {
      // we need this only for the asserts
      attach (reinterpret_cast<sint8*>(0), 0);
    }
#endif

    /// Creates a memory stack and attaches ot to the given memory and size
    CMemoryStack(sint8* const memory, const uint32 size)
    {
      attach (memory, size);
    }

    /// Creates a memory stack and attaches ot to the given memory and size
    CMemoryStack(uint8* const memory, const uint32 size)
    {
      attach (memory, size);
    }

    /// Attaches the memory stack to the given memory pointer.
    /// It will directly detach it from a previous memory block.
    void attach (sint8* const memory, const uint32 size)
    {
      m_data     = memory;
      m_capacity = size;
      m_size     = 0;

#ifdef CCT_SIM_DEBUG
      debug.maxSize  = 0;
#endif
    }

    void attach (uint8* const memory, const uint32 size)
    {
      attach(reinterpret_cast<sint8*>(memory), size);
    }

    /// Return memory for given class T and increment the stack by sizeof(T).
    /// This will not call the constructor of T!
    template <class T> T& push() { return *new (pushBytes(sizeof(T))) T; }
    
    /// Give back memory for given class T and decrement stack by sizeof(T)
    /// Do not use the given reference afterwards!
    template <class T> void pop (const T&) { popBytes(sizeof(T)); }

    /// Retrieves current size of the stack
    uint32 size()     const { return m_size;     }
    /// Retrieves allocated size of the stack. This is the valid maximum size.
    uint32 capacity() const { return m_capacity; }
    
  private:

    /// Aligns x onto 2^SHIFT bytes
    template <uint32 SHIFT>
    static uint32 alignUp( const uint32& x )
    {
      static const uint32 ALIGNBYTES = 1U << SHIFT;

      return ( (x - 1U) & ~(ALIGNBYTES - 1U) ) + ALIGNBYTES;
    }

    /// Returns memory of given size and increments stack by given size
    sint8* pushBytes (const uint32 size)
    {
      // ensure that we have been given a pointer to memory
      assert (m_data != 0);
      // align memory to 8 byte boundary
      const uint32 alignedSize = alignUp<3U>( size );
      // ensure that we stay in the assigned memory
      assert ((m_size + alignedSize) <= m_capacity);
      // calculate the pointer to memory
      sint8* p = m_data + m_size;
      // increment the current size
      m_size += alignedSize;

#ifdef CCT_SIM_DEBUG
      // update max size
      if ( debug.maxSize < m_size )
      {
        debug.maxSize = m_size;
      }

# ifndef NDEBUG
      // add pushed size for verification
      debug.pushSizes.push_back(alignedSize);
# endif

#endif

      return p;
    }

    /// Gives back memory of given size and decrement stack by given size.
    void popBytes (const uint32 size)
    {
      const uint32 alignedSize = alignUp<3U>( size );
      assert (alignedSize <= m_size);
      m_size -= alignedSize;

#ifdef CCT_SIM_DEBUG
# ifndef NDEBUG
      assert (debug.pushSizes.size()  > 0);    // assert pop follows push
      assert (debug.pushSizes.back() == size); // assert pop order is inverse of push order
      // remove size from push vector
      debug.pushSizes.pop_back();
# endif
#endif
    }

    /// The pointer to the beginning of the memory block
    sint8* m_data;
    /// The size of the memory block attached
    uint32 m_capacity;
    /// The current size of the stack
    uint32 m_size;

#ifdef CCT_SIM_DEBUG
    struct SDebug
    {
      uint32 maxSize;
#ifndef NDEBUG
      std::vector<uint32> pushSizes;
#endif
    };
    mutable SDebug debug;
#endif
  };
}

#endif // memory_stack_h__
