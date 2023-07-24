#ifndef _viscr_math_hpp_
#define _viscr_math_hpp_

#include <viscr_types.hpp>

/// Find the maximal element of two floats
/* <ln_offset:+1to+9 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Function to calculate maximum value. */
inline viscr_float
viscr_float_max(
    viscr_float a,
    viscr_float b)
{
  if( a>b)
    return a;
  return b;
}



#endif

