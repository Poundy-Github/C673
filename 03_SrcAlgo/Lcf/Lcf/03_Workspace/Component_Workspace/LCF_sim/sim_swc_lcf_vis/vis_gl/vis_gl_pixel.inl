
#include <assert.h>

namespace GL
{
  inline
  Pixel::Pixel()
  : m_x( -1)
  , m_y( -1)
  {}

  inline
  Pixel::Pixel( float x, float y)
  : m_x( x)
  , m_y( y)
  {}

  inline
  Pixel::Pixel( double x, double y)
  : m_x( float( x))
  , m_y( float( y))
  {}

  inline
  Pixel::Pixel( int x, int y)
  : m_x( static_cast<float>( x))
  , m_y( static_cast<float>( y))
  {}

  inline
  Pixel & Pixel::operator+=( Pixel const & offset)
  {
    m_x += offset.m_x;
    m_y += offset.m_y;
    return *this;
  }

  inline
  Pixel & Pixel::operator-=( Pixel const & offset)
  {
    m_x -= offset.m_x;
    m_y -= offset.m_y;
    return *this;
  }

  inline
  Pixel & Pixel::operator*=( int iFactor)
  {
    m_x *= iFactor;
    m_y *= iFactor;
    return *this;
  }

  inline
  Pixel Pixel::operator-() const
  {
    return Pixel( -m_x, -m_y);
  }

  inline
  Pixel operator*( int iFactor, Pixel const & pixel)
  {
    return Pixel( pixel) *= iFactor;
  }

  inline
  Pixel operator*( Pixel const & pixel, int iFactor)
  {
    return Pixel( pixel) *= iFactor;
  }

  inline
  Pixel operator+( Pixel const & p1, Pixel const & p2)
  {
    return Pixel( p1) += p2;
  }

  inline
  Pixel operator-( Pixel const & p1, Pixel const & p2)
  {
    return Pixel( p1) -= p2;
  }

  inline
  Pixel::operator float const*() const
  {
    return & m_x;
  }

  inline
  Pixel operator/( float f, Pixel const & pxl)
  {
    assert( pxl.m_x && pxl.m_y);
    return Pixel( 1.0F / pxl.m_x, 1.0F / pxl.m_y);
  }
}
