
#include "vis_gl_rect.h"

#include "vis_gl_line.h"

using namespace GL;

GL::Rect::Rect()
{}

GL::Rect::Rect( GL::Pos const & p00, GL::Pos const & p01, GL::Pos const & p10, GL::Pos const & p11)
: m_p00( p00)
, m_p01( p01)
, m_p10( p10)
, m_p11( p11)
{}

GL::Rect::Rect( float x0, float x1, float y0, float y1, float z)
: m_p00( x0, y0, z)
, m_p01( x0, y1, z)
, m_p10( x1, y0, z)
, m_p11( x1, y1, z)
{}

GL::Rect::Rect( double x0, double x1, double y0, double y1, double z)
: m_p00( static_cast<float>( x0), static_cast<float>( y0), z)
, m_p01( static_cast<float>( x0), static_cast<float>( y1), z)
, m_p10( static_cast<float>( x1), static_cast<float>( y0), z)
, m_p11( static_cast<float>( x1), static_cast<float>( y1), z)
{}

GL::Rect::Rect( GL::Pos const & p00, int iWidth, int iHeight)
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

GL::Rect::Rect( Pos const & p00, Pos const & ext)
: m_p00( p00)
, m_p01( p00 + GL::Pos( 0, ext.m_y))
, m_p10( p00 + GL::Pos( ext.m_x, 0))
, m_p11( p00 + ext)
{}

GL::Rect::Rect( Pos const & ext)
: m_p00( GL::Pos( 0, 0))
, m_p01( GL::Pos( 0, ext.m_y))
, m_p10( GL::Pos( ext.m_x, 0))
, m_p11( ext)
{}

GL::Rect::Rect( GL::Line const & lineX, Pos const & relVector)
: m_p00( lineX.m_p0)
, m_p01( lineX.m_p0 + relVector)
, m_p10( lineX.m_p1)
, m_p11( lineX.m_p1 + relVector)
{}

Rect::Rect( Line const & lineY1, Line const & lineY2)
: m_p00( lineY1.m_p0)
, m_p01( lineY1.m_p1)
, m_p10( lineY2.m_p0)
, m_p11( lineY2.m_p1)
{}

GL::Rect GL::Rect::LeftWidth( Line const & lineX, double dLeftWidth)
{
  GL::Pos LeftDir = lineX.GetDir().LeftAutoSAR( dLeftWidth);

  GL::Rect r;
  r.m_p00 = lineX.m_p0 + LeftDir;
  r.m_p01 = lineX.m_p0;
  r.m_p10 = lineX.m_p1 + LeftDir;
  r.m_p11 = lineX.m_p1;
  return r;
}


Rect GL::Rect::MiddleWidth( Line const & lineX, double dWidth)
{
  GL::Pos dir = lineX.GetDir();
  GL::Pos up( 0, 0, 1);
  GL::Pos sideDir = GL::Pos::Cross( dir, up).GetNormalised() * (dWidth / 2);

  GL::Rect r;
  r.m_p00 = lineX.m_p0 - sideDir;
  r.m_p01 = lineX.m_p0 + sideDir;
  r.m_p10 = lineX.m_p1 - sideDir;
  r.m_p11 = lineX.m_p1 + sideDir;
  return r;
}

Rect Rect::MiddleWidth( GL::Pos const & p0, GL::Pos const & p1, double dWidth)
{
  return MiddleWidth( GL::Line( p0, p1), dWidth);
}

GL::Line GL::Rect::GetSide0() const
{
  return Line( m_p00, m_p01);
}

GL::Line GL::Rect::GetSide1() const
{
  return Line( m_p01, m_p11);
}

GL::Line GL::Rect::GetSide2() const
{
  return Line( m_p11, m_p10);
}

GL::Line GL::Rect::GetSide3() const
{
  return Line( m_p10, m_p00);
}

GL::Rect::operator GL::Pos const *() const
{
  return & m_p00;
}

void Rect::ExtendBouding( Pos const & pos)
{
  m_p00.m_x = min( m_p00.m_x, pos.m_x);
  m_p01.m_x = min( m_p01.m_x, pos.m_x);
  m_p10.m_x = max( m_p10.m_x, pos.m_x);
  m_p11.m_x = max( m_p11.m_x, pos.m_x);

  m_p00.m_y = min( m_p00.m_y, pos.m_y);
  m_p10.m_y = min( m_p10.m_y, pos.m_y);
  m_p01.m_y = max( m_p01.m_y, pos.m_y);
  m_p11.m_y = max( m_p11.m_y, pos.m_y);
}

GL::Rect GL::operator+( Rect const & r, Pos const & pos)
{
  Rect ret = r;
  ret.m_p00 += pos;
  ret.m_p01 += pos;
  ret.m_p11 += pos;
  ret.m_p10 += pos;
  return ret;
}

GL::Pos Rect::GetCenter() const
{
  return ( m_p00 + m_p01 + m_p11 + m_p10 ) / 4;
}
