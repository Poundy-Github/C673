
#include "vis_gl_mat.h"

#include "vis_gl_pos.h"
#include "vis_gl_rect.h"
#include "vis_gl_pixel.h"

#ifndef D2R
#  include <math.h>
#  define D2R ( M_PI / 180)
#endif

using namespace GL;

Mat::Mat()
{
  for( int i=0; i < sizeof( m_a) / sizeof( m_a[0][0]); i++)
  {
    (&m_a[0][0])[i] = 0;
  }
  m_a[0][0] = 1;
  m_a[1][1] = 1;
  m_a[2][2] = 1;
  m_a[3][3] = 1;
}

Mat::Mat( double * dRowCol4x4)
{
  memcpy( m_a[0], dRowCol4x4, sizeof( m_a));
}

Mat Mat::RotateZ( double fAngleRad)
{
  Mat m;
  m.m_a[0][0] = cos( fAngleRad);
  m.m_a[1][1] = cos( fAngleRad);
  m.m_a[0][1] = -sin( fAngleRad);
  m.m_a[1][0] = sin( fAngleRad);
  m.m_a[3][3] = 1;
  return m;
}

Mat Mat::RotatePitch( double fAngleRad)
{
  Mat m;
  m.m_a[0][0] = cos( fAngleRad);
  m.m_a[2][2] = cos( fAngleRad);
  m.m_a[0][2] = -sin( fAngleRad);
  m.m_a[2][0] = sin( fAngleRad);
  m.m_a[3][3] = 1;
  return m;
}

Mat Mat::Translate( Pos const & p)
{
  Mat m;
  m.m_a[0][3] = p.m_x;
  m.m_a[1][3] = p.m_y;
  m.m_a[2][3] = p.m_z;
  m.m_a[0][0] = 1;
  m.m_a[1][1] = 1;
  m.m_a[2][2] = 1;
  m.m_a[3][3] = 1;
  return m;
}

Mat Mat::GenGNR( double fYawRad, double fNickRad, double fRollRad)
{
  // aus http://de.wikipedia.org/wiki/Eulersche_Winkel

  double fy_cos = cos( fYawRad);
  double fy_sin = sin( fYawRad);
  double fn_cos = cos( fNickRad);
  double fn_sin = sin( fNickRad);
  double fr_cos = cos( fRollRad);
  double fr_sin = sin( fRollRad);
  Mat r;
  r.m_a[0][0] = fn_cos * fy_cos;
  r.m_a[0][1] = fn_cos * fy_sin;
  r.m_a[0][2] = - fn_sin;
  r.m_a[1][0] = fr_sin * fn_sin * fy_cos - fr_cos * fy_sin;
  r.m_a[1][1] = fr_sin * fn_sin * fy_sin + fr_cos * fy_cos;
  r.m_a[1][2] = fr_sin * fn_cos;
  r.m_a[2][0] = fr_cos * fn_sin * fy_cos + fr_sin * fy_sin;
  r.m_a[2][1] = fr_cos * fn_sin * fy_sin - fr_sin * fy_cos;
  r.m_a[2][2] = fr_cos * fn_cos;

  return r;
}

Mat Mat::Scale( double dx, double dy, double dz, double dw)
{
  Mat m;
  m.m_a[0][0] = dx;
  m.m_a[1][1] = dy;
  m.m_a[2][2] = dz;
  m.m_a[3][3] = dw;
  return m;
}

Pos GL::operator*( Mat const & m, Pos const & p)
{
  Pos r;
  r.m_x = Pos( m.m_a[0]) * p + m.m_a[0][3];
  r.m_y = Pos( m.m_a[1]) * p + m.m_a[1][3];
  r.m_z = Pos( m.m_a[2]) * p + m.m_a[2][3];
  return r;
}

Pixel GL::operator*( Mat const & m, Pixel const & p)
{
  Pos r = m * Pos( p.m_x, p.m_y, 0);
  return Pixel( r.m_x, r.m_y);
}

std::vector<Pos> GL::operator*( Mat const & m, std::vector<Pos> const & vecPos)
{
  std::vector<Pos> vecResult;
  vecResult.reserve( vecPos.size());
  for( size_t i=0; i < vecPos.size(); i++)
  {
    vecResult.push_back( m * vecPos[i]);
  }
  return vecResult;
}

Mat GL::operator*( Mat const & m1, Mat const & m2)
{
  Mat r;
  for( int ir=0; ir < 4; ir++)
  {
    for( int ic=0; ic < 4; ic++)
    {
      r.m_a[ir][ic] = 0;
      for( int i=0; i < 4; i++)
      {
        r.m_a[ir][ic] += m1.m_a[ir][i] * m2.m_a[i][ic];
      }
    }
  }
  return r;
}

Mat GL::operator+( Mat const & m1, Mat const & m2)
{
  Mat r;
  for( int ir=0; ir < 4; ir++)
  {
    for( int ic=0; ic < 4; ic++)
    {
      r.m_a[ir][ic] = m1.m_a[ir][ic] + m2.m_a[ir][ic];
    }
  }
  return r;
}

void Mat::Transpose()
{
  for( int ir=0; ir < 4; ir++)
  {
    for( int ic=ir+1; ic < 4; ic++)
    {
      double t = m_a[ir][ic];
      m_a[ir][ic] = m_a[ic][ir];
      m_a[ic][ir] = t;
    }
  }
}

Mat Mat::GetTransposed() const
{
  Mat m( *this);
  m.Transpose();
  return m;
}

GL::Rect GL::operator*( Mat const & m, Rect const & r)
{
  GL::Rect ret;
  ret.m_p00 = m * r.m_p00;
  ret.m_p01 = m * r.m_p01;
  ret.m_p11 = m * r.m_p11;
  ret.m_p10 = m * r.m_p10;
  return ret;
}
