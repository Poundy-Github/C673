
#pragma once

#include "vis_gl.h"
#include <windows.h>
#include <vector>


namespace GL
{
  /** \class GL::Bitmap
   *
   *  Encapsulates Windows bmp - file usage with OpenGL.
   *
   *  Features:
   *  - handles line alignment 2 of bitmap format
   *  - used resolution if avaible:
   *    - use glScaled to rescale texture transformation
   *
   *  \sa GL::Texture2D
   *
   *  \ingroup ld_vis2_opengl
   */
  class Bitmap
  {
  public:
    Bitmap();
    Bitmap( std::string const & sFile); ///< \sa Load

    /// @name Image manipulation
    /// @{
    /// Loades following formats depending on extension:
    /// - BMP
    /// - PNG
    void Load( std::string const & sFile);

    /// Saves following formats depending on extension:
    /// - BMP
    /// - PNG
    /// - PPM ( color )
    /// - PGM ( gray - not using color map )
    void Save( std::string const & sFile) const;
    void Unload();  ///< free memory
    void Set( unsigned char * rgb, int iWidth, int iHeight);
    void Set( unsigned short * gray16, int iWidth, int iHeight, int iValidBits);
    /// @}

    /// @name Image attributes
    /// @{
    int Height() const;
    int Width() const;
    GL::Pixel GetExtension() const;
    int XPixelsPerMeter() const;  ///< resolution used within textures
    int YPixelsPerMeter() const;  ///< resolution used within textures

    void SetXPixelsPerMeter( int iPixels);
    void SetYPixelsPerMeter( int iPixels);
    void SetTopDown( bool bTopDown = true);  ///< only effects on BMP file format
    /// @}

    /// return initialised
    operator bool() const;

    /// @name OpenGL interface
    /// @{
    /// Wrapper around glTexImage2D and glPixelStorei with correct GL_PACK_ALIGNMENT from bitmap fileformat
    void TexImage( int iLevel = 0, int iInternalFormat = GL_RGBA, int iBorder = 0) const;

    /// Wrapper around glGetTexImage and glPixelStorei with correct GL_PACK_ALIGNMENT from bitmap fileformat
    void GetTexImage( int iLevel = 0, GLenum format = GL_RGB);

    /// glScale with internal resolution
    void ScaleXY( double dFakX, double dFakY) const;

    /// @param format GL_RGB, GL_BGRdependent for further usage GL_BGR used for save BMP fileformat
    void ReadPixels( GLenum format = GL_RGB);
    void ReadPixels(  Screen const & start, Screen const & size, GLenum format = GL_RGB);
    void ReadPixels(  GLint x, GLint y, GLsizei width, GLsizei height, GLenum format = GL_RGB);
    /// @}

  protected:
    enum Format { eUndef, eRgb, eRgbA, eBgr, eBgrA, eColorTable} m_format;

    int LineSize() const;
    void LoadWindowsBmp( std::string const & sFile);
    void ToRgb();
    void ToBgr();
    void SwapRgb();
    void EraseAlpha();
    static Format GL2Format( GLenum format);
#ifdef VIS_GL_PNG_SUPPORT
    void LoadPNG( std::string const & sFile);
    void SavePNG( std::string const & sFile) const;
#endif  // VIS_GL_PNG_SUPPORT
    void SaveBMP( std::string const & sFile) const;
    void SavePPM( std::string const & sFile) const;
    void SavePGM( std::string const & sFile) const;
    BITMAPINFOHEADER m_bih;
    std::vector<unsigned char> m_pixel;   ///< buffer to BMP linesize ( +3 / 4 * 4 )
    bool m_bValid;
    int m_iValidBits;
  };
}
