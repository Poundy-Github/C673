
#include "vis_gl_line.h"

using namespace GL;

GL::Line::Line()
{}

GL::Line::Line( Pos const & p0, Pos const & p1)
: m_p0( p0)
, m_p1( p1)
{}

GL::Line GL::operator+( Line const & line, Pos const & offset)
{
  Line ret = line;
  ret.m_p0 += offset;
  ret.m_p1 += offset;
  return ret;
}

Pos Line::GetDir() const
{
  return m_p1 - m_p0;
}

GL::Line::operator GL::Pos const *() const
{
  return & m_p0;
}

Pos Line::Middle() const
{
  return GetDir() / 2 + m_p0;
}

void Line::Revers()
{
  Pos p = m_p0;
  m_p0 = m_p1;
  m_p1 = p;
}

Line Line::GetRevers() const
{
  Line r = *this;
  r.Revers();
  return r;
}

double Line::Length() const
{
  return GetDir().Length();
}

Line Line::X( double x1, double x2, double y)
{
  return Line( Pos( x1, y), Pos( x2, y));
}

Line Line::Y( double x, double y1, double y2)
{
  return Line( Pos( x, y1), Pos( x, y2));
}

Line Line::Z( double x, double y, double z1, double z2)
{
  Line ret;
  ret.m_p0.m_x = ret.m_p1.m_x = x;
  ret.m_p0.m_y = ret.m_p1.m_y = y;
  ret.m_p0.m_z = z1;
  ret.m_p1.m_z = z2;
  return ret;
}
