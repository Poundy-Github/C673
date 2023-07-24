#ifndef memory_stack_h__
#define memory_stack_h__

/// @file cct_memory_stack.h Carries the class CMemoryStack.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

#include "algo_glob.h"
#include <new>
#include <cassert>


#ifdef CCT_SIM_DEBUG
#  ifndef NDEBUG
#    include<vector>
#  endif
#endif

namespace cct
{
  /// Class representing a stack based memory management.
  /// It does its work by uitilizing the push() method to retrieve
  /// some memory from the stack, that could be used then to operate on it
  /// after the memory is not required anymore it shall be given back by
  /// calling the pop() method.
  ///
  /// To enable the class to do its work the user has to attach it to some
  /// memory block via the attach() method. It will then manage this memory
  /// block as a stack.
  ///
  /// @section live-cycle Live Cycle:
  /// Here is an overview of the live cycle of the class. It is important to stick to it,
  /// otherwise the user will create memory exceptions. Especially make sure that the sizes
  /// and number of push() calls fits the sizes and number of pop() calls.
  /// @startuml cct_memory_stack_live_cycle.png
  /// (*)               --> "CMemoryStack()"
  /// "CMemoryStack()"  --> "attach()"
  /// note right: Connects the class with some memory block
  /// "attach()"        --> "push()"
  /// note left: Reserves (a part) of the memory
  ///
  /// "push()"          --> "pop()"
  /// note left: Cancels reservation of (a part) of the memory
  ///
  /// "pop()"           --> "push()"
  ///
  /// "push()"          --> "push()"
  /// "pop()"           --> "pop()"
  ///
  ///
  /// "pop()"           --> "~CMemoryStack()"
  /// "~CMemoryStack()" --> (*)
  /// @enduml
  ///
  /// In fact, the class does not allocate or deallocate memory. It just keeps track
  /// of the blocks of memory the user requests via push() and gives back with pop().
  class CMemoryStack
  {
  public:
    // PRQA S 4054 L_CONSTRUCTORS
    // date: 2015-17-07, reviewer: Christian Exner
    // reason: QAC-Bug: Misra rule 12-1-2 is about explicitly calling of all immediate base and virtual base classes,
    // not about member initialization. Also we initialize our members via the attach method, that is called from all
    // constructors.

#ifndef NDEBUG
    /// Creates an empty memory stack.
    /// In case of debug mode:
    /// Initializes the internal m_data member to NULL.
    /// This constructor with the NULL initialization  only lives in the debug case
    /// to check wether the class is used corectly
    /// by initializing the m_data and thus enabeling the other methods to check it
    /// via assert(). The initialization shall happen via the attach() method.
    ///
    /// @warning In non-debug mode, nothing is initialized. The user has to take care to respect the @ref live-cycle "live cycle" of the class
    ///          mentioned before!
    CMemoryStack()
    {
      // we need this only for the asserts
      attach (reinterpret_cast<sint8*>(0), 0);
    }
#endif

    /// Creates a memory stack and attaches ot to the given memory and size.
    /// Afterwards, up to @a _size bytes of data could be reserved via push().
    /// It does its work by just calling push() with the given arguments.
    /// @param _memory Pointer to memory organized in bytes.
    /// @param _size   Byte size of the memory behind the pointer given as @a _memory.
    CMemoryStack(sint8* const _memory, const uint32 _size)
    {
      attach (_memory, _size);
    }

    /// @copydoc CMemoryStack(sint8* const, const uint32)
    CMemoryStack(uint8* const _memory, const uint32 _size)
    {
      attach (_memory, _size);
    }

    // PRQA L:L_CONSTRUCTORS

    /// Attaches the memory stack to the given memory pointer.
    /// Attaching means: Remember the parameters given (pointer and size of memory)
    /// to be able to manage the push() and pop() calls. No allocation / deallocation
    /// happens!
    ///
    /// It will directly detach it from a (possibly) previously attached memory block by
    /// reseting the internal m_size member back to 0.
    ///
    /// If CCT_SIM_DEBUG is defined it also resets the maximum size ever reserved to 0.
    /// @param _memory Pointer to memory organized in bytes.
    /// @param _size   Byte size of the memory behind the pointer given as @a _memory.
    void attach (sint8* const _memory, const uint32 _size)
    {
      m_data     = _memory;
      m_capacity = _size;
      m_size     = 0;

#ifdef CCT_SIM_DEBUG
      debug.maxSize  = 0;
#endif
    }

    /// @copydoc attach (sint8* const, const uint32)
    void attach (uint8* const _memory, const uint32 _size)
    {
      attach(reinterpret_cast<sint8*>(_memory), _size);
    }

    /// Returns constructed class T and reserve sizeof(T) bytes on the stack.
    /// In debug mode it also checks wether enough memory is available and triggers
    /// a runtime break if not.
    /// @warning In non-debug mode it will just use the memory required without checking
    ///          checking boundaries!
    /// Be concentrated when using this method - The number and summed sizes of push() calls
    /// has to be exactly the same as the number and summed sizes of pop() calls!
    ///
    /// Internaly it utilizes the pushBytes() method to reserve the memory and get a pointer to
    /// it and then class the new() operator (placement version) to construct the class onto
    /// that memory block.
    ///
    /// If CCT_SIM_DEBUG is defined it also keeps track of the maximum sum of bytes reserved over
    /// the livetime of the stack instance.
    /// @tparam T Type name of type to be pushed to the memory stack
    /// @return Reference to the newly placed type on the memory stack
    template <class T> T& push()
    {
      // PRQA S 5118 5
      // date: 2015-17-07, reviewer: Christian Exner
      // reason: QAC-Bug: This is the placement version of the new() operator.
      // Misra rule 18-4-1 clearly allows this version: "The built-in new and delete operators,
      // OTHER THAN THE PLACEMENT VERSIONS, use dynamic heap memory."
      return *new (pushBytes(sizeof(T))) T;
    }
    /// Give back memory for given class T and decrement stack by sizeof(T).
    /// In debug mode it also checks wether enough memory was reserved before doing the pop. It
    /// triggers a runtime break (via assert()) when not.
    /// @warning In non-debug mode it will just remove the reserved memory without checking. If
    ///          used wrong the m_size member will wrap around and the class is in an undefined state.
    /// @warning Do not use the given reference afterwards!
    /// Internaly it will utilize the popBytes() method to do its work.
    ///
    /// If CCT_SIM_DEBUG is defined it also keeps track of the maximum sum of bytes reserved over
    /// the livetime of the stack instance.
    /// @tparam T Type name of type to be pushed to the memory stack
    template <class T> void pop (const T&) { popBytes(sizeof(T)); }

    /// Retrieves current reserved size of the stack.
    /// @return Number of bytes currently reserved on the stacks memory block.
    uint32 size()     const { return m_size;     }
    /// Retrieves maximum size that could be (in sum) reserved on the stack.
    /// That is the size given to the constructors or attach() method call.
    /// @return Number of bytes that could be reserved in sum on this instance of the stack.
    uint32 capacity() const { return m_capacity; }

  private:

    /// Aligns x onto \f$ 2^{SHIFT} \f$ bytes.
    /// @tparam SHIFT Used as power of 2 for specifying the alignment. E.g. if set to 3 it means that align up rounds up the given size @a x to integer multiples of 8 (bytes).
    /// @param  x Number of bytes to be aligned to the specified power of 2.
    /// @return Number of bytes given via @a x rounded up to \f$ 2^{SHIFT} \f$ bytes.
    template <uint32 SHIFT>
    static uint32 alignUp( const uint32& x )
    {
      static const uint32 ALIGNBYTES = 1U << SHIFT;

      return ( (x - 1U) & ~(ALIGNBYTES - 1U) ) + ALIGNBYTES;
    }

    /// Returns memory of given size and increments stack by given size.
    /// In debug mode it also checks wether enough memory is available and triggers
    /// a runtime break if not.
    /// @warning In non-debug mode it will just use the memory required without checking
    ///          checking boundaries!
    /// Be concentrated when using this method - The number and summed sizes of push() calls
    /// has to be exactly the same as the number and summed sizes of pop() calls!
    /// @param _size Number of bytes to reserve on the stack
    /// @return Pointer to the begining of the memory block just reserved.
    sint8* pushBytes (const uint32 _size)
    {
      // ensure that we have been given a pointer to memory
      assert (m_data != 0);
      // align memory to 8 byte boundary
      const uint32 alignedSize = alignUp<3U>( _size );
      // ensure that we stay in the assigned memory
      assert ((m_size + alignedSize) <= m_capacity);

      // calculate the pointer to memory
      // PRQA S 3706 5
      // date: 2015-17-07, reviewer: Christian Exner, reason: We need pointer arithmetics here since the class is used
      // in connection with a pointer interface. So it is not possible to store a reference to an
      // array here to circumvent the pointer arithmetics, since we can't cast an arbitrary pointer to an array reference.
      // Also the use case of dynamic attach would have been lost then.
      sint8* p = &m_data[m_size];
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
    /// In debug mode it also checks wether enough memory was reserved before doing the pop. It
    /// triggers a runtime break (via assert()) when not.
    /// @warning In non-debug mode it will just remove the reserved memory without checking. If
    ///          used wrong the m_size member will wrap around and the class is in an undefined state.
    /// @warning Do not use the reference retrieved via a previous push() call afterwards!
    /// @param _size Number of bytes to unreserve on the stack.
    void popBytes (const uint32 _size)
    {
      const uint32 alignedSize = alignUp<3U>( _size );
      assert (alignedSize <= m_size);
      m_size -= alignedSize;

#ifdef CCT_SIM_DEBUG
# ifndef NDEBUG
      assert (debug.pushSizes.size()  > 0);    // assert pop follows push
      assert (debug.pushSizes.back() == _size); // assert pop order is inverse of push order
      // remove size from push vector
      debug.pushSizes.pop_back();
# endif
#endif
    }

    /// The pointer to the beginning of the memory block available to the stack. Set / initialized by attach().
    sint8* m_data;
    /// The size of the memory block available to the stack. Set / initialized by attach().
    uint32 m_capacity;
    /// The current number of bytes reserved / in use on the stack. Changed by push(), pop()
    uint32 m_size;

#ifdef CCT_SIM_DEBUG
    /// Structure for storing additional debugging data.
    /// Only available if CCT_SIM_DEBUG is defined and it uses STL std::vector for its work!
    /// @sa push(), pop(), attach()
    struct SDebug
    {
      uint32 maxSize; ///< The number of bytes reserved at maximum throughout the life time after the last attach() call.
#ifndef NDEBUG
      std::vector<uint32> pushSizes; ///< The trace of the push() calls that happend throughout the life time after the last attach() call.
#endif
    };
    mutable SDebug debug; ///< The instance of the debug structure. @sa SDebug
#endif
  };
}

#endif // memory_stack_h__
