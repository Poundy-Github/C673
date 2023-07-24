
#include "vis_gl_normal.h"

#include "vis_gl.h"

#include <math.h>
#include <assert.h>
#include <float.h>

using namespace GL;

Normal::Normal()
: m_nx( -1)
, m_ny( -1)
, m_nz( -1)
{}

Normal::Normal( Pos const & pos)
: m_nx( pos.m_x)
, m_ny( pos.m_y)
, m_nz( pos.m_z)
{}

Normal::Normal( double nx, double ny, double nz)
: m_nx( nx)
, m_ny( ny)
, m_nz( nz)
{}

Normal & Normal::operator=( Pos const & pos)
{
  m_nx = pos.m_x;
  m_ny = pos.m_y;
  m_nz = pos.m_z;
  return *this;
}

Normal & Normal::operator=( Normal const & o)
{
  m_nx = o.m_nx;
  m_ny = o.m_ny;
  m_nz = o.m_nz;
  return *this;
}

void Normal::InflateHeight( double f)
{
  m_nz *= f;
}

void Normal::Normalize()
{
  double l = sqrt( m_nx * m_nx + m_ny * m_ny + m_nz * m_nz);

  assert( l > DBL_EPSILON);
  m_nx /= l;
  m_ny /= l;
  m_nz /= l;
}

Normal GL::operator/( Normal const & n, double f)
{
  return Normal( n.m_nx / f, n.m_ny / f, n.m_nz / f);
}

Normal GL::operator+( Normal const & n1, Normal const & n2)
{
  return Normal( n1.m_nx + n2.m_nx, n1.m_ny + n2.m_ny, n1.m_nz + n2.m_nz);
}

Normal::operator double const*() const
{
  return & m_nx;
}

Normal::operator void const*() const
{
  return & m_nx;
}
