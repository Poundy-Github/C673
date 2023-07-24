
#pragma once

#include "vis_gl.h"

namespace GL
{
  class Pos;
  /** \class GL::Normal
   *
   *  \brief Normal Vector in AutoSAR coordinates
   *
   *  Encapsulates the Normal vectors in OpenGL. Used for Lightning
   *
   *  \sa \ref vis_gl_func_3d "OpenGL 3D functions"
   *  \sa \ref vis_gl_normal_anchor "OpenGL Normal functions"
   *  \ingroup ld_vis2_opengl_3d
   */

  class Normal
  {
  public:
    Normal();
    explicit Normal( Pos const & pos);
    Normal( double nx, double ny, double nz);

    Normal & operator=( Pos const & pos);
    Normal & operator=( Normal const & pos);

    /// Can be used for more contrast
    void InflateHeight( double f);

    /// not needed in case of OpenGL does it when glEnable( GL_NORMALIZE)
    void Normalize();

    operator double const*() const;
    operator void const*() const;

    double m_nx, m_ny, m_nz;

    static const int GLType = GL_DOUBLE;
  };
  Normal operator/( Normal const & n, double f);
  Normal operator+( Normal const & n1, Normal const & n2);
}
