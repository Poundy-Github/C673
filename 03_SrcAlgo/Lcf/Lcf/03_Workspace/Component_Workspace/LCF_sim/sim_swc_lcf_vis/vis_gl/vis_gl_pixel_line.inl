
namespace GL
{
  inline
  PixelLine::PixelLine()
  {}

  inline
  PixelLine::PixelLine( Pixel const & p0, Pixel const & p1)
  : m_p0( p0)
  , m_p1( p1)
  {}

  inline
  PixelLine & PixelLine::operator+=( Pixel const & offset)
  {
    m_p0 += offset;
    m_p1 += offset;
    return *this;
  }

  inline
  PixelLine & PixelLine::operator-=( Pixel const & offset)
  {
    m_p0 -= offset;
    m_p1 -= offset;
    return *this;
  }

  inline
  PixelLine operator+( PixelLine const & line, Pixel const & offset)
  {
    return PixelLine( line) += offset;
  }

  inline
  PixelLine operator-( PixelLine const & line, Pixel const & offset)
  {
    return PixelLine( line) -= offset;
  }

  inline
  PixelLine::operator Pixel const*() const
  {
    return & m_p0;
  }

  inline
  PixelLine PixelLine::Hori( float y, float x1, float x2)
  {
    PixelLine l;
    l.m_p0.m_y = l.m_p1.m_y = y;
    l.m_p0.m_x = x1;
    l.m_p1.m_x = x2;
    return l;
  }

  inline
  PixelLine PixelLine::Vert( float x, float y1, float y2)
  {
    PixelLine l;
    l.m_p0.m_x = l.m_p1.m_x = x;
    l.m_p0.m_y = y1;
    l.m_p1.m_y = y2;
    return l;
  }

}
