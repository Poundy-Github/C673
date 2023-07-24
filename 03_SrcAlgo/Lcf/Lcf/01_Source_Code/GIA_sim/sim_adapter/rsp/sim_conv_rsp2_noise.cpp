/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter rsp

  MODULNAME:       sim_conv_rsp2_noise

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   20.08.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_rsp2_noise.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:21:45CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:15:39CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.3 2015/04/24 12:28:59CEST Manea, Gabriela (ManeaG) 
  CHANGES:         Added conversions  RSP2_Noise_V0_0  ( old  structure version )
  CHANGES:         - Added comments -  ManeaG [Apr 24, 2015 12:29:00 PM CEST]
  CHANGES:         Change Package : 278885:1 http://mks-psad:7002/im/viewissue?selection=278885
  CHANGES:         Revision 1.2 2015/01/16 07:55:03CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         + RSP2_t_Noise Version 2
  CHANGES:         --- Added comments ---  berndtt1 [Jan 16, 2015 8:04:47 AM CET]
  CHANGES:         Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.1 2014/10/07 11:41:19CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.1 2014/08/22 16:56:31CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_rsp2_noise.h"
#include "sim_versioninfo_impl.h"

typedef unsigned __int8 boolean;

#define SYS_NUM_OF_BEAMS (16)

#define RSP2_SIM_INTERFERENCE 1u

#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  #define RSP2_NUMBER_FREQUENCY_BANDS 5
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON) || (SRR_SWITCH == SWITCH_ON)
  #define RSP2_NUMBER_FREQUENCY_BANDS 3
#endif


namespace RSP2_Noise_V0                                              // Length: ARS400 PR 340, EN 184
{
  typedef unsigned short AlgoCycleCounter_t                          /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t                          /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t                            /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */;
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_NoiseMin;
    boolean b_InfluencedByLargePeak;
  } t_NoiseMin;

  typedef struct
  {
    t_NoiseMin a_NoiseMinBeamLongTerm[SYS_NUM_OF_SCANS][SYS_NUM_OF_BEAMS];
    t_NoiseMin a_NoiseMinLongTermTotal[SYS_NUM_OF_SCANS];
    t_NoiseMin a_NoiseMinBeamTotal[SYS_NUM_OF_SCANS];
    float a_NoiseMaxBeamTotal[SYS_NUM_OF_SCANS];
#if (RSP2_SIM_INTERFERENCE == 1u)
    boolean b_InterfCondition1;
    boolean b_InterfCondition2;
    boolean b_InterfCondition3;
    boolean b_RequestRfChangeRandom;
    boolean b_UpperLevel;
    unsigned __int8 u_ChangeRfIndex;
    unsigned __int8 u_CurrentRfIndex;
#endif
//#if (ALGO_SensorType != ALGO_CFG_SRR300)
#if (SRR_SWITCH == SWITCH_OFF)
    float a_ArrayOfMaxRanges[RSP2_NUMBER_FREQUENCY_BANDS];
    unsigned __int32 u_RfChangeCounter;
#endif
    SignalHeader_t sSigHeader;
  } RSP2_t_Noise;

} // end of namespace RSP_Noise_V0


namespace RSP2_Noise_V0_0                                              // Length: SRR3xx: 164
{
  
  typedef struct
  {
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinBeamLongTerm[SYS_NUM_OF_SCANS][SYS_NUM_OF_BEAMS];
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinLongTermTotal[SYS_NUM_OF_SCANS];
    float a_ArrayOfMaxRanges[RSP2_NUMBER_FREQUENCY_BANDS];
    unsigned __int32 u_RfChangeCounter;
    RSP2_Noise_V0::SignalHeader_t sSigHeader;
  } RSP2_t_Noise;

} // end of namespace RSP_Noise_V0_0  .  



namespace RSP2_Noise_V1                                              // Length: ARS400 PR 348, EN 192
{
  typedef struct
  {
    unsigned __int32 u_VersionNumber;
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinBeamLongTerm[SYS_NUM_OF_SCANS][SYS_NUM_OF_BEAMS];
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinLongTermTotal[SYS_NUM_OF_SCANS];
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinBeamTotal[SYS_NUM_OF_SCANS];
    float a_NoiseMaxBeamTotal[SYS_NUM_OF_SCANS];
#if (RSP2_SIM_INTERFERENCE == 1u)
    boolean b_InterfCondition1;
    boolean b_InterfCondition2;
    boolean b_InterfCondition3;
    boolean b_RequestRfChangeRandom;
    boolean b_UpperLevel;
    unsigned __int8 u_CurrentRfIndex;
#endif
//#if (ALGO_SensorType != ALGO_CFG_SRR300)
#if (SRR_SWITCH == SWITCH_OFF)
    float a_ArrayOfMaxRanges[RSP2_NUMBER_FREQUENCY_BANDS];
    unsigned __int32 u_RfChangeCounter;
    boolean b_ArrayMaxRangesFlag;
    unsigned __int8 u_ChangeRfIndex;
#endif
    RSP2_Noise_V0::SignalHeader_t sSigHeader;
  } RSP2_t_Noise;
} // end of namespace RSP_Noise_V1

namespace RSP2_Noise_V2                                              // Length: ARS400 PR 348, EN 192
{
  typedef struct
  {
    unsigned __int32 u_VersionNumber;
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinBeamLongTerm[SYS_NUM_OF_SCANS][SYS_NUM_OF_BEAMS];
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinLongTermTotal[SYS_NUM_OF_SCANS];
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinBeamTotal[SYS_NUM_OF_SCANS];
    float a_NoiseMaxBeamTotal[SYS_NUM_OF_SCANS];
    unsigned __int8 u_GainReductionPast[SYS_NUM_OF_SCANS];
#if (RSP2_SIM_INTERFERENCE == 1u)
    boolean b_InterfCondition1;
    boolean b_InterfCondition2;
    boolean b_InterfCondition3;
    boolean b_RequestRfChangeRandom;
    boolean b_UpperLevel;
    unsigned __int8 u_CurrentRfIndex;
#endif
    float a_ArrayOfMaxRanges[RSP2_NUMBER_FREQUENCY_BANDS];
    unsigned __int32 u_RfChangeCounter;
//#if (ALGO_SensorType != ALGO_CFG_SRR300)
#if (SRR_SWITCH == SWITCH_OFF)
    boolean b_ArrayMaxRangesFlag;
    unsigned __int8 u_ChangeRfIndex;
#endif
    RSP2_Noise_V0::SignalHeader_t sSigHeader;
  } RSP2_t_Noise;
} // end of namespace RSP_Noise_V2

namespace RSP2_Noise_Gen                                             // Length: not used
{
  typedef struct
  {
    unsigned __int32 u_VersionNumber;
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinBeamLongTerm[SYS_NUM_OF_SCANS][SYS_NUM_OF_BEAMS];
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinLongTermTotal[SYS_NUM_OF_SCANS];
    RSP2_Noise_V0::t_NoiseMin a_NoiseMinBeamTotal[SYS_NUM_OF_SCANS];
    float a_NoiseMaxBeamTotal[SYS_NUM_OF_SCANS];
    unsigned __int8 u_GainReductionPast[SYS_NUM_OF_SCANS];
  #if (RSP2_SIM_INTERFERENCE == 1u)
    boolean b_InterfCondition1;
    boolean b_InterfCondition2;
    boolean b_InterfCondition3;
    boolean b_RequestRfChangeRandom;
    boolean b_UpperLevel;
    unsigned __int8 u_CurrentRfIndex;
  #endif
    float a_ArrayOfMaxRanges[RSP2_NUMBER_FREQUENCY_BANDS];
    unsigned __int32 u_RfChangeCounter;
  #if (SRR_SWITCH == SWITCH_OFF)
    boolean b_ArrayMaxRangesFlag;
    unsigned __int8 u_ChangeRfIndex;
  #endif
    RSP2_Noise_V0::SignalHeader_t sSigHeader;
  } RSP2_t_Noise;
} // end of namespace RSP_Noise_Gen

// Initialization
template <typename T> static void InitVersion (T & Dest)
{
  ::memset(&Dest, 0, sizeof(Dest));
}
template <typename T> static void InitVersion (T & Dest, unsigned __int32 VersionNumber)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber = VersionNumber;
}

class CConvRsp2Noise : public CSimConverterBase
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

  RSP2_Noise_V0::RSP2_t_Noise m_BufV0;
  RSP2_Noise_V0_0::RSP2_t_Noise m_BufV0_0;
  RSP2_Noise_V1::RSP2_t_Noise m_BufV1;
  RSP2_Noise_V2::RSP2_t_Noise m_BufV2;
  RSP2_Noise_Gen::RSP2_t_Noise m_BufGen;

public:

  static const char *GetConverterTypeName()
  {
    return "RSP2_t_Noise";
  }

  CConvRsp2Noise(void);
  virtual ~CConvRsp2Noise(void);

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
  long ConvertData (
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
  bool IsVersionCompatibleWithType (
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible (
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo);

private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;
  static CVersionInfoImpl VERSION2;

  enum RSP_Noises
  {
    RSP2NOISE_V0,
    RSP2NOISE_V1,
    RSP2NOISE_V2,
    RSP2NOISE_V3,
    RSP2NOISE_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[RSP2NOISE_VERSION_COUNT];
  static const CVersionInfoImpl * const NACOM_INPUT_VERSIONS[RSP2NOISE_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo * pPortVersion) const
  {
    for (int nI = 0; nI < RSP2NOISE_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(NACOM_INPUT_VERSIONS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };
  // Conversions from provide port (input) to generic buffer
  void Convert_v0_to_Gen   (RSP2_Noise_Gen::RSP2_t_Noise & Dest, const RSP2_Noise_V0::RSP2_t_Noise & Src);
  void Convert_v0_0_to_Gen (RSP2_Noise_Gen::RSP2_t_Noise & Dest, const RSP2_Noise_V0_0::RSP2_t_Noise & Src);

  void Convert_v1_to_Gen (RSP2_Noise_Gen::RSP2_t_Noise & Dest, const RSP2_Noise_V1::RSP2_t_Noise & Src);
  void Convert_v2_to_Gen (RSP2_Noise_Gen::RSP2_t_Noise & Dest, const RSP2_Noise_V2::RSP2_t_Noise & Src);

  // Conversions from generic buffer to receive port (output)
  void Convert_Gen_to_v0   (RSP2_Noise_V0::RSP2_t_Noise & Dest, const RSP2_Noise_Gen::RSP2_t_Noise & Src);
  void Convert_Gen_to_v0_0 (RSP2_Noise_V0_0::RSP2_t_Noise & Dest, const RSP2_Noise_Gen::RSP2_t_Noise & Src);
  void Convert_Gen_to_v1   (RSP2_Noise_V1::RSP2_t_Noise & Dest, const RSP2_Noise_Gen::RSP2_t_Noise & Src);
  void Convert_Gen_to_v2   (RSP2_Noise_V2::RSP2_t_Noise & Dest, const RSP2_Noise_Gen::RSP2_t_Noise & Src);

};

CVersionInfoImpl CConvRsp2Noise::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvRsp2Noise::VERSION1(0, 0, 1);
CVersionInfoImpl CConvRsp2Noise::VERSION2(0, 0, 2);

const unsigned long CConvRsp2Noise::SUPPORTED_SIZE[CConvRsp2Noise::RSP2NOISE_VERSION_COUNT] =
{
  sizeof(RSP2_Noise_V0_0::RSP2_t_Noise),
  sizeof(RSP2_Noise_V0::RSP2_t_Noise),
  sizeof(RSP2_Noise_V1::RSP2_t_Noise),
  sizeof(RSP2_Noise_V2::RSP2_t_Noise),
};

const CVersionInfoImpl * const CConvRsp2Noise::NACOM_INPUT_VERSIONS[CConvRsp2Noise::RSP2NOISE_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION,
  &VERSION1,
  &VERSION2
};


CConvRsp2Noise::CConvRsp2Noise(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufGen(), m_BufV0(), m_BufV1(), m_BufV2()
{
}

CConvRsp2Noise::~CConvRsp2Noise(void)
{
}


void CConvRsp2Noise::Convert_v0_to_Gen (RSP2_Noise_Gen::RSP2_t_Noise & Dest, const RSP2_Noise_V0::RSP2_t_Noise & Src)
{
  Dest.u_VersionNumber = 0;
  memcpy(&Dest.a_NoiseMinBeamLongTerm, &Src.a_NoiseMinBeamLongTerm, sizeof(Dest.a_NoiseMinBeamLongTerm));
  memcpy(&Dest.a_NoiseMinLongTermTotal, &Src.a_NoiseMinLongTermTotal, sizeof(Dest.a_NoiseMinLongTermTotal));
  memcpy(&Dest.a_NoiseMinBeamTotal, &Src.a_NoiseMinBeamTotal, sizeof(Dest.a_NoiseMinBeamTotal));
  memcpy(&Dest.a_NoiseMaxBeamTotal, &Src.a_NoiseMaxBeamTotal, sizeof(Dest.a_NoiseMaxBeamTotal));
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++) { Dest.u_GainReductionPast[nI] = 0; }
#if (RSP2_SIM_INTERFERENCE == 1u)
  Dest.b_InterfCondition1 = Src.b_InterfCondition1;
  Dest.b_InterfCondition2 = Src.b_InterfCondition2;
  Dest.b_InterfCondition3 = Src.b_InterfCondition3;
  Dest.b_RequestRfChangeRandom = Src.b_RequestRfChangeRandom;
  Dest.b_UpperLevel = Src.b_UpperLevel;
  Dest.u_CurrentRfIndex = Src.u_CurrentRfIndex;
#endif
#if (SRR_SWITCH == SWITCH_OFF)
  memcpy(&Dest.a_ArrayOfMaxRanges, &Src.a_ArrayOfMaxRanges, sizeof(Dest.a_ArrayOfMaxRanges));
  Dest.u_RfChangeCounter = Src.u_RfChangeCounter;
  Dest.b_ArrayMaxRangesFlag = 0;
#if (RSP2_SIM_INTERFERENCE == 1u)
  Dest.u_ChangeRfIndex = Src.u_ChangeRfIndex;
#else
  Dest.u_ChangeRfIndex = 0;
#endif
#endif
  Dest.sSigHeader = Src.sSigHeader;
}


void CConvRsp2Noise::Convert_v0_0_to_Gen (RSP2_Noise_Gen::RSP2_t_Noise & Dest, const RSP2_Noise_V0_0::RSP2_t_Noise & Src)
{
  Dest.u_VersionNumber = 0;
  memcpy(&Dest.a_NoiseMinBeamLongTerm, &Src.a_NoiseMinBeamLongTerm, sizeof(Dest.a_NoiseMinBeamLongTerm));
  memcpy(&Dest.a_NoiseMinLongTermTotal, &Src.a_NoiseMinLongTermTotal, sizeof(Dest.a_NoiseMinLongTermTotal));
  memset(&Dest.a_NoiseMinBeamTotal, 0, sizeof(Dest.a_NoiseMinBeamTotal));
  memset(&Dest.a_NoiseMaxBeamTotal, 0, sizeof(Dest.a_NoiseMaxBeamTotal));
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++) { Dest.u_GainReductionPast[nI] = 0; }
  memcpy(&Dest.a_ArrayOfMaxRanges, &Src.a_ArrayOfMaxRanges, sizeof(Dest.a_ArrayOfMaxRanges));
  Dest.u_RfChangeCounter = Src.u_RfChangeCounter;
  Dest.sSigHeader = Src.sSigHeader;
}


void CConvRsp2Noise::Convert_v1_to_Gen (RSP2_Noise_Gen::RSP2_t_Noise & Dest, const RSP2_Noise_V1::RSP2_t_Noise & Src)
{
  Dest.u_VersionNumber = 1;
  memcpy(&Dest.a_NoiseMinBeamLongTerm, &Src.a_NoiseMinBeamLongTerm, sizeof(Dest.a_NoiseMinBeamLongTerm));
  memcpy(&Dest.a_NoiseMinLongTermTotal, &Src.a_NoiseMinLongTermTotal, sizeof(Dest.a_NoiseMinLongTermTotal));
  memcpy(&Dest.a_NoiseMinBeamTotal, &Src.a_NoiseMinBeamTotal, sizeof(Dest.a_NoiseMinBeamTotal));
  memcpy(&Dest.a_NoiseMaxBeamTotal, &Src.a_NoiseMaxBeamTotal, sizeof(Dest.a_NoiseMaxBeamTotal));
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++) { Dest.u_GainReductionPast[nI] = 0; }
#if (RSP2_SIM_INTERFERENCE == 1u)
  Dest.b_InterfCondition1 = Src.b_InterfCondition1;
  Dest.b_InterfCondition2 = Src.b_InterfCondition2;
  Dest.b_InterfCondition3 = Src.b_InterfCondition3;
  Dest.b_RequestRfChangeRandom = Src.b_RequestRfChangeRandom;
  Dest.b_UpperLevel = Src.b_UpperLevel;
  Dest.u_CurrentRfIndex = Src.u_CurrentRfIndex;
#endif
#if (SRR_SWITCH == SWITCH_OFF)
  memcpy(&Dest.a_ArrayOfMaxRanges, &Src.a_ArrayOfMaxRanges, sizeof(Dest.a_ArrayOfMaxRanges));
  Dest.u_RfChangeCounter = Src.u_RfChangeCounter;
  Dest.b_ArrayMaxRangesFlag = Src.b_ArrayMaxRangesFlag;
  Dest.u_ChangeRfIndex = Src.u_ChangeRfIndex;
#endif
  Dest.sSigHeader = Src.sSigHeader;
}

void CConvRsp2Noise::Convert_v2_to_Gen (RSP2_Noise_Gen::RSP2_t_Noise & Dest, const RSP2_Noise_V2::RSP2_t_Noise & Src)
{
  // if RSP2_Noise_Gen::RSP2_t_Noise is exactly like RSP2_Noise_V1::RSP2_t_Noise then
  memcpy (&Dest, &Src, sizeof(Dest));
}

void CConvRsp2Noise::Convert_Gen_to_v0 (RSP2_Noise_V0::RSP2_t_Noise & Dest, const RSP2_Noise_Gen::RSP2_t_Noise & Src)
{
  memcpy(&Dest.a_NoiseMinBeamLongTerm, &Src.a_NoiseMinBeamLongTerm, sizeof(Dest.a_NoiseMinBeamLongTerm));
  memcpy(&Dest.a_NoiseMinLongTermTotal, &Src.a_NoiseMinLongTermTotal, sizeof(Dest.a_NoiseMinLongTermTotal));
  memcpy(&Dest.a_NoiseMinBeamTotal, &Src.a_NoiseMinBeamTotal, sizeof(Dest.a_NoiseMinBeamTotal));
  memcpy(&Dest.a_NoiseMaxBeamTotal, &Src.a_NoiseMaxBeamTotal, sizeof(Dest.a_NoiseMaxBeamTotal));
#if (RSP2_SIM_INTERFERENCE == 1u)
  Dest.b_InterfCondition1 = Src.b_InterfCondition1;
  Dest.b_InterfCondition2 = Src.b_InterfCondition2;
  Dest.b_InterfCondition3 = Src.b_InterfCondition3;
  Dest.b_RequestRfChangeRandom = Src.b_RequestRfChangeRandom;
  Dest.b_UpperLevel = Src.b_UpperLevel;
#if (SRR_SWITCH == SWITCH_OFF)
  Dest.u_ChangeRfIndex = Src.u_ChangeRfIndex;
#else
  Dest.u_ChangeRfIndex = 0;
#endif
  Dest.u_CurrentRfIndex = Src.u_CurrentRfIndex;
#endif
#if (SRR_SWITCH == SWITCH_OFF)
  memcpy(&Dest.a_ArrayOfMaxRanges, &Src.a_ArrayOfMaxRanges, sizeof(Dest.a_ArrayOfMaxRanges));
  Dest.u_RfChangeCounter = Src.u_RfChangeCounter;
#endif
  Dest.sSigHeader = Src.sSigHeader;
}


void CConvRsp2Noise::Convert_Gen_to_v0_0 (RSP2_Noise_V0_0::RSP2_t_Noise & Dest, const RSP2_Noise_Gen::RSP2_t_Noise & Src)
{
  memcpy(&Dest.a_NoiseMinBeamLongTerm, &Src.a_NoiseMinBeamLongTerm, sizeof(Dest.a_NoiseMinBeamLongTerm));
  memcpy(&Dest.a_NoiseMinLongTermTotal, &Src.a_NoiseMinLongTermTotal, sizeof(Dest.a_NoiseMinLongTermTotal));
  memcpy(&Dest.a_ArrayOfMaxRanges, &Src.a_ArrayOfMaxRanges, sizeof(Dest.a_ArrayOfMaxRanges));
  Dest.u_RfChangeCounter = Src.u_RfChangeCounter;
  Dest.sSigHeader = Src.sSigHeader;
}


void CConvRsp2Noise::Convert_Gen_to_v1 (RSP2_Noise_V1::RSP2_t_Noise & Dest, const RSP2_Noise_Gen::RSP2_t_Noise & Src)
{
  memcpy(&Dest.a_NoiseMinBeamLongTerm, &Src.a_NoiseMinBeamLongTerm, sizeof(Dest.a_NoiseMinBeamLongTerm));
  memcpy(&Dest.a_NoiseMinLongTermTotal, &Src.a_NoiseMinLongTermTotal, sizeof(Dest.a_NoiseMinLongTermTotal));
  memcpy(&Dest.a_NoiseMinBeamTotal, &Src.a_NoiseMinBeamTotal, sizeof(Dest.a_NoiseMinBeamTotal));
  memcpy(&Dest.a_NoiseMaxBeamTotal, &Src.a_NoiseMaxBeamTotal, sizeof(Dest.a_NoiseMaxBeamTotal));
#if (RSP2_SIM_INTERFERENCE == 1u)
  Dest.b_InterfCondition1 = Src.b_InterfCondition1;
  Dest.b_InterfCondition2 = Src.b_InterfCondition2;
  Dest.b_InterfCondition3 = Src.b_InterfCondition3;
  Dest.b_RequestRfChangeRandom = Src.b_RequestRfChangeRandom;
  Dest.b_UpperLevel = Src.b_UpperLevel;
  Dest.u_CurrentRfIndex = Src.u_CurrentRfIndex;
#endif
#if (SRR_SWITCH == SWITCH_OFF)
  memcpy(&Dest.a_ArrayOfMaxRanges, &Src.a_ArrayOfMaxRanges, sizeof(Dest.a_ArrayOfMaxRanges));
  Dest.u_RfChangeCounter = Src.u_RfChangeCounter;
  Dest.b_ArrayMaxRangesFlag = Src.b_ArrayMaxRangesFlag;
  Dest.u_ChangeRfIndex = Src.u_ChangeRfIndex;
#endif
  Dest.sSigHeader = Src.sSigHeader;
}

void CConvRsp2Noise::Convert_Gen_to_v2 (RSP2_Noise_V2::RSP2_t_Noise & Dest, const RSP2_Noise_Gen::RSP2_t_Noise & Src)
{
  // if RSP2_Noise_Gen::RSP2_t_Noise is exactly like RSP2_Noise_V1::RSP2_t_Noise then
  memcpy (&Dest, &Src, sizeof(Dest));
  Dest.u_VersionNumber = 2;
}

long CConvRsp2Noise::ConvertData (
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const unsigned __int32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned __int32*>(pPPortData)):(0);
  bool bGenBufferFilled = false;
  // First decide which version we are converting to
  // If direct one:one copy possible then do that (without check of Versions!)
  if (ulPPortSize == ulRPortSize)
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == SUPPORTED_SIZE[3]) &&
    ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(NACOM_INPUT_VERSIONS[3])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))) &&
    (uDataVer == 2u))
  {
    // Source Port V3
    InitVersion(m_BufGen, 2);
    const RSP2_Noise_V2::RSP2_t_Noise & Src = *reinterpret_cast<RSP2_Noise_V2::RSP2_t_Noise *>(pPPortData);
    Convert_v2_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == SUPPORTED_SIZE[2]) &&
    ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(NACOM_INPUT_VERSIONS[2])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))) &&
    (uDataVer == 1u))
  {
    // Source Port V2
    InitVersion(m_BufGen, 1);
    const RSP2_Noise_V1::RSP2_t_Noise & Src = *reinterpret_cast<RSP2_Noise_V1::RSP2_t_Noise *>(pPPortData);
    Convert_v1_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == SUPPORTED_SIZE[1]) &&
    ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(NACOM_INPUT_VERSIONS[1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))/* &&
    ((uDataVer == 1u) || (uDataVer == 0))*/)
  {
    // Source Port V1
    InitVersion(m_BufGen, 0);
    const RSP2_Noise_V0::RSP2_t_Noise & Src = *reinterpret_cast<RSP2_Noise_V0::RSP2_t_Noise *>(pPPortData);
    Convert_v0_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == SUPPORTED_SIZE[0]) &&
    ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(NACOM_INPUT_VERSIONS[0])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))/* &&
    ((uDataVer == 1u) || (uDataVer == 0))*/)
  {
    // Source Port V0
    InitVersion(m_BufGen, 0);
    const RSP2_Noise_V0_0::RSP2_t_Noise & Src = *reinterpret_cast<RSP2_Noise_V0_0::RSP2_t_Noise *>(pPPortData);
    Convert_v0_0_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == SUPPORTED_SIZE[3]) &&
      ((requestPortVersionInfo.Equals(NACOM_INPUT_VERSIONS[3])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V3
      InitVersion(m_BufV2, 0);
      RSP2_Noise_V2::RSP2_t_Noise & Dest = /*reinterpret_cast<RSP2_Noise_V1::RSP2_t_Noise &>*/(m_BufV2);
      Convert_Gen_to_v2(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[2]) &&
      ((requestPortVersionInfo.Equals(NACOM_INPUT_VERSIONS[2])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V2
      InitVersion(m_BufV1, 0);
      RSP2_Noise_V1::RSP2_t_Noise & Dest = /*reinterpret_cast<RSP2_Noise_V1::RSP2_t_Noise &>*/(m_BufV1);
      Convert_Gen_to_v1(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[1]) &&
      ((requestPortVersionInfo.Equals(NACOM_INPUT_VERSIONS[1])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V1
      InitVersion(m_BufV0);
      RSP2_Noise_V0::RSP2_t_Noise & Dest = /*reinterpret_cast<RSP2_Noise_V0::RSP2_t_Noise &>*/(m_BufV0);
      Convert_Gen_to_v0(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[0]) &&
      ((requestPortVersionInfo.Equals(NACOM_INPUT_VERSIONS[0])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V0
      InitVersion(m_BufV0_0);
      RSP2_Noise_V0_0::RSP2_t_Noise & Dest = /*reinterpret_cast<RSP2_Noise_V0::RSP2_t_Noise &>*/(m_BufV0_0);
      Convert_Gen_to_v0_0(Dest, m_BufGen);
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
long CConvRsp2Noise::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    // Disclamation of check on version, only the size matters
    // if (BASE_VERSION1.Equals(&requestPortVersionInfo) ||
    //   VERSION1.Equals(&requestPortVersionInfo) ||
    //   VERSION2.Equals(&requestPortVersionInfo))
    // {

    if (ulRPortSize == sizeof(m_BufV0_0))
    {
      InitVersion(m_BufV0_0);
      *pDefaultData = &m_BufV0_0;
      ulDefaultSize = sizeof(m_BufV0_0);
      lRet = SIM_ERR_OK;
    }
    if (ulRPortSize == sizeof(m_BufV0))
    {
      InitVersion(m_BufV0);
      *pDefaultData = &m_BufV0;
      ulDefaultSize = sizeof(m_BufV0);
      lRet = SIM_ERR_OK;
    }
    else if (ulRPortSize == sizeof(m_BufV1))
    {
      InitVersion(m_BufV1, 1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(m_BufV1);
      lRet = SIM_ERR_OK;
    }
    else if (ulRPortSize == sizeof(m_BufV2))
    {
      InitVersion(m_BufV2, 2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(m_BufV2);
      lRet = SIM_ERR_OK;
    }
    else
    {
      lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    }
    // }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRsp2Noise::IsVersionCompatibleWithType (
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
}

// used to check if ports are compatible between different versions
bool CConvRsp2Noise::AreVersionsCompatible (
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
IConverter * CreateRSP2NoiseConvClass(void)
{
  return new CConvRsp2Noise();
}
