
#include "vis_gl_lense_shader.h"

#define VIS_USE_FRAG_SHADER 1
#define USE_ID_VERT_SHADER  0
#define USE_VERT_INCLUDE    1

#if ! defined USE_VERT_INCLUDE && ! defined USE_ID_VERT_SHADER
#  include "../vis_util.h"
#endif

#include <string>
using namespace std;


VisGlLenseShader::VisGlLenseShader()
: m_fK1( -1)
, m_fK2( -1)
, m_fCenterX( -1)
, m_fCenterY( -1)
{}

void VisGlLenseShader::Init()
{
#if USE_VERT_INCLUDE
  char const cShader[] =
#include "lense_vert.inl"
    ;
  SetVertexShader( cShader);
#elif USE_ID_VERT_SHADER

  char const cShader[] =
"uniform float fK1;"
"uniform float fK2;"
"uniform vec2 v2Center;"
""
""
"void main()"
"{"
"  gl_Position = gl_ModelViewProjectionMatrix * ( gl_Vertex + vec4( 0, 1, 0, 0));"
"  gl_FrontColor = gl_Color;"
"  gl_BackColor = gl_Color;"
"}";
  SetVertexShader( cShader);

#else
  std::string sVertexShader = GetFileContent( "D:\\dev\\LD_trunc\\04_Engineering\\03_Workspace\\algo\\ld_sim\\sim_swc_ld_vis2\\vis_gl\\lense.vert");
  SetVertexShader( sVertexShader.c_str());
#endif

#if VIS_USE_FRAG_SHADER
  SetFragmentShader( NULL);
#endif
}

void VisGlLenseShader::SetParam( float fK1, float fK2, float fCenterX, float fCenterY)
{
#if ! USE_ID_VERT_SHADER
  vector<string> vecNames = GetActiveUniforms();
  if( m_fK1 != fK1)
    Uniform( "fK1", m_fK1 = fK1);

  if( m_fK2 != fK2)
    Uniform( "fK2", m_fK2 = fK2);

  if( m_fCenterX != fCenterX || m_fCenterY != fCenterY)
  {
    Uniform( "v2Center", m_fCenterX = fCenterX, m_fCenterY = fCenterY);
  }
#endif
}

bool VisGlLenseShader::IsInit() const
{
  return IsLinked();
}
