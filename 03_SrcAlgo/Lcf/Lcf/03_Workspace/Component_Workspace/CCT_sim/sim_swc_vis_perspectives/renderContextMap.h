#ifndef renderContextMap_h__
#define renderContextMap_h__

#include <map>
#include <cassert>
#include "sim_rendercontext_ifc.h"

template <typename T>
class RenderContextMap : public std::map<HWND, T>
{
public:
  mapped_type& operator[] (const ISimRenderContext& context)
  {
    return std::map<HWND, T>::operator [](context.GetWindow().GetWindowHandle());
  }

  const mapped_type& operator[] (const ISimRenderContext& context) const
  {
    return std::map<HWND, T>::operator [](context.GetWindow().GetWindowHandle());
  }

  mapped_type& operator[] (const ISimRenderContext* const p_context)
  {
    assert (p_context != 0);
    return operator [](*p_context);
  }

  const mapped_type& operator[] (const ISimRenderContext* const p_context) const
  {
    assert (p_context != 0);
    return operator [](*p_context);
  }

private:
  mapped_type& operator[] (const key_type& key);
  const mapped_type& operator[] (const key_type& key) const;
};

#endif // renderContextMap_h__
