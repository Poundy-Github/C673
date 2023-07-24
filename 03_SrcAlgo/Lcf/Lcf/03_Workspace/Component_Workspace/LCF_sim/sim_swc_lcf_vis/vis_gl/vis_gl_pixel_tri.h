#pragma once

#ifndef vis_gl_pixel_triH
#define vis_gl_pixel_triH

#include "vis_gl_pixel.h"

namespace GL
{
  /** \class PixelTri
   *
   *  \brief viewport triangle
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa \ref vis_gl_func_2d "OpenGL 2D wrapper functions"
   *  \ingroup ld_vis2_opengl_2d
   */

  class PixelTri
  {
  public:
    PixelTri();
    PixelTri( Pixel const & p0, Pixel const & p1, Pixel const & p2);

    Pixel m_p0;
    Pixel m_p1;
    Pixel m_p2;
  };

}

#endif // vis_gl_pixel_triH
