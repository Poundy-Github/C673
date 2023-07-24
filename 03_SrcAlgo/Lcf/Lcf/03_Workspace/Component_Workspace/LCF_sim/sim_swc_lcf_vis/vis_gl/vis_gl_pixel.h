#pragma once

#ifndef vis_gl_pixelH
#define vis_gl_pixelH

#include <windows.h>
#include <GL/GL.h>

namespace GL
{

  class Screen;

  /** \class Pixel
   *
   *  \brief viewport pos
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa \ref vis_gl_func_2d "OpenGL 2D wrapper functions"
   *  \ingroup ld_vis2_opengl_2d
   */

  class Pixel
  {
  public:
    typedef float Type;

    Pixel();
    Pixel( double x, double y);
    Pixel( float x, float y);
    Pixel( int x, int y);
    explicit Pixel( Screen const & screen);

    Pixel & operator+=( Pixel const & offset);
    Pixel & operator-=( Pixel const & offset);
    Pixel & operator*=( double dFactor);
    Pixel & operator*=( float dFactor);
    Pixel & operator/=( double dFactor);

    operator Type const*() const;
    Type const * GetPtr() const;
    Pixel operator-() const;
    Pixel & operator>>=( int iShift);
    Pixel & operator<<=( int iShift);

    float m_x, m_y;

    static const int GLType = GL_FLOAT;   ///< changed if members becom a different type
  };

  Pixel operator*( double dFactor, Pixel const & offset);
  Pixel operator*( Pixel const & offset, double dFactor);
  Pixel operator+( Pixel const & p1, Pixel const & p2);
  Pixel operator-( Pixel const & p1, Pixel const & p2);
  Pixel operator/( double f, Pixel const & pxl);
  Pixel operator/( Pixel const & p1, double dFactor);
  Pixel operator>>( Pixel const & pxl, int iShift);
  Pixel operator<<( Pixel const & pxl, int iShift);
}

#endif // vis_gl_pixelH
