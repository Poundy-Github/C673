
#include "stdafx.h"
#include "resource.h"
#include "sim_swc_vis_velodyne.h"
#include "sim_swc_vis_velodyne_version.h"
#include "sim_renderparam_helper.h"

#include <sstream>

// the client port names
const char* CSimVisVelodyne::CP_CALCULATIONDONE = "CalculationDone";

const char* CSimVisVelodyne::PN_COLOR_MODE = "ColorMode";
const char* CSimVisVelodyne::PN_SUB_SAMPLE = "SubSamplingStep";
const char* CSimVisVelodyne::PN_POINT_SIZE = "PointSize";

CSimVisVelodyne::CSimVisVelodyne()
: CSimSwcDrawBase (10, "__BufferDataID", simI64_t, "__DoStore", "..\\gia_sim\\adapter.dll")

// Receive Ports
, m_rpMeasPointList        (this, "VelodyneHDL64EPointCloud", 0)

// Draw Ports
, m_dpVelodyneAutosar( this, "DrawVelodyneAutosar", &CSimVisVelodyne::DrawVelodyneAutosar, this, this )
{
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "VisVelodyne version " << VIS_VELODYNE_SW_MAIN_VER_NO << "." << VIS_VELODYNE_SW_SUB_VER_NO << "." << VIS_VELODYNE_SW_BUG_FIX_LEV << "." << VIS_VELODYNE_SW_BUG_FIX_LEV2;
  dataTxt   << "VisVelodyne  (VisVelodyne  Simulation Module)";
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

  // Menu Items
  OpenSubmenu(PN_COLOR_MODE);
  {
    AttachFunctionToMenu("Intensity",         MenuHandler, this, MA_CM_INTENSITY);
    AttachFunctionToMenu("Distance",          MenuHandler, this, MA_CM_DISTANCE);
    AttachFunctionToMenu("Height",            MenuHandler, this, MA_CM_AUTOSAR_HEIGHT);    
    AttachFunctionToMenu("Timestamp",         MenuHandler, this, MA_CM_VELO_TIMESTAMP);    
  }
  CloseSubmenu();

  OpenSubmenu(PN_POINT_SIZE);
  {
    AttachFunctionToMenu("+ 1", MenuHandler, this, MA_PS_INCREASE);
    AttachFunctionToMenu("- 1", MenuHandler, this, MA_PS_DECREASE);
  }
  CloseSubmenu();

  OpenSubmenu(PN_SUB_SAMPLE);
  {
    AttachFunctionToMenu("+ 1", MenuHandler, this, MA_SS_INCREASE);
    AttachFunctionToMenu("- 1", MenuHandler, this, MA_SS_DECREASE);
  }
  CloseSubmenu();
  
  // Parameters
  long paramValueLong = static_cast<long>(m_visVelodyne.getColorMode());
  AddGlobalParameter(PN_COLOR_MODE, simI32_t, &paramValueLong, sizeof(long));
  paramValueLong = m_visVelodyne.getPointSize();
  AddLocalParameter(PN_POINT_SIZE, simI32_t, &paramValueLong, sizeof(long));
  paramValueLong = m_visVelodyne.getSubSampling();
  AddGlobalParameter(PN_SUB_SAMPLE, simI32_t, &paramValueLong, sizeof(long));
      
  // Create client ports
  AddClientPort(CP_CALCULATIONDONE, NULL, 0, PORT_WITH_AUTOCLONE);

  // Create algorithm ports
  SetupPorts();
}

CSimVisVelodyne::~CSimVisVelodyne()
{
  m_visVelodyne.resetData();  
}

void CSimVisVelodyne::SetupPorts()
{
  // input ports  
  m_rpMeasPointList.setVersion        ("VelodyneHDL64EPointCloud",       CreateVersionInfoFromI32(0));
}

void CSimVisVelodyne::Reset()
{
  // setting for default values is only done if adapter is available
  FillRPortDefaultValues(DoStore, this);

  // mark RPorts as not dirty
  ResetRPortDirtyFlags(DoStore, this);

  {
    ScopeLock lock(*this);
    m_visVelodyne.resetData();
  }
}

void CSimVisVelodyne::DoStore()
{
  // lock against the draw methods
  ScopeLock lock(*this);

  bool updatedData = false;   
 
  if ( m_rpMeasPointList.isDirty() )
  {
    m_rpMeasPointList.lock();

    const VelodyneHDL64EPointCloud_t* mpl = m_rpMeasPointList.val();

    if(NULL == mpl)
    {
      m_visVelodyne.resetData();
    }
    else
    {
      m_visVelodyne.setVelodyneData(mpl); 
    }

    updatedData = true;
  }

  if (updatedData)
  {
    // trigger done port
    TriggerEvent(CP_CALCULATIONDONE, 0, 0);
  }
}

CVersionInfoImpl CSimVisVelodyne::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

void CSimVisVelodyne::DrawVelodyneAutosar( const ISimRenderContext& ctx )
{
  // setup
  setupParams(ctx);

  // lock against the store method
  ScopeLock lock(*this);

  // draw
  m_visVelodyne.renderVelodyne3D(ctx);  
}

void CSimVisVelodyne::MenuHandler( ISimRenderContext& ctx, const MenuAction action )
{
  switch (action)
  {
  case MA_CM_INTENSITY:
    CSimRenderParamHelper::SetGlobalParamByRef<long>(ctx, PN_COLOR_MODE, CVisVelodyne::CM_INTENSITY);
    break;
  case MA_CM_DISTANCE:
    CSimRenderParamHelper::SetGlobalParamByRef<long>(ctx, PN_COLOR_MODE, CVisVelodyne::CM_CAMERA_DISTANCE);
    break;
  case MA_CM_AUTOSAR_HEIGHT:
    CSimRenderParamHelper::SetGlobalParamByRef<long>(ctx, PN_COLOR_MODE, CVisVelodyne::CM_AUTOSAR_HEIGHT);
    break; 
  case MA_CM_VELO_TIMESTAMP:
    CSimRenderParamHelper::SetGlobalParamByRef<long>(ctx, PN_COLOR_MODE, CVisVelodyne::CM_VELO_TIMESTAMP);
    break; 
  case MA_PS_INCREASE:
    CSimRenderParamHelper::SetLocalParamByRef<long>(ctx, PN_POINT_SIZE, m_visVelodyne.getPointSize() + 1);
    break;
  case MA_PS_DECREASE:
    CSimRenderParamHelper::SetLocalParamByRef<long>(ctx, PN_POINT_SIZE, std::max<long>(1, m_visVelodyne.getPointSize() - 1));
    break;
  case MA_SS_INCREASE:
    CSimRenderParamHelper::SetGlobalParamByRef<long>(ctx, PN_SUB_SAMPLE, std::min<long>(32, m_visVelodyne.getSubSampling() + 1));
    break;
  case MA_SS_DECREASE:
    CSimRenderParamHelper::SetGlobalParamByRef<long>(ctx, PN_SUB_SAMPLE, std::max<long>(1, m_visVelodyne.getSubSampling() - 1));
    break;  
  }
}

void CSimVisVelodyne::setupParams( const ISimRenderContext& ctx )
{
  // setup
  m_visVelodyne.setParameters(    
    CSimRenderParamHelper::GetLocalParamByRef (ctx, PN_POINT_SIZE,              m_visVelodyne.getPointSize()),
    CSimRenderParamHelper::GetGlobalParamByRef(ctx, PN_SUB_SAMPLE,              m_visVelodyne.getSubSampling()),    
    CSimRenderParamHelper::GetGlobalParamByRef(ctx, PN_COLOR_MODE,              m_visVelodyne.getColorMode())    
    );
}
