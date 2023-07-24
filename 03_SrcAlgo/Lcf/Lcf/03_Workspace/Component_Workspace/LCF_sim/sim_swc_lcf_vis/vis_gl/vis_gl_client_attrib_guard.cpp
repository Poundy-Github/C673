
#include "vis_gl_client_attrib_guard.h"

#include <assert.h>

#define GL_IN_ARG( v) ( a1 == v || a2 == v || a3 == v || a4 == v || a5 == v || a6 == v)


GL::ClientAttribGuard::ClientAttribGuard( GLenum a1, GLenum a2, GLenum a3, GLenum a4, GLenum a5, GLenum a6)
{
#ifdef _DEBUG
  if( ! iMaxStack)
  {
    glGetIntegerv( GL_MAX_CLIENT_ATTRIB_STACK_DEPTH, & iMaxStack);
  }

  glGetIntegerv( GL_CLIENT_ATTRIB_STACK_DEPTH, & m_iAkStackDepth);
  assert( m_iAkStackDepth + 1 < iMaxStack);
#endif
  glPushClientAttrib( GL_CLIENT_ALL_ATTRIB_BITS);
  if( a1) glEnableClientState( a1);
  if( a2) glEnableClientState( a2);
  if( a3) glEnableClientState( a3);
  if( a4) glEnableClientState( a4);
  if( a5) glEnableClientState( a5);
  if( a6) glEnableClientState( a6);

  if( ! GL_IN_ARG( GL_COLOR_ARRAY))
    glDisableClientState( GL_COLOR_ARRAY);
  if( ! GL_IN_ARG( GL_EDGE_FLAG_ARRAY))
    glDisableClientState( GL_EDGE_FLAG_ARRAY);
  if( ! GL_IN_ARG( GL_INDEX_ARRAY))
    glDisableClientState( GL_INDEX_ARRAY);
  if( ! GL_IN_ARG( GL_NORMAL_ARRAY ))
    glDisableClientState( GL_NORMAL_ARRAY );
  if( ! GL_IN_ARG( GL_TEXTURE_COORD_ARRAY))
    glDisableClientState( GL_TEXTURE_COORD_ARRAY);
  if( ! GL_IN_ARG( GL_VERTEX_ARRAY))
    glDisableClientState( GL_VERTEX_ARRAY);
#undef GL_IN_ARG
}

GL::ClientAttribGuard::~ClientAttribGuard()
{
#ifdef _DEBUG
  GLint iAkStackDepth;
  glGetIntegerv( GL_CLIENT_ATTRIB_STACK_DEPTH, & iAkStackDepth);
  assert( m_iAkStackDepth == iAkStackDepth - 1);
#endif
  glPopClientAttrib();
}
