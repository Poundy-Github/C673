#ifndef _viscr_image_hpp_
#define _viscr_image_hpp_

#include <cassert>
#include <cstdlib>
#include <viscr_types.hpp>

/** @name Image storage.
 *
 */
/*@{*/

/// Size of an image.
// {{{
struct viscr_image_size
{
  /// Number of pixels in horizontal direction
  viscr_int u;


  /// Number of pixels in vertical direction
  viscr_int v;


  /// Default: empty image
  viscr_image_size(): 
    u(0), v(0) { }


  /// Copy constructor
  viscr_image_size( const viscr_image_size & sz):
    u(sz.u),
    v(sz.v)
  { }


  /// Normal constructor
  /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Function currently not used. */
  viscr_image_size( viscr_uint _u, viscr_uint _v):
    u(_u),
    v(_v)
  { }

 /* ~CodeReview ~ID:e0aa4195ef841db1d64037cef0042c99 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:unused method */
  /// Equality operator
    /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Opertor currently not used. */
  bool operator==( const viscr_image_size & sz) const 
  {
    return u==sz.u && v==sz.v;
  }
};
/*}}}*/


/// Monochromatic image
// {{{
struct viscr_image
{
  /// Number of pixels
  viscr_image_size size;


  /// Pixel storage
  viscr_pixel * data;


  /// Default: illegal image
  viscr_image(): 
    data( NULL) { }


  /// Normal constructor for image aliasing
    /* <ln_offset:+1to+3 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Function currently not used. */
  viscr_image( const viscr_image_size & sz, viscr_pixel * d):
    size( sz),
    data( d) { }


  /// Normal constructor for external storage
    /* <ln_offset:+1to+3 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Function currently not used. */
    viscr_image( viscr_uint u, viscr_uint v, viscr_pixel * d):
    size( u, v),
    data( d) { }

  private:
    viscr_image( const viscr_image &);
    viscr_image & operator=( const viscr_image &);
};
/*}}}*/


/// Get the pointer to a pixel
inline viscr_pixel *
viscr_image_get_pointer( 
    const viscr_image & img, 
    viscr_coord u, 
    viscr_coord v)
{
  assert( 0<=u && u<img.size.u);
  assert( 0<=v && v<img.size.v);
  return img.data+u+img.size.u*v;
}
 

/// Read a pixel
inline viscr_pixel 
viscr_image_getPixel( 
    const viscr_image & img, 
    viscr_coord u, 
    viscr_coord v)
{
  return *viscr_image_get_pointer( img, u, v);
}

/* ~CodeReview ~ID:e7b7166afa6d18a898049965215baf1a ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:unused method */

/// Write a pixel
/* <ln_offset:+1to+9 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Function has no callers. Dead code. */
inline void
viscr_image_set_pixel( 
    const viscr_image & img, 
    viscr_coord u, 
    viscr_coord v,
    viscr_pixel val)
{
  *viscr_image_get_pointer( img, u, v)=val;
}

/*@}*/

#endif

