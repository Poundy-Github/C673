/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter rsp

  MODULNAME:       sim_conv_rsp1_noise.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   24.6.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_rsp1_noise.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:21:41CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:15:34CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.1 2015/06/24 11:18:05CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_rsp1_noise.h"
#include "sim_versioninfo_impl.h"

#define MIN(x,y) (((x)<(y))?(x):(y))

/* Common definitions/declarations */
typedef unsigned long AlgoDataTimeStamp_t                            /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
typedef unsigned short AlgoCycleCounter_t                            /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
typedef unsigned char AlgoSignalState_t                              /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;

typedef struct SignalHeader_t                                        /* [Satisfies_rte sws 1191] */
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;                                                    /* Common header for all structured data types */


namespace RSP1_Noise_V216
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_NoiseMin;
    unsigned char b_InfluencedByLargePeak;
  } t_NoiseMin;

  typedef t_NoiseMin a_NoiseMinBeam_array_t[16];                     /* Minimum noise over range for each beam */ /* [Satisfies_rte sws 1189] */
  typedef float a_NoiseMaxBeam_array_t[16];                          /* Maximum noise over range for each beam */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    SignalHeader_t sSigHeader;
    unsigned long u_VersionNumber;
  } RSP_t_NoiseHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    a_NoiseMinBeam_array_t a_NoiseMinBeam;
    a_NoiseMaxBeam_array_t a_NoiseMaxBeam;
    unsigned long u_InterferenceCounter1;
    unsigned long u_InterferenceCounter2;
  } RSP_t_Noise;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_NoiseHeader NoiseHeader;
    RSP_t_Noise Noise;
  } RSP_t_NoiseFNS;                                                  /* @vaddr:0x06070000 @vaddr_defs: RSP1_VADDR_NOISE_NS @cycleid:RSP1_ENV @vname:RSP_NoiseNS */
} // end of RSP1_Noise_V216


namespace RSP1_Noise_V228
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP1_Noise_V216::a_NoiseMinBeam_array_t a_NoiseMinBeam;
    RSP1_Noise_V216::a_NoiseMaxBeam_array_t a_NoiseMaxBeam;
    unsigned long u_InterferenceCounter1;
    unsigned long u_InterferenceCounter2;
    unsigned long u_InterferenceThresMax;
    unsigned long u_InterferenceThresMean;
    float f_ThresSnr;
  } RSP_t_Noise;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP1_Noise_V216::RSP_t_NoiseHeader NoiseHeader;
    RSP_t_Noise Noise;
  } RSP_t_NoiseFNS;                                                  /* @vaddr:0x06070000 @vaddr_defs: RSP1_VADDR_NOISE_NS @cycleid:RSP1_ENV @vname:RSP_NoiseNS */
} // end of RSP1_Noise_V228


class CConvRsp1Noise : public CSimConverterBase
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

  RSP1_Noise_V216::RSP_t_NoiseFNS m_BufV216;
  RSP1_Noise_V228::RSP_t_NoiseFNS m_BufV228;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "RSP1_t_Noise";
  }

  CConvRsp1Noise(void);
  virtual ~CConvRsp1Noise(void);

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
  enum AVWV_Rsp1Noise
  {
    RSP1_NOISE_V216,
    RSP1_NOISE_V228,
    RSP1_NOISE_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;

  static const CVersionInfoImpl * const RSP1_NOISE_VERSIONS[RSP1_NOISE_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[RSP1_NOISE_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < RSP1_NOISE_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(RSP1_NOISE_VERSIONS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };
};

CVersionInfoImpl CConvRsp1Noise::BASE_VERSION(0, 0, 0);

const CVersionInfoImpl * const CConvRsp1Noise::RSP1_NOISE_VERSIONS[CConvRsp1Noise::RSP1_NOISE_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION
};

const unsigned long CConvRsp1Noise::SUPPORTED_SIZE[CConvRsp1Noise::RSP1_NOISE_VERSION_COUNT] =
{
  sizeof(RSP1_Noise_V216::RSP_t_NoiseFNS),
  sizeof(RSP1_Noise_V228::RSP_t_NoiseFNS),
};

__inline void v_Convert_v228_to_v216 (RSP1_Noise_V216::RSP_t_NoiseFNS * const pDest,
  const RSP1_Noise_V228::RSP_t_NoiseFNS * const pSrc)
{
  int nMinSize = MIN(sizeof(*pDest), sizeof(*pSrc));
  memcpy (pDest, pSrc, nMinSize);
}

__inline void v_Convert_v216_to_v228 (RSP1_Noise_V228::RSP_t_NoiseFNS * const pDest,
  const RSP1_Noise_V216::RSP_t_NoiseFNS * const pSrc)
{
  int nMinSize = MIN(sizeof(*pDest), sizeof(*pSrc));
  memcpy (pDest, pSrc, nMinSize);
  pDest->Noise.u_InterferenceThresMax  = 0U;
  pDest->Noise.u_InterferenceThresMean = 0U;
  pDest->Noise.f_ThresSnr              = 11.0f;
}


CConvRsp1Noise::CConvRsp1Noise(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV216(), m_BufV228()
{
  InitVx(m_BufV216);
  InitVx(m_BufV228);
}

CConvRsp1Noise::~CConvRsp1Noise(void)
{
}

long CConvRsp1Noise::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  //const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);

  if (eRPortType == ePPortType)
  {
    if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
    {
      // Use data directly from provide port
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else
    {
      // First decide which version we are converting from
      if ((ulPPortSize == SUPPORTED_SIZE[RSP1_NOISE_V228]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(RSP1_NOISE_VERSIONS[RSP1_NOISE_V228])))
      {
        const RSP1_Noise_V228::RSP_t_NoiseFNS *pSrc = reinterpret_cast<RSP1_Noise_V228::RSP_t_NoiseFNS *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[RSP1_NOISE_V216]) &&
          (requestPortVersionInfo.Equals(RSP1_NOISE_VERSIONS[RSP1_NOISE_V216])))
        {
          // Destination port of V5 is m_BufV216
          v_Convert_v228_to_v216(&m_BufV216, pSrc);
          *pOutData = &m_BufV216;
          ulOutSize = sizeof(m_BufV216);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[RSP1_NOISE_V216]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(RSP1_NOISE_VERSIONS[RSP1_NOISE_V216])))
      {
        const RSP1_Noise_V216::RSP_t_NoiseFNS *pSrc = reinterpret_cast<RSP1_Noise_V216::RSP_t_NoiseFNS *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[RSP1_NOISE_V228]) &&
          (requestPortVersionInfo.Equals(RSP1_NOISE_VERSIONS[RSP1_NOISE_V228])))
        {
          // Destination port of V7 is m_BufV228
          v_Convert_v216_to_v228(&m_BufV228, pSrc);
          *pOutData = &m_BufV228;
          ulOutSize = sizeof(m_BufV228);
          lRet = SIM_ERR_OK;
        }
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
long CConvRsp1Noise::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(RSP1_Noise_V228::RSP_t_NoiseFNS)) && (RSP1_NOISE_VERSIONS[RSP1_NOISE_V228]->Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV228);
      *pDefaultData = &m_BufV228;
      ulDefaultSize = sizeof(RSP1_Noise_V228::RSP_t_NoiseFNS);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(RSP1_Noise_V216::RSP_t_NoiseFNS)) && (RSP1_NOISE_VERSIONS[RSP1_NOISE_V216]->Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV216);
      *pDefaultData = &m_BufV216;
      ulDefaultSize = sizeof(RSP1_Noise_V216::RSP_t_NoiseFNS);
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
bool CConvRsp1Noise::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvRsp1Noise::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
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
IConverter * CreateRSP1NoiseConvClass(void)
{
  return new CConvRsp1Noise();
}
