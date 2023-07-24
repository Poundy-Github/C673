/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#include "stdafx.h"
#include "resource.h"
#include "sim_swc_mfc_to_srlcam_converter.h"
#include "gia_ver.h"

#include <sstream>

#include "image_fingerprint.h"

// the client port names
const char* CSimMfcToSrlcamConverter::CP_CALCULATIONDONE      = "CalculationDone";
const char* CSimMfcToSrlcamConverter::CP_DISTRIBUTEONLYDIRTYPORTS = "DistributeOnlyDirtyPorts";

// the provide port names
const char* CSimMfcToSrlcamConverter::PP_IC_IMG_CHAR_ODD      = "SrlIcImageCharacteristicsOddRight";
const char* CSimMfcToSrlcamConverter::PP_IC_IMG_CHAR_EVEN     = "SrlIcImageCharacteristicsEvenRight";
const char* CSimMfcToSrlcamConverter::PP_IMAGE_ODD      = "SrlImageOddRight";
const char* CSimMfcToSrlcamConverter::PP_IMAGE_EVEN     = "SrlImageEvenRight";
const char* CSimMfcToSrlcamConverter::PP_ALGO_COMP_STATE      = "AlgoCompState";

/// List of cycles, this plugin sends output to. 
const DWORD CSimMfcToSrlcamConverter::CYCLE_INFO_ARR[1] = {CYLCE_ID};

static void IcImageCharacteristicsOddReceived (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcToSrlcamConverter* cropper = reinterpret_cast<CSimMfcToSrlcamConverter*>(PlgID);
  cropper->ReplaceImagerCroiOdd();
}

static void IcImageCharacteristicsEvenReceived (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcToSrlcamConverter* cropper = reinterpret_cast<CSimMfcToSrlcamConverter*>(PlgID);
  cropper->ReplaceImagerCroiEven();
}

CSimMfcToSrlcamConverter::CSimMfcToSrlcamConverter()
: CSimSwcDrawBase (10, "__BufferDataID", simI64_t, "__DoStore", "..\\gia_sim\\adapter.dll")
, CSimSwcCDL      (this, IDR_CDL)
, CSimSwcMeas     (this)
, CSimSwcDebugExc ()
, CSimSwcCycleInfo(this, CYCLE_INFO_ARR, sizeof(CYCLE_INFO_ARR)/sizeof(DWORD))
, m_rpBaseCtrlData      (this, "BaseCtrlData",          BaseCtrlData_t())
, m_rpIcImgCharOdd      (this, "IcImageCharacteristicsOddRight",      IcImageCharacteristics_t(), sizeof(IcImageCharacteristics_t), 0, IcImageCharacteristicsOddReceived,  this)
, m_rpIcImgCharEven     (this, "IcImageCharacteristicsEvenRight",     IcImageCharacteristics_t(), sizeof(IcImageCharacteristics_t), 0, IcImageCharacteristicsEvenReceived, this)
, m_rpImageOdd          (this, "ImageOddRight",                       NULL)
, m_rpImageEven         (this, "ImageEvenRight",                       NULL)
{
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "MfcToSrlcamConverter version " << GIA_ALL_SW_MAIN_VER_NO << "." << GIA_ALL_SW_SUB_VER_NO << "." << GIA_ALL_SW_BUG_FIX_LEV << "." << GIA_ALL_SW_BUG_FIX_LEV2;
  dataTxt   << "MfcToSrlcamConverter (MfcToSrlcamConverter Simulation Module)";
  AddInternalData(headerTxt.str().c_str(), dataTxt.str().c_str());

#ifdef _DEBUG
  dataTxt.str("Debug ");
#else
  dataTxt.str("Release ");
#endif
  dataTxt << "build at " << __DATE__ << " " << __TIME__;
  AddInternalData("Compiling Info", dataTxt.str().c_str());

  // Create server Ports
  AddServerPort("Reset", Reset, this);
  AddServerPort("Init",  Init,  this);
  AddServerPort("Doit",  Doit,  this);

  // Create client ports
  AddClientPort(CP_DISTRIBUTEONLYDIRTYPORTS, NULL, 0);
  AddClientPort(CP_CALCULATIONDONE,      NULL, 0, PORT_WITH_AUTOCLONE);

  // Create algorithm ports
  SetupPorts();

  // reset "received" flags and error counters
  ResetReceivePorts();
}

CSimMfcToSrlcamConverter::~CSimMfcToSrlcamConverter()
{
}

void CSimMfcToSrlcamConverter::SetupPorts()
{
  // input ports
  m_rpBaseCtrlData.setVersion   ("BaseCtrlData_t",             CreateVersionInfoFromI32(BASE_CTRL_DATA_INTFVER));
  m_rpIcImgCharOdd.setVersion   ("IcImageCharacteristics_t",   CreateVersionInfoFromI32(IC_IMAGE_CHARACTERISTICS_INTFVER));
  m_rpIcImgCharEven.setVersion  ("IcImageCharacteristics_t",   CreateVersionInfoFromI32(IC_IMAGE_CHARACTERISTICS_INTFVER));
  m_rpImageOdd.setVersion       ("ImageU16_t",                 CreateVersionInfoFromI32(IMAGE16_INTFVER));
  m_rpImageEven.setVersion      ("ImageU16_t",                 CreateVersionInfoFromI32(IMAGE16_INTFVER));

  m_rpImageOdd.setAutoLock(true);
  m_rpImageEven.setAutoLock(true);

  // output ports
  AddProvidePort (PP_ALGO_COMP_STATE, simOPAQUE_t, &m_ppAlgoCompState, sizeof(m_ppAlgoCompState));
  SetPPortVersion(PP_ALGO_COMP_STATE, "AlgoCompState_t", CreateVersionInfoFromI32(COMP_STATE_INTFVER));

  AddProvidePort (PP_IC_IMG_CHAR_ODD, simOPAQUE_t, &m_ppIcImgCharOdd, sizeof(m_ppIcImgCharOdd));
  SetPPortVersion(PP_IC_IMG_CHAR_ODD, "IcImageCharacteristics_t", CreateVersionInfoFromI32( IC_IMAGE_CHARACTERISTICS_INTFVER));

  AddProvidePort (PP_IC_IMG_CHAR_EVEN, simOPAQUE_t, &m_ppIcImgCharEven, sizeof(m_ppIcImgCharEven));
  SetPPortVersion(PP_IC_IMG_CHAR_EVEN, "IcImageCharacteristics_t", CreateVersionInfoFromI32( IC_IMAGE_CHARACTERISTICS_INTFVER));

  AddProvidePort (PP_IMAGE_ODD, simREFERENCE_t, &m_ppImageOdd, 0);
  SetPPortVersion(PP_IMAGE_ODD, "ImageU16_t", CreateVersionInfoFromI32( IMAGE16_INTFVER));

  AddProvidePort (PP_IMAGE_EVEN, simREFERENCE_t, &m_ppImageEven, 0);
  SetPPortVersion(PP_IMAGE_EVEN, "ImageU16_t", CreateVersionInfoFromI32( IMAGE16_INTFVER));

  memset(&m_ppAlgoCompState, 0, sizeof(m_ppAlgoCompState));
  m_ppAlgoCompState.uiAlgoVersionNumber = 1;
  m_ppAlgoCompState.uiVersionNumber = COMP_STATE_INTFVER;
}

void CSimMfcToSrlcamConverter::ResetReceivePorts()
{
  for (ReceivePortMap_t::iterator i = m_receivePortMap.begin(); i != m_receivePortMap.end(); ++i)
  {
    SimReceivePortBase& port = **i;
    port.setNotDirty();
  }
}

void CSimMfcToSrlcamConverter::Reset()
{
  // reset received flags
  ResetReceivePorts();

  // TODO: Place reset stuff
}

void CSimMfcToSrlcamConverter::Init()
{ 

  // TODO: Place initialization stuff
}

void CSimMfcToSrlcamConverter::Doit()
{
  //! send cycle start
  MEASSendCycleStartMTS (CYLCE_ID);

  MainCall();

  //! send cycle end
  MEASSendCycleEndMTS (CYLCE_ID);

  // trigger done port
  TriggerEvent(CP_DISTRIBUTEONLYDIRTYPORTS, 0, 0);

  // trigger done port
  TriggerEvent(CP_CALCULATIONDONE, 0, 0);
}


void CSimMfcToSrlcamConverter::MainCall()
{
  // Setup FPU
  SimDbgSetupFPU();

  __try
  {  

    // Odd Image
    if(m_rpIcImgCharOdd.isDirty() && m_rpImageOdd.isDirty() && m_rpImageOdd.val() && m_rpImageOdd.val()->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    {
      // check if imager size is not srlcam size
      if(m_rpImageOdd.val()->sImgHeader.uiHeight != 630 || m_rpImageOdd.val()->sImgHeader.uiWidth != 832)
      {
        m_ppIcImgCharOdd = m_rpIcImgCharOdd.val();
        m_CropResultOdd = CropOddImage();
      }
      else
      {
        m_CropResultOdd = m_rpIcImgCharOdd.val().s_ImagerCroi;
        UpdatePPortSize(PP_IMAGE_ODD,  sizeof(ImageU16_t) + m_rpImageOdd.val()->sImgHeader.iSizeBytes, false);
        m_ppImageOdd = m_rpImageOdd.val();
      }
      SetPPortDirty(PP_IMAGE_ODD);
      m_rpIcImgCharOdd.setNotDirty();
      m_rpImageOdd.setNotDirty();
      m_ppAlgoCompState.eCompState = COMP_STATE_RUNNING;

      // Meeasfreeze Odd Data
      MeasFreezeSim(GIA_MEAS_ID_CROPPER_COMP_STATE, &m_ppAlgoCompState, sizeof(m_ppAlgoCompState));
      MeasFreezeSim(GIA_MEAS_ID_CROPPER_IMAGE_ODD, m_ppImageOdd, sizeof(ImageU16_t));
    }

    // Even Image
    if(m_rpIcImgCharEven.isDirty() && m_rpImageEven.isDirty() && m_rpImageEven.val() && m_rpImageEven.val()->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    {
      // check if imager size is not srlcam size
      if(m_rpImageEven.val()->sImgHeader.uiHeight != 482 || m_rpImageEven.val()->sImgHeader.uiWidth != 832)
      {
        m_ppIcImgCharEven = m_rpIcImgCharEven.val();
        m_CropResultEven = CropEvenImage();
      }
      else
      {
        m_CropResultEven = m_rpIcImgCharEven.val().s_ImagerCroi;
        UpdatePPortSize(PP_IMAGE_EVEN,  sizeof(ImageU16_t) + m_rpImageEven.val()->sImgHeader.iSizeBytes, false);
        m_ppImageEven = m_rpImageEven.val();
      }
      SetPPortDirty(PP_IMAGE_EVEN);
      m_rpIcImgCharEven.setNotDirty();
      m_rpImageEven.setNotDirty();
      m_ppAlgoCompState.eCompState = COMP_STATE_RUNNING;

      // Meeasfreeze Even Data
      MeasFreezeSim(GIA_MEAS_ID_CROPPER_COMP_STATE, &m_ppAlgoCompState, sizeof(m_ppAlgoCompState));
      MeasFreezeSim(GIA_MEAS_ID_CROPPER_IMAGE_EVEN, m_ppImageEven, sizeof(ImageU16_t));
    }
  }
  __except(SimDbgEvaluateException(GetExceptionCode(), GetExceptionInformation(), this))
  {
    m_ppAlgoCompState.eCompState = COMP_STATE_TEMPORARY_ERROR;
  }

  // Restore FPU
  SimDbgRestoreFPU();
}

CVersionInfoImpl CSimMfcToSrlcamConverter::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

IcRect_t CSimMfcToSrlcamConverter::CropOddImage()
{
  /**********************************************************************************/
  /* Begin: Cut out the SrlCam CROI (832*630) out of the incoming Image             */
  /**********************************************************************************/
  

  /*
    Stand BO1
  -------------------------------------------------------------------------
  |(Imager-Komplett)					|
  |									          |210Pixel
  |									          |
  |			      -----------------------------------------------------------------
  |			      |SMFC4B0(1176x640)			|
  |			      |								        |0Pixel
  |			      |								        |
  |			      |					          ---------------------------------------------
  |			      |					          |SRLCam4xx (832x630)
  |-----------|					          |
  |  56Pixel	|					          |
  |			      |-------------------|
  |			      |		  170Pixel      |
  |			      |					          |
  |			      |					          |
  */

  uint16 imgHeight = 630;
  uint16 imgWidth  = 832;
  ImageHeader_t srcImageHeader = m_rpImageOdd.val()->sImgHeader;
  IcRect_t cropResult;

  sint32 iSizeBytes  = sizeof(uint16)*imgHeight*imgWidth;
  UpdatePPortSize(PP_IMAGE_ODD,  sizeof(ImageU16_t) + iSizeBytes, true);

  if(!m_ppImageOdd)
  {
    /*Error Handling*/
    cropResult = m_rpIcImgCharOdd.val().s_ImagerCroi;
  }
  else
  {
    memcpy(m_ppImageOdd, m_rpImageOdd.val(), sizeof(ImageU16_t)); // Copy Image Header, Singal Header and VersionNumber

    // Update ImageHeader
    m_ppImageOdd->sImgHeader.iSizeBytes = iSizeBytes;
    m_ppImageOdd->sImgHeader.iRowBytes = imgWidth*sizeof(uint16);
    m_ppImageOdd->sImgHeader.uiWidth = imgWidth;
    m_ppImageOdd->sImgHeader.uiHeight = imgHeight;

    // check boundaries
    const uint16 x_from    = (uint16)((sint32)srcImageHeader.uiWidth  - (sint32)imgWidth > 0) ? (srcImageHeader.uiWidth - imgWidth)/2 : 0;
    const uint16 x_to      = (uint16)((sint32)srcImageHeader.uiWidth -  (sint32)imgWidth > 0)? (srcImageHeader.uiWidth - imgWidth)/2 + imgWidth : srcImageHeader.uiWidth;
    const uint16 eff_width = (uint16)std::max( 0, x_to - x_from);

    const uint16 y_from    = 0;
    const uint16 y_to      = (uint16)((sint32)srcImageHeader.uiHeight - (sint32)imgHeight > 0)? imgHeight : srcImageHeader.uiHeight;
    const uint16 eff_height = (uint16)std::max( 0, y_to - y_from);
    
    uint16 * pDestImage = reinterpret_cast<uint16*>(m_ppImageOdd) + sizeof(ImageU16_t);
    m_ppImageOdd->aImageData = reinterpret_cast<const uint16*>(pDestImage);
    uint32 uiLineLength = m_rpImageOdd.val()->sImgHeader.iRowBytes/sizeof(uint16);
    for (int i = 0; i < eff_height; ++i)
    {
      memcpy(&pDestImage[i*eff_width], &m_rpImageOdd.val()->aImageData[(i + y_from)*uiLineLength + x_from], eff_width*sizeof(uint16));
    }

    // Image fingerprint computation
    ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_ui16(m_ppImageOdd);

    cropResult.ui16_Width = eff_width;
    cropResult.ui16_Height = eff_height;
    cropResult.ui16_X = m_rpIcImgCharOdd.val().s_ImagerCroi.ui16_X + x_from;
    cropResult.ui16_Y = m_rpIcImgCharOdd.val().s_ImagerCroi.ui16_Y + y_from;
  }

    

  /**********************************************************************************/
  /* End: Cut out the SrlCam CROI (832*630) out of the incoming Image               */
  /**********************************************************************************/
  return cropResult;
}

IcRect_t CSimMfcToSrlcamConverter::CropEvenImage()
{
  /**********************************************************************************/
  /* Begin: Cut out the SrlCam CROI (832*482) out of the incoming Image             */
  /**********************************************************************************/
  

  // ToDo: Modify figure
  /*
    Stand BO1
  -------------------------------------------------------------------------
  |(Imager-Komplett)					|
  |									          |210Pixel
  |									          |
  |			      -----------------------------------------------------------------
  |			      |SMFC4B0(1176x482)			|
  |			      |								        |0Pixel
  |			      |								        |
  |			      |					          ---------------------------------------------
  |			      |					          |SRLCam4xx (832x482)
  |-----------|					          |
  |  56Pixel	|					          |
  |			      |-------------------|
  |			      |		  170Pixel      |
  |			      |					          |
  |			      |					          |
  */

  uint16 imgHeight = 482;
  uint16 imgWidth  = 832;
  ImageHeader_t srcImageHeader = m_rpImageEven.val()->sImgHeader; 
  IcRect_t cropResult;

  sint32 iSizeBytes  = sizeof(uint16)*imgHeight*imgWidth;
  UpdatePPortSize(PP_IMAGE_EVEN,  sizeof(ImageU16_t) + iSizeBytes, true);

  if(!m_ppImageEven)
  {
    /*Error Handling*/
    cropResult = m_rpIcImgCharEven.val().s_ImagerCroi;
  }
  else
  {
    memcpy(m_ppImageEven, m_rpImageEven.val(), sizeof(ImageU16_t)); // Copy Image Header, Singal Header and VersionNumber

    // Update ImageHeader
    m_ppImageEven->sImgHeader.iSizeBytes = iSizeBytes;
    m_ppImageEven->sImgHeader.iRowBytes  = imgWidth*sizeof(uint16);
    m_ppImageEven->sImgHeader.uiWidth    = imgWidth;
    m_ppImageEven->sImgHeader.uiHeight   = imgHeight;

    // check boundaries
    const uint16 x_from    = (uint16)((sint32)srcImageHeader.uiWidth  - (sint32)imgWidth > 0) ? (srcImageHeader.uiWidth - imgWidth)/2 : 0;
    const uint16 x_to      = (uint16)((sint32)srcImageHeader.uiWidth -  (sint32)imgWidth > 0)? (srcImageHeader.uiWidth - imgWidth)/2 + imgWidth : srcImageHeader.uiWidth;
    const uint16 eff_width = (uint16)std::max( 0, x_to - x_from);

    const uint16 y_from    = 0;
    const uint16 y_to      = (uint16)((sint32)srcImageHeader.uiHeight - (sint32)imgHeight > 0)? imgHeight : srcImageHeader.uiHeight;
    const uint16 eff_height = (uint16)std::max( 0, y_to - y_from);
    
    uint16 * pDestImage = reinterpret_cast<uint16*>(m_ppImageEven) + sizeof(ImageU16_t);
    m_ppImageEven->aImageData = reinterpret_cast<const uint16*>(pDestImage);
    uint32 uiLineLength = m_rpImageEven.val()->sImgHeader.iRowBytes/sizeof(uint16);
    for (int i = 0; i < eff_height; ++i)
    {
      memcpy(&pDestImage[i*eff_width], &m_rpImageEven.val()->aImageData[(i + y_from)*uiLineLength+ x_from], eff_width*sizeof(uint16));
    }
    // Image fingerprint computation
    ifp::CImageFingerPrint::getInstance().ComputeImageFingerPrint_ui16(m_ppImageEven);

    cropResult.ui16_Width = eff_width;
    cropResult.ui16_Height = eff_height;
    cropResult.ui16_X = m_rpIcImgCharEven.val().s_ImagerCroi.ui16_X + x_from;
    cropResult.ui16_Y = m_rpIcImgCharEven.val().s_ImagerCroi.ui16_Y + y_from;

  }

  /**********************************************************************************/
  /* End: Cut out the SrlCam CROI (832*482) out of the incoming Image               */
  /**********************************************************************************/
  return cropResult;
}

void CSimMfcToSrlcamConverter::ReplaceImagerCroiOdd()
{
  if(m_rpIcImgCharOdd.isDirty())
  {
    m_ppIcImgCharOdd = m_rpIcImgCharOdd.val();
    m_ppIcImgCharOdd.s_ImagerCroi = m_CropResultOdd;
    SetPPortDirty(PP_IC_IMG_CHAR_ODD);
    MeasFreezeSim(GIA_MEAS_ID_CROPPER_IMAGE_CHARACTERISTIC_ODD, &m_ppIcImgCharOdd, sizeof(m_ppIcImgCharOdd));
    TriggerEvent(CP_DISTRIBUTEONLYDIRTYPORTS, 0, 0);
  }
}

void CSimMfcToSrlcamConverter::ReplaceImagerCroiEven()
{
  if(m_rpIcImgCharEven.isDirty())
  {
    m_ppIcImgCharEven = m_rpIcImgCharEven.val();
    m_ppIcImgCharEven.s_ImagerCroi = m_CropResultEven;
    SetPPortDirty(PP_IC_IMG_CHAR_EVEN);
    MeasFreezeSim(GIA_MEAS_ID_CROPPER_IMAGE_CHARACTERISTIC_EVEN, &m_ppIcImgCharEven, sizeof(m_ppIcImgCharEven));
    TriggerEvent(CP_DISTRIBUTEONLYDIRTYPORTS, 0, 0);
  }
}

// Meas freeze method for sim data
void CSimMfcToSrlcamConverter::MeasFreezeSim (const uint32 _vaddr, const void* _addr, const uint32 _size)
{
  MEASInfo_t desc;

  desc.VirtualAddress = _vaddr;
  desc.Length         = _size;
  desc.FuncID         = 0;
  desc.FuncChannelID  = static_cast<uint8>(TASK_ID_GIA);

  (void) MTSMeas(&desc, (void *)_addr, NULL);
}

MEASReturn_t CSimMfcToSrlcamConverter::MTSMeas(const MEASInfo_t *pInfo, void *pData, MEAS_Callback_t Callback)
{
  // Algorithm specific parameter translation
  SIMMEASInfo_t SimInfo;

  SimInfo.VirtualAddress = pInfo->VirtualAddress;
  SimInfo.Length         = pInfo->Length;
  SimInfo.FuncID         = pInfo->FuncID;
  SimInfo.FuncChannelID  = pInfo->FuncChannelID;
  // pass on to CPP code:
  return static_cast<MEASReturn_t>( MEASFreezeDataMTS (&SimInfo, pData, Callback));
  return MEAS_OK;
}
