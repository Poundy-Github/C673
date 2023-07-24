/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_rtereqhwconfig.h

  DESCRIPTION:     Conversion module

  AUTHOR:          Mohammad Altamash Yakoob

  CREATION DATE:   22.03.2017

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_rtereqhwconfig.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:52CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 2.1 2017/04/05 13:30:05CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx]
  CHANGES:         ? Remove A Sample compatilbility
  CHANGES:         ? Clean up SimAdapters
  CHANGES:         ? Only have version V100 and above
  CHANGES:         Revision 1.1 2017/03/22 12:48:38CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ALN_Alignment/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj
**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_rtereqhwconfig.h"
#include "sim_versioninfo_impl.h"
#include "sim_adapter_cfg.h"

// Commonly used type definitions
typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;

typedef unsigned long AlgoDataTimeStamp_t;
typedef unsigned short AlgoCycleCounter_t;
typedef unsigned char AlgoSignalState_t;

typedef struct SignalHeader_t
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;

/* Number of Channels */
#define ALN_SimInit_NumOfChannels (12u)

typedef struct
{
  signed short s_Real;
  signed short s_Imag;
} t_Complex16;

typedef t_Complex16 FPGA_t_PathComp[ALN_SimInit_NumOfChannels];

// ALN_ReqHWConfig_t version V100
namespace ALN_ReqHWConfig_t_Radar5xx_V100
{
  typedef struct  
  {
    FPGA_t_PathComp a_PathCompensations;
    boolean b_Changed;
    uint8   u_Dummy[3];
  } ALN_ReqHWConfigSiminit;
  
  typedef struct  
  {
    uint32 u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_ReqHWConfigSiminit PathCompensations;
  } ALN_ReqHWConfig;
}// ALN_ReqHWConfig_t version V100

// ALN_ReqHWConfig_t version V101
namespace ALN_ReqHWConfig_t_Radar5xx_V101
{
  typedef struct  
  {
    FPGA_t_PathComp a_PathCompensations;
  } ALN_ReqHWConfigSiminit;

  typedef struct  
  {
    uint32 u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_ReqHWConfigSiminit PathCompensations;
  } ALN_ReqHWConfig;
}// ALN_ReqHWConfig_t version V101

// Generic ARS5xx & SRR5xx ALN_ReqHWConfig_t
// Holds all possible structure members from all possible namespaces
namespace ALN_ReqHWConfig_t_Radar5xx_Gen
{
  typedef struct  
  {
    uint32 u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfigSiminit PathCompensations_V100;
    ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfigSiminit PathCompensations_V101;
  } ALN_ReqHWConfig;
}


class CConvAlnRteReqHwConfig : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char *DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig m_BufGen;
  ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig m_BufV100;
  ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig m_BufV101;

  static void InitGen(ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Params);
  static void InitV100(ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig & Params);
  static void InitV101(ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig & Params);

  // Conversions from provide port (input) to generic buffer
  void Convert_v100_to_Gen (ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Dest, const ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig & Src);
  void Convert_v101_to_Gen (ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Dest, const ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig & Src);

  // Conversions form generic buffer to receive port (output)
  void Convert_Gen_to_v100 (ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig & Dest, const ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Src);
  void Convert_Gen_to_v101 (ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig & Dest, const ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Src);

public:

  static const char *GetConverterTypeName()
  {
    return "ALN_RteReqHwConfig";
  }

  CConvAlnRteReqHwConfig(void);
  virtual ~CConvAlnRteReqHwConfig(void);

  const char *GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
  {
    delete this;
  }

  /** returns:
  *   SIM_ERR_OK - when this value can be used
  *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
  *                                  and the value from Provide Port must be used
  */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
  *   SIM_ERR_OK - when this value can be used
  *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
  *                                            and the default value from Request Port must be used
  */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    void **pDefaultData, unsigned long &ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo);

private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION100;
  static CVersionInfoImpl VERSION101;

  enum ALNRteReqHwConfig
  {
    ALN_REQ_HW_CONFIG_V100,
    ALN_REQ_HW_CONFIG_V101,
    ALN_REQ_HW_CONFIG_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[ALN_REQ_HW_CONFIG_VERSION_COUNT];
  static CVersionInfoImpl * const ALNREQHWCONFIG_VERSION_NUMBERS[ALN_REQ_HW_CONFIG_VERSION_COUNT];

  bool PortSupported (SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;

};

CVersionInfoImpl CConvAlnRteReqHwConfig::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnRteReqHwConfig::VERSION100(0, 0, 100);
CVersionInfoImpl CConvAlnRteReqHwConfig::VERSION101(0, 0, 101);

const unsigned long CConvAlnRteReqHwConfig::SUPPORTED_SIZE[CConvAlnRteReqHwConfig::ALN_REQ_HW_CONFIG_VERSION_COUNT] =
{
  sizeof(ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig),
  sizeof(ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig)
};

CVersionInfoImpl * const CConvAlnRteReqHwConfig::ALNREQHWCONFIG_VERSION_NUMBERS[CConvAlnRteReqHwConfig::ALN_REQ_HW_CONFIG_VERSION_COUNT]=
{
  &VERSION100,
  &VERSION101
};

CConvAlnRteReqHwConfig::CConvAlnRteReqHwConfig(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufGen(), m_BufV100(), m_BufV101()
{
}

CConvAlnRteReqHwConfig::~CConvAlnRteReqHwConfig(void)
{
}

bool CConvAlnRteReqHwConfig::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  if (ePortType == simOPAQUE_t)
  {
    for (i=0; (i<CConvAlnRteReqHwConfig::ALN_REQ_HW_CONFIG_VERSION_COUNT) && (false == bResult); i++)
    {
      if (ulPortSize == SUPPORTED_SIZE[i])
      {
        // Check if version information is compatible - with extra care for simulators that do not set the version number at all...
        if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(ALNREQHWCONFIG_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}


void CConvAlnRteReqHwConfig::InitV100(ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 100u;
}

void CConvAlnRteReqHwConfig::InitV101(ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 101u;
}

void CConvAlnRteReqHwConfig::InitGen(ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  // Set to the highest number
  Params.u_VersionNumber = 101u;
}

void CConvAlnRteReqHwConfig::Convert_v100_to_Gen (ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Dest, const ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig & Src)
{
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.PathCompensations_V100          = Src.PathCompensations;
  memcpy(&(Dest.PathCompensations_V101), &(Src.PathCompensations), sizeof(Dest.PathCompensations_V101));
}

void CConvAlnRteReqHwConfig::Convert_v101_to_Gen (ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Dest, const ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig & Src)
{
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.PathCompensations_V101          = Src.PathCompensations;
  memset(&(Dest.PathCompensations_V100), 0, sizeof(Dest.PathCompensations_V100));
  memcpy(&(Dest.PathCompensations_V100), &(Src.PathCompensations), sizeof(Src.PathCompensations));
}


void CConvAlnRteReqHwConfig::Convert_Gen_to_v100 (ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig & Dest, const ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Src)
{
  Dest.u_VersionNumber = 100u;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.PathCompensations               = Src.PathCompensations_V100;
}

void CConvAlnRteReqHwConfig::Convert_Gen_to_v101 (ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig & Dest, const ALN_ReqHWConfig_t_Radar5xx_Gen::ALN_ReqHWConfig & Src)
{
  Dest.u_VersionNumber = 101u;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.PathCompensations               = Src.PathCompensations_V101;
}

long CConvAlnRteReqHwConfig::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // If direct one:one copy possible then do that
  const CVersionInfoImpl uDataReqVersionInfo(0, 0, uDataVer);
  // If direct one:one copy possible then do that
  if ((ulPPortSize == ulRPortSize)
    && ((pProvidePortVersionInfo == NULL) /*|| (pProvidePortVersionInfo->Equals(&VERSION11)) */
    || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    /* do not explicitely check data version -> if size fits, just use it */
    && (requestPortVersionInfo.Equals(&uDataReqVersionInfo))
    /*&& ((uDataVer == 7u) || (uDataVer == 6u) || (uDataVer == 5u) || (uDataVer == 4u) || (uDataVer == 3u) || (uDataVer == 1) || (uDataVer == 0))*/)
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 101u) || (uDataVer == 0)))
  {
    // Source Port V101
    CConvAlnRteReqHwConfig::InitGen(m_BufGen);
    const ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig & Src = *reinterpret_cast<ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig*>(pPPortData);
    Convert_v101_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 100u) || (uDataVer == 0)))
  {
    // Source Port V100
    CConvAlnRteReqHwConfig::InitGen(m_BufGen);
    const ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig & Src = *reinterpret_cast<ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig*>(pPPortData);
    Convert_v100_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == sizeof(ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig)) && ((requestPortVersionInfo.Equals(&VERSION101)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V101
      CConvAlnRteReqHwConfig::InitV101(m_BufV101);
      ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig & Dest = m_BufV101;
      Convert_Gen_to_v101(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig)) && ((requestPortVersionInfo.Equals(&VERSION100)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V100
      CConvAlnRteReqHwConfig::InitV100(m_BufV100);
      ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig & Dest = m_BufV100;
      Convert_Gen_to_v100(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

/** returns:
*   SIM_ERR_OK - when this value can be used
*   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
*                                            and the default value from Request Port must be used
*/
long CConvAlnRteReqHwConfig::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION100.Equals(&requestPortVersionInfo))))
    {
      InitV100(m_BufV100);
      *pDefaultData = &m_BufV100;
      ulDefaultSize = sizeof(ALN_ReqHWConfig_t_Radar5xx_V100::ALN_ReqHWConfig);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION101.Equals(&requestPortVersionInfo))))
    {
      InitV101(m_BufV101);
      *pDefaultData = &m_BufV101;
      ulDefaultSize = sizeof(ALN_ReqHWConfig_t_Radar5xx_V101::ALN_ReqHWConfig);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // No conversion available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvAlnRteReqHwConfig::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize))
  {
    bResult = true;
  }
  else
  {
    bResult = (PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize));
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvAlnRteReqHwConfig::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Always allow same type/size ports to be bound together
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (providePortVersionInfo.Equals(&requestPortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    // Ports are different: conversion necessary and possible if provide & request port known
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize, &providePortVersionInfo);
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateAlnRteReqHwConfigConvClass(void)
{
  return new CConvAlnRteReqHwConfig();
}
