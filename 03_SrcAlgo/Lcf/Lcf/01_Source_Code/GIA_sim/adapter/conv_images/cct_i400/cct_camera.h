/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CCT (Common Camera Toolbox)

MODULNAME:                 cct_camera.h

DESCRIPTION:               Basic Camera Transformations

AUTHOR:                    Stefan Zechner

CREATION DATE:             24.05.2013

VERSION:                   $Revision: 1.1 $

---*/ /*---
CHANGES:                   $Log: cct_camera.h  $
CHANGES:                   Revision 1.1 2021/12/13 17:19:57CET Wang, David (Wangd3) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/adapter/conv_images/cct_i400/project.pj
CHANGES:                   Revision 1.0 2017/03/03 10:30:27CET Sorge, Sven (uidg3181) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/adapter/converters/conv_images/cct_i400/project.pj
CHANGES:                   Revision 1.25 2014/05/20 08:23:32CEST Zechner, Stefan (uidt9253) 
CHANGES:                   - revert 1.23 (because copy constructor is required i.e. for PED mono)
CHANGES:                   - Added comments -  uidt9253 [May 20, 2014 8:23:32 AM CEST]
CHANGES:                   Change Package : 199413:3 http://mks-psad:7002/im/viewissue?selection=199413
CHANGES:                   Revision 1.24 2014/05/19 12:46:44CEST Exner, Christian (uidt8578) 
CHANGES:                   - added separate methods to solve the World2Camera and Camera2World row-wise, because sometimes only one row is required. The methods will be used by the original full ones to be consistent
CHANGES:                     - World2CameraX, World2CameraY, World2CameraZ
CHANGES:                     - Camera2WorldX, Camera2WorldY, Camera2WorldZ
CHANGES:                   --- Added comments ---  uidt8578 [May 19, 2014 12:46:45 PM CEST]
CHANGES:                   Change Package : 199077:3 http://mks-psad:7002/im/viewissue?selection=199077
CHANGES:                   Revision 1.23 2014/05/19 10:54:20CEST Friebertshaeuser, Markus (uidt0551) 
CHANGES:                   Forbid copy constructor and equal operator
CHANGES:                   --- Added comments ---  uidt0551 [May 19, 2014 10:54:21 AM CEST]
CHANGES:                   Change Package : 199714:3 http://mks-psad:7002/im/viewissue?selection=199714
CHANGES:                   Revision 1.22 2014/02/18 16:46:04CET Friebertshaeuser, Markus (uidt0551) 
CHANGES:                   Corrected checks
CHANGES:                   --- Added comments ---  uidt0551 [Feb 18, 2014 4:46:05 PM CET]
CHANGES:                   Change Package : 199714:3 http://mks-psad:7002/im/viewissue?selection=199714
CHANGES:                   Revision 1.21 2014/01/28 12:10:42CET Erbs, Friedrich (uidg5371) 
CHANGES:                   Variables initialization.
CHANGES:                   --- Added comments ---  uidg5371 [Jan 28, 2014 12:10:42 PM CET]
CHANGES:                   Change Package : 203466:5 http://mks-psad:7002/im/viewissue?selection=203466
CHANGES:                   Revision 1.20 2013/10/25 14:06:48CEST Defatsch, Simon (uidv1229) 
CHANGES:                   get distortion and rectification coefficients functions added
CHANGES:                   --- Added comments ---  uidv1229 [Oct 25, 2013 2:06:48 PM CEST]
CHANGES:                   Change Package : 199315:4 http://mks-psad:7002/im/viewissue?selection=199315
CHANGES:                   Revision 1.19 2013/10/15 18:19:06CEST Daiber-EXT, Sebastian (uidw3458) 
CHANGES:                   moved inversion function from cct_camera to cct_float_tools
CHANGES:                   --- Added comments ---  uidw3458 [Oct 15, 2013 6:19:06 PM CEST]
CHANGES:                   Change Package : 162889:78 http://mks-psad:7002/im/viewissue?selection=162889
CHANGES:                   Revision 1.18 2013/10/14 18:25:34CEST Daiber-EXT, Sebastian (uidw3458) 
CHANGES:                   speedup divisions on DSP by using Intrinsics
CHANGES:                   --- Added comments ---  uidw3458 [Oct 14, 2013 6:25:34 PM CEST]
CHANGES:                   Change Package : 162889:78 http://mks-psad:7002/im/viewissue?selection=162889
CHANGES:                   Revision 1.17 2013/07/01 14:24:46CEST Zechner, Stefan (uidt9253) 
CHANGES:                   - new function translateCamera(): translate camera relative to the current camera position
CHANGES:                   --- Added comments ---  uidt9253 [Jul 1, 2013 2:24:47 PM CEST]
CHANGES:                   Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
CHANGES:                   Revision 1.16 2013/06/06 15:58:17CEST Zechner, Stefan (uidt9253) 
CHANGES:                   - no change. Comment corrected
CHANGES:                   --- Added comments ---  uidt9253 [Jun 6, 2013 3:58:17 PM CEST]
CHANGES:                   Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
CHANGES:                   Revision 1.15 2013/06/04 13:34:40CEST Friebertshaeuser, Markus (uidt0551) 
CHANGES:                   added #include <cassert>
CHANGES:                   --- Added comments ---  uidt0551 [Jun 4, 2013 1:34:40 PM CEST]
CHANGES:                   Change Package : 162889:10 http://mks-psad:7002/im/viewissue?selection=162889
CHANGES:                   Revision 1.14 2013/05/27 10:23:11CEST Exner, Christian (uidt8578) 
CHANGES:                   - misra:
CHANGES:                     - used comparison against std::numeric_limits<float32>::epsilon() wherever it was possible without a std::abs
CHANGES:                     - the check of equality between floats is also forbidden (rule 6-2-2, misra 2008), but i kept them due to runtime envolved with using std::abs. we'll see later
CHANGES:                   - renamed:
CHANGES:                     - getDisparityFromDistance -> getDisparityFromCameraZ
CHANGES:                     - getDistanceFromDisparity -> getCameraZFromDisparity
CHANGES:                   - made comments above methods / class doxygen compatible
CHANGES:                   - made members of classes private rather than protected and used the appropriate getters also for internal acess
CHANGES:                   - reused the methods getDisparityFromCameraZ, getCameraZFromDisparity instead of computing it in Image2CameraFromDisparity, Camera2Image
CHANGES:                   --- Added comments ---  uidt8578 [May 27, 2013 10:23:11 AM CEST]
CHANGES:                   Change Package : 177735:2 http://mks-psad:7002/im/viewissue?selection=177735
CHANGES:                   Revision 1.13 2013/05/27 09:54:06CEST Exner, Christian (uidt8578) 
CHANGES:                   - fixed: Misra 2008, Rule2-13-4, Required: Literal suffixes shall be upper case.
CHANGES:                   --- Added comments ---  uidt8578 [May 27, 2013 9:54:06 AM CEST]
CHANGES:                   Change Package : 177735:2 http://mks-psad:7002/im/viewissue?selection=177735
CHANGES:                   Revision 1.12 2013/05/27 09:41:27CEST Exner, Christian (uidt8578) 
CHANGES:                   - offered getters for the stored inverted focal lengths
CHANGES:                   --- Added comments ---  uidt8578 [May 27, 2013 9:41:27 AM CEST]
CHANGES:                   Change Package : 177735:2 http://mks-psad:7002/im/viewissue?selection=177735
CHANGES:                   Revision 1.11 2013/05/24 17:11:55CEST Zechner, Stefan (uidt9253) 
CHANGES:                   - bugfix Image2WorldFromDisparity(): reference was missing
CHANGES:                   --- Added comments ---  uidt9253 [May 24, 2013 5:11:55 PM CEST]
CHANGES:                   Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
CHANGES:                   Revision 1.10 2013/05/24 16:31:38CEST Zechner, Stefan (uidt9253) 
CHANGES:                   - rename setParamsRTE() to setParams()
CHANGES:                   --- Added comments ---  uidt9253 [May 24, 2013 4:31:38 PM CEST]
CHANGES:                   Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
CHANGES:                   Revision 1.9 2013/05/24 13:22:24CEST Zechner, Stefan (uidt9253) 
CHANGES:                   - cct_camera completely rewritten
CHANGES:                   --- Added comments ---  uidt9253 [May 24, 2013 1:22:24 PM CEST]
CHANGES:                   Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889

**************************************************************************** */

#ifndef cct_camera_h__
#define cct_camera_h__

#include "algo_type.h"
#include "cct_float_tools.h"

#include <cmath>
#include <limits>
#include <cassert>

namespace cct
{
  /// cct camera provides the most basic camera transformations.
  ///
  /// A Mono and Stereo version is available. The Stereo camera includes all features
  /// of the mono camera plus some stereo specific ones.
  ///
  /// Before using the camera class it has to be initialized by setParams().
  ///
  /// The function checkCameraUpToDate() can test if the camera has to be updated by setParams()
  /// or if the internal camera state is identical to test provided camera calibration.
  ///
  /// The coordinate systems are defined as follows:
  ///
  /// Image Coordinate System:
  /// ========================
  /// - imageX from left to right
  /// - imageY from top to bottom
  /// Point (0,0) in image coordinate system is the most top left pixel in imager plane
  ///
  /// Camera Coordinate System:
  /// =========================
  /// - cameraX is parallel to imageX
  /// - cameraY is parallel to imageY
  /// - cameraZ is the positive optical axis
  /// Point (0,0,0) in camera coordinate system is the center point in the camera
  ///
  /// Vehicle Coordinate System (aka: Autosar Coordinate System):
  /// ==============================+++++========================
  /// - x longitudinal forward,
  /// - y lateral left,
  /// - z up
  /// Point (0,0,0) in vehicle coordinate system is the center of front wheel axle on the ground.
  /// pitch / yaw / roll = 0 -> camera is looking parallel to the vehicles axes (cameraZ parallel to vehicleX)
  class CMonoCamera
  {
  public:

    CMonoCamera()
    : m_inverseFocalX( 0.0F ),
      m_inverseFocalY( 0.0F )
    {
      m_intr.fFocalX = 0.0F;
    }

    /// Initialization method 1: Init the camera by the calibration data from RTE.
    ///                          Rotation matrix will not be calculated. It is just copied from the pose parameters.
    void setParams(const PoseParameters_t& poseParameters, const MonoCalibrationIntrinsic_t& monoCalibrationIntrinsic)
    {
      m_pose = poseParameters;
      m_intr = monoCalibrationIntrinsic;

      preCalc();
    }

    /// Initialization method 2: Set all camera parameters manually.
    void setParams(float32 rotXroll, float32 rotYpitch, float32 rotZyaw,
                   float32 transX, float32 transY, float32 transZ,
                   float32 intrFocalX, float32 intrFocalY, 
                   float32 intrCenterX, float32 intrCenterY)
    {
      m_pose.fRoll    = rotXroll;
      m_pose.fPitch   = rotYpitch;
      m_pose.fYaw     = rotZyaw;
      m_pose.fTx      = transX;
      m_pose.fTy      = transY;
      m_pose.fTz      = transZ;
      m_intr.fFocalX  = intrFocalX;
      m_intr.fFocalY  = intrFocalY;
      m_intr.fCenterX = intrCenterX;
      m_intr.fCenterY = intrCenterY;

      preCalcPoseTransformationMatrix(rotXroll, rotYpitch, rotZyaw, transX, transY, transZ);
      preCalc();
    }

    /// returns true if camera is up to date (compare camera calibration against internal camera state)
    boolean_t checkCameraUpToDate(const PoseParameters_t& pose, const MonoCalibrationIntrinsic_t& intr)
    {
      return checkCameraUpToDate( pose.fRoll, pose.fPitch, pose.fYaw, pose.fTx, pose.fTy, pose.fTz,
                                  intr.fFocalX, intr.fFocalY, intr.fCenterX, intr.fCenterY);
    }

    /// returns true if camera is up to date (compare camera calibration against internal camera state)
    boolean_t checkCameraUpToDate( float32 rotXroll, float32 rotYpitch, float32 rotZyaw,
                                   float32 transX, float32 transY, float32 transZ,
                                   float32 intrFocalX, float32 intrFocalY, 
                                   float32 intrCenterX, float32 intrCenterY)
    {
      return (  m_pose.fRoll == rotXroll &&
                m_pose.fPitch == rotYpitch &&
                m_pose.fYaw == rotZyaw &&
                m_pose.fTx == transX &&
                m_pose.fTy == transY &&
                m_pose.fTz == transZ &&
                m_intr.fFocalX == intrFocalX &&
                m_intr.fFocalY == intrFocalY &&
                m_intr.fCenterX == intrCenterX &&
                m_intr.fCenterY == intrCenterY  );
    }

    /// translate camera relative to the current camera position
    void translateCamera(float32 transX, float32 transY, float32 transZ)
    {
      m_pose.fTx += transX;
      m_pose.fTy += transY;
      m_pose.fTz += transZ;

      m_pose.sTransform.fA03 += - m_pose.sTransform.fA00 * transX - m_pose.sTransform.fA01 * transY - m_pose.sTransform.fA02 * transZ;
      m_pose.sTransform.fA13 += - m_pose.sTransform.fA10 * transX - m_pose.sTransform.fA11 * transY - m_pose.sTransform.fA12 * transZ;
      m_pose.sTransform.fA23 += - m_pose.sTransform.fA20 * transX - m_pose.sTransform.fA21 * transY - m_pose.sTransform.fA22 * transZ;
    }

    // Parameter getter functions
    float32 getRotationXroll()  const { return m_pose.fRoll; }
    float32 getRotationYPitch() const { return m_pose.fPitch; }
    float32 getRotationZYaw()   const { return m_pose.fYaw; }

    float32 getTranslationX() const { return m_pose.fTx; }
    float32 getTranslationY() const { return m_pose.fTy; }
    float32 getTranslationZ() const { return m_pose.fTz; }

    const Mat3x4_t& getExtrinsicTransformationMatrix() const { return m_pose.sTransform; }

    float32 getIntrinsicFocalLengthX() const { return m_intr.fFocalX; }
    float32 getIntrinsicFocalLengthY() const { return m_intr.fFocalY; }

    float32 getIntrinsicFocalLengthXInverted() const { return m_inverseFocalX; }
    float32 getIntrinsicFocalLengthYInverted() const { return m_inverseFocalY; }

    float32 getIntrinsicCenterX() const { return m_intr.fCenterX; }
    float32 getIntrinsicCenterY() const { return m_intr.fCenterY; }

    float32 getIntrinsicDistCeoff0() const { return m_intr.fDistortionCoefficients[0]; }
    float32 getIntrinsicDistCeoff1() const { return m_intr.fDistortionCoefficients[1]; }

    float32 getIntrinsicRectCeoff0() const { return m_intr.fRectificationCoefficients[0]; }
    float32 getIntrinsicRectCeoff1() const { return m_intr.fRectificationCoefficients[1]; }

    /// Transform point in world coordinate system to camera coordinate system
    void World2Camera(float32  worldX,  float32  worldY,  float32  worldZ,
                      float32& cameraX, float32& cameraY, float32& cameraZ) const
    {
      cameraX = World2CameraX(worldX, worldY, worldZ);
      cameraY = World2CameraY(worldX, worldY, worldZ);
      cameraZ = World2CameraZ(worldX, worldY, worldZ);
    }

    /// Transform point in world coordinate system to camera X coordinate.
    /// It executes only the X row of the matrix operation.
    /// @return Camera X coordinate.
    float32 World2CameraX (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return (m_pose.sTransform.fA00 * worldX) + (m_pose.sTransform.fA01 * worldY) + (m_pose.sTransform.fA02 * worldZ) + m_pose.sTransform.fA03;
    }

    /// Transform point in world coordinate system to camera Y coordinate.
    /// It executes only the Y row of the matrix operation.
    /// @return Camera Y coordinate.
    float32 World2CameraY (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return (m_pose.sTransform.fA10 * worldX) + (m_pose.sTransform.fA11 * worldY) + (m_pose.sTransform.fA12 * worldZ) + m_pose.sTransform.fA13;
    }

    /// Transform point in world coordinate system to camera Z coordinate.
    /// It executes only the Z row of the matrix operation.
    /// @return Camera Z coordinate.
    float32 World2CameraZ (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return (m_pose.sTransform.fA20 * worldX) + (m_pose.sTransform.fA21 * worldY) + (m_pose.sTransform.fA22 * worldZ) + m_pose.sTransform.fA23;
    }

    /// Transform point in camera coordinate system to world coordinate system
    void Camera2World(float32 cameraX, float32 cameraY, float32 cameraZ, 
                      float32& worldX, float32& worldY, float32& worldZ) const
    {
      worldX = Camera2WorldX(cameraX, cameraY, cameraZ);
      worldY = Camera2WorldY(cameraX, cameraY, cameraZ);
      worldZ = Camera2WorldZ(cameraX, cameraY, cameraZ);
    }

    /// Transform point in camera coordinate system to world X coordinate.
    /// It executes only the X row of the matrix operation.
    /// @return World X coordinate.
    float32 Camera2WorldX (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return ( m_pose.sTransform.fA00 * cameraX ) + ( m_pose.sTransform.fA10 * cameraY ) + ( m_pose.sTransform.fA20 * cameraZ ) + m_pose.fTx;
    }

    /// Transform point in camera coordinate system to world X coordinate.
    /// It executes only the Y row of the matrix operation.
    /// @return World Y coordinate.
    float32 Camera2WorldY (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return ( m_pose.sTransform.fA01 * cameraX ) + ( m_pose.sTransform.fA11 * cameraY ) + ( m_pose.sTransform.fA21 * cameraZ ) + m_pose.fTy;
    }

    /// Transform point in camera coordinate system to world X coordinate.
    /// It executes only the Z row of the matrix operation.
    /// @return World Z coordinate.
    float32 Camera2WorldZ (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return ( m_pose.sTransform.fA02 * cameraX ) + ( m_pose.sTransform.fA12 * cameraY ) + ( m_pose.sTransform.fA22 * cameraZ ) + m_pose.fTz;
    }

    /// Transform point in camera coordinate system to image coordinate system
    /// cameraZ must be positive (avoid projection behind camera)
    void Camera2Image(float32 cameraX, float32 cameraY, float32 cameraZ,
                      float32& imageX, float32& imageY) const
    {
      const float32 cameraZ_inv= cct::invert( cameraZ );
      assert(std::abs(cameraZ) > std::numeric_limits<float32>::epsilon());
      imageX = ((m_intr.fFocalX * cameraZ_inv) * cameraX) + m_intr.fCenterX;
      imageY = ((m_intr.fFocalY * cameraZ_inv) * cameraY) + m_intr.fCenterY;
    }

    /// Transform point in world coordinate system to image coordinate system
    /// Returns false if point in world is behind camera plane
    boolean_t World2Image(float32 worldX, float32 worldY, float32 worldZ,
                          float32& imageX, float32& imageY) const
    {
      boolean_t result = false;
      float32 cameraX, cameraY, cameraZ;

      World2Camera(worldX, worldY, worldZ, cameraX, cameraY, cameraZ);
      if (std::abs(cameraZ) > std::numeric_limits<float32>::epsilon())
      {
        Camera2Image(cameraX, cameraY, cameraZ, imageX, imageY);
        result = true;
      }

      return result;
    }

    /// Transform point in image coordinate system to camera coordinate system
    /// by specifying the camera x coordinate
    /// Returns false if transformation fails due to image coordinate is identical to intrinsic center point
    boolean_t Image2CameraKnownCameraX(float32 imageX, float32 imageY,
                                       float32 cameraX, float32& cameraY, float32& cameraZ) const
    {
      boolean_t result = false;
      const float32 div = imageX - m_intr.fCenterX;
      if (std::abs(div) > std::numeric_limits<float32>::epsilon())
      {
        cameraZ = (cameraX * m_intr.fFocalX)  * cct::invert( div );
        cameraY = ((imageY - m_intr.fCenterY) * cameraZ) * m_inverseFocalY;
        result = true;
      }

      return result;
    }

    /// Transform point in image coordinate system to camera coordinate system
    /// by specifying the camera y coordinate
    /// Returns false if transformation fails due to image coordinate is identical to intrinsic center point
    boolean_t Image2CameraKnownCameraY(float32 imageX, float32 imageY,
                                       float32& cameraX, float32 cameraY, float32& cameraZ) const
    {
      boolean_t result = false;
      const float32 div = imageY - m_intr.fCenterY;
      if (std::abs(div) > std::numeric_limits<float32>::epsilon())
      {
        cameraZ = (cameraY * m_intr.fFocalY)  * cct::invert( div );
        cameraX = ((imageX - m_intr.fCenterX) * cameraZ) * m_inverseFocalX;
        result = true;
      }

      return result;
    }

    /// Transform point in image coordinate system to camera coordinate system
    /// by specifying the camera z coordinate
    /// cameraZ must be positive (avoid projection behind camera)
    void Image2CameraKnownCameraZ(float32 imageX, float32 imageY,
                                  float32& cameraX, float32& cameraY, float32 cameraZ) const
    {
      assert(std::abs(cameraZ) > std::numeric_limits<float32>::epsilon());
      cameraX = ((imageX - m_intr.fCenterX) * cameraZ) * m_inverseFocalX;
      cameraY = ((imageY - m_intr.fCenterY) * cameraZ) * m_inverseFocalY;
    }

    /// Transform point in image coordinate system to world coordinate system
    /// by specifying the world x coordinate
    /// Returns false if transformation fails due to image coordinate is identical to intrinsic center point
    boolean_t Image2WorldKnownWorldX(float32 imageX, float32 imageY,
                                     float32 worldX, float32& worldY, float32& worldZ) const
    {
      boolean_t result = false;
      float32 a, b, zk;

      a = (imageX - m_intr.fCenterX) * m_inverseFocalX;
      b = (imageY - m_intr.fCenterY) * m_inverseFocalY;

      const float32 div = (m_pose.sTransform.fA00*a) + (m_pose.sTransform.fA10*b) + m_pose.sTransform.fA20;
      if (std::abs(div) > std::numeric_limits<float32>::epsilon())
      {
        zk = (worldX - m_pose.fTx) * cct::invert( div );

        worldY = (((m_pose.sTransform.fA01*a) + (m_pose.sTransform.fA11*b) + m_pose.sTransform.fA21) * zk) + m_pose.fTy;
        worldZ = (((m_pose.sTransform.fA02*a) + (m_pose.sTransform.fA12*b) + m_pose.sTransform.fA22) * zk) + m_pose.fTz;
        result = true;
      }

      return result;
    }

    /// Transform point in image coordinate system to world coordinate system
    /// by specifying the world y coordinate
    /// Returns false if transformation fails due to image coordinate is identical to intrinsic center point
    boolean_t Image2WorldKnownWorldY(float32 imageX, float32 imageY,
                                     float32& worldX, float32 worldY, float32& worldZ) const
    {
      boolean_t result = false;
      float32 a, b, zk;

      a = (imageX - m_intr.fCenterX) * m_inverseFocalX;
      b = (imageY - m_intr.fCenterY) * m_inverseFocalY;

      const float32 div = (m_pose.sTransform.fA01*a) + (m_pose.sTransform.fA11*b) + m_pose.sTransform.fA21;
      if (std::abs(div) > std::numeric_limits<float32>::epsilon())
      {
        zk = (worldY - m_pose.fTy) * cct::invert( div );

        worldX = (((m_pose.sTransform.fA00*a) + (m_pose.sTransform.fA10*b) + m_pose.sTransform.fA20) * zk) + m_pose.fTx;
        worldZ = (((m_pose.sTransform.fA02*a) + (m_pose.sTransform.fA12*b) + m_pose.sTransform.fA22) * zk) + m_pose.fTz;
        result = true;
      }

      return result;
    }

    /// Transform point in image coordinate system to world coordinate system
    /// by specifying the world y coordinate
    /// Returns false if transformation fails due to image coordinate is identical to intrinsic center point
    boolean_t Image2WorldKnownWorldZ(float32 imageX, float32 imageY,
                                     float32& worldX, float32& worldY, float32 worldZ) const
    {
      boolean_t result = false;
      float32 a, b, zk;

      a = (imageX - m_intr.fCenterX) * m_inverseFocalX;
      b = (imageY - m_intr.fCenterY) * m_inverseFocalY;

      const float32 div = (m_pose.sTransform.fA02*a) + (m_pose.sTransform.fA12*b) + m_pose.sTransform.fA22;
      if (std::abs(div) > std::numeric_limits<float32>::epsilon())
      {
        zk = (worldZ - m_pose.fTz) * cct::invert( div );

        worldX = (((m_pose.sTransform.fA00*a) + (m_pose.sTransform.fA10*b) + m_pose.sTransform.fA20) * zk) + m_pose.fTx;
        worldY = (((m_pose.sTransform.fA01*a) + (m_pose.sTransform.fA11*b) + m_pose.sTransform.fA21) * zk) + m_pose.fTy;
        result = true;
      }

      return result;
    }


  private:

    PoseParameters_t m_pose;
    MonoCalibrationIntrinsic_t m_intr;

    float32 m_inverseFocalX;
    float32 m_inverseFocalY;

    void preCalc()
    {
      assert(m_intr.fFocalX > std::numeric_limits<float32>::epsilon());
      assert(m_intr.fFocalY > std::numeric_limits<float32>::epsilon());
      m_inverseFocalX = cct::invert( m_intr.fFocalX );
      m_inverseFocalY = cct::invert( m_intr.fFocalY );
    }

    void preCalcPoseTransformationMatrix(float32 rotXroll, float32 rotYpitch, float32 rotZyaw,
                                         float32 transX, float32 transY, float32 transZ)
    {
      // set the pose transformation matrix T defined as:
      //  T = [A * R| - A * R * t],
      //  R = Tait–Bryan-Z-Y'-X''-MobileFrameAxes-PassiveComposition(zYaw, yPitch, xRoll) = R(rotXroll)' * R(rotYpitch)' * R(rotZyaw)'
      //  t = [t_x ; t_y ; t_z] = Position of the camera in the vehicle coordinate system
      //  A = Rotation from vehicle to forward looing camera system = [[0 -1 0] ; [0 0 -1] ; [1 0 0]] (A' * A = I)
      //
      // This equals:
      //  - x_camera = A * R * (x_vehicle - t)
      //  - x_camera = T * [x_vehicle, 1]
      //
      //         [ 0  -1   0 ]   [  1      0        0    ]   [ cos(y)   0   -sin(y) ]   [  cos(z)  sin(z)   0 ]
      // A * R = [ 0   0  -1 ] * [  0    cos(x)   sin(x) ] * [   0      1      0    ] * [ -sin(z)  cos(z)   0 ]
      //         [ 1   0   0 ]   [  0   -sin(x)   cos(x) ]   [ sin(y)   0    cos(y) ]   [   0       0       1 ]
      //
      // Matlab:
      // =======
      //
      // syms sx cx sy cy sz cz tx ty tz
      // A = [0 -1 0; 0 0 -1; 1 0 0];
      // Rx=[1 0 0; 0 cx sx; 0 -sx cx];
      // Ry=[cy 0 -sy; 0 1 0; sy 0 cy];
      // Rz=[cz sz 0; -sz cz 0; 0 0 1];
      // t=[tx;ty;tz];
      // R=Rx*Ry*Rz;
      // T=[A*R -A*R*t]

      float32 cZ = std::cos(rotZyaw);
      float32 sZ = std::sin(rotZyaw);
      float32 cY = std::cos(rotYpitch);
      float32 sY = std::sin(rotYpitch);
      float32 cX = std::cos(rotXroll);
      float32 sX = std::sin(rotXroll);

      m_pose.sTransform.fA00 = -sX*sY*cZ + cX*sZ;       m_pose.sTransform.fA01 = -sX*sY*sZ - cX*cZ;       m_pose.sTransform.fA02 = -sX*cY;
      m_pose.sTransform.fA10 = -cX*sY*cZ - sX*sZ;       m_pose.sTransform.fA11 = -cX*sY*sZ + sX*cZ;       m_pose.sTransform.fA12 = -cX*cY;
      m_pose.sTransform.fA20 = cY*cZ;                   m_pose.sTransform.fA21 = cY*sZ;                   m_pose.sTransform.fA22 = -sY;

      m_pose.sTransform.fA03 = - m_pose.sTransform.fA00 * transX - m_pose.sTransform.fA01 * transY - m_pose.sTransform.fA02 * transZ;
      m_pose.sTransform.fA13 = - m_pose.sTransform.fA10 * transX - m_pose.sTransform.fA11 * transY - m_pose.sTransform.fA12 * transZ;
      m_pose.sTransform.fA23 = - m_pose.sTransform.fA20 * transX - m_pose.sTransform.fA21 * transY - m_pose.sTransform.fA22 * transZ;
    }
  };


  class CStereoCamera : public CMonoCamera
  {
  public:

    /// Initialization method 1: Init the camera by the calibration data from RTE.
    ///                          Rotation matrix will not be calculated. It is just copied from the pose parameters.
    void setParams(const PoseParameters_t& poseParameters, const MonoCalibrationIntrinsic_t& monoCalibrationIntrinsic, float32 stereoBaseline)
    {
      CMonoCamera::setParams(poseParameters, monoCalibrationIntrinsic);
      m_stereoBaseline = stereoBaseline;

      preCalc();
    }

    /// Initialization method 2: Set all camera parameters manually.
    void setParams(float32 rotXroll, float32 rotYpitch, float32 rotZyaw,
                   float32 transX, float32 transY, float32 transZ,
                   float32 intrFocalX, float32 intrFocalY, 
                   float32 intrCenterX, float32 intrCenterY,
                   float32 stereoBaseline)
    {
      CMonoCamera::setParams(rotXroll, rotYpitch, rotZyaw, transX, transY, transZ, intrFocalX, intrFocalY, intrCenterX, intrCenterY);
      m_stereoBaseline = stereoBaseline;

      preCalc();
    }

    /// returns true if camera is up to date (compare camera calibration against internal camera state)
    boolean_t checkCameraUpToDate(const PoseParameters_t& pose, const MonoCalibrationIntrinsic_t& intr, float32 stereoBaseline)
    {
      return checkCameraUpToDate( pose.fRoll, pose.fPitch, pose.fYaw, pose.fTx, pose.fTy, pose.fTz,
                                  intr.fFocalX, intr.fFocalY, intr.fCenterX, intr.fCenterY, stereoBaseline);
    }

    /// returns true if camera is up to date (compare camera calibration against internal camera state)
    boolean_t checkCameraUpToDate( float32 rotXroll, float32 rotYpitch, float32 rotZyaw,
                                   float32 transX, float32 transY, float32 transZ,
                                   float32 intrFocalX, float32 intrFocalY, 
                                   float32 intrCenterX, float32 intrCenterY,
                                   float32 stereoBaseline)
    {
      return (  CMonoCamera::checkCameraUpToDate(rotXroll, rotYpitch, rotZyaw, transX, transY, transZ, intrFocalX, intrFocalY, intrCenterX, intrCenterY) &&
                m_stereoBaseline == stereoBaseline  );
    }

    // Parameter getter functions
    float32 getStereoBaseline() const { return m_stereoBaseline; }
    float32 getStereoConstant() const { return m_stereoConstant; }

    /// Transform point in world coordinate system to image coordinate system
    /// Identical to mono version + calculation of disparity
    /// Returns false if point in world is behind camera plane
    boolean_t World2Image(float32 worldX, float32 worldY, float32 worldZ,
                          float32& imageX, float32& imageY, float32& disparity) const
    {
      boolean_t result = false;
      float32 cameraX, cameraY, cameraZ;

      World2Camera(worldX, worldY, worldZ, cameraX, cameraY, cameraZ);
      if (std::abs(cameraZ) > std::numeric_limits<float32>::epsilon())
      {
        Camera2Image(cameraX, cameraY, cameraZ, imageX, imageY);
        disparity = m_stereoConstant  * cct::invert( cameraZ );
        result = true;
      }

      return result;
    }
    using CMonoCamera::World2Image;

    /// Transform point in camera coordinate system to image coordinate system
    /// Identical to mono version + calculation of disparity
    /// cameraZ must be positive (avoid projection behind camera)
    void Camera2Image(float32 cameraX, float32 cameraY, float32 cameraZ,
                      float32& imageX, float32& imageY, float32& disparity) const
    {
      CMonoCamera::Camera2Image(cameraX, cameraY, cameraZ, imageX, imageY);
      disparity = getDisparityFromCameraZ(cameraZ);
    }
    using CMonoCamera::Camera2Image;

    float32 getDisparityFromCameraZ(float32 cameraZ) const
    {
      assert (std::abs(cameraZ) > std::numeric_limits<float32>::epsilon());
      return (m_stereoConstant * cct::invert(cameraZ));
    }

    float32 getCameraZFromDisparity(float32 disparity) const
    {
      assert(disparity > std::numeric_limits<float32>::epsilon());
      return (m_stereoConstant * cct::invert(disparity));
    }

    /// Transform point in image coordinate system to camera coordinate system
    /// by specifying the stereo disparity
    /// disparity must be positive (avoid projection behind camera)
    void Image2CameraFromDisparity(float32 imageX, float32 imageY, float32 disparity,
                                   float32& cameraX, float32& cameraY, float32& cameraZ) const
    {
      cameraZ = getCameraZFromDisparity(disparity);
      CMonoCamera::Image2CameraKnownCameraZ(imageX, imageY, cameraX, cameraY, cameraZ);
    }

    /// Transform point in image coordinate system to world coordinate system
    /// by specifying the stereo disparity
    /// disparity must be positive (avoid projection behind camera)
    void Image2WorldFromDisparity(float32 imageX, float32 imageY, float32 disparity,
                                  float32& worldX, float32& worldY, float32& worldZ) const
    {
      float32 cameraX, cameraY, cameraZ;
      Image2CameraFromDisparity(imageX, imageY, disparity, cameraX, cameraY, cameraZ);
      CMonoCamera::Camera2World(cameraX, cameraY, cameraZ, worldX, worldY, worldZ);
    }

  private:

    float32 m_stereoBaseline;
    float32 m_stereoConstant;

    void preCalc()
    {
      m_stereoConstant = m_stereoBaseline * getIntrinsicFocalLengthX();
    }
  };

}

#endif // cct_camera_h__

