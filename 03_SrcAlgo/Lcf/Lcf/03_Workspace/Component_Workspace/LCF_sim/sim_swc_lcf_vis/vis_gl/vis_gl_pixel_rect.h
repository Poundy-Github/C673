#pragma once

#ifndef vis_gl_pixel_rectH
#define vis_gl_pixel_rectH

#include "vis_gl_pixel.h"

namespace GL
{
  /** \class PixelRect
   *
   *  \brief viewport rect
   *
   *  Interal usage of point order:
   *  - first dimension is x
   *  - second dimension is y
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa \ref vis_gl_func_2d "OpenGL 2D wrapper functions"
   *  \ingroup ld_vis2_opengl_2d
   */

  class PixelRect
  {
  public:
    PixelRect();
    PixelRect( Pixel const & p00, int iWidth, int iHeight);
    PixelRect( Pixel const & p00, Pixel const & ext);
    explicit PixelRect( Pixel const & ext);
    PixelRect( float x0, float x1, float y0, float y1);
    PixelRect( double x0, double x1, double y0, double y1);
    PixelRect( int x0, int x1, int y0, int y1);
    PixelRect( Pixel const & p00, Pixel const & p01, Pixel const & p11, Pixel const & p10);

    static PixelRect CenterBox( Pixel const & center, int iWidth, int iHeight);

    operator Pixel const*() const;   ///< used for GL::VertexPointer

    Pixel m_p00, m_p01, m_p11, m_p10;  /// << order is important for glVertex command
  };

}

#endif // vis_gl_pixel_rectH
