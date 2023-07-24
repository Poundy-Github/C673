
#include "vis_gl_pixel.h"

#include "vis_gl_screen.h"

#include <float.h>
#include <assert.h>

using namespace GL;

GL::Pixel::Pixel()
: m_x( -1)
, m_y( -1)
{}

GL::Pixel::Pixel( double x, double y)
: m_x( static_cast<Type>( x))
, m_y( static_cast<Type>( y))
{}

GL::Pixel::Pixel( float x, float y)
: m_x( x)
, m_y( y)
{}

GL::Pixel::Pixel( int x, int y)
: m_x( static_cast<Type>( x))
, m_y( static_cast<Type>( y))
{}

GL::Pixel::Pixel( Screen const & screen)
: m_x( (float) screen.m_x)
, m_y( (float) screen.m_y)
{}

GL::Pixel & GL::Pixel::operator+=( Pixel const & offset)
{
  m_x += offset.m_x;
  m_y += offset.m_y;
  return *this;
}

GL::Pixel & GL::Pixel::operator-=( Pixel const & offset)
{
  m_x -= offset.m_x;
  m_y -= offset.m_y;
  return *this;
}

GL::Pixel & GL::Pixel::operator*=( double dFactor)
{
  m_x *= static_cast<Type>( dFactor);
  m_y *= static_cast<Type>( dFactor);
  return *this;
}

GL::Pixel & GL::Pixel::operator/=( double dFactor)
{
  m_x /= static_cast<Type>( dFactor);
  m_y /= static_cast<Type>( dFactor);
  return *this;
}

GL::Pixel GL::Pixel::operator-() const
{
  return Pixel( -m_x, -m_y);
}

GL::Pixel GL::operator*( double dFactor, Pixel const & pixel)
{
  return Pixel( pixel) *= dFactor;
}

GL::Pixel GL::operator*( Pixel const & pixel, double dFactor)
{
  return Pixel( pixel) *= dFactor;
}

GL::Pixel GL::operator+( Pixel const & p1, Pixel const & p2)
{
  return Pixel( p1) += p2;
}

GL::Pixel GL::operator-( Pixel const & p1, Pixel const & p2)
{
  return Pixel( p1) -= p2;
}

GL::Pixel::operator Pixel::Type const*() const
{
  return & m_x;
}

GL::Pixel::Type const * GL::Pixel::GetPtr() const
{
  return & m_x;
}

GL::Pixel GL::operator/( double f, Pixel const & pxl)
{
  assert( pxl.m_x >= DBL_EPSILON && pxl.m_y >= DBL_EPSILON);
  return Pixel( f / pxl.m_x, f / pxl.m_y);
}

Pixel & Pixel::operator>>=( int iShift)
{
  m_x = m_x / ( 1 << iShift);
  m_y = m_y / ( 1 << iShift);
  return *this;
}

Pixel & Pixel::operator<<=( int iShift)
{
  m_x = m_x * ( 1 << iShift);
  m_y = m_y * ( 1 << iShift);
  return *this;
}

Pixel GL::operator>>( Pixel const & pxl, int iShift)
{
  return Pixel( pxl)>>= iShift;
}

Pixel GL::operator<<( Pixel const & pxl, int iShift)
{
  return Pixel( pxl)<<= iShift;
}

Pixel GL::operator/( Pixel const & p1, double dFactor)
{
  return Pixel( p1)/= dFactor;
}
