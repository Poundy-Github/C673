/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_monitoring.cpp

  DESCRIPTION:     Conversion module

  AUTHOR:          Jakob Schluttig / Mohammad Altamash Yakoob

  CREATION DATE:   29.09.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_monitoring.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:49CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 2.2 2017/05/09 15:32:15CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS520/SRR520] Adapt ALN_AzimuthCorrections and ALN_Monitoring ports for ASample
  CHANGES:         Revision 2.1 2017/04/05 13:30:04CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx]
  CHANGES:         ? Remove A Sample compatilbility
  CHANGES:         ? Clean up SimAdapters
  CHANGES:         ? Only have version V100 and above
  CHANGES:         Revision 1.8 2017/02/15 15:55:42CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS510/SRR520] Update SimAdapter for the interface changes caused by removal of Elevation feature in SRR520
  CHANGES:         Revision 1.7 2016/07/15 12:43:11CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         added V100 for ARS510 B_Sample
  CHANGES:         Revision 1.6 2015/01/21 15:33:42CET Schluttig, Jakob (uidv7098) 
  CHANGES:         added v7
  CHANGES:         --- Added comments ---  uidv7098 [Jan 21, 2015 3:33:43 PM CET]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.5 2014/12/10 08:57:59CET Schluttig, Jakob (uidv7098) 
  CHANGES:         added v2 adapter
  CHANGES:         --- Added comments ---  uidv7098 [Dec 10, 2014 8:57:59 AM CET]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.4 2014/12/02 10:01:44CET Schluttig, Jakob (uidv7098) 
  CHANGES:         another bugfix :\
  CHANGES:         --- Added comments ---  uidv7098 [Dec 2, 2014 10:01:44 AM CET]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.3 2014/11/11 10:03:20CET Schluttig, Jakob (uidv7098) 
  CHANGES:         bugfix
  CHANGES:         --- Added comments ---  uidv7098 [Nov 11, 2014 10:03:20 AM CET]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.2 2014/11/10 16:30:58CET Schluttig, Jakob (uidv7098) 
  CHANGES:         added intf. version 6
  CHANGES:         --- Added comments ---  uidv7098 [Nov 10, 2014 4:30:58 PM CET]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.1 2014/09/29 15:16:07CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ALN_Alignment/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj
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
#include "sim_conv_aln_monitoring.h"
#include "sim_adapter_cfg.h"
#include "sim_versioninfo_impl.h"

// Commonly used type definitions
typedef unsigned long AlgoDataTimeStamp_t;
typedef unsigned short AlgoCycleCounter_t;
typedef unsigned char AlgoSignalState_t;

typedef unsigned char e_AlignState_t;

typedef struct SignalHeader_t
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;

// ALN_Monitoring_t version ASample
namespace ALN_Monitoring_t_Radar5xx_ASample
{
  typedef unsigned char e_Direction_t;
  typedef struct
  {
    float f_DirConfidence;
    e_Direction_t e_Direction;
    unsigned char a_Dummy[3];
  } Direction_t;

  typedef struct
  {
    float f_Misalignment;
    float f_Std;
    boolean b_ResultsAvailable;
    unsigned char u_Dummy[3];
  } ALN_t_MonitoringScan_t;

  typedef struct
  {
    float f_ObstacleRangeMax;
    float a_CurrentAzimuthStd;
    float f_CurrentElevationStd;
    float f_EgoSpeed;
    float f_EgoSpeedStandardDeviation;
    float f_ConfirmationEgoSpeed;
    AlgoDataTimeStamp_t u_TimeStamp;
    e_AlignState_t e_AlignState;
    unsigned char u_UpdateCounter;
    unsigned char u_ConfirmationUpdateCounter;
    unsigned char u_Dummy;
    Direction_t Direction;
  } ALN_t_ASampleDataStruct;

  typedef struct
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_t_MonitoringScan_t Azimuth;
    ALN_t_MonitoringScan_t Elevation;
    ALN_t_ASampleDataStruct ASampleDataStruct;
  } ALN_Monitoring_t;
}// ALN_Monitoring_t version ASample

// ALN_Monitoring_t version 100
namespace ALN_Monitoring_t_Radar5xx_V100
{
  typedef unsigned char e_Direction_t;

  typedef unsigned char a_Dummy_array_t[2];
  typedef unsigned char a_Dummy_array_t_0[3];
  typedef unsigned char u_Dummy_array_t_0[3];
  typedef unsigned char u_Dummy_array_t_1[3];

  typedef struct
  {
    float             f_DirConfidence;
    e_Direction_t     e_Direction;
    a_Dummy_array_t_0 a_Dummy;
  } DrivingDirection_t;

  typedef struct
  {
    float               f_EgoSpeed;
    float               f_EgoSpeedStandardDeviation;
    float               f_ConfirmationEgoSpeed;
    unsigned char       u_UpdateCounter;
    unsigned char       u_ConfirmationUpdateCounter;
    a_Dummy_array_t     a_Dummy;
    DrivingDirection_t  DrivingDirection;
  } EgoSpeed_t;

  typedef struct
  {
    float f_Probability;
    float f_Confidence;
  } PartialBlockage_t;

  typedef struct
  {
    float             f_Misalignment;
    float             f_Std;
    boolean           b_ResultsAvailable;
    u_Dummy_array_t_1 u_Dummy;
  } ALN_t_DegradationSafety_t;

  typedef struct
  {
    ALN_t_DegradationSafety_t DegradationSafety;
    float                     f_Correction;
    float                     f_DegradationComfortStd;
  } ALN_t_Information_t;

  typedef struct
  {
    unsigned long       u_VersionNumber;
    SignalHeader_t      sSigHeader;
    EgoSpeed_t          EgoSpeed;
    PartialBlockage_t   PartialBlockage;
    ALN_t_Information_t Azimuth;
    ALN_t_Information_t Elevation;
    float               f_ObstacleRangeMax;
    float               f_TunnelProbability;
    e_AlignState_t      e_AlignState;
    u_Dummy_array_t_0   u_Dummy;
  } ALN_Monitoring_t;
}// ALN_Monitoring_t version 100


// ALN_Monitoring_t version 101
namespace ALN_Monitoring_t_Radar5xx_V101
{
  typedef struct
  {
    unsigned long                                       u_VersionNumber;
    SignalHeader_t                                      sSigHeader;
    ALN_Monitoring_t_Radar5xx_V100::EgoSpeed_t          EgoSpeed;
    ALN_Monitoring_t_Radar5xx_V100::PartialBlockage_t   PartialBlockage;
    ALN_Monitoring_t_Radar5xx_V100::ALN_t_Information_t Azimuth;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_Monitoring_t_Radar5xx_V100::ALN_t_Information_t Elevation;
    float                                               f_ObstacleRangeMax;
#endif
    float                                               f_TunnelProbability;
    e_AlignState_t                                      e_AlignState;
    ALN_Monitoring_t_Radar5xx_V100::u_Dummy_array_t_0   u_Dummy;
  } ALN_Monitoring_t;
}// ALN_Monitoring_t version 101

// Generic ARS5xx & SRR5xx ALN_Monitoring_t
// Holds all possible structure members from all possible namespaces
namespace ALN_Monitoring_t_Radar5xx_Gen
{
  typedef struct
  {
    unsigned long                                               u_VersionNumber;
    SignalHeader_t                                              sSigHeader;
    ALN_Monitoring_t_Radar5xx_ASample::ALN_t_MonitoringScan_t   Azimuth_ASample;
    ALN_Monitoring_t_Radar5xx_ASample::ALN_t_MonitoringScan_t   Elevation_ASample;
    ALN_Monitoring_t_Radar5xx_ASample::ALN_t_ASampleDataStruct  DataStruct_ASample;
    ALN_Monitoring_t_Radar5xx_V100::EgoSpeed_t                  EgoSpeed_V100;
    ALN_Monitoring_t_Radar5xx_V100::PartialBlockage_t           PartialBlockage_V100;
    ALN_Monitoring_t_Radar5xx_V100::ALN_t_Information_t         Azimuth_V100;
    ALN_Monitoring_t_Radar5xx_V100::ALN_t_Information_t         Elevation_V100;
    float                                                       f_ObstacleRangeMax;
    float                                                       f_TunnelProbability;
    e_AlignState_t                                              e_AlignState;
  } ALN_Monitoring_t;
} // end of namespace ALN_Monitoring_t_Radar5xx_Gen


void Convert_ASample_to_Gen (ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t & Dest,
  const ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t & Src)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber       = Src.u_VersionNumber;
  Dest.sSigHeader            = Src.sSigHeader;
  // ASample
  Dest.Azimuth_ASample       = Src.Azimuth;
  Dest.Elevation_ASample     = Src.Elevation;
  Dest.DataStruct_ASample    = Src.ASampleDataStruct;
  // BSample
  Dest.EgoSpeed_V100.f_EgoSpeed = Src.ASampleDataStruct.f_EgoSpeed;
  Dest.EgoSpeed_V100.f_EgoSpeedStandardDeviation = Src.ASampleDataStruct.f_EgoSpeedStandardDeviation;
  Dest.EgoSpeed_V100.f_ConfirmationEgoSpeed = Src.ASampleDataStruct.f_ConfirmationEgoSpeed;
  Dest.EgoSpeed_V100.u_UpdateCounter = Src.ASampleDataStruct.u_UpdateCounter;
  Dest.EgoSpeed_V100.u_ConfirmationUpdateCounter = Src.ASampleDataStruct.u_ConfirmationUpdateCounter;
  Dest.EgoSpeed_V100.DrivingDirection.e_Direction = Src.ASampleDataStruct.Direction.e_Direction;
  Dest.EgoSpeed_V100.DrivingDirection.f_DirConfidence = Src.ASampleDataStruct.Direction.f_DirConfidence;
  Dest.PartialBlockage_V100.f_Probability = 0.f;
  Dest.PartialBlockage_V100.f_Confidence = 0.f;
  Dest.Azimuth_V100.DegradationSafety.f_Misalignment = Src.Azimuth.f_Misalignment;
  Dest.Azimuth_V100.DegradationSafety.f_Std = Src.Azimuth.f_Std;
  Dest.Azimuth_V100.DegradationSafety.b_ResultsAvailable = Src.Azimuth.b_ResultsAvailable;
  Dest.Azimuth_V100.f_Correction = 0.f;
  Dest.Azimuth_V100.f_DegradationComfortStd = Src.ASampleDataStruct.a_CurrentAzimuthStd;
  Dest.Elevation_V100.DegradationSafety.f_Misalignment = Src.Elevation.f_Misalignment;
  Dest.Elevation_V100.DegradationSafety.f_Std = Src.Elevation.f_Std;
  Dest.Elevation_V100.DegradationSafety.b_ResultsAvailable = Src.Elevation.b_ResultsAvailable;
  Dest.Elevation_V100.f_Correction = 0.f;
  Dest.Elevation_V100.f_DegradationComfortStd = Src.ASampleDataStruct.f_CurrentElevationStd;
  Dest.f_ObstacleRangeMax    = Src.ASampleDataStruct.f_ObstacleRangeMax;
  Dest.f_TunnelProbability   = 0.f;
  Dest.e_AlignState          = Src.ASampleDataStruct.e_AlignState;
}


void Convert_v100_to_Gen (ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t & Dest,
  const ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t & Src)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber       = Src.u_VersionNumber;
  Dest.sSigHeader            = Src.sSigHeader;
  // ASample --> Set to zero.. No use case of simulating BSample data in ASample build
  // BSample
  Dest.EgoSpeed_V100         = Src.EgoSpeed;
  Dest.PartialBlockage_V100  = Src.PartialBlockage;
  Dest.Azimuth_V100          = Src.Azimuth;
  Dest.Elevation_V100        = Src.Elevation;
  Dest.f_ObstacleRangeMax    = Src.f_ObstacleRangeMax;
  Dest.f_TunnelProbability   = Src.f_TunnelProbability;
  Dest.e_AlignState          = Src.e_AlignState;
}


void Convert_v101_to_Gen (ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t & Dest,
  const ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t & Src)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber      = Src.u_VersionNumber;
  Dest.sSigHeader           = Src.sSigHeader;
  // ASample --> Set to zero.. No use case of simulating BSample data in ASample build
  // BSample
  Dest.EgoSpeed_V100        = Src.EgoSpeed;
  Dest.PartialBlockage_V100 = Src.PartialBlockage;
  Dest.Azimuth_V100         = Src.Azimuth;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.Elevation_V100       = Src.Elevation;
  Dest.f_ObstacleRangeMax   = Src.f_ObstacleRangeMax;
#endif
  Dest.f_TunnelProbability  = Src.f_TunnelProbability;
  Dest.e_AlignState         = Src.e_AlignState;
}


void Convert_Gen_to_ASample (ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t & Dest,
  const ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t & Src)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber      = 7u;
  Dest.sSigHeader           = Src.sSigHeader;
  Dest.Azimuth              = Src.Azimuth_ASample;
  Dest.Elevation            = Src.Elevation_ASample;
  Dest.ASampleDataStruct    = Src.DataStruct_ASample;
}


void Convert_Gen_to_v100 (ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t & Dest,
  const ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t & Src)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber      = 100u;
  Dest.sSigHeader           = Src.sSigHeader;
  Dest.EgoSpeed             = Src.EgoSpeed_V100;
  Dest.PartialBlockage      = Src.PartialBlockage_V100;
  Dest.Azimuth              = Src.Azimuth_V100;
  Dest.Elevation            = Src.Elevation_V100;
  Dest.f_ObstacleRangeMax   = Src.f_ObstacleRangeMax;
  Dest.f_TunnelProbability  = Src.f_TunnelProbability;
  Dest.e_AlignState         = Src.e_AlignState;
}


void Convert_Gen_to_v101 (ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t & Dest,
  const ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t & Src)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber      = 101u;
  Dest.sSigHeader           = Src.sSigHeader;
  Dest.EgoSpeed             = Src.EgoSpeed_V100;
  Dest.PartialBlockage      = Src.PartialBlockage_V100;
  Dest.Azimuth              = Src.Azimuth_V100;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.Elevation            = Src.Elevation_V100;
  Dest.f_ObstacleRangeMax   = Src.f_ObstacleRangeMax;
#endif
  Dest.f_TunnelProbability  = Src.f_TunnelProbability;
  Dest.e_AlignState         = Src.e_AlignState;
}

class CConvAlnMonitoring : public CSimConverterBase
{
  ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t m_BufGen;
  ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t m_BufASample;
  ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t m_BufV100;
  ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t m_BufV101;

  static void InitGen(ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t & Params);
  static void InitASample(ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t & Params);
  static void InitV100(ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t & Params);
  static void InitV101(ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t & Params);

public:

  static const char *GetConverterTypeName()
  {
    return "ALNRteMonitoring";
  }

  CConvAlnMonitoring(void);
  virtual ~CConvAlnMonitoring(void);

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
  static CVersionInfoImpl VERSION101;

  enum ALNMonitoring
  {
    ALN_MONITORING_ASAMPLE,
    ALN_MONITORING_V100,
    ALN_MONITORING_V101,
    ALN_MONITORING_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[ALN_MONITORING_VERSION_COUNT];

  static CVersionInfoImpl * const VERSION_NUMBERS[ALN_MONITORING_VERSION_COUNT];

  bool PortSupported (SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;
};

CVersionInfoImpl CConvAlnMonitoring::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnMonitoring::VERSION_ASAMPLE(0, 0, 7);
CVersionInfoImpl CConvAlnMonitoring::VERSION100(0, 0, 100);
CVersionInfoImpl CConvAlnMonitoring::VERSION101(0, 0, 101);

const unsigned long CConvAlnMonitoring::SUPPORTED_SIZE[CConvAlnMonitoring::ALN_MONITORING_VERSION_COUNT] =
{
  sizeof(ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t),
  sizeof(ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t),
  sizeof(ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t)
};

CConvAlnMonitoring::CConvAlnMonitoring(void) : CSimConverterBase(NULL, 0), m_BufGen(), m_BufASample(), m_BufV100(), m_BufV101()
{
  InitGen(m_BufGen);
  InitASample(m_BufASample);
  InitV100(m_BufV100);
  InitV101(m_BufV101);
}

CVersionInfoImpl * const CConvAlnMonitoring::VERSION_NUMBERS[CConvAlnMonitoring::ALN_MONITORING_VERSION_COUNT]=
{
  &VERSION_ASAMPLE,
  &VERSION100,
  &VERSION101
};

CConvAlnMonitoring::~CConvAlnMonitoring(void)
{
}

bool CConvAlnMonitoring::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  if (ePortType == simOPAQUE_t)
  {
    for (i=0; (i<CConvAlnMonitoring::ALN_MONITORING_VERSION_COUNT) && (false == bResult); i++)
    {
      if (ulPortSize == SUPPORTED_SIZE[i])
      {
        // Check if version information is compatible - with extra care for simulators that do not set the version number at all...
        if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(CConvAlnMonitoring::VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}

void CConvAlnMonitoring::InitGen(ALN_Monitoring_t_Radar5xx_Gen::ALN_Monitoring_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  // Set to the highest number
  Params.u_VersionNumber = 101;
}

void CConvAlnMonitoring::InitASample(ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 7u;
}

void CConvAlnMonitoring::InitV100(ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 100u;
}

void CConvAlnMonitoring::InitV101(ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 101u;
}

long CConvAlnMonitoring::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  // First decide which version we are converting to
  if ((ulPPortSize == ulRPortSize)
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
  {
    // Seem to be identical size. Use data directly from provide port
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    )
  {
    // Source Port V101
    CConvAlnMonitoring::InitGen(m_BufGen);
    const ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t & Src = *reinterpret_cast<::ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t*>(pPPortData);
    Convert_v101_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    )
  {
    // Source Port V100
    CConvAlnMonitoring::InitGen(m_BufGen);
    const ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t & Src = *reinterpret_cast<::ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t*>(pPPortData);
    Convert_v100_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION_ASAMPLE)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    )
  {
    // Source Port ASample
    CConvAlnMonitoring::InitGen(m_BufGen);
    const ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t & Src = *reinterpret_cast<::ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t*>(pPPortData);
    Convert_ASample_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == sizeof(ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t)) && ((requestPortVersionInfo.Equals(&VERSION101)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V101
      CConvAlnMonitoring::InitV101(m_BufV101);
      ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t & Dest = /*reinterpret_cast<ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t &>*/(m_BufV101);
      Convert_Gen_to_v101(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t)) && ((requestPortVersionInfo.Equals(&VERSION100)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V100
      CConvAlnMonitoring::InitV100(m_BufV100);
      ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t & Dest = /*reinterpret_cast<ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t &>*/(m_BufV100);
      Convert_Gen_to_v100(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t)) && ((requestPortVersionInfo.Equals(&VERSION_ASAMPLE)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of ASample
      CConvAlnMonitoring::InitASample(m_BufASample);
      ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t & Dest = /*reinterpret_cast<ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t &>*/(m_BufASample);
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
long CConvAlnMonitoring::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION101.Equals(&requestPortVersionInfo))))
    {
      InitV101(m_BufV101);
      *pDefaultData = &m_BufV101;
      ulDefaultSize = sizeof(ALN_Monitoring_t_Radar5xx_V101::ALN_Monitoring_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION100.Equals(&requestPortVersionInfo))))
    {
      InitV100(m_BufV100);
      *pDefaultData = &m_BufV100;
      ulDefaultSize = sizeof(ALN_Monitoring_t_Radar5xx_V100::ALN_Monitoring_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION_ASAMPLE.Equals(&requestPortVersionInfo))))
    {
      InitASample(m_BufASample);
      *pDefaultData = &m_BufASample;
      ulDefaultSize = sizeof(ALN_Monitoring_t_Radar5xx_ASample::ALN_Monitoring_t);
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
bool CConvAlnMonitoring::IsVersionCompatibleWithType(
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
bool CConvAlnMonitoring::AreVersionsCompatible(
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
IConverter * CreateAlnMonitoringConvClass(void)
{
  return new CConvAlnMonitoring();
}
