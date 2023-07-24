#include "stdafx.h"
#include "vis_velodyne.h"

// set
#include "sim_gl_tools.h"

// stl
#include <limits>
#include <cassert>
#include <sstream>

const float CVisVelodyne::COLOR_DISTANCE_MAX_INV      = 1.0F / 50.0F;  
const float CVisVelodyne::COLOR_AUTOSAR_HEIGHT_MIN    = 0.0F;
const float CVisVelodyne::COLOR_AUTOSAR_HEIGHT_MAX    = 2.0F;
const float CVisVelodyne::FLOAT_TO_S16Q7              = 128.0F;
const float CVisVelodyne::S16Q7_TO_FLOAT              = 1.0F / FLOAT_TO_S16Q7;

CVisVelodyne::CVisVelodyne()
: m_pointSize(2)
, m_pointSubsample(1)
, m_dataIsNew(true)
, m_pMeasPointList(NULL)
, m_colorMode(CM_INTENSITY)
{

}

CVisVelodyne::~CVisVelodyne()
{ 
  m_pMeasPointList = NULL;
}

void CVisVelodyne::setParameters(const int pointSize,
                                 const int pointSubsamplingStep,
                                 const ColorMode& colorMode)
{  
  m_pointSize = pointSize;

  if (pointSubsamplingStep != m_pointSubsample)
  {
    m_pointSubsample = pointSubsamplingStep;
    m_dataIsNew    = true;
  }

  if (colorMode != m_colorMode)
  {
    m_colorMode = colorMode;
    m_dataIsNew = true;
  }
}

void CVisVelodyne::setVelodyneData(const VelodyneHDL64EPointCloud_t* pMeasPointList )
{
  // only store pointer to data (which must be locked)
  m_pMeasPointList = pMeasPointList;
  m_dataIsNew = true;
}

void CVisVelodyne::renderVelodyne3D(const ISimRenderContext& ctx)
{
  ctx; 

  if (m_dataIsNew)
  {
    // calculate point vector
    prepareData3D();
    m_dataIsNew = false;
  }

  glPushMatrix();
  
  glScalef(S16Q7_TO_FLOAT, S16Q7_TO_FLOAT, S16Q7_TO_FLOAT);
  glPointSize(float(m_pointSize));

  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);

  if (m_measPoints.size() > 0)
  {
    glVertexPointer (3, GL_FLOAT,         sizeof(MeasurementPoint3D), &m_measPoints[0]);
    glColorPointer  (3, GL_UNSIGNED_BYTE, sizeof(MeasurementPoint3D), &m_measPoints[0].r);
    glDrawArrays (GL_POINTS, 0, static_cast<GLsizei>(m_measPoints.size()));
  }

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

  glPopMatrix();
 
  // status infos
  IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", 8);

  set::gl::beginViewPortPerspective();
  {
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    const double h = font.GetTextHeight("X");
    double y = 5 + h;

    font.BeginRender();

    if (NULL == m_pMeasPointList)
    {
      std::stringstream s;
      s << "error: point list is null. can't display point cloud.";
      const double w = set::gl::calcTextWidth(font, s.str());

      font.SetTextColor(1, 0, 0);
      font.RenderTextf(viewport[2] - w - 5, y, 0, s.str().c_str());
      y += h;
    }
    else if (!m_pMeasPointList->s_signalHeader.b_signalValid)
    {
      std::stringstream s;
      s << "error: signal state is invalid. can't display point cloud.";
      const double w = set::gl::calcTextWidth(font, s.str());

      font.SetTextColor(1, 0, 0);
      font.RenderTextf(viewport[2] - w - 5, y, 0, s.str().c_str());
      y += h;
    }    
    else if (VELODYNE_PROCESSOR_INTERFACE_VERSION != m_pMeasPointList->s_signalHeader.ui_versionNumber)
    {
      std::stringstream s;
      s << "error: velodyne signal version is incompatible. can't display point cloud.";
      const double w = set::gl::calcTextWidth(font, s.str());

      font.SetTextColor(1, 0, 0);
      font.RenderTextf(viewport[2] - w - 5, y, 0, s.str().c_str());
      y += h;
    }    

    font.EndRender();
  }
  set::gl::endViewPortPerspective();
}

void CVisVelodyne::prepareData3D()
{
  m_measPoints.clear();

  if (NULL == m_pMeasPointList || !m_pMeasPointList->s_signalHeader.b_signalValid || (VELODYNE_PROCESSOR_INTERFACE_VERSION != m_pMeasPointList->s_signalHeader.ui_versionNumber))
  {
    // preconditions not met, no point cloud
    return;
  }

  // convert coloring parameters from float to fixpoint 
  static const float COLOR_AUTOSAR_HEIGHT_MIN_S16Q7 = COLOR_AUTOSAR_HEIGHT_MIN * FLOAT_TO_S16Q7;
  static const float COLOR_AUTOSAR_HEIGHT_MAX_S16Q7 = COLOR_AUTOSAR_HEIGHT_MAX * FLOAT_TO_S16Q7;
  static const float COLOR_DISTANCE_MAX_INV_S16Q7   = COLOR_DISTANCE_MAX_INV   / FLOAT_TO_S16Q7;

  // setup sub sampling  
  const uint32 subSampling = std::max<uint32>(1, std::min<uint32>(m_pointSubsample, 512));  

  // prepare point buffer
  const uint32 numPoints = m_pMeasPointList->ui_numValidPoints;

  m_measPoints.reserve(numPoints);

  const uint32 lastPointRelTimestamp = m_pMeasPointList->ui_relativeTimestampMicroSeconds[numPoints-1];  

  for (uint32 i = 0; i < numPoints; i += subSampling)
  {               
    MeasurementPoint3D currentPoint;

    currentPoint.x = static_cast<float32>(m_pMeasPointList->s16q7_X[i]);
    currentPoint.y = static_cast<float32>(m_pMeasPointList->s16q7_Y[i]);
    currentPoint.z = static_cast<float32>(m_pMeasPointList->s16q7_Z[i]);

    if(CM_INTENSITY == m_colorMode)
    {
      currentPoint.r = (unsigned char)m_pMeasPointList->uc_intensity[i];
      currentPoint.g = (unsigned char)m_pMeasPointList->uc_intensity[i];
      currentPoint.b = (unsigned char)m_pMeasPointList->uc_intensity[i];
    }
    else
    {            
      float32 hue;
      switch (m_colorMode)
      {      
      case CM_CAMERA_DISTANCE:
        {          
          const float32 absDist = std::sqrt(currentPoint.x * currentPoint.x  + currentPoint.y * currentPoint.y);
          hue = std::max<float>(0.0F, std::min<float>(absDist * COLOR_DISTANCE_MAX_INV_S16Q7, 1.0F)) * (4.0F/6.0F);          
        }
        break;

      case CM_AUTOSAR_HEIGHT:
        {
          const float32 height = currentPoint.z;
          hue = (1.0F - std::max<float>(COLOR_AUTOSAR_HEIGHT_MIN_S16Q7, std::min<float>(height, COLOR_AUTOSAR_HEIGHT_MAX_S16Q7)) / COLOR_AUTOSAR_HEIGHT_MAX_S16Q7) * (4.0F/6.0F);
        }
        break;      

      case CM_VELO_TIMESTAMP:
        {
          const uint32 relTimestamp = m_pMeasPointList->ui_relativeTimestampMicroSeconds[i];
          hue = static_cast<float32>(relTimestamp) / static_cast<float32>(lastPointRelTimestamp) * (4.0F/6.0F);            
        }
        break;      

      default:
        hue = 0.0F;
        break;
      }

      // set the points color
      float r;
      float g;
      float b;
      set::gl::hsv2rgb(hue, 1.0F, 1.0F, r, g, b);

      currentPoint.r = static_cast<unsigned char>((r * 255.0F) + 0.5F);
      currentPoint.g = static_cast<unsigned char>((g * 255.0F) + 0.5F);
      currentPoint.b = static_cast<unsigned char>((b * 255.0F) + 0.5F);
    }



    // add it to the point list
    m_measPoints.push_back(currentPoint);    
  }
}


void CVisVelodyne::resetData()
{  
  m_pMeasPointList = NULL;
  m_dataIsNew = true;
}
