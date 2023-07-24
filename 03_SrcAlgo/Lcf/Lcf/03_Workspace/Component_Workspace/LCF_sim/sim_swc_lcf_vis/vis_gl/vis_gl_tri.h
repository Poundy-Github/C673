
#pragma once

#include "vis_gl_pos.h"

namespace GL
{
  /** \class Tri
   *
   *  \brief AutoSAR triangle
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa \ref vis_gl_func_3d "OpenGL 3D wrapper functions"
   *  \ingroup ld_vis2_opengl_3d
   */

  class Tri
  {
  public:
    Tri(){};
    Tri( Pos const & p0, Pos const & p1, Pos const & p2);

    operator Pos const *() const;

    Pos m_p0, m_p1, m_p2;
  };
}

inline
GL::Tri::Tri( Pos const & p0, Pos const & p1, Pos const & p2)
: m_p0( p0)
, m_p1( p1)
, m_p2( p2)
{}

inline
GL::Tri::operator GL::Pos const*() const
{
  return & m_p0;
}
