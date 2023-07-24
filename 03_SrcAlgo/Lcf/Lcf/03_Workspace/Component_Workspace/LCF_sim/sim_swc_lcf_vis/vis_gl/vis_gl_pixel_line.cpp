
#include "vis_gl_pixel_line.h"

GL::PixelLine::PixelLine()
{}

GL::PixelLine::PixelLine( GL::Pixel const & p0, GL::Pixel const & p1)
: m_p0( p0)
, m_p1( p1)
{}

GL::PixelLine & GL::PixelLine::operator+=( GL::Pixel const & offset)
{
  m_p0 += offset;
  m_p1 += offset;
  return *this;
}

GL::PixelLine & GL::PixelLine::operator-=( GL::Pixel const & offset)
{
  m_p0 -= offset;
  m_p1 -= offset;
  return *this;
}

GL::PixelLine GL::operator+( GL::PixelLine const & line, GL::Pixel const & offset)
{
  return GL::PixelLine( line) += offset;
}

GL::PixelLine GL::operator-( GL::PixelLine const & line, GL::Pixel const & offset)
{
  return GL::PixelLine( line) -= offset;
}

GL::PixelLine::operator GL::Pixel const*() const
{
  return & m_p0;
}

GL::PixelLine GL::PixelLine::Hori( double y, double x1, double x2)
{
  GL::PixelLine l;
  l.m_p0.m_y = l.m_p1.m_y = static_cast<Pixel::Type>( y);
  l.m_p0.m_x = static_cast<Pixel::Type>( x1);
  l.m_p1.m_x = static_cast<Pixel::Type>( x2);
  return l;
}

GL::PixelLine GL::PixelLine::Vert( double x, double y1, double y2)
{
  GL::PixelLine l;
  l.m_p0.m_x = l.m_p1.m_x = static_cast<Pixel::Type>( x);
  l.m_p0.m_y = static_cast<Pixel::Type>( y1);
  l.m_p1.m_y = static_cast<Pixel::Type>( y2);
  return l;
}

GL::PixelLine GL::PixelLine::X( double x1, double x2, double y)
{
  return GL::PixelLine( GL::Pixel( x1, y), Pixel( x2, y));
}

GL::PixelLine GL::PixelLine::Y( double x, double y1, double y2)
{
  return GL::PixelLine( Pixel( x, y1), Pixel( x, y2));
}
