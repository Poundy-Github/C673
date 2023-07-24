#include "vis_gl_pixel_rect.h"

GL::PixelRect::PixelRect()
{}

GL::PixelRect::PixelRect( float x0, float x1, float y0, float y1)
: m_p00( GL::Pixel( x0, y0))
, m_p01( GL::Pixel( x0, y1))
, m_p11( GL::Pixel( x1, y1))
, m_p10( GL::Pixel( x1, y0))
{}

GL::PixelRect::PixelRect( double x0, double x1, double y0, double y1)
: m_p00( GL::Pixel( x0, y0))
, m_p01( GL::Pixel( x0, y1))
, m_p11( GL::Pixel( x1, y1))
, m_p10( GL::Pixel( x1, y0))
{}

GL::PixelRect::PixelRect( int x0, int x1, int y0, int y1)
: m_p00( GL::Pixel( static_cast<Pixel::Type>( x0), static_cast<Pixel::Type>( y0)))
, m_p01( GL::Pixel( static_cast<Pixel::Type>( x0), static_cast<Pixel::Type>( y1)))
, m_p11( GL::Pixel( static_cast<Pixel::Type>( x1), static_cast<Pixel::Type>( y1)))
, m_p10( GL::Pixel( static_cast<Pixel::Type>( x1), static_cast<Pixel::Type>( y0)))
{}

GL::PixelRect::PixelRect( Pixel const & p00, Pixel const & ext)
: m_p00( p00)
, m_p01( p00 + GL::Pixel( GL::Pixel::Type( 0.0), ext.m_y))
, m_p10( p00 + GL::Pixel( ext.m_x, GL::Pixel::Type( 0.0)))
, m_p11( p00 + ext)
{}

GL::PixelRect::PixelRect( Pixel const & ext)
: m_p00( GL::Pixel( 0, 0))
, m_p01( GL::Pixel( GL::Pixel::Type( 0.0), ext.m_y))
, m_p10( GL::Pixel( ext.m_x, GL::Pixel::Type( 0.0)))
, m_p11( ext)
{}

GL::PixelRect::PixelRect( GL::Pixel const & p00, GL::Pixel const & p01, GL::Pixel const & p11, GL::Pixel const & p10)
: m_p00( p00)
, m_p01( p01)
, m_p11( p11)
, m_p10( p10)
{}

GL::PixelRect::PixelRect( GL::Pixel const & p00, int iWidth, int iHeight)
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

GL::PixelRect::operator GL::Pixel const*() const
{
  return & m_p00;
}

GL::PixelRect GL::PixelRect::CenterBox( GL::Pixel const & center, int iWidth, int iHeight)
{
  return PixelRect( center.m_x - iWidth / 2.0, center.m_x + iWidth / 2.0, center.m_y - iHeight / 2.0, center.m_y + iHeight / 2.0);
}
