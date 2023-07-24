
#pragma once

namespace GL
{
  /** \class GL::TexGuard
   *
   *  \brief Encapsulates block binding of texture with enable/disable
   *
   *  Example:
   *  \code
   *
   *  void Myfund( int iTex)
   *  {
   *    TexGuard myTex( iTex);
   *
   *    // ... now using texture
   *  }
   *  \endcode
   *
   *  \ingroup ld_vis2_opengl
   */

  class Texture2D;

  class TexGuard
  {
  public:
    explicit TexGuard( int iTexture);
    explicit TexGuard( Texture2D const & textId);
    ~TexGuard();

  protected:
    int m_iTexture;
  };
}