#include "stdafx.h"
#include "resource.h"
#include "sim_swc_vis_rt_range.h"
#include "sim_swc_vis_rt_range_version.h"
#include "sim_renderparam_helper.h"

#include "ctk_tiny_xml.h"

#ifndef _DEBUG
#pragma comment (lib, "ctk_xml.lib")
#else
#pragma comment (lib, "ctk_xmld.lib")
#endif

#include <sstream>

// menu and parameter names
const char* CSimVisRtRange::PN_TIME_SHIFT        = "Time Shift";
const char* CSimVisRtRange::PN_TRANSLATE         = "Translate X";
const char* CSimVisRtRange::PN_INVERTY           = "Invert Y Axis";
const char* CSimVisRtRange::PN_SHOW_LEGEND       = "Show Legend";
const char* CSimVisRtRange::PN_AUTOCORRELATE     = "Autocorrelate Signal";

const char* CSimVisRtRange::CP_CALCULATIONDONE = "CalculationDone";

CSimVisRtRange::CSimVisRtRange()
: CSimSwcDrawBase (10, "__BufferDataID", simI64_t, "__DoStore", "..\\gia_sim\\adapter.dll")
// Receive Ports
, m_rpAbsoluteTimestamp                     ( this, "AbsoluteTimestamp"           , sint64()               )
, m_rpAutoCorrelationSignalMeas             ( this, "AutoCorrelationSignalMeas"   , float32()              )
, m_rpAutoCorrelationSignalRTRange          ( this, "AutoCorrelationSignalRTRange", float32()              )
, m_rpRtRangeForward                        ( this, "RTRangeForward"              , sint32()               )
, m_rpRtRangeLateral                        ( this, "RTRangeLateral"              , sint32()               )
, m_rpRtRangeVelForward                     ( this, "RTRangeVelForward"           , float32()              )
, m_rpRtRangeVelLateral                     ( this, "RTRangeVelLateral"           , float32()              )
, m_rpRtRangeForward2                       ( this, "RTRangeForward2"             , float32()              )
, m_rpRtRangeLateral2                       ( this, "RTRangeLateral2"             , float32()              )
, m_rpRtRangeVelForward2                    ( this, "RTRangeVelForward2"          , float32()              )
, m_rpRtRangeVelLateral2                    ( this, "RTRangeVelLateral2"          , float32()              )
// Draw Ports
, m_dpDrawRtRange                           ( this, "RTRange"       , &CSimVisRtRange::drawRTRange , this , this )
, m_invertYMenuChecked(FALSE)
, m_showLegendMenuChecked(TRUE)
, m_invertYMenuEnabled(TRUE)
, m_showLegendMenuEnabled(TRUE)
{
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "VisRtRange version " << VIS_RT_RANGEALL_SW_MAIN_VER_NO << "." << VIS_RT_RANGEALL_SW_SUB_VER_NO << "." << VIS_RT_RANGEALL_SW_BUG_FIX_LEV << "." << VIS_RT_RANGEALL_SW_BUG_FIX_LEV2;
  dataTxt   << "VisRtRange (VisRtRange Simulation Module)";
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
  AddServerPort("Reset",   Reset,   this);
  AddServerPort("DoStore", DoStore, this);

  // Menu Items for parameter names
  OpenSubmenu(PN_TIME_SHIFT);
  {
    AttachFunctionToMenu("+ 50ms", MenuHandler, this, MA_TIME_SHIFT_INCREASE);
    AttachFunctionToMenu("- 50ms", MenuHandler, this, MA_TIME_SHIFT_DECREASE);
  }
  CloseSubmenu();

  OpenSubmenu(PN_TRANSLATE);
  {
    AttachFunctionToMenu("+ 50cm", MenuHandler, this, MA_TRANSLATE_INCREASE);
    AttachFunctionToMenu("- 50cm", MenuHandler, this, MA_TRANSLATE_DECREASE);
  }
  CloseSubmenu();

  AttachBoolVarToMenu(PN_INVERTY,    m_invertYMenuChecked, m_invertYMenuEnabled, MenuHandler, this, MA_INVERTY);                        
  AttachBoolVarToMenu(PN_SHOW_LEGEND, m_showLegendMenuChecked, m_showLegendMenuEnabled, MenuHandler,this, MA_SHOW_LEGEND);

  AttachFunctionToMenu(PN_AUTOCORRELATE, MenuHandler, this, MA_CALC_AUTOCORRELATION);

  // global parameter will be used for all ctx, whereas local parameters 
  // are only present within one ctx
  float paramValueFloat = static_cast<float>(m_visRtRange.getTimeShift());
  AddGlobalParameter(PN_TIME_SHIFT, simF32_t, &paramValueFloat, sizeof(float));
  paramValueFloat = static_cast<float>(m_visRtRange.getTranslateX());
  AddGlobalParameter(PN_TRANSLATE, simF32_t, &paramValueFloat, sizeof(float));

  long paramValueLong = static_cast<long>(m_visRtRange.getInvertY());
  AddGlobalParameter(PN_INVERTY, simI32_t, &paramValueLong, sizeof(long));
  paramValueLong = static_cast<long>(m_visRtRange.getDrawOptionShowLegend());
  AddGlobalParameter(PN_SHOW_LEGEND, simI32_t, &paramValueLong, sizeof(long));

   // Create client ports
  AddClientPort(CP_CALCULATIONDONE, NULL, 0, PORT_WITH_AUTOCLONE);

  // Create algorithm ports
  setupPorts();
}

void CSimVisRtRange::setupPorts()
{
  // input ports
}

CSimVisRtRange::~CSimVisRtRange()
{
  m_visRtRange.resetData();
}

void CSimVisRtRange::MenuHandler(ISimRenderContext& ctx, const MenuAction action)
{
  switch (action)
  {
  case MA_TIME_SHIFT_INCREASE:
    CSimRenderParamHelper::SetGlobalParamByRef<float>(ctx, PN_TIME_SHIFT, m_visRtRange.getTimeShift() + 50.0F);    
    break;
  case MA_TIME_SHIFT_DECREASE:
    CSimRenderParamHelper::SetGlobalParamByRef<float>(ctx, PN_TIME_SHIFT, m_visRtRange.getTimeShift() - 50.0F);
    break;
  case MA_TRANSLATE_INCREASE:
    CSimRenderParamHelper::SetGlobalParamByRef<float>(ctx, PN_TRANSLATE, m_visRtRange.getTranslateX() + 0.5F);
    break;
  case MA_TRANSLATE_DECREASE:
    CSimRenderParamHelper::SetGlobalParamByRef<float>(ctx, PN_TRANSLATE, m_visRtRange.getTranslateX() - 0.5F);
    break;
  case MA_INVERTY:
    //m_visRtRange.setInvertY(m_visRtRange.getInvertY()?0:1);
    CSimRenderParamHelper::SetGlobalParamByRef<int>(ctx, PN_INVERTY,m_visRtRange.getInvertY()?0:1);
   break;
  case MA_SHOW_LEGEND:
    CSimRenderParamHelper::SetGlobalParamByRef<int>(ctx, PN_SHOW_LEGEND, m_visRtRange.getDrawOptionShowLegend()?0:1);  
    break;
  case MA_CALC_AUTOCORRELATION:
    CSimRenderParamHelper::SetGlobalParamByRef<float>(ctx, PN_TIME_SHIFT, m_visRtRange.calcAutoCorrelation()); 
  }
}

void CSimVisRtRange::drawRTRange(const ISimRenderContext& ctx)
{
  // setup
  setupParams(ctx);
  // locking against DoStore method is done implicitly by SimDrawPort class!
  // draw
  m_visRtRange.renderRTRangeData(ctx);
}

void CSimVisRtRange::setupParams(const ISimRenderContext& ctx)
{
  // setup
  m_visRtRange.setTimeShift(CSimRenderParamHelper::GetGlobalParamByRef(ctx, PN_TIME_SHIFT,m_visRtRange.getTimeShift()));
  m_visRtRange.setTranslateX(CSimRenderParamHelper::GetGlobalParamByRef(ctx, PN_TRANSLATE,m_visRtRange.getTranslateX()));
  m_visRtRange.setInvertY(CSimRenderParamHelper::GetGlobalParamByRef(ctx, PN_INVERTY,m_visRtRange.getInvertY()));
  m_visRtRange.setDrawOptionShowLegend(CSimRenderParamHelper::GetGlobalParamByRef(ctx, PN_SHOW_LEGEND,m_visRtRange.getDrawOptionShowLegend()));
}

void CSimVisRtRange::Reset()
{
  // setting for default values is only done if adapter is available
  FillRPortDefaultValues(DoStore, this);

  // mark RPorts as not dirty
  ResetRPortDirtyFlags(DoStore, this);

  {
    ScopeLock lock(*this);
    m_visRtRange.resetData();

    // re-read ini file
    readIniFile();
  }
}

void CSimVisRtRange::DoStore()
{
  // lock against the draw methods
  ScopeLock lock(*this);

  bool dataChanged = false;   

  CVisRtRange::RtRangePoints_t rangePoints;  

  // TODO: Question: is position dirty reason enough to use all other values without checking their dirtiness??
  if(m_rpRtRangeLateral.isDirty() && m_rpRtRangeForward.isDirty())
  {
    CVisRtRange::RtRangePoint rp;
    rp.lateralPos = static_cast<float32>(m_rpRtRangeLateral.val());
    rp.longPos    = static_cast<float32>(m_rpRtRangeForward.val());
    rp.id         = 1;
    // conversion from microseconds  10^-6 to milliseconds 10^-3
    rp.timestamp  = static_cast<float32>(m_rpAbsoluteTimestamp.val())/1000;

    dataChanged = true;
    if(m_rpRtRangeVelForward.isDirty() && m_rpRtRangeVelLateral.isDirty())
    {
      rp.lateralVel = static_cast<float32>(m_rpRtRangeVelForward.val());
      rp.longVel    = static_cast<float32>(m_rpRtRangeVelLateral.val());
    }

    if(m_rpAutoCorrelationSignalMeas.isDirty() && m_rpAutoCorrelationSignalRTRange.isDirty())
    {
      rp.signalMeas     = static_cast<float32>(m_rpAutoCorrelationSignalMeas.val());
      rp.signalRTRange  = static_cast<float32>(m_rpAutoCorrelationSignalRTRange.val());
    }
    rangePoints.push_back(rp);
  }

  if(m_rpRtRangeLateral2.isDirty() && m_rpRtRangeForward2.isDirty())
  {
    CVisRtRange::RtRangePoint rp;
    rp.lateralPos = static_cast<float32>(m_rpRtRangeLateral2.val());
    rp.longPos    = static_cast<float32>(m_rpRtRangeForward2.val());
    rp.id         = 1;
    // conversion from microseconds  10^-6 to milliseconds 10^-3
    rp.timestamp  = static_cast<float32>(m_rpAbsoluteTimestamp.val())/1000;

    dataChanged = true;
    if(m_rpRtRangeVelForward2.isDirty() && m_rpRtRangeVelLateral2.isDirty())
    {
      rp.lateralVel = static_cast<float32>(m_rpRtRangeVelForward2.val());
      rp.longVel    = static_cast<float32>(m_rpRtRangeVelLateral2.val());
    }

    if(m_rpAutoCorrelationSignalMeas.isDirty() && m_rpAutoCorrelationSignalRTRange.isDirty())
    {
      rp.signalMeas     = static_cast<float32>(m_rpAutoCorrelationSignalMeas.val());
      rp.signalRTRange  = static_cast<float32>(m_rpAutoCorrelationSignalRTRange.val());
    }
    rangePoints.push_back(rp);
  }

  if (dataChanged)
  {
    m_visRtRange.addRTRangeData(rangePoints);
    TriggerEvent(CP_CALCULATIONDONE, 0, 0);// trigger done port
  }
}

void CSimVisRtRange::SetIniFileName(const char* szIniFileName)
{
  // called by inherited class, reread the file on resert
  m_ssIniFilePath = szIniFileName;
  readIniFile();
}

void CSimVisRtRange::readIniFile()
{
  USES_CONVERSION;

  ctkTiXmlDocument xml( A2CT(m_ssIniFilePath.c_str()) );

  if(!xml.LoadFile())
  {
    // xml file does not exist or is corrupt
    std::stringstream ssErr;
    ssErr << "Invalid or non-existent ini file provided. Please check: " << m_ssIniFilePath;
    ReportError(err_sev_error, 0, ssErr.str().c_str());
    return;
  }

  // get the root nodes and generate the information for every tab or linked simvis file
  ctkTiXmlElement* rootElement = xml.RootElement();
  if ( strcmp(T2CA(rootElement->Value()), "RtRange") == 0 )
  {
    float fValue;
    int   iValue;

    if (rootElement->QueryFloatAttribute( _T("AutoCorrolationSignalMeasScale"), &fValue ) == TIXML_SUCCESS)
    {
      m_visRtRange.setAutoCorrelationSignalMeasScale(static_cast<float32>(fValue));
    }

    // iterate through the children of the root
    for (ctkTiXmlElement* childElement = rootElement->FirstChildElement(); childElement; childElement = childElement->NextSiblingElement())
    {

      float32 timeshift   = 0.0F;
      float32 translateX  = 0.0F;
      uint8   invertY     = 0;
      uint8   id          = 0;
      if (childElement->QueryIntAttribute( _T("id"), &iValue ) == TIXML_SUCCESS)
      {
        id = static_cast<uint8>(iValue);
      }
      if (childElement->QueryFloatAttribute( _T("Timeshift_ms"), &fValue ) == TIXML_SUCCESS)
      {
        timeshift = static_cast<float32>(fValue);
      }
      if (childElement->QueryFloatAttribute( _T("TranslateX_m"), &fValue ) == TIXML_SUCCESS)
      {
        translateX = static_cast<float32>(fValue);
      }
      if (childElement->QueryIntAttribute( _T("InvertY_bool"), &iValue ) == TIXML_SUCCESS)
      {
        invertY = static_cast<uint8>(iValue);
      }
      // currently only one parameter is stored for both rt range data
      switch(id)
      {
      case 1: 
        {
          m_visRtRange.setTimeShift(timeshift);
          m_visRtRange.setTranslateX(translateX);
          m_visRtRange.setInvertY(invertY);
        }
        break;
      case 2: 
        {
          m_visRtRange.setTimeShift(timeshift);
          m_visRtRange.setTranslateX(translateX);
          m_visRtRange.setInvertY(invertY);
        }
        break;
      default:
        break;
      }
    }// for
  }
  else
  {
    // xml file does not exist or is corrupt
    std::stringstream ssErr;
    ssErr << "Invalid file format. Please check: " << m_ssIniFilePath;
    ReportError(err_sev_error, 0, ssErr.str().c_str());
    return;
  }
}
