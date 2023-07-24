#ifndef _viscr_camera_hpp_
#define _viscr_camera_hpp_

#include <viscr_types.hpp>
#include <viscr_vector.hpp>
#include <viscr_matrix.hpp>
#include <viscr_image.hpp>

/** @name Camera parameter
 *
 */
/*@{*/

/// Projection type 
//{{{
typedef enum { VISCR_CAMERA_PINHOLE, VISCR_CAMERA_FTHETA } viscr_camera_type;
/*}}}*/

/// Camera parameter
//{{{
struct viscr_camera
{
  /// Camera type
  viscr_camera_type camera_type;


  /// Number of pixels
  viscr_image_size size;


  /* ~CodeReview ~ID:c941af42545d56c6d6ea34a9bef428ab ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:2 ~Comment:Use of generic float. No guarantee it is a f32_t type */
  /// Camera constant
  viscr_float f;


  /// Pixel aspect ratio
  viscr_float fs;


  /// Principal point u
  viscr_float cu;


  /// Principal point v
  viscr_float cv;


  /// Distortion according to bouguet model
  viscr_float k0;


  /// Distortion according to bouguet model
  viscr_float k1;


  /// Distortion according to bouguet model
  viscr_float k2;


  /// Distortion according to bouguet model
  viscr_float k3;


  /// Distortion according to bouguet model
  viscr_float k4;

 
  /// Master to camera translation
  viscr_vec3 m2c_t;


  /// Master to camera rotation
  viscr_mat33 m2c_r;


  /* ~CodeReview ~ID:45f0a03f4c1770293f3947d469dd0902 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:empty constructor. Uninitialized member variables */
  /** Default constructor to silence the compiler. */
  viscr_camera() { }
    

  private:

    /* ~CodeReview ~ID:95b317ba6528095dd830513b6cfcb8dd ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:unused methods */
    viscr_camera( const viscr_camera &);
    viscr_camera & operator=( const viscr_camera &);
};
/*}}}*/

/*@}*/

#endif

