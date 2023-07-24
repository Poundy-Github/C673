
#pragma once

#include "vis_gl.h"

namespace GL
{
  /** class GL::Texture2D
   *
   *  \brief Encalsulates a texture object.
   *
   *  Texture2D can be used as a stack obejct:
   \code
   *  Texture2D texObj( true);
   *  ... // do something with current texture obejct texObj
   \endcode
   *
   *  or as a class member:
   \code
   *  class A
   *  {
   *    void Render();
   *    Texture2D m_texObj;
   *  }
   *
   *  void A::Render()
   *  {
   *    if( ! m_texObj)
   *      m_texObj.Init();
   *    m_texObj.Bind();
   *    m_texObj.Enable();
   *    ... // do something rendering stuff
   *    m_texObj.Disable();
   *  }
   *  
   \endcode
   *
   *  \ingroup ld_vis2_opengl
   */

  class TexGuard;

  class Texture2D
  {
    friend class TexGuard;
  public:
    explicit Texture2D( bool bAutoInit = false);
    Texture2D( Texture2D const & o);
    Texture2D & operator=( Texture2D const & o);
    ~Texture2D();

    void Init();  ///< calls Gen() and set default Parameter( false, false);
    void Reset();  ///< shut down texture object if avaible

    void Set();  ///< call Bind/Enable
    void Unset();  ///< reset Set

    void Gen();   ///< glGenTexture
    void Delete();  ///< glDeleteTexture

    void Bind();  ///< glBindTexture
    void Unbind();  ///< glBindTexture( 0)

    void Enable();  ///< glEnable( GL_TEXTURE_2D)
    void Disable();  ///< glDisable( GL_TEXTURE_2D)

    void Parameter( bool bMinMagLinear, bool bRepeat);   ///< sets GL_TEXTURE_Mxx_FILTER and GL_TEXTURE_WRAP_x

    /// copy texture to hardware. \sa GL::Bitmap fuer easyer usage
    template<typename T>
    void Image( GLint internalformat, GLsizei width, GLsizei height, GLenum format, T const * pixels, GLint iLevel = 0, GLint border = 0);

    /// return true if created
    operator bool() const;

  protected:
    GLuint m_iTexture;
    bool m_bIsBind;
    bool m_bIsEnabled;
  };

  template<typename T>
  void Texture2D::Image( GLint internalformat, GLsizei width, GLsizei height, GLenum format, T const * pixels, GLint iLevel, GLint border)
  {
    glTexImage2D( GL_TEXTURE_2D, iLevel, internalformat, width, height, border, format, GLType<T>::TYPE_ID, pixels);
  }

}
