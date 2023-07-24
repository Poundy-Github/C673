#ifndef _viscr_color_hpp_
#define _viscr_color_hpp_

#include <viscr_bayerpattern.h>
#include <viscr_image.hpp>

/** @name Color conversion of images.  */
/*@{*/

/** Convert a bayer pattern (raw color) image to a gray level image. bayertype
 * is one of the constants from viscr_bayerpattern.h */
extern bool viscr_bayer_to_gray(
    viscr_image & img_grey,
    const viscr_image & img_bayer,
    int bayertype);



/*@}*/

#endif

