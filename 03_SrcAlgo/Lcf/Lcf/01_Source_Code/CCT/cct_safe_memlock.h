#ifndef cct_safe_memlock_h__
#define cct_safe_memlock_h__

/// @file cct_safe_memlock.h Helper class to safely handle L2 and L3 cache memory on DSP.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

#include "algo_glob.h"

#include <cassert>

// PRQA S 7007 EOF
// date: 2015-17-07, reviewer: Christian Exner, reason: QAC-Bug: The number of parameters is always <= 10.

namespace cct
{
  /// Wrapper for L2/L3 memory locking services that makes sure that memory is never accidentally in a locked state ("smart-pointer").
  /// This wrapper uses the memory locking concept described in the following doors document:
  /// @see doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-437-00022807
  /// @see algo_service_types.h for a description of the required inputs and outputs
  ///
  /// Simple example:
  /// @code{.cpp}
  /// void example_func()
  /// {
  ///   cct::CSafeMemlock memLock(m_bswServices, 0, 1024 * 124, COMP_ID_SIB, true);
  ///
  ///   // get detailed information about the lock (note that AS_t_MemScratchReturnCode is acutally a bit field!)
  ///   AS_t_MemScratchReturnCode state = getState();
  ///
  ///   // lockSuccessful() returns true if there were no problems during locking
  ///   if(!memLock.lockSuccessful())
  ///   {
  ///     return false;
  ///   }
  ///   else
  ///   {
  ///     // use pointer to cache
  ///     void* l3Cache = memLock.getLockedL3Pointer();
  ///     sint32 l3Size = memLock.getLockedL3Size();
  ///     // ...
  ///   }
  ///
  ///   // memory is unlocked automatically once memLock variable goes out of scope and is destroyed
  /// }
  /// @endcode
  class CSafeMemlock
  {
  public:
    /// Constructor intializes all member variables
    /// @a m_sizeL2 and @a m_sizeL3 with 0.
    /// @a m_pL2 and @a m_pL3 with @a NULL.
    /// @a m_lockSuccessful with @a false.
    /// @param[in] services      Reference to the set of algo service function pointers to initialize @a m_services.
    /// @param[in] u_sizeBytesL2 The size of L2 memory to be locked. 
    /// @param[in] u_sizeBytesL3 The size of L3 memory to be locked.
    /// @param[in] u_componentId The component ID. See @a glob_comp_id.h
    /// @param[in] b_waitForLock Bool value to wait for a lock. 
    ///                          If set to @a false, the lock will be forced.
    ///                          If set to @a true, it will be waited til the unlock operaton from outside.
    /// @param[in] u_memReqId    Memory request identifier. Valid range is 0..7 for each component.
    ///                          7 is reserved for FUSI memory. Default to 0.
    CSafeMemlock(
      const AS_t_ServiceFuncts& services,
      uint32                    u_sizeBytesL2,
      uint32                    u_sizeBytesL3,
      uint32                    u_componentId,
      boolean                   b_waitForLock,
      uint32                    u_memReqId     = 0)
      : m_services      (services)
      , m_memReqId      (u_memReqId)
      , m_compId        (u_componentId)
      , m_sizeL2        (0)
      , m_sizeL3        (0)
      , m_pL2           (NULL)
      , m_pL3           (NULL)
      , m_retCode       (AS_MEM_SCRATCH_SRV_NOT_AVL)
      , m_lockSuccessful(false)
    {
      // some basic assertions
      assert(NULL != m_services.pfMemScratchLock);         // we need access to the algo services
      assert(!(u_sizeBytesL2 == 0 && u_sizeBytesL3 == 0)); // no memory requested, doesn't make sense
      assert(u_memReqId < 8);                              // memory request identifier. valid range is 0..7 for each component. 7 is reserved for FUSI memory.

      if(m_services.pfMemScratchLock != NULL)
      {
        AS_t_MemScratchReqPort rp = {0}; // initialize struct members to zero
        AS_t_MemScratchProPort pp = {0}; // initialize struct members to zero

        // fill input parameter struct for mem lock
        rp.b_condWait = b_waitForLock;
        rp.u_compId   = u_componentId;
        rp.u_memReqId = u_memReqId;
        rp.u_sizeL2   = u_sizeBytesL2;
        rp.u_sizeL3   = u_sizeBytesL3;

        // call the lock service
        m_retCode = m_services.pfMemScratchLock(&rp, &pp);

        // determine if the lock was completely successful
        m_lockSuccessful = (m_retCode == AS_MEM_SCRATCH_SRV_SUCCESS);

        // access results of lock only if lock was successful, otherwise uninitialized values could be returned
        if(m_lockSuccessful)
        {
          m_pL2 = pp.p_memL2;
          m_pL3 = pp.p_memL3;
          m_sizeL2 = pp.u_sizeL2;
          m_sizeL3 = pp.u_sizeL3;
        }
      }
    }

    /// Destructor unlocks all memory (calls @a unlockAllMemory()).
    ~CSafeMemlock()
    {
      // PRQA S 4631 2
      // date: 2015-17-07, reviewer: Christian Exner, reason: The unlockAllMemory() method does not throw an exception.
      unlockAllMemory();
    }

    /// Was the lock operation successful?
    /// @return @a true if lock was performed successful, @a false elsewise.
    bool lockSuccessful() const
    {
      return m_lockSuccessful;
    }

    /// Get the size of previously locked L2 memory.
    /// @return The size of L2 memory.
    sint32 getLockedL2Size() const
    {
      return m_sizeL2;
    }

    /// Get the size of previously locked L3 memory.
    /// @return The size of L3 memory.
    sint32 getLockedL3Size() const
    {
      return m_sizeL3;
    }

    /// Get the pointer to previously locked L2 memory.
    /// @return The pointer to L2 memory.
    void* getLockedL2Pointer() const
    {
      // PRQA S 4628 3
      // date: 2015-17-07, reviewer: Christian Exner, reason: That is the use-case of the class, manage the locking of the pointers.
      // So only methods that change the locking of the data are non-const.
      return m_pL2;
    }

    /// Get the pointer to previously locked L3 memory.
    /// @return The pointer to L3 memory.
    void* getLockedL3Pointer() const
    {
      // PRQA S 4628 3
      // date: 2015-17-07, reviewer: Christian Exner, reason: That is the use-case of the class, manage the locking of the pointers.
      // So only methods that change the locking of the data are non-const.
      return m_pL3;
    }

    /// Get the return value of algo service functions.
    /// @return Return code of algo service functions.
    AS_t_MemScratchReturnCode getState() const
    {
      return m_retCode;
    }
    
    /// Unlocks all memory that was previously locked.
    /// @return Return code if unlock was successful.
    AS_t_MemScratchReturnCode unlockAllMemory()
    {
      assert(NULL != m_services.pfMemScratchUnlock);

      AS_t_MemScratchReturnCode retCode;

      if(m_services.pfMemScratchUnlock != NULL)
      {
        m_lockSuccessful = false;
        m_sizeL2 = 0;
        m_sizeL3 = 0;
        m_pL2 = NULL;
        m_pL3 = NULL;

        retCode = m_services.pfMemScratchUnlock(m_compId, m_memReqId);
      }
      else
      {
        retCode = AS_MEM_SCRATCH_SRV_NOT_AVL;
      }

      return retCode;
    }

  private:
    CSafeMemlock(const CSafeMemlock&);            ///< Forbidden copy constructor. 
    CSafeMemlock& operator=(const CSafeMemlock&); ///< Forbidden assignment operator. @return Not implemented.

    const AS_t_ServiceFuncts& m_services; ///< Reference to algo service function pointer list

    uint32 m_sizeL2;   ///< Current size of locked L2 memory.
    uint32 m_sizeL3;   ///< Current size of locked L3 memory.
    uint32 m_compId;   ///< The component ID. See @a glob_comp_id.h
    uint32 m_memReqId; ///< Memory request identifier. Valid range is 0..7 for each component. 7 is reserved for FUSI memory.

    AS_t_MemScratchReturnCode m_retCode; ///< The return code from calls to algo service functions.

    void* m_pL2;            ///< Pointer to L2 memory
    void* m_pL3;            ///< Pointer to L3 memory
    bool  m_lockSuccessful; ///< @a true if memory lock was performed successfully, @a false elsewise.
  };
}

#endif // cct_safe_memlock_h__
