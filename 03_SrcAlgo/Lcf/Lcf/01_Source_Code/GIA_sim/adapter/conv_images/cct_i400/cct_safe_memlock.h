#ifndef cct_safe_memlock_h__
#define cct_safe_memlock_h__

#include <cassert>
#include "algo_type.h"
#include "glob_type.h"
#include "algo_service_types.h"

namespace cct
{  
  
  /**************************************************************************
  Classname         CSafeMemlock                                       */ /*!   

  @brief            Wrapper for L2/L3 memory locking services that makes sure that memory is never accidentally in a locked state ("smart-pointer")
  @description      This wrapper uses the memory locking concept described in the following doors document:
                    doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-437-00022807
                    See algo_service_types.h for a description of the required inputs and outputs  


                    Simple example:

                    void example_func()
                    {
                      cct::CSafeMemlock memLock(m_bswServices, 0, 1024 * 124, COMP_ID_SIB, true);

                      // get detailed information about the lock (note that AS_t_MemScratchReturnCode is acutally a bit field!)
                      AS_t_MemScratchReturnCode state = getState();

                      // lockSuccessful() returns true if there were no problems during locking
                      if(!memLock.lockSuccessful()) 
                      {                        
                        return false;
                      }
                      else
                      {
                        // use pointer to cache
                        void* l3Cache = memLock.getLockedL3Pointer();
                        sint32 l3Size = memLock.getLockedL3Size();
                        ...
                      }

                      // memory is unlocked automatically once memLock variable goes out of scope and is destroyed
                    }
  *****************************************************************************/
  class CSafeMemlock
  {
  public:
    CSafeMemlock(const AS_t_ServiceFuncts &services, uint32 u_sizeBytesL2, uint32  u_sizeBytesL3, uint32  u_componentId, boolean b_waitForLock, uint32  u_memReqId = 0)
      : m_services(services)            
      ,m_memReqId(u_memReqId)
      ,m_compId(u_componentId)
      ,m_sizeL2(0)
      ,m_sizeL3(0)      
      ,m_pL2(0)
      ,m_pL3(0)
      ,m_retCode(AS_MEM_SCRATCH_SRV_NOT_AVL)
      ,m_lockSuccessful(false)      
    {                 
      // some basic assertions
      assert(NULL != m_services.pfMemLock);                // we need access to the algo services
      assert(!(u_sizeBytesL2 == 0 && u_sizeBytesL3 == 0)); // no memory requested, doesn't make sense
      assert(u_memReqId < 8);                              // memory request identifier. valid range is 0..7 for each component. 7 is reserved for FUSI memory.
      
      if(m_services.pfMemLock) 
      {
        AS_t_MemScratchReqPort rp;
        AS_t_MemScratchProPort pp;

        // fill input parameter struct for mem lock
        rp.b_condWait = b_waitForLock;
        rp.u_compId   = u_componentId;
        rp.u_memReqId = u_memReqId;
        rp.u_sizeL2   = u_sizeBytesL2;
        rp.u_sizeL3   = u_sizeBytesL3;

        // call the lock service
        m_retCode = m_services.pfMemScratchLock(&rp, &pp);

        // store results of lock
        m_pL2 = pp.p_memL2;
        m_pL3 = pp.p_memL3;
        m_sizeL2 = pp.u_sizeL2;
        m_sizeL3 = pp.u_sizeL3;

        // determine if the lock was completely successful
        m_lockSuccessful = (m_retCode == AS_MEM_SCRATCH_SRV_SUCCESS);
      }

    }

    ~CSafeMemlock()
    {
      unlockAllMemory();
    }

    bool8 lockSuccessful() const
    {
      return m_lockSuccessful;
    }

    sint32 getLockedL2Size() const
    {      
      return m_sizeL2;     
    }

    sint32 getLockedL3Size() const
    {      
      return m_sizeL3;      
    }
    
    void* getLockedL2Pointer() const
    {
      return m_pL2;
    }

    void* getLockedL3Pointer() const
    {
      return m_pL3;
    }

    AS_t_MemScratchReturnCode getState() const
    {
      return m_retCode;
    }

    AS_t_MemScratchReturnCode unlockAllMemory() 
    {      
      assert(NULL != m_services.pfMemUnlock);      
      if(m_services.pfMemUnlock)
      {        
        m_lockSuccessful = false;
        m_sizeL2 = 0;
        m_sizeL3 = 0;
        m_pL2 = 0;
        m_pL3 = 0;          
        return m_services.pfMemScratchUnlock(m_compId, m_memReqId);
      }
      else
      {
        return AS_MEM_SCRATCH_SRV_NOT_AVL;
      }
    }

  private:   
    CSafeMemlock& operator=(const CSafeMemlock&);

    const AS_t_ServiceFuncts m_services;    

    uint32  m_sizeL2;
    uint32  m_sizeL3;
    uint32  m_compId;    
    uint32  m_memReqId;

    AS_t_MemScratchReturnCode m_retCode;

    void*         m_pL2;
    void*         m_pL3;    
    AS_t_MemState m_memState;
    boolean       m_lockSuccessful;

  };
}

#endif // cct_safe_memlock_h__
