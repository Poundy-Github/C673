#ifndef _viscr_corner_check_hpp_
#define _viscr_corner_check_hpp_

#include <viscr_image.hpp>

/** Check if the window around the given coordinate is a corner of sufficient
 * contrast. This is a version of the FAST corner detector.
 *
 * \return true if the contrast is sufficient for viscr_klt_shift.
 */

extern viscr_bool viscr_corner_check(const viscr_image & img, viscr_coord u, viscr_coord v);

extern viscr_bool viscr_fastcorner_check(const viscr_image & img, const viscr_coord u, const viscr_coord v, const viscr_pixel min_contrast);

#endif

