/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#include "stdafx.h"
#include "resource.h"
#include "sim_swc_image_timestamp_fix.h"

#include <sstream>
#include <limits>

// the provide port names
const char* CSimImageTimestampFix::PP_IMAGE_FRAMECOUNTER_LEFT   = "ImageFramecounterLeft";
const char* CSimImageTimestampFix::PP_IMAGE_FRAMECOUNTER_RIGHT  = "ImageFramecounterRight";
const char* CSimImageTimestampFix::PP_IMAGE_TIMESTAMP_LEFT      = "ImageTimestampLeft";
const char* CSimImageTimestampFix::PP_IMAGE_TIMESTAMP_RIGHT     = "ImageTimestampRight";
const char* CSimImageTimestampFix::PP_IMAGE_RAW_LEFT            = "ImageRawLeft";
const char* CSimImageTimestampFix::PP_IMAGE_RAW_RIGHT           = "ImageRawRight";

CSimImageTimestampFix::CSimImageTimestampFix(CSimSwcBase* pBaseInstance)
: m_pBaseInstance(pBaseInstance)
, m_rpTimestampToBeSet      (pBaseInstance, "TimestampToBeSet"         , 0)
, m_rpFramecounterToBeSet   (pBaseInstance, "FrameCounterToBeSet"      , 0)
, m_rpImageFramecounterLeft (pBaseInstance, PP_IMAGE_FRAMECOUNTER_LEFT , 0)
, m_rpImageFramecounterRight(pBaseInstance, PP_IMAGE_FRAMECOUNTER_RIGHT, 0)
, m_rpImageTimestampLeft    (pBaseInstance, PP_IMAGE_TIMESTAMP_LEFT    , 0)
, m_rpImageTimestampRight   (pBaseInstance, PP_IMAGE_TIMESTAMP_RIGHT   , 0)
, m_rpImageRawLeft          (pBaseInstance, PP_IMAGE_RAW_LEFT          , NULL)
, m_rpImageRawRight         (pBaseInstance, PP_IMAGE_RAW_RIGHT         , NULL)
, m_uiNumMissedInput(0)
, m_bCopiedDataInPPorts(false)
{
  // Create algorithm ports
  SetupPorts();

  // reset "received" flags and error counters
  ResetReceiveErrors();
}

CSimImageTimestampFix::~CSimImageTimestampFix()
{
  Reset();
}

void CSimImageTimestampFix::SetupPorts()
{
  // special sim reference port behaviour -> lock memory on receiving of data
  m_rpImageRawLeft.setAutoLock(true);
  m_rpImageRawRight.setAutoLock(true);

  // initialize input port map
  m_receivePortMap[&m_rpImageTimestampLeft].errorCount   = 0;
  m_receivePortMap[&m_rpImageTimestampLeft].checkForData = true;

  m_receivePortMap[&m_rpImageTimestampRight].errorCount   = 0;
  m_receivePortMap[&m_rpImageTimestampRight].checkForData = true;

  m_receivePortMap[&m_rpImageRawLeft].errorCount   = 0;
  m_receivePortMap[&m_rpImageRawLeft].checkForData = true;

  m_receivePortMap[&m_rpImageRawRight].errorCount   = 0;
  m_receivePortMap[&m_rpImageRawRight].checkForData = true;

  // output ports
  m_pBaseInstance->AddProvidePort(PP_IMAGE_TIMESTAMP_LEFT  , simI64_t      , &m_ppImageTimestampLeft , sizeof(m_ppImageTimestampLeft));
  m_pBaseInstance->AddProvidePort(PP_IMAGE_TIMESTAMP_RIGHT , simI64_t      , &m_ppImageTimestampRight, sizeof(m_ppImageTimestampRight));
  m_pBaseInstance->AddProvidePort(PP_IMAGE_RAW_LEFT        , simREFERENCE_t, &m_ppImageRawLeft, 0);
  m_pBaseInstance->AddProvidePort(PP_IMAGE_RAW_RIGHT       , simREFERENCE_t, &m_ppImageRawRight, 0);
}

void CSimImageTimestampFix::ResetReceiveErrors()
{
  for (ReceivePortMap_t::iterator i = m_receivePortMap.begin(); i != m_receivePortMap.end(); ++i)
  {
    i->second.errorCount = 0;
    i->first->setNotDirty();
  }
}

void CSimImageTimestampFix::Reset()
{
  m_uiNumMissedInput = 0;
  if (m_bCopiedDataInPPorts)
  {
    m_pBaseInstance->MemLock(m_ppImageRawLeft, FALSE);
    m_pBaseInstance->MemLock(m_ppImageRawRight, FALSE);
    m_ppImageRawLeft = NULL;
    m_ppImageRawRight = NULL;
  }
  m_bCopiedDataInPPorts = false;

  // reset received flags
  ResetReceiveErrors();
}

void CSimImageTimestampFix::Init()
{
  // reset received flags
  ResetReceiveErrors();
}

int CSimImageTimestampFix::Doit(bool bMFC400)
{
  int iResult = SIM_ERR_UNDEFINED;

  if (bMFC400)
  {
    if (m_bCopiedDataInPPorts)
    {
      m_pBaseInstance->MemLock(m_ppImageRawLeft, FALSE);
      m_pBaseInstance->MemLock(m_ppImageRawRight, FALSE);
      m_ppImageRawLeft = NULL;
      m_ppImageRawRight = NULL;
      m_bCopiedDataInPPorts = false;
    }
    // try to replace timestamp
    if ( IsRequiredDataAvailable() )
    {
      iResult = ProcessData();
      if (iResult == SIM_ERR_OK)
      {
        // reset the received flags for the request ports
        ResetReceiveErrors();
      }

      m_rpFramecounterToBeSet.setNotDirty();
      m_rpTimestampToBeSet.setNotDirty();
    }
  }
  else
  {
    // just pass through received data
    iResult = SIM_ERR_OK;
    if (!m_bCopiedDataInPPorts)
    {
      // free old data
      m_pBaseInstance->UpdatePPortSize(PP_IMAGE_RAW_LEFT, 0, TRUE);
      m_pBaseInstance->UpdatePPortSize(PP_IMAGE_RAW_RIGHT, 0, TRUE);
    }
    m_pBaseInstance->UpdatePPortSize(PP_IMAGE_RAW_LEFT, (unsigned long)m_rpImageRawLeft.size(), FALSE);
    m_pBaseInstance->UpdatePPortSize(PP_IMAGE_RAW_RIGHT, (unsigned long)m_rpImageRawRight.size(), FALSE);

    m_pBaseInstance->MemLock(m_ppImageRawLeft, FALSE);
    m_pBaseInstance->MemLock(m_ppImageRawRight, FALSE);

    m_ppImageRawLeft = m_rpImageRawLeft.val();
    m_ppImageRawRight = m_rpImageRawRight.val();
    m_ppImageTimestampLeft = m_rpImageTimestampLeft.val();
    m_ppImageTimestampRight = m_rpImageTimestampRight.val();
    m_pBaseInstance->MemLock(m_ppImageRawLeft, TRUE);
    m_pBaseInstance->MemLock(m_ppImageRawRight, TRUE);
    // set provide ports dirty
    m_pBaseInstance->SetPPortDirty(PP_IMAGE_RAW_LEFT);
    m_pBaseInstance->SetPPortDirty(PP_IMAGE_RAW_RIGHT);
    m_pBaseInstance->SetPPortDirty(PP_IMAGE_TIMESTAMP_LEFT);
    m_pBaseInstance->SetPPortDirty(PP_IMAGE_TIMESTAMP_RIGHT);
    m_bCopiedDataInPPorts = true;
  }

  return iResult;
}

int CSimImageTimestampFix::ProcessData()
{
  static const unsigned int NUM_MAX_MISSED = 10;
  static const int CYCLE_TIME = 60280;

  if (m_rpFramecounterToBeSet.isDirty() != m_rpTimestampToBeSet.isDirty())
  {
    // situation not recoverable
    m_pBaseInstance->ReportError(err_sev_error, 0, "Timestamp fix: Data input check failed. Mismatch in updating timestamp and framecounter.");
    return SIM_ERR_UNDEFINED;
  }

  if (!m_rpFramecounterToBeSet.isDirty())
  {
    m_uiNumMissedInput++;
    if (m_uiNumMissedInput > NUM_MAX_MISSED)
    {
      m_pBaseInstance->ReportError(err_sev_error, 0, "Timestamp fix: Missing input for replacement.");
      return SIM_ERR_UNDEFINED;
    }
  }
  else
  {
    m_uiNumMissedInput = 0;
  }

  if (m_rpImageFramecounterLeft.val() != m_rpImageFramecounterRight.val())
  {
    m_pBaseInstance->ReportError(err_sev_error, 0, "Timestamp fix: Left/Right counter mismatch.");
    return SIM_ERR_UNDEFINED;
  }

  // adapt timestamp if necessary
  unsigned int uiTimestamp = m_rpTimestampToBeSet.val();
  if (m_rpFramecounterToBeSet.val() != m_rpImageFramecounterRight.val())
  {
    // detect possible wrap around
    int iFrameDiff = static_cast<unsigned short>(m_rpImageFramecounterRight.val()) - static_cast<unsigned short>(m_rpFramecounterToBeSet.val());
    bool bWrap = std::abs(iFrameDiff) > std::numeric_limits<unsigned short>::max() - std::abs(iFrameDiff);
    if (bWrap)
    {
      if (iFrameDiff < 0)
      {
        iFrameDiff = (std::numeric_limits<unsigned short>::max() - std::abs(iFrameDiff) + 1);
      }
      else
      {
        iFrameDiff = -(std::numeric_limits<unsigned short>::max() - std::abs(iFrameDiff) + 1);
      }
    }
    uiTimestamp = static_cast<int>(static_cast<__int64>(uiTimestamp) + (static_cast<__int64>(iFrameDiff) * static_cast<__int64>(CYCLE_TIME)) / 2);
  }

  m_pBaseInstance->UpdatePPortSize(PP_IMAGE_RAW_LEFT , (unsigned long)m_rpImageRawLeft.size() , TRUE);
  m_pBaseInstance->UpdatePPortSize(PP_IMAGE_RAW_RIGHT, (unsigned long)m_rpImageRawRight.size(), TRUE);
  memcpy(m_ppImageRawLeft , m_rpImageRawLeft.val() , m_rpImageRawLeft.size() );
  memcpy(m_ppImageRawRight, m_rpImageRawRight.val(), m_rpImageRawRight.size());

  ReplaceEmbeddedTimestamp(m_ppImageRawLeft , (unsigned long)m_rpImageRawLeft.size() , uiTimestamp);
  ReplaceEmbeddedTimestamp(m_ppImageRawRight, (unsigned long)m_rpImageRawRight.size(), uiTimestamp);

  // fill provide ports
  m_ppImageTimestampLeft = uiTimestamp;
  m_ppImageTimestampRight = uiTimestamp;

  // set provide ports dirty
  // TODO: switch to provide port class and provide index instead of name
  m_pBaseInstance->SetPPortDirty(PP_IMAGE_RAW_LEFT);
  m_pBaseInstance->SetPPortDirty(PP_IMAGE_RAW_RIGHT);
  m_pBaseInstance->SetPPortDirty(PP_IMAGE_TIMESTAMP_LEFT);
  m_pBaseInstance->SetPPortDirty(PP_IMAGE_TIMESTAMP_RIGHT);

  return SIM_ERR_OK;
}

void CSimImageTimestampFix::ReplaceEmbeddedTimestamp(void* pData, unsigned int uiSize, unsigned __int64 uiTimestampToBeSet)
{
  unsigned short qiValue0 = (unsigned short)((uiTimestampToBeSet >>  0) & 0xffff);
  unsigned short qiValue1 = (unsigned short)((uiTimestampToBeSet >> 16) & 0xffff);
  unsigned short qiValue2 = (unsigned short)((uiTimestampToBeSet >> 32) & 0xffff);
  unsigned short qiValue3 = (unsigned short)((uiTimestampToBeSet >> 48) & 0xffff);

  m_mapRegisterReplacements[0x3102] = qiValue0;
  m_mapRegisterReplacements[0x3104] = qiValue1;
  m_mapRegisterReplacements[0x310C] = qiValue2;
  m_mapRegisterReplacements[0x310E] = qiValue3;


  int i32Result;
  MFC::SImageInfoStruct sImageInfo;
  i32Result = GetImageParameter(uiSize, sImageInfo);
  if(i32Result != SIM_ERR_OK)
  {
    std::stringstream err;
    err << "Image Converter: No Image Parameter available for ProvidePortSize" << uiSize;
    m_pBaseInstance->ReportError(err_sev_error, SIM_ERR_UNDEFINED, err.str().c_str());
    return;
  }

  MFC::MFCEmbeddedData pEmbeddedData;
  DWORD dwSize = sizeof(pEmbeddedData.embeddedRegs);
  PVOID pRegs = &pEmbeddedData.embeddedRegs;
  //unsigned int retVal = ExtractEmbeddedData(pData, pRegs, dwSize, uiSize, sImageInfo);
  ExtractEmbeddedData(pData, pRegs, dwSize, uiSize, sImageInfo);

  // do a cross check of the written data
  unsigned __int64 qiValue0_2 = 0;
  unsigned __int64 qiValue1_2 = 0;
  unsigned __int64 qiValue2_2 = 0;
  unsigned __int64 qiValue3_2 = 0;

  for (USHORT index = 0; index < MFC::sNoOfRegs; ++index)
  {
    MFC::SPairData& reg = pEmbeddedData.embeddedRegs.regs[index];
    switch (reg.sAddress)
    {
    case 0x3102:
      qiValue0_2 = reg.sValue;
      continue; // no need to search anymore
    case 0x3104:
      qiValue1_2 = reg.sValue;
      continue; // no need to search anymore
    case 0x310C:
      qiValue2_2 = reg.sValue;
      continue; // no need to search anymore
    case 0x310E:
      qiValue3_2 = reg.sValue;
      continue; // no need to search anymore
    default:
      continue; // no need to search anymore
    }
  }

  unsigned __int64 uiTimestamp = (qiValue0_2 << 0) | (qiValue1_2 << 16) | (qiValue2_2 << 32) | (qiValue3_2 << 48);
  if (uiTimestamp != uiTimestampToBeSet)
  {
    m_pBaseInstance->ReportError(err_sev_error, 0, "Timestamp fix: Replacing error. Mismatch between actual and target timestamp detected.");
  }
}

bool CSimImageTimestampFix::IsRequiredDataAvailable()
{
  bool bEnableFlag = true;

  // general data loss handling
  for (ReceivePortMap_t::iterator i = m_receivePortMap.begin(); i != m_receivePortMap.end(); ++i)
  {
    SimReceivePortBase& port = *(i->first);
    SimReceivePortInfo& info = i->second;

    if (info.checkForData && (! port.isDirty()))
    {
      // increment error counter
      info.errorCount++;

      // disable plugin
      bEnableFlag = false;

      // report
      if (info.errorCount < MAX_REPORTED_PORT_ERRORS)
      {
        // print error message when below the counter
        std::stringstream err;
        err << "Input: " << port.name() << " data not received, ImageTimestampFix can't run.";

        m_pBaseInstance->ReportError(err_sev_error, 1, err.str().c_str());
      }
      else if (info.errorCount == MAX_REPORTED_PORT_ERRORS)
      {
        // print final error message
        std::stringstream err;
        err << "Input: " << port.name() << " data not received for " << info.errorCount << " cycles. No more Errors are generated";

        m_pBaseInstance->ReportError(err_sev_error, 1, err.str().c_str());
      }
    }
  }

  return bEnableFlag;
}

CVersionInfoImpl CSimImageTimestampFix::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

INT32 CSimImageTimestampFix::ExtractEmbeddedData(void *SrcImage, void* pDestImage, UINT32 dwDestSize, unsigned long ulPPortSize, MFC::SImageInfoStruct &imageInfo)
{
  LPBYTE puTempBuffer = static_cast<LPBYTE>(SrcImage);
  LPBYTE puTempDestBuffer = static_cast<LPBYTE>(pDestImage);
  DWORD dwTempBufferSize = ulPPortSize;
  DWORD dwTempDestSize = dwDestSize;

  INT32 nReturnCode = 0;
  if( imageInfo.m_bDarkStart1InfoLines + imageInfo.m_bStart2InfoLines > 16 /*m_bDefaultDarkInfoLines*/ )
    puTempBuffer += static_cast<DWORD>(MFC::m_bDefaultDarkInfoLines * imageInfo.m_unWidth * MFC::m_bImageUnitBytes / MFC::m_bImageUnitPixels);


  MFC::EmbeddedRegisters * pTmpEmbRegs;

  pTmpEmbRegs = reinterpret_cast<MFC::EmbeddedRegisters *>(puTempDestBuffer);

  USHORT usRegsCnt = 0;
  BYTE ubLineNo = 0;

  MFC::PixelAlignment *p3Bytes = reinterpret_cast<MFC::PixelAlignment*>(puTempBuffer);
  USHORT us12BitsValue = 0x009;
  BYTE ubEndOfLine;
  bool bIsRegAdr;

  while (ubLineNo < 2)
  {
    // - start of line
    // -- checking the EDF
    if (ubLineNo == 0)
      us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);

    if (us12BitsValue != 0x0A0)
      return 2;

    // -- extracting the registers addresses and values
    ubEndOfLine = 0;
    bIsRegAdr = false;
    do
    {
      // tag value (AA0 - MSB of reg adr; A50 - LSB of reg adr; 05A - reg val
      us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
      if (us12BitsValue == 0x070)
        ubEndOfLine++;
      else
        if (us12BitsValue == 0xAA0)
          bIsRegAdr = true;
        else
          bIsRegAdr = false;

      if (ubEndOfLine >= 2)
      {
        usRegsCnt--;
        break;
      }
      else
        ubEndOfLine = 0;

      p3Bytes++;

      // MSB of reg address/value
      us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
      if (bIsRegAdr)
        pTmpEmbRegs->regs[usRegsCnt].sAddress = us12BitsValue;
      else
      {
        REGISTER_MAP::iterator it = m_mapRegisterReplacements.find(pTmpEmbRegs->regs[usRegsCnt].sAddress);
        if (it != m_mapRegisterReplacements.end())
        {
          // write replacement value into memory
          unsigned short sValue = it->second;
          p3Bytes->bytes[0] = (BYTE)((sValue >> 4) & 0xf0);
          p3Bytes->bytes[1] = (BYTE)((p3Bytes->bytes[1] & 0x0f) + ((sValue >> 8) & 0xf0));
        }
        // read back again for later cross check
        us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
        pTmpEmbRegs->regs[usRegsCnt].sValue = us12BitsValue;
      }

      // tag value
      us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
      if (us12BitsValue == 0x070)
        ubEndOfLine++;
      else
        if (us12BitsValue == 0xA50)
          bIsRegAdr = true;
        else
          bIsRegAdr = false;

      p3Bytes++;

      // LSB of reg address/value
      us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
      if (bIsRegAdr)
      {
        pTmpEmbRegs->regs[usRegsCnt].sAddress = (pTmpEmbRegs->regs[usRegsCnt].sAddress << 4)
          + ((us12BitsValue & 0xff0) >> 4);
      }
      else
      {
        REGISTER_MAP::iterator it = m_mapRegisterReplacements.find(pTmpEmbRegs->regs[usRegsCnt].sAddress);
        if (it != m_mapRegisterReplacements.end())
        {
          // write replacement value into memory
          unsigned short sValue = it->second;
          p3Bytes->bytes[0] = (BYTE)((sValue << 4) & 0xf0);
          p3Bytes->bytes[1] = (BYTE)((p3Bytes->bytes[1] & 0x0f) + (sValue & 0xf0));
        }
        // read again for later cross check
        us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
        pTmpEmbRegs->regs[usRegsCnt].sValue = (pTmpEmbRegs->regs[usRegsCnt].sValue << 4)
        + ((us12BitsValue & 0xff0) >> 4);
      }

      if (!bIsRegAdr)
      {
        usRegsCnt++;
        pTmpEmbRegs->regs[usRegsCnt].sAddress = pTmpEmbRegs->regs[usRegsCnt-1].sAddress + 2;
        dwTempDestSize -= sizeof(MFC::SPairData);
      }

      dwTempBufferSize -= 2*sizeof(MFC::PixelAlignment);
    }
    while ( (dwTempDestSize >= sizeof(MFC::SPairData))
      && (dwTempBufferSize >= 6));

    // skipping all 0x070 filling values at the end (only for the 1st line)
    if (ubLineNo == 0)
    {
      while (us12BitsValue == 0x070)
      {
        p3Bytes++;
        us12BitsValue = p3Bytes->bytes[0] + ((p3Bytes->bytes[1] & 0xf0) << 4);
        if (us12BitsValue != 0x070)
          break;

        us12BitsValue = (p3Bytes->bytes[1] & 0x0f) + (p3Bytes->bytes[2] << 4);
        if (us12BitsValue != 0x070)
          break;

      }
    }
    else    // resetting the extra written reg line (only for the 2nd line)
      if ((ubLineNo == 1) && (ubEndOfLine >= 2))
      {
        pTmpEmbRegs->regs[usRegsCnt].sAddress = 0;
        pTmpEmbRegs->regs[usRegsCnt].sValue = 0;
        usRegsCnt--;
      }

      ubLineNo++;
  }

  return nReturnCode;
}

int CSimImageTimestampFix::GetImageParameter(unsigned long providePortSize, MFC::SImageInfoStruct &imageInfo)
{
  int i32Result = SIM_ERR_OK;
  switch(providePortSize)
  {
  case 571392:
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 0;
    imageInfo.m_bEndInfoLines = 0;
    imageInfo.m_unHeight = 372;
    imageInfo.m_unWidth = 1024;
    break;
  case 577536:
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 372;
    imageInfo.m_unWidth = 1024;
    break;
  case 989184:
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 640;
    imageInfo.m_unWidth = 1024;
    break;
  case 1136016:
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 640;
    imageInfo.m_unWidth = 1176;
    break;
  case 1164240:
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 640;
    imageInfo.m_unWidth = 1176;
    break;
  case 885528:
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 1176;
    break;
    //rectified image1
  case 615936:
    imageInfo.m_bDarkStart1InfoLines = 1;
    imageInfo.m_bStart2InfoLines = 0;
    imageInfo.m_bEndInfoLines = 0;
    imageInfo.m_unHeight = 400;
    imageInfo.m_unWidth = 1024;
    break;
    //rectified image2
  case 520704:
    imageInfo.m_bDarkStart1InfoLines = 1;
    imageInfo.m_bStart2InfoLines = 0;
    imageInfo.m_bEndInfoLines = 0;
    imageInfo.m_unHeight = 338;
    imageInfo.m_unWidth = 1024;
    break;
  case 798840 :
    // new added case for smaller imager ( for MFC 316 device )
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 630;
    imageInfo.m_unWidth = 840;
    break;
  case 612360 :
    // another new added case for smaller imager ( for MFC 316 device )
    imageInfo.m_bDarkStart1InfoLines = 0;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 840;
    break;
  case 1728720 :
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 960;
    imageInfo.m_unWidth = 1176;
    break;
  case 321048 :
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 182;
    imageInfo.m_unWidth = 1176;
    break;
    // SRLCam
    //long - new
    //(630+2+2+16)*832*3/2
  case  811200:
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 630;
    imageInfo.m_unWidth = 832;
    break;
    //short - new
    //(482+2+2+16)*832*3/2
  case  626496:
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 832;
    break;
    //short - backward compatibility
    //(482+2+2+16)*840*3/2
  case 632520 :
    // fourth new added case for smaller imager ( for MFC 316 device )
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 482;
    imageInfo.m_unWidth = 840;
    break;
    //long - backward compatibility
    //(630+2+2+16)*840*3/2
  case 819000 :
    // third new added case for smaller imager ( for MFC 316 device )
    imageInfo.m_bDarkStart1InfoLines = 16;
    imageInfo.m_bStart2InfoLines = 2;
    imageInfo.m_bEndInfoLines = 2;
    imageInfo.m_unHeight = 630;
    imageInfo.m_unWidth = 840;
    break;
  default:
    i32Result = SIM_ERR_INVALID_DATA_SIZE;
    break;
  }
  return i32Result;
}