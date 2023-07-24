#pragma once

#ifndef vis_gl_pixel_lineH
#define vis_gl_pixel_lineH

#include "vis_gl_pixel.h"

namespace GL
{
  /** \class PixelLine
   *
   *  \brief viewport line
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa \ref vis_gl_func_2d "OpenGL 2D wrapper functions"
   *  \ingroup ld_vis2_opengl_2d
   */

  class PixelLine
  {
  public:
    PixelLine();
    PixelLine( Pixel const & p0, Pixel const & p1);

    static PixelLine X( double x1, double x2, double y);
    static PixelLine Y( double x, double y1, double y2);

    PixelLine & operator+=( Pixel const & offset);
    PixelLine & operator-=( Pixel const & offset);

    static PixelLine Hori( double x, double y1, double y2);
    static PixelLine Vert( double y, double x1, double x2);

    operator Pixel const*() const;   ///< used for GL::VertexPointer
    
    Pixel m_p0;
    Pixel m_p1;
  };

  PixelLine operator+( PixelLine const & line, Pixel const & offset);
  PixelLine operator-( PixelLine const & line, Pixel const & offset);

}

#endif // vis_gl_pixel_lineH
