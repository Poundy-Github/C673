#ifndef _viscr_rectification_hpp_
#define _viscr_rectification_hpp_

#include <viscr_types.hpp>
#include <viscr_camera.hpp>
#include <viscr_stereo_camera.hpp>
#include <viscr_image.hpp>

#include <vector>

/** @name Rectification routines
 *
 */
/*@{*/

/// Rectification table
struct viscr_rectification
{
  /// Number of pixels in the output image
  viscr_image_size size;


  /// Fixed-point weight table
  std::vector< viscr_uint16> weight;


  /// Pixel offset to start of image
  std::vector< viscr_uint32> offset;


  /// Construct as illegal values
  viscr_rectification() { }
  
  private:
    viscr_rectification( const viscr_rectification &);
    viscr_rectification & operator=( const viscr_rectification &);
};


/// Allocate the tables to the given size
extern void
viscr_rectification_alloc( 
    viscr_rectification & data, 
    const viscr_image_size & size);


/// Free the tables
extern void 
viscr_rectification_free(
    viscr_rectification & data);


/// Rectify a given grey image. Remove any Bayer-pattern information before
/// calling this function.
extern void
viscr_rectification_rectify(
    viscr_image & out,
    const viscr_image & in,
    const viscr_rectification & rect);


/// Build the rectification tables for a stereo camera system so that pixel
/// rows go through the epipolar lines at best resoultion. Return false on
/// error.
extern bool
viscr_rectification_compute_stereo(
    viscr_stereo_camera & stereo_cam,
    viscr_rectification & k0_rect,
    viscr_rectification & k1_rect,
    const viscr_camera & k0_param,
    const viscr_camera & k1_param);


/*@}*/

#endif

