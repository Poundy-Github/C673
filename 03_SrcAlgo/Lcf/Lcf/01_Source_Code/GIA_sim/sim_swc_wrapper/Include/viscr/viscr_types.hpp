#ifndef _viscr_types_hpp_
#define _viscr_types_hpp_

/** @name Internal type definitions
 *
 */
/*@{*/

#ifdef _WIN32
typedef char viscr_int8;
typedef unsigned char viscr_uint8;

typedef short viscr_int16;
typedef unsigned short viscr_uint16;

typedef long viscr_int32;
typedef unsigned long viscr_uint32;

typedef long long viscr_int64;
typedef unsigned long long viscr_uint64;

#else

#include <stdint.h>

typedef int8_t viscr_int8;
typedef uint8_t viscr_uint8;

typedef int16_t viscr_int16;
typedef uint16_t viscr_uint16;

typedef int32_t viscr_int32;
typedef uint32_t viscr_uint32;

typedef int64_t viscr_int64;
typedef uint64_t viscr_uint64;

#endif

typedef enum { viscr_false=0, viscr_true} viscr_bool;

/* ~CodeReview ~ID:dd4162c6df67564163dbdd0ea049a619 ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:undefined int type */
/// Generic signed counter, must be at least 16 bit
typedef int viscr_int;

/* ~CodeReview ~ID:adafd9294a926fef86f54d46a55d464d ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:undefined unsigned int type */
/// Generic signed counter, must be at least 16 bit
typedef unsigned int viscr_uint;

/* ~CodeReview ~ID:667ec2dabd0c10ef31325fc8d9761c13 ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:undefined float type */
/// Generic float, at least 32 bit
typedef float viscr_float;


/// Grey and colour values are 16 bit
typedef viscr_uint16 viscr_pixel;


/// Image coordinates
typedef viscr_int16 viscr_coord;


/// This must be signed, as we work with mean-free grey values. Must be at
/// least 6 bits longer than grey value to store 8x8 pixel sum.
typedef viscr_int32 viscr_pixel_accu;


/*@}*/

#endif

