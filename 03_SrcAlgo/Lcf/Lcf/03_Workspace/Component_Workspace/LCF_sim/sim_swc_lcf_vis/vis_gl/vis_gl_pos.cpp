
#include "vis_Gl_pos.h"

#include "vis_gl_screen.h"

#include "vis_gl_mat.h"

#include <math.h>
#include <assert.h>
#include <float.h>
#include <iostream>

using namespace GL;

GL::Pos::Pos()
: m_x( -1)
, m_y( -1)
, m_z( -1)
{}

GL::Pos::Pos( Screen const & screen)
: m_x( screen.m_x)
, m_y( screen.m_y)
{}

GL::Pos::Pos( double x, double y, double z)
: m_x( x)
, m_y( y)
, m_z( z)
{}

GL::Pos::Pos( double const * x3)
: m_x( x3[0])
, m_y( x3[1])
, m_z( x3[2])
{}

GL::Pos & GL::Pos::operator+=( Pos const & o)
{
  m_x += o.m_x;
  m_y += o.m_y;
  m_z += o.m_z;
  return *this;
}

bool GL::Pos::operator==( Pos const & o) const
{
  return fabs( m_x - o.m_x) < DBL_EPSILON && fabs( m_y - o.m_y) < DBL_EPSILON && fabs( m_z - o.m_z) < DBL_EPSILON;
}

bool GL::Pos::operator!=( Pos const & o) const
{
  return ! operator==( o);
}

GL::Pos::Pos( Pos const & o)
: m_x( o.m_x)
, m_y( o.m_y)
, m_z( o.m_z)
{}

GL::Pos GL::operator+( Pos const & p1, Pos const & p2)
{
  return Pos( p1) += p2;
}

GL::Pos GL::operator*( double f, Pos const & p)
{
  return GL::Pos( p)*= f;
}

GL::Pos GL::operator/( Pos const & p, double fDiv)
{
  return Pos( p) /= fDiv;
}

GL::Pos GL::operator-( Pos const & p1, Pos const & p2)
{
  return Pos( p1)-= p2;
}

GL::Pos::operator double const*() const
{
  return & m_x;
}

double const * GL::Pos::GetType() const
{
  return & m_x;
}

double GL::Pos::Length() const
{
  return sqrt( m_x * m_x + m_y * m_y + m_z * m_z);
}

void GL::Pos::Normalise()
{
  double fLength = Length();
  assert( fLength >= DBL_EPSILON);
  m_x /= fLength;
  m_y /= fLength;
  m_z /= fLength;
}

GL::Pos GL::Pos::GetNormalised() const
{
  GL::Pos p( *this);
  p.Normalise();
  return p;
}

GL::Pos GL::operator*( GL::Pos const & p, double f)
{
  return f * p;
}

double GL::operator*( GL::Pos const & p1, Pos const & p2)
{
  return p1.m_x * p2.m_x +
         p1.m_y * p2.m_y +
         p1.m_z * p2.m_z;
}

GL::Pos GL::Pos::Cross( GL::Pos const & a, GL::Pos const & b)
{
  return GL::Pos( a.m_y * b.m_z - a.m_z * b.m_y
                , a.m_z * b.m_x - a.m_x * b.m_z
                , a.m_x * b.m_y - a.m_y * b.m_x);
}

GL::Pos & GL::Pos::operator-=( GL::Pos const & o)
{
  m_x -= o.m_x;
  m_y -= o.m_y;
  m_z -= o.m_z;
  return *this;
}

GL::Pos & GL::Pos::operator*=( double f)
{
  m_x *= f;
  m_y *= f;
  m_z *= f;
  return *this;
}

GL::Pos & GL::Pos::operator/=( double f)
{
  m_x /= f;
  m_y /= f;
  m_z /= f;
  return *this;
}

GL::Pos GL::Pos::operator-() const
{
  return GL::Pos( - m_x, - m_y, - m_z);
}

void GL::Pos::RotateZ( double dAngleRad)
{
  *this = GL::Mat::RotateZ( dAngleRad) * *this;
}

Pos Pos::LeftAutoSAR( double dLen) const
{
  Pos up( 0, 0, 1);
  return Pos::Cross( *this, -up).GetNormalised() * dLen;
}

double Pos::GetXAzimuthRad() const
{
  return atan2( m_y, m_x);
}

Pos Pos::AzimuthDirX( double dAzimuthRadX, double dLen)
{
  return Pos( cos( dAzimuthRadX) * dLen, sin( dAzimuthRadX) * dLen, 0.0);
}

std::ostream & GL::operator<<( std::ostream & os, GL::Pos const & p)
{
  return os << "(" << p.m_x << "," << p.m_y << "," << p.m_z << ")";
}

double GL::Pos::Distance( GL::Pos const & p1, GL::Pos const & p2)
{
  return ( p1 - p2).Length();
}

GL::Pos GL::Pos::GetXYPlane() const
{
  GL::Pos r( *this);
  r.m_z = 0;
  return r;
}

GL::Pos GL::Pos::LeftAutoSAR( Pos const & p0, Pos const & p1, double dLeftDist, bool bStart)
{
  GL::Pos dir = p1 - p0;
  GL::Pos left = dir.LeftAutoSAR( dLeftDist);
  return bStart ? left + p0 : left + p1;
}

GL::Pos GL::Pos::DirectionNext( GL::Pos const & p0, GL::Pos const & p1, double dLen)
{
  return p0 + ( ( p1-p0).GetNormalised() * dLen);
}

GL::Pos GL::Pos::LeftAutoSAR( double dAzimuthRad, double dLeftDist) const
{
  GL::Pos dir = AzimuthDirX( dAzimuthRad);
  return LeftAutoSAR( *this, *this + dir, dLeftDist, true);
}
