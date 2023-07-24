
#include "vis_gl_line.h"

namespace GL
{
  inline
  Rect::Rect( Pos const & p00, Pos const & p01, Pos const & p10, Pos const & p11)
  : m_p00( p00)
  , m_p01( p01)
  , m_p10( p10)
  , m_p11( p11)
  {}

  inline
  Rect::Rect( float x0, float x1, float y0, float y1, float z)
  : m_p00( x0, y0, z)
  , m_p01( x0, y1, z)
  , m_p10( x1, y0, z)
  , m_p11( x1, y1, z)
  {}

  inline
  Rect::Rect( Pos const & p00, int iWidth, int iHeight)
  : m_p00( p00)
  , m_p01( p00)
  , m_p10( p00)
  , m_p11( p00)
  {
    m_p01.m_x += iHeight;
    m_p10.m_y += iWidth;
    m_p11.m_x += iHeight;
    m_p11.m_y += iWidth;
  }

  inline
  Rect::Rect( Line const & line, Pos const & relVector)
  : m_p00( line.m_p0)
  , m_p01( line.m_p1)
  , m_p10( line.m_p0 + relVector)
  , m_p11( line.m_p1 + relVector)
  {}

  inline
  Line Rect::GetSide0() const
  {
    return Line( m_p00, m_p01);
  }

  inline
  Line Rect::GetSide1() const
  {
    return Line( m_p01, m_p11);
  }
  
  inline
  Line Rect::GetSide2() const
  {
    return Line( m_p11, m_p10);
  }
  
  inline
  Line Rect::GetSide3() const
  {
    return Line( m_p10, m_p00);
  }

  inline
  Rect::operator Pos const *() const
  {
    return & m_p00;
  }
}
