#ifndef image_h__
#define image_h__

#include "algo_type.h"
#include "cml_ext_cpp.h"

namespace cct
{
  inline boolean_t operator==(const SignalHeader_t& lhs, const SignalHeader_t& rhs)
  {
    return (lhs.uiMeasurementCounter == rhs.uiMeasurementCounter)
      ||   (lhs.uiTimeStamp          == rhs.uiTimeStamp         );
  }

  inline boolean_t operator!=(const SignalHeader_t& lhs, const SignalHeader_t& rhs)
  {
    return ! operator==(lhs, rhs);
  }

  class CImage
  {
  public:
    CImage();

    ~CImage();

#if defined(MFC_REDUCED_ROI_WIDTH_L0) && defined(MFC_REDUCED_ROI_HEIGHT_L0)
    typedef cml::CArray2D< unsigned char, 3 * MFC_REDUCED_ROI_WIDTH_L0, MFC_REDUCED_ROI_HEIGHT_L0 > RGBImage_t;
#else
    typedef cml::CArray2D< unsigned char, 3*1024, 640 > RGBImage_t;
#endif

    struct SRGBImage
    {
      SignalHeader_t sSigHeader;
      ImageHeader_t  sImgHeader;
      RGBImage_t     image;
    };

    void reset();

    void doStore(
      const ImageU16_t*                 image
      , const ImageU8_t*                imageUP1
      , const ImageU8_t*                imageVP1
#ifdef CIPP_WBR_INTFVER
      , const CippWhiteBalanceResult_t& cippWhiteBalanceResult
#endif
#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
      , const SacRteFexControlOutput_t* pSacFexControlOutput
#endif
      );

    const SRGBImage& getColoredImage( const float histCut );

    bool isNewImage() const { return m_newImageCalculated; }

  private:
    void calculateColoredImage( const float histCut );

    const ImageU16_t* m_pImage;
    const ImageU8_t*  m_pImageUP1;
    const ImageU8_t*  m_pImageVP1;

    int m_whiteBalanceU;
    int m_whiteBalanceV;

    SRGBImage m_rgbImage;

    bool m_newImageCalculated;

#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
    SacRteFexControlOutput_t* m_pSacFexControlOutput;

    /// Transforms given rectified SRoi coordinate to a RRoi
    /// coordinate according to the given LUT and the assumption
    /// that the RRoi image has a lateral dhift of 80px.
    /// @param[in]     sacFexControlOutput Contains the rectification LUTs - right one is used
    /// @param[in,out] x                   Rectified SRoi x-coordinate to be transformed to RRoi coordinates
    /// @param[in,out] y                   Rectified SRoi y-coordinate to be transformed to RRoi coordinates
    static void transformToRRoiCoordinates(
      const SacRteFexControlOutput_t& sacFexControlOutput,
      float32& x, float32& y);
#endif
  };
}

#endif // image_h__
