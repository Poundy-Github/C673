
#include "vis_gl_matrix_guard.h"

#include "vis_gl.h"

#include <assert.h>

using namespace GL;

//--------------  config section  -----------------

#define MAT_GUARD_USE_STACK 0

//-------------------------------------------------

static GLenum StackDepth( GLenum matrixMode)
{
  switch( matrixMode)
  {
  case GL_MODELVIEW: return GL_MODELVIEW_STACK_DEPTH;
  case GL_PROJECTION: return GL_PROJECTION_STACK_DEPTH;
  case GL_TEXTURE: return GL_TEXTURE_STACK_DEPTH;
  default:
    assert( 0 && "never reach");
    return (GLenum) -1;  // satisfy the compiler
  }
}

#pragma warning ( suppress: 4505 )
static GLenum MaxStackDepth( GLenum matrixMode)
{
  switch( matrixMode)
  {
  case GL_MODELVIEW: return GL_MAX_MODELVIEW_STACK_DEPTH;
  case GL_PROJECTION: return GL_MAX_PROJECTION_STACK_DEPTH;
  case GL_TEXTURE: return GL_MAX_TEXTURE_STACK_DEPTH;
  default:
    assert( 0 && "never reach");
    return (GLenum) -1;  // satisfy the compiler
  }
}

static GLenum GetMatrix( GLenum matrixMode)
{
  switch( matrixMode)
  {
  case GL_PROJECTION: return GL_PROJECTION_MATRIX;
  case GL_MODELVIEW: return GL_MODELVIEW_MATRIX;
  case GL_TEXTURE: return GL_TEXTURE_MATRIX;
  default:
    assert( 0 && "never reach");
    return (GLenum) -1;  // satisfy the compiler
  }
}

void MatrixGuard::Init()
{
  if( ! iMaxModelStack)
  {
    glGetIntegerv( GL_MAX_MODELVIEW_STACK_DEPTH, & iMaxModelStack);
    GL::CheckError();
  }
  if( ! iMaxProjStack)
  {
    glGetIntegerv( GL_MAX_PROJECTION_STACK_DEPTH, & iMaxProjStack);
    CheckError();
  }
  if( ! iMaxTexStack)
  {
    glGetIntegerv( GL_MAX_TEXTURE_STACK_DEPTH, & iMaxTexStack);
    CheckError();
  }
}

MatrixGuard::MatrixGuard( GLenum mode)
{
  assert( mode == GL_MODELVIEW || mode == GL_PROJECTION || GL_TEXTURE);

  Init();

  glMatrixMode( m_newMode = mode);

#if MAT_GUARD_USE_STACK
  m_iAkDeep = -1;
  glGetIntegerv( StackDepth( mode), & m_iAkDeep);
  assert( m_iAkDeep != -1);
  if( ( m_iAkDeep + 1 < iMaxProjStack  && mode == GL_PROJECTION ||
        m_iAkDeep + 1 < iMaxModelStack && mode == GL_MODELVIEW ||
        m_iAkDeep + 1 < iMaxTexStack   && mode == GL_TEXTURE ))
  {
    glPushMatrix();
    m_bUseStack = true;
  }
  else
#endif
  {
    glGetFloatv( GetMatrix( m_newMode), m_fMat4x4[0]);
    m_bUseStack = false;
  }
  CheckError();
}

MatrixGuard::~MatrixGuard()
{
  glMatrixMode( m_newMode);
  if( m_bUseStack)
  {
#ifdef _DEBUG
    GLint iAkDeep;
    glGetIntegerv( StackDepth( m_newMode), & iAkDeep);
    assert( iAkDeep == m_iAkDeep + 1);
#endif

    glPopMatrix();
  }
  else
  {
    glLoadMatrixf( m_fMat4x4[0]);
  }
  CheckError();
}

