#ifndef _viscr_klt_shift_hpp_
#define _viscr_klt_shift_hpp_

#include <viscr_types.hpp>
#include <viscr_image.hpp>

// ~CodeReviewBegin ~ID:626667c9f47665e92d795304126fdcaf ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or commen dead code
#if 0 // CODE NOT USED
/** Compute the sub-pixel accurate displacement between corresponding image
 * windows. 
 * \return false if displacement cannot be computed. */
extern viscr_bool
viscr_klt_shift(
    viscr_float & su,
    viscr_float & sv,
    const viscr_image & k0, 
    viscr_coord u0,
    viscr_coord v0,
    const viscr_image & k1, 
    viscr_coord u1,
    viscr_coord v1,
    viscr_uint rad,
    viscr_pixel min_grey,
    viscr_pixel max_grey,
    viscr_pixel_accu * accu);
#endif
// ~CodeReviewEnd   ~ID:626667c9f47665e92d795304126fdcaf

/** Compute the sub-pixel accurate displacement between corresponding image
 * windows, in fix point.
 * \return false if displacement cannot be computed. */
extern viscr_bool
viscr_klt_shift_fp(
    viscr_float & su,
    viscr_float & sv,
    const viscr_image & k0, 
    viscr_coord u0,
    viscr_coord v0,
    const viscr_image & k1, 
    viscr_coord u1,
    viscr_coord v1,
    viscr_uint rad,
    viscr_pixel min_grey,
    viscr_pixel max_grey,
    viscr_pixel_accu * const dy,
    const viscr_bool use_cornercheck);


#endif

