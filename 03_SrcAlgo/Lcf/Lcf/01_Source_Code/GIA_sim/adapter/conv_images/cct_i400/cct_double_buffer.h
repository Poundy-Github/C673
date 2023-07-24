#ifndef cct_double_buffer_h__
#define cct_double_buffer_h__

#include "cml_ext_cpp.h"

namespace cct
{
  template<class T>
  class CDoubleBuffer
  {
  public:
    CDoubleBuffer() : m_idxFront(0), m_idxBack(1) {}

    T& front() { return m_data[m_idxFront]; }
    T& back()  { return m_data[m_idxBack ]; }

    const T& front() const { return m_data[m_idxFront]; }
    const T& back()  const { return m_data[m_idxBack ]; }

    void swap()
    {
      m_idxFront = (m_idxFront + 1) % 2;
      m_idxBack  = (m_idxBack  + 1) % 2;
    }

  private:
    cml::CArray<T,2> m_data;
    sint8            m_idxFront;
    sint8            m_idxBack;
  };
}

#endif // cct_double_buffer_h__
