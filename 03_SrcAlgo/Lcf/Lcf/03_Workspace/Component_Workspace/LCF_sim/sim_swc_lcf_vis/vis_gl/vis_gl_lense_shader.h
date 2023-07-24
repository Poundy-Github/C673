
#pragma once

/** \class VisGlLenseShader
 *
 *  \brief Lense corretion via OpenGL shader
 *
 *  Encapsulates the Lense correction via OpenGL shader.
 *
 *  \todo move from vis_gl to 'ld_vis2'. It is specific to gl_vis2 to universal to OpenGL
 *
 *  \ingroup ld_vis2_opengl
 */


#include "vis_gl_shader_base.h"

#include "vis_gl_screen.h"

class VisGlLenseShader : public GL::ShaderBase
{
public:
  VisGlLenseShader();

  void Init();
  void SetParam( float fK1, float fK2, float fCenterX, float fCenterY);
  bool IsInit() const;

protected:
  float m_fK1, m_fK2, m_fCenterX, m_fCenterY;
};
