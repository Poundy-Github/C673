#pragma once

#ifndef vis_gl_posH
#define vis_gl_posH

#include <windows.h>
#include <GL/GL.h>

#include <iosfwd>

namespace GL
{
  /** \class Pos
   *
   *  \brief AutoSAR position
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa \ref vis_gl_func_3d "OpenGL 3D wrapper functions"
   *  \ingroup ld_vis2_opengl_3d
   *
   */

#pragma pack ( push)
#pragma pack( 4)

  class Screen;

  class Pos
  {
  public:
    Pos();
    explicit Pos( Screen const & screen);
    Pos( double x, double y, double z = 0);
    explicit Pos( double const * x3);
    Pos( Pos const & o);

    bool operator==( Pos const & o) const;
    bool operator!=( Pos const & o) const;

    Pos & operator+=( Pos const & o);
    Pos & operator-=( Pos const & o);
    Pos & operator*=( double f);
    Pos & operator/=( double f);
    Pos   operator-() const;

    operator double const*() const;
    double const * GetType() const;

    double Length() const;
    void Normalise();
    Pos GetNormalised() const;

    /// this is used as direction
    Pos LeftAutoSAR( double dLen) const;

    /// this is used as pos
    Pos LeftAutoSAR( double dAzimuthRad, double dLen) const;
    double GetXAzimuthRad() const;
    Pos GetXYPlane() const;  ///< @return x,y,z=0

    /// @param dAngleRad counter clock wise
    void RotateZ( double dAngleRad);

    static Pos Cross( Pos const & p1, Pos const & p2);
    /// @param dAzimuthRadX angle in rad from x direction
    /// @param dLen length in dAzimuthRadX direction
    /// @return normalized pos in direction 'dAzimuthRadX'
    static Pos AzimuthDirX( double dAzimuthRadX, double dLen = 1);
    static double Distance( GL::Pos const & p1, GL::Pos const & p2);
    /// Calculates a orthogonal point
    /// @param p0,p1 specify line
    /// @param dLeftDist lot distnace from line
    /// @param bStart true - lot point is p0, false - lot point is p1
    static Pos LeftAutoSAR( Pos const & p0, Pos const & p1, double dLeftDist, bool bStart);

    /// Calculates an enhanced point behind p1 in distance dLen
    static Pos DirectionNext( Pos const & p0, Pos const & p1, double dLen);

    double m_x;
    double m_y;
    double m_z;

    static const int GLType = GL_DOUBLE;  ///< changed if members becom a different type
  };

#pragma pack ( pop)

  Pos operator-( Pos const & p1, Pos const & p2);
  Pos operator*( double f, Pos const & p);
  Pos operator*( Pos const & p, double f);
  double operator*( Pos const & p1, Pos const & p2);
  Pos operator/( Pos const & p, double fDiv);
  Pos operator+( Pos const & p1, Pos const & p2);

  std::ostream & operator<<( std::ostream & os, GL::Pos const & p);
}

#endif // vis_gl_posH