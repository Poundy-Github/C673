
#pragma once

#ifndef gl_vis_matH
#define gl_vis_matH

/** \class GL::Mat
 *
 *  For Matrix operations with GL::Pos
 *
 *  Attension:
 *  The representation of Mat is transposed to OpenGL
 *
 *  \ingroup ld_vis2_opengl_3d
 *
 */

#include <vector>

namespace GL
{
  class Pos;
  class Rect;
  class Pixel;

  class Mat
  {
  public:
    /// Creates Id matrix
    Mat();
    Mat( double * dRowCol4x4);

    /// @name Matrix generation
    ///@{
    static Mat RotateZ( double fAngleRad);
    static Mat RotatePitch( double fAngleRad);
    static Mat Translate( Pos const & p);
    static Mat GenGNR( double fYawRad, double fPitchRad, double fRollRad);
    static Mat Scale( double dx, double dy, double dz, double dw = 1);
    ///@}

    friend Pos operator*( Mat const & m, Pos const & p);
    friend Rect operator*( Mat const & m, Rect const & r);
    friend Pixel operator*( Mat const & m, Pixel const & p);
    friend std::vector<Pos> operator*( Mat const & m, std::vector<Pos> const & vecPos);
    friend Mat operator*( Mat const & m1, Mat const & m2);  ///< linear matrix multiplication
    friend Mat operator+( Mat const & m1, Mat const & m2);  ///< component wise addition
    friend void MultMatrix( Mat const & mat);  ///< wrapper around glMultMatrix
    friend void LoadMatrix( Mat const & mat);  ///< wrapper around glLoadMatrix
    friend Mat GetProjectionMatrix();          ///< wrapper arounnd glGet( GL_PROJECTION_MATRIX)
    friend Mat GetModelViewMatrix();           ///< wrapper arounnd glGet( GL_MODELVIEW_MATRIX)

    void Transpose();  ///< used for OpenGL interface. OpenGL matrix classes are arranged col/row
    Mat GetTransposed() const;  //< @return Transpose() instance

  protected:
    double m_a[4][4];  ///< row,col
  };

  /// component wise addition
  Mat operator+( Mat const & m1, Mat const & m2);
}

#endif // gl_vis_matH
