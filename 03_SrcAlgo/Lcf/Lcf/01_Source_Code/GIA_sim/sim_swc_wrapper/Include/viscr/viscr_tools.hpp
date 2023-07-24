#ifndef _viscr_tools_hpp_
#define _viscr_tools_hpp_

#include <viscr_types.hpp>

inline viscr_uint
viscr_uint_min( 
    viscr_uint a,
    viscr_uint b)
{
  return (a<b)?a:b;
}

#endif

