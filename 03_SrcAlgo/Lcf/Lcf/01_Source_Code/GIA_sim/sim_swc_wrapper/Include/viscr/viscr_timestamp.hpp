#ifndef _viscr_timestamp_hpp_
#define _viscr_timestamp_hpp_

#include <viscr_types.hpp>

/// Unit of time is application dependent, no assumptions are made unless
/// explicitly state by a function. If no statement is made, a module is time
/// unit independent as long as the same unit is used for all time
///measurements.
typedef viscr_uint64 viscr_timestamp;

#endif

