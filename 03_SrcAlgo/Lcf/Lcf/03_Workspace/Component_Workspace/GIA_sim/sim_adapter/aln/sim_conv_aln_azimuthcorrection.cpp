/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_azimuthcorrection.cpp

  DESCRIPTION:     Conversion module

  AUTHOR:          Thomas Berndt / Mohammad Altamash Yakoob

  CREATION DATE:   21.10.2013

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_azimuthcorrection.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:48CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 2.2 2017/05/09 15:32:14CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS520/SRR520] Adapt ALN_AzimuthCorrections and ALN_Monitoring ports for ASample
  CHANGES:         Revision 2.1 2017/04/05 13:33:45CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx]
  CHANGES:         ? Remove A Sample compatilbility
  CHANGES:         ? Clean up SimAdapters
  CHANGES:         ? Only have version V100 and above
  CHANGES:         Revision 1.7.1.1 2016/09/21 14:21:43CEST Manea, Gabriela (ManeaG) 
  CHANGES:         Updated for SRR520 B Sample . 
  CHANGES:         Intermediate branch until the same file will be used for ARS and SRR .
  CHANGES:         Revision 1.7 2016/07/15 12:43:10CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         added V100 for ARS510 B_Sample
  CHANGES:         Revision 1.6 2015/01/30 15:10:01CET Schluttig, Jakob (uidv7098) 
  CHANGES:         added v4
  CHANGES:         --- Added comments ---  uidv7098 [Jan 30, 2015 3:10:01 PM CET]
  CHANGES:         Change Package : 279548:1 http://mks-psad:7002/im/viewissue?selection=279548
  CHANGES:         Revision 1.5 2014/09/29 15:31:01CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         corrected ConverterTypeName
  CHANGES:         --- Added comments ---  uidv7098 [Sep 29, 2014 3:31:01 PM CEST]
  CHANGES:         Change Package : 264784:1 http://mks-psad:7002/im/viewissue?selection=264784
  CHANGES:         Revision 1.4 2014/06/06 08:51:43CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         adapted version 6 for entry
  CHANGES:         --- Added comments ---  uidv7098 [Jun 6, 2014 8:51:44 AM CEST]
  CHANGES:         Change Package : 215877:1 http://mks-psad:7002/im/viewissue?selection=215877
  CHANGES:         Revision 1.3 2014/06/03 12:01:25CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Added Version 6 (which was announced with version number 3)
  CHANGES:         Additional element float f_Elevation;
  CHANGES:         --- Added comments ---  berndtt1 [Jun 3, 2014 12:04:23 PM CEST]
  CHANGES:         Change Package : 221167:2 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.2 2013/11/08 15:51:26CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Added Version 4 and 5
  CHANGES:         Version number doesn't correspond to transmitted version number!
  CHANGES:         --- Added comments ---  berndtt1 [Nov 11, 2013 7:13:06 AM CET]
  CHANGES:         Change Package : 193430:7 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:         Revision 1.1 2013/10/22 14:13:19CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_azimuthcorrection.h"
#include "sim_adapter_cfg.h"
#include "sim_versioninfo_impl.h"


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


//ALN_AzimuthCorrection_t version ASample
namespace ALN_AzimuthCorrection_t_Radar5xx_ASample
{
  typedef struct
  {
    float f_Misalignment;
    float f_Std;
    boolean b_ResultsAvailable;
    unsigned char u_Dummy[3];
  } ALN_t_MonitoringScan_t;

  typedef struct
  {
    ALN_t_MonitoringScan_t Elevation;
    float f_CurrentElevationStd;
  } Monitoring_t;

  typedef float a_AngleDeviations_array_t[721];

  typedef struct
  {
    float                     f_Azimuth,
                              f_Elevation,
                              f_TunnelProbability;
    a_AngleDeviations_array_t a_AngleDeviations;
    Monitoring_t              Monitoring;
  }ALN_t_ASampleDataStruct;

  typedef struct
  {
    unsigned long             u_VersionNumber;
    SignalHeader_t            sSigHeader;
    ALN_t_ASampleDataStruct   ASampleDataStruct;
  } ALN_AzimuthCorrection_t;
}


//ALN_AzimuthCorrection_t version 100
namespace ALN_AzimuthCorrection_t_Radar5xx_V100
{
  typedef float a_AngleDeviations_array_t[721];

  typedef struct
  {
    unsigned long             u_VersionNumber;
    SignalHeader_t            sSigHeader;
    float                     f_Azimuth;
    a_AngleDeviations_array_t a_AngleDeviations;
  } ALN_AzimuthCorrection_t;
}

// Generic ARS5xx & SRR5xx ALN_AzimuthCorrection_t
// Holds all possible structure members from all possible namespaces
namespace ALN_AzimuthCorrection_t_Radar5xx_Gen
{
  typedef struct
  {
    unsigned long                                                       u_VersionNumber;
    SignalHeader_t                                                      sSigHeader;
    ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_t_ASampleDataStruct   DataStruct_ASample;
    float                                                               f_Azimuth;
    ALN_AzimuthCorrection_t_Radar5xx_V100::a_AngleDeviations_array_t    a_AngleDeviations_V100;
  } ALN_AzimuthCorrection_t;
}


void Convert_ASample_to_Gen (ALN_AzimuthCorrection_t_Radar5xx_Gen::ALN_AzimuthCorrection_t & Dest,
  const ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t & Src)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  // ASample
  Dest.DataStruct_ASample              = Src.ASampleDataStruct;
  // BSample
  Dest.f_Azimuth                       = Src.ASampleDataStruct.f_Azimuth;
  memcpy (Dest.a_AngleDeviations_V100, Src.ASampleDataStruct.a_AngleDeviations, sizeof(Src.ASampleDataStruct.a_AngleDeviations));
}


void Convert_v100_to_Gen (ALN_AzimuthCorrection_t_Radar5xx_Gen::ALN_AzimuthCorrection_t & Dest,
                          const ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t & Src)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  // ASample --> Set to zero.. No use case of simulating BSample data in ASample build
  // BSample
  Dest.f_Azimuth                       = Src.f_Azimuth;
  memcpy (Dest.a_AngleDeviations_V100, Src.a_AngleDeviations, sizeof(Src.a_AngleDeviations));
}


void Convert_Gen_to_ASample (ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t & Dest,
  const ALN_AzimuthCorrection_t_Radar5xx_Gen::ALN_AzimuthCorrection_t & Src)
{
  Dest.u_VersionNumber                 = 4u;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.ASampleDataStruct               = Src.DataStruct_ASample;
}


void Convert_Gen_to_v100 (ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t & Dest,
                          const ALN_AzimuthCorrection_t_Radar5xx_Gen::ALN_AzimuthCorrection_t & Src)
{
  Dest.u_VersionNumber                 = 100u;
  Dest.sSigHeader                      = Src.sSigHeader;
  Dest.f_Azimuth                       = Src.f_Azimuth;
  memcpy (Dest.a_AngleDeviations, Src.a_AngleDeviations_V100, sizeof(Src.a_AngleDeviations_V100));
}

class CConvAlnAzimuthCorrection : public CSimConverterBase
{
  ALN_AzimuthCorrection_t_Radar5xx_Gen::ALN_AzimuthCorrection_t m_BufGen;
  ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t m_BufASample;
  ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t m_BufV100;

  static void InitGen(ALN_AzimuthCorrection_t_Radar5xx_Gen::ALN_AzimuthCorrection_t & Params);
  static void InitASample(ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t & Params);
  static void InitV100(ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t & Params);

public:

  static const char *GetConverterTypeName()
  {
    return "ALNAzimuthCorrection";
  }

  CConvAlnAzimuthCorrection(void);
  virtual ~CConvAlnAzimuthCorrection(void);

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
  static CVersionInfoImpl VERSION_ASAMPLE;
  static CVersionInfoImpl VERSION100;

  enum ALNAzimuthCorrection
  {
    ALN_AZIMUTHCORRECTION_ASAMPLE,
    ALN_AZIMUTHCORRECTION_V100,
    ALN_AZIMUTHCORRECTION_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[ALN_AZIMUTHCORRECTION_VERSION_COUNT];

  static CVersionInfoImpl * const VERSION_NUMBERS[ALN_AZIMUTHCORRECTION_VERSION_COUNT];

  bool PortSupported (SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;
};

CVersionInfoImpl CConvAlnAzimuthCorrection::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnAzimuthCorrection::VERSION_ASAMPLE(0, 0, 4);
CVersionInfoImpl CConvAlnAzimuthCorrection::VERSION100(0, 0, 100);

const unsigned long CConvAlnAzimuthCorrection::SUPPORTED_SIZE[CConvAlnAzimuthCorrection::ALN_AZIMUTHCORRECTION_VERSION_COUNT] =
{
  sizeof(ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t),
  sizeof(ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t)
};

CConvAlnAzimuthCorrection::CConvAlnAzimuthCorrection(void) : CSimConverterBase(NULL, 0), m_BufGen(), m_BufASample(), m_BufV100()
{
  InitGen(m_BufGen);
  InitASample(m_BufASample);
  InitV100(m_BufV100);
}

CVersionInfoImpl * const CConvAlnAzimuthCorrection::VERSION_NUMBERS[CConvAlnAzimuthCorrection::ALN_AZIMUTHCORRECTION_VERSION_COUNT]=
{
  &VERSION_ASAMPLE,
  &VERSION100
};

CConvAlnAzimuthCorrection::~CConvAlnAzimuthCorrection(void)
{
}

bool CConvAlnAzimuthCorrection::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  if (ePortType == simOPAQUE_t)
  {
    for (i=0; (i<CConvAlnAzimuthCorrection::ALN_AZIMUTHCORRECTION_VERSION_COUNT) && (false == bResult); i++)
    {
      if (ulPortSize == SUPPORTED_SIZE[i])
      {
        // Check if version information is compatible - with extra care for simulators that do not set the version number at all...
        if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(CConvAlnAzimuthCorrection::VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}

void CConvAlnAzimuthCorrection::InitGen(ALN_AzimuthCorrection_t_Radar5xx_Gen::ALN_AzimuthCorrection_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  // Set to the highest number
  Params.u_VersionNumber = 100u;
}


void CConvAlnAzimuthCorrection::InitASample(ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 4u;
}


void CConvAlnAzimuthCorrection::InitV100(ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 100u;
}


long CConvAlnAzimuthCorrection::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  // First decide which version we are converting to
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
  {
    // Seem to be identical size. Use data directly from provide port
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && (uDataVer == 100u))
  {
    // Source Port V100
    CConvAlnAzimuthCorrection::InitGen(m_BufGen);
    const ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t & Src = *reinterpret_cast<::ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t*>(pPPortData);
    Convert_v100_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION_ASAMPLE)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && (uDataVer == 4u))
  {
    // Source Port ASample
    CConvAlnAzimuthCorrection::InitGen(m_BufGen);
    const ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t & Src = *reinterpret_cast<::ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t*>(pPPortData);
    Convert_ASample_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == sizeof(ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t)) && ((requestPortVersionInfo.Equals(&VERSION100)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V100
      CConvAlnAzimuthCorrection::InitV100(m_BufV100);
      ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t & Dest = /*reinterpret_cast<ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t &>*/(m_BufV100);
      Convert_Gen_to_v100(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t)) && ((requestPortVersionInfo.Equals(&VERSION_ASAMPLE)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of ASample
      CConvAlnAzimuthCorrection::InitASample(m_BufASample);
      ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t & Dest = /*reinterpret_cast<ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t &>*/(m_BufASample);
      Convert_Gen_to_ASample(Dest, m_BufGen);
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
long CConvAlnAzimuthCorrection::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION100.Equals(&requestPortVersionInfo))))
    {
      InitV100(m_BufV100);
      *pDefaultData = &m_BufV100;
      ulDefaultSize = sizeof(ALN_AzimuthCorrection_t_Radar5xx_V100::ALN_AzimuthCorrection_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION_ASAMPLE.Equals(&requestPortVersionInfo))))
    {
      InitASample(m_BufASample);
      *pDefaultData = &m_BufASample;
      ulDefaultSize = sizeof(ALN_AzimuthCorrection_t_Radar5xx_ASample::ALN_AzimuthCorrection_t);
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
bool CConvAlnAzimuthCorrection::IsVersionCompatibleWithType(
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
bool CConvAlnAzimuthCorrection::AreVersionsCompatible(
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
IConverter * CreateAlnAzimuthCorrectionConvClass(void)
{
  return new CConvAlnAzimuthCorrection();
}
