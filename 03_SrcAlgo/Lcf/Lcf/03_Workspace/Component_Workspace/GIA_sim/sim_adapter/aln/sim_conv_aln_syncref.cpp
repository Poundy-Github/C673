/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_syncref

  DESCRIPTION:     Conversion module

  AUTHOR:          Thomas Berndt / Mohammad Altamash Yakoob

  CREATION DATE:   31.01.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_syncref.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:54CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 2.1 2017/04/05 13:30:08CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx]
  CHANGES:         ? Remove A Sample compatilbility
  CHANGES:         ? Clean up SimAdapters
  CHANGES:         ? Only have version V100 and above
  CHANGES:         Revision 1.5 2016/09/06 14:57:21CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         added v3 (ARS510/SRR520 B Sample)
  CHANGES:         Revision 1.4 2014/05/21 16:22:47CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Bugfix: Converting the sSigHeader
  CHANGES:         - Added comments -  berndtt1 [Jun 3, 2014 9:34:11 AM CEST]
  CHANGES:         Change Package : 221167:2 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.3 2014/03/11 14:29:49CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         * ALN_MTS_MEAS_t_SyncRef_ARS4xx_V2 -> ALN_MTS_MEAS_t_SyncRef_ARS4xx_V2_1
  CHANGES:         + ALN_MTS_MEAS_t_SyncRef_ARS4xx_V2_2
  CHANGES:         --- Added comments ---  berndtt1 [Mar 11, 2014 4:42:37 PM CET]
  CHANGES:         Change Package : 221167:2 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.2 2014/02/07 08:43:50CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         - FCTSenErrorOutNear as in ALN_MTS_MEAS_t_SyncRef
  CHANGES:         --- Added comments ---  berndtt1 [Feb 7, 2014 9:01:06 AM CET]
  CHANGES:         Change Package : 216105:1 http://mks-psad:7002/im/viewissue?selection=216105
  CHANGES:         Revision 1.1 2014/01/31 15:10:16CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_syncref.h"
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



// ALN_MTS_MEAS_t_SyncRef version 100 (Initial version for Rardar5xx)
namespace ALN_t_SyncRef_Radar5xx_V100
{
  typedef struct
  {
    uint32         u_VersionNumber;
    SignalHeader_t sSigHeader;
    SignalHeader_t ALN_BSWIn;
    SignalHeader_t RSP_PreClusterHeader;
    SignalHeader_t RSP_ClusterList;
    SignalHeader_t VehDyn;
    SignalHeader_t VehPar;
    SignalHeader_t ALN_Nvm;
    SignalHeader_t FCTSenErrorOut;
  } ALN_MTS_MEAS_t_SyncRef;
}

// Generic ARS5xx & SRR5xx ALN_MTS_MEAS_t_SyncRef
// Holds all possible structure members from all possible namespaces
namespace ALN_t_SyncRef_Radar5xx_Gen
{
  typedef struct
  {
    uint32         u_VersionNumber;
    SignalHeader_t sSigHeader;
    SignalHeader_t ALN_BSWIn;
    SignalHeader_t RSP_PreClusterHeader;
    SignalHeader_t RSP_ClusterList;
    SignalHeader_t VehDyn;
    SignalHeader_t VehPar;
    SignalHeader_t ALN_Nvm;
    SignalHeader_t FCTSenErrorOut;
  } ALN_MTS_MEAS_t_SyncRef;
}


class CConvAlnSyncRef : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char *DEP_NAMES[];
  */

  // here we define the index of each dependency for quick access
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  ALN_t_SyncRef_Radar5xx_Gen::ALN_MTS_MEAS_t_SyncRef m_BufGen;
  ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef m_BufV100;

  // Initialization
  template <typename T> static void InitVersion (T & Dest, uint32 VersionNumber)
  {
    ::memset(&Dest, 0, sizeof(Dest));
    Dest.u_VersionNumber = VersionNumber;
  }

  // Conversions from provide port (input) to generic buffer
  void Convert_V100_to_Gen (const ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef & Src);

  // Conversions form generic buffer to receive port (output)
  void Convert_Gen_to_V100 (ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef & Dest);

public:

  static const char *GetConverterTypeName()
  {
    return "ALN_SM_t_SyncRef";
  }

  CConvAlnSyncRef(void);
  virtual ~CConvAlnSyncRef(void);

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

  enum SyncRefVersions
  {
    ALN_SYNC_REF_V100,
    SYNCREF_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[SYNCREF_VERSION_COUNT];

  static CVersionInfoImpl * const SYNCREF_VERSION_NUMBERS[SYNCREF_VERSION_COUNT];

  bool PortSupported (SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;

};

CVersionInfoImpl CConvAlnSyncRef::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnSyncRef::VERSION100(0, 0, 100);

const unsigned long CConvAlnSyncRef::SUPPORTED_SIZE[CConvAlnSyncRef::SYNCREF_VERSION_COUNT] =
{
  sizeof(ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef)
};

CVersionInfoImpl * const CConvAlnSyncRef::SYNCREF_VERSION_NUMBERS[CConvAlnSyncRef::SYNCREF_VERSION_COUNT]=
{
  &VERSION100
};


CConvAlnSyncRef::CConvAlnSyncRef(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufGen(), m_BufV100()
{
}

CConvAlnSyncRef::~CConvAlnSyncRef(void)
{
}

bool CConvAlnSyncRef::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  if (ePortType == simOPAQUE_t)
  {
    for (i=0; (i<CConvAlnSyncRef::SYNCREF_VERSION_COUNT) && (false == bResult); i++)
    {
      if (ulPortSize == SUPPORTED_SIZE[i])
      {
        // Check if version information is compatible - with extra care for simulators that do not set the version number at all...
        if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(SYNCREF_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}


void CConvAlnSyncRef::Convert_V100_to_Gen (const ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef & Src)
{
  m_BufGen.u_VersionNumber          = Src.u_VersionNumber;
  m_BufGen.sSigHeader               = Src.sSigHeader;
  m_BufGen.ALN_BSWIn                = Src.ALN_BSWIn;
  m_BufGen.RSP_PreClusterHeader     = Src.RSP_PreClusterHeader;
  m_BufGen.RSP_ClusterList          = Src.RSP_ClusterList;
  m_BufGen.VehDyn                   = Src.VehDyn;
  m_BufGen.VehPar                   = Src.VehPar;
  m_BufGen.ALN_Nvm                  = Src.ALN_Nvm;
  m_BufGen.FCTSenErrorOut           = Src.FCTSenErrorOut;
}


void CConvAlnSyncRef::Convert_Gen_to_V100 (ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef & Dest)
{
  Dest.u_VersionNumber      = 3u;
  Dest.sSigHeader           = m_BufGen.sSigHeader;
  Dest.ALN_BSWIn            = m_BufGen.ALN_BSWIn;
  Dest.RSP_PreClusterHeader = m_BufGen.RSP_PreClusterHeader;
  Dest.RSP_ClusterList      = m_BufGen.RSP_ClusterList;
  Dest.VehDyn               = m_BufGen.VehDyn;
  Dest.VehPar               = m_BufGen.VehPar;
  Dest.ALN_Nvm              = m_BufGen.ALN_Nvm;
  Dest.FCTSenErrorOut       = m_BufGen.FCTSenErrorOut;      
}

long CConvAlnSyncRef::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // If direct one:one copy possible then do that
  if ((ulPPortSize == ulRPortSize)
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    /* do not explicitly check data version -> if size fits, just use it */ )
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 100u) || (uDataVer == 3u)))
  {
    // Source Port V100 (also V3)
    InitVersion(m_BufGen, 100u);
    const ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef & Src = *reinterpret_cast<::ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef*>(pPPortData);
    Convert_V100_to_Gen(Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == sizeof(ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef)) && ((requestPortVersionInfo.Equals(&VERSION100)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V100
      InitVersion(m_BufV100, 100u);
      ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef & Dest = /*reinterpret_cast<ALN_t_SyncRef_Radar5xx_V3::ALN_MTS_MEAS_t_SyncRef &>*/(m_BufV100);
      Convert_Gen_to_V100(Dest);
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
long CConvAlnSyncRef::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_t_SyncRef_Radar5xx_V100::ALN_MTS_MEAS_t_SyncRef)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION100))))
    {
      InitVersion(m_BufV100, 100u);
      *pDefaultData = &m_BufV100;
      ulDefaultSize = sizeof(m_BufV100);
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
bool CConvAlnSyncRef::IsVersionCompatibleWithType(
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
bool CConvAlnSyncRef::AreVersionsCompatible(
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
IConverter * CreateAlnSyncRefConvClass(void)
{
  return new CConvAlnSyncRef();
}
