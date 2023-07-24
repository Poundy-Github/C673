
#include <windows.h>
#include "vis_gl_shader_base.h"
#include "vis_gl_exception.h"
#include "vis_gl.h"

#include <assert.h>

//-----------  OpenGL ---------------------

#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_COMPILE_STATUS 0x8B81

typedef char GLchar;

//--------------------- End OpenGL  -------------------------

using namespace GL;

ShaderBase::ShaderBase()
: m_program( 0)
, m_vertexShader( 0)
, m_fragmentShader( 0)
, m_bIsLinked( false)
, m_bIsUsed( false)
{
}

ShaderBase::ShaderBase( char const * cVertexShader, char const * cFragShader)
{
  SetVertexShader( cVertexShader);
  SetFragmentShader( cFragShader);
  LinkProgram();
}

void ShaderBase::Init()
{
  GL::Init();

  GL::CheckError();
  if( m_program)
    return;
  m_program = glCreateProgram();
  assert( m_program);
  GL::CheckError();
}

ShaderBase::~ShaderBase()
{
  Cleanup();
}

void ShaderBase::Cleanup()
{
  // Can not cleanup outside GLRC
  if( wglGetCurrentContext() == 0)
    return;

  if( m_vertexShader)
  {
    glDetachShader( m_program, m_vertexShader);
    glDeleteShader( m_vertexShader);
    m_vertexShader = 0;
  }
  if( m_fragmentShader)
  {
    glDetachShader( m_program, m_fragmentShader);
    glDeleteShader( m_fragmentShader);
    m_fragmentShader = 0;
  }
  if( m_program)
    glDeleteProgram( m_program);
  m_vertexShader = 0;
  m_fragmentShader = 0;
  m_program = 0;
  m_bIsUsed = false;
  GL::CheckError();
}

void ShaderBase::InitShader( GLint shader, char const * cShaderText)
{
  assert( cShaderText);
  InitShader( shader, 1, & cShaderText);
}

void ShaderBase::InitShader( GLint shader, int iNum, char const ** cShaderText)
{
  assert( shader);
  assert( cShaderText);
  glShaderSource( shader, iNum, cShaderText, 0);
  glCompileShader( shader);

  GLint iCompileStatus;
  glGetShaderiv( shader, GL_COMPILE_STATUS, & iCompileStatus);
  GL::CheckError();
  if( iCompileStatus != GL_TRUE)
  {
    char cErrBuf[1024];
    GLsizei length;
    glGetShaderInfoLog( shader, sizeof( cErrBuf), & length, cErrBuf);
    // std::vector<std::string> formatError = StringTok( cErrBuf, std::string( 1, '\n'));
    assert( 0 && "never reach. Shader MUST compile");
    throw vis_gl_exception( cErrBuf);
  }
}

void ShaderBase::SetVertexShader( char const * cVertexShader)
{
  Init();

  static char const cDefaultVertexShader[] = ""
  "void main()\n"
  "{\n"
  "  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
  "  gl_FrontColor = gl_Color;\n"
  "  gl_BackColor = gl_Color;\n"
  "}";

  if( ! cVertexShader)
    cVertexShader = cDefaultVertexShader;
  m_vertexShader = glCreateShader( GL_VERTEX_SHADER);
  GL::CheckError();
  assert( m_vertexShader);
  try
  {
    InitShader( m_vertexShader, cVertexShader);
  }
  catch( ...)
  {
    glDeleteShader( m_fragmentShader);
    m_fragmentShader = 0;
    throw;
  }
}

void ShaderBase::SetFragmentShader( int iNum, char const ** cFragmentShader)
{
  Init();
  m_fragmentShader = glCreateShader( GL_FRAGMENT_SHADER);
  assert( m_fragmentShader);
  GL::CheckError();
  try
  {
    InitShader( m_fragmentShader, iNum, cFragmentShader);
  }
  catch( ...)
  {
    glDeleteShader( m_fragmentShader);
    m_fragmentShader = 0;
    throw;
  }
}

void ShaderBase::SetFragmentShader( char const * cFragmentShader)
{
  static char const cFragShader[] =
  "void main()\n"
  "{\n"
  "  gl_FragColor = gl_Color;\n"
  "}\n"
  ;

  if( ! cFragmentShader)
    cFragmentShader = cFragShader;

  SetFragmentShader( 1, & cFragmentShader);
}

void ShaderBase::UnuseProgram()
{
  if( ! m_bIsUsed)
    return;
  glUseProgram( 0);
  GL::CheckError();
  m_bIsUsed = false;
}

void ShaderBase::LinkProgram()
{
  assert( ! m_bIsLinked);

  if( ! m_program)
    m_program = glCreateProgram();

  if( m_vertexShader)
    glAttachShader( m_program, m_vertexShader);
  if( m_fragmentShader)
    glAttachShader( m_program, m_fragmentShader);
  glLinkProgram( m_program);
  GL::CheckError();
  m_bIsLinked = true;
}

void ShaderBase::UseProgram()
{
  assert( ! m_bIsUsed);
  if( ! m_bIsLinked)
    LinkProgram();
  glUseProgram( m_program);
  GL::CheckError();
  m_bIsUsed = true;
}

void ShaderBase::Uniform( char const * cName, float f)
{
  assert( m_program && m_bIsLinked && m_bIsUsed);
  GLint loc = glGetUniformLocation( m_program, cName);
  assert( loc != -1);
  glUniform1f( loc, f);
  GL::CheckError();
}

void ShaderBase::Uniform( char const * cName, int i)
{
  assert( m_program && m_bIsLinked && m_bIsUsed);
  GLint loc = glGetUniformLocation( m_program, cName);
  assert( loc != -1);
  glUniform1i( loc, i);
  GL::CheckError();
}

void ShaderBase::Uniform( char const * cName, double f)
{
  assert( m_program && m_bIsLinked && m_bIsUsed);
  GLint loc = glGetUniformLocation( m_program, cName);
  assert( loc != -1);
  glUniform1f( loc, static_cast<float>( f));
  GL::CheckError();
}

void ShaderBase::Uniform( char const * cName, float f1, float f2)
{
  assert( m_program && m_bIsLinked && m_bIsUsed);
  GLint loc = glGetUniformLocation( m_program, cName);
  assert( loc != -1);
  glUniform2f( loc, f1, f2);
  GL::CheckError();
}

void ShaderBase::Uniform( char const * cName, int i1, int i2)
{
  assert( m_program && m_bIsLinked && m_bIsUsed);
  GLint loc = glGetUniformLocation( m_program, cName);
  assert( loc != -1);
  glUniform2i( loc, i1, i2);
  GL::CheckError();
}

void ShaderBase::Uniform2( char const * cName, float const * pf)
{
  assert( m_program && m_bIsLinked && m_bIsUsed);
  GLint loc = glGetUniformLocation( m_program, cName);
  assert( loc != -1);
  glUniform2fv( loc, 2, pf);
  GL::CheckError();
}

void ShaderBase::Uniform2( char const * cName, int const * pi)
{
  assert( m_program && m_bIsLinked && m_bIsUsed);
  GLint loc = glGetUniformLocation( m_program, cName);
  assert( loc != -1);
  glUniform2iv( loc, 2, pi);
  GL::CheckError();
}

bool ShaderBase::IsProgramUsed() const
{
  return m_bIsUsed;
}

bool ShaderBase::IsLinked() const
{
  return m_bIsLinked;
}

void ShaderBase::GetActiveUniform( int iIndex, int & iLength, int & iSize, GLenum & eType, std::string & sName) const
{
  assert( m_program && m_bIsLinked && m_bIsUsed);

  char cBuf[1024];
  GLsizei iGlLength;
  GLint iGlSize;
  glGetActiveUniform( m_program, iIndex, sizeof( cBuf), & iGlLength, & iGlSize, & eType, cBuf);
  if( glGetError() != GL_NO_ERROR)
  {
    sName = "";
    return;
  }
  iLength = iGlLength;
  iSize = iGlSize;
  sName = cBuf;
}

std::vector<std::string> ShaderBase::GetActiveUniforms() const
{
  std::vector<std::string> ret;
  for( int iIndex = 0; ; iIndex++)
  {
    std::string sName;
    int iLength;
    int iSize;
    GLenum eType;
    GetActiveUniform( iIndex, iLength, iSize, eType, sName);
    if( sName == "")
      break;
    ret.push_back( sName);
  }
  return ret;
}
