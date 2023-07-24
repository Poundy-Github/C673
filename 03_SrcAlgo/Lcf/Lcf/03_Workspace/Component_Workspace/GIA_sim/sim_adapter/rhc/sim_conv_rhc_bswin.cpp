/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter rhc

  MODULNAME:       sim_conv_rhc_bswin

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   23.08.2013

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_rhc_bswin.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:29CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rhc/project.pj
  CHANGES:         Revision 1.1 2013/09/02 12:50:17CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/rhc/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_rtebswin.h"
#include "sim_versioninfo_impl.h"

typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;

/* typedef u_OpMode_t */
#ifndef RHC_OpMode_Reset
  #define RHC_OpMode_Reset (0U)
#endif
#ifndef RHC_OpMode_Normal
  #define RHC_OpMode_Normal (2U)
#endif


// ARS4xx RHC_t_BswIn version 2 V1               Length = 36
namespace RHC_t_BswIn_ARS4xx_V2_1
{
  typedef float a_PowerAmp_array_t[2];           /* power amplifier */  /* [Satisfies_rte sws 1189] */
  typedef float a_Rx_array_t[4];                 /* receiver chips */  /* [Satisfies_rte sws 1189] */
  typedef unsigned char u_OpMode_t               /* @min: 0 @max:4 @values: enum { RHC_OpMode_Normal=2,RHC_OpMode_Alignment=3,RHC_OpMode_Pause=1,RHC_OpMode_Reset=0,RHC_OpMode_NoEmission=4,} */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char u_Dummy_array_t[3];      /* dummy for 4-byte alignment */  /* [Satisfies_rte sws 1189] */

  typedef struct t_SensorTemperature             /* [Satisfies_rte sws 1191] */
  {
    float f_Vco;
    a_Rx_array_t a_Rx;
    a_PowerAmp_array_t a_PowerAmp;
  } t_SensorTemperature;                         /* sensor temperature semantic still has to be defined (e.g. quality) */

  typedef struct RHC_t_BswIn                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    t_SensorTemperature SensorTemperature;
    u_OpMode_t u_OpMode;
    u_Dummy_array_t u_Dummy;
  } RHC_t_BswIn;                                 /* input from base software @vaddr:0x20500000, 0x20501000, 0x20502000 @vaddr_defs: ALN_MEAS_ID_BSW_IN_FAR,ALN_MEAS_ID_BSW_IN_NEAR,ALN_MEAS_ID_BSW_IN_CLUSTERS @cycleid:ALN_ENV @vname:ALN_RteBswInFar,ALN_RteBswInNear,ALN_RteBswInClusters */
}

// ARS4xx RHC_t_BswIn version 2 V2               Length = 48
namespace RHC_t_BswIn_ARS4xx_V2_2
{
  typedef unsigned long AlgoDataTimeStamp_t      /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t      /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t        /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;

  typedef struct SignalHeader_t                  /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                              /* Common header for all structured data types */

  typedef struct RHC_t_BswIn                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    RHC_t_BswIn_ARS4xx_V2_1::t_SensorTemperature SensorTemperature;
    RHC_t_BswIn_ARS4xx_V2_1::u_OpMode_t u_OpMode;
    RHC_t_BswIn_ARS4xx_V2_1::u_Dummy_array_t u_Dummy;
  } RHC_t_BswIn;                                 /* input from base software @vaddr:0x20500000, 0x20501000, 0x20502000 @vaddr_defs: ALN_MEAS_ID_BSW_IN_FAR,ALN_MEAS_ID_BSW_IN_NEAR,ALN_MEAS_ID_BSW_IN_CLUSTERS @cycleid:ALN_ENV @vname:ALN_RteBswInFar,ALN_RteBswInNear,ALN_RteBswInClusters */
}



class CConvRhcBswIn : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char* DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  RHC_t_BswIn_ARS4xx_V2_1::RHC_t_BswIn m_BufV2_1;
  RHC_t_BswIn_ARS4xx_V2_2::RHC_t_BswIn m_BufV2_2;

  static void InitV2_1(RHC_t_BswIn_ARS4xx_V2_1::RHC_t_BswIn & Params);
  static void InitV2_2(RHC_t_BswIn_ARS4xx_V2_2::RHC_t_BswIn & Params);

public:

  static const char *GetConverterTypeName()
  {
    return "RHC_S_InputBsw_t";
  }

  CConvRhcBswIn(void);
  virtual ~CConvRhcBswIn(void);

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
  static CVersionInfoImpl VERSION2;
  //static CVersionInfoImpl VERSION2;

  enum BSWAlgoParameters
  {
    ALN_RTE_BSW_IN_V2_1,
    ALN_RTE_BSW_IN_V2_2,
    //ALN_RTE_BSW_IN_V3,
    BSW_ALGO_PARAM_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[BSW_ALGO_PARAM_VERSION_COUNT];

};

CVersionInfoImpl CConvRhcBswIn::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvRhcBswIn::VERSION2(0, 0, 2);
//CVersionInfoImpl CConvRhcBswIn::VERSION2(0, 0, 3);

const unsigned long CConvRhcBswIn::SUPPORTED_SIZE[CConvRhcBswIn::BSW_ALGO_PARAM_VERSION_COUNT] =
{
  sizeof(RHC_t_BswIn_ARS4xx_V2_1::RHC_t_BswIn),
  sizeof(RHC_t_BswIn_ARS4xx_V2_2::RHC_t_BswIn),
  //sizeof(RHC_t_BswIn_ARS4xx_V3::RHC_t_BswIn),
};

CConvRhcBswIn::CConvRhcBswIn(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), /*m_BufV6_1(), m_BufV6_2(),*/ m_BufV2_1(), m_BufV2_2()
{
}

CConvRhcBswIn::~CConvRhcBswIn(void)
{
}

void CConvRhcBswIn::InitV2_1(RHC_t_BswIn_ARS4xx_V2_1::RHC_t_BswIn & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 2u;
  // Sensor Temperature
  Params.SensorTemperature.f_Vco                 = 0.0F;
  Params.SensorTemperature.a_Rx[0]               = 0;
  Params.SensorTemperature.a_Rx[1]               = 0;
  Params.SensorTemperature.a_Rx[2]               = 0;
  Params.SensorTemperature.a_Rx[3]               = 0;
  Params.SensorTemperature.a_PowerAmp[0]         = 0;
  Params.SensorTemperature.a_PowerAmp[1]         = 0;
  // OP mode
  Params.u_OpMode                                = RHC_OpMode_Reset;
}

void CConvRhcBswIn::InitV2_2(RHC_t_BswIn_ARS4xx_V2_2::RHC_t_BswIn & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 3u;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = 0;
  // Sensor Temperature
  Params.SensorTemperature.f_Vco                 = 0.0F;
  Params.SensorTemperature.a_Rx[0]               = 0;
  Params.SensorTemperature.a_Rx[1]               = 0;
  Params.SensorTemperature.a_Rx[2]               = 0;
  Params.SensorTemperature.a_Rx[3]               = 0;
  Params.SensorTemperature.a_PowerAmp[0]         = 0;
  Params.SensorTemperature.a_PowerAmp[1]         = 0;
  // OP mode
  Params.u_OpMode                                = RHC_OpMode_Reset;
}

long CConvRhcBswIn::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long & ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // First decide which version we are converting to
  if ((ulRPortSize == sizeof(m_BufV2_2)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V2
    RHC_t_BswIn_ARS4xx_V2_2::RHC_t_BswIn & Dest = m_BufV2_2;
    if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 0)))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else if ((ulPPortSize == sizeof(m_BufV2_1))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 0)))
    {
      const RHC_t_BswIn_ARS4xx_V2_1::RHC_t_BswIn & Src = *reinterpret_cast<RHC_t_BswIn_ARS4xx_V2_1::RHC_t_BswIn*>(pPPortData);
      Dest.u_VersionNumber                 = 2u;
      Dest.sSigHeader.uiTimeStamp          = 0;
      Dest.sSigHeader.uiCycleCounter       = 0;
      Dest.sSigHeader.uiMeasurementCounter = 0;
      Dest.sSigHeader.eSigStatus           = 1;
      Dest.u_OpMode                        = Src.u_OpMode;
      Dest.SensorTemperature               = Src.SensorTemperature;
      Dest.u_Dummy[0]                      = Src.u_Dummy[0];
      Dest.u_Dummy[1]                      = Src.u_Dummy[1];
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == sizeof(m_BufV2_1)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V1
    RHC_t_BswIn_ARS4xx_V2_1::RHC_t_BswIn & Dest = m_BufV2_1;
    if ((ulPPortSize == sizeof(m_BufV2_2))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 0)))
    {
      const RHC_t_BswIn_ARS4xx_V2_2::RHC_t_BswIn & Src = *reinterpret_cast<RHC_t_BswIn_ARS4xx_V2_2::RHC_t_BswIn*>(pPPortData);
      Dest.u_VersionNumber                 = 1u;
      Dest.u_OpMode                        = Src.u_OpMode;
      Dest.SensorTemperature               = Src.SensorTemperature;
      Dest.u_Dummy[0]                      = Src.u_Dummy[0];
      Dest.u_Dummy[1]                      = Src.u_Dummy[1];
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 0)))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvRhcBswIn::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(m_BufV2_2)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo))))
    {
      InitV2_2(m_BufV2_2);
      *pDefaultData = &m_BufV2_2;
      ulDefaultSize = sizeof(m_BufV2_2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV2_1)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo))))
    {
      InitV2_1(m_BufV2_1);
      *pDefaultData = &m_BufV2_1;
      ulDefaultSize = sizeof(m_BufV2_1);
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
bool CConvRhcBswIn::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
  {
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((ulRPortSize == sizeof(m_BufV2_1)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      if (ulPPortSize == sizeof(m_BufV2_1))
      {
        bResult = true;
      }
      else if (ulPPortSize == sizeof(m_BufV2_2))
      {
        bResult = true;
      }
    }
    else if ((ulRPortSize == sizeof(m_BufV2_2)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      if (ulPPortSize == sizeof(m_BufV2_1))
      {
        bResult = true;
      }
      else if (ulPPortSize == sizeof(m_BufV2_2))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvRhcBswIn::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((ulRPortSize == sizeof(m_BufV2_1)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      if ((ulPPortSize == sizeof(m_BufV2_1)) && ((providePortVersionInfo.Equals(&VERSION2)) || (providePortVersionInfo.Equals(&BASE_VERSION))))
      {
        bResult = true;
      }
      else if ((ulPPortSize == sizeof(m_BufV2_2)) && ((providePortVersionInfo.Equals(&VERSION2)) || (providePortVersionInfo.Equals(&BASE_VERSION))))
      {
        bResult = true;
      }
    }
    else if ((ulRPortSize == sizeof(m_BufV2_2)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      if ((ulPPortSize == sizeof(m_BufV2_1)) && ((providePortVersionInfo.Equals(&VERSION2)) || (providePortVersionInfo.Equals(&BASE_VERSION))))
      {
        bResult = true;
      }
      else if ((ulPPortSize == sizeof(m_BufV2_2)) && ((providePortVersionInfo.Equals(&VERSION2)) || (providePortVersionInfo.Equals(&BASE_VERSION))))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateRhcBswInConvClass(void)
{
  return new CConvRhcBswIn();
}
