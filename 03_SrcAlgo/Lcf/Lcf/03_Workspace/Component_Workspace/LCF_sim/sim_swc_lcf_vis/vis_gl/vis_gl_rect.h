#pragma once

#ifndef vis_gl_rectH
#define vis_gl_rectH

#include "vis_gl_pos.h"

namespace GL
{
  class Line;
  /** \class Rect
   *
   *  \brief AutoSAR rect
   *
   *  Encapsulates a rect in AutoSAR coordinate system.
   *
   *  Convention is first dimension is x, second s y.
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa \ref vis_gl_func_3d "OpenGL 3D wrapper functions"
   *  \ingroup ld_vis2_opengl_3d
   */

#pragma pack ( push)
#pragma pack( 4)

  class Rect
  {
  public:
    Rect();
    Rect( Pos const & p00, Pos const & p01, Pos const & p10, Pos const & p11);
    Rect( Pos const & p00, int iWidth, int iHeight);
    Rect( Pos const & p00, Pos const & ext);
    explicit Rect( Pos const & ext);
    Rect( float x0, float x1, float y0, float y1, float z);
    Rect( double x0, double x1, double y0, double y1, double z);
    /// @param lineX line in X direction if possible
    /// @param relVector orthogonal direction for parallel line
    Rect( Line const & lineX, Pos const & relVector);
    /// Create a rect from two parallel lines in Y-direction
    Rect( Line const & lineY1, Line const & lineY2);
    
    /// @param lineX line in X direction if possible
    /// @param dLeftWidth extens parall box from lineX Left ( positiv autosar Y) 
    static Rect LeftWidth( Line const & lineX, double dLeftWidth);
    /// @param lineX line in X direction if possible
    /// @param dWidth extens parall box from lineX
    static Rect MiddleWidth( Line const & lineX, double dWidth);
    static Rect MiddleWidth( GL::Pos const & p0, GL::Pos const & p1, double dWidth);

    GL::Pos GetCenter() const;

    void ExtendBouding( Pos const & pos);

    /// side 00->01
    Line GetSide0() const;
    /// side 01->11
    Line GetSide1() const;
    /// side 11->10
    Line GetSide2() const;
    /// side 10->01
    Line GetSide3() const;

    operator Pos const *() const;   ///< used for GL::VertexPointer

    Pos m_p00, m_p01, m_p11, m_p10;  /// << order is important for glVertex command
  };

  Rect operator+( Rect const & r, Pos const & pos);

}
#pragma pack ( pop)

#endif // vis_gl_rectH
