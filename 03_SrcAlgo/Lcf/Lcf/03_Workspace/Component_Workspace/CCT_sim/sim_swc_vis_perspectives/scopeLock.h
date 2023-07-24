#ifndef scopeLock_h__
#define scopeLock_h__

#include "stdafx.h"

/// Helper class to lock a critical section throughout
/// a certain scope (block) and automaticaly leave it
/// when leaving the block
class ScopeLock
{
public:
  // force == true:  Enter critical section in all cases
  // force == false: Enter critical section only if computational power is available
  ScopeLock ( CRITICAL_SECTION& cs, const bool& force = true )
    : m_cs(cs)
  {
    if ( force )
    {
      ::EnterCriticalSection(&m_cs);
      m_successful = true;
    }
    else
    {
      m_successful = ::TryEnterCriticalSection(&m_cs) != 0;
    }
  }

  ~ScopeLock () { if (m_successful) ::LeaveCriticalSection(&m_cs); }

  const bool successful() { return m_successful; }

private:
  CRITICAL_SECTION& m_cs;
  bool m_successful;
};

#endif // scopeLock_h__
