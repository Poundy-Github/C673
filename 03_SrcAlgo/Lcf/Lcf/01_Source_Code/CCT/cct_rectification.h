#ifndef cct_rectification_h__
#define cct_rectification_h__

#include "cct_camera.h"
#include "cml_ext_cpp.h"

namespace cct
{
  /// Library class to be used for applying rectification forward / backward.
  /// @tparam LUT_ITEM_COORDINATE Element type of the LUT to be used
  /// @tparam LUT_ITEM_QPOINT     Q-Point of the LUT element fixed point value
  /// @tparam LUT_ROWS            Number of rows of the LUT storage array
  /// @tparam LUT_COLS            Number of columns of the LUT storage array
  /// @tparam LUT_SCALE_QPOINT    Q-Point of the sub sampling step in pixels between two LUT elements
  template <typename LUT_ITEM_COORDINATE, sint32 LUT_ITEM_QPOINT, sint32 LUT_ROWS, sint32 LUT_COLS, sint32 LUT_SCALE_QPOINT>
  class Rectification
  {
  public:
    /// @{ @name LUT container specification
    typedef cml::CartesianPoint2D<LUT_ITEM_COORDINATE>                     LutItem;     ///< LUT element, consisting of two shifts pointing towards the unrectified position that is valid for the current rectified coordinate
    typedef cml::CArray2D        <      LutItem, LUT_ROWS, LUT_COLS, true> LutExt;      ///< LUT modifiable external array container.
    typedef cml::CArray2D        <const LutItem, LUT_ROWS, LUT_COLS, true> ConstLutExt; ///< LUT constant external array container
    /// @}

    /// @{ @name LUT C-Array specification
    typedef LUT_ITEM_COORDINATE LutArray[2 * LUT_ROWS * LUT_COLS]; ///< LUT array type without container
    /// @}

    /// Adapts a LutArray to the LUT container. Use it to call the other methods of the
    /// class from a plain C-Array instead of the real container.
    /// @param[in] lutArray C-Array holding the LUT items in the following way x00,y00,x01,y01,..,x10,y10,x11,y11,..xRC,yRC
    /// @return Container adapted to represent the contents of the LUT.
    static ConstLutExt asLut(const LutArray& lutArray)
    {
      return ConstLutExt(reinterpret_cast<const Rectification::LutItem*>(&lutArray[0]), sizeof(lutArray));
    }

    /// Calculates the delta vector for the given rectified position.
    /// Output will be bilinear interpolated between the LUT sampling points.
    /// @param[in]  lut        Rectification look up table to use
    /// @param[in]  xRectified X-coordinate of position in LUT-ROI to be evaluated for the delta shift
    /// @param[in]  yRectified Y-coordinate of position in LUT-ROI to be evaluated for the delta shift
    /// @param[out] dx         X-component of bilinear interpolated shift vector
    /// @param[out] dy         Y-component of bilinear interpolated shift vector
    static void getRectificationDelta(const ConstLutExt& lut, const float32 xRectified, const float32 yRectified, float32& dx, float32& dy)
    {
      static const sint32 LUT_SCALE          = 1 << LUT_SCALE_QPOINT;
      static const sint32 LUT_SCALE_2_QPOINT = LUT_SCALE_QPOINT << 1;
      static const sint32 LUT_SCALE_2_HALF   = 1 << (LUT_SCALE_2_QPOINT - 1);
      
      // item q-point as factor
      static const float32 LUT_ITEM_SCALE = 1.0F / static_cast<float32>(1 << LUT_ITEM_QPOINT);

      // define of ROI of LUT
      static const sint32 LUT_ROI_COLS = (LUT_COLS - 1) << LUT_SCALE_QPOINT;
      static const sint32 LUT_ROI_ROWS = (LUT_ROWS - 1) << LUT_SCALE_QPOINT;

      // clamp to valid LUT ROI
      const sint32 px = cml::clamp(0, LUT_ROI_COLS, static_cast<sint32>(xRectified));
      const sint32 py = cml::clamp(0, LUT_ROI_ROWS, static_cast<sint32>(yRectified));

      // sub sampled index
      const sint32 idxx = px >> LUT_SCALE_QPOINT;
      const sint32 idxy = py >> LUT_SCALE_QPOINT;

      // position fraction in LUT space
      const sint32 facX  = LUT_SCALE - (px - (idxx << LUT_SCALE_QPOINT));
      const sint32 facY  = LUT_SCALE - (py - (idxy << LUT_SCALE_QPOINT));
      
      // inverse fraction in LUT space
      const sint32 invFacX = LUT_SCALE - facX;
      const sint32 invFacY = LUT_SCALE - facY;

      // left-top LUT coordinates for interpolation
      const sint32 posx1 = idxx;
      const sint32 posy1 = idxy;
      // right-bottom LUT coordinates for interpolation
      const sint32 posx2 = cml::min(posx1 + 1, LUT_COLS - 1);
      const sint32 posy2 = cml::min(posy1 + 1, LUT_ROWS - 1);

      // bi-linear interpolation
      const LutItem& lut11 = lut(posy1, posx1);
      const LutItem& lut12 = lut(posy1, posx2);
      const LutItem& lut21 = lut(posy2, posx1);
      const LutItem& lut22 = lut(posy2, posx2);

      const sint32 lutX1 =    lut11.x() * facX +   lut12.x() * invFacX;
      const sint32 lutX2 =    lut21.x() * facX +   lut22.x() * invFacX;
      const sint32 lutX  = (((lutX1     * facY) + (lutX2     * invFacY)) + LUT_SCALE_2_HALF) >> LUT_SCALE_2_QPOINT;

      const sint32 lutY1 =    lut11.y() * facX +   lut12.y() * invFacX;
      const sint32 lutY2 =    lut21.y() * facX +   lut22.y() * invFacX;
      const sint32 lutY  = (((lutY1     * facY) + (lutY2     * invFacY)) + LUT_SCALE_2_HALF) >> LUT_SCALE_2_QPOINT;

      dx = static_cast<float32>(lutX) * LUT_ITEM_SCALE;
      dy = static_cast<float32>(lutY) * LUT_ITEM_SCALE;
    }

    /// Transforms given rectified coordinate to original coordinates.
    /// @param[in]  lut                Rectification look up table to use
    /// @param[in]  lutOffsetXOriginal X-coordinate of upper left corner of LUT in original coordinate system
    /// @param[in]  lutOffsetYOriginal Y-coordinate of upper left corner of LUT in original coordinate system
    /// @param[in]  xRectified         X-coordinate of position in LUT-ROI to be evaluated for the delta shift
    /// @param[in]  yRectified         Y-coordinate of position in LUT-ROI to be evaluated for the delta shift
    /// @param[out] xOriginal          X-component of derectified coordinate of given rectified one
    /// @param[out] yOriginal          Y-component of derectified coordinate of given rectified one
    static void derectify(
      const ConstLutExt& lut,
      const float32      lutOffsetXOriginal,
      const float32      lutOffsetYOriginal,
      const float32      xRectified, 
      const float32      yRectified,
      float32&           xOriginal,
      float32&           yOriginal)
    {
      float32 dx;
      float32 dy;

      Rectification::getRectificationDelta(lut, xRectified, yRectified, dx, dy);

      xOriginal = (xRectified + lutOffsetXOriginal) + dx;
      yOriginal = (yRectified + lutOffsetYOriginal) + dy;
    }

    /// Transforms given original coordinate to rectified coordinates.
    /// This is an approximative transform assuming that the original and the rectified camera are sharing the same
    /// origin. With this assumption the given original position is transformed into the rectified camera coordinate
    /// system to get a better positioning within the lut.
    /// This is the more precise way to perform the rectification. If the original camera and the rectified one share
    /// the same optical axis, one may use the rectifyApproxSameOpticalAxis(), which is faster.
    ///
    /// @see cct::CMonoCamera::Image2ImageSameOrigin()
    /// @see rectifyApproxSameOpticalAxis()
    ///
    /// @param[in]  lut                Rectification look up table to use
    /// @param[in]  lutOffsetXOriginal X-coordinate of upper left corner of LUT in original coordinate system
    /// @param[in]  lutOffsetYOriginal Y-coordinate of upper left corner of LUT in original coordinate system
    /// @param[in]  camOriginal        cct::CMonoCamera representing the properties of the original coordinate system
    /// @param[in]  camRectified       cct::CMonoCamera representing the properties of the rectified coordinate system
    /// @param[in]  xOriginal          X-component of original position to be rectified
    /// @param[in]  yOriginal          Y-component of original position to be rectified
    /// @param[out] xRectified         X-coordinate of rectified position
    /// @param[out] yRectified         Y-coordinate of rectified position
    static void rectifyApproxSameOrigin(
      const ConstLutExt&      lut,
      const float32           lutOffsetXOriginal,
      const float32           lutOffsetYOriginal,
      const cct::CMonoCamera& camOriginal,
      const cct::CMonoCamera& camRectified,
      const float32           xOriginal, 
      const float32           yOriginal,
      float32&                xRectified,
      float32&                yRectified)
    {
      // calculate approximative coordinates by applying a pinhole transform form unrectified to rectified
      float32 xRectifiedApprox;
      float32 yRectifiedApprox;

      camOriginal.Image2ImageSameOrigin(xOriginal, yOriginal, camRectified, xRectifiedApprox, yRectifiedApprox);
    
      float32 dx;
      float32 dy;

      Rectification::getRectificationDelta(lut, xRectifiedApprox, yRectifiedApprox, dx, dy);

      xRectified = (xOriginal - lutOffsetXOriginal) - dx;
      yRectified = (yOriginal - lutOffsetYOriginal) - dy;
    }

    /// Transforms given original coordinate to rectified coordinates.
    /// This is an approximative transform assuming that the original and the rectified camera are sharing the same
    /// optical axis. With this assumption the given original position is transformed into the rectified camera coordinate
    /// system to get a better positioning within the lut.
    /// This is the more faster way to perform the transition that holds valid only if the optical axes of the cameras
    /// are equal. If not, the method rectifyApproxSameOrigin() is preferred.
    ///
    /// @see cct::CMonoCamera::Image2ImageSameOpticalAxis()
    /// @see rectifyApproxSameOrigin()
    ///
    /// @param[in]  lut                Rectification look up table to use
    /// @param[in]  lutOffsetXOriginal X-coordinate of upper left corner of LUT in original coordinate system
    /// @param[in]  lutOffsetYOriginal Y-coordinate of upper left corner of LUT in original coordinate system
    /// @param[in]  camOriginal        cct::CMonoCamera representing the properties of the original coordinate system
    /// @param[in]  camRectified       cct::CMonoCamera representing the properties of the rectified coordinate system
    /// @param[in]  xOriginal          X-component of original position to be rectified
    /// @param[in]  yOriginal          Y-component of original position to be rectified
    /// @param[out] xRectified         X-coordinate of rectified position
    /// @param[out] yRectified         Y-coordinate of rectified position
    static void rectifyApproxSameOpticalAxis(
      const ConstLutExt&      lut,
      const float32           lutOffsetXOriginal,
      const float32           lutOffsetYOriginal,
      const cct::CMonoCamera& camOriginal,
      const cct::CMonoCamera& camRectified,
      const float32           xOriginal, 
      const float32           yOriginal,
      float32&                xRectified,
      float32&                yRectified)
    {
      // calculate approximative coordinates by applying a pinhole transform form unrectified to rectified
      float32 xRectifiedApprox;
      float32 yRectifiedApprox;

      camOriginal.Image2ImageSameOpticalAxis(xOriginal, yOriginal, camRectified, xRectifiedApprox, yRectifiedApprox);

      float32 dx;
      float32 dy;

      Rectification::getRectificationDelta(lut, xRectifiedApprox, yRectifiedApprox, dx, dy);

      xRectified = (xOriginal - lutOffsetXOriginal) - dx;
      yRectified = (yOriginal - lutOffsetYOriginal) - dy;
    }
  };
}

#endif // cct_rectification_h__
