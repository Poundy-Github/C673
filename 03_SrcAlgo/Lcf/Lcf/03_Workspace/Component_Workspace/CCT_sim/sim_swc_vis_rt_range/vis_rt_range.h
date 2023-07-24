#ifndef vis_rt_range__h__
#define vis_rt_range__h__

// sim
#include "sim_rendercontext_ifc.h"
#include "scopeLock.h"

// ogl
#include <gl/gl.h>
#include <gl/glu.h>
#pragma comment  (lib, "opengl32.lib")
#pragma comment  (lib, "glu32.lib")

// algo
#include "algo_type.h"

// cml
#include "cml_ext_cpp.h"

// stl
#include <vector>
#include <limits>
#include <cassert>
#include <sstream>

static const float32 RT_RANGE_MARKER_LEVEL    = -3.0F;
static const float32 RT_RANGE_MARKER_HEIGHT   =  6.0F;
static const float32 RT_RANGE_POINT_SIZE      =  5.0F;

static const float32 RT_RANGE_TIMESHIFT_MIN    = -600.0F;
static const float32 RT_RANGE_TIMESHIFT_STEP   =   60.0F;
static const float32 RT_RANGE_FRAME_RATE_DIV_2 =   30.0F;

static const uint16  RT_RANGE_PLOT_HEIGHT =   100;

/// This class provides the actual visualization, data storage and algorithms
/// to perform rudimentary operations, e.g. time shift, on the data.
class CVisRtRange
{
public: 

  CVisRtRange();

  ~CVisRtRange();

  /// Data container storing the frame-wise information 
  /// of a RT-range point
  struct RtRangePoint
  {
    uint8   id;         ///< Object ID, currently limited to 1 and 2

    float32 longPos;    ///< longitudinal position
    float32 lateralPos; ///< lateral position
    float32 longVel;    ///< longitudinal velocity
    float32 lateralVel; ///< lateral velocity

    // the time stamp associated with the frame
    // this might be any time since only the time shift
    // relative to it will be computed.
    float32 timestamp;  ///< timestamp on which RT-range data and video image was stored

    /// The timeshift can be determined via autocorrelation.
    /// To do so, two signals are required. One from the RT-range data source
    /// and one from the camera itself
    float32 signalMeas;   ///< e.g. velocity derived from vehDyn
    float32 signalRTRange;///< e.g. velocity derived from RT Range of the hunter
  }; 

  /// Storage of the range points of a frame
  typedef std::vector<RtRangePoint> RtRangePoints_t;

  /// Stores the provided data into member variables
  /// @param[in]       rtRangePoints: vector of RtRangePoint
  /// @param[in]       vehPar: vehicle parameters for the correct visualization
  void addRTRangeData(const RtRangePoints_t& rtRangePoints);

  /// Resets the member variables m_rtRangePoints and m_vehPar
  void resetData();

  /// Draws the visualization into the render context 
  /// @param[in]       ctx: the render context
  void renderRTRangeData(const ISimRenderContext& ctx);

  /// Draws the visualization into the render context 
  /// @param[in]       ctx: the render context
  void renderRTRangeCockpit(const ISimRenderContext& ctx) const;

  /// Returns the currently set time shift
  /// @return timeshift
  const float32& getTimeShift()  const { return m_timeshift; }

  /// Returns the currently set flag indicating whether the Y axis shall be inverted
  /// @return timeshift
  const uint8& getInvertY()    const { return m_invertY; }

  /// Returns the currently set value providing the translation distance along the x axis
  /// @return timeshift
  const float32& getTranslateX() const { return m_translateX; }

  /// Returns the currently assigned flag indicating whether the legend of the visualization shall be displayed or not
  /// @return timeshift
  const uint8& getDrawOptionShowLegend() const { return m_drawOptionShowLegend; }

  /// Sets the time shift of the visualization
  /// @param[in] timeshift  the time shift
  void setTimeShift(const float32 timeshift) { m_timeshift = cml::min(0.0F, timeshift); }

  /// Sets the boolean flag indicating whether the z axsi shall be inverted or not
  /// @param[in] invertY  boolean Y needs to be inverted flag  
  void setInvertY(const uint8 invertY) { m_invertY = invertY; }

  /// Set the translation distance of the x axis
  /// @param[in] translateX  distance in meter along which the rt range data will be translated
  void setTranslateX(const float32 translateX){ m_translateX = translateX; }
  void CVisRtRange::setAutoCorrelationSignalMeasScale(float32 autoCorrelationSignalMeasScale)
  { 
    m_autoCorrelationSignalMeasScale = autoCorrelationSignalMeasScale; 
  }

  /// Sets the boolean flag to display the legend
  /// @param[in] drawOptionShowLegend flag to turn the legend in the visualization on or off  
  void setDrawOptionShowLegend(const uint8 drawOptionShowLegend) {m_drawOptionShowLegend = drawOptionShowLegend; }

  /// Algorithm to calculate the auto correlation between the signal of the camera and the rt range data
  /// In case the closest point to a value was already used, it is discarded.
  /// The autocorrelation is normalized by the number of samples contributing to the quantity.
  /// Performs a buffer check before evaluation. 
  float32 calcAutoCorrelation();

private:

  /// Method to find the closed index in the buffer which matches the timestamp corrected by the timeshift
  /// Returns -1 in case the offset is larger than half the frame rate
  /// @param[in]  shiftedTimestampToMatch The timestamp to be aligned to
  /// @param[out] idx       Index of the vector element
  /// @param[out] offset    Offset of the vector element to the given timestamp
  /// @return index in the range buffer closed to the timestamp - timeshift
  void calcClosedBufferIdx(const float32& shiftedTimestampToMatch, sint16& idx, float32& offset) const;

  /// Checks the buffer for inconsistent timestamp occurring due to relocating the time slider of MTS
  void checkBufferConsistency();

  // Variable to set the capacity of the buffer 
  static const uint16 BUFFER_LENGTH = 100;

  /// Type definition of the buffer to store the camera and rt range data. 
  /// Each element contains a vector of two points
  typedef std::vector<RtRangePoints_t>  RtRangePointsBuffer_t;
  
  // The instantiation of the data buffer
  RtRangePointsBuffer_t  m_rtRangePointsBuffer;

  // Local parameter describing the individual properties of 
  // rt-range data in relation to the camera data. 
  float32  m_timeshift; 
  uint8    m_invertY;   
  float32  m_translateX;
  float32  m_autoCorrelationSignalMeasScale;

  uint8    m_drawOptionShowLegend;
  
  CRITICAL_SECTION m_csData;  

};
#endif // vis_rt_range__h__