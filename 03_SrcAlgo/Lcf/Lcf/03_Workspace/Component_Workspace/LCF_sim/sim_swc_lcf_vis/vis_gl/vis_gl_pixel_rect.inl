
namespace GL
{
  inline
  PixelRect::PixelRect()
  {}

  inline
  PixelRect::PixelRect( float x0, float x1, float y0, float y1)
  : m_p00( Pixel( x0, y0))
  , m_p01( Pixel( x0, y1))
  , m_p11( Pixel( x1, y1))
  , m_p10( Pixel( x1, y0))
  {}

  inline
  PixelRect::PixelRect( Pixel const & p00, Pixel const & p01, Pixel const & p11, Pixel const & p10)
  : m_p00( p00)
  , m_p01( p01)
  , m_p11( p11)
  , m_p10( p10)
  {}

  inline
  PixelRect::PixelRect( Pixel const & p00, int iWidth, int iHeight)
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


  inline
  PixelRect::operator Pixel const*() const
  {
    return & m_p00;
  }

  inline
  PixelRect PixelRect::CenterBox( Pixel const & center, int iWidth, int iHeight)
  {
    return PixelRect( center.m_x - iWidth / 2, center.m_x + iWidth / 2, center.m_y - iHeight / 2, center.m_y + iHeight / 2);
  }
}
