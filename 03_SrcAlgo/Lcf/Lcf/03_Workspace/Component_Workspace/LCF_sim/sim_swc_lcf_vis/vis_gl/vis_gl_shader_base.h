
#pragma once

/** \class GL::ShaderBase
 *
 *  \brief Base clas of shader program
 *
 *  Encapsulates Vertex - and Fragment shader and the containing program.
 *
 *  \ingroup ld_vis2_opengl
 */

#include "vis_gl.h"
#include <string>
#include <vector>

#ifndef vis_gl_shader_baseH
#define vis_gl_shader_baseH

namespace GL
{

  class ShaderBase
  {
  public:
    /// @name CTOR/DTOR
    ///@{
    ShaderBase();

    /// @param cVertexShader NULL default shader
    /// @param cFragShader NULL default shader
    /// CTOR can be used in static
    ///
    /// Example:
    /// \code
    /// {
    ///   static ShaderBase akShader( "main() {...}", "main(){..}");
    ///   akShader.UseProgram()
    ///
    ///
    ///   akShader.UnuseProgram();
    /// }
    /// \endcode
    ShaderBase( char const * cVertexShader, char const * cFragShader);
    ~ShaderBase();
    ///@}

    /// @name Shader
    /// compile shader source
    ///@{
    /// @param cVertexShader shader source. if NULL use default
    void SetVertexShader( char const * cVertexShader);
    /// @param cFragmentShader shader source. if NULL use default
    void SetFragmentShader( char const * cFragmentShader);

    /// used to set multiple separate shader sources
    void SetFragmentShader( int iNum, char const ** cFragmentShader);
    ///@}

    /// @name shader Program
    /// Do program stuff like linking and calls glUseProgram
    ///@{
    void LinkProgram();
    void UseProgram();
    void UnuseProgram();
    bool IsProgramUsed() const;
    bool IsLinked() const;
    ///@}

    /// @name shader Arguments
    /// Set arguments via uniform
    ///@{
    void Uniform( char const * cName, double f);
    void Uniform( char const * cName, float f);
    void Uniform( char const * cName, float f1, float f2);
    void Uniform( char const * cName, int i);
    void Uniform( char const * cName, int i1, int i2);
    void Uniform2( char const * cName, float const * pf);
    void Uniform2( char const * cName, int const * pi);
    void GetActiveUniform( int iIndex, int & iLength, int & iSize, GLenum & eType, std::string & sName) const;
    std::vector<std::string> GetActiveUniforms() const;   ///< return all shader variables. Used for debugging.
    ///@}


  protected:
    /// @name Init and reset
    /// retrieve function pointer
    /// create shader and program resources
    /// @{
    void Init();
    void Cleanup();
    /// @}

    static void InitShader( GLint shader, char const * cShaderText);
    static void InitShader( GLint shader, int iNum, char const ** cShaderText);

    GLint m_program;
    GLint m_vertexShader;
    GLint m_fragmentShader;
    bool  m_bIsLinked;
    bool  m_bIsUsed;
  };
}

#endif // vis_gl_shader_baseH
