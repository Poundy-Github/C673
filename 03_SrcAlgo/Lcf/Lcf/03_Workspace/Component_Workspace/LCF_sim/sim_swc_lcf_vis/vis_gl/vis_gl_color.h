#pragma once

#ifndef vis_gl_colorH
#define vis_gl_colorH

#include <windows.h>
#include <GL/GL.h>

namespace GL
{
  /** \class Color
   *
   *  \brief opengl color
   *
   *  \sa \ref vis_gl_func "OpenGL wrapper functions"
   *  \sa GL::Color4
   *  \ingroup ld_vis2_opengl
   */

  class Color
  {
  public:
    Color();
    /// @param iSat 0-255
    /// @param iA opaque 0-255
    explicit Color( int iSat, int iA = 255);
    /// @param fSat 0-255
    /// @param fA opaque 0-1
    explicit Color( float fSat, float fA = 1.0);
    /// @param ucR 0-255
    /// @param ucG 0-255
    /// @param ucB 0-255
    /// @param ucA 0-255
    Color( int ucR, int ucG, int ucB, int ucA = 255);
    /// @param fR 0-1
    /// @param fG 0-1
    /// @param fB 0-1
    /// @param fA 0-1
    Color( float fR, float fG, float fB, float fA = 1.0F);
    /// @param dR 0-1
    /// @param dG 0-1
    /// @param dB 0-1
    /// @param dA 0-1
    Color( double dR, double dG, double dB, double dA = 1.0);

    /// use color with opaque value
    /// @param color 3 values color
    /// @param fA opaque value
    Color( Color const & color, float fA);

    Color( double dIntensity, double fOpaque);

    Color & operator*=( double f);    ///< bright or dark color \sa GL::operator*( GL::Color const &, double f)
    Color & operator*=( Color const & clr);  ///< multiply each component \sa GL::operator*( Color const &, Color const &)
    Color & operator/=( double f);    ///< bright or dark color \sa GL::operator/( GL::Color const &, double f)

    static float dot( Color c1, Color c2);  ///< like scalar product. Functions copied from GLSL

    operator float const*() const;

    float RedFloat() const;
    float GreenFloat() const;
    float BlueFloat() const;
    float AlphaFloat() const;

    float Saturation() const;

    void SetRed( float fRed);
    void SetGreen( float fRed);
    void SetBlue( float fRed);
    void SetAlpha( float fRed);

    /// @name colors
    /// values from http://en.wikipedia.org/wiki/Web_colors
    ///@{
    static const Color red;
    static const Color green;
    static const Color blue;
    static const Color white;
    static const Color black;
    static const Color yellow;
    static const Color cyan;
    static const Color aqua;  ///< sa GL::Color::cyan
    static const Color magenta;
    static const Color gray;
    static const Color silver;
    static const Color maroon;
    static const Color olive;
    static const Color lime;
    static const Color teal;
    static const Color navy;
    static const Color fuchsia;
    static const Color purple;

    static const Color orange;
    static const Color pink;
    static const Color hotPink;
    static const Color lightGray;
    static const Color violet;
    static const Color orangeRed;
    ///@}

    static const Color opaque;

    static const int GLType = GL_FLOAT;  ///< changed if members becom a different type

  protected:
    float m_fR, m_fG, m_fB, m_fA;

  };

  /**
   *  Example:
   *  \code
   *  GL::Color cResult = GL::Color::red * 0.5;
   *  \endcode
   *  \sa GL::Color::operator*=( double f)
   */
  Color operator*( Color const & color, double f);
  /**
   *  Example:
   *  \code
   *  GL::Color cResult = GL::Color::red * GL::Color( fBright, Opaque);
   *  \endcode
   *  \sa GL::Color::operator*( Color color)
   */
  Color operator*( Color const & color, Color const & c2);
  /**
   *  Example:
   *  \code
   *  GL::Color cResult = GL::Color::red / 2.5;
   *  \endcode
   *  \sa GL::Color::operator/=( double f)
   */
  Color operator/( Color const & color, double f);
}

#endif // vis_gl_colorH
