
#include "vis_gl_screen_quad.h"

#include "vis_gl_math.h"

using namespace GL;

ScreenQuad::ScreenQuad()
{}

GL::ScreenQuad::ScreenQuad( Screen const & p00, int iWidth, int iHeight)
: m_p00( p00)
, m_p01( p00)
, m_p10( p00)
, m_p11( p00)
{
  m_p01.m_y += iHeight;
  m_p10.m_x += iWidth;
  m_p11.m_x += iWidth;
  m_p11.m_y += iHeight;
}

ScreenQuad::ScreenQuad( int x0, int x1, int y0, int y1)
: m_p00( Screen( x0, y0))
, m_p01( Screen( x0, y1))
, m_p11( Screen( x1, y1))
, m_p10( Screen( x1, y0))
{}

ScreenQuad::ScreenQuad( Screen const & p00, Screen const & p01, Screen const & p11, Screen const & p10)
: m_p00( p00)
, m_p01( p01)
, m_p11( p11)
, m_p10( p10)
{}

static bool IntersectX( Screen const & s0, Screen const & s1, Screen const & s)
{
  return IntersectX( s0.m_x, s0.m_y, s1.m_x, s1.m_y, s.m_x, s.m_y);
}

bool ScreenQuad::IsInside( Screen const & pos) const
{
  // Algorithm:
  // - transform pos to center
  // - show how many intersections are on positive x-achse
  // - odd is inside
  int iCountIntersction = 0;
  if( ::IntersectX( m_p00, m_p01, pos))
    iCountIntersction++;
  if( ::IntersectX( m_p01, m_p11, pos))
    iCountIntersction++;
  if( ::IntersectX( m_p11, m_p10, pos))
    iCountIntersction++;
  if( ::IntersectX( m_p10, m_p00, pos))
    iCountIntersction++;
  return iCountIntersction % 2 ? true : false;
}
