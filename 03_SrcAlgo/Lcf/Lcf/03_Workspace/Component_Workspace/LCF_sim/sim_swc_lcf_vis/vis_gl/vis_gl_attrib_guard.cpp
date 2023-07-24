
#include "vis_gl_attrib_guard.h"

#include <assert.h>

GL::AttribGuard::AttribGuard( GLbitfield attr)
{
  if( ! iMaxAttribStack)
  {
    glGetIntegerv( GL_MAX_ATTRIB_STACK_DEPTH, & iMaxAttribStack);
  }
  glGetIntegerv( GL_ATTRIB_STACK_DEPTH, & m_iAkStackDeep);
  if( m_iAkStackDeep + 1 < iMaxAttribStack)
  {
    glPushAttrib( attr);
    m_bUsed = true;
  }
  else
    m_bUsed = false;

}

GL::AttribGuard::~AttribGuard()
{
  End();
}

void GL::AttribGuard::End()
{
  if( m_bUsed)
  {
    GLint iAkStackDeep;
    glGetIntegerv( GL_ATTRIB_STACK_DEPTH, & iAkStackDeep);
    assert( iAkStackDeep == m_iAkStackDeep + 1);
    glPopAttrib();
    m_bUsed = false;
  }
}
