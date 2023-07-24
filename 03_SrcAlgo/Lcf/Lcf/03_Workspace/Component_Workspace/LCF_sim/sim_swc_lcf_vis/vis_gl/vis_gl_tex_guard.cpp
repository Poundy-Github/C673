
#include "vis_gl_tex_guard.h"

#include "vis_gl_texture_2d.h"

#include <assert.h>

#include <windows.h>
#include <GL/gl.h>

using namespace GL;

TexGuard::TexGuard( int iTexture)
: m_iTexture( iTexture)
{
  assert( iTexture);
  glBindTexture( GL_TEXTURE_2D, m_iTexture);
  glEnable( GL_TEXTURE_2D);
}

TexGuard::TexGuard( Texture2D const & textId)
: m_iTexture( textId.m_iTexture)
{
  assert( textId.m_iTexture);
  glBindTexture( GL_TEXTURE_2D, textId.m_iTexture);
  glEnable( GL_TEXTURE_2D);
}


TexGuard::~TexGuard()
{
  glBindTexture( GL_TEXTURE_2D, 0);
  glDisable( GL_TEXTURE_2D);
}
