/// @file cct_camera.h Basic camera transformations for pinhole mono and stereo optics.
/// @copyright Continental AG, A.D.C. GmbH
/// $Revision: 1.1 $

#ifndef cct_camera_h__
#define cct_camera_h__
// PRQA S 1026 EOF
// 2020-2-5; uic58113
// summary < Msg(3:1026) Macro may be used as a constant expression.>
// reason < RTE is in C.Interface version has to use Macro instead of constants.>

/// Interface version of the classes in this file.
/// @warning If anything to the interface is changed, that number must be incremented by one!
#define CCT_CAMERA_INTFVER (1)

#include "algo_glob.h"

#include "cml_ext_cpp.h"
#include "cct_float_tools.h"

#include <cmath>
#include <limits>
#include <cassert>

// PRQA S 7007 EOF
// date: 2015-17-07, reviewer: Christian Exner, reason: QAC-Bug: The number of parameters is always <= 10.

namespace cct
{
  /// CCT mono camera provides the pinhole camera transformations.
  ///
  /// Before using the camera class it has to be initialized by setParams()!
  ///
  /// The function checkCameraUpToDate() can test if the camera has to be updated by setParams()
  /// or if the internal camera state is identical to test provided camera calibration.
  ///
  /// The coordinate systems are defined as follows:
  ///
  /// Image Coordinate System:
  /// <ul>
  /// <li> imageX from left to right
  /// <li> imageY from top to bottom
  /// </ul>
  /// Point (0,0) in image coordinate system is the most top left pixel in imager plane. Image coordinates are
  /// notated as "img", "image" or "i" throughout the class description.
  ///
  /// Camera Coordinate System:
  /// <ul>
  /// <li> cameraX is parallel to imageX
  /// <li> cameraY is parallel to imageY
  /// <li> cameraZ is the positive optical axis
  /// </ul>
  /// Point (0,0,0) in camera coordinate system is the center point in the camera. Camera coordinates are
  /// notated as "cam", "camera", "c" throughout the class description.
  ///
  /// @image html "cct_camera_pinhole_projection.svg" "Pinhole projection: Image and camera coordinates" width=50%
  ///
  /// World Coordinate System:
  /// <ul>
  /// <li> x longitudinal forward,
  /// <li> y lateral left,
  /// <li> z up
  /// </ul>
  /// The world coordinates are sometimes also called vehicle coordinates, since the camera almost always runs in the
  /// context of the vehicle as a moving platform. Thus the coordinates are notated as "world", "w" throughout
  /// the documentation. But: The camera class itself is not bound to that platform nor to the position of the coordinate
  /// system shown in the image and used as example. That alone is defined by the 6DOF (six degrees of freedom) that
  /// the user uses to setup the class instance.
  ///
  /// @image html cct_camera_world_coordinates.svg "World / vehicle and camera coordinates" width=50%
  ///
  /// In this example:
  /// <ul>
  /// <li>Point (0,0,0) in world coordinate system is the center of front wheel axle on the ground.
  /// <li>Rotation (pitch, yaw, roll) = (0,0,0) -> camera is looking parallel to the vehicles axes (cameraZ parallel to worldX,
  /// worldX descibes the vehicles longitundinal axis)
  /// </ul>
  class CMonoCamera
  {
  public:
    /// Constructor.
    /// @pre  None
    /// @post Class constructed and m_inverseFocalX, m_inverseFocalY, m_intr.fFocalX initialized to 0
    /// Initializes the inverse focal lengths and the focal legth x to 0. Use case: Detect an unitialized class
    /// @todo Check use case - this is only debugging!
    CMonoCamera()
      : m_inverseFocalX( 0.0F )
      , m_inverseFocalY( 0.0F )
    {
      m_intr.fFocalX = 0.0F;
    }

    /// Initialization method 1: Init the camera by the calibration data structs.
    /// Stores the given parameters into the class instance and calls preCalc().
    /// @pre  None
    /// @post
    /// - The values of @a poseParameters and @a monoCalibrationIntrinsic are stored in m_pose and m_intr respectively.
    /// - The preCalc() has been exceuted
    /// @remark Rotation matrix will not be calculated. It is just copied from the pose parameters.
    /// @param[in] poseParameters           The 6D extrinsic parameter set that defines the 3 rotation and 3 positional coordinates
    /// @param[in] monoCalibrationIntrinsic The intrinsic pinhole configuration that defines the focal length and the principal point
    void setParams(const PoseParameters_t& poseParameters, const MonoCalibrationIntrinsic_t& monoCalibrationIntrinsic)
    {
      m_pose = poseParameters;
      m_intr = monoCalibrationIntrinsic;

      preCalc();
    }

    /// Initialization method 2: Set all camera parameters manually.
    /// Stores the given parameters into the class instance and calls preCalcPoseTransformationMatrix() and preCalc().
    /// @pre  None
    /// @post
    /// - The values of @a rotXroll, @a rotYpitch, @a rotZyaw, @a transX, @a transY, @a transZ are stored in m_pose
    /// - The values of @a intrFocalX, @a intrFocalY, @a intrCenterX, @a intrCenterY are stored in m_intr
    /// - The preCalcPoseTransformationMatrix() and preCalc() have been exceuted
    /// @param[in] rotXroll    The roll angle of the camera. That is the rotation around the world X axis.
    /// @param[in] rotYpitch   The pitch angle of the camera. That is the rotation around the world Y axis.
    /// @param[in] rotZyaw     The yaw angle of the camera. That is the rotation around the world Z axis.
    /// @param[in] transX      The x-position of the camera in the world coordinate system.
    /// @param[in] transY      The y-position of the camera in the world coordinate system.
    /// @param[in] transZ      The z-position of the camera in the world coordinate system.
    /// @param[in] intrFocalX  The horizontal focal length of the pinhole camera model
    /// @param[in] intrFocalY  The vertical focal length of the pinhole camera model
    /// @param[in] intrCenterX The horizontal principal point coordinate
    /// @param[in] intrCenterY The vertical principal point coordinate
    void setParams(
      const float32 rotXroll,    const float32 rotYpitch,  const float32 rotZyaw,
      const float32 transX,      const float32 transY,     const float32 transZ,
      const float32 intrFocalX,  const float32 intrFocalY,
      const float32 intrCenterX, const float32 intrCenterY)
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

    /// Returns true if camera is up to date with respect to the given parameter set.
    /// It is done by comparing all extrinsic some of the intrinsic parameters given against the internal state.
    /// @pre  None
    /// @post None
    /// @InOutCorrelation
    /// A comparison of all the fields in the list below is done:
    /// <ul>
    /// <li> @a pose vs m_pose:
    ///  <ul>
    ///  <li> fRoll
    ///  <li> fPitch
    ///  <li> fYaw
    ///  <li> fTx
    ///  <li> fTy
    ///  <li> fTz
    ///  </ul>
    /// <li> @a intr vs m_intr:
    ///  <ul>
    ///  <li> fFocalX
    ///  <li> fFocalY
    ///  <li> fCenterX
    ///  <li> fCenterY
    ///  </ul>
    /// </ul>
    /// If all of these have a difference less than std::numeric_limits<float32>::min() the parameter set is
    /// seen as equal and the method returns true.
    /// @param[in] pose The 6D extrinsic parameter set that defines the 3 rotation and 3 positional coordinates
    /// @param[in] intr The intrinsic pinhole configuration that defines the focal length and the principal point
    /// @return True if the difference of all given to all stored pose and intrinsic parameters is less than
    ///         std::numeric_limits<float32>::min(), otherwise false.
    /// @todo  The distortion parameters inside MonoCalibrationIntrinsic_t (@a intr) are not compared, thus that method is not complete.
    bool checkCameraUpToDate(const PoseParameters_t& pose, const MonoCalibrationIntrinsic_t& intr) const
    {
      return checkCameraUpToDate( pose.fRoll, pose.fPitch, pose.fYaw, pose.fTx, pose.fTy, pose.fTz,
        intr.fFocalX, intr.fFocalY, intr.fCenterX, intr.fCenterY);
    }

    /// @copybrief checkCameraUpToDate(const PoseParameters_t&, const MonoCalibrationIntrinsic_t&) const
    /// It is done by comparing all extrinsic some of the intrinsic parameters given against the internal state.
    /// @pre  None
    /// @post None
    /// @InOutCorrelation
    /// A comparison of all the fields in the list below is done:
    /// <ul>
    /// <li> m_pose members vs:
    ///  <ul>
    ///  <li> @a rotXroll
    ///  <li> @a rotYpitch
    ///  <li> @a rotZyaw
    ///  <li> @a transX
    ///  <li> @a transY
    ///  <li> @a transZ
    ///  </ul>
    /// <li> m_intr members vs:
    ///  <ul>
    ///  <li> @a intrFocalX
    ///  <li> @a intrFocalY
    ///  <li> @a intrCenterX
    ///  <li> @a intrCenterY
    ///  </ul>
    /// </ul>
    /// If all of these have a difference less than std::numeric_limits<float32>::min() the parameter set is
    /// seen as equal and the method returns true.
    /// @param[in] rotXroll    The roll angle of the camera. That is the rotation around the world X axis.
    /// @param[in] rotYpitch   The pitch angle of the camera. That is the rotation around the world Y axis.
    /// @param[in] rotZyaw     The yaw angle of the camera. That is the rotation around the world Z axis.
    /// @param[in] transX      The x-position of the camera in the world coordinate system.
    /// @param[in] transY      The y-position of the camera in the world coordinate system.
    /// @param[in] transZ      The z-position of the camera in the world coordinate system.
    /// @param[in] intrFocalX  The horizontal focal length of the pinhole camera model
    /// @param[in] intrFocalY  The vertical focal length of the pinhole camera model
    /// @param[in] intrCenterX The horizontal principal point coordinate
    /// @param[in] intrCenterY The vertical principal point coordinate
    /// @return True if the difference of all given to all stored pose and intrinsic parameters is less than
    ///         std::numeric_limits<float32>::min(), otherwise false.
    /// @todo  The distortion parameters inside MonoCalibrationIntrinsic_t (m_intr) are not compared, thus that method is not complete.
    bool checkCameraUpToDate(
      const float32 rotXroll,    const float32 rotYpitch, const float32 rotZyaw,
      const float32 transX,      const float32 transY,    const float32 transZ,
      const float32 intrFocalX,  const float32 intrFocalY,
      const float32 intrCenterX, const float32 intrCenterY) const
    {
      return (
        (cml::abs(m_pose.fRoll     - rotXroll)     < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_pose.fPitch    - rotYpitch)    < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_pose.fYaw      - rotZyaw)      < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_pose.fTx       - transX)       < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_pose.fTy       - transY)       < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_pose.fTz       - transZ)       < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_intr.fFocalX   - intrFocalX)   < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_intr.fFocalY   - intrFocalY)   < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_intr.fCenterX  - intrCenterX)  < std::numeric_limits<float32>::min()) &&
        (cml::abs(m_intr.fCenterY  - intrCenterY)  < std::numeric_limits<float32>::min())    );
    }

    /// Translates camera position relative to the current camera position.
    /// It adds the given relative translation to the current camera translation and updates the transformation
    /// matrix m_pose.Transform to match that new translation.
    /// @param[in] transX Relative translation in x direction.
    /// @param[in] transY Relative translation in Y direction.
    /// @param[in] transZ Relative translation in Z direction.
    void translateCamera(const float32 transX, const float32 transY, const float32 transZ)
    {
      m_pose.fTx += transX;
      m_pose.fTy += transY;
      m_pose.fTz += transZ;

      m_pose.sTransform.fA03 += - m_pose.sTransform.fA00 * transX - m_pose.sTransform.fA01 * transY - m_pose.sTransform.fA02 * transZ;
      m_pose.sTransform.fA13 += - m_pose.sTransform.fA10 * transX - m_pose.sTransform.fA11 * transY - m_pose.sTransform.fA12 * transZ;
      m_pose.sTransform.fA23 += - m_pose.sTransform.fA20 * transX - m_pose.sTransform.fA21 * transY - m_pose.sTransform.fA22 * transZ;
    }

    /// @name Parameter getter functions
    /// @{
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
    /// @}

    /// Transforms a point in world coordinate system to camera coordinate system.
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Transformes the given coordinates @a worldX, @a worldY, @a worldZ into the camera coordinate system
    /// via the methods World2Camera*(). The resulting coordinates are written to @a cameraX, @a cameraY and @a cameraZ.
    /// Mathematics are described in the methods linked in the see also section.
    /// @sa World2CameraX(), World2CameraY(), World2CameraZ()
    /// @param[in] worldX X coordinate in world coordinate system
    /// @param[in] worldY Y coordinate in world coordinate system
    /// @param[in] worldZ Z coordinate in world coordinate system
    /// @param[out] cameraX Resulting x coordinate in camera coordinate system
    /// @param[out] cameraY Resulting y coordinate in camera coordinate system
    /// @param[out] cameraZ Resulting z coordinate in camera coordinate system
    void World2Camera(
      const float32 worldX,  const float32 worldY,  const float32 worldZ,
      float32&      cameraX, float32&      cameraY, float32&      cameraZ) const
    {
      cameraX = World2CameraX(worldX, worldY, worldZ);
      cameraY = World2CameraY(worldX, worldY, worldZ);
      cameraZ = World2CameraZ(worldX, worldY, worldZ);
    }

    /// Transform world coordinates to camera coordinates using the container class.
    /// @param[in]  worldPos The world coordinates to be transformed.
    /// @param[out] camPos   The output container for the camera coordinates.
    void World2Camera(const cml::CartesianPoint3D<float32>& worldPos, cml::CartesianPoint3D<float32>& camPos) const
    {
      // TODO: implement the camera rotation as a Matrix to be able to use matrix vector multiplications. E.g.
      // camPos = Rot * [worldPos + t]
      // PRQA S 3223 2
      // date: 2015-14-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long the different calls are made with disjoint indices.
      World2Camera(worldPos.x() , worldPos.y() , worldPos.z() , camPos.x() , camPos.y() , camPos.z());
    }

    /// Transform variances of independent random variables that follow Gaussian distributions from world coordinates to camera coordinates.
    /// The covariance of a linearly transformed (multiplication with matrix R) Gaussian random vector with covariance C is given by RCR^T.
    /// C is assumed to be diagonal here (independent random variables).
    /// @param[in]  varWorld The world coordinates to be transformed.
    /// @param[out]  varCam  The output container for the camera coordinates.
    void World2CameraVar(const cml::CartesianPoint3D<float32>& varWorld, cml::CartesianPoint3D<float32>& varCam) const
    {
      varCam.x() =
        cml::pow<2>(m_pose.sTransform.fA00)*(varWorld.x() )+
        cml::pow<2>(m_pose.sTransform.fA01)*(varWorld.y() )+
        cml::pow<2>(m_pose.sTransform.fA02)*(varWorld.z());
      varCam.y() =
        cml::pow<2>(m_pose.sTransform.fA10)*(varWorld.x() )+
        cml::pow<2>(m_pose.sTransform.fA11)*(varWorld.y() )+
        cml::pow<2>(m_pose.sTransform.fA12)*(varWorld.z());
      varCam.z() =
        cml::pow<2>(m_pose.sTransform.fA20)*(varWorld.x() )+
        cml::pow<2>(m_pose.sTransform.fA21)*(varWorld.y() )+
        cml::pow<2>(m_pose.sTransform.fA22)*(varWorld.z());
    }

    /// Transform variances of independent random variables that follow Gaussian distributions from camera coordinates to world coordinates.
    /// The covariance of a linearly transformed (multiplication with matrix R) Gaussian random vector with covariance C is given by RCR^T.
    /// C is assumed to be diagonal here (independent random variables).
    /// @param[in]  varCam     The variance of the camera coordinates to be transformed.
    /// @param[out] varWorld   The output variance of the world coordinates.
    void Camera2WorldVar(const cml::CartesianPoint3D<float32>& varCam, cml::CartesianPoint3D<float32>& varWorld) const
    {
      varWorld.x() =
        cml::pow<2>(m_pose.sTransform.fA00)*(varCam.x())+
        cml::pow<2>(m_pose.sTransform.fA10)*(varCam.y())+
        cml::pow<2>(m_pose.sTransform.fA20)*(varCam.z());
      varWorld.y() =
        cml::pow<2>(m_pose.sTransform.fA01)*(varCam.x())+
        cml::pow<2>(m_pose.sTransform.fA11)*(varCam.y())+
        cml::pow<2>(m_pose.sTransform.fA21)*(varCam.z());
      varWorld.z() =
        cml::pow<2>(m_pose.sTransform.fA02)*(varCam.x())+
        cml::pow<2>(m_pose.sTransform.fA12)*(varCam.y())+
        cml::pow<2>(m_pose.sTransform.fA22)*(varCam.z());
    }

    /// Transform variances of independent random variables that follow Gaussian distributions from camera coordinates to world coordinates.
    /// The covariance of a linearly transformed (multiplication with matrix R) Gaussian random vector with covariance C is given by RCR^T.
    /// C is assumed to be diagonal here (independent random variables).
    /// @param[in]  varCam     The variance of the camera coordinates to be transformed.
    /// @param[out] varWorld   The output variance of the world coordinates.
    /// @param[out] covWorldXY The output covariance of the world coordinates X and Y.
    /// @param[out] covWorldYZ The output covariance of the world coordinates Y and Z.
    /// @param[out] covWorldXZ The output covariance of the world coordinates X and Z.
    void Camera2WorldVar(
      const cml::CartesianPoint3D<float32>& varCam,
      cml::CartesianPoint3D<float32>& varWorld,
      float32& covWorldXY, float32& covWorldYZ, float32& covWorldXZ) const
    {
      Camera2WorldVar(varCam, varWorld);

      covWorldXY =
        m_pose.sTransform.fA00*m_pose.sTransform.fA01*varCam.x()+
        m_pose.sTransform.fA10*m_pose.sTransform.fA11*varCam.y()+
        m_pose.sTransform.fA20*m_pose.sTransform.fA21*varCam.z();
      covWorldYZ =
        m_pose.sTransform.fA01*m_pose.sTransform.fA02*varCam.x()+
        m_pose.sTransform.fA11*m_pose.sTransform.fA12*varCam.y()+
        m_pose.sTransform.fA21*m_pose.sTransform.fA22*varCam.z();
      covWorldXZ =
        m_pose.sTransform.fA00*m_pose.sTransform.fA02*varCam.x()+
        m_pose.sTransform.fA10*m_pose.sTransform.fA12*varCam.y()+
        m_pose.sTransform.fA20*m_pose.sTransform.fA22*varCam.z();
    }

    /// Transform point in world coordinate system to camera X coordinate.
    /// It executes only the X row of the matrix operation.
    /// @param[in]  worldX  World x-coordinate
    /// @param[in]  worldY  World y-coordinate
    /// @param[in]  worldZ  World z-coordinate
    /// @return Camera X coordinate.
    float32 World2CameraX (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return RotateWorld2CameraX(worldX, worldY, worldZ) + m_pose.sTransform.fA03;
    }

    /// Transform point in world coordinate system to camera Y coordinate.
    /// It executes only the Y row of the matrix operation.
    /// @param[in]  worldX  World x-coordinate
    /// @param[in]  worldY  World y-coordinate
    /// @param[in]  worldZ  World z-coordinate
    /// @return Camera Y coordinate.
    float32 World2CameraY (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return RotateWorld2CameraY(worldX, worldY, worldZ) + m_pose.sTransform.fA13;
    }

    /// Transform point in world coordinate system to camera Z coordinate.
    /// It executes only the Z row of the matrix operation.
    /// @param[in]  worldX  World x-coordinate
    /// @param[in]  worldY  World y-coordinate
    /// @param[in]  worldZ  World z-coordinate
    /// @return Camera Z coordinate.
    float32 World2CameraZ (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return RotateWorld2CameraZ(worldX, worldY, worldZ) + m_pose.sTransform.fA23;
    }

    /// Applies the camera rotation matrix: Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// It executes only the X row of the matrix operation.
    /// @param[in]  worldX  World x-coordinate
    /// @param[in]  worldY  World y-coordinate
    /// @param[in]  worldZ  World z-coordinate
    /// @return Camera X coordinate.
    float32 RotateWorld2CameraX (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return (m_pose.sTransform.fA00 * worldX) + (m_pose.sTransform.fA01 * worldY) + (m_pose.sTransform.fA02 * worldZ);
    }

    /// Applies the camera rotation matrix: Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// It executes only the Y row of the matrix operation.
    /// @param[in]  worldX  World x-coordinate
    /// @param[in]  worldY  World y-coordinate
    /// @param[in]  worldZ  World z-coordinate
    /// @return Camera Y coordinate.
    float32 RotateWorld2CameraY (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return (m_pose.sTransform.fA10 * worldX) + (m_pose.sTransform.fA11 * worldY) + (m_pose.sTransform.fA12 * worldZ);
    }

    /// Applies the camera rotation matrix: Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// It executes only the Z row of the matrix operation.
    /// @param[in]  worldX  World x-coordinate
    /// @param[in]  worldY  World y-coordinate
    /// @param[in]  worldZ  World z-coordinate
    /// @return Camera Z coordinate.
    float32 RotateWorld2CameraZ (const float32& worldX, const float32& worldY, const float32& worldZ) const
    {
      return (m_pose.sTransform.fA20 * worldX) + (m_pose.sTransform.fA21 * worldY) + (m_pose.sTransform.fA22 * worldZ);
    }

    /// Rotates from the camera coordinate system to the world coordinate system without (!) translation.
    /// @param[in]  worldX  World x-coordinate
    /// @param[in]  worldY  World y-coordinate
    /// @param[in]  worldZ  World z-coordinate
    /// @param[out] cameraX Camera x-coordinate of rotated vertex given with (@a worldX, @a worldY, @a worldZ)
    /// @param[out] cameraY Camera y-coordinate of rotated vertex given with (@a worldX, @a worldY, @a worldZ)
    /// @param[out] cameraZ Camera z-coordinate of rotated vertex given with (@a worldX, @a worldY, @a worldZ)
    void RotateWorld2Camera (
      const float32 worldX,  const float32 worldY,  const float32 worldZ,
      float32&      cameraX, float32&      cameraY, float32&      cameraZ) const
    {
      cameraX = RotateWorld2CameraX(worldX, worldY, worldZ);
      cameraY = RotateWorld2CameraY(worldX, worldY, worldZ);
      cameraZ = RotateWorld2CameraZ(worldX, worldY, worldZ);
    }

    /// Applies the camera rotation matrix: Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// The z-coordinate is assumed to be zero!
    /// It executes only the X row of the matrix operation.
    /// @todo Check use case. It just calls RotateWorld2CameraX() having Z = 0. Compilers are able to optimize this themselfes.
    /// @param[in] worldXY X and y-coordinate of the world point (worldX, worldY, 0) to be rotated.
    /// @return Camera Z coordinate.
    float32 RotateWorld2CameraXWorldZ0 (const cml::CartesianPoint2D<float32>& worldXY) const
    {
      // PRQA S 3223 2
      // date: 2015-15-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long as different calls are made with disjoint indices (x(), y(), z() function names).
      return RotateWorld2CameraX(worldXY.x(), worldXY.y(), 0.0F);
    }

    /// Applies the camera rotation matrix: Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// The z-coordinate is assumed to be zero!
    /// It executes only the Y row of the matrix operation.
    /// @todo Check use case. It just calls RotateWorld2CameraY() having Z = 0. Compilers are able to optimize this themselfes.
    /// @param[in] worldXY X and y-coordinate of the world point (worldX, worldY, 0) to be rotated.
    /// @return Camera Y coordinate.
    float32 RotateWorld2CameraYWorldZ0 (const cml::CartesianPoint2D<float32>& worldXY) const
    {
      // PRQA S 3223 2
      // date: 2015-15-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long as different calls are made with disjoint indices (x(), y(), z() function names).
      return RotateWorld2CameraY(worldXY.x(), worldXY.y(), 0.0F);
    }

    /// Applies the camera rotation matrix: Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// The z-coordinate is assumed to be zero!
    /// It executes only the Z row of the matrix operation.
    /// @todo Check use case. It just calls RotateWorld2CameraZ() having Z = 0. Compilers are able to optimize this themselfes.
    /// @param[in] worldXY X and y-coordinate of the world point (worldX, worldY, 0) to be rotated.
    /// @return Camera Z coordinate.
    float32 RotateWorld2CameraZWorldZ0 (const cml::CartesianPoint2D<float32>& worldXY) const
    {
      // PRQA S 3223 2
      // date: 2015-15-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long as different calls are made with disjoint indices (x(), y(), z() function names).
      return RotateWorld2CameraZ(worldXY.x(), worldXY.y(), 0.0F);
    }

    /// Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// It executes only the x row of the matrix operation.
    /// @param[in] cameraX Camera x-coordinate
    /// @param[in] cameraY Camera y-coordinate
    /// @param[in] cameraZ Camera z-coordinate
    /// @return Rotated x-coordinate of given vertex
    float32 RotateCamera2WorldX (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return ( m_pose.sTransform.fA00 * cameraX ) + ( m_pose.sTransform.fA10 * cameraY ) + ( m_pose.sTransform.fA20 * cameraZ );
    }

    /// Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// It executes only the y row of the matrix operation.
    /// @param[in] cameraX Camera x-coordinate
    /// @param[in] cameraY Camera y-coordinate
    /// @param[in] cameraZ Camera z-coordinate
    /// @return Rotated y-coordinate of given vertex
    float32 RotateCamera2WorldY (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return ( m_pose.sTransform.fA01 * cameraX ) + ( m_pose.sTransform.fA11 * cameraY ) + ( m_pose.sTransform.fA21 * cameraZ );
    }

    /// Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// It executes only the z row of the matrix operation.
    /// @param[in] cameraX Camera x-coordinate
    /// @param[in] cameraY Camera y-coordinate
    /// @param[in] cameraZ Camera z-coordinate
    /// @return Rotated z-coordinate of given vertex
    float32 RotateCamera2WorldZ (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return ( m_pose.sTransform.fA02 * cameraX ) + ( m_pose.sTransform.fA12 * cameraY ) + ( m_pose.sTransform.fA22 * cameraZ );
    }

    /// Rotates from the world coordinate system to the camera coordinate system without (!) translation.
    /// @param[in]  cameraX Camera x-coordinate
    /// @param[in]  cameraY Camera y-coordinate
    /// @param[in]  cameraZ Camera z-coordinate
    /// @param[out] worldX  World x-coordinate of rotated vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    /// @param[out] worldY  World y-coordinate of rotated vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    /// @param[out] worldZ  World z-coordinate of rotated vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    void RotateCamera2World (
      const float32 cameraX, const float32 cameraY, const float32 cameraZ,
      float32&      worldX,  float32&      worldY,  float32&      worldZ) const
    {
      worldX = RotateCamera2WorldX(cameraX, cameraY, cameraZ);
      worldY = RotateCamera2WorldY(cameraX, cameraY, cameraZ);
      worldZ = RotateCamera2WorldZ(cameraX, cameraY, cameraZ);
    }

    /// Transform point in camera coordinate system to world coordinate system.
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Transformes the given coordinates @a cameraX, @a cameraY, @a cameraZ into the camera coordinate system
    /// via the methods Camera2World*(). The resulting coordinates are written to @a worldX, @a worldY and @a worldZ.
    /// Mathematics are described in the methods linked in the see also section.
    /// @sa Camera2WorldX(), Camera2WorldY(), Camera2WorldZ()
    /// @param[in]  cameraX Camera x-coordinate
    /// @param[in]  cameraY Camera y-coordinate
    /// @param[in]  cameraZ Camera z-coordinate
    /// @param[out] worldX  World x-coordinate of transformed vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    /// @param[out] worldY  World y-coordinate of transformed vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    /// @param[out] worldZ  World z-coordinate of transformed vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    void Camera2World(
      const float32 cameraX, const float32 cameraY, const float32 cameraZ,
      float32&      worldX,  float32&      worldY,  float32&      worldZ) const
    {
      worldX = Camera2WorldX(cameraX, cameraY, cameraZ);
      worldY = Camera2WorldY(cameraX, cameraY, cameraZ);
      worldZ = Camera2WorldZ(cameraX, cameraY, cameraZ);
    }

    /// Transform point in camera coordinate system to world coordinate system.
    /// @param[in]  cameraPos A position in camera coordinates.
    /// @param[out] worldPos  The computed position in world coordinates.
    void Camera2World(const cml::CartesianPoint3D<float32>& cameraPos, cml::CartesianPoint3D<float32>& worldPos) const
    {
      // PRQA S 3223 2
      // date: 2015-9-12, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long the different calls are made with disjoint indices.
      Camera2World(cameraPos.x(), cameraPos.y(), cameraPos.z(), worldPos.x(), worldPos.y(), worldPos.z());
    }

    /// Transform point in camera coordinate system to world X coordinate.
    /// It executes only the X row of the matrix operation.
    /// @param[in]  cameraX Camera x-coordinate
    /// @param[in]  cameraY Camera y-coordinate
    /// @param[in]  cameraZ Camera z-coordinate
    /// @return World X coordinate.
    float32 Camera2WorldX (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return RotateCamera2WorldX(cameraX, cameraY, cameraZ) + m_pose.fTx;
    }

    /// Transform point in camera coordinate system to world X coordinate.
    /// It executes only the Y row of the matrix operation.
    /// @param[in]  cameraX Camera x-coordinate
    /// @param[in]  cameraY Camera y-coordinate
    /// @param[in]  cameraZ Camera z-coordinate
    /// @return World Y coordinate.
    float32 Camera2WorldY (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return RotateCamera2WorldY(cameraX, cameraY, cameraZ) + m_pose.fTy;
    }

    /// Transform point in camera coordinate system to world X coordinate.
    /// It executes only the Z row of the matrix operation.
    /// @param[in]  cameraX Camera x-coordinate
    /// @param[in]  cameraY Camera y-coordinate
    /// @param[in]  cameraZ Camera z-coordinate
    /// @return World Z coordinate.
    float32 Camera2WorldZ (const float32& cameraX, const float32& cameraY, const float32& cameraZ) const
    {
      return RotateCamera2WorldZ(cameraX, cameraY, cameraZ) + m_pose.fTz;
    }

    /// Project point in camera coordinates onto the image plane.
    /// @warning @a cameraZ must be positive (avoid projection behind camera) and non-zero
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Transformes the given coordinates @a cameraX, @a cameraY, @a cameraZ into the image coordinate system
    /// by applying the pinhole mathematics. The resulting coordinates are written to @a imageX, @a imageY.
    /// @f[
    /// image_x = \frac{focalLength_x * camera_x}{camera_z} + principalPoint_x \\
    /// image_y = \frac{focalLength_y * camera_y}{camera_z} + principalPoint_y
    /// @f]
    /// @param[in]  cameraX Camera x-coordinate
    /// @param[in]  cameraY Camera y-coordinate
    /// @param[in]  cameraZ Camera z-coordinate
    /// @param[out] imageX Image x-coordinate of transformed vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    /// @param[out] imageY Image y-coordinate of transformed vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    /// @return "false" if point is behind camera plane, else "true".
    bool Camera2Image(
      const float32 cameraX, const float32 cameraY, const float32 cameraZ,
      float32&      imageX,  float32&      imageY) const
    {
      const float32 newCameraZ  = cml::max(cameraZ, std::numeric_limits<float32>::min());
      const float32 cameraZ_inv = cct::invert(newCameraZ);
      imageX = ((m_intr.fFocalX * cameraZ_inv) * cameraX) + m_intr.fCenterX;
      imageY = ((m_intr.fFocalY * cameraZ_inv) * cameraY) + m_intr.fCenterY;

      return (cameraZ >= std::numeric_limits<float32>::min());
    }

    /// Project point in camera coordinates onto the image plane.
    /// @warning @a cameraPos.z() must be positive (avoid projection behind camera) and non-zero
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Transformes the given point @a cameraPos into the image coordinate system
    /// by applying the pinhole mathematics. The resulting point is written to @a imagePos.
    /// @f[
    /// imagePos_x = \frac{focalLength_x * cameraPos_x}{cameraPos_z} + principalPoint_x \\
    /// imagePos_y = \frac{focalLength_y * cameraPos_y}{cameraPos_z} + principalPoint_y
    /// @f]
    /// @param[in]  cameraPos The camera coordinates to be transformed.
    /// @param[out] imagePos The output container for the image coordinates.
    /// @return "false" if point is behind camera plane, else "true".
    bool Camera2Image(const cml::CartesianPoint3D<float32>& cameraPos, cml::CartesianPoint2D<float32>& imagePos) const
    {
      // PRQA S 3223 2
      // date: 2015-14-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long the different calls are made with disjoint indices.
      return Camera2Image(cameraPos.x() , cameraPos.y() , cameraPos.z() , imagePos.x() , imagePos.y());
    }

    /// Transform point in world coordinate system to image coordinate system
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Given point (@a worldPos) is tranformed to the camera coordinate system via World2Camera()
    /// and then projected onto the image plane via Camera2Image(). If intermediate point in camera coordinates is behind
    /// the image plane (camera z-coordinate less then std::numeric_limits<float32>::min()) the operation is aborted
    /// and the method returns "false". In that case the outputed image point (@a imagePos) is not set and left as given.
    /// The mathematical description will be found at the methods linked in the see also section.
    /// @sa World2Camera(), Camera2Image()
    /// @param[in]  worldPos The position in world coordinates to be transformed in image coordinates.
    /// @param[out] imagePos The result of the transformation.
    /// @return "false" if point is behind camera plane, else "true".
    bool World2Image(const cml::CartesianPoint3D<float32>& worldPos, cml::CartesianPoint2D<float32>& imagePos) const
    {
      // PRQA S 3223 2
      // date: 2017-26-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long the different calls are made with disjoint indices.
       return World2Image(worldPos.x(), worldPos.y(), worldPos.z(), imagePos.x(), imagePos.y());
    }

    /// Transform point in world coordinate system to image coordinate system
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Given point (@a worldX, @a worldY, @a worldZ) is tranformed to the camera coordinate system via World2Camera()
    /// and then projected onto the image plane via Camera2Image(). If intermediate point in camera coordinates is behind
    /// the image plane (camera z-coordinate less then std::numeric_limits<float32>::min()) the operation is aborted
    /// and the method returns "false". In that case the outputed image point (@a imageX, @a imageY) is not set and left as given.
    /// The mathematical description will be found at the methods linked in the see also section.
    /// @sa World2Camera(), Camera2Image()
    /// @param[in]  worldX World x-coordinate
    /// @param[in]  worldY World y-coordinate
    /// @param[in]  worldZ World z-coordinate
    /// @param[out] imageX Image x-coordinate of transformed vertex given with (@a worldX, @a worldY, @a worldZ)
    /// @param[out] imageY Image y-coordinate of transformed vertex given with (@a worldX, @a worldY, @a worldZ)
    /// @return "false" if point is behind camera plane, else "true".
    bool World2Image(
      const float32 worldX, const float32 worldY, const float32 worldZ,
      float32&      imageX, float32&      imageY) const
    {
      float32 cameraX;
      float32 cameraY;
      float32 cameraZ;

      World2Camera(worldX, worldY, worldZ, cameraX, cameraY, cameraZ);

      const bool result = (cameraZ >= std::numeric_limits<float32>::min());
      cameraZ = cml::max(cameraZ, std::numeric_limits<float32>::min());

      Camera2Image(cameraX, cameraY, cameraZ, imageX, imageY);

      return result;
    }

    /// compensates the distortion of a pixel in image coordinates
    /// distortion parameters are constant, distortion model is a 4th degree polynom: correctionFactor = 1 + k0*distance^2 + k1*distance^4 (distance related to center of image)
    /// @param[in]  imageX                distorted x image coordinate (origin top left)
    /// @param[in]  imageY                distorted y image coordinate (origin top left)
    /// @param[out] imageX_distortionFree corrected x image coordinate (origin top left)
    /// @param[out] imageY_distortionFree corrected y image coordinate (origin top left)
    void compensateDistortion(const float32 imageX,                const float32 imageY,
                              float32&      imageX_distortionFree, float32&      imageY_distortionFree ) const
    {
      const float32 distortionCoeff0 = getIntrinsicRectCeoff0();
      const float32 distortionCoeff1 = getIntrinsicRectCeoff1();
      // coordinate transformation to center of image
      const float32 imageX_center = (imageX - getIntrinsicCenterX());
      const float32 imageY_center = (imageY - getIntrinsicCenterY());
      const float32 distSquared = imageX_center*imageX_center + imageY_center*imageY_center; ///< squared distance related to center of image

      // compensationFactor = 1 + k0*distance^2 + k1*distance^4
      const float32 correctionFactor = 1.0f + distortionCoeff0 * distSquared + distortionCoeff1 * distSquared*distSquared;

      const float32 imageX_compensated = correctionFactor * imageX_center;
      const float32 imageY_compensated = correctionFactor * imageY_center;

      //coordinate transformation to border of image
      imageX_distortionFree = imageX_compensated + getIntrinsicCenterX();
      imageY_distortionFree = imageY_compensated + getIntrinsicCenterY();
    }

    /// Transform point in image to camera coordinate system by additionally specifying the camera x coordinate.
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Calculates the remaining 2 components of the camera point (@a cameraY, @a cameraZ) out of the given image point (@a imageX, @a imageY)
    /// and the @a cameraX coordinate by reorganizing the pinhole projection equations:
    /// @f[
    /// image_x = \frac{focalLength_x * camera_x}{camera_z} + principalPoint_x \\
    /// image_y = \frac{focalLength_y * camera_y}{camera_z} + principalPoint_y
    /// @f]
    /// Solved for @a cameraY and @a cameraZ, having @a cameraX:
    /// @f{eqnarray*}{
    /// camera_z &=& \frac{camera_x * focalLength_x}{image_x - principalPoint_x} \\
    /// camera_y &=& \frac{(image_y - principalPoint_y) * camera_z}{focalLength_y}
    /// @f}
    /// @param[in]  imageX  Image x-coordinate
    /// @param[in]  imageY  Image y-coordinate
    /// @param[in]  cameraX Known camera x-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] cameraY Resulting camera y-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] cameraZ Resulting camera z-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @return "false" if transformation fails due to image coordinate is identical to intrinsic center point
    bool Image2CameraKnownCameraX(
      const float32 imageX,  const float32 imageY,
      const float32 cameraX, float32&      cameraY, float32& cameraZ) const
    {
      bool result = true;
      float32 divisor = imageX - m_intr.fCenterX;
      if (cml::abs(divisor) < std::numeric_limits<float32>::min())
      {
        divisor = std::numeric_limits<float32>::min();
        result = false;
      }
      cameraZ = (cameraX * m_intr.fFocalX)  * cct::invert( divisor );
      cameraY = ((imageY - m_intr.fCenterY) * cameraZ) * m_inverseFocalY;

      return result;
    }

    /// Transform point in image to camera coordinate system by additionally specifying the camera y coordinate.
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Calculates the remaining 2 components of the camera point (@a cameraX, @a cameraZ) out of the given image point (@a imageX, @a imageY)
    /// and the @a cameraY coordinate by reorganizing the pinhole projection equations:
    /// @f[
    /// image_x = \frac{focalLength_x * camera_x}{camera_z} + principalPoint_x \\
    /// image_y = \frac{focalLength_y * camera_y}{camera_z} + principalPoint_y
    /// @f]
    /// Solved for @a cameraX and @a cameraZ, having @a cameraY:
    /// @f{eqnarray*}{
    /// camera_z &=& \frac{camera_y * focalLength_y}{image_y - principalPoint_y} \\
    /// camera_x &=& \frac{(image_x - principalPoint_x) * camera_z}{focalLength_x}
    /// @f}
    /// @param[in]  imageX  Image x-coordinate
    /// @param[in]  imageY  Image y-coordinate
    /// @param[out] cameraX Resulting camera x-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @param[in]  cameraY Known  camera y-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] cameraZ Resulting camera z-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @return "false" if transformation fails due to image coordinate is identical to intrinsic center point
    bool Image2CameraKnownCameraY(
      const float32 imageX,  const float32 imageY,
      float32&      cameraX, const float32 cameraY, float32& cameraZ) const
    {
      bool result = true;
      float32 divisor = imageY - m_intr.fCenterY;
      if (cml::abs(divisor) < std::numeric_limits<float32>::min())
      {
        divisor = std::numeric_limits<float32>::min();
        result = false;
      }
      cameraZ = (cameraY * m_intr.fFocalY)  * cct::invert( divisor );
      cameraX = ((imageX - m_intr.fCenterX) * cameraZ) * m_inverseFocalX;

      return result;
    }

    /// Transform point in image coordinate system to camera coordinate system
    /// by specifying the camera z coordinate together with the variance estimates. cameraZ must be positive (avoid projection behind camera).
    /// @param[in]     imagePos        The image position measurement x,y are horizontal and vertical coordinates respectively.
    /// @param[in]     imagePosVar     The variance estimate of the image position measurement x,y are horizontal and vertical coordinates respectively.
    /// @param[in,out] cameraPos       The computed camera position, the z coordinate is used as input.
    /// @param[in,out] cameraPosVar    The variance estimate of the computed camera position, the z coordinate is used as input.
    /// @return "false" if cameraZ is not positive, else "true".
    bool Image2CameraKnownCameraZVar(
      const cml::CartesianPoint2D<float32>& imagePos , const cml::CartesianPoint2D<float32>& imagePosVar,
            cml::CartesianPoint3D<float32>& cameraPos,       cml::CartesianPoint3D<float32>& cameraPosVar) const
    {
      // PRQA S 3223 3
      // date: 2015-14-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long the different calls are made with disjoint indices.
      ImageX2CameraXKnownCameraZVar(imagePos.x(), imagePosVar.x(), cameraPos.z(), cameraPosVar.z(), cameraPos.x(), cameraPosVar.x());
      ImageY2CameraYKnownCameraZVar(imagePos.y(), imagePosVar.y(), cameraPos.z(), cameraPosVar.z(), cameraPos.y(), cameraPosVar.y());

      return (cameraPos.z() > std::numeric_limits<float32>::min());
    }

    /// Transform point in image to camera coordinate system by additionally specifying the camera z coordinate.
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Calculates the remaining 2 components of the camera point @a camPos out of the given image point @a imagePos
    /// and the z-coordinate set in @a camPos by reorganizing the pinhole projection equations:
    /// @f[
    /// imagePos_x = \frac{focalLength_x * camPos_x}{camPos_z} + principalPoint_x \\
    /// imagePos_y = \frac{focalLength_y * camPos_y}{camPos_z} + principalPoint_y
    /// @f]
    /// Solved for @a cameraX and @a cameraY, having @a cameraZ:
    /// @f{eqnarray*}{
    /// camPos_x &=& \frac{(imagePos_x - principalPoint_x) * camPos_z}{focalLength_x} \\
    /// camPos_y &=& \frac{(imagePos_y - principalPoint_y) * camPos_z}{focalLength_y}
    /// @f}
    /// Utilizes the Image2CameraKnownCameraZ(const float32, const float32, float32&, float32&, const float32) const for the calculation.
    /// @param[in]     imagePos  Image coordinate
    /// @param[in,out] cameraPos Camera point, that gets its remaining coordinates x and y calcualated out of image point @a imagePos and the must have set coordinate z.
    /// @return "false" if cameraZ is not positive, else "true".
    bool Image2CameraKnownCameraZ(
      const cml::CartesianPoint2D<float32>& imagePos,
            cml::CartesianPoint3D<float32>& cameraPos) const
    {
      // PRQA S 3223 2
      // date: 2015-14-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long the different calls are made with disjoint indices.
      return Image2CameraKnownCameraZ(imagePos.x(), imagePos.y(), cameraPos.x(), cameraPos.y(), cameraPos.z());
    }

    /// Transform point in image to camera coordinate system by additionally specifying the camera z coordinate.
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Calculates the remaining 2 components of the camera point (@a cameraX, @a cameraY) out of the given image point (@a imageX, @a imageY)
    /// and the @a cameraZ coordinate by reorganizing the pinhole projection equations:
    /// @f[
    /// image_x = \frac{focalLength_x * camera_x}{camera_z} + principalPoint_x \\
    /// image_y = \frac{focalLength_y * camera_y}{camera_z} + principalPoint_y
    /// @f]
    /// Solved for @a cameraX and @a cameraY, having @a cameraZ:
    /// @f{eqnarray*}{
    /// camera_x &=& \frac{(image_x - principalPoint_x) * camera_z}{focalLength_x} \\
    /// camera_y &=& \frac{(image_y - principalPoint_y) * camera_z}{focalLength_y}
    /// @f}
    /// @sa ImageX2CameraXKnownCameraZ(), ImageY2CameraYKnownCameraZ(), Image2CameraKnownDistance()
    /// @param[in]  imageX  Image x-coordinate
    /// @param[in]  imageY  Image y-coordinate
    /// @param[out] cameraX Resulting camera x-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] cameraY Resulting camera y-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @param[in]  cameraZ Known camera z-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @return "false" if cameraZ is not positive, else "true".
    bool Image2CameraKnownCameraZ(
      const float32 imageX,  const float32 imageY,
      float32&      cameraX, float32&      cameraY, const float32 cameraZ) const
    {
      const float32 newCameraZ = cml::max(cameraZ, std::numeric_limits<float32>::min());
      cameraX = ImageX2CameraXKnownCameraZ(imageX, newCameraZ);
      cameraY = ImageY2CameraYKnownCameraZ(imageY, newCameraZ);

      return (cameraZ >= std::numeric_limits<float32>::min());
    }

    /// Transform the X coordinate in the image coordinate system to the X coordinate of the camera coordinate system
    /// given the camera Z coordinate together with the variance estimates.
    /// @param[in]  imageX     The horizontal image coordinate.
    /// @param[in]  imageXVar  The variance estimate of the horizontal image coordinate.
    /// @param[in]  cameraZ    The camera z coordinate.
    /// @param[in]  cameraZVar The variance estimate of the camera z coordinate.
    /// @param[out] cameraX    The computed camera x coordinate.
    /// @param[out] cameraXVar The variance estimate of the camera x coordinate.
    /// @return "false" if cameraZ is not positive, else "true".
    bool ImageX2CameraXKnownCameraZVar(const float32 imageX, const float32 imageXVar, const float32 cameraZ, const float32 cameraZVar, float32& cameraX, float32& cameraXVar) const
    {
      const float32 newCameraZ   = cml::max(cameraZ, std::numeric_limits<float32>::min());
      const float32 dCamXdCamZ   = (imageX - m_intr.fCenterX) * m_inverseFocalX;
      const float32 dCamXdimageX = newCameraZ                 * m_inverseFocalX;

      cameraX    = dCamXdCamZ * newCameraZ;
      cameraXVar = cml::pow<2>(dCamXdCamZ)*cameraZVar + cml::pow<2>(dCamXdimageX)*imageXVar;
      assert(cml::abs(cameraX - ImageX2CameraXKnownCameraZ(imageX, newCameraZ)) < cml::max(cml::abs(2.0F*cameraX),1.0F)*std::numeric_limits<float32>::epsilon());

      return (cameraZ >= std::numeric_limits<float32>::min());
    }

    /// Transform the Y coordinate in the image coordinate system to the Y coordinate of the camera coordinate system. Also propagate the variances.
    /// given the camera Z coordinate together with the variance estimates.
    /// @param[in]  imageY     The horizontal image coordinate.
    /// @param[in]  imageYVar  The variance estimate of the horizontal image coordinate.
    /// @param[in]  cameraZ    The camera z coordinate.
    /// @param[in]  cameraZVar The variance estimate of the camera z coordinate.
    /// @param[out] cameraY    The computed camera y coordinate.
    /// @param[out] cameraYVar The variance estimate of the camera y coordinate.
    /// @return "false" if point is behind camera plane, else "true".
    bool ImageY2CameraYKnownCameraZVar(const float32 imageY, const float32 imageYVar, const float32 cameraZ, const float32 cameraZVar, float32& cameraY, float32& cameraYVar) const
    {
      const float32 newCameraZ   = cml::max(cameraZ, std::numeric_limits<float32>::min());
      const float32 dCamYdCamZ   = (imageY - m_intr.fCenterY) * m_inverseFocalY;
      const float32 dCamYdimageY = newCameraZ                 * m_inverseFocalY;

      cameraY    = dCamYdCamZ * newCameraZ;
      cameraYVar = cml::pow<2>(dCamYdCamZ)*cameraZVar + cml::pow<2>(dCamYdimageY)*imageYVar;
      assert(cml::abs(cameraY - ImageY2CameraYKnownCameraZ(imageY, newCameraZ)) < cml::max(cml::abs(2.0F*cameraY),1.0F)*std::numeric_limits<float32>::epsilon());

      return (cameraZ >= std::numeric_limits<float32>::min());
    }

    /// Transform the X coordinate in the image coordinate system to the X coordinate of the camera coordinate system
    /// given the camera Z coordinate.
    /// @pre  Initialized class instance.
    /// @post None.
    /// @InOutCorrelation
    /// Calculates the x component of the camera point out of the given image x-coordinate @a imageX
    /// and the @a cameraZ coordinate by reorganizing the pinhole projection equations:
    /// @f[
    /// image_x = \frac{focalLength_x * camera_x}{camera_z} + principalPoint_x \\
    /// image_y = \frac{focalLength_y * camera_y}{camera_z} + principalPoint_y
    /// @f]
    /// Solved for x-coordinate:
    /// @f[
    /// camera_x = \frac{(image_x - principalPoint_x) * camera_z}{focalLength_x}
    /// @f]
    /// @sa Image2CameraKnownCameraZ()
    /// @param[in]  imageX  Image x-coordinate
    /// @param[in]  cameraZ Known camera z-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @return Camera x-coordinate according given @a imageX and @a cameraZ
    float32 ImageX2CameraXKnownCameraZ(const float32 imageX, const float32 cameraZ) const
    {
      return ((imageX - m_intr.fCenterX) * cameraZ) * m_inverseFocalX;
    }

    /// Transform the Y coordinate in the image coordinate system to the Y coordinate of the camera coordinate system
    /// given the camera Z coordinate.
    /// @pre  Initialized class instance.
    /// @post None.
    /// @InOutCorrelation
    /// Calculates the y component of the camera point out of the given image y-coordinate @a imageY
    /// and the @a cameraZ coordinate by reorganizing the pinhole projection equations:
    /// @f[
    /// image_x = \frac{focalLength_x * camera_x}{camera_z} + principalPoint_x \\
    /// image_y = \frac{focalLength_y * camera_y}{camera_z} + principalPoint_y
    /// @f]
    /// Solved for camera y-coordinate:
    /// @f[
    /// camera_y = \frac{(image_y - principalPoint_y) * camera_z}{focalLength_y}
    /// @f]
    /// @sa Image2CameraKnownCameraZ()
    /// @param[in]  imageY  Image y-coordinate
    /// @param[in]  cameraZ Known camera z-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @return Camera y-coordinate according given @a imageY and @a cameraZ
    float32 ImageY2CameraYKnownCameraZ(const float32 imageY, const float32 cameraZ) const
    {
      return ((imageY - m_intr.fCenterY) * cameraZ) * m_inverseFocalY;
    }

    /// Transform point in image coordinate system to camera coordinate system
    /// by specifying a radial distance between the point and the camera.
    /// @warning Distance must be positive (avoid projection behind camera)
    /// @pre  Initialized class instance.
    /// @post None.
    /// @InOutCorrelation
    /// Define @a a and @a b:
    /// @f[
    /// a = \frac{image_x - principalPoint_x}{focalLength_x} \\
    /// b = \frac{image_y - principalPoint_y}{focalLength_y}
    /// @f]
    /// According to the pinhole projection equations, @a cameraX and @a cameraY can be represented by @cameraZ:
    /// @f[
    /// camera_x = a * camera_z \\
    /// camera_y = b * camera_z
    /// @f]
    /// Since we have in 3D:
    /// @f{eqnarray*}{
    /// distance^2 &=& camera_x^2 + camera_y^2 + camera_z^2 \\
    ///            &=& camera_z^2 * (a^2 + b^2 + 1)
    /// @f}
    /// Solved for @a camera_z:
    /// @f[
    /// camera_z = \frac{distance}{\sqrt{a^2 + b^2 + 1}}
    /// @f]
    /// @sa Image2CameraKnownCameraZ()
    /// @param[in]  imageX   Image x-coordinate
    /// @param[in]  imageY   Image y-coordinate
    /// @param[in]  distance Radial distance on the ray specified by @a imageX and @a imageY
    /// @param[out] cameraX Resulting camera x-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] cameraY Resulting camera y-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] cameraZ Resulting camera z-coordinate of the point (@a cameraX, @a cameraY, @a cameraZ) related to the image point (@a imageX, @a imageY)
    /// @return Camera y-coordinate according given @a imageY and @a cameraZ
    /// @return "false" if the distance is not positive, else "true".
    bool Image2CameraKnownDistance(
      const float32 imageX,  const float32 imageY,  const float32 distance,
      float32&      cameraX, float32&      cameraY, float32&      cameraZ) const
    {
      const float32 a = (imageX - m_intr.fCenterX) * m_inverseFocalX;
      const float32 b = (imageY - m_intr.fCenterY) * m_inverseFocalY;

      const float32 newDistance = cml::max(distance, std::numeric_limits<float32>::min());

      cameraZ = newDistance * cct::invertSqrt((a*a) + (b*b) + 1.0f);
      cameraX = a * cameraZ;
      cameraY = b * cameraZ;

      return (distance >= std::numeric_limits<float32>::min());
    }

    /// Transform point in image coordinate system to world coordinate system
    /// by specifying the world x coordinate.
    /// @todo InOutCorrelation to be done.
    /// @param[in]  imageX   Image x-coordinate
    /// @param[in]  imageY   Image y-coordinate
    /// @param[in]  worldX Known world x-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] worldY Resulting world y-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] worldZ Resulting world z-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @return False if transformation fails because the view ray from (@a imageX, @a imageY) is parallel to the plane defined by the assumption @a worldX, true otherwise.
    ///         If the transformation fails, none of the outputs (@a worldY, @a worldZ) will be calculated nor initialized!
    bool Image2WorldKnownWorldX(
      const float32 imageX, const float32 imageY,
      const float32 worldX, float32&      worldY, float32& worldZ) const
    {
      bool result = false;

      // normalize image coordinates
      float32 normX;
      float32 normY;
      Image2CameraKnownCameraZ(imageX, imageY, normX, normY, 1.0F);

      // rotate towards world coordinate system
      float32 worldCamOrigX;
      float32 worldCamOrigY;
      float32 worldCamOrigZ;
      RotateCamera2World (normX, normY, 1.0F, worldCamOrigX, worldCamOrigY, worldCamOrigZ);

      if (cml::abs(worldCamOrigX) > std::numeric_limits<float32>::min())
      {
        const float32 zCam = (worldX - m_pose.fTx) * cct::invert( worldCamOrigX );

        worldY = (worldCamOrigY * zCam) + m_pose.fTy;
        worldZ = (worldCamOrigZ * zCam) + m_pose.fTz;

        result = true;
      }

      return result;
    }

    /// Transform point in image coordinate system to world coordinate system
    /// by specifying the world y coordinate.
    /// @todo InOutCorrelation to be done.
    /// @param[in]  imageX   Image x-coordinate
    /// @param[in]  imageY   Image y-coordinate
    /// @param[out] worldX Resulting world x-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @param[in]  worldY Known world y-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] worldZ Resulting world z-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @return False if transformation fails because the view ray from (@a imageX, @a imageY) is parallel to the plane defined by the assumption @a worldY, true otherwise.
    ///         If the transformation fails, none of the outputs (@a worldX, @a worldZ) will be calculated nor initialized!
    bool Image2WorldKnownWorldY(
      const float32 imageX, const float32 imageY,
      float32&      worldX, const float32 worldY, float32& worldZ) const
    {
      bool result = false;

      // normalize image coordinates
      float32 normX;
      float32 normY;
      Image2CameraKnownCameraZ(imageX, imageY, normX, normY, 1.0F);

      // rotate towards world coordinate system
      float32 worldCamOrigX;
      float32 worldCamOrigY;
      float32 worldCamOrigZ;
      RotateCamera2World (normX, normY, 1.0F, worldCamOrigX, worldCamOrigY, worldCamOrigZ);

      if (cml::abs(worldCamOrigY) > std::numeric_limits<float32>::min())
      {
        const float32 zCam = (worldY - m_pose.fTy) * cct::invert( worldCamOrigY );

        worldX = (worldCamOrigX * zCam) + m_pose.fTx;
        worldZ = (worldCamOrigZ * zCam) + m_pose.fTz;

        result = true;
      }

      return result;
    }

    /// Transform point in image coordinate system to world coordinate system
    /// by specifying the world z coordinate.
    /// @todo InOutCorrelation to be done.
    /// @param[in]  imageX   Image x-coordinate
    /// @param[in]  imageY   Image y-coordinate
    /// @param[out] worldX Resulting world x-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @param[out] worldY Resulting world y-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @param[in]  worldZ Known world z-coordinate of the point (@a worldX, @a worldY, @a worldZ) related to the image point (@a imageX, @a imageY)
    /// @return False if transformation fails because the view ray from (@a imageX, @a imageY) is parallel to the plane defined by the assumption @a worldZ, true otherwise.
    ///         If the transformation fails, none of the outputs (@a worldX, @a worldY) will be calculated nor initialized!
    bool Image2WorldKnownWorldZ(
      const float32 imageX, const float32 imageY,
      float32&      worldX, float32&      worldY, const float32 worldZ) const
    {
      bool result = false;

      // normalize image coordinates
      float32 normX;
      float32 normY;
      Image2CameraKnownCameraZ(imageX, imageY, normX, normY, 1.0F);

      // rotate towards world coordinate system
      float32 worldCamOrigX;
      float32 worldCamOrigY;
      float32 worldCamOrigZ;
      RotateCamera2World (normX, normY, 1.0F, worldCamOrigX, worldCamOrigY, worldCamOrigZ);

      if (cml::abs(worldCamOrigZ) > std::numeric_limits<float32>::min())
      {
        const float32 zCam = (worldZ - m_pose.fTz) * cct::invert( worldCamOrigZ );

        worldX = (worldCamOrigX * zCam) + m_pose.fTx;
        worldY = (worldCamOrigY * zCam) + m_pose.fTy;

        result = true;
      }

      return result;
    }

    /// Transforms 2d image coordinates into 3d world coordinates given the world z coordinate. In addition the variance for the resulting world position computed from the
    /// image coordinate variance is computed It is assumed that the input world z coordinate is without error.
    /// @param[in]  imageX    The x-image coordinate to be transformed.
    /// @param[in]  imageY    The y-image coordinate to be transformed.
    /// @param[in]  imageXVar The variance of the x-image coordinate to be transformed.
    /// @param[in]  imageYVar The variance of the y-image coordinate to be transformed.
    /// @param[out] worldX    The resulting x-world coordinate.
    /// @param[out] worldY    The resulting y-world coordinate.
    /// @param[in]  worldZ    The known z-world coordinate.
    /// @param[out] worldXVar The variance of the resulting x-world coordinate.
    /// @param[out] worldYVar The variance of the resulting y-world coordinate.
    /// @return False if transformation fails because the view ray from (@a imageX, @a imageY) is parallel to the plane defined by the assumption @a worldZ, true otherwise.
    ///         If the transformation fails, none of the outputs (@a worldX, @a worldY, @a worldXVar, @a worldYVar) will be calculated nor initialized!
    bool Image2WorldKnownWorldZVar(
      const float32 imageX,    const float32 imageY,
      const float32 imageXVar, const float32 imageYVar,
      float32&      worldX,    float32&      worldY,    const float32 worldZ,
      float32&      worldXVar, float32&      worldYVar                       ) const
    {
      bool result = false;

      // normalize image coordinates
      float32 normX;
      float32 normY;
      Image2CameraKnownCameraZ(imageX, imageY, normX, normY, 1.0F);

      // rotate towards world coordinate system
      float32 worldCamOrigX;
      float32 worldCamOrigY;
      float32 worldCamOrigZ;
      RotateCamera2World (normX, normY, 1.0F, worldCamOrigX, worldCamOrigY, worldCamOrigZ);

      if (cml::abs(worldCamOrigZ) > std::numeric_limits<float32>::min())
      {
        // calculate divisor
        const float32 worldCamOrigZInv = cct::invert( worldCamOrigZ );

        // calculate real zCam from our knowledge
        const float32 zCam = (worldZ - m_pose.fTz) * worldCamOrigZInv;

        // calculate positions
        worldX = (worldCamOrigX * zCam) + m_pose.fTx;
        worldY = (worldCamOrigY * zCam) + m_pose.fTy;

        // calculate other real cam coordinates
        const float32 xCam = (worldX - m_pose.fTx) * worldCamOrigZInv;
        const float32 yCam = (worldY - m_pose.fTy) * worldCamOrigZInv;

        // propagate variances
        const float32 dWxDxI = ((m_pose.sTransform.fA00 * zCam) - (m_pose.sTransform.fA02 * xCam)) * m_inverseFocalX;
        const float32 dWxDyI = ((m_pose.sTransform.fA10 * zCam) - (m_pose.sTransform.fA12 * xCam)) * m_inverseFocalY;

        const float32 dWyDxI = ((m_pose.sTransform.fA01 * zCam) - (m_pose.sTransform.fA02 * yCam)) * m_inverseFocalX;
        const float32 dWyDyI = ((m_pose.sTransform.fA11 * zCam) - (m_pose.sTransform.fA12 * yCam)) * m_inverseFocalY;

        worldXVar = (cml::pow<2>(dWxDxI) * imageXVar) + (cml::pow<2>(dWxDyI) * imageYVar);
        worldYVar = (cml::pow<2>(dWyDxI) * imageXVar) + (cml::pow<2>(dWyDyI) * imageYVar);

        result = true;
      }

      return result;
    }
    /// Transforms 2d image coordinates into 3d world coordinates given the world z coordinate.
    /// @param[in] imagePos     The image coordinates to be transformed.
    /// @param[in,out] worldPos The world coordinates, the z coordinate is needed as input in the transformation.
    ///                         The x and y coordinates are computed and will contain the transformation result.
    /// @return If transformation fails due to image coordinate is identical to intrinsic center point "false" is returned, else "true".
    bool Image2WorldKnownWorldZ(
      const cml::CartesianPoint2D<float32>& imagePos,
      cml::CartesianPoint3D<float32>&       worldPos) const
    {
      // PRQA S 3223 2
      // date: 2015-14-07, reviewer: Robert Stück, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long the different calls are made with disjoint indices.
      return Image2WorldKnownWorldZ(imagePos.x(), imagePos.y(), worldPos.x(), worldPos.y(), worldPos.z());
    }

    /// @copybrief Image2WorldKnownWorldZVar(const float32, const float32, const float32, const float32, float32&, float32&, const float32, float32&, float32&) const
    /// @param[in] imagePos     The image coordinates to be transformed.
    /// @param[in] imagePosVar  The image coordinates to be transformed.
    /// @param[in,out] worldPos The world coordinates, the z coordinate is needed as input in the transformation.
    ///                         The x and y coordinates are computed and will contain the transformation result.
    /// @param[out] worldPosVar The variance estimate of the world coordinates x and y.
    /// @return False if transformation fails because the view ray from @a imagePos is parallel to the plane defined by the assumption @a worldZ, true otherwise.
    ///         If the transformation fails, none of the outputs (@a worldPos, @a worldPosVar) will be calculated nor initialized!
    bool Image2WorldKnownWorldZVar(
      const cml::CartesianPoint2D<float32>& imagePos, const cml::CartesianPoint2D<float32>& imagePosVar,
      cml::CartesianPoint3D<float32>&       worldPos, cml::CartesianPoint2D<float32>&       worldPosVar) const
    {
      // PRQA S 3223 6
      // date: 2015-10-26, reviewer: Christian Exner, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long they are not called twice since they are accessing disjunct parts of the instance.
      return Image2WorldKnownWorldZVar(
        imagePos.x(),    imagePos.y(),
        imagePosVar.x(), imagePosVar.y(),
        worldPos.x(),    worldPos.y(),    worldPos.z(),
        worldPosVar.x(), worldPosVar.y());
    }

    /// Transform given image coordinate to image coordinate of other camera, assuming the optical axes of both cameras are the same.
    ///
    /// @code
    /// Same optical axis means:
    ///                     x_c/z_c = (x_i_src - x0_src) / fx_src
    ///                     x_c/z_c = (x_i_dst - x0_dst) / fx_dst
    ///
    /// Transition:
    /// (x_i_dst - x0_dst) / fx_dst = (x_i_src - x0_src) / fx_src
    /// (x_i_dst - x0_dst)          = (x_i_src - x0_src) * (fx_dst / fx_src)
    ///  x_i_dst                    = (x_i_src - x0_src) * (fx_dst / fx_src) + x0_dst
    ///
    /// Same applies for y
    /// @endcode
    ///
    /// @param[in] imageX     Image x-coordinate of our coordinate system.
    /// @param[in] imageY     Image y-coordinate of our coordinate system.
    /// @param[in] dstCam     Destination camera.
    /// @param[out] dstImageX Image x-coordinate of @a dstCam coordinate system.
    /// @param[out] dstImageY Image y-coordinate of @a dstCam coordinate system.
    void Image2ImageSameOpticalAxis(const float32 imageX, const float32 imageY, const CMonoCamera& dstCam, float32& dstImageX, float32& dstImageY) const
    {
      // ensure same origin (less than one mm as rough criteria)
      assert (cml::abs(getTranslationX() - dstCam.getTranslationX()) < 1e-3F);
      assert (cml::abs(getTranslationY() - dstCam.getTranslationY()) < 1e-3F);
      assert (cml::abs(getTranslationZ() - dstCam.getTranslationZ()) < 1e-3F);

      // ensure same origin (less than one pixel @ 20px / 1°)
      assert (cml::abs(getRotationXroll()  - dstCam.getRotationXroll() ) < 9e-4);
      assert (cml::abs(getRotationYPitch() - dstCam.getRotationYPitch()) < 9e-4);
      assert (cml::abs(getRotationZYaw()   - dstCam.getRotationZYaw()  ) < 9e-4);

      // compute focal length and shift corrected destination coordinate
      const float32 focalScaleX = dstCam.getIntrinsicFocalLengthX() * getIntrinsicFocalLengthXInverted();
      const float32 focalScaleY = dstCam.getIntrinsicFocalLengthY() * getIntrinsicFocalLengthYInverted();

      dstImageX = (imageX - getIntrinsicCenterX()) * focalScaleX + dstCam.getIntrinsicCenterX();
      dstImageY = (imageY - getIntrinsicCenterY()) * focalScaleY + dstCam.getIntrinsicCenterY();
    }

    /// Transform given image coordinate to image coordinate of other camera, assuming the optical axes of both cameras having the same origin.
    ///
    /// @code
    /// Same origin means:
    ///            P_wrot = R_src^T * P_c_src
    ///            P_wrot = R_dst^T * P_c_dst
    ///
    /// Assuming  z_c_src = 1:
    ///           x_c_src = (x_i_src - x0_src) / fx_src
    ///           y_c_src = (y_i_src - y0_src) / fy_src
    ///
    /// Transition:
    /// R_dst^T * P_c_dst =         R_src^T * P_c_src
    ///           P_c_dst = R_dst * R_src^T * P_c_src
    ///
    /// Project to destination camera, see Camera2Image()
    /// @endcode
    ///
    /// @param[in] imageX     Image x-coordinate of our coordinate system.
    /// @param[in] imageY     Image y-coordinate of our coordinate system.
    /// @param[in] dstCam     Destination camera.
    /// @param[out] dstImageX Image x-coordinate of @a dstCam coordinate system.
    /// @param[out] dstImageY Image y-coordinate of @a dstCam coordinate system.
    void Image2ImageSameOrigin(const float32 imageX, const float32 imageY, const CMonoCamera& dstCam, float32& dstImageX, float32& dstImageY) const
    {
      // ensure same origin (less than one mm as rough criteria)
      //assert (cml::abs(getTranslationX() - dstCam.getTranslationX()) < 1e-3F);
      //assert (cml::abs(getTranslationY() - dstCam.getTranslationY()) < 1e-3F);
      //assert (cml::abs(getTranslationZ() - dstCam.getTranslationZ()) < 1e-3F);

      // source camera coordinate, assuming z = 1
      const cml::CartesianPoint3D<float32> srcCamP(
        (imageX - getIntrinsicCenterX()) * getIntrinsicFocalLengthXInverted(),
        (imageY - getIntrinsicCenterY()) * getIntrinsicFocalLengthYInverted(),
        1.0F);

      // rotate to world (without translation)
      cml::CartesianPoint3D<float32> worldRotP;
      // PRQA S 3223 4
      // date: 2018-13-11, reviewer: Xu Tang, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long as different calls are made with disjoint indices (x(), y(), z() function names).
      RotateCamera2World(
        srcCamP.x(), srcCamP.y(), srcCamP.z(),
        worldRotP.x(), worldRotP.y(), worldRotP.z());

      // rotate to destination (without translation)
      cml::CartesianPoint3D<float32> dstCamP;
      // PRQA S 3223 4
      // date: 2018-13-11, reviewer: Xu Tang, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long as different calls are made with disjoint indices (x(), y(), z() function names).
      dstCam.RotateWorld2Camera(
        worldRotP.x(), worldRotP.y(), worldRotP.z(),
        dstCamP.x(), dstCamP.y(), dstCamP.z());

      // project to destination image
      // PRQA S 3223 4
      // date: 2018-13-11, reviewer: Xu Tang, reason: The access of CartesianPoint3D data via x(), y(), z() is safe here as long as different calls are made with disjoint indices (x(), y(), z() function names).
      dstCam.Camera2Image(
        dstCamP.x(), dstCamP.y(), dstCamP.z(),
        dstImageX, dstImageY);
    }

    /// Row in the image considered as the horizon computed based on the static pitch of the camera.
    /// The camera roll is neglected. Uses the intrinsic camera parameters to project the optical center into
    /// the world, then rotates it according to the static pitch and projects it back onto the image plane.
    /// @return the row in the image considered as the camera horizon
    float32 calcHorizonYImage() const
    {
      return m_intr.fCenterY + m_intr.fFocalY * cml::tan(-m_pose.fPitch);
    }

  protected:

    /// Stores the 6D pose of the camera, that are the 3 rotation angles (roll, pitch, yaw)and the 3D position of the camera in the world coordinate system.
    /// Is initialized by setParams().
    PoseParameters_t m_pose;
    /// Stores the intrinsic pinhole parameters focal length, principal point and distortion coefficients.
    /// Is initialized by setParams().
    MonoCalibrationIntrinsic_t m_intr;

    float32 m_inverseFocalX; ///< Represents the inverse focal length in horizontal / x direction. \f$ inverseFocal_x = \frac{1}{focal_x} \f$. Is initialized by preCalc().
    float32 m_inverseFocalY; ///< Represents the inverse focal length in vertical / y direction. \f$ inverseFocal_y = \frac{1}{focal_y} \f$. Is initialized by preCalc().

    /// Calculates the inverse focal lengths out of the stored focal lengths.
    /// @pre  Initialized focal lengths.
    /// @post Inverse focal lengths are calculated.
    /// @warning If at least one of the stored focal lengths is zero, it is not handled.
    ///          Depending on the target platform it generates an flt-div-by-zero exception.
    /// @sa m_inverseFocalX, m_inverseFocalY
    void preCalc()
    {
      assert(m_intr.fFocalX > std::numeric_limits<float32>::min()); // polyspace RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."
      assert(m_intr.fFocalY > std::numeric_limits<float32>::min()); // polyspace RTE:ASRT [Not a defect: Low] "This assert is there by intention. It is a dynamic test. It is monitored during a SIL test."
      m_inverseFocalX = cct::invert( m_intr.fFocalX );
      m_inverseFocalY = cct::invert( m_intr.fFocalY );
    }

    /// Calculates pose transfrom matrix from given rotations and translations.
    /// @code
    /// Set the pose transformation matrix T defined as:
    ///  T = [A * R| - A * R * t],
    ///  R = Tait–Bryan-Z-Y'-X''-MobileFrameAxes-PassiveComposition(zYaw, yPitch, xRoll) = R(rotXroll)' * R(rotYpitch)' * R(rotZyaw)'
    ///  t = [t_x ; t_y ; t_z] = Position of the camera in the vehicle coordinate system
    ///  A = Rotation from vehicle to forward looking camera system = [[0 -1 0] ; [0 0 -1] ; [1 0 0]] (A' * A = I)
    ///
    /// This equals:
    ///  - x_camera = A * R * (x_vehicle - t)
    ///  - x_camera = T * [x_vehicle, 1]
    ///
    ///         [ 0  -1   0 ]   [  1      0        0    ]   [ cos(y)   0   -sin(y) ]   [  cos(z)  sin(z)   0 ]
    /// A * R = [ 0   0  -1 ] * [  0    cos(x)   sin(x) ] * [   0      1      0    ] * [ -sin(z)  cos(z)   0 ]
    ///         [ 1   0   0 ]   [  0   -sin(x)   cos(x) ]   [ sin(y)   0    cos(y) ]   [   0       0       1 ]
    ///
    /// Matlab:
    /// =======
    ///
    /// syms sx cx sy cy sz cz tx ty tz
    /// A = [0 -1 0; 0 0 -1; 1 0 0]
    /// Rx=[1 0 0; 0 cx sx; 0 -sx cx]
    /// Ry=[cy 0 -sy; 0 1 0; sy 0 cy]
    /// Rz=[cz sz 0; -sz cz 0; 0 0 1]
    /// t=[tx;ty;tz]
    /// R=Rx*Ry*Rz
    /// T=[A*R -A*R*t]
    /// @endcode
    /// @param[in] rotXroll    The roll angle of the camera. That is the rotation around the world X axis.
    /// @param[in] rotYpitch   The pitch angle of the camera. That is the rotation around the world Y axis.
    /// @param[in] rotZyaw     The yaw angle of the camera. That is the rotation around the world Z axis.
    /// @param[in] transX      The x-position of the camera in the world coordinate system.
    /// @param[in] transY      The y-position of the camera in the world coordinate system.
    /// @param[in] transZ      The z-position of the camera in the world coordinate system.
    void preCalcPoseTransformationMatrix(
      const float32 rotXroll, const float32 rotYpitch, const float32 rotZyaw,
      const float32 transX,   const float32 transY,    const float32 transZ)
    {
      const float32 cZ = cml::cos(rotZyaw);
      const float32 sZ = cml::sin(rotZyaw);
      const float32 cY = cml::cos(rotYpitch);
      const float32 sY = cml::sin(rotYpitch);
      const float32 cX = cml::cos(rotXroll);
      const float32 sX = cml::sin(rotXroll);

      m_pose.sTransform.fA00 = -sX*sY*cZ + cX*sZ;       m_pose.sTransform.fA01 = -sX*sY*sZ - cX*cZ;       m_pose.sTransform.fA02 = -sX*cY;
      m_pose.sTransform.fA10 = -cX*sY*cZ - sX*sZ;       m_pose.sTransform.fA11 = -cX*sY*sZ + sX*cZ;       m_pose.sTransform.fA12 = -cX*cY;
      m_pose.sTransform.fA20 = cY*cZ;                   m_pose.sTransform.fA21 = cY*sZ;                   m_pose.sTransform.fA22 = -sY;

      m_pose.sTransform.fA03 = - m_pose.sTransform.fA00 * transX - m_pose.sTransform.fA01 * transY - m_pose.sTransform.fA02 * transZ;
      m_pose.sTransform.fA13 = - m_pose.sTransform.fA10 * transX - m_pose.sTransform.fA11 * transY - m_pose.sTransform.fA12 * transZ;
      m_pose.sTransform.fA23 = - m_pose.sTransform.fA20 * transX - m_pose.sTransform.fA21 * transY - m_pose.sTransform.fA22 * transZ;
    }
  };

  /// Extends the CMonoCamera to a rectified stereo use case.
  /// In fact it utilizes the CMonoCamera a lot and adds a third image coordinates "disparity" to it. This describes the
  /// horizontal shift between left / and right image plane:
  /// @image html cct_camera_pinhole_projection_stereo.svg "Pinhole projection: Image and camera coordinates with disparity" width=70%
  /// @copydetails cct::CMonoCamera
  class CStereoCamera : public CMonoCamera
  {
  public:

    /// @copydoc CMonoCamera::setParams(const PoseParameters_t&, const MonoCalibrationIntrinsic_t&)
    /// @param[in] stereoBaseline Horizontal distance of the 2 optical axes
    void setParams(const PoseParameters_t& poseParameters, const MonoCalibrationIntrinsic_t& monoCalibrationIntrinsic, const float32 stereoBaseline)
    {
      CMonoCamera::setParams(poseParameters, monoCalibrationIntrinsic);
      m_stereoBaseline = stereoBaseline;

      preCalc();
    }

    /// @copydoc CMonoCamera::setParams(const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32)
    /// @param[in] stereoBaseline Horizontal distance of the 2 optical axes
    void setParams(
      const float32 rotXroll,    const float32 rotYpitch, const float32 rotZyaw,
      const float32 transX,      const float32 transY,    const float32 transZ,
      const float32 intrFocalX,  const float32 intrFocalY,
      const float32 intrCenterX, const float32 intrCenterY,
      const float32 stereoBaseline)
    {
      CMonoCamera::setParams(rotXroll, rotYpitch, rotZyaw, transX, transY, transZ, intrFocalX, intrFocalY, intrCenterX, intrCenterY);
      m_stereoBaseline = stereoBaseline;

      preCalc();
    }

    /// Returns true if camera is up to date with respect to the given parameter set.
    /// It is done by comparing all extrinsic some of the intrinsic parameters given against the internal state as well as the stereo baseline.
    /// @pre  None
    /// @post None
    /// @InOutCorrelation
    /// <p>
    /// See checkCameraUpToDate(const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32) const
    /// @param[in] pose The 6D extrinsic parameter set that defines the 3 rotation and 3 positional coordinates
    /// @param[in] intr The intrinsic pinhole configuration that defines the focal length and the principal point
    /// @param[in] stereoBaseline Horizontal distance of the 2 optical axes
    /// @return True if the difference of all given to all stored pose and intrinsic parameters is less than
    ///         std::numeric_limits<float32>::min(), otherwise false.
    bool checkCameraUpToDate(const PoseParameters_t& pose, const MonoCalibrationIntrinsic_t& intr, const float32 stereoBaseline) const
    {
      return checkCameraUpToDate( pose.fRoll, pose.fPitch, pose.fYaw, pose.fTx, pose.fTy, pose.fTz,
        intr.fFocalX, intr.fFocalY, intr.fCenterX, intr.fCenterY, stereoBaseline);
    }

    /// Returns true if camera is up to date with respect to the given parameter set.
    /// It is done by comparing all extrinsic some of the intrinsic parameters given against the internal state as well as the stereo baseline.
    /// @pre  None
    /// @post None
    /// @InOutCorrelation
    /// <p>
    /// Calls CMonoCamera::checkCameraUpToDate(const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32, const float32) const
    /// and additionally compares the @a stereoBaseline parameter.
    /// @param[in] rotXroll    The roll angle of the camera. That is the rotation around the world X axis.
    /// @param[in] rotYpitch   The pitch angle of the camera. That is the rotation around the world Y axis.
    /// @param[in] rotZyaw     The yaw angle of the camera. That is the rotation around the world Z axis.
    /// @param[in] transX      The x-position of the camera in the world coordinate system.
    /// @param[in] transY      The y-position of the camera in the world coordinate system.
    /// @param[in] transZ      The z-position of the camera in the world coordinate system.
    /// @param[in] intrFocalX  The horizontal focal length of the pinhole camera model
    /// @param[in] intrFocalY  The vertical focal length of the pinhole camera model
    /// @param[in] intrCenterX The horizontal principal point coordinate
    /// @param[in] intrCenterY The vertical principal point coordinate
    /// @param[in] stereoBaseline Horizontal distance of the 2 optical axes
    /// @return True if the difference of all given to all stored pose and intrinsic parameters is less than
    ///         std::numeric_limits<float32>::min(), otherwise false.
    bool checkCameraUpToDate(
      const float32 rotXroll,    const float32 rotYpitch, const float32 rotZyaw,
      const float32 transX,      const float32 transY,    const float32 transZ,
      const float32 intrFocalX,  const float32 intrFocalY,
      const float32 intrCenterX, const float32 intrCenterY,
      const float32 stereoBaseline) const
    {
      return CMonoCamera::checkCameraUpToDate(rotXroll, rotYpitch, rotZyaw, transX, transY, transZ, intrFocalX, intrFocalY, intrCenterX, intrCenterY)
        &&   (cml::abs(m_stereoBaseline - stereoBaseline) < std::numeric_limits<float32>::min());
    }

    /// @name Parameter getter functions
    /// @{
    float32 getStereoBaseline() const { return m_stereoBaseline; }
    float32 getStereoConstant() const { return m_stereoConstant; }
    /// @}

    /// Transform point in world coordinate system to image coordinate system
    /// Identical to mono version + calculation of disparity
    /// @param[in]  worldX World x-coordinate
    /// @param[in]  worldY World y-coordinate
    /// @param[in]  worldZ World z-coordinate
    /// @param[out] imageX Image x-coordinate of transformed vertex given with (@a worldX, @a worldY, @a worldZ)
    /// @param[out] imageY Image y-coordinate of transformed vertex given with (@a worldX, @a worldY, @a worldZ)
    /// @param[out] disparity Image disparity of transformed vertex given with (@a worldX, @a worldY, @a worldZ)
    /// @return "false" if point in world is behind camera plane, "true" if successful
    bool World2Image(
      const float32 worldX, const float32 worldY, const float32 worldZ,
      float32&      imageX, float32&      imageY, float32&      disparity) const
    {
      bool result = true;

      float32 cameraX;
      float32 cameraY;
      float32 cameraZ;

      World2Camera(worldX, worldY, worldZ, cameraX, cameraY, cameraZ);
      if (cameraZ < std::numeric_limits<float32>::min())
      {
        cameraZ = std::numeric_limits<float32>::min();
        result = false;
      }

      Camera2Image(cameraX, cameraY, cameraZ, imageX, imageY, disparity);

      return result;
    }
    using CMonoCamera::World2Image;

    /// Project point in camera coordinates onto the image plane and calculate its disparity.
    /// @warning @a cameraZ must be positive (avoid projection behind camera) and non-zero
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Transformes the given coordinates @a cameraX, @a cameraY, @a cameraZ into the image coordinate system
    /// by applying the pinhole and stereo mathematics. The resulting coordinates are written to @a imageX, @a imageY and @a disparity.
    /// @f{eqnarray*}{
    /// image_x   &=& \frac{focalLength_x * camera_x}{camera_z} + principalPoint_x \\
    /// image_y   &=& \frac{focalLength_y * camera_y}{camera_z} + principalPoint_y \\
    /// disparity &=& \frac{focalLength_x * stereoBaseLine}{camera_z}
    /// @f}
    /// @sa CMonoCamera::Camera2Image(), CameraZ2Disparity()
    /// @param[in]  cameraX Camera x-coordinate
    /// @param[in]  cameraY Camera y-coordinate
    /// @param[in]  cameraZ Camera z-coordinate
    /// @param[out] imageX    Image x-coordinate of transformed vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    /// @param[out] imageY    Image y-coordinate of transformed vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    /// @param[out] disparity Image disparity of transformed vertex given with (@a cameraX, @a cameraY, @a cameraZ)
    void Camera2Image(
      const float32 cameraX, const float32 cameraY, const float32 cameraZ,
      float32&      imageX,  float32&      imageY,  float32&      disparity) const
    {
      CMonoCamera::Camera2Image(cameraX, cameraY, cameraZ, imageX, imageY);
      const bool result = CameraZ2Disparity(cameraZ, disparity);
      assert(result);
      (void) result;
    }
    // PRQA S 2524 
	// 2020-2-5; uic58113
	// summary < Msg(3:2524) This using declaration is in a header file.>
	// reason  < It's a QACPP Bug, since this using declaration is within the class scope.>
    
    // make the mono variants available
    using CMonoCamera::Camera2Image;

    /// Calculate disparity from z coordinate in camera coordinate system.
    /// @pre  Initialized class instance.
    /// @post None
    /// @InOutCorrelation
    /// Transformes the given coordinates @a cameraZ into the stereo image @a disparity.
    /// @f[
    /// disparity = \frac{focalLength_x * stereoBaseLine}{camera_z}
    /// @f]
    /// @param[in]  cameraZ     camera z coordinate
    /// @param[out] disparity   calculated disparity
    /// @return False if the point in camera coordinates is behind camera plane, true otherwise.
    ///         If the projection fails, the output (@a disparity) will not be calculated nor initialized!
    bool CameraZ2Disparity(float32 cameraZ, float32& disparity) const
    {
      bool result = false;

      if (cml::abs(cameraZ) > std::numeric_limits<float32>::min())
      {
        disparity = (m_stereoConstant * cct::invert(cameraZ));
        result    = true;
      }
      return result;
    }

    /// Calculate disparity variance from variance of z coordinate in camera coordinate system.
    /// @param[in]  cameraZ       camera z coordinate
    /// @param[in]  cameraZVar    camera z variance
    /// @param[out] disparityVar  calculated disparity
    /// @return False if the point in camera coordinates is behind camera plane, true otherwise.
    ///         If the projection fails, the output (@a disparityVar) will not be calculated nor initialized!
    bool CameraZ2DisparityVar(float32 cameraZ, const float32 cameraZVar, float32& disparityVar) const
    {
      bool result = false;

      if (cml::abs(cameraZ) > std::numeric_limits<float32>::min())
      {
        const float32 cameraZInv = cct::invert(cameraZ);
        disparityVar = cml::pow<2>(m_stereoConstant * cml::pow<2>(cameraZInv)) * cameraZVar;
        result = true;
      }
      return result;
    }

    /// Calculates camera z coordinate from disparity.
    /// @param[in]  disparity  disparity to calculate camera z for.
    /// @param[out] cameraZ    calculated camera z coordinate.
    /// @return False if the disparity is negative or zero and therefore the point in camera coordinates would be behind the camera plane, true otherwise.
    ///         If the projection fails, the output (@a cameraZ) will not be calculated nor initialized!
    bool Disparity2CameraZ(float32 disparity, float32& cameraZ) const
    {
      bool result = false;

      if (disparity > std::numeric_limits<float32>::min())
      {
        cameraZ = (m_stereoConstant * cct::invert(disparity));
        result  = true;
      }
      return result;
    }

    /// Transform point in image coordinate system to camera coordinate system
    /// by specifying the stereo disparity.
    /// @warning Disparity must be positive (avoid projection behind camera)
    /// @sa Disparity2CameraZ(), CMonoCamera::Image2CameraKnownCameraZ()
    /// @param[in]  imageX    Image x-coordinate
    /// @param[in]  imageY    Image y-coordinate
    /// @param[in]  disparity Image stereo disparity
    /// @param[out] cameraX   Camera x-coordinate
    /// @param[out] cameraY   Camera y-coordinate
    /// @param[out] cameraZ   Camera z-coordinate
    void Image2CameraFromDisparity(
      const float32 imageX,  const float32 imageY,  const float32 disparity,
      float32&      cameraX, float32&      cameraY, float32&      cameraZ) const
    {
      const bool result = Disparity2CameraZ(disparity, cameraZ);
      assert(result);
      (void) result;
      CMonoCamera::Image2CameraKnownCameraZ(imageX, imageY, cameraX, cameraY, cameraZ);
    }

    /// Transform point in image coordinate system to world coordinate system
    /// by specifying the stereo disparity.
    /// @warning Disparity must be positive (avoid projection behind camera)
    /// @sa Image2CameraFromDisparity(), CMonoCamera::Camera2World()
    /// @param[in]  imageX    Image x-coordinate
    /// @param[in]  imageY    Image y-coordinate
    /// @param[in]  disparity Image stereo disparity
    /// @param[out] worldX   Camera x-coordinate
    /// @param[out] worldY   Camera y-coordinate
    /// @param[out] worldZ   Camera z-coordinate
    void Image2WorldFromDisparity(
      const float32 imageX, const float32 imageY, const float32 disparity,
      float32&      worldX, float32&      worldY, float32&      worldZ) const
    {
      float32 cameraX;
      float32 cameraY;
      float32 cameraZ;

      Image2CameraFromDisparity(imageX, imageY, disparity, cameraX, cameraY, cameraZ);

      CMonoCamera::Camera2World(cameraX, cameraY, cameraZ, worldX, worldY, worldZ);
    }

  protected:

    /// Horizontal distance between left and right optical axis of the rectified stereo system in meters.
    /// Initialized by setParams().
    float32 m_stereoBaseline;
    /// Precalculated stereo constant: \f$ stereoConstant = focalLength_x * stereoBaseLine \f$.
    /// Initialized in preCalc().
    float32 m_stereoConstant;

    /// @copydoc CMonoCamera::preCalc()
    /// <p>
    /// Additionally calculates the stereo constant.
    /// @sa m_stereoConstant, CMonoCamera::preCalc()
    void preCalc()
    {
      CMonoCamera::preCalc();
      m_stereoConstant = m_stereoBaseline * getIntrinsicFocalLengthX();
    }
  };
}

#endif // cct_camera_h__
