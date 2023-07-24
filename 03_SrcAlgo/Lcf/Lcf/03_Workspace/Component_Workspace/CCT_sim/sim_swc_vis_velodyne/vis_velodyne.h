#ifndef visVelodyne_h__
#define visVelodyne_h__

// sim
#include "sim_rendercontext_ifc.h"

// ogl
#include <gl/gl.h>
#include <gl/glu.h>
#pragma comment  (lib, "opengl32.lib")
#pragma comment  (lib, "glu32.lib")

// rte
#include "glob_type.h"

// stl
#include <vector>

#include "velodyne_processor/velodynePointCloudHDL64EPointCloud.h"

class CVisVelodyne
{
public:
  enum ColorMode
  {    
    CM_INTENSITY               = 0x01, ///< Color hue defined by intensityvalue
    CM_CAMERA_DISTANCE         = 0x02, ///< Color hue defined by distance from camera
    CM_AUTOSAR_HEIGHT          = 0x03, ///< Color hue defined by autosar height (z) coordinate    
    CM_VELO_TIMESTAMP          = 0x04, ///< Color hue defined by velodyne point timestamp 
  };

  CVisVelodyne();
  ~CVisVelodyne();

  void setParameters (    
    const int pointSize,
    const int pointSubsamplingStep,    
    const ColorMode& colorMode);

  void setColorMode(const ColorMode colorMode)
  {
    setParameters(      
      m_pointSize,
      m_pointSubsample,      
      colorMode);
  }

  void setPointSize(const int pointSize)
  {
    setParameters(      
      pointSize,
      m_pointSubsample,      
      m_colorMode);
  }

  void setSubSampling(const int pointSubSample)
  {
    setParameters(      
      m_pointSize,
      pointSubSample,      
      m_colorMode);
  }

  void setVelodyneData( const VelodyneHDL64EPointCloud_t* pMeasPointList );  
  void prepareData3D();
  void resetData();
  
  void renderVelodyne3D      (const ISimRenderContext& ctx);
  
  ColorMode getColorMode()               const { return m_colorMode;          }
  int getPointSize()                     const { return m_pointSize; }
  int getSubSampling()                   const { return m_pointSubsample; }

private:  
  static const float COLOR_DISTANCE_MAX_INV;   ///< Blue point for distance coloring 1 / distance [m]
  static const float COLOR_AUTOSAR_HEIGHT_MIN; ///< Blue point for height coloring [m]
  static const float COLOR_AUTOSAR_HEIGHT_MAX; ///< Red point for height coloring [m]  
  static const float FLOAT_TO_S16Q7;           ///< Multiplicative factor to convert from float to s16q7 fixpoint 
  static const float S16Q7_TO_FLOAT;           ///< Multiplicative factor to convert from s16q7 fixpoint to float
  
  struct MeasurementPoint3D
  {
    float x;
    float y;
    float z;

    unsigned char r;
    unsigned char g;
    unsigned char b;
  };

  struct PlaneEQ
  {
    double a;
    double b;
    double c;
    double d;
  };

  const VelodyneHDL64EPointCloud_t*       m_pMeasPointList;

  int   m_pointSize;
  int   m_pointSubsample;
  
  ColorMode m_colorMode;

  typedef std::vector<MeasurementPoint3D> meas_point_vector;
  meas_point_vector m_measPoints;
  
  boolean m_dataIsNew;

  static unsigned char clampGray (const long& gray)
  {
    if (gray < 0)
    {
      return 0;
    }
    else if (gray > 255)
    {
      return 255;
    }
    else
    {
      return static_cast<unsigned char>(gray);
    }
  }    
};
#endif // visVelodyne_h__