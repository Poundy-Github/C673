#pragma once

#ifndef vis_gl_attrib_guardH
#define vis_gl_attrib_guardH

#include <windows.h>
#include <GL/GL.h>

namespace GL
{
  /** \class GL::AttribGuard
   *
   *  \brief object guard to recover opengl attributes
   *
   *  Features:
   *  - check stack in _DEBUG
   *
   *  Example:
   *  \code
   *  void MyOpenGLDrawFunc()
   *  {
   *    GL::AttribGuard attrbGuard( GL_LIGHTING_BIT | GL_LINE_BIT | ...)
   *    
   *    do some glChanges here
   *    
   *    // at DTOR changes are pop'ed
   *  }
   *  \endcode
   *
   *  \ingroup ld_vis2_opengl
   */

  class AttribGuard
  {
  public:
    /// @param attr all bit combinations from glPushAttrib
    explicit AttribGuard( GLbitfield attr = GL_ALL_ATTRIB_BITS);

    /// reset to previous state
    ~AttribGuard();

    void End();  // can be called for pre pop

  private:
    AttribGuard( AttribGuard const & o);
    AttribGuard & operator=( AttribGuard const & o);

  protected:
    static GLint iMaxAttribStack;   ///< only used if _DEBUG defined
    GLint m_iAkStackDeep;   ///< only used if _DEBUG defined
    bool m_bUsed;
  };

}

#endif // vis_gl_attrib_guardH
