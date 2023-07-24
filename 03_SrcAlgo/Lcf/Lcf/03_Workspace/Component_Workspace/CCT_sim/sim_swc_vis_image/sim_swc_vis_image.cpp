/*! \file **********************************************************************

TEMPLATE VERSION:          1.2
changed parameters in cpp version to be a struct/class
added version management for template

*/
#include "stdafx.h"
#include "resource.h"
#include "sim_swc_vis_image.h"
#include "sim_swc_vis_image_version.h"

#include "sim_renderparam_helper.h"

#include <sstream>

const char* CSimVisImage::PN_HIST_CUT = "HistogramCut";

CSimVisImage::CSimVisImage()
// TODO: change data type of buffer id input port if needed
: CSimSwcDrawBase (10, "__BufferDataID", simI64_t, "__DoStore", "..\\gia_sim\\adapter.dll")

, m_rpImage                 (this, "Image"                 , NULL                       )
, m_rpImageUP1              (this, "ImageUP1"              , NULL                       )
, m_rpImageVP1              (this, "ImageVP1"              , NULL                       )

#ifdef CIPP_WBR_INTFVER
, m_rpCippWhiteBalanceResult(this, "CippWhiteBalanceResult", CippWhiteBalanceResult_t() )
#endif

#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
, m_rpSacFexControlOutput   (this, "SacFexControlOutput"   , SacRteFexControlOutput_t() )
#endif

, m_dpDraw(this, "DrawImage", &CSimVisImage::Draw, this, this )
{
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "Image version " << VIS_IMAGEALL_SW_MAIN_VER_NO << "." << VIS_IMAGEALL_SW_SUB_VER_NO << "." << VIS_IMAGEALL_SW_BUG_FIX_LEV << "." << VIS_IMAGEALL_SW_BUG_FIX_LEV2;
  dataTxt   << "Image (Image Visualization Module)";
  AddInternalData(headerTxt.str().c_str(), dataTxt.str().c_str());

  dataTxt.str("");
#ifdef _DEBUG
  dataTxt << "Debug ";
#else
  dataTxt << "Release ";
#endif
  dataTxt << "build at " << __DATE__ << " " << __TIME__;
  AddInternalData("Compiling Info", dataTxt.str().c_str());

  // Create server Ports
  AddServerPort("Reset"  , Reset  , this);
  AddServerPort("DoStore", DoStore, this);

  const float histCut = 0.01F;
  AddGlobalParameter( PN_HIST_CUT, simF32_t, &histCut, sizeof(float) );
}

void CSimVisImage::Reset()
{
  m_image.reset();
}

void CSimVisImage::DoStore()
{
  ScopeLock lock(*this);

  m_rpImage.lock();
  m_rpImageUP1.lock();
  m_rpImageVP1.lock();

  m_image.doStore(
    m_rpImage.val()
    , (m_rpImageUP1.isDirty() ? m_rpImageUP1.val() : NULL)
    , (m_rpImageVP1.isDirty() ? m_rpImageVP1.val() : NULL)
#ifdef CIPP_WBR_INTFVER
    , m_rpCippWhiteBalanceResult.val()
#endif
#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
    , (m_rpSacFexControlOutput.isDirty() ? &m_rpSacFexControlOutput.val() : NULL)
#endif
    );

  m_rpImage.setNotDirty();
  m_rpImageUP1.setNotDirty();
  m_rpImageVP1.setNotDirty();
#ifdef CIPP_WBR_INTFVER
  m_rpCippWhiteBalanceResult.setNotDirty();
#endif
#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
  m_rpSacFexControlOutput.setNotDirty();
#endif
}

CVersionInfoImpl CSimVisImage::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

void CSimVisImage::Draw( const ISimRenderContext& ctx )
{
  const float histCut = CSimRenderParamHelper::GetGlobalParamByRef<float>(ctx, PN_HIST_CUT);

  const cct::CImage::SRGBImage& image = m_image.getColoredImage(histCut);

  if ( image.sSigHeader.eSigStatus == AL_SIG_STATE_OK )
  {
    glPushAttrib(GL_COLOR_BUFFER_BIT | GL_ENABLE_BIT | GL_TEXTURE_BIT);
    {
      glDisable(GL_DEPTH_TEST);
      glEnable(GL_TEXTURE_2D);

      const HGLRC currentContextHandle = wglGetCurrentContext();

      Context2TextureMap_t::iterator context2TextureIt = m_context2TextureMap.find(currentContextHandle);

      if ( context2TextureIt != m_context2TextureMap.end() )
      {
        const GLuint texture = context2TextureIt->second;

        glBindTexture(GL_TEXTURE_2D, texture);
      }
      else
      {
        GLuint texture;

        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        m_context2TextureMap[currentContextHandle] = texture;
      }

      if ( m_image.isNewImage() || ( context2TextureIt == m_context2TextureMap.end() ) )
      {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.sImgHeader.uiWidth, image.sImgHeader.uiHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, &image.image[0]);
      }

      // setup texture parameters
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glColor4ub(255, 255, 255, 255);

      glBegin(GL_QUADS);
      glTexCoord2f(0.0F, 0.0F);  glVertex2i(0                       , 0                        );
      glTexCoord2f(1.0F, 0.0F);  glVertex2i(image.sImgHeader.uiWidth, 0                        );
      glTexCoord2f(1.0F, 1.0F);  glVertex2i(image.sImgHeader.uiWidth, image.sImgHeader.uiHeight);
      glTexCoord2f(0.0F, 1.0F);  glVertex2i(0                       , image.sImgHeader.uiHeight);
      glEnd();
    }
    glPopAttrib();
  }
}
