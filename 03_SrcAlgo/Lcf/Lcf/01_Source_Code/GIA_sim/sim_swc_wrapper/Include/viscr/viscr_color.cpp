#include <cassert>
#include <viscr_color.hpp>


bool viscr_bayer_to_gray(
    viscr_image & img_grey,
    const viscr_image & img_bayer,
    int bayertype)
{
  assert( img_grey.size.u==img_bayer.size.u);
  assert( img_grey.size.v==img_bayer.size.v);
  assert( img_grey.data);
  assert( img_bayer.data);
  assert( 
      bayertype==VISCR_BAYER_RGGB ||
      bayertype==VISCR_BAYER_GBRG ||
      bayertype==VISCR_BAYER_GRBG ||
      bayertype==VISCR_BAYER_BGGR);

  return 0!=viscr_BayerColorGray( 
      (unsigned char*)img_bayer.data, 
      (unsigned char*)img_grey.data, 
      img_grey.size.u, img_grey.size.v,
      0, 0,
      img_grey.size.u, img_grey.size.v,
      sizeof(viscr_pixel),
      bayertype);
}

