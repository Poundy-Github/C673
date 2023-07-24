#pragma once

#ifndef vis_gl_vertex_pointerH
#define vis_gl_vertex_pointerH

#include "vis_gl.h"
#include <vector>

namespace GL
{
  class Pos;
  class Pixel;
  class Color;
  class Normal;

  /** \class GL::VertexPointer
   *
   *  \brief wrapper around glVertexPointer
   *
   *  Wrapper around glVertexPointer.
   *
   *  \b Features:
   *  - datatype wrapper : GL::pos, GL::Pixel
   *  - enables needed client attributes in the visibile context
   *  - DTOR resets client attributes
   *  - supports routines which should be called in the context.
   *
   *  \b Example:
   *
   *  \code
   *  void MyOpenGLDrawFunc()
   *  {
   *    vector<GL::Pos> vecPos = GetPositionVector( ...);
   *    vector<GL::Color> vecColor = GetColorVector( ...);
   *
   *    // vecPos and vecColor must have same size.
   *
   *    VertexPointer vertexPointer( vecPos);
   *    
   *    vertexPointer.AddColor( vecColor);
   *    
   *    vertexPointer.DrawArrays( GL_POINTS, 0, vecPos.size());
   *    
   *    
   *    // at DTOR client attributes are previous
   *  }
   *  \endcode
   *
   *  \ingroup ld_vis2_opengl
   */

  class VertexPointer
  {
  public:
    /// Enables client attributes and register vertexPointer
    explicit VertexPointer( Pos const * pos, int iStride = 0);
    /// Enables client attributes and register vertexPointer
    explicit VertexPointer( Pixel const * pixel, int iStride = 0);

    /// Disables cliebt Attributes to previous
    ~VertexPointer();

    /// Enables client attributes to color and register Color Pointer
    void AddColor( std::vector<Color> const & vecColor);

    void AddTexCoord( Pos const * pPos, int iStride = 0);
    void AddTexCoord( Pixel const * pPixel, int iStride = 0);
    void AddTexCoord( std::vector<Pos> const & vecPos, int iStride = 0);
    void AddTexCoord( std::vector<Pixel> const & vecPixel, int iStride = 0);

    /// Enables client attributes to normal and register Normal Pointer
    void AddNormal( std::vector<Normal> const & vecNormal);

    /// wrapper around glDrawArrays
    void DrawArrays( GLenum mode, GLint first, size_t count) const;
  private:
    VertexPointer();
    VertexPointer( VertexPointer const & o);

  protected:
    bool m_bHasColor;
    bool m_bHasNormal;
    bool m_bHasTex;
  };
}

// #include "vis_gl_vertex_pointer.inl"

#endif // vis_gl_vertex_pointerH
