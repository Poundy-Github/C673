
#include "vis_gl_screen.h"

#include "vis_gl_pixel.h"

#include <math.h>

using namespace GL;

GL::Screen::Screen()
  : m_x( -1)
  , m_y( -1)
{}

GL::Screen::Screen( int _ix, int _iy)
  : m_x( _ix)
  , m_y( _iy)
{}

GL::Screen::Screen( GL::Pixel const & ext)
  : m_x( static_cast<int>( ext.m_x))
  , m_y( static_cast<int>( ext.m_y))
{}


GL::Screen::operator int const *() const
{
  return & m_x;
}

bool GL::Screen::operator==( Screen const & o)
{
  return m_x == o.m_x && m_y == o.m_y;
}

bool GL::Screen::operator!=( Screen const & o)
{
  return ! operator==( o);
}

Screen GL::operator*( Screen const & sc, double fFak)
{
  Screen r = sc;
  r.m_x = static_cast<int>( r.m_x * fFak);
  r.m_y = static_cast<int>( r.m_y * fFak);
  return r;
}

Screen GL::operator/( Screen const & sc, double fDiv)
{
  Screen r = sc;
  r.m_x = static_cast<int>( r.m_x / fDiv);
  r.m_y = static_cast<int>( r.m_y / fDiv);
  return r;
}

Screen GL::operator-( Screen const & sc1, Screen sc2)
{
  Screen r = sc1;
  r.m_x -= sc2.m_x;
  r.m_y -= sc2.m_y;
  return r;
}

Screen & Screen::Clip( Screen const & lo, Screen const & hi)
{
  m_x = max( m_x, lo.m_x);
  m_x = min( m_x, hi.m_x);
  m_y = max( m_y, lo.m_y);
  m_y = min( m_y, hi.m_y);
  return *this;
}

Screen & Screen::operator-=( Screen const & o)
{
  m_x -= o.m_x;
  m_y -= o.m_y;
  return *this;
}

Screen & Screen::operator+=( Screen const & o)
{
  m_x += o.m_x;
  m_y += o.m_y;
  return *this;
}

double Screen::Distance( Screen const & p1, Screen const & p2)
{
  Screen dist = p2 - p1;
  return sqrt( (double) dist.m_x * dist.m_x + dist.m_y * dist.m_y);
}
