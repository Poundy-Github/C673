
#pragma once

#include "vis_gl_Screen.h"

/** \class GL::ScreenQuad
 *
 *  \brief Encapsualtes screen coordinates
 *  \ingroup ld_vis2_opengl
 */

namespace GL
{
  class ScreenQuad
  {
  public:
    ScreenQuad();
    ScreenQuad( int x0, int x1, int y0, int y1);
    ScreenQuad( Screen const & p00, int iWidth, int iHeight);
    ScreenQuad( Screen const & p00, Screen const & p01, Screen const & p11, Screen const & p10);

    bool IsInside( Screen const & pos) const;

  public:
    Screen m_p00;
    Screen m_p01;
    Screen m_p11;
    Screen m_p10;
  };
}