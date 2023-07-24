#ifndef _viscr_stereo_camera_hpp_
#define _viscr_stereo_camera_hpp_

#include <viscr_types.hpp>
#include <viscr_matrix.hpp>

/// Rectified stereo camera information.
// {{{
struct viscr_stereo_camera 
{
  /* ~CodeReview ~ID:531a69abad31e430975a8c3f9b18b1e8 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:Use of generic float. No guarantee it is a f32_t type */
  /// Camera constant in pixel
  viscr_float f;


  /// Principal point, horizontal coordinate, in pixel
  viscr_float u;


  /// Principal point, vertical coordinate, in pixel
  viscr_float v;


  /// baseline length in meter
  viscr_float b;
  

  /// New rotation matrix for rectification
  viscr_mat33 R;

  /// Rotation camera 0
  viscr_mat33 R_k0;
  
  /// Rotation camera 1
  viscr_mat33 R_k1;

  /// Transform from undistorted to rectified coordinates, camera 0
  viscr_mat33 T_k0;
  

  /// Transform from undistorted to rectified coordinates, camera 1
  viscr_mat33 T_k1;
  

  /// Transform from rectified to undistorted coordinates, camera 0
  viscr_mat33 invT_k0;
  

  /// Transform from rectified to undistorted coordinates, camera 1
  viscr_mat33 invT_k1;
  

  /* ~CodeReview ~ID:12573aed81a58efaae711bbd9c2af2b7 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:empty constructor. Uninitialized member variables */
  /// Default constructor to make compiler happy
  viscr_stereo_camera() { }

  private:
    /* ~CodeReview ~ID:9e61f493408a4df49d1e28ff83884859 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:unused methods */
    viscr_stereo_camera( const viscr_stereo_camera &);
    viscr_stereo_camera & operator=( const viscr_stereo_camera &);
};
/*}}}*/


#endif

