
#include "GL/Glu.h"

#include "vis_gl_core.h"

#include <assert.h>

template<typename T>
void GL::GetTexImage2D( GLenum format, T * pixel, int iLevel)
{
  glGetTexImage( GL_TEXTURE_2D, iLevel, format, GLType<T>::TYPE_ID, pixel);
  GL::CheckError();
}

template<typename T>
void GL::TexImage2D( GLint internalformat, GL::Pixel const & dim, GLint border, GLenum format, const T * pixels, GLint level)
{
#ifdef _DEBUG
  GLint iTexture = -1;
  glGetIntegerv( GL_TEXTURE_BINDING_2D, & iTexture);
  assert( iTexture > 0);
#endif
  glTexImage2D( GL_TEXTURE_2D, level, internalformat, static_cast<GLsizei>( dim.m_x), static_cast<GLsizei>( dim.m_y), border, format, GLType<T>::TYPE_ID, pixels);
  GL::CheckError();
}

template<typename T>
void GL::ReadPixels( GL::Pixel const & origin, GL::Pixel const & ext, GLenum format, T *pixels)
{
  glReadPixels( static_cast<int>( origin.m_x), static_cast<int>( origin.m_y)
              , static_cast<int>( ext.m_x), static_cast<int>( ext.m_y)
              , format, GLType<T>::TYPE_ID, pixels);
  GL::CheckError();
}
