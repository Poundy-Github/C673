#include "image.h"
#include "cct_float_tools.h"

cct::CImage::CImage()
#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
  : m_pSacFexControlOutput(NULL)
#endif
{
  reset();
}

cct::CImage::~CImage()
{
#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
  if ( m_pSacFexControlOutput != NULL )
  {
    delete m_pSacFexControlOutput;
  }
#endif
}

void cct::CImage::reset()
{
  m_pImage    = NULL;
  m_pImageUP1 = NULL;
  m_pImageVP1 = NULL;

  m_newImageCalculated             = false;
  m_rgbImage.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
}

void cct::CImage::doStore(  const ImageU16_t*               pImage
                          , const ImageU8_t*                pImageUP1
                          , const ImageU8_t*                pImageVP1
#ifdef CIPP_WBR_INTFVER
                          , const CippWhiteBalanceResult_t& cippWhiteBalanceResult
#endif
#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
                          , const SacRteFexControlOutput_t* pSacFexControlOutput
#endif
                          )
{
#ifndef NDEBUG
  if ( ( pImage                        != NULL            )
    && ( pImage->sSigHeader.eSigStatus == AL_SIG_STATE_OK ) )
  {
    if ( ( pImageUP1                        != NULL            )
      && ( pImageUP1->sSigHeader.eSigStatus == AL_SIG_STATE_OK ) )
    {
      assert( pImage->sSigHeader == pImageUP1->sSigHeader );
    }
    if ( ( pImageVP1                        != NULL            )
      && ( pImageVP1->sSigHeader.eSigStatus == AL_SIG_STATE_OK ) )
    {
      assert( pImage->sSigHeader == pImageVP1->sSigHeader );
    }
  }
#endif

  m_pImage    = pImage;
  m_pImageUP1 = pImageUP1;
  m_pImageVP1 = pImageVP1;

#ifdef CIPP_WBR_INTFVER
  m_whiteBalanceU = std::min(static_cast<sint32>(14), static_cast<sint32>(cippWhiteBalanceResult.s_WbDynUsedBlue / 16));
  m_whiteBalanceV =                                                       cippWhiteBalanceResult.s_WbDynUsedRed  / 16;
#endif

#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
  if (pSacFexControlOutput != NULL)
  {
    if ( m_pSacFexControlOutput == NULL )
    {
      m_pSacFexControlOutput = new SacRteFexControlOutput_t();
    }

    if ( m_pSacFexControlOutput != NULL )
    {
      *m_pSacFexControlOutput = *pSacFexControlOutput;
    }
  }
#endif
}

const cct::CImage::SRGBImage& cct::CImage::getColoredImage( const float histCut )
{
  m_newImageCalculated = false;

#ifdef CIPP_WBR_INTFVER
  if ( ( m_pImage                             != NULL                 )
    && ( m_rgbImage.sSigHeader                != m_pImage->sSigHeader )
    && ( m_pImage->sSigHeader.eSigStatus      == AL_SIG_STATE_OK      )
    && ( ( m_pImageUP1                        == NULL                 )
    ||   ( m_pImageUP1->sSigHeader.eSigStatus == AL_SIG_STATE_OK      ) )
    && ( ( m_pImageVP1                        == NULL                 )
    ||   ( m_pImageVP1->sSigHeader.eSigStatus == AL_SIG_STATE_OK      ) ) )
  {
    calculateColoredImage( histCut );

    m_rgbImage.sSigHeader = m_pImage->sSigHeader;
    m_rgbImage.sImgHeader = m_pImage->sImgHeader;

    m_newImageCalculated = true;
  }
#else
  (void)histCut;
#endif

  return m_rgbImage;
}

void cct::CImage::calculateColoredImage( const float histCut )
{
  if ( m_pImage == NULL )
  {
    return;
  }

  const bool imageColorable = (m_pImageUP1 != NULL) && (m_pImageVP1 != NULL);

  float imageStretchScale;
  int   imageStretchOffset;

  // set the image scale factor (histogram based image stretching)
  {
    cml::CArray<unsigned int, 4096> hist;
    hist.fill(0);

    for (int Ym_imageRight = 0; Ym_imageRight < m_pImage->sImgHeader.uiHeight; Ym_imageRight++)
    {
      const unsigned short* pImg = m_pImage->aImageData + Ym_imageRight*m_pImage->sImgHeader.iRowBytes/sizeof(uint16);
      for (int YImgX = 0; YImgX < m_pImage->sImgHeader.uiWidth; YImgX++)
      {
        if (*pImg < 4096)
        {
          hist[*pImg]++;
        }
        pImg++;
      }
    }

    int histMin = 5;
    int sumMin = 0;
    while (histMin < 4096)
    {
      sumMin += hist[histMin];
      if (sumMin > (histCut * m_pImage->sImgHeader.uiWidth*m_pImage->sImgHeader.uiHeight))
      {
        break;
      }
      histMin++;
    }

    int histMax = 4095;
    int sumMax  = 0;
    while (histMax >= 0)
    {
      sumMax += hist[histMax];
      if (sumMax > (histCut * m_pImage->sImgHeader.uiWidth*m_pImage->sImgHeader.uiHeight))
      {
        break;
      }
      histMax--;
    }

    imageStretchScale = 255.0f / (histMax - histMin);
    imageStretchOffset = histMin;
  }

  // RGB conversion
  RGBImage_t::it pImageRGB = m_rgbImage.image.begin();
  for ( int Ym_image = 0; Ym_image < m_pImage->sImgHeader.uiHeight; ++Ym_image )
  {
    for ( int YImgX = 0; YImgX < m_pImage->sImgHeader.uiWidth; ++YImgX )
    {
#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
      float32 fxImg = static_cast<float32>(YImgX);
      float32 fyImg = static_cast<float32>(Ym_image);

      if ( m_pSacFexControlOutput != NULL )
      {
        transformToRRoiCoordinates(*m_pSacFexControlOutput, fxImg, fyImg);
      }

      const sint32 UVImgX         = imageColorable ? cct::roundToInt<int>(fxImg / m_pImageUP1->sImgHeader.iScaleX) : 0;
      const sint32 UVm_imageRight = imageColorable ? cct::roundToInt<int>(fyImg / m_pImageUP1->sImgHeader.iScaleY) : 0;
#else
      const sint32 UVImgX         = imageColorable ? (YImgX    / m_pImageUP1->sImgHeader.iScaleX) : 0;
      const sint32 UVm_imageRight = imageColorable ? (Ym_image / m_pImageUP1->sImgHeader.iScaleY) : 0;
#endif

      const bool isRRoiCoordinateValid = imageColorable &&
        (UVImgX         >= 0) && (UVImgX         < static_cast<sint32>(m_pImageUP1->sImgHeader.uiWidth)) &&
        (UVm_imageRight >= 0) && (UVm_imageRight < static_cast<sint32>(m_pImageUP1->sImgHeader.uiHeight));

      const uint16 Y = m_pImage->aImageData[Ym_image *(m_pImage->sImgHeader.iRowBytes / sizeof(uint16)) + YImgX ];

      const uint8 U = isRRoiCoordinateValid
        ? static_cast<uint8>(static_cast<int>(m_pImageUP1->aImageData[UVm_imageRight*(m_pImageUP1->sImgHeader.iRowBytes / sizeof(uint8))  + UVImgX]) + m_whiteBalanceU)
        : 128U;

      const uint8 V = isRRoiCoordinateValid
        ? static_cast<uint8>(static_cast<int>(m_pImageVP1->aImageData[UVm_imageRight*(m_pImageVP1->sImgHeader.iRowBytes / sizeof(uint8))  + UVImgX]) + m_whiteBalanceV)
        : 128U;

      const sint32 Red    = Y -  4*U + 12*V - 1024;
      const sint32 Green  = Y -  4*U -  4*V + 1024;
      const sint32 Blue   = Y + 12*U -  4*V - 1024;

      const uint8 RedStretched   = static_cast<uint8>(cml::clamp(0.0f, 255.0f, imageStretchScale * (Red   - imageStretchOffset)));
      const uint8 GreenStretched = static_cast<uint8>(cml::clamp(0.0f, 255.0f, imageStretchScale * (Green - imageStretchOffset)));
      const uint8 BlueStretched  = static_cast<uint8>(cml::clamp(0.0f, 255.0f, imageStretchScale * (Blue  - imageStretchOffset)));

      *pImageRGB = RedStretched;
      pImageRGB++;
      *pImageRGB = GreenStretched;
      pImageRGB++;
      *pImageRGB = BlueStretched;
      pImageRGB++;
    }
  }
}

#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
void cct::CImage::transformToRRoiCoordinates( const SacRteFexControlOutput_t& sacFexControlOutput, float32& x, float32& y )
{
  const sint32 lutwidth  = static_cast<sint32>(std::ceil(static_cast<float32>(sacFexControlOutput.sShiftedSRoiRight.ROIWidth)/32.0F)) + 1;
  const sint32 lutheight = static_cast<sint32>(std::ceil(static_cast<float32>(sacFexControlOutput.sShiftedSRoiRight.ROIHeight)/32.0F)) + 1;

  const sint32 px   = std::max(std::min(static_cast<sint32>(x), static_cast<sint32>(sacFexControlOutput.sShiftedSRoiRight.ROIWidth-1U)), 0);
  const sint32 py   = std::max(std::min(static_cast<sint32>(y), static_cast<sint32>(sacFexControlOutput.sShiftedSRoiRight.ROIHeight-1U)), 0);
  const sint32 idxx = px >> 5;
  const sint32 idxy = py >> 5;
  const sint32 facx = 32 - (px - (idxx << 5));
  const sint32 facy = 32 - (py - (idxy << 5));

  const sint32 posx1 = idxx;
  const sint32 posy1 = idxy;
  const sint32 posx2 = std::min(posx1+1, lutwidth-1);
  const sint32 posy2 = std::min(posy1+1, lutheight-1);

  const sint32 sLUTx11 = static_cast<sint32>( sacFexControlOutput.sLutRight.aLutData[ 2 * (posx1 + (posy1 * lutwidth))     ] );
  const sint32 sLUTy11 = static_cast<sint32>( sacFexControlOutput.sLutRight.aLutData[(2 * (posx1 + (posy1 * lutwidth))) + 1] );

  const sint32 sLUTx12 = static_cast<sint32>( sacFexControlOutput.sLutRight.aLutData[ 2 * (posx2 + (posy1 * lutwidth))     ] );
  const sint32 sLUTy12 = static_cast<sint32>( sacFexControlOutput.sLutRight.aLutData[(2 * (posx2 + (posy1 * lutwidth))) + 1] );

  const sint32 sLUTx21 = static_cast<sint32>( sacFexControlOutput.sLutRight.aLutData[ 2 * (posx1 + (posy2 * lutwidth))     ] );
  const sint32 sLUTy21 = static_cast<sint32>( sacFexControlOutput.sLutRight.aLutData[(2 * (posx1 + (posy2 * lutwidth))) + 1] );

  const sint32 sLUTx22 = static_cast<sint32>( sacFexControlOutput.sLutRight.aLutData[ 2 * (posx2 + (posy2 * lutwidth))     ] );
  const sint32 sLUTy22 = static_cast<sint32>( sacFexControlOutput.sLutRight.aLutData[(2 * (posx2 + (posy2 * lutwidth))) + 1] );

  const sint32 sLUTx1 =    sLUTx11 * facx +   sLUTx12 * (32 - facx);
  const sint32 sLUTx2 =    sLUTx21 * facx +   sLUTx22 * (32 - facx);
  const sint32 sLUTx  = (((sLUTx1  * facy) + (sLUTx2  * (32 - facy))) + 512) >> 10;

  const sint32 sLUTy1 =    sLUTy11 * facx +   sLUTy12 * (32 - facx);
  const sint32 sLUTy2 =    sLUTy21 * facx +   sLUTy22 * (32 - facx);
  const sint32 sLUTy  = (((sLUTy1  * facy) + (sLUTy2  * (32 - facy))) + 512) >> 10;

  x = x + (static_cast<float32>(sLUTx) * (1.0F / 64.0F)) + static_cast<float32>(sacFexControlOutput.sShiftedSRoiRight.ROIStartRelCroiX) - 80.0F; // use the magic 80 as CIPP image offset
  y = y + (static_cast<float32>(sLUTy) * (1.0F / 64.0F)) + static_cast<float32>(sacFexControlOutput.sShiftedSRoiRight.ROIStartRelCroiY);
}
#endif
