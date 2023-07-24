#pragma once

#ifndef vis_gl_client_attrib_guardH
#define vis_gl_client_attrib_guardH

/** \class GL::ClientAttribGuard
 *
 *  \brief Guard for OpenGL glEnableClientAttrib
 *
 *  Pushes actual attrib on stack, set new. DTOR restore previous values.
 *
 *  \sa GL::VertexPointer for more convinient usage.
 *
 *  Example:
 *  \code
 *  void MyFunc()
 *  {
 *    ClientAttribGuard clientGuard( GL_VERTEX_ARRAY, GL_COLOR_ARRAY);
 *
 *    // do something...
 *  }
 *  \endcode
 *
 *  \ingroup ld_vis2_opengl
 */

#include <windows.h>
#include <GL/GL.h>

namespace GL
{
  class ClientAttribGuard
  {
  public:
    /// pushes client attributes on stack. Possible values : GL_COLOR_ARRAY, GL_EDGE_FLAG_ARRAY
    /// , GL_INDEX_ARRAY, GL_NORMAL_ARRAY, GL_TEXTURE_COORD_ARRAY, GL_VERTEX_ARRAY
    /// @param a1 parameter from glPushClientAttrib
    /// @param a2 parameter from glPushClientAttrib
    /// @param a3 parameter from glPushClientAttrib
    /// @param a4 parameter from glPushClientAttrib
    /// @param a5 parameter from glPushClientAttrib
    /// @param a6 parameter from glPushClientAttrib
    explicit ClientAttribGuard( GLenum a1 = 0, GLenum a2 = 0, GLenum a3 = 0, GLenum a4 = 0, GLenum a5 = 0, GLenum a6 = 0);
    /// pop client attributes from stack
    ~ClientAttribGuard();

  protected:
    static GLint iMaxStack;   ///< only used if _DEBUG defined
    GLint m_iAkStackDepth;   ///< only used if _DEBUG defined
  };
}

#endif // vis_gl_client_attrib_guardH
