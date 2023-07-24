#include "stdafx.h"
#include "vis_rt_range.h"
#include "sim_gl_tools.h"

#include <cstring>
#include <iostream>
CVisRtRange::CVisRtRange()
: m_timeshift(-50.0F)
, m_invertY(0)
, m_translateX(0.0F)
, m_drawOptionShowLegend(1)
//, m_rtRangePointsBuffer(BUFFER_LENGTH)
{
  ::InitializeCriticalSection(&m_csData); 
}

CVisRtRange::~CVisRtRange()
{
  resetData();
  ::DeleteCriticalSection(&m_csData);
}

void CVisRtRange::addRTRangeData(const RtRangePoints_t& rtRangePoints)
{
  ScopeLock lock(m_csData);

  if(m_rtRangePointsBuffer.size() == BUFFER_LENGTH)
  {
    m_rtRangePointsBuffer.erase(m_rtRangePointsBuffer.begin());
  }
  m_rtRangePointsBuffer.push_back(rtRangePoints);
}

void CVisRtRange::renderRTRangeData(const ISimRenderContext& ctx) 
{
  if(m_drawOptionShowLegend)
  {
    renderRTRangeCockpit(ctx);
  }

  ScopeLock lock(m_csData);

  if(m_rtRangePointsBuffer.size() > 0)
  {

    // Go back in time and find best matching RT range data
    float32 signalTimeMax =  m_rtRangePointsBuffer.rbegin()->front().timestamp;
    sint16  shiftedFrameIdx;
    float32 offset;
    calcClosedBufferIdx(signalTimeMax + m_timeshift, shiftedFrameIdx, offset); 

    if(shiftedFrameIdx != -1)
    {
      glPointSize(RT_RANGE_POINT_SIZE);  

      for(RtRangePoints_t::const_iterator it = m_rtRangePointsBuffer.at(shiftedFrameIdx).begin(); it!=m_rtRangePointsBuffer.at(shiftedFrameIdx).end(); ++it)
      {
        switch (it->id)
        {
        case 1:
          glColor4f(1.0F, 0.0F, 0.0F, 1.0F); 
          break;
        case 2:
          glColor4f(1.0F, 1.0F, 0.0F, 1.0F); 
          break;
        default:
          glColor4f(1.0F, 1.0F, 1.0F, 1.0F); 
        }

        // LABEL <A>
        // RT-Range point of reference is the front bumper or the rear axle, depending on rec
        // Scaling might be necessary
        const float32 autosar_x =  (it->longPos)/1000 + m_translateX;
        ///const float32 autosar_x =  (it->longPos)/1000 - m_vehPar.VehParAdd.OverhangFront ;
        //const float32 autosar_x =  (it->longPos )/1000 + m_vehPar.VehParMain.WheelBase;

        // RT-Range y-axis points right in some recordings
        const float32 autosar_y = (m_invertY?-1:1)* (it->lateralPos)/1000;

        glBegin(GL_TRIANGLES);            
        glVertex3f(autosar_x-0.25f, autosar_y,       RT_RANGE_MARKER_LEVEL);
        glVertex3f(autosar_x+0.25f, autosar_y-0.25f, RT_RANGE_MARKER_LEVEL);
        glVertex3f(autosar_x+0.25f, autosar_y+0.25f, RT_RANGE_MARKER_LEVEL);
        glEnd();   

        glBegin(GL_TRIANGLES);            
        glVertex3f(autosar_x-0.25f, autosar_y,       RT_RANGE_MARKER_LEVEL+RT_RANGE_MARKER_HEIGHT/2);
        glVertex3f(autosar_x+0.25f, autosar_y-0.25f, RT_RANGE_MARKER_LEVEL+RT_RANGE_MARKER_HEIGHT/2);
        glVertex3f(autosar_x+0.25f, autosar_y+0.25f, RT_RANGE_MARKER_LEVEL+RT_RANGE_MARKER_HEIGHT/2);
        glEnd();  

        glBegin(GL_TRIANGLES);            
        glVertex3f(autosar_x-0.25f, autosar_y,       RT_RANGE_MARKER_LEVEL+RT_RANGE_MARKER_HEIGHT);
        glVertex3f(autosar_x+0.25f, autosar_y-0.25f, RT_RANGE_MARKER_LEVEL+RT_RANGE_MARKER_HEIGHT);
        glVertex3f(autosar_x+0.25f, autosar_y+0.25f, RT_RANGE_MARKER_LEVEL+RT_RANGE_MARKER_HEIGHT);
        glEnd(); 

        glBegin(GL_LINES);    
        glVertex3f(autosar_x, autosar_y, RT_RANGE_MARKER_LEVEL);
        glVertex3f(autosar_x, autosar_y, RT_RANGE_MARKER_LEVEL+RT_RANGE_MARKER_HEIGHT);
        glEnd();   

        IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", 9);

        glPushMatrix();
        {
          glPointSize(3);
          glLineWidth(1);

          glPushMatrix();
          {
            const float objX = autosar_x;
            const float objY = autosar_y;
            const float objZ = RT_RANGE_MARKER_LEVEL-RT_RANGE_MARKER_HEIGHT;

            glColor4f(1.0F,0.0F,0.0F,1.0F);
            font.SetTextColor(1.0F,0.0F,0.0F);

            glTranslatef(objX, objY, objZ);

            font.BeginRender2D();
            font.RenderTextf(0.0F, 0.0F, 0.0F, "vx:%0.2f:vy:%0.2f", it->longVel, it->lateralVel);
            font.EndRender2D();
          }
          glPopMatrix();
        }
        glPopMatrix();

      } // for RtRangePoints_t
    } // if shiftedFrame != -1
  } // size > 0
}


void CVisRtRange::renderRTRangeCockpit(const ISimRenderContext& ctx) const
{
  ctx;
  // Renders current settings:
  // +- Y
  // Translation
  // Time Shift
  // Plot of last Second Velocity
  set::gl::beginViewPortPerspective();
  {
    IGDVFont& font = ctx.GetWindow().GetFontInterface("Arial", 9);
    
    font.SetTextColor(1.0F, 0.671F, 0.0F);

    // setup viewport perspective
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    std::stringstream header;
    std::stringstream info;
    
    header << "Time shift (ms):  " << std::endl;
    info   << m_timeshift    << std::endl;
    
    header << "Translate X (m):  "<< std::endl;
    info   << m_translateX << std::endl;

    header << "Invert Y:  "<< std::endl;
    switch(m_invertY)
    {
      case 0:
        info   << "Y_NEW =  Y" << std::endl;
        break;
      default:
        info   << "Y_NEW = -Y" << std::endl;
        break;
    }

    // Nice to have in order to check whether the signal is available
    header << "Timestamp (ms):  "<< std::endl;
    if(m_rtRangePointsBuffer.size() > 0)
    {
      info   << m_rtRangePointsBuffer.back().front().timestamp << std::endl;
    }
    else
    {
      info   << "n/a" << std::endl;
    }

    header << "Buffer size:  ";
    info   << static_cast<uint16>(m_rtRangePointsBuffer.size());

    const GLint headerWidth = static_cast<GLint>(set::gl::calcTextWidth (font, header.str()));
    const GLint infoWidth   = static_cast<GLint>(set::gl::calcTextWidth (font, info.str()  ));
    const GLint infoHeight  = static_cast<GLint>(set::gl::calcTextHeight(font, info.str()  ));

    static const GLint BOX_MARGIN  = 5;

    const GLint headerLeft = 5;
    const GLint infoLeft   = headerLeft + headerWidth;
    const GLint infoRight  = infoLeft + infoWidth;

    const GLint top    = 5;
    const GLint bottom = top + infoHeight ;

    // draw dark background
    glPushAttrib(GL_COLOR_BUFFER_BIT);
    {
      // transparency setup
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_BLEND);

      glColor4f(0, 0, 0, 0.60F);
      glBegin(GL_QUADS);
      {
        glVertex2i(headerLeft - BOX_MARGIN, viewport[3] - (top    - BOX_MARGIN));
        glVertex2i(infoRight  + BOX_MARGIN, viewport[3] - (top    - BOX_MARGIN));
        glVertex2i(infoRight  + BOX_MARGIN, viewport[3] - (bottom + BOX_MARGIN));
        glVertex2i(headerLeft - BOX_MARGIN, viewport[3] - (bottom + BOX_MARGIN));
      }
      glEnd();
    }
    glPopAttrib();

    // draw text
    font.BeginRender();
    {
      font.RenderTextf(headerLeft, viewport[3] - top, 0, header.str().c_str());
      font.RenderTextf(infoLeft,   viewport[3] - top, 0, info.str().c_str());
      
    }
    font.EndRender();

    // Plot pixel-wise the velocities
    if(m_rtRangePointsBuffer.size() > 0)
    {
      float32 signalValMax = std::numeric_limits<float32>::min();
      float32 signalValMin = std::numeric_limits<float32>::max();
      float32 signalTimeMax =  m_rtRangePointsBuffer.rbegin()->front().timestamp;
      for(RtRangePointsBuffer_t::const_iterator it = m_rtRangePointsBuffer.begin(); it!=m_rtRangePointsBuffer.end(); ++it)
      {
        for(RtRangePoints_t::const_iterator jt = it->begin(); jt!=it->end(); ++jt)
        {
          signalValMin = cml::min(signalValMin, jt->signalMeas*m_autoCorrelationSignalMeasScale);
          signalValMin = cml::min(signalValMin, jt->signalRTRange);
          signalValMax = cml::max(signalValMax, jt->signalMeas*m_autoCorrelationSignalMeasScale);
          signalValMax = cml::max(signalValMax, jt->signalRTRange);
        }        
      }
      if(signalValMax-signalValMin < 1)
      {
        signalValMax = signalValMin + 1; 
      }

      const GLint leftBorder = BOX_MARGIN;
      const GLint topBorder  = viewport[3] - top - infoHeight - BOX_MARGIN;
      const GLint height     = RT_RANGE_PLOT_HEIGHT;
      GLint xVal             = 0;

      sint16 idx;
      sint16  maximalShiftIdx;
      float32 offset;
      calcClosedBufferIdx(signalTimeMax + RT_RANGE_TIMESHIFT_MIN, maximalShiftIdx, offset);
      
      for(RtRangePointsBuffer_t::const_iterator it = m_rtRangePointsBuffer.begin(); it!=m_rtRangePointsBuffer.end(); ++it)
      {

        float32 valMeas    = (it->front().signalMeas*m_autoCorrelationSignalMeasScale-signalValMin)/(signalValMax-signalValMin)*height;
        float32 valRTRange = (it->front().signalRTRange-signalValMin)/(signalValMax-signalValMin)*height;
        glPointSize(2);
        glLineWidth(1);
        // The camera data
        glColor4f(1, 0, 1, 1);
        glBegin(GL_POINTS);
        {
          glVertex2i(xVal+leftBorder, topBorder-height+static_cast<GLint>(valMeas));
        }
        glEnd();
        // The RT Range data
        glColor4f(0, 1, 0, 1);
        glBegin(GL_POINTS);
        {
          glVertex2i(xVal+leftBorder, topBorder-height+static_cast<GLint>(valRTRange));
        }
        glEnd();
        // Shifted the RT Range data, i.e. move old rt range data forward in time
        calcClosedBufferIdx(it->front().timestamp - m_timeshift, idx, offset);
        if(idx != -1)
        {
          glColor4f(1.0F, 0.671F, 0.0F, 1);
          glBegin(GL_POINTS);
          {
            glVertex2i(idx+leftBorder, topBorder-height+static_cast<GLint>(valRTRange));
          }
          glEnd();
        }
        if(maximalShiftIdx != -1 && m_rtRangePointsBuffer.at(maximalShiftIdx).front().timestamp == it->front().timestamp)
        {
          glColor4f(1, 1, 1, 1);
          glBegin(GL_POINTS);
          {
            glVertex2i(xVal+leftBorder, topBorder-height);
            glVertex2i(xVal+leftBorder, topBorder);
          }
          glEnd();
        }
        xVal = xVal + 1;
      }
    }// draw plot
  }
  set::gl::endViewPortPerspective();
}

void CVisRtRange::checkBufferConsistency()
{

  std::reverse(m_rtRangePointsBuffer.begin(), m_rtRangePointsBuffer.end());
  float32 lastTimestamp = std::numeric_limits<float32>::max();

  RtRangePointsBuffer_t::iterator it = m_rtRangePointsBuffer.begin();
  while (it != m_rtRangePointsBuffer.end()) {
    if(it->front().timestamp > lastTimestamp) // if the actual timestamp
    {
      it = m_rtRangePointsBuffer.erase(it);
    }
    else
    {
      lastTimestamp = it->front().timestamp; 
      ++it;
    }
  }
  std::reverse(m_rtRangePointsBuffer.begin(), m_rtRangePointsBuffer.end());
}

void CVisRtRange::calcClosedBufferIdx(const float32& shiftedTimestampToMatch, sint16& idx, float32& offset) const
{
  idx    = -1;
  offset = std::numeric_limits<float32>::max();  

  if(m_rtRangePointsBuffer.size() == 0)
  {
    (void) shiftedTimestampToMatch; 
    return;
  }
   
  //iterate from end to begin
  for(idx = static_cast<sint16>(m_rtRangePointsBuffer.size()) - 1; idx >= 0; idx = idx - 1) 
  {
    float32 itemTimestamp = m_rtRangePointsBuffer.at(idx).front().timestamp;
    float32 val_distance = cml::abs( itemTimestamp - shiftedTimestampToMatch);

    if(val_distance < offset)
    {
      offset = val_distance;
    }
    else
    {
      idx = idx + 1; // reverse last decrement
      break;
    }
  }
  idx = cml::max<sint16>(0,idx); // reverse last decrement in case the loop finished
}

float32 CVisRtRange::calcAutoCorrelation()
{  

  uint8 steps = static_cast<uint8>(-std::floor(RT_RANGE_TIMESHIFT_MIN/RT_RANGE_TIMESHIFT_STEP)) + 1;
  // output
  float32 autocorr1Max  = std::numeric_limits<float32>::min();
  float32 timeshift1Max = 0.0F;
  float32 autocorr2Max  = std::numeric_limits<float32>::min();
  float32 timeshift2Max = 0.0F;

  // temporary variables 
  float32 autocorr1;
  float32 autocorr2;
  float32 meanRT;
  float32 meanMS;
  float32 stdRT;
  float32 stdMS;

  float32 timeshift;
  sint16  idx;
  float32 offset;
  std::vector<float32>  RT1Vec;
  std::vector<float32>  MS1Vec;
  std::vector<float32>  RT2Vec;
  std::vector<float32>  MS2Vec;

  for (uint8 i = 0; i < steps; i++) // iterate over timeshift
  { 
    autocorr1 = 0.0F;
    autocorr2 = 0.0F;
    timeshift = RT_RANGE_TIMESHIFT_MIN + static_cast<float32>(i)*RT_RANGE_TIMESHIFT_STEP; 
    RT1Vec.clear();
    MS1Vec.clear();
    RT2Vec.clear();
    MS2Vec.clear();
    
    for(sint16 idx2 = 0; idx2 < static_cast<sint16>(m_rtRangePointsBuffer.size());idx2++)
    {
      calcClosedBufferIdx(m_rtRangePointsBuffer.at(idx2).front().timestamp + timeshift, idx, offset);

      if(offset <= RT_RANGE_TIMESHIFT_STEP/2 && idx >= 0)  
      {
        for(RtRangePoints_t::const_iterator jt = m_rtRangePointsBuffer.at(idx2).begin(); jt!=m_rtRangePointsBuffer.at(idx2).end(); ++jt)
        {
          switch(jt->id)
          {
          case 1:
            if(m_rtRangePointsBuffer.at(idx).front().id == 1)
            {
              MS1Vec.push_back(jt->signalMeas);
              RT1Vec.push_back(m_rtRangePointsBuffer.at(idx).front().signalRTRange);
            }
            else
            {
              MS1Vec.push_back(jt->signalMeas);
              RT1Vec.push_back(m_rtRangePointsBuffer.at(idx).back().signalRTRange); 
            }
            break;
          case 2:
            if(m_rtRangePointsBuffer.at(idx).front().id == 2)
            {
              MS2Vec.push_back(jt->signalMeas);
              RT2Vec.push_back(m_rtRangePointsBuffer.at(idx).front().signalRTRange);              
            }
            else
            {
              MS2Vec.push_back(jt->signalMeas);
              RT2Vec.push_back(m_rtRangePointsBuffer.at(idx).back().signalRTRange); 
            }
            break;
          default:
            break;
          }
        } // for all elements of one frame     
      }
    }// for all buffered points
    // ID 1
    meanRT = 0.0F;
    meanMS = 0.0F;
    for (sint16 idx2 = 0; idx2 < static_cast<sint16>(RT1Vec.size());idx2++)
    {
      meanRT = meanRT + RT1Vec.at(idx2);
      meanMS = meanMS + MS1Vec.at(idx2);
    }
    meanRT = meanRT/(RT1Vec.size());
    meanMS = meanMS/(MS1Vec.size());
    stdRT = 0.0F;
    stdMS = 0.0F;
    for (sint16 idx2 = 0; idx2 < static_cast<sint16>(RT1Vec.size());idx2++)
    {
      stdRT = stdRT + (RT1Vec.at(idx2) - meanRT)*(RT1Vec.at(idx2) - meanRT);
      stdMS = stdMS + (MS1Vec.at(idx2) - meanMS)*(MS1Vec.at(idx2) - meanMS);
    }
    stdRT = cml::sqrt(stdRT/(RT1Vec.size() - 1));
    stdMS = cml::sqrt(stdMS/(MS1Vec.size() - 1));
    autocorr1 = 0.0F;
    for (sint16 idx2 = 0; idx2 < static_cast<sint16>(RT1Vec.size());idx2++)
    {
      autocorr1 = autocorr1 + (RT1Vec.at(idx2) - meanRT)*(MS1Vec.at(idx2) - meanMS); 
    }
    autocorr1 = autocorr1/(stdMS*stdRT*static_cast<float32>(RT1Vec.size()));
    if(autocorr1 > autocorr1Max && RT1Vec.size() > 0){
      autocorr1Max  = autocorr1;
      timeshift1Max = timeshift;
    }

    // ID 2
    meanRT = 0.0F;
    meanMS = 0.0F;
    for (sint16 idx2 = 0; idx2 < static_cast<sint16>(RT2Vec.size());idx2++)
    {
      meanRT = meanRT + RT2Vec.at(idx2);
      meanMS = meanMS + MS2Vec.at(idx2);
    }
    meanRT = meanRT/(RT2Vec.size());
    meanMS = meanMS/(MS2Vec.size());
    stdRT = 0.0F;
    stdMS = 0.0F;
    for (sint16 idx2 = 0; idx2 < static_cast<sint16>(RT2Vec.size());idx2++)
    {
      stdRT = stdRT + (RT2Vec.at(idx2) - meanRT)*(RT2Vec.at(idx2) - meanRT);
      stdMS = stdMS + (MS2Vec.at(idx2) - meanMS)*(MS2Vec.at(idx2) - meanMS);
    }
    stdRT = cml::sqrt(stdRT/(RT2Vec.size() - 1));
    stdMS = cml::sqrt(stdMS/(MS2Vec.size() - 1));
    autocorr2 = 0.0F;
    for (sint16 idx2 = 0; idx2 < static_cast<sint16>(RT2Vec.size());idx2++)
    {
      autocorr2 = autocorr2 + (RT2Vec.at(idx2) - meanRT)*(MS2Vec.at(idx2) - meanMS); 
    }
    autocorr2 = autocorr2/(stdMS*stdRT*static_cast<float32>(RT2Vec.size()));
    if(autocorr2 > autocorr2Max && RT2Vec.size() > 0){
      autocorr2Max  = autocorr2;
      timeshift2Max = timeshift;
    }
  }// for timeshift
  return timeshift1Max;
}

void CVisRtRange::resetData()
{
  ScopeLock lock(m_csData);
  m_rtRangePointsBuffer.clear();
}


