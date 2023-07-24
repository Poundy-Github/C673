/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_rsp1_peaklist.cpp

  DESCRIPTION:          Convert

  AUTHOR:               Thomas Berndt

  CREATION DATE:        14.01.2016

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_rsp1_peaklist.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:35CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.3 2016/08/18 13:31:50CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Version V2 (=V100)
  CHANGES:              Revision 1.2 2016/08/17 13:49:30CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Bugfix Version Number
  CHANGES:              Revision 1.1 2016/08/11 09:45:53CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */

/* includes ---------------------------------------------------------------- */
#include <atlbase.h>                                                 // ATL includes, used by CSimConverterBase
#include "sim_adapter_cfg.h"
#include "sim_conv_rsp1_peaklist.h"

#include "sim_versioninfo_impl.h"

// Makros

#define _MINI(x,y) (x<y?x:y)

// Structure and type definitions that are used by all namespaces and are common.

typedef unsigned long AlgoDataTimeStamp_t;                           /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */
typedef unsigned short AlgoCycleCounter_t;                           /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */
typedef unsigned char AlgoSignalState_t;                             /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */

typedef struct SignalHeader_t                                        /* [Satisfies_rte sws 1191] */
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;                                                    /* Common header for all structured data types */

// Namespaces with the versioned structure(s)

namespace RSP1_PeakList_V1
{
  typedef unsigned __int16 a_BeamformerMain_array_t[16];
  typedef unsigned __int16 a_Beamformer_array_t[16];
  typedef unsigned __int16 a_BeamformerDopplerP_array_t[16];
  typedef unsigned __int16 a_BeamformerDopplerNext_array_t[16];
  typedef unsigned __int16 a_BeamformerRangePrev_array_t[16];
  typedef unsigned __int16 a_BeamformerRangeNext_array_t[16];

  typedef struct
  {
    signed __int8 s_Real;
    signed __int8 s_Imag;
  } t_Complex8;

  typedef t_Complex8 t_Channels[16];

  typedef unsigned __int8 u_FourByteAlignment_array_t[3];
  typedef unsigned __int32 u_ThirtyTwoByteAlignment_array_t[5];

  typedef struct
  {
    a_BeamformerMain_array_t a_BeamformerMain;
    a_Beamformer_array_t a_Beamformer;
    a_BeamformerDopplerP_array_t a_BeamformerDopplerP;
    a_BeamformerDopplerNext_array_t a_BeamformerDopplerNext;
    a_BeamformerRangePrev_array_t a_BeamformerRangePrev;
    a_BeamformerRangeNext_array_t a_BeamformerRangeNext;
    t_Channels a_Channels;
    t_Channels a_ChannelsDopplerPrev;
    t_Channels a_ChannelsDopplerNext;
    unsigned __int16 u_BitFieldBeams;
    unsigned __int16 u_IdxDoppler;
    unsigned __int16 u_PowMax;
    unsigned __int8 u_IdxMax;
    unsigned __int8 u_IdxMaxPrevDoppler;
    unsigned __int8 u_IdxMaxNextDoppler;
    u_FourByteAlignment_array_t u_FourByteAlignment;
    u_ThirtyTwoByteAlignment_array_t u_ThirtyTwoByteAlignment;
  } RSP_t_Peak;

  typedef RSP_t_Peak a_Peaks_array_t[64];

  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    a_Peaks_array_t a_Peaks;
  } RSP_t_PeakList;
}

namespace RSP1_PeakList_V100
{
  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    RSP1_PeakList_V1::a_Peaks_array_t a_Peaks;
  } RSP_t_PeakList;
}

// Generic namespace and structure, which includes all variances of the versioned namespaces

namespace RSP1_PeakList_GenAll
{
  typedef struct
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    RSP1_PeakList_V1::a_Peaks_array_t a_Peaks;
  } RSP_t_PeakList;
}


class CConvRsp1PeakList : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  //static const TCHAR *DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  RSP1_PeakList_GenAll::RSP_t_PeakList m_Buf_GenAll;
  RSP1_PeakList_V1::RSP_t_PeakList m_Buf_V1;
  RSP1_PeakList_V100::RSP_t_PeakList m_Buf_V100;

public:

  CConvRsp1PeakList(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT)
  {
    InitRsp1PeakList(m_Buf_V1, 1);
    InitRsp1PeakList(m_Buf_V100, 100);
    InitRsp1PeakList(m_Buf_GenAll, 100);
  };


  // Not implemented copy constructor to get linker error
  CConvRsp1PeakList(const CConvRsp1PeakList & init);

  virtual ~CConvRsp1PeakList(void)
  {
  };

  // IConverterDestroy::Destroy implementation
  virtual void Destroy()
  {
    delete this;
  };

  // IConverter::GetTypeName implementation
  virtual const char *GetTypeName(void)
  {
    return "RSP1_PeakList";
  };

  // Initialization of header
  template <typename T> static void InitRsp1PeakList (T & Dest, unsigned long VersionNumber)
  {
    ::memset(&(Dest), 0, sizeof(Dest));
    Dest.uiVersionNumber = VersionNumber;
  }

  /* **************************************************************************** 
    @fn            IsPortSupported */ /*!  
    @brief         Check Port for support
    @description   Used to check if a given port is in the list(s) of supported versions.
                   The version info is in the arrays VERSION_NUMBERS and SUPPORTED_SIZE
    @return        bool
    @param[in]     unsigned long ulPortSize
    @param[in]     const IVersionInfo *pPortVersion
    @pre           
    @post          (no changes)
    @date          07.01.2016
    @todo          
    @author        Thomas Berndt
  **************************************************************************** */
  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < FCT_PEAKLIST_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(VERSION_NUMBERS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   *   SIM_ERR_UNADAPTABLE_DATA_PORTS - if a conversion is needed but isn't possible (not implemented)
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                          and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void **pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);
private:
  static void Convert_V1_to_V100(RSP1_PeakList_V100::RSP_t_PeakList & Dest, const RSP1_PeakList_V1::RSP_t_PeakList & Src);
  static void Convert_V100_to_V1(RSP1_PeakList_V1::RSP_t_PeakList & Dest, const RSP1_PeakList_V100::RSP_t_PeakList & Src);

  //static void Convert_V1_to_Gen(RSP1_PeakList_GenAll::RSP_t_PeakList & Dest, const RSP1_PeakList_V1::RSP_t_PeakList & Src);
  //static void Convert_V100_to_Gen(RSP1_PeakList_GenAll::RSP_t_PeakList & Dest, const RSP1_PeakList_V100::RSP_t_PeakList & Src);
  //static void Convert_Gen_to_V100(RSP1_PeakList_V100::RSP_t_PeakList & Dest, const RSP1_PeakList_GenAll::RSP_t_PeakList & Src);
  //static void Convert_Gen_to_V1(RSP1_PeakList_V1::RSP_t_PeakList & Dest, const RSP1_PeakList_GenAll::RSP_t_PeakList & Src);

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl Version1;
  static CVersionInfoImpl Version2;
  static CVersionInfoImpl Version100;

  enum E_RSP1_PEAKLIST
  {
    RSP1_PEAKLIST_V1,
    RSP1_PEAKLIST_V2,
    RSP1_PEAKLIST_V100,
    FCT_PEAKLIST_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[FCT_PEAKLIST_VERSION_COUNT];

  static const CVersionInfoImpl * const VERSION_NUMBERS[FCT_PEAKLIST_VERSION_COUNT];
};

//const TCHAR *CConvRsp1PeakList::DEP_NAMES[CConvRsp1PeakList::DEP_COUNT] = {_T(""), _T(""), _T("")};

CVersionInfoImpl CConvRsp1PeakList::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvRsp1PeakList::Version1(0, 0, 1);
CVersionInfoImpl CConvRsp1PeakList::Version2(0, 0, 2);
CVersionInfoImpl CConvRsp1PeakList::Version100(0, 1, 0);

const unsigned long CConvRsp1PeakList::SUPPORTED_SIZE[CConvRsp1PeakList::FCT_PEAKLIST_VERSION_COUNT]=
{
  sizeof(RSP1_PeakList_V1::RSP_t_PeakList),
  sizeof(RSP1_PeakList_V100::RSP_t_PeakList),
  sizeof(RSP1_PeakList_V100::RSP_t_PeakList)
};

const CVersionInfoImpl * const CConvRsp1PeakList::VERSION_NUMBERS[CConvRsp1PeakList::FCT_PEAKLIST_VERSION_COUNT] =
{
  &Version1,
  &Version2,
  &Version100
};

// conversion functions: For every version there is one to convert to generic structure and one to convert from generic
void CConvRsp1PeakList::Convert_V1_to_V100(RSP1_PeakList_V100::RSP_t_PeakList & Dest, const RSP1_PeakList_V1::RSP_t_PeakList & Src)
{
  static unsigned char TransTable[16] = { 1, 3, 5, 7, 9, 11, 0, 2, 4, 6, 8, 10, 12, 13, 14, 15 };

  memcpy (&Dest, &Src, sizeof(Src));
  Dest.uiVersionNumber = 0x100;
  for (int nI = 0; nI < 64; nI++)
  {
    for (int nJ = 0; nJ < /*16*/12; nJ++)                                      // Important: Changing the TransTable in the last 4 Elements -> Adapt end value
    {
      Dest.a_Peaks[nI].a_Channels[TransTable[nJ]] = Src.a_Peaks[nI].a_Channels[nJ];
    }
  }
}

void CConvRsp1PeakList::Convert_V100_to_V1(RSP1_PeakList_V1::RSP_t_PeakList & Dest, const RSP1_PeakList_V100::RSP_t_PeakList & Src)
{
  static unsigned char TransTable[16] = { 6, 0, 7, 1, 8, 2, 9, 3, 10, 4, 11, 5, 12, 13, 14, 15 };

  memcpy (&Dest, &Src, sizeof(Src));
  Dest.uiVersionNumber = 0x100;
  for (int nI = 0; nI < 64; nI++)
  {
    for (int nJ = 0; nJ < /*16*/12; nJ++)                                      // Important: Changing the TransTable in the last 4 Elements -> Adapt end value
    {
      Dest.a_Peaks[nI].a_Channels[TransTable[nJ]] = Src.a_Peaks[nI].a_Channels[nJ];
    }
  }
}

//void CConvRsp1PeakList::Convert_V1_to_Gen(RSP1_PeakList_GenAll::RSP_t_PeakList & Dest, const RSP1_PeakList_V1::RSP_t_PeakList & Src)
//{
//  memcpy (&Dest, &Src, sizeof(Src));
//  Dest.uiVersionNumber = Src.uiVersionNumber;
//  Dest.sSigHeader = Src.sSigHeader;
//}
//
//void CConvRsp1PeakList::Convert_V100_to_Gen(RSP1_PeakList_GenAll::RSP_t_PeakList & Dest, const RSP1_PeakList_V100::RSP_t_PeakList & Src)
//{
//  memcpy (&Dest, &Src, sizeof(Src));
//  Dest.uiVersionNumber = Src.uiVersionNumber;
//  Dest.sSigHeader = Src.sSigHeader;
//}
//
//void CConvRsp1PeakList::Convert_Gen_to_V100(RSP1_PeakList_V100::RSP_t_PeakList & Dest, const RSP1_PeakList_GenAll::RSP_t_PeakList & Src)
//{
//  memcpy (&Dest, &Src, sizeof(Src));
//  Dest.uiVersionNumber = Src.uiVersionNumber;
//  Dest.sSigHeader = Src.sSigHeader;
//}
//
//void CConvRsp1PeakList::Convert_Gen_to_V1(RSP1_PeakList_V1::RSP_t_PeakList & Dest, const RSP1_PeakList_GenAll::RSP_t_PeakList & Src)
//{
//  memcpy (&Dest, &Src, sizeof(Src));
//  Dest.uiVersionNumber = Src.uiVersionNumber;
//  Dest.sSigHeader = Src.sSigHeader;
//}


long CConvRsp1PeakList::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;

  const unsigned __int32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned __int32*>(pPPortData)):(0);

  // First decide which version we are converting to
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    // If ports equal AND version numbers are equal, then always compatible
    // pProvidePortVersionInfo is always NULL, because data source is UDEX
    if ((ulRPortSize == ulPPortSize) &&
      ((requestPortVersionInfo.Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V100]) && (uDataVer == 0x100)) ||
      (requestPortVersionInfo.Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V2]) && (uDataVer == 2u)) ||
      (requestPortVersionInfo.Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V1]) && (uDataVer == 1u)) ) )
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    // Conversion A Sample to B Sample
    else if ((uDataVer == 1u) &&
      (requestPortVersionInfo.Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V2]) ||
      requestPortVersionInfo.Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V100])))
    {
      // Source port V1 of ARS510 and destination port V100 of ARS510
      const RSP1_PeakList_V1::RSP_t_PeakList & Src = *reinterpret_cast<RSP1_PeakList_V1::RSP_t_PeakList*>(pPPortData);
      Convert_V1_to_V100(m_Buf_V100, Src);
      bGenBufferFilled = false;
      *pOutData = &m_Buf_V100;
      ulOutSize = sizeof(m_Buf_V100);
      lRet = SIM_ERR_OK;
    }
    else if (((uDataVer == 2u) || (uDataVer == 0x100u)) &&
      requestPortVersionInfo.Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V1]))
    {
      // Source port V2/V100 of ARS510 and destination port V1 of ARS510
      const RSP1_PeakList_V100::RSP_t_PeakList & Src = *reinterpret_cast<RSP1_PeakList_V100::RSP_t_PeakList*>(pPPortData);
      Convert_V100_to_V1(m_Buf_V1, Src);
      bGenBufferFilled = false;
      *pOutData = &m_Buf_V1;
      ulOutSize = sizeof(m_Buf_V1);
      lRet = SIM_ERR_OK;
    }
    //// First decide from which version we are converting and fill the generic buffer accordingly
    //else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PEAKLIST_V100])
    //  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V100])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    //  && (uDataVer == 100u))
    //{
    //  // Source Port V100 of ARS4xx
    //  InitRsp1PeakList(m_Buf_GenAll, 4);
    //  const RSP1_PeakList_V100::RSP_t_PeakList & Src = *reinterpret_cast<RSP1_PeakList_V100::RSP_t_PeakList*>(pPPortData);
    //  Convert_V100_to_Gen(m_Buf_GenAll, Src);
    //  bGenBufferFilled = true;
    //}
    //else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_PEAKLIST_V1])
    //  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    //  && (uDataVer == 1u))
    //{
    //  // Source Port V1 of ARS4xx
    //  InitRsp1PeakList(m_Buf_GenAll, 4);
    //  const RSP1_PeakList_V1::RSP_t_PeakList & Src = *reinterpret_cast<RSP1_PeakList_V1::RSP_t_PeakList*>(pPPortData);
    //  Convert_V1_to_Gen(m_Buf_GenAll, Src);
    //  bGenBufferFilled = true;
    //}

    //if (bGenBufferFilled == true)
    //{
    //  // Second decide to which version we are converting
    //  // and take the generic buffer to fill the destination buffer
    //  if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PEAKLIST_V100]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V100])))
    //  {
    //    // Destination port of V2 of ARS4xx
    //    InitRsp1PeakList(m_Buf_V100, 100);
    //    Convert_Gen_to_V100(m_Buf_V100, m_Buf_GenAll);
    //    *pOutData = &m_Buf_V100;
    //    ulOutSize = sizeof(m_Buf_V100);
    //    lRet = SIM_ERR_OK;
    //  }
    //  else if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PEAKLIST_V1]) && (requestPortVersionInfo.Equals(VERSION_NUMBERS[RSP1_PEAKLIST_V1])))
    //  {
    //    // Destination port of V1 of ARS4xx
    //    InitRsp1PeakList(m_Buf_V1, 1);
    //    Convert_Gen_to_V1(m_Buf_V1, m_Buf_GenAll);
    //    *pOutData = &m_Buf_V1;
    //    ulOutSize = sizeof(m_Buf_V1);
    //    lRet = SIM_ERR_OK;
    //  }
    //}
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvRsp1PeakList::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PEAKLIST_V100]) &&
      (VERSION_NUMBERS[RSP1_PEAKLIST_V100]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PeakList_V100::RSP_t_PeakList & Dest = m_Buf_V100;
      InitRsp1PeakList(Dest, 2);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[RSP1_PEAKLIST_V1]) &&
      (VERSION_NUMBERS[RSP1_PEAKLIST_V1]->Equals(&requestPortVersionInfo)))
    {
      RSP1_PeakList_V1::RSP_t_PeakList & Dest = m_Buf_V1;
      InitRsp1PeakList(Dest, 1);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRsp1PeakList::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvRsp1PeakList::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // If ports equal, then always compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// The one and only externally visible factory function
//
IConverter * CreateRsp1PeakListConvInstance(void)
{
  return new CConvRsp1PeakList();
}