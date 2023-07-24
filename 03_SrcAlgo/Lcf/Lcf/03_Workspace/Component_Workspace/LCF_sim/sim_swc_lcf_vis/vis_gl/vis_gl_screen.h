
#pragma once

#ifndef vis_gl_screenH
#define vis_gl_screenH

namespace GL
{
  class Pixel;

  /** \class GL::Screen
   *
   *  \brief encapsulates screen cordinates.
   *
   *  Screen coordinate system is the OpenGL screen coordinate system which is lower left orientated.
   *  Windows mouse coordinate system is upper left orientated. 
   *
   *  In MTS Viewport means Image coordinate system. In OpenGL viewport means rendering image.
   *  Screen is used for OpenGL viewport coordinate system.
   *
   *  \sa \ref vis_gl_coord_transform "OpenGL coordinate transformation functions"
   *  \ingroup ld_vis2_opengl
   *
   */

  class Screen
  {
  public:
    Screen();
    Screen( int x, int y);
    explicit Screen( GL::Pixel const & ext);

    Screen & operator-=( Screen const & o);
    Screen & operator+=( Screen const & o);

    bool operator==( Screen const & o);
    bool operator!=( Screen const & o);

    Screen & Clip( Screen const & lo, Screen const & hi);

    operator int const *() const;

    static double Distance( Screen const & p1, Screen const & p2);

    int m_x;
    int m_y;
  };

  Screen operator*( Screen const & sc, double fFak);
  Screen operator/( Screen const & sc, double fDiv);
  Screen operator-( Screen const & sc1, Screen sc2);
}

#endif // vis_gl_screenH
