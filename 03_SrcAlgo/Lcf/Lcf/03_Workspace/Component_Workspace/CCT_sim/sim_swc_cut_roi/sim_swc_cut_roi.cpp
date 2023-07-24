#include "stdafx.h"
#include "resource.h"
#include "sim_swc_cut_roi.h"
#include "sim_swc_cut_roi_version.h"

#include "algo_type.h"

#include <cassert>
#include <sstream>

// global variables
HANDLE g_hModule = NULL;

// The Measurement Objects
BEGIN_SIM_OBJECT_TABLE()
  SIM_OBJECT_ENTRY(CSimRoiCutter)
  END_SIM_OBJECT_TABLE()

  BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID /*lpReserved*/)
{
  switch(ul_reason_for_call)
  {
  case DLL_PROCESS_ATTACH:
    g_hModule = hModule;
    break;
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
  case DLL_PROCESS_DETACH:
    break;
  }
  return TRUE;
}

CSimRoiCutter::CSimRoiCutter()
  : CSimSwcImg(reinterpret_cast<CSimSwcBase*>(this))

#ifdef MFC_REDUCED_ROI_WIDTH_L0
  , m_rpRoiSizeX ( this, "ROI Image Width" , MFC_REDUCED_ROI_WIDTH_L0, sizeof(m_rpRoiSizeX.val() ) )
#else
  , m_rpRoiSizeX ( this, "ROI Image Width" , 1024U, sizeof(m_rpRoiSizeX.val() ) )
#endif

#ifdef MFC_REDUCED_ROI_HEIGHT_L0
  , m_rpRoiSizeY ( this, "ROI Image Height",  MFC_REDUCED_ROI_HEIGHT_L0, sizeof(m_rpRoiSizeY.val() ) )
#else
  , m_rpRoiSizeY ( this, "ROI Image Height",  512U, sizeof(m_rpRoiSizeY.val() ) )
#endif

  , m_rpRoiStartX( this, "Start ROI X"     ,   76U, sizeof(m_rpRoiStartX.val()) )
  , m_rpRoiStartY( this, "Start ROI Y"     ,  128U, sizeof(m_rpRoiStartY.val()) )

  , m_rpFpgaConfigData( this, "FpgaConfigData", NULL, 0, 0, ParseConfigData, this )

  , m_rpProcessLeftImage( this, "ProcessLeftImage", 0, sizeof(m_rpProcessLeftImage.val()) )

  , m_rpImage( this, "ImageIn", NULL )

  , m_ppImage( this, "ImageOut" )

  , m_uiTimestamp   (0U)
  , m_uiFrameCounter(0U)
{
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "Image version " << CUT_ROIALL_SW_MAIN_VER_NO << "." << CUT_ROIALL_SW_SUB_VER_NO << "." << CUT_ROIALL_SW_BUG_FIX_LEV << "." << CUT_ROIALL_SW_BUG_FIX_LEV2;
  dataTxt   << "Image (Image Visualization Module)";
  AddInternalData(headerTxt.str().c_str(), dataTxt.str().c_str());

  dataTxt.str("");
#ifdef _DEBUG
  dataTxt << "Debug ";
#else
  dataTxt << "Release ";
#endif
  dataTxt << "build at " << __DATE__ << " " << __TIME__;
  AddInternalData("Compiling Info", dataTxt.str().c_str());

  m_cConfigDataDecoder.resetDecoder();

  AddServerPort("Init", InitExit, this);
  AddServerPort("Doit", Doit    , this);
  AddServerPort("Exit", InitExit, this);

  AddClientPort("AlgoCalcDone", NULL, 0, PORT_WITH_AUTOCLONE);

  AddReceivePort("Timestamp",      simI64_t,  &m_uiTimestamp,    sizeof(long long) );
  AddProvidePort("Timestamp",      simI64_t,  &m_uiTimestamp,    sizeof(long long) );
  AddProvidePort("Timestamp_ui64", simUI64_t, &m_uiTimestamp,    sizeof(unsigned long long) );

  AddReceivePort("FrameCounter",   simUI32_t, &m_uiFrameCounter, sizeof(unsigned int));
  AddProvidePort("FrameCounter",   simUI32_t, &m_uiFrameCounter, sizeof(unsigned int));

  m_rpImage.setAutoLock(true);
  m_rpFpgaConfigData.setAutoLock(true);
}

// Callback for MFC400 ConfigData
void CSimRoiCutter::ParseConfigData(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimRoiCutter *pThis  = reinterpret_cast<CSimRoiCutter*>(PlgID);
  if (pThis->m_rpFpgaConfigData.val() == NULL)
  {
    pThis->ReportError(err_sev_error, 0, "Received NULL-pointer in FEX data callback");
    return;
  }

  if(pThis->m_rpFpgaConfigData.val() != NULL)
  {
    pThis->DecodeFexData();
  }
}

// MFC400 Fex interface implementation
void CSimRoiCutter::DecodeFexData()
{
  int StreamSize= GetRPortSize(m_rpFpgaConfigData.name())/sizeof(unsigned short);
  m_cConfigDataDecoder.decodeStream(m_rpFpgaConfigData.val(), StreamSize);
}

void CSimRoiCutter::InitExit(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimRoiCutter *pThis = reinterpret_cast<CSimRoiCutter*>(PlgID);

  pThis->InitExit();
}

void CSimRoiCutter::InitExit()
{
  m_cConfigDataDecoder.resetDecoder();
}

void CSimRoiCutter::Doit(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimRoiCutter *pThis = reinterpret_cast<CSimRoiCutter*>(PlgID);

  pThis->Doit();

  //Notify the MO, that Calculation is done
  pThis->TriggerEvent("AlgoCalcDone",0,0);
}

void CSimRoiCutter::Doit()
{
  //  SafeUpdateReceivePorts();

  if (m_rpImage.val() == NULL)
  {
    return;
  }

  const short ROI_WIDTH  = m_rpRoiSizeX.val();
  const short ROI_HEIGHT = m_rpRoiSizeY.val();
  const int   ROI_SIZE   = ROI_WIDTH*ROI_HEIGHT*sizeof(unsigned short);

  const short IMAGE_IN_WIDTH  = m_rpImage.val()->bmWidth;
  const short IMAGE_IN_HEIGHT = m_rpImage.val()->bmHeight;

  unsigned short start_ROI_x;
  unsigned short start_ROI_y;

  // Set Output Port Size
  m_ppImage.updatePortSize(true, ROI_SIZE+sizeof(CTKImageData_t));

  if (m_ppImage.val() == NULL)
  {
    return;
  }

  // Prepare ROI position parameters
  start_ROI_x = m_rpRoiStartX.val();
  start_ROI_y = m_rpRoiStartY.val();

  if(m_cConfigDataDecoder.ConfigReceived())
  {
    // process FEX config stream
    if(!m_cConfigDataDecoder.areRoiRegistersSet())
    {
      ReportError(err_sev_error, 0, "C_SimRoiCutter::Doit: ROI Registers are missing in FEX data");
    }
    else
    {
      if(m_rpProcessLeftImage.val() == 1)
      {
        start_ROI_x = static_cast<unsigned short>(m_cConfigDataDecoder.getRoiStartX_Left());
        start_ROI_y = static_cast<unsigned short>(m_cConfigDataDecoder.getRoiStartY_Left());
      }
      else
      {
        start_ROI_x = static_cast<unsigned short>(m_cConfigDataDecoder.getRoiStartX_Right());
        start_ROI_y = static_cast<unsigned short>(m_cConfigDataDecoder.getRoiStartY_Right());
      }
    }
  }

  /**********************************************************************************/
  /* Begin: Cut out the Stereo ROI (1024*372) out of the incoming Image (1176*640)  */
  /**********************************************************************************/

  unsigned short *pImgOutData_ROI = reinterpret_cast<unsigned short*>(m_ppImage.val() + 1);
  unsigned short *pImgInData      = reinterpret_cast<unsigned short*>(m_rpImage.val() + 1);

  /*
  Stand BO1
  -------------------------------------------------------------------------
  |(Imager-Total)                                                         |
  |                                                                       |210Pixel
  |                                                                       |
  |           -----------------------------------------------------------------
  |           |Imager(1176x640)                                               |
  |           |                                                               |128Pixel
  |           |                                                               |
  |           |                   ---------------------------------------------
  |           |                   |Stereo ROI (1024x372)
  |-----------|                   |
  |  56Pixel	|                   |
  |           |-------------------|
  |           |     76Pixel       |
  |           |                   |
  |           |                   |
  */

  // check boundaries
  const unsigned short x_from    = std::min( static_cast<unsigned short>(IMAGE_IN_WIDTH-1), std::max( static_cast<unsigned short>(0), start_ROI_x ) );
  const unsigned short x_to      = std::min( static_cast<unsigned short>(IMAGE_IN_WIDTH-1), std::max( static_cast<unsigned short>(0), static_cast<unsigned short>(start_ROI_x + m_rpRoiSizeX.val()) ) );
  assert( x_to > x_from );
  const unsigned short eff_width = std::max( static_cast<unsigned short>(0), static_cast<unsigned short>(x_to - x_from));

  const unsigned short y_from     = std::min( static_cast<unsigned short>(IMAGE_IN_HEIGHT-1), std::max( static_cast<unsigned short>(0), start_ROI_y ) );
  const unsigned short y_to       = std::min( static_cast<unsigned short>(IMAGE_IN_HEIGHT-1), std::max( static_cast<unsigned short>(0), static_cast<unsigned short>(start_ROI_y + m_rpRoiSizeY.val()) ) );
  assert( y_to > y_from );
  const unsigned short eff_height = std::max( static_cast<unsigned short>(0), static_cast<unsigned short>(y_to - y_from));

  for (int i = 0; i < eff_height; ++i)
  {
    memcpy(&pImgOutData_ROI[i*ROI_WIDTH], &pImgInData[(i + y_from)*IMAGE_IN_WIDTH + x_from], eff_width*sizeof(unsigned short));
  }

  /**********************************************************************************/
  /* End: Cut out the Stereo ROI (1024*372) out of the incoming Image (1176*640)    */
  /**********************************************************************************/

  // Copy and update CTK header for the output image
  memcpy((void *)m_ppImage.val(), (void *)m_rpImage.val(), sizeof(CTKImageData_t)); // copy header

  m_ppImage.val()->bmWidth    = ROI_WIDTH;
  m_ppImage.val()->bmHeight   = ROI_HEIGHT;
  m_ppImage.val()->bmBytesRow = ROI_WIDTH * static_cast<unsigned short>(sizeof(unsigned short));
  m_ppImage.val()->bmSize     = ROI_SIZE;

  //generate some debug output & display overlay
  InitOverlay();  //Clears the overlay

  UpdatePPortSize("OverlayData", GetPictureSize(), FALSE);
  return;
}
