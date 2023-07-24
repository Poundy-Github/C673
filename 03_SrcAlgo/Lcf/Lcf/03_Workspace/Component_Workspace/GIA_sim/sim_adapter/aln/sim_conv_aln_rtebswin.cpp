/*! \file **********************************************************************

COMPANY:         Continental

PROJECT:         Simulation

COMPONENT:       sim_adapter aln

MODULNAME:       sim_conv_aln_rtebswin

DESCRIPTION:     Conversion module

AUTHOR:          Thomas Berndt / Mohammad Altamash Yakoob

CREATION DATE:   23.08.2013

VERSION:         $Revision: 1.1 $

---*/ /*---
CHANGES:         $Log: sim_conv_aln_rtebswin.cpp  $
CHANGES:         Revision 1.1 2017/08/10 13:14:50CEST uid34177 
CHANGES:         Initial revision
CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
CHANGES:         Revision 2.1 2017/04/05 13:30:08CEST Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         [ARS5xx/SRR5xx]
CHANGES:         ? Remove A Sample compatilbility
CHANGES:         ? Clean up SimAdapters
CHANGES:         ? Only have version V100 and above
CHANGES:         Revision 1.27 2017/02/15 15:55:39CET Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         [ARS510/SRR520] Update SimAdapter for the interface changes caused by removal of Elevation feature in SRR520
CHANGES:         Revision 1.26 2017/02/08 15:31:58CET Dagli-EXT, Goekhan (uidj7850) 
CHANGES:         bugfix of conversion and init of V11
CHANGES:         Revision 1.25 2017/02/02 16:34:37CET Yakoob, Mohammad Altamash (uidj9850) 
CHANGES:         [ARS400 PR] Partial blockage: provide internal data at output to BSW --> Update simulation adapters
CHANGES:         Revision 1.24 2016/09/05 14:03:37CEST Schluttig, Jakob (uidv7098) 
CHANGES:         fixed a sample HWSample number for A1 variant (269 instead of 4096 as wrongly written in earlier algo_common)
CHANGES:         Revision 1.23 2016/09/05 13:54:52CEST Schluttig, Jakob (uidv7098) 
CHANGES:         added version 10 v2 to correctly match ARS510 A Sample input data
CHANGES:         Revision 1.22 2016/08/10 13:45:02CEST Berndt, Thomas01 (berndtt1) 
CHANGES:         New Version V100 for ARS510
CHANGES:         Revision 1.21 2016/08/08 15:18:34CEST Berndt, Thomas01 (berndtt1) 
CHANGES:         New Version V100 for ARS510 (Only the namespace)
CHANGES:         Revision 1.20 2016/03/01 15:00:06CET Schluttig, Jakob (uidv7098) 
CHANGES:         bugfix for v10 adaption ; changed compatibility check to generic concept
CHANGES:         Revision 1.19 2015/07/30 09:34:20CEST Schluttig, Jakob (uidv7098) 
CHANGES:         + new IF version 10: added b_EolTargetIsCorner , updated interface version number, size is the same as V8_2 and V9_1
CHANGES:         - Added comments -  uidv7098 [Jul 30, 2015 9:34:20 AM CEST]
CHANGES:         Change Package : 361863:1 http://mks-psad:7002/im/viewissue?selection=361863
CHANGES:         Revision 1.18 2015/07/13 10:09:01CEST Berndt, Thomas01 (berndtt1) 
CHANGES:         + new IF version 9: added b_DrivingLevelDeadjusted, updated interface version number, size is the same as V8_2
CHANGES:         --- Added comments ---  berndtt1 [Jul 13, 2015 10:14:41 AM CEST]
CHANGES:         Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
CHANGES:         Revision 1.17 2014/11/10 16:07:08CET Schluttig, Jakob (uidv7098) 
CHANGES:         added new IF vers. 8 including b_EolInspection flag also for ARS400 (unfortunately, interface version number was not updated)
CHANGES:         --- Added comments ---  uidv7098 [Nov 10, 2014 4:07:08 PM CET]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.16 2014/10/09 16:24:58CEST Manea, Gabriela (ManeaG) 
CHANGES:         small fix for V8 (SRR projects)
CHANGES:         --- Added comments ---  ManeaG [Oct 9, 2014 4:24:58 PM CEST]
CHANGES:         Change Package : 263320:1 http://mks-psad:7002/im/viewissue?selection=263320
CHANGES:         Revision 1.15 2014/09/29 17:23:26CEST Schluttig, Jakob (uidv7098) 
CHANGES:         added interface V8
CHANGES:         --- Added comments ---  uidv7098 [Sep 29, 2014 5:23:27 PM CEST]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.14 2014/09/15 15:03:42CEST Schluttig, Jakob (uidv7098) 
CHANGES:         fixed intf. version 7 for ARS400
CHANGES:         --- Added comments ---  uidv7098 [Sep 15, 2014 3:03:42 PM CEST]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.13 2014/07/23 17:10:57CEST Schluttig, Jakob (uidv7098) 
CHANGES:         always allow direct copy (do not explicitely check for intf version number in case of correct size)
CHANGES:         Revision 1.12 2014/07/10 15:48:03CEST Manea, Gabriela (ManeaG) 
CHANGES:         added intf-version-no. 7 for SRR
CHANGES:         --- Added comments ---  ManeaG [Jul 10, 2014 3:48:03 PM CEST]
CHANGES:         Change Package : 212023:2 http://mks-psad:7002/im/viewissue?selection=212023
CHANGES:         Revision 1.11 2014/07/08 16:23:57CEST Schluttig, Jakob (uidv7098) 
CHANGES:         added new IF versions for direct copy
CHANGES:         --- Added comments ---  uidv7098 [Jul 8, 2014 4:23:57 PM CEST]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.10 2014/05/08 09:11:40CEST Schluttig, Jakob (uidv7098) 
CHANGES:         fixed compiler warning (implicit cast)
CHANGES:         --- Added comments ---  uidv7098 [May 8, 2014 9:11:41 AM CEST]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.9 2014/04/04 11:27:51CEST Schluttig, Jakob (uidv7098) 
CHANGES:         added earlier Entry interface
CHANGES:         --- Added comments ---  uidv7098 [Apr 4, 2014 11:27:51 AM CEST]
CHANGES:         Change Package : 215877:1 http://mks-psad:7002/im/viewissue?selection=215877
CHANGES:         Revision 1.7 2014/03/24 14:51:28CET Schluttig, Jakob (uidv7098) 
CHANGES:         added intf-version-no. 5 for SRR
CHANGES:         --- Added comments ---  uidv7098 [Mar 24, 2014 2:51:28 PM CET]
CHANGES:         Change Package : 208727:1 http://mks-psad:7002/im/viewissue?selection=208727
CHANGES:         Revision 1.6 2014/03/20 12:15:09CET Schluttig, Jakob (uidv7098) 
CHANGES:         + ALN_BSWIn_t_ARS4xx_V6_1
CHANGES:         --- Added comments ---  uidv7098 [Mar 20, 2014 12:15:09 PM CET]
CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
CHANGES:         Revision 1.5 2014/02/19 12:57:36CET Manea, Gabriela (ManeaG) 
CHANGES:         Added SRR conversions , as a sigle adapter will be used for both projects. Updated ALN_BSWIn_t_Radar5xx_Gen
CHANGES:         --- Added comments ---  ManeaG [Feb 19, 2014 12:57:36 PM CET]
CHANGES:         Change Package : 212023:1 http://mks-psad:7002/im/viewissue?selection=212023
CHANGES:         Revision 1.4 2014/01/27 13:11:27CET Berndt, Thomas01 (berndtt1) 
CHANGES:         + ALN_BSWIn_t_ARS4xx_V4_2 
CHANGES:         + ALN_BSWIn_t_Radar5xx_Gen and new conversion strategy instead of N*N only N+N conversions
CHANGES:         --- Added comments ---  berndtt1 [Jan 27, 2014 2:36:33 PM CET]
CHANGES:         Change Package : 208935:9 http://mks-psad:7002/im/viewissue?selection=208935
CHANGES:         Revision 1.3 2014/01/13 07:45:13CET Schluttig, Jakob (uidv7098) 
CHANGES:         adapted to rare cases, where version number was set incorrectly (V3)
CHANGES:         --- Added comments ---  uidv7098 [Jan 13, 2014 7:45:14 AM CET]
CHANGES:         Change Package : 183794:1 http://mks-psad:7002/im/viewissue?selection=183794
CHANGES:         Revision 1.2 2013/11/29 14:47:22CET Berndt, Thomas01 (berndtt1) 
CHANGES:         Added V4 of ALN_BSWIn_t
CHANGES:         --- Added comments ---  berndtt1 [Nov 29, 2013 4:10:00 PM CET]
CHANGES:         Change Package : 208935:2 http://mks-psad:7002/im/viewissue?selection=208935
CHANGES:         Revision 1.1 2013/08/30 16:19:40CEST Berndt, Thomas01 (berndtt1) 
CHANGES:         Initial revision
CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_rtebswin.h"
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

typedef unsigned char e_AlnOpMode_t;

// ALN_BSWIn_t version 100
namespace ALN_BSWIn_t_Radar5xx_V100
{
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  typedef float a_Rx_array_t[1];
  typedef float a_Tx_array_t[1];
  typedef float a_RacerunnerExtern_array_t[2];
#endif

#if (CFG_SRR520_SWITCH == SWITCH_ON)
  typedef float a_Rx_array_t[1];
  typedef float a_Tx_array_t[1];
  typedef float a_RacerunnerExtern_array_t[1];
#endif

  typedef unsigned char u_Dummy_array_t_3[2];

  typedef struct
  {
    uint32 u_LowFreqBoardVersion;
    uint32 u_HighFreqBoardVersion;
    uint32 u_RaceRunnerVersion;
  } SYS_t_HWSample;

  typedef struct
  {
    float f_Vco;
    a_Tx_array_t a_Tx;
    a_Rx_array_t a_Rx;
    a_RacerunnerExtern_array_t a_RacerunnerExtern;
  } t_SensorTemperature;

  typedef struct
  {
    float f_DistanceTarget;
    float f_AzimuthTarget;
    float f_ElevationTarget;
    float f_SetupAccuracyAzimuth;
    float f_SetupAccuracyElevation;
    boolean b_EolInspection;
    boolean b_EolTargetIsCorner;
    unsigned char u_Dummy_array_t_1[2];
  } s_EolParameters_t;

  typedef struct ALN_BSWIn_t
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    SYS_t_HWSample HWSample;
    t_SensorTemperature SensorTemperature;
    s_EolParameters_t s_EolParameters;
    e_AlnOpMode_t e_AlnOpMode;
    boolean b_DrivingLevelDeadjusted;
    u_Dummy_array_t_3 u_Dummy;
  } ALN_BSWIn_t;
}// ALN_BSWIn_t version 100


// ALN_BSWIn_t version 101
namespace ALN_BSWIn_t_Radar5xx_V101
{
  typedef struct
  {
    float f_DistanceTarget;
    float f_AzimuthTarget;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    float f_ElevationTarget;
#endif
    float f_SetupAccuracyAzimuth;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    float f_SetupAccuracyElevation;
#endif
    boolean b_EolInspection;
    boolean b_EolTargetIsCorner;
    unsigned char u_Dummy_array_t_1[2];
  } s_EolParameters_t;


  typedef struct ALN_BSWIn_t
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_BSWIn_t_Radar5xx_V100::SYS_t_HWSample HWSample;
    ALN_BSWIn_t_Radar5xx_V100::t_SensorTemperature SensorTemperature;
    s_EolParameters_t s_EolParameters;
    e_AlnOpMode_t e_AlnOpMode;
    boolean b_DrivingLevelDeadjusted;
    ALN_BSWIn_t_Radar5xx_V100::u_Dummy_array_t_3 u_Dummy;
  } ALN_BSWIn_t;
}// ALN_BSWIn_t version 101


// Generic ARS5xx & SRR5xx ALN_BSWIn_t
// Holds all possible structure members from all possible namespaces
namespace ALN_BSWIn_t_Radar5xx_Gen
{
  typedef struct ALN_BSWIn_t
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_BSWIn_t_Radar5xx_V100::SYS_t_HWSample HWSample_V100;
    ALN_BSWIn_t_Radar5xx_V100::t_SensorTemperature SensorTemperature_V100;
    ALN_BSWIn_t_Radar5xx_V100::s_EolParameters_t s_EolParameters_V100;
    ALN_BSWIn_t_Radar5xx_V101::s_EolParameters_t s_EolParameters_V101;
    e_AlnOpMode_t e_AlnOpMode;
    boolean b_DrivingLevelDeadjusted;
  } ALN_BSWIn_t;
}


class CConvAlnRteBswIn : public CSimConverterBase
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

  ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t m_BufGen;
  ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t m_BufV100;
  ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t m_BufV101;

  static void InitGen(ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Params);
  static void InitV100(ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t & Params);
  static void InitV101(ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t & Params);

  // Conversions from provide port (input) to generic buffer
  void Convert_v100_to_Gen (ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Dest, const ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t & Src);
  void Convert_v101_to_Gen (ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Dest, const ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t & Src);

  // Conversions from generic buffer to receive port (output)
  void Convert_Gen_to_v100 (ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t & Dest, const ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Src);
  void Convert_Gen_to_v101 (ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t & Dest, const ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Src);

public:

  static const char *GetConverterTypeName()
  {
    return "AlnRteBswInput";
  }

  CConvAlnRteBswIn(void);
  virtual ~CConvAlnRteBswIn(void);

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

  enum ALNBswIn
  {
    ALN_RTE_BSW_IN_V100,
    ALN_RTE_BSW_IN_V101,
    ALN_RTE_BSW_IN_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[ALN_RTE_BSW_IN_VERSION_COUNT];

  static CVersionInfoImpl * const ALNBSWIN_VERSION_NUMBERS[ALN_RTE_BSW_IN_VERSION_COUNT];

  bool PortSupported (SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;

};

CVersionInfoImpl CConvAlnRteBswIn::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnRteBswIn::VERSION100(0, 0, 100);
CVersionInfoImpl CConvAlnRteBswIn::VERSION101(0, 0, 101);

const unsigned long CConvAlnRteBswIn::SUPPORTED_SIZE[CConvAlnRteBswIn::ALN_RTE_BSW_IN_VERSION_COUNT] =
{
  sizeof(ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t),
  sizeof(ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t)
};

CVersionInfoImpl * const CConvAlnRteBswIn::ALNBSWIN_VERSION_NUMBERS[CConvAlnRteBswIn::ALN_RTE_BSW_IN_VERSION_COUNT]=
{
  &VERSION100,
  &VERSION101
};

CConvAlnRteBswIn::CConvAlnRteBswIn(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufGen(), m_BufV100(), m_BufV101()
{
}

CConvAlnRteBswIn::~CConvAlnRteBswIn(void)
{
}

bool CConvAlnRteBswIn::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  if (ePortType == simOPAQUE_t)
  {
    for (i=0; (i<CConvAlnRteBswIn::ALN_RTE_BSW_IN_VERSION_COUNT) && (false == bResult); i++)
    {
      if (ulPortSize == SUPPORTED_SIZE[i])
      {
        // Check if version information is compatible - with extra care for simulators that do not set the version number at all...
        if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(ALNBSWIN_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}


void CConvAlnRteBswIn::InitV100(ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 100u;
  // HWSample
  Params.HWSample.u_HighFreqBoardVersion         = 1;
  Params.HWSample.u_LowFreqBoardVersion          = 1;
  Params.HWSample.u_RaceRunnerVersion            = 1;
  // EOL Parameters
  Params.s_EolParameters.f_DistanceTarget        = 1.4f; // default
  Params.s_EolParameters.f_AzimuthTarget         = 0.0f;
  Params.s_EolParameters.f_ElevationTarget       = 0.0f;
  Params.s_EolParameters.f_SetupAccuracyAzimuth  = 0.00174533f; // 0.1deg => radians
  Params.s_EolParameters.f_SetupAccuracyElevation = 0.00174533f; // 0.1deg => radians
  Params.s_EolParameters.b_EolInspection         = FALSE;
  Params.s_EolParameters.b_EolTargetIsCorner     = FALSE;
}


void CConvAlnRteBswIn::InitV101(ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 101u;
  // HWSample
  Params.HWSample.u_HighFreqBoardVersion         = 1;
  Params.HWSample.u_LowFreqBoardVersion          = 1;
  Params.HWSample.u_RaceRunnerVersion            = 1;
  // EOL Parameters
  Params.s_EolParameters.f_DistanceTarget        = 1.4f; // default
  Params.s_EolParameters.f_AzimuthTarget         = 0.0f;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Params.s_EolParameters.f_ElevationTarget       = 0.0f;
  Params.s_EolParameters.f_SetupAccuracyElevation = 0.00174533f; // 0.1deg => radians
#endif
  Params.s_EolParameters.f_SetupAccuracyAzimuth  = 0.00174533f; // 0.1deg => radians
  Params.s_EolParameters.b_EolInspection         = FALSE;
  Params.s_EolParameters.b_EolTargetIsCorner     = FALSE;
}


void CConvAlnRteBswIn::InitGen(ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  // Set to the highest number
  Params.u_VersionNumber = 101u;
  // HW Sample
  Params.HWSample_V100.u_HighFreqBoardVersion    = 1;
  Params.HWSample_V100.u_LowFreqBoardVersion     = 1;
  Params.HWSample_V100.u_RaceRunnerVersion       = 1;
  // EOL Parameters V100
  Params.s_EolParameters_V100.f_DistanceTarget        = 1.4f; // default
  Params.s_EolParameters_V100.f_AzimuthTarget         = 0.0f;
  Params.s_EolParameters_V100.f_ElevationTarget       = 0.0f;
  Params.s_EolParameters_V100.f_SetupAccuracyAzimuth  = 0.00174533f; // 0.1deg => radians
  Params.s_EolParameters_V100.f_SetupAccuracyElevation = 0.00174533f; // 0.1deg => radians
  Params.s_EolParameters_V100.b_EolInspection         = FALSE;
  Params.s_EolParameters_V100.b_EolTargetIsCorner     = FALSE;
  // EOL Parameters V100
  Params.s_EolParameters_V101.f_DistanceTarget        = 1.4f; // default
  Params.s_EolParameters_V101.f_AzimuthTarget         = 0.0f;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Params.s_EolParameters_V101.f_ElevationTarget       = 0.0f;
  Params.s_EolParameters_V101.f_SetupAccuracyElevation = 0.00174533f; // 0.1deg => radians
#endif
  Params.s_EolParameters_V101.f_SetupAccuracyAzimuth  = 0.00174533f; // 0.1deg => radians
  Params.s_EolParameters_V101.b_EolInspection         = FALSE;
  Params.s_EolParameters_V101.b_EolTargetIsCorner     = FALSE;

}


void CConvAlnRteBswIn::Convert_v100_to_Gen(ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Dest,
  const ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t & Src)
{
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  // HWSample V100
  Dest.HWSample_V100                   = Src.HWSample;
  // SensorTemperature V100
  Dest.SensorTemperature_V100          = Src.SensorTemperature;
  // EOL Parameters V100
  Dest.s_EolParameters_V100            = Src.s_EolParameters;
  // EOL Parameters V101
  Dest.s_EolParameters_V101.f_AzimuthTarget          = Src.s_EolParameters.f_AzimuthTarget;
  Dest.s_EolParameters_V101.f_DistanceTarget         = Src.s_EolParameters.f_DistanceTarget;
  Dest.s_EolParameters_V101.f_SetupAccuracyAzimuth   = Src.s_EolParameters.f_SetupAccuracyAzimuth; // 0.1deg => radians
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_EolParameters_V101.f_SetupAccuracyElevation = Src.s_EolParameters.f_SetupAccuracyElevation; // 0.1deg => radians
  Dest.s_EolParameters_V101.f_ElevationTarget        = Src.s_EolParameters.f_ElevationTarget; // 0.1deg => radians
#endif
  Dest.s_EolParameters_V101.b_EolInspection          = Src.s_EolParameters.b_EolInspection;
  Dest.s_EolParameters_V101.b_EolTargetIsCorner      = Src.s_EolParameters.b_EolTargetIsCorner;
  // OP mode
  Dest.e_AlnOpMode              = Src.e_AlnOpMode;
  // DrivingLevel
  Dest.b_DrivingLevelDeadjusted = Src.b_DrivingLevelDeadjusted;
}


void CConvAlnRteBswIn::Convert_v101_to_Gen(ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Dest,
                                            const ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t & Src)
{
  Dest.u_VersionNumber                 = Src.u_VersionNumber;
  Dest.sSigHeader                      = Src.sSigHeader;
  // HWSample V100
  Dest.HWSample_V100                   = Src.HWSample;
  // SensorTemperature V100
  Dest.SensorTemperature_V100          = Src.SensorTemperature;
  // EOL Parameters V101
  Dest.s_EolParameters_V101            = Src.s_EolParameters;
  // EOL Parameters V100
  Dest.s_EolParameters_V100.f_AzimuthTarget          = Src.s_EolParameters.f_AzimuthTarget;
  Dest.s_EolParameters_V100.f_DistanceTarget         = Src.s_EolParameters.f_DistanceTarget;
  Dest.s_EolParameters_V100.f_SetupAccuracyAzimuth   = Src.s_EolParameters.f_SetupAccuracyAzimuth; // 0.1deg => radians
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.s_EolParameters_V100.f_SetupAccuracyElevation = Src.s_EolParameters.f_SetupAccuracyElevation; // 0.1deg => radians
  Dest.s_EolParameters_V100.f_ElevationTarget        = Src.s_EolParameters.f_ElevationTarget; // 0.1deg => radians
#endif
  Dest.s_EolParameters_V100.b_EolInspection          = Src.s_EolParameters.b_EolInspection;
  Dest.s_EolParameters_V100.b_EolTargetIsCorner      = Src.s_EolParameters.b_EolTargetIsCorner;
  // OP mode
  Dest.e_AlnOpMode              = Src.e_AlnOpMode;
  // DrivingLevel
  Dest.b_DrivingLevelDeadjusted = Src.b_DrivingLevelDeadjusted;
}


void CConvAlnRteBswIn::Convert_Gen_to_v100 (ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t & Dest, const ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Src)
{
  Dest.u_VersionNumber          = 100u;
  Dest.sSigHeader               = Src.sSigHeader;
  Dest.HWSample                 = Src.HWSample_V100;
  Dest.SensorTemperature        = Src.SensorTemperature_V100;
  Dest.s_EolParameters          = Src.s_EolParameters_V100;
  Dest.e_AlnOpMode              = Src.e_AlnOpMode;
  Dest.b_DrivingLevelDeadjusted = Src.b_DrivingLevelDeadjusted;
}


void CConvAlnRteBswIn::Convert_Gen_to_v101 (ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t & Dest, const ALN_BSWIn_t_Radar5xx_Gen::ALN_BSWIn_t & Src)
{
  Dest.u_VersionNumber          = 101u;
  Dest.sSigHeader               = Src.sSigHeader;
  Dest.HWSample                 = Src.HWSample_V100;
  Dest.SensorTemperature        = Src.SensorTemperature_V100;
  Dest.s_EolParameters          = Src.s_EolParameters_V101;
  Dest.e_AlnOpMode              = Src.e_AlnOpMode;
  Dest.b_DrivingLevelDeadjusted = Src.b_DrivingLevelDeadjusted;
}

long CConvAlnRteBswIn::ConvertData(
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
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    /* do not explicitly check data version -> if size fits, just use it */
    )
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 100u) || (uDataVer == 0)))
  {
    // Source Port V100
    CConvAlnRteBswIn::InitGen(m_BufGen);
    const ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t & Src = *reinterpret_cast<ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t*>(pPPortData);
    Convert_v100_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 101u) || (uDataVer == 0)))
  {
    // Source Port V101
    CConvAlnRteBswIn::InitGen(m_BufGen);
    const ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t & Src = *reinterpret_cast<ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t*>(pPPortData);
    Convert_v101_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == sizeof(ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t)) && ((requestPortVersionInfo.Equals(&VERSION101)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V101
      CConvAlnRteBswIn::InitV101(m_BufV101);
      ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t & Dest = /*reinterpret_cast<ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t &>*/(m_BufV101);
      Convert_Gen_to_v101(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t)) && ((requestPortVersionInfo.Equals(&VERSION100)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V100
      CConvAlnRteBswIn::InitV100(m_BufV100);
      ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t & Dest = /*reinterpret_cast<ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t &>*/(m_BufV100);
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
long CConvAlnRteBswIn::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION100.Equals(&requestPortVersionInfo))))
    {
      InitV100(m_BufV100);
      *pDefaultData = &m_BufV100;
      ulDefaultSize = sizeof(ALN_BSWIn_t_Radar5xx_V100::ALN_BSWIn_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION101.Equals(&requestPortVersionInfo))))
    {
      InitV101(m_BufV101);
      *pDefaultData = &m_BufV101;
      ulDefaultSize = sizeof(ALN_BSWIn_t_Radar5xx_V101::ALN_BSWIn_t);
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
bool CConvAlnRteBswIn::IsVersionCompatibleWithType(
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
bool CConvAlnRteBswIn::AreVersionsCompatible(
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
IConverter * CreateAlnRteBswInConvClass(void)
{
  return new CConvAlnRteBswIn();
}
