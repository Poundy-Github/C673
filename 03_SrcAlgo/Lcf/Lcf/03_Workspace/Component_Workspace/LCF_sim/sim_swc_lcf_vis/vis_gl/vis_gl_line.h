#pragma once

#ifndef vis_gl_lineH
#define vis_gl_lineH

#include "vis_gl_pos.h"

namespace GL
{

  /** \class GL::Line
   *
   *  \brief AutoSAR line
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa \ref vis_gl_func_3d "OpenGL 3D functions"
   *  \ingroup ld_vis2_opengl_3d
   */

  class Line
  {
  public:
    Line();
    Line( Pos const & p0, Pos const & p1);

    static Line X( double x1, double x2, double y);
    static Line Y( double x, double y1, double y2);
    static Line Z( double x, double y, double z1, double z2);

    operator Pos const *() const;    ///< used for GL::VertexPointer

    Pos GetDir() const;
    Pos Middle() const;
    void Revers();
    Line GetRevers() const;
    double Length() const;

    Pos m_p0, m_p1;
  };

  /// @return line with offset
  Line operator+( Line const & line, Pos const & offset);
}

#endif // vis_gl_lineH