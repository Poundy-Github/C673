#pragma once

#ifndef vis_gl_matrix_guardH
#define vis_gl_matrix_guardH

#include "vis_gl.h"

namespace GL
{
  /** \class GL::MatrixGuard
   *
   *  Saves selected Matrix on OpenGL stack. Only the selected Matrix will be restored.
   *  The usage is to switch to new matrix mode and manipulate the new matrix mode.
   *
   *  \ingroup ld_vis2_opengl
   */
  class MatrixGuard
  {
  public:
    /**
     * Select mode and push matrix state on the stack.
     * @param mode select GL_MODELVIEW, GL_PROJECTION or GL_TEXTURE
     */
    explicit MatrixGuard( GLenum mode);

    /// restores previous matrix mode and pop from matrix stack
    ~MatrixGuard();

  private:
    MatrixGuard( MatrixGuard const & o);
    MatrixGuard & operator=( MatrixGuard const & o);

  protected:
    static void Init();
    static GLint iMaxProjStack;
    static GLint iMaxModelStack;
    static GLint iMaxTexStack;
    GLint m_iAkDeep;
    GLenum m_newMode;
    float m_fMat4x4[4][4];
    bool m_bUseStack;
  };

}

#endif // vis_gl_matrix_guardH
