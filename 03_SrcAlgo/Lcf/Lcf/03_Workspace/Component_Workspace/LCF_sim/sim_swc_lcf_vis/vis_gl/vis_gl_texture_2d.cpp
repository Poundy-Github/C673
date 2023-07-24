
#include "vis_gl_texture_2d.h"
#include "vis_gl.h"

#include <assert.h>

using namespace GL;

Texture2D::Texture2D( bool bAuto)
: m_iTexture( 0)
, m_bIsEnabled( false)
, m_bIsBind( false)
{
  if( bAuto)
  {
    Init();
    Bind();
    Enable();
  }
}

void Texture2D::Init()
{
  Gen();
  Bind();
  Enable();
  Parameter( false, false);
  Disable();
  Unbind();
}

void Texture2D::Reset()
{
  if( m_bIsEnabled)
    Disable();
  if( m_bIsBind)
    Unbind();
  if( m_iTexture)
    Delete();

}

Texture2D::Texture2D( Texture2D const & o)
: m_iTexture( o.m_iTexture)
, m_bIsBind( false)
, m_bIsEnabled( false)
{
  assert( ! o.m_iTexture && "copyCtor not allowed for initialised id's");
}

Texture2D & Texture2D::operator=( Texture2D const & o)
{
  assert( ! o.m_iTexture && "copyCtor not allowed for initialised id's");
  Reset();
  return *this;
}

Texture2D::~Texture2D()
{
  if( ! m_iTexture)
    return;
  Reset();
}

void Texture2D::Gen()
{
  assert( ! m_iTexture);
  m_iTexture = GenTexture();
}

void Texture2D::Delete()
{
  if( m_bIsBind)
    Unbind();
  if( m_bIsEnabled)
    Disable();
  DeleteTexture( m_iTexture);
  m_iTexture = 0;
}

void Texture2D::Bind()
{
  assert( ! m_bIsBind);
  BindTexture2D( m_iTexture);
  m_bIsBind = true;
}

void Texture2D::Unbind()
{
  assert( m_bIsBind);
  BindTexture2D( 0);
  m_bIsBind = false;
}

void Texture2D::Parameter( bool bMinMagLinear, bool bRepeat)
{
  TexParameter2D( GL_TEXTURE_MIN_FILTER, bMinMagLinear ? GL_LINEAR : GL_NEAREST);
  TexParameter2D( GL_TEXTURE_MAG_FILTER, bMinMagLinear ? GL_LINEAR : GL_NEAREST);
  TexParameter2D( GL_TEXTURE_WRAP_S    , bRepeat       ? GL_REPEAT : GL_CLAMP_TO_EDGE);
  TexParameter2D( GL_TEXTURE_WRAP_T    , bRepeat       ? GL_REPEAT : GL_CLAMP_TO_EDGE);
}

void Texture2D::Enable()
{
  assert( ! m_bIsEnabled);
  glEnable( GL_TEXTURE_2D);
  m_bIsEnabled = true;
}

void Texture2D::Disable()
{
  assert( m_bIsEnabled);
  glDisable( GL_TEXTURE_2D);
  m_bIsEnabled = false;
}

Texture2D::operator bool() const
{
  return m_iTexture != 0;
}

void Texture2D::Set()
{
  Bind();
  Enable();
}

void Texture2D::Unset()
{
  Unbind();
  Disable();
}
