/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter rsp

  MODULNAME:       sim_conv_rsp_inputactl

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   23.08.2013

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_rsp_inputactl.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:32CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.7 2016/11/25 08:17:43CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         +  (Src_HWSample == 269u)
  CHANGES:         Revision 1.6 2016/10/12 06:52:29CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Added converting of RSP_INPUT_ACTL_V4 with u_InterfaceVersion == 256 (00.01.00)
  CHANGES:         Revision 1.5 2016/10/10 14:00:29CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         * corrected version number
  CHANGES:         Revision 1.4 2016/08/10 14:20:37CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Version V100 for ARS510
  CHANGES:         Revision 1.3 2016/08/09 13:22:59CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Intermediate V100
  CHANGES:         Revision 1.2 2014/01/13 08:37:19CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Added namespace RSP_t_InputActl_ARS4xx_V4 and appropriate conversion
  CHANGES:         --- Added comments ---  berndtt1 [Jan 13, 2014 9:38:03 AM CET]
  CHANGES:         Change Package : 208935:7 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:         Revision 1.1 2013/09/02 14:22:25CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_rsp_inputactl.h"
#include "sim_versioninfo_impl.h"

typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;


/* typedef RSP_t_OpMode */
#ifndef RSP_OpMode_Reset
  #define RSP_OpMode_Reset (0U)
#endif
#ifndef RSP_OpMode_Normal
  #define RSP_OpMode_Normal (2U)
#endif

/* typedef SYS_t_Scans */
#ifndef SYS_SCAN_FAR
  #define SYS_SCAN_FAR (0U)
#endif
#ifndef SYS_SCAN_NEAR
  #define SYS_SCAN_NEAR (1U)
#endif
#ifndef SYS_NUM_OF_SCANS
  #define SYS_NUM_OF_SCANS (2U)
#endif

/* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif
#ifndef AL_SIG_STATE_OK
  #define AL_SIG_STATE_OK (1U)
#endif


// ARS4xx RSP_t_InputActl version 2 V1           Length = 16
namespace RSP_t_InputActl_ARS4xx_V2_1
{
  typedef unsigned char RSP_t_OpMode             /* @min: 0 @max:2 @values: enum { RSP_OpMode_Pause=1,RSP_OpMode_Normal=2,RSP_OpMode_Reset=0,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char SYS_t_Scans              /* @min: 0 @max:2 @values: enum { SYS_SCAN_NEAR=1,SYS_NUM_OF_SCANS=2,SYS_SCAN_FAR=0,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct RSP_t_InputActl                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_InterfaceVersion;
    RSP_t_OpMode RSPOpMode;
    float f_RSPCycleTime;
    SYS_t_Scans ScanMode;
  } RSP_t_InputActl;                             /* input data origin ACTL @vaddr:0x06030000, 0x06030100, 0x06030200, 0x06030300 @vaddr_defs: RSP1_MEAS_ID_IN_ACTL_FAR,RSP1_MEAS_ID_IN_ACTL_NEAR,RSP2_MEAS_ID_IN_ACTL_FAR,RSP2_MEAS_ID_IN_ACTL_NEAR @cycleid:RSP_ENV @vname:RSP1_InputActlFS,RSP1_InputActlNS,RSP2_InputActlFS,RSP2_InputActlNS */
}

// ARS4xx RSP_t_InputActl version 2 V2           Length = 20
namespace RSP_t_InputActl_ARS4xx_V2_2
{
  typedef unsigned long AlgoDataTimeStamp_t      /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t      /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t        /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned short SYS_t_HWSample          /* @min: 257 @max:258 @values: enum { SYS_C0=258,SYS_B1_2=257,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct SignalHeader_t                  /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                              /* Common header for all structured data types */

  typedef struct RSP_t_InputActl                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_InterfaceVersion;
    SignalHeader_t sSigHeader;
    RSP_t_InputActl_ARS4xx_V2_1::RSP_t_OpMode RSPOpMode;
    RSP_t_InputActl_ARS4xx_V2_1::SYS_t_Scans ScanMode;
    SYS_t_HWSample HWSample;
  } RSP_t_InputActl;                             /* input data origin ACTL @vaddr:0x06030000, 0x06030100, 0x06030200, 0x06030300 @vaddr_defs: RSP1_MEAS_ID_IN_ACTL_FAR,RSP1_MEAS_ID_IN_ACTL_NEAR,RSP2_MEAS_ID_IN_ACTL_FAR,RSP2_MEAS_ID_IN_ACTL_NEAR @cycleid:RSP_ENV @vname:RSP1_InputActlFS,RSP1_InputActlNS,RSP2_InputActlFS,RSP2_InputActlNS */
}

// ARS4xx RSP_t_InputActl version 4              Length = 24
namespace RSP_t_InputActl_ARS4xx_V4
{
  typedef struct RSP_t_InputActl                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_InterfaceVersion;
    RSP_t_InputActl_ARS4xx_V2_2::SignalHeader_t sSigHeader;
    RSP_t_InputActl_ARS4xx_V2_1::RSP_t_OpMode RSPOpMode;
    RSP_t_InputActl_ARS4xx_V2_1::SYS_t_Scans ScanMode;
    RSP_t_InputActl_ARS4xx_V2_2::SYS_t_HWSample HWSample;
    boolean b_ExtendedCycle;
  } RSP_t_InputActl;                             /* input data origin ACTL @vaddr:0x06030000, 0x06030100, 0x06030200, 0x06030300 @vaddr_defs: RSP1_MEAS_ID_IN_ACTL_FAR,RSP1_MEAS_ID_IN_ACTL_NEAR,RSP2_MEAS_ID_IN_ACTL_FAR,RSP2_MEAS_ID_IN_ACTL_NEAR @cycleid:RSP_ENV @vname:RSP1_InputActlFS,RSP1_InputActlNS,RSP2_InputActlFS,RSP2_InputActlNS */
}

// ARS4xx RSP_t_InputActl version 100            Length = 40
namespace RSP_t_InputActl_ARS4xx_V100
{
  typedef struct SYS_t_HWSample
  {
    unsigned __int32 u_LowFreqBoardVersion;
    unsigned __int32 u_HighFreqBoardVersion;
    unsigned __int32 u_RaceRunnerVersion;
  } SYS_t_HWSample;

  typedef struct RSP_t_InputActl                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_InterfaceVersion;
    RSP_t_InputActl_ARS4xx_V2_2::SignalHeader_t sSigHeader;
    RSP_t_InputActl_ARS4xx_V2_1::RSP_t_OpMode RSPOpMode;
    RSP_t_InputActl_ARS4xx_V2_1::SYS_t_Scans ScanMode;
    SYS_t_HWSample HWSample;
    float32 TimeStampDataAquisition;
    boolean b_ExtendedCycle;
  } RSP_t_InputActl;                             /* input data origin ACTL @vaddr:0x06030000, 0x06030100, 0x06030200, 0x06030300 @vaddr_defs: RSP1_MEAS_ID_IN_ACTL_HRR,RSP1_MEAS_ID_IN_ACTL_NEAR,RSP2_MEAS_ID_IN_ACTL_HRR,RSP2_MEAS_ID_IN_ACTL_NEAR @cycleid:RSP1_ENV,RSP1_ENV,RSP2_ENV,RSP2_ENV @vname:RSP1_InputActlHRR,RSP1_InputActlNS,RSP2_InputActlHRR,RSP2_InputActlNS */
}


class CConvRspInputActl : public CSimConverterBase
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

  RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl m_BufV2_1;
  RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl m_BufV2_2;
  RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl m_BufV4;
  RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl m_BufV100;

  static void InitV2_1(RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl & Params);
  static void InitV2_2(RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl & Params);
  static void InitV4(RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl & Params);
  static void InitV100(RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl & Params);

  void ConvertHWSample(RSP_t_InputActl_ARS4xx_V100::SYS_t_HWSample &Dest, RSP_t_InputActl_ARS4xx_V2_2::SYS_t_HWSample Src_HWSample);

public:

  static const char *GetConverterTypeName()
  {
    return "RSP_InputActl";
  }

  CConvRspInputActl(void);
  virtual ~CConvRspInputActl(void);

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

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < BSW_ALGO_PARAM_VERSION_COUNT; nI++)
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

private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION2;
  static CVersionInfoImpl VERSION3;
  static CVersionInfoImpl VERSION4;
  static CVersionInfoImpl VERSION100;

  enum BSWAlgoParameters
  {
    RSP_INPUT_ACTL_V2_1,
    RSP_INPUT_ACTL_V2_2,
    RSP_INPUT_ACTL_V2_3,               /* V2_2 with Version Info V3 */
    RSP_INPUT_ACTL_V4,
    RSP_INPUT_ACTL_V100,
    BSW_ALGO_PARAM_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[BSW_ALGO_PARAM_VERSION_COUNT];

  static const CVersionInfoImpl * const VERSION_NUMBERS[BSW_ALGO_PARAM_VERSION_COUNT];
};

CVersionInfoImpl CConvRspInputActl::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvRspInputActl::VERSION2(0, 0, 2);
CVersionInfoImpl CConvRspInputActl::VERSION3(0, 0, 3);
CVersionInfoImpl CConvRspInputActl::VERSION4(0, 0, 4);
CVersionInfoImpl CConvRspInputActl::VERSION100(0, 1, 0);

const unsigned long CConvRspInputActl::SUPPORTED_SIZE[CConvRspInputActl::BSW_ALGO_PARAM_VERSION_COUNT] =
{
  sizeof(RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl),
  sizeof(RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl),
  sizeof(RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl),
  sizeof(RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl),
  sizeof(RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl),
};

const CVersionInfoImpl * const CConvRspInputActl::VERSION_NUMBERS[CConvRspInputActl::BSW_ALGO_PARAM_VERSION_COUNT] =
{
  &VERSION2,
  &VERSION2,
  &VERSION3,
  &VERSION4,
  &VERSION100
};

CConvRspInputActl::CConvRspInputActl(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV2_1(), m_BufV2_2()
{
}

CConvRspInputActl::~CConvRspInputActl(void)
{
}

void CConvRspInputActl::InitV2_1(RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_InterfaceVersion = 2u;
  Params.RSPOpMode                               = RSP_OpMode_Reset;
  Params.f_RSPCycleTime                          = 0;
  Params.ScanMode                                = SYS_SCAN_NEAR;
}

void CConvRspInputActl::InitV2_2(RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_InterfaceVersion = 3u;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  Params.RSPOpMode                               = RSP_OpMode_Reset;
  Params.ScanMode                                = SYS_SCAN_NEAR;
  Params.HWSample                                = 0;
}

void CConvRspInputActl::InitV4(RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_InterfaceVersion = 3u;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  Params.RSPOpMode                               = RSP_OpMode_Reset;
  Params.ScanMode                                = SYS_SCAN_NEAR;
  Params.HWSample                                = 0;
  Params.b_ExtendedCycle                         = 0;
}

void CConvRspInputActl::InitV100(RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_InterfaceVersion = 100u;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  Params.RSPOpMode                               = RSP_OpMode_Reset;
  Params.ScanMode                                = SYS_SCAN_NEAR;
  Params.HWSample.u_LowFreqBoardVersion          = 1;
  Params.HWSample.u_HighFreqBoardVersion         = 1;
  Params.HWSample.u_RaceRunnerVersion            = 1;
  Params.b_ExtendedCycle                         = 0;
}

void CConvRspInputActl::ConvertHWSample(RSP_t_InputActl_ARS4xx_V100::SYS_t_HWSample &Dest, RSP_t_InputActl_ARS4xx_V2_2::SYS_t_HWSample Src_HWSample)
{
  if (Src_HWSample == 259u)
  {
    Dest.u_HighFreqBoardVersion = 1;
  }
  else if ((Src_HWSample == 269u) || (Src_HWSample == 4096u))
  {
    Dest.u_HighFreqBoardVersion = 2;
  }
}

long CConvRspInputActl::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // First decide which version we are converting to
  // If ports equal, then always compatible
  if (eRPortType == ePPortType)
  {
    if (ulPPortSize == ulRPortSize)
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[RSP_INPUT_ACTL_V100]) && (VERSION_NUMBERS[RSP_INPUT_ACTL_V100]->Equals(&requestPortVersionInfo) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V100
      RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl & Dest = m_BufV100;
      InitV100(m_BufV100);
      if ((ulPPortSize == SUPPORTED_SIZE[RSP_INPUT_ACTL_V4])
        && ((pProvidePortVersionInfo == NULL) || (VERSION_NUMBERS[RSP_INPUT_ACTL_V4]->Equals(pProvidePortVersionInfo)) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 256u) || (uDataVer == 4u) || (uDataVer == 3u) || (uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = Src.u_InterfaceVersion;
        Dest.sSigHeader.uiTimeStamp          = Src.sSigHeader.uiTimeStamp;
        Dest.sSigHeader.uiCycleCounter       = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        ConvertHWSample(Dest.HWSample, Src.HWSample);
        Dest.b_ExtendedCycle                 = Src.b_ExtendedCycle;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_BufV2_2))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION3) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 3u) || (uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = Src.u_InterfaceVersion;
        Dest.sSigHeader.uiTimeStamp          = Src.sSigHeader.uiTimeStamp;
        Dest.sSigHeader.uiCycleCounter       = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        ConvertHWSample(Dest.HWSample, Src.HWSample);
        Dest.b_ExtendedCycle                 = 0;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_BufV2_1))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION3) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = 2u;
        Dest.sSigHeader.uiTimeStamp          = 0;
        Dest.sSigHeader.uiCycleCounter       = 0;
        Dest.sSigHeader.uiMeasurementCounter = 0;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        //ConvertHWSample(Dest.HWSample, 259);
        Dest.b_ExtendedCycle                 = 0;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(m_BufV4)) && (requestPortVersionInfo.Equals(&VERSION4) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V4
      RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl & Dest = m_BufV4;
      if ((ulPPortSize == SUPPORTED_SIZE[RSP_INPUT_ACTL_V100])
        && ((pProvidePortVersionInfo == NULL) || VERSION_NUMBERS[RSP_INPUT_ACTL_V100]->Equals(pProvidePortVersionInfo) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && (uDataVer == 100u))
      {
        const RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = Src.u_InterfaceVersion;
        Dest.sSigHeader.uiTimeStamp          = Src.sSigHeader.uiTimeStamp;
        Dest.sSigHeader.uiCycleCounter       = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        Dest.HWSample                        = 0;
        Dest.b_ExtendedCycle                 = 0;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_BufV2_2))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION3) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 3u) || (uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = Src.u_InterfaceVersion;
        Dest.sSigHeader.uiTimeStamp          = Src.sSigHeader.uiTimeStamp;
        Dest.sSigHeader.uiCycleCounter       = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        Dest.HWSample                        = Src.HWSample;
        Dest.b_ExtendedCycle                 = 0;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_BufV2_1))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION3) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = 2u;
        Dest.sSigHeader.uiTimeStamp          = 0;
        Dest.sSigHeader.uiCycleCounter       = 0;
        Dest.sSigHeader.uiMeasurementCounter = 0;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        Dest.HWSample                        = 0;
        Dest.b_ExtendedCycle                 = 0;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(m_BufV2_2)) && (requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V2_2
      RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl & Dest = m_BufV2_2;
      if ((ulPPortSize == SUPPORTED_SIZE[RSP_INPUT_ACTL_V100])
        && ((pProvidePortVersionInfo == NULL) || VERSION_NUMBERS[RSP_INPUT_ACTL_V100]->Equals(pProvidePortVersionInfo) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && (uDataVer == 100u))
      {
        const RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = 2u;
        Dest.u_InterfaceVersion              = Src.u_InterfaceVersion;
        Dest.sSigHeader.uiTimeStamp          = Src.sSigHeader.uiTimeStamp;
        Dest.sSigHeader.uiCycleCounter       = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        Dest.HWSample                        = 0;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_BufV4))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION4) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 4u) || (uDataVer == 3u) || (uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = Src.u_InterfaceVersion;
        Dest.sSigHeader.uiTimeStamp          = Src.sSigHeader.uiTimeStamp;
        Dest.sSigHeader.uiCycleCounter       = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        Dest.HWSample                        = Src.HWSample;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_BufV2_1))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = 2u;
        Dest.sSigHeader.uiTimeStamp          = 0;
        Dest.sSigHeader.uiCycleCounter       = 0;
        Dest.sSigHeader.uiMeasurementCounter = 0;
        Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.ScanMode                        = Src.ScanMode;
        Dest.HWSample                        = 0;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(m_BufV2_1)) && (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V2_1
      RSP_t_InputActl_ARS4xx_V2_1::RSP_t_InputActl & Dest = m_BufV2_1;
      if ((ulPPortSize == SUPPORTED_SIZE[RSP_INPUT_ACTL_V100])
        && ((pProvidePortVersionInfo == NULL) || VERSION_NUMBERS[RSP_INPUT_ACTL_V100]->Equals(pProvidePortVersionInfo) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && (uDataVer == 100u))
      {
        const RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V100::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = 2u;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.f_RSPCycleTime                  = (float)Src.sSigHeader.uiTimeStamp;
        Dest.ScanMode                        = Src.ScanMode;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_BufV4))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION4) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 4u) || (uDataVer == 3u) || (uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V4::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = 2u;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.f_RSPCycleTime                  = (float)Src.sSigHeader.uiTimeStamp;
        Dest.ScanMode                        = Src.ScanMode;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_BufV2_2))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION3) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
        && ((uDataVer == 3u) || (uDataVer == 2u) || (uDataVer == 0)))
      {
        const RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl & Src = *reinterpret_cast<RSP_t_InputActl_ARS4xx_V2_2::RSP_t_InputActl*>(pPPortData);
        Dest.u_InterfaceVersion              = 2u;
        Dest.RSPOpMode                       = Src.RSPOpMode;
        Dest.f_RSPCycleTime                  = (float)Src.sSigHeader.uiTimeStamp;
        Dest.ScanMode                        = Src.ScanMode;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvRspInputActl::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    // Disclamation of check on version, only the size matters
    //if (BASE_VERSION.Equals(&requestPortVersionInfo) || VERSION2.Equals(&requestPortVersionInfo))
    //{
      if (ulRPortSize == sizeof(m_BufV100))
      {
        InitV100(m_BufV100);
        *pDefaultData = &m_BufV100;
        ulDefaultSize = sizeof(m_BufV100);
        lRet = SIM_ERR_OK;
      }
      else if (ulRPortSize == sizeof(m_BufV4))
      {
        InitV4(m_BufV4);
        *pDefaultData = &m_BufV4;
        ulDefaultSize = sizeof(m_BufV4);
        lRet = SIM_ERR_OK;
      }
      else if (ulRPortSize == sizeof(m_BufV2_2))
      {
        InitV2_2(m_BufV2_2);
        *pDefaultData = &m_BufV2_2;
        ulDefaultSize = sizeof(m_BufV2_2);
        lRet = SIM_ERR_OK;
      }
      else if (ulRPortSize == sizeof(m_BufV2_1))
      {
        InitV2_1(m_BufV2_1);
        *pDefaultData = &m_BufV2_1;
        ulDefaultSize = sizeof(m_BufV2_1);
        lRet = SIM_ERR_OK;
      }
    //}
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRspInputActl::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
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
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvRspInputActl::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
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
// Main factory class returning conversion class
//
IConverter * CreateRspInputActlConvClass(void)
{
  return new CConvRspInputActl();
}
